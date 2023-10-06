const int sz = 1e5 + 7;
bool NotPrime[sz];
vector<int>primes;
void Linear_Sieve()
{
    NotPrime[0] = NotPrime[1] = true;
    for( int i = 2; i < sz; i++ )
    {
        if( !NotPrime[i] ) 
            primes.push_back(i);
        for( int j = 0; j < primes.size() && i * primes[j] <= sz; j++ )
        {
            NotPrime[i * primes[j]] = true;
            if( i % primes[j] == 0 )
                break;
        }
    }
} // O(n)
