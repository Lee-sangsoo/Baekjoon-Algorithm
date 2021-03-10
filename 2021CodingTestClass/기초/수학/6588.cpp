/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.15
���� : �������� ���� - 6588
Ǯ�� : 2���� ū ��� ¦���� �� Ȧ�� �Ҽ��� ������ ǥ�� �����ϴ�.
       ��� �������� ���� �����̴�.

	   C++�� �Է°� ����� ������ ios_base�� cin.tie�� ���� �ð��ʰ��� ���´�. (��������)

	   �����佺�׳׽��� ü�� �̸� �Ҽ��� ���صΰ�

	   �Ʒ����� Ȧ���̱� ������ 3���� �����Ͽ� ���ϸ�ȴ�.
	   (2�� ������ ¦�� �Ҽ��̴�.)

	   10^18 ������ �������� �� ������ ������ �Ǿ��� ������
	   ���������� ������ 10^18���� �۱� ������
	   Ʋ���� ���� ���ǽ��� ���� �ʾƵ� �ȴ�.
*/
#include<iostream>

using namespace std;

const int MAX = 1000000;
bool chk[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	chk[0] = chk[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (chk[i]) continue;
		for (int j = i * i; j <= MAX; j += i) {
			chk[j] = true;
		}
	}

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 3; i<=n; i+=2) {
			if (!chk[i] && !chk[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
				
		}
	}
}