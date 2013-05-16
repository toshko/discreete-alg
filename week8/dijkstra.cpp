/* Program that take a graph represented as
 * a list of edges and convert it to 
 * adjacency matrix(AM).
 */
#include <iostream>
#include <climits>
#define MAXN 1000
using namespace std;

int vertices, edges;
int matrix[MAXN][MAXN], D[MAXN], U[MAXN], P[MAXN], C[MAXN][MAXN];

void printAM();
void convert();
void dijkstra(int r);

int main ()
{
   cin >> vertices >> edges;
   convert();
   //printAM();
   dijkstra(1);
   for (int v = 1; v <= vertices; v++)
      cout << D[v] << " ";
   cout << endl;

   return 0;
}

void dijkstra(int r)
{
   U[r] = 1;
   P[r] = -1;
   D[r] = 0;
   int i, j, z;
   for ( i = 1; i <= vertices; ++i)
   {
      for (j = 1; j <= vertices; ++j)
      {
	 if(matrix[r][j] != 0 && U[j] == 0)
	 {
	    if((matrix[r][j] + D[r]) < D[j])
	    {
	       D[j] = matrix[r][j] + D[r];
	       P[j] = r;
	    }
	 }
      }
      r = INT_MAX;
      for (z = 1; z < vertices; z++)
      {
	 if(D[z] < r && U[z] == 0)
	 {
	    r = z;
	 }
      }
      U[r] = 1;
   }
}
//func that converts list of edges to AM
void convert()
{
   int a, b, i, c;
   for ( i = 0; i < edges; i++ )
   {
      D[i+1] = INT_MAX;
      cin >> a >> b >> c;
      matrix[a][b] = c;
      matrix[b][a] = c; // if the graph is directed comment this line
   }

}

//func that prints the AM
void printAM()
{
   int i, j;
   for (i = 1; i <= vertices; i++) // loops starts from 1 because there is no vertex 0
   {
      for (j = 1; j <= vertices; j++)
      {
	 cout << matrix[i][j] << " "; 
      }
      cout << endl;
   }
   cout << endl;

}

