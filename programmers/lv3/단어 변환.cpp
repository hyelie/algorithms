#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool one_word_diff(string a, string b){
    int diff_num = 0, len = a.length();
    for(int i= 0; i<len; i++){
        if(diff_num > 2) return false;
        if(a[i] != b[i]) diff_num++;
    }
    return diff_num==1?true:false;
}
// O(a.length());

int solution(string begin, string target, vector<string> words) { 
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    
    
    int words_num = words.size(), words_add_num = words_num+2;;
    vector<string> words_add(words_add_num);
    
    for(int i = 1; i<words_add_num-1; i++){
        words_add[i] = words[i-1];
    } words_add[0] = begin; words_add[words_add_num-1] = target;
    
    vector<vector<bool>> edge(words_add_num, vector<bool>(words_add_num, false));
    for(int i = 0; i<words_add_num; i++){
        for(int j = 0; j<words_add_num; j++){
            if(i == j)
                edge[i][j] = false;
            else
                edge[i][j] = one_word_diff(words_add[i], words_add[j])?true:false;
            
        }
    }
    // O(words_num^2 * a.length());
    
    vector<int> dist(words_add_num, 9999);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    
    while(!q.empty()){
        int qidx = q.front(); q.pop();
        for(int i = 0; i<words_add_num; i++){
            if(dist[i] == 9999 && edge[qidx][i]){
                dist[i] = dist[qidx] + 1;
                q.push(i);
            }
        }
    }
    
    int answer = dist[words_add_num-1] != 9999?dist[words_add_num-1]:0;
    return answer;
}

// BFS
// 인접하다 -> 한글자만 다르다!

// hit -> hot -> lot -> log -> dog -> cog