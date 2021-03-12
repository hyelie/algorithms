#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
	int n; cin >> n;
	map<string, int> m;
	string name, type;
	for (int i = 0; i < n; i++) {
		cin >> name >> type;
		// 못찾은경우
		if (m.find(type) == m.end()) {
			m.insert({ type, 1 });
		}
		// 찾은경우
		else {
			m[type]++;
		}
	}
	int result = 1;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		result *= (*iter).second + 1;
	}
	cout << result - 1<<'\n';


	return;
}