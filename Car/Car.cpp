#include "Car.h"

Car::Car () {
	pmcFuelGauge = new FuelGauge (16.0);
	pmcOdometer = new Odometer ();
	mMPG = 22.0;
}

Car::Car (double fuelTankSize, double MPG) {
	pmcFuelGauge = new FuelGauge (fuelTankSize);
	pmcOdometer = new Odometer ();
	mMPG = MPG;
}

double Car::getFuelTankSize () {
	return pmcFuelGauge->getFuelTankSize ();
}

double Car::getMPG () {
	return mMPG;
}

double Car::getFuelAmount () {
	return pmcFuelGauge->getFuelAmount ();
}

int Car::getMiles () {
	return pmcOdometer->getMiles ();
}

bool Car::Drive (int miles) {
	if (pmcFuelGauge->getFuelAmount () * getMPG () >= miles) {
		pmcOdometer->addMiles (miles);
		pmcFuelGauge->useFuel (double (miles) / mMPG);
	}
	else {
		pmcOdometer->addMiles (pmcFuelGauge->getFuelAmount () * getMPG ());
		pmcFuelGauge->useFuel (pmcFuelGauge->getFuelAmount ());
	}

	return (pmcFuelGauge->getFuelAmount () != 0.0);
}

double Car::FuelUp (double fuelAmount) {
	pmcFuelGauge->addFuel (fuelAmount);
	return pmcFuelGauge->getFuelAmount ();
}