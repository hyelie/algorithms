#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;
	queue<int> q; string s; int temp;
	while (N--) {
		 cin >> s;
		if (s == "push") {
			 cin >> temp;
			 q.push(temp);
		}
		else if (s == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
		else if (s == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
	}

	return;
}