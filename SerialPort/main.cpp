// SerialPort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"

using std::cout;
using std::endl;

/*Portname must contain these backslashes, and remember to
replace the following com port*/
const char *port_name = "\\\\.\\COM2";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

int main()
{
	SerialPort arduino(port_name);
	if (arduino.IsConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";

	while (arduino.IsConnected()) {
		//Check if data has been read or not
		int read_result = arduino.Read(incomingData, MAX_DATA_LENGTH);
		//prints out data
		puts(incomingData);
		//wait a bit
		Sleep(10);
	}
}
