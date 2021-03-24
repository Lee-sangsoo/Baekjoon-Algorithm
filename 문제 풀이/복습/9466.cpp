/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.24
���� : �� ������Ʈ - 9466
Ǯ�� : �ٸ� ��� ��� ����
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[100001];
bool chk[100001];
bool done[100001];
int cnt = 0;

void dfs(int x) {
	chk[x] = true;
	int nxt = arr[x];

	if (!chk[nxt]) dfs(nxt);
	else {
		if (!done[nxt]) {
			for (int i = nxt; i != x; i = arr[i])
				cnt++;
			cnt++;
		}
	}
	done[x] = true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			chk[i] = false;
			done[i] = false;
		}

		for (int i = 1; i <= n; i++) {
			if (done[i]) continue;
			dfs(i);
		}

		cout << n - cnt << '\n';
	}
}

/*
  // ���� ��������� �ƴ϶� ����Ŭ�� ���� ���θ� Ȯ���ϰ� �ʹٸ�?
  void dfs(int x){
	chk[x] = true;
	for(int i = 1; i<=n; i++){
		int nxt = arr[x];
		if(!chk[nxt]) dfs(nxt);
		else if(!done[nxt]){
			ok = true;
		}
	}
	done[x] = true;
  }

*/