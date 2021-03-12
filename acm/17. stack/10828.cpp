#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;
	stack<int> mys;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int input; cin >> input;
			mys.push(input);
		}
		else if (s == "top") {
			if (mys.empty()) {
				cout << "-1\n";
			}
			else
				cout << mys.top()<<'\n';
		}
		else if (s == "size") {
			cout << mys.size() << '\n';
		}
		else if (s == "empty") {
			cout << mys.empty() << '\n';
		}
		else if (s == "pop") {
			if (mys.empty()) {
				cout << "-1\n";
			}
			else {
				cout << mys.top() << '\n';
				mys.pop();
			}
		}
		else {
			cout << "wrong command\n";
		}
	}


	return;
}