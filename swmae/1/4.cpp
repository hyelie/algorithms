#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

int num_each(vector<int>& v, int curidx) {
	set<int> s;
	int num = 0;
	while (1) {
		// 중복으로밟은경우
		if (s.insert(curidx).second == false) {
			num++;
			break;
		}
		else {
			curidx += v[curidx];
			num++;
		}
	}
	return num;
}

void solve() {
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int curidx = 0;
	cout << max(num_each(v, 0), max(num_each(v, 1), num_each(v, 2)))<<'\n';

	

	return;
}