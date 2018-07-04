#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define BRANCO 0
#define CINZA 1
#define PRETO 2

vector< pair<int,int> > lista_adjacencia[MAX];
int cor[MAX], ciclos=0;

void dfs(int u){
	cor[u] = CINZA;

	for(int a=0; a<lista_adjacencia[u].size(); a++){
		int v = lista_adjacencia[u][a].first;
		if(cor[v] == BRANCO) dfs(v);
		else if(cor[v] == CINZA) ciclos++;
	}
	cor[u] = PRETO;
}

void init(int num_vertices){
	for(i=0;i<num_vertices;i++){
		cor[i] = BRANCO;
		lista_adjacencia[i].clear();
	}
}

int numero_ciclos(){
	dfs(0);
	return ciclos;
}
