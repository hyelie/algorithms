#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// 1번 풀이 - sort로
// nlogn
// 2번 정렬 후 n
/*string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int n = completion.size();
    
    for(int i = 0; i<n; i++){
        if(completion[i] != participant[i]){
            return participant[i];
        }
    }
    return participant[n];
}*/

// 1 <= participant.size() <= 100000
// completion.length() = participant.size()-1
// 100000
// 2^7
// 2^10 = 1024
// 2^20 = 100000

// 2번 풀이 
// map으로
// 1개 넣는데 logn이고 n개 넣으니 넣는데는 nlogn
// completion 다 찾는 데 nlogn
// 첨부터 끝까지 순회하는 데 n
// O(nlogn)

string solution(vector<string> participant, vector<string> completion) {
    
    map<string, int> m;
    
    int n = participant.size();
    
    for(int i = 0; i<n; i++){
        if(m.find(participant[i]) == m.end()){
            m[participant[i]] = 1;
        }
        else{
            m[participant[i]]++;
        }
    }
    
    for(int i = 0; i<n-1; i++){
        m[completion[i]]--;
    }
    
    map<string, int>::iterator iter;
    
    for(iter = m.begin(); iter != m.end(); iter++){
        if(iter->second != 0){
            return iter->first;
        }
    }
    return "";
}
