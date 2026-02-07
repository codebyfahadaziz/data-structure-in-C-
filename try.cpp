#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int find_day_index(const string days[], const string &user_day) {
    for (int i = 0; i < 5; ++i) {
        string temp = days[i];
        for (char &c : temp) c = tolower(c);
        if (temp == user_day) return i;
    }
    return -1;
}

int find_slot_by_time(const string times_row[], const string &time_str) {
    for (int j = 0; j < 8; ++j) {
        if (times_row[j] == time_str) return j;
    }
    return -1;
}

int main() {
    string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // Times for each day (5 x 8)
    string times[5][8] = {
        {"8:30 - 9:20", "9:20 - 10:10", "10:10 - 11:00", "11:00 - 11:50", "11:50 - 12:40", "12:40 - 1:30", "1:30 - 2:20", "2:20 - 3:10"},
        {"8:00 - 8:50", "8:50 - 9:40", "9:40 - 10:30", "10:30 - 11:20", "11:20 - 12:10", "12:10 - 1:00", "1:00 - 1:50", "1:50 - 2:40"},
        {"8:30 - 9:20", "9:20 - 10:10", "10:10 - 11:00", "11:00 - 11:50", "11:50 - 12:40", "12:40 - 1:30", "1:30 - 2:20", "2:20 - 3:10"},
        {"9:00 - 9:50", "9:50 - 10:40", "10:40 - 11:30", "11:30 - 12:20", "12:20 - 1:10", "1:10 - 2:00", "2:00 - 2:50", "2:50 - 3:40"},
        {"8:30 - 9:20", "9:20 - 10:10", "10:10 - 11:00", "11:00 - 11:50", "11:50 - 12:40", "12:40 - 1:30", "1:30 - 2:20", "2:20 - 3:10"}
    };

    // Subjects
    string time_table[5][8] = {
        {"Free", "DSA", "Free", "Pro_and_Stats", "CN", "CN_lab", "CN_lab", "CN_lab"},
        {"DSA", "CN", "Pro_and_Stats", "Free", "Software_Engineering", "IS_lab", "IS_lab", "IS_lab"},
        {"DSA_LAB", "DSA_LAB", "DSA_LAB", "DSA", "Free", "Free", "Free", "Free"},
        {"IS", "Free", "Software_Engineering", "Pro_and_Stats", "Free", "AP", "AP", "AP"},
        {"IS", "Software_Engineering", "AP_LAB", "AP_LAB", "AP_LAB", "Free", "Free", "Free"}
    };

    // Room assignments for these subjects (use "---" for no room / free)
    string room_table[5][8] = {
        {"---", "A101", "---", "B204", "C303", "Lab-1", "Lab-1", "Lab-1"},
        {"A101", "C303", "B204", "---", "A105", "Lab-2", "Lab-2", "Lab-2"},
        {"Lab-3", "Lab-3", "Lab-3", "A101", "---", "---", "---", "---"},
        {"B204", "---", "A105", "C303", "---", "A201", "A201", "A201"},
        {"B204", "A105", "Lab-4", "Lab-4", "Lab-4", "---", "---", "---"}
    };

    // Known list of all rooms in the building/faculty (expand as needed)
    vector<string> all_rooms = {"A101","B204","C303","A105","A201","Lab-1","Lab-2","Lab-3","Lab-4","Hall-1"};

    cout << "Enter day (e.g. Monday): ";
    string user_day;
    cin >> user_day;
    for (char &c : user_day) c = tolower(c);

    int day_index = find_day_index(days, user_day);
    if (day_index == -1) {
        cout << "Invalid day entered.\n";
        return 0;
    }

    cout << "Enter desired makeup time (either slot number 1-8 or exact time string like \"9:20 - 10:10\"):\n";
    string input;
    // read entire line (slot or time); first try to read a token, if it's a number treat as slot, else read remainder
    // We'll use getline to be flexible
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    // trim leading/trailing spaces
    while (!input.empty() && isspace(input.front())) input.erase(input.begin());
    while (!input.empty() && isspace(input.back())) input.pop_back();

    int slot_index = -1;
    bool is_number = true;
    for (char ch : input) if (!isdigit(ch)) { is_number = false; break; }

    if (is_number && !input.empty()) {
        // user gave slot number
        int slot = stoi(input);
        if (slot >= 1 && slot <= 8) slot_index = slot - 1;
        else {
            cout << "Slot number out of range (1-8).\n";
            return 0;
        }
    } else {
        // user gave a time string, try to find matching slot in times[day_index]
        slot_index = find_slot_by_time(times[day_index], input);
        if (slot_index == -1) {
            cout << "Could not find that time on " << days[day_index] << ".\n";
            cout << "Available times on " << days[day_index] << ":\n";
            for (int j = 0; j < 8; ++j) cout << j+1 << ". " << times[day_index][j] << "\n";
            return 0;
        }
    }

    // Occupied rooms at that day+slot: we only have one recorded assignment per slot in this dataset
    set<string> occupied;
    string assigned_room = room_table[day_index][slot_index];
    if (assigned_room != "---" && assigned_room != "") {
        occupied.insert(assigned_room);
    }

    // Build available list = all_rooms - occupied
    vector<string> available;
    for (const string &r : all_rooms) {
        if (occupied.find(r) == occupied.end()) available.push_back(r);
    }

    cout << "\nRequested: " << days[day_index] << " | Slot " << (slot_index+1)
         << " (" << times[day_index][slot_index] << ")\n";

    if (time_table[day_index][slot_index] == "Free") {
        cout << "Note: that slot currently marked FREE (no scheduled lecture).\n";
    } else {
        cout << "Currently scheduled: " << time_table[day_index][slot_index]
             << "  in room: " << (assigned_room == "---" ? "no room assigned" : assigned_room) << "\n";
    }

    cout << "\nAvailable rooms at that time (from known room list):\n";
    if (available.empty()) {
        cout << "  None (all known rooms are occupied at that time).\n";
    } else {
        for (const string &r : available) cout << "  - " << r << "\n";
    }

    return 0;
}

