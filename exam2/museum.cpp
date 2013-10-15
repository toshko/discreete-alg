#include <iostream>
using namespace std;

#define MAXN 10000

void convert();
void DFS_R(int r);
void first_call();

int vertices, edges;
int m[MAXN][MAXN] = {0};
int U[MAXN], P[MAXN], T[MAXN], q;

int D[MAXN] = {0};
int cp[MAXN][MAXN];
void maxPath();
int maxHalls;
int main()
{
   cin >> vertices >> edges;
   convert();
   first_call();

   maxPath();
   cout << maxHalls << endl;
}


void convert()
{
   int a, b, i;
   for ( i = 0; i < edges; i++ )
   {
      cin >> a >> b;

      m[a][++m[a][0]] = b; 
      cp[a][++cp[a][0]] = b; // copy of the original matrix

   }

}

void first_call()
{
   int i;
   q = 0;
   for ( i = 1; i < vertices; ++i)
   {
      if (U[i] == 0) 
      {
	 DFS_R(i);
      }
   }
}

void DFS_R(int r)
{
   int y;
   U[r] = 1;
   while (m[r][0] > 0)
   {
      y = m[r][m[r][0]--];
      if (!U[y])
      {
	 U[y] = 1;
	 P[y] = r;
	 DFS_R(y);
      }
   } T[q++] = r; // topological sort
}        
void maxPath()
{
   int last = T[0];
   q--;
   while ( q >= 0 )
   {
      for(int i = cp[T[q]][0]; i > 0; --i)
      {
	 if ( D[T[q]] + 1 > D[cp[T[q]][i]] )
	 {
	    D[cp[T[q]][i]] = D[T[q]] + 1;
	 }
      }
      q--;
   }
   maxHalls = D[last] + 1;
}



