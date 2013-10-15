#include <iostream>
#include <climits>
#define MAXN 10000
using namespace std;

int vertices, edges;
int matrix[MAXN][MAXN], D[MAXN], U[MAXN], P[MAXN], C[MAXN][MAXN];

void printAM();
void convert();
void dijkstra(int r);

int SL[MAXN],R[MAXN], begin, end;
int tr, cnt = 0;
int main ()
{
   cin >> vertices >> edges >> begin >> end;
   convert();
   dijkstra(begin);
   tr = end;
   R[cnt++] = end;
   while (P[tr] != -1)
   {
      R[cnt++] = P[tr];
      tr = P[tr];
   }
   cnt--;

   for (int i = 0; cnt >= i; cnt--)
   {
      cout << R[cnt] << " ";

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
void convert()
{
   int a, b, i, c;
   for ( i = 1; i <= vertices; i++)
   {
      cin >> c;
      SL[i] = c;
   }

   for ( i = 0; i < edges; i++ )
   {
      D[i+1] = INT_MAX;
      cin >> a >> b;
      c = a - b;
      if ( c < 0 )
      {
	 c = c * -1;
      }
      matrix[a][b] = c;
      matrix[b][a] = c;
   }

}

