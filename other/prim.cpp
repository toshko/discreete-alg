#include <iostream>
using namespace std;

//max number of elements
const int MAXN = 100;

//simulate infinity
const int INF = 999;

//the number of vertices 
int N;
//the number of edges
int M;

//adjacency matrix
int AM[MAXN][MAXN];

//an array to mark used vertices
int U[MAXN+1] = {0};

//spanning tree 
int P[MAXN+1] = {0};

//distance array
int D[MAXN+1] = {0};

//prototypes
void readAM();
void printAM();
void prim(int r);

//main
int main()
{
	//reading the number of vertices
	cin >> N;
	//reading the number of edges
	cin >> M;

	//read
	readAM();

	//test print
	printAM();

    prim(1);

    cout << "P: " << endl;
    for(int i = 1; i <= N; i++)
    {
            cout << i << " " << P[i] << endl;
    }
    cout << "D: " << endl;
    for(int i = 1; i <= N; i++)
    {
            cout << i << " " << D[i] << endl;
    }

    

	return 0;
}
//functions
//reading AM
void readAM()
{
    //filling the matrix with infinity
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			AM[i][j] = INF;
		}
	}	
	//reading both ends of an edge
	//and recording its weight
	for(int i = 1; i <= M; i++)
	{
		//first vertex
		int a;
		cin >> a;
		//second vertex
		int b;
		cin >> b;
		//the weight
		int c;
		cin >> c;

		AM[a][b] = c;
		AM[b][a] = c;
	}
}
//printing AM
void printAM()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << AM[i][j] << " ";
		}
		cout << endl;
	}
}

void prim(int r)
{
    //marking
    for(int i = 1; i <= N; i++)
	{	
		U[i] = 0;    //every vertex is unused
		D[i] = r; //currently the shortest paths
	}
 
    U[r] = 1; //mark initial as used
    P[r] = 0; //r is root
    D[r] = 0; //r to r

    //we must use relaxation as in dijkstra 
    int counter = 1; //counter for the used vertices
    //while we don`t use every vertex
    while(counter != N)
    {
        int min = INF;
        int pos; //the w of the min edge
        for(int i = 1; i<= N; i++)
        {
             if(U[i] == 0 && AM[i][D[i]] < min)
             {
                    min = AM[i][D[i]];
                    pos = i;                  
             }       
        }
        cout << "Min pos: " << pos << endl;
        cout << "Min edge: " << D[pos] << endl;

        U[pos] = 1;
        P[pos] = D[pos];       

        for(int i = 1; i <= N; i++)
        {
            if(U[i] == 0 && AM[i][D[i]] > AM[i][pos])
            {
                 D[i] = pos;
            }    
        }
 
        counter++;        
    }         
}
