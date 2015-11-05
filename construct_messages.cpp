#include <iostream>

#define CONCAT(x, y) x ## y
#define CONCATINATE(x, y) CONCAT(x, y)
#define SAY(x) struct CONCATINATE(saystruct, __LINE__) { static std::string text() { return x; } }; print<CONCATINATE(saystruct, __LINE__)> CONCATINATE(printer, __LINE__);

namespace
{
   template<class S>
      struct print
      {
         print()
         {
            std::cout << S::text() << std::endl;
         }
      };

   struct thing
   {
      thing() { std::cout << "thing::ctor" << std::endl; }
   };

   struct stuff
   {
      thing i;
      SAY("...constructed i...");
      thing j;
      SAY("...constructed j...");

   };
}

int main()
{
   stuff s;
}

