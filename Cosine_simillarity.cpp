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


void cosine(int num1, int num2)
{

    int index1=num1-1;
    int index2=num2-1;
    double  sum=0,mul,sq1,sq2;
    double sum2,sum3;
    for(int i=0;i<item;i++)
    {
        mul=doc[index1][i]*doc[index2][i];
        sum+=mul;
        sq1=doc[index1][i]*doc[index1][i];
        sq2=doc[index2][i]*doc[index2][i];
        sum2+=sq1;
        sum3+=sq2;
    }
  double ans;
  sum2=sqrt(sum2);
  sum3=sqrt(sum3);
  ans=sum/(sum2*sum3);
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
    cout<<"Enter two Documnet number for find cosine simillarity :";
    cin>>num1>>num2;
    cosine(num1,num2);


  return 0;

}

/*Input

4 7
4 0 0 5 1 0 0
5 5 4 0 0 0 0
0 0 0 2 4 3 0
0 3 0 0 0 0 3
1 2


*/
