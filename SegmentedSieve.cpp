const int sz = 1e6 + 10;
bool NotPrime[sz];
int l, r;
void Segmented_Sieve()
{
    int lim = ::sqrt(r);
    for( int i = 2; i <= lim ; i++ )
    {
        for( int j = max( i * i, ( l + i - 1 ) / i * i ); j <= r; j += i )
            NotPrime[j - l] = true;
    }
    if( l == 1 )
        NotPrime[0] = true;
}