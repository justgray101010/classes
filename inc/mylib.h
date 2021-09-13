#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date {
    private:
        int m_day;
        int m_month;
        int m_year;

    public:
        Date();
        Date(int day, int month, int year);
        Date(const Date&);

        void setDate(int day, int month, int year);

        int getDay() { return m_day; }
        int getMonth() { return m_month; }
        int getYear() { return m_year; }

        Date setDay(int day) { this->m_day = day; return *this; }
        Date setMonth(int month) { this->m_month = month; return *this; }
        Date setYear(int year) { this->m_year = year; return *this; }

        void display();

        ~Date();
};

enum Sensor_type {
    ACCELEROMETER,
    PROXIMETER,
    THERMOMETER
};

class Sensor {
    private:
         char *s_units;
         double s_min;
         double s_max;
         double s_current;

    public:
        Sensor();
        Sensor(char* units, double min, double max, double current);
        Sensor(const Sensor&);

        char* getUnits() { return s_units; }
        int getMin() { return s_min; }
        int getMax() { return s_max; }
        int getCurrent() { return s_current; }

        void setUnits(char* units) { this->s_units = units; }
        void setMin(double min) { this->s_min = min; }
        void setMax(double max) { this->s_max = max; }
        void setCurrent(double current) { this->s_current = current; }

        void display();

        ~Sensor() {}
};

//delete[](this->s_units);

class Device {
    private:
        Sensor_type d_type;
        Sensor d_sensor;
        int d_number;
        Date d_calibration;

    public:
        Device();
        Device(Sensor_type type, Sensor sensor, int number, Date calibration);
        Device(const Device&);

        char* getType();
        Sensor getSensor() { return d_sensor; }
        int getNumber() { return d_number; }
        Date getCalibration() { return d_calibration; }

        void setType(Sensor_type type) { this->d_type = type; }
        void setSensor(Sensor sensor) { this->d_sensor = Sensor(sensor); }
        void setNumber(int number) { this->d_number = number; }
        void setCalibration(Date calibration) { this->d_calibration = Date(calibration); }

        void display();

        ~Device() {}
};

class Channel {
    static int counter;

    private:
        int c_serialNumber;
        Device* c_devices;
        int c_n;

    public:
        Channel();
        Channel(Device* devices, int n);
        Channel(const Channel&);

        int getSerialNumber() { return c_serialNumber; }
        Device* getDevices() { return c_devices; }
        int getSize() { return c_n; }

        void addDevice(Device *device);
        void display();

        ~Channel() {}
};

#endif
