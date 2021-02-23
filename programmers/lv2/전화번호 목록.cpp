#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    int n = phone_book.size();
    
    for(int i = 1; i<n; i++){
        if(phone_book[i-1] == phone_book[i].substr(0, phone_book[i-1].length())){
            return false;
        }
    }
    
    return answer;
}

// 접두어인 경우가 있으면 false를, 그렇지 않으면 true를
// 길이는 1000000 (백만) -> nlogn 허용, n^2 허용 x
// 트리를 만들고 

/*
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    for(int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for(int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}
*/
/*

hash는 insert가 O(1)에 수렴하니까 O(n)일 것임
모든 phone number에 대해 hash에 작성하고
string 앞부분이 hash_map에 있으면 접두어가 있는 거니까 false

*/