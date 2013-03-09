/* Program that take a graph represented as
 * a list of edges and convert it to 
 * lists of neighbours(LN).
 */
#include <iostream>

using namespace std;

int vertices, edges;
int matrix[15][15] = {0};

void printLN(int m[15][15], int vertices);
void convert(int m[15][15], int edges);

int main ()
{
	cin >> vertices >> edges;
	convert(matrix, edges);
	printLN(matrix, vertices);
	return 0;
}

//func that converts list of edges to LN
void convert(int m[15][15], int edgs)
{
	int a, b, i;
	for ( i = 0; i < edgs; i++ )
	{
		cin >> a >> b;
		m[a][0]++; // update the counter
		m[a][m[a][0]] = b; 
		m[b][0]++; // if the graph is directed comment the last two lines of the for cycle
		m[b][m[b][0]] = a;
	}

}

//func that prints the LN
void printLN(int m[15][15], int vertcs)
{
	int i, j;
	for (i = 1; i <= vertcs; i++) // loop starts from 1 because there is no vertex 0
	{
		for (j = 0; j <= vertcs; j++) // loop starts from 0 because in the zero element of every row is a counter of the neighbours
		{
			cout << m[i][j] << " "; 
		}
		cout << endl;
	}

}

