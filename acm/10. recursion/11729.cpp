#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;

void solve();
void hanoi(int n, int from, int temp, int to) {
	if (n == 1) {
		v.push_back({ from, to });
		return;
	}
	hanoi(n - 1, from, to, temp);
	v.push_back({ from, to });
	hanoi(n - 1, temp, from, to);
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n; cin >> n;

	hanoi(n, 1, 2, 3);

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}


	return;
}


/*

�ϳ��� : A, B, C�� ���� �� + A�� n���� ���� ��
A->B�� 1~n-1��° �͵��� �ű��
A->C�� n���縦 �ű��
B->C�� 1~n-1��° ���� �ű�� ��.

*/