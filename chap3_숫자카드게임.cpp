#include <iostream>
#pragma warning(disable : 4996)
#include <vector>

using namespace std;

int min(vector<int> a) {                       // 인자로 전달된 배열의 최솟값을 찾아 반환하는 함수
	int j = a[0];
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < j)
			j = a[i];
	}

	return j;
}

int max(vector<int> a) {						//인자로 전달된 배열의 최댓값을 찾아 반환하는 함수
	int j =0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > j)
			j = a[i];
	}

	return j;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> row;							// 입력 행
	vector<int> min_r;							//각 행에서의 최솟 값을 저장할 배열
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			scanf("%d", &n);
			row.emplace_back(n);
		}
		min_r.emplace_back(min(row));
		row.clear();
	}

	int result = max(min_r);
	printf("%d", result);
}