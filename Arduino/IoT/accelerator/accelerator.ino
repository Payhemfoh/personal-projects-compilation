// accelerator.ino
#include "MPU9250.h"

// Configure I^2C address
MPU9250 IMU(Wire, 0x68);
int status;

void setup(){
	Serial.begin(115200);
	while(!Serial){}
	
	status = IMU.begin();
	if(status < 0){
		Serial.println("MPU9250 not detected.");
		Serial.print("Status: ");
		Serial.println(status);
		while(1){}
	}
}

void loop(){
	IMU.readSensor();
	
	// Accelerator
	// Serial.print("Accelerator X: ");
	// Serial.print(IMU.getAccelX_mss(), 6);
	// Serial.print("\t");
	// Serial.print("Accelerator Y: ");
	// Serial.print(IMU.getAccelY_mss(), 6);
	// Serial.print("\t");
	// Serial.print("Accelerator Z: ");
	// Serial.print(IMU.getAccelZ_mss(), 6);
	
	// Gyroscope, rotations
	// Serial.print("GyroX: ");
	// Serial.print(IMU.getGyroX_rads(), 6);
	// Serial.print("\t");
	// Serial.print("GyroY: ");
	// Serial.print(IMU.getGyroY_rads(), 6);
	// Serial.print("\t");
	// Serial.print("GyroZ: ");
	// Serial.print(IMU.getGyroZ_rads(), 6);
	
	// Magnetometer gives the direction.
	Serial.print("MagX: ");
	Serial.print(IMU.getMagX_uT(), 6); // Up.
	Serial.print("\t");
	Serial.print("MagY: ");
	Serial.print(IMU.getMagY_uT(), 6); // North in the compass.
	Serial.print("\t");
	Serial.print("MagZ: ");
	Serial.print(IMU.getMagZ_uT(), 6); // Sea level.
	Serial.print("\t");
	
	Serial.println();
	delay(200);
}
