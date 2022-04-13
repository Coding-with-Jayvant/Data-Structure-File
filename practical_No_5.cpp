/*
    Name        :: Jayavant Warkhade.
    Roll No.    :: 70
    Tittle      :: program about Priority heap queue.
    Practical No:: 05
*/
#include<iostream>
using namespace std;
int size = -1;
int H[10];
int parent(int i)
{
	return(i-1)/2;
}

int leftchild(int i)
{
	return((2*i)+1);
}

int rightchild(int i)
{
	return((2*i)+2);
}

void shiftup(int i)
{
	while(i>0 && H[parent(i)]<H[i])
	{
		swap(H[parent(i)],H[i]);
		i=parent(i);
	}
}

void shiftdown(int i)
{
	int maxindex=i;
	int l=leftchild(i);
	if(l<=size && H[l]>H[maxindex])
	{
		maxindex=l;	
	}
	int r=rightchild(i);
	if(r<=size && H[r]>H[maxindex])
	{
		maxindex=r;
	}
	if(i!=maxindex)
	{
		swap(H[i], H[maxindex]);
		shiftdown(maxindex);
	}
}

void insert(int p)
{
	size=size+1;
	H[size]=p;
	shiftup(size);
}

int extractmax()
{
	int result=H[0];
	H[0]=H[size];
	size=size-1;
	shiftdown(0);
	return result;
}

void changepriority(int i , int p)
{
	int oldp=H[i];
	H[i]=p;
	if(p>oldp)
	{
		shiftup(i);
	}
	else
	{
		shiftdown(i);	
	}
}

int getmax()
{
	return H[0];
}

void remove(int i)
{
	H[i]=getmax()+1;
	shiftup(i);
	extractmax();
}

int main()
{
	int i=0;
	int pri[10],n;
	cout<<"\n # How many element you want to store :: ";
	cin>>n;
	cout<<"\n # Enter a Element :: ";
	for(i=0;i<n;i++)
	{
		cin>>pri[i];
	}
	for(i=0;i<n;i++)
	{
		insert(pri[i]);
	}
	cout<<"\n # Priority queue --> ";
	while(i<=size)
	{
		cout<<H[i]<<"  ";
		i++;
	}
	
	cout<<"\n\t Node with Max-priority :: "<<extractmax()<<"\n";
	
	cout<<"\t priority queue after extrctmax  :: ";
	int j=0;
	while(j<=size)
	{
		cout<<H[j]<<" ";
		j++;
	}
	cout<<"\n";
	changepriority(1, n);
	
	cout<<"\t priority queue after priority-change :: ";
	int k=0;
	while(k<=size)
	{
		cout<<H[k]<<" ";
		k++;
	}
	remove(3);
	cout<<"\n";
	cout<<"\t priority queue after removing the element :: ";
	int l=0;
	while(l<=size)
	{
		cout<<H[l]<<" ";
		l++;
	}
	return 0;
}
/*
                        * OUTPUT *
    
     # How many element you want to store :: 5

 	# Enter a Element :: 1
	2
	6
	8
	3

 	# Priority queue -->
         Node with Max-priority :: 8
         priority queue after extrctmax  :: 6 3 2 1
         priority queue after priority-change :: 6 5 2 1
         priority queue after removing the element :: 6 5 2
--------------------------------
Process exited after 9.713 seconds with return value 0
Press any key to continue . . .

*/