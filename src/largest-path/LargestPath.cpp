#include<bits/stdc++.h>
using namespace std;

#define MAX 100

vector< pair<int,int> > lista_adjacencia[MAX];
bool visitado[MAX];

int dfs(int v, int t){
	int a, maxv = -1;

	if(v == t) return 0;
	visitado[v] = true;
	for(a=0; a<lista_adjacencia[v].size(); a++){
		if( !visitado[ lista_adjacencia[v][a].first] ){
			int maxw = dfs( lista_adjacencia[v][a].first, t);
			if(maxw != -1 && maxv < lista_adjacencia[v][a].second + maxw) maxv = lista_adjacencia[v][a].second + maxw;
		}
	}
	visitado[v] = false;

	return maxv;
}

int custo_maximo (int num_vertices, int s, int t){
	for(int v = 0; v<num_vertices; ++v) visitado[v] = false;
	return dfs(s, t);
}

void init(int num_vertices){
	for(i=0; i<num_vertices; i++) lista_adjacencia[i].clear();
}

void maior_caminho(int num_vertices){
	int origem, destino;
	cin>>origem>>destino;
	return custo_maximo(num_vertices, origem, destino);
}
