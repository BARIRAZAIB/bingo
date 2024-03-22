#include<iostream>
#include<iomanip>
#include<ctime>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<fstream>
using namespace std;
void nameOfGame()
{

	cout << endl << endl;
	cout << setw(65) << "| B  I  N  G  O| ";
	cout << endl << endl;
}
void instructionOfgame() //How to Play the Game
{
	cout << endl;
	cout << setw(65) << "Game  Instructions" << endl;
	cout << setw(80) << "_________________________________________" << endl;
	cout << endl;
	cout << setw(85) << "1.Bingo is a fun game which  can played by two players..." << endl;
	cout << setw(92) << "2.This game is played on a board that's made up of 25 squares..." << endl;
	cout << setw(90) << "3.A player wins if they get 5 covered squares in a horizontal," << endl;
	cout << setw(56) << "vertical, or diagonal row..." << endl;
	cout << setw(95) << "4.both players keep choosing new combinations until someone wins..." << endl;
	cout << setw(80) << "________________________________________" << endl;
	cout << endl;

}
void nameOfplayer(string & x, string & y)// Player Names Input
{
	cout << "1st player is : ";
	cin >> x;
	cout << endl;
	cout << "2nd player is : ";
	cin >> y;
	cout << endl;
}
void gameID(int& ID) //Random gameID Genereator
{
	srand(time(0));
	ID = rand();
	cout << "gameID : " << ID << endl;
}
void myArray(int arr[][5]) //populate array
{
	int row = 0, col = 0;
	int rndm, counter = 0;
	bool flag = false;
	while (counter != 25)
	{
		rndm = (rand() % 25) + 1;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[i][j] == rndm)
				{
					flag = true;
				}
			}
		}
		if (flag != true)
		{
			arr[row][col] = rndm;
			counter++;
			col++;
			if (col == 5)
			{
				row++;
				col = 0;
			}
		}
		flag = false;
	}
}
bool goBack()  //TO Run Code Again
{
	char enter;
	bool flag;

	cout << "\nIf you want to go back press any button \nTo exit press 0\n";
	cin >> enter;
	if (enter != '0')
	{
		flag = true;
	}
	else {
		flag = false;
	}
	return flag;
}

