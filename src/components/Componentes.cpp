#include<bits/stdc++.h>
using namespace std;

#define MAX 100

vector< pair<int,int> > lista_adjacencia[MAX];
int id_v[MAX];

void dfs(int v, int id){
		id_v[v] = id;

   	for (int a=0; a<lista_adjacencia[v].size(); a++)
			if (id_v[ lista_adjacencia[v][a].first ] == -1) dfs(lista_adjacencia[v][a].first, id);
}

int numero_de_componentes(int num_vertices){
	int v, id=0;
	for(v=0; v<num_vertices; v++) id_v[v] = -1;
	for(v=0; v<num_vertices; v++) if(id_v[v] == -1) dfs(v, id++);
	return id;
}

void init(int num_vertices){
	for(i=0;i<num_vertices;i++) lista_adjacencia[i].clear();
}
