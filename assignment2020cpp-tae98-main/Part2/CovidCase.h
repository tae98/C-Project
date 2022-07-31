// TODO: Replace this file with your CovidCase.h from Part1
#ifndef COVIDCASE_H
#define COVIDCASE_H
#include <string>
#include <iostream>
#include <cmath>
#include<vector>
using std::vector;
using std::ostream;
using std::string;
using std::stod;
using std::stoi;
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

	CovidCase(string patientDetail) {

		vector<string> listOfWord;
		string word = "";

		for (int i = 0; i < patientDetail.size(); ++i) {
			//get 1 character from string
			char a = patientDetail[i];
			//create new words arfter "," has been found
			if (a == ',') {
				listOfWord.push_back(word);
				word = "";
				i++;
			}
			//if its not"," then add it with previous collection of characters.
			//if it reaches to the end of the set push the collected characters to list of words as a single word.
			else {
				word += a;
				if (i == patientDetail.size() - 1) {
					listOfWord.push_back(word);
				}
			}
		}

		string a = listOfWord[0];
		string b = listOfWord[1];
		string c = listOfWord[2];
		string d = listOfWord[3];
		string e = listOfWord[4];
		//stod for a,b 
		//stodi d,e 
		//remove unecessary \" from c
		m_latitude = stod(a);
		m_longitude = stod(b);
		m_age = stoi(d);
		m_time = stoi(e);
		m_name = c.substr(1, c.size() - 2);
	}

	double getLatitude() {
		return m_latitude;
	}
	double getLongitude() {
		return m_longitude;
	}
	string getName() {
		return m_name;
	}
	int getAge() {
		return m_age;
	}
	int getTime() {
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
	bool operator==(const CovidCase other) const {
		if (m_latitude == other.m_latitude &&
			m_longitude == other.m_longitude &&
			m_name == other.m_name &&
			m_age == other.m_age &&
			m_time == other.m_time) {
			return true;
		}
		else {
			return false;
		}
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
	o << "{" << printOut.getLatitude() << ", " << printOut.getLongitude() << ", \"" << printOut.getName() << "\", " << printOut.getAge() << ", " << printOut.getTime() << "}";
	return o;
}




// don't write any code below this line

#endif


// then extend as per the instructions in README.md

