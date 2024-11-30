#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int y = park.size();
    int x = park[0].size();
    string ts;
    
    int startx = 0;
    int starty = 0;
    
    for(int i=0; i<y; i++){ // 시작점 찾기
        ts = park[i];
        for(int t=0; t<x; t++){
            if(ts[t] == 'S'){
                startx = t;
                starty = i;
                break;
            }
        }
    }   
    
    int cmy = routes.size();
    int cmx = routes[0].size();
    int flag=0;
    
    string s;
    string field;
    
    int how = 0;
    int no = -1;
    
    for(int i=0; i<cmy; i++){
        
        s = routes[i]; // 명령 저장
        how = s[2] - '0';
        field = park[starty];
        printf("현재 명령 : %d %c %d %c\n", i, s[0], how, field[0]);
        no = -1;
        
        if(s[0] == 'E'){
            if(startx + how < x){ //공원을 벗어나는가?
                no = field.find('X', startx);
                
                if(no <= startx + how && no >= 0){ //가려는 곳에 'x'가 있으면
                }
                else{ // 없으면
                    printf("더하기 %d\n", startx+ how);
                    startx = startx + how; // 이동
                }
            }
        }
        else if(s[0] == 'S'){
            flag=0;
            if(starty + how < y){ //공원을 벗어나는가?
                
                for(int t=starty; t<=starty+how; t++){
                    if(park[t][startx] == 'X'){ // 장애물이 있다면
                        flag=1;
                    }
                }
                
                if(flag == 0){
                    printf("더하기 %d\n", starty+how);
                    starty = starty+how;
                } // y축 이동
                
            }
            
        }
        else if(s[0] == 'W'){
            if(startx - how >= 0){ //공원을 벗어나는가?
                no = field.find('X', startx - how);
                
                if(no <= startx && no >=0){ // 가려는 곳에 'x'가 있으면
                    
                }
                else{ // 없으면
                    startx = startx - how; // 이동
                }
            }
        }
        else if(s[0] == 'N'){
            flag=0;
            if(starty - how >= 0){ //공원을 벗어나는가?
                
                for(int t=starty-how; t<=starty; t++){
                    if(park[t][startx] == 'X'){ // 장애물이 있다면
                        flag=1;
                    }
                }
                
                if(flag == 0){
                    starty = starty-how;
                } // y축 이동        
            } 
        }
    }
     
    answer.push_back(starty);
    answer.push_back(startx);
    
    return answer;
}