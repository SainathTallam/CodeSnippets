#include<bits/stdc++.h>
#include<string.h>
using namespace  std;

#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")

#define ll long long
typedef unsigned long long ull;
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a*b)/gcd(a,b))
#define all(a) (a).begin(),(a).end()

void fileIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}




/**********************the fun begins**********************************************************************************************/
ll total;

ll recurse(ll l, ll note)
{
    if(l == 0)
        return 0;

    ll ans = LLONG_MAX;

    // give 1 coin
    ans = min(ans, 1 + recurse(l-1, note));

    // give 2 coins
    if(note != 0 && note<=l)
    {
        ans = min(ans, 2 + recurse(l-note, note));
    }

    // give 4 coins
    if(note != total - l)
    {
        ans = min(ans, 4 + recurse(l, total-l));
    }

    return ans;

}

ll bfs(vector<vector<ll>> &adj, ll curr)
{
    queue<ll> q;
    ll n = adj.size();

    vector<bool> visited(n, false);

    q.push(curr); visited[curr] = true;
    ll ans = 0;

    while(!q.empty())
    {
        curr = q.front(); q.pop();
        ans++;

        for(auto next : adj[curr])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }

    }

    return ans;
}

void dfs(vector<vector<ll>> &adj, ll curr, vector<ll> visited, map<ll, bool> &mp)
{
    visited[curr] = 1;

    for(auto next : adj[curr])
    {
        if(visited[next] == 0)
        {
            dfs(adj, next, visited, mp);
        }
        else if(visited[next] == 2)
        {

        }
        else
        {
            mp[curr] = false;
        }
    }

    visited[curr] = 2;
}

void solve(int z)
{
   ll n; cin>>n;
   vector<ll> a(n);

   for(ll i=0;i<n;i++)
    cin>>a[i];

   vector<vector<ll>> adj(n);
    map<ll, bool> mp;

   for(ll i=0;i<n-1;i++)
   {
        ll u, v; cin>>u>>v; u--; v--;

        if(a[u] > a[v])
        {
            adj[u].push_back(v);
            mp[v] = true;
        }

        if(a[v] > a[u])
        {
            adj[v].push_back(u);
            mp[u] = true;
        }
   }

   ll ans = 0;
   vector<ll> visited(n, 0); // 0 not visited 1 in current branch 2 completed visiting

   for(ll curr = 0; curr < n; curr++)
   {
        if(visited[curr] == 0)
        {
            dfs(adj, curr, visited, mp);
        }
    }

   for(ll i=0;i<n;i++)
   {
        if(mp[i] == false)
        { 
            ll temp = bfs(adj, i);
            //cout<<i+1<<" "<<temp<<endl;
            ans = max(ans, temp);
        }
   }

    cout<<"Case #"<<z<<": "<<ans<<endl ;
}





/**********************Just the Driver Function************************************************************************************************/
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   // fileIO(); 
   ll t=1 ;
   
   cin>>t ; 
   
   for(ll i=0;i<t;i++)
   {
     solve(i+1) ;
   }
    return 0 ;
}

