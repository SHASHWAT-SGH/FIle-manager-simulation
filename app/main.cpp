#include <iostream>
#include "../headers/DiskManager.h"

/*

g++ main.cpp ../entities/DiskManager.cpp ../utils/Commands.cpp ../headers/DataStructures.h  -o main

*/
using namespace std;

int main()
{
    int choice;
    DiskManager diskManager(1000);
    while (true)
    {
        cout << endl
             << endl
             << "----------------------------------------------------------------------------------" << endl
             << endl;
        cout << "\t\t\tWelcome To File Manager" << endl
             << endl;
        cout << "1. Create directory" << endl; // done
        cout << "2. Create file" << endl;      // done
        cout << "3. Delete file" << endl;
        cout << "4. Rename file" << endl;                // done
        cout << "5. Show contents of directory" << endl; // done
        cout << "6. Delete complete directory" << endl;
        cout << "7. Copy file" << endl; // done
        cout << "8. Move file" << endl; // done
        cout << "9. Display memory details" << endl;
        cout << "10. Show fragmentation" << endl;
        cout << "11. Show available memory" << endl;
        cout << "12. Show Disk Wastage" << endl;
        cout << "13. Change directory" << endl;
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
            diskManager.createFile(stringInput, intInput);
            break;
        case 3:
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
            cout << "Enter file name: ";
            cin >> stringInput;
            cout << endl;
            diskManager.showDirContent(stringInput);
            break;
        case 6:
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
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            // Change directory

            break;

        default:
            exit(1);
        }
    }
}
