#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

double ConvertToRadians(double degrees)
{
    return degrees * M_PI / 180.0;
}
double ConvertToDegrees(double radians)
{
    return radians * (180.0 / M_PI);
}

double ScaleWidth(double logoDiameter, double cylinderDiameter)
{
    double x = logoDiameter / cylinderDiameter;
    x = ConvertToDegrees(asin(logoDiameter / cylinderDiameter)) * ConvertToRadians(cylinderDiameter);
    return x;

}

double parseDouble(const char* str) {
    char* endptr;
    double value = std::strtod(str, &endptr);

    if (*endptr != '\0') {
        // Conversion failed, return NaN
        return std::numeric_limits<double>::quiet_NaN();
    }
    else {
        return value;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Not enough args";
        std::cerr << "Usage " << argv[0] << " <diameter logo> <diameter cylinder>";
        return -1;
    }

    double logoDiameter = parseDouble(argv[1]);
    if (std::isnan(logoDiameter)) {
        std::cerr << "Error parsing '" << argv[1] << ";";
        return -2;
    }

    double cylinderDiameter = parseDouble(argv[2]);
    if (std::isnan(cylinderDiameter)) {
        std::cerr << "Error parsing '" << argv[1] << ";";
        return -2;
    }

    double val = ScaleWidth(logoDiameter, cylinderDiameter);

    std::cout << "Horizontal Width:" << val;
}
