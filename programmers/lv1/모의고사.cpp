#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int correct(vector<int> &answers, vector<int> &choose){
    int correct_num = 0;
    int choose_size = choose.size();
    for(int i = 0, j = 0; i<answers.size(); i++){
        if(answers[i] == choose[j]){
            correct_num++;
        }
        j++;
        if(j == choose_size) j = 0;
    }
    return correct_num;
}

vector<int> solution(vector<int> answers) {
    
    vector<int> one(5); one = {1, 2, 3, 4, 5};
    vector<int> two(8); two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three(10); three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> num_correct(3);
    num_correct[0] = correct(answers, one);
    num_correct[1] = correct(answers, two);
    num_correct[2] =  correct(answers, three);
    
    int max_correct = *max_element(num_correct.begin(), num_correct.end());
    
    vector<int> answer;
    for(int i = 0; i<3; i++){
        if(num_correct[i] == max_correct) answer.push_back(i+1);
    
    
    return answer;
}