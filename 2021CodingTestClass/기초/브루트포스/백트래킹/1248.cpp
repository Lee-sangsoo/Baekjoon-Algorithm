/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.21
���� : �����
Ǯ�� : �� 21���� ���ڸ� �ִ� 10���� �ڸ��� �ߺ����� ���� ���� �� �ִ� �����̴�.
       ��, �� ����� ���� 21^10 ���� �� 16���̴�. (���Ʈ ���� �Ұ�)

	   �̸� ���� Ǫ�� ����� ������ ����.

	   sign[i][j] = num[i]���� num[j]������ ���̱� ������
	   sign[i][i] = num[i]�� ��ȣ�� ���� (�ڱ� �ڽű����� ���̱� ������)

	   �̸� �����Ͽ� 
	   chk�Լ��� ���� k��° ���ڱ��� ���� �־��ٸ�
	   [k][k] + [k][k-1] + [k][k-2] + ... �� ���� �����ϸ鼭
	   �־��� �����հ� ��ȣ�� ���� �ٸ��ٸ� false�� �Ѱ� �ش� ������ ���̻� 
	   ��͸� �������� �ʵ��� �Ѵ�.

	   �̿� ���� �� ���ǿ� �´� ��쿡�� ��͸� �����ϰ� (��Ʈ��ŷ)
	   ù��°�� ������ �Ǵ� ���� ���´ٸ� �ٷ� exit(0); �� ȣ���Ͽ� �����Ѵ�.

	   �ٽ� ���̵��
	   1. num[k]�� ��ȣ�� sign[k][k]�� ��ȣ�� ����.
	   2. �������� ���鼭 �־��� ��ȣ�� ��ġ���� ���� ��쿡�� ��͸� ������ �ʿ䰡 ����.
*/
#include<iostream>

using namespace std;

char sign[11][11];
int num[11];
int n;

bool chk(int k) {
	int sum = 0;
	for (int i = k; i >= 0; i--) {
		sum += num[i];
		if (sign[i][k] == '0' && sum != 0) return false;
		if (sign[i][k] == '+' && sum <= 0) return false;
		if (sign[i][k] == '-' && sum >= 0) return false;
	}
	return true;
}

void go(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++)
			cout << num[i] << ' ';
		exit(0);
	}

	for (int i = -10; i < 11; i++) {
		num[k] = i;
		if (chk(k)) go(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++) 
			cin >> sign[i][j];

	go(0);
}