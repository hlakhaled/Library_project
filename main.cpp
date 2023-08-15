#ifndef BOOK_RECORD_H
#define BOOK_RECORD_H
#include"Node.h"
#include<iostream>
#include<fstream>
#include"string.h"
using namespace std;
template<class t>
class Book_Record
{
public:
void r_file();
    void i_file();
    Book_Record();
    virtual ~Book_Record();
    Node<t>*Begin;
    Node<t>*Last;
    int m_count;
    bool isempty();
    void f_insert();
    void display();
    void B_insert(t item);
    bool q_search(t item);
    void e_insert();
    string r_search(t item);
    void B_Statistic();
    void Delete(t item);
    void Borrowing(t item);
    int B;
    int m;
   // void sorting();
   void reversing();
   void sorting_l();
    void new_N();
    Node<t>*new_node;

protected:

private:
};

template<class t>
Book_Record<t>::Book_Record()
{
    m_count=0;
    m=0;
    B=0;
Last=nullptr;
    Begin=nullptr;
}

template<class t>
Book_Record<t>::~Book_Record()
{
    for(int i=0; i<(m_count+B); i++)
    {
        delete new_node;
    }
}
template<class t>
void Book_Record<t>::i_file(){
        fstream f;
       f.open("Book.txt",ios::app);
Node<t>*temp=Begin;
if(f.is_open()){
        if(isempty()){
            cout<<"The Catalog Is Empty!!!"<<endl;
            return;
        }

while(temp!=nullptr){
        if(temp->put==false){
    if(temp->borrowing==true){
        f<<"The Book Has Been Borrowed"<<endl;
f<<"Name Of Client : "<<temp->n_borrowing<<endl;
cout<<"Phone Number : "<<temp->phone<<endl;
    }
            f<< "Title -> "<<temp->title<<endl;
            f<<"Author -> "<<temp->author<<endl;
            f<<"ISBN -> "<<temp->ISBN<<endl;
            f<<"Genre -> "<<temp->gener<<endl;
            f<<"Availability Status -> "<<temp->av_status<<endl;
            temp->put=true;

    f<<"------------------------------"<<endl;


}   temp=temp->next;
}
cout<<"Added Successfully "<<endl;
}else{

cout<<"The File Can't Be Exist"<<endl;
}

f.close();

}

template<class t>
void Book_Record<t>::new_N()
{
    new_node=new Node<t>();
    cout<<"Title -> ";
   // cin.ignore();
    getline(cin,new_node->title);
    cout<<"Author -> ";
    getline(cin,new_node->author);
    cout<<"ISBN -> ";
    getline(cin,new_node->ISBN);
    cout<<"Genre -> ";
    getline(cin,new_node->gener);
    cout<<"Availability Status -> ";
    getline(cin,new_node->av_status);
    new_node->borrowing=false;
    new_node->put=false;
    m_count++;
}
template<class t>
void Book_Record<t>::r_file(){
fstream f;
f.open("Book.txt",ios::in);
string line;
if(f.is_open()){
while(getline(f,line)){

    cout<<line<<endl;
}f.close();
}else{
cout<<"The File Can't Be Exist"<<endl;
}
}
template<class t>
bool Book_Record<t>::isempty()
{
    return(Begin==nullptr);

}

template<class t>
void Book_Record<t>::f_insert()
{    cin.ignore();
    new_N();
    if(isempty())
    {
        new_node->next=nullptr;
      Last= Begin=new_node;
    }
    else
    {
        new_node->next=Begin;
        Begin=new_node;

    }cout<<"Added Successfully"<<endl;

}

template<class t>
void Book_Record<t>::display()
{
int u;
cout<<"\n\n 1. Sorting Books \t\t\t 2. Reversing Books"<<endl;
cin>>u;
switch(u){
case 1:
    sorting_l();
    break;
case 2:
    reversing();
break;
default:
    cout<<"Try Again \n"<<endl;
}

    if(isempty())
    {
        cout<<"The Catalog Is Empty"<<endl;

    }
    else
    {

        Node<t> *temp=Begin;
        while(temp!=nullptr)
        {

            if(temp->borrowing==true)
            {
                cout<<"The Book Has Been Borrowed"<<endl;
                cout<<"The Name Of Client : "<<temp->n_borrowing<<endl;
cout<<"Phone Number : "<<temp->phone<<endl;
            }

            cout<<"Title -> "<<temp->title<<endl;
            cout<<"Author -> "<<temp->author<<endl;
            cout<<"ISBN -> "<<temp->ISBN<<endl;
            cout<<"Genre -> "<<temp->gener<<endl;
            cout<<"Availability Status -> "<<temp->av_status<<endl;
            temp=temp->next;
            cout<<"------------------------------"<<endl;
        }
    }
}

template<class t>
void Book_Record<t>::B_insert(t item)
{if(isempty()){
        f_insert();
}

    if(q_search(item))
    {    if(Begin->title==item)
    {
        f_insert();

    }else{
        new_N();
        Node<t>* temp=Begin;
        while(temp!=nullptr&&temp->next->title!=item)
        {
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
        cout<<"Added Successfully"<<endl;}
    }
    else
    {
        cout<<"Item Not Found !!!"<<endl;
    }
}

template<class t>
bool Book_Record<t>::q_search(t item)
{
    bool is_found=false;
    Node<t>*temp=Begin;
    while(temp!=nullptr)
    {
        if(temp->title==item)
        {
         is_found=true;
            break;
        }
        temp=temp->next;
    }
    return is_found;
}

template<class t>
void Book_Record<t>::e_insert()
{
    if(isempty())
    {
        f_insert();
    }
    Node<t>*temp=Begin;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }    cin.ignore();
    new_N();
    temp->next=new_node;
    new_node->next=nullptr;
    Last=new_node;
    cout<<"Added Successfully"<<endl;
}

