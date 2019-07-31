bool isPrime(ll n)
{
    if(n<=1)
        return 0;
    if(n%2==0)
        return 0;
    for(ll i=3; i*i<=n; i+=2)
        if(n%i==0)
            return 0;
    return 1;
}
