#include <string>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 각 genres의 재생 회수 다르니까 총 재생 회수만 비교
bool genres_comp(const pair<string, pair<int, vector<pair<int, int>>>> &a, const pair<string, pair<int, vector<pair<int, int>>>> &b){
    return a.second.first > b.second.first;
}

// 각 plays를 정렬. first(i)는 오름차순, second(plays)는 내림차순
bool plays_comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second > b.second) return true;
    else if(a.second < b.second) return false;
    else{
        if(a.first < b.first) return true;
        else return false;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();
       
    unordered_map<string, pair<int, vector<pair<int, int>>>> m;
    
    // 일단 각 genres마다 총 play time 합이 있어야 하고, 이거 순서대로 정렬되어 있어야 함.
    // 그리고 각 genres마다 각 plays와 i(식별번호)가 {내림차순, 오름차순}으로 정렬되어 있어야 함.
    
    // m의 key : genres. ex) classic, pop, ...
    // m의 value : {plays의 합, map} pair
    // m.value.first = 해당 genres의 총 재생 회수
    // m.value.second = pair vector, first = i(고유 번호), second = 재생 회수
    
    for(int i = 0; i<n; i++){
        if(m.find(genres[i]) == m.end()){
            vector<pair<int, int>> subv(1, {i, plays[i]});
            m[genres[i]] = {plays[i], subv};
        }
        else{
            m[genres[i]].first += plays[i];
            m[genres[i]].second.push_back({i, plays[i]});
        }
    }
    
    vector<pair<string, pair<int, vector<pair<int, int>>>>> genres_plays_link(m.begin(), m.end());
    sort(genres_plays_link.begin(), genres_plays_link.end(), genres_comp);
    
    for(int i = 0; i<genres_plays_link.size(); i++){
        sort(genres_plays_link[i].second.second.begin(), genres_plays_link[i].second.second.end(), plays_comp);
    }
    
    vector<int> answer;
    
    for(int i = 0; i<genres_plays_link.size(); i++){
        answer.push_back(genres_plays_link[i].second.second[0].first);
        if(genres_plays_link[i].second.second.size() > 1){
            answer.push_back(genres_plays_link[i].second.second[1].first);
        }
    }
    
    return answer;
}

// 1. 속한 노래가 많이 재생된 장르부터
// 2. 장르 내에서 가장 많이 재생된 노래부터
// 3. 2가 같으면 번호가 낮은 노래부터

// genres.size() < 100
// genres의 play 회수가 다름
// genres[i] : 고유번호가 i
// 장르별로 2개씩 모음.

// genres에 따라 unordered map(hash) 하나 만듦
// 값 있으면 더하고 없으면 재생수 play에 있는거로 추가
// 장르 종류가 100개 미만이므로 이 hash 순회하면서 play 순서 가져옴

// 그리고 

//////////////////////////////////////////////////위에 게 내 코드.
// 코드 자체는 정답지와 유사한데 m 자체가 너무 길어진 듯.
// genres-sum, genres-play_vector 이렇게 2개 나누어서... 하는거도 복잡하긴 하구나
// 결국 코드는 맞았는데 구현에서 너무 헷갈려했던 것 같음. 구현력을 높이자!