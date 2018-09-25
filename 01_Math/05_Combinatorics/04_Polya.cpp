// ---
// 推论：一共$n$个置换，第$i$个置换的循环节个数为$gcd(i,n)$\\
// $N*N$的正方形格子，$c^{n^2}+2c^{\frac{n^2+3}{4}}+c^{\frac{n^2+1}{2}}+2c^{n\frac{n+1}{2}}+2c^{\frac{n(n+1)}{2}}$\\
// 正六面体，$\frac{m^8+17m^4+6m^2}{24}$
// 正四面体，$\frac{m^4+11m^2}{12}$\\
// ---
// ---
// 长度为$n$的项链串用$c$种颜色染
// $\sum_{d|n} \frac{\varphi(n / d) c ^ d}{n}$
// ---
ll solve(int c, int n)
{
    if (n == 0) return 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += Pow(c, __gcd(i, n));
    if (n & 1) ans += n * Pow(c, n + 1 >> 1);
    else ans += n / 2 * (1 + c) * Pow(c, n >> 1);
    return ans / n / 2;
}
// ---
// 每种颜色至少涂多少个，求方案数
// ---
ll polya(int a)//a为循环节长度
{
    ll dp[65][65] = {0}; //前者为颜色，后者为未填充格子个数
    int tot = 60 / a, limit = 0;
    dp[0][tot] = 1;
    for (int i = 1; i <= n; i++)
    {
        int tmp = (c[i] + a - 1) / a;
        int up2 = tot - limit;
        int up1 = up2 - tmp;           //最多空tot-(limit + tmp)
        for (int j = 0; j <= up1; j++) //最少空0个，即填满
        {
            for (int k = tmp; j + k <= up2; k++) //至少选tmp个，最多选tot - limit -j
                (dp[i][j] += dp[i - 1][j + k] * C[j + k][k]) %= p;
        }
        limit += tmp;
    }
    return dp[n][0];
}
// ---
// 每种颜色要有多少个，求恰好满足的方案数
// ---
bool check(int b) //a[i]是每种颜色有多少个，b是循环节长度
{
    for (int i = 0; i < n; i++)
        if (a[i] % b) return false;
    return true;
}
ll solve(int tot, int b) //tot是总数，b是循环节长度
{
    if (!check(b)) return 0;
    ll res = 1, cnt = tot / b; //cnt循环节个数
    for (int i = 0; i < 6; i++)
    {
        res *= C[cnt][a[i] / b];
        cnt -= a[i] / b;
    }
    return res;
}
