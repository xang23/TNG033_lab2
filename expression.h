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
	//virtual betyder att underklasserna ska ha funktionen.
	virtual Expression* clone() const = 0; //Finns ingen constructor ( const =0 berättar detta)
	//friend betyder att subclasserna kan se varandras kod i private och protected men kan ej ändra på dem.
	friend std::ostream& operator<<(std::ostream& os, const Expression& b);

	bool isRoot(double d) const; //Är d en lösning för ett polynom

	virtual double operator()(double d) const = 0; //retunerar ett värde från funktionen med insatt x (b)
	//default betyder att funktionen körs alltid om ingen annan funktion "overide" den
	virtual ~Expression() = default; //destruktorn

protected:
	virtual void display(std::ostream& os)const = 0;
	Expression() = default;
	virtual Expression& operator=(const Expression&) = default;

	//Protected, när någpt ska nås utav subclasser
private:
	
	//cannot have something private because the subclasses wont see them

};




#endif
