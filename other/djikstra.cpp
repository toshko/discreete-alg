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
void djikstra(int r);

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

	djikstra(1);

	cout << "D: " << endl;;
	for(int i = 1; i<= N; i++)
	{
		cout << i << " " << D[i] << endl;;		
	}

	cout << "P: " << endl;
	for(int i = 1; i <= N; i++)
	{
		cout << i << " " << P[i] << endl;
	}
		
	cout << "U: " << endl;
	for(int i = 1; i <= N; i++)
	{
		cout << i << " " << U[i] << endl;
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
//djikstra
void djikstra(int r)
{   
	for(int i = 1; i <= N; i++)
	{
		P[i] = r;
		U[i] = 0;
		D[i] = AM[r][i];
	}

	P[r] = 0;
	U[r] = 1;
	D[r] = 0;		
    //relaxation
    
    for(int k = 2; k <= N; k++)
    {
    
    
         	cout << "D: " << endl;;
	for(int i = 1; i<= N; i++)
	{
		cout << D[i] << " ";		
	}    
    cout << endl;  
      for(int i = 1; i <= N; i++)
      {    
          int min = INF;   
          for(int j = 1; j <= N; j++)
          {
             if(D[j] < min && U[j] == 0)
             {
               min = D[j];
               r = j;                    
             }    
          }     
      }            
    
   
       U[r] = 1;
       cout << "R: " << r << endl;
        for(int w = 1; w <= N; w++)
        {
           if(D[r] + AM[r][w] < D[w] && U[w] == 0)
           {
               D[w] = D[r] + AM[r][w];    
           }     
        }
    }
}
