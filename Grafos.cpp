#include <iostream>
using namespace std;

int main ()
{
int n,m,x,y,w,z,f,c;
 
cout<< "Digite n:";
cin>>n;
 
cout<< "Digite m:";
cin>>m;
 
char matriz [n][m];
 
for(f = 0; f < n; f++){
	for(c = 0; c < m; c++)
		cout<<"Digite la matriz["<<f<<"]["<<c<<"]:";
 
		in>>matriz [f][c];
 
		if(matriz [f][c]== 'A')
		{
			x = f; y = c;
		}
 
		if(matriz [f][c]== 'B')
		{
			w = f;
 			z = c;
		}
 
		}
 
}
 
for(f = 0; f < n; f++)
{
	cout<<endl;
 	for(c = 0; c < m; c++)
	{
		if(matriz[f][c]=='B')
 		{
		 	matriz[f][c]='A';
 			c=m; 
			f=n;
 		}else
 		{
		 	if(matriz[f][c]=='A')
 			{
			 	matriz[f][c]='.';
 			}
 			else
 			{
 				matriz[f][c]='.';
 			}
 	}
    for(int i=0;i<n;i++)
	{
 		for(intj=0;j<m;j++)
		{
			cout<<matriz[i][j];
 		}
 		cout<<endl;
	}
  }
 
 }
 
cout<<"\n"<<endl;
 
return 0;
}
