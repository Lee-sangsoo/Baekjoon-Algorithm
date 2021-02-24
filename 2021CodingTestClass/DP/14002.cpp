/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.24
���� : ���� �� �����ϴ� �κ� ���� 4 - 14002
Ǯ�� : ���� �� �����ϴ� �κ� ���� ������ �ٸ� ���� �� ������ ���������� ����ϴ� �����̴�.
       ��, LIS�� ����ϴ� �����̴�.
	   
	   �������� ������ �ְ�����, ���� Ǭ �����
	   ���ͽ�Ʈ�� �˰����� ���ã��� ����ϰ� Ǯ����.

	   pre[N] = N��° ���� �� ��, �ش� �������� N��° �� ������ �� ���� ��Ƶд�.
	   �� ���� ��Ƶΰ� ���߿� ���� �ε����� �˾Ƴ���
	   �� ��θ� ��� ��� reverse ���ָ� �ȴ�.
	   ��, pre[n] = a[n] �տ� �;� �ϴ� ���� �ε��� 
	   ������ ���ָ� �ȴ�.

	   LIS�� ���� = D[1], ... , D[N]�� �ִ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int d[1001];
int a[1001];
int pre[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		int maxCnt = 0;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && maxCnt < d[j]) {
				maxCnt = d[j];
				pre[i] = j;
			}
		}
		d[i] = maxCnt + 1;
	}

	int ans = 0, idx = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			idx = i;
		}
	}

	vector<int> path;
	while (pre[idx] != 0) {
		path.push_back(idx);
		idx = pre[idx];
	}
	path.push_back(idx);

	cout << ans << '\n';
	reverse(path.begin(), path.end());
	for (auto i : path)
		cout << a[i] << ' ';
}