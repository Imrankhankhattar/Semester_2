#include <iostream>

using namespace std;

class node
{
private:
    int data;
    node *next;
public:
    node()
    {
        data=0;
        next=NULL;
    }
    void setdata(int a)
    {
        data = a;
    }

    void setnext(node* b)
    {
        next = b;
    }
    int getdata()
    {
        return data;
    }
    node* getnext()
    {
        return next;
    }
}; // end of first class

class linkedlist
{
    node*head;
public:
    linkedlist()
    {
        head=NULL;
    }

    void addatend(int a)
    {
        node *n=new node();
        n->setdata(a);
        node *temp=head;
        if(head==NULL)
        {
            head=n;
        }
        else
        {
            while(temp->getnext()!= NULL)
            {
                temp=temp->getnext();
            }
            temp->setnext(n);
        }
    } //end of add at end

    void addatstart(int b)
    {
        node*n=new node();
        n->setdata(b);
        node*temp=head;
        head=n;
        n->setnext(temp);
    }// end of add at start

    void removefromstart()
    {
        if(head==NULL)
        {
         cout << "List Is Empty" << endl;
        }
        else
        head=head->getnext();

    }// end of remove from start

    void removefromend()
    {
        node*temp=new node();
        temp=head;
        if(temp->getnext() == NULL)
        {
            removefromstart();
        }
        else
        {
            while(temp->getnext()->getnext()!= NULL )
            {
                temp=temp->getnext();
            }

            temp->setnext(NULL);

        }
    }// end of remove from end

    void removethevalue(int a)
    {
        node*temp1=new node();
        node*temp2=new node();
        temp1=head;
        temp2=head;
        if(head==NULL)
        {
            cout << "list is empty " << endl;
        }
        else
        {
        if(temp1->getdata()==a)
        {
            removefromstart();
        }
            else
        {
        while(temp1->getnext()->getdata() != a )
        {
            temp1=temp1->getnext();
        }
        if(temp1->getnext()->getnext()==NULL)
        {
            temp1->setnext(NULL);
        }
        else
        {   temp2=temp1;
            temp1->setnext(temp2->getnext()->getnext());
        }
        }
        }
    } // end of remove the value

    int getsize()
    {
        int a=0;
        node*temp=new node();
        temp=head;
        while(temp->getnext()!=NULL)
        {
            a++;
            temp=temp->getnext();
        }
        return a+1;
    }// end of get size

    void removeatindex(int a)
    {
        if(head==NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            int num=1,x;
            x=getsize();
            if(a>x)
            {
                cout << "Index is not correct" << endl;
            }
            else
            {
                node*temp1=new node();
                node*temp2=new node();
                temp1=head;
                temp2=head;
                if(a==1)
                {
                    removefromstart();
                }
                else
                {
                    while(num<a)
                    {
                        temp1=temp1->getnext();
                        //cout << num << endl;
                        num++;
                    }
                    num=1;
                    while(num<a-1)
                    {
                        temp2=temp2->getnext();
                         // cout << num << endl;
                        num++;
                    }
                    temp2->setnext(temp1->getnext());
                }
            }
        }
    }// end of remove at index

    void addnewvalue(int a, int b)
    {
        node*namal=new node();
        namal=head;
        int num=1;
        int check;
        if(namal==NULL)
        {
            cout << "list is empty value will store in first index" << endl;
            addatstart(a);
        }
        else
        {
            if(b<=1)
            {
                addatstart(a);
            }
            else
            {
                //cout << "Enter the value you want to enter" << endl;
                //cin >> val;
                check=getsize();
                if(b>check)
                {
                    addatend(a);
                }
                node*temp1=new node();
                node*temp2=new node();
                node*n=new node();
                n->setdata(a);
                temp1=head;
                temp2=head;
                //num=1;
                while(num<b-1)
                {
                    temp2=temp2->getnext();
                    num++;
                }
                temp1=temp2->getnext();
                temp2->setnext(n);
                n->setnext(temp1);
            }
        }
    }// end of new value

