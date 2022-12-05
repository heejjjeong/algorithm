#pragma once
#include <windows.h>
#include "Types.h"

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};
class ConsoleHelper
{
};

