#include <iostream>
#include <fstream>                //This is the library 
#include <map>
#include <string>




using namespace std;
class GroceryTracker {     // this this the class
private:

	string inputTextFileName = "CS210_Project_Three_Input_File.txt";  //I am defining my variables here
	string outputTextFileName = "frequency.dat";
	map<string, int>  GroceryTracker;


public:

	bool loadFileData() {
		ifstream inputFile(inputTextFileName);
		if (!inputFile.is_open()) {
			cout << "error for file being open"; //this is the public class
			return false;
		}
		string itemName;

		while (inputFile >> itemName) {
			GroceryTracker[itemName]++; // using a while loop
		}
		return true;
	}

	bool saveFileData() {
		ofstream saveFileData(outputTextFileName);
		if (!saveFileData.is_open()) {
			cout << "File cannot open: Error";  // using if statements
			return false;
		}

		for (const auto& itemData : GroceryTracker) {  // using for loop

			saveFileData << itemData.first << " " << itemData.second << endl;
		}

		saveFileData.close();

		return true;
	}

	bool printFrequencies() {
		for (const auto& itemData : GroceryTracker) {
			                                                         // this is the print frequencies and for loop function
			cout << itemData.first << " " << itemData.second << endl;
		}

		return true;
	}
	bool printHistogram() {

		for (const auto& itemData : GroceryTracker) {
			cout << itemData.first << " ";                 // this is the print histogram adn for loop function
			for (int i = 0; i < itemData.second; i++) {

				cout << "*";

			}
			cout << endl;
		}
		return true;
	}

	void search() {

		string itemName;
		cout << "Please input an item: " << endl;  // I am telling the user ito input an item and using a for loop to so can numorous times
		cin >> itemName;
		for (const auto& itemData : GroceryTracker) {
			if (itemData.first == itemName)
				cout << itemData.first << " " << itemData.second << endl;
		}

	}
	bool displayMenu() {
		int dM = 0;
		do {
			cout << "1. Print Frequencies" << endl;
			cout << "2. Print Histogram" << endl;   // Using display Menue Function
			cout << "3. Exit Program" << endl;
			cout << "Please enter a choice:  " << endl;
			cin >> dM;

			switch (dM) {

			case 1:
				printFrequencies(); //using switch statement and do while loop for the display menue function


				break;

			case 2:
				printHistogram();


				break;

			case 3: cout << "Have a nice day!" << endl;

				break;

			default:

				cout << "That input is invalid!!!" << endl;
			}


		} while (dM != 3);
		return true;
	}




};




int main() {

	GroceryTracker groceryTrackerObject;

	groceryTrackerObject.loadFileData();
                                                     // this is the int main function calling all functions
	groceryTrackerObject.saveFileData();

	groceryTrackerObject.printFrequencies();

	groceryTrackerObject.printHistogram();

	groceryTrackerObject.displayMenu();



}