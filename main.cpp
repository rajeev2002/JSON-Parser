#include <bits/stdc++.h>
#include "parser.h"

using namespace std;
using namespace std::filesystem;

int main(){

    path p = "tests";

    vector<string> files;

    for (auto const& dir_entry : recursive_directory_iterator("tests")){
        if(!is_directory(dir_entry)){
            string path_str = dir_entry.path().generic_string();
            bool res = parse(path_str);
            string temp = path_str;
            reverse(temp.begin(),temp.end()-5);
            int pos = temp.find("/");
            string flag = temp.substr(0,pos);
            reverse(flag.begin(), flag.end());
            cout<<path_str<<"     ";
            if((flag == "valid" && res) || (flag == "invalid" && !res)){
                cout<<"pass";
            }else{
                cout<<"fail";
            }
            cout<<"\n";
        }
    }

    return 0;
}