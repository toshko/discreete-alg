/* Program that take a graph represented as
 * a list of edges and convert it to 
 * lists of neighbours(LN).
 */
#include <iostream>
#define MAXN 1000
using namespace std;

int vertices, edges;
int matrix[MAXN][MAXN] = {0};

void printLN(int matrix[MAXN][MAXN], int vertices);
void convert();

int main ()
{
	cin >> vertices >> edges;
	convert();
	printLN(matrix, vertices);
	return 0;
}

//func that converts list of edges to LN
void convert()
{
	int a, b, i;
	for ( i = 0; i < edges; i++ )
	{
		cin >> a >> b;
		matrix[a][0]++; // update the counter
		matrix[a][matrix[a][0]] = b; 
		matrix[b][0]++; // if the graph is directed comment the last two lines of the for cycle
		matrix[b][matrix[b][0]] = a;
	}

}

//func that prints the LN
void printLN(int matrix[][MAXN], int vertcs)
{
	int i, j;
	for (i = 1; i <= vertcs; i++) // loop starts from 1 because there is no vertex 0
	{
		for (j = 0; j <= vertcs; j++) // loop starts from 0 because in the zero element of every row is a counter of the neighbours
		{
			cout << matrix[i][j] << " "; 
		}
		cout << endl;
	}

}

