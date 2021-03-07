/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.07
���� : �迭 �����ϱ� - 16967
Ǯ�� : ��������
       �ڱ� �ڽ��� ��ġ�� �̵��Ͽ� ���ٿ� ���� �ø��� ����̱� ������
	   �̵��� ��ŭ�� ������ ���ؼ��� �Ű��� ���ָ� �ȴ�.

	   ���� �ٲ���ٴ� ���� �ڱ� �ڽŰ��� ���� �������ٴ� ���̸�

	   �̸� �ݴ�� �����ϸ� �̵��� ��ŭ�� ������ �ȴٸ�
	   ������ ���� ���ָ� ������ ������ ���ƿ��� �ȴ�.
*/
#include<iostream>

using namespace std;

int h, w, x, y;

int a[301][301];
int b[600][600];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w >> x >> y;

	for (int i = 0; i < h + x; i++)
		for (int j = 0; j < w + y; j++)
			cin >> b[i][j];

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			a[i][j] = b[i][j];

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i - x < 0 || j - y < 0) continue;
			a[i][j] -= a[i - x][j - y];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}