#include "Circle.h"

Circle::Circle()
{
	color_ = "green";
	size_ = 2;
	Shape::setLocation();
}

string Circle::shapeInfo() {
	string s = "Circle, Color: " + color_ + ", Size: " + to_string(size_) + "Longitide: " + to_string(location_[0]) + ", Latitude: " +
		to_string(location_[1]) + ", Altitude: " +to_string(location_[2]);
	return s;
}
