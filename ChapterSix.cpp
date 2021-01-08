#include<stdio.h>
#include <vector>
#include "ChapterSix.h"

using namespace  std;
using funP = int (*) (int, int);
int section_six_dot_seven::sumTwoNumber(int x, int y){
   printf("%d + %d = %d \n", x, y, x + y );
   return 0;
}

int section_six_dot_seven::minusTwoNumber(int x, int y){
   printf("%d - %d = %d \n", x, y, x - y);
   return 0;
}

int section_six_dot_seven::multiplyTwoNumber(int x, int y){
   printf("%d * %d = %d \n", x, y, x * y);
   return 0;
}

int section_six_dot_seven::divideTwoNumber(int x, int y){
   printf("%d / %d = %d \n", x, y, x / y);
   return 0;
}

int section_six_dot_seven::callFunctions()
{
   vector<funP> v1;
   funP sumTwo = nullptr, minusTwo = nullptr,
        multiplyTwo = nullptr, dividedTwo = nullptr;
   sumTwo = section_six_dot_seven::sumTwoNumber;
   v1.push_back(sumTwo);
   minusTwo = section_six_dot_seven::minusTwoNumber;
   v1.push_back(minusTwo);
   multiplyTwo = section_six_dot_seven::multiplyTwoNumber;
   v1.push_back(multiplyTwo);
   dividedTwo = section_six_dot_seven::divideTwoNumber;
   v1.push_back(dividedTwo);
   for(auto element = v1.begin();element != v1.end(); element++)
   {
        (*element)(4,5);
   }
   return 0;
}
