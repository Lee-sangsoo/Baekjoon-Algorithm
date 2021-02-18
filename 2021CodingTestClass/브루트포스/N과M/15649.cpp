/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : N�� M (1) - 15649
Ǯ�� : ����Լ��� ����� ������ ã�� ���Ʈ���� ����
       ����Լ��� ����Ͽ� ����(����)�� ���� �����ϸ�
	   ���������� �����Ǹ� ��� ���ְ� �����ϵ��� �ϸ� �ȴ�.

	   ���� ������ ���� ��� ������ ��Ÿ���� �Ǵ� �����̱� ������
	   �Ϲ������� �����ϸ� �ȴ�.
*/
#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool chk[9];

void bf(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		arr[k] = i;
		chk[i] = true;
		bf(k + 1);
		chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	bf(0);
}