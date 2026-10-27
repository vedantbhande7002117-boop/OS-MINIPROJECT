#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdio>

using namespace std;

void createFile() {
    string filename, content;
    cout << "Enter file name (example: notes.txt): ";
    getline(cin, filename);

    ofstream file(filename);
    if (!file) {
        cout << "Error: Could not create the file.\n";
        return;
    }

    cout << "Enter content for the file: ";
    getline(cin, content);
    file << content << '\n';
    file.close();

    cout << "File created and content saved successfully.\n";
}

void readFile() {
    string filename, line;
    cout << "Enter file name to read: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file) {
        cout << "Error: File not found or cannot be opened.\n";
        return;
    }

    cout << "\n----- File Content -----\n";
    bool hasContent = false;
    while (getline(file, line)) {
        cout << line << '\n';
        hasContent = true;
    }
    if (!hasContent) {
        cout << "(File is empty)\n";
    }
    cout << "------------------------\n";
    file.close();
}

void appendFile() {
    string filename, content;
    cout << "Enter file name to append: ";
    getline(cin, filename);

    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error: Could not open the file for appending.\n";
        return;
    }

    cout << "Enter content to append: ";
    getline(cin, content);
    file << content << '\n';
    file.close();

    cout << "Content appended successfully.\n";
}

void searchInFile() {
    string filename, keyword, line;
    cout << "Enter file name to search: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file) {
        cout << "Error: File not found or cannot be opened.\n";
        return;
    }

    cout << "Enter text to search for: ";
    getline(cin, keyword);

    int lineNumber = 0;
    bool found = false;
    while (getline(file, line)) {
        ++lineNumber;
        if (line.find(keyword) != string::npos) {
            cout << "Found on line " << lineNumber << ": " << line << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << "Text not found in the file.\n";
    }
    file.close();
}

void deleteFile() {
    string filename;
    cout << "Enter file name to delete: ";
    getline(cin, filename);

    if (remove(filename.c_str()) == 0) {
        cout << "File deleted successfully.\n";
    } else {
        cout << "Error: Could not delete the file. Check the name and permissions.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== FILE MANAGEMENT SYSTEM =====\n";
        cout << "1. Create a file and write content\n";
        cout << "2. Read a file\n";
        cout << "3. Append content to a file\n";
        cout << "4. Search text in a file\n";
        cout << "5. Delete a file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: appendFile(); break;
            case 4: searchInFile(); break;
            case 5: deleteFile(); break;
            case 0: cout << "Exiting File Management System. Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