    void getvalue(int b)
    {
        int num=1,c;
        node*temp1=new node();
        temp1=head;
        c=getsize();
        if(b>c)
        {
            cout << "This index does not exist" << endl;
        }
        else
        {
            while(num<b)
            {
                temp1=temp1->getnext();
                num++;
            }
            cout << "The value of required Index is " << temp1->getdata() <<endl;;
        }
    } // end of get value

    void searchvalue(int b)
    {
        int num=1,check,check1=0;
        node*temp=new node();
        temp=head;
        check = getsize();
        while(num<=check)
        {
            if(temp->getdata() == b)
            {
                cout << "The index of searched value is " << endl;
                cout << num <<endl;
                check1=1;
                break;
            }
            else
            {
                temp=temp->getnext();
                num++;
            }
        }

        if(check1==0)
        {
            cout << "-1" << endl;
        }
    }// end of search value


    void display()
    {
        node *temp;
        temp=head;
        if(head==NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            while(temp->getnext()!= NULL)
            {
                cout << temp->getdata() << endl;
                temp=temp->getnext();
            }
            cout << temp->getdata() << endl;
        }

    }// end of display function

};// end of second class

int main()
{
    int a,loop=99;
    linkedlist l;

    while(loop==99)
    {
        cout << "Enter 1 to add at end" << endl;
        cout << "Enter 2 to add at start" << endl;
        cout << "Enter 3 to remove from start" << endl;
        cout << "Enter 4 to remove from last" << endl;
        cout << "Enter 5 to remove the specified data" << endl;
        cout << "Enter 6 to remove the specified index" << endl;
        cout << "Enter 7 to add new value at specified index" << endl;
        cout << "Enter 8 to get value of specified index" << endl;
        cout << "Enter 9 to search the index of specified value" << endl;
        cout << "Enter 10 to get the size of list" << endl;
        cout << "Enter 11 to display the list" << endl;
        cout << "enter the value" << endl;
        cin >> a;
        cout << "----------------------------------" << endl;
        if(a==1)
        {
            int u;
            cout << "Enter the value you want to add at end " << endl;
            cin >> u;
            l.addatend(u);
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        } // end of first option

        if(a==2)
        {
            int b;
            cout << "Enter the value you want to add  " << endl;
            cin >> b;
            l.addatstart(b);
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        } // end of second option

        if(a==3)
        {
            l.removefromstart();
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        }  // end of third option

        if(a==4)
        {
            l.removefromend();
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        } // end of forth option

        if(a==5)
        {
            int u;
            cout << "Enter the value " << endl;
            cin >> u;
            l.removethevalue(u);
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        } // end of fifth option

        if(a==6)
        {
            int u;
            cout << "Enter the index " << endl;
            cin >> u;
            l.removeatindex(u);
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        } //end of seth option

        if(a==7)
        {
            int u,b;
            cout << "Enter the index at which you want to enter" << endl;
            cin >> b;
            cout << "Enter the value" << endl;
            cin >> u;
            l.addnewvalue(u,b);
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        }// end of 7th option

        if(a==8)
        {
            int b;
            cout << "Enter the value of index " << endl;
            cin >> b;
            l.getvalue(b);
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;

        }// end of eight option

        if(a==9)
        {
            int b;
            cout << "Enter the value you want to search" << endl;
            cin >> b;
            l.searchvalue(b);
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;

        }// end of ninth option

        if(a==10)
        {
            int x;
            x=l.getsize();
            cout << "----------------------------------" << endl;
            cout<< " The size of list is = " << x << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        }  //end of tenth option

        if(a==11)
        {
            l.display();
            cout << "----------------------------------" << endl;
            cout << "Enter 99 if you want to proceed" << endl;
            cin >> loop;
        } //end of eleventh option
    } // main while loop
    return 0;
}
