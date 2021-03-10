/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : ������ �����ֱ� - 14888
Ǯ�� : ���ڴ� ������ �ʰ� �������� ������ �ٲ�� ������
       �������� ������ �����ְ� ������ �����ָ� �ȴ�.

	   next_permutation�� ����Ͽ� Ǯ������
	   ��� ���Ʈ������ ���� Ǯ ���� �ִ�.
	   (��ͷ� �ϴ� ����� �� ������)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[12];
vector<int> oper;
vector<int> ans;

void go(int index, int cur, int plus, int minus, int mul, int div) {
	// index = ���� ����ؾ� �ϴ� �ε���	cur = index-1��°���� ����� ���
	// plus, minus, mul, div = �� �����ں� ��� ������ Ƚ��

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

	vector<int> opernum(4);
	for (int i = 0; i < 4; i++)
		cin >> opernum[i];

	/*
	for (int i = 0; i < opernum.size(); i++) {
		for (int j = 0; j < opernum[i]; j++) {
			oper.push_back(i);
		}
	}

	do {
		int now = arr[0];
		for (int i = 1; i < n; i++) {
			if (oper[i - 1] == 0) {
				now = now + arr[i];
			}
			else if (oper[i - 1] == 1) {
				now = now - arr[i];
			}
			else if (oper[i - 1] == 2) {
				now = now * arr[i];
			}
			else {
				if (now < 0) {
					now *= -1;
					now = now / arr[i];
					now *= -1;
				}
				else {
					now = now / arr[i];
				}
			}
		}
		ans.push_back(now);
	} while (next_permutation(oper.begin(), oper.end()));
	*/

	go(1, arr[0], opernum[0], opernum[1], opernum[2], opernum[3]);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << '\n' << ans[0];
}