#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int arr[101];

void solve();
// a > b임을 보장됨.
int GCD(int a, int b) {
	int temp;
	while (1) {
		if (a % b == 0) {
			return b;
		}
		else {
			temp = a % b;
			a = b;
			b = temp;
		}
	}
	return b;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int maxGCD = abs(arr[0] - arr[1]);
	for (int i = 2; i < N; i++) {
		maxGCD = GCD(max(abs(arr[i - 1] - arr[i]), maxGCD), min(abs(arr[i - 1] - arr[i]), maxGCD));
	}
	/*
	int N; cin >> N;
	int first; cin >> first;
	int second; cin >> second;
	int maxGCD = abs(first - second);
	first = second;
	for (int i = 2; i < N; i++) {
		cin >> second;
		maxGCD = GCD(max(maxGCD, abs(first-second)), min(maxGCD, abs(first - second)));
		first = second;
	}*/

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= sqrt(maxGCD); i++) {
		if (maxGCD % i == 0) {
			pq.push(i);
			if(i != maxGCD / i)
				pq.push(maxGCD / i);
		}
	}

	pq.pop();
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}


	return;
}

/*

i1 = aM + q
i2 = bM + q
i3 = cM + q
...
total sum = (a+b+...+)M + nq

i1 - i2 = (a-b)M
i2 - i3 = (b-c)M

-> 내림차순 정렬, arr[i]들의 차이의 GCD

*/