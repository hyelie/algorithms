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
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	int N, M; cin >> N >> M;
	queue<int> q;
	vector<int> priority(N);
	for (int i = 0; i < N; i++) {
		cin >> priority[i];
		q.push(priority[i]);
	}

	
	int cnt = 0, maxval = -1, qsize;
	while (1) {
		qsize = q.size();
		maxval = -1;
		while (qsize--) {
			maxval = max(maxval, q.front());
			q.push(q.front());
			q.pop();
		}
		if (q.front() == maxval) {
			q.pop();
			cnt++;
			if (M == 0) {
				cout << cnt << '\n';
				break;
				
			}
			else {
				M--;
				if (M < 0) M = q.size() - 1;
			}
		}
		else {
			q.push(q.front());
			q.pop();
			M--;
			if (M < 0) M = q.size() - 1;
		}
	}

	return;
}