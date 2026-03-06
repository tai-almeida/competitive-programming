#include <iostream>

using namespace std;

int press_buttons(int first_button, int second_button) {
    if(first_button - 1 > second_button) {
        return 2*first_button - 1;
    } else if (second_button - 1 > first_button) {
        return 2*second_button - 1;
    } else {
        return first_button + second_button;
    }
}

int main() {
    int first_button, second_button; 
    
    cin >> first_button >> second_button;

    cout << press_buttons(first_button, second_button);

    return 0;
} 

