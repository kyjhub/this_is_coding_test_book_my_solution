#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int main() {
	int n, m, k;
	int first = 0, second = 0;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> v;
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.emplace_back(x);
	}

	int j = 0;
	for (int i = 0; i < n; i++) {                  //가장 큰 수 찾기
		if (v[i] > j)
			j = v[i];
	}
	first = j; j = 0;

	int f_n = 0;
	for (int i = 0; i < n; i++) {				//입력받은 숫자에서 가장 큰 수가 몇개 인지 f_n변수에 저장
		if (v[i] == first)
			f_n++;
	}

	if (f_n >= 2) {                             //가장 큰 수가 배열에 2개이상 있으면 결과는 가장 큰수를 M개 더한 것
		cout<< first * m;
		return 0;
	}

	for (int i = 0; i < n; i++) {                  //2번째로 큰 수 찾기
		if (v[i] > j && v[i] < first)
			j = v[i];
	}
	second = j;

	int result = 0, fsn = 0;
	for (int i = 0; i < m; i++) {				// 가장 큰 수 1개 2번째로 큰 수 1개 이상 있으면 큰 수 K개, 작은 수 1개 큰 수k개 이런 식으로 반복되므로
		if (fsn != k) {							// M개에 도달할 때가지 위와 같은 방식으로 더하면 결과를 얻을 수 있다.
			result += first; fsn++;
		}
		else {
			result += second; fsn = 0;
		}
	}
	cout << result;
	return 0;


}