/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.02
���� : 16235 - ���� ����ũ
Ǯ�� : �Ｚ S���� ���� ������� �Ѵ�.
       ������ �����ϸ� ������ ����.
	   
	   1. ���� N X N ũ�� �̸� (1,1) ~ (n,n)�����̴�.
	   2. ��� ���� ����� 5���� �����Ѵ�.
	   3. M���� ������ �����Ͽ� ������ ��ĭ�� ���� �������� ������ ������ �� �ִ�.
	   4. ��, ����, ����, �ܿ�� ������ ����ȴ�.

	   �� : ������ ���̸�ŭ ����� �԰� ���̰� 1���� �Ѵ�.
	        ��, ������ ��������� ���̰� ���� �������� ����� �Դ´�.
			���̸�ŭ�� ����� ���� ���ϸ� �״´�.
	   ���� : ���� ���� �������� ���� ����� �ȴ� (���� ������ ���� / 2)
	   ���� : ���� �������� ���̰� 5�� ������ �ڽ��� �������� 8���⿡ ���̰� 1�� ������ �����Ѵ�.
	   �ܿ� : ���� A�迭 ��ŭ�� ����� �߰��Ѵ�.

	   ����, ����, �ܿ��� ������ �����ϰ� ó���ȴ� (�����ϴ�)

	   ������, ���� ��� ���� ������ ���� ������ ���� Ǯ�� �Ǿ��µ�
	   1. �켱���� ť�� ����Ͽ� ó��
	   2. ���Ϳ��� ������ ����Ͽ� ó��
	   3. ���� ���

	   1���� ��� �ð��ʰ��� ������� ���߰�
	   2���� ��� Ǯ�̴� ������ �ð��� ���ѽð��� ���ϸ� ���� �˹��ߴ�.

	   1���� ������ ������ ������ ���ٰ� �Ѵ�.
	   �켱���� ť�� Ư�� ���� �����ϸ� �Ź� ������ �߻��ϰ� �� �ڵ� ������ �ӽ� ���Ϳ� ���� �޾Ƽ� �ٽ� ť�� �ֱ� ������ 2���� ������ �Ͼ�� �ð� �ʰ��� �Ͼ�ٰ� �Ѵ�.

	   2���� ��� 1���� 2�� ������ 1���� �����ϵ��� �ϴ� ������ ���� ����� �Ǿ���

	   ������ 3���� Ǯ�̸� �˻��� ���� Ȯ���� ��� ���� ����ϸ� 2������ �ξ� ȿ������ ����� �����ߴ�.
	   ���� �ڷᱸ�� Ư����
	   ��(front) ��(back)���� pop�� push�� �����ϴٴ� Ư¡�� �ִ� �ڷᱸ���̴�.
	   �׷��� ������ ���� ������ ���̸� ó������ ������������ ���ĵǵ��� ���� ����Ѵٸ� ������ ��� �ùٸ� ������ �����ϴٴ� ���̵ȴ�.

	   ��ĭ�� ���� �������� ���̰� (3, 4, 5) ���
	   �� 3���� �ݺ��ϵ��� size�� �޾ƿͼ� �ݺ����� ���� front���� pop�� ���ش�. �׸���
	   - ����� ���� �� �ִ� ������ ���̸� ������Ű�� ���� �ڷ� �־��ش�.
	   - ����� ���� ���ϴ� ������ ���� ������ ���Խ�Ű�� ���� �ٽ� �־����� �ʴ´�.

	   �� ������ ���� �������� ���� ������ �����ǰ� ����ִ� �����鸸 �״�� Ž���ȴ�.

	   ���⼭ �ϳ� ������ "size�� �޾ƿͼ� �ݺ����� ���� ��" �̴�.
	   ����� �˰��־��� �� �� �ִ� ��������, �� �ڷᱸ������ �����ϰ� ���̴� ����ΰ� ������ �˾Ƶθ� ������ ����.

	   (�߰��� 3������ �ξ� ���� ������� ������ ����� �ڵ带 ������ �� �־���.
	    �� ���� �ڵ�� �߰��� Ž���� �߰��� �����ϰ� ���� ���� ��� ���� ������ �ְų� ������ ó���� ������ �̸� spring_to_summer �Լ����� ������ �ϴ� ������ �����ϼ̴�.)

		(�Ʒ� �ּ� �ڵ� -> 2�� // �� �ڵ� -> 3�� // 1�� �ڵ�� �ð��ʰ��� ����)
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, m, k;
int a[11][11];
int food[11][11];
deque<int> trees[11][11];

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void spring_to_summer() {
	vector<pair<pair<int, int>, int>> dead_tree;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			int it = trees[i][j].size();
			while(it--) {
				int age = trees[i][j].front();
				trees[i][j].pop_front();
				if (age <= food[i][j]) {
					food[i][j] -= age;
					trees[i][j].push_back(age + 1);
				}
				else {
					dead_tree.push_back({ {i, j}, age });
				}
			}
		}
	}

	for (int i = 0; i < dead_tree.size(); i++) {
		auto cur = dead_tree[i];
		int x = cur.first.first;
		int y = cur.first.second;
		int z = cur.second;
		food[x][y] += z / 2;
	}
}

void autumn() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int t = 0; t < 8; t++) {
						int nx = i + dx[t];
						int ny = j + dy[t];
						if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
						trees[nx][ny].push_front(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] += a[i][j];
		}
	}
}

int count_tree() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += trees[i][j].size();
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			food[i][j] = 5;

	while (k--) {
		spring_to_summer();
		autumn();
		winter();
	}

	int ans = count_tree();
	cout << ans;
}


/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int a[11][11];
int food[11][11];
vector<int> trees[11][11];

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void spring_to_summer() {
	vector<pair<pair<int, int>, int>> dead_tree;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			vector<int> tmp;
			sort(trees[i][j].begin(), trees[i][j].end());
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] <= food[i][j]) {
					tmp.push_back(trees[i][j][k] + 1);
					food[i][j] -= trees[i][j][k];
				}
				else {
					dead_tree.push_back({ {i, j}, trees[i][j][k] });
				}
			}
			trees[i][j].clear();
			for (int k = 0; k < tmp.size(); k++) {
				trees[i][j].push_back(tmp[k]);
			}
		}
	}

	for (int i = 0; i < dead_tree.size(); i++) {
		auto cur = dead_tree[i];
		int x = cur.first.first;
		int y = cur.first.second;
		int z = cur.second;
		food[x][y] += z / 2;
	}
}

void autumn() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (trees[i][j].empty()) continue;
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int t = 0; t < 8; t++) {
						int nx = i + dx[t];
						int ny = j + dy[t];
						if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
						trees[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] += a[i][j];
		}
	}
}

int count_tree() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += trees[i][j].size();
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			food[i][j] = 5;

	while (k--) {
		spring_to_summer();
		autumn();
		winter();
	}

	int ans = count_tree();
	cout << ans;
}
*/