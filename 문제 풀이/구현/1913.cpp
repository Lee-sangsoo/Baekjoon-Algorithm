/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.10
���� : 1913 - ������
Ǯ�� : ������ �迭 ����... ���� ����� �ߴ� ������ ���������� Ǯ��Ҵ�.
       Ȧ���� n�� ���� �� �迭�� ���� �־��� ���ǿ� ���� �����ϴ� ����̴�.

	   n�� ���� �� ����
	   1 1 2 2 3 3 4 4 ... n
	   Ex) 
	   n = 5
	   1 1 2 2 3 3 4 4 5
	   
	   n = 3
	   1 1 2 2 3

	   �� ���� ó���ȴ�.
	   �� ���� ���Ǵ� x�� y��ǥ���� �����̸�
	   ������ x�� y�� ���ư��� ����ȴ�.
	   ��
	   n = 5
	   x y x y x y x y x

	   n = 3
	   x y x y x

	   �׸��� ������
	   -1 +1   +2 -2   -3 +3 ...
	   �� (-, +) -> (+, -) -> (- +) -> ...

	   �̸� ���󰡸� ���� ä��� ��� �� ã���� �ϴ� ���� ��ǥ�� ������ָ� �ȴ�.
*/
#include <iostream>

using namespace std;

int arr[1000][1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x = n / 2, y = n / 2;
	int cnt = 1;
	int xcnt = 1, ycnt = 1;
	int xa = -1, ya = 1;
	while (1) {
		for (int i = 0; i < xcnt; i++) {
			arr[x][y] = cnt;
			x += xa;
			cnt++;
		}
		if (cnt == n * n + 1) break;
		for (int i = 0; i < ycnt; i++) {
			arr[x][y] = cnt;
			y += ya;
			cnt++;
		}
		xcnt++; ycnt++;
		xa *= -1;
		ya *= -1;
	}

	int mx, my = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
			if (arr[i][j] == m) {
				mx = i;
				my = j;
			}
		}
		cout << '\n';
	}
	cout << mx + 1 << ' ' << my + 1;
}