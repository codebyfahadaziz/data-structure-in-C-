#include <iostream>
using namespace std;

// Global (kept for compatibility with your original approach)
int exit_car = 0;

// =========================
// Node for queues (entry)
// =========================
class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

// =========================
// Queue (linked list) - entry queue
// =========================
class quene {
public:
    int size;
    node* front;
    node* rear;
    quene() {
        front = rear = NULL;
        size = 0;
    }

    // push at rear (enqueue)
    void push(int val) {
        node* newcar = new node(val); // push back
        if (front == NULL) {
            front = rear = newcar;
        }
        else {
            rear->next = newcar;
            rear = newcar;
        }
        size++;
    }

    // pop from front (dequeue). sets global exit_car
    void pop() {
        if (front == NULL) {
            // nothing to pop
            exit_car = -1;
            return;
        }
        node* temp = front;
        front = front->next;
        exit_car = temp->data;
        delete temp;
        size--;
        if (front == NULL) rear = NULL;
    }

    // insert at front (for emergency vehicles)
    void push_front(int val) {
        node* newcar = new node(val);
        if (front == NULL) {
            front = rear = newcar;
        } else {
            newcar->next = front;
            front = newcar;
        }
        size++;
    }

    // remove a specific vehicle id from this queue
    // returns true if removed, false otherwise
    bool removeValue(int val) {
        if (front == NULL) return false;
        node* curr = front;
        node* prev = NULL;
        while (curr != NULL) {
            if (curr->data == val) {
                // found
                if (prev == NULL) { // removing front
                    front = curr->next;
                    if (front == NULL) rear = NULL;
                } else {
                    prev->next = curr->next;
                    if (curr == rear) rear = prev;
                }
                delete curr;
                size--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    // check if a vehicle id exists in this queue
    bool contains(int val) {
        node* curr = front;
        while (curr != NULL) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        node* temp = front;
        if(temp==NULL){
            cout << "(empty)";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

// =========================
// Node for stacks (exit)
// =========================
class node1 {
public:
    int data;
    node1* next;
    node1(int val) {
        data = val;
        next = NULL;
    }
};

// =========================
// Stack (linked list) - exit stack
// =========================
class stack { // push front = push on top
public:
    node1* top;
    stack() {
        top = NULL;
    }

    // push using global exit_car (keeps your original global style)
    void push() {
        node1* newnode = new node1(exit_car);
        if (top == NULL) {
            top = newnode;
        }
        else {
            newnode->next = top;
            top = newnode;
        }
    }

    // push by value (helper)
    void pushValue(int val) {
        node1* newnode = new node1(val);
        newnode->next = top;
        top = newnode;
    }

    int pop() {
        if (top == NULL) return -1;
        node1* temp = top;
        int v = temp->data;
        top = top->next;
        delete temp;
        return v;
    }

    void display() {
        node1* temp = top;
        if (temp == NULL) {
            cout << "(empty)";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

// =========================
// Multi-lane system
// =========================
const int LANES = 4;
quene lanesQ[LANES];
stack lanesS[LANES];
bool laneOperational[LANES]; // true = working, false = malfunction

// Helper: get lane with minimum queue size among operational lanes (optionally exclude a lane)
int leastBusyLane(int excludeLane = -1) {
    int best = -1;
    int bestSize = INT_MAX;
    for (int i = 0; i < LANES; ++i) {
        if (!laneOperational[i]) continue;
        if (i == excludeLane) continue;
        if (lanesQ[i].size < bestSize) {
            bestSize = lanesQ[i].size;
            best = i;
        }
    }
    return best; // -1 if none operational
}

// arrive: normal arrival to specified lane (push at rear)
void arrive(int vehicle_id, int lane_id) {
    if (lane_id < 0 || lane_id >= LANES) {
        cout << "Invalid lane\n";
        return;
    }
    if (!laneOperational[lane_id]) {
        cout << "Lane " << lane_id << " is not operational. Redirecting to least busy lane.\n";
        int l = leastBusyLane(lane_id);
        if (l == -1) {
            cout << "No operational lanes available. Vehicle " << vehicle_id << " cannot arrive now.\n";
            return;
        }
        lanesQ[l].push(vehicle_id);
        cout << "Vehicle " << vehicle_id << " sent to lane " << l << " (as lane " << lane_id << " is down).\n";
        return;
    }
    lanesQ[lane_id].push(vehicle_id);
    cout << "Vehicle " << vehicle_id << " arrived at lane " << lane_id << ".\n";
}

// handle_emergency: ambulance goes to front of queue of lane (push_front)
void handle_emergency(int vehicle_id, int lane_id) {
    if (lane_id < 0 || lane_id >= LANES) {
        cout << "Invalid lane\n";
        return;
    }
    if (!laneOperational[lane_id]) {
        cout << "Lane " << lane_id << " is not operational. Redirecting emergency to least busy lane.\n";
        int l = leastBusyLane(lane_id);
        if (l == -1) {
            cout << "No operational lanes available. Emergency cannot be inserted.\n";
            return;
        }
        lanesQ[l].push_front(vehicle_id);
        cout << "Emergency vehicle " << vehicle_id << " inserted at front of lane " << l << ".\n";
        return;
    }
    lanesQ[lane_id].push_front(vehicle_id);
    cout << "Emergency vehicle " << vehicle_id << " inserted at front of lane " << lane_id << ".\n";
}

// process_toll: move front of entry queue to exit stack for a lane
void process_toll(int lane_id) {
    if (lane_id < 0 || lane_id >= LANES) {
        cout << "Invalid lane\n";
        return;
    }
    if (!laneOperational[lane_id]) {
        cout << "Lane " << lane_id << " is not operational. Cannot process toll.\n";
        return;
    }
    if (lanesQ[lane_id].size == 0) {
        cout << "Lane " << lane_id << " entry queue is empty.\n";
        return;
    }
    // use quene.pop() to set exit_car
    lanesQ[lane_id].pop();
    if (exit_car == -1) {
        cout << "Error popping from queue.\n";
        return;
    }
    // push into corresponding exit stack
    lanesS[lane_id].push(); // uses global exit_car
    cout << "Processed vehicle " << exit_car << " from lane " << lane_id << " to exit stack.\n";
    // reset exit_car (optional)
    exit_car = 0;
}

// request_lane_switch: vehicle requests to switch from current_lane to the least busy lane
void request_lane_switch(int vehicle_id, int current_lane) {
    if (current_lane < 0 || current_lane >= LANES) {
        cout << "Invalid source lane\n";
        return;
    }
    if (!laneOperational[current_lane]) {
        cout << "Current lane is not operational; cannot switch from it.\n";
        return;
    }
    // check vehicle exists in current lane
    if (!lanesQ[current_lane].contains(vehicle_id)) {
        cout << "Vehicle " << vehicle_id << " not found in lane " << current_lane << ".\n";
        return;
    }
    int target = leastBusyLane(current_lane);
    if (target == -1) {
        cout << "No other operational lanes to switch to.\n";
        return;
    }
    // ensure target has strictly fewer vehicles
    if (lanesQ[target].size >= lanesQ[current_lane].size) {
        cout << "No lane has fewer vehicles than current lane; switch denied.\n";
        return;
    }
    // remove from current and add to target (simulate temporary holding)
    bool removed = lanesQ[current_lane].removeValue(vehicle_id);
    if (!removed) {
        cout << "Failed to remove vehicle from current lane.\n";
        return;
    }
    // simulate holding (not stored separately here, we directly enqueue to target)
    lanesQ[target].push(vehicle_id);
    cout << "Vehicle " << vehicle_id << " moved from lane " << current_lane << " to lane " << target << ".\n";
}

// malfunction_lane: mark lane as malfunction and transfer its entry queue vehicles to least-busy operational lane
void malfunction_lane(int lane_id) {
    if (lane_id < 0 || lane_id >= LANES) {
        cout << "Invalid lane\n";
        return;
    }
    if (!laneOperational[lane_id]) {
        cout << "Lane already malfunctioning.\n";
        return;
    }
    laneOperational[lane_id] = false;
    cout << "Lane " << lane_id << " has malfunctioned.\n";

    // transfer all vehicles in its entry queue to the least busy functioning lane(s)
    // Keep transferring while there are vehicles
    while (lanesQ[lane_id].size > 0) {
        int target = leastBusyLane(lane_id);
        if (target == -1) {
            cout << "No functioning lanes to transfer to. Remaining vehicles stay in broken lane.\n";
            break;
        }
        // pop from malfunctioning lane and push to target
        lanesQ[lane_id].pop(); // sets exit_car to the popped vehicle id
        int vid = exit_car;
        if (vid == -1) break;
        lanesQ[target].push(vid);
        cout << "Transferred vehicle " << vid << " from lane " << lane_id << " to lane " << target << ".\n";
        exit_car = 0;
    }
}

// repair_lane: mark lane operational again
void repair_lane(int lane_id) {
    if (lane_id < 0 || lane_id >= LANES) {
        cout << "Invalid lane\n";
        return;
    }
    laneOperational[lane_id] = true;
    cout << "Lane " << lane_id << " repaired and operational.\n";
}

// exit_system: vehicle exits from exit stack of lane (pop stack)
void exit_system(int lane_id) {
    if (lane_id < 0 || lane_id >= LANES) {
        cout << "Invalid lane\n";
        return;
    }
    int v = lanesS[lane_id].pop();
    if (v == -1) {
        cout << "Exit stack for lane " << lane_id << " is empty.\n";
    } else {
        cout << "Vehicle " << v << " exited system from lane " << lane_id << ".\n";
    }
}

// get_lane_status: show queue size and stack size and operational status
void get_lane_status() {
    cout << "=== Lane Status ===\n";
    for (int i = 0; i < LANES; ++i) {
        // compute stack size (walk stack)
        int stackSize = 0;
        node1* t = lanesS[i].top;
        while (t) {
            stackSize++;
            t = t->next;
        }
        cout << "Lane " << i << " | Entry(" << lanesQ[i].size << ") ";
        cout << "| ExitStack(" << stackSize << ") ";
        cout << "| " << (laneOperational[i] ? "Operational" : "Malfunction") << "\n";
    }
    cout << "===================\n";
}

// display full content for debugging
void display_all() {
    cout << "=== Full Lanes Content ===\n";
    for (int i = 0; i < LANES; ++i) {
        cout << "Lane " << i << " entry: ";
        lanesQ[i].display();
        cout << "  | exit stack(top?bottom): ";
        lanesS[i].display();
        cout << "\n";
    }
    cout << "=========================\n";
}

// =========================
// DEMO main
// =========================
int main() {
    // initialize all lanes as operational
    for (int i = 0; i < LANES; ++i) laneOperational[i] = true;

    // Sample arrivals
    arrive(101, 0);
    arrive(102, 0);
    arrive(201, 1);
    arrive(202, 1);
    arrive(301, 2);
    arrive(401, 3);

    cout << "\nInitial state:\n";
    display_all();

    // Emergency arrives at lane 0 (ambulance)
    cout << "\n-- Emergency (999) arrives at lane 0 --\n";
    handle_emergency(999, 0);
    display_all();

    // Process toll on lane 0 (moves front -> exit stack)
    cout << "\n-- Processing toll on lane 0 twice --\n";
    process_toll(0);
    process_toll(0);
    display_all();

    // Request lane switch: vehicle 202 (currently lane 1) tries to switch
    cout << "\n-- Vehicle 202 requests to switch from lane 1 --\n";
    request_lane_switch(202, 1);
    display_all();

    // Malfunction lane 2
    cout << "\n-- Lane 2 malfunctions --\n";
    malfunction_lane(2);
    display_all();

    // Try processing on a malfunction lane
    cout << "\n-- Trying to process toll on broken lane 2 --\n";
    process_toll(2);

    // Repair lane 2
    cout << "\n-- Repairing lane 2 --\n";
    repair_lane(2);
    display_all();

    // Exit some cars from exit stacks
    cout << "\n-- Exiting cars from exit stacks --\n";
    exit_system(0);
    exit_system(0);
    exit_system(1);
    display_all();

    // Final status
    cout << "\nFinal status:\n";
    get_lane_status();

    return 0;
}

