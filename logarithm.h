
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

	bool isRoot(double d) const override; //�r d en l�sning f�r ett polynom
	Logarithm* clone()const override; //Finns ingen constructor ( const =0 ber�ttar detta)


	double operator()(double d) const override; //retunerar ett v�rde fr�n funktionen med insatt x (b)

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
