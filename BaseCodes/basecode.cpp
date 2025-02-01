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


void solve()
{
   vector<int> myvector(5);

   int *p = myvector.data();

   *p = 10;
   ++p;
   *p = 20;
   p[2] = 100;

   for(unsigned i=0;i<myvector.size();++i)
   {
        cout<<' '<<myvector[i];
   }

   cout<<endl;

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
       solve();
   }
    return 0 ;
}


