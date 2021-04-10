#include <iostream>
#include<string>
#include<list>
#include <fstream>
using namespace std;

string sep[100];
int state;

int codeBreaker(string input, int count) {
	//int state = 1;
	//string sep[100];
	//int count = 0;

	for (int i = 0; i < input.length(); i++) {
		if (state == 3 || state == 4 || state == 5) {
			count++;
			state = 1;
		}
		
		if (state == 1) {
			if (input.at(i) == ' ') {
				state = 4;
				continue;
			}
			else if (input.at(i) == '"') {
				if (input.at(i - 1) != ' ') {
					count++;
				}
				sep[count].push_back(input.at(i));
				state = 2;
				continue;
			}

			else if (input.at(i) == '/') {
				if (input.at(i + 1) == '*') {
					i++;
					state = 6;
				}
				else if (input.at(i + 1) == '/') {
					i++;
					state = 7;
				}
				else {
					sep[count].push_back(input.at(i));
				}
				
				continue;
			}

			

			else {
				sep[count].push_back(input.at(i));
				continue;
			}
			
		}

		if (state == 2) {
			
			if (input.at(i) == '"') {
				sep[count].push_back(input.at(i));
				state = 3;
				continue;
			}
			else {
				sep[count].push_back(input.at(i));
				continue;
			}

		}

		if (state == 6) {
			if (input.at(i) == '*') {
				if (input.at(i + 1) == '/') {
					i++;
					state = 1;
				}
				

				continue;
			}

		}

		if (state == 7) {
			continue;

		}

		
	 }

	

	return count;
	
}


int main() {
	cout << "Enter String:\n";
	string input;
	int count = 0;
	state = 1;
	//getline(cin, input);

	ifstream myfile("code.txt");
	while (getline(myfile, input)) {
		count =codeBreaker(input, count);
		if (state != 2) {
			count++;
		}

		if (state == 7) {
			state = 1;
		}
		
	}

	cout << "\n";

	for (int i = 0; i < 100; i++) {
		if (sep[i] != "") {
			cout << sep[i] << "\n";
		}
	}
	

	return 0;

}
