// PSleep.h
// Quick code to sleep with microsecond granularity on Windows and Linux
// Charles Machalow - MIT License

#pragma once

/// <summary>
/// Sleeps for the given number of nanoseconds
/// </summary>
void pSleep(unsigned long long nanoseconds);