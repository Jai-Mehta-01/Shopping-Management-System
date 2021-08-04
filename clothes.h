#ifndef __CLOTHES
#define __CLOTHES

#include<bits/stdc++.h>
#include"product.h"
#include<fstream>
using namespace std;
namespace sample
{
    class clothes:public products
    {
        private:
            string type;
            string size;
            string gender;
            string cloth_material;
        public:
            void show_menu();
            void show_model_trial();
            void add_to_cart();    
    };
}
#endif // __CLOTHES
