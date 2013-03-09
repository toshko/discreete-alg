/* Program that take a graph represented as
 * an adjacency matrix(AM) and convert it to
 * list of edges.
 */
#include <iostream>

using namespace std;

void convert(int vertcs);
void convert_to_array(int le[][2], int vertcs);

int list_of_edges[50][2] = {0};
int vertices, edges;

int main ()
{
	cin >> vertices >> edges;
	convert(vertices);

	/* convert_to_array(list_of_edges, vertices);

	for (int i = 0; i < edges; i++)
	{
		cout << list_of_edges[i][0] << " ";
		cout << list_of_edges[i][1] << endl;
	}
	*/

	return 0;
}

//func that converts AM to list of edges
void convert(int vertcs)
{
	int a, i, j;
	for ( i = 0; i < vertcs; i++ )
	{
		for ( j = 0; j < vertcs; j++)
		{
			cin >> a;
			if ( a == 1 && j >= i) // if the graph is oriented 'j >= i' condition has to be omited
			{
				cout << i+1 << " " << j+1 << endl; // Add +1 because there is no vertex 0
			}
		}
	}

}

//func that converts AM to list of edges and store it in an array
void convert_to_array(int le[][2], int vertcs)
{
	int a, i, j, counter = 0;
	for ( i = 0; i < vertcs; i++ )
	{
		for ( j = 0; j < vertcs; j++)
		{
			cin >> a;
			if ( a == 1 && j >= i)  // if the graph is oriented 'j >= i' condition has to be omited
			{
				le[counter][0] = i+1;
				le[counter++][1] = j+1;
			}
		}
	}
}
