
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;


int main()
{
	//Allowing the user to enter in their angle measure to be converted between radians and degrees
	double fullDegrees, radianMeasure, degreeMeasure, minutes, seconds, angleMeasure;
	int c = 0, formula = 0;
	const int MAX_NAME_LEN = 10;
	//we add (+1) to account for the null character
	char cStringUnitId[MAX_NAME_LEN + 1] = {}, symbol, start = 'Y';
	string unitId;


	while (start == 'y' || start == 'Y') {

		cout << "Please enter the measure of your angle:\n\n";
		cin >> angleMeasure;
		cin.ignore();


		cout << "Please type the unit measure for your angle from the following options\n\n[1]\tRadians\n\n[2]\tDegrees\n\n>";
		cin.get(symbol);

		//store in char array
		while (symbol != '\n') {
			cStringUnitId[c] = symbol;
			cin.get(symbol);
			c++;
		}

		int USER_IN_LEN = strlen(cStringUnitId);
		for (int i = 0; i < USER_IN_LEN; i++) { cStringUnitId[i] = tolower(cStringUnitId[i]); }

		//put into a string
		unitId = cStringUnitId;

		try {
			if (unitId == "radians") {
				cout << "Congrats, you have entered a correct full name measurement\n";
				formula = 1;

			}
			else if (unitId == "degrees") {
				cout << "Congrats, you have entered a correct full name measurement\n";
				formula = 2;
			}
			else {
				const int TEMP_LEN = 3;
				char temp1[TEMP_LEN + 1] = { 'r','a','d', '\0' }, temp2[TEMP_LEN + 1] = { 'd', 'e', 'g','\0' };

				if (strncmp(cStringUnitId, temp1, TEMP_LEN) != 0) {
					if (strncmp(cStringUnitId, temp2, TEMP_LEN) != 0) { throw (-1); }
					else { formula = 2; }
				}
				else { formula = 1; }
			}
		}

		//pre-condition: there is no match
		catch (int) {
			cout << "Unit measure is invalid\n\n\tWould you like to try again? (Y/N)\n\n";
			cin >> start;
			if (start == 'n' || start == 'N') {
				cout << "Exiting...\n";
				exit(1);
			}
			//flush out newLine
			cin.get(symbol);
			while (symbol != '\n') { cin.get(symbol); }
			//reset counter
			c = 0;
			//empty array, set to null
			for (int i = 0; i < MAX_NAME_LEN + 1; i++) { cStringUnitId[i] = '\0'; }
			continue;
		}

		switch (formula) {
		case 1:
			//we must convert radians to  degrees
			radianMeasure = angleMeasure;
			degreeMeasure = angleMeasure * (180 / M_PI);
			cout << degreeMeasure << " degrees\n";
			break;
		case 2:
			//we must convert degrees to radians
			degreeMeasure = angleMeasure;
			radianMeasure = angleMeasure * (M_PI / 180);
			cout << radianMeasure << " radians\n";
			break;
		default:
			cout << "Invalid case...\n";
			break;

		}

		exit(1);

	} //end while

	return 0;
}


