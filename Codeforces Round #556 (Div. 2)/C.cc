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
int ones = 0, twos = 0;
int num;

void read_input(){
    cin >> n; // 1 <= n <= 200 000
    for(int i=0;i<n;i++){
        cin >> num;
        if(num == 1) ones++; else twos++;
    }
}

VVI dp;

int is_prime(int x){
    
    if(x == 1)
        return 0;

    for(int i=2;i*i<=x;i++){
        if(x % i == 0)
            return 0;
    }

    return 1;
}

// void solve(){

//     dp.resize(ones + 1, VI(twos + 1, 0));
//     dp[0][0] = 0;

//     for(int i=1;i<=ones;i++){
//         dp[i][0] = dp[i-1][0] + is_prime(i);
//     }

//     for(int i=1;i<=twos;i++){
//         dp[0][i] = dp[0][i-1] + is_prime(2*i);
//     }

//     for(int i=1;i<=ones;i++){
//         for(int j=1;j<=twos;j++){
            
//             dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + is_prime(i + 2*j);
//         }
//     }

//     cout << dp[ones][twos] << "\n";
// }

void solve(){
    VI solution;
    int curr = 0;
    while(ones > 0 || twos > 0){

        if(ones == 0){
            solution.push_back(2);
            twos--;
            curr += 2;
        }else
        if(twos == 0){
            solution.push_back(1);
            ones--;
            curr += 1;
        }else{
            if(is_prime(curr + 1)){
                solution.push_back(1);
                ones--;
                curr += 1;
            }else{
                solution.push_back(2);
                twos--;
                curr += 2;
            }
        }
    }

    for(int i=0;i<solution.size();i++){
        if(i == solution.size() - 1) 
            cout << solution[i] << "\n";
        else
            cout << solution[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
