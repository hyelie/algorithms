#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int board[100001], N, max_cycle_num = -1;
pii edge[100001];
// edge.first : ��� vertex, second : ���� vertex
// edge[i].second : i���� second�� �����ϴ� ��.
bool visited[100001];
int cnt[100001], curcnt = 1;
// cnt[i] : i��° vertex�� ���� ��ȣ�� �������

void solve();

void DFS(int cur) {
	visited[cur] = true;
	cnt[cur] = curcnt;
	curcnt++;

	if (!visited[edge[cur].second]) {
		DFS(edge[cur].second);
	}
	// �湮�� ��- > cycle��.
	else {
		max_cycle_num = max(max_cycle_num, curcnt - cnt[edge[cur].second]);
	}
}


// �̷��� n^2�̳�



int main(void) {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;

	//vertex�� 1���� N����
	for (int i = 1; i <= N; i++) {
		cin >> board[i];
		edge[i] = { i, i + board[i] };
	}

	for (int i = 1; i <= N; i++) {
		DFS(i);
		/*for (int j = 0; j < N; j++) {
			visited[j] = false;
		}*/
		curcnt = 1;
		// �������� ���� �� cycle �ȿ� ���� ���� ���� -> cycle �ٱ��� ����
	}

	cout << max_cycle_num;




	return;
}

/*

�κ����� 0�� �Ǵ� �� �ƴѰ�
1������ ������� ���� ��
  3 -2 5 3 -2 -2 4
0 3  1 6 9  7  5 9

�׷� ��� ���� �� �����ϴ� O(N^2)

O(n)���� Ǯ�� O(nlogn)���� Ǯ�����

���Ͽ�-���ε带 ���ٸ�
����Ŭ ã�°ǵ�
1�� ��� -> 4�� ��� ����
4�� ��� -> 
�̷��� �ȵ� �̰� ������ ã�°���
DFS�� �Ǻ��ϸ� �ǰڴ�

�̹� visited�� vertex�� ���� cnt�� ���̸� �����൵ ��
�� ���� DFS���� cycle�� ã�´� -> �� cycle�� ���� visited�� ��
�� cycle���� �� ū cycle�� ���� �� �ִ°�? NO. ���� Ư���� ����.
�׷��� 
DFS(i)���Ŀ� curcnt=1�� �ϴ� ������ �ٽ� ���ο� cycle�� ã�ƾ߸� �ϱ� ������
DFS(i)���� Ž���� vertex j���� visited�� ���� ã�´ٸ� -> �̰� �̹� ã�� cycle�̹Ƿ� pass
unvisited cycle�� ã�ƾ߸� �� -> �׷��� curcnt = 1�� �ٽ� ��.

�Ҹ�ð� 55��.
�˰��� �����ϴ� �� �ð� ���� ��.


*/