#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int size = priorities.size();
    int answer = 0;
    
    queue<pair<int, int>> q;
    // 내가뽑고 싶은 거 : second에 1
    for(int i = 0; i<size; i++){
        if(i == location) q.push({priorities[i], 1});
        else q.push({priorities[i], 0});
    }
    
    int num = 1;
    while(!q.empty()){
        int front_priority = q.front().first; // J에 대한 정보
        int ismy = q.front().second;
        q.pop();
        
        bool isOK = true;   // J를 출력해도 되는지에 대한 bool
        int qsize = q.size();
        while(qsize--){
            if(q.front().first > front_priority) isOK = false;
            q.push({q.front().first, q.front().second});
            q.pop();
        }
        
        // 출력 불가면 젤 앞에 있던 거 젤 뒤에 넣고
        if(!isOK){
            q.push({front_priority, ismy});
        }
        // 출력 가능하면 num++(출력했다는 정보)
        else{
            if(ismy){
                answer = num;
                break;
            }
            num++;
        }
        
    }
    
    
    return answer;
}

// circular queue