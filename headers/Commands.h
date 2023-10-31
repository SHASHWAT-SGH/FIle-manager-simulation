#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>

using namespace std;

class Commands
{
private:
    /* data */
public:
    string rootDir = ".\\root\\";
    string currentDir = ".\\root\\";
    Commands(/* args */);
    bool createDirectory(const string directoryName);
    bool createFile(const string fileName, const string size);
    bool copyFile(const string src, const string dest);
    bool moveFile(const string src, const string dest);
    bool deleteFile(const string fileName);
    bool deleteDir(const string dirName);
    void printDirStruct(const string dirName);
};

#endif