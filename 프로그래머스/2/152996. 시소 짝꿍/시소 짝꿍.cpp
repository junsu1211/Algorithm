#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
        
    int left=0; 
    int right=1;
    
    //4a=2b , 4a=3b, 3a=2b, a=b
    while(1){
        if(weights[left]*4 < weights[right]*2 || right == weights.size() ){
            left++;
            right = left+1;
        }
        
        if(left == weights.size()-1)
            break;
    
        if(weights[left] == weights[right]){
            answer++;
        }
        else if(weights[left]*4 == weights[right]*2){
            answer++;
        }
        else if(weights[left]*4 == weights[right]*3){
            answer++;
        }
        else if(weights[left]*3 == weights[right]*2){
            answer++;
        }
        
        right++;
        
    }
    
    
    return answer;
}