#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
	int N, M;
	cin >> N >> M;
	queue<int> q;
	// 3 4 5 6 7 8 9 10 1
	// size 9. 
	// 9 10 1 3 4 5 6 7 8가 되어야 함
	// 연산 2 : 6
	// 연산 3 : 3
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	vector<int> v(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int cycle = 0;
		while (q.front() != v[i]) {
			cycle++;
			q.push(q.front());
			q.pop();
		}

		cnt += min((int)q.size() - cycle, cycle);

		q.pop();

	}

	cout << cnt;

	return;
}