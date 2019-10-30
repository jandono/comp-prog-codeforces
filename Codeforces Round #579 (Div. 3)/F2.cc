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

int n, r, a, b;
vector<PII> pos, neg;

void read_input(){
    cin >> n >> r;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(b < 0)
            neg.push_back({a, b});
        else
            pos.push_back({a, b});
    }
}

void solve(){
    
    int cnt_pos = 0;
    sort(pos.begin(), pos.end());
    for(int i=0;i<pos.size();i++){
        
        if(r < pos[i].first) break;

        r += pos[i].second;
        cnt_pos++;
    }

    auto comp = [](PII &lhs, PII &rhs){
        return lhs.first + lhs.second > rhs.first + rhs.second;
    };

    sort(neg.begin(), neg.end(), comp);

    VVI dp(neg.size() + 1, VI(r+1, 0));
    for(int i=0;i<neg.size();i++){

        tie(a, b) = neg[i];

        for(int j=0;j<=r;j++){

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            if(j >= a && j + b >= 0)
                dp[i+1][j+b] = max(dp[i+1][j+b], dp[i][j] + 1);
        }
    }

    int cnt_neg=0;
    for(int j=0;j<=r;j++){
        cnt_neg = max(cnt_neg, dp[dp.size()-1][j]);
    }

    cout << cnt_pos + cnt_neg << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
