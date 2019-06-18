int extended_euclidean(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int mod_inverse(int a,int m)
{
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1)
    {
        cout << "No solution!";
        return -1;
    }
    else
    {
        x = (x % m + m) % m;
        return x;
    }
}
void for_all_mod_inverse(int m)
{
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
        inv[i] = (m - (m/i) * inv[m%i] % m) % m;
}
