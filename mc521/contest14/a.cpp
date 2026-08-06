#include <bits/stdc++.h>

using namespace std;

int main() {
    int n_cities, queries, test_cases;
    cin >> test_cases;
    vector<long long> cities, trips, closest_cities;
    for(int t = 0; t < test_cases; t++) {
        cin >> n_cities;
        cities.resize(n_cities);
        for(int i = 0; i < n_cities; i++) {
            cin >> cities[i];
        }
        closest_cities.resize(n_cities, 0);
        closest_cities[0] = 1;
        closest_cities[n_cities-1] = n_cities-2;
        for(int i = 1; i < n_cities-1; i++) {
            if((cities[i] - cities[i-1]) < (cities[i+1] - cities[i])) {
                closest_cities[i] = i-1;
            } else {
                closest_cities[i] = i+1;
            }
        }

        vector<long long> costRight(n_cities, 0), costLeft(n_cities, 0);
        for(int i = 0; i < n_cities-1; i++) {
            if(closest_cities[i] == i+1) {
                costRight[i+1] = costRight[i] + 1;
            } else {
                costRight[i+1] = costRight[i] + (cities[i+1] - cities[i]);
            }
            
        }

        for(int i = n_cities-1; i > 0; i--) {
            if(closest_cities[i] == i-1) {
                costLeft[i-1] = costLeft[i] + 1;
            } else {
                costLeft[i-1] = costLeft[i] + (cities[i] - cities[i-1]);
            }
        }

        cin >> queries;
        int city_x, city_y, cost;
        for(int i = 0; i < queries; i++) {
            cost = 0;
            cin >> city_x >> city_y;

            if(city_x > city_y) {
                cout << costLeft[city_y-1] - costLeft[city_x-1]  << endl;
            } else {
                cout << costRight[city_y-1] - costRight[city_x-1] << endl;
            }
        }
    }
}