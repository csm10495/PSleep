// PSleep.cpp
// Quick code to sleep with microsecond granularity on Windows and Linux
// Charles Machalow - MIT License

#include "PSleep.h"

#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void pSleep(unsigned long long microseconds)
{
#ifdef _WIN32
	HANDLE timer = CreateWaitableTimer(NULL, true, NULL);
	if (!timer)
	{
		fprintf(stderr, "timer is NULL (%d)\n", GetLastError());
		return;
	}

	FILETIME ft = { 0 };
	GetSystemTimeAsFileTime(&ft);

	LARGE_INTEGER ft_as_li = { 0 };
	ft_as_li.HighPart = ft.dwHighDateTime;
	ft_as_li.LowPart = ft.dwLowDateTime;

	ft_as_li.QuadPart += (microseconds * 10); // 100 nanosecond intervals

	if (!SetWaitableTimer(timer, &ft_as_li, 0, NULL, NULL, 0))
	{
		fprintf(stderr, "SetWaitableTimer failed (%d)\n", GetLastError());
		CloseHandle(timer);
		return;
	}

	if (WaitForSingleObject(timer, INFINITE) != WAIT_OBJECT_0)
	{
		fprintf(stderr, "WaitForSingleObject failed (%d)\n", GetLastError());
		CloseHandle(timer);
		return;
	}
	CloseHandle(timer);
#else
	usleep(microseconds);
#endif
}
