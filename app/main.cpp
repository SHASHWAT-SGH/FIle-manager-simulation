#include <iostream>
#include "../headers/DiskManager.h"

/*

g++ main.cpp ../entities/DiskManager.cpp ../utils/Commands.cpp ../headers/DataStructures.h  -o main

*/
using namespace std;

int main()
{
    int choice;
    DiskManager diskManager(10000);
    while (true)
    {
        cout << endl
             << endl
             << "----------------------------------------------------------------------------------" << endl
             << endl;
        cout << "\t\t\tWelcome To File Manager" << endl
             << endl;
        cout << "1. Create directory" << endl;                     // done
        cout << "2. Create file" << endl;                          // done
        cout << "3. Delete file" << endl;                          // done
        cout << "4. Rename file" << endl;                          // done
        cout << "5. Show contents of directory" << endl;           // done
        cout << "6. Show present directory" << endl;               // done
        cout << "7. Copy file" << endl;                            // done
        cout << "8. Move file" << endl;                            // done
        cout << "9. Display memory details" << endl;               // done
        cout << "10. Show fragmentation and disk wastage" << endl; // done
        cout << "11. Show available memory" << endl;               // done
        cout << "12. Change directory" << endl;
        cout << "13. Exit" << endl;
        cout << ">>> ";

        // take user input
        cin >> choice;

        cout << endl
             << endl
             << "----------------------------------------------------------------------------------" << endl
             << endl;

        string stringInput = "";
        string stringInput1 = "";
        int intInput;

        switch (choice)
        {
        case 1:
            // Create directory
            cout << "Enter directory name: ";
            cin >> stringInput;
            cout << endl;
            diskManager.createDirectory(stringInput);
            break;
        case 2:
            // Create file
            cout << "Enter file name: ";
            cin >> stringInput;
            cout << "Enter file size: ";
            cin >> intInput;
            cout << endl;
            // diskManager.createFile(stringInput, intInput);
            if (diskManager.createFile(stringInput, intInput))
            {
                cout << "success";
            }
            else
            {
                cout << "failed";
            }
            break;
        case 3:
            // Delete file
            cout << "Enter file name: ";
            cin >> stringInput;
            if (diskManager.deleteFile(stringInput))
            {
                cout << "Successfully deleted file." << endl;
            }
            else
            {
                cout << "Unable to delete file." << endl;
            }
            break;
        case 4:
            // Rename file
            cout << "Enter file name: ";
            cin >> stringInput;
            cout << "Enter new file name: ";
            cin >> stringInput1;
            cout << endl;
            if (diskManager.renameFile(stringInput, stringInput1))
            {
                cout << "File renamed." << endl;
            }
            else
            {
                cout << "Unable to rename file!" << endl;
            }
            break;
        case 5:
            // Show contents of directory
            cout << "Enter directory name: ";
            cin >> stringInput;
            cout << endl;
            diskManager.showDirContent(stringInput);
            break;
        case 6:
            // Show present directory
            cout << "current working directory: " << diskManager.getCurrentDir() << endl;
            break;
        case 7:
            // Copy file
            cout << "Enter source file location: ";
            cin >> stringInput;
            cout << "Enter destination directory: ";
            cin >> stringInput1;
            cout << endl;
            if (diskManager.copyFile(stringInput, stringInput1))
            {
                cout << "File successfully copied." << endl;
            }
            else
            {
                cout << "Unable to copy file!" << endl;
            }
            break;
        case 8:
            // move a file
            cout << "Enter source file location: ";
            cin >> stringInput;
            cout << "Enter destination file location: ";
            cin >> stringInput1;
            cout << endl;
            if (diskManager.moveFile(stringInput, stringInput1))
            {
                cout << "File moved successfully.." << endl;
            }
            else
            {
                cout << "Unable to move file!" << endl;
            }
            break;
        case 9:
            // Display memory details
            diskManager.displayMemory();
            break;
        case 10:
            // Show fragmentation
            diskManager.calculateFragmentation();
            break;
        case 11:
            // Show available memory
            intInput = diskManager.getAvailableMemory();
            cout << "Available memory: " << intInput << " bytes" << endl;
            break;
        case 12:
            break;
        case 13:
            // exit
            exit(1);
        default:
            exit(1);
        }
    }
}
