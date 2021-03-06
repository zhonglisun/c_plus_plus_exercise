#include "ChapterSeven.h"

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

double Sales_data::avg_price() const{
    if( units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return  *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
   Sales_data sum = lhs;
   sum.combine(rhs);
   return sum;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
}
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return  is;
}

std::istream &exercise_7_1_2::read(std::istream &is, Person &p){
    is >> p.name >> p.address;
    return is;
}

std::ostream &exercise_7_1_2::print(std::ostream &os, const Person &p){
    os << p.getName() << " " << p.getAddress() ;
    return os;
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen s =screens[i];
    s.contents =   std::string(s.height * s.width, ' ');
}

Screen::pos Screen::size() const
{
    return  height * width;
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return  screens.size() -1;
}
