#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int n, m;
int dp[1010][1010], ans[1010][1010], f[1010][1010];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &f[j][i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= j; k++) {
				if (dp[i][j] < dp[i - 1][j - k] + f[i][k]) {
					dp[i][j] = dp[i - 1][j - k] + f[i][k];
					ans[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d %d ", dp[j][i], ans[j][i]);
		}
		printf("\n");
	}
}

