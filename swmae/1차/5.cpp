#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	// S_i : i번째 두더지 점수, K_i : 올라오는 회수, 나머지는 올라오는시간
	unordered_map<int, int> umap;
	// key : time, value : t=time일 때 최대 점수
	
	for (int i = 0; i < N * N; i++) {
		int point, num_up, time;
		cin >> point >> num_up;
		for (int j = 0; j < num_up; j++) {
			cin >> time;
			// time이 없는경우
			auto iter = umap.find(time);
			if (iter == umap.end()) { 
				umap[time] = point;
			}
			else {
				umap[time] = max(iter->second, point);
			}
		}
	}

	long long answer = 0;
	unordered_map<int, int>::iterator iter;
	for (iter = umap.begin(); iter != umap.end(); iter++) {
		answer += iter->second;
	}

	cout << answer;

	return;
}
// 1억 -> O(n)
// t에 대해 점수를 넣고 -> 이거 구현내용이네
// 각 t에서 점수 최댓값 뽑아서 더하면 될듯.
// hash?
// 시간을 key, 그 시간 내에서 최대 점수 : value로