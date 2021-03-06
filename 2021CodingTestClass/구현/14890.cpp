/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.06
���� : ���� - 14890
Ǯ�� : ��������
       
	   �����ؾ� �ϴ� ��
	   1. ������ ĭ�� ���̰� �ٸ� �� ���� ���� 
	   2. ������ ĭ�� ���̰� �ٸ� �� ���̰� L�� ���θ� ���� �� �ִ���
	   3. �̹� ���ΰ� ���������� �ƴ���

	   �� 3������ ���� ����� ���� go�Լ��� �� �κ��̴�.
	   ���� ���̰� 1�� �Ѵ��� Ȯ�����ְ�

	   ����ĭ�� �� ���� ��� �� �� ���� ��츦 ���Ͽ� �����ϸ� �Ǹ�

	   ���� �˻��ϴ� ���ǿ��� �������� ���ϴ� ������ ���´ٸ� 
	   �̴� ������������ ���� �ȴ�.
	   �ֳ��ϸ�, ���� �˻��ϴ� ���� ���� ���̰� ���� ���� ���̴� �̵����� ���ϴµ�
	   ������ �������� ���ϸ� ���θ� ���� ���ϱ� �����̴�.

	   �� ������ �����ϴ� ������ ���ָ� �ȴ�.

	   ��Ȳ 1. p[i] > p[i - 1]
	       ��
	   ��  ��
	   i-1  i

	   ��Ȳ 2. p[i] < p[i - 1]
	   ��
	   ��  ��
	   i-1  i
*/
#include<iostream>
#include<vector>

using namespace std;

int n, l;
vector<vector<int>> path;
int arr[101][101];

bool go(vector<int> p) {
	vector<bool> chk(n, false);

	for (int i = 1; i < n; i++) {
		if (p[i - 1] != p[i]) {
			int diff = p[i] > p[i - 1] ? p[i] - p[i - 1] : p[i - 1] - p[i];
			if (diff > 1) return false;
		}
		if (p[i] > p[i - 1]) {
			for (int j = 1; j <= l; j++) {
				if (i - j < 0) return false;
				if (p[i - j] != p[i - 1]) return false;
				if (chk[i - j]) return false;
				chk[i - j] = true;
			}

		}
		else if (p[i] < p[i - 1]) {
			for (int j = 0; j < l; j++) {
				if (i + j >= n) return false;
				if (p[i + j] != p[i]) return false;
				if (chk[i + j]) return false;
				chk[i + j] = true;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++)
			tmp.push_back(arr[i][j]);
		path.push_back(tmp);
	}

	for (int j = 0; j < n; j++) {
		vector<int> tmp;
		for (int i = 0; i < n; i++)
			tmp.push_back(arr[i][j]);
		path.push_back(tmp);
	}

	int ans = 0;
	for (int i = 0; i < path.size(); i++) {
		if (go(path[i])) ans++;
	}

	cout << ans;
}