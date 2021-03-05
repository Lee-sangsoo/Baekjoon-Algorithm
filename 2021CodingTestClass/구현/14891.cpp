/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.05
���� : ��Ϲ��� - 14891
Ǯ�� : ��������
       ���� ��ü�� �����ϸ� �����ϴµ� �־� ������ ���� ��� �ִ�.

	   ��Ϲ����� ��� �Ѳ����� ���ư��ٴ� ���� �߿��ϸ�
	   �̸� ���� chk �迭�� ����ߴ�.
	   chk[n] = 1 -> �ð� ���� / -1 -> �ݽð� ���� / 0 -> ȸ������ ����

	   �̸� ����Ͽ� [2]�� [6]�� ���ϰ� ([2] = �� [6] = ��)
	   ���ٸ� ���̻� ���� �����Ƿ� �� ���� ��� �������� ������ ���� �ʵ��� break
	   �ٸ��ٸ� ���� �� �� chk�� -1�� ���� ���� �־��ְ� �ݺ����� �̾��.

	   �̷��� ������ �ð���� ȸ��, �ݽð���� ȸ���� ��������ָ� �ȴ�.

	   ������ ������ �׻� �ſ� �߿��ϴ� (�� ����)
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int gear[4][8];
int k;

void turn_right(int arr[]) {
	int tmp = arr[7];
	for (int i = 7; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = tmp;
}

void turn_left(int arr[]) {
	int tmp = arr[0];
	for (int i = 0; i < 7; i++)
		arr[i] = arr[i + 1];
	arr[7] = tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			gear[i][j] = s[j] - '0';
	}

	cin >> k;
	while (k--) {
		int num, lr;
		cin >> num >> lr;

		int chk[4];
		for (int i = 0; i < 4; i++) chk[i] = 0;

		if (num == 1) {
			chk[0] = lr;
			for (int i = 0; i < 3; i++) {
				if (gear[i][2] == gear[i + 1][6]) break;
				else chk[i + 1] = chk[i] * -1;
			}
		}

		else if (num == 2) {
			chk[1] = lr;
			if (gear[0][2] != gear[1][6]) chk[0] = chk[1] * -1;

			for (int i = 1; i < 3; i++) {
				if (gear[i][2] == gear[i + 1][6]) break;
				else chk[i + 1] = chk[i] * -1;
			}
		}

		else if (num == 3) {
			chk[2] = lr;
			for (int i = 2; i > 0; i--) {
				if (gear[i][6] == gear[i - 1][2]) break;
				else chk[i - 1] = chk[i] * -1;
			}
			
			if (gear[2][2] != gear[3][6]) chk[3] = chk[2] * -1;
		}

		else {
			chk[3] = lr;
			for (int i = 3; i > 0; i--) {
				if (gear[i][6] == gear[i - 1][2]) break;
				else chk[i - 1] = chk[i] * -1;
			}
		}


		for (int i = 0; i < 4; i++) {
			if (chk[i] == 1) turn_right(gear[i]);
			else if (chk[i] == -1) turn_left(gear[i]);
		}
	}

	int ans = 0;
	int point = 1;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) ans += point;
		point *= 2;
	}

	cout << ans;
}



// Ȯ�ο� ��� �ڵ�
/*
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++)
				cout << gear[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
		cout << gear[0][6] << ' ' << gear[0][2] << '|' << gear[1][6] << ' ' << gear[1][2] << '|' << gear[2][6] << ' ' << gear[2][2] << '|' << gear[3][6] << ' ' << gear[3][2] << '\n';
		cout << num << "��° ��� ���� ";
		if (lr == 1) cout << "���������� ȸ�� \n";
		else cout << "�������� ȸ�� \n";
		cout << '\n';
*/