bool winningCondition(int arr[][5]) //Winning Condition
{
	bool n = false;
	int count = 0;
	int countForNumOfZero_r_c_d = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i][i] == 0)
		{
			count++;
		}
	}
	if (count == 5)
	{
		countForNumOfZero_r_c_d++;
	}
	else
	{
		count = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[i][j] == 0)
				{
					count++;
				}
			}
			if (count == 5)
			{
				countForNumOfZero_r_c_d++;
			}
			count = 0;
		}
		count = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[j][i] == 0)
				{
					count++;
				}
			}
			if (count == 5)
			{
				countForNumOfZero_r_c_d++;
			}
			count = 0;
		}
		count = 0;
		for (int i = 0; i < 5; i++)
		{
			if (arr[i][4 - i] == 0)
			{
				count++;
			}
		}
		if (count == 5)
		{
			countForNumOfZero_r_c_d++;
		}
		count = 0;
	}
	if (countForNumOfZero_r_c_d >= 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void tableOfPlayer(int arr[][5], string a) //Printing Table
{
	cout << a << "'s turn : " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(10) << "|" << setw(5) << arr[i][j] << "|";
		}
		cout << endl;
	}
}
bool numberOfZero(int arr1[][5], int arr2[][5], int num)
{
	bool checker1 = false;
	bool checker2 = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr1[i][j] == num)
			{
				arr1[i][j] = 0;
				checker2 = true;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr2[i][j] == num)
			{
				arr2[i][j] = 0;
				checker1 = true;
			}
		}
	}
	return checker2;

}
bool exsistanceOfNum(int arr[][5], int num) //Duplication check
{
	bool duplication = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == num)
			{
				duplication = true;
			}
		}
	}
	return duplication;
}
void myFile(int q, string& i) //File handling
{
	ofstream data("history.text", ios::app);
	data << "Name: " << i << endl << "ID: " << q << endl;
	data.close();


}
void readHistory()
{
	ifstream fin;
	fin.open("history.txt");
	if (fin.is_open())
	{
		char x;
		while (!fin.eof())
		{
			fin.get(x);
			cout << x;
		}
	}
}
void mainMenu() //Main Menu
{
	int num;
	bool flag = true;
	system("cls");
	nameOfGame();


	do //Main Menu loop

	{
		cout << "1) Play Game\n2) Game History\n3)How to Play?\n4)Exit\n";
		cin >> num;
		flag = true;
		switch (num)
		{
		case 1: //Game case
		{
			int userInput = 1;
			while (userInput == 1)
			{
				system("cls");
				bool x;
				system("cls");
				string name1, name2;
				int c;
				int turn;
				int array1[5][5], array2[5][5];
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						array1[i][j] = 0;
						array2[i][j] = 0;
					}
				}
				nameOfplayer(name1, name2);
				gameID(c);
				myArray(array1);
				myArray(array2);
				tableOfPlayer(array1, name1);
				tableOfPlayer(array2, name2);
				turn = rand() % 2 + 1;
				bool p = winningCondition(array1);
				bool q = winningCondition(array2);
				int inputNum = 0;
				while (q == false && p == false && inputNum != -1)
				{
					if (turn == 1)
					{
						turn = 2;
					}
					else
					{
						turn = 1;
					}
					if (turn == 1)
					{
						system("cls");
						tableOfPlayer(array1, name1);
						cout << " Enter  number : " << endl;
						cin >> inputNum;
						if (inputNum != -1)
						{
							bool first = exsistanceOfNum(array1, inputNum);
							if (first == true)
							{
								bool second = exsistanceOfNum(array2, inputNum);
								if (second == true)
								{
									x = numberOfZero(array1, array2, inputNum);
								}
								else
								{
									cout << "Invalid Input " << endl;
									Sleep(3000);
								}
							}
							else
							{

								cout << "Invalid Input " << endl;
								Sleep(3000);
							}
						}
					}
					else if (turn == 2)
					{
						system("cls");
						tableOfPlayer(array2, name2);
						cout << "Player 2 Enter a number : " << endl;
						int number;
						cin >> number;
						bool first = exsistanceOfNum(array1, number);
						if (first == true)
						{
							bool second = exsistanceOfNum(array2, number);
							if (second == true)
							{
								x = numberOfZero(array1, array2, number);
							}
							else
							{
								cout << "Invalid Input " << endl;
								Sleep(3000);
							}
						}
						else
						{
							cout << "Invalid Input " << endl;
							Sleep(3000);
						}
					}
					p = winningCondition(array1);
					q = winningCondition(array2);
				}
				bool winner1 = winningCondition(array1);
				bool winner2 = winningCondition(array2);
				if (winner1 == true)
				{
					myFile(c, name1);
					cout << "winner is : " << name1 << endl;

				}
				else if (winner2 == true)
				{
					myFile(c, name2);
					cout << "winner is :  " << name2 << endl;
				}
				else
				{
					cout << "The game has ended in a DRAW" << endl;
				}

				cout << endl;
				cout << "Enter '1' to play the game ";
				cout << endl;
				cout << "Enter any key to exit  ";
				cin >> userInput;

			}
			flag = goBack();
			break;
		}

		case 2: //History Case
		{
			readHistory();
			flag = goBack();
			break;

		}
		case 3: //How To Play Case
		{
			instructionOfgame();
			flag = goBack();
			break;
		}
		case 4:
		{
			flag = false;
			break;
		}
		default:
		{
			cout << "Invalid Input ";
			flag = true;
			break;
		}
		}
	} while (flag);

}
int main() //Main Function
{
	mainMenu();
	system("pause");
	return 0;
}
