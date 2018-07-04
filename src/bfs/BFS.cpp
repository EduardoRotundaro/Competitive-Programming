#include<bits/stdc++.h>
using namespace std;

#define MAX 9999

vector< pair<int,int> > lista_adjacencia[MAX];
bool visitado[MAX];

void bfs(int ini){

	queue<int> q;
	q.push(ini);

	while(!q.empty()){

		int u = q.front();
		q.pop();

		if(!visitado[u]){
			visitado[u] = true;
			int t = lista_adjacencia[u].size();
			for(int i=0;i<t;i++){
				int v = lista_adjacencia[u][i].first;
				q.push(v);
			}
		}
	}
}

void init(){
	int i;
	for(i=0;i<MAX;i++) visitado[i] = false;
	for(i=0;i<MAX;i++) lista_adjacencia[i].clear();
}
