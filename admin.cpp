#include<bits/stdc++.h>
#include<fstream>
#include"user.h"
#include"admin.h"
#include<time.h>
#include<unistd.h>
using namespace std;
namespace sample
{
    int admin::login()
    {
        int cnte=0;
        string us,pass;
        ifstream input("admin.txt");
        while(input>>us>>pass)
        {
            if(us==access_username() && pass==access_password())
            {
                system("clear");
                cout<<"Hello Sir\n";
                cout<<"What privileges would you like ?"<<'\n';
                input.close();
                cnte=1;
                break;
            }
        }
            if(!cnte)
            {
                cout<<"Sorry incorrect username or password\n";
                return 0;
            }
            return 1;

    }


    void admin::total_inc()
    {
        double total;
        fstream input("total_income.txt");
        input>>total;
        cout<<"Your total income till now is : Rs."<<total<<'\n';
        input.close();
        return;

    }


    void admin::total_on_each()
    {
       cout<<"Showing total income on each product....\n";
       int ms=1000000;
       usleep(5*ms);
       system("clear");
    }


    void admin::privileges()
    {
        cout<<"Press 1 for checking total income till now\n";
        cout<<"Press 2 for checking total income on a each product available \n";
        cout<<"Press 3 to see user feedback\n";
        cout<<"Press 4 to exit\n";
        int ch;
        cin>>ch;
        system("clear");
        if(ch==1)
        {
            total_inc();
        }
        else if(ch==2)
        {
            total_on_each();
        }
        else if(ch==3)
        {
            show_user_feedback();
        }
        else if(ch==4)
        {
            cout<<"Have a great day ahead :)\n";
            exit(1);
        }
        else
        {
            cout<<"Wrong option detected\nTry Again....\n";
            privileges();
        }
        cout<<"Press 1 to choose again and q to quit\n";
        char ci;
        cin>>ci;
        system("clear");
        if(ci=='1')
        {
            privileges();
        }
        else if(ci=='q')
        {
            exit(1);
        }
    }
    void admin::show_user_feedback()
    {
        fstream feedback("feedback.txt");
        string s;
        int i=1;
        while(std::getline(feedback,s))
        {
            cout<<i<<"."<<" ";
            cout<<s<<'\n';
            i++;
        }
    }
}
