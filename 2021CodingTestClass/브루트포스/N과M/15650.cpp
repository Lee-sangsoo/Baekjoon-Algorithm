/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : N�� M (2) - 15650
Ǯ�� : ���� N�� M (1) �ڵ忡�� �Լ��� ���ڷ� �����ϴ� ����
	   �ϳ��� �þ��� �� ���� ������ 
	   1 ~ N �ݺ��̴����� 
	   ���� ���ð� + 1 ~ N ������ �ٲ����.
	   �� ���� ���� �ݺ����� �����ϸ� �� ������ �����´�.

	   �����δ� �� �ڵ忡���� ��� ���θ� Ȯ���ϴ� chk�迭�� ���ǹ� �κ��� �ʿ����.
	   �ֳ��ϸ� ������ ���� �˻��ϴ� �κ��� ���� ���� ���� ������ �˻��ϱ� �����̴�.
*/
#include<iostream>

using namespace std;

int n, m;
int arr[9];
bool chk[9];

// ���� Ǯ���� ���Ʈ ����
void bf_other(int k, int st) {
	if (k == m) {
		for (int i = 0; i < k; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		arr[k] = i;
		bf_other(k + 1, i + 1);
		chk[i] = false;
	}
}

// �������� Ǯ���� ���Ʈ ����
void bf_select(int num, int select) { // index = ���� ��, select = ������ ���� ����
	if (select == m) { // ������ �����ٸ� (m���� ����ٸ�) ���
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	if (num > n) return; // ������ ��ġ�� ���ߴµ� ���� n�� �Ѿ�ٸ� ���̻� ���� ���ٴ� ���̹Ƿ� ����
	arr[select] = num; // �� ����
	bf_select(num + 1, select + 1); // ���� + 1(���� ��), ���� ���� + 1
	arr[select] = 0; // �� ���� X
	bf_select(num + 1, select); // ���� + 1, ���� ���� ����
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	bf_other(0, 1);
}