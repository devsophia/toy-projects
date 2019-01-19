#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inp;
	ofstream out;
	vector<string> code;

	if(argc != 3) {
		cout << "how to use : ";
		cout << "./codetranslate <inputfilename> <outputfilename>" << endl;
		return 0;
	}

	inp.open(argv[1]);
	out.open(argv[2]);	

	for(string line; getline(inp, line); ) {
		for(int i=0; i<line.length(); ++i) {
			switch(line[i]) {
				case '<':
					line.replace(i, 1, "&lt;");
					i += 3;
					break;
				case '>':
					line.replace(i, 1, "&gt;");
					i += 3;
					break;
				case '&':
					line.replace(i, 1, "&amp;");
					i += 4;
					break;
				default:
					break;
			}
		}
		code.push_back(line);
	}

	for(auto it=code.begin(); it!=code.end(); ++it)
		out << *it << endl;

	inp.close();
	out.close();

	return 0;
}
