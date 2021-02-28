#include <string>
#include <vector>

using namespace std;


// op[i] == true : i번째 숫자는 더함.
void DFS(int depth, int maxdepth, int target, vector<int> &num, vector<bool> &op, int &answer){
    if(depth == maxdepth){
        int cal = 0, opnum = num.size();
        for(int i = 0; i<opnum; i++){
            cal += op[i]? num[i] : -1*num[i];
        }
        if(cal == target) answer++;
        return;
    }
    
    op[depth] = true;
    DFS(depth+1, maxdepth, target, num, op, answer);
    op[depth] = false;
    DFS(depth+1, maxdepth, target, num, op, answer);
    return;
}

int solution(vector<int> numbers, int target) {
    int num_num = numbers.size();
    vector<bool> op(num_num, true);
    int answer = 0;
    DFS(0, num_num, target, numbers, op, answer);
    return answer;
}

// 2^n을 DFS