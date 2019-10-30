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

int n;
VLL a;
bool solved = false;
VVLL g_bits(64);

void read_input(){
    cin >> n;
    a.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
        LL x = a[i];
        for(int j=0;x!=0;j++){
            if(x & 1){
                g_bits[j].push_back(i);
                if(g_bits[j].size() == 3){
                    solved = true;
                    cout << "3\n";
                    return;
                }
            }
            x >>= 1;
        }
    }
}

vector<unordered_set<int>> g;
vector<PII> edges;

void build_graph(){
    
    g.resize(n);
    for(int i=0;i<g_bits.size();i++){
        if(g_bits[i].size() == 2){
            int x = g_bits[i][0];
            int y = g_bits[i][1];
            g[x].insert(y);
            g[y].insert(x);
            edges.push_back({x, y});
        }
    }
}

int bfs(int start, int end){

    int curr;
    queue<int> q;
    VB visited(n, false);
    VI dist(n, 0);

    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        curr= q.front(); q.pop();

        for(auto neigh : g[curr]){
            if(!visited[neigh]){
                visited[neigh] = true;
                dist[neigh] = dist[curr] + 1;
                if(neigh == end) return dist[neigh];
                q.push(neigh);
            }
        }
    }
    return INT_MAX-1;
}

void solve(){

    if(solved) return;

    build_graph();

    int cycle = INT_MAX;
    for(auto e : edges){
        int from = e.first;
        int to = e.second;

        g[from].erase(to);
        g[to].erase(from);        
    
        cycle = min(cycle, bfs(from, to) + 1);
    
        g[from].insert(to);
        g[to].insert(from);
    }

    if(cycle == INT_MAX) cycle = -1;
    
    cout << cycle << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
