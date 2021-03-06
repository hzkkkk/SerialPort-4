// SerialPort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SerialPort.h"

using std::cout;
using std::endl;

const char *portName = "\\\\.\\COM1";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

int main()
{
	SerialPort port(portName);
	if (port.IsConnected())
	{
		cout << "INFO: Connection Established" << endl;
	}
	else
	{
		cout << "ERROR: port name is incorrect" << endl;
	}
	while (port.IsConnected()) 
	{
		//Check if data has been read or not
		int read_result = port.Read(incomingData, MAX_DATA_LENGTH);
		//prints out data
		puts(incomingData);
		//wait a bit
		Sleep(10);
	}
}
