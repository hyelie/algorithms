#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();
pii decompose(int i) {
	int two = 0, five = 0;
	while (i % 2 == 0) {
		two++;
		i /= 2;
	}
	while (i % 5 == 0) {
		five++;
		i /= 5;
	}
	return { two, five };
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	int two = 0, five = 0;
	pii temp;
	for (int i = 1; i <= N; i++) {
		temp = decompose(i);
		two += temp.first;
		five += temp.second;
	}

	cout << min(two, five);



	return;
}

