/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.22
���� : ���� ���� - 10973
Ǯ�� : ������ ���ϴ� �⺻���� ����
	   prev_permutation �Լ��� ����Ͽ� �����Ͽ�����
	   ���� �Լ��� ������ �ڵ�� Permutation.cpp�� �ִ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int a[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (prev_permutation(a, a + n)) {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
	}
	else {
		cout << -1;
	}
}