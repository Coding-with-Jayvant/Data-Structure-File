/*
    Name :: Jayavant Warkhade.
    Roll No. 70
    Tittle::
    Practical No. 1
*/
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
    node *root,*nn,*temp,*parent;
    public:
        btree()         //Constuctor
        {
            root = NULL;
        }
        void creat();
        void display();
        void insert(node *,node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void leaf();
        void display_leaves(node *temp);
        void longest_path();
        int height(node *);
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

        case 3://Postnorder
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

void btree::leaf()
{
    display_leaves(root);
}

void btree::display_leaves(node *temp)
{
    if(root==NULL)
    {
        cout<<"Tree is not created ...";
    }
    if(temp!=NULL)
    {
        if((temp->left==NULL) && (temp->right==NULL)) 
        {
            cout<<" "<<temp->data;
        }
        else
        {
            display_leaves(temp->left);
            display_leaves(temp->right);
        }
    }
}

void btree::longest_path()
{
    if(root==NULL)
    {
        cout<<"Tree is empty..";
    }
    else{
        int lheight=height(root);
        int rheight=height(root);

        if(lheight>rheight)
        {
            cout<<"The tree is--> "<<lheight;

        }
        else{
            cout<<"The height of tree is--> "<<rheight;
        }
    }
}
int btree::height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
        {
            return(lheight+1);
        }
        else{
            return(rheight+1);
        }

    }
}

int main()
{
    int j,d,o;
    btree obj;
    do{
        cout<<"# Which operation do you want perform \n\t 1.Insert \n\t 2.Display ---> \n\t     -PREORDER \n\t     -INORDER \n\t     -POSTORDER \n\t 3.Display leaf Node \n\t 4.Display Height ::";
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
                cout<<"------------------------------------------------------------------"<<endl;
                obj.display();
                cout<<"\n------------------------------------------------------------------"<<endl;
            break;
            
            case 3:
                cout<<"------------------------------------------------------------------"<<endl;
                cout<<"--> leveas is::";
                obj.leaf();
                cout<<"\n------------------------------------------------------------------"<<endl;
            break;

            case 4:
                cout<<"------------------------------------------------------------------"<<endl;
                cout<<"--> Longest Path::";
                obj.longest_path();
                cout<<"\n------------------------------------------------------------------";
            break;  
           
        }
        cout<<"\n\n Do you want to continue \n\t 1.Yes 2.No ::";
        cin>>d;
    }while(d!=2);
    cout<<"\n\n* Thank You For Visiting My program *"<<endl;
    return 0;
}
/*
                        * OUTPUT OF ABOVE PROGRAME *

 # Which operation do you want perform 
         1.Insert 
         2.Display ---> 
             -PREORDER
             -INORDER
             -POSTORDER
         3.Display leaf Node
         4.Display Height ::1

# Enter a element::9
        Root is Created... 

Do you want to Add more node
         1. Yes 2. No ::1

# Enter a element::6
You want add element Right/Left::9==> r


Do you want to Add more node
         1. Yes 2. No ::1

# Enter a element::8
You want add element Right/Left::9==> l


Do you want to Add more node
         1. Yes 2. No ::1

# Enter a element::3
You want add element Right/Left::9==> l
You want add element Right/Left::8==> r


Do you want to Add more node
         1. Yes 2. No ::1

# Enter a element::8
You want add element Right/Left::9==> l
You want add element Right/Left::8==> l


Do you want to Add more node
         1. Yes 2. No ::2


 Do you want to continue
         1.Yes 2.No ::1
# Which operation do you want perform 
         1.Insert
         2.Display --->
             -PREORDER
             -INORDER
             -POSTORDER
         3.Display leaf Node
         4.Display Height ::2
------------------------------------------------------------------


# You want to Display in Element in which Form ::
         1.Preoreder
         2.Inoreder
         3.Postoreder :: 1
--> Preorder:: 9   8   8   3   6  

# You Want to Display the Node in another Form ...
         1. YES  2. NO ::1


# You want to Display in Element in which Form ::
         1.Preoreder
         2.Inoreder
         3.Postoreder :: 2
--> inorder:: 8   8   3   9   6  

# You Want to Display the Node in another Form ...
         1. YES  2. NO ::1


# You want to Display in Element in which Form ::
         1.Preoreder
         2.Inoreder
         3.Postoreder :: 3
--> Postorder:: 8   3   8   6   9  

# You Want to Display the Node in another Form ...
         1. YES  2. NO ::2

------------------------------------------------------------------
    Do you want to continue
         1.Yes 2.No ::1
         
# Which operation do you want perform 
         1.Insert
         2.Display --->
             -PREORDER
             -INORDER
             -POSTORDER
         3.Display leaf Node
         4.Display Height ::3
------------------------------------------------------------------
--> leveas is:: 8 3 6
------------------------------------------------------------------


 Do you want to continue
         1.Yes 2.No ::1
# Which operation do you want perform 
         1.Insert
         2.Display --->
             -PREORDER
             -INORDER
             -POSTORDER
         3.Display leaf Node
         4.Display Height ::4
------------------------------------------------------------------
--> Longest Path::The height of tree is--> 3
------------------------------------------------------------------

 Do you want to continue
         1.Yes 2.No ::2


    * Thank You For Visiting My program *

*/