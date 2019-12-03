/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/


#include "polynomial.h"


//ADD implementation of the member functions for class Polynomial
Polynomial::Polynomial(const int b, const double a[])
	:Expression(), degree{ b }, coeffs{ new double[b + 1] }
{
	int howMany = b + 1;

	for (int i = 0; i < howMany; i++) {
		coeffs[i] = a[i];
	}

}

Polynomial::Polynomial(const double b)
	:degree{ 0 }, coeffs{ new double[1] }
{
	coeffs[0] = b;
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& b)
{
	degree = b.degree;
	coeffs = new double[b.degree + 1];

	for (int i = 0; i < b.degree + 1; i++) {
		coeffs[i] = b.coeffs[i];
	}
}

Polynomial* Polynomial::clone() const {
	//how does this work

	return new Polynomial(*this);
}


void Polynomial::display(std::ostream& os)const {

	if (degree == 0) {
		os << coeffs[0];
	}
	else {
		for (int i = 0; i <= degree; i++) {
			if (i == 0) {
				os <<coeffs[i];
			}
			else if (i == 1) {
				if (coeffs[i] == 0) {

				}
				else
					os << " + " << coeffs[i] << " * x";

			}

			else {
				os << " + " << coeffs[i] << " * x^" << i;
			}
			//coeffs[i] 				os << "x^" << i
		}
	}
}

Polynomial::~Polynomial() {
	delete[] coeffs;
	degree = 0;

	coeffs = nullptr;

}

Polynomial& Polynomial::operator=(Polynomial b) {
	
	Polynomial copy{ b };
	std::swap(coeffs, copy.coeffs);
	std::swap(degree, copy.degree);
	delete[] copy.coeffs;
	copy.coeffs = nullptr;

	copy.degree = 0;

	return *this;

}

double& Polynomial::operator[](int index) {
	return coeffs[index];
}

double Polynomial::operator[](int index) const {
	return coeffs[index];
}

double Polynomial::operator()(double d)const {
	int exponent = 0;
	double result = 0;
	for (int i = 0; i < this->degree + 1; i++) {
		result = result + coeffs[i] * (pow(d, exponent));
		exponent++;
	}
	return result;
}


Polynomial operator+(const Polynomial lhs, const Polynomial rhs) {
	//hur funcar dynamic alocated array. Behöver vi inte oroa oss för att hamna out of bounderies?? Växer den automatiskt?? Var
	//vi är i this och vi får in P
	//vi vill jämföra degrees av polynom och ta den som är störrst och antingen skapa en ny eller ändra i den vi har.
	if (lhs.degree > rhs.degree || lhs.degree == rhs.degree) {
		Polynomial temp = Polynomial(lhs);
		//använd dens degree och array
		for (int i = 0; i <= rhs.degree; i++) {
			temp.coeffs[i] = lhs.coeffs[i] + rhs.coeffs[i];
		}
		return temp;
	}
	// this->degree < P.degree
	else {
		//använ P.degrees array
		Polynomial temp = rhs;
		for (int i = 0; i <= lhs.degree; i++) {
			temp.coeffs[i] = lhs.coeffs[i] + rhs.coeffs[i];;
		}
		return temp;
	}
}


