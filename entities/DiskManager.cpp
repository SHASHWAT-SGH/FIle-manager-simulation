#include "../headers/DiskManager.h"
#include "../headers/Commands.h"

/*
    Parameterised constructor which takes
    disk size as input and creates a virtual
    memory with given disk size.

    It also initializes the memoryBlocks
    array with the first memory block
    which is empty
*/
DiskManager::DiskManager(int diskSize)
{
    // Initialize the memory blocks
    MemoryBlock initialBlock = {0, diskSize, ""};
    memoryBlocks.push_back(initialBlock);
    commands.createRoot();
}

/*
    This function creates a directory
    with the given name.
    it returns true if creation is successfull
    else it returns false and prints the error message.
*/
bool DiskManager::createDirectory(const string dirName)
{
    if (commands.createDirectory(dirName))
    {
        cout << "Directory successfully created." << endl;
    }
    else
    {
        cout << "Unable to create Directory!" << endl;
    }
}

/*
    This function creates a file
    with the given name and given size in bytes.
    it returns true if creation is successfull
    else it returns false and prints the error message.
*/
bool DiskManager::createFile(const string fileName, int fileSize)
{
    // create file
    if (commands.createFile(fileName, to_string(fileSize)))
    { // if file is created
        cout << "Successfully created file." << endl;
    }
    else
    { // if file is not created
        cout << "Unable to create file!" << endl;
        return false;
    }
    // Find the best-fit block to allocate space for the file.
    int bestFitIndex = -1;
    int bestFitSize = diskSize + 1;

    // itterate over each block to find the best fit
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

    //  Check if a best-fit block was found.
    if (bestFitIndex == -1)
    {
        return false; // No suitable block found, allocation failed
    }

    // Allocate the file in the best-fit block.
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
    if (!commands.deleteFile(fileName))
    {
        return false;
    }

    // Find and mark the block to be deleted.
    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        if (memoryBlocks[i].fileName == fileName)
        {
            memoryBlocks[i].fileName = "";
            break;
        }
    }

    //  Merge adjacent free blocks (optional but can help reduce fragmentation).
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
    // Block 5: File: File5, Size: 25 bytes
    cout << endl
         << endl
         << "----------------------------------" << endl;
    cout << "Memory Blocks:" << endl;

    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        cout << "Block " << i << ": ";
        if (memoryBlocks[i].fileName.empty())
        {
            cout << "Free Space, Size: " << memoryBlocks[i].size << " bytes" << endl;
        }
        else
        {
            cout << "File: " << memoryBlocks[i].fileName << ", Size: " << memoryBlocks[i].size << " bytes" << endl;
        }
    }

    cout << endl
         << "----------------------------------" << endl
         << endl;
}

void DiskManager::calculateFragmentation()
{
    int totalFreeSpace = 0;
    int totalWastedSpace = 0;
    int numWastedBlocks = 0;
    cout << endl
         << endl
         << "----------------------------------" << endl;
    cout << "Memory Blocks:" << endl;
    // Calculate external fragmentation and disk wastage
    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        if (memoryBlocks[i].fileName.empty())
        {
            totalFreeSpace += memoryBlocks[i].size;
        }
        if (i > 0 && memoryBlocks[i - 1].fileName.empty())
        {
            numWastedBlocks++;
            totalWastedSpace += memoryBlocks[i - 1].size;
            cout << "Block" << i - 1 << " Wasted memory: " << memoryBlocks[i - 1].size << "bytes" << endl;
        }
    }

    // Print or log the fragmentation and wastage values

    cout << endl;
    cout << "Total Free Space: " << totalFreeSpace << " bytes" << endl;
    cout << "Disk Wastage: " << totalWastedSpace << " bytes in " << numWastedBlocks << " blocks";
    cout << endl
         << "----------------------------------" << endl
         << endl;
}

/*
    This function is used to rename a file
    it takes 2 arguments
    1. the old file name
    2. the new file name

*/
bool DiskManager::renameFile(const string oldName, const string newName)
{
    return commands.moveFile(oldName, newName);
}

/*
    This function is used to change
    the current working directory path
*/
bool DiskManager::changeDir(const string dirPath)
{
    string currDir = commands.getCurrentDir();
    if (dirPath == ".." || dirPath == "../")
    {
    }
    return false;
}

/*
    it lists all the contents of the dirPath
    in a tree like structure
    if no name is provided, it shows the contents of current path
*/
void DiskManager::showDirContent(const string dirPath)
{
    commands.printDirStruct(dirPath);
}

bool DiskManager::copyFile(const string source, const string destination)
{
    return commands.copyFile(source, destination);
}

bool DiskManager::moveFile(const string source, const string destination)
{
    return commands.moveFile(source, destination);
}

int DiskManager::getAvailableMemory()
{
    int totalFreeSpace = 0;

    for (int i = 0; i < memoryBlocks.size(); i++)
    {
        if (memoryBlocks[i].fileName.empty())
        {
            totalFreeSpace += memoryBlocks[i].size;
        }
    }
    return totalFreeSpace;
}

string DiskManager::getCurrentDir()
{
    return commands.getCurrentDir();
}