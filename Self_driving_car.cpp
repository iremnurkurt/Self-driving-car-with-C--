#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Define car properties
struct Car {
    double x, y, heading;  // Position and heading
    double speed;          // Speed
    vector<double> wheelAngles; // Wheel angles (for steering)
};

// Function to update car position based on speed and heading
void updatePosition(Car& car) {
    car.x += car.speed * cos(car.heading);
    car.y += car.speed * sin(car.heading);
}

// Function to apply steering based on wheel angles
void applySteering(Car& car) {
    // Calculate turning radius based on wheel angles
    double turningRadius = 0;  // Initialize to avoid potential division by zero

    if (abs(car.wheelAngles[0]) > 0 || abs(car.wheelAngles[1]) > 0) {
    turningRadius = 0.5 * car.length / tan(max(abs(car.wheelAngles[0]), abs(car.wheelAngles[1])));
}
    // Update heading based on turning radius and speed
    car.heading += car.speed / turningRadius;
}

// Function to simulate movement
void simulate(Car& car) {
    // Apply steering
    applySteering(car);

    // Update position
    updatePosition(car);
}

int main() {
    Car car = {0, 0, 0, 5, {0, 0}};  // Initial position, speed, and wheel angles

    for (int i = 0; i < 100; i++) {
        // Adjust wheel angles based on a simple controller (e.g., to follow a path)
        car.wheelAngles[0] = 0.1; // Example steering command

        // Simulate movement
        simulate(car);

        // Print car state
        cout << "Position: (" << car.x << ", " << car.y << ")" << endl;
        cout << "Heading: " << car.heading << endl;
    }

    return 0;
}

