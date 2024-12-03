#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    // 투 포인터
    int left=0;
    int right=0;
    int summation = sequence[0];
    int asnl=0;
    int asnr=0;
    int len = sequence.size()+1;
    
    while(1){
        if(right == sequence.size() || left == sequence.size())
            break;
        
        //printf("현재 %d, %d 합 : %d\n", left, right, summation);
        if(summation < k){
            right++;
            summation = summation + sequence[right];
        }
        else if(summation > k){
            summation = summation - sequence[left];
            left++;
            
        }
        else if(summation == k && right - left + 1 < len){
            asnl = left;
            asnr = right;
            len = right - left + 1;

            summation = summation - sequence[left];
            left++;
            
        }
        else if(summation == k && right - left + 1 >= len){
            summation = summation - sequence[left];
            left++;
        }
    }
    
    answer.push_back(asnl);
    answer.push_back(asnr);
    
    return answer;
}