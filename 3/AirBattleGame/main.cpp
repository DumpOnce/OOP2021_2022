#include "Game/AirBattle.hpp"
#include <windows.h>
#include <cwchar>

int main()
{
	HANDLE soh = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	memset(&cfi, 0, sizeof(cfi));
	cfi.cbSize = sizeof(cfi);
	GetCurrentConsoleFontEx(soh, FALSE, &cfi);
	cfi.dwFontSize.Y += 7;
	SetCurrentConsoleFontEx(soh, FALSE, &cfi);
	try {
		AirBattle Game;
	}
	catch (...) {
		std::cerr << "Unknown error!";
	}
	return 0;
}
