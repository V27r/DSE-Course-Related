#include<iostream>
using namespace std;
int main()
{
    struct Sparse
    {
        int row;
        int col;
        int val;    
    };
    int m,n,count=0,i,j;
    int a[10][10];
    cout<<"Enter number of rows and columns:";
    cin>>m>>n;
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<"Enter a["<<(i+1)<<"]["<<(j+1)<<"]:";
                cin>>a[i][j];
                if(a[i][j]!=0)
                count++;
            }
        }
    Sparse s[count];
    s[0].row=m;
    s[0].col=n;
    s[0].val=count;
    int k=1;
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                s[k].row=i;
                s[k].col=j;
                s[k].val=a[i][j];
                k++;
            }
        }
    }
    cout<<"Sparse in 1D:\n";
    cout<<s[0].row<<" "<<s[0].col<<" "<<s[0].val<<"\n";
    for(i=1;i<count+1;i++)
    {
        
        cout<<s[i].row<<" "<<s[i].col<<" "<<s[i].val;
        cout<<"\n";
    }
    int b[s[0].row][s[0].col]={};
    cout<<"Reconstructed sparse matrix:\n";
    for(i=0;i<s[0].val;i++)    
        b[s[i+1].row][s[i+1].col]=s[i+1].val;
    for(i=0;i<s[0].row;i++)
    {
        for(j=0;j<s[0].col;j++)
            cout<<b[i][j]<<" ";
        cout<<"\n";
    }        
    return 0;
}