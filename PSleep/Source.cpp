// PSleep.cpp
// Quick sample code to sleep with microsecond granularity on Windows and Linux
// Charles Machalow - MIT License
// Compile in g++ with g++ Source.cpp PSleep.cpp -std=c++11

#include "PSleep.h"

#include <stdio.h>
#include <stdlib.h>

#include <string>

int main(int argc, char*argv[])
{
	if (argc > 1)
	{
		unsigned long long us = std::stoull(std::string(argv[1]));
		printf("Sleeping for %llu microseconds.\n", us);
		pSleep(us);
		return 0;
	}
	fprintf(stderr, "No sleep param given.\n");
	return 1;
}