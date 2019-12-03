
/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>

#include "expression.h"

class Logarithm : public Expression
{
public:
	Logarithm();
	Logarithm(const Expression &E, const double c1, const double c2, const int b);

	Logarithm* clone()const override; //Finns ingen constructor ( const =0 berättar detta)


	double operator()(double d) const override; //retunerar ett värde från funktionen med insatt x (b)
	Logarithm& operator=(Logarithm c);
	Logarithm(const Logarithm& c);

	~Logarithm(); //destruktorn

protected:
	void display(std::ostream& os)const override;
	Expression* exp_; //_ members of a class
	double c1;
	double c2;
	int b;

	//ADD CODE
private:

};

#endif
