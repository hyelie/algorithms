#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int board[100001], N, max_cycle_num = -1;
pii edge[100001];
// edge.first : 출발 vertex, second : 도착 vertex
// edge[i].second : i에서 second로 도착하는 거.
bool visited[100001];
int cnt[100001], curcnt = 1;
// cnt[i] : i번째 vertex가 받은 번호가 몇번인지

void solve();

void DFS(int cur) {
	visited[cur] = true;
	cnt[cur] = curcnt;
	curcnt++;

	if (!visited[edge[cur].second]) {
		DFS(edge[cur].second);
	}
	// 방문한 곳- > cycle임.
	else {
		max_cycle_num = max(max_cycle_num, curcnt - cnt[edge[cur].second]);
	}
}


// 이러면 n^2이네



int main(void) {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;

	//vertex는 1부터 N까지
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
		// 다음으로 보는 게 cycle 안에 있을 수는 없음 -> cycle 바깥에 있음
	}

	cout << max_cycle_num;




	return;
}

/*

부분합이 0이 되는 거 아닌가
1번부터 순서대로 봤을 때
  3 -2 5 3 -2 -2 4
0 3  1 6 9  7  5 9

그럼 모든 발판 다 봐야하니 O(N^2)

O(n)으로 풀든 O(nlogn)으로 풀어야함

유니온-파인드를 쓴다면
싸이클 찾는건데
1번 노드 -> 4번 노드 연결
4번 노드 -> 
이러면 안됨 이건 합집합 찾는거지
DFS로 판별하면 되겠다

이미 visited인 vertex에 대해 cnt의 차이만 구해줘도 됨
한 번의 DFS에서 cycle을 찾는다 -> 그 cycle은 전부 visited가 됨
그 cycle보다 더 큰 cycle이 있을 수 있는가? NO. 발판 특성상 없음.
그러면 
DFS(i)이후에 curcnt=1로 하는 이유는 다시 새로운 cycle을 찾아야만 하기 때문임
DFS(i)이후 탐색한 vertex j에서 visited한 것을 찾는다면 -> 이건 이미 찾은 cycle이므로 pass
unvisited cycle을 찾아야만 함 -> 그래서 curcnt = 1로 다시 둠.

소모시간 55분.
알고리즘 생각하는 데 시간 많이 씀.


*/