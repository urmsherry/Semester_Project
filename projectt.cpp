#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Patient {
    string name;
    int age;
    string gender;
    string address;
};

class MedicalSystem {
private:
    vector<Patient> patients;

public:
    void registerPatient() {
        Patient patient;
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, patient.name);

        cout << "Enter age: ";
        cin >> patient.age;
        cin.ignore();

        cout << "Enter gender: ";
        getline(cin, patient.gender);

        cout << "Enter address: ";
        getline(cin, patient.address);

        patients.push_back(patient);
        cout << "Patient registered successfully!" << endl;
    }

    void displayPatients() {
        cout << "Patient Information:" << endl;
        for (size_t i = 0; i < patients.size(); ++i) {
            const Patient &patient = patients[i];
            cout << "Name: " << patient.name << endl;
            cout << "Age: " << patient.age << endl;
            cout << "Gender: " << patient.gender << endl;
            cout << "Address: " << patient.address << endl;
            cout << "-----------------------------------" << endl;
        }
    }
};

int main() {
    MedicalSystem medicalSystem;
    int choice;

    do {
        cout << "Medical Information System" << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Display Patients" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                medicalSystem.registerPatient();
                break;
            case 2:
                medicalSystem.displayPatients();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
