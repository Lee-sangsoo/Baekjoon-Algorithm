/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.03
���� : 12886 - �� �׷�
Ǯ�� : BFS�� ����Ͽ� Ǯ���� ���
       ������ Ǯ�̿� ũ�� �ٸ����� ����.
	   �켱 chk�迭�� �ִ� 1501��� (a, b, c <= 500�̱� ������ 500 499 500 �̶�� �����ϸ� �ִ� 1000�� ���´� ������ �˳��� ��´�)
	   �� ������ (a, b, c)��� �� �� �������� �� �� �ִ� ���� ��ġ�� (a+a, b-a, c), (a-b, b+b, c), ... �� �������� ���´�.
	   �̵��� ��� �����ϰ� a, b, c�� ��� ���� �� ���� �ݺ��ϸ� �Ǵµ�, �� ��� ������ �ٲ��� �ʱ� ������
	   �� ������ ������ �ΰ� ����� �ص� �ȴ�.
	   sum = x + y + z = (x+x) + (y-x) + c = x + (y + y) + (c - y) = ...

	   ������ ����� DFS�� ��� ��츦 Ȯ���ߴٸ�
	   �� ����� ���� �� �ִ�(Ž�� ������) ����� ���� ��� ����Ͽ� ����ϵ��� �Ѵ�.
	   �� ������ �ݺ��ϸ� x, y, z�� ��� ���� ��찡 ������ �� ��� 1�� �����ϰ�
	   ť�� ��� �� ������ ������ ������ 0�� �����Ѵ�.

	   ó�� Ǯ�̿� ũ�� �ٸ��� ����
	   �� ��츦 ��� Ǯ�� ������ �ݺ������� ó���ߴ��� �̴�.

	   ������ �ð��� �� ����� �ξ� ������
	   (�Ƹ��� ��� Ž���� ��ġ�� chk���� ���� Ȯ���ϴ� ����� ù��° ��Ŀ� ���ؼ� ��� ���� ���� ������ �� ��� Ž���� �����ϱ� ������ �� ������ ����)
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int sum;
bool chk[1501][1501];

int go(int a, int b, int c) {
	queue < pair<int, pair<int, int>>> q;
	q.push({ a, {b, c} });
	chk[a][b] = 1;
	chk[a][c] = 1;
	chk[b][c] = 1;
	chk[b][a] = 1;
	chk[c][a] = 1;
	chk[c][b] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second.first;
		int z = cur.second.second;
		if (x == y && y == z) return 1;
		if (x < y && !chk[x + x][y - x]) {
			q.push({ x + x, {y - x, z} });
			chk[x + x][y - x] = true;
		}
		if (x < z && !chk[x + x][z - x]) {
			q.push({ x + x, {y, z - x} });
			chk[x + x][z - x] = true;
		}
		if (y < z && !chk[y + y][z - y]) {
			q.push({ x, {y + y, z - y} });
			chk[y + y][z - y] = true;
		}
		if (y < x && !chk[y + y][x - y]) {
			q.push({ x - y, {y + y, z} });
			chk[x - y][y + y] = true;
		}
		if (z < x && !chk[z + z][x - z]) {
			q.push({ x - z, {y, z + z} });
			chk[x - z][z + z] = true;
		}
		if (z < y && !chk[z + z][y - z]) {
			q.push({ x, {y - z, z + z} });
			chk[z + z][y - z] = true;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	cout << go(a, b, c);
}