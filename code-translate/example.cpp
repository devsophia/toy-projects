#include<iostream>
using namespace std;

// this code has a lot of <, >, &

int main(void)
{
	string one;
	string &two = one;
	string &three = two;

	int a = 1;
	int b = 2;
	int c = (a > b) ? a : b;
	int d = (b < c) ? b : c;

	return 0;
}
