/* Author : Prasuk Jain */
#include <bits/stdc++.h>
using namespace std;

#define int                 long long int
#define ull                 unsigned long long
#define ld                  long double
#define fo(i, n)            for(int i=0; i<n; i++)
#define Fo(i, a, b)         for(int i=a; i<b; i++)
#define rfo(i, n)           for(int i=n-1; i>=0; i--)
#define Rfo(i, b, a)        for(int i=b-1; i>=a; i--)
#define tr(it, v)           for(auto it=v.begin(); it!=v.end(); it++)
#define ff                  first
#define ss                  second
#define vi                  vector<int>
#define vvi                 vector<vector<int>>
#define pii                 pair<int, int>
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int, vi, greater<int>>
#define mii                 map<int, int>
#define si                  set<int>
#define msi                 multiset<int>
#define uset                unordered_set<int>
#define umap                unordered_map<int, int>
#define mp                  make_pair
#define pb(x)               push_back(x)
#define hcf(x, y)           __gcd(x, y)
#define lcm(x, y)           boost::math::lcm(x,y)
#define setpre(x, y)        fixed << setprecision(y) << x
#define maax(a, b, c)       max(a, max(b, c))
#define miin(a, b, c)       min(a, min(b, c))
#define zerolead(x)         __builtin_clzll(x)
#define zerotrail(x)        __builtin_ctzll(x)
#define setbits(x)          __builtin_popcountll(x)
#define parity(x)           __builtin_parityll(x)
#define all(x)              x.begin(), x.end()
#define sortall(x)          sort(all(x))
#define rmdups(a)           a.resize(unique(a.begin(),a.end())-a.begin());
#define deb1(x)             cout<<#x<<"="<<x<<endl
#define deb2(x, y)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define deb3(x, y, z)       cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define inarr(arr, n)       for(int i=0;i<n;i++) cin >> arr[i];
#define printarray(arr, n)  for(int i=0;i<n;i++) {cout<<arr[i]<<" ";} cout<<"\n";
#define PI                  3.1415926535897932384626
const int mod = 1e9+7;
const int inf = 1e18;
vector<int> fact;

//----------------------Functions-----------------------//
int mpow(int base, int exp);
bool isPrime(int num);
bool isPowerTwo(int x);
bool isSubstring(string s1, string s2);
void factorial(int num);
void factmod(int num);
void primeFactor(int num);

//*!*!*!*!*!*!*!*!*!*!*!*! Solve !*!*!*!*!*!*!*!*!*!*!*!//

void heisenbuggs() {
    int n, k, p, q;
    
}

//*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!//

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int T = clock();
    int t = 1;
    cin >> t;
    while(t--) {
        heisenbuggs();
    }
    cerr << "TIME : " << 1000 * (double)(clock()-T)/CLOCKS_PER_SEC << " ms\n";
    T = clock();
    return 0;
}

//*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!//

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((int)result * base) % mod;
        base = ((int)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool isPrime(int num) {
    if(num <= 1) return false;
    for(int i=2; i*i <= num; i++)
        if(num%i == 0) return false;
    return true;
}

bool isPowerTwo(int x) {
    return (x && !(x & (x-1)));
}

bool isSubstring(string s1, string s2) {
    if(s1.find(s2) != string::npos) return true;
    else return false;
}

void factorial(int num) {
    fact[0] = 1; 
    for(int i = 1; i <= num; i++)
        fact[i] = i * fact[i - 1];
}

void factmod(int num) {
    fact[0] = 1; 
    for(int i = 1; i <= num; i++) 
        fact[i] = (i * fact[i - 1]) % mod;
}

void primeFactor(int num){
    for(int i=2; i<=num; i++)
    if(num%i == 0){
        int cnt = 0;
        while(num%i == 0)
        cnt++ , num /= i;
        cout << i << "^" << cnt << " ";
    }
    if(num > 1)
    cout << num << "^" << "1" << " ";
}
