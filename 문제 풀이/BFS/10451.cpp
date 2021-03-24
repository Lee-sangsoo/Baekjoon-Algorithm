/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.24
���� : ���� ����Ŭ - 10451
Ǯ�� : DFS�� ����Ͽ� ����Ŭ�� ������ ���ϴ� ����
       �־����� �Է��� ��� ������ �����ϴ� ���� ����Ŭ�̸�
	   �� ������ ����Ŭ�� �ƴ� ���� �־����� �����Ƿ� ���� ����� �ʿ� ����
	   �湮�ÿ� �̹� �湮�� ��带 ��湮 �ϴ����� Ȯ�� ���ָ� �ȴ�.

	   �� dfs Ž�� Ƚ���� ������ָ� �ȴ�.
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[1001];
bool chk[1001];

void dfs(int x) {
	if (chk[x]) return;

	chk[x] = true;
	dfs(arr[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			chk[i] = false;
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (chk[i]) continue;
			cnt++;
			dfs(i);
		}

		cout << cnt << '\n';
	}
}