#ifndef CHAPTERSEVEN_H
#define CHAPTERSEVEN_H
#include <iostream>
#include <string>
#include <vector>


//struct Sales_data {
//    //this point is const point
//    std::string  isbn() const { return this->bookNo; }; //const member function
//    Sales_data& combine(const Sales_data &);
//    double avg_price() const;
//    //const member function, add const after function this point is a point that point to a const varaible
//    Sales_data() = default;
//    Sales_data(const std::string &s):bookNo(s){}
//    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){}
//    Sales_data(std::istream&);
//    std::string bookNo;
//    unsigned units_sold = 0;
//    double revenue = 0.0;
//};
class Sales_data {
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);
public:
    //this point is const point
    std::string  isbn() const { return this->bookNo; }; //const member function
    Sales_data& combine(const Sales_data &);
    double avg_price() const;
    //const member function, add const after function this point is a point that point to a const varaible
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){}
    Sales_data(std::istream&);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

namespace exercise_7_1_2 {
//   struct Person {
//       std::string name;
//       std::string address;
//       Person() = default;
//       Person(std::string sName, std::string sAddress):name(sName), address(sAddress){}

//       std::string getName() const { return this->name; };
//       std::string getAddress() const { return this->address;};
//   };
class Person {
private:
    std::string name;
    std::string address;
public:
    Person() = default;
    Person(std::string sName, std::string sAddress):name(sName), address(sAddress){}

    std::string getName() const { return this->name; };
    std::string getAddress() const { return this->address;};
    friend std::ostream &print(std::ostream&, const Person&);
    friend std::istream &read(std::istream&, Person&);
};
   std::ostream &print(std::ostream&, const Person&);
   std::istream &read(std::istream&, Person&);
}


class Screen;
class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
public:
    Window_mgr();
    ScreenIndex addScreen(const Screen&);

    private:
        std::vector<Screen> screens;
    public:
        void clear(ScreenIndex i);

};
   class Screen{
       friend void Window_mgr::clear(ScreenIndex i);
   public:
      using pos = std::string::size_type;
       protected:
      pos cursor = 0;
      pos height = 0, width = 0;
      std::string contents;
   public:
      Screen() = default;
      Screen(pos ht, pos wd, char c):height(ht), width(wd),
          contents(ht*wd, c){}
      char get() const {return contents[cursor];}
      inline char get(pos ht, pos wd) const;
      Screen &move(int r, int c);
      Screen &set(char);
      Screen &set(pos, pos, char);
      Screen &display(std::ostream &os) { do_display(os); return *this; }
      const Screen &display(std::ostream &os) const { do_display(os); return *this; }
      pos size() const;
   private:
      void do_display(std::ostream &os) const { os << contents; }
   };

inline Screen &Screen::move(int r, int c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos ht, pos wd) const
{
    pos row = ht * width;
    return contents[row + wd];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return  *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[ r * width + col ] = ch;
    return *this;
}



#endif // CHAPTERSEVEN_H
