/* Program that implements the Euler
 * traversal with static stack */
#include <iostream>
#define MAXN 10000
using namespace std;

int S[MAXN],matrix[MAXN][MAXN],PATH[MAXN], vertices, edges, top, start, counter1 = 0;
int path = 0;
int edgecounter = 0;
int counter2 = 0;
void make_empty();
void push(int x);
void pop();
void convert();
void eulerCircuit(int r);
int look();
bool not_empty();
bool eulerCheck();
bool checks = true;
int main()
{
   cin >> vertices >> edges;
   convert();
   checks = eulerCheck();
   
   if ( checks && counter1 == 2)
   {
      eulerCircuit(start);
     
   }
   else if ( checks )
   {
      eulerCircuit(1);
   }
   else
   {
      cout << "Sorry, Pesho" << endl;
      return 0;
   }
   cout << endl;
   if ( edgecounter == edges )
   {
      int i = 0;
      while ( PATH[i] != 0)
      {
	 cout << PATH[i] << " ";
	 i++;
      }
      cout << endl;
   }
   else
   {
      cout << "Sorry, Pesho" << endl;
   }


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
	 edgecounter++;
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
   int counter = 0;
   bool check = true;
   for (int i = 1; i <= vertices; ++i)
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
counter1 = counter;
   
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
   //cout << S[top--] << " ";
   PATH[counter2++] = S[top--];
}
int look()
{
   return S[top];
}
bool not_empty()
{
   return top > -1;
}

