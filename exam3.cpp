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
    std::ofstream out("tags.txt");
    std::vector<std::string> hnames;
    while(elem != NULL) {
        if (elem->d_name[0] != '.') {
            std::string st;
            st = st + elem->d_name;
            hnames.push_back(st);
        }
        elem = readdir(t);
    }
    for (std::string file : hnames) {
        std::string st = file;
        if (st.substr(st.find_last_of('.'), st.size()) == ".html") {
            std::ifstream file("./tests/" + st);
            std::string word;
            int s = 0;
            while (std::getline(file, word, ' ')) {
                if (word.size() > 1) {
                    if (word.substr(0, 1) == "<") {
                        if (word.find_first_of(">") < word.size()) {
                            std::string ans = word.substr(word.find_first_of("<"), word.size() - 1);
                            out << ans << "\n";
                        }
                    }
                }
            }
        }
    }
}
