#include "DebugUtil.h"
#ifdef __linux__
// linux code goes here.
#elif _WIN32
#include "windows.h"
// windows code goes here.
#else 
#endif

void DebugUtil::OutputString(const char* s)
{
#ifdef __linux__
	std::cout << s << std::endl;
#elif _WIN32
	OutputDebugString(s);
#endif
}
