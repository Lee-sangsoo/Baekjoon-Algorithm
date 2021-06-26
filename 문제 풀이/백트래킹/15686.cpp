/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 15686 - ġŲ ���
Ǯ�� : ��� ������ ���� 2���� �迭�� ����ؾ� �� �� ������, 
	   ġŲ���� ��ġ�� ���� ��ġ�� ������ ������ ���� ������ �����ϴ� ���� �����̴�.
	   ġŲ���� ��ġ���� ���Ϳ� ��� �����صΰ� �� �߿��� M���� �̾� ������ �����
	   ������ �Ÿ��� ����ϰ� �ּҰ��� �����ָ� �ȴ�.
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int ans = 987654321;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> choose_chicken;

int calc() {
	int ret = 0;
	for (int i = 0; i < house.size(); i++) {
		int closer = 1000;
		for (int j = 0; j < choose_chicken.size(); j++) {
			int x = house[i].first > choose_chicken[j].first ? house[i].first - choose_chicken[j].first : choose_chicken[j].first - house[i].first;
			int y = house[i].second > choose_chicken[j].second ? house[i].second - choose_chicken[j].second : choose_chicken[j].second - house[i].second;
			closer = min(closer, x + y);
		}
		ret += closer;
	}
	return ret;
}

void go(int nxt, int cnt) {
	if (cnt == m) {
		int cur = calc();
		ans = min(ans, cur);
		return;
	}

	for (int i = nxt; i < chicken.size(); i++) {
		choose_chicken.push_back(chicken[i]);
		go(i + 1, cnt + 1);
		choose_chicken.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 1) house.push_back({ i, j });
			if (num == 2) chicken.push_back({ i, j });
		}
	}
	go(0, 0);
	cout << ans;
}