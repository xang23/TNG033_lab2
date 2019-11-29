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
	explicit Polynomial(const int b, const double a[]);
	Polynomial(const double b);

	Polynomial* clone() const override;
	Polynomial(const Polynomial &b);


	~Polynomial(); //destruktorn


	bool isRoot(double d) const override; //Är d en lösning för ett polynom
	double operator()(double d) const override;

	Polynomial& operator=(Polynomial b);
	friend Polynomial operator+(const Polynomial rhs, const Polynomial lhs);	

	double& operator[](int index);
	double operator[](int index)const;

protected:
	void display(std::ostream& os) const override;
	int degree = 0;
	double* coeffs = nullptr;

private:
	
};


#endif
