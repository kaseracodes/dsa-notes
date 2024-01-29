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

vector <string> getSubstrings ( string &input ){

  int n = input.length();
  vector <string> ans;

  for ( int i = 0; i < n ; i++ ){
    string str = "";
    for( int j = i; j < n ; j++ ){
      str += input[j];
      ans.push_back(str);
    }
  }

  return ans;

}

// "abc" --> [..., ..c, .b., .bc, a.., a.c, ab., abc ]
// "bc" -->  [.., .c, b., bc ]
vector <string> getSubsequences ( string &input ){

    if ( input.length() == 0 ){
      vector <string> baseAns;
      baseAns.push_back("");
      return baseAns;
    }

    char first = input[0]; 
    string smallerInput = input.substr(1); // rest of the string without the first char
    vector <string> smallerAns = getSubsequences(smallerInput); // recursive faith

    vector <string> ans;
    for ( auto &str : smallerAns ){
      string ssq1 = "" + str;     // not including the first character
      string ssq2 = first + str;  // including the first character
      ans.push_back(ssq1);
      ans.push_back(ssq2);
    }

    return ans;

}

void solve(){
    
    string input;
    cin >> input;

    vector <string> substrings = getSubstrings(input);
    cout << "The subs-strings are as follows: " << endl;
    for ( auto &str : substrings )  cout << str << endl;

    vector <string> subsequences = getSubsequences(input);
    cout << "The subs-sequences are as follows: " << endl;
    for ( auto &str : subsequences )  cout << str << endl;

}

int32_t main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while ( T-- ){
        solve();
    }

    return 0;
}

