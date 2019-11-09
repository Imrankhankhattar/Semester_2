#include <iostream>

using namespace std;

class node
{
private:
    node*right;
    node*left;
    int data;
    int height;
public:

    node()
    {
        right = NULL;
        left = NULL;
        data = 0;
        height = 0;
    }
    void setright(node*x)
    {
        right=x;
    }
    void setleft(node*y)
    {
        left=y;
    }
    void setdata(int z)
    {
        data=z;
    }
    void setheight(int a)
    {
        height = a;
    }

    node* getright()
    {
        return right;
    }
    node* getleft()
    {
        return left;
    }
    int getdata()
    {
        return data;
    }
    int getheight1()
    {
        return height;
    }




}; // END OF CLASS node

class BST
{
    node*root;
public:
    BST()
    {
        root=NULL;
    }
    int max(int a, int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }

     int getheight(node* node)
    {
       if(node==NULL)
        return -1;
       else
        return node->getheight1();
    }

    int getbalancefactor(node* u)
    {
        return getheight(u->getleft())-getheight(u->getright());
    }
    node* rightrotate(node* x)
    {
        node*temp=x->getleft();
        x->setleft(temp->getright());
        temp->setright(x);
        temp->setheight(max(getheight(temp->getleft()),getheight(temp->getright()))+1);
        x->setheight(max(getheight(x->getleft()),getheight(x->getright()))+1);
        return temp;
    } // END OF RIGHT ROTATION

    node* leftrotate(node* x)
    {
        node*temp=x->getright();
        x->setright(temp->getleft());
        temp->setleft(x);
        temp->setheight(max(getheight(temp->getleft()),getheight(temp->getright()))+1);
        x->setheight(max(getheight(x->getleft()),getheight(x->getright()))+1);
        return temp;
    } // END OF LEFT ROTATION

    void addavalue(int a)
    {
        root=add(root,a);
    } // END OF ADD_A_VALUE FUNCTION

    node* add(node*start,int key)
    {
        int bf;
        if(start==NULL)
        {
           node*temp=new node();
           temp->setdata(key);
           start=temp;
        }
        else if(key<start->getdata())
        {
            start->setleft(add(start->getleft(),key));
            bf=getbalancefactor(start);
            if(bf==2 || bf==-2)
            {
                 if(start->getleft()->getdata()>key)
                 {
                     start=rightrotate(start);
                 }
                 else
                 {
                     node*temp=start->getleft();
                   start->setleft(leftrotate(temp));
                   start=rightrotate(start);
                 }
            }
        }
        else
        {
            start->setright(add(start->getright(),key));
            bf=getbalancefactor(start);
            if(bf==2 || bf==-2)
            {
                 if(start->getright()->getdata()<key)
                 {
                     start=leftrotate(start);
                 }
                 else
                 {
                     node*temp1=start->getright();
                     start->setright(rightrotate(temp1));
                     start=leftrotate(start);
                 }
            }
        }

        start->setheight(max(getheight(start->getleft()),getheight(start->getright()))+1);
        return start;
    } // End of a recursive addition

    void displayr(node*n)
    {
        if(n==NULL)
            return ;
        else
        {
            cout << n->getdata() << endl;
            displayr(n->getleft());
             displayr(n->getright());
        }

    }// END OF INNER display FUNCTION

     void displayr_1(node*n1)
    {
        if (n1 == NULL)
        return;
        else
        {
        displayr_1(n1->getleft());
        cout << n1->getdata() <<endl;
        displayr_1(n1->getright());
        }
    } // END OF IN_ORDER

    void display_2(node*n2)
    {
        if (n2 == NULL)
         return;
    else
    {
     display_2(n2->getleft());
    display_2(n2->getright());
    cout << n2->getdata() << endl;
    }
    } //END OF POST_ORDER


    void display()
    {
         int b;
        cout<< "enter 1 for pre-order" << endl;
        cout << "ENter 2 for in-order" << endl;
        cout << "Enter 3 for post order" << endl;
        cin>>b;
        cout << "-------------------------" << endl;
        if(b==1)
        displayr(root);
        if(b==2)
            displayr_1(root);
        if(b==3)
            display_2(root);
    } // END OF DISPLAY FUNCTION

    node * minValueNode(node* root1)
    {
        node*minv = new node();
        minv=root1;
        while (minv && minv->getleft() != NULL)
            minv = minv->getleft();

        return minv;
    } //END OF MIN VALUE FUNCTION

