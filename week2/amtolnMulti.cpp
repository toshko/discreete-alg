/* Program that take a graph represented as
 * an adjacency list_nbors(AM) and convert it to
 * list of edges.
 */
#include <iostream>
#define MAXN 1000
using namespace std;

int lists_nbors[MAXN][MAXN];
int vertices, edges;

void printLN();
void convert();

int main()
{
	cin >> vertices >> edges;
	convert();
	printLN();
}

void convert()
{
	int a, i, j;
	for (i = 1; i <= vertices; i++)
	{
		for (j = 1; j <= vertices; j++)
		{
			cin >> a;
			if ( a != 0)
			{
				lists_nbors[i][0]++; 
				lists_nbors[i][lists_nbors[i][0]] = j;
			}
		}
	}
}

void printLN()
{
	int i, j;
	for (i = 1; i <= vertices; i++) // loop starts from 1 because there is no vertex 0
	{
		for (j = 0; j <= vertices; j++) // loop starts from 0 because in the zero element of every row is a counter of the neighbours
		{
			if ( lists_nbors[i][j] != 0)
			cout << lists_nbors[i][j] << " "; 
		}
		cout << endl;
	}

}
