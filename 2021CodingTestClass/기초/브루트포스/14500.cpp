/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.16
���� : ��Ʈ�ι̳� - 14500
Ǯ�� : ���Ʈ�����̸鼭 �������� ���� ����
       �ִ� 500 * 500ĭ���� �� ����� �� 19������ �˻��ϴ� �����̱� ������
	   ���Ʈ ������ ��� ����Ǽ��� Ȯ���ϸ� �Ǵ� ������ �����̴�.

	   �ٸ�... ��û���� �밡�ٸ� �ؾ� �Ѵ�...
	   (�׸� �׸��� ��ǥ ����ΰ� �����ϸ� ����)
*/
#include<iostream>
#include<algorithm>

using namespace std;

int point[501][501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> point[i][j];
		}
	}

	int totalPoint = 0;
	// �������� ����
	for (int i = 0; i < n; i++) { // ����
		for (int j = 0; j < m - 3; j++) { // ����
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i][j + 3];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// �������� ����
	for (int i = 0; i < n - 3; i++) {
		for (int j = 0; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 3][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ����
	// ����
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i][j + 1] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ��
	// ��
	// ����
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ��
	//   ��
	// ����
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 2][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ����
	//   ��
	//   ��
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j + 1] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ����
	// ��
	// ��
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j] + point[i + 2][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ������
	//     ��
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ������
	// ��
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i + 1][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//     ��
	// ������
	for (int i = 0; i < n - 1; i++) {
		for (int j = 2; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j - 1] + point[i + 1][j - 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ��
	// ������
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j + 1] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ��
	// ����
	//   ��
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 1][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ��
	// ����
	// ��
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ��
	// ������
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j - 1] + point[i + 1][j] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ������
	//   ��
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j - 1] + point[i + 1][j] + point[i][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ��
	// ����
	//   ��
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j + 1] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ��
	// ����
	// ��
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j - 1] + point[i + 2][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// ����
	//   ����
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j + 1] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   ����
	// ����
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j - 1] + point[i + 1][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	cout << totalPoint;
}