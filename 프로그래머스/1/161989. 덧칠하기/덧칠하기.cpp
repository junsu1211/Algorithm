#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int* wall = new int[n+1];
    for(int i=1; i<=n; i++)
        wall[i] = 1;
    
    
    // O(n) 은 안됨
    for(int i=0; i<section.size(); i++){
        wall[ section[i] ] = 0; // 페인트가 벗겨짐
    }
    
    int count=0;
    for(int i=1; i<=n; i++){
        
        if(wall[ i ] == 0){ // 페인트가 벗겨진 곳이면
            i = i + m - 1;
            count++;
        }
        
    }
    answer = count;
    
    return answer;
}