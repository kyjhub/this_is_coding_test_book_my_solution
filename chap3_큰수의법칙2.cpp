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
	for (int i = 0; i < n; i++) {                  //���� ū �� ã��
		if (v[i] > j)
			j = v[i];
	}
	first = j; j = 0;

	int f_n = 0;
	for (int i = 0; i < n; i++) {				//�Է¹��� ���ڿ��� ���� ū ���� � ���� f_n������ ����
		if (v[i] == first)
			f_n++;
	}

	if (f_n >= 2) {                             //���� ū ���� �迭�� 2���̻� ������ ����� ���� ū���� M�� ���� ��
		cout<< first * m;
		return 0;
	}

	for (int i = 0; i < n; i++) {                  //2��°�� ū �� ã��
		if (v[i] > j && v[i] < first)
			j = v[i];
	}
	second = j;

	int result = 0, fsn = 0;
	for (int i = 0; i < m; i++) {				// ���� ū �� 1�� 2��°�� ū �� 1�� �̻� ������ ū �� K��, ���� �� 1�� ū ��k�� �̷� ������ �ݺ��ǹǷ�
		if (fsn != k) {							// M���� ������ ������ ���� ���� ������� ���ϸ� ����� ���� �� �ִ�.
			result += first; fsn++;
		}
		else {
			result += second; fsn = 0;
		}
	}
	cout << result;
	return 0;


}