#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> ans;
    
    stack<int> s;
    
    s.push(numbers[numbers.size()-1]);
    ans.push_back(-1);
    
    for(int i=numbers.size()-2; i>=0; i--){
        
        while(1){
             if(s.empty()){
                ans.push_back(-1);
                 break;
             }
            
             if(s.top() > numbers[i]){
                ans.push_back(s.top());
                break;
             }
             else{
                s.pop();
             }
        }
        
        s.push(numbers[i]);        
    }
    
    for(int i=ans.size()-1; i>=0; i--){
        answer.push_back(ans[i]);
    }
    
    
    
    return answer;
}