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
	// S_i : i��° �δ��� ����, K_i : �ö���� ȸ��, �������� �ö���½ð�
	unordered_map<int, int> umap;
	// key : time, value : t=time�� �� �ִ� ����
	
	for (int i = 0; i < N * N; i++) {
		int point, num_up, time;
		cin >> point >> num_up;
		for (int j = 0; j < num_up; j++) {
			cin >> time;
			// time�� ���°��
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
// 1�� -> O(n)
// t�� ���� ������ �ְ� -> �̰� ���������̳�
// �� t���� ���� �ִ� �̾Ƽ� ���ϸ� �ɵ�.
// hash?
// �ð��� key, �� �ð� ������ �ִ� ���� : value��