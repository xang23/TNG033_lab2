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
	 //use explicit when coverting from default
	//constructor som tar in en int b, som står för den högsta exponentens värde, och en array som står för värde i polynomet
	 explicit Polynomial(const int b, const double a[]); //Explicit?

	 //en konstructor som endast tar in en double som står för värdet som polynomet får.
	 //Detta görs så att vi ska kunna addera int/double tal ihop med polynom.
	 Polynomial(const double b);

	 //Copy Constructor, gör en referering till Polynomial b och skapar en ny array med innehållet (*this) ur clone 
	 Polynomial(const Polynomial& b);

	//Clone använder Copy constructor och skapar ett nytt Polynom utav arrayen
	 Polynomial* clone() const override; //Finns ingen constructor ( const =0 berättar detta)

	//default destructor
	 ~Polynomial(); 

	//Polynomial(double b);
	//Var blir värdet för f(x), x = d i polynomet.
	double operator()(double d) const override;
	
	//Vi får se vad som finns i ett visst slot i polynomet. p[]
	double& operator[](int index); 

	//Vad var skillnaden här? Något om lhs och rhs
	double operator[](int index)const;
	
	//ändrar ett polynoms värde till det i rhs polynomets värde
	Polynomial& operator=(const Polynomial b); //???????????????????????????????????


	friend Polynomial operator+(const Polynomial lhs, const Polynomial rhs); //????????????

protected:
	void display(std::ostream& os) const override;

private:
	int degree=0;
	double* coeffs=nullptr;
};


#endif
