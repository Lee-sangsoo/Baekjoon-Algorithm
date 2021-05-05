/*
�ۼ��� : �̻��
�Ͻ� : 2021.05.05
���� : ���� ���� - 11060
Ǯ�� : 1���� �迭 �ȿ��� A[i] ������ �ǳʶٱ⸦ ���� A[N]���� ���� �ּ� �̵� Ƚ���� ã�� ����
       DP�� �̿��Ͽ� Ǯ���ϸ� �ȴ�.

	   DP[N] = N��° ��ġ�� ���µ� �ɸ��� �ּ� ���� Ƚ��
	   ��� �Ѵٸ� 
	   DP[N] = MIN(DP[n-1] + 1, DP[n-2] + 1, DP[n-3] + 1, ... DP[n - arr[n]]) ���� �� �� �ִ�.
	   ���� Ž���� �����ϸ鼭 N�� �ִ�� 1000�̰� arr[n]�� �ִ�� 100�̱� ������
	   ��� Ž���� �����Ͽ��� 100,000���� ����� �ð��ȿ� �ذ��� �����ϴ�.

	   ���ǹ��� Ȯ���� �� �ϰ� ��������
	   1. if (cnt[i] == -1) continue; -> ó�� �ݺ����� �� �� ���� ���� Ž���� ��� Ž������ �ʵ��� �Ѵ�.
	   2. if (cnt[i + j] != -1) continue; -> �̹� Ž���� �����ߴٴ� ���� �� �ּ��� ��찡 �ִٴ� ���̱� ������ Ž���� �������� �ʴ´�.
*/
#include<iostream>

using namespace std;

int n;
int arr[1001];
int cnt[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[i] = -1;
	}
	cnt[1] = 0;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == -1) continue;
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j > n) break;
			if (cnt[i + j] != -1) continue;
			cnt[i + j] = cnt[i] + 1;
		}
	}

	cout << cnt[n];
}