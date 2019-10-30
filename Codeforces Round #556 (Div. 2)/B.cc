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
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;

// TEMPLATE DEFINITIONS END

int n;
int visited = 0;
VS board;
bool solved = false;
int ii[4] = {0, 0, -1, 1};
int jj[4] = {-1, 1, 0, 0};

VI vis_row;

void read_input(){
    cin >> n;
    board.resize(n);
    vis_row.resize(n, 0);
    for(int i=0;i<n;i++){
        cin >> board[i];
        if(i > 0) vis_row[i] = vis_row[i-1];

        for(int j=0;j<n;j++){
            visited += (board[i][j] == '#') ? 1 : 0;
        }
    }
}

bool check(int i, int j){
    
    if(board[i][j] == '#') return false;

    for(int k=0;k<4;k++){
        int new_i = i + ii[k];
        int new_j = j + jj[k];
        
        if(new_i < 0 || new_i >= n) return false;
        if(new_j < 0 || new_j >= n) return false;
        if(board[new_i][new_j] == '#') return false;
    }

    return true;
}

void update(int i, int j, char c){
    
    board[i][j] = c;

    for(int k=0;k<4;k++){
        int new_i = i + ii[k];
        int new_j = j + jj[k];

        board[new_i][new_j] = c;
    }
}

void dfs(int start_i, int start_j){

    for(int i=start_i;i<n;i++){
        if(i != start_i) start_j = 0;

        for(int j=start_j;j<n;j++){
            
            if(solved) return;
            if(i > 0 && j > 0 && board[i-1][j-1] == '.') return;

            if(!solved && check(i, j)){
                
                update(i, j, '#');
                visited += 5;
                if(visited == n*n){
                    solved = true;
                    return;
                }
                dfs(i, j + 1);
                update(i, j, '.');
                visited -= 5;
                dfs(i, j + 1);
            }
        }
    }
}

void solve(){
    if((n*n - visited) % 5){
        cout << "NO\n";
        return;
    }

    dfs(0, 0);
    if(solved)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
