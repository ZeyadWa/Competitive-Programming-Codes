const int sz = 1e5 + 7;
bool NotPrime[sz];
void Sieve()
{
    NotPrime[0] = NotPrime[1] = 1;
    for( int i = 2; i * i <= sz; i++ )
    {
        if( !NotPrime[i] )
        {
            for( int j = i * i; j < sz; j += i )
                NotPrime[j] = 1;
        }
    }
} // O(n*log(log(n)))