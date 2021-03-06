#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int d[110][110], n, m;
int main() {
	scanf("%d %d", &n, &m);
	memset(d, inf, sizeof(d));
	for (int i = 1; i <= n; i++)	d[i][i] = 0;
	while (m--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		d[x][y] = min(d[x][y], z);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d -> %d : %d\n", i, j, d[i][j]);
		}
	}
}

