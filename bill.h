#ifndef __bill
#define __bill
#include<bits/stdc++.h>
#include"payment.h"
using namespace std;
namespace sample
{
    class bill
    {
        private:
            bool purchased;
            payment pay;
        public:
            void show_bill();
            void view_cart();
            void show_cart_total();
            void proceed_to_pay();
    };
}
#endif