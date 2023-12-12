#include<iostream>
using namespace std;
bool isSafe(int **arr, int x, int y, int n)
{
	if(x-1>=0 && y-2>=0)
	{
		if(arr[x-1][y-2]==1)
		return false;
	}
	if(x-1>=0 && y+2<n)
	{
		if(arr[x-1][y+2]==1)
		return false;
	}
	if(x-2>=0 && y-1>=0)
	{
		if(arr[x-2][y-1]==1)
		return false;
	}
	if(x-2>=0 && y+1<n)
	{
		if(arr[x-2][y+1]==1)
		return false;
	}
	if(x+1<n && y-2>=0)
	{
		if(arr[x+1][y-2]==1)
		return false;
	}
	if(x+1<n && y+2<n)
	{
		if(arr[x+1][y+2]==1)
		return false;
	}
	if(x+2<n && y-1>=0)
	{
		if(arr[x+2][y-1]==1)
		return false;
	}
	if(x+2<n && y+1<n)
	{
		if(arr[x+2][y+1]==1)
		return false;
	}
	return true;
}
bool nKnight(int **arr, int x, int y, int n,int knights)
{	
	if(knights==0)
	{
		return true;
	}
//	if(y==n)
//	{
//		x+=1;
//		y = 0;
//	}
	for(int j=x;j<n;++j)
	{
		for(int i=y;i<n;++i)
		{
			if(isSafe(arr,j,i,n))
			{
				arr[j][i] = 1;
				if(nKnight(arr,j,i+1,n,knights-1))
				{
					return true;
				}
				arr[j][i] = 0;
			}
		}
		y=0;
	}
	return false;					
}
int main()
{
	int n;
	cout<<"Input N for NxN chess : ";
	cin>>n;
	int **arr= new int *[n];
	for(int i=0;i<n;++i)
	{
		arr[i] = new int[n];
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			arr[i][j] = 0;
		}
	}
	int knights;
	if(n%2==0)
	{
		knights = n*n/2;
	}
	else
	{
		knights = (n*n+1)/2;
	} 
	nKnight(arr,0,0,n,knights);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<arr[i][j]<<"  ";
		
		}
		cout<<endl;
	}
	for(int i=0;i<n;++i)
	{
		delete[] arr[i];
	}
	delete[] arr;	
}
