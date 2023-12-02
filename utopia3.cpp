#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent environmental data
struct EnvironmentalData {
    string name;
    double carbonEmissions;
    double energyUsage;
    double wasteProduction;
};

// Function to calculate environmental impact score
double calculateEnvironmentalImpact(const EnvironmentalData& data) {
    return (data.carbonEmissions + data.energyUsage + data.wasteProduction) / 3.0;
}

int main() {
    vector<EnvironmentalData> entries;

    int choice = 0;
    while (choice != 4) {
        cout << "Environmental Impact Tracker" << endl;
        cout << "1. Add Environmental Data Entry" << endl;
        cout << "2. Calculate Environmental Impact Units (EIU)" << endl;
        cout << "3. View All Entries" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            EnvironmentalData entry;
            cout << "Enter Company Name: ";
            cin.ignore();
            getline(cin, entry.name);
            cout << "Enter Carbon Emissions (in tons): ";
            cin >> entry.carbonEmissions;
            cout << "Enter Energy Usage (in kWh): ";
            cin >> entry.energyUsage;
            cout << "Enter Waste Production (in tons): ";
            cin >> entry.wasteProduction;

            entries.push_back(entry);
            cout << "Data entry added successfully." << endl;
        } else if (choice == 2) {
            if (entries.empty()) {
                cout << "No data entries to calculate impact." << endl;
            } else {
                cout << "Environmental Impact Scores:" << endl;
                for (const auto& data : entries) {
                    double impact = calculateEnvironmentalImpact(data);
                    cout << data.name << ": " << impact << " EIU" << endl;
                }
            }
        } else if (choice == 3) {
            if (entries.empty()) {
                cout << "No data entries to display." << endl;
            } else {
                cout << "Environmental Data Entries:" << endl;
                for (const auto& data : entries) {
                    cout << "Company Name: " << data.name << endl;
                    cout << "Carbon Emissions: " << data.carbonEmissions << " tons" << endl;
                    cout << "Energy Usage: " << data.energyUsage << " kWh" << endl;
                    cout << "Waste Production: " << data.wasteProduction << " tons" << endl;
                    cout << endl;
                }
            }
        } else if (choice == 4) {
            cout << "Exiting the Environmental Impact Tracker." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}