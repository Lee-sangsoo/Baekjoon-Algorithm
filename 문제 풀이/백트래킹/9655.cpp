/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.30
���� : 9655 - �� ����
Ǯ�� : ������ ���� ������� �ؼ� ������ ����ؼ� Ǯ��Ҵ�(�ּ� �ڵ�)
       ������, ������ Ǯ�ٺ��� N�� ¦����� ������ â���̰� �̱��
	   Ȧ����� ������ ����̰� �̱�� ��������.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	if (n % 2 == 1) cout << "SK";
	else cout << "CY";
}


/*
#include<iostream>
#include<algorithm>

using namespace std;

int n;
bool ans;
bool flag;

void bfs(int cnt, int cur) {
	if (cnt == n) {
		flag = true;
		if (cur % 2 != 0) ans = true;
		else ans = false;
		return;
	}
	if (cnt > n) return;
	if (flag) return;

	bfs(cnt + 3, cur + 1);
	bfs(cnt + 1, cur + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	bfs(0, 0);
	if (ans) cout << "SK";
	else cout << "CY";
}
*/