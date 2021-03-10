/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.19
���� : 1, 2, 3 ���ϱ�
Ǯ�� : �� ������ �ִ� ����� ���� 3^10���� ���Ʈ ������ ����Ͽ� Ǯ� �ǰ�
       DP�� ����Ͽ� Ǯ� �Ǵ� �����̴�.

	   ���Ʈ ������ Ǯ�� �ϴ� ��� ����Լ��� ���� �����ϰ�
	   DP�� ��� �ڽ� ������ 3�� ���� ���Ͽ� ó���� �����ϴ�.
*/
#include<iostream>

using namespace std;

int go(int sum, int n) {
	if (sum == n) return 1;
	else if (sum > n) return 0;

	int now = 0;
	for (int i = 1; i <= 3; i++) {
		now += go(sum + i, n);
	}
	return now;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}
}