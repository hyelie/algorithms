#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const int&a, const int&b){
    return a>=b;
}

int solution(vector<int> citations) {
    
    sort(citations.begin(), citations.end(), cmp);
    
    int len = citations.size();

    
    for(int i = 0; i<len; i++){
        if(citations[i] < i+1) return i;
    }
    
    return len;
}

// i+1가 가리키는 것 : citations[i] 이상 인용된 논문의 개수

// citation 배열 중 h보다 값이 크거나 같은 것의 개수가 h 이상이고
// 나머지는 h보다 값이 작거나 같다면 -> H-index.
// 어떤 (index 값) : 그 앞에건 전부 다 그 index값보다 많다 -> 그 idx가 예를 들어 4고 값이 6이다 -> 5편은 6번 이상 읽혔다.
// 그 idx가 예를 들어 5고 값이 5다 -> 6편은 5번 이상 읽혔다가 됨. -> h가 5라는 말.
// 그래서 idx i에서 i+1편은 citations[i] 이상 읽혔다가 됨. 근데 citations[i]<i+1이면 h가 i라는 것
// 만약 

// 6 5 3 1 0
// 6 5 5 5 1 0 0
// 이런 경우는 4번 이상 인용된 논문이 4편 이상, 나머지 논문이 4번 이하 -> 4.


// 5 5 5 5 5 -> 5
// 5 5 5 5 -> 4