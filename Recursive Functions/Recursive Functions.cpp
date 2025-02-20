#include <Windows.h>
#include <iostream>
#include <string>

using std::string;

#define NEWLINE "\n";

void printDirectory(string directory, int depth)
{
	HANDLE hFind;
	WIN32_FIND_DATAA data;

	string padding(depth + 1, ' ');

	string searchPath = directory + "\\*";

	hFind = FindFirstFileA(searchPath.c_str(), &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (strcmp(data.cFileName, ".") == 0 || strcmp(data.cFileName, "..") == 0)
				continue;

			std::cout << padding << data.cFileName << NEWLINE;

			if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
				printDirectory(directory + "\\" + data.cFileName, depth+1);
			}
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
}

int main() {
	printDirectory("C:\\Users\\s242289\\", 0);
	return EXIT_SUCCESS;
}