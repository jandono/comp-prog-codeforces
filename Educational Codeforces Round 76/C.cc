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

int t, n;
VI a;

void solve_q();

void read_input(){
    cin >> t; // 1 <= t <= 1000
    for(int i=0;i<t;i++) solve_q();
}

void read_q(){
    cin >> n;  // 1 <= n <= 2 * 10^5
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
}

void solve_q(){
    read_q();
    
    map<int, int> num2cnt;
    map<int, int, greater<int>> cnt2elems;
    
    int sol = INT_MAX;
    
    int l = 0, r = 0;
    while(r < n){
        
        if(r > l + 1 && (*cnt2elems.begin()).second == 1){
            sol = min(sol, r - l);
            cnt2elems[num2cnt[a[l]]]--;
            num2cnt[a[l]]--;
            cnt2elems[num2cnt[a[l]]]++;
            l++;
        }else{
            num2cnt[a[r]]++;
            cnt2elems[num2cnt[a[r]]]++;
            r++;
        }

        // debug(l);
        // debug(r);
        // cout << "#############\n";
    }

    while(r > l + 1 && (*cnt2elems.begin()).second == 1){
        sol = min(sol, r - l);
        cnt2elems[num2cnt[a[l]]]--;
        num2cnt[a[l]]--;
        cnt2elems[num2cnt[a[l]]]++;
        l++;
    }

    cout << ((sol == INT_MAX) ? -1 : sol) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    // solve();
    return 0;
}
