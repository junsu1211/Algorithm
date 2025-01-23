#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int arr[4][3];
    // left = arr[3][0];
    // right = arr[3][2];
    int idx=1;
    for(int i=0; i<3; i++){
        for(int t=0; t<3; t++){
            arr[i][t] = idx;
            idx++;
        }
    }
    arr[3][0] = -1; // * = -1
    arr[3][2] = -2; // # = -2
    arr[3][1] = 0;
    
    int leftl = 3, leftr = 0; //시작점
    int rightl = 3, rightr = 2; // 시작점
    int mid = 0;
    
    for(int t=0; t<numbers.size(); t++){
        // 각 num에 대해 결정해야함
        if(numbers[t] == 1 || numbers[t] == 4 || numbers[t] == 7){
            // 1,4,7 인 경우
            for(int i=0; i<3; i++){
                if(arr[i][0] == numbers[t]){ // 찾기
                    //printf("%da\n", arr[i][0]);
                    leftl = i;
                    leftr = 0;
                    answer = answer + "L";
                }
            }
        }
        else if(numbers[t] == 3 || numbers[t] == 6 || numbers[t] == 9){
            // 3,6,9인 경우
            for(int i=0; i<3; i++){
                if(arr[i][2] == numbers[t]){ // 찾기
                    //printf("%db\n", arr[i][2]);
                    rightl = i;
                    rightr = 2;
                    answer = answer + "R";
                }
            }
        }
        else{ // 2,5,8,0
            for(int i=0; i<=3; i++){
                if(numbers[t] == arr[i][1]){
                    //printf("%dc\n", arr[i][1]);
                    mid = i; // 중앙 값 찾기
                }
            }
            // 두 점사이의 거리로 생각하자
            if(abs(leftl-mid)+abs(leftr-1) < abs(rightl-mid) + abs(rightr-1)){
                //왼쪽이 더 가까움
                answer = answer + "L";
                leftl = mid;
                leftr = 1;
            }
            else if(abs(leftl-mid)+abs(leftr-1) > abs(rightl-mid) + abs(rightr-1) ){
                answer = answer + "R";
                rightl = mid;
                rightr = 1;
            }
            else if ( abs(leftl-mid)+abs(leftr-1) == abs(rightl-mid) + abs(rightr-1)){
                if(hand == "right"){
                    answer = answer + "R";
                    rightl = mid;
                    rightr = 1;
                }
                else if(hand == "left"){
                    answer = answer + "L";
                    leftl = mid;
                    leftr = 1;
                }
            }
                
        }
        
    }
    
    return answer;
}