#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct MemoryBlock
{
    int start;
    int size;
    string fileName;
};

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

DiskManager::DiskManager(int diskSize)
{
    // Initialize the memory blocks
    MemoryBlock initialBlock = {0, diskSize, ""};
    memoryBlocks.push_back(initialBlock);
}

bool DiskManager::createFile(const string fileName, int fileSize)
{
    // Step 1: Find the best-fit block to allocate space for the file.
    int bestFitIndex = -1;
    int bestFitSize = diskSize + 1;

    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        if (!memoryBlocks[i].fileName.empty())
        {
            continue; // Skip allocated blocks
        }

        int blockSize = memoryBlocks[i].size;
        if (blockSize >= fileSize && blockSize < bestFitSize)
        {
            bestFitIndex = i;
            bestFitSize = blockSize;
        }
    }

    // Step 2: Check if a best-fit block was found.
    if (bestFitIndex == -1)
    {
        return false; // No suitable block found, allocation failed
    }

    // Step 3: Allocate the file in the best-fit block.
    int remainingSize = memoryBlocks[bestFitIndex].size - fileSize;
    memoryBlocks[bestFitIndex].fileName = fileName;
    memoryBlocks[bestFitIndex].size = fileSize;

    if (remainingSize > 0)
    {
        // Split the block if there's remaining space.
        MemoryBlock newBlock = {memoryBlocks[bestFitIndex].start + fileSize, remainingSize, ""};
        memoryBlocks.insert(memoryBlocks.begin() + bestFitIndex + 1, newBlock);
    }

    return true; // Allocation successful
}

bool DiskManager::deleteFile(const string fileName)
{
    // Step 1: Find and mark the block to be deleted.
    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        if (memoryBlocks[i].fileName == fileName)
        {
            memoryBlocks[i].fileName = "";
            break;
        }
    }

    // Step 2: Merge adjacent free blocks (optional but can help reduce fragmentation).
    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        if (memoryBlocks[i].fileName.empty())
        {
            int j = i + 1;
            while (j < memoryBlocks.size() && memoryBlocks[j].fileName.empty())
            {
                // Merge the adjacent free blocks.
                memoryBlocks[i].size += memoryBlocks[j].size;
                // Remove the merged block from memoryBlocks.
                memoryBlocks.erase(memoryBlocks.begin() + j);
            }
        }
    }

    return true; // Deletion successful
}

void DiskManager::displayMemory()
{
    cout << "Memory Blocks:" << endl;

    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        cout << "Block " << i << ": ";
        if (memoryBlocks[i].fileName.empty())
        {
            cout << "Free Space, Size: " << memoryBlocks[i].size << " units" << endl;
        }
        else
        {
            cout << "File: " << memoryBlocks[i].fileName << ", Size: " << memoryBlocks[i].size << " units" << endl;
        }
    }

    cout << "----------------------------------" << endl;
}

void DiskManager::calculateFragmentation()
{
    int totalFreeSpace = 0;
    int totalWastedSpace = 0;
    int numWastedBlocks = 0;

    // Calculate external fragmentation and disk wastage
    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        if (memoryBlocks[i].fileName.empty())
        {
            totalFreeSpace += memoryBlocks[i].size;
            if (i > 0 && memoryBlocks[i - 1].fileName.empty())
            {
                numWastedBlocks++;
                totalWastedSpace += memoryBlocks[i].size;
            }
        }
    }

    // Print or log the fragmentation and wastage values
    cout << "External Fragmentation: " << totalFreeSpace << " units" << endl;
    cout << "Disk Wastage: " << totalWastedSpace << " units in " << numWastedBlocks << " blocks" << endl;
}

int main()
{
    int diskSize = 1000;         // Specify the disk size
    int simulationDuration = 10; // Simulate for 10 time units

    DiskManager diskManager(diskSize);

    // Simulation loop
    for (int timeUnit = 0; timeUnit < simulationDuration; timeUnit++)
    {
        // Simulate file creation, deletion, etc.
        string fileName = "File" + to_string(timeUnit);
        int fileSize = rand() % 100 + 1; // Random file size between 1 and 100 units
        bool created = diskManager.createFile(fileName, fileSize);

        if (created)
        {
            cout << "Created " << fileName << " with size " << fileSize << " units." << endl;
        }
        else
        {
            cout << "Failed to create " << fileName << " with size " << fileSize << " units." << endl;
        }

        // Implement other file operations (e.g., deletion, moving) here

        // Update the display
        diskManager.displayMemory();

        // Calculate and print external fragmentation, disk wastage, etc.
        diskManager.calculateFragmentation();
    }

    cout << "-------------------------" << endl
         << endl
         << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        diskManager.deleteFile("File" + to_string(i * 2));
        diskManager.displayMemory();
        diskManager.calculateFragmentation();
    }

    string fileName = "File" + to_string(10);
    int fileSize = 2; // Random file size between 1 and 100 units
    bool created = diskManager.createFile(fileName, fileSize);

    if (created)
    {
        cout << "Created " << fileName << " with size " << fileSize << " units." << endl;
    }
    else
    {
        cout << "Failed to create " << fileName << " with size " << fileSize << " units." << endl;
    }

    // Implement other file operations (e.g., deletion, moving) here

    // Update the display
    diskManager.displayMemory();

    // Calculate and print external fragmentation, disk wastage, etc.
    diskManager.calculateFragmentation();

    return 0;
}
