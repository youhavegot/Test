#pragma once
#define PI 3.1415926


int factorial(int);

class FAC {

public:
	FAC() {};

	float convert(float deg) {
		return deg*PI/180;
	};
};