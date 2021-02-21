/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.21
���� : �ε�ȣ - 2529
Ǯ�� : �ִ� 10���� ���ڸ� 10�ڸ��� �ִ� �����
       10! = 3628800 �̹Ƿ� ���Ʈ������ ����� �����ϴ�.

	   ������ Ǯ�̴� ���Ʈ������ �ι��̳� ���� ������ (�ִ� �ּҸ� ���� �����Ͽ�)
	   ���� ������ �� Ŀ���� ������ �ȴ�. (�Ʒ� �ּ�ó���� �ڵ�)

	   �̸� �ذ��ϱ� ���ؼ� �ѹ��� ���Ʈ���� �ȿ� 0���� 9������ ���ڸ� üũ�ϴ� ���� �˸� �ȴ�.
	   ���� ��ģ �κ��� go �Լ����� �ݺ����� �� ��, 0 ~ n+1������ ó���� �ع��ȴµ�
	   �̷��� �Ǹ� ���� ������ n���� ���� ������ ������ �ȴ�.
	   �̸� �����ϱ� ���� �� �ڵ��� goó�� 0 ~ 10 ���� ó���ϸ� �ȴ�.

	   �� �ڵ�� ������ �迭�� ���� �־�ΰ� ���� �����ͼ�
	   to_string �Լ��� �Ź� ����ϴµ� �̷��� �Ǹ� �ð��� �� ���� �ɸ���.

	   go�� ó������ �� ���ڿ��� �Ѱ��־� ���ڿ��� �������� ó���ϸ�
	   �� ������ �����ϰ� ó�� �����ϴ�.

	   ���⼭ �� ������ ó���ϰ� �ʹٸ�,
	   �ݺ����� �� ��, chk[i]�� true�� �� �ǳʶٴ°� �ƴ϶�
	   ���� ����Ǿ� �ִ� ������ ���ڿ� �̹��� ���� ���ڸ� �ε�ȣ�� �̸� ���Ͽ�
	   �̸� ������ ���� ó���ϵ��� �ϸ� �ȴ�.

	   �ٽø��� good(char x, char y, char op) ��� �Լ��� ���� ��,
	   x = ����1 y = ����2 op = �ε�ȣ �� �� �̸� �̿��Ͽ�
	   �ݺ����� 0 ~ 9 ���� ���ڸ� ���� ����� ���ڵ�� ���Ͽ� 
	   �� �Լ��� ���� ���� ���� ����ְ� ��͸� �ݺ��ϵ��� �ϸ� �ȴ�.
	   (��û �������� 198ms -> 12ms   �ſ� �������� ������ ��Ʈ��ŷ�� ������ ����)
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<char> sign;
bool chk[10];
int num[10];
int num2[10];
int n;
string min_ans = "", max_ans = "";

bool chk_sign() {
	for (int i = 1; i < n + 1; i++) {
		if (sign[i - 1] == '<') {
			if (num[i - 1] > num[i]) return false;
		}
		else {
			if (num[i - 1] < num[i]) return false;
		}
	}
	return true;
}

string ret_str() {
	string tmp = "";
	for (int i = 0; i < n + 1; i++)
		tmp += to_string(num[i]);
	return tmp;
}

void go(int k) {
	if (k == n + 1) {
		if (chk_sign()) {
			string tmp = ret_str();
			if (min_ans == "") min_ans = tmp;
			else {
				if (min_ans > tmp) min_ans = tmp;
			}
			if (max_ans == "") max_ans = tmp;
			else {
				if (max_ans < tmp) max_ans = tmp;
			}
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		num[k] = i;
		go(k + 1);
		chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		sign.push_back(c);
	}

	go(0);
	//go_max(0);
	cout << max_ans << '\n' << min_ans;
}


// ��� �ڵ�
/*
bool chk_sign2() {
	for (int i = 1; i < n + 1; i++) {
		if (sign[i - 1] == '<') {
			if (num2[i - 1] > num2[i]) return false;
		}
		else {
			if (num2[i - 1] < num2[i]) return false;
		}
	}
	return true;
}

string ret_str2() {
	string tmp = "";
	for (int i = 0; i < n + 1; i++)
		tmp += to_string(num2[i]);
	return tmp;
}




void go(int k) {
	if (k == n + 1) {
		if (chk_sign()) {
			string tmp = ret_str();
			if (min_ans == "") min_ans = tmp;
			else {
				if (min_ans > tmp) min_ans = tmp;
			}
		}
		return;
	}

	for (int i = 0; i < n + 1; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		num[k] = i;
		go(k + 1);
		chk[i] = false;
	}
}



void go_max(int k) {
	if (k == n + 1) {
		if (chk_sign2()) {
			string tmp = ret_str2();
			if (max_ans == "") max_ans = tmp;
			else {
				if (max_ans < tmp) max_ans = tmp;
			}

		}
		return;
	}

	for (int i = 9; i > 9 - n - 1; i--) {
		if (chk[i]) continue;
		chk[i] = true;
		num2[k] = i;
		go_max(k + 1);
		chk[i] = false;
	}
}
*/