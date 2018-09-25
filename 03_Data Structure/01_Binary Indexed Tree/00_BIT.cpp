// ---
// $O(\log n)$查询和修改数组的前缀和
// ---
// 注意下标应从1开始
template <class T>
struct BIT
{
    vector<T> bit;
    int n;
    void init(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int x, T v)
    {
        for (; x <= n; x + = x & -x) bit[x] += v
    }
    void query(int x)
    {
        T ret = 0;
        for (; x; x -= x & -x) ret += bit[x];
        return ret;
    }
    // 做权值树状数组时求第k小
    int kth(int k)
    {
        int ret = 0, cnt = 0;
        for (int i = 20; ~i; i--)
        {
            ret ^= (1 << i);
            if (ret > n || cnt + bit[ret] >= k)
                ret ^= (1 << i);
            else
                cnt += bit[ret];
        }
        return ret + 1;
    }
};