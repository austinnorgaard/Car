#include "FuelGauge.h"

FuelGauge::FuelGauge (double fuelTankSize) {
	mFuelTankSize = fuelTankSize;
	mFuelAmount = mFuelTankSize;
	mbIsFull = (mFuelAmount == mFuelTankSize);
	mbIsEmpty = (mFuelAmount == 0.0);
	mbIsFuelLightOn = (mFuelAmount == mFuelTankSize * 0.1);
}

double FuelGauge::getFuelAmount () {
	return mFuelAmount;
}

double FuelGauge::getFuelTankSize () {
	return mFuelTankSize;
}

double FuelGauge::addFuel (double fuelAmount) {
	mFuelAmount += fuelAmount;
	if (mFuelAmount >= mFuelTankSize) {
		mbIsFull = true;
	}
	if (mFuelAmount > mFuelTankSize) {
		mFuelAmount -= mFuelAmount - mFuelTankSize;
	}
	return mFuelAmount;
}

double FuelGauge::useFuel (double fuelAmount) {
	mFuelAmount -= fuelAmount;
	if (mFuelAmount <= 0.0) {
		mbIsEmpty = true;
	}
	if (mFuelAmount < 0.0) {
		mFuelAmount = 0.0;
	}
	return mFuelAmount;
}

bool FuelGauge::notifyFuelLow () {
	return mbIsFuelLightOn = true;
}