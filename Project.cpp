#include <iostream>
#include <fstream>
using namespace std;

const int MAX_NUM_CARS = 500;
const int MAX_NAME_CHAR = 100;
bool menu(){
  bool exitmenu = false;
  cout << "Welcome to the Car list" << endl;
  return exitmenu;
}

struct Cars{
  enum {MAX_NAME_CHAR=100};
  char carName[MAX_NAME_CHAR];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[MAX_NAME_CHAR];
  bool validEntry;
};

Cars readcars(ifstream &inFile){
    Cars cars; 
    inFile.get(cars.carName, Cars::MAX_NAME_CHAR, ';');
    inFile.ignore(100,';');
    inFile >> cars.mpg;
    inFile.ignore(100,';');
    inFile >> cars.cylinders;
    inFile.ignore(100,';');
    inFile >> cars.displacement;
    inFile.ignore(100,';');
    inFile >> cars.horsepower;
    inFile.ignore(100,';');
    inFile >> cars.weight;
    inFile.ignore(100,';');
    inFile >> cars.acceleration;
    inFile.ignore(100,';');
    inFile >> cars.model;
    inFile.ignore(100,';');
    inFile >> cars.origin;
    inFile.ignore(100,'\n');
    cars.validEntry = !inFile.eof();
    return cars;
}

//Cars::Cars() {

//}


int readCarData(Cars Car[]) {
    ifstream carFile("cars.txt");
    int numCars = 0;
    while(carFile.peek() != EOF && numCars < MAX_NUM_CARS) {
        Car[numCars] = readcars(carFile);
        numCars++;
    }
    return numCars;
}

/*int addCar(const char car[]){
    int temp = 0;
    cout << car;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << car;
        cin >> temp;
    }
    return temp;
}*/

void printCars(Cars car[], int numCars){
  for(int index = 0; index < numCars; index++){
      cout << car[index].carName;
      cout << endl;
    }
  }

int main() {
  int numCars = 0;
  Cars car[MAX_NUM_CARS];
  numCars = readCarData(car);
  printCars(car, numCars);
}