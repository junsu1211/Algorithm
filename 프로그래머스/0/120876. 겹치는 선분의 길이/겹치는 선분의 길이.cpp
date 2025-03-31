#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    // 선분은 무조건 3개인가? 그렇다.
    
    sort(lines.begin(), lines.end());
    
    // 0과 1 구간 비교
    vector<pair<int,int>> v;
    
    // 0과 1
    int x = lines[1][0];
    
    if( lines[0][1] > x){ // 겹치는 구간 있음
        if(lines[0][1] <= lines[1][1]){
            v.push_back({x,lines[0][1]});
        }else if(lines[0][1] > lines[1][1]){
            v.push_back({x,lines[1][1]});
        }
    }
    
    // 0과 2 구간 비교
    x = lines[2][0];
    
    if( lines[0][1] > x){
        if(lines[0][1] <= lines[2][1]){
            v.push_back({x,lines[0][1]});
        }
        else{
            v.push_back({x,lines[2][1]});
        }
    }
    
    // 1과 2 구간 비교
    x = lines[2][0];
    if (lines[1][1] > x){
        if(lines[1][1] <= lines[2][1]){
            v.push_back({x,lines[1][1]});
        }
        else{
            v.push_back({x,lines[2][1]});
        }
    }
    
    int min=101;
    int max=-101;
    for(int i=0; i<v.size(); i++){
        if(v[i].first <= min){
            min = v[i].first;
        }
        if(v[i].second >= max){
            max = v[i].second;
        }
        printf("%d, %d\n", v[i].first, v[i].second);
    }
    
    printf("%d, %d\n", min, max);
    
    if(max > 0){
        int* arr = new int[max+1];    
        for(int i=min; i<=max; i++){
            
            for(int t=0; t<v.size(); t++){
                if(v[t].first < i && v[t].second >= i){
                    arr[i] = 1;
                }
            }
            
        }
      
        for(int i=min; i<=max; i++){
           if(arr[i]==1){
             answer++;
           }
        }
    }
    
    if(v.size() == 0){
        answer=0;
    }
    
    return answer;
}