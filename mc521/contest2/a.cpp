#include <bits/stdc++.h>

using namespace std;

int greedy_scheduler(int cashiers, vector<int>& schedule, int client_interval) {
    int shortest = 0;
    for(int i=0; i< cashiers; i++) {
        if(schedule[i] < schedule[shortest]) {
            shortest = i;
        }
    }
    schedule[shortest] += client_interval;

    return shortest;
}

int main() {
    int cashiers, clients;
    cin >> cashiers >> clients;

    vector<int> schedule(clients, 0);
    vector<int> cashiers_order(clients, 0);

    int client_interval;
    for(int i=0; i<clients; i++) {
        cin >> client_interval;

        cashiers_order[i] = greedy_scheduler(cashiers, schedule, client_interval);
        
    }

    for(int i=0; i<clients; i++)  {
        if(i < clients-1) {
            cout << cashiers_order[i] + 1 << " ";
        } else {
            cout << cashiers_order[i] + 1;
        }
    }

    return 0;
}