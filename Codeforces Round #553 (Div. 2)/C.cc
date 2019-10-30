#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

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

typedef pair<int, int> ii;
typedef long long LL;

bool power_of_two(int x){
    return !(x & (x - 1));
}

LL gen_seq(LL l, LL r){
    
    LL odd = 1;
    LL even = 2;
    LL tmp = 0;
    LL res = 0;
    int flag = -1; // 1 == odd, -1 == even
    for(LL i=1;i<=r;i++){
        
        if(power_of_two(i)){
            flag *= -1;
            // cout << "\n";
        }

        if(flag == 1){
            // cout << i << ":" << odd << " ";
            res += odd;
            odd += 2;
        }else{
            // cout << i << ":" << even << " ";
            res += even;
            even += 2;
        }
        // cout << res << "\n";
        
        if(i == l - 1)
            tmp = res;
    }

    return res - tmp;
}

vector<int> gen_contains_all_before(int n){

    int el = 0;
    vector<int> sol;
    
    while(el < n){
        if(!(el & 1))
            el = el * 2 + 1;
        else
            el = el * 2;
        sol.push_back(el);
    }

    return sol;
}

vector<int> gen_all_swaps(int n){
    int el = 2;
    vector<int> sol;
    while(el < n){
        sol.push_back(el - 1);
        el = el << 1;
    }

    return sol;
}

int sum_even_to_n(int n){
    int z = n/2;
    return z * (z + 1);
}

int sum_odd_to_n(int n){
    int z = (n + 1) / 2;
    return z * z;
}

// int value(int n){

//     vector<int> contains_all_before = gen_contains_all_before(n);
//     vector<int> all_swaps = gen_all_swaps(n);
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // gen_seq(90);
    
    // LL n;
    // cin >> n;
    // vector<int> contains_all_before = gen_contains_all_before(n);
    // debug(contains_all_before);
    // vector<int> all_swaps = gen_all_swaps(n);
    // debug(all_swaps);
    // cout << sum_even_to_n(20) - sum_even_to_n(9);

    LL l, r;
    cin >> l >> r;
    cout << gen_seq(l, r) % 1000000007  << "\n";
    return 0;
}