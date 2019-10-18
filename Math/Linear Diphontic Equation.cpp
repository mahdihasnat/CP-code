int gcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long mulmod(long long a, long long b,long long m)
{
    return ( (a % m )* (b%m) )%m ;
}
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }
    long long dx = c / a;
    c -= dx * a;
    long long dy = c / b;
    c -= dy * b;
    x0 = dx + mulmod(x0, c / g, b);
    y0 = dy + mulmod(y0, c / g, a);
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}
