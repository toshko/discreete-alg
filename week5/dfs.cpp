#include <iostream>
using namespace std;

#define MAXN 1000

void convert();
bool not_empty();
void make_empty();
void push(int x);
void pop();
int  look();
void DFS(int r);
void DFS_R(int r);

int vertices, edges;
int m[MAXN][MAXN] = {0};
int S[MAXN], top;
int U[MAXN], P[MAXN];



int main()
{
   cin >> vertices >> edges;
   convert();
   DFS_R(1);

   for (int z = 1; z <= vertices; ++z)
      cout << z << " " << P[z] << endl;
}


void convert()
{
   int a, b, i;
   for ( i = 0; i < edges; i++ )
   {
      cin >> a >> b;

      m[a][++m[a][0]] = b; 
      m[b][++m[b][0]] = a; // if the graph is directed comment this line 

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
   }
}        


void DFS(int r)
{
   make_empty();
   push(r);
   U[r] = 1;
   P[r] = 0;
   while(not_empty())
   {
      int t = look();
      if(m[t][0] > 0)
      {
	 int v = m[t][m[t][0]--];
	 if (!U[v])
	 {
	    U[v] = 1;
	    P[v] = t;
	    push(v);
	 }
      }
      else
      {
	 pop();
      }

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
   top--;
}

int look()
{
   return S[top];
}

bool not_empty()
{
   return top > -1;
}

