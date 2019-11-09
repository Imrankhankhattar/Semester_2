#include <iostream>
#include<fstream>


using namespace std;

int main()
{
   char c;
   int a=0,b=1;
   ifstream obj;
   obj.open("main.cpp");
   while(obj.eof()==0)
   {
       obj >> c;
       if(c=='(')
       {
           a++;
          // cout << c << endl;
       }
       if(c==')')
       {
           a--;
            //cout << c << endl;
       }

       if(c=='{')
       {
           b++;
            //cout << c << endl;
       }
       if(c=='}')
       {
           b--;
            //cout << c << endl;
       }
   }
   if(a==0 && b==0)
   {
       cout << "BRACKETS ARE NUSTED PROPERLY" << endl;
       //cout << a << endl;
       //cout << b << endl;
   }
   if(a>0 || b>0)
               cout << "BRACKETS ARE NOT NUSTED PROPERLY " << endl;
    return 0;
}
