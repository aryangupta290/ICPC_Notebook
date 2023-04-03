#include <bits/stdc++.h>

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

string getStr(string input) {
    std::vector<std::string> tokens;

    // Use stringstream to read tokens from the input string
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    string res = "";

    if (tokens.size() == 0) return res;
    res = tokens[0];
    for (int i = 1; i < tokens.size(); i++) {
        if (!isalnum(res.back()) || !isalnum(tokens[i][0]))
            res += tokens[i];
        else {
            res += ' ';
            res += tokens[i];
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }
    cout << "Hello";
    std::ifstream input_file(argv[1]);
    std::ofstream output_file("dummy.txt");
    std::string line;
    std::string curr = "";
    bool started = false;
    while (std::getline(input_file, line)) {
        // Remove whitespace from the line
        if (line.size() > 0 && line[0] == '#')
            started = true;
        if (!started) {
            output_file << line << endl;
            continue;
        }
        line.erase(std::unique(line.begin(), line.end(), [](char a, char b) { return isspace(a) && isspace(b); }), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());

        line = getStr(line);
        // // std::replace(line.begin(), line.end(), ' ', '\n');

        // Split the line into chunks of at most 42 characters
        if (line.size() > 0 && line[0] == '#') {
            output_file << curr << endl;
            output_file << line << endl;
            curr = "";
            line = "";
        }
        string temp = curr + line;
        if (temp.length() <= 42)
            curr += line;
        else {
            output_file << curr << endl;
            curr = line;
        }
    }
    output_file << curr << endl;
    input_file.close();
    output_file.close();

    // Remove contents of original input file
    std::ofstream ofs(argv[1], std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    // Write contents of temporary file to original input file
    std::ifstream tmp_file("dummy.txt");
    std::ofstream input_file_ofs(argv[1]);
    input_file_ofs << tmp_file.rdbuf();
    tmp_file.close();
    input_file_ofs.close();
    std::remove("dummy.txt");

    return 0;
}
