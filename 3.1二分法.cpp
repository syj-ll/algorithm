#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
int n, a[10010], x, i;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	int le, ri, mid;
	le = 1, ri = n;
	while (le <= ri) {
		mid = (le + ri) / 2;
		if (a[mid] < x)	le = mid + 1;
		else	ri = mid - 1;
	}
	if (a[le] == x)	printf("%d", le);
	else	printf("0");
}

