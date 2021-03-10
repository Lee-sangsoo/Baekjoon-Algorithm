/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.15
���� : �Ҽ� ã�� - 1978
Ǯ�� : �Ϲ����� �Ҽ� ã�� ����
       �־����� �׽�Ʈ ���̽��� 100�� �����̰� �� ���� 1000 �����̱� ������
	   �Ϲ����� �Ҽ� ����� ���� �����ص� ����� ��� �����ϴ�.

	   ���ǻ���
	   1. �˻�� �־����� �� N�� ������ ������ ���ָ�ȴ�.
	   2. �������� �� ���� �Լ� sqrt�� �ٻ簪���� �������� ������ i * i�� �ϴ°� ��Ȯ�ϴ�.
*/
#include<iostream>

using namespace std;

bool prime(int a) {
	if (a < 2) return false;
	 
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0) return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
		int a;
		cin >> a;
		if (prime(a)) cnt++;
	}
	cout << cnt;
}