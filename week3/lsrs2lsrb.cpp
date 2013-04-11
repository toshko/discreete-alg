#include <iostream>
using namespace std;

#define MAXN 1000

int LSRB[MAXN][MAXN];
int vertices;

void convert();

int main()
{
   cin >> vertices;
   convert();
   for ( int i = 1; i <= vertices; ++i)
   {
      cout << LSRB[i][0] << " " << LSRB[i][1] << endl;
   }
}
void convert()
{
   int i, a, b;
   for ( i = 1; i <= vertices; ++i)
   {
      cin >> a >> b;
      if ( a != 0 )
      {
	 LSRB[i][0] = a;
	 LSRB[a][1] = b;
      }
   }
}
