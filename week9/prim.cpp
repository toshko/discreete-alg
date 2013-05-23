/* Program that implements Prim Algorithm */
#include <iostream>
#include <climits>
#define MAXN 10000
using namespace std;

void convert();
void prim(int r);

int vertices, edges;
int AM[MAXN][MAXN], U[MAXN], P[MAXN], D[MAXN];

int main()
{
   cin >> vertices >> edges;
   convert();
   prim(1);
   for (int i = 1; i <= vertices; ++i)
   {
      cout << i << " " << P[i] << endl;
   }

}

//create AM of the graph from LE
void convert()
{
   int i, j, a, b, c;
   //fill the AM with infinity(SHRT_MAX)
   for ( i = 1; i <= vertices; ++i)
   {
      for ( j = 1; j <= vertices; ++j)
      {
	 AM[i][j] = SHRT_MAX;
      }
      AM[i][i] = 0; // the path from a vertex to itself is zero
   }

   //fill with actual weight
   for ( i = 1; i <= edges; ++i)
   {
      cin >> a >> b >> c;

      AM[a][b] = c;
      AM[b][a] = c;
   }
}

void prim(int r)
{
   int i, j, k, minc, minv;
   P[r] = 0;
   U[r] = 1;

   //Set the closest vertex to every vertex in U
   for ( i = 1; i <= vertices; ++i)
   {
      //for the first step only r is in U
      D[i] = r;
   }

   for ( i = 1; i < vertices; ++i)
   {
      minc = SHRT_MAX;
      minv = 0;
      for ( j = 1; j <= vertices; ++j)
      {
	 if ( U[j] == 0 && AM[j][D[j]] < minc)
	 {
	    minc = AM[j][D[j]];
	    minv = j;
	 }
      }
      P[minv] = D[minv];
      U[minv] = 1;
      for ( j = 1; j <= vertices; j++)
      {
	 if( U[j] == 0 && AM[j][D[j]] > AM[j][minv])
	 {
	    D[j] = minv;
	 }

      }
   }
}

