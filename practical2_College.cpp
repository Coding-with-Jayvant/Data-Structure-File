#include<iostream>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
};
class btree
{
    node *root,*nn,*temp,*parent,*stc[100];
    int top;
    public:
        btree()         //Constuctor
        {
            root = NULL;
	    top=-1;
	   
        }
        void creat();
        void insert(node *,node *);
        void display();
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
	
	void display_non();
        void preorder_non(node *);
        void inorder_non(node *);
        void postorder_non(node *);
	int isempty();
	int isfull();
	void push(node *);
	node *pop();

};
void btree::creat()
{
    nn= new node;
    nn->left = NULL;
    nn->right = NULL;
    cout<<"\n# Enter a element::";
    cin>>nn->data;
    if(root==NULL)
    {
        root=nn;
         cout<<"\tRoot is Created... ";
    }
    else{
        insert(root,nn);
    }
}
void btree::insert(node *root,node *nn)
{
    char m;
    cout<<"You want add element Right/Left::"<<root->data<<"==> ";
    cin>>m;
    if(m=='r' || m=='R')
    {
        if(root->right==NULL)
        {
            root->right=nn;
           
        }
        else{
            insert(root->right,nn);
        }
    }
    else{
        if(root->left==NULL)
        {
            root->left=nn;
        }
        else{
            insert(root->left,nn);
        }
    }
}
void btree::display()
{
    int p,l;
    do{
    cout<<"\n\n# You want to Display in Element in which Form ::";
    cout<<"\n\t 1.Preoreder";
    cout<<"\n\t 2.Inoreder";
    cout<<"\n\t 3.Postoreder :: ";
    cin>>p;
    switch(p)
    {
        case 1://Preorder
            if(root==NULL)
            {
                cout<<"\nnode is not created!!";
            }
            else{
                cout<<"--> Preorder::";
                preorder(root);
            }
        break;

        case 2://inorder
            if(root==NULL)
            {
                cout<<"\nnode is not created!!";
            }
            else{
                cout<<"--> inorder::";
                inorder(root);
            }
        break;

        case 3://Postorder
            if(root==NULL)
            {
                cout<<"\nnode is not created!!";
            }
            else{
                cout<<"--> Postorder::";
                postorder(root);
            }
        break;
    }
    cout<<"\n\n# You Want to Display the Node in another Form ...\n\t 1. YES  2. NO ::";
    cin>>l;
    }while(l!=2);
}
void btree::preorder(node *ptr)
{
    if(ptr!=NULL)
    {
        cout<<" "<<ptr->data<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);

    }
    
}

void btree::inorder(node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<" "<<ptr->data<<"  ";
        inorder(ptr->right);

    }
    
}

void btree::postorder(node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<" "<<ptr->data<<"  ";

    }
    
}

int btree::isempty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
}

int btree::isfull()
{
	if(top==99)
	{
		return 1;
	}
	return 0;
}

void btree::push(node *e)
{
	if(!isfull())
	{
		stc[++top]=e;
	}
}

node *btree::pop()
{
	node *temp=stc[top];
	top--;
	return temp;
}

void btree::display_non()
{


    int a,b;
    do{
    cout<<"\n\n# You want to Display in Element in which Form ::";
    cout<<"\n\t 1.Preoreder Non recu.";
    cout<<"\n\t 2.Inoreder Non recu.";
    cout<<"\n\t 3.Postoreder Non recu.:: ";
    cin>>a;
    switch(a)
    {
        case 1://Preorder
            if(root==NULL)
            {
                cout<<"\nnode is not created!!";
            }
            else{
                cout<<"--> Preorder Non recurcively::";
                preorder_non(root);
            }
        break;

        case 2://inorder
            if(root==NULL)
            {
                cout<<"\nnode is not created!!";
            }
            else{
                cout<<"--> inorder Non Recurcively::";
                inorder_non(root);
            }
        break;

        case 3://Postorder
            if(root==NULL)
            {
                cout<<"\nnode is not created!!";
            }
            else{
                cout<<"--> Postorder Non Recurcively::";
                postorder_non(root);
            }
        break;
    }
    cout<<"\n\n# You Want to Display the Node in another Form ...\n\t 1. YES  2. NO ::";
    cin>>b;
    }while(b!=2);
}
void btree::inorder_non(node *root)
{
	btree g;
	while(!g.isempty() || root!=NULL)
	{
	    while(root!=NULL)
	    {
		g.push(root);
		root=root->left;
	
	
	    }
		root=g.pop();
		cout<<" "<<root->data<<"  ";
		root=root->right;
	}
	
}
void btree::preorder_non(node *root)
{
	btree g;
	while(!g.isempty() || root!=NULL)
	{
	    while(root!=NULL)
	    {
		cout<<" "<<root->data<<"  ";
		g.push(root);
		root=root->left;
	    }
		root=g.pop();
		root=root->right;
	}
	
}
void btree::postorder_non(node *root)
{
	btree g;
	int i=0;
	int str[30];
	while(!g.isempty() || root!=NULL)
	{
	    while(root!=NULL)
	    {
		str[i++]=root->data;
		g.push(root);
	
		root=root->right;
	
	    }
		root=g.pop();
		root=root->left;
	}
	while(--i>=0)
	{
		cout<<str[i]<<"  ";
	}
	
}
int main()
{
    int j,d,o;
    btree obj;
    do{
        cout<<"\n# Which operation do you want perform \n\t 1.Insert \n\t 2.Display Recurcively ---> \n\t     -PREORDER \n\t     -INORDER \n\t     -POSTORDER \n\t 3.Display Non_Recurcively  ---> \n\t     -PREORDER NON RECURCIVELY \n\t     -INORDER NON RECURCIVELY\n\t      -POSTORDER NON RECURCIVELY ::";
        cin>>j;
        switch(j)
        {
            case 1:
                do{
                    
                    obj.creat();
                    cout<<"\n\nDo you want to Add more node\n\t 1. Yes 2. No ::";
                    cin>>o;

                }while(o!=2);
            break;

            case 2:
                obj.display();
            break;
            
            case 3:
             	obj.display_non();

            break;
           
        }
        cout<<"\n\n Do you want to continue \n\t 1.Yes 2.No ::";
        cin>>d;
    }while(d!=2);
    cout<<"\n * Thank You For Visiting My program *";
    return 0;
}