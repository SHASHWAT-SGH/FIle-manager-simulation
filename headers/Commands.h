#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>

using namespace std;

class Commands
{
private:
    const string rootDir = ".\\root\\";
    string currentDir = ".\\root\\";

public:
    Commands(/* args */);
    string getRootDir();
    string getCurrentDir();
    string setCurrentDir(string newDir);
    bool createDirectory(const string directoryName);
    bool createFile(const string fileName, const string size);
    bool copyFile(const string src, const string dest);
    bool moveFile(const string src, const string dest);
    bool deleteFile(const string fileName);
    bool deleteDir(const string dirName);
    void printDirStruct(const string dirName);
};

#endif