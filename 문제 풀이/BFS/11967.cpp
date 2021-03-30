/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.30
���� : ���ѱ� - 11967
Ǯ�� : ť�� ����ϰ� BFS�� ����Ͽ� Ǯ���� ����
       ������ �˰��������� Ǯ� ���� �����ϸ�
	   (1) ���� ��ҿ��� ���� ų �� �ִ°��� ��� �濡 ���� Ų��
	   (2) �̵� ������ ���� ã�� �̵��Ѵ�
	   (3) �̵��� ��ҿ��� ť�� �� ������ (1)�� (2)�� �ݺ��Ѵ�

	   �� �ǰڴ�. �� �������� ���� ��� �Ǽ��� �ѹ��� AC�� ���� ���Ͽ��µ�
	   �� �Ǽ��� ������ ����.

	   1. ���� ������ �̵��� �����Ѱ��� Ȯ���ϴ� Ÿ�̹�
	   2. ���ο� ���� ���� �� �� �� �� �ִ� ���� ���Ӱ� ����°�.

	   �ε�, 2�� ������ 1���� �Ǽ��� ����ٰ� �� �� �ִ�.
	   �� ������ ������ ����.
	   ���ο� ��ҷ� �̵��ϰ� �� �� ���� ���ӵ� �� ���� ���� Ű�� �Ǵµ�
	   ���ӵ� �濡�� ������ ���� ���� Ű�� �߰��� ���� ���� Ű�� �ʰ�
	   �̵� ���ɿ��θ� Ȯ���ϰ� �Ǹ� �̵��� �Ұ����ϰ� ������ �����.

	   �� �Ǽ��� ��ġ�� ���� ��� ��ǥ�� ���� �̵� ������ ���ο� ���� �ֳ�
	   Ȯ���� �غ������� �� �ڵ�� �ð��ʰ��� �ް� �Ǿ���.

	   ���������� 2���� �Ǽ��� ���� �Ǽ��� ��ġ�� ���� ���Ӱ� ���� ������ ��� ����
	   ��ǥ�� �����ϰ� �ش� ���� ��ǥ�� �̵��������� Ȯ���� �ߴµ�, ���⼭ 
	   ��ģ ���� ���Ӱ� ���� ������ �Ǹ鼭
	   ������ �̵����� ���ϴ� ���� ���� �ִ� ����� ������ ������ ���ְ� �Ǹ�
	   �̵��� ������ ���ο� ���� ����� �Ǵ� ���̴�.
	   Ex) O X O -> O O O 

	   �̷� �Ǽ����� ��ġ�� ���� ���������� ������ �����
	   �ϳ��� �濡�� ������ ��� ����ġ�� �۵����� ���� Ű�� ����
	   BFS Ž���� ���鼭 ������ �湮���� ���� �� �� �� �� �ִ� ��� ����
	   vector�� ��� ��ȯ��Ű�� ���̴�.
	   �� ���͸� �ݺ����� ���� �� �� �ִ� ������ ��� ť�� �־� �ٽ� Ž����
	   �����ϴ� ����� ����Ͽ� Solve�� �� �־���.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> arr[101][101];
bool on[101][101];
bool chk[101][101];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<pair<int, int>> canGo() {
	vector<vector<bool>> tmp(n + 1, vector<bool>(n + 1, false));
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	tmp[1][1] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
			if (tmp[nx][ny] || on[nx][ny] == false) continue;
			q.push({ nx, ny });
			tmp[nx][ny] = true;
		}
	}

	vector<pair<int, int>> vv;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// �湮������ ������ �� �� �ִ� ���ΰ��
			if (tmp[i][j] && chk[i][j] == false) vv.push_back({ i, j });
		}
	}
	
	return vv;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	on[x][y] = true;
	chk[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		// �켱 ��� ���� ���� ���ش�.
		for (auto nxt : arr[x][y]) {
			int nx = nxt.first;
			int ny = nxt.second;
			on[nx][ny] = true; 
		}
		
		// ���Ӱ� �� �� �ִ� ��� ���� ��ǥ�� �޾ƿͼ� ť�� �ִ´�.
		vector<pair<int, int>> tmp = canGo();
		for (auto nxt : tmp) {
			int nx = nxt.first;
			int ny = nxt.second;
			q.push({ nx, ny });
			chk[nx][ny] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		arr[x][y].push_back({ a, b });
	}

	bfs(1, 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (on[i][j]) cnt++;
		}
	}
	cout << cnt;
}