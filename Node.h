#ifndef NODE_H
#define NODE_H

template<class t>
class Node
{
    public:
        Node();
        virtual ~Node();
t title;
t author;
t ISBN;
t gener;
t av_status;
t n_borrowing;
t phone;
bool put;
bool borrowing;
Node *next;
    protected:

    private:
};
template<class t>
Node<t>::Node()
{borrowing=false;
put =false;
    //ctor
}
template<class t>
Node<t>::~Node()
{
    //dtor
}

#endif // NODE_H
