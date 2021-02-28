#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

bool mycomp(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}

struct qcomp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    set<int> s;
    sort(costs.begin(), costs.end(), mycomp);
    int total_num_bridge = costs.size(), current_num_bridge = 0;
    
    
    
    vector<vector<int>> graph(n, vector<int> (n, -1));    // graph 표현 방식. graph[i][j] : i<->j edge.
                                                        // -1이면 없는거
    
        // edge list 초기화
    for(int i = 0; i<total_num_bridge; i++){
        graph[costs[i][0]][costs[i][1]] = graph[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    
    /*for(int i = 0; i<n; i++){
        cout<<"edge "<<i<<endl;
        for(int j = 0; j<graph[i].size(); j++){
            cout<<graph[i][j]<<" ";
        }cout<<endl;
    }*/
    
    // 초기화 : 젤작은거 넣음
    // pq.first = 도착지, pq.second = 가격.
    priority_queue<pair<int, int>, vector<pair<int, int>>, qcomp> pq;
    s.insert(costs[0][0]); s.insert(costs[0][1]);
    answer += costs[0][2];
    current_num_bridge++;
    for(int i = 0; i<n; i++){
        // 넣은 vertex들의 {neighbor vertex idx, weight}
        if(graph[costs[0][0]][i] != -1) pq.push({i, graph[costs[0][0]][i]});
        if(graph[costs[0][1]][i] != -1) pq.push({i, graph[costs[0][1]][i]});
    }
    
    while(current_num_bridge != n-1){
        pair<int, int> temp = pq.top(); pq.pop();
        // 삽입 불가(cycle 생김. 이미 있는 vertex)
        if(s.insert(temp.first).second == false) continue;
        // 삽입 가능
        else{
            current_num_bridge++;
            answer += temp.second;
            for(int i = 0; i<n; i++){
                if(graph[temp.first][i] != -1) pq.push({i, graph[temp.first][i]});
            }
        }
    }
    return answer;
}

// cost[i][0], cost[i][1] : 연결되는 두 섬의 번호, cost[2] : 건설비용
// 이거... MST아닌가?