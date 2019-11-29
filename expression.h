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

	friend std::ostream& operator<<(std::ostream& os, const Expression& b);

	virtual bool isRoot(double d) const=0; //�r d en l�sning f�r ett polynom
	virtual Expression* clone()const = 0; //Finns ingen constructor ( const =0 ber�ttar detta)


	virtual double operator()(double d) const = 0; //retunerar ett v�rde fr�n funktionen med insatt x (b)

	virtual ~Expression()= default; //destruktorn

protected:
	virtual void display(std::ostream& os)const = 0;

	//Protected, n�r n�gpt ska n�s utav subclasser
private:

	//cannot have something private because the subclasses wont see them

};




#endif
