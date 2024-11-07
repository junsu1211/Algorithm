#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    string video_len_1 = video_len.substr(0,2);
    string video_len_2 = video_len.substr(3,2);
    int video = stoi(video_len_1)*100 + stoi(video_len_2);
    // 비디오 크기 int로 변환
    
    string mm = pos.substr(0,2); // 분
    string ss = pos.substr(3,2); // 초
    int now_mm = stoi(mm);
    int now_ss = stoi(ss);
    
    // 시작 위치 int로 변환
    
    string op_start_1 = op_start.substr(0,2);
    string op_start_2 = op_start.substr(3,2);
    int opstart = ( stoi(op_start_1) )*100 + stoi(op_start_2);
    
    string op_end_1 = op_end.substr(0,2);
    string op_end_2 = op_end.substr(3,2);
    int opend = ( stoi(op_end_1) )*100 + stoi(op_end_2);
    
    if(now_mm*100 + now_ss >= opstart && now_mm*100 + now_ss <= opend){ //들어가기에 앞서 검사
                //op_end로 이동
                now_mm = opend/100;
                now_ss = opend - now_mm*100;
    }
    
    
    for(int i=0; i<commands.size(); i++){
        
        if(commands[i] == "next"){ // 현 명령이 next인 경우
            
            // 만약 60초를넘어서는 경우 분 단위를 움직여야 함
            if(now_ss + 10 >= 60){
                now_mm++; // 분 하나 추가 하고
                now_ss = now_ss - 50;
            }
            else{
                now_ss = now_ss + 10;
            }
            
            if(now_mm*100 + now_ss >= opstart && now_mm*100 + now_ss <= opend){ 
                //op_end로 이동
                now_mm = opend/100;
                now_ss = opend - now_mm*100;
            }
            
            if(now_mm*100 + now_ss >= video){ // 비디오의 맨 끝을 넘어선 경우
                now_mm = video/100; // 비디오의 최대 길이 까지만
                now_ss = video - now_mm*100;
            }
        }
        else if(commands[i] == "prev"){ // 현 명령이 prev인 경우
            if(now_ss -10 < 0 ){ // 0보다 작아지는 경우
                
                if(now_mm == 0){
                    now_ss = 0;
                    now_mm = 0;
                }
                else{
                    now_mm--; // 분 하나 감소
                    now_ss = now_ss + 50;
                }
            }
            else {
                now_ss = now_ss -10;
            }
            
            if(now_mm*100 + now_ss <= opend && now_mm*100 + now_ss >=opstart) {
                now_mm = opend/100;
                now_ss = opend - now_mm*100;
            }
            
            if(now_mm*100 + now_ss <= 0 ){
                now_mm = 0;
                now_ss = 0;
            }
            
        }
        
    }
    
    string resultmm = to_string(now_mm);
    if(resultmm.size() == 1){
        resultmm = '0' + resultmm; // 재정의
    }
    else if(resultmm == "0"){
        resultmm = "00";
    }
    
    string resultss = to_string(now_ss);
    if(resultss.size() == 1){
        resultss = '0' + resultss; // 재정의
    }
    else if(resultss == "0"){
        resultss = "00";
    }
    
    answer = resultmm + ':' + resultss;
    
    return answer;
}