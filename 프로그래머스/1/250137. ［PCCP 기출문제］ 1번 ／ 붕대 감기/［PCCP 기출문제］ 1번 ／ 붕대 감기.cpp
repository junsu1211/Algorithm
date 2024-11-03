#include <string>
#include <vector>

using namespace std;


int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    int cnt=0;
    int atcnt=0;
    int nowtime=1;
    int addtm=0; // 추가 회복시켜주는 시간
    int mh = health;
    // 첫번째 공격 전 까지의 체력을 구해놓자
     
    
    while(1){
        
        
        
        if(attacks[atcnt][0] == nowtime){ // 공격 시간이다
            health = health - attacks[atcnt][1]; // 피 깎기
            addtm = 0; // 추가 회복시간 초기화    
            if(health <= 0){ // 죽는다면 리턴
                answer = -1;
                break;
            }  
            atcnt++; // 다음 공격 받기
        }
        else{ // 공격 받는 시간이 아니라면
            addtm++; //현재 공격 안받아서 연속 힐링 성공
            
            if(health < mh){ // 또한 현재 최대 체력이 아니라면
                health = health + x; // 초당 회복량 일단 추가
                if(addtm == t){ // 만약 연속 시간도 채웟다면
                    health = health + y; // 추가회복
                    addtm=0; // 초기화
                }
            }
            if(health > mh){
                health = mh; // 최대체력 넘겨버렸으면
            }
           
            
        }
        
        
        if(atcnt == attacks.size()){ // 마지막 공격을 받으면 종료
            answer= health;
            break;
        }
        
        nowtime++; // 초 증가
    }
    
    
    
    return answer;
}