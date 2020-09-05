#include <bits/stdc++.h>
using namespace std;
int PHI(int n)
{
    int ret = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ret -= ret / i;
        }
    }
    // this case will happen if n is a prime number
    // in that case we won't find any prime that divides n
    // that's less or equal to sqrt(n)
    if (n > 1)
        ret -= ret / n;
    return ret;
}

// Optimized Euler function
#define M 1000005
int phi[M];

void calculatePhi()
{
    for (int i = 1; i < M; i++)
    {
        phi[i] = i;
    }
    for (int p = 2; p < M; p++)
    {
        if (phi[p] == p)
        { // p is a prime
            for (int k = p; k < M; k += p)
            {
                phi[k] -= phi[k] / p;
            }
        }
    }
}
int main()
{
    long long a;
    cin >> a;
    cout << PHI(a);
}