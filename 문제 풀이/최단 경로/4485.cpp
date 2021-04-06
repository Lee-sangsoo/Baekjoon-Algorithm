/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.06
���� : ��� �� ���� �ְ� ������? - 4485
Ǯ�� : ���ͽ�Ʈ�� �˰����� ���̽��� ���� vector�� ���� ���� ������ �⺻���� ����ٸ�
       �� ������ ��ķ� �־��� ���鿡�� Ư�� ��ǥ (x, y)���� (nx, ny)������ �ּ� �Ÿ���
	   ã�� �����̴�.

	   ������ �˰� ���� ���ͽ�Ʈ�� ������ ���� �����Ͽ� �����ϴ� ���� �ʿ��ϴ�.
	   ������ ����ϴ� vector���� arr[n].push_back({cost, nxt}) ���� �̸� ���� Ǯ��
	   �����ϸ� n���� nxt�� �������� �� �� ��� ����� cost�̴�.
	   ������ �̸� ��Ŀ� �����Ͽ�
	   (x,y)��ǥ���� (nx, ny)�� ���� �ִ� �Ÿ���
	   2���� 2���� �迭�� ����Ͽ� 
	   arr[][] => �ʱ� ����
	   dist[][] => ���� ��ǥ���� �ش� ��ǥ���� ���µ� ��� ���
	   ���� �ΰ� Ǯ�̸� �ϸ� �ȴ�.

	   ���� ������ pair<int, pair<int, int>>�� �ȴ�.
	   ({ cost, { x, y } })

	   �� ���������� �������� (0, 0) ���� �ΰ� �ش� ��ǥ���� �ٸ� ��ǥ�� ���� 
	   �ִ� �Ÿ��� ���ϴ� ���ͽ�Ʈ�� �˰����� �����ϰ� ���� ��������
	   dist[n-1][n-1]�� ��� ���ָ� �ȴ�.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int INF = 987654321;
int n;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int arr[126][126];
int dist[126][126];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				dist[i][j] = INF;
			}
		}

		dist[0][0] = arr[0][0];
		pq.push({ dist[0][0], {0, 0} });

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			int cost = cur.first, x = cur.second.first, y = cur.second.second;
			if (dist[x][y] != cost) continue;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				int ncost = arr[nx][ny];
				if (dist[nx][ny] > cost + ncost) {
					dist[nx][ny] = cost + ncost;
					pq.push({ dist[nx][ny], { nx, ny } });
				}
			}
		}

		cout << "Problem " << t << ": " << dist[n - 1][n - 1] << '\n';
		t++;
	}
}