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

int n, k;
string s;
vector<PII> cb, rb;

void read_input(){

    cin >> n >> k;
    cb.resize(n, {INT_MAX, INT_MIN});
    rb.resize(n, {INT_MAX, INT_MIN});

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j] == 'B'){
                cb[j].first = min(cb[j].first, i);
                cb[j].second = max(cb[j].second, i);

                rb[i].first = min(rb[i].first, j);
                rb[i].second = max(rb[i].second, j);
            }
        }
    }
}

int white_lines(){
    LL lines = 0;
    for(int i=0;i<n;i++){
        if(cb[i].first == INT_MAX && cb[i].second == INT_MIN) lines++;
        if(rb[i].first == INT_MAX && rb[i].second == INT_MIN) lines++;
    }
    return lines;
}

VVI process(vector<PII> &b, bool swap){
    
    VVI lines(n, VI(n, 0));
    int curr_lines;
    
    for(int i=0;i<=n-k;i++){

        curr_lines = 0;
        for(int t=0;t<k;t++){
            if(b[t].first != INT_MAX && b[t].first >= i && b[t].second < i + k) curr_lines++;
        }

        if(!swap)
            lines[i][0] = max(lines[i][0], curr_lines);
        else
            lines[0][i] = max(lines[0][i], curr_lines);
        
        for(int j=1;j<=n-k;j++){
        
            if(b[j-1].first != INT_MAX && b[j-1].first >= i && b[j-1].second < i + k)
                curr_lines--;
            
            if(b[j+k-1].first != INT_MAX && b[j+k-1].first >= i && b[j+k-1].second < i + k)
                curr_lines++;

            if(!swap)
                lines[i][j] = max(lines[i][j], curr_lines);
            else
                lines[j][i] = max(lines[j][i], curr_lines);
        }
    }
    
    return lines;
}

void solve(){

    int w_lines = white_lines();
    VVI lines_c = process(cb, false);
    VVI lines_r = process(rb, true);

    int max_lines = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            max_lines = max(max_lines, lines_c[i][j] + lines_r[i][j]);
        }
    }

    cout << w_lines + max_lines << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
