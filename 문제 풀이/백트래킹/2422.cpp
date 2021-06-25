/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.23
���� : 2422 - �������� ��Ż���ƿ� ���� ���̽�ũ���� ��Դµ�
Ǯ�� : ���� ����. 
       ��� ������ �ȵǴ� �͵��� ������ M�� �ִµ� �� M���� 10000���̱� ������ �� ������ �׻�
	   Ž���� �ϱ⿡�� �ʹ� ���� �ð��� �ɸ���. �׷��� ������
	   bool chk[a][b] => ���� true�̸� a�� b�� ������ �ȵȴ�.
	   �� ���� �����Ͽ� �ѹ��� Ž���ϵ��� �Ѵ�.
	   �� �ܿ��� �� ������ ������ ���ϰ� 
	   �� 3���� ���̽�ũ���� ������ ������ ���踦 �ľ��ϱ� ����
	   01, 02
	   10, 12
	   20, 21 
	   �� ���踦 �ľ��Ͽ� �� �߿� �ϳ��� true�� �ִٸ� ī��Ʈ�� ������Ű�� �ʵ��� �Ѵ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n, m, ans = 0;
bool chk[201][201];
int sel[3];

void go(int nxt, int cnt) {
	if (cnt == 3) {
		if (chk[sel[0]][sel[1]] || chk[sel[0]][sel[2]]) return;
		if (chk[sel[1]][sel[0]] || chk[sel[1]][sel[2]]) return;
		if (chk[sel[2]][sel[0]] || chk[sel[2]][sel[1]]) return;
		ans++;
		return;
	}

	for (int i = nxt; i <= n; i++) {
		sel[cnt] = i;
		go(i + 1, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		chk[a][b] = true;
	}
	go(1, 0);
	cout << ans;
}