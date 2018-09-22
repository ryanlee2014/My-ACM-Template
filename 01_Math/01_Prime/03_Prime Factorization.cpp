vector<pair<ll, int>> getFactors(ll x)
{
    vector<pair<ll, int>> fact;
    for (int i = 0; prime[i] <= x / prime[i]; i++)
    {
        if (x % prime[i] == 0)
        {
            fact.emplace_back(prime[i], 0);
            while (x % prime[i] == 0) fact.back().second++, x /= prime[i];
        }
    }
    if (x != 1) fact.emplace_back(x, 1);
    return fact;
}