#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int size = speeds.size();
    
    // 남은 작업일수 계산
    vector<int> left_days(size);
    for(int i = 0; i<size;i++){
        if(speeds[i] == 1){
            left_days[i] = 100 - progresses[i];
        }
        else{
            left_days[i] = (100-progresses[i]) / speeds[i];
            if((100-progresses[i]) % speeds[i] != 0){
                left_days[i]++;
            }
        }
    }
    
    /*for(int i = 0; i<size; i++)
    {
        cout<<left_days[i]<<" ";
    }    */
    // stack으로
    // 남은 작업일수가 5 10 1 1 20 1
    // 5 있는 상태
    // 10은 5보다 크니, 5가 먼저 나감 -> answer.push_back(1)
    // 10 다음 들어오는 1, 1은 10보다 작음 -> answer.push_back(1), answer.last()++, answer.last()++
    // 그 다음 들어오는 20은 10보다 크니까 answer.push_back(1)
    // 앞 문제랑 동일하게 커질 때, 그 전에 몇개가 있었는지 check.
    
    stack<int> s;
    vector<int> answer;
    
    int dummy = 0;
    
    for(int i = 0; i<size; i++){
        // top이 더 작은 경우 -> 그전까지 있던 것들을 전부 출시함
        if(!s.empty() && s.top() < left_days[i]){
            
            s.push(left_days[i]);
            answer.push_back(dummy);
            dummy = 1;
        }
        // top이 더 큰 경우 -> 그까지 있는 것과 같이 출시 가능 -> 쟁여둠(예를 들어 10, 3일 때 개발기간 3인거는 10을 낼 때 같이 출시 가능)
        else if(!s.empty() && s.top() >= left_days[i]) {
            dummy++;
        }
        // stack이 빈 경우(초기화) 처음걸 넣고 dummy=1로 설정
        else{
            s.push(left_days[i]);
            dummy = 1;
        }
    }
    // 맨 마지막에 dummy도 추가해줌
    answer.push_back(dummy);
        
    
    
    
    return answer;
}

// 작업 개수 100개 이하
// 작업 진도 100미만 자연수
// 작업 속도 100 이하 자연수 -> 최대 100번 반복하면 되겠네
// 100*100