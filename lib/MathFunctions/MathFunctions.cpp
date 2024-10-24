// MathFunctions.cpp
#include "MathFunctions.h"
#include <cmath>

// Function to calculate the square root of a number
double squareRoot(double value) {
    if (value < 0.0) {
        return -1; // Return -1 for negative inputs to indicate an error
    }
    return std::sqrt(value);
}
