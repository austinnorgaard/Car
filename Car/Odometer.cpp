#include "Odometer.h"

Odometer::Odometer () {
	mMilesTraveled = 0;
}

int Odometer::addMiles (int miles) {
	mMilesTraveled += miles;
	if (mMilesTraveled > 999999) {
		mMilesTraveled = mMilesTraveled - 999999;
	}
	return mMilesTraveled;
}

int Odometer::getMiles () {
	return mMilesTraveled;
}