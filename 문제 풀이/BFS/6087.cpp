/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.04
���� : 6087 - ������ ���
Ǯ�� : BFS Ǯ���� �� �ٸ� ����� �˷��� ����
       (���� ��������� Ǯ�� ���ؼ� Ǯ�̸� ã�ƺ��� Ǭ ����)

	   �� ������ �Ϲ����� BFS�� Ǯ�� Ǯ�� ���Ѵ�.
	   BFS�� �ִ� �Ÿ��� ã�µ��� ����ȭ�� �����̰� �� ������ �ش� ��η� ���� �������� ����� ���� ������ ��������� Ȯ���ϴ� �����̱� �����̴�.
	   �׷��� ������ ���� Ǯ�̿� ��ȭ�� �ʿ��ϴ�.
	   (�Ϲ����� BFS���� ���� ��ȭ�� �ʿ��ϸ� �߰������� Ž���� �ٽ� �����ϴ� ����� �ִٰ� �ϴµ� �� Ǯ�̺��� ���� �ɸ���)

	   �� Ǯ�̴� ���� �������� '���� ���� ����'�� �� �ִ� ��� ������ �ѹ��� �湮�ϵ��� �ϴ� ����̴�.

	   �������

	   . . C . .   �� �ִٸ�
	   1 1 0 1 1   �� ó���� �ȴٴ� ���̴�.

	   dist�� ���Ǵ� ��������� �ش� �������� ���µ� �ʿ��� ������ ������ �ȴ�. (������ ���� - 1 => �ʿ��� �ſ��� ����)
	   ��, ���� �������� �� �� �ִ� ���� ����(������ �����ų�, ���� �����ų� �ϱ� ������) ��� ������ ������ �����ֵ��� �ϴµ�
	   ���⼭ ���ο� ����� ���´�.

	   �ٷ� ������ 'if(nx < 0 || nx >= n || ny < 0 || ny >= m)' ��
	   ������ ���� 'while(nx >= 0 && nx < n && ny >= 0 && ny < m)'���� �ٲپ� �ش� �ݺ��� �ȿ���
	   nx += dx[k] 
	   ny += dy[k]�� �ݺ����ָ�
	   ���� ������ break��Ű�� �׷��� �ʴٸ� ����ؼ� �������Ѱ��� 
	   dist[nx][ny] = dist[x][y] + 1 �� ó�� ���ش�. (�� ����ó�� ó���Ѵ�)

	   �̸� ���� ���� ������ ���� C�� �ִ� ��ǥ�� dist���� -1�� ���ָ� �ȴ�.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int w, h;
vector<pair<int, int>> rc;
char arr[101][101];
bool chk[101][101];
int dist[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void show() {
	cout << '\n';
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cout << dist[i][j] << "  ";
		}
		cout << '\n';
	}
}

void init() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			dist[i][j] = 987654321;
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({rc[0].first, rc[0].second});
	dist[rc[0].first][rc[0].second] = 0;
	chk[rc[0].first][rc[0].second] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			while (nx >= 0 && nx < w && ny >= 0 && ny < h) {
				if (arr[nx][ny] == '*') break;
				if (!chk[nx][ny]) {
					chk[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
				nx += dx[k];
				ny += dy[k];
			}
			/*
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if (chk[nx][ny] || arr[nx][ny] == '*') continue;
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
			*/
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w;
	int cnt = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') rc.push_back({ i, j });
		}
	}
	//init();
	bfs();
	//show();
	cout << dist[rc[1].first][rc[1].second] - 1;
}
