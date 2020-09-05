#include <bits/stdc++.h>
using namespace std;
int vis[100005];
int par[100005];
vector<int> g[100005], res;
bool ok = false, backtracking = false;
int backNode = -1;

int n, m;
void dfs(int u, int x = 0, int prev = -1)
{
    vis[u] = x;
    for (auto v : g[u])
    {
        if (v == prev)
            continue;
        if (vis[v] == -1)
            dfs(v, x + 1, u);
        else
        {
            int cur = (x + 1) - vis[v];
            res.push_back(v);
            res.push_back(u);
            if (cur >= 2)
            {
                ok = true, backtracking = true;
                backNode = v;
                return;
            }
        }
        if (backtracking)
        {
            res.push_back(u);
            if (u == backNode)
                backtracking = false;
        }
        if (ok)
            return;
    }
}
int main()
{
    ok = false;
    memset(vis, -1, sizeof(vis));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {

            par[i] = -1;
            dfs(i, 1);
        }
        if (ok)
        {
            break;
            ;
        }
    }
    if (!ok)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << res.size() << '\n';
        for (auto x : res)
            cout << x << " ";
        cout << '\n';
    }
}