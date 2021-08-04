#include<bits/stdc++.h>
#include"payment.h"
#include"bill.h"
#include"clothes.h"
#include"books.h"
#include"watches.h"
#include"catalogue.h"
using namespace std;
namespace sample
{
    void bill::show_bill()
    {
      
        char ids[10];      
        char prod_typ[50];
        char prod[50];
        char quantity[50];
        double total_price;
        fstream cart("current_user.txt");
        string us,mob,em;
        int f=0;
        
        while(!cart.eof())
        {
            if(f==0)
            {
                cart>>us>>mob>>em;
                cout<<"USERNAME: "<<us<<'\n';
                cout<<"MOBILE NUMBER: "<<mob<<'\n';
                cout<<"EMAIL: "<<em<<'\n';
                f=1;
                cout<<endl;
                printf("%-8s","ID");
                printf("%-15s","Product Type");
                printf("%-48s","Product Name");
                printf("%-12s","Quantity");
                printf("%-9s","Total(In Rupees)\n\n");
                continue;
            }
            
                cart>>ids>>prod_typ>>prod>>quantity>>total_price;
                printf("%-8s",ids);
                printf("%-15s", prod_typ);
                printf("%-50s",prod);
                printf("%-12s",quantity);
                auto str=std::to_string(total_price);
                cout<<str<<'\n';            
        }
        cout<<endl;
        printf("Total number of distinct items bought are: %s\n",ids);
        cout<<'\n';
        show_cart_total();
        cout<<endl;
        char cho;
        do{
        cout<<"Would you like to make payment??\n";
        cout<<"Press y for yes or r to return to catalogue or q to quit\n";
        
        cin>>cho;
        system("clear");
        cho=tolower(cho);
        if(cho=='y')
        {
            proceed_to_pay();
            purchased=true;
        }
        else if(cho=='q')
        {
            cout<<"You have been logged out\n";
            cout<<"Have a nice day :)\n";
            exit(1);
        }
        else if(cho=='r')
        {
          catalogue random;
          random.show_catalogue();
        }
        else{
          cout<<"Invalid input..try again\n";
        }
        }while(cho!='y'||cho!='q'||cho!='r');
        cart.close();
    }
    void bill::show_cart_total()
    {
        string prod_typ,prod,ids;
        int quantity;
        float total_price;
        fstream cart("current_user.txt");
        float cart_total=0;
        string us,mob,em;
        int f=0;
        while(!cart.eof())
        {
            if(f==0)
            {
                cart>>us>>mob>>em;
                f=1;
            }
            else
            {   cart>>ids>>prod_typ>>prod>>quantity>>total_price;
                cart_total+=total_price;
            }
        }
        auto str=std::to_string(cart_total);
        cout<<"Your total is : Rs."<<str<<'\n';
        cart.close();
        
    }
    void bill::proceed_to_pay()
    {
        pay.verify_user();
        pay.get_payment_mode();
        pay.display_payment_details();
    }
}