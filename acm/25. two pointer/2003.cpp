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
	// ���� ���� ���� : l���� r-1������. �׷��� ���ǿ� r<=N
	while (l <= r && r <= N) {
		// sum�� �� ���� ��Ȳ, r++�������
		if (sum < M) {
			// �ٵ� r++ ���ϴ� ��Ȳ -> �� ������.
			if (r == N)break;
			// r++ �� �� �ִ� ��Ȳ -> sum ���ϰ� r++
			sum += v[r];
			r++;
		}
		// sum�̶� ���� ��Ȳ : v[l] ��
		else if (sum == M) {
			sum -= v[l];
			l++;
			cnt++;
		}
		// sum���� ū ��Ȳ : v[l] ��
		else {	// sum > M
			sum -= v[l];
			l++;
		}
	}

	cout << cnt;

	return;
}