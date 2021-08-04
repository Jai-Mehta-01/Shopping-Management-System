#include<bits/stdc++.h>
#include<fstream>
#include"catalogue.h"
#include"product.h"
#include"clothes.h"
#include"books.h"
#include"watches.h"
namespace sample
{
    void catalogue::show_catalogue()
    {
        
        char h;
        do
        {
            cout<<"*************************  LIST OF ITEMS TO BUY  *************************\n";
            cout<<"1.CLOTHES\n";
            cout<<"2.BOOKS\n";
            cout<<"3.WATCHES\n";
            cout<<"ENTER YOUR CHOICE : ";
            int choice;
            cin>>choice;
            system("clear");
            if(choice==1)
            {
                clothes obj;
                obj.show_menu();
            }
            else if(choice==2)
            {
                books obj;
                obj.show_menu();
            }
            else if(choice==3)
            {
                watches obj;
                obj.show_menu();
            }
            else
            {
                cout<<'\a';
                cout<<"Sorry Invalid Input :(\n";
                cout<<"Press d to try again and any other key to quit\n";
                cin>>h;
                system("clear");
            }
        }
        while(h=='d'|| h=='D');
    }
}
