#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M, K, result=0;
	cin >> N >> M >> K;							
	int* ar = new int[N];						// 입력받은 문자열을 int형을 바꿔서 저장할 int형 배열
	string s;									// N개의 숫자를 입력받을 문자열
	cin.ignore();
	getline(cin, s);
	
	for (int i = 0; i < s.length(); i++) {       //입력받은 문자열 형태의 숫자들 사이의 공백 제거
		if (s[i] == ' ') {
			s.erase(i, 1);
		}
	}
	
	for (int i = 0; i < s.length(); i++) {		//입력받은 문자열 형태의 숫자를 int형으로 변환
		char ref = s[i];
		ar[i] = ref - '0';
	}

	int j = 0;                                       
	int first, second; 
	for (int i = 0; i < N; i++) {                  //가장 큰 수 찾기
		if (ar[i] > j)
			j = ar[i];
	}
	first = j;
	j = 0;

	int f_n=0;
	for (int i = 0; i < N; i ++ ) {				//입력받은 숫자에서 가장 큰 수가 몇개 인지 f_n변수에 저장
		if (ar[i] == first)
			f_n++;
	}

	if (f_n >= 2) {                             //가장 큰 수가 배열에 2개이상 있으면 결과는 가장 큰수를 M개 더한 것
		result = first * M;
		cout<< result;
		return 0;
	}

	for (int i = 0; i < N; i++) {                  //2번째로 큰 수 찾기
		if (ar[i] > j && ar[i] <first)
			j = ar[i];
	}
	second = j;

	int fsn = 0; int ssn = 0;
	for (int i = 0; i < M; i++) {				// 가장 큰 수 1개 2번째로 큰 수 1개 이상 있으면 큰 수 K개, 작은 수 1개 큰 수k개 이런 식으로 반복되므로
		if (fsn != K) {							// M개에 도달할 때가지 위와 같은 방식으로 더하면 결과를 얻을 수 있다.
			result += first; fsn++;
		}
		else {
			result += second; fsn = 0;
		}
	}
	cout<< "최종결과 : "<<result;
	return 0;

}
