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
    auto start_time = chrono::high_resolution_clock::now();
    // check the os which is running in current system for windows use filename.exe and for linux use .out file
    int run_result;
    #ifdef __WIN32
        run_result = system((filename + ".exe").c_str());
    #elif __APPLE__ || __MACH__
        run_result = system(("./"+filename+).c_str());
    #elif __linux__
        run_result = system(("./"+filename+).c_str());
    #endif
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    if (run_result == 0) {
        // cout << "\nSuccessful attempt" << endl;
        // cout << duration.count() << " ms : Runtime" << endl;
        cout<<duration.count();
        return 0;
    } else {
        return -1;
        // cout << "\nRuntime error" << endl;
    }
    return 0;
}
