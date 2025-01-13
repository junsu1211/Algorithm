#include <string>
#include <vector>

using namespace std;

int odd(int x){
    x = x*3 +1;
    return x;
}

int even(int x){
    x = x/2;
    return x;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int n=0;
    
    vector<int> y;
    y.push_back(k); // 초기값
    
    while(k!=1){
        if(k%2 == 0){
            k = even(k);
        }
        else{
            k = odd(k);
        }
        y.push_back(k);
        n++;
    }
    printf("%d\n", n);
    int a, b;
    double ans=0;
    
    for(int i=0; i<ranges.size(); i++){
        ans = 0;
        
        a = ranges[i][0];
        b = n + ranges[i][1];
        
        if(a < b){
        
        for(int t=a; t<b; t++){
            if((y[t] + y[t+1] )%2 == 0){
                ans = ans + ( ( y[t] + y[t+1] ) /2 );
            }
            else{
                ans = ans + ( (y[t] + y[t+1]) / 2) + 0.5;
            }
        }
        answer.push_back(ans);
        }
        else if(a == b){
            answer.push_back(0);
        }
        else if(a > b){
            answer.push_back(-1);
        }
    }
    
    
    
    return answer;
}