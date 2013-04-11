#include <iostream>
#define MAXN 1000
using namespace std;


void convert();

int vertices, edges = 0;
int list_edges[MAXN][MAXN];


int main ()
{
   cin >> vertices;
   convert();
   cout << vertices << " " << edges << endl;
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
	 list_edges[position][0] = i;
	 list_edges[position++][1] = a;
	 edges++;
      }
   }
}



