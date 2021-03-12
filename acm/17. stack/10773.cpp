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
	solve();
	return 0;
}

void solve() {
	int K; cin >> K;
	stack<int> s;
	int input;
	while (K--) {
		cin >> input;
		if (input != 0) {
			s.push(input);
		}
		else {
			s.pop();
		}
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

	return;
}