#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int V, E;
int dist[401][401] = { 0, };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> V >> E;
	int a, b, c;
	// �ʱ�ȭ
	for (int src = 1; src <= V; src++) {
		for (int dst = 1; dst <= V; dst++) {

				dist[src][dst] = 40000001;

		}
	}
	while (E--) {
		cin >> a >> b >> c;
		//  �ִ� �Ÿ��� ���ϱ� �� -> ������ �Ÿ��� �ִ� �Ÿ��� ��
		dist[a][b] = c;
	}

	for (int temp = 1; temp <= V; temp++) {
		for (int src = 1; src <= V; src++) {
			for (int dst = 1; dst <= V; dst++) {
				if (dist[src][dst] > dist[src][temp] + dist[temp][dst]) {
					dist[src][dst] = dist[src][temp] + dist[temp][dst];
				}
			}
		}
	}

	/*for (int src = 1; src <= V; src++) {
		for (int dst = 1; dst <= V; dst++) {
			//if (dist[src][dst] == 10000001 || src == dst) dist[src][dst] = 0;
			cout << dist[src][dst] << ' ';
		}cout << '\n';
	}*/

	int min_val = 40000001;

	for (int src = 1; src <= V; src++) {
		for (int dst = 1; dst <= V; dst++) {
			if (src == dst) continue;
			min_val = min(min_val, dist[src][dst] + dist[dst][src]);
		}
	}

	min_val = min_val == 40000001 ? -1 : min_val;

	cout << min_val;

	return;
}

/*

�÷��̵�-�ͼ�
��� ������ ���� �ִ� ���
O(V^3)

���� ��� x
��� �� -> ��� ��

*/