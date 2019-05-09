#include <iostream> 
#include <poly.h>
using namespace std;

int main(void)
{
	Polynomial poly;
	double start, end, tol;
	cout << "type two boundary values." << endl;
	cin >> start >> end;

	cout << "type tolerance." << endl;
	cin >> tol;

	cout << "sol : " << poly.bisect(start, end, tol) << endl;
	return 0;
}
