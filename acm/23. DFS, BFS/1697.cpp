#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N, K;
int dist[100001];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> K;
	if (N == K) cout << "0";
	else {
		

		for (int i = 0; i <= 100000; i++) {
			dist[i] = -1;
		}
		dist[N] = 0;

		queue<int> q;
		q.push(N);

		int temp, prevdist;
		while (!q.empty()) {
			temp = q.front(); q.pop();
			if (temp == K) break;
			prevdist = dist[temp];
			if (0 <= temp - 1 && temp - 1 <= 100000 && dist[temp-1] == -1) {
				q.push(temp - 1);
				dist[temp - 1] = prevdist+1;
			}
			if (0 <= temp + 1 && temp + 1 <= 100000 && dist[temp+1] == -1) {
				q.push(temp + 1);
				dist[temp + 1] = prevdist + 1;
			}
			if (0 <= 2 * temp && 2 * temp <= 100000 && dist[2*temp] == -1) {
				q.push(2 * temp);
				dist[2 * temp] = prevdist + 1;
			}
		}

		cout << dist[K];
	}
	

	return;
}