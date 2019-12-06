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
	//constructor som tar in en int b, som st�r f�r den h�gsta exponentens v�rde, och en array som st�r f�r v�rde i polynomet
	 explicit Polynomial(const int b, const double a[]); //Explicit?

	 //en konstructor som endast tar in en double som st�r f�r v�rdet som polynomet f�r.
	 //Detta g�rs s� att vi ska kunna addera int/double tal ihop med polynom.
	 Polynomial(const double b);

	 //Copy Constructor, g�r en referering till Polynomial b och skapar en ny array med inneh�llet (*this) ur clone 
	 Polynomial(const Polynomial& b);

	//Clone anv�nder Copy constructor och skapar ett nytt Polynom utav arrayen
	 Polynomial* clone() const override; //Finns ingen constructor ( const =0 ber�ttar detta)

	//default destructor
	 ~Polynomial(); 

	//Polynomial(double b);
	//Var blir v�rdet f�r f(x), x = d i polynomet.
	double operator()(double d) const override;
	
	//Vi f�r se vad som finns i ett visst slot i polynomet. p[]
	double& operator[](int index); 

	//Vad var skillnaden h�r? N�got om lhs och rhs
	double operator[](int index)const;
	
	//�ndrar ett polynoms v�rde till det i rhs polynomets v�rde
	Polynomial& operator=(const Polynomial b); //???????????????????????????????????


	friend Polynomial operator+(const Polynomial lhs, const Polynomial rhs); //????????????

protected:
	void display(std::ostream& os) const override;

private:
	int degree=0;
	double* coeffs=nullptr;
};


#endif
