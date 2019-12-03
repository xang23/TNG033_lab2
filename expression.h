/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <cmath>


const double EPSILON = 1.0e-5;


class Expression
{
public:

	virtual Expression* clone() const = 0; //Finns ingen constructor ( const =0 berättar detta)
	friend std::ostream& operator<<(std::ostream& os, const Expression& b);

	bool isRoot(double d) const; //Är d en lösning för ett polynom

	virtual double operator()(double d) const = 0; //retunerar ett värde från funktionen med insatt x (b)
	
	virtual ~Expression() = default; //destruktorn

protected:
	virtual void display(std::ostream& os)const = 0;

	//Protected, när någpt ska nås utav subclasser
private:
	
	//cannot have something private because the subclasses wont see them

};




#endif
