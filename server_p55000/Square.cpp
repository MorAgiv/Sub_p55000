#include "Square.h"

Square::Square()
{
	color_ = "blue";
	size_ = 2;
	Shape::setLocation();
}

string Square::shapeInfo(){
	string s = "Square , Color: " + color_ + ", Size: " + to_string(size_) + "Longitide: " + to_string(location_[0]) + ", Latitude: " +
		to_string(location_[1]) + ", Altitude: " + to_string(location_[2]);
	return s;
}
