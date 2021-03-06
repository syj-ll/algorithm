#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;
typedef long long ll;
int n, k, a[10010], ans;
void insort(int a[], int le, int ri) {
    int temp, j;
    for (int i = le + 1; i <= ri; i++) {
        temp = a[i];
        for (j = i - 1; j >= le && temp < a[j]; j--)   a[j + 1] = a[j];
        a[j + 1] = temp;
    }
}
int partition(int le, int ri, int zhong) {
    int t, i = le - 1, j, temp;
    for (j = le; j < ri; j++) {
        if (a[j] == zhong)  swap(a[j], a[ri]);
    }
    t = a[ri];
    for (j = le; j < ri; j++) {
        if (a[j] <= t) {
            i++; swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[ri]);
    return i + 1;
}
int select(int le, int ri, int k) {
    if (ri - le + 1 <= 5) {
        insort(a, le, ri);
        return a[le + k - 1];
    }
    int f = (ri - le + 1 + 5) / 5;
    int left, right, mid;
    for (int i = 0; i < f; i++) {
        left = le + 5 * i;
        right = min(ri, le + 5 * i + 4);
        mid = (left + right) / 2;
        insort(a, left, right);
        swap(a[le + i], a[mid]);
    }
    int zhong = select(le, le + f - 1, (f + 1) / 2);
    int zz = partition(le, ri, zhong);
    int ln = zz - le;
    if (k == ln + 1)    return a[zz];
    else if (k <= ln)    return select(le, zz - 1, k);
    return select(zz + 1, ri, k - ln - 1);
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
    ans = select(0, n - 1, k);
	printf("%d", ans);
}

