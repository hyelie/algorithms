#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> total(n+1, 1);
    for(int i = 0; i<lost.size(); i++){
        total[lost[i]]--;
    }
    for(int i = 0; i<reserve.size();i++){
        total[reserve[i]]++;
    }
    
    
    
    
   
    
    int answer=0;
    if(total[0] == 0 && total[1] == 2){
        total[0]++; total[1]--;
    }
    if(n>2 && total[n] == 0 && total[n-1] == 2){
        total[n]++; total[n-1]--;
    }
    for(int i = 1; i<=n; i++){
        if(total[i] == 0){
            if(total[i+1] == 2){
                total[i+1]--; total[i]++;
            }
            else if(total[i-1] == 2){
                total[i-1]--; total[i]++;
            }
        }
    }
    
    for(int i = 1;i <n+1; i++){
        if(total[i] == 1 || total[i] == 2) answer++;
    }
    
    
    return answer;
}

// 0 2 또는 2 0 모든 페어만 찾으면 됨