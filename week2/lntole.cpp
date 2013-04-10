/* Program that take a graph represented 
 * as a lists of neighbours and convert it to
 * list of edges.
 */
#include <iostream>
#define MAXN 1000
using namespace std;


void convert();
void convert_zero_ter();

int vertices, edges;
int list_edges[MAXN][MAXN];


int main ()
{
   cin >> vertices >> edges;
   convert();
   for (int i = 0; i < edges; i++)
   {
      cout << list_edges[i][0] << " ";
      cout << list_edges[i][1] << endl;
   }
}

void convert()
{
   int a, i, j, counter, position = 0;

   for (i = 1; i <= vertices; i++)
   {
      cin >> counter;
      for ( j = 0; j < counter; j++)
      {	
	 cin >> a;
	 if ( a > i) //If the graph is oriented comment this line.
	 {	
	    list_edges[position][0] = i;
	    list_edges[position++][1] = a;
	 }
      }
   }
}


void convert_zero_ter()
{
   int a, i, j, position = 0;

   for (i = 0; i < vertices; i++)
   {
      do 
      {
	 cin >> a;
      } while ( a == 0);

      while ( a != 0)
      {
	 if ( a > i+1 )  // i+1 because there is no vertex 0. If the graph is oriented comment this line.
	 {
	    list_edges[position][0] = i+1;
	    list_edges[position++][1] = a;
	 }

	 cin >> a;
      }
   }
}
