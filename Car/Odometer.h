#pragma once

#include <iostream>
#include <math.h>

class Odometer {
public:
	Odometer ();

	int addMiles (int miles);
	int getMiles ();

private:
	int mMilesTraveled;
};