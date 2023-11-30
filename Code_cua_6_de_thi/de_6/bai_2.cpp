#include <iostream>
#include <vector>

// Forward declarations
class Patient;
class Hospital;
class ActivityLogParser;

// Class representing a Patient
class Patient {
public:
    int patient_id;
    std::string patient_type;
    std::string room_type;
    int days_in_hospital;
    double total_fee;

    Patient(int id, const std::string& type, const std::string& room, int days)
        : patient_id(id), patient_type(type), room_type(room), days_in_hospital(days), total_fee(0) {}

    void calculateTotalFee() {
        // Implement calculation logic based on patient type, room type, and days in hospital
        // This is a placeholder; you need to fill in the actual calculation logic.
        total_fee = 1000; // Placeholder value
    }
};

// Class representing a Hospital
class Hospital {
private:
    std::vector<Patient*> patients;

public:
    void addPatient(Patient* patient) {
        patients.push_back(patient);
    }

    double calculateHospitalFee() {
        double hospitalFee = 0;
        for (const auto& patient : patients) {
            patient->calculateTotalFee();
            hospitalFee += patient->total_fee;
        }
        return hospitalFee;
    }

    int countInpatient() {
        int inpatientCount = 0;
        for (const auto& patient : patients) {
            if (patient->patient_type == "I - daily fee") {
                inpatientCount++;
            }
        }
        return inpatientCount;
    }

    int countOutpatient() {
        int outpatientCount = 0;
        for (const auto& patient : patients) {
            if (patient->patient_type != "I - daily fee") {
                outpatientCount++;
            }
        }
        return outpatientCount;
    }
};

// Class representing an ActivityLogParser
class ActivityLogParser {
    // Implement parsing logic if needed
};

int main() {
    // Create instances of Hospital and patients
    Hospital hospital;

    Patient* patient1 = new Patient(1, "I - daily fee", "Room Type A", 5);
    Patient* patient2 = new Patient(2, "O - outpatient", "Room Type B", 2);

    // Add patients to the hospital
    hospital.addPatient(patient1);
    hospital.addPatient(patient2);

    // Calculate and print hospital fees
    double hospitalFee = hospital.calculateHospitalFee();
    std::cout << "Total Hospital Fee: $" << hospitalFee << std::endl;

    // Count and print the number of inpatients and outpatients
    int inpatientCount = hospital.countInpatient();
    int outpatientCount = hospital.countOutpatient();

    std::cout << "Number of Inpatients: " << inpatientCount << std::endl;
    std::cout << "Number of Outpatients: " << outpatientCount << std::endl;

    // Clean up memory
    delete patient1;
    delete patient2;

    return 0;
}
