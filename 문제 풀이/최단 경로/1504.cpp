/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.03
���� : Ư���� �ִ� ��� - 1504
Ǯ�� : ���ͽ�Ʈ�� �˰����� ����Ͽ� Ǫ�� ����. 
       ���ͽ�Ʈ�� �˰����� ������ �� �����ϰ� �ִٸ� �����ϰ� �ذ� ������ �����̴�.

	   ���ͽ�Ʈ�� �˰��� : ���� �������� ������ ��� ���������� �ִ� �Ÿ��� ���ϴ� �˰���
	   �� ������ v1�� v2�� �־��� �� �� �� ���� �� �����鼭 N���� ���� �ּ� ���� ���ϴ�
	   �����̴�. �� ������ Ǯ�� �������ڸ�

	   ���� ������ 1�� �������� �Ȱ�����
	   v1�� v2�� ���ļ� n�� �������� ���� �ϹǷ�
	   1 -> V1 -> V2 -> N ���� �� ���ΰ�
	   1 -> V2 -> V1 -> N ���� �� �������� ���ϸ� �Ǵ� �����̴�.

	   ��, 1�� �������� -> V1�̳� V2�� ���� �ּ� �� +
	   V1�̳� V2���� -> V2�� V1���� ���� �ּ� �� +
	   V2, V1���� -> N���� ���� �ּ� ���� ��� ���� ����
	   ���� ��츦 ���ϸ� �ȴ�.

	   �߰������� �� ���������� �� 3���� ���� ���ؾ� �ϱ� ������
	   3 ������ ��� INF��� ���� �����÷ο찡 ���� ������
	   ans�� ��� ������ �ִ밪 ���� ũ�ų� 0 �̸��̶�� -1�� ����ϵ��� �ؾ� �Ѵ�.
	   (���� ������ �� �ؼ� INF�� �����ϵ��� ����)
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 987654321;
int n, e, v1, v2;
int dist[3][801];
vector<pair<int, int>> arr[801];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// dist[0][n] => 1�� ����
// dist[1][n] => v1�� ����
// dist[2][n] => v2�� ����

void dijkstra(int num, int st) {
	dist[num][st] = 0;
	pq.push({ dist[num][st], st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = cur.first, idx = cur.second;
		if (dist[num][idx] != cost) continue;
		for (auto k : arr[idx]) {
			int ncost = k.first, nidx = k.second;
			if (dist[num][nidx] > cost + ncost) {
				dist[num][nidx] = cost + ncost;
				pq.push({ dist[num][nidx], nidx });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		dist[0][i] = INF;
		dist[1][i] = INF;
		dist[2][i] = INF;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
		arr[b].push_back({ c, a });
	}

	cin >> v1 >> v2;

	dijkstra(0, 1);
	dijkstra(1, v1);
	dijkstra(2, v2);

	int sum1 = dist[0][v1] + dist[1][v2] + dist[2][n];
	int sum2 = dist[0][v2] + dist[2][v1] + dist[1][n];
	int ans = 0;
	if (sum1 > sum2) ans = sum2;
	else ans = sum1;

	if (ans > 800000 || ans < 0) cout << -1;
	else cout << ans;
}