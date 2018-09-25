// ---
// 有$n$个数$(n \leq 100000,1 \le  a_i \le 10 ^ 6)$，问这$n$个数中互质的数的对数
// ---
const int maxn = "Edit";
int b[maxn];
ll solve(int n)
{
    ll ans = 0;
    for (int i = 0, x; i < n; i++) scanf("%d", &x), b[x]++;
    for (int i = 1; i < maxn; i++)
    {
        int cnt = 0;
        for (int j = i; j < maxn; j += i) cnt += b[j];
        ans += 1LL * mu[i] * cnt * cnt;
    }
    return (ans - b[1]) / 2;
}
// ---
// $\gcd(x,y)=1$的对数, $x \leq n, y \leq m$
// ---
ll solve(int n, int m)
{
    if (n > m) swap(n, m);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += (ll)mu[i] * (n / i) * (m / i);
    /* 
    数论分块写法(sum为莫比乌斯函数的前缀和)
    for (int i = 1; i <= n; i = pos + 1)
    {
        pos = min(n / (n / i), m / (m / i));
        ans += 1LL * (sum[pos] - sum[i - 1]) * (n / i) * (m / i);
    }
    */
    return ans;
}

