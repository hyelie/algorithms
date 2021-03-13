#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M, E;
	vector<int> location(N);
	for (int i = 0; i < N; i++) {
		cin >> location[i];
	}

	int curidx;		// 현재 위치보다 작거나 같은 땅콩의 idx
	for (int i = 0; i < N; i++) {
		if (E >= location[i]) {
			curidx = i;
			break;
		}
	}

	vector<bool> isred(N, false);	// true면 붉은 선 있음
	vector<bool> iseaten(N, false);	// true면 먹힌 것

	int eaten_num = 0;
	while (eaten_num != M) {
		if (curidx == N - 1) {	// 왼쪽 젤 가까운걸 찾으면됨

		}
		else {	// 양쪽 중 가까운걸 찾으면됨

		}
	}
	// curidx랑 curidx+1이랑 비교하면 됨
	// 만약 curidx가 0인 경우 -> 그대로
	// curidx가 N-1인 경우 -> 그 앞거만 보면 됨

	return;
}

// 젤 가까운 데로 가면 될듯
// 못 품.
// 그냥


/*
----------------------------
------
 ------
  ------
   ------
    ... 이렇게 비교해서 거리 찾았으면 되었지 싶은데... curidx 기준으로 
*/