/* Program that take a graph represented 
 * as a lists of neighbours and convert it to
 * list of edges.
 */
#include <iostream>
using namespace std;


void convert(int le[20][2], int vertcs);
void convert_zero_ter(int le[20][2], int vertcs);

int vertices, edges;
int list_edges[20][2];


int main ()
{
	cin >> vertices >> edges;
	convert_zero_ter(list_edges, vertices);
	for (int i = 0; i < edges; i++)
	{
		cout << list_edges[i][0] << " ";
		cout << list_edges[i][1] << endl;
	}
}

void convert(int le[20][2], int vertcs)
{
	int a, i, j, counter, position = 0;

	for (i = 0; i < vertcs; i++)
	{
		cin >> counter;
		for ( j = 0; j < counter; j++)
		{	
			cin >> a;
			if ( a > i+1) // i+1 because there is no vertex 0. If the graph is oriented comment this line.
			{	
				le[position][0] = i+1;
				le[position++][1] = a;
			}
		}
	}
}


void convert_zero_ter(int le[20][2], int vertcs)
{
	int a, i, j, position = 0;

	for (i = 0; i < vertcs; i++)
	{
		do 
		{
			cin >> a;
		} while ( a == 0);

		while ( a != 0)
		{
			if ( a > i+1 )  // i+1 because there is no vertex 0. If the graph is oriented comment this line.
			{
				le[position][0] = i+1;
				le[position++][1] = a;
			}

			cin >> a;
		}
	}
}