template<class t>
string Book_Record<t>::r_search(t item)
{
    if(isempty())
    {
      return("The Catalog Is empty \n");
    }
    Node <t>*temp=Begin;
    while(temp!=nullptr)
    {
        if(temp->title==item)
        {
            string info;
            if(temp->borrowing==true){
                info+="The Book Has Been Borrowed\n";
                info+="The Name Of Client : "+temp->n_borrowing+"\n";
                info+="Phone Number : "+temp->phone+"\n";
            }info+="Title -> "+temp->title+"\n"+"Author -> "+temp->author+"\n"
                      +"ISBN -> "+temp->ISBN+"\n"+"Genre -> "+temp->gener+"\n"
                      +"Availability Status -> "+temp->av_status+"\n";
                  return info;
        }
        temp=temp->next;
    }
        return("Not Found !! \n");

}

template<class t>
void Book_Record<t>::Delete(t item)
{   Node <t>*pre=nullptr;
    Node<t> *temp=Begin;
    if(q_search(item))
    {
        if(Begin->title==item)
        {if(Begin->borrowing==true){
        B--;
        }else{
        m_count--;

        }
            Begin=Begin->next;
            delete temp;
        }

        else
        {

            while(temp->title!=item)
            {
                pre=temp;
                temp=temp->next;
            }if(temp->borrowing==true){
            B--;

            }else{
            m_count--;
            }
            if(item==Last->title){
                Last=pre;
            }
            pre->next=temp->next;
            delete temp;

        }cout<<"Deleted Successfully"<<endl;


    }
    else
    {
        cout<<"Not Found!!"<<endl;
    }

}

template<class t>
void Book_Record<t>::Borrowing(t item)
{
    if(q_search(item))
    {
        Node<t>*temp=Begin;
        while(temp!=nullptr)
        {
            if(temp->title==item)
            {cout<<"Name Of Client : ";
            getline(cin,temp->n_borrowing);
            cout<<"Phone Number : ";
            getline(cin,temp->phone);

                temp->borrowing=true;
                m_count--;
                B++;

                cout<<"\nthe Borrowing Operation Is Successfully "<<endl;
                cout<<"Import Message To Client "<<temp->n_borrowing<<" : You Should Return Book After One Week"<<endl;
                break;
            }
            temp=temp->next;
        }
    }
    else
    {
        cout<<"The Title Not Found!!!"<<endl;
    }
}

template<class t>
void Book_Record<t>::B_Statistic()
{
    m=m_count+B;
    cout<<"Book Statistics : "<<endl;
    cout<<"\t\t . Total Number Of Books = >"<<m<<endl;
    cout<<"\t\t . Total Number Of Borrowing Books = >"<<B<<endl;
    cout<<"\t\t . Total Number Of Books ( library )= >"<<m_count<<endl;
}
/*
template<class t>
void  Book_Record<t>::sorting(){
    if(!isempty()){
    Node<t>*k=Begin;
    Node<t> arr[m_count+B];
    int y=0;
    while(k!=nullptr){
            arr[y].title=k->title;
            arr[y].ISBN=k->ISBN;
            arr[y].author=k->author;
            arr[y].gener=k->gener;
            arr[y].av_status=k->av_status;
k=k->next;
y++;

    }

for(int i=0;i<(m_count+B)-1;i++){

    int f=i;
            int m=0;
    for(int r=i+1;r<(m_count+B);r++){


        if(arr[f].title[m]>arr[r].title[m]){
            f=r;
            m=0;
        }
else if(arr[f].title[m]==arr[r].title[m])
    {
    m++;
    r--;
}
    }swap(arr[f],arr[i]);
}
          cout<<"=>Book Sorting : "<<endl;
    for(int y=0;y<(m_count+B);y++){


        cout<<"\t\t . Title : "<<arr[y].title<<endl;
        cout<<"\t\t . ISBN : "<<arr[y].ISBN<<endl;
        cout<<"\t\t . Author : "<<arr[y].author<<endl;
        cout<<"\t\t . Genre : "<<arr[y].gener<<endl;
        cout<<"\t\t . Availability Status : "<< arr[y].av_status<<endl;
cout<<"-----------------------------------------"<<endl;
    }}
    else{
        cout<<"The Catalog Is Empty "<<endl;
    }
}
*/
template<class t>
void Book_Record<t>::sorting_l(){
Node<t>*pre;
Node <t>*temp;
t a,b,g,f,d;
int m;
Node<t>*u;
for(pre=Begin;pre!=nullptr;pre=pre->next){
    u=pre;
    m=0;
    for(temp=pre->next;temp!=nullptr;temp=temp->next){
        if(u->title[m]>temp->title[m]){
m=0; u=temp;


        }else if(u->title[m]==temp->title[m]){
        m++;
        temp=u;
        }
    }


    swap(pre->gener,u->gener);
    swap(pre->author,u->author);
    swap(pre->av_status,u->av_status);
    swap(pre->ISBN,u->ISBN);
    swap(pre->title,u->title);
}
}
template<class t>
void Book_Record<t>::reversing(){
Node<t>*pre=nullptr;
Node<t>*temp=Begin;
Node<t>*b=temp->next;
while(temp!=nullptr){
        b=temp->next;
   temp->next=pre;
    pre=temp;
    temp=b;



}Last=Begin;
Begin=pre;
}


#endif // BOOK_RECORD_H
