
int fastPowerMod( int base, int exponent, int modulus )
{
    int result = 1;
    base %= modulus;
    while (exponent > 0)
    {
        if ( exponent & 1 )
            result = (result * base) % modulus;

        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

int inv( int num )
{
    return fastPowerMod( num , MOD - 2, MOD );
}

int NCR( int num, int i )
{
    return mul( mul( fact[num], inv( fact[num - i] ) ), inv( fact[i] ) );
}