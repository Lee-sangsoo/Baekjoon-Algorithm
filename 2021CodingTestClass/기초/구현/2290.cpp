/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.07
���� : LCD Test - 2290
Ǯ�� : ��������
       �� ���ڸ� ���÷��̿� ��Ÿ���ٰ� �� ��
	   �� �κ��� ���ڷ� ��Ÿ���� ǥ�õǴ� ������ �����.
	   �׷��� �ϰ���
	   ��� -> ���� -> ��� -> �ߴ� -> ���� -> �Ͽ� -> �ϴ� ������ ��µ��� �� �� �ִ�.

	   �̿� ���� �� ���ڰ� �ش� �κ��� ǥ�õǴ����� ��Ÿ���� num �迭�� ����Ͽ�
	   ������ ������ �ְ� 
	   ǥ���ؾ� �ϴ� ���ڸ� ����s�� �°� ����� |, - �� �־�� Ǯ���ϸ� �ȴ�.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int s;
	string n;
	cin >> s >> n;

	bool num[10][7] = { {1,1,1,0,1,1,1}, // 0
						{0,0,1,0,0,1,0}, // 1
						{1,0,1,1,1,0,1}, // 2
						{1,0,1,1,0,1,1}, // 3
						{0,1,1,1,0,1,0}, // 4
						{1,1,0,1,0,1,1}, // 5
						{1,1,0,1,1,1,1}, // 6
						{1,0,1,0,0,1,0}, // 7
						{1,1,1,1,1,1,1}, // 8
						{1,1,1,1,0,1,1}  // 9 
	};
	
	vector<int> numbers;
	for (int i = 0; i < n.length(); i++) {
		int num = n[i] - '0';
		numbers.push_back(num);
	}

	// 0��° (��� ���)
	for (int i = 0; i < numbers.size(); i++) {
		cout << ' ';
		for (int j = 0; j < s; j++) {
			if (num[numbers[i]][0] == 1) cout << '-';
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << '\n';

	// 1, 2��° (��� ��, ��� �� ���)
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < numbers.size(); i++) {
			if (num[numbers[i]][1] == 1) cout << '|';
			else cout << ' ';

			for (int k = 0; k < s; k++) cout << ' ';

			if (num[numbers[i]][2] == 1) cout << '|';
			else cout << ' ';

			cout << ' ';
		}
		cout << '\n';
	}

	// 3��° (�ߴ� ���)
	for (int i = 0; i < numbers.size(); i++) {
		cout << ' ';
		for (int j = 0; j < s; j++) {
			if (num[numbers[i]][3] == 1) cout << '-';
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << '\n';

	// 4, 5��° (�ϴ� ��, �ϴ� �� ���)
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < numbers.size(); i++) {
			if (num[numbers[i]][4] == 1) cout << '|';
			else cout << ' ';

			for (int k = 0; k < s; k++) cout << ' ';

			if (num[numbers[i]][5] == 1) cout << '|';
			else cout << ' ';

			cout << ' ';
		}
		cout << '\n';
	}

	// 6��° (�ϴ� ���)
	for (int i = 0; i < numbers.size(); i++) {
		cout << ' ';
		for (int j = 0; j < s; j++) {
			if (num[numbers[i]][6] == 1) cout << '-';
			else cout << ' ';
		}
		cout << "  ";
	}
	cout << '\n';
}