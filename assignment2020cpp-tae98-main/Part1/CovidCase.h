#ifndef COVIDCASE_H
#define COVIDCASE_H
#include <string>
#include <iostream>
#include <cmath>
using std::ostream;
using std::string;

// TODO: your code  goes here
class CovidCase {
public:
	CovidCase(double latitude, double longitude, string name, int age, int time)
	{
		m_latitude = latitude;
		m_longitude = longitude;
		m_name = name;
		m_age = age;
		m_time = time;
	}

	double GetLatitude() {
		return m_latitude;
	}
	double GetLongitude() {
		return m_longitude;
	}
	string GetName() {
		return m_name;
	}
	int GetAge() {
		return m_age;
	}
	int GetTime() {
		return m_time;
	}

	double distanceTo(CovidCase& patient) {
		double pi = 3.14159265358979323846;
		double dlon = (patient.m_longitude - m_longitude) * (pi / 180);
		double dlat = (patient.m_latitude - m_latitude) * (pi / 180);
		double a = pow((sin(dlat / 2)), 2) + cos((m_latitude * (pi / 180))) * cos((patient.m_latitude * (pi / 180))) * pow((sin(dlon / 2)), 2);
		double c = 2 * atan2(sqrt(a), sqrt(1 - a));
		double R = 3960;
		double distance = R * c;
		return distance;
	}
private:
	double m_latitude;
	double m_longitude;
	string m_name;
	int m_age;
	int m_time;
	double m_distanceto;
};
//{latitude, longitude, "name", age, time}
ostream& operator<<(ostream& o, CovidCase& printOut) {
	o << "{" << printOut.GetLatitude() << ", " << printOut.GetLongitude() << ", \"" << printOut.GetName() << "\", " << printOut.GetAge() << ", " << printOut.GetTime() << "}" ;
	return o;
}




// don't write any code below this line

#endif

