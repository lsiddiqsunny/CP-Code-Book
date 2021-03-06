#include <bits/stdc++.h>
using namespace std;
vector<int> primes; // we'll preload primes once at the beginning
int countDivisor(int n)
{
    int divisor = 1;
    for (int i = 0; i * i <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt = 1;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
    }
    return divisor;
}
int main()
{
    int n;
    cin >> n;
    countDivisor(n);
}