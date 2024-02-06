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

// find out the maximum element in the array from the index position to the last position
int maxElement ( vector <int> &nums, int index ){

    if ( index == nums.size() ) return INT_MIN;

    int firstElement = nums[index];
    int smallerAns = maxElement(nums, index+1);
    
    int ans = INT_MIN;
    if ( firstElement > smallerAns )    ans = firstElement;
    else ans = smallerAns;

    return ans;

}


// find out the first occurance of target in nums from index position to the last position
int firstOccurance ( vector <int> &nums, int index, int target ){

    if ( index == nums.size() ) return -1;

    if ( nums[index] == target )    return index;
    int smallerAns = firstOccurance(nums, index+1 , target);

    return smallerAns;

}

// find out the last occurance of target in nums from index position to the last position
int lastOccurance ( vector <int> &nums, int index, int target ){
    return 0;
}

/** 
 *  Find out all the occurances of target in nums from index position to the last position and return them in a vector     
 *     i =  0  1  2  3  4  5  6  7
 *  nums = 30 20 30 40 30 20 30 60
 *  target = 30
 *  Output : {0, 2, 4, 6}
 */
vector <int> allIndices ( vector <int> nums, int index, int target ){
    
    if ( index == nums.size() ){
        vector <int> base;
        return base;
    }

    // faith: {2, 4, 6}
    vector <int> ans = allIndices( nums, index+1, target );

    if ( nums[index] == target )    ans.push_back(index);
    return ans;

}


void solve(){
    
    int pow1 = powerLinear( 3, 4);
    cout << "the output of powerLinear is " << pow1 << endl;

    int pow2 = powerLogrithmic(3, 5);
    cout << "the output of powerLogrithmic is " << pow2 << endl;

    // [1, 2, 3, 4, 5, 3, 3, 3]
    vector <int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(3);
    nums1.push_back(3);
    nums1.push_back(3);
    

    printArray (nums1, 0 );
    cout << endl;

    printReverse (nums1, 0);
    cout << endl;

    int max = maxElement(nums1, 0);
    cout << "Maximum Element in the array: " << max << endl;

    int firstIndex = firstOccurance ( nums1, 0, 3 );
    cout << "First occurance is " << firstIndex << endl;

    vector <int> allOccurances = allIndices( nums1, 0, 3 );
    cout << "All Occurances: ";
    for ( auto index : allOccurances )  cout << index << " ";   cout << endl;




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

