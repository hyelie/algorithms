#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isAllzero(vector<int> &v){
    int len = v.size();
    for(int i = 0; i<len; i++){
        if(v[i] == 1) return false;
    }
    return true;
}

int solution(string name) {
    int answer = 0;
    
    int len = name.length();
    vector<int> isA(len, 1);
    for(int i = 0; i<len; i++){
        if(name[i] == 'A') { isA[i] = 0; }
    }
    
    int curidx = 0;
    
    while(!isAllzero(isA)){
        answer += min(name[curidx] - 'A', 'Z' - name[curidx] + 1);
        isA[curidx] = 0;
        
        int minimum = 30, minidx;
        for(int i = 1; i<len; i++){
            if(isA[i] == 1){
                if(minimum > min(abs(i - curidx), abs(len - i + curidx))){
                    minimum = min(abs(i - curidx), abs(len - i + curidx));
                    minidx = i;
                }
            }
        }
        
        answer += minimum;
        curidx = minidx;
    }
    
    
    
    
    
    return answer-30;
    // 맨 마지막에 30 더해짐
}

// JAN의 경우
// J 9번, 커서 왼쪽(1번), N 12번

// A B C D E F G H I J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

// min(char - 'A', 'Z' - char + 1)하면 각 글자를 만들기 위해 몇번 움직여야 하는지 나오겠네
// 이제 좌우 움직이는거 생각해 보자
// A아닌거 1, A인거 0
// 10111 -> 왼쪽으로 가는게 이득
// 11101 ->
// 11000001
// 111101111
// 110000000101

// 지금 작성하는 칸에서 제일 가까운 A가 아닌 칸을 찾음(for 순회하면서 min(i-현재위치, length-i+현재위치))

// 이거말고 다른방법은?