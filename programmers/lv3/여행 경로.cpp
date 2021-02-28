#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

// 오름차순
bool mycomp(const vector<string> &a, const vector<string> &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    else return a[0] < b[0];
}

bool backtrack(int depth, int maxD, string from, vector<bool> &used, vector<vector<string>>& tickets, vector<string> &answer){
    if(depth == maxD){
        answer.push_back(from);
        return true;
    }
    for(int i = 0; i<maxD; i++){
        if(tickets[i][0] == from && used[i] == false){
            used[i] = true;
            answer.push_back(from);
            bool temp = backtrack(depth+1, maxD, tickets[i][1], used, tickets, answer);
            if(temp) return true;
            else{
                used[i] = false;
                answer.pop_back();
            }
        }
    }
    return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), mycomp);
    int num = tickets.size();
    vector<bool> used(num, false);
    vector<string> answer;
    bool temp = backtrack(0, num, "ICN", used, tickets, answer);
    return answer;
    
}

// ICN 출발. DFS


/*
a b
b d
d c
d a
a d
*/