#include "functions.h"

int main(){
    Window w;
    Screen s = w.screens[0];
    s.move(4,0).set('#');
    s.print();
    cout << s.get_access() << endl;

    //### const Screen myScreen(15, 10, 'F');
    // cout << myScreen.get_access() << endl;


    // char c = myScreen.get();
    // cout << "\033[31mOdsek 1:\033[0m\n" << c << endl;
    // cout << myScreen.get_access() << endl;


    // char ch = myScreen.get(1,4);
    // cout << "\033[31mOdsek 2:\033[0m\n" << ch << endl;
    // cout << myScreen.get_access() << endl;

    // cout << "\033[31mOdsek 3:\n";
    // myScreen.print();
    // cout<<"\033[0m\n";
    return 0;
}