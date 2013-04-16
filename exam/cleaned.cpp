#include <iostream>
using namespace std;

#define MAXN 1100

void letoln();
void make_empty();
void push(int x);
void BFS(int r);
void forest();
bool not_empty();
int pop();
void result();

int Q[MAXN], b, e;
int U[MAXN];
int vertices, edges;
int m[MAXN][MAXN] = {0};
int num_edges, component = 1;
int max_cleaned[1][2]; 


int main()
{
   cin >> vertices >> edges;  
   letoln();
   forest();
   cout << max_cleaned[0][1] << endl;
   result();
}
void forest()
{
   int k;
   for (k = 1; k <= vertices; ++k)
   {
      if(U[k] == 0)
      {
	 BFS(k);
      }


   }
}
void BFS(int r)
{
   int x,y,i;
   num_edges = 0;
   make_empty();
   push(r);
   U[r] = component;
   while (not_empty())
   {
      x = pop();
      num_edges += m[x][0];
      for ( i = 1; i <= m[x][0]; ++i)
      {
	 y = m[x][i];
	 if (!U[y])
	 {
	    push(y);
	    U[y] = component;
	 }
      }
   }
   num_edges = num_edges/2;
   if ( num_edges > max_cleaned[0][1] )
   {
      max_cleaned[0][0] = component;
      max_cleaned[0][1] = num_edges;
   }
   component++;

}

void letoln()
{
   int a, b, i;
   for ( i = 0; i < edges; i++ )
   {
      cin >> a >> b;

      m[a][++m[a][0]] = b; 
      m[b][++m[b][0]] = a;

   }

}

void result()
{
   int i, j;

   for (i = 1; i <= vertices; i++)
   {
      if ( max_cleaned[0][0] == U[i] )
      {
	 for ( j = 1; j <= m[i][0]; j++)
	 {	

	    if ( m[i][j] > i ) 
	    {	
	       cout << i << " " << m[i][j] << endl;
	    }
	 }
      }
   }
}

void make_empty()
{
   b = 0;
   e = -1;
}

void push(int x)
{
   Q[++e] = x;
}

int pop()
{
   return Q[b++];
}

bool not_empty()
{
   return b <= e;
}
