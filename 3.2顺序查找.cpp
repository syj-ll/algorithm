#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
int n, a[10010], x, i, j;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	j = 0;
	for (i = 1; i <= n; i++) {
		if (x == a[i]) {
			j = i;
			break;
		}
	}
	printf("%d", j);
}

