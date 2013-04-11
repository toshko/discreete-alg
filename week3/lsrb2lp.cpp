#include <iostream>
using namespace std;

#define MAXN 1000

int P[MAXN];
int vertices;

void convert();

int main()
{
   cin >> vertices;
   convert();
   for ( int i = 1; i <= vertices; ++i)
   {
      cout << P[i] << endl;
   }
}
void convert()
{
   int i, a, b;
   for ( i = 1; i <= vertices; ++i)
   {
      cin >> a >> b;
      if (a != 0)
      {
	 P[a] = i;
      }
      if (b != 0)
      {
	 P[b] = P[i];
      }
   }
}
