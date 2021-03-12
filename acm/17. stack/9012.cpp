#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	string input_s; cin >> input_s;
	stack<int> s;
	for (int i = 0; i < input_s.length(); i++) {
		if (input_s[i] == '(') {
			s.push(1);
		}
		else {
			if (s.empty()) {
				cout << "NO\n";
				return;
			}
			s.pop();
		}
	}
	if(s.empty())
		cout << "YES\n";
	else
		cout << "NO\n";

	return;
}