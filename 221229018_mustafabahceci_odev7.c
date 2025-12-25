#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void goster(char dizi[9][9])
{
	int	b=1,i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%c(%2d)|",dizi[i][j],b);
			b=b+1;	
		}
		printf("\n------------------------------------------------------");
		printf("\n");
	}
}
void oyna(char dizi[9][9])
{
	int x,y,i,j,a,b,uygun,gecici;
	do
	{
		printf("hangi tas nereye:");
		scanf("%d %d",&x,&y);
		uygun=1;
		i=(x-1)/9;
		j=(x-1)%9;
		a=(y-1)/9;
		b=(y-1)%9;
		if(((i==a && j-1==b) && j-1>-1) || ((i==a && j+1==b) && j+1<9) || ((i-1==a && j+1==b) && (i-1>-1 && j+1<9)) || ((i-1==a && j-1==b)&& (a>-1 && b>-1)) || ((i+1==a && j-1==b) && (a<9 && b>-1)) || ((i+1==a && j+1==b) && (a<9 && b<9)))
		{
			if(dizi[a][b]=='.')
			{
				uygun=1;
			}
			else
			{
				uygun=0;
			}
		}
		else
		{
			uygun=0;
		}
		if(((i-2==a && j-2==b) && dizi[i-2][j-2]=='2' && dizi[i-1][j-1]=='.') || ((i-2==a && j+2==b) && dizi[i-2][j+2]=='2' && dizi[i-1][j+1]=='.') || ((i+2==a && j-2==b) && dizi[i+2][j-2]=='2' && dizi[i+1][j-1]=='.') || ((i+2==a && j+2==b) && dizi[i+2][j+2]=='2' && dizi[i+1][j+1]=='.')) 
		{
			uygun=2;
		}
		if(dizi[i][j]!='1')
		{
			uygun=0;
		}
		if(y>81 || y<1 || x>81 || x<1)
		{
			uygun=0;
		}
		if(uygun==1)
		{
			gecici=dizi[i][j];
			dizi[i][j]=dizi[a][b];
			dizi[a][b]=gecici;
		}
		if(uygun==2)
		{
			dizi[i][j]='.';
			dizi[a][b]='1';
		}
	}
	while(uygun==0);
}
void bilgisayaroyna(char dizi[9][9],int *q)
{
	int x,uygun,i,j,a,b,gecici;
	x=1;
	uygun=1;
	while(x<82)
	{
		i=(x-1)/9;
		j=(x-1)%9;
		if(dizi[i][j]=='2')
		{
			if((i-2>-1 && j-2>-1) && dizi[i-2][j-2]=='1' && dizi[i-1][j-1]=='.')
			{
				uygun=2;
				a=i-2;
				b=j-2;
				dizi[a][b]=dizi[i-2][j-2];
				break;
			}
			if((i-2>-1 && j+2<9) && dizi[i-2][j+2]=='1' && dizi[i-1][j+1]=='.')
			{
				uygun=2;
				a=i-2;
				b=j+2;
				dizi[a][b]=dizi[i-2][j+2];
				break;
			}
			if((i+2<9 && j-2>-1) && dizi[i+2][j-2]=='1' && dizi[i+1][j-1]=='.')
			{
				uygun=2;
				a=i+2;
				b=j-2;
				dizi[a][b]=dizi[i+2][j-2];
				break;
			}
			if((i+2<9 && j+2<9) && dizi[i+2][j+2]=='1' && dizi[i+1][j+1]=='.')
			{
				uygun=2;
				a=i+2;
				b=j+2;
				dizi[a][b]=dizi[i+2][j+2];
				break;
			}
		}
		x=x+1;
	}
	if(uygun==2)
	{
		dizi[a][b]='2';
		dizi[i][j]='.';
		*q=*q+1;
		printf("bilgisayar %d yi tasidi\n",x);
	}
	if(uygun==1)
	{
		int y;
		do
		{
			uygun=1;
			x=rand()%81+1;
			y=rand()%81+1;
			i=(x-1)/9;
			j=(x-1)%9;
			a=(y-1)/9;
			b=(y-1)%9;
			if(dizi[i][j]=='2')
			{
				if((i==a && j-1==b) || (i==a && j+1==b) || (i-1==a && j+1==b) || (i-1==a && j-1==b) || (i+1==a && j-1==b) || (i+1==a && j+1==b)) 
				{
					if(dizi[a][b]=='.')
					{
						uygun=1;
					}
					else
					{
						uygun=0;
					}
				}
				else
				{
					uygun=0;
				}
			}
			else
			{
				uygun=0;
			}
            if(uygun==1)
            {
            	gecici=dizi[i][j];
				dizi[i][j]=dizi[a][b];
				dizi[a][b]=gecici;
				printf("bilgisayar %d yi %d yapti\n",x,y);
			}
		}
		while(uygun==0);
	}
}


int main(int argc, char *argv[]) {
	
	char dizi[9][9];
		
	int i,j;
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			dizi[i][j]='.';
		}
	}
	srand(time(0));
	
	int a,b=0;
	while(b<8)
	{
		a=rand()%81+1;
		i=(a-1)/9;
		j=(a-1)%9;
		if(dizi[i][j]=='.')
		{
			b=b+1;
			dizi[i][j]='1';
		}
	}
	
	b=0;
	int uygun;
	while(b<8)
	{
		uygun=1;
		a=rand()%81+1;
		i=(a-1)/9;
		j=(a-1)%9;
		if(dizi[i][j]!='.')
		{
			uygun=0;
		}
		if((i-2>-1 && j-2>-1) && dizi[i-2][j-2]=='1' && dizi[i-1][j-1]!='1')
		{
			uygun=0;
		}
		if((i-2>-1 && j+2<9) && dizi[i-2][j+2]=='1' && dizi[i-1][j+1]!='1')
		{
			uygun=0;
		}
		if((i+2<9 && j-2>-1) && dizi[i+2][j-2]=='1' && dizi[i+1][j-1]!='1')
		{
			uygun=0;
		}
		if((i+2<9 && j+2<9) && dizi[i+2][j+2]=='1' && dizi[i+1][j+1]!='1')
		{
			uygun=0;
		}
		if(uygun==1)
		{
			dizi[i][j]='2';
			b=b+1;
		}
	}
	int q=0;
	goster(dizi);
	oyna(dizi);
	goster(dizi);
	int c=0;
	while(c<5 || q<1)
	{
		printf("\n\n\n\n\n");
		bilgisayaroyna(dizi,&q);
		goster(dizi);
		oyna(dizi);
		goster(dizi);
		c=c+2;
	}
	
	
	
	
	
	
	return 0;
}
