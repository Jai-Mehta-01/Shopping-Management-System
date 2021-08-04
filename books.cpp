#include<bits/stdc++.h>
#include"product.h"
#include"bill.h"
#include"books.h"
#include"catalogue.h"
#include"customer.h"
using namespace std;
namespace sample
{
    catalogue show2;
    void books::display_preview()
    {
        cout<<"Showing the preview of "<<book_name<<'\n';
        cout<<"Showing contents from one of the chapters\n";
        cout<<"A very nice book to read \nRecommended by most critics\nA must buy\n\n";
    }
    void books::add_to_cart()
    {
      
        cout<<"Added to cart successfully!!\n";
        ofstream output("current_user.txt",ios::app);
        output<<endl<<get_id()<<" "<<"book "<<book_name<<" "<<return_quan()<<" "<<total_price();
        output.close();
    }
    void books::show_book_info()
    {
        cout<<"Language: "<<language<<'\n';
        cout<<"Genre: "<<genre<<'\n';
        cout<<"Book Name: "<<book_name<<'\n';
        cout<<"Author: "<<author<<'\n';
        cout<<"Ratings: "<<ratings<<"/5"<<'\n';
        cout<<"Price: Rs."<<price<<'\n';
    }
    void books::show_menu()
    {
        do
        {
            cout<<"Which language book you read\n";
            cout<<"1. ENGLISH\n";
            cout<<"2. HINDI\n";
            cout<<"3. FRENCH\n";
            cout<<"4. LATIN\n";
            cout<<"5. SPANISH\n";
            cout<<"ENTER YOUR CHOICE\n";
            string op1;
            cin>>op1;
            system("clear");
            int x=stoi(op1);
            if(x<1 || x>5)
            {
                cout<<'\a';
                cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                continue;
            }
            cout<<"What genre you like\n";
            cout<<"1. FANTASY\n";
            cout<<"2. BIOGRAPHY/AUTO-BIOGRAPHY\n";
            cout<<"3. ACTION and THRILLER\n";
            cout<<"4. SCIENCE-FICTION\n";
            cout<<"5. SUSPENSE(MYSTERY)\n";
            cout<<"ENTER YOUR CHOICE\n";
            string op2;
            cin>>op2;
            system("clear");
            int y=stoi(op2);
            if(y<1 || y>5)
            {
                cout<<'\a';
                cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                continue;
            }

            string op3;
            if(op2=="1") 
            {
                cout<<"Select the book\n";
                cout<<"1. Harry Potter and the Half-Blood Prince\n";
                cout<<"2. Narnia-The Witch The Wizard and the Wardrobe\n";
                cout<<"3. Alice in Wonderland\n";
                cout<<"ENTER YOUR CHOICE\n";
                cin>>op3;
                system("clear");
                int z=stoi(op3);
                if(z<1 || z>3)
                {
                    cout<<'\a';
                    cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                    continue;
                }
            }
            else if(op2=="2") 
            {
                cout<<"Select the book\n";
                cout<<"1. Playing it My Way\n"; 
                cout<<"2. Steve-Jobs\n";    
                cout<<"3. The Story of My Life\n";  
                cout<<"ENTER YOUR CHOICE\n";
                cin>>op3;
                system("clear");
                int z=stoi(op3);
                if(z<1 || z>3)
                {
                    cout<<'\a';
                    cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                    continue;
                }
            }
            else if(op2=="3")  
            {
                cout<<"Select the book\n";
                cout<<"1. HUNGER GAMES\n";
                cout<<"2. BATMAN RISES\n";
                cout<<"3. Z WARS\n";
                cout<<"ENTER YOUR CHOICE\n";
                cin>>op3;
                system("clear");
                int z=stoi(op3);
                if(z<1 || z>3)
                {
                    cout<<'\a';
                    cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                    continue;
                }
            }
            else if(op2=="4")   
            {
                cout<<"Select the book\n";
                cout<<"1. Transformers\n";
                cout<<"2. Star Wars\n";
                cout<<"3. Mandalorian\n";
                cout<<"ENTER YOUR CHOICE\n";
                cin>>op3;
                system("clear");
                int z=stoi(op3);
                if(z<1 || z>3)
                {
                    cout<<'\a';
                    cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                    continue;
                }
            }
            else if(op2=="5")  
            {
                cout<<"Select the book\n";
                cout<<"1. Sherlock\n";
                cout<<"2. Insidious\n";
                cout<<"3. lupin\n";
                cout<<"ENTER YOUR CHOICE\n";
                cin>>op3;
                system("clear");
                int z=stoi(op3);
                if(z<1 || z>3)
                {
                    cout<<'\a';
                    cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                    continue;
                }
            }

            string ch1,ch2,ch3,lan,gen,book_nam,aut,rat;
            float pric;
            int data_mismatch=1;
            fstream book("books.txt");
            while(book>>ch1>>ch2>>ch3>>lan>>gen>>book_nam>>aut>>rat>>pric)
            {
                if(ch1==op1 && ch2==op2 && ch3==op3)
                {
                    language=lan;
                    genre=gen;
                    author=aut;
                    book_name=book_nam;
                    ratings=rat;
                    price=pric;   
                    data_mismatch=0;
                    break;
                }
            }
            
            if(data_mismatch)
            {
                cout<<'\a';
                cout<<"Wrong type selection\nRetrieving to the menu\nTry again\n";
                continue;
            }
            cout<<"Showing book info\n";
            show_book_info();
            cout<<"Would you like to see the books's preview ?\n";
            char choi;
            cout<<"Press y for yes and n for no\n";
            cin>>choi;
            system("clear");
            choi=tolower(choi);
            fstream file("current_user.txt");
            string us;
            file>>us;
            obj.set_username(us);
            if(choi=='y')
            {
                display_preview();
            }

            cout<<"Would you like to buy it\nEnter 1 for Yes  or 2 to go back : ";
            int d;
            cin>>d;
            system("clear");
            if(d==1)
            {
                cout<<"Tell the quantity : ";
                input_quantity();
                cout<<"Press c to add to cart\n";
                cout<<"Press a to choose again\n";
                cout<<"Press q to show bill and quit\n";
                cout<<"Press t to get carmenut total\n";
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
                        show2.show_catalogue();
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
                    cout<<'\n';
                }

            }
            break;
        }while(1);
    }
}