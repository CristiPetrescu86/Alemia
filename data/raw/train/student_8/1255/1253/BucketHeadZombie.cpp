#include "BucketHeadZombie.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include<string>
#define ROW_ZOMBIE					17			
#define COL_FIRST_ZOMBIE_POSITION		142
#define COL_DISTANCE_BETWEEN_ZOMBIES	2

using namespace std::chrono;


BucketHeadZombie::BucketHeadZombie(int viteza, int rezistenta) :
	Zombie(viteza, rezistenta)
{
}

int BucketHeadZombie::place_zombie3()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_ZOMBIE_POSITION;
	static std::string printedChar = "B";
	auto end = steady_clock::now();

	if (col > 15)
	{
		if (duration_cast<milliseconds>(end - begin).count() > this->viteza)
		{
			begin = end;
			conOut(ROW_ZOMBIE + 1, col + COL_DISTANCE_BETWEEN_ZOMBIES) << " ";
			conOut(ROW_ZOMBIE + 1, col) << printedChar;
			conOut(ROW_ZOMBIE + 11, col + COL_DISTANCE_BETWEEN_ZOMBIES) << " ";
			conOut(ROW_ZOMBIE + 11, col) << printedChar;
			conOut(ROW_ZOMBIE - 4, col + COL_DISTANCE_BETWEEN_ZOMBIES) << " ";
			conOut(ROW_ZOMBIE - 4, col) << printedChar;
			col -= COL_DISTANCE_BETWEEN_ZOMBIES;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

BucketHeadZombie::~BucketHeadZombie()
{
}
