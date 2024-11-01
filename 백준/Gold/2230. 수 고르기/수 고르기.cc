#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v;
    int ipt;

    for(int i=1; i<=N; i++){
        cin >> ipt;
        v.push_back(ipt);
    }

    int left=0, right=0;
    int len=0;
    int cons=2100000000;

    // 정렬을 해도 상관 없음
    sort(v.begin(), v.end());
    // 1 3 5 7 9 11 15 18
    while(1){
        if(right==N || left == N){
            break;
        }

        len = v[right] - v[left];
        if(len < M){

            right++;
        }
        else if(len >= M){ // 그 차이가 m을 넘어서는 순간
            cons = min(cons, len);
            left++;
        }
    
    }
    cout << cons;
}