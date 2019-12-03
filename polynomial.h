/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"


class Polynomial : public Expression
{
    //ADD CODE

public:
	explicit Polynomial(const int b, const double a[]); //Explicit?
	 Polynomial(const double b);
	 Polynomial(const Polynomial& b);
	
	 Polynomial* clone() const override; //Finns ingen constructor ( const =0 berättar detta)
	//default constructor
	 ~Polynomial(); //destruktorn
	//Polynomial(double b);
	double operator()(double d) const override;
	
	double& operator[](int index);
	double operator[](int index)const;
	
	Polynomial& operator=(const Polynomial b);

	friend Polynomial operator+(const Polynomial lhs, const Polynomial rhs);

protected:
	void display(std::ostream& os) const override;

private:
	int degree=0;
	double* coeffs=nullptr;
};


#endif
