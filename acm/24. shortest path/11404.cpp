#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int n, m;
int dist[101][101] = { 0, };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> n >> m;
	int a, b, c;
	// �ʱ�ȭ
	for (int src = 1; src <= n; src++) {
		for (int dst = 1; dst <= n; dst++) {
			if (src == dst) {
				dist[src][dst] = 0;
			}
			else {
				dist[src][dst] = 10000001;
			}
		}
	}
	while (m--) {
		cin >> a >> b >> c;
		//  �ִ� �Ÿ��� ���ϱ� �� -> ������ �Ÿ��� �ִ� �Ÿ��� ��
		dist[a][b] = min(dist[a][b], c);
	}

	for (int temp = 1; temp <= n; temp++) {
		for (int src = 1; src <= n; src++) {
			for (int dst = 1; dst <= n; dst++) {
				if (dist[src][dst] > dist[src][temp] + dist[temp][dst]) {
					dist[src][dst] = dist[src][temp] + dist[temp][dst];
				}
			}
		}
	}

	for (int src = 1; src <= n; src++) {
		for (int dst = 1; dst <= n; dst++) {
			if (dist[src][dst] == 10000001 || src == dst) dist[src][dst] = 0;
			cout << dist[src][dst] << ' ';
		}cout << '\n';
	}

	return;
}

/*

�÷��̵�-�ͼ�
��� ������ ���� �ִ� ���
O(V^3)

���� ��� x
��� �� -> ��� ��

*/