#pragma once

#include <iostream>
#include <math.h>
#include "FuelGauge.h"
#include "Odometer.h"

class Car {
public:
	Car ();
	Car (double fuelTankSize, double MPG);

	double getFuelTankSize ();
	double getMPG ();
	double getFuelAmount ();
	int getMiles ();

	bool Drive (int miles);

	double FuelUp (double fuelAmount);

private:
	FuelGauge *pmcFuelGauge;
	Odometer *pmcOdometer;
	double mMPG;
	
};