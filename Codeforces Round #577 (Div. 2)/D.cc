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


int n, m, k, q;
VVI table;
VI left_most, right_most;
set<int> safe_cols;

void read_input(){
    cin >> n >> m >> k >> q; // 2 <= n, m, k, q <= 200 000
    table.resize(n, VI(m, 0));
    left_most.resize(n, n);
    right_most.resize(n, -1);

    int x, y;
    for(int i=0;i<k;i++){
        cin >> x >> y; x--, y--;
        
        left_most[x] = min(left_most[x], y);
        right_most[x] = max(right_most[x], y);
    }

    int c;
    for(int i=0;i<q;i++){
        cin >> c; c--;
        safe_cols.insert(c);
    }

    // sort(safe_cols.begin(), safe_cols.end());
}

void solve(){

    // debug(columns);
    VI safe_left(m), safe_right(m);
    for(int i=0;i<m;i++){
        auto idx_r = safe_cols.lower_bound(i);
        
        cout << "\n########################\n";
        debug(i);
        if(idx_r != safe_cols.begin()){
            auto idx_l = prev(idx_r);
            debug(*idx_l);
        }
        
        if(idx_r != safe_cols.end()){
            debug(*idx_r);
        }
    }
    return;
    
    // queue<PII> q;
    // q.push({0, 0});
    // int x, y;
    // while(!q.empty()){
        
    //     tie(x, y) = q.front(); q.pop();
    //     int l = min(left_most[x], y);
    //     int r = max(right_most[x], y);

    //     auto clr = columns.upper_bound(l);
    //     auto cll = prev(clr);
        

    //     auto crr = columns.upper_bound(r);
    //     auto crl = prev(crr);
    // } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
