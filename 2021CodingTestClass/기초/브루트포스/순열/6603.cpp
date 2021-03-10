/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.23
���� : �ζ� - 6603
Ǯ�� : �� ������ ��Ϳ� ������ �̿��Ͽ� Ǯ�̰� ������ ���Ʈ ���� �����̴�.
       �켱 ���Ұ��� �������ٴ� ��Ͱ� �� ���� ����̶�� �Ѵ�.

	   �Ʒ� �ּ� �ڵ�� ��͸� �̿��Ͽ� Ǭ �ڵ��̰�
	   ������ �ڵ�� ������ �̿��Ͽ� Ǭ �ڵ��̴�.

	   ������ �̿��Ͽ� Ǫ�� ����� 
	   N���� ���� �־��� �� 6���� �����Ͽ��� �ϱ� ������
	   N�� �� 6���� �����ߴٴ� ǥ�ø� �����
	   N - 6���� �������� �ʾҴٴ� ǥ�ø� ���ܼ� ����Ѵ�.

	   ������ ���ڴ� 1
	   �������� ���� ���ڴ� 0�� �ش�.

	   0�� 1�� �̷���� ���ͳ� �迭�� ������ ���� ó���ϰ�
	   1�� �κи� Ȯ���Ͽ� ���� ���� �־��ش�.
	   ���� �ְ� ������ ����� ���� ������ ���ְ� ������ָ� �ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		
		vector<int> num(n); // ����
		for (int i = 0; i < n; i++)
			cin >> num[i];

		vector<int> a; // �� = 1 ���� ���� = 0
		for (int i = 0; i < n - 6; i++)
			a.push_back(0);

		for (int i = 0; i < 6; i++)
			a.push_back(1); 

		vector<vector<int>> answer;
		do {
			vector<int> ans; // �� ���� ��� ����
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) ans.push_back(num[i]);
			}
			answer.push_back(ans);
		} while (next_permutation(a.begin(), a.end()));
		sort(answer.begin(), answer.end());
		for (auto v : answer) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}

/*
#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[14];
int num[14];

void go(int k, int st) {
	if (k == 6) {
		for (int i = 0; i < 6; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < n; i++) {
		arr[k] = num[i];
		go(k + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0) break;

		fill(arr, arr + 14, 0);
		fill(num, num + 14, 0);
		for (int i = 0; i < n; i++)
			cin >> num[i];

		go(0, 0);
		cout << '\n';
	}
}
*/

// �� �κ��� ó�� ������ �ݺ��ϰ��� �� �� �� �������� ������ִ� ����� �����ߴµ�,
// �� �ڵ带 ����ϸ� ���õ� ���ڸ� ������ ������ ���� �� ����ϱ� ������ ������ �ȴ�.
// ���� ��� �����ڸ� 1 2 3 4 5 6 7 �� ���ڰ� ���� ��
// 2 3 4 5 6 7 �� ���� ������
// 1 2 3 4 5 6 �� ���� ���ɼ��� �ִٴ� ���̴�.
/*
		do {
			vector<int> ans; // �� ���� ��� ����
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) ans.push_back(num[i]);
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << ' ';
			cout << '\n';
			answer.push_back(ans);
		} while (next_permutation(a.begin(), a.end()));
*/