#include<bits/stdc++.h>

using namespace std;
vector<string>v1,v2,clas,posi,neg;

vector <pair<string,string> >doc;
set<string>dis;
vector<string>p;
vector<string>n;

vector<double>pos_post;
vector<double>neg_post;



int num_doc;
string que;
double p_pos,p_neg;


string low(string s)
{
    for(int i=0; i<s.length();i++)
    {
        s[i]=tolower(s[i]);
    }
    return s;
}

void findI(string sen){

    stringstream S(sen);
    string s;
    while(S>>s)
    {
        v1.push_back(s);
    }

 return;
}

 void pos()
 {


    p.push_back("positive");
    n.push_back("negative");
     for(int i=0;i<doc.size();i++)
     {
         if(doc[i].first==p[0])
         {
             posi.push_back(doc[i].second);
         }
         if(doc[i].first==n[0])
         {
             neg.push_back(doc[i].second);
         }
     }

     return ;
 }

void dist()
{

    for(int i=0;i<doc.size();i++)
    {
        dis.insert(doc[i].second);
    }
}


void prior()
{
    double P=0,N=0;
    for(int i=0;i<clas.size();i++)
    {
        if(clas[i]==p[0])
        {
            P=P+1;
        }
        else
            N=N+1;
    }
    p_pos=P/num_doc;
    p_neg=N/num_doc;


    return;
}


void pos_terio(){
    double c1=0,c2=0;
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<posi.size();j++)
        {
            if(v1[i]==posi[j])
            {
                c1=c1+1;
            }
        }


        for(int k=0;k<neg.size();k++)
        {
            if(v1[i]==neg[k])
            {
                c2=c2+1;
            }
        }

              pos_post.push_back(  (c1+1) / (dis.size()+ posi.size()  )   );
              neg_post.push_back(  (c2+1) / (dis.size()+ neg.size()  )   );

    }

 return;
}


void decision(){

     for(int i=0;i<pos_post.size();i++)
     {
         p_pos=p_pos*pos_post[i];
     }

      for(int i=0;i<neg_post.size();i++)
     {
         p_neg=p_neg*neg_post[i];
     }

     if(p_pos>p_neg)
     {
         cout<<"Query is positive";
     }

     else
        cout<<"Query is Negative";

return;
}

int main()
{
        cin>>num_doc;
        cin.ignore();
        string sen,cl;
        for(int i=0;i<num_doc;i++)
        {
            getline(cin,sen);
            cin>>cl;
            cin.ignore();
            sen=low(sen);
            cl=low(cl);
            findI(sen);
            clas.push_back(cl);
            for(int i=0;i<v1.size();i++)
            {
                doc.push_back(make_pair(cl,v1[i]));
            }
            v1.clear();
        }


        getline(cin,que);
        que=low(que);
        findI(que);
        dist();
        pos();
        prior();
        pos_terio();
        decision();



        return 0;

}
/*

5
Phone got crashed
Negative
Good Performance
Positive
Good Camera
Positive
Cheap in price
Positive
Battery drains fast
Negative
buy this phone

/*/
