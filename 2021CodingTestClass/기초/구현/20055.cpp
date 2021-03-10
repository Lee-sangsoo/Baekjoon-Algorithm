/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.07
���� : �����̾� ��Ʈ ���� �κ� - 20055
Ǯ�� : ��������
       ���� ������ �ſ� �ָ��ϴ�...

	   �������� ���ϴ� �ܰ��
	   �����̾� ��Ʈ ��ĭ�� �̵��ϴ°��� 1�ܰ��̴�
	   (�� �ؼ��� �κ� �ϳ��� �������� 1�ܰ� �������� �˾Ҵ�...)

	   ������ �������� �־����� �ܰ踦 ������ ���󰡾� �Ѵ�.

	   ������ ��ĭ ȸ���� �켱�̸� �����ϸ� ȸ���� �켱�ȴ�.
	   �� �ܰ� �߰��߰���
	   �κ��� �������� ��ġ�� �� ���� �ƴ��� Ȯ���ؾ� �ϸ�
	   ���ο� ĭ���� �̵��� �� �κ��� �ִ��� �������� Ȯ���ؾ��Ѵ�.

	   ������ STL
	   vector<int> a
	   1. rotate(a.begin(), a.begin()+1, a.end());
	   2. rotate(a.rbegin(), a.rbegin()+1, a.rend());

	   1. ABCD -> BCDA
	   2. ABCD -> DABC

	   a.begin()���� a.begin()+1 ������ ������ a.end�� ������.
	   rend() = �ڿ��� ���� �� = ���� ��
*/
#include<iostream>
#include<deque>

using namespace std;

int n, k;
deque<int> dq;
deque<bool> chk;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	int zeroCnt = 0;
	int ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		int ai;
		cin >> ai;
		if (ai == 0) zeroCnt++;
		dq.push_back(ai);
		chk.push_back(false);
	}

	if (zeroCnt >= k) {
		cout << 1;
		return 0;
	}

	for(ans = 0; ; ans++) {
		// ��ĭ ȸ���Ѵ�.
		int bc = dq.back();
		dq.pop_back();
		dq.push_front(bc);

		bool bck = chk.back();
		chk.pop_back();
		chk.push_front(bck);

		// ��ĭ ȸ���ϰ� �ȴٸ� �κ��� �������� �ڸ��� �������ִ�.
		if (chk[n - 1]) {
			chk[n - 1] = false;
		}
		
		// �κ��� ��ĭ �̵�
		for (int i = n - 2; i >= 0; i--) {
			if (chk[i] && chk[i + 1] == false && dq[i + 1] > 0) {
				chk[i] = false;
				chk[i + 1] = true;
				dq[i + 1]--;
			}
		}

		if (chk[n - 1]) {
			chk[n - 1] = false;
		}

		// �κ��� ���ٸ� �κ��� �ø���.
		if (dq[0] > 0 && chk[0] == false) {
			dq[0]--;
			chk[0] = true;
		}

		int cnt = 0;
		for (int i = 0; i < 2 * n; i++)
			if (dq[i] <= 0) cnt++;
		zeroCnt = cnt;
		if (zeroCnt >= k) break;
	}

	cout << ans + 1;
}