#include <bits/stdc++.h>
using namespace std;
#define cin std :: cin
#define cout std :: cout
#define int long long
#define ll long long
#define endl '\n'
const int mod = 1e9+7;

int gcd ( int a , int b ){ if ( b == 0 ) return a; return gcd ( b , a%b ); }
int modexp(int a, int b, int m) {a %= m;int res = 1LL;while (b > 0) {if (b & 1)res = (res%m *1LL* a%m) % m;a = (a%m *1LL* a%m) % m;b >>= 1;}return res%m;}
int modmul(int a,int b,int m){return (a%m*1LL*b%m)%m;}

void solve(){
    
    

}

int32_t main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while ( T-- ){
        solve();
    }

    return 0;
}

