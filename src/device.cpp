#include "mylib.h"

Device::Device() {
	d_type = THERMOMETER;
	d_sensor = Sensor();
	d_number = 0;
	d_calibration = Date();
}

Device::Device(Sensor_type type, Sensor sensor, int number, Date calibration) {
	d_type = type;
	d_sensor = Sensor(sensor);
	d_number = number;
	d_calibration = Date(calibration);
}

Device::Device(const Device& device) {
	d_type = device.d_type;
	d_sensor = device.d_sensor;
	d_number = device.d_number;
	d_calibration = device.d_calibration;
}

char* Device::getType() {
	if (this->d_type == 0)
		return "ACCELEROMETER";
	if (this->d_type == 1)
		return "PROXIMETER";
	if (this->d_type == 2)
		return "THERMOMETER";
}

void Device::display() {
	cout << this->getType() << " ";
	cout << this->getNumber() << " ";
	this->getCalibration().display();
}
