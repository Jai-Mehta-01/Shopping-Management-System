#ifndef __BOOKS
#define __BOOKS

#include<bits/stdc++.h>
#include"product.h"
namespace sample
{
    class books:public products
    {
        private:
            string language;
            string genre;
            string author;
            string ratings;
            string book_name;
            
        public:

            void show_book_info();
            void display_preview();
            void show_menu();
            void add_to_cart();   
    };
}
#endif // __BOOKS
