#ifndef __ADMIN_HEADER
#define __ADMIN_HEADER

#include<bits/stdc++.h>
#include"user.h"
using namespace std;
namespace sample
{
    class admin:public user
    {
        public:
            int login();
            void privileges();
            void total_inc();
            void total_on_each();
            void show_user_feedback();
    };


}
#endif // __ADMIN_HEADER
