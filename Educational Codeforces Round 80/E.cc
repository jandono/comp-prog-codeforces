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

int n, m, x;

struct Message{
    int min_update_step;
    int min_pos;
    int curr_pos;
    int max_pos;
};

vector<Message> a;

void read_input(){

    cin >> n >> m; 
    a.resize(n);
    
    for(int i=0;i<n;i++){
        a[i].min_update_step = 0;
        a[i].min_pos = i;
        a[i].curr_pos = i;
        a[i].max_pos = i;
    }

    for(int i=0;i<m;i++){

        cin >> x; x--;

        // debug(x);
        // debug(a[x].min_pos);
        // debug(a[x].curr_pos);
        // debug(a[x].max_pos);

        a[x].max_pos = max(a[x].max_pos, i - a[x].min_update_step + a[x].curr_pos);
        a[x].min_update_step = i;
        a[x].min_pos = 0;
        a[x].curr_pos = 0;
        // cout << "---------------------\n";
        // debug(a[x].min_pos);
        // debug(a[x].curr_pos);
        // debug(a[x].max_pos);
        // cout << "#####################\n";
    }
}

void solve(){

    for(int i=0;i<n;i++){

        if(m-1 != a[i].min_update_step)
            a[i].max_pos = max(a[i].max_pos, m - 1 - a[i].min_update_step + a[i].curr_pos);

        cout << a[i].min_pos + 1 << " " << a[i].max_pos + 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
