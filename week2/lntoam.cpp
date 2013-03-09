/* A program that take a graph represented as
 * an lists of neighbours and convert it to
 * list of edges.
 */
#include <iostream>
using namespace std;

int vertices, edges;
int matrix[15][15];

void convert(int am[15][15], int vertcs);
void printAM(int am[15][15], int vertcs);

int main ()
{
	cin >> vertices >> edges;
	convert(matrix, vertices);
	printAM(matrix, vertices);
	
}

void convert(int am[15][15], int vertcs)
{
	int a, i, j, counter, position = 0;

	for (i = 0; i < vertcs; i++)
	{
		do
		{
			cin >> counter;
		} while ( counter == 0 );

		for ( j = 0; j < counter; j++)
		{	
			cin >> a;
			
			am[i+1][a] = 1;
		}
	}
}
void printAM(int am[15][15], int vertcs)
{
	int i, j;
	for (i = 1; i <= vertcs; i++) // loops starts from 1 because there is no vertex 0
	{
		for (j = 1; j <= vertcs; j++)
		{
			cout << am[i][j] << " "; 
		}
		cout << endl;
	}

}

