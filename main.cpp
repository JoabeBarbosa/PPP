#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream; //ostream is a class. cout is an object of ostream class.
using std::istream;

enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m)
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}

class Date{
public:
    class Invalid{};
    Date(); /** Default constructor */
    Date(int, Month, int);
private:
    int y;
    Month m;
    int d;
};

Date::Date(int a, Month b, int c)
:y(a), m(b), d(c){}

const Date& default_date()
{
     static Date dd {2022, Month::jul, 1};
     return dd;
}

Date::Date()
:y(default_date().y),
 m(default_date().m),
 d(default_date().d) {}

enum class Genre{
    fiction, nonfiction, periodical, biography, children
};

class Book{
public:
        class Invalid{};
        Book(); /** Deafult constructor */
        Book(string, string, string, Date, bool, Genre);
        string get_isbn()const{return isbn;}
        string get_title()const{return title;}
        string get_author()const{return author;}
        Date get_cp_date()const{return cp_date;}
        bool get_checked_out()const{return checked_out;}
        Genre get_gen()const{return gen;}
private:
        string isbn;
        string title;
        string author;
        Date cp_date;
        bool checked_out;
        Genre gen;
};

bool is_valid(string s)
{
    if(s.size()==4&&
       isdigit(s[0])&&
       isdigit(s[1])&&
       isdigit(s[2])&&
       (isdigit(s[3])||isalpha(s[3])))
        return true;
    else
        return false;
}

Book::Book(string a, string b, string c, Date d, bool e, Genre f)
:isbn(a), title(b), author(c), cp_date(d), checked_out(e), gen(f)
{
    if(!is_valid(isbn))throw Invalid{};
}

Book::Book()
:isbn("0000"), title(" "), author(" "), cp_date(2022, Month::jul, 1), checked_out(false), gen(Genre::nonfiction)
{
    if(is_valid(isbn))throw Invalid{};
}

class Patron{
public:
    Patron();
    string get_name()const{return name;}
    int get_card_number()const{return card_number;}
    double get_fee()const{return fee;}
    string set_name();
    void set_card_number();
    void set_fee();
    void owes_fee();
private:
    string name;
    int card_number;
    double fee;
};

void Patron::set_fee()
{
    cin >> fee;
}

bool operator==(const Book& a, const Book& b)
{
    return a.get_isbn()==b.get_isbn();
}

bool operator!=(const Book& a, const Book& b)
{
    return !(a.get_isbn()==b.get_isbn());
}

ostream& operator<<(ostream& os, const Book& a) //1) cout is an object of ostream class and cin is an object of istream class
   {                                       //2) These operators must be overloaded as a global function. And if we want to
    os << a.get_title() << endl           //   allow them to access private data members of the class,
        << a.get_author() << endl          //   we must make them friend.
        << a.get_isbn() << endl;
        return os;
}

istream& operator>>(istream& is, Book& a)
{
    string s1, s2, s3;
    is >> s1 >> s2 >> s3;
    Date d;
    bool b = false;
    Genre g = Genre::nonfiction;
    a = Book(s1, s2, s3, d, b, g); //Useful way of assignment. Not equal initialization "Book a {s1, s2, s3, d, b};".
    return is;
}

int main()
{

}
