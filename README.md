# Car-Rental-System
The Car Rental System is a C++ program that simulates a basic car rental management system. It allows users to add cars, display available cars, rent cars to customers, return rented cars, and view rental history.

## Features

- Add new cars to the system.
- Display the list of available cars.
- Rent cars to customers.
- Return rented cars.
- View rental history.

## Getting Started

1. Clone the repository to your local machine:

git clone https://github.com/yourusername/car-rental-system.git

2. Open the project in your preferred C++ IDE or compile it using a C++ compiler.

3. Build and run the program.

## Usage

1. Add cars to the system using the `addCar` function.
2. Display the list of available cars using the `displayCars` function.
3. Rent a car to a customer using the `rentCar` function.
4. View rental history using the `displayRentalHistory` function.
5. Return a rented car using the `returnCar` function.

## Example

```cpp
CarRentalSystem system;

// Add cars
system.addCar("Toyota", "Camry", "ABC123");
system.addCar("Honda", "Civic", "DEF456");

// Display cars
system.displayCars();

// Rent a car
system.rentCar(1, 101, std::time(0), std::time(0) + 3600);

// Display rental history
system.displayRentalHistory();

// Return the rented car
system.returnCar(1);

// Display cars after return
system.displayCars();
