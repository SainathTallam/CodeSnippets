#include<bits/stdc++.h>
#include<string.h>
using namespace  std;

// #pragma GCC optimize("Ofast")
// #pragma GCC ("unroll-loops")
#define ll long long
typedef long long loptimizel;
typedef unsigned long long ull;
typedef long double ld;

#define f1( i , a , b , x) for(ll i = a; i <= (ll)b; i += x)
#define f2( i , a , b , x) for(ll i = a; i >= (ll)b; i -= x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a*b)/gcd(a,b))
#define mx(a,b,c) max(a,max(b,c))
#define mn(a,b,c) min(a,min(b,c))
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define pob pop_back
#define pof pop_front
#define mk make_pair
#define ff first
#define ss second 
#define input(A,n) {                \
                     f1(i,0,n-1,1)   \
                       cin>>A[i] ;   \
                    }
#define M_PI 3.14159265358979323846264338327

void fileIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}




/**********************the fun begins**********************************************************************************************/

void update(ll ind, ll val, ll n,vector<ll> &tree)
{
       ind += n;
       tree[ind] = val;

       for(ll i = ind/2;i>=1;i = i/2)
       {
           tree[i] = tree[2*i] + tree[(2*i)+ 1];
       }
}

 
int get_freq(ll l, ll r, ll n, vector<ll> &tree)
{
    l += n;
    r += n;

    ll ans = 0;

    while(l<=r)
    {
        if(l%2==1) 
            ans+=tree[l++];

        if(r%2==0) 
            ans+=tree[r--];

        l/=2; r/=2;
    }

    return ans;
}

vector<ll> build_tree(vector<ll> &v)
{
    ll sz = v.size();

    vector<ll> tree(2*sz,0);

    for(ll i=sz;i < 2*sz;i++)
    {
          tree[i] = v[i-sz];
    }

    for(int i=sz-1;i>=1;i--)
    {
         tree[i] = tree[2*i]+tree[(2*i)+1] ;
    }

    return tree;
}

void solve(ll t)
{
    ll n, m; cin>>n>>m;

    vector<ll> a(n);

    for(ll i=0;i<n;i++)
        cin>>a[i];

    vector<vector<ll>> trees(4);

    for(ll i=1;i<=3;i++)
    {
        vector<ll> v;

        for(ll j=0;j<n;j++)
        {
            if(a[j] == i)
                v.push_back(1);
            else
                v.push_back(0);
        }

        trees[i] = build_tree(v);
    }

    ll fans = 0;

    while(m--)
    {
        ll ind, val, mid;
        cin>>ind>>val>>mid;
        ind--; mid--;

        ll prev = a[ind];
        update(ind, 0, n, trees[prev]);

        a[ind] = val;

        update(ind, 1, n, trees[val]);

        ll a = get_freq(0, mid, n, trees[1]);
        ll b = get_freq(0, mid, n, trees[2]);
        ll c = get_freq(0, mid, n, trees[3]);

        ll x = get_freq(mid+1, n-1 , n, trees[1]);
        ll y = get_freq(mid+1, n-1, n, trees[2]);
        ll z = get_freq(mid+1, n-1, n, trees[3]);

        ll leftsum = a + b*2 + c*3;
        ll rightsum = x + y*2 + z*3;

        ll diff;

        if(leftsum > rightsum)
        {
            swap(a,x);
            swap(b,y);
            swap(c,z);
            swap(leftsum,rightsum);
        }

        diff = rightsum - leftsum;

        ll ans = 0;
        // use as many 3 from right, 1 from left
        ll limit = min({diff/4, a, z}); ans+=limit;

        diff-=limit*4;
        a-=limit; z-=limit;
        x+=limit; c+=limit;

        // use 2 from right, 1 from left
        limit = min({diff/2, a, y}); ans+=limit;

        diff-=limit*2;
        a-=limit; y-=limit;
        x+=limit; b+=limit;

        // use 3 from right, 2 from left
        limit = min({diff/2, b, z}); ans+=limit;

        diff-=limit*2;
        b-=limit; z-=limit;
        y+=limit; c+=limit;

        ll q = -1;

        if(diff==0)
        {
            q = ans;
        }

        fans += q;
    }

    cout<<"Case #"<<t<<": "<<fans<<endl;
}


/**********************Just the Driver Function************************************************************8**********************/
int main()
{
   //ios_base::sync_with_stdio(false);cin.tie(NULL);
   fileIO(); 
   ll t=1 ;
   
   cin>>t ; 
    
    for(ll i=0;i<t;i++)
        solve(i+1);
    return 0 ;
}

