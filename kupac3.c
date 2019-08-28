#include <stdio.h>
int counter=0;
void sullyeszt(int K[14], int honnan, int vege){

 int x=K[honnan];
 int gyermek=honnan+honnan;
 while (gyermek<=vege) {
   if (gyermek<vege && K[gyermek+1]>K[gyermek]) {gyermek=gyermek+1;counter++;}
   
   if (K[gyermek]>x){
     K[honnan]=K[gyermek];
     honnan=gyermek;
     gyermek=honnan+honnan;}
   else {gyermek=vege+1;}
}
K[honnan]=x;
}

int main(){
 
 int c=0;
 int a1=0;
 int a2=0;
 int a3=0;
 int meret=15;
 int K[16]={100, 37,27,39,93,46,78,50,89,84,95,48,94,5,43,15};
 int i=7;
 while (i>0) {
   sullyeszt(K, i, meret);
   i=i-1;
 }
 i=meret; a2=K[9];
 for(int j=1;j<14;j++) printf("%d\n",K[j]);
 printf("ennyi\n");
 while (i>1){
  c=K[1];
  K[1]=K[i];
  K[i]=c;
  i=i-1; a1=a1+1;
  sullyeszt(K,1,i); 
 }
for(i=1;i<14;i++) printf("%d\n",K[i]);
printf("%d %d %d %d",a1, a2, a3,counter);

}
