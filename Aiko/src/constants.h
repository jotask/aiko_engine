#pragma once

#include <random>

#define WIDTH 640
#define HEIGHT 480 // 360

int random(int low, int high);

#include <Windows.h>
#include <iostream>
#include <sstream>

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

enum class STATE { LABYRINTH, CODE }; // enum class

#define START_STATE STATE::LABYRINTH