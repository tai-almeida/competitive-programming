#include <iostream>
using namespace std;

void percorre(int coordinate, int paths) {
    if(coordinate==0) {
        cout<<paths;
    }
    
    if(coordinate-5 >= 0) {
        coordinate = coordinate-5;
        paths++;
        percorre(coordinate, paths);
    } else if(coordinate-4>=0) {
        coordinate = coordinate-4;
        paths++;
        percorre(coordinate, paths);
    } else if(coordinate-3>=0) {
        coordinate = coordinate-3;
        paths++;
        percorre(coordinate, paths);
    } else if(coordinate-2>=0) {
        coordinate = coordinate-2;
        paths++;
        percorre(coordinate, paths);
    } else if(coordinate-1>=0) {
        coordinate = coordinate-1;
        paths++;
        cout<<paths;
    } 
}

int main() {
    int coordinate, paths=0;
    cin>>coordinate;
    if(coordinate>0 && coordinate<6) {
        paths = 1;
        cout<<paths;
    } else {
        percorre(coordinate, paths);
    }
    return 0;
}