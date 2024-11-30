#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    int range = name.size(); // 그리워하는 인원 수
    
    unordered_map<string, int> m;
    
    for(int i=0; i<range; i++){
        m.insert({name[i], yearning[i]});
    }
    
    int sum = 0;
    
    int y = photo.size();
    
    for(int i=0; i<y; i++){
        sum=0;
        for(int t=0; t<photo[i].size(); t++){
            auto pt = m.find(photo[i][t]); // 이 이름에 대해 찾아
            if(pt != m.end()){ // 찾으면
                sum = sum + pt->second;
            }
            
        }
        answer.push_back(sum);
    }
    
    
    return answer;
}