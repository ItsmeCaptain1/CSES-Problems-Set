    #include<bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define ar array
#define endl '\n'
const int mod = 1e9+7 ;
const int Mxn = 2e5+2 ;
 
int n; 
unordered_map<int,vector<int>> edge ;
vector<ll> dx(Mxn, INT_MAX), dy(Mxn,INT_MAX) ;
 
int bfs(int u, vector<ll>& d ){
    queue<int> q ; 
    q.push(u) ; 
    d[u] = 0 ;
    int last = -1 ; 
    while( !q.empty() ){
        int x = q.front() ; 
        q.pop() ; 
        last = x ;
        for( auto v : edge[x] ){
            if( d[v] > d[x]+1){
                d[v] = d[x]+1 ; 
                q.push(v) ;
            }
        }
    } 
    return last ; 
}
 
 
void solve(){
    cin >> n ; 
    for( int i = 0 ; i < n-1 ; i++ ){
        int a,b ; cin >> a >> b ; 
        edge[a].pb(b) ;
        edge[b].pb(a) ;
    }
    int x = bfs(1,dy) ; 
    int y = bfs(x,dx) ;
    for( int i = 1 ; i <= n ; i++ ){
        dy[i] = INT_MAX ;
    }
    bfs(y,dy) ; 
    for( int i = 1 ; i <= n ; i++ ){
        cout << max(dy[i],dx[i]) << " " ;
    }
    
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1 ;
    
	//clock_t start , finish ;
	//start = clock() ;
	while(t--){
		solve() ;
	}
	//finish = clock() ;
	//cout << fixed << setprecision(3) << (float)(finish - start)/CLOCKS_PER_SEC ;
	
}