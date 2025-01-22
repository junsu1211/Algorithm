#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    vector<int> ans(arr.begin(), arr.end());
    sort(ans.begin(), ans.end());
    int min = ans[0]; // 최소값
    
    unordered_set<int> s(arr.begin(), arr.end());
    
    for(int i=0; i< arr.size(); i++){
       if(arr[i] != min){
           answer.push_back(arr[i]);
       }
    }
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    
    return answer;
}