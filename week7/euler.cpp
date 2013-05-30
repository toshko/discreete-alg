/* Program that implements the Euler
 * traversal with static stack */
#include <iostream>
#define MAXN 1000
using namespace std;

int S[MAXN],matrix[MAXN][MAXN], vertices, edges, top;
void make_empty();
void push(int x);
void pop();
void convert();
void eulerCircuit(int r);
int look();
bool not_empty();

int main()
{
   cin >> vertices >> edges;
   convert();
   eulerCircuit(1);

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

