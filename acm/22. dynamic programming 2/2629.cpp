#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int weight[31];
int ball[8];
int N;
bool dp[31][40001] = { false, };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	// dp[i][j] : i번째 무게추까지 사용했을 때 j g을 확인할 수 있는지
	dp[0][weight[0]] = true;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= 40000; j++) {
			if (dp[i-1][j]) {
				if (j + weight[i] <= 40000) {
					dp[i][j + weight[i]] = true;
				}
				if (abs(j - weight[i]) <= 40000) {
					dp[i][abs(j - weight[i])] = true;
				}
				dp[i][j] = true;
			}
		}
		dp[i][weight[i]] = true;
	}
	
	// dp[i]로 하면 안되는 이유
	// 추 1짜리 올라간 상태. weight = 1이 true
	// 근데 3짜리 올라간다 치자 그럼 weight = 4가 true가 됨
	// weight = 7도 true가 됨
	// 이게 문제였음.




	int ballnum; cin >> ballnum;
	for (int i = 0; i < ballnum; i++) {
		cin >> ball[i];
		if (dp[N-1][ball[i]]) {
			cout << "Y ";
		}
		else cout << "N ";
	}




	return;
}

/*

dp[i][j] : i번째 무게추까지 사용했을 때 j g을 확인할 수 있는지

경우 3가지.
1) i번째 무게추를 사용하지 않는 경우
2) i번째 무게추를 구슬쪽에 올릴 것인지(기존 weight에서 뺄건지) -> abs 처리 필요
3) i번째 무게추를 구슬 반대편에 올릴 것인지(기존 weight에서 더할건지)


*/

