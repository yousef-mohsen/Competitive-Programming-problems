//
//  main.cpp
//  Fibonacci Numbers
//
//  Created by Yousef on 07.10.20.
//

#include <iostream>
#include <vector>

using namespace std;
long long mo = 1e9 + 7;
typedef long long ll;

vector<vector<long long> > x (3, vector<long long>(3));


vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    int l = a.size(), r = b[0].size();
    
    vector<vector<ll>> temp2 (l, vector<ll> (r));
    
    for(int i = 1; i < l; i++)
        for(int k = 1; k < r; k++)
            for(int q = 1; q < a[0].size(); q++)
            {
                temp2[i][k] += a[i][q] * b[q][k];
                if(temp2[i][k] > mo)
                    temp2[i][k] %= mo;
            }
    return temp2;
}




vector<vector<ll>> modpow (long long power)
{
    if(power <= 1)
        return x;
    vector<vector<ll>> temp = modpow(power / 2);
    vector<vector<ll>> temp2 = mul(temp, temp);
    
    if((power & 1) == 1)
        return (mul(temp2, x));
    return temp2;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n;
    cin>>n;
    if(n == 0)
    {
        cout<<0;
        return 0;
    }
    x[1][1] = 0;
    x[1][2] = 1;
    x[2][1] = 1;
    x[2][2] = 1;
    
    
    vector<vector<ll>>f(3, vector<ll>(2));
    f[1][1] = 0;
    f[2][1] = 1;
    auto t = modpow(n);
    auto m  = mul(t,f);
    cout<<m[1][1];
    
    
    

    return 0;
}
