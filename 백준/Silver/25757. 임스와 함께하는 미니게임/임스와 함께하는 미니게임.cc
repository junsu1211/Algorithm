#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    string Game;
    vector<string> vec;

    cin >> N >> Game;
    string people;
    int k = N;

    for (int i = 1; i <= N; i++) {
        cin >> people;
        vec.push_back(people);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    if(Game == "Y") {
        cout << vec.size();
    }
    else if (Game == "F") { // 2명씩 참가됨
        cout << vec.size() / 2;
    }
    else if (Game == "O") { // 3명씩 참가됨
        cout << vec.size() / 3;
    }
}