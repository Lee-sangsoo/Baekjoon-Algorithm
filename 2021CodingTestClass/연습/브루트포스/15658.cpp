/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : ������ �����ֱ� (2) - 15658
Ǯ�� : ������ �����ֱ� ���� �������� �����ڰ� �� �°� �־����°� �ƴ϶�
       N-1�� ���� ���� ������ �־��� ���� �ִ� �����̴�.

	   ������ �����ֱ� ���� ������ ũ�� �ٸ����� ������
	   ��͸� ����� ��� �ڵ� ��ü�� �Ȱ���.

	   ���� ������ �̿��Ұ�� 0�� 1�� �̿��Ͽ�
	   ���ԵǾ��ִ��� �ƴ��� Ȯ���� ���� 
	   �� �����ڸ� ����ϰ� ����ϸ� �ȴ�.
	   ( 0 0 0 0 1 1 1 1 2 2 2 2 3 3 3 3) -> (0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1)
	   (����Ͽ� 1�� ���Ե� ���� ������ ���)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[12];
vector<int> ans;

void go(int index, int cur, int plus, int minus, int mul, int div) {
	if (index == n) {
		ans.push_back(cur);
		return;
	}

	if (plus > 0) go(index + 1, cur + arr[index], plus - 1, minus, mul, div);
	if (minus > 0) go(index + 1, cur - arr[index], plus, minus - 1, mul, div);
	if (mul > 0) go(index + 1, cur * arr[index], plus, minus, mul - 1, div);
	if (div > 0) go(index + 1, cur / arr[index], plus, minus, mul, div - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int oper[4] = {};
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	go(1, arr[0], oper[0], oper[1], oper[2], oper[3]);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << '\n' << ans[0];
}