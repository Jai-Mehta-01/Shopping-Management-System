#include<bits/stdc++.h>
#include<unistd.h>
#define ms 1000000
#include<fstream>
#include"product.h"
#include"clothes.h"
#include"catalogue.h"
#include"bill.h"
#include"customer.h"

using namespace std;

namespace sample
{
    catalogue show1;
    void clothes::add_to_cart()
    {

        cout<<"Added to cart successfully!!\n";
        ofstream output("current_user.txt",ios::app);
        output<<endl<<get_id()<<" "<<"cloth "<<type<<"("<<size<<")"<<"("<<cloth_material<<")"<<" "<<return_quan()<<" "<<total_price();
        output.close();
    }
    void clothes::show_menu()
    {
        
        do
        {
            cout<<"Which gender's product would you like to buy\n";
            cout<<"Male\n";
            cout<<"Female\n";
            string gen;
            cin>>gen;
            system("clear");
            transform(gen.begin(),gen.end(),gen.begin(), ::tolower);
            if(gen!="male" && gen!="female")
            {
                cout<<'\a';
                cout<<"Could not recognize gender \n";
                cout<<"choose again.....\n";
                show_menu();
            }
            cout<<"Choose a product\nInput the number indicated before the product\n\n";
            cout<<"1. Trousers\n";
            cout<<"2. Jeans\n";
            cout<<"3. Shirt\n";
            cout<<"4. T-Shirt\n";
            string op1;
            cin>>op1;
            system("clear");
            if(op1!="1" && op1!="2" && op1!="3" && op1!="4")
            {
                cout<<'\a';
                cout<<"Wrong size or type selection\nRetrieving to the menu\nTry again\n";
                continue;
            }
            
            cout<<"What size you wear\n";
            cout<<"1. S -> Small\n";
            cout<<"2. M -> Medium\n";
            cout<<"3. L -> Large\n";
            cout<<"4. XL -> Extra Large\n";
            cout<<"ENTER YOUR CHOICE : ";
            string op2;
            cin>>op2;
            system("clear");
            if(op2!="1" && op2!="2" && op2!="3" && op2!="4")
            {
                cout<<'\a';
                cout<<"Wrong size or type selection\nRetrieving to the menu\nTry again\n";
                continue;
            }
            cout<<"What material Would you like to wear\n";
            cout<<"1. Denim\n";
            cout<<"2. Cotton\n";
            cout<<"3. Synthetic\n";
            string op3;
            cout<<"ENTER YOUR CHOICE : ";
            cin>>op3; 
            system("clear");
            if(op3!="1" && op3!="2" && op3!="3" && op3!="4")
            {
                cout<<'\a';
                cout<<"Wrong size or type selection\nRetrieving to the menu\nTry again\n";
                continue;
            }  
            
            int data_mismatch=1;
            fstream clothes("clothes.txt");
            string ch1,ch2,ch3,typ,siz,mat;
            float pric;
            while(clothes>>ch1>>ch2>>ch3>>typ>>siz>>mat>>pric)
            {
                if(ch1==op1 && ch2==op2 && ch3==op3)
                {
                    type=typ;
                    size=siz;
                    gender=gen;
                    price=pric;
                    cloth_material=mat;
                    data_mismatch=0;
                    break;
                }
            }
            clothes.close();

            
            if(data_mismatch)
            {
                cout<<'\a';
                cout<<"Wrong size or type selection\nRetrieving to the menu\nTry again\n";
                continue;
            }
            cout<<"Would you like to see a model wearing this dress??\n";
            cout<<"Press y for yes and n for no\n";
            char cho;
            cin>>cho;
            system("clear");
            if(cho=='y')
            {
                show_model_trial();
            }
            cout<<type<<" "<<size<<" "<<cloth_material<<" "<<"Rs."<<price<<'\n';
            cout<<"Would you like to buy it\nEnter 1 for Yes or 2 to go back : ";
            int d;
            cin>>d;

            fstream file("current_user.txt");
            string us;
            file>>us;
            obj.set_username(us);
            if(d==1)
            {
                cout<<"Tell the quantity : ";
                input_quantity();
                cout<<"Press c to add to cart\n";
                cout<<"Press a to choose again\n";
                cout<<"Press q to show bill and quit\n";
                cout<<"Press t to get cart total\n";
                char u;
                cin>>u;
                   system("clear");
                if(u=='c')
                {
                        add_to_cart();
        	            cout<<"To see your bill press b and to continue shopping Press any other key\n";
                     
                        char x;
                        cin>>x;
                        system("clear");
                        if(x=='B'||x=='b')
                        {
                            obj.show_invoice();
                        }
                        else
                        {
                        
                            show1.show_catalogue();
                        }
                }
                if(u=='q')
                {
                    obj.show_invoice();
                    exit(1);
                }
                if(u=='a')
                {
                    show_menu();
                }
                if(u=='t')
                {
                    cout<<"Your bill till now is : ";
                    obj.show_the_cart_total();
                    cout<<'\n'<<'\n';
                }
               break;
            }
            else if(d==2)
            {
                show_menu();
            }
            break;


        }while(1);
    }
    void clothes::show_model_trial()
    {
        cout<<"Showing the model wearing your desired dress :)\n";
        for(int i=0;i<10;i++)
        {
            cout<<"******* Showing TRIAL *******"<<endl;
            usleep(0.5*ms);
        }
        system("clear");
    }
}

