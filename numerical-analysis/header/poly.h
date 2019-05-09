#ifndef __POLY_H__
#define __POLY_H__ 

#include <vector>
using namespace std;

class Term
{
private:
	double coef;
	int deg;
public:
	Term(double coef=0.0, int deg=0)
		: coef(coef), deg(deg) {}
	double getCoef() const {
		return this->coef;
	}
	int getDeg() const {
		return this->deg;
	}
	void setCoef(double coef) {
		this->coef = coef;
	}
	void setDeg(int deg) {
		this->deg = deg;
	}
};

class Polynomial
{
protected:
	vector<Term> terms;
public:
	Polynomial();
	double yVal(double x) const;
	double bisect(double start, double end, double tol) const;
	void show() const;
};

#endif
