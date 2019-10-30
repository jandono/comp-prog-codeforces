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

int n, x, y;
VVI g;

void read_input(){
    cin >> n;
    g.resize(n, VI());
    for(int i=0;i<n-1;i++){
        cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

bool check(int root){

    VI degree(n, -1);
    VB visited(n, false);
    visited[root] = true;

    queue<PII> q;
    q.push({root, 0});
    int curr, wave;
    while(!q.empty()){
        tie(curr, wave) = q.front(); q.pop();

        if(degree[wave] == -1)
            degree[wave] = g[curr].size();
        else
        if(degree[wave] != g[curr].size()){
            return false;
        }

        for(auto j : g[curr]){
            if(!visited[j]){
                visited[j] = true;
                q.push({j, wave + 1});
            }
        }
    }

    return true;
}

VI distances(int start){

    queue<PII> q;
    q.push({start, 0});
    VI distance(n, -1);
    VB visited(n, false);
    visited[start] = true;
    int curr, wave;
    while(!q.empty()){
        tie(curr, wave) = q.front(); q.pop();
        distance[curr] = wave;
        for(auto j : g[curr]){
            if(!visited[j]){
                visited[j] = true;
                q.push({j, wave+1});
            }
        }
    }
    
    return distance;
}

int maxi(VI &d){
    int m = -1;
    int idx = -1;
    for(int i=0;i<d.size();i++){
        if(d[i] > m){
            m = d[i];
            idx = i;
        }
    }

    return idx;
}
void solve(){
    
    VI dist1 = distances(0);
    int l1 = maxi(dist1);
    VI dist2 = distances(l1);
    int l2 = maxi(dist2);
    VI dist3 = distances(l2);
    
    int best_dist = -1;
    int res = -2;
    for(int i=0;i<n;i++){
        if(dist2[i] == dist3[i] && dist2[i] > best_dist){
            best_dist = dist2[i];
            res = i;
        }
    }

    if(res >= 0){
        if(check(res)){
            cout << res + 1 << "\n";
            return;
        }

        for(auto cand : g[res]){
            if(check(cand)){
                cout << cand + 1 << "\n";
                return;
            }
        }
    } 
    
    cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
