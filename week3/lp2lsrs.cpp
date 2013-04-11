#include <iostream>
using namespace std;
#define MAXN 1000

void convert();
void readParents();

int vertices;
int LSRB[MAXN][2];
int P[MAXN];



int main()
{
   cin >> vertices;

   readParents();
   convert();
   for (int i = 1; i <= vertices; i++)
   {
      cout << LSRB[i][0] << " " << LSRB[i][1] << endl;
   }
}


void readParents()
{
   int i;
   for (i = 1; i <= vertices; ++i)
   {
      cin >> P[i];
   }
}
void convert()
{
   int i, z, j;
   for ( i = 1; i <= vertices; ++i)
   {

      for ( z = 1; z <= vertices; ++z)
      {
	 if (P[z] == i)
	 {
	    LSRB[i][0] = z;
	    break;
	 }
      }
      for ( j = 1; j <= vertices; ++j )
      {
	 if(P[j] == i &&  j > z)
	 {
	    LSRB[i][1] = j;
	 }
      }
   }

}
