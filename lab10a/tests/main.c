#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <vector>

int main() {
    DIR* t = opendir("tests");
    dirent* elem = readdir(t);
    std::ofstream out("sums.txt");
    std::vector<std::string> filenames;
    while(elem != NULL) {
        if (elem->d_name[0] != '.') {
            std::string st;
            st = st + elem->d_name;
            filenames.push_back(st);
        }
        elem = readdir(t);
    }
    for (std::string file : filenames) {
        std::string st = file;
        if (st.substr(st.find_last_of('.'), st.size()) == ".txt") {
            std::ifstream file("./tests/" + st);
            std::string word;
            int s = 0;
            while (std::getline(file, word, ' ')) {
                int a = atoi(word.c_str());
                s += a;
            }
            out << st << " " << s << "\n";
        }
    }
}
