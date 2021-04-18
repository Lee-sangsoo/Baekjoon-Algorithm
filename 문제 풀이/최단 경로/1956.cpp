/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.18
���� : � - 1956
Ǯ�� : �÷��̵� �ͼ� �˰����� ����ϴ� ����
       ���� �÷��̵� �ͼ� ������ Ǯ �� �׻� ��ġ�� �κ�
	   1. ó�� �ڱ� �ڽ� (arr[i][j]���� i == j�� ��)�� ����� 0�̴�.
	   2. ���� ���� ������ i�� j�� �������� Ȯ������ "�ʴ´�."
	   
	   �� ����� �ݵ�� �Ǿ�� �ϴ°��� �ƴ����� (�̺κ��� �ٽ� ����Ȯ������)

	   �� ������ �÷��̵� �ͼ� �˰����� ���� �ִ� ��θ� ���� ����
	   "�ּ� ����� ������ ����Ŭ �Ÿ�" �� ���ϴ� �����̴�.
	   ��, Ư�� N1���� ����Ͽ� �ٽ� N1���� ���ƿ��� ��쿡��
	   ����Ŭ�� �ٸ� �ϳ��� ���� ���ٰ� �ٽ� �����Է� ���ƿ��� ����Ŭ�̱� ������

	   ������ �� ���ϱ⿡�� 2�� �ݺ����� ����
	   i���� ����Ͽ� �ٽ� i�� ���ƿ��� �ּ� ����� ã���� �ȴ�.
*/
#include<iostream>
#include<vector>

using namespace std;

const int INF = 987654321;
int v, e;
long long arr[401][401];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e;

	
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}
	
	/*
	for (int i = 1; i <= v; i++) 
		for (int j = 1; j <= v; j++) 
			arr[i][j] = INF;
	*/

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	long long ans = INF;
	
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			if (ans > arr[i][j] + arr[j][i]) ans = arr[i][j] + arr[j][i];
		}
	}
	
	/*
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) {
				if (ans > arr[i][j]) ans = arr[i][j];
			}
		}
	}
	*/
	if (ans == INF) cout << -1;
	else cout << ans;
}