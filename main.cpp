#include <iostream>
#include"Book_Record.h"
#include"Book_Record.h"
#include<windows.h>
#include<cstdlib>

using namespace std;

void printline(string l,bool e=true){
cout<<l<<(e?"\n":"\t");

}
void data_entry(){
    Book_Record <string> p;
int i=1;
while(i!=7){
system("cls");
printline("  Main Page");
printline("--------------");
printline("1. Book Catalog");
printline("2. Book Insertion And Removal");
printline("3. Book Search");
printline("4. Book Borrowing");
printline("5. Book Statistics");
printline("6. File Handling");
printline("7. Stop Book App");
printline("Enter Your Selection...",false);
cin>>i;



cout<<endl;
    switch(i){
case 1:
    p.display();
 Sleep(3000);

break;

case 2:{
// exit_loop: ;
bool exitLoop = false;
    int r=1;
    while(r!=0&& !exitLoop){
            system("cls");
        printline("Book Insertion And Removal");
        cout<<"----------------------------------"<<endl;
        printline("1. Insert");
        printline("2. Delete");
        printline("3. Back To Main Page");
        printline("Enter Your Selection...",false);

        cin>>r;
        cout<<endl;
        switch(r){
case 1:{

    int g=1;
    while(g!=0){
system("cls");
        printline("1. Add Book At The Beginning");
        printline("2. Add Book Before Specific Title");
        printline("3. Add Book At The End");
        printline("4. Back To Book Insertion And Removal");
        printline("Enter Your Selection...",false);
        cin>>g;
    cout<<endl;
        switch (g){

    case 1:{
        p.f_insert();
        Sleep(3000);
        break;}

    case 2:{
        cout<<"Enter The Title To Add Before It => ";
        string f;
cin.ignore();
 getline(cin,f);
        p.B_insert(f);
   Sleep(3000);
   break;

    }case 3:{
    p.e_insert();
    Sleep(3000);
    break;
    }case 4:{
g=0;
break;
  //goto exit_loop;
  }  default:{
        cout<<"Try Again"<<endl;
        break;
    }
    }
    }


        Sleep(3000);
        break;}
    case 2:{
        string t;
        cout<<"Enter Title To Delete Book => ";
        cin.ignore();
        getline(cin,t);
        p.Delete(t);
         Sleep(3000);
        break;}

    case 3:{
        exitLoop=true;
        break;
         // goto exit_loop;
          }
    default:
        cout<<"Try Again "<<endl;
        }
    }

 Sleep(3000);
break;
    }

    case 3:{
      cout<<"Enter Title To search => ";
      string f;
      cin.ignore();
  getline(cin,f);
    cout<<"\n"<<  p.r_search(f);
     Sleep(3000);
break;}
case 4: {
     cout<<"Enter Title To Borrow => ";
      string f;
      cin.ignore();
      getline(cin,f);
p.Borrowing(f);

   Sleep(3000);
break;
}


case 5:{
p.B_Statistic();
   Sleep(3000);
break;
}
case 6:{

int k=1;
while(k!=0){
        system("cls");
        printline("File : ");
    printline("\t\t1. Write Data Into File ");
    printline("\t\t2. Read All Data From The File");
    printline("\t\t3. Back To Main Page");
    cout<<endl;
    printline("Enter Your Selection...",false);
    cin>>k;
    switch(k){
case 1:{
p.i_file();
Sleep(3000);
break;
}
case 2:
{p.r_file();
          Sleep(3000);
break;
    }
    case 3:{
         k=0;
         break;
    }default:{
cout<<"Try Again"<<endl;

    }
    }

}
//p.r_file();



   Sleep(3000);
break;
}
case 7:
    {
//p.i_file();
        cout<<"\t\t\t Thanks"<<endl;
        return;
    }
default:{
    cout<<"Try Again"<<endl;

}}

}
}
int main()
{
    data_entry();
    return 0;
}
