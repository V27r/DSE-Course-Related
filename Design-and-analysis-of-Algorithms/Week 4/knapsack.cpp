#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Knapsack(unsigned int *w, unsigned int *v, unsigned int n, unsigned int B)
{
        unsigned int i,temp,maxVal=0,maxSequence=0,totalWeight,totalValue,index=0; 
        for(i=1;i<pow(2,n);i++)
        {
            temp = i;
            totalWeight=totalValue=0;
			index=0;
            while(temp) 
			{
                if(temp & 0x1) 
				{
                	totalWeight=totalWeight+w[index];
                    totalValue=totalValue+v[index];
                }
				index++;
                temp=temp>>1;
            }
            if(totalWeight<=B && totalValue>maxVal) 
			{
                maxVal=totalValue;
                maxSequence=i;
            }
    }
    return maxSequence;
}    
int  main() 
{
    unsigned int *v,*w,i,n,knaps,B;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    v=(unsigned int *)calloc(n, sizeof(unsigned  int));
    w=(unsigned int *)calloc(n, sizeof(unsigned int)); 
    printf("Enter the weights:");
    for(i=0;i<n;i++) 
        scanf("%d",&w[i]);
    printf("Enter the values:");
    for(i=0;i<n;i++)
    	scanf("%d",&v[i]);
    printf("Enter the Knapsack capacity:");
    scanf("%d", &B);
    knaps = Knapsack(w,v,n,B);
    printf("Knapsack contains the following items\n");
	i=0;
    while(knaps) 
	{
        if(knaps & 0X1)
        	printf("item %u\tvalue %u", (i+1), v[i]);
        printf("\n");
        i++;
        knaps=knaps>>1;
    } 
	return 0;     
}
