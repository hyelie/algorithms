#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N, K;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> K;
	vector<int> coin(N);
	int i;
	for (i = N-1; i >= 0; i--) {
		cin >> coin[i];
	}

	i = 0;
	int cnt = 0;
	while (K != 0) {
		if (K - coin[i] < 0) {
			i++;
			continue;
		}

		cnt += K / coin[i];
		K -= (K / coin[i]) * coin[i];
		i++;
	}

	cout << cnt;


	return;
}