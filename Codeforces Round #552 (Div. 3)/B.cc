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

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define debug(x) cerr << #x << " = " << x << endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;
    
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> x;
        s.insert(x);
        if(s.size() > 3){
            cout << "-1\n";
            return 0;
        }
    }

    if(s.size() == 1){
        cout << "0\n";
        return 0;
    }

    vi nums;
    for(auto el : s){
        nums.push_back(el);
    }
    
    int result;
    if(nums.size() == 3){
        if(nums[2] - nums[1] == nums[1] - nums[0])
            result = nums[2] - nums[1];
        else
            result = -1;
    }else{
        result = nums[1] - nums[0];
        if(!(result & 1))
            result >>= 1;
    }

    cout << result << "\n";
    return 0;
}