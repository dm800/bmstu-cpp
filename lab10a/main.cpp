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
    std::ofstream out("headers.txt");
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
        if (st.substr(st.find_last_of('.'), st.size()) == ".c") {
            std::ifstream file("./tests/" + st);
            std::string word;
            int s = 0;
            while (std::getline(file, word, '\n')) {
                if (word.size() > 8) {
                    if (word.substr(0, 8) == "#include") {
                        if (word.find_last_of(" ") < word.size()) {
                            std::string ans = word.substr(word.find_last_of(" "), word.size());
                            out << ans << "\n";
                        }
                    }
                }
            }
        }
    }
}
