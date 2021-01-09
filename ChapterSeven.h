#ifndef CHAPTERSEVEN_H
#define CHAPTERSEVEN_H
#include <iostream>
#include <string>

struct Sales_data {
    //this point is const point
    std::string  isbn() const { return this->bookNo; }; //const member function
    Sales_data& combine(const Sales_data &);
    double avg_price() const;
    //const member function, add const after function this point is a point that point to a const varaible

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

namespace exercise_7_1_2 {
   struct Person {
       std::string name;
       std::string address;

       std::string getName() const { return this->name; };
       std::string getAddress() const { return this->address;};
   };
   std::ostream &print(std::ostream&, const Person&);
   std::istream &read(std::istream&, Person&);
}

#endif // CHAPTERSEVEN_H
