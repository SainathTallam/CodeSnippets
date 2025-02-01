
// for sum
struct segtree
{
    ll size ;
    vector<ll> sums ;

    void init(ll n)
    {
        size = 1 ;

        while(size<n)
            size*=2 ;

        sums.resize(2*size,0) ;
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if(rx-lx == 1)
        {
            if(lx<a.size())
            {
                sums[x] = a[lx] ;
            }
            return ;
        }

        ll m = (lx+rx)/2 ;

        build(a,2*x+1,lx,m) ;
        build(a,2*x+2,m,rx) ;

        sums[x] = sums[2*x+1] + sums[2*x+2] ;
        
        return ;
    }

    void build(vector<ll> &a)
    {
        build(a,0,0,size) ;
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if(rx-lx == 1)
        {
            sums[x] = v ;
            return ;
        }

        ll m = (lx+rx)/2 ;

        if(i<m)
        {
            set(i,v,2*x+1,lx,m) ;
        }
        else
        {
            set(i,v,2*x+2,m,rx) ;
        }

        sums[x] = sums[2*x+1] + sums[2*x+2] ;

        return ;
    }

    void set(ll i, ll v)
    {
        set(i,v,0,0,size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if(lx>=l && rx<=r)
        {
            return sums[x] ;
        }

        if(lx>=r || rx<=l)
        {
            return 0 ;
        }

        ll m = (lx+rx)/2 ;
        
        ll s1 = sum(l,r,2*x+1,lx,m) ;
        ll s2 = sum(l,r,2*x+2,m,rx) ;

        return s1+s2 ;
    }

    ll sum(ll l, ll r)
    {
        return sum(l,r,0,0,size) ;
    }

};






// for minimum
struct segtree
{
    ll size ;
    vector<ll> mins ;

    void init(ll n)
    {
        size = 1 ;

        while(size<n)
            size*=2 ;

        mins.resize(2*size,INT_MAX) ;
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if(rx-lx == 1)
        {
            if(lx<(int)a.size())
            {
                mins[x] = a[lx] ;
            }
            return ;
        }

        ll m = (lx+rx)/2 ;

        build(a,2*x+1,lx,m) ;
        build(a,2*x+2,m,rx) ;

        mins[x] = min(mins[2*x+1], mins[2*x+2]) ;
        
        return ;
    }

    void build(vector<ll> &a)
    {
        build(a,0,0,size) ;
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if(rx-lx == 1)
        {
            mins[x] = v ;
            return ;
        }

        ll m = (lx+rx)/2 ;

        if(i<m)
        {
            set(i,v,2*x+1,lx,m) ;
        }
        else
        {
            set(i,v,2*x+2,m,rx) ;
        }

        mins[x] = min(mins[2*x+1], mins[2*x+2]) ;

        return ;
    }

    void set(ll i, ll v)
    {
        set(i,v,0,0,size);
    }

    ll get_min(ll l, ll r, ll x, ll lx, ll rx)
    {
        if(lx>=l && rx<=r)
        {
            return mins[x] ;
        }

        if(lx>=r || rx<=l)
        {
            return INT_MAX ;
        }

        ll m = (lx+rx)/2 ;
        
        ll s1 = get_min(l,r,2*x+1,lx,m) ;
        ll s2 = get_min(l,r,2*x+2,m,rx) ;

        return min(s1,s2) ;
    }

    ll get_min(ll l, ll r)
    {
        return get_min(l,r,0,0,size) ;
    }

};

