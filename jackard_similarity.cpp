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


void jackard(int num1, int num2)
{

    int index1=num1-1;
    int index2=num2-1;
    int co=0;
    int com=0;
    for(int i=0;i<item;i++)
    {
        if( (doc[index1][i]!= 0) || (doc[index2][i]!= 0) )
        {
            co=co+1;
            if(doc[index1][i]!=0 && doc[index2][i]!=0 )
            {
                com=com+1;
            }

        }
    }

        double ans;
        ans=double(com)/double(co);
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
    cout<<"Enter two Documnet number for find jackard simillarity :";
    cin>>num1>>num2;
    jackard(num1,num2);


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
