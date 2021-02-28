#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    vector<pair<int, int>> divisor;
    for(int i = 2; i<=sqrt(sum); i++){
        if(sum % i == 0) divisor.push_back({i, sum/i});
    }
    
    vector<int> answer;
    
    for(int i = 0; i<divisor.size(); i++){
        if(yellow == (divisor[i].first-2) * (divisor[i].second-2)){
            answer.push_back(divisor[i].second);
            answer.push_back(divisor[i].first);
            break;
        }
    }
    
    
    return answer;
}

// 합의 약수 모든 조합 구하고

// sqrt(sum)보다 작은 모든 약수 구해서 
// 가로-1 * 세로-1이 yellow 되면 되는 것