/* A program that take a graph represented as
 * an lists of neighbours and convert it to
 * list of edges.
 */
#include <iostream>
#define MAXN 1000
using namespace std;

int vertices, edges;
int matrix[MAXN][MAXN];

void convert();
void printAM();

int main ()
{
   cin >> vertices >> edges;
   convert();
   printAM();

}

void convert()
{
   int a, i, j, counter;

   for (i = 1; i <= vertices; i++)
   {
      cin >> counter;

      for ( j = 1; j <= counter; j++)
      {	
	 cin >> a;

	 matrix[i][a]++;
      }
   }
}
void printAM()
{
   int i, j;
   for (i = 1; i <= vertices; i++) // loops starts from 1 because there is no vertex 0
   {
      for (j = 1; j <= vertices; j++)
      {
	 cout << matrix[i][j] << " "; 
      }
      cout << endl;
   }

}

