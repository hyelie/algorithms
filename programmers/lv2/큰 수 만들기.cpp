#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    
    vector<char> v;
    for (auto c:number){
        v.push_back(c);
    }
    
    vector<char>::iterator iter;
    int k_iter = k;
    while(k_iter--){
        bool isDelete = false;
        for(iter = v.begin(); iter != v.end()-1; iter++){
            if(*iter < *(iter+1)){
                isDelete = true;
                v.erase(iter);
                break;
            }
        }
        if(!isDelete){
            v.erase(iter);
        }
    }
    
    string answer = "";
    for(int i = 0; i<v.size(); i++){
        answer.push_back(v[i]);
    }
    return answer;
}

// 앞에서  젤 작은 걸 뺌. 같은 수라면 앞에 있는 걸 뺌
// 전체 수에서 오름차인 것 중 앞에 있는 수를 뺌
// 4177252841
// 477252841
// 77252841
// 7752841
// 775841

// 