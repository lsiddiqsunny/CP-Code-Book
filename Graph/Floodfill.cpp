#include <bits/stdc++.h>
using namespace std;
int vis[1005][1005];
int grid[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
bool possible(int x, int y)
{

    return (x < n && x >= 0 && y < m && y >= 0);
}
void dfs(int i, int j)
{
    //cout << i << " " << j << endl;
    if (!possible(i, j) or vis[i][j] or !grid[i][j])
    {
        return;
    }
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        dfs(i + dx[k], j + dy[k]);
    }
}
int main()
{

    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                grid[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and grid[i][j])
            {
             //   cout << "starting " << i << " " << j << endl;
                dfs(i, j);

                ans++;
            }
        }
    }
    cout << ans << endl;
}