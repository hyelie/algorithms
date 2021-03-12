#include <string>
#include <vector>
#include <iostream>

//vector<vector<int>> candidates_idx;

using namespace std;

// cols.first : 몇번째 col인지 / cols.second : 쓴 건지
void backtrack(int depth, int maxD, vector<pair<int, bool>>& cols, vector<vector<int>>& candidates_idx) {
    if (depth == maxD) {
        vector<int> comb;
        for (int i = 0; i < cols.size(); i++) {
            if (cols[i].second) {
                comb.push_back(i);
            }
        }
        candidates_idx.push_back(comb);
        return;
    }
    for (int i = depth; i < cols.size(); i++) {
        if (cols[i].second) continue;
        else {
            cols[i].second = true;
            backtrack(depth + 1, maxD, cols, candidates_idx);
            cols[i].second = false;
        }
    }

}

int solution(vector<vector<string>> relation) {
    int row = relation.size();
    int col = relation.size();

    /*for(int i = 0; i<relation.size(); i++){
        for(int j = 0; j<relation[0].size(); j++){
            cout<<relation[i][j]<<" ";
        }cout<<endl;
    }*/

    vector<vector<int>> candidates_idx;
    vector<pair<int, bool>> cols(col);
    for (int i = 0; i < col; i++) {
        cols[i].first = i;
        cols[i].second = false;
    }

    backtrack(1, col, cols, candidates_idx);

    for (int i = 0; i < candidates_idx.size(); i++) {
        for (int j = 0; j < candidates_idx[0].size(); j++) {
            cout << candidates_idx[i][j] << " ";
        }cout << endl;
    }




    int answer = 0;
    return answer;
}

// n = column num
// nC1 + nC2 + nC3 + ... nCn
// 각각에 대해 다 봐야 할듯.

int main() {
    vector<vector<string>> relation(6, vector<string>(4));
    relation[0] = { "100", "ryan", "music", "2" };
    relation[1] = { "200", "apeach", "math", "2" };
    relation[2] = { "300", "tube", "computer", "3" };
    relation[3] = { "400", "con", "computer", "4" };
    relation[4] = { "500", "muzi", "music", "3" };
    relation[5] = { "600", "apeach", "music", "2" };


    solution(relation);
}