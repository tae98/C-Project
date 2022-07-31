#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"
#include "algorithm"
using std::vector;
using std::ostream;
using std::cout;
using std::endl;
// TODO: your code goes here

class TimeAndCaseData {
public:
    void setTime(int t) {
        time = t;
    }

    void setNumberOfCases(int c) {
        cases = c;
    }

    int getTime() {
        return time;
    }

    int getNumberOfCases() {
        return cases;
    }

private:
    int time;
    int cases;
};

class CovidCaseMap {
public:
    void addCase(CovidCase cc) {
        list.push_back(cc);
    }

    void print() {
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << endl;
        }
    }

    double getResult() {
        return result;
    }

    bool checker(int input, vector<int> times) {
        bool result = false;
        for (int i = 0; i < times.size(); i++) {
            if (times[i] == input) {
                result = true;
                break;
            }
        }
        return result;
    }

    vector<TimeAndCaseData> getCasesOverTime(int hours) {
       vector<TimeAndCaseData> tt;
        vector<int> times;
        vector<int> allTimes;
        vector<int> cases;
        times.push_back(0);
        allTimes.push_back(0);
        int c = 0;

        for (auto i = list.begin(); i < list.end(); i++) {
            times.push_back((*i).getTime());
            allTimes.push_back((*i).getTime());
            allTimes.push_back((*i).getTime() + hours);
        }

        sort(allTimes.begin(), allTimes.end());

        for (int i = 0; i < allTimes.size(); i++) {
            if (i == 0) {
                cases.push_back(c);
            }
            else {
                if (checker(allTimes[i], times)) {
                    c = c + 1;
                    cases.push_back(c);
                }
                else {
                    c = c - 1;
                    cases.push_back(c);
                }
            }
        } // for

        for (int i = 0; i < cases.size(); i++) {
            TimeAndCaseData t;
            t.setTime(allTimes[i]);
            t.setNumberOfCases(cases[i]);
            tt.push_back(t);
        }
        return tt;
    }

   vector<CovidCase> findWhoISIn(int time) {
        vector<CovidCase> c = {};
        for (int i = 0; i < list.size(); i++) {
            if (time >= list[i].getTime()) {
                c.push_back(list[i]);
            }
        }
        return c;
    }

    void updateHelperPosition(double lat, double lon) {
        helper = CovidCase(lat, lon, "helper", 20, 0);
    }

    void findShortest(vector<CovidCase>& c) {
        double min = 999;
        for (int i = 0; i < c.size(); i++) {
            double dis = helper.distanceTo(c[i]);
            if (dis < min && dis != 0) {
                min = dis;
            }
        }
        // find the total distance
        result = result + min;

        // update the helper's position
        for (int i = 0; i < c.size(); i++) {
            if (min == helper.distanceTo(c[i])) {
                updateHelperPosition(c[i].getLatitude(), c[i].getLongitude());
                whoIsIn.erase(whoIsIn.begin() + i);
            }
        }
    }

    double supportVisitGreedyTSP(double latitude, double longitude, int time, int length) {

        whoIsIn = findWhoISIn(time);
        while (whoIsIn.size() > 0) {
            findShortest(whoIsIn);
        }
        return getResult() + helper.distanceTo(home);
    }



private:
    vector<CovidCase> list;
    CovidCase helper = CovidCase(51.751, -0.336, "helper", 20, 0);
    CovidCase home = CovidCase(51.751, -0.336, "helper", 20, 0);
    vector<CovidCase> whoIsIn;
    double result;
};
// don't write any code below this line

#endif
