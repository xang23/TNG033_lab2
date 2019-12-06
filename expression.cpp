/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"
#include <cmath>
#include <iomanip>

//ADD implementation of the member functions for class Expression
//en funktion som tittar om expression har en rot allts� att d insatt i f ger svaret 0
//Denna k�rs f�r b�de log och pol
bool Expression::isRoot(double d) const { //�r d en l�sning f�r ett polynom
	
	if (std::abs((*this)(d)) < EPSILON) {
		return true;
	}
	
	return std::abs((*this)(d)) < EPSILON;
}



//n�r n�got skrivs ut kallas display i subclasserna som sedan skickas hit f�r att skrivas ut.
//h�r ger vi varje ta en precision av 2 decimaler.
std::ostream& operator<<(std::ostream& os, const Expression& b) { //Display
	
		b.display(os << std::fixed << std::setprecision(2));
	
	return os;
}

