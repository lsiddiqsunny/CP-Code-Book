#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b); // return __gcd(a,b);
}
long long int lcm(long long int a, long long int b)
{
    return (a / gcd(a, b)) * b;
}
int main()
{
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b)<<" "<<lcm(a,b);
}