   node* deleteNoder(node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->getdata() )
        root->setleft(deleteNoder(root->getleft(), key)) ;
    else if( key > root->getdata() )
        root->setright(deleteNoder(root->getright(), key)) ;
    else
    {
        if( (root->getleft() == NULL) || (root->getright() == NULL) )
        {
            node *temp = root->getleft() ? root->getleft() : root->getright();

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            *root = *temp;
        }
        else
        {
            node* temp = minValueNode(root->getright());
            root->setdata(temp->getdata()) ;
            root->setright(deleteNoder(root->getright(),temp->getdata())) ;
        }
    }
    if (root == NULL)
    return root;

    root->setheight(1 + max(getheight(root->getleft()),getheight(root->getright())));
    int balance = getbalancefactor(root);

    // Left Left Case
    if (balance > 1 && getbalancefactor(root->getleft()) >= 0)
        return rightrotate(root);

    // Left Right Case
    if (balance > 1 && getbalancefactor(root->getleft()) < 0)
    {
        root->setleft(leftrotate(root->getleft())) ;
        return rightrotate(root);
    }

    // Right Right Case
    if (balance < -1 && getbalancefactor(root->getright()) <= 0)
        return leftrotate(root);

    // Right Left Case
    if (balance < -1 && getbalancefactor(root->getright()) > 0)
    {
        root->setright(rightrotate(root->getright()));
        return leftrotate(root);
    }

    return root;
}   // END OF REMOVEr FUNCTION

    void deleteNode(int key)
    {
        deleteNoder(root,key);
    }// END OF REMOVEr FUNCTION

    void search1(int z)
    {
        node*temp=new node();
        temp=root;
         if(root==NULL)
        {
            cout << "TREE IS EMPTY" << endl;
        }
         else
        {
            while(true)
            {
                if(z==root->getdata())
                {
                     cout<<"Value Exist"<<endl;
                    break;
                }
                else if(z<temp->getdata())
                {
                    if(temp->getleft()==NULL)
                    {
                        cout<<"Value doesn't Exist"<<endl;
                        break;
                    }
                    temp=temp->getleft();
                    if(temp->getdata()==z)
                    {
                         cout<<"Value Exist"<<endl;
                        break;
                    }
                }
                else if(z>=temp->getdata())
                {
                     if(temp->getright()==NULL)
                    {
                        cout<<"Value doesn't Exist"<<endl;
                        break;
                    }
                    temp=temp->getright();
                    if(temp->getdata()==z)
                    {
                         cout<<"Value Exist"<<endl;
                        break;
                    }
                }
            }

        }

    } // END OF SEARCH VALUE


}; //END OF BST CLASS

int main()
{
    int a,loop=11;
    BST obj;
    while(loop==11)
    {
        cout << "Enter 1 to add a value"<< endl;
        cout << "Enter 2 to DISPLAY the tree"<< endl;
        cout << "Enter 3 to remove a value"<< endl;
        cout << "Enter 4 to search a value"<< endl;
        cin >> a;
        cout << "--------------------------------------- " << endl;
        if(a==1)
        {
           /* int x;
            cout << "ENTER a value to add" << endl;
            cin >> x;*/
            obj.addavalue(45);
             obj.addavalue(9);
              obj.addavalue(15);
                obj.addavalue(66);
                obj.addavalue(77);
                 obj.addavalue(95);
                  obj.addavalue(88);
                   obj.addavalue(70);
            cout << "--------------------------------------- " << endl;
            cout<< "enter 11 if you want to proceed" << endl;
            cin >> loop;
        } // END OF FIRST OPTION

        if(a==2)
        {
            obj.display();
            cout << "--------------------------------------- " << endl;
            cout<< "enter 11 if you want to proceed" << endl;
            cin >> loop;
        } // END OF 2ND OPTION
        if(a==3)
        {
            int y;
            cout << "ENTER a value to remove" << endl;
            cin >> y;
            obj.deleteNode(y);
            cout << "--------------------------------------- " << endl;
            cout<< "enter 11 if you want to proceed" << endl;
            cin >> loop;
        } // END OF 3rd OPTION

        if(a==4)
        {
            int z;
            cout << "ENTER a value to search" << endl;
            cin >> z;
            obj.search1(z);
            cout << "--------------------------------------- " << endl;
            cout<< "enter 11 if you want to proceed" << endl;
            cin >> loop;
        } // END OF 4th OPTION

    } // end of main loop
    return 0;
}
