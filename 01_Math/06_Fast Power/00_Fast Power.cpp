inline ll Mul(ll a, ll b, ll m)
{
    if (m <= 1000000000)
        return a * b % m;
    else if (m <= 1000000000000ll)
        return (((a * (b >> 20) % m) << 20) + (a * (b & ((1 << 20) - 1)))) % m;
    else
    {
        ll d = (ll)floor(a * (long double)b / m + 0.5);
        ll ret = (a * b - d * m) % m;
        if (ret < 0) ret += m;
        return ret;
    }
}
ll Pow(ll a, ll n, ll m)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % m))
        if (n & 1) t = (t * a % m);
    return t;
}
