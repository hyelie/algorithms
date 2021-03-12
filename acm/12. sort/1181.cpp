#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;

void solve();

struct mycompp {
	bool operator()(const string &a, const string& b) const {
		if (a.size() == b.size()) {
			return a < b;
		}
		else return a.size() < b.size();
	}
};

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	set<string, mycompp> s;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		s.insert(input);
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << '\n';
	}

	return;
}