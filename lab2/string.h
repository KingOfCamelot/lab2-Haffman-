#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char* line;
    int length;
    static int num;
    static const int CINLIM = 80;
public:

    String(const char* temp);
    String();
    String(const String&);
    ~String();
    int length_() { return length; }

    String& operator=(const String&);
    String& operator=(const char*);
    char& operator[](int i);
    const char& operator[](int i) const;

    friend bool operator<(const String& line, const String& line_2);
    friend bool operator>(const String& line_1, const String& line_2);
    friend bool operator==(const String& line, const String& line_2);
    friend ostream& operator<<(ostream& os, const String& line_2);
    friend istream& operator>>(istream& is, String& line);
    friend String operator+(const String& line_1, const String& line_2);

    int quantity();
};