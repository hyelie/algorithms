#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	string p; cin >> p;
	bool isError = false;
	int n; cin >> n;
	vector<string> inputarr;
	string input; cin >> input; string temp = "";
	for (int i = 1; i < input.length(); i++) {
		if (input[i] == ',' || input[i] == ']') {
			inputarr.push_back(temp);
			temp = "";
		}
		else {
			temp += input[i];
		}
	}

	deque<string> dq;
	for (int i = 0; i < n; i++) {
		dq.push_back(inputarr[i]);
	}

	int front_pop = 0, back_pop = 0, num_reverse = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == 'R') {
			num_reverse++;
			continue;
		}
		else {
			if (dq.size() == 0) {
				isError = true;
				break;
			}
			if (num_reverse % 2 == 0) {
				dq.pop_front();
			}
			else {
				dq.pop_back();
			}
		}
	}

	if (isError) {
		cout << "error\n";
	}
	else {
		if (num_reverse % 2) {
			if (dq.empty()) cout << "[]\n";
			else {
				cout << "[";
				while (dq.size() != 1) {
					cout << dq.back() << ',';
					dq.pop_back();
				}
				cout << dq.back() << "]\n";
			}
			
		}
		else {
			if (dq.empty()) cout << "[]\n";
			else {
				cout << "[";
				while (dq.size() != 1) {
					cout << dq.front() << ',';
					dq.pop_front();
				}
				cout << dq.front() << "]\n";
			}
		}
	}

	return;
}