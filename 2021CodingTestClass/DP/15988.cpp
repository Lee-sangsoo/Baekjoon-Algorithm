/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.25
���� : 1, 2, 3 ���ϱ� 3 - 15988
Ǯ�� : 1, 2, 3 ���ϱ� ������ ��� ������ ������, �־����� N�� ũ�Ⱑ
       �ִ� �鸸�̱� ������ ���Ʈ������ Ǯ�̰� �Ұ����ϴ�.

	   �Ϲ����� ���� ����ؼ� Ǯ�� �ȴ�.
	   ������, ������ ��û���� Ŀ���� ������
	   d�迭�� long long ������ ���־�� �Ѵ�.

	   ����
	   1. �ڷ���
	   2. ������ ����
*/
#include<iostream>

using namespace std;

int n, t;
long long d[1000001];
const int mod = 1000000009;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	
	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		d[i] = (d[i - 3] + d[i - 2] + d[i - 1]) % mod;

	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}
}