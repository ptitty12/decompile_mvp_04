/* Imported from emoose/re4 @ feb6805b (src/lib/dummy.c). SN ProDG libsn as built into MVP (libsn v62). */
/* SN Systems ProDG libsn: stdio system-call stubs (dummy.c). fd 1/2 go to the UART, everything else
 * to the host file server (PC* calls, which MVP's proview turns into an error report). GCC 2.95 -O2.
 * MVP's copy adds open() at the end; re4's (libsn v60) does not have it. re4's 8-byte .data
 * alignment and its padding word are left out: in MVP the 4 bytes after `first` are only padding
 * before the next object's .data. */

extern unsigned long fn_804289F4(unsigned long baud);
extern unsigned long fn_80428A64(const void *buf, unsigned long len);
extern int fn_804061F8(const char *name, int mode);
extern int fn_80406200(const char *name, int flags, int mode);
extern int fn_80406218(int fd, const void *buf, unsigned int len);
extern int fn_80406208(int fd);
extern int fn_80406220(int fd, int ofs, int whence);
extern int fn_80406210(int fd, void *buf, unsigned int len);

struct stat_min {
	int st_dev;
	int st_mode;
};

// Serial output of the runtime: initialises the UART on the first call (fn_804289F4(0)) and
// writes the bytes (what OSReport/printf text ends up as on the debug console).
int __sn_serialp(const void *buf, unsigned int len)
{
	static int first = 1;

	if (first) {
		first = 0;
		fn_804289F4(0);
	}
	fn_80428A64(buf, len);
	return len;
}

// The stdio write syscall of the SN runtime: fd 1/2 (stdout/stderr, i.e. printf) go to the UART
// through __sn_serialp, fd 0 fails, any other fd is a host file (fn_80406218).
int _write(int fd, const void *buf, unsigned int len)
{
	if (fd == 1 || fd == 2) {
		return __sn_serialp(buf, len);
	}
	if (fd == 0) {
		return -1;
	}
	return fn_80406218(fd, buf, len);
}

// Alias of _write.
int write(int fd, const void *buf, unsigned int len)
{
	return _write(fd, buf, len);
}

// Closes a host file (fn_80406208).
int close(int fd)
{
	return fn_80406208(fd);
}

// Every fd reports as a character device (st_mode 0x2000) so newlib's stdio stays unbuffered-line.
int fstat(int fd, struct stat_min *st)
{
	st->st_mode = 0x2000;
	return 0;
}

// Seeks a host file (fn_80406220).
int lseek(int fd, int ofs, int whence)
{
	return fn_80406220(fd, ofs, whence);
}

// Reads a host file (fn_80406210).
int read(int fd, void *buf, unsigned int len)
{
	return fn_80406210(fd, buf, len);
}

// Opens a host file (fn_80406200). With O_CREAT (0x200) the file is first created and closed again
// (fn_804061F8, fn_80406208): a failed close returns -1, a failed create is ignored and the open is tried
// anyway. The mode argument is never read.
int open(const char *name, int flags, ...)
{
	int fd;

	if (flags & 0x200) {
		fd = fn_804061F8(name, 0);
		if (fd != -1 && fn_80406208(fd) != 0)
			return -1;
	}
	return fn_80406200(name, flags, 0);
}
