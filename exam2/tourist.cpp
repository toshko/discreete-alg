/* Program that implements Dijkstra algorithm
*/
#include <iostream>
#include <climits>
#include <cmath>
#define MAXN 1000
using namespace std;

int vertices, edges;
int matrix[MAXN][MAXN], D[MAXN], U[MAXN], P[MAXN], C[MAXN][MAXN];
int V[MAXN],PATH[MAXN], start, end;
void printAM();
void convert();
void dijkstra(int r);

int main ()
{
   int g,h;
   g = 0;
   cin >> vertices >> edges >> start >> end;
   h = end;
   convert();
   //printAM();
   dijkstra(start);
   cout << endl;
   PATH[g] = end;  
   while ( P[h] != -1)
   {
      PATH[++g] = P[h];
      h = P[h];
   }
   while ( g >= 0 )
   {
      cout << PATH[g] << " ";
      g--;
   }

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
      int min = INT_MAX;
      for (z = 1; z <= vertices; z++)
      {
	 if(D[z] < min && U[z] == 0)
	 {
	    min = D[z];
	    r = z;
	 }
      }
      U[r] = 1;
   }
}
//func that converts list of edges to AM
void convert()
{
   int a, b, i, c, d;
   for ( i = 1; i <= vertices; ++i)
   {
      cin >> c;
      V[i] = c;
   }
   for ( i = 0; i < edges; i++ )
   {
      D[i+1] = INT_MAX;
      cin >> a >> b;
      d = abs( a - b);
      matrix[a][b] = d;
      matrix[b][a] = d; // if the graph is directed comment this line
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

