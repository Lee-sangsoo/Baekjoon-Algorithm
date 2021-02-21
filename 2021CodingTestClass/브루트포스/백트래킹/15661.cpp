/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.21
���� : ��ũ�� ��ŸƮ - 15661
Ǯ�� : ��ŸƮ�� ��ũ �������� ���� �ο����� �ݹ��� �Ǿ�� �Ѵٴ� ������ ������
       ���� �ο���� ���� �ʾƵ� ������, �ּ� �Ѹ��� �־�� �Ѵ� ��� �������� �ٲ����.

	   ��ŸƮ�� ��ũ ������ Ǯ�̴� �Ȱ����� 
	   �� ���͸� �޾ƿ��� idx�� n�� �������� �� 
	   �� ������ �ϳ��� ����ִٸ� �߸��� ������ return �Ѵ�.

	   �׷��� �������� �� ���� �ɷ�ġ�� ����Ͽ� ó���Ѵ�.
*/
#include<iostream>
#include<vector>

using namespace std;

int point[21][21];
int n;
int ans = 1e9;

int chk(vector<int> t) {
	int sum = 0;
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t.size(); j++) {
			if (i == j) continue;
			sum += point[t[i]][t[j]];
		}
	}
	return sum;
}

void go(int idx, vector<int> f, vector<int> s) {
	if (idx == n) {
		if (f.empty() || s.empty()) return;
		int f_point = chk(f);
		int s_point = chk(s);
		int status = f_point > s_point ? f_point - s_point : s_point - f_point;
		if (ans > status) ans = status;
		return;
	}

	f.push_back(idx);
	go(idx + 1, f, s);
	f.pop_back();

	s.push_back(idx);
	go(idx + 1, f, s);
	s.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> point[i][j];
	vector<int> first;
	vector<int> second;
	go(0, first, second);
	cout << ans;
}