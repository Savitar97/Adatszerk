#include <stdio.h>
static int counter,elso;
void csere(int* a, int* b) { int t = *a; *a = *b;  *b = t; }
void sulyed(int K[],int honnan,int vege)
{
	int x=K[honnan];
	int gyermek=honnan+honnan;
	while(gyermek<=vege)
	{
		if(gyermek<vege && K[gyermek+1]>K[gyermek])
			{gyermek=gyermek+1;
				counter++;
			}
		if(K[gyermek]>x)
		{
			K[honnan]=K[gyermek];
			honnan=gyermek;
			gyermek=honnan+honnan;
		}
		else
			{gyermek=vege+1;}
	}
	K[honnan]=x;
}
void kupac(int K[],int size)
{
	int i=size/2;
	size=size-1;
	while(i>=0)
	{
		sulyed(K,i,size);
		i=i-1;
	}
	elso=K[0];
	i=size;
	while(i>=1)
	{
		csere(&K[0],&K[i]);
		i=i-1;
		sulyed(K,0,i);
	}
}

int main()
{
	int A[]={37,27,39,93,46,78,50,89,84,95,48,94,5,43,15};
	int size=sizeof(A)/sizeof(A[0]);
	printf("%d\n",size/2 );
	printf("\n");
	kupac(A,size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n",A[i] );
	}
	printf("\n");
	printf("%d\n",counter );
	printf("\n");
	printf("%d\n",elso );	
	printf("\n");
	return 0;
}
