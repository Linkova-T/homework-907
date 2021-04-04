#include <iostream>
#include <fstream>
#include <string>


int main() {

    std::fstream ofile("output.txt", std::ios::out);
    std::fstream ifile("input.txt", std::ios::in);
    std::string str;
    bool flag = true;
    while (!ifile.eof()) {
        getline(ifile, str);
        for (int i = 0; i < str.length(); ++i) {
           
                if ((str[i] == '/') && (str[i + 1] == '/')) { ofile << '\n'; break; }
                if ((str[i] == '/') && (str[i + 1] == '*')) { flag = false; }
                if ((str[i] == '*') && (str[i + 1] == '/')) { i += 2; flag = true; }
                if (flag) { ofile << str[i]; }
            
        }
    }
    ifile.close();

    return 0;
}

