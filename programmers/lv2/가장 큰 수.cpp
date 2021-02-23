#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const int &a, const int &b){
    return stoi(to_string(a) + to_string(b)) > stoi(to_string(b) + to_string(a));
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);

    string answer = "";
    
    int n = numbers.size();
    for(int i =0; i<n; i++){
        if(answer.length()>=1 && answer[0] == '0') continue;
        answer.append(to_string(numbers[i]));
    }
    
    return answer;
}

// 배열 크기는 10만, 각 원소는 1000이하.
// greedy.
// 문자열로 바꾸어서 결과 제출이고
// 앞자리가 제일 큰 것부터 정렬
// 3보다는 30이 뒤에 있어야 함
// 3보다는 34가 앞에 있어야 함
/// 77보다는 778이 앞에, 776이 뒤에.
// 1000이하니까
// 3, 30, 34 -> 34, 3, 30
// 젤 뒤에 있는 걸 붙여넣으면?
// 333, 300, 344 -> 344, 333, 300
// 이러면 정렬은 되네. -> 안됨.
// 40, 403 보면
// 40403보다 40340이 더 작음
// 근데 40 -> 400, 403 -> 403이 됨. 그래서 403이 더 앞으로 와서 작아지게 됨.