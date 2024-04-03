#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

class matchGame {
public:
	void menuStart() {
		string sportsCars[50] = { "BwmM4", "AudiRs7", "Z06", "Hellcat", "Demon", "Redeye", "Supra", "NisanGtr", 
			"Porch911", "Rari812", "AmgGTR", "AudiR8", "Roma", "Trkhawk", "CmaroZL1", "AudiR8", "AstonV12", "Bentley", 
			"BmwM5", "BmwM8", "Chiron", "Bugatti", "CtsV", "ZR1", "Viper", "AcuraNSX", "Ferrari", "Tributo", "Spider", 
			"488Pista","FrdGT500","InfinG35","FType","Gemera","Jesko","DiabloVT","Mrcelago","Huracan","VntdrSVJ","Cntnario",
			"DrngoSRT","Urus","LexusRC","FTaycan","918Spydr","Laren600","720Mlren","Pagani","Huayra" };
		
			
		//string capture[50][50] = { "," } , { "," };

		srand(time(nullptr));
		int grid; // capture grid size
		int speed; // 
		int answer;
		cout << " Choose an option 1: 4x4 2: 6x6 3: 8x8" << endl;
		cin >> grid;
		cout << " Choose speed 1: (2 sec) 2: (4 secs) 3: (6 secs) " << endl;
		cin >> speed;

		if (grid == 1) {
			grid = 4;
		}
		else if (grid == 2) {
			grid = 6;
		}
		else {
			grid = 8;
		}
		
		if (speed == 1) {
			speed = 2000;
		}
		else if (speed == 2) {
			speed = 4000;
		}
		else {
			speed = 6000;
		}
		int x = rand() % 50;
		string theme[64];
		for (int i = 0; i < (grid * grid) / 2; i++) {

			theme[i] = sportsCars[x % 50]; //
			x++;
		}

		string duplicate[64];
		int t = 0;

		for (int a = 0; a < grid * grid; a += 2) {

			duplicate[a] = theme[t];
			duplicate[a + 1] = theme[t]; //// creates duplicate of each car
			t++;
		}
		string shuffle;

		for (int r = 0; r < grid * grid; r++) {
			shuffle = duplicate[r];
			int rando = rand() % grid * grid;
			duplicate[r] = duplicate[rando]; ////randomizes duplicate of each car
			duplicate[rando] = shuffle;
			//shuffle = duplicate[rando]
		}
		for (int i = 0; i < (grid * grid); i++) {
		//	cout << setw(10) << duplicate[i];
			if (grid == i % grid + 1) {
				cout << endl;
			}
		}
		cout << endl;
		//cout << "TEST" <<grid<< endl;
		cout << endl;

		gameStart(duplicate, grid, speed);
	}
	
	void gameStart(string duplicate[], int grid , int speed) { //begin playing game
		string match[2][64];
	
		 for (int i = 0; i < 2; i++) {
			for (int g = 0; g < grid * grid; g++) {
				if (i == 0) {
					match[i][g] = duplicate[g];
				}
				if (i == 1) {
					match[1][g] = "sportsCars";
					//cout << match[1][g] ;
					//	cout <<setw(6)<< "SportCars ";
				}
			}
		}
		bool won = true;
		int row = 0;
		int colum=0;
		int row2 = 0;
		int colum2 = 0;
		int ans1=0;
		int ans2 = 0;
		int x = 0;

		cout << setw(8) << "1" << setw(10) << "2" << setw(12) << "3" << setw(11) << "4";
		if (grid >= 6) {
			cout << setw(11) << "5" << setw(13) << "6";
		}
		if (grid >= 8) {
			cout << setw(11) << "7" << setw(11) << "8";
		}
		cout << endl;


	for (int i = 0; i < grid; i++) {
		cout << i + 1 << " ";
		for (int i = 0; i <grid; i++) {
			cout << setw(11) << match[1][i];
			if (grid == i % grid + 1) {
				cout << endl;
			}
		}
			}

	string array[64] = { "Holder"};
	
		while (won == true) {
			bool check = true;
			while (check == true) {
				check = false;
				cout << "Enter a row for your first choice" << endl;
				cin >> row;
				cout << "Enter a column for your first choice" << endl;
				cin >> colum;
				ans1 = colum - 1 + (row - 1) * grid;
				cout << "Enter a row for your second choice" << endl;
				cin >> row2;
				cout << "Enter a column for your second choice" << endl;
				cin >> colum2;
				ans2 = colum2 - 1 + (row2 - 1) * grid;
				if ("Error" == array[ans1] || "Error" == array[ans2]) {
					check = true;
					cout << "CANNOT ENTER SAME NUMBERS" << endl;
				}
			}
			if (match[0][ans1] == match[0][ans2]) {
				cout << "Match!" << endl;
				match[1][ans1] = match[0][ans1];
				match[1][ans2] = match[0][ans2];
				x++;
				
				array[ans1] = "Error";
				array[ans2] = "Error";

			}
		else {
			int L = 0;
			cout << "No match!" << endl;
			for (int r = 0; r < grid; r++)
			{
				cout << r + 1 << " ";
				for (int c = 0; c < grid; c++)
				{
					if ((ans1!=L) &&(ans2!=L))
					{
					cout << setw(11) << match[1][L];
					}			
					if (ans1 == L) {
						cout << setw(11)<< match[0][ans1];
					}
					if(ans2==L){
						cout << setw(11) << match[0][ans2];
					}
				L++;
				}
				cout << endl;
			}
		}

		Sleep(speed);
		for (int i = 0; i < 1000; i++) {
			cout << endl;
		}
		if (x == (grid * grid) / 2) {
			cout << "You've won!" << endl;
			cout << "  You've won!" << endl;
			cout << "    You've won!" << endl;
			cout << "      You've won!" << endl;
			cout << "        You've won!" << endl;

			won = false;
		}

			for (int i = 0; i < (grid * grid); i++) {

				//	cout << setw(10) << duplicate[i]; 
				if (grid == i % grid + 1) {
					cout << endl;
				}
			}
			cout << setw(11) << "1" << setw(11) << "2" << setw(12) << "3" << setw(11) << "4";
			if (grid >= 6) {
				cout << setw(11) << "5" << setw(11) << "6";
			}
			if (grid >= 8) {
			cout << setw(11) << "7" << setw(11) << "8";
		}
		cout << endl;
		int b = 0;
		for (int r = 0; r < grid; r++)
		{
			cout << r + 1 << " ";
			for (int c = 0; c < grid; c++)
		{
				cout <<setw(11)<< match[1][b];
			b++;
			}
			cout << endl;
			}
		}	
	}
};
int main() {
	cout << "Osbaldo Ramirez 05/17/2021" << endl;
	matchGame game;
	game.menuStart();
	
	return 0;
}

