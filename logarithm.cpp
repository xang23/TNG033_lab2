/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//ADD implementation of the member functions for class Logarithm
//Default constructor that creates log2X
Logarithm::Logarithm() : Expression(), c1{ 0 }, c2{ 1 }, b{ 2 } //Good programin practise to call the parent constructor
{
	double v1[2]{ 0.0, 1.0 };
	exp_ = new Polynomial{ 1, v1 };

	//delete[] v1;

}


//A constructor that given an expression E and constant c1, c2 and b creates the logarithm c1+c2Xlogb(E)
	//Logarithm(*, int c1, int c2, int b);	
Logarithm::Logarithm(const Expression &E, const double c1, const double c2, const int b) : Expression(), c1{ c1 }, c2{ c2 }, b{b}{

	exp_ = E.clone();
}

//CopyContructor
Logarithm::Logarithm(const Logarithm& c) : Expression()
{
	c1 = c.c1;
	c2 = c.c2;
	b = c.b;
	exp_ = c.exp_->clone(); //deep copy av det som finns i c.exp_
	
}

//A copy constructor not a clone
Logarithm* Logarithm::clone() const {
	//how does this work
	return new Logarithm(*this);
}




//Overload function called operator(), Evaluate an expression E, calculate the answer if we throw in our double d
double Logarithm::operator()(double d) const {
	
	return c1 + (c2 * (log10(exp_->operator()(d)) / log10(b)));
}

Logarithm& Logarithm::operator=(Logarithm c) {

	Logarithm copy{ c };
	std::swap(exp_, copy.exp_);

	c1 = c.c1;
	c2 = c.c2;
	b = c.b;
	
	delete copy.exp_;
	copy.exp_ = nullptr;

	copy.exp_ = 0;

	return *this;

}

//Stream insertion operator<<
void Logarithm::display(std::ostream& os)const {
	if (c1 != 0 && (c2 != 0 || b != 1) && exp_ != nullptr) {
		os << c1 << " + " << c2 << " * log_" << b << "(" << *exp_ << ")";
	}
	else if (c1 == 0 && (c2 != 0 || b != 1) && exp_ != nullptr) {
		os << c2 << " * log_" << b << "(" << *exp_ << ")";
	}
	else
		os << c1;
}

//Destructor
Logarithm::~Logarithm() {

	c1, c2 = 0;
	b = 0; 

	delete exp_; //Vrf memoryleaks med men inte utan?
	exp_ = nullptr;

}