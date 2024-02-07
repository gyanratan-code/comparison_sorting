#include <iostream>
#include <cstdlib>
#include <chrono>
#define endl '\n';
using namespace std;
int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    string filename = argv[1];
    filename = filename.substr(0, filename.rfind("."));
    string compile_command = "g++ -std=c++20 " + filename + ".cpp -o " + filename + ".exe";
    int compile_result = system(compile_command.c_str());
    if (compile_result == 1) {
        // cout << "Compilation Error" << endl;
    } else {
        // cout << "Build successful" << endl;
        auto start_time = chrono::high_resolution_clock::now();
        int run_result = system((filename + ".exe").c_str());
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
        if (run_result == 0) {
            // cout << "\nSuccessful attempt" << endl;
            // cout << duration.count() << " ms : Runtime" << endl;
            cout<<duration.count();
        } else {
            // cout << "\nRuntime error" << endl;
        }
    }
    return 0;
}
