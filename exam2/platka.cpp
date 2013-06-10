/* Program that implements the Euler
 * traversal with static stack */
#include <iostream>
#define MAXN 10000
using namespace std;

int S[MAXN],matrix[MAXN][MAXN], vertices, edges, top, start, counter = 0;
void make_empty();
void push(int x);
void pop();
void convert();
void eulerCircuit(int r);
int look();
bool not_empty();
bool eulerCheck();
int main()
{
   cin >> vertices >> edges;
   convert();
   if ( eulerCheck() && counter == 2)
   {
      eulerCircuit(start);
   }
   else if ( eulerCheck() )
   {
      eulerCircuit(1);
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
      }
      else pop();
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

bool eulerCheck()
{
   bool check = true;
   for (int i = 0; i < vertices; ++i)
   {
      if(matrix[i][0] % 2 != 0)
      {
	 counter++;
	 start = i;
      }

   }

   if (counter != 2 || counter > 2)
   {
      check = false;
   }

   return check;

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
   cout << S[top--] << " ";
}
int look()
{
   return S[top];
}
bool not_empty()
{
   return top > -1;
}

