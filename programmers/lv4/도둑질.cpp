#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int num = money.size();
    // DPn[i] : i번째 집 털 때까지 최댓값.
    
    // 첫번째 집을 터는 경우
    vector<int> DP1(num);
    DP1[1] = DP1[0] = money[0];
    // 첫 번째 집을 털지 않는 경우
    vector<int> DP2(num);
    DP2[0] = 0;
    DP2[1] = money[1];
    
    for(int i = 2; i<num; i++){
        // 이전 집을 턴 경우 : DP[i] = DP[i-1]
        // 이전 집을 안 턴 경우 : DP[i] = DP[i-2] + money[i]
        DP1[i] = max(DP1[i-1], DP1[i-2] + money[i]);
        DP2[i] = max(DP2[i-1], DP2[i-2] + money[i]);
    } 
    DP1[num-1] = DP1[num-2];
    
    int answer = max(DP1[num-1], DP2[num-1]);
    return answer;
}

// DP인데. 연속된 2개의 집을 털 수 없다고 되어 있음
// 첫 번째 집을 털면 마지막 집을 못털고
// 첫 번째 집을 안 털면 마지막 집을 털 수 있음
// 종류를 2개로 해서 다른 종류의 DP를 하고 2개 MAX 취하면 될 듯.