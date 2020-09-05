#include <bits/stdc++.h>
using namespace std;
#define mx 505

long long int mat[mx][mx];
int n, m, q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mat[i][j] = 1e15;
        }
        mat[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        mat[a][b] = min(mat[a][b], w);
        mat[b][a] = min(mat[b][a], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << ((mat[a][b] >= 1e15) ? -1 : mat[a][b]) << "\n";
    }
}