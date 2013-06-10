#include <iostream>
using namespace std;

const int MAXN = 100;

//the number of vertices
int N;
//the number of edges
int M;
//the adjacency matrix
int AM[MAXN][MAXN] = {0};

//the stack
int S[MAXN+1] = {0};
int top;

//prototypes
void LE2AM();
void make_empty();
void push(int);
void pop();
int look();
bool not_empty();
void euler_cycle(int);

//main
int main()
{
	//reading the number of vertices
	cin >> N;
	//reading the number of edges
	cin >> M;

	//converting	
	LE2AM();
	
	//test euler
	euler_cycle(1);	

	return 0;
}
//functions
void LE2AM()
{
	for(int i = 1; i <= M; i++)
	{
		int a;
		cin >> a;
		int b;
		cin >> b;

		//recording neighbours and number of neighbours
		AM[a][b]++;
		AM[a][0]++;
		AM[b][a]++;
		AM[b][0]++;
	}
}
//make_empty
void make_empty()
{
	top = -1;
}
//push
void push(int x)
{
	S[++top] = x;
}
//pop
void pop()
{
	top--;
}
//look
int look()
{
	return S[top];
}
//not_empty
bool not_empty()
{
	return top > -1;
}

void euler_cycle(int r)
{
	//row 0 keeps track of position
	//we fill it with 1s 
	for(int i = 1; i <= N; i++)
	{
		AM[0][i] = 1;
	}	

	//create the stack
	make_empty();

	//push the starting vertex
	push(r);
	
	while(not_empty())
	{
		int t = look();
	
		if(AM[t][0] > 0)
		{
			//v is the next neighbour
			//is it 0 or 1... 
			int v = AM[t][AM[0][t]];
			
			if(v > 0)
			{
				v = AM[0][t];
	
				AM[t][0]--;
				AM[t][v]--;
				AM[v][0]--;
				AM[v][t]--;
				push(v);
			}
			else
			{
				//we move to the next position
				AM[0][t]++;
			}
		}		
		else
		{
			//E[e_index++] = look();			
			cout << look() << " ";
			pop();
		}
	}	
	cout << endl;
}
