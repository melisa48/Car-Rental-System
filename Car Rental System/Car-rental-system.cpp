#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Car {
public:
    std::string make;
    std::string model;
    std::string licensePlate;
    bool isAvailable;

    Car(std::string make, std::string model, std::string licensePlate)
        : make(make), model(model), licensePlate(licensePlate), isAvailable(true) {}
};

class Rental {
public:
    int rentalID;
    int carID;
    int customerID;
    time_t startDate;
    time_t endDate;

    Rental(int rentalID, int carID, int customerID, time_t startDate, time_t endDate)
        : rentalID(rentalID), carID(carID), customerID(customerID), startDate(startDate), endDate(endDate) {}
};

class CarRentalSystem {
private:
    std::vector<Car> cars;
    std::vector<Rental> rentals;
    int nextRentalID;
    int nextCarID;

public:
    CarRentalSystem() : nextRentalID(1), nextCarID(1) {}

    void addCar(std::string make, std::string model, std::string licensePlate) {
        cars.push_back(Car(make, model, licensePlate));
    }

    void displayCars() {
        for (const auto& car : cars) {
            std::cout << "ID: " << nextCarID << ", Make: " << car.make << ", Model: " << car.model
                << ", License Plate: " << car.licensePlate << ", Available: " << (car.isAvailable ? "Yes" : "No") << std::endl;
            nextCarID++;
        }
        nextCarID = 1;
    }

    void rentCar(int carID, int customerID, time_t startDate, time_t endDate) {
        if (carID > 0 && carID <= cars.size()) {
            Car& car = cars[carID - 1];
            if (car.isAvailable) {
                car.isAvailable = false;
                rentals.push_back(Rental(nextRentalID, carID, customerID, startDate, endDate));
                nextRentalID++;
            }
            else {
                std::cout << "Car with ID " << carID << " is not available for rent." << std::endl;
            }
        }
        else {
            std::cout << "Invalid car ID." << std::endl;
        }
    }

    void returnCar(int rentalID) {
        for (auto& rental : rentals) {
            if (rental.rentalID == rentalID) {
                Car& car = cars[rental.carID - 1];
                car.isAvailable = true;
                rental.endDate = std::time(0);
                std::cout << "Car with ID " << rental.carID << " has been returned." << std::endl;
                return;
            }
        }
        std::cout << "Rental with ID " << rentalID << " not found." << std::endl;
    }

    void displayRentalHistory() {
        for (const auto& rental : rentals) {
            char buffer[26];
            ctime_s(buffer, sizeof(buffer), &rental.startDate);
            std::cout << "Rental ID: " << rental.rentalID << ", Car ID: " << rental.carID
                << ", Customer ID: " << rental.customerID << ", Start Date: " << buffer;
            ctime_s(buffer, sizeof(buffer), &rental.endDate);
            std::cout << ", End Date: " << buffer;
        }
    }
};

int main() {
    CarRentalSystem system;

    system.addCar("Toyota", "Camry", "ABC123");
    system.addCar("Honda", "Civic", "DEF456");

    system.displayCars();

    system.rentCar(1, 101, std::time(0), std::time(0) + 3600);

    system.displayRentalHistory();

    system.returnCar(1);

    system.displayCars();

    return 0;
}
