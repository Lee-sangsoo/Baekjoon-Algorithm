/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : N�� M (4) - 15652
Ǯ�� : �񳻸����� (�ߺ��� ����ϴ� ��������)
       �� ����� �����̴�.
	   N�� M ���� 2�� 3�� ��ġ�� �ذ� ������ �����̴�.

	   �ߺ��� ����ϱ� ������ �������� �ڱ� �ڽ����� �ϸ� �ȴ�.
*/
#include<iostream>

using namespace std;

int n, m;
int arr[9];

void bf(int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; i++) {
		arr[k] = i;
		bf(k + 1, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	bf(0, 1);
}