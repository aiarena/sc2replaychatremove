//#include <Windows.h>
#include <string>
//#include <istream>
//#include <fstream>
//#include <iostream>
//#include <ostream>
//
#include "StormLib.h"

//#include <fstream>

// Taken from: https://github.com/Cryptyc/Sc2ReplayNameChange
static int RemoveFileFromArchive(const char *ArchiveName, const char *ArchivedFile)
{
	HANDLE hMpq = NULL;          // Open archive handle
	int    nError = ERROR_SUCCESS; // Result value
	if (nError == ERROR_SUCCESS)
	{
		if (!SFileOpenArchive(ArchiveName, 0, 0, &hMpq))
		{
			nError = GetLastError();
		}
	}

	if (nError == ERROR_SUCCESS)
	{
		if (!SFileRemoveFile(hMpq, ArchivedFile, 0))
		{
			nError = GetLastError();
		}
	}
	if (hMpq != NULL)
		SFileCloseArchive(hMpq);
	return nError;
}


int main(int argc, char **argv)
{
	const static std::string ReplayFile = argv[1];
	RemoveFileFromArchive(ReplayFile.c_str(), "replay.message.events");
}