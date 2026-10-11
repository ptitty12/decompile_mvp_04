/*
 * Dolphin SDK OS library, OS.c (build "May 21 2004 09:28:09", rev 0x2301).
 * Partial: only the functions matched so far. The split in
 * config/GV4E69/splits.txt covers exactly these functions.
 */

void OSReport(const char* msg, ...);

void OSRegisterVersion(const char* id)
{
    OSReport("%s\n", id);
}
