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

int powerLinear( int x , int n ){

    if ( x == 0 ) return 0;
    if ( n == 0 ) return 1;

    int smallerAns = powerLinear(x, n-1); //faith
    int ans = x * smallerAns;
    return ans;

}

int powerLogrithmic ( int x , int n ){

    if ( x == 0 )   return 0;
    if ( n == 0 )   return 1;

    int smallerAns = powerLogrithmic ( x , n/2 ); // faith
    int ans = smallerAns * smallerAns;
    if ( n % 2 == 1 )   ans = ans * x;
    return ans;

}

void printArray ( vector <int> &nums, int index ){

    if ( index >= nums.size() )    return;

    cout << nums[index] << " ";
    printArray( nums, index+1 ); // faith
}

void printReverse ( vector <int> &nums, int index ){

    if ( index >= nums.size() )    return;

    printReverse( nums, index+1);
    cout << nums[index] << " ";

}

int maxElement ( vector <int> &nums, int index ){

}

int firstOccurance ( vector <int> &nums, int index, int target ){

}

int lastOccurance ( vector <int> &nums, int index, int target ){

}

vector <int> allIndices ( vector <int> nums, int index, int target ){

}


void solve(){
    
    int pow1 = powerLinear( 3, 4);
    cout << "the output of powerLinear is " << pow1 << endl;

    int pow2 = powerLogrithmic(3, 5);
    cout << "the output of powerLogrithmic is " << pow2 << endl;

    vector <int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(5);

    printArray (nums1, 0 );
    cout << endl;

    printReverse (nums1, 0);
    cout << endl;

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

