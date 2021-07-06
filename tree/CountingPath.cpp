#include<bits/stdc++.h>
using namespace std ;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
// find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// *(s.find_by_order(2)) : 3rd element in the set i.e. 6
// *(s.find_by_order(4)) : 5th element in the set i.e. 88
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
// s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.
 
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define ar array
#define endl '\n'
#define trace(x) cout << #x << " = " << x << endl; 
const int mod = 1e9+7 ;
const int Mxn = 2e5+5 ;
 
int n, q ;
const int LOG = 22 ; 
unordered_map<int,vector<int>> edge; 
vector<int> val(Mxn), level(Mxn) ;
int dp[Mxn][LOG] ;
 
void dfs( int u, int p ){
	level[u] = level[p]+1 ; 
	dp[u][0] = p ;
	for( int v : edge[u] ){
		if( p == v ) continue ; 
		dfs(v,u) ;
	}
}
 
int kthAncestor(int x, int k ){
	for( int i = LOG-1 ; i >= 0 ; i-- ){
		if( (1<<i)&k ) x = dp[x][i] ;
	}
	return x ;
}
 
 
int LCA( int u, int v){
	if( level[u] > level[v] ){
		swap(u,v) ;
	}
	v = kthAncestor(v,level[v]-level[u]) ;
	if( v == u ){
		return u ; 
	}
	for( int i = LOG-1 ; i >= 0 ; i-- ){
		if( dp[v][i] != dp[u][i] ){
			v = dp[v][i] ; 
			u = dp[u][i] ;
		}
	}
	return dp[v][0] ;
}
 
void dfs1( int u, int p){
	for( int v : edge[u] ){
		if( v == p ) continue ;
		dfs1(v,u) ;
		val[u] += val[v] ;
	}
}
 
void solve(){
    cin >> n >> q ; 
	for( int i = 0 ; i < n-1 ; i++ ){
		int u, v ; cin >> u >> v ; 
		edge[u].pb(v) ; 
		edge[v].pb(u) ;
	}
	dfs(1,0) ;
	for( int i = 1 ; i < LOG ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			dp[j][i] = dp[dp[j][i-1]][i-1] ; 
		}
	}
	while(q--){
		int u, v ; cin >> u >> v ; 
		val[u]++ ; 
		val[v]++ ; 
		int x = LCA(u,v) ;
		val[x]-- ; 
		if( x != 1 ) val[dp[x][0]]-- ; 
	}
	dfs1(1,0) ;
	for( int i = 1 ; i <= n ; i++ ){
		cout << val[i] << " " ;
	}
	
}
 
int main(){
	int t =1 ;
	
	//clock_t start , finish ;
	//start = clock() ;
	while(t--){
		solve() ;
	}
	//finish = clock() ;
	//cout << fixed << setprecision(3) << (float)(finish - start)/CLOCKS_PER_SEC ;
	
}