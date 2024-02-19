#include <iostream>

using namespace std;
int main() {
	int numswitch = 0;
	cin >> numswitch; // 스위치의 개수
	if (numswitch > 100 || numswitch < 1) {
		perror("스위치의 개수가 너무 많음\n");
		exit(1);
	}

	int* swtarray = (int*)malloc((numswitch+1) * sizeof(int));
	for (int i = 1; i <= numswitch; i++) {
		cin >> swtarray[i]; // 동적배열에 스위치 상태 초기화
	}

	int studentnum;
	cin >> studentnum;// 학생 수

	int gender; // 성별
	int numstate; // 받은 스위치 번호
	int t = 1;
	for (int i = 1; i <= studentnum; i++) {
		cin >> gender >> numstate;

		if (gender == 1) { // 남자
			for (int k = numstate; k <= numswitch; k = numstate * t) {
				if (swtarray[k] == 0) // 스위치 반전
					swtarray[k] = 1;
				else if(swtarray[k] == 1)
					swtarray[k] = 0;
				t++;
			}
		}

		else if (gender == 2) { // 여자
			if (numstate == 1 || numstate == numswitch) {
				if (swtarray[numstate] == 0) // 본인 스위치 반전
					swtarray[numstate] = 1;
				else if (swtarray[numstate] == 1)
					swtarray[numstate] = 0;
				continue;
			}
			else {
				if (swtarray[numstate] == 0) // 본인 스위치 반전
					swtarray[numstate] = 1;
				else if (swtarray[numstate] == 1)
					swtarray[numstate] = 0;
				for (int k = 1; k <= numswitch; k++) {
					if ( numstate+k > numswitch || numstate - k < 1 ) {
						break;
					}

					if (swtarray[numstate + k] == swtarray[numstate - k]) {
						if (swtarray[numstate+k] == 0) // 스위치 반전
							swtarray[numstate+k] = 1;
						else if (swtarray[numstate+k] == 1)
							swtarray[numstate+k] = 0;

						if (swtarray[numstate - k] == 0) // 스위치 반전
							swtarray[numstate - k] = 1;
						else if (swtarray[numstate - k] == 1)
							swtarray[numstate - k] = 0;
					}
					else {
						break;
					}
				}
			}
		}
		t = 1;
	}

	
	for (int i = 1; i <= numswitch; i++) {
		cout << swtarray[i] << " ";
		if (i % 20 == 0) {
			cout << endl;
		}
	}
}