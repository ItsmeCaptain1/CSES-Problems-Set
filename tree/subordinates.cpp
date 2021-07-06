#include<bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define ar array
const int mod = 1e9+7 ;
 
const int Mxn = 2e5 ;
vector<int> edge[Mxn] ;
int sub[Mxn] ;
int n ; 
 
int dfs( int u, int p){
	for( int v : edge[u] ){
		if( v == p ){
			continue ;
		}
		sub[u] += dfs(v,u) ;
	}
	return sub[u]+1 ;
}
 
int main(){
	cin >> n ;
	for( int i = 0 ; i < n ;++i){
		sub[i] = 0 ;
	}
	for( int i = 1 ; i < n ; i++){
		int x ; cin >> x, --x ; 
		edge[x].push_back(i) ;
	}
	dfs(0,-1) ;
	for( int i = 0 ; i < n ; i++){
		cout << sub[i] << " " ;
	}
}
 