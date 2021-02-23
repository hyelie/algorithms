#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int clock = 0; // 시간초
    int passing_sum = 0; // 다리를 건너는 트럭의 무게 합
    
    queue<int> q;   // 대기 트럭
    int truck_num = truck_weights.size();
    for(int i = 0; i<truck_num; i++){
        q.push(truck_weights[i]);
    }
    
    queue<pair<int, int>> passing_q;  // first는 진입한 clock(clock+bridge_length가 되면 나가야함), second는 그 차의 무게
    
    while(!q.empty()){
        if(!passing_q.empty() && clock == passing_q.front().first + bridge_length){
            passing_sum -= passing_q.front().second;
            passing_q.pop();
        }
        if(q.front() + passing_sum <= weight){
            passing_sum += q.front();
            passing_q.push({clock, q.front()});
            q.pop();
        }
        clock++;
    }
    clock += bridge_length;
    
    return clock;
}

// (다리를 건너는 트럭)에 있는 시간이 length만큼임.
// 1초마다 다 계산가면 100,000,000 - 1억