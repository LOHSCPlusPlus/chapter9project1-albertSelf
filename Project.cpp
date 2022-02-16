#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_NUM_CARS = 500;
const int MAX_NAME_CHAR = 100;



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
  Cars();
};

void getInt(const char info[], int &val);
void getDouble(const char info[], double &val);
void getCstring(const char info[], char val[]);
void printCars(Cars car[], int numCars);
void addCar(Cars cars[], int &numCars);
void removeCar(Cars cars[]);
void findOrigin(Cars car[], int numCars);

void menu(Cars cars[], int &numCars)
 {
  int option = 0;
  while(option != 5){
    cout << "Welcome to the car list" << endl;
    cout << "Select a menu option: " << endl; 
    cout << "1. Show Car list" << endl;
    cout << "2. Add a Car to the list" << endl;
    cout << "3. Search Car by origin" << endl;
    cout << "4. Remove a car from the list" << endl;
    cout << "5. Exit Car List" << endl;
    cin >> option;
    switch (option)
    {
      case 1:
      printCars(cars, numCars);
      break;
      case 2:
      addCar(cars, numCars);
      break;
      case 3:
      findOrigin(cars, numCars);
      break;
      case 4:
      removeCar(cars);
      break;
    }
  }
  cout << "Thank you for using our car list" << endl;
}

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

Cars::Cars() {
for(int index = 0; index < MAX_NAME_CHAR; index++){
  carName[index] = '0';
}
mpg = 0;
cylinders = 0;
displacement = 0;
horsepower = 0;
weight = 0;
acceleration = 0;
model = 0;
for(int index = 0; index < MAX_NAME_CHAR; index++){
  origin[index] = '0';
}
validEntry = false;
}

void findOrigin(Cars car[], int numCars){
  cout << "What Origin would you like to search? : ";
  char term[MAX_NAME_CHAR];
  cin >> term;
  for(int index = 0; index < numCars; index++){
    if(strcmp(car[index].origin, term) == 0 && car[index].validEntry == true) {
      cout << index << ". ";
      cout << car[index].carName << " ";
      cout << car[index].mpg << " ";
      cout << car[index].cylinders << " ";
      cout << car[index].displacement << " ";
      cout << car[index].horsepower << " ";
      cout << car[index].weight << " ";
      cout << car[index].acceleration << " ";
      cout << car[index].model << " ";
      cout << endl;
    }
  }
}

int readCarData(Cars Car[]) {
    ifstream carFile("cars.txt");
    int numCars = 0;
    while(carFile.peek() != EOF && numCars < MAX_NUM_CARS) {
        Car[numCars] = readcars(carFile);
        numCars++;
    }
    return numCars;
}

void addCar(Cars cars[], int &numCars) {
    if(numCars == MAX_NUM_CARS){
      cout << "Maximum amount of cars reached";
      return;
    }
    getCstring("Name", cars[numCars].carName);
    getDouble("MPG", cars[numCars].mpg);
    getInt("Cylinders", cars[numCars].cylinders);
    getDouble("Displacement", cars[numCars].displacement);
    getDouble("Horse Power", cars[numCars].horsepower);
    getDouble("Weight", cars[numCars].weight);
    getDouble("Acceleration", cars[numCars].acceleration);
    getInt("Model", cars[numCars].model);
    getCstring("Origin", cars[numCars].origin);
    cars[numCars].validEntry = true;
    numCars++;
}

void getDouble(const char info[], double &val){
  cout << "Enter " << info << " of car: ";
  cin >> val;
  while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
      cout << "Enter " << info << "of car: ";
      cin >> val;
    }
}

void getInt(const char info[], int &val){
  cout << "Enter " << info << " of car: ";
  cin >> val;
  while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
      cout << "Enter " << info << "of car: ";
      cin >> val;
    }
}

void getCstring(const char info[], char val[]){
  cout << "Enter " << info << " of car: ";
  cin >> val;
  while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
      cout << "Enter " << info << "of car: ";
      cin >> val;
    }
}

void printCars(Cars car[], int numCars){
  for(int index = 0; index < numCars; index++){
      if(car[index].validEntry == true){
      cout << index << ". ";
      cout << car[index].carName << " ";
      cout << car[index].mpg << " ";
      cout << car[index].cylinders << " ";
      cout << car[index].displacement << " ";
      cout << car[index].horsepower << " ";
      cout << car[index].weight << " ";
      cout << car[index].acceleration << " ";
      cout << car[index].model << " ";
      cout << car[index].origin << " ";
      cout << endl;
      }
    }
  }


void removeCar(Cars car[]){
  cout << "Which car number would you like to remove? ";
  int index = 0;
  cin >> index;
  car[index].validEntry = false;
}


int main() {
  int numCars = 0;
  Cars car[MAX_NUM_CARS];
  numCars = readCarData(car);
  menu(car, numCars);
  return 0;
}