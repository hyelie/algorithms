#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 요청시간 빠른거부터, 같다면 작업시간 작은 순대로
bool listcomp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first) return a.second<b.second;
    else return a.first<b.first;
}

struct qcomp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second) return a.first > b.first;
        else return a.second > b.second;
    }
};

// 작업시간이 작은 순대로, 같으면 요청시간 빠른거부터

int solution(vector<vector<int>> jobs) {
    int len = jobs.size();
    vector<pair<int, int>> lists(len);
    for(int i = 0; i<len; i++){
        lists[i] = {jobs[i][0], jobs[i][1]};
    }
    sort(lists.begin(), lists.end(), listcomp);
    priority_queue<pair<int, int>, vector<pair<int, int>>, qcomp> pq;
    
    int clock=0;
    int jobtime_sums = 0;
    int iter =0 ;
    while(iter != len){
        if(pq.empty()){
            clock = lists[iter].first + lists[iter].second;
            jobtime_sums += lists[iter].second;
            iter++;
            //cout<<"1:"<<clock<<" "<<jobtime_sums<<endl;
        }
        else{
            pair<int, int> temp = pq.top(); pq.pop();
            clock += temp.second;
            jobtime_sums += clock - temp.first;
            //cout<<"2:"<<clock<<" "<<jobtime_sums<<endl;
        }
        while(lists[iter].first <= clock && iter != len){
            pq.push(lists[iter]);
            iter++;
            //cout<<"3:"<<iter<<endl;
        }
    }
    
    while(!pq.empty()){
        pair<int, int> temp = pq.top(); pq.pop();
        //cout<<"check:"<<temp.first<<" "<<temp.second<<endl;
        clock += temp.second;
        jobtime_sums += clock - temp.first;
        //cout<<"4:"<<clock<<" "<<jobtime_sums<<endl;
    }
    
    
    int answer = jobtime_sums / len;
    return answer;
}

// jobs[i][0] : 작업 i가 요청되는 시점
// jobs[i][1] : 작업 i가 소요되는 시간
// 평균을 가장 줄이는 방법 : 짧은거부터(SJF) - 평균대기시간 제일 짧음
// 1 <= jobs.size() <= 500

// 짧은거부터 heap에 넣으면 되지 싶음

// jobs를 요청 시점(오름차순), 소요 시간(오름차순)으로 정렬한 lists
// 현재 clock보다 요청 시간이 더 작아서, 작업 시작을 기다리고 있는 min heap pq
// 만약 pq가 비었다면 다음 job을 받아들이면 됨.(받아들인다 : clock = 다음 작업 요청시간 + 다음 작업 시간)
// pq가 비지 않았다면 제일 짧은 걸 하면 됨. pq가 비지 않았다 = 요청시간보다는 시간이 지났다 : clock += 다음 작업 시간




