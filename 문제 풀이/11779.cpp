/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.11
���� : �ּҺ�� ���ϱ� 2 - 11779
Ǯ�� : ���ͽ�Ʈ���� ��� ���� ����
       �÷��̵� �˰���� �ſ� �����ѵ�,
	   �÷��̵� �˰����� ��θ� ã�°��� start���� �����Ͽ� ���� ��带 ã�� ���ٸ�

	   ���ͽ�Ʈ�� �˰����� ��θ� ã�°��� "end���� �����Ͽ� ���� ��带 ã�ư���"
	   �� �Ųٷ� Ž���� �ذ��ٴ� ���̴�.
	   
	   ����� ������ ����
	   ���� ���� ���� ó���� �Ͼ ��, ���ο� ������ ���� ��带 ����ϴ� ���̴�.
	   �÷��̵�� �޸� 1���� �迭�� ������ �ȴ�.

	   ���� �������� ó���� �÷��̵�� ����ϰ� �����ؼ� nxt��� �迭�� ��������
	   ��Ȯ�� ��Ī�� pre�� ������ ����.

	   �� �� �İ� �ƴ� �� ���� ��带 �����ϰ� �޾ƿͼ� �ݴ�� ����Ѵ�.

	   �߰������� ���� �̸��� �� ���� �ʿ䰡 �ִ�.
	   Ȯ���� ��Ī�� ���� end�� ���� ���� ������ ���� �ִµ� �̴� vector�� iter�� 
	   �̸��� ��ġ�⵵ �ϹǷ� �ٸ� �̸��� ������ �ʿ䰡 �ִ�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

vector<pii> line[1001];
int d[1001];
int nxt[1001];
const int INF = 1e9 + 10;
int n, m, st, en;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	fill(d, d + n + 1, INF);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		line[a].push_back({ c, b });
	}

	cin >> st >> en;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[st] = 0;
	pq.push({ d[st], st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int dist = cur.first, idx = cur.second;
		if (d[idx] != dist) continue;
		for (auto nnxt : line[idx]) {
			int cost = nnxt.first, nidx = nnxt.second;
			if (d[nidx] > cost + dist) {
				d[nidx] = cost + dist;
				pq.push({ d[nidx], nidx });
				nxt[nidx] = idx; // ��� ��忡�� �Դ����� ���
			}
		}
	}


	int now = en; // end���� ����Ͽ� ���� path�� ���
	vector<int> path;
	while (now != st) {
		path.push_back(now);
		now = nxt[now];
	}
	path.push_back(now);
	reverse(path.begin(), path.end()); // ������ �� ���� ���

	cout << d[en] << '\n';
	cout << path.size() << '\n';
	for (auto i : path)
		cout << i << ' ';
}