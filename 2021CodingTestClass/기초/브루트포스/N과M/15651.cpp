/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : N�� M (3) - 15651
Ǯ�� : �ߺ��� ����ϴ� �����̹Ƿ�
       ������ �ߺ��� �����ϱ� ���� ���� chk �迭�� ������� �ʰ� 
	   chk�迭�� ���õ� �ڵ� �κ��� ��� �����ָ�ȴ�.
*/
#include <iostream>

using namespace std;

int n, m;
int arr[8];

void go(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		go(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	go(0);
}