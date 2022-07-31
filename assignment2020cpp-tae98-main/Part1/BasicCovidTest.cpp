#include "CovidCase.h"
using std::cout;

int main() {
    // this just make some objects for you
    CovidCase patientA(51.5115, -0.1160, "PatientA", 48, 49);
    CovidCase patientB(51.5033, -0.1195, "PatientB", 51, 79);
    cout << patientA << "\n";
    cout << patientB << "\n";
    cout << patientA.distanceTo(patientB) << "\n";
    return 0;

}
