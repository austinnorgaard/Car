#pragma once

#include <iostream>
#include <math.h>

class FuelGauge {
public:
	FuelGauge (double fuelTankSize);

	double getFuelAmount ();
	double getFuelTankSize ();

	double addFuel (double fuelAmount);
	double useFuel (double fuelAmount);

	bool notifyFuelLow ();

private:
	bool mbIsFull, mbIsEmpty, mbIsFuelLightOn;
	double mFuelAmount, mFuelTankSize;
};