#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, S;
    cin >> N >> S;
    vector<int> v;
    int ipt;
    
    for(int i=1; i<=N; i++){
        cin >> ipt;
        v.push_back(ipt);
    }
    int left=0, right=0;
    int sums=v[0];
    int result=1000000001; // 10억
    int len = 100001;
    int flag=0;
    while(1){
        if(right== N || left== N)
            break;

        if(sums < S){
            right++;
            sums = v[right]+sums;
            //cout << v[left] << " " <<v[right] <<" "<< sums << "\n";
            
        }
        else if(sums >= S){
            flag=1;
            result = min(result, sums);
            sums = sums - v[left];
            len = min(len, right-left+1);  
            //cout << v[left] << " " <<v[right] <<" "<< sums << "\n";
            left++;
        }
    }
    if(flag==0){
        cout << "0";
    }
    else{
        cout << len;
    }
}