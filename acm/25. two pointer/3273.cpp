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
bool mycomp(int a, int b) {
	return a < b;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, x;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cin >> x;

	sort(v.begin(), v.end(), mycomp);

	int cnt = 0, left = 0, right = N - 1, sum;
	while (left < right && 0<= left && left < N && 0<=right && right<N) {
		sum = v[left] + v[right];
		if (x == sum) {
			cnt++;
			left++; right--;
		}
		else if (sum < x) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << cnt;



	return;
}