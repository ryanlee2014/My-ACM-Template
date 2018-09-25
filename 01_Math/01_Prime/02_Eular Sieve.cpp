// ---
// $O(n)$得到欧拉函数$phi[]$、素数表$prime[]$、素数个数$tot$\\
// ---
const int maxn = "Edit";
bool vis[maxn];
int tot, phi[maxn], prime[maxn];
void CalPhi()
{
    phi[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[tot++] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > maxn) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
// ---
// $d(n)$函数
// ---
const int maxn = "Edit";
int prime[maxn], tot;
int d[maxn], e[maxn]; //d正除数个数，e最小质因子个数
bool check[maxn];
void CalD()
{
    d[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            e[i] = 1, d[i] = 2; 
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                e[i * prime[j]] = e[i] + 1;
                d[i * prime[j]] = d[i] / e[i] * (e[i] + 1);
                break;
            }
            else
            {
                e[i * prime[j]] = 1;
                d[i * prime[j]] = 2 * d[i];
            }
        }
    }
}
// ---
// $\sigma \lambda(n)$函数，$\lambda=1$
// ---
const int maxn = "Edit";
int prime[maxn], tot;
int sig[maxn], e[maxn]; //sig正除数，e不含能整除i的最小质因子的正除数和
bool check[maxn];
void CalSig()
{
    sig[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            e[i] = 1, sig[i] = i + 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                sig[i * prime[j]] = sig[i] * prime[j] + e[i];
                e[i * prime[j]] = e[i];
                break;
            }
            else
            {
                sig[i * prime[j]] = sig[i] * (prime[j] + 1);
                e[i * prime[j]] = sig[i];
            }
        }
    }
}