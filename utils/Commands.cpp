#include "../headers/Commands.h"

Commands::Commands(/* args */)
{
}

string Commands::getRootDir()
{
    return rootDir;
}

string Commands::getCurrentDir()
{
    return currentDir;
}

string Commands::setCurrentDir(string newDir)
{
    currentDir = newDir;
}

bool Commands::createDirectory(const string directoryName)
{

    string command = "mkdir " + rootDir + directoryName;
    cout << command << endl;
    int result = system(command.c_str());

    if (result == 0)
    {
        return true; // Directory created successfully
    }
    else
    {
        return false; // Directory creation failed
    }
}

bool Commands::createFile(const string fileName, string size)
{
    string command = "fsutil file createnew " + currentDir + fileName + " " + size;
    cout << command << endl;
    int result = system(command.c_str());
    if (result == 0)
    {
        return true; // File created successfully
    }
    else
    {
        return false; // File creation failed
    }
}

bool Commands::copyFile(const string src, const string dest)
{
    string command = "copy " + currentDir + src + " " + currentDir + dest;
    int result = system(command.c_str());
    if (result == 0)
    {
        return true; // File copied successfully
    }
    else
    {
        return false; // File copy failed
    }
}

bool Commands::moveFile(const string src, const string dest)
{
    string command = "move " + currentDir + src + " " + currentDir + dest;
    int result = system(command.c_str());
    if (result == 0)
    {
        return true; // File moved successfully
    }
    else
    {
        return false; // File move failed
    }
}

bool Commands::deleteFile(const string fileName)
{
    string command = "del " + rootDir + fileName;
    int result = system(command.c_str());
    if (result == 0)
    {
        return true; // File deleted successfully
    }
    else
    {
        return false; // File deleted failed
    }
}

bool Commands::deleteDir(const string dirName)
{
    string command = "rmdir " + rootDir + dirName;
    int result = system(command.c_str());
    if (result == 0)
    {

        return true;
    }
    else
    {
        return false; // directory deleted failed
    }
}

void Commands::printDirStruct(const string dirName)
{
    string command = "tree " + currentDir + dirName + " /f";
    system(command.c_str());
}

void Commands::createRoot()
{
    system("mkdir root");
}