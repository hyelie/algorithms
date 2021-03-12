#include <iostream>
#include <vector>
#include <deque>
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
	deque<int> dq; string s; int temp;
	while (N--) {
		cin >> s;
		if (s == "push_front") {
			cin >> temp;
			dq.push_front(temp);
		}
		else if (s == "push_back") {
			cin >> temp;
			dq.push_back(temp);
		}
		else if (s == "pop_front") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << '\n';
		}
		else if (s == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (s == "front") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (s == "back") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << '\n';
			}
		}



		
	}

	return;
}