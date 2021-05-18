#include<iostream>
#include<math.h>
#include<process.h>
using namespace std;
//Hamiltonian Path
bool gph[4][4]={{0,0,1,1},{0,0,1,1},{1,1,0,0},{1,1,0,0}};
int V=4;
int path[4];
int pos=1;
void write(int path[])     
{
for (int i=0;i<=V-1;i++) cout<<path[i]<<" ";  cout<<"0";}

bool isSafe(int r, int c)
{   if(gph[r][c])
{for(int i=0;i<V;i++)
	{  if(path[i]==c){cout<<c<<" is not safe, repeated"<<endl;    return false;}}
	cout<<c<<" is safe, not repeated "<<endl; return true;
}
cout<<c <<" is not an adjacent vertex of "<<r<<endl;
return false;
}
bool createloop(int r)
{
if(gph[r][0]==1) return true;
return false;	
}

void  Hamilpath(int r)
{ 
if(pos==V)
	    {
		    if(createloop(r)==1)
		    {
		    cout<<"\n Ouput"; write(path); exit(-1);	
		     }
			else 
			{
	cout<<"Not a valid path as of no connection between Row "<<r<<"and first node for position"<<pos<<"\n";
			path[--pos]=-1; 	
			write(path);	
			}
	}
		
else
{
	int c=0;
	while(c<=V-1)
	{   cout<<"\nR, POS, C : "<<r<<" "<<pos<<" "<<c<<endl;
	if(isSafe(r,c))
		{   path[pos++]=c;
		     write(path);
		     Hamilpath(c);
		}
		c++;
	}
	cout<<"No further path to reach destination for r ="<<r<<"for position"<<pos<<"\n";
	path[--pos]=-1;
	write(path);
	}
}

int main()
{  for(int i=0;i<=V-1;i++) path[i]=-1;
    path[0]=0;
	Hamilpath(0);}
