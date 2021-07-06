#include<bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define ar array
const int mod = 1e9+7 ;
 
const int Mxn = 2e5 ;
vector<int> edge[Mxn] ;
int n, ans = 0 ;
 
int dfs( int u, int p){
	int z = 0 ;
	int m1 = 0, m2 = 0 ;
 
	for( int v : edge[u] ){
		if( v == p ){
			continue ;
		}
		int x = dfs(v,u) ;
		z = max( z, x ) ;
		if( m1 < x ){
			m2 = m1 ;
			m1 = x ;
		}
		else if( m2 < x ){
			m2 = x ;
		}
	}
	ans = max( m1+m2, ans ) ;
	return z+1 ;
}
int main(){	
	cin >> n ; 
	for( int i = 0 ; i < n-1 ; i++){
		int a, b ; cin >> a >> b, --a, --b ;
		edge[a].push_back(b) ;
		edge[b].push_back(a) ;
	}
	
	dfs(0,-1) ;
	cout << ans ;
}
 