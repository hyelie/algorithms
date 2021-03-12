#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int V, E;

void solve();
// bipartite�� true
bool BFS(int start, vector<vector<int>>& adjacent, vector<int>& color) {
	queue<int> q;
	q.push(start);
	color[start] = 1;

	int temp, tempcolor;
	bool break_condition = false;
	while (!q.empty() && !break_condition) {
		temp = q.front(); q.pop();
		tempcolor = color[temp];
		for (int i = 0; i < adjacent[temp].size(); i++) {
			if (color[adjacent[temp][i]] == tempcolor) {
				break_condition = true;
				break;
				//!!!!!!!!
			}
			if (color[adjacent[temp][i]] == 0) {
				color[adjacent[temp][i]] = tempcolor == 1 ? 2 : 1;
				q.push(adjacent[temp][i]);
			}
		}
	}

	return !break_condition;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
	return 0;
}

void solve() {
	 cin >> V >> E;
	 vector<vector<int>> adjacent(V + 1);
	 // adjacent[v] : v���� �ٸ� vertex���� edge vector
	 int s, e;
	 for (int i = 0; i < E; i++) {
		 cin >> s >> e;
		 adjacent[s].push_back(e);
		 adjacent[e].push_back(s);
	 }

	 vector<int> color(V + 1, 0);
	 // color[i] : i��° vertex�� color
	 // 0 : unvisit
	 // 1, 2�� �ĺ�

	 
	 bool isBipartite;
	 for (int i = 1; i <= V; i++) {
		 if (color[i] == 0) {
			 isBipartite = BFS(i, adjacent, color);
			 if (!isBipartite) break;
		 }
	 }

	 if (isBipartite) {
		 cout << "YES\n";
	 }
	 else {
		 cout << "NO\n";
	 }

	return;
}

/*

bipartite graph : 2���� ������ ��. �Ѱ��� red, �Ѱ��� blue �����ϰ� red-red �̾� 
Ž���Ǹ� not bipartite

�׸���, ��� node�� ���� bipartite���� ���ƾ� ��
bipartite�� ������ �� ����.

*/