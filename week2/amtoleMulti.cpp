/* Program that take a graph represented as
 * an adjacency matrix(AM) and convert it to
 * list of edges.
 */
#include <iostream>
#define MAXN 1000
using namespace std;

void convert();
void convert_to_array();

int list_of_edges[MAXN][MAXN] = {0};
int vertices, edges;

int main ()
{
   cin >> vertices >> edges;
   //convert(vertices);

   convert_to_array();

   for (int i = 0; i < edges; i++)
   {
      cout << list_of_edges[i][0] << " ";
      cout << list_of_edges[i][1] << endl;
   }


   return 0;
}

//func that converts AM to list of edges
void convert()
{
   int a, i, j;
   for ( i = 1; i <= vertices; i++ )
   {
      for ( j = 1; j <= vertices; j++)
      {
	 cin >> a;
	 if ( a == 1 && j >= i) // if the graph is oriented 'j >= i' condition has to be omited
	 {
	    cout << i << " " << j << endl; 
	 }
      }
   }

}

//func that converts AM to list of edges and store it in an array
void convert_to_array()
{
   int a, i, j, k, counter = 0;
   for ( i = 1; i <= vertices; i++ )
   {
      for ( j = 1; j <= vertices; j++)
      {
	 cin >> a;
	 if ( a != 0 && j >= i)  // if the graph is oriented 'j >= i' condition has to be omited
	 {
	    for ( k = 0; k < a; k++ )
	    {
	       list_of_edges[counter][0] = i;
	       list_of_edges[counter++][1] = j;
	    }
	 }
      }
   }
}
