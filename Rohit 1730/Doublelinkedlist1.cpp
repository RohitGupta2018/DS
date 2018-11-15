#include<iostream>
using namespace std;
struct node
{   int data;
    struct node *next,*prev;
};
class doublelink
{
    struct node*start=NULL;
  public:  void insertionFirst()
    {   int a;
        cout<<"Enter the Value to be inserted at first "<<endl;
        cin>>a;
        struct node*temp=new struct node;
        temp->data=a;
        if(start==NULL)
        {temp->next=NULL;
         temp->prev=NULL;
         start=temp;
        }
        else
        {
           temp->next=start;
           temp->prev=NULL;
           start->prev=temp;
           start=temp;
        }


    }
    void deletionFirst()
    {
        struct node*t=start;
        if(t==NULL)
        {
            cout<<"LInked list is empty"<<endl;

        }
        else if(t->next==NULL)
        {
            start=NULL;
            delete(t);
        }
        else
        {start=start->next;
        start->prev=NULL;
        delete(t);

    }}
    void deletionLast()
    {
        struct node*t=start;
        if(t==NULL)
        {
            cout<<"Linked List is Empty"<<endl;
        }
        else if(t->next==NULL)
        {
          start=NULL;
          delete(t);
        }
        else{
        while(t->next!=NULL)
        {t=t->next;}
        struct node*del=t;
        t=t->prev;
        t->next=NULL;
            delete(del);

    }}
    void insertAfter()
    {   int a,b;
        cout<<"Enter the Value after which new value is to be inserted "<<endl;
        cin>>a;
        cout<<"Enter the new value "<<endl;
        cin>>b;
        struct node*t=start;
         struct node*temp=new struct node;
         while(t->data!=a)
         {
             t=t->next;
         }
         temp->data=b;
         temp->next=t->next;
         temp->prev=t;
         t->next=temp;
         t=temp->next;
         t->prev=temp;
    }
    void insertionLast()
    {   int a;
        cout<<"Enter the Value to be inserted at last "<<endl;
        cin>>a;
         struct node*t=start;
         while(t->next!=NULL)
         {
             t=t->next;
         }
         struct node*temp=new struct node;
         temp->data=a;
         temp->prev=t;
         temp->next=NULL;
         t->next=temp;


    }
    void sorti()
    {
        struct node*t=start;
        int c=0;
        while(t!=NULL)
        {
            t=t->next;
            c++;
        }
        for(int i=0;i<c-1;i++)
        { t=start;
            for(int j=0;j<c-i-1;j++)
            { struct node*t1=t->next;
              if(t->data>t1->data)
              {
                  int a=t->data;
                  t->data=t1->data;
                  t1->data=a;
              }
              t=t->next;

            }
        }
    }


    void display()
    {
        struct node*temp=start;
        if(start==NULL)
            cout<<"LInked LIst is Empty "<<endl;
        else
        {while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }}
};
int main()
{
    doublelink l1;
    /*char ch='Y';
    int a;
    while(ch!='N')
    {cout<<"Enter the value to insert at first in a double link list :";
    cin>>a;
    l1.insertionFirst(a);
    l1.display();
    cout<<"Want to enter more values (Y/N)";
    cin>>ch;}
    l1.deletionFirst();
    cout<<"After deletion of First element"<<endl;
    l1.display();
    l1.deletionLast();
    cout<<"After deletion of last element"<<endl;
    l1.display();
    cout<<"Enter the value after which the new value is to be inserted "<<endl;
    cin>>a;
    int b;
    cout<<"Enter the new value"<<endl;
    cin>>b;
    l1.insertAfter(a,b);
    l1.display();*/
        int ch;
        char ch1='Y';
        cout<<"Enter from the following choices :"<<endl;
        cout<<"1. Insert the element at the begining "<<endl<<"2. Insert the element after a fixed value "<<endl<<"3. Delete the first element "<<endl;
        cout<<"4. delete a last element "<<endl<<"5. Insert at last "<<endl<<"6. sort"<<endl;
        while(ch1=='Y')
        {cout<<"Enter the choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: l1.insertionFirst();
                    l1.display();
                    break;
            case 2:l1.insertAfter();
                   l1.display();
                   break;
            case 3:l1.deletionFirst();
                   l1.display();
                   break;
            case 4:l1.deletionLast();
                   l1.display();
                   break;
            case 5:l1.insertionLast();
                   l1.display();
                    break;
            case 6:l1.sorti();
                   l1.display();
                   break;

        default:cout<<"Invalid choice";
        }
        cout<<"Do you Want to continue (Y/N):"<<endl;
        cin>>ch1;
        }


    return 0;
}
