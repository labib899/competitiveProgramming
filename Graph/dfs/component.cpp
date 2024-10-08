#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define fastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef priority_queue<ll> pqll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int N=1e5+10;
vi graph[N]; //adjacency list
bool vis[N];
void solve();
void dfs(int node);

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    int t=1; //cin>>t;
    while(t--) solve();
}

void solve()
{
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int comp=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            comp++;
        }
    }
    cout<<comp<<endl;
}


void dfs(int node)
{
    vis[node]=true;
    for(auto c:graph[node])
    {
        if(!vis[c]) dfs(c);
    }
}

// undirected graph
