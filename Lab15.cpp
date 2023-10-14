#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void fillList(list<char> &userList, string fromFile);
void printList(list<char> userList, ofstream &fout);
list<char> removeCharacter(list<char> userList, char character);

int main() {

	ifstream fin;
	ofstream fout;
	string fileInput, vowels = "AEIOUaeiou";
	char temp;
	list<char> userList;
	
	fin.open("input.txt");
	fout.open("output.txt");

	//This while loop reads in a string from the line and starts the different fucntions.
	//Once all the functions are done, the list is cleared and the loop starts over again.
	//The loop stops once it reaches the word "END".
	getline(fin, fileInput);
	while (fileInput!= "END") {
			fillList(userList, fileInput);
			
			for (int i = 0; i < vowels.size(); ++i) {
			
				temp = vowels.at(i);
				userList = removeCharacter(userList, temp);
			}

			printList(userList, fout);
			userList.clear();
			getline(fin, fileInput);
	}

	fin.close();
	fout.close();

	return 0;
}

//This function creates the list.
void fillList(list<char> &userList, string fromFile) {
	char temp;
	for (int i = 0; i < fromFile.size(); ++i) {
		temp = fromFile.at(i);
		userList.push_back(temp);
	}
}

//This function prints out the list on both the screen and in the output file.
void printList(list<char> userList, ofstream &fout) {

	for (list<char>::iterator iter = userList.begin(); iter != userList.end(); ++iter) {
			cout << "[" << *iter << "] -> ";
	}
	cout << '0' << endl << endl;

	for (list<char>::iterator iter = userList.begin(); iter != userList.end(); ++iter) {
		fout << "[" << *iter << "] -> ";
	}
	fout << '0' << endl << endl;

}

//This function removes the vowels (both the uppercase and the lowercase) from the list.
//The function makes note of where the vowels are located in the list and store it in a vector
//After the whole list is searched, the function erases the vowels at the locations provided by
//the vector.
list<char> removeCharacter(list<char> userList, char character) {
	list<char>::iterator iter;
	vector<list<char>::iterator> vector;
	int i = 0;

		for (iter = userList.begin(); iter != userList.end(); ++iter) {
			if (*iter == character) {
				vector.push_back(iter);
			}
		}
		for (int i = 0; i < vector.size(); ++i) {
			userList.erase(vector.at(i));
		}
		++i;
		vector.clear();
		
	

	return userList;
}

/*character = toupper(character);
	userList.remove(character);

	character = tolower(character);
	userList.remove(character);*/