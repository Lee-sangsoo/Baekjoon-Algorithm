/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 2210 - ������ ����
Ǯ�� : 5 X 5 ũ���� �ǿ��� �� ���� ���������� �Ͽ� ��� ������ �������� �ΰ� ������ ��� ���� ���Ѵ�.
       SET �ڷᱸ���� ����Ͽ� ������ key�� �����Ͽ� ���������� set �ڷᱸ���� ũ�⸦ ����ϵ��� �Ѵ�.

	   ������ ����� ��츦 �������� (>=�� >�� �Ἥ ������ Ʋ�ȴ�...)
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int A[5][5];
int sel[6];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
set<int> V;

int calc() {
	int ret = 0;
	int mul = 100000;
	for (int i = 0; i < 6; i++) {
		ret += sel[i] * mul;
		mul /= 10;
	}
	return ret;
}

void go(int cnt, int x, int y) {
	if (cnt == 6) {
		int num = calc();
		V.insert(num);
		return;
	}
	sel[cnt] = A[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		go(cnt + 1, nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> A[i][j];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(0, i, j);
		}
	}
	
	cout << V.size() << '\n';
}