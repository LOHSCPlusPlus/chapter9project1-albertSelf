#include <iostream>
#include <ifstream>
using namespace std;

const int MAX_NUM_CARS = 500;

bool menu(){
  bool exitmenu = false;
  cout << "Welcome to the Car list" << endl;
  cout 
  return exitmenu;
}

struct Cars{
  char array Car Name
  double MPG
  int Cylinders
  double Displacement
  double Horsepower
  double Weight
  double Acceleration
  int Model
  char array Origin
  bool ValidEntry
}

Cars: Cars{
  
}

int readCars(Cars Car[]) {
    ifstream carFile("cars.txt");
    int numCars = 0;
    while(carFile.peek() != EOF && numCars < MAX_NUM_CARS) {
        car[numCars] = readcars(carFile);
        numCars++;
    }
    return numCars;

int main() {
  




}