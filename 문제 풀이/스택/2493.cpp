/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.28
���� : ž - 2493
Ǯ�� : ������ 2�� ����ؼ� Ǫ�� ���� (�ϳ��� �ᵵ �ɰŰ����ϴ�)
       ù��° ���� = ž���� ����
	   �ι�° ���� = ���� ���� ������ ž�� ã�� ž���� ������ ��ġ

	   �� �ΰ����� ������ Ǯ�� �ȴ�.
	   �ι�° ������ �ٽ� �����̴�.
	   �ι�° ������ ������ stack<pair<int, int>> �μ�
	   first = ���� second = ��ġ �����̴�.

	   �� �ΰ����� ������ ���ο� ž�� ������ ������ �ش� ž�� ���̸�
	   ���� Ž������ ž���� ������ ���Ͽ� ���ο� ž�� ���̰� ��
	   ���� ���� �ι�° ������ pop�ذ��鼭 ���� ����ְ� �־��ش�.

	   �̷��� ���� �߰��Ͽ� ù��° ������ ��� �� ���� 
	   �ι�° ���ÿ��� ������ ���ߴٸ� �̴� ���� ������ ž�� ���ٴ� ���̱� ������
	   ��� 0�� �־��ָ� �ȴ�.
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	stack<int> arr;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push(tmp);
	}

	vector<int> ans(n + 1, 100);
	int idx = n;
	stack<pair<int, int>> srr;
	srr.push({ arr.top(), idx });
	arr.pop();
	while (!arr.empty()) {
		idx--;
		if (srr.top().first >= arr.top()) {
			srr.push({ arr.top(), idx });
			arr.pop();
		}
		else {

			while (!srr.empty()) {
				int now = srr.top().first;
				if (now >= arr.top()) break;
				ans[srr.top().second] = idx;
				srr.pop();
			}

			srr.push({ arr.top(), idx });
			arr.pop();
		}
	}

	while (!srr.empty()) {
		ans[srr.top().second] = 0;
		srr.pop();
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	
}