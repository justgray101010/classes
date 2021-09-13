#include "mylib.h"

Sensor::Sensor() {
	s_units = new char[7];
	s_units = "degree";
	s_min = -300;
	s_max = 10000;
	s_current = 0;
}

Sensor::Sensor(char* units, double min, double max, double current) {
	s_units = units;
	s_min = min;
	s_max = max;
	s_current = current;
}

Sensor::Sensor(const Sensor& sensor) {
	s_units = sensor.s_units;
	s_min = sensor.s_min;
	s_max = sensor.s_max;
	s_current = sensor.s_current;
}

void Sensor::display() {
	cout << this->getUnits() << " " << this->getMin() << " " 
		<< this->getMax() << " " << this->getCurrent() << endl;
}
