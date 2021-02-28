#include <string>
#include <vector>

using namespace std;
void DFS(int vertex, vector<bool>& visit, vector<vector<int>>& computers, int n){
    if(visit[vertex]){
        return;
    }
    visit[vertex] = true;
    
    for(int i = 0; i<n; i++){
        if(i == vertex) continue;
        if(computers[vertex][i] == 1 && visit[i] == 0){
            DFS(i, visit, computers, n);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit(n, false);    // visit[i] == 0 : 아직 방문 하지 않음.
    for(int i = 0;i <n;i++){
        if(visit[i]) continue;
        else{
            DFS(i, visit, computers, n);
            answer++;
        }
    }
    
    return answer;
}

// n : 컴퓨터 개수.
// 컴퓨터는 0부터 n-1로 표현
// computers[i][j] == 1 -> 연결됨.

// 유니온-파인드 아닌강
// 모든 대상에 대해 일단 보고
// 만약 이미 본 노드라면 패스.