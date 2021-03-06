#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
int n, m, match, ans = 0, a, b;
int mp[1010][1010], se[1010];
bool check(int t) {
    for (int i = 1; i <= n; ++i) {
        if (mp[t][i] && se[i] == se[t])    return 0;
    }
    return 1;
}
void back(int t) {
    if (t > n) {
        ans++;
        for (int i = 1; i <= n; ++i)    printf("%d ", se[i]);
        printf("\n");
    }
    else {
        for (int i = 1; i <= m; ++i) {
            se[t] = i;
            if (check(t))    back(t + 1);
            se[t] = 0;
        }
    }
}
int main() {
    scanf("%d %d %d", &m, &n, &match);
    for (int i = 1; i <= match; ++i) {
        scanf("%d %d", &a, &b);
        mp[a][b] = mp[b][a] = 1;
    }
    back(1);
    if (ans > 0)   printf("%d", ans);
    else    printf("NO");
}

