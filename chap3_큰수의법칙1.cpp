#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M, K, result=0;
	cin >> N >> M >> K;							
	int* ar = new int[N];						// �Է¹��� ���ڿ��� int���� �ٲ㼭 ������ int�� �迭
	string s;									// N���� ���ڸ� �Է¹��� ���ڿ�
	cin.ignore();
	getline(cin, s);
	
	for (int i = 0; i < s.length(); i++) {       //�Է¹��� ���ڿ� ������ ���ڵ� ������ ���� ����
		if (s[i] == ' ') {
			s.erase(i, 1);
		}
	}
	
	for (int i = 0; i < s.length(); i++) {		//�Է¹��� ���ڿ� ������ ���ڸ� int������ ��ȯ
		char ref = s[i];
		ar[i] = ref - '0';
	}

	int j = 0;                                       
	int first, second; 
	for (int i = 0; i < N; i++) {                  //���� ū �� ã��
		if (ar[i] > j)
			j = ar[i];
	}
	first = j;
	j = 0;

	int f_n=0;
	for (int i = 0; i < N; i ++ ) {				//�Է¹��� ���ڿ��� ���� ū ���� � ���� f_n������ ����
		if (ar[i] == first)
			f_n++;
	}

	if (f_n >= 2) {                             //���� ū ���� �迭�� 2���̻� ������ ����� ���� ū���� M�� ���� ��
		result = first * M;
		cout<< result;
		return 0;
	}

	for (int i = 0; i < N; i++) {                  //2��°�� ū �� ã��
		if (ar[i] > j && ar[i] <first)
			j = ar[i];
	}
	second = j;

	int fsn = 0; int ssn = 0;
	for (int i = 0; i < M; i++) {				// ���� ū �� 1�� 2��°�� ū �� 1�� �̻� ������ ū �� K��, ���� �� 1�� ū ��k�� �̷� ������ �ݺ��ǹǷ�
		if (fsn != K) {							// M���� ������ ������ ���� ���� ������� ���ϸ� ����� ���� �� �ִ�.
			result += first; fsn++;
		}
		else {
			result += second; fsn = 0;
		}
	}
	cout<< "������� : "<<result;
	return 0;

}
