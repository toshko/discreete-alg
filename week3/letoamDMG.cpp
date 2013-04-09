/* Program that take a graph represented as
 * a list of edges and convert it to 
 * adjacency matrix(AM).
 */
#include <iostream>

using namespace std;

int vertices, edges;
int matrix[15][15] = {0};
int matrixb[15][15] = {0};

void printAM(int m[15][15], int vertices);
void convert(int m[15][15], int edges);
void power(int** m, int** z, int vertcs);
int main ()
{
	cin >> vertices >> edges;
	convert(matrix, edges);
	printAM(matrix, vertices);
	power(matrix, matrixb, vertices);
	power(matrixb, matrix, vertices);
	cout << endl;
	printAM(matrix, vertices);
	return 0;
}

//func that converts list of edges to AM
void convert(int m[15][15], int edgs)
{
	int a, b, i;
	for ( i = 0; i < edgs; i++ )
	{
		cin >> a >> b;
		m[a][b]++;
		//m[b][a] = 1; // if the graph is directed comment this line
	}

}
void power(int** m, int** z, int vertcs)
{
	int h, i, j, sum = 0;
	for ( h = 1; h <= vertcs; h++ )
	{
		for ( i = 1; i <= vertcs; i++ )
			{
				sum = 0;
				for ( j = 1; j <= vertcs; j++ )
				{
					sum += m[h][j] * m[j][i]; 
				}
				z[h][i] = sum;
			}
			
	}

}


//func that prints the AM
void printAM(int m[15][15], int vertcs)
{
	int i, j;
	for (i = 1; i <= vertcs; i++) // loops starts from 1 because there is no vertex 0
	{
		for (j = 1; j <= vertcs; j++)
		{
			cout << m[i][j] << " "; 
		}
		cout << endl;
	}

}

