
const int N = 2e5 + 5, M = 1e6 + 6, OO = 0x3f3f3f3f;
int par[N];
int n, m;
pair<int, pair<int,int>>EdgeList[M];

void init()
{
    FOR(i, N) par[i] = i;
}

int FindParent( int u )
{
    if( par[u] != u )
        return par[u] = FindParent( par[u] );
    return u;
}

bool SameSet( int u, int v )
{
    u = FindParent(u);
    v = FindParent(v);
    return u == v;
}

void join( int u, int v )
{
    u = FindParent(u);
    v = FindParent(v);
    if( u == v )
        return;
    par[v] = u;
}

int DSU() // Kruskal
{
    sort( EdgeList, EdgeList + m );
    int res = 0;
    FOR(i, m)
    {
        if( !SameSet( EdgeList[i].second.first, EdgeList[i].second.second ) )
        {
            res += EdgeList[i].first;
            join( EdgeList[i].second.first, EdgeList[i].second.second );
        }
    }
    return res;
}


