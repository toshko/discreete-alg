/* Program that take a graph represented as
 * an adjacency matrix(AM) and convert it to
 * list of edges.
 */
#include <iostream>
using namespace std;

int lists_nbors[20][20];
int vertices, edges;

void printLN(int m[][20], int vertices);
void convert(int list_n[][20], int vertcs);

int main()
{
	cin >> vertices >> edges;
	convert(lists_nbors, vertices);
	printLN(lists_nbors, vertices);
}

void convert(int ln[][20], int vertcs)
{
	int a, i, j;
	for (i = 0; i < vertcs; i++)
	{
		for (j = 0; j < vertcs; j++)
		{
			cin >> a;
			if ( a == 1)
			{
				ln[i+1][0]++; // i+1 because there is no vertex 0
				ln[i+1][ln[i+1][0]] = j+1;
			}
		}
	}
}

void printLN(int m[][20], int vertices)
{
	int i, j;
	for (i = 1; i <= vertices; i++) // loop starts from 1 because there is no vertex 0
	{
		for (j = 0; j <= vertices; j++) // loop starts from 0 because in the zero element of every row is a counter of the neighbours
		{
			if ( m[i][j] != 0)
			cout << m[i][j] << " "; 
		}
		cout << endl;
	}

}
