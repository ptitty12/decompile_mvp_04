// Added for the MVP engine's differential tests (not part of pureikyubu): the
// recompiler is not built, so the core gets an always-unsupported stand-in.
#pragma once

namespace Gekko
{
	class Jit
	{
	public:
		explicit Jit(GekkoCore*) {}
		void Run() {}
		bool IsSupported() { return false; }
		void InvalidateAll() {}
	};
}
