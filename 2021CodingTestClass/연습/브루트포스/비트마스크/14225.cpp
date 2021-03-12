/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.12
���� : �κм����� �� - 14225
Ǯ�� : �������� ������ ����Լ��� ���� Ǯ���µ�
       �̹����� ��Ʈ����ũ�� ����Ͽ� Ǯ�̸� �Ͽ���.

	   �� ����� �Ȱ���.
	   ������, ��Ʈ����ũ���ٴ� ��͹���� �� ������.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool chk[2000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += s[j];
			}
		}
		chk[sum] = true;
	}

	for (int i = 1; ; i++) {
		if (chk[i] == false) {
			cout << i;
			break;
		}
	}
}