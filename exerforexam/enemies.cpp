#include <iostream>
using namespace std;

#define MAXN 1000

void convert();
void make_empty();
void push(int x);
void BFS(int r);
void forest();
bool not_empty();
int pop();
bool isEven(int x);

int level = 0;
int marker = 0;
int Q[MAXN], b, e;
int U[MAXN], P[MAXN], L[MAXN];
int vertices, edges;
int m[MAXN][MAXN] = {0};
int am[MAXN][MAXN] = {0};
bool possible = true;

int main()
{
   cin >> vertices >> edges;  
   convert();
   forest();
   for (int i = 1; i <= vertices; ++i )
   {
      for (int j = 1; j <= vertices; ++j)
      {
	 cout << m[i][j] << " ";
      }
      cout << endl;
   }
   if ( possible )
      cout << "YES" << endl;
   else
      cout << "NO" << endl;
}
void forest()
{
   int i;
   for (i = 1; i<= vertices; ++i)
   {
      if(P[i] == 0 && possible)
      {
	 BFS(i);
      }
   }
}
void BFS(int r)
{
   int x,y,i;
   make_empty();
   push(r);
   U[r] = 1;
   P[r] = -1;
   marker = r;
   L[y] = 0;
   while (not_empty())
   {
      x = pop();
      for ( i = 1; i <= m[x][0]; ++i)
      {
	 y = m[x][i];
	 //cout << y << " ";
	 if (!U[y])
	 {
//	    cout << level << endl;
	    cout << endl;
	    push(y);
	    U[y] = 1;
	    P[y] = x;
	    if (isEven(level + 1))
	    {
	       L[y] = 0;
	    }
	    else
	    {
	       L[y] = 1;
	    }
	 }
	 else if( (!isEven(level) && isEven(L[y])) || (isEven(level) && !isEven(L[y])) )
	 {
	    if ((P[y] != -1) && (y != P[x]) )
	    {
	       possible = false;
	       cout << y << " " << U[y] << " " << P[y] << " " << level << " " << L[y] << endl;
	       break;
	    }
	 }
      }
	 if (marker == x)
	 {
	    marker = Q[e];
	    level++;
	 }
      

   }
}

void convert()
{
   int a, b, i, j;
   for ( i = 1; i <= vertices; ++i )
   {
      for ( j = 1; j <= vertices; ++j)
      {
	 am[i][j] = 1;
      }
      am[i][i] = 0;
   }
   for (i = 0; i < edges; ++i)
   {
      cin >> a >> b;
      am[a][b] = 0;
      am[b][a] = 0;
   }
   for (i = 1; i <= vertices; ++i)
   {
      for (j = 1; j <= vertices; ++j)
      {
	 if (am[i][j] == 1)
	 {
	    m[i][++m[i][0]] = j;
	 }
      }
   }


}

bool isEven(int x)
{
   return x % 2 == 0;
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
