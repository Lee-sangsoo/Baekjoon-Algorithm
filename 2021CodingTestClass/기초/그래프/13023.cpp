/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.01
���� : ABCDE - 13023
Ǯ�� : �׷����� ģ�� ������ �����ϰ� dfs�� ���� ���̰� ������ �����ϴ� ���� ������
       �ùٸ� ����� ���ָ� �Ǵ� �����̴�.

	   �������� ����� ������, dfs�� ����� ���
	   ��Ʈ��ŷ�� ����ϰ� ó���ȴ�.

	   �ϳ��� �������� �����Ͽ� ����� �ٸ� ������� ����Ǿ� �� ��
	   �湮������ ���� ���鿡 ���� ������ �����ϰ� �� ������ �޾ƿͼ�
	   �˻��ϵ��� �Ѵ�. ������ ã�Ҵٸ�
	   answer�� �������� ����Ͽ� Ž���� ���� �����ϵ��� �Ѵ�. (�ð� ����)
	   
	   ���� ���� dfs�� ���Ѱ� ����. ������ �� �ʿ䰡 �ִ�.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> g[2001];
bool chk[2001];
bool answer;

void dfs(int x, int len) {
	if (len == 4) { // ģ�� ���� ������ 4���̸� �Ϸ�
		answer = true;
		return;
	}

	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i]; // y = x�� ����� ���
		// �湮�� ���� ���ٸ� �湮�Ͽ� Ž��
		if (!chk[y]) {
			chk[y] = true;
			dfs(y, len + 1);
			chk[y] = false;
		}
		if (answer) return; // �̹� ������ ã�Ҵٸ� Ž�� ����
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { // ó������ �����ϱ� ���� ��� �湮 ���� ����
			chk[j] = false;
		}
		chk[i] = true;
		dfs(i, 0); // i������ �����ϴ� dfs ����
		if (answer == true) break;
	}

	if (answer) cout << 1;
	else cout << 0;
}