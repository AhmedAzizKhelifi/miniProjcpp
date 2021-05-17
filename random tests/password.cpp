#include <iostream>
#include <conio.h>
int main(){
    char c = ' ';
    std::string pw;
    while (c!=13){  // c = 13 is 'Enter' key.
        c = getch();
        if (c!=13){
            pw +=c;
            std::cout << "*";
        }
    }
    std::cout <<"\nPassword is :"  << pw;

}
