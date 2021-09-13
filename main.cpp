#include "mylib.h"

int main() {
	/*char* units = new char[8];
	units = "monkeys";
	Sensor sensor1 = Sensor();
	Sensor sensor2 = Sensor(units, 0, 200, 14);

	sensor1.display();
	sensor2.display();
	sensor1.setMin(0);
	sensor1.display();
	sensor1.setMax(10);
	sensor1.display();
	sensor1.setCurrent(2);
	sensor1.display();
	sensor1.setUnits(units);
	sensor1.display();
	sensor2.display();*/
	
	char* s2 = new char[8];
	s2 = "monkeys";

	char* s1 = new char[9];
	s1 = "elefants";

	Device thermometer1 = Device(ACCELEROMETER, Sensor(s1, 0, 100, 22), 2, Date(13, 9, 2021));
	thermometer1.display();

	Channel channel1 = Channel();
	channel1.display();

	Channel channel2 = Channel(channel1);

	channel2.addDevice(&thermometer1);
	channel2.display();

	Channel channel3 = Channel(channel2);
	channel3.addDevice(&Device(PROXIMETER, Sensor(s2, 0, 200, 44), 3, Date(11, 11, 2011)));
	channel3.display();

	return 0;
}