#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// v[0], v[0][0] 순으로 오름차순.
bool mycomp(const vector<int> &a, const vector<int> &b){
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0]){
        return a[1] < b[1];
    }
    else return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), mycomp);
    
    /*for(int i = 0; i<routes.size();i++){
        cout<<routes[i][0]<<" "<<routes[i][1]<<endl;
    }*/
    
    answer++;
    int cam = routes[0][1], routesnum = routes.size();
    
    for(int i = 1; i<routesnum; i++){
        if(cam < routes[i][0]){
            answer++; cam = routes[i][1];
        }
        else if(cam > routes[i][1]){
            cam = routes[i][1];
        }
    }
    
    /*
캠 위치 < 차 진입시점
|         | --------
 => 차 탈출지점에 새 캠을 깜

캠 위치 > 차 탈출지점
--------- |
 => 캠 위치를 앞으로 당겨줌.
 */
    return answer;
}

/*

차 2개의 관계는 3가지임

1) 뒤차의 진입지점 < 앞차의 탈출지점 / 뒤차의 탈출지점 > 앞차의 탈출지점
-------
    ------
-> 이 경우에는 겹치는 부분(어디?)에 캠을 깔아야 함.

    a) 그러면 아래같은 경우는? 1개만 깔면 되는데...
            --------
                ------
                  ---------
    
2) 뒤차의 진입지점, 뒤차의 탈출지점 > 앞차의 탈출지점
-------
        ------
-> 이 경우에는 앞 차 나가는 지점에 캠을 깔고 뒤 차를 보면 됨. PASS
        
3) 뒤차의 진입지점, 뒤차의 탈출지점 < 앞차의 탈출지점
---------
  ----
-> 이 경우는? 뒤 차만 봐주면 됨. PASS

// https://greenapple16.tistory.com/61
여기 풀이가 직관적임.

이렇게 상대적인 차 위치를 보지말고, 캠을 깔고 캠과 차 위치의 상관관계를 보면 됨


캠 위치 < 차 진입시점
|         | --------
 => 차 탈출지점에 새 캠을 깜

캠 위치 > 차 탈출지점
--------- |
 => 캠 위치를 앞으로 당겨줌.
 => 이런 그림이 나왔다는 건 아래 그림과 같음
--------|
   ---
 => 앞 차에서 이런식으로 캠이 깔렸기 때문인 것.
 
 
---------------
  ---------
    --------
      ------------
             -


캠과 루트의 관계는 아래 3가지.
--------- |
| -----------
--------|------ -> OK 아무상관 x 다음차 보면됨


캠 위치보다 앞이라면 -> 

| --------- |

|      |
  ----------
 


*/

/* 이건 다른사람 솔루션
routes는 탈출지점 기준 오름차순 정렬
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int limit = -30001;
    sort(routes.begin(), routes.end(), cmp);
    for(int i = 0; i < routes.size(); i++){
        if(limit < routes[i][0]){
            answer++;
            limit = routes[i][1];
        }
    }
    return answer;
}

----
 -----
        ------
           ----
        -----------
무조건 이런식으로만 나오겠네 
그래서 탈출위치에 캠 깔고 캠 안깔아진다 싶으면 새 캠 까는식으로 했네

     
    
*/