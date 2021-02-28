#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int com_len = commands.size();
    for(int i = 0; i<com_len; i++){
        vector<int> subarr(array.begin() + commands[i][0]-1, array.begin() + commands[i][1]);
        sort(subarr.begin(), subarr.end());
        answer.push_back(subarr[commands[i][2]-1]);
    }
    
    
    
    return answer;
}