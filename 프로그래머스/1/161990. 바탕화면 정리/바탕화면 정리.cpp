#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    // 제일 좌측 파일의 위치와 제일 우측 파일의 위치가 필요
    string s = wallpaper[0];
    int x = s.size();
    int y = wallpaper.size();
    
    int lux=x, luy=y;
    int rdx = -1, rdy=0;
    
    string nows;
    
    for(int i=0; i<y; i++){
        nows = wallpaper[i]; // 현재 스트링 조사
        
        for(int t=0; t<x; t++){
            if(nows[t] == '#' && t < lux){ //가장 좌측에 있는 값
                lux = t; // 새로운 좌측값 입력
            }
            if(nows[t] == '#' && t > rdx){ //가장 우측에 있는 값
                rdx = t;
            }
            if(nows[t] == '#' && i < luy ){ //가장 상단에 있는 값
                luy = i;
            }
            if(nows[t] == '#' && i > rdy){ //가장 하단에 있는 값
                rdy = i;
            }
        }
    
    }
    //printf("%d %d %d %d", luy, lux, rdy, rdx);
    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy+1);
    answer.push_back(rdx+1);
    
    
    return answer;
}