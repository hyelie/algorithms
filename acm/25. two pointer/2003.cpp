#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

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
	int N, M; cin >> N >> M;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int l = 0, r = 0, sum = 0, cnt = 0;
	// 현재 보는 구간 : l부터 r-1까지임. 그래서 조건에 r<=N
	while (l <= r && r <= N) {
		// sum이 더 작은 상황, r++해줘야함
		if (sum < M) {
			// 근데 r++ 못하는 상황 -> 더 못더함.
			if (r == N)break;
			// r++ 할 수 있는 상황 -> sum 더하고 r++
			sum += v[r];
			r++;
		}
		// sum이랑 같은 상황 : v[l] 뺌
		else if (sum == M) {
			sum -= v[l];
			l++;
			cnt++;
		}
		// sum보다 큰 상황 : v[l] 뺌
		else {	// sum > M
			sum -= v[l];
			l++;
		}
	}

	cout << cnt;

	return;
}