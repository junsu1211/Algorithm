#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    // 원형의 개념 필요 %로
    
    int size = elements.size();
    unordered_set<int> s;
    int sum=0;
    
    for(int i=0; i<size; i++){
        s.insert({elements[i]}); // len=1인 경우
    }
        
    for(int len=2; len<=size; len++){
        
        for(int i=0; i<size; i++){
            sum=0;
            for(int k=i; k<i+len; k++){
                sum = sum+elements[k%size];
            }
            s.insert({sum});
        }
    }
    answer = s.size(); 
    
    return answer;
}