#include<bits/stdc++.h>
using namespace std;

#define MAX 100

vector< pair<int,int> > lista_adjacencia[MAX];
static int low[MAX], pre[MAX], pai[MAX];
static int contapre;

void lowR(int v){
	int a;
	pre[v] = contapre++;
	low[v] = pre[v];

	for (a = 0; a <lista_adjacencia[v].size(); a++){
		int w = lista_adjacencia[v][a].first;
		if (pre[w] == -1){
			pai[w] = v;
			lowR(w);
			if (low[w] < low[v]) low[v] = low[w];

    }
		else if (pre[w] < low[v] && w != pai[v]) low[v] = pre[w];
	}
}

void lowestPre(int num_vertices){
	int v;
	contapre = 0;

	for(v=0; v<num_vertices; v++) pre[v] = -1;
	for(v=0; v<num_vertices; v++)
		if(pre[v] == -1){
			pai[v] = v;
			lowR(v);
		}
}

int pontes_do_grafo(int num_vertices){
	int num_pontes, v;

	lowestPre(num_vertices);
	num_pontes = 0;
	for (v=0; v<num_vertices; v++)
		if (low[v] == pre[v] && pai[v] != v) num_pontes++;

	 return num_pontes;
}

void init(int num_vertices){
	for(i=0; i<num_vertices; i++) lista_adjacencia[i].clear();
}
