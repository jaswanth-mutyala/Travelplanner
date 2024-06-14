#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Structure to represent a place with distance and transport mode
struct Place {
    string name;
    int distance;
    string transport;
};

// Structure to represent a connection between cities
struct Connection {
    string destination_city;
    int distance;
    string transport;
};

int main() {
    // Define predefined places in India
    map<string, vector<Place>> intra_city_places = {
        {"Hyderabad", {{"Charminar", 5, "Bus"}, {"Golconda Fort", 10, "Car"}, {"Hussain Sagar", 3, "Walk"}, {"Ramoji Film City", 20, "Car"}, {"Birla Mandir", 8, "Bus"}}},
        {"Delhi", {{"Red Fort", 15, "Metro"}, {"Qutub Minar", 12, "Taxi"}, {"India Gate", 10, "Walk"}, {"Lotus Temple", 8, "Auto"}, {"Humayun's Tomb", 14, "Bus"}}},
        {"Chennai", {{"Marina Beach", 8, "Bus"}, {"Kapaleeshwarar Temple", 6, "Auto"}, {"Fort St. George", 10, "Walk"}, {"San Thome Basilica", 5, "Bus"}, {"Guindy National Park", 15, "Taxi"}}},
        {"Mumbai", {{"Gateway of India", 7, "Bus"}, {"Marine Drive", 5, "Walk"}, {"Siddhivinayak Temple", 12, "Auto"}, {"Chhatrapati Shivaji Maharaj Vastu Sangrahalaya", 10, "Metro"}, {"Juhu Beach", 20, "Car"}}},
        {"Bangalore", {{"Lalbagh Botanical Garden", 6, "Auto"}, {"Bangalore Palace", 9, "Metro"}, {"Cubbon Park", 5, "Walk"}, {"ISKCON Temple", 14, "Bus"}, {"Wonderla Amusement Park", 25, "Car"}}},
        {"Kolkata", {{"Victoria Memorial", 8, "Metro"}, {"Howrah Bridge", 10, "Bus"}, {"Dakshineswar Kali Temple", 15, "Auto"}, {"Indian Museum", 7, "Walk"}, {"Science City Kolkata", 12, "Taxi"}}},
        {"Jaipur", {{"Hawa Mahal", 6, "Auto"}, {"Amber Fort", 12, "Bus"}, {"Jantar Mantar", 5, "Walk"}, {"City Palace", 8, "Auto"}, {"Jaigarh Fort", 15, "Taxi"}}},
        {"Goa", {{"Basilica of Bom Jesus", 9, "Bus"}, {"Calangute Beach", 7, "Auto"}, {"Dudhsagar Falls", 20, "Car"}, {"Fort Aguada", 10, "Walk"}, {"Anjuna Beach", 15, "Taxi"}}},
        {"Agra", {{"Taj Mahal", 8, "Auto"}, {"Agra Fort", 6, "Walk"}, {"Fatehpur Sikri", 20, "Car"}, {"Itmad-ud-Daula", 9, "Bus"}, {"Mehtab Bagh", 12, "Taxi"}}},
        {"Varanasi", {{"Kashi Vishwanath Temple", 7, "Auto"}, {"Assi Ghat", 5, "Walk"}, {"Dashashwamedh Ghat", 6, "Bus"}, {"Sarnath", 10, "Auto"}, {"Banaras Hindu University", 8, "Taxi"}}}
    };

    // Define connections between cities in India
    map<string, vector<Connection>> inter_city_connections = {
        {"Hyderabad", {{"Delhi", 1500, "Flight"}, {"Chennai", 700, "Train"}, {"Mumbai", 800, "Bus"}, {"Bangalore", 550, "Flight"}, {"Kolkata", 1600, "Flight"}, {"Jaipur", 1200, "Train"}, {"Goa", 600, "Flight"}, {"Agra", 1400, "Flight"}, {"Varanasi", 1300, "Train"}}},
        {"Delhi", {{"Hyderabad", 1500, "Flight"}, {"Chennai", 2200, "Flight"}, {"Mumbai", 1400, "Train"}, {"Bangalore", 1700, "Flight"}, {"Kolkata", 1500, "Flight"}, {"Jaipur", 300, "Bus"}, {"Goa", 1900, "Flight"}, {"Agra", 200, "Bus"}, {"Varanasi", 800, "Train"}}},
        {"Chennai", {{"Hyderabad", 700, "Train"}, {"Delhi", 2200, "Flight"}, {"Mumbai", 1300, "Flight"}, {"Bangalore", 350, "Train"}, {"Kolkata", 1700, "Flight"}, {"Jaipur", 1900, "Flight"}, {"Goa", 900, "Flight"}, {"Agra", 2100, "Flight"}, {"Varanasi", 1800, "Flight"}}},
        {"Mumbai", {{"Hyderabad", 800, "Bus"}, {"Delhi", 1400, "Train"}, {"Chennai", 1300, "Flight"}, {"Bangalore", 850, "Flight"}, {"Kolkata", 2000, "Flight"}, {"Jaipur", 1100, "Train"}, {"Goa", 400, "Bus"}, {"Agra", 1600, "Flight"}, {"Varanasi", 1800, "Flight"}}},
        {"Bangalore", {{"Hyderabad", 550, "Flight"}, {"Delhi", 1700, "Flight"}, {"Chennai", 350, "Train"}, {"Mumbai", 850, "Flight"}, {"Kolkata", 1900, "Flight"}, {"Jaipur", 2000, "Flight"}, {"Goa", 600, "Flight"}, {"Agra", 1800, "Flight"}, {"Varanasi", 1900, "Flight"}}},
        {"Kolkata", {{"Hyderabad", 1600, "Flight"}, {"Delhi", 1500, "Flight"}, {"Chennai", 1700, "Flight"}, {"Mumbai", 2000, "Flight"}, {"Bangalore", 1900, "Flight"}, {"Jaipur", 1700, "Flight"}, {"Goa", 1900, "Flight"}, {"Agra", 1700, "Flight"}, {"Varanasi", 600, "Train"}}},
        {"Jaipur", {{"Hyderabad", 1200, "Train"}, {"Delhi", 300, "Bus"}, {"Chennai", 1900, "Flight"}, {"Mumbai", 1100, "Train"}, {"Bangalore", 2000, "Flight"}, {"Kolkata", 1700, "Flight"}, {"Goa", 1900, "Flight"}, {"Agra", 250, "Bus"}, {"Varanasi", 1400, "Train"}}},
        {"Goa", {{"Hyderabad", 600, "Flight"}, {"Delhi", 1900, "Flight"}, {"Chennai", 900, "Flight"}, {"Mumbai", 400, "Bus"}, {"Bangalore", 600, "Flight"}, {"Kolkata", 1900, "Flight"}, {"Jaipur", 1900, "Flight"}, {"Agra", 2000, "Flight"}, {"Varanasi", 2000, "Flight"}}},
        {"Agra", {{"Hyderabad", 1400, "Flight"}, {"Delhi", 200, "Bus"}, {"Chennai", 2100, "Flight"}, {"Mumbai", 1600, "Flight"}, {"Bangalore", 1800, "Flight"}, {"Kolkata", 1700, "Flight"}, {"Jaipur", 250, "Bus"}, {"Goa", 2000, "Flight"}, {"Varanasi", 600, "Train"}}},
        {"Varanasi", {{"Hyderabad", 1300, "Train"}, {"Delhi", 800, "Train"}, {"Chennai", 1800, "Flight"}, {"Mumbai", 1800, "Flight"}, {"Bangalore", 1900, "Flight"}, {"Kolkata", 600, "Train"}, {"Jaipur", 1400, "Train"}, {"Goa", 2000, "Flight"}, {"Agra", 600, "Train"}}}
    };

    // Display options for the user to choose from
    cout << "Choose the type of travel:" << endl;
    cout << "1. Intra-city" << endl;
    cout << "2. Inter-city" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) { // Intra-city travel
        cout << "Choose a city:" << endl;
        cout << "1. Hyderabad" << endl;
        cout << "2. Delhi" << endl;
        cout << "3. Chennai" << endl;
        cout << "4. Mumbai" << endl;
        cout << "5. Bangalore" << endl;
        cout << "6. Kolkata" << endl;
        cout << "7. Jaipur" << endl;
        cout << "8. Goa" << endl;
        cout << "9. Agra" << endl;
        cout << "10. Varanasi" << endl;

        int city_index;
        cout << "Enter the index of the city: ";
        cin >> city_index;

        if (city_index < 1 || city_index > 10) {
            cerr << "Invalid city index!" << endl;
            return 1;
        }

        string selected_city;
        switch (city_index) {
            case 1:
                selected_city = "Hyderabad";
                break;
            case 2:
                selected_city = "Delhi";
                break;
            case 3:
                selected_city = "Chennai";
                break;
            case 4:
                selected_city = "Mumbai";
                break;
            case 5:
                selected_city = "Bangalore";
                break;
            case 6:
                selected_city = "Kolkata";
                break;
            case 7:
                selected_city = "Jaipur";
                break;
            case 8:
                selected_city = "Goa";
                break;
            case 9:
                selected_city = "Agra";
                break;
            case 10:
                selected_city = "Varanasi";
                break;
        }

        cout << "Places in " << selected_city << ":" << endl;
        for (int i = 0; i < intra_city_places[selected_city].size(); ++i) {
            cout << i + 1 << ". " << intra_city_places[selected_city][i].name << endl;
        }

        int source_index, destination_index;
        cout << "Enter the index of the source place: ";
        cin >> source_index;

        if (source_index < 1 || source_index > intra_city_places[selected_city].size()) {
            cerr << "Invalid source place index!" << endl;
            return 1;
        }

        cout << "Enter the index of the destination place: ";
        cin >> destination_index;

        if (destination_index < 1 || destination_index > intra_city_places[selected_city].size()) {
            cerr << "Invalid destination place index!" << endl;
            return 1;
        }

        // Print distance and means of transport for the selected source and destination places
        cout << "You selected to travel from " << intra_city_places[selected_city][source_index - 1].name << " to " << intra_city_places[selected_city][destination_index - 1].name << endl;
        cout << "Distance: " << intra_city_places[selected_city][destination_index - 1].distance - intra_city_places[selected_city][source_index - 1].distance << " km" << endl;
        cout << "Means of transport: " << intra_city_places[selected_city][source_index - 1].transport << endl;

    } else if (choice == 2) { // Inter-city travel
        cout << "Choose a source city:" << endl;
        cout << "1. Hyderabad" << endl;
        cout << "2. Delhi" << endl;
        cout << "3. Chennai" << endl;
        cout << "4. Mumbai" << endl;
        cout << "5. Bangalore" << endl;
        cout << "6. Kolkata" << endl;
        cout << "7. Jaipur" << endl;
        cout << "8. Goa" << endl;
        cout << "9. Agra" << endl;
        cout << "10. Varanasi" << endl;

        int source_index;
        cout << "Enter the index of the source city: ";
        cin >> source_index;

        if (source_index < 1 || source_index > 10) {
            cerr << "Invalid source city index!" << endl;
            return 1;
        }

        string source_city;
        switch (source_index) {
            case 1:
                source_city = "Hyderabad";
                break;
            case 2:
                source_city = "Delhi";
                break;
            case 3:
                source_city = "Chennai";
                break;
            case 4:
                source_city = "Mumbai";
                break;
            case 5:
                source_city = "Bangalore";
                break;
            case 6:
                source_city = "Kolkata";
                break;
            case 7:
                source_city = "Jaipur";
                break;
            case 8:
                source_city = "Goa";
                break;
            case 9:
                source_city = "Agra";
                break;
            case 10:
                source_city = "Varanasi";
                break;
        }

        cout << "Choose a destination city:" << endl;
        for (int i = 1; i <= 10; ++i) {
            if (i != source_index) {
                cout << i << ". ";
                switch (i) {
                    case 1:
                        cout << "Hyderabad" << endl;
                        break;
                    case 2:
                        cout << "Delhi" << endl;
                        break;
                    case 3:
                        cout << "Chennai" << endl;
                        break;
                    case 4:
                        cout << "Mumbai" << endl;
                        break;
                    case 5:
                        cout << "Bangalore" << endl;
                        break;
                    case 6:
                        cout << "Kolkata" << endl;
                        break;
                    case 7:
                        cout << "Jaipur" << endl;
                        break;
                    case 8:
                        cout << "Goa" << endl;
                        break;
                    case 9:
                        cout << "Agra" << endl;
                        break;
                    case 10:
                        cout << "Varanasi" << endl;
                        break;
                }
            }
        }

        int destination_index;
        cout << "Enter the index of the destination city: ";
        cin >> destination_index;

        if (destination_index < 1 || destination_index > 10 || destination_index == source_index) {
            cerr << "Invalid destination city index!" << endl;
            return 1;
        }

        string destination_city;
        switch (destination_index) {
            case 1:
                destination_city = "Hyderabad";
                break;
            case 2:
                destination_city = "Delhi";
                break;
            case 3:
                destination_city = "Chennai";
                break;
            case 4:
                destination_city = "Mumbai";
                break;
            case 5:
                destination_city = "Bangalore";
                break;
            case 6:
                destination_city = "Kolkata";
                break;
            case 7:
                destination_city = "Jaipur";
                break;
            case 8:
                destination_city = "Goa";
                break;
            case 9:
                destination_city = "Agra";
                break;
            case 10:
                destination_city = "Varanasi";
                break;
        }

        // Print available means of transport between the source and destination cities
        cout << "Available means of transport from " << source_city << " to " << destination_city << ":" << endl;
        for (const auto& connection : inter_city_connections[source_city]) {
            if (connection.destination_city == destination_city) {
                cout << "Transport: " << connection.transport << ", Distance: " << connection.distance << " km" << endl;
            }
        }

    } else {
        cerr << "Invalid choice!" << endl;
        return 1;
    }

    return 0;
}
