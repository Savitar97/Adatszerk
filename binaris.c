#include <stdio.h>

int binaris( int t[], int n, int ertek)
{
	int also=0,felso=n-1,kozepso=0;
	while(also<=felso)
		{
			int lepteto=0;
			kozepso=(also+felso)/2;
			printf("%d\n",kozepso+1 );

			if(t[kozepso]==ertek)
				{
					return kozepso+1;
				}
			else if(t[kozepso]>ertek)
				{
					felso=kozepso-1;
				}
			else {also=kozepso+1;}
		}
	return -1;
}

int main()
  {
  	 int t[]={2,  4,  5,  8, 12, 13, 17, 18, 21, 25, 29, 30, 33, 37, 38, 41, 42, 46, 49, 53, 54, 58, 59, 63, 65, 68, 72, 75, 78, 79, 83};
  	 int n=31;
  	 int ertek=18;
  	 binaris(t,n,ertek);
  	 return 0;
  }