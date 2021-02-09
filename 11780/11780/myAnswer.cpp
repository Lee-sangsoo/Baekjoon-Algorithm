/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.09
���� : �÷��̵� 2 - 11780
Ǯ�� : �÷��̵� �˰��򿡼� ��θ� ���ؾ� �ϴ� ����

       �־��� ��İ� ũ�� �ٸ��� ����.
	   �⺻������ �÷��̵� �˰����� �����ϸ鼭
	   ���� �������� �������� ���� ������ ������� �����ϴ� �迭�� �ϳ� �� ����ϸ� �ȴ�.

	   ���� �÷��̵� �˰��򿡼� ���İ��� ������ �� ª�ٸ�
	   �������� ���� ���� ���� ���İ��� ������ ������ �ٲ��ش�.
	   �ٽ� ����
	   nxt[n][m] = n���� m���� �� ���� ���� ���� (�� ���� m�� ������ ������ ���̴�)
	   ó�� �⺻���� ��� m�̴�.

	   ������, �÷��̵� �˰����� ���鼭 
	   dist[n][m] = dist[n][k] + dist[k][m] �̶��
	   nxt[n][m] = nxt[n][k]�� �ȴ�.

	   �� �Ŀ� nxt[n][m]�� m�� ���� �� ���� ��ȸ�ϸ鼭 ���� �����ϰ� ����ϸ�ȴ�.
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dist[101][101];
int nxt[101][101];
int main() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 987654321;
		}
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = dist[a][b] > c ? c : dist[a][b];
		nxt[a][b] = b;
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int n1 = 1; n1 <= n; n1++) {
		for (int n2 = 1; n2 <= n; n2++) {
			for (int n3 = 1; n3 <= n; n3++) {
				if (dist[n2][n3] > dist[n2][n1] + dist[n1][n3]) {
					dist[n2][n3] = dist[n2][n1] + dist[n1][n3];
					nxt[n2][n3] = nxt[n2][n1];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 987654321) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> path;
			if (i == j) {
				cout << 0 << '\n';
				continue;
			}
			int cur = nxt[i][j];
			path.push_back(i);
			while (cur != j) {
				path.push_back(cur);
				cur = nxt[cur][j];
			}
			path.push_back(j);

			cout << path.size() << ' ';
			for (int k = 0; k < path.size(); k++)
				cout << path[k] << ' ';
			cout << '\n';
		}
	}
}