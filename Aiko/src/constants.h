#pragma once

#include <random>

#define WIDTH 800
#define HEIGHT 600 // 360

int random(int low, int high);

#include <iostream>
#include <sstream>

// include for everyone
//#include "engine/aiko.h"


/*
#include <Windows.h>
#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}
*/

enum class STATE { LABYRINTH, CODE, FLAPPYBIRD, MANDELBROT, BARNSLEYFERN, OPENGL }; // enum class

#define START_STATE STATE::OPENGL