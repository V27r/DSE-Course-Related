#include<iostream>
using namespace std;
int N;
int cost[10][10];
int permutations[10];
int bestCost=123478675;
int bestPermutation[10];

void generatePermutation(int depth)
{
	if(depth==N)
	{
		int currentCost=0;
		for(int i=0;i<N;i++)
			currentCost+=cost[i][permutations[i]];
		if(currentCost<bestCost)
		{
			bestCost=currentCost;
			for(int i=0;i<N;i++)
				bestPermutation[i]=permutations[i];
		}
	}
	else
	{
		for(int i=0;i<N;i++)
		{
			bool used=false;
			for(int j=0;j<depth;j++)
			{
				if(permutations[j]==i)
				{
					used=true;
					break;
				}
			}
			if(!used)
			{
				permutations[depth]=i;
				generatePermutation(depth+1);
			}
		}
	}
}
int main()
{
	cout<<"Enter size of matrix:";
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cout<<"Enter cost:";
		for(int j=0;j<N;j++)
			cin>>cost[i][j];
	}
	generatePermutation(0);
	cout<<"Best cost:"<<bestCost<<endl;
	cout<<"Best permutation:";
	for(int i=0;i<N;i++)
		cout<<bestPermutation[i]<<" ";
	return 0;
}