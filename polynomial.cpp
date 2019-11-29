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

Polynomial::Polynomial(double b)
	:degree{ 0 }, coeffs{ new double[1] }
{
	coeffs[0] = b;
}

Polynomial::Polynomial(const Polynomial &b) 
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
				os << coeffs[i];
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

Polynomial operator+(const Polynomial rhs, const Polynomial lhs) {
	int lhs_lenght = lhs.degree + 1;
	int rhs_lenght = rhs.degree + 1;
	int smaler = 0;
	bool lhs_smaler = true;
	double* dummy_array = nullptr;

	if (lhs_lenght < rhs_lenght) {
		dummy_array = new double[rhs_lenght];
		smaler = lhs_lenght;
	}
	else {
		dummy_array = new double[lhs_lenght];
		smaler = rhs_lenght;
		lhs_smaler = false;
	}

	if (lhs_smaler) {
		for (int i = 0; i < rhs_lenght; i++) {
			dummy_array[i]=rhs.coeffs[i];
			//std::cout << dummy_array[i] << "All values in lhs";
		}
		for (int i = 0; i < lhs_lenght; i++) {
			dummy_array[i] =dummy_array[i]+ lhs.coeffs[i];
			//std::cout <<"\n"<< dummy_array[i] << "Trying to add rhs to lhs";
		}
		//std::cout << "lhs_smalet true ";
		for (int i = 0; i < sizeof(dummy_array); i ++) {
			//std::cout  << dummy_array[i]<< " " ;
		}
	}
	else {
		for (int i = 0; i < lhs_lenght; i++) {
			dummy_array[i] = lhs.coeffs[i];
			//std::cout << "\n" << dummy_array[i] << "All values in rhs";
		}
		for (int i = 0; i < rhs_lenght; i++) {
			dummy_array[i] = dummy_array[i] + rhs.coeffs[i];
			//std::cout << "\n" << dummy_array[i] << "Trying to add lhs to rhs";
		}
		//std::cout << "lhs_smalet false ";
	}


	Polynomial polynomial = Polynomial(sizeof(dummy_array)-1, dummy_array);
	delete[] dummy_array;
	dummy_array = nullptr;
	
	return polynomial;
}


bool Polynomial::isRoot(double d) const{ //Är d en lösning för ett polynom

	if (std::abs((*this)(d)) < EPSILON) {
		return true;
	}

	return std::abs((*this)(d)) < EPSILON;
}


