#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 9999999

vector< pair<int,int> > lista_adjacencia[MAX];
int pai[MAX], distancia[MAX];
bool visitado[MAX];

void init(int num_vertices){
	for(int i=0;i<num_vertices;i++){
		pai[i] = -1;
		distancia[i] = INF;
		visitado[i] = false;
	}
}

void dijkstra(int num_vertices, int origem, int destino){
	int x, y, peso, i, menor_distancia;

	init(num_vertices);

	distancia[origem] = 0;
	x = origem;

	while(!visitado[x]){
		for(i=0;i<lista_adjacencia[x].size();i++){
			y=lista_adjacencia[x][i].first;
			peso=lista_adjacencia[x][i].second;

			if( (distancia[x]+peso) < distancia[y] ){
				distancia[y] = distancia[x]+peso;
				pai[y] = x;
			}
		}

		visitado[x] = true;
		menor_distancia = INF;

		for(i=0;i<num_vertices;i++){
			if(!visitado[i] && distancia[i]<menor_distancia){
				x=i;
				menor_distancia = distancia[i];
			}
		}
	}
}

void caminho(int destino){
	i = destino;
	printf("\nCaminho: %d ", destino);
	while(pai[i]!=-1){
		cout<<pai[i]<<" ";
		i=pai[i];
	}
}

void menorCaminho(int destino){
	printf("Menor distancia: %d", distancia[destino]);
}
