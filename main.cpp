#include <iostream>

using namespace std;

class node
{
private:
    node*right;
    node*left;
    int data;
public:

    node()
    {
        right = NULL;
        left = NULL;
        data = 0;
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


}; // END OF CLASS node

class BST
{
    node*root;
public:
    BST()
    {
        root=NULL;
    }

    void addavaluer(int u,node*new1,node*i)
    {
        node*temp=i;
        if(u<temp->getdata())
        {
            if(temp->getleft()==NULL)
            {
                temp->setleft(new1);
                return;
            }
            else
                addavaluer(u,new1,temp->getleft());
        }
        else if(u>=temp->getdata())
        {
            if(temp->getright()==NULL)
            {
                temp->setright(new1);
                return;
            }
            else
                addavaluer(u,new1,temp->getright());
        }
    }  // END OF ADD_A_VALUER function
    void addavalue(int a)
    {
        node*new1=new node();
        new1->setdata(a);
        if(root==NULL)
        {
            root=new1;
            return;
        }
        else
            addavaluer(a,new1,root);
    } // END OF ADD_A_VALUE FUNCTION

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
        cout << "-------------------------" << endl;
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

        if (key < root->getdata())
            root->setleft(deleteNoder(root->getleft(), key));
        else if (key > root->getdata())
            root->setright(deleteNoder(root->getright(), key)) ;

        else
        {

            if (root->getleft() == NULL)
            {
                node *temp = root->getright();
                return temp;
            }
            else if (root->getright() == NULL)
            {
                node *temp = root->getleft();
                return temp;
            }
            node* temp = minValueNode(root->getright());
            root->setdata(temp->getdata()) ;
            root->setright(deleteNoder(root->getright(), temp->getdata()));
        }
        return root;
    } // END OF REMOVEr FUNCTION

    void deleteNode(int key)
    {
        deleteNoder(root,key);
    }// END OF REMOVEr FUNCTION



    void search1r(int z,node*temp)
    {
        if(z<temp->getdata())
        {
            if(temp->getleft()==NULL)
            {
                cout<<"Value doesn't Exist"<<endl;
                return;
            }
            temp=temp->getleft();
            if(z==temp->getdata())
            {
                cout<<"Value Exist"<<endl;
                return;
            }
            else
                search1r(z,temp);
        }
        else if(z>=temp->getdata())
        {
            if(temp->getright()==NULL)
            {
                cout<<"Value doesn't Exist"<<endl;
                return;
            }
            temp=temp->getright();
            if(temp->getdata()==z)
            {
                cout<<"Value Exist"<<endl;
                return;
            }
            else
                search1r(z,temp);
        }


    }// END OF SEARCH1r FUNCTION

    void search1(int z)
    {
        node*temp=new node();
        temp=root;
        if(root==NULL)
        {
            cout << "TREE IS EMPTY" << endl;
            return;
        }
        else if(z==root->getdata())
        {
            cout<<"Value Exist"<<endl;
            return;
        }
        else
            search1r(z,temp);

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
            /*  int x;
              cout << "ENTER a value to add" << endl;
              cin >> x;
              obj.addavalue(x);*/
            obj.addavalue(10);
            obj.addavalue(19);
            obj.addavalue(7);
            obj.addavalue(21);
            obj.addavalue(39);
            obj.addavalue(123);
            obj.addavalue(77);
            obj.addavalue(2);
            obj.addavalue(9);
            obj.addavalue(91);
            obj.addavalue(80);
            obj.addavalue(20);
            obj.addavalue(25);
            obj.addavalue(27);
            obj.addavalue(26);
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

