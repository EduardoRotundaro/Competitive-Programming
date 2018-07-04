#include<bits/stdc++.h>
using namespace std;

#define MAX 100

vector< pair<int,int> > lista_adjacencia[MAX];
bool visitado[MAX];

void reachR(int v){
	visitado[v] = true;
	for(int a=0; a<lista_adjacencia[v].size(); a ++)
		if(!visitado[ lista_adjacencia[v][a].first ]) reachR(lista_adjacencia[v][a].first);
}

bool existe_um_caminho(int num_vertices, int origem, int destino){
	for(int v=0; v<num_vertices; v++) visitado[v] = false;
	reachR(origem);

	if (!visitado[destino]) return false;
	return true;
}

void init(int num_vertices){
	for(int i=0;i<num_vertices;i++) lista_adjacencia[i].clear();
}
