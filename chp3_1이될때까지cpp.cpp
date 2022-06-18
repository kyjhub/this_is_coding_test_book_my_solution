#include <iostream>
#pragma warning(disable : 4996)
#include <vector>

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	int n = 0;
	
	while (N > 1) {
		if (N % K == 0) {
			N = N / K;
			n += 1;
		}
		else {
			N -= 1;
			n += 1;
		}
	}

	printf("%d", n);
	exit(1);
}