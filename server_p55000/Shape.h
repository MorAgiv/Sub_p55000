#pragma once
#include <string>
#include <random>

#pragma once

using namespace std;

class Shape
{
protected:
	//string name; //?
	string color_; //(enum?)
	int size_;
	int location_[3];// lat, lon, alt- can be random
	void setLocation();

public:
	virtual string shapeInfo() = 0;


};

