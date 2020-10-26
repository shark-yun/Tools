#include <iostream>
#include <iomanip>
using namespace std;


struct highscore 
{ 
	int score; 
	char name[24]; 
};
void initializeData(highscore scores[], int size);
void sortData(highscore scores[], int size);
void displayData(const highscore scores[], int size);

int main()
{
	int* pt = NULL;

	//memory dynamic allocation
	pt = new int;

	//size of array is dynamic and is entered by user at console
	cout << "How many scores will you enter? ";
	cin >> *pt;
	const int a = *pt;
	highscore* scores = new highscore[a];


	initializeData( &scores[a], a);
    sortData( &scores[a], a);
	displayData( &scores[a], a);


	delete scores;
	return 0;
}
void initializeData(highscore scores[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter the Name less than 24 cahr" << endl << endl;
		cout << "Enter the Name for Student " << (i + 1)<<" : ";
		cin>>scores[i].name;
	
		cout << "Enter the Score for Student " << (i + 1)<< " : ";
		cin >> scores[i].score;

	}
};
void sortData(highscore scores[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (scores[i].score > scores[j].score) {
				highscore a = scores[i];
				scores[i]= scores[j];
				scores[j] = a;
			}
		}
	}
};
void displayData(const highscore scores[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Top Scorers in order: " << endl;
		cout<< scores[i].name;
		cout << " has the score:  ";
		cout << scores[i].score << endl;
	}
};
