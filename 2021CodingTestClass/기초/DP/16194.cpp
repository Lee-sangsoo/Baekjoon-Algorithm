/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.24
���� : ī�� �����ϱ� 2 - 16194
Ǯ�� : D[N] = N���� ī�带 �����ϰ��� �� ��, �����ؾ� �ϴ� ���� ���� �ݾ�

	   D�� P�� ������ ������ �ϸ�
	   D[N]�� �̹� N���� �����ϱ� ���� �ּҷ� �����ؾ� �ϴ� �ݾ��̱� ������
	   ���� ������ ī���� ������ 1 ~ N�� ���� �����ϹǷ�
	   ��� N�� ���ؼ�
	   D[N-1] + P[1]
	   D[N-2] + P[2]
	   ...
	   D[0] + P[N]
	   ���� ���Ͽ� ���� ���� ���� �������� �־��ָ� �ȴ�.

	   ��
	   D[N] = MIN(D[N], D[N-K] + P[K]) �� �ȴ�.
*/
#include<iostream>

using namespace std;

int n;
int d[1001];
int p[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	d[1] = p[1];

	for (int i = 2; i <= n; i++) {
		d[i] = p[i];
		for (int j = i - 1; j > 0; j--) {
			d[i] = d[i] > d[i - j] + p[j] ? d[i - j] + p[j] : d[i];
		}
	}
	cout << d[n];
}