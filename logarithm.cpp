/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//ADD implementation of the member functions for class Logarithm
//Default constructor that creates log2X
Logarithm::Logarithm() : Expression(), c1{ 0 }, c2{ 1 }, b { 2 } //Good programin practise to call the parent constructor
{
	double v1[2]{ 0.0,1.0 };
	exp_ = new Polynomial{ 1, v1 };

	

}


//A constructor that given an expression E and constant c1, c2 and b creates the logarithm c1+c2Xlogb(E)
	//Logarithm(*, int c1, int c2, int b);	



//A copy constructor not a clone
Logarithm* Logarithm::clone() const {
	//how does this work

	return new Logarithm(*this);
}

//function isRoot
bool Logarithm::isRoot(double d) const{
	
	return true;
}
//Overload function called operator()
double Logarithm::operator()(double d) const{
	
	return 0;
}

//All expressions should be cloneble copies.





//Stream insertion operator<<
void Logarithm::display(std::ostream& os)const {
	if (c1 != 0 && (c2 != 0 || b != 1) && exp_!= nullptr) {
		os << c1 << " + " << c2 << "* log_" << b << "(" << *exp_ << ")";
	}
	else if (c1 == 0 && (c2 != 0 || b != 1) && exp_ != nullptr) {
		os << c2 << "* log_" << b << "(" << *exp_ << ")";
	}
	else
		os << c1;
}

//Destructor
Logarithm::~Logarithm() {
	
	delete[] exp_;
	exp_ = nullptr; 

}