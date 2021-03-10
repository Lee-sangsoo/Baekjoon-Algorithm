/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.19
���� : ��ŸƮ�� ��ũ - 14889
Ǯ�� : ��Ʈ��ŷ = ���Ʈ���� + ���� ����
       (���Ʈ ������ �����ϴٰ� �� �̻��� ȣ���� �ǹ̰� ���� ��� �Լ��� �����ϴ� ���)

	   ��Ʈ��ŷ �����̴�.
	   �ڵ� �߰��� ����� ���ǹ� ���ٷ� ���� �Լ��� ���� �ӵ��� ��û �پ���.

	   1. �ظ� �κ��̶�� ����� �κа� ���� �Ǽ��� �� �ִ� �κ��� ���� ������ ����
	   2. vector�� ���� �ڿ� �־����� ���� �ڿ��� ���� �ȴ� (pop_back())
	   3. �������� ����� �ڵ�� int�� �Լ��� �ۼ��Ͽ��µ� �Լ��� ���� �ð��� ��û ���̳���.
	   (��...?)
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int status[21][21];
int ans = 1e9;

int statpoint(vector<int> team) {
	int sum = 0;
	for (int i = 0; i < team.size(); i++) {
		for (int j = 0; j < team.size(); j++) {
			if (i == j) continue;
			sum += status[team[i]][team[j]]; // �ظ� �κ�
		}
	}
	return sum;
}

void go(int idx, vector<int> f, vector<int> s) {
	if (f.size() > n / 2 || s.size() > n / 2) return; // �� ���ٷ� ���� 292ms -> 168ms �� ��
	if (idx == n) {
		if (f.size() != n / 2) return;
		if (s.size() != n / 2) return;
		int f_score = statpoint(f);
		int s_score = statpoint(s);
		int subscore = f_score > s_score ? f_score - s_score : s_score - f_score;
		if (ans > subscore) ans = subscore;
		return;
	}

	// first ���� �� ���
	f.push_back(idx);
	go(idx + 1, f, s);
	f.pop_back(); // erase�� �� �ʿ� ����
	// second ���� �� ���
	s.push_back(idx);
	go(idx + 1, f, s);
	s.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> status[i][j];

	vector<int> first;
	vector<int> second;
	go(0, first, second);
	cout << ans;
}