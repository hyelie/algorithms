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
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	vector<int> tell(N);
	for (int i = 0; i < N; i++) {
		cin >> tell[i];
	}
	priority_queue<int, vector<int>, less<int>> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int MID = tell[0];
	cout << MID << '\n';


	for (int i = 1; i < N; i++) {
		if (MID < tell[i]) {
			minheap.push(tell[i]);
		}
		else {
			maxheap.push(tell[i]);
		}

		while (!(maxheap.size() == minheap.size() || maxheap.size() == minheap.size() + 1)) {
			if (maxheap.size() > minheap.size()) {
				minheap.push(MID);
				MID = maxheap.top();
				maxheap.pop();
			}
			else if (maxheap.size() < minheap.size()) {
				maxheap.push(MID);
				MID = minheap.top();
				minheap.pop();
			}
		}

		if (i % 2) {
			cout << maxheap.top() << '\n';
		}
		else {
			cout << MID << '\n';
		}

		


		
	}
	

	return;
}

// nlogn
/*

1) maxheap.size() == minheap.size() || maxheap.size() == minheap.size()+1
2) maxheap.top() <= minheap.top();
이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
[결과] 이때 이 두가지 규칙을 유지해 준다면 항상 최대 힙 top값이 중간값이 된다.
MID = maxheap.top();



출처: https://www.crocus.co.kr/625 [Crocus]


*/