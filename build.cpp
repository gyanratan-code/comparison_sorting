#include <iostream>
#include <cstdlib>
#include <chrono>
#define endl '\n';
using namespace std;
int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }
    string filename = argv[1];
    filename = filename.substr(0, filename.rfind("."));
    string compile_command;
    #ifdef __WIN32
        compile_command="g++ -std=c++20 " + filename + ".cpp -o " + filename + ".exe";
    #elif __APPLE__ || __MACH__
        compile_command="g++ -std=c++20 " + filename + ".cpp -o " + filename;
    #elif __linux__
        compile_command="g++ -std=c++20 " + filename + ".cpp -o " + filename;
    #endif
    int compile_result = system(compile_command.c_str());
    if (compile_result == 1) {
        cout << "Compilation Error" << endl;
        return -1;
    } else {
        // cout << "Build successful" << endl;
        return 0;
    }
    return 0;
}
