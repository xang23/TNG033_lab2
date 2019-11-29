/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"
#include <cmath>
#include <iomanip>

//ADD implementation of the member functions for class Expression


std::ostream& operator<<(std::ostream& os, const Expression& b) { //Display
	
	b.display(os);
	//os << std::setprecision(3)

	return os;
}

