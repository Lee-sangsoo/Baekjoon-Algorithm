/*
�ۼ��� : �̱���
�Ͻ� : 2021.05.26
���� : �α� �̵� - 16234
Ǯ�� : ���� ���� ������ BFS�� �����
       ���� ������ �׻� ���� �ɸ����� ��մ� (Ǯ�� �ְŵ�...)

	   ������ �����ΰ� �����ΰ��� ���ؾ� �ϴ°��� �켱�̰�
	   ������ �����ٸ� �����ִ� ���氣�� ���� �α� �̵��� �ؾ� �Ѵ�.

	   �� �Լ��� ������ ���� ������ ���ڸ�
	   <����>
	   people[x][y] => (x,y)������ �α� ��

	   line[x][y][4] => (x,y)������ ���漱 ���� ���� -> ��, ��, ��, �� ������ 0, 1, 2, 3 �ε����� ������.

	   dx, dy[] => BFSŽ���� ���� ĭ �̵� �迭

	   dxs, dys[] => �α��� Ž���� ���� ĭ �̵� �迭

	   <�Լ�>
	   find_people => ���� �´��� �������� �α� ���� L�̻� R���� ���� Ȯ���Ͽ� ������ ���� �Լ��̴�.
	                  �� �Լ��� BFS�� �޸� (0,0)���� �����Ͽ� �����ʰ� �Ʒ����� ������ Ž���ϸ� �����Ѵ�.
					  �̷��� �����ϸ� ������ �Ǵ� ������ (x,y) �α� ������ (dx, dy)��� ���� ��
					  ���� ������ ���漱 �ε����� �α� ������ ���漱 �ε����� ���ǹ��� ���� �� ���� ����� ���漱�� ��������ش�.
	   
	   find_end => ��� ���漱�� �����ִ��� Ȯ���ϴ� �Լ��� ��� �����ִٸ� ���̻� �̵��� ���ٴ� ���̹Ƿ� �ݺ����� �����Ű�� ���� bool ������ �����Ѵ�.

	   bfs => 2���� queue�� ���Ǵµ�
	          q => bfs Ž���� ť
			  people_cnt => Ž���� ��ġ�� ��� �ο��� people �迭�� ������� �־�� �ϴ��� ��ǥ���� ������ �ִ� ť
			  �� �ΰ��� ť�� ����ϸ�
			  ���� q ť�� ����Ͽ� ���漱�� �����ְ� �������� ���� ������� �̵��Ͽ� ���漱�� �ݰ� 
			  sum_people (���漱�� ���� �������� �� ��)
			  cnt (�� ���� ��)
			  �� ���� �������� ��� ���� �����.
			  �׸��� ���� people_cnt ť�� ����Ͽ� �̵��� �����鿡 ���� ��� �ο����� ��� �ٲ��ش�.

	   union_people => ���� ���漱�� �ľ��ϱ� ���� ��� (bfs�� ��ġ�� ���������� ���� ���� ���״�.)
*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, l, r;
int people[50][50];
int line[50][50][4];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dxs[] = { 0, 1 };
int dys[] = { 1, 0 };

void find_people() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 2; k++) {
				int x = i + dxs[k];
				int y = j + dys[k];
				if (x >= n || y >= n) continue;
				int sub_people = people[i][j] > people[x][y] ? people[i][j] - people[x][y] : people[x][y] - people[i][j];
				if (sub_people >= l && sub_people <= r) {
					if (k == 0) {
						line[i][j][k + 1] = true;
						line[x][y][k + 3] = true;
					}
					else { // k = 1
						line[i][j][k + 1] = true;
						line[x][y][k - 1] = true;
					}
				}
			}
		}
	}
}

bool find_end() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (line[i][j][k]) return false;
			}
		}
	}
	return true;
}

void bfs(int a, int b) {
	int sum_people = people[a][b];
	int cnt = 1;
	vector<vector<bool>> chk(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	queue<pair<int, int>> people_cnt;
	q.push({ a, b });
	people_cnt.push({ a, b });
	chk[a][b] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int k = 0; k < 4; k++) {
			if (!line[x][y][k]) continue;
			line[x][y][k] = false;
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny]) continue;
			q.push({ nx, ny });
			people_cnt.push({ nx, ny });
			chk[nx][ny] = true;
			if (k == 0) {
				line[nx][ny][2] = false;
			}
			else if (k == 1) {
				line[nx][ny][3] = false;
			}
			else if (k == 2) {
				line[nx][ny][0] = false;
			}
			else {
				line[nx][ny][1] = false;
			}
			sum_people += people[nx][ny];
			cnt++;
		}
	}
	//cout << sum_people << ' '  << cnt << '\n';
	int avg_people = sum_people / cnt;
	while (!people_cnt.empty()) {
		auto cur = people_cnt.front();
		people_cnt.pop();
		int x = cur.first;
		int y = cur.second;
		people[x][y] = avg_people;
	}
}

void union_people() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (line[i][j][k]) bfs(i, j);
			}
		}
	}
}

void show_people() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << people[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> people[i][j];
	//cout << '\n';
	int answer = 0;
	while (1) {
		find_people();
		bool chk_end = find_end();
		if (chk_end) break;
		union_people();

		//show_people();

		answer++;
	}

	cout << answer;
}