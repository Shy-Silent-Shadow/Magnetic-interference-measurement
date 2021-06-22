#include <iostream>
#include <fstream>
#include <string>
using namespace std
using System;
int main() {
	int time = 0;
	ofstream Logfile("Logfile.txt");
	while (time = 0.5) {
		Logfile << "Engine time is 1:00, Position of of main camera: right side, Orientation of main camera: 90 degrees north \n";
		Logfile << "Virtual Hazard at right most corner. Additional hazard at left most corner, Virtual hazard displayed = True \n";
		Logfile << "Date is 4/9/2021 and starting time is 11:31 am. Standard radar being used \n";
		Logfile.close();
		string LogOutput;
		ifstream LogOutputFile(Logfile.txt);
		while (getline(LogOutputFile, LogOutput) {
			cout << LogOutput;
		}
		LogOutputFile.close();
	}
	}
