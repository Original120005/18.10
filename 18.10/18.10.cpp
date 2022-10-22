﻿#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void Validator(ifstream& o, int counter, string content) {
	int s, a;
	for (int i = 0; i < counter; i++) {
		s = 0, a = 0;
		for (int j = 0; j < content.length(); j++) {
			if (content[j] == '<') {
				s += 1;
				a += 1;
			}
			else if (content[j] == '>' && s == 1) {
				s = 0;
				a -= 1;
			}
		}
		if (a == 0) {
			cout << " correct: " << endl;
			cout << content << "\n\n";
		}
		else if (a != 0) {
			cout << " uncorrect: " << endl;
			cout << content << "\n\n";
		}
		break;
	}
}

int main() {
	string path;
	cout << "Enter file : ";
	getline(cin, path);


	ifstream open(path);
	string content;
	int anti = 0;
	if (open.is_open()) {
		do {
			getline(open, content);
			anti++;

			Validator(open, anti, content);

		} while (!open.eof());
	}
	else {
		cout << "";
	}
	open.close();

}