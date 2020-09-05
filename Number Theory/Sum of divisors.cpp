#include <bits/stdc++.h>
using namespace std;
int MOD= 1e9 + 7;

typedef pair<int, int> pii;
#define x first
#define y second
vector<int>primes;// pre-calculated prime
long long bigmod(long long a, long long p, long long m) 
{
    long long res = 1;
    long long x = a;
    while (p)
    {
        if (p & 1) //p is odd
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        p = p >> 1;
    }
    return res;
}
pii extendedEuclid(int a, int b)
{ // returns x, y | ax + by = gcd(a,b)
    if (b == 0)
        return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

int modularInverse(int a, int n)
{
    pii ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}
int sod(long long int n)
{
    long long sum = 1;
    long long nowsum = 0;
    long long rt = sqrtl(n);
    for (int i = 0; primes[i] <= rt; i++) 
    {
        if (n % primes[i] == 0)
        { //cout<<primes[i]<<endl;
            int cnt = 0;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            rt = sqrtl(n);
            //cout<<cnt<<endl;
            long long x = bigmod(primes[i], (cnt) + 1, MOD);
            long long y = modularInverse(primes[i] - 1, MOD);
            nowsum = (((x - 1 + MOD) % MOD) * (y % MOD)) % MOD;
            sum = ((sum % MOD) * (nowsum % MOD)) % MOD;
        }
    }
    if (n > 1)
    {
        long long x = bigmod(n, 1,MOD);
        long long y = modularInverse(n - 1,MOD);
        nowsum = (((x - 1 + MOD) % MOD) * (y % MOD)) % MOD;
        sum = ((sum % MOD) * (nowsum % MOD)) % MOD;
    }
    return sum;
}
int main()
{

    cout <<sod(10);
}