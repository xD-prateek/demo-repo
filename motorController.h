#include <SoftwareSerial.h>

class cytronQuadController{

	//VARIABLES
	int d1, d2;
	const int BUFFER_SIZE=8;
	byte buf[BUFFER_SIZE];
	SoftwareSerial driver1(NOT_A_PIN, d1);
	SoftwareSerial driver2(NOT_A_PIN, d2);
	byte m1_byte=0, m2_byte=128, m3_byte=0, m4_byte=128;

public:
	cytronQuadController(long baud_rate, int d1, int d2){
		this->d1 = d1;
		this->d2 = d2;
		driver1.begin(baud_rate);
  		driver2.begin(baud_rate);
  		Serial.begin(baud_rate);


	}

private:
	void setSpeed(char motor, int speed){
		/*
			- The speed will range from -100 to 100.
			- The motor options are 1, 2, 3, 4

			Input example: setSpeed(2, -20).
			Explanation: Set motor 2 to speed 20 anticlockwise

		*/

		// convert speed range from -100-100 to -63-63
		int vel = speed*63/100;

		// set the direction bit (6th bit)
		if(speed<0){
			vel = vel | (1<<6);
		}

		switch(motor){
			case '1':
				vel = vel | (1<<7);
			case '2':

			case '3':

			case '4':

			default:

		}


	}
	void stopAll(){

	}


};