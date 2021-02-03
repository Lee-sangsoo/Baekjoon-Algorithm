/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.03
���� : �÷��̵� - 11404
Ǯ�� : �÷��̵� �ͼ� ������ ������ �� �� �ƴ��ĸ� ���� ����
       �׷����� �׷��� �����ϸ� �ȴ�.
	   ��, �������� �־����� ������ �ϳ��� �ƴ� �� �ֱ� ������
	   ���� �־��� �� �ش� ������ �ʱⰪ�� �ƴ϶�� �� ���� �� ����� ���� ���� ��������

	   �� �ڷ� ������ ���ٸ� ���� �ſ� ũ�� ��Ƽ� ���� ���ǹ� ó���� ���� �ʰ� ó�� �ǵ��� �� �� �ִ�.
	   ��� �� �ٶ��� ���ǹ����� 0���� ��� �� �־�� �Ѵ�.
*/
#include <iostream>

using namespace std;

int arr[101][101];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] != 0) arr[a][b] = arr[a][b] > c ? c : arr[a][b];
		else arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) arr[i][j] = 987654321;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || i == k || k == j) continue;
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 987654321)
				cout << 0 << ' ';
			else
				cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}