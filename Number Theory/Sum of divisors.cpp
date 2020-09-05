#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
int sod(long long int n)
{
    long long sum = 1;
    long long nowsum = 0;
    long long rt = sqrtl(n);
    for (int i = 0; primes[i] <= rt; i++) // pre-calculated prime
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
        long long x = bigmod(n, 1);
        long long y = modularInverse(n - 1);
        nowsum = (((x - 1 + MOD) % MOD) * (y % MOD)) % MOD;
        sum = ((sum % MOD) * (nowsum % MOD)) % MOD;
    }
    return sum;
}
int main()
{

    cout <<sod(10);
}