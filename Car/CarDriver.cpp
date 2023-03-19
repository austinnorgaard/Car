#include <iostream>
#include <math.h>
#include <iomanip>
#include "FuelGauge.h"
#include "Odometer.h"
#include "Car.h"

int main () {
	Car miniVan;
	std::string sFuel = "Remaining Fuel: ", sOdo = " Odometer: ", sSucJo = "Succesful Journey! ", sFailedJou = "Out of Fuel! ", sFueledUp = "Fueled Up! ";
	int totalTripLength = 1000000, numFillUps = 0, milesTraveled = 0;
	bool bIsNotEmpty;

	while (milesTraveled != totalTripLength) {
		bIsNotEmpty = miniVan.Drive (1);
		if (bIsNotEmpty) {
			milesTraveled++;
			std::cout <<sFuel << std::setprecision (4) << miniVan.getFuelAmount () << " Gallons" << sOdo << miniVan.getMiles () << " Miles" << std::endl;
		}
		else {
			numFillUps++;
			std::cout << sFailedJou << sFuel << miniVan.getFuelAmount () << " Gallons" << sOdo << miniVan.getMiles ()<< " Miles" << std::endl;
			miniVan.FuelUp (miniVan.getFuelTankSize () - miniVan.getFuelAmount ());
			std::cout << sFueledUp << sFuel << miniVan.getFuelAmount () << " Gallons" << sOdo << miniVan.getMiles () << " Miles" << std::endl;
		}
	}

	std::cout << "Arrived! " << sFuel << miniVan.getFuelAmount () << " Gallons" 
			  << sOdo << miniVan.getMiles () << " Mile(s)" << " Miles Traveled: " << milesTraveled << " Mile(s)"
			  << " Number of fill ups: " << numFillUps << std::endl;

	return EXIT_SUCCESS;
}