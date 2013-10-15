#include <iostream>
#define MAXN 10000
using namespace std;

int S[MAXN],matrix[MAXN][MAXN], vertices, edges, top;
void make_empty();
void push(int x);
void pop();
void convert();
void eulerCircuit(int r);
int look();
bool not_empty();

void oddDegree();
void connected();
int odd = 0;
int begin;
bool hasEuler = true;
bool conn = true;
int U[MAXN], E[MAXN], path = 0;

int main()
{
   cin >> vertices >> edges;
   convert();
   oddDegree();
   if (odd == 2)
   {
      eulerCircuit(begin);
   }
   else if (hasEuler)
   {
      eulerCircuit(1);
   }
   connected();
   if (conn)
   {
      for (int i = 0; i < path; i++)
      {
	 cout << E[i] << " ";
      }
      cout << endl;
   }
   else
   {
      cout << "Sorry, Pesho";
   }
   cout << endl;


}

void eulerCircuit(int r)
{
   make_empty();
   push(r);
   U[r] = 1;
   while(not_empty())
   {
      int t = look();
      if ( matrix[t][0] > 0 )
      {
	 int v = matrix[t][matrix[t][0]--];
	 for ( int j = 1; j <= matrix[v][0]; j++)
	 {
	    if(matrix[v][j] == t)
	    {
	       matrix[v][j] = matrix[v][matrix[v][0]--];
	       break;
	    }
	 }
	 push(v);
	 U[v] = 1;
      }
      else pop();
   }
}
void oddDegree()
{
   int i;
   for (i = 1; i <= vertices; i++)
   {
      if (matrix[i][0] % 2 != 0)
      {
	 odd++;
	 begin = i;
      }
   }

   if ( odd != 2 && odd != 0 )
   {
      hasEuler = false;
   }
}
void connected()
{
   for (int i = 1; i <= vertices; i++)
   {
      if( U[i] != 1)
      {
	 conn = false;
      }
   }
}

void convert()
{
   int a, b, i;
   for ( i = 0; i < edges; i++ )
   {
      cin >> a >> b;
      matrix[a][++matrix[a][0]] = b; 
      matrix[b][++matrix[b][0]] = a;
   }

}
void make_empty()
{
   top = -1;
}
void push(int x)
{
   S[++top] = x;
}
void pop()
{
   E[path++] = S[top--];
}
int look()
{
   return S[top];
}
bool not_empty()
{
   return top > -1;
}

