#include <iostream>
#pragma warning(disable : 4996)
#include <vector>

using namespace std;

int min(vector<int> a) {                       // ���ڷ� ���޵� �迭�� �ּڰ��� ã�� ��ȯ�ϴ� �Լ�
	int j = a[0];
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < j)
			j = a[i];
	}

	return j;
}

int max(vector<int> a) {						//���ڷ� ���޵� �迭�� �ִ��� ã�� ��ȯ�ϴ� �Լ�
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
	vector<int> row;							// �Է� ��
	vector<int> min_r;							//�� �࿡���� �ּ� ���� ������ �迭
	
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