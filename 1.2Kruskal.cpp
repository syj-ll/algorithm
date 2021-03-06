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
struct node {
	int x, y, z;
}edge[500010];
int fa[100010], n, m, ans;
int get(int x) {
	if (x == fa[x])	return x;
	return fa[x] = get(fa[x]);
}
bool cmp(node p, node q) {
	return p.z < q.z;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z);
	}
	sort(edge + 1, edge + m + 1, cmp);
	for (int i = 1; i <= n; i++)	fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int fx = get(edge[i].x);
		int fy = get(edge[i].y);
		if (fx == fy)	continue;
		fa[fx] = fy;
		ans += edge[i].z;
	}
	printf("%d", ans);
}

