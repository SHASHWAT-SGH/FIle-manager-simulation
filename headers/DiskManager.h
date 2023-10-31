#ifndef DISKMANAGER_H
#define DISKMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "../headers/DataStructures.h"
#include "../headers/Commands.h"

using namespace std;

class DiskManager
{
private:
    int diskSize;
    vector<MemoryBlock> memoryBlocks;

public:
    DiskManager(int diskSize);
    Commands commands;
    bool createDirectory(const string dirName);
    bool createFile(const string fileName, int fileSize);
    bool deleteFile(const string fileName);
    void displayMemory();
    void calculateFragmentation();
    bool renameFile(const string oldName, const string newName);
    bool changeDir(const string dirPath);
    void showDirContent(const string dirPath);
    bool copyFile(const string source, const string destination);
    bool moveFile(const string source, const string destination);
    int getAvailableMemory();
    string getCurrentDir();
};

#endif