
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

	//en constructor som tar in ett expression och 3 constanter som den omvandlar till en logarithm
	//c1+c2* log_b(exp)
	Logarithm(const Expression &E, const double c1, const double c2, const int b);

	//default overridar default funktionen i expression. 
	//använder copyconstructorn för att returnera en logaritm med sammavärde som i rhs.
	Logarithm* clone()const override; 
	Logarithm(const Logarithm& c);
	
	//retunerar ett värde från funktionen med insatt x (b)
	double operator()(double d) const override; 

	//assigment operator som sätter lhs till rhs
	Logarithm& operator=(Logarithm c);

	~Logarithm(); //destruktorn 

protected:
	//disp här i log kallas när en expression med typ log ska skrivas ut (overrdide)
	void display(std::ostream& os)const override;

private:
	//varje logaritm består av en pekare exp_ mot en expression, även tre konstanter 
	Expression* exp_; //_ members of a class
	double c1;
	double c2;
	int b;
};

#endif
