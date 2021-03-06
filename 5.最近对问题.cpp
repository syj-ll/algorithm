#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
typedef long long ll;
using namespace std;
struct point {
	double x, y;
}a[100010],b[100010];
bool cmp1(point p, point q) {
	return p.x < q.x;
}
bool cmp2(point p, point q) {
	return p.y < q.y;
}
double dis(point p, point q) {
	double ans = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
	return ans;
}
double closest(int le, int ri) {
	if (ri - le + 1 == 2)	return dis(a[le], a[ri]);
	if (ri - le + 1 == 3)	return min(dis(a[le], a[le + 1]), min(dis(a[le + 1], a[ri]), dis(a[le], a[ri])));
	int mid = (le + ri) / 2;
	double ans = min(closest(le, mid), closest(mid + 1, ri));
	int f = 0;
	for (int i = le; i <= ri; i++) {
		if (fabs(a[i].x - a[mid].x) <= ans) {
			f++; b[f] = a[i];
		}
	}
	sort(b + 1, b + f + 1, cmp2);
	for (int i = 1; i <= f; i++) {
		for (int j = i + 1; j <= f && j < i + 6; j++) {
			ans = min(ans, dis(b[i], b[j]));
		}
	}
	return ans;
}
int n;
double ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	scanf("%lf %lf", &a[i].x, &a[i].y);
	sort(a + 1, a + 1 + n, cmp1);
	ans = closest(1, n);
	printf("%f", ans);
}

