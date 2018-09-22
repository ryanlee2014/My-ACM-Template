const int maxn = "Edit";
struct Palindromic_Tree
{
    int ch[maxn][26], f[maxn], cnt[maxn], len[maxn], s[maxn];
    int last, sz, n;
    int newnode(int x)
    {
        memset(ch[sz], 0, sizeof(ch[sz]));
        cnt[sz] =  0, len[sz] = x;
        return sz++;
    }
    void init()
    {
        sz = 0;
        newnode(0), newnode(-1);
        last = 0, n = 0, s[0] = -1, f[0] = 1;
    }
    int get_fail(int u)
    {
        while (s[n - len[u] - 1] != s[n]) u = f[u];
        return u;
    }
    void add(int c)
    {
        s[++n] = c;
        int u = get_fail(last);
        if (!ch[u][c])
        {
            int np = newnode(len[u] + 2);
            f[np] = ch[get_fail(f[u])][c];
            ch[u][c] = np;
        }
        last = ch[u][c];
        cnt[last]++;
    }
    void count()
    {
        for (int i = sz - 1; ~i; i--) cnt[f[i]] += cnt[i];
    }
};