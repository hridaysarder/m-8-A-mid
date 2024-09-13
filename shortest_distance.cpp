#include <bits/stdc++.h>
#define ll long long int
const long long int INF = 1e18 + 5;
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll adj[105][105];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] < INF && adj[k][j] < INF)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        if (adj[s][d] == INF)
            cout << -1 << endl;
        else
            cout << adj[s][d] << endl;
    }

    return 0;
}