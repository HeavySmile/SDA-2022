#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Directory
{
    string fullpath;
    map<string, Directory*> subs;
    Directory* parent;
};

int main()
{
    int queryCount;
    cin >> queryCount;
    cin.ignore();

    string userInput = "default";
    
    Directory* currDir = new Directory;
    currDir->fullpath = "/";
    currDir->parent = nullptr;

    for (int i = 0; i <= queryCount; i++)
    {
        getline(cin, userInput);
        
        string command = userInput.substr(0, userInput.find(' '));

        if(!command.compare("ls"))
        {
            for (auto sub : currDir->subs)
            {
                cout << sub.first << ' ';
            }
            cout << '\n';
        }
        if(!command.compare("pwd"))
        {
            cout << currDir->fullpath << '\n';
        }
        if(!command.compare("mkdir"))
        {
            Directory* newDir = new Directory;
            string newDirName = userInput.substr(userInput.find(' ') + 1);
            
            if(currDir->subs.find(newDirName) != currDir->subs.end())
            {
                cout << "Directory already exists\n";
                continue;
            }

            newDir->fullpath = currDir->fullpath + newDirName + "/";
            newDir->parent = currDir;
            currDir->subs[newDirName] = newDir;
        }
        if(!command.compare("cd"))
        {
            string newCurDirName = userInput.substr(userInput.find(' ') + 1);
            
            if(!newCurDirName.compare(".."))
            {
                if(currDir->parent != nullptr) currDir = currDir->parent;
                else cout << "No such directory\n";

                continue;
            }

            auto newCurDir = currDir->subs.find(newCurDirName);
            
            if(newCurDir != currDir->subs.end()) currDir = newCurDir->second;
            else cout << "No such directory\n";
        }   
    }

    return 0;
}