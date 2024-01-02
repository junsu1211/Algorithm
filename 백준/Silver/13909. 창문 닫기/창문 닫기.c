#include <stdio.h>

int main() {
	int N=0;
	int count = 0;
	scanf("%d", &N);
	if (N > 2100000000 || N < 1) {
		perror(" 범위 초과 \n");
		return 1;
	}

	int w = 0;
	

	for (int i = 1; i <= N; i++) {
		w = i * i;
		if (w <= N)
			count++;
		else if (w > N)
			break;
	}
	
	printf("%d", count);
}