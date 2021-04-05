/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.05
���� : ��Ƽ - 1238
Ǯ�� : ���ͽ�Ʈ�� �˰����� ����Ͽ� Ǫ�� ����
       �� �������� ������(x)���� �ɸ��� ���� �����ְ�
	   ���������� �� �������� �ɸ��� ���� ���Ͽ�
	   �� ���� ���� �ִ밡 �Ǵ� ���� ��� ���ָ� �ȴ�.

	   ������ Ǯ���� �����غ��� ù��° �� �������� ���������� �ɸ��� ���� 
	   ���� ������ �÷��̵� �ͼ� �˰����� �ᵵ �ɰ� ����...

	   ���ͽ�Ʈ�� �˰����� �ð� ���⵵�� 
	   O(ElogV)�̴�. (E = ������ ����, V = ������ ����)
	   �� �������� E = 10000   V = 1000 ����
	   �ִ� 1000 * 10000 * 3 �� �Ǳ� ������ �ð��ʰ��� ���� �ʴ´�.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int INF = 987654321;
int n, m, x;
vector<pair<int, int>> arr[1001];
int distGo[1001];
int distBack[1001];

int dijkstraGo(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int dist[1001];
	fill(dist, dist + n + 1, INF);
	dist[st] = 0;
	pq.push({ dist[st], st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = cur.first, idx = cur.second;
		if (dist[idx] != cost) continue;
		for (auto k : arr[idx]) {
			int ncost = k.first, nidx = k.second;
			if (dist[nidx] > cost + ncost) {
				dist[nidx] = cost + ncost;
				pq.push({ dist[nidx], nidx });
			}
		}
	}
	return dist[x];
}

void dijkstraBack(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(distBack, distBack + n + 1, INF);
	distBack[st] = 0;
	pq.push({ distBack[st], st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cost = cur.first, idx = cur.second;
		if (distBack[idx] != cost) continue;
		for (auto k : arr[idx]) {
			int ncost = k.first, nidx = k.second;
			if (distBack[nidx] > cost + ncost) {
				distBack[nidx] = cost + ncost;
				pq.push({ distBack[nidx], nidx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c, b });
	}

	for (int i = 1; i <= n; i++) {
		if (i == x) {
			distGo[i] = 0;
			continue;
		}
		distGo[i] = dijkstraGo(i);
	}

	dijkstraBack(x);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < distGo[i] + distBack[i])
			ans = distGo[i] + distBack[i];
	}

	cout << ans;
}