/* Program that implements Dijkstra algorithm
*/
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdio>
#define MAXN 1000
using namespace std;

int vertices, edges;
int matrix[MAXN][MAXN], P[MAXN][MAXN];

void printAM();
void convert();
void floyd();
void path(int v, int w);

int main ()
{
   cin >> vertices >> edges;
   convert();
   floyd();
   cout << 5 << " ";
   path(4, 7);
   cout << 7 << endl;
   printAM();
   cout << endl;

   return 0;
}

void floyd()
{
   int  i,j,k; 
   for( k=1; k <= vertices; k++)
   {
      for(i=1;i<=vertices;i++)
      {
	 for(j=1;j<=vertices;j++)
	 {
	    if(matrix[i][k]+matrix[k][j]<matrix[i][j])  
	    {
	       matrix[i][j]=matrix[i][k]+matrix[k][j];
	       P[i][j]=k;
	    }
	 }
      }
   }
}
void path(int v, int w)
{
   if(P[v][w]!=0) 
   {  
      path(v, P[v][w]);
      printf("%d ", P[v][w]);   
      path(P[v][w],w);
   }
}


//func that converts list of edges to AM
void convert()
{
   int a, b, i, c, j;
   for ( i = 1; i <= vertices; i++ )
   {
      for ( j = 1; j <= vertices; ++j)
      {
	 matrix[i][j] = SHRT_MAX;
      }
      matrix[i][i] = 0;
   }

   for ( i = 0; i < edges; i++ )
   {
      cin >> a >> b >> c;
      matrix[a][b] = c;
      matrix[b][a] = c;
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
	 cout << setw(3);
	 cout << matrix[i][j] << " "; 
      }
      cout << endl;
   }
   cout << endl;

}

