#include <iostream>

using namespace std;
int main() {

   int k, n;
   cin >> n >> k; // 변수 초기화

   int p = n;
   int *queue = (int*)malloc(n * sizeof(int));
   for (int i = 0; i < n; i++) {
      queue[i] = i + 1;
   } // 큐 생성

   cout << "<";
   int pointer = k-1; // 큐의 포인터

   for (int i = 0; i < p; i++) {
      cout << queue[pointer]; // 포인터 위치 출력
      if (i == p - 1)
         break;
      cout << ", ";
      for (int t = pointer%n; t < n - 1; t++) {
         queue[t] = queue[t + 1];
      }
      n--;
      pointer = (pointer + k - 1) % n;
   }
   cout << ">" << endl;
   return 0;
}