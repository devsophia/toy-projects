#include <poly.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial()
{
	double coef;
	int deg, num;

	cout << "how many terms are there ?" << endl;
	cin >> num;

	for(int i=1; i<=num; ++i) {
		cout << "type coefficient and degree of " << i <<
		"th term." << endl;
		cin >> coef >> deg;
		Term term(coef, deg);
		this->terms.push_back(term);
	}

	sort(terms.begin(), terms.end(), [] (Term &A, Term &B) -> bool {
		if(A.getDeg() >= B.getDeg())
			return true;
		else
			return false;
	});
}

double Polynomial::yVal(double x) const
{
	double sum = 0;
	for(auto it=terms.begin(); it!=terms.end(); ++it) {
		double val = 1.0;
		for(int i=0; i<it->getDeg(); ++i) {
			val *= x;
		}
		val *= it->getCoef();
		sum += val;
	}

	return sum;
}

double Polynomial::bisect(double start, double end, double tol) const
{
	double mid;

	if(yVal(start) * yVal(end) >= 0) {
		cout << "f(a)f(b) >= 0 !" << endl;
		exit(-1);
	}

	mid = (start + end) / 2.0;
	while(abs(end - start) > tol) {
		double mulVal = yVal(mid) * yVal(end);
		if(mulVal < 0)
			start = mid;
		else if(mulVal > 0)
			end = mid;
		else
			break;
		mid = (start + end) / 2.0;
	}

	return mid;
}

void Polynomial::show() const
{
	if(terms.size() == 0) {
		cout << "no term to show." << endl;
		return;
	}

	for(auto iter=terms.begin(); iter!=terms.end(); ++iter) {
		if(iter != terms.begin() && iter->getCoef() > 0)
			cout << '+';
		cout << iter->getCoef() << "x^" << iter->getDeg();
	}
	cout << endl;
}
