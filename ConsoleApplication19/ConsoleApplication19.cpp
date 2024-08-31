#include <iostream>
using namespace std;

class Vehicle {
public:
	string make;
	string model;
	int year;

	Vehicle(string Veh_make, string Veh_model, int Veh_year) {
		make = Veh_make;
		model = Veh_model;
		year = Veh_year;
	}
	virtual void displayInfo() const {
		cout << "Mark: " << make << ", Model: " << model << ", Year: " << year << endl;
	}
	string getMake() const {
		return make;
	}
	string getModel() const {
		return model;
	}
	int getYear() const {
		return year;
	}
};

class Engine {
public:
	int horsepower;
	double displacement;

	Engine(int Engine_horsepower, double Engine_displacement) {
		horsepower = Engine_horsepower;
		displacement = Engine_displacement;
	}
	virtual void displayInfo() const {
		cout << "Horsepower: " << horsepower << ", Displacement: " << displacement << endl;
	}

	int getHorsepower() const {
		return horsepower;
	}

	double getDisplacement() const {
		return displacement;
	}
};

class Car : public Vehicle, public Engine {
public:
	int numberOfDoors;

	Car(string Car_make, string Car_model, int Car_year, int Car_horsepower, double Car_displacement, int Car_numberOfDoors)
		: Vehicle(Car_make, Car_model, Car_year),
		Engine(Car_horsepower, Car_displacement),
		numberOfDoors(Car_numberOfDoors){}

	void displayInfo() const override{
		cout << "Mark: " << make << ", Model: " << model << ", Year: " << year << ", Horsepower: " << horsepower << ", Displacement: " << displacement << ", NumberOfDoors: " << numberOfDoors << endl;
	}

	int getNumberOfDoors() {
		return numberOfDoors;
	}
};

class Truck : public Vehicle, public Engine {
public:
	double loadCapacity;

	Truck(string Truck_make, string Truck_model, int Truck_year, int Truck_horsepower, double Truck_displacement, double Truck_loadCapacity)
		: Vehicle(Truck_make, Truck_model, Truck_year),
		Engine(Truck_horsepower, Truck_displacement),
		loadCapacity(Truck_loadCapacity){}


	void displayInfo() const override {
		cout << "Mark: " << make << ", Model: " << model << ", Year: " << year << ", Horsepower: " << horsepower << ", Displacement: " << displacement << ", loadCapacity: " << loadCapacity << endl;
	}
	
	double getloadCapacity() {
		return loadCapacity;
	}
};

class ElectricVehicle : public Vehicle {
public:
	double batteryCapacity;
	int range;

	ElectricVehicle(string Electric_make, string Electric_model, int Electric_year, double Electric_batteryCapacity, int Electric_range)
		:Vehicle(Electric_make,Electric_model,Electric_year),
		batteryCapacity(Electric_batteryCapacity),
		range(Electric_batteryCapacity){}

	void displayInfo() const override {
		cout << "Mark: " << make << ", Model : " << model << ", Year : " << ", batteryCapacity : " << batteryCapacity << ", Range : " << range << endl;
	}

	double getBatteryCapacity() const {
		return batteryCapacity;
	}

	int getRange() const {
		return range;
	}

};

class ElectricCar : public ElectricVehicle, public Car {
public:
	ElectricCar(string make, string model, int year, int horsepower, double displacement, int numberOfDoors, double batteryCapacity, int range)
	:ElectricVehicle(make,model,year,batteryCapacity,range),
		Car(make,model,year,horsepower,displacement,numberOfDoors){}
		
	void displayInfo() const override {
		cout << "Mark: " << Car::make << ", Model: " << Car::model << ", Year: " << ElectricVehicle::year << ", Horsepower: " << horsepower << ", Displacement: " << displacement << ", NumberOfDoors: " << numberOfDoors << ", BatteryCapacity" << batteryCapacity << ", Range: " << range << endl;
	}
};

int main()
{
	Car car1("Mercedes", "Gt63", 1999, 240, 3.0, 4);
	car1.displayInfo();
	Vehicle vehicle1("Mercedes", "Gt63", 1999);
	vehicle1.displayInfo();
	Engine engine1(240, 20.0);
	engine1.displayInfo();
	Truck truck1("Mercedes", "Gt63", 1999,240,3.0,4.0);
	truck1.displayInfo();
	ElectricVehicle electricvehicle1("Bmw", "M5", 1999, 4.0, 5);
	electricvehicle1.displayInfo();
	ElectricCar electriccar1("Audi", "Rs6", 1999, 500, 4.0, 6, 4.0, 5);
	electriccar1.displayInfo();

	cout << "Get vehicle: " << vehicle1.getMake() << endl;
	cout << "Get vehicle: " << vehicle1.getModel() << endl;
	cout << "Get vehicle: " << vehicle1.getYear() << endl;
	cout << "Get engine: " << engine1.getDisplacement() << endl;
	cout << "Get engine: " << engine1.getHorsepower() << endl;
	cout << "Get Car: " << car1.getDisplacement() << endl;
	cout << "Get Car: " << car1.getHorsepower() << endl;
	cout << "Get Car: " << car1.getMake() << endl;
	cout << "Get Car: " << car1.getModel() << endl;
	cout << "Get Car: " << car1.getNumberOfDoors() << endl;
	cout << "Get Car: " << car1.getYear() << endl;
	cout << "Get Truck: " << truck1.getDisplacement() << endl;
	cout << "Get Truck: " << truck1.getHorsepower() << endl;
	cout << "Get Truck: " << truck1.getloadCapacity() << endl;
	cout << "Get Truck: " << truck1.getMake() << endl;
	cout << "Get Truck: " << truck1.getModel() << endl;
	cout << "Get Truck: " << truck1.getYear() << endl;
	cout << "Get ElectricVehicle: " << electricvehicle1.getBatteryCapacity() << endl;
	cout << "Get ElectricVehicle: " << electricvehicle1.getMake() << endl;
	cout << "Get ElectricVehicle: " << electricvehicle1.getModel() << endl;
	cout << "Get ElectricVehicle: " << electricvehicle1.getRange() << endl;
	cout << "Get ElectricVehicle: " << electricvehicle1.getYear() << endl;
	cout << "Get ElectricCar: " << electriccar1.getBatteryCapacity() << endl;
	cout << "Get ElectricCar: " << electriccar1.getDisplacement() << endl;
	cout << "Get ElectricCar: " << electriccar1.getHorsepower() << endl;
	cout << "Get ElectricCar: " << electriccar1.getNumberOfDoors() << endl;
	cout << "Get ElectricCar: " << electriccar1.getRange() << endl;



}

