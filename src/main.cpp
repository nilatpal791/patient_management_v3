#include "Menu.h"

int main() {
    AuthService auth("users.txt");
    DoctorDatabase ddb("doctors.txt");
    PatientDatabase pdb("patients.txt");
    AppointmentDatabase adb("appointments.txt");

    Menu menu(auth, ddb, pdb, adb);
    menu.run();

    return 0;
}
