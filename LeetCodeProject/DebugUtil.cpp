#include "DebugUtil.h"
#include "windows.h"

void DebugUtil::OutputString(const char* s)
{
	OutputDebugString(s);
}
