bool smaller(string s, string f)
{
    if (s.size() < f.size()) return true;
    if (s.size() > f.size()) return false;

    FOR (i,0,s.size())
    {
        if (s[i] < f[i]) return true;
        else if (s[i] > f[i]) return false;
    }
    return false;
}

string difference_large_number(string s, string f)
{
    if (smaller(s,f)) swap(s,f);

    ll n = s.size(), m = f.size();
    string res = "";
    ll dis = n - m, carry = 0;

    FOD (i,m-1,0)
    {
        ll digit = (s[i + dis] - '0') - (f[i] - '0') - carry;
        
        if (digit < 0) {digit += 10; carry = 1;}
        else carry = 0;

        res.pub(digit + '0');
    }

    FOD (i,n-m-1,0)
    {
        if (s[i] == '0' && carry) {res.pub('9'); continue;}

        ll digit = ((s[i] - '0') - carry);
        if (i > 0 || digit > 0) res.pub(digit + '0');
        carry = 0;
    }

    while (res[res.size() - 1] == '0' && res.size() > 1) res.pob();
    reverse (res.begin(), res.end()); 
    return res;
}