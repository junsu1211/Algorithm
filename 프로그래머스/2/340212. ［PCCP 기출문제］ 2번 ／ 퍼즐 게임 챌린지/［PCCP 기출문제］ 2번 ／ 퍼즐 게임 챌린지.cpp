#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    // 레벨의 범위는 정해져 있음
    vector<int> v = diffs;
    sort(v.begin(), v.end());
    int high = v[v.size()-1];
    int low = v[0];
    long long level;
    long long sum=0;
    int flag=0;
    int mid;
    
    while(1){
        flag=0;
        mid = (low+high)/2;
        level = mid;
        
        for(int i=0; i<diffs.size(); i++){
            if(diffs[i] <= level){ // 현 레벨보다 같거나 작으면
                sum = sum + times[i];
            }
            else if(diffs[i] > level){ // 현레벨보다 크면
                sum = sum + (diffs[i]-level)*(times[i-1]+times[i]) + times[i]; 
            }
            
            if(sum > limit){
                flag=1;
                low = mid;
                break; // limit 넘어버리면 탈출
            }
        }
        
        if(flag == 0){
            high = mid;
        }
        sum=0;
        //1 2 3 4 5
        //l h    
        //h
        if(low+1 == high && flag == 1){
            answer = high;
            break;
        }
        else if(low == high){
            answer = high;
            break;
        }
        
           
    }

    return answer;
}