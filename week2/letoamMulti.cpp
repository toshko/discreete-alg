/* Program that take a graph represented as
 * a list of edges and convert it to 
 * adjacency matrix(AM).
 */
#include <iostream>
#define MAXN 1000
using namespace std;

int vertices, edges;
int matrix[MAXN][MAXN];

void printAM();
void convert();

int main ()
{
	cin >> vertices >> edges;
	convert();
	printAM();
	return 0;
}

//func that converts list of edges to AM
void convert()
{
	int a, b, i;
	for ( i = 0; i < edges; i++ )
	{
		cin >> a >> b;
		matrix[a][b]++;
		matrix[b][a]++; // if the graph is directed comment this line
	}

}

//func that prints the AM
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

