#include <iostream>
#include <vector>

#include "ChapterSix.h"
#include "ChapterSeven.h"

//using namespace std;

int main()
{
   section_six_dot_seven::callFunctions();
   struct Sales_data book1, book2;
   read(read(std::cin, book1), book2);
   std::cout <<"print book1 " <<std::endl;
   print(std::cout, book1);
   std::cout <<"print book2 " <<std::endl;
   print(std::cout, book2);
   system("pause");
   return 0;
}
