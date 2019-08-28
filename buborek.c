#include <stdio.h>

static int counter=0;

void buborekos( int t[], int n )
{
	int i, j;
	for( i = n -1; i > 0; --i){
		for( j = 0; j < i; ++j )
		{
			if( t[ j ] > t[ j + 1 ] )
			{
				t[j]=t[j]+t[j+1];
				t[j+1]=t[j]-t[j+1];
				t[j]=t[j]-t[j+1];
				counter++;
			}
		}
	}
}


int main()
{
 int tomb[]={64, 72, 20, 63, 42, 80, 85, 58, 93, 35, 67, 26, 50, 20, 82};
 int n=15;
 buborekos(tomb,n);
 printf("%d\n",counter );
 printf("\n");
 for (int i = 0; i < n; ++i)
 {
 	printf("%d\n",tomb[i] );
 }
 
 return 0;
}