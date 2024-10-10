#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cpr/cpr.h>
using namespace std;

string url;

// Color codes for console output
const string RESET_COLOR = "\033[0m";
const string GREEN_COLOR = "\033[32m";
const string RED_COLOR = "\033[31m";


vector<string> getfile(){
    string filename;
    vector<string> directories;

    cout << "Enter path to wordlist: ";
    cin >> filename;

    //open a file
    ifstream infile(filename);
    if (!infile){
        cerr << RED_COLOR <<"There was an error opening you file" <<RESET_COLOR<< endl;
        return directories;
    }
    // read each line and store it in a vector
    string line;
    while(getline(infile, line)){
        if(!line.empty() && line.back() == '\r'){
            line.pop_back();
        }
        directories.push_back(line);
    }
    infile.close();
    return directories;
}

void scanner()
{
    vector<string> directories= getfile();
    // for dir in directory
    for (const auto& dir : directories){
        string url2 = url + dir;
        //make request with cpr
        cpr::Response r = cpr::Get(cpr::Url{ url2 });
        if (r.status_code == 200){
            cout << GREEN_COLOR<< url2 << " is a valid path!" <<RESET_COLOR<< endl;
        }else{
            cout <<RED_COLOR<< url2 << " doesnt exist" <<RESET_COLOR<< endl;
        }
        
    }
}

int main()
{
    cout << "Enter your target domain: ";
    cin >> url;
    if(url.find("https://") != 0 && url.find("http://")!=0){
        url = "http://"+url;
    }
    scanner();
    return 0;
}