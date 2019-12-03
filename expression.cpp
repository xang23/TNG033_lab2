/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"
#include <cmath>
#include <iomanip>

//ADD implementation of the member functions for class Expression

bool Expression::isRoot(double d) const { //Är d en lösning för ett polynom
	
	if (std::abs((*this)(d)) < EPSILON) {
		return true;
	}
	
	return std::abs((*this)(d)) < EPSILON;
}




std::ostream& operator<<(std::ostream& os, const Expression& b) { //Display
	
		b.display(os << std::fixed << std::setprecision(2));
	
	return os;
}

