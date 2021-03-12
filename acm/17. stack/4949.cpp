#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	string input;
	getline(cin, input);
	while (input != "."){
		stack<int> s;
		bool isanswer = false;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') {
				s.push(1);
			}
			else if (input[i] == '[') {
				s.push(2);
			}
			else if (input[i] == ')') {
				if (s.empty() || s.top() != 1) {
					isanswer = true;
					cout << "no\n";
					break;
				}
				else
				s.pop();
			}
			else if (input[i] == ']') {
				if (s.empty() || s.top() != 2) {
					isanswer = true;
					cout << "no\n";
					break;
				}
				else
				s.pop();
			}
			else {
				continue;
			}
		}

		if (!isanswer) {
			if (s.empty()) {
				cout << "yes\n";
			}
			else cout << "no\n";
		}

		
		getline(cin, input);
	}
	return 0;
}