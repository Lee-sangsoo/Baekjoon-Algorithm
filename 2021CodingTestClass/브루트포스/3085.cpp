/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.15
���� : ���� ���� - 3085
Ǯ�� : 2������ ������ �����ϸ� �ȴ�.
       1. ������ �ٲٴ� ����
	   2. �ִ�� �̾��� ������ ����

	   1�� ��쿡�� ��,��,��,�� �� ��� �� �ʿ䰡 ���� ��, �� �� Ȯ���ϸ� �ȴ�.
	   (������ �� ���� ������ Ȯ���� �ϱ� ������ �� �ʿ䰡 ����)
	   Ȯ���� ������ ���� ������ ��ġ�� ������� �ٲ��־�� �Ѵ�.

	   2�� ��� 1�� ���������� ��� ���� �˻��ϸ� �ȴ�.
	   �ٽ� ���� ��,��,��,�츦 ��� Ȯ���� �ʿ� ����
	   ��� ���� ����� Ȯ���ϸ� �ȴ�.

	   ������ N��
	   ���� N�� 
	   ������ Ȯ���� ���ְ� �� ���� return �ϸ� �ȴ�.

	   max���� �ٲ� ��, ���� 41���� else������ ���� �ٲ��־��ٸ�
	   for���� ������ ���� cnt�� �����ϴٰ� ���������� �����Ƿ�
	   �ѹ� �� max�� �����־�� �Ѵ�. (48��)

	   �Ʒ��� �ּ����� �ִ� �ڵ�� O(n^4) Ǯ���̴�.
	   ������, ������ ĭ�� ������ �ٲ��ִ� ���� �ᱹ �ִ� ������ ��ȭ��
	   �� 3���� ��� ���� ������ �ش�.
	   ��� ��츦 Ȯ���ϴ°��� �ð������� ���̴�.
	   �� ó�� 3���� �ุ Ȯ���ϴ� ���� O(n^3)�� ó�� �����ϴ�.

	   ��� �����ؾ� ���� �����ϴٸ� �� ���� ���̿� �׸����� �׷�����
	   (�ѹ��� ���صȴ�)
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<char>> candy;

int check(int a, int b, int c, int d) {
	int ret = 1;
	for (int i = a; i <= c; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) cnt++;
			else cnt = 1;
			ret = max(ret, cnt);
		}
	}

	for (int i = b; i <= d; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) cnt++;
			else cnt = 1;
			ret = max(ret, cnt);
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		vector<char> tmp;
		for (int i = 0; i < line.length(); i++)
			tmp.push_back(line[i]);
		candy.push_back(tmp);
	}

	int maxCandy = check(0,0,n-1,n-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(candy[i][j], candy[i][j + 1]);
				maxCandy = max(maxCandy, check(i,j,i,j+1));
				swap(candy[i][j], candy[i][j + 1]);
			}
			if (i + 1 < n) {
				swap(candy[i][j], candy[i + 1][j]);
				maxCandy = max(maxCandy, check(i,j,i+1,j));
				swap(candy[i][j], candy[i + 1][j]);
			}
		}
	}

	cout << maxCandy;
}

/*
int check() {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				cnt++;
			}
			else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
		cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) {
				cnt++;
			}
			else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
	}
	return ret;
}
*/