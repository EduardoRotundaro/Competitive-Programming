#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 9999

vector< pair<int,int> > lista_adjacencia[MAX];
int pai[MAX], frj[MAX], pr[MAX];

void initialize(int num_vertices){
	int v, a;

	for(v=0; v<num_vertices; v++){
		pai[v] = -1;
		pr[v] = INF;
	}
	pai[0] = 0;
	for(a=0; a<lista_adjacencia[0].size(); a++){
		pr[ lista_adjacencia[0][a].first ] = lista_adjacencia[0][a].second;
		frj[ lista_adjacencia[0][a].first ] = 0;
	}
}

void prim_mst(int num_vertices){
	initialize(num_vertices);
	while(true){
		int w, y, a, c, min = INF;

		for(w=0; w<num_vertices; w++)
			if (pai[w] == -1 && pr[w] < min) min = pr[y = w];

		if(min == INF) break;
		pai[y] = frj[y];
		for (a=0; a<lista_adjacencia[y].size(); a++){
			w = lista_adjacencia[y][a].first;
			c = lista_adjacencia[y][a].second;
			if(pai[w] == -1 && c < pr[w]){
				pr[w] = c;
				frj[w] = y;
			}
		}
	}
}

void init(int num_vertices){
	for(int i=0; i<num_vertices; i++) lista_adjacencia[i].clear();
}
