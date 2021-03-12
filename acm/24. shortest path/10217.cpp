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


	return;
}

/*

dijkstra 갱신이
dist뿐만 아니라
금액도 있어야함

dist[nxtv] > dist[curv] + weight && curm + nxtm < M
이어야 갱신.

dp[i][j] : i번 vertex까지 j원으로 갔을 떄 최소시간

각 vertex : 
DP

*/