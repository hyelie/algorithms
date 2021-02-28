#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<bool> dp(10000001, true);        // 소수이면 true, 아니면 false
set<int> candidates;

void isPrime(){
    dp[0] = dp[1] = false;
    for(int i = 2; i<10000001; i++){
        if(dp[i] == false){
            continue;
        }
        else{
            dp[i] = true;
            for(int j = 2*i; j<10000001; j += i){
                dp[j] = false;
            }
        }
    }
}

// isUsed : 사용되었으면 true, 아니면 false
void backtrack(int depth, int Max, vector<int> &nums,vector<bool>& isUsed, string &s){
    if(depth == Max){
        candidates.insert(stoi(s));
        return;
    }
    
    for(int i = 0; i<isUsed.size(); i++){
        if(!isUsed[i]){
            s.push_back(nums[i] + '0'); isUsed[i] = true;
            backtrack(depth+1, Max, nums, isUsed ,s);
            s.pop_back();isUsed[i] = false;
        }
    }
}

int solution(string numbers) {
    
    int len = numbers.length();
    vector<int> nums(numbers.length());
    for(int i = 0; i<len; i++){
        nums[i] = numbers[i]-'0';
    }
    
    
    for(int i = 0; i<len; i++){
        string s = "";
        vector<bool> isUsed(len, false);
        backtrack(i, len, nums, isUsed, s);
    }
    
    isPrime();
    
    int answer = 0;
    set<int>::iterator i;
    for(auto i = candidates.begin(); i!= candidates.end(); i++){
        if(dp[*i]) answer++;
    }
    return answer;
}

// 순열 구현.