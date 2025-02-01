// implementation 1 

#define MAXN 100000 

struct DSU
{
    int root[MAXN] ;

    void init()
    {
        for (int i = 0; i < MAXN; i++)
        {
            root[i] = i;
        }
    }

    int find_root(int i)
    {
        return root[i] == i ? i : root[i] = find_root(root[i]);
    }

    bool merge(int a, int b)
    {
        a = find_root(a), b = find_root(b);

        if (a == b)
        {
            return false;
        }

        root[a] = b;
        return true;
    }
};









// implementation 2
// implementation of union by rank based on the depth of the trees:

#define MAXN 100000 

struct DSU1
{
    int root[MAXN] ;
    int rank[MAXN] ;

    void init()
    {
        for (int i = 0; i < MAXN; i++)
        {
            root[i] = i ;
            rank[i] = 0 ;
        }
    }

    int find_root(int i)
    {
        return root[i] == i ? i : root[i] = find_root(root[i]);
    }


    bool merge(int a, int b) 
    {
        a = find_root(a);
        b = find_root(b);

        if (a == b)
        {
            return false;
        }

        if (rank[a] < rank[b])
            swap(a, b);

        root[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;

        return true ;
    }
};




// implementation 3
// union by size

#define MAXN 100000 

struct DSU1
{
    int root[MAXN] ;
    int size[MAXN] ;

    void init()
    {
        for (int i = 0; i < MAXN; i++)
        {
            root[i] = i ;
            size[i] = 1 ;
        }
    }

    int find_root(int i)
    {
        return root[i] == i ? i : root[i] = find_root(root[i]);
    }


    bool merge(int a, int b) 
    {
        a = find_root(a);
        b = find_root(b);

        if (a == b)
        {
            return false;
        }

        if (size[a] < size[b])
            swap(a, b);

        root[b] = a;

        size[a]+=size[b] ;

        return true ;
    }
};
