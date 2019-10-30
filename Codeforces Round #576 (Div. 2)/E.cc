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

int T;

void solve_q();

void read_input(){
    cin >> T;
    for(int i=0;i<T;i++){
        solve_q();
    }
}

int n, m, x, y;
vector<PII> edges;
VB node_in_match;
VI matching;

void read_q(){
    cin >> n >> m;
    edges.clear();
    node_in_match.clear();
    node_in_match.resize(3*n, false);
    matching.clear();

    for(int i=0;i<m;i++){
        cin >> x >> y; x--; y--;
        edges.push_back({x, y});
    }
}

void solve_q(){

    read_q();

    for(int i=0;i<edges.size();i++){
        int x = edges[i].first;
        int y = edges[i].second;

        if(!node_in_match[x] && !node_in_match[y]){
            node_in_match[x] = true;
            node_in_match[y] = true;
            matching.push_back(i);
        }
    }

    int cnt = matching.size();

    if(cnt >= n){
        cout << "Matching\n";
        for(int i=0;i<n;i++)
            cout << matching[i] + 1 << " ";
        cout << "\n";
    }else
    if(n >= cnt){
        
        int br = 0;
        cout << "IndSet\n";
        for(int i=0;i<3*n;i++){
            if(!node_in_match[i]){
                cout << i + 1 << " ";
                br++;
            }

            if(br == n)
                break;
        }
        cout << "\n";
    }else{
        cout << "Impossible\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    // solve();
    return 0;
}
