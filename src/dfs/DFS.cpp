#include<bits/stdc++.h>
using namespace std;

#define MAX 9999

bool visitado[MAX];
vector< pair<int,int> > lista_adjacencia[MAX];

void dfs(int u){
	int v, i;

	visitado[u] = true;
	int t = lista_adjacencia[u].size();

	for(i=0;i<t;i++){
		v = lista_adjacencia[u][i].first;
		if(!visitado[v]) dfs(v);
	}

}

void init(){
	int i;
	for(i=0;i<MAX;i++) visitado[i] = false;
	for(i=0;i<MAX;i++) lista_adjacencia[i].clear();
}
