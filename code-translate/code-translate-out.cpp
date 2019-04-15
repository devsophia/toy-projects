#include &lt;iostream&gt;
#include &lt;fstream&gt;
#include &lt;vector&gt;

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inp;
	ofstream out;
	vector&lt;string&gt; code;

	if(argc != 3) {
		cout &lt;&lt; "how to use : ";
		cout &lt;&lt; "./codetranslate &lt;inputfilename&gt; &lt;outputfilename&gt;" &lt;&lt; endl;
		return 0;
	}

	inp.open(argv[1]);
	out.open(argv[2]);	

	for(string line; getline(inp, line); ) {
		for(int i=0; i&lt;line.length(); ++i) {
			switch(line[i]) {
				case '&lt;':
					line.replace(i, 1, "&amp;lt;");
					i += 3;
					break;
				case '&gt;':
					line.replace(i, 1, "&amp;gt;");
					i += 3;
					break;
				case '&amp;':
					line.replace(i, 1, "&amp;amp;");
					i += 4;
					break;
				default:
					break;
			}
		}
		code.push_back(line);
	}

	for(auto it=code.begin(); it!=code.end(); ++it)
		out &lt;&lt; *it &lt;&lt; endl;

	inp.close();
	out.close();

	return 0;
}
