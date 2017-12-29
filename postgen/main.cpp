#include <iostream>
#include <fstream>
using namespace std;

void getData();
string title;
string date;
string category;
string textfile;

int main() {
    cout << "Jekyll Post Generator" << endl;
    cout << "Make sure you're in the jekyll root dir!" << endl;
    getData();

    ofstream _file;
    _file.open(date + "-" + title + ".markdown");
    _file << "---\n";
    _file << "title: " + title + "\n";
    _file << "date: " + date + "\n";
    _file << "category: " + category + "\n";
    _file << "---\n\n";

    ifstream text;
    text.open(textfile);
    if (!text) {
    cerr << "Unable to open file datafile.txt\n";
    exit(1);   // call system to stop
    }
    string line;
    while(!text.eof()) {
	        getline(text,line); // Saves the line in STRING.
	        _file << line + "\n"; // Prints our STRING.
    }
    text.close();

    _file.close();
    cin.get();
    return 0;
}

void getData(){
    cout << "Title: ";
    cin >> title;
    cout << "Date(yyy-dd-mm): ";
    cin >> date;
    cout << "Category: ";
    cin >> category;
    cout << "Path to text file: ";
    cin >> textfile;
}