#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
int n, a[1010], b[1010];
void merge(int a[], int le, int mid, int ri) {
	int i = le, j = mid + 1, k = le;
	while (i != mid + 1 && j != ri + 1) {
		if (a[i] >= a[j])	b[k++] = a[j++];
		else	b[k++] = a[i++];
	}
	while (i != mid + 1)	b[k++] = a[i++];
	while (j != ri + 1)		b[k++] = a[j++];
	for (i = le; i <= ri; i++)	a[i] = b[i];
}
void mergesort(int a[], int le, int ri) {
	int mid;
	if (le < ri) {
		mid = (le + ri) / 2;
		mergesort(a, le, mid);
		mergesort(a, mid + 1, ri);
		merge(a, le, mid, ri);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	mergesort(a, 1, n);
	for (int i = 1; i <= n; i++)	printf("%d ", a[i]);
}

