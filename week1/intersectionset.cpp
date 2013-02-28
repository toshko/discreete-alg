#include <iostream>
using namespace std;

void read(int SetA[], int SetB[], int m, int n);
void solve(int SetA[], int SetB[], int result[], int m, int n);
 
#define MAXN 1000
int m, n, counter;
int SetA[MAXN], SetB[MAXN], result[MAXN];

int main()
{
	cin >> m;
	cin >> n;
	read(SetA, SetB, m, n);
	solve(SetA, SetB, result, m, n);
	for (int i = 0; i < counter; i++)
	{
			cout << result[i] << endl;
	}	
	
	

	return 0;
}

void read(int SetA[], int SetB[], int m, int n)
{	
	
	int i;
	
	for (i = 0; i < m; ++i)
	{
			cin >> SetA[i];
	}
	
	for (i = 0; i < n; ++i)
	{
			cin >> SetB[i];
	}
	
}

void solve(int SetA[], int SetB[], int result[], int m, int n)
{
	
	int i;
	int j;
	counter = 0;
	
	for (i = 0, j = 0; i < m && j < n; )
	{
		if ( SetA[i] < SetB[j] )
		{
			result[counter++] = SetA[i];
			i++;
		}
		else if ( SetB[j] < SetA[i] )
		{
			result[counter++] = SetB[j];
			j++;
		}
		else 
		{
			result[counter++] = SetB[j];
			j++;
			i++;
		}
	}
	
	if ( i < m )
	{
		for (; i < n ; )
			result[counter++] = SetA[i++];
	}
	else
	{
		for (; j < n ; )
			result[counter++] = SetB[j++];
	}
			result[counter] = -1;
	
}
