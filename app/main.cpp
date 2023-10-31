#include <iostream>
#include "../headers/Commands.h"

using namespace std;

int main()
{
    int choice;

    while (true)
    {
        cout << endl
             << endl
             << "----------------------------------------------------------------------------------" << endl
             << endl;
        cout << "\t\t\tWelcome To File Manager" << endl
             << endl;
        cout << "1. Create directory" << endl;
        cout << "2. Create file" << endl;
        cout << "3. Delete file" << endl;
        cout << "4. Rename file" << endl;
        cout << "5. Show contents of directory" << endl;
        cout << "6. Delete complete directory" << endl;
        cout << "7. Copy file" << endl;
        cout << "8. Move file" << endl;
        cout << "9. Display memory details" << endl;
        cout << "10. Show fragmentation" << endl;
        cout << "11. Show available memory" << endl;
        cout << "12. Show Disk Wastage" << endl;
        cout << ">>> ";

        // take user input
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Create directory

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;

        default:
            break;
        }
    }
}
