/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.04
���� : �ּҺ�� ���ϱ� - 1916
Ǯ�� : ���ͽ�Ʈ�� �˰����� ����ϸ� �����ϰ� Ǯ���� ����
       �������� ������ �־����� �׻� ������ ��츸 �Է����� �־����� ������
	   �Ϲ������� ���ϰ� ��¿��� ���ǹ��� ���� �Ұ��������� ������ �ʿ䰡 ����.
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 987654321;
int n, m;
int s, e;
int dist[1001];
vector<pair<int, int>> arr[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> m;
	fill(dist, dist + n + 1, INF);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
	}
	cin >> s >> e;
	dist[s] = 0;
	pq.push({ dist[s], s });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = cur.first, idx = cur.second;
		if (dist[idx] != cost) continue;
		for (auto k : arr[idx]) {
			int ncost = k.first, nidx = k.second;
			if (dist[nidx] > ncost + cost) {
				dist[nidx] = ncost + cost;
				pq.push({ dist[nidx], nidx });
			}
		}
	}

	cout << dist[e];
}