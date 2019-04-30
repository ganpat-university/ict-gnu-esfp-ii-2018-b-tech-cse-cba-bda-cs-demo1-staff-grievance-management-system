#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;
class staff
{
public :
int sid,sage,s_w_exp,k,n,len,len2;
char sname[30],s_domain[30],d[30];
 int setsid()
 {
  cout<<"Enter S_id :";
  cin>>sid;
  return sid;
 }
 void getd()
 {
  cout<<"Enter name: ";
  again:
  cin>>sname;
  len=strlen(sname);
  for(k=0;k<len;k++)
  {
            if(sname[k]=='*' || sname[k]=='?' || sname[k]=='[' || sname[k]==']' || sname[k]=='!' || sname[k]=='-' || sname[k]=='#')
            {
                cout << "Wild Card Characters are not allowed \n";
                cout<<"Enter name again : ";
                goto again;
            }
   else if( sname[k]>=48 && sname[k]<=57)
            {
                cout << "Numeric characters are not allowed \n";
                cout<<"Enter name again : ";
                goto again;
            }
 }
  cout<<"Enter age: ";
  s:
  cin>>sage;
  cout<<"Enter work experience: ";
  cin>>s_w_exp;
  cout<<"Enter work domain: ";
  s2:
  cin>>s_domain;
  len2=strlen(s_domain);
  for(k=0;k<len;k++)
  {
   if( s_domain[k]>=48 && s_domain[k]<=57)
            {
                cout << "Numeric characters are not allowed \n";
                goto s2;
            }
  }
 }
 void putd()
 {
  cout<<"\t"<<sname<<"\t"<<"\t"<<sage<<"\t"<<s_w_exp<<"\t"<<s_domain<<endl;
 }
};
class grievance : public staff
{
public :
int gid;
char g_type[20],g_faculty[30],g_status[20];
 int setgid()
 {
  cout<<"Enter G_id : ";
  cin>>gid;
  return gid;
 }
 void getdata()
 {
  cout<<"Enter gtype : ";
  cin>>g_type;
  cout<<"Enter faculty name : ";
  cin>>g_faculty;
  cout<<"Enter status : ";
  cin>>g_status;
  cout<<endl;
 }
 void putdata()
 {
  cout<<"\t"<<g_type;
  cout.width(16);
  cout<<g_status;
  cout.width(20);
  cout<<g_faculty<<endl;
  
 }
};
int main()
{
int i,mem,q[10],p[10];
cout<<"*************************************"<<endl;
cout<<"Staff Grievance Management System"<<endl;
cout<<"*************************************"<<endl;
grievance ob[6];
for(i=0;i<=4;i++)
{
 p[i]=ob[i].setsid();
 ob[i].getd();
 q[i]=ob[i].setgid();
 ob[i].getdata();
}
cout<<"\t"<<"S_ID"<<"\t"<<"Name"<<"\t"<<"\t"<<"Age"<<"\t"<<"Exp"<<"\t"<<"Work_Domain"<<endl;
for(i=0;i<=4;i++)
{
cout<<"\t"<<p[i];
ob[i].putd();
}
cout<<"\n";
cout<<"\t"<<"G_ID"<<"\t"<<"G_TYPE";
cout.width(16);
cout<<"G_STATUS";
cout.width(20);
cout<<"G_FACULTY"<<endl;
for(i=0;i<=4;i++)
{
cout<<"\t"<<q[i];
ob[i].putdata();
}
do
{
cout<<"Enter which member wants to perform the task : ";
cin>>mem;
if(mem==1)
{
cout<<"Task of group member 1 :"<<endl;
cout<<"Name of all staff with work domain as programming language and age more than 35 years"<<endl;
for(i=0;i<=4;i++)
{
 if((ob[i].sage>35) && (strcmp(ob[i].s_domain,"prog_language")==0))
 {
   cout<<ob[i].sname;
   cout<<endl;
 }
}
cout<<"Name of staff with gtype as bad infrastructure and work experience more than 5 years"<<endl;
for(i=0;i<=4;i++)
{
 if((ob[i].s_w_exp>5) && (strcmp(ob[i].g_type,"Bad_Infra")==0))
 {
   cout<<"Name"<<ob[i].sname<<endl;
 }
}
}
if(mem==2)
{
int j;
char t[50],l[3][50];
cout<<"\nTask of Group Member 2 :"<<endl;
cout<<"The staff that have been harsesd by Ms Sharma are :\n";
for(i=0;i<=4;i++)
{
if(strcmp(ob[i].g_type,"staff_m")==0)
{
if(strcmp(ob[i].g_faculty,"Ms_Sharma")==0)
{
cout<<ob[i].sname;
cout<<"\n";
}
}
}
for(i=0;i<=4;i++)
{
 strcpy(l[i],ob[i].sname);
}
for(i=0;i<=4;i++)
{
 for(j=i+1;j<=4;j++)
 {
  if(strcmp(l[i],l[j])>0)
  {
   strcpy(t,l[i]);
   strcpy(l[i],l[j]);
   strcpy(l[j],t);
  }
 }
}
cout<<"The name alphabetically arranged are: \n";
for(i=0;i<=4;i++)
{
cout<<l[i]<<"\n";
}
}
if(mem==3)
{
cout<<"\nTask of Group Member 3 :"<<endl;
cout<<"Names of all faculties whose gstatus is pending :";
for(i=0;i<=4;i++)
{
 if(strcmp(ob[i].g_status,"pending")==0)
 {
  cout<<"\n"<<ob[i].g_faculty;
 }
}
int j,v=0,count=0,p=0;
char temp[30],a[30][30];
for(i=0;i<=4;i++)
{
 if(((strcmp(ob[i].s_domain,"prog_language")==0)||(strcmp(ob[i].s_domain,"labmanage")==0))&&(strcmp(ob[i].g_type,"compissue")==0)||(strcmp(ob[i].g_type,"workload")==0))
 {
   strcpy(a[p],ob[i].sname);
   v=count;
   count++;
   p++;
 }
}
for(i=0;i<=v;i++)
{
 for(j=i+1;j<=v;j++)
 {
  if(strcmp(a[i],a[j])>0)
  {
   strcpy(temp,a[i]);
   strcpy(a[i],a[j]);
   strcpy(a[j],temp);
  }
 }
}
cout<<"\n\nName of members whose work domain is programming or labmanagement and gtype is computer issue or work load\n";
cout<<"Alphabetically sorted"<<endl;
for(i=0;i<=v;i++)
{
 cout.width(5);
 cout<<a[i]<<endl;
}
}
}while(mem!=0);
int choice;
char ch;
do
{
cout<<"\n1.To display the given records in a file\n";
cout<<"2.To append records in a file\n";
cout<<"3.To read from file and display\n";
cout<<"4.Exit\n";
cout<<"Enter your choice\n";
cin>>choice;
if(choice==1)
{
 ofstream obj("myfile.txt",ios::out);
 obj<<"\t"<<"SID"<<"\t"<<"Name"<<"\t"<<"Age"<<"\t"<<"Experience"<<endl;
  for(i=0;i<=4;i++)
  {
     
         obj<<"\t"<<p[i]<<"\t"<<ob[i].sname<<"\t"<<ob[i].sage<<"\t"<<ob[i].s_w_exp<<endl;
  }
  obj.close();    
}
grievance g[6];
int w[10],x[10];
if(choice==2)
{
 ofstream obj("myfile.txt",ios::app|ios::binary|ios::out);
 for(i=0;i<=1;i++)
 {
  w[i]=g[i].setsid();
  g[i].getd();
  x[i]=g[i].setgid();
  g[i].getdata();
 }
 for(i=0;i<=1;i++)
 {
  obj<<"\t"<<p[i]<<"\t"<<g[i].sname<<"\t"<<g[i].sage<<"\t"<<g[i].s_w_exp<<endl;
 }
 obj.close();
}
if(choice==3)
{
 ifstream fin("myfile.txt",ios::in);
while(fin.get(ch))
{
cout.setf(ios::left,ios::adjustfield);
cout<<ch;
}
}
if(choice==4)
{
break;
}
}while(choice!=4);
return 0;
}