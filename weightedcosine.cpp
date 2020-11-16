#include<bits/stdc++.h>
using namespace std;

int num_of_doc;
int item;
int doc[100][100];
int num1,num2;





void create_doc()
{
    for(int i=0;i<num_of_doc;i++)
    {
        for(int j=0;j<item;j++)
        {
            cin>>doc[i][j];
        }
    }
    return;

}


void wet(int num1, int num2)
{

    int index1=num1-1;
    int index2=num2-1;
    int  sum1=0,sum2=0,cou1=0,cou2=0;

    for(int i=0;i<item;i++)
    {
        sum1+=doc[index1][i];
        sum2+=doc[index2][i];
        if(doc[index1][i])
        {
            cou1+=1;
        }
         if(doc[index2][i])
        {
            cou2+=1;
        }
    }
     double avg1=double(sum1)/double(cou1);
     double avg2=double(sum2)/double(cou2);
     vector<double>v1;
     vector<double>v2;
     for(int i=0;i<item;i++)
     {
        if(doc[index1][i]==0)
        {
            v1.push_back(0);
        }
        else
            v1.push_back(doc[index1][i]-avg1);
     }

        for(int i=0;i<item;i++)
     {
        if(doc[index2][i]==0)
        {
            v2.push_back(0);
        }
        else
            v2.push_back(doc[index2][i]-avg2);
     }
     double mul,mul2,mul3,sum3=0,sum4=0,sum5=0,ans;
     for(int i=0;i<item;i++)
     {
        mul=v1[i]*v2[i];
        sum3+=mul;
        mul2=pow(v1[i],2);
        sum4=sum4+mul2;
        mul3=v2[i]*v2[i];
        sum5=sum5+mul3;
     }

     v1.clear();
     v2.clear();
     sum4=sqrt(sum4);
     sum5=sqrt(sum5);
     ans=sum3/(sum4*sum5);
     cout<<ans;


    return;
}

int main()

{
    cout<<"Enter the num of Doc and number of item in each doc :";
    cin>>num_of_doc;
    cin>>item;
    cout<<"Enter The items :"<<endl;
    create_doc();
    cout<<"Enter two Documnet number for find Weighted-cosine simillarity :";
    cin>>num1>>num2;
   wet(num1,num2);


  return 0;

}
/*
4 7
4 0 0 5 1 0 0
5 5 4 0 0 0 0
0 0 0 2 4 3 0
0 3 0 0 0 0 3
1 2


*/
