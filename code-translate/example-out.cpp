#include&lt;iostream&gt;
using namespace std;

// this code has a lot of &lt;, &gt;, &amp;

int main(void)
{
	string one;
	string &amp;two = one;
	string &amp;three = two;

	int a = 1;
	int b = 2;
	int c = (a &gt; b) ? a : b;
	int d = (b &lt; c) ? b : c;

	return 0;
}
