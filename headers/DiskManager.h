#ifndef DISKMANAGER_H
#define DISKMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "../headers/DataStructures.h"

using namespace std;

class DiskManager
{
public:
    DiskManager(int diskSize);
    bool createFile(const string fileName, int fileSize);
    bool deleteFile(const string fileName);
    void displayMemory();
    void calculateFragmentation();

private:
    int diskSize;
    vector<MemoryBlock> memoryBlocks;
};

#endif