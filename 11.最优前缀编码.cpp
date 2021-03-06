#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
priority_queue<ll, vector<ll>, greater<ll> >q;
ll n, ans = 0, t, x, y;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t);
        q.push(t);
    }
    while (!q.empty()) {
        x = q.top();
        q.pop();
        if (q.empty())  break;
        y = q.top();
        q.pop();
        ans += x + y;
        q.push(x + y);
    }
    printf("%lld", ans);
}

