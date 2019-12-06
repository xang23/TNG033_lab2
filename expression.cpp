/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"
#include <cmath>
#include <iomanip>

//ADD implementation of the member functions for class Expression
//en funktion som tittar om expression har en rot alltså att d insatt i f ger svaret 0
//Denna körs för både log och pol
bool Expression::isRoot(double d) const { //Är d en lösning för ett polynom
	
	if (std::abs((*this)(d)) < EPSILON) {
		return true;
	}
	
	return std::abs((*this)(d)) < EPSILON;
}



//när något skrivs ut kallas display i subclasserna som sedan skickas hit för att skrivas ut.
//här ger vi varje ta en precision av 2 decimaler.
std::ostream& operator<<(std::ostream& os, const Expression& b) { //Display
	
		b.display(os << std::fixed << std::setprecision(2));
	
	return os;
}

