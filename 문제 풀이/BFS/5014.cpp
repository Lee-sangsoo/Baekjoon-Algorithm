/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.29
���� : ��ŸƮ��ũ - 5014
Ǯ�� : BFSŽ�� �����̴�.
       1���� ���������� BFSŽ�� �������� �ſ� ������ �����̴�.

	   ������, ������ BFS �ڵ� �ۼ� ����� �� ���������� �ùٸ��� �۵����� �ʴ´�.

	   ��� �ۼ� ����� �ڵ尡 �������� ������ continue�� ���� �ݺ����� �����ϴ� ����̿���.
	   �� ����� ��, ��, ��, �� 4���� ���⿡ ���ؼ� �ϳ��� �ݺ����� ���� �����ϸ�
	   �� �ݺ��� �ȿ��� continue�� �����ϱ� ������ ������ ���� �ʾ�����

	   �� ������ ��� U�� D�� ���� ���� �迭�� ������ �ʾұ� ������
	   �������� ������ continue�� �ϰ� �Ǹ� ���� �̵��� Ȯ���ϰ� �Ѿ ���ɼ��� �����.

	   �̴� �߸��� ����̸� �̸� �����ϱ� ����
	   ������ ������ �� ť�� ���ο� ��ǥ�� �ִ� ����� ����ϸ� �ذ�ȴ�.
*/
#include<iostream>
#include<queue>

using namespace std;

int f, s, g, u, d;
int arr[1000001];
int chk[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> f >> s >> g >> u >> d;

	queue<int> q;
	q.push(s);
	chk[s] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		int nxtUp = x + u;
		int nxtDown = x - d;

		if (nxtUp > 0 && nxtUp <= f && chk[nxtUp] == false) {
			q.push(nxtUp);
			chk[nxtUp] = chk[x] + 1;
		}
		
		if (nxtDown > 0 && nxtDown <= f && chk[nxtDown] == false) {
			q.push(nxtDown);
			chk[nxtDown] = chk[x] + 1;
		}
		
	}

	if (chk[g] == 0) cout << "use the stairs";
	else cout << chk[g] - 1;
}