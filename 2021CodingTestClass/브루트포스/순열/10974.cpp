/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.22
���� : ��� ���� - 10974
Ǯ�� : ������ ���ϴ� �⺻���� ����
	   prev_permutation �Լ��� do{}while()���� ����Ͽ� �����ϸ� �ȴ�.

	   �⺻������ n�� 10�϶� ������ ������ �̿��Ͽ� ��� ��츦 Ȯ���� �� �ִ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int a[9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i - 1] = i;

	do {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	} while (next_permutation(a, a + n));
}