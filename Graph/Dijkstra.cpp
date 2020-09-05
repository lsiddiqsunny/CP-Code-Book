#include <bits/stdc++.h>
using namespace std;
#define mx 100005
#define pii pair<long long int, int>
#define pb push_back

int vis[mx];
int par[mx];
long long dist[mx];
int parent[mx];

vector<pair<long long, int>> g[mx];
int n, m;
priority_queue<pii, vector<pii>, greater<pii>> q;
void printpath(int src)
{
    if (parent[src] != -1)
        printpath(parent[src]);
    cout << src << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        g[x].push_back({w, y});
        // one-way path
        //g[y].push_back({w, x}); 
    }
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT64_MAX;
        vis[i] = false;
        parent[i] = -1;
    }
    
    dist[1] = 0;
    q.push(pii(0, 1));
    while (!q.empty())
    {
        int s = q.top().second;
        long long d = q.top().first;
        q.pop();
        if (d != dist[s])
            continue;
        for (int i = 0; i < g[s].size(); i++)
        {
            int v = g[s][i].second;
            long long int w = g[s][i].first;
            if (!vis[v] && dist[s] + w < dist[v])
            {
                dist[v] = dist[s] + w;
                q.push(pii(dist[v], v));
                parent[v] = s;
            }
        }
        vis[s] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}