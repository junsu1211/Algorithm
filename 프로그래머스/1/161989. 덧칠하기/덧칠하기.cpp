#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    // n: (1미터인)구역의 개수, m: 롤러의 크기
    int count=0;
    int* dp = new int[n+1];
    // 배열
    int idx=0;
    int i=1;
    int end=0;
    
    for(i=1; i<=n;i++){ //페인트칠을 시작하는 것이 가능한 위치의 범위
        if(section[idx] == i && section[idx] > end){
            end = i+m-1; // 마지막까지 칠해진 곳의 위치 
            printf("%d\n", i);
            answer++;
            idx++;
        }
        else if(section[idx] == i && section[idx] <= end){
            idx++;
        }
    }
    
    
    
    
    
    
    return answer;
}