#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int a[1010][1010], dist[1010], n, m, ans;
bool vis[1010];
void prim() {
	memset(dist, inf, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		int x = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (x == 0 || dist[j] < dist[x]))	x = j;
		}
		vis[x] = 1;
		for (int y = 1; y <= n; y++) {
			if (!vis[y])	dist[y] = min(dist[y], a[x][y]);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	memset(a, inf, sizeof(a));
	for (int i = 1; i <= n; i++)	a[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[y][x] = a[x][y] = min(a[x][y], z);
	}
	prim();
	for (int i = 2; i <= n; i++)	ans += dist[i];
	printf("%d", ans);
}

