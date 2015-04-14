#include <vector> // vector
#include <utility> // pair
#include <stdio.h> // I/O

using namespace std;

// Re-defini��o
typedef pair<int,int > ii;

// MACROS
#define MAXV 5 // quantidade m�xima de v�rtices
#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++) // otimizar a escrita do FOR
#define pb push_back
#define mp make_pair

// Declara��o global
vector<int> ladj[MAXV]; // Lista de adjac�ncia n�o ponderada (Origem -> Destino)
vector< ii > ladjP[MAXV]; // Lista de adjac�ncia ponderada (Origem, Peso - > Destino)

int main()
{
    /*
	  Grafo n�o ponderado e n�o direcionado ( u->v e v->u)

	  0 1
	  1 2
	  1 3
	  2 3
    */

	int u,v,w; //origem, destino e peso

	rep(i,0,4){ // quantidade de arestas do grafo
		scanf("%d %d",&u,&v);
		ladj[u].pb(v); //adiciona a aresta u->v sem peso
		ladj[v].pb(u); //adiciona a aresta v->u sem peso
	}

	printf("******** Grafo N�o Ponderado ********\n");
	rep(i,0,MAXV){ // printando a lista de adjac�ncia
		printf("Adjacencia de %d = ", i);
		rep(j,0,ladj[i].size())
			printf("%d -> ",ladj[i][j]);
		printf("\n");
	}

	rep(i,0,MAXV) // limpando o grafo
		ladj[i].clear();

	  /*
		  Grafo ponderado e n�o direcionado ( (u->v,w)  e (v->u,w) )

		  0 1 5
		  1 2 11
		  1 3 21
		  2 3 100
	    */


	rep(i,0,4){ // quantidade de arestas do grafo
		scanf("%d %d %d",&u,&v,&w);
		ladjP[u].pb(ii(v,w)); //adiciona a aresta u->v com peso w
		ladjP[v].pb(ii(u,w)); //adiciona a aresta v->u com peso w
	}

	printf("\n\n******** Grafo Ponderado ********\n");
	rep(i,0,MAXV){ // printando a lista de adjac�ncia
		printf("Adjacencia de %d = ", i);
		rep(j,0,ladjP[i].size())
		{
			ii aux = ladjP[i][j];
			printf("( %d,%d ) -> ",aux.first, aux.second);
		}
		printf("\n");
	}

	rep(i,0,MAXV){
		ladjP[i].clear();
	}



	return 0;
}
