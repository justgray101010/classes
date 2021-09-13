#include "mylib.h"

int Channel::counter = 0;

Channel::Channel() {
	c_serialNumber = counter;
	counter++;
	c_n = 1;
	c_devices = new Device[1];
	c_devices[0] = Device();
}

Channel::Channel(Device* devices, int n) {
	c_serialNumber = counter;
	counter++;
	c_n = n;
	c_devices = new Device[c_n];
	for (int i = 0; i < c_n; i++) {
		c_devices[i] = Device();
	}
}

Channel::Channel(const Channel& channel) {
	c_serialNumber = counter;
	counter++;
	c_n = channel.c_n;
	c_devices = new Device[c_n];
	for (int i = 0; i < c_n; i++) {
		c_devices[i] = Device(channel.c_devices[i]);
	}
}

void Channel::addDevice(Device *device) {
	int n = this->c_n + 1;
	Device* devices = new Device[n];
	this->c_n = n;
	this->c_devices[n - 1] = *device;
}

void Channel::display() {
	cout << "Channel #" << this->c_serialNumber << endl;
	for (int i = 0; i < this->c_n; i++) {
		cout << "\t" << this->c_devices[i].getType() << "\t";
		this->c_devices[i].getCalibration().display();
	}
}
