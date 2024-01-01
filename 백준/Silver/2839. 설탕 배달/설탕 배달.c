#include <stdio.h>

int main() {
	int kg3 = 0; // 3kg의 봉지의 개수
	int deliv = 0;
	int weight = 0;
	int min = -1; // 봉지 최소 개수
	int upd = 0;

	scanf("%d", &deliv); // Nkg 입력
	if (deliv > 5000 || deliv < 3) {
		perror("범위 초과");
		return 0;
	}
	
	if (deliv % 5 == 0) { // 만약 5의 배수라면 5kg봉지만으로 이루어짐
		printf("%d", deliv / 5);
		return 0;
	}
	else {
		for (int i = 0; i < deliv; i++) { // 5와 3을 섞어 쓰는 경우

			if (i * 5 > deliv) { // 범위 초과시
				if (min == -1) {
					printf("-1");
				}
				else {
					printf("%d", min);
				}
				return 0;
			}

			weight = deliv - (i * 5);
			if (weight % 3 == 0) { // 5의 단위를 제외하고 3의 배수이면 

				kg3 = weight / 3; // 3kg봉지의 개수
				upd = i + kg3; // 총 개수
				if (min == -1) { // 처음일 때
					min = upd;
				}

				if (upd < min) { // 만약 기존의 min보다 작다면
					min = upd; // 업데이트
				}
			}
		}
	}	
	return 0;
}