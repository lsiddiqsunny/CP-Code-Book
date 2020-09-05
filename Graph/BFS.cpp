#include <bits/stdc++.h>
using namespace std;
int vis[100005];
int par[100005];
vector<int> g[100005];
int n, m;

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    par[1] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();//cout<<u<<endl;
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v]=1;
                par[v] = u;
            }
        }
    }
    
    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> ans;
        int now = n;
        while (now != -1)
        {
            ans.push_back(now);
            now = par[now];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}