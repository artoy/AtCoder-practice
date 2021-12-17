#include "../tasks/CCounting2.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
    std::string input;
    std::string output;
    bool active;
    bool has_output;
};

bool check(std::string expected, std::string actual) {
    while(!expected.empty() && isspace(*--expected.end()))
        expected.erase(--expected.end());
    while(!actual.empty() && isspace(*--actual.end()))
        actual.erase(--actual.end());
    return expected == actual;
}

} // namespace jhelper

signed main() {
    std::vector<jhelper::Test> tests = {
        {"3 1\n100 160 130\n120\n", "2\n", true, true},{"5 5\n1 2 3 4 5\n6\n5\n4\n3\n2\n", "0\n1\n2\n3\n4\n", true, true},{"5 5\n804289384 846930887 681692778 714636916 957747794\n424238336\n719885387\n649760493\n596516650\n189641422\n", "5\n3\n5\n5\n5\n", true, true},
    };
    bool allOK = true;
    int testID = 0;
    std::cout << std::fixed;
    double maxTime = 0.0;
    std::cout << std::endl;
    for(const jhelper::Test& test: tests ) {
        std::cout << "\033[4m" << "Test #" << ++testID << "\033[m" << std::endl;
        std::cout << "Input: \n" << test.input << std::endl;
        if (test.has_output) {
            std::cout << "Expected output: \n" << test.output << std::endl;
        }
        else {
            std::cout << "Expected output: \n" << "N/A" << std::endl;
        }
        if (test.active) {
            std::stringstream in(test.input);
            std::ostringstream out;
            std::clock_t start = std::clock();
            CCounting2 solver;
            solver.solve(in, out);
            std::clock_t finish = std::clock();
            double currentTime = double(finish - start) / CLOCKS_PER_SEC;
            maxTime = std::max(currentTime, maxTime);
            std::cout << "Actual output: \n" << out.str() << std::endl;
            if (test.has_output) {
                bool result = jhelper::check(test.output, out.str());
                allOK = allOK && result;

                if (result) {
                    std::cout << "Result: " << "\033[32m OK \033[m" << std::endl;
                }
                else {
                    std::cout << "Result: " << "\033[31m WA \033[m" << std::endl;
                }
            }
            std::cout << "Time: " << currentTime << std::endl;
        }
        else {
            std::cout << "SKIPPED\n";
        }


        std::cout << std::endl;

    }
    if(allOK) {
        std::cout << "\033[32m" << "All OK" << "\033[m"<< std::endl;
    }
    else {
        std::cout << "\033[31m" << "Some cases failed" << "\033[m"<< std::endl;
    }
    std::cout << "Maximal time: " << maxTime << "s." << std::endl;
    return 0;
}