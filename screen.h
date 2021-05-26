#ifndef SCREEN
#define SCREEN
    #include "functions.h"

class Screen{
public:
    //using pos = std::string::size_type;
    typedef std::string::size_type pos;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    mutable size_t access_ctr = 0;

public:
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(wd * ht, c){}

    char get() const {
        this->some_member();
        return contents[cursor];
    }
    inline char get(pos r, pos c) const;
    Screen &move(pos r, pos c);

    void some_member() const;
    size_t get_access() const;

    ostream &print(ostream &os = cout) const;
    Screen &set(char);
    Screen &set(pos, pos, char);
};

char Screen::get(pos r, pos c) const{
    pos row = r * width;
    this->some_member();
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    this->some_member();
    return *this;
}

void Screen::some_member() const{
    access_ctr++;
}

inline size_t Screen::get_access() const{
    return access_ctr;
}

ostream &Screen::print(ostream &os) const{
    int i = 0;
    for(char c: contents){
        if(i == width) {
            cout << endl;
            i = 0;
        }
        os.put(c);
        i++;
    }
    os<<endl;
    return os;
}

inline Screen &Screen::set(char c){
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch){
    contents[r*width + col] = ch;
    return *this;
}

#endif