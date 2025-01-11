#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(wallet[1] < bill[1] || wallet[0] < bill[0]){
       
        // 어찌 되었든 큰 값을 줄여야함
        if(bill[0] > bill[1]){
            bill[0] = bill[0]/2;
        }
        else{
            bill[1] = bill[1]/2;
        }
        answer++;
        // 반으로 줄이는 작업을 한 뒤에 90도로 돌려서 가능한지 확인
        
        if( bill[1] <= wallet[0] && bill[0] <= wallet[1]){
            break; // 탈출
        }
        
    }
    
    
    
    return answer;
}