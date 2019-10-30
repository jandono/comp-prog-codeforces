#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>
#include <fstream>
#include <cmath>

using namespace std;

/// ********* debug template by Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const unordered_set< T > &v ) {
    os << "[";
    typename unordered_set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const unordered_map< F, S > &v ) {
    os << "[";
    typename unordered_map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    } 
    return os << "]";
}

#define debug(x) cerr << #x << " = " << x << endl;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;

// TEMPLATE DEFINITIONS END

int n, I;
VI a;

void read_input(){
    cin >> n; // 1 <= n <= 400 000
    cin >> I; // 1 <= I <= 100 000 000
    I *= 8; //transform from bytes to bits

    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i]; // 1 <= a[i] <= 1 000 000 000
}

bool check(int K){
    return n * ceil(log2(K)) <= I;
}

int bs(){
    int l=0, r=n, k=0;
    while(l < r){
        int mid = l + (r-l)/2;

        if(check(mid)){
            k = mid;
            l = mid + 1;
        }else{
            r = mid;
        }
    }

    return k;
}

void solve(){

    if(check(n)){
        cout << "0\n";
        return;
    }

    int k = bs();
    sort(a.begin(), a.end());

    int cnt = 0;
    int l, r, sol = INT_MAX;
    
    // debug(a);
    // debug(k);
    for(l=0,r=0;r<n;r++){
        if((r > 0 && a[r] != a[r-1]) || r == 0) cnt++;
        // cout << "\n########################\n";
        // debug(l);
        // debug(r);
        // debug(cnt);
        // debug(sol);

        if(cnt > k){
            while(l < r && a[l] == a[l+1]) l++;
            l++;
            cnt--;
        }

        sol = min(sol, n - (r-l+1));
    }

    cout << sol << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
