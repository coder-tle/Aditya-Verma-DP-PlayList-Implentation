#include<bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[])
    {
        // code here
		int sum = 0;
		for(int i = 0; i<N; i++)
		sum += arr[i];
		
		if(sum % 2 == 1)
		return 0;
		sum = sum /2 ;
		
		bool dp[ N + 1][sum + 1];
		
		
		// Initialization of matrix
		for( int i = 0; i<=N; i++)
		{
			for(int j = 0; j<=sum; j++)
			{
				if(i == 0)
				dp[i][j] = false;
				if(j == 0)
				dp[i][j] = true;
			}
		}
		
		for(int i = 1; i <=N; i++)
		{
			for(int j = 1; j<=sum; j++)
			{
				if(arr[i-1] <= j)
				{
					dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
				}
				else
				dp[i][j] = dp[i-1][j];
			}
		}
		if(dp[N][sum] == true)
		return 1;
		else
		return 0; 
		
    }

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i = 0; i<n ; i++)
	{
		cin>>arr[i];
		
	}
	if(equalPartition(n, arr) == 1)
	cout<<"YES\n";
	else
	cout<<"NO\n";
	
	return 0;
	
	
}
