/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.10
���� : �ִܰ�� - 1753
Ǯ�� : ���ͽ�Ʈ�� ����ϴ� ����
	   �Ʒ� �ּ����� �Ǿ��ִ� �κ��� ���������� ������ ������� O(n^2)�� �޸� �ʰ� ������ ����

	   �� �ڵ��� ������ ���� ����Ͽ� Ǯ���� �ڵ��̴�.
	   ���ͽ�Ʈ�� �˰��򿡼� �׻� �ּ� ����� ������ ���� ���� �ϴµ�
	   �� �� �ּ� ���� �����ϸ� �����ϰ� ��� �����ϴ�.

	   ������ ������ ����.
	   1. �� ���� ������ (���, ��������) ������ ���� ��
	   2. ���� ��带 ���� �־��ش�. (0, ���۳��)
	   
	   3. ������ ����� ���� ���� ���Ҹ� �����Ѵ�. (�ּ����� ����ϱ� ������ �׳� .top())
	   4. �ش� ���Ҵ� ������ �����Ѵ�. (.pop())
	   5. �ִ� �Ÿ� �迭(dist)�� ���� ���� ����� ���Ͽ� ���� ������ continue (dist[idx] != dst)
	   6. ���� ���
		6.1. �ִ� �Ÿ� �迭�� ���� ���Ͽ� ���ٸ� �ش� �������� �� �� �ִ� �ٸ� ������(������)�� 
			 Ȯ���Ͽ� ���������� ���������� �ٷΰ��� ���� idx�� ���İ��� ��츦 ���Ͽ� ó��
			 ���ְ� �� ������ ���� �־��ش�.
		6.2. ���� �ٸ��ٸ� �׳� ������ �����ϰ� �Ѿ��.
	   7. �� ������ ���� �������� �ݺ��Ѵ�.

	   8. ���� ���� ������ش�.

	   �� ������ ���ͽ�Ʈ�� �˰����̴�. ���� ����ϴ� ����� O(NlgN)���� ó���� �����ϴٰ� �Ѵ�.
	   �� ������ �����ΰ� �������.

	   �÷��̵�� ���ͽ�Ʈ�� 2������ �ڵ� �׽�Ʈ���� �ַ� ���δ�.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
const int INF = 1e9 + 10; // ��
int dist[20001];
vector<pair<int, int>> arr[20001]; // ���� ������ �����ϱ� ���� ���� 
								   // 2���� �迭�� ������� �ʰ� arr[����] = {{���, ����}} �̴�.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	// �ּ� ���� ����Ͽ� �׻� �ּҰ��� ���õǵ��� �Ѵ�.

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	fill(dist, dist + n + 1, INF); // ��
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b }); // ��
	}
	dist[k] = 0;
	pq.push({ dist[k], k }); // �������� (0, ������) ���� ���� �ִ´�.
	while (!pq.empty()) { // ���ͽ�Ʈ�� ó�� ���� // ��
		auto cur = pq.top();
		pq.pop();
		int dst = cur.first, idx = cur.second; // dst = ���, idx = ����
		if (dist[idx] != dst) continue; // �ִ� �Ÿ� �迭�� ���� �ٸ��ٸ� continue
		for (auto nxt : arr[idx]) { // nxt = idx���� �� �� �ִ� ������ ���� (���, ����)
			int cost = nxt.first, nidx = nxt.second; // cost = ���� �������� ���, nidx = ���� ����
			if (dist[nidx] > dst + cost) { // �ִ� �Ÿ� �迭�� ���Ͽ� ���İ��°� �� �δٸ�
				dist[nidx] = dst + cost; // �ִ� �Ÿ� �迭�� ���� ����
				pq.push({ dist[nidx], nidx }); // �� ������ ���� ��´�.
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

















/*
// O(n^2)�� Ǯ�� (�ð�, �޸� �ʰ��� ����)
#include <iostream>

using namespace std;

int n, m, k;
int INF = 987654321;

int dist[20001];
bool chk[20001];
int line[20001][20001];

int getSmallerIndex() {
	int min = INF;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		if (i == k) continue;
		if (min > dist[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 1; i <= n; i++) dist[i] = line[k][i];
	chk[start] = true;
	for (int i = 1; i <= n - 1; i++) {
		int cur = getSmallerIndex();
		chk[cur] = true;
		for (int j = 1; j <= n; j++) {
			if (chk[j]) continue;
			if (dist[j] > dist[cur] + line[cur][j])
				dist[j] = dist[cur] + line[cur][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	cin >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			line[i][j] = INF;
		}
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		line[a][b] = line[a][b] > c ? c : line[a][b];
	}

	dijkstra(k);

	dist[k] = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}
*/