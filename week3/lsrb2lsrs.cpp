#include <iostream>
using namespace std;

#define MAXN 1000

int LSRS[MAXN][MAXN];
int vertices;

void convert();

int main()
{
   cin >> vertices;
   convert();
   for ( int i = 1; i <= vertices; ++i)
   {
      cout << LSRS[i][0] << " " << LSRS[i][1] << endl;
   }
}
void convert()
{
   int i, a, b, j;
   for ( i = 1; i <= vertices; ++i)
   {
      cin >> a >> b;
      if (a != 0)
      {
	 LSRS[i][0] = a;
      }
      if (b != 0)
      {
	 for ( j = 1; j <= vertices; ++j)
	 {
	    if ( LSRS[j][0] == i )
	    {
	       LSRS[j][1] = b;
	    }
	 }
      }
   }
}
