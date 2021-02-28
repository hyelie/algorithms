#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size=  prices.size();
    vector<int> answer(size);
    
    priority_queue<pair<int, int>> pq;
    // first는 prices, second는 idx
    for(int i = 0; i<size; i++){
        while(!pq.empty() && pq.top().first > prices[i]){
            answer[pq.top().second] = i - pq.top().second;
            pq.pop();
        }
        
        pq.push({prices[i], i});
    }
    
    while(!pq.empty()){
        answer[pq.top().second] = size - 1 - pq.top().second;
        pq.pop();
    }
    
    
    
    return answer;
}

// 100,000
// n^2 안됨.
// nlogn으로 풀어야 하는ㄷ... -> pq로 품.
// 이게 stack이 된다고..? 그렇네. 구현 방식이 동일함. pq로 굳이 풀 이유가 없었네.
// 내가 pq로 풀어야 한다고 생각한 이유는, 다음 idx의 price가 들어오면 그 전까지의 것 중에 최대치와 비교해야 한다고 생각했음.

// pq에 큰 숫자가 top에 오도록 삽입하면
// 1 2 3 2 3
// 1은 끝날때까지 안떨어지니 4
// 2는 끝날때까지 안떨어지니 3
// 3은 2에서 떨어져버리니 1
// 2는 끝날때까지 안떨어지니 1
// 3은 끝날때까지 안떨어지니 0