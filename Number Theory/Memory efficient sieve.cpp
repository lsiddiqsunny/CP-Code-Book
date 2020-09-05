#include <bits/stdc++.h>
using namespace std;
#define M 100000000
int marked[M / 64 + 2];
#define on(x) (marked[x / 64] & (1 << ((x % 64) / 2)))
#define mark(x) marked[x / 64] |= (1 << ((x % 64) / 2))
void sieve(int n)
{
    for (int i = 3; i * i < n; i += 2)
    {
        if (!on(i))
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                mark(j);
            }
        }
    }
}
bool isPrime(int num)
{
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}
int main()
{
    int n;
    cin >> n;
    sieve(n);
}