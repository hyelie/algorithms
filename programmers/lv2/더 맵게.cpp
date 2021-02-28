#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int len = scoville.size();
    int answer = 0;
    
    for(int i = 0; i<len; i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty() && pq.top() < K){
        if(pq.size() == 1){
            answer = 0;
            break;
        }
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        if(first == 0 && second == 0 && K != 0){
            answer = 0; break;
        }
        pq.push(first + 2*second);
        answer++;
    }
    
    return answer==0?-1:answer;
}

// length : 1,000,000 (백만)
// K : 10억 이하

// 반례를 잘 생각 못했던 문제.
// K가 너무 커서 못만드는 경우도 존재한다는 걸 생각했어야 했음.