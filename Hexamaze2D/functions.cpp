#include <iostream>
#include <cmath>

bool isPointInsideRotatedRectangle(double x, double y, double rectCenterX, double rectCenterY, double rectWidth, double rectHeight, double rotationAngle) {
    // Translate point to local coordinate system
    double xPrime = x - rectCenterX;
    double yPrime = y - rectCenterY;

    // Rotate the point
    double cosAngle = cos(-rotationAngle);
    double sinAngle = sin(-rotationAngle);
    double xDoublePrime = xPrime * cosAngle + yPrime * sinAngle;
    double yDoublePrime = -xPrime * sinAngle + yPrime * cosAngle;

    // Calculate half-width and half-height of the unrotated rectangle
    double halfWidth = rectWidth / 2;
    double halfHeight = rectHeight / 2;

    // Check if the rotated point is inside the unrotated rectangle
    if (std::abs(xDoublePrime) <= halfWidth && std::abs(yDoublePrime) <= halfHeight) {
        return true;
    }

    return false;
}