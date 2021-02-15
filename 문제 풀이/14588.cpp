/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.09
���� : Line Friends (Small) - 14588
Ǯ�� : �÷��̵� �˰����� ����ϸ� �����ϰ� Ǯ�̰� �Ǵ� �����̴�.
       �ٸ�, �־����� ������ �Ÿ��� �迭�� �ε��� ������ �ٷ� �־����� ���� �ƴ϶�
	   �ٸ� ����� ������ �����Ͽ� �ε��������� ���� �־�� �ϴ� �����̴�.

	   ������ Ǯ�̴� ������ ����. 
	   1���� ��ǥ�󿡼� �־����� ������ �ٸ� �������� ���Ͽ� 
	   ���� ��ġ�� ��쿡 �׷����� ��ǥ�� 1�� �ְ� �÷��̵� �˰����� ������ �����ϰ� Ǯ�̵ȴ�.

	   ó�� ������ ����� ��ġ�� ��츦 �����Ͽ� ���ǹ��� �����Ͽ��µ�
	   �� ���� �������� �ʹ� ���� (4���� ��� -> �����ϴ� ���)

	   �̷��� Ǯ� ������ Ǯ������, ���ݸ� �ü��� �ٲ㼭 
	   �������� �ʴ� ��츦 �׳� �ѱ�� ���� �����ϰ� ó���� �Ǿ���.

	   ������ 4���� ���� ¥���� 4���� ���ǹ����� 
	   �������� �ʴ� 2���� ��츦 OR �������� ������ 1���� ���ǹ� ������ ó���� �Ǿ���.

	   �Ʒ��� �ּ��� �ڵ尡 �����ϴ� ��츦 ������ �ڵ��̰�
	   ������ �ڵ尡 �������� �ʴ� ��츦 ������ �ڵ��̴�.

	   �ü��� �޸��ϴ� ������ ������.
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dist[301][301];

int main() {
	cin >> n;
	vector<pair<int, int>> line(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		line[i] = make_pair(a, b);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 987654321;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = line[i].first;
			int b = line[i].second;
			int c = line[j].first;
			int d = line[j].second;
			if (b < c || a > d) continue; // �����ϴ� ���ǿ��� �������� �ʴ� �������� �ٲ� ���ǹ�
			dist[i][j] = 1;
			dist[j][i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int n1 = 1; n1 <= n; n1++) {
		for (int n2 = 1; n2 <= n; n2++) {
			for (int n3 = 1; n3 <= n; n3++) {
				if (dist[n2][n3] > dist[n2][n1] + dist[n1][n3])
					dist[n2][n3] = dist[n2][n1] + dist[n1][n3];
			}
		}
	}

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] == 987654321) cout << -1 << '\n';
		else cout << dist[a][b] << '\n';
	}
}


// �� ������ ���� �����ϰ� ������ ����� ���� �ڵ�
/*
for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = line[i].first;
			int b = line[i].second;
			int c = line[j].first;
			int d = line[j].second;
			if (a <= c && b >= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
			else if (a >= c && b <= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
			else if (b >= c && b <= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
			else if (a <= d && b >= d) {
				dist[i][j] = 1;
				dist[j][i] = 1;
			}
		}
	}
*/