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
        bit.assign(n, 0);
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
};