#include<iostream>
using namespace std;
int main()
{
    struct poly
    {
        int c;
        int e;
    };
    int n,m,i,j,k;
    cout<<"Enter number of terms in first polynomial:";
    cin>>n;
    poly p1[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter coefficient:";
        cin>>p1[i].c;
        cout<<"Enter exponent:";
        cin>>p1[i].e;
    }
    cout<<"Enter number of terms in second polynomial:";
    cin>>m;
    poly p2[m];
    poly p3[100];
    for(i=0;i<m;i++)
    {
        cout<<"Enter coefficient:";
        cin>>p2[i].c;
        cout<<"Enter exponent:";
        cin>>p2[i].e;
    }
    i=0;
    j=0;
    k=0;
    while(i<n && j<m)
    {
        if(p1[i].e>p2[j].e)
        {    
            p3[k].e=p1[i].e;
            p3[k].c=p1[i].c;
            i++;
            k++;
        }
        else if(p2[j].e>p1[i].e)
        {    
            p3[k].e=p2[j].e;
            p3[k].c=p2[j].c;
            j++;
            k++;
        }
        else
        {
            p3[k].c=p2[j].c+p1[i].c;
            p3[k].e=p2[j].e;
            i++;
            j++;
            k++;
        }
    }
    while(i<n)
    {
        p3[k].c=p1[i].c;
        p3[k].e=p1[i].e;
        i++;
        k++;
    }
    while(j<m)
    {    
        p3[k].c=p2[j].c;
        p3[k].e=p2[j].e;
        j++;
        k++;
    }
    cout<<"Polynomial after addition:\n";
    for(i=0;i<k-1;i++)
        if(p3[i].c!=0)
            cout<<p3[i].c<<"x^"<<p3[i].e<<" + ";
        else
            cout<<0<<" + ";
    if(p3[i].c!=0)
        cout<<p3[i].c<<"x^"<<p3[i].e;
    else
        cout<<0;
    return 0;
}