#include<iostream>
#include<string>
#include<cctype>
#include<math.h>
#include <windows.h>
using namespace std;
struct node
{
	char data;
	int colNum;
	node* next;
};
class stack
{
private:
	int** Array;
	int rows, coloumns;
	node* top;
	string strpostfix;
public:
	stack() //default constructor
	{
		top = NULL;
	}
	stack(int numofalpha, int numofop, string exp, string temp) //parameterized constructor
	{

		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] != '\0')
				cout << temp[i] << "	";
		}
		cout << exp << endl;
		for (int i = 0; i < temp.length(); i++)
			cout << "----------";
		cout << endl;
		rows = pow(2, numofalpha);
		coloumns = numofalpha + numofop;
		top = NULL;
		//dynamically allocating memory to form a 2D Array
		Array = new int* [rows];
		for (int i = 0; i < rows; i++)
			Array[i] = new int[coloumns];

		//filling the initial columns
		int fact = 2;
		bool bol = true;
		for (int j = 0; j < numofalpha; j++)
		{
			for (int i = 0; i < rows;)
			{
				int colfill = rows / fact;

				for (int n = 0; n < colfill; n++, i++)
				{
					if (bol == true)
					{
						Array[i][j] = 0;
						if (n == colfill - 1)
							bol = false;
					}
					else if (bol == false)
					{
						Array[i][j] = 1;
						if (n == colfill - 1)
							bol = true;
					}
				}
			}
			fact = fact * 2;  //fact is multiply to fill the next coloumn 
		}
	}
	~stack() //deleting all the nodes created
	{
		while (top && top->next != NULL)
		{
			node* temp = top;
			top = top->next;
			delete temp;
			temp = NULL;
		}
	}

	//converts the string to postfix string
	void conversiontopostfix(string str, string temp)
	{
		//this will read the string till the end.
		for (int i = 0; i < str.length(); i++)
		{
			//this will check that the character in thes string is operator or not.
			//if the character in the string is an operator then that operator will push on stack.
			if (ifcharoperator(str[i]))
			{
				//if the top of stack is NULL then it will push on the stack
				if (topcharacter() == NULL)
					push(str[i], 0);

				else if (topcharacter() != NULL)
				{
					//if the string contain this '(' character then  as it has the highest precedence so it will be push in stack whenever it is found.
					if (str[i] == '(')
						push(str[i], 0);

					//as it is postfix conversion so when this char ')' is found then all the operators will be popped from the stack unti '(' is encountered. 
					else if (str[i] == ')')
					{
						while (topcharacter() != '(')
						{
							strpostfix = strpostfix + topcharacter();
							pop();
						}
						//now that '(' is found, so we will discard it from stack
						pop();
					}
					//other than this '(' or ')' character then we will compare the precedence of the operator which is on the top of the stack.
					else
					{
						while (!isEmpty() && precedence(str[i]) <= precedence(topcharacter()))
						{
							strpostfix += topcharacter();
							pop();
						}
						push(str[i], 0);
					}
				}
			}
			//if the char is not an operator then it is stored in the postfix string
			else
			{
				strpostfix = strpostfix + str[i];


			}
		}
		while (!isEmpty())
		{
			strpostfix = strpostfix + topcharacter();
			pop();
		}
		//cout << endl << "Postfix string: " << postfix << endl;
	}

	// function to obtain the truth table
	void evafortruthtable(string str, string temp, int numOfVar, int& finalCol)
	{
		conversiontopostfix(str, temp); //converting the string to postfix
		//scanning postfix 

		//for filling the null spaces in the string as we had previously deleted duplicates from the string (in scan function)
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '\0')
			{
				for (int j = i; j < temp.length(); j++)
				{
					if (temp[j] != '\0')
					{
						temp[i] = temp[j];
						break;
					}
				}
			}
		}

		//evaluation for the postfix string
		//this will read the string till the end.
		for (int i = 0; i < strpostfix.length(); i++)
		{
			int c = 0;

			//if character is an alphabet, then it is pushed on the stack
			//isalpha is predefined function
			if (isalpha(strpostfix[i]))
			{
				for (int k = 0; k < temp.length(); k++)
				{
					if (temp[k] == strpostfix[i])
					{

						c = k;
						break;
					}
				}

				push(strpostfix[i], c);
			}

			//if character is an operator, then that operand will pops from the stack
			//operation will be performed on it and the final result of that operation will pe push on the stack.
			if (ifcharoperator(strpostfix[i]))
			{
				int j;
				//for finding an empty column for storing the result
				for (j = 0; j < coloumns; j++)
				{
					if (Array[0][j] != 0 && Array[0][j] != 1)
						break;
				}
				//function for And operator
				if (strpostfix[i] == '&')
				{

					int x = intTop();
					pop();
					int y = intTop();
					pop();
					andFunc(i, j, x, y);
					push(' ', j);
				}
				//Function for Or operator
				if (strpostfix[i] == '|')
				{
					int x = intTop();
					pop();
					int y = intTop();
					pop();
					orFunc(i, j, x, y);
					push(' ', j);
				}
				//Function For Negation operator
				if (strpostfix[i] == '~')
				{
					int x = intTop();
					pop();
					notFunc(i, j, x);
					push(' ', j);
				}
				//Function for Xor operator
				if (strpostfix[i] == '+')
				{
					int x = intTop();
					pop();
					int y = intTop();
					pop();
					xorFunc(i, j, x, y);
					push(' ', j);
				}
				//Function for implies operator
				if (strpostfix[i] == '-')
				{
					int x = intTop();
					pop();
					int y = intTop();
					pop();
					impliesFunc(i, j, x, y);
					push(' ', j);
				}
				else if (strpostfix[i] == '<')
				{
					int x = intTop();
					pop();
					int y = intTop();
					pop();
					biImplication(i, j, x, y);
					push(' ', j);
				}
			}
			finalCol = intTop(); //this points to the column containing the final answer
		}
	}
	void impliesFunc(int i, int j, int x, int y)
	{
		for (int i = 0; i < rows; i++)
		{
			if (Array[i][y] == 1 && Array[i][x] == 0)
			{
				Array[i][j] = 0;
			}
			else
			{
				Array[i][j] = 1;
			}
		}
	}
	void xorFunc(int i, int j, int x, int y)
	{
		for (int i = 0; i < rows; i++)
		{
			if (Array[i][y] != Array[i][x])
			{
				Array[i][j] = 1;
			}
			else
			{
				Array[i][j] = 0;
			}
		}
	}
	//logical AND operation
	void andFunc(int i, int j, int x, int y)
	{
		for (int i = 0; i < rows; i++)
			Array[i][j] = (Array[i][y]) && (Array[i][x]);
	}

	//logical OR operation
	void orFunc(int i, int j, int x, int y)
	{
		for (int i = 0; i < rows; i++)
			Array[i][j] = (Array[i][y]) || (Array[i][x]);
	}

	//logical NOT operation
	void notFunc(int i, int j, int x)
	{
		for (int i = 0; i < rows; i++)
			Array[i][j] = !(Array[i][x]);
	}

	//bi implication
	void biImplication(int i, int j, int x, int y)
	{
		for (int i = 0; i < rows; i++)
		{
			if (Array[i][y] == Array[i][x])
			{
				Array[i][j] = 1;
			}
			else
			{
				Array[i][j] = 0;
			}
		}
	}

	//checks if the encountered character in the string is a character or not
	bool ifcharoperator(char a)
	{
		if (a == '&' || a == '~' || a == '|' || a == '(' || a == ')' || a == '+' || a == '-' || a == '<')
			return true;
		return false;
	}

	//returns the precedence of the enocountered operator in the string (used while converting string -> postfix)

	int precedence(char operator1)
	{
		if (operator1 == '<') // bi-implication
			return 0;
		if (operator1 == '|')
			return 1;
		if (operator1 == '+')
			return 2;
		if (operator1 == '&')
			return 3;
		if (operator1 == '~')
			return 4;
		if (operator1 == ')')
			return 5;
		else
			return -1;
	}



	void push(char x, int y)
	{
		node* newnode = new node();
		newnode->data = x;
		newnode->colNum = y;
		newnode->next = top;
		top = newnode;
	}


	void pop()
	{
		if (isEmpty())
			return;
		node* temp = top;
		if (top->next == NULL)
			top = NULL;
		else
			top = top->next;
		delete temp;
		temp = NULL;
	}

	//returns the integer (column number) which is on top of the stack
	int intTop()
	{
		if (top == NULL)
			return NULL;
		return (top->colNum);
	}

	//returns the char which is on top of the stack
	char topcharacter()
	{
		if (top == NULL)
			return NULL;
		return (top->data);
	}

	//checks if the stack is empty or not
	bool isEmpty()
	{
		if (topcharacter() == NULL)
			return true;
		return false;
	}

	//for printing the truth table
	void printTable(int finalCol, int numOfVar)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < numOfVar; j++)
			{
				if (Array[i][j] == 0 || Array[i][j] == 1)
					cout << Array[i][j] << "	";
				if (j == numOfVar - 1)
					cout << Array[i][finalCol] << "  ";
			}
			cout << endl;
		}
	}
};
//used for obatining the number of different variables and total number of operators
void tocountalpaandop(string express, int& numOfVar, int& numOfOp, string& temp)
{
	//for finding total number of variables & total number of operators
	temp = "";
	for (int i = 0; i < express.length(); i++)
	{
		if ((express[i] >= 65 && express[i] <= 90) || (express[i] >= 97 && express[i] <= 122))
		{
			//ll the alphabet will store in temp.
			temp = temp + express[i];
		}
		else
			numOfOp++;
	}

	//it is used to delete the repeating alphabets in the string.
	for (int i = 0; i < temp.length(); i++)
	{
		for (int j = 1; j < temp.length(); j++)
		{
			if (i != j)
			{
				if (temp[i] == temp[j])
					temp[j] = '\0';
			}
		}
	}

	//this for loop is used to find the total number of varaiables/alphabets from the string.
	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] != '\0')
		{
			if ((temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122))
				numOfVar++;
		}
	}
}
// Function to set text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
int main()
{
	setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	string expression1, expression2, temp, temp1;
	cout << "\t\t                   ------------------------------" << endl;
	cout << "\t\t                  | WELCOME TO OUR CODE PALACE   |" << endl;
	cout << "\t\t                   ------------------------------" << endl;
	cout << endl;
    
    cout << "\t\t         ----------------------------------------" << endl;
	cout << "\t\t        | OUR CODE WILL DISPLAY THE Truth Table. |" << endl;
	cout << "\t\t         ----------------------------------------" << endl;
	cout << endl;
	cout << "\t\t         ----------------------------" << endl;
	cout << "\t\t        | Expression Of Truth Table  |" << endl;
	cout << "\t\t         ----------------------------" << endl;
	cout << endl;
	cout << "\t" << "-------------------------------" << endl;
	cout << "\t" << "|  Press ~ For Negation       |" << endl;
	cout << "\t" << "|  Press &  For And           |" << endl;
	cout << "\t" << "|  Press | For  OR            |" << endl;
	cout << "\t" << "|  Press - For Implication    |" << endl;
	cout << "\t" << "|  Press + For XOR            |" << endl;
	cout << "\t" << "|  Press < For BI-IMPLICATION |" << endl;
	cout << "\t" << "-------------------------------" << endl << endl;
    
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "Enter the first expression " << endl;
	getline(cin, expression1);
	cout << "Enter the second expression " << endl;
	getline(cin, expression2);
	int numofalpha1 = 0, numofop = 0;;
	int finalCol1 = 0;
	int numofalpha2 = 0, numofop2 = 0;
	int finalCol2 = 0;

	system("cls");
	cout << "TRUTH TABLE FOR 1ST EXPRESSION : " << endl;
	cout << endl;
	tocountalpaandop(expression1, numofalpha1, numofop, temp);	//find the number of variables and operators in the string
	stack obj(numofalpha1, numofop, expression1, temp); //initializing stack
	obj.evafortruthtable(expression1, temp, numofalpha1, finalCol1);
	obj.printTable(finalCol1, numofalpha1); //the truth table

	cout << endl;
	cout << endl;
	cout << "TRUTH TABLE FOR 2ND EXPRESSION : " << endl;
	cout << endl;
	tocountalpaandop(expression2, numofalpha2, numofop2, temp1);
	stack obj2(numofalpha2, numofop2, expression2, temp1);
	obj2.evafortruthtable(expression2, temp1, numofalpha2, finalCol2);
	obj.printTable(finalCol1, numofalpha1);
	cout << "\n\n";
	cout << endl;
	cout << "CHECKING EQUIVALANCE OF TRUTH TABLES :" << endl;
	cout << endl;
	obj2.printTable(finalCol2, numofalpha2);

	if (finalCol1 == finalCol2)
		cout << "\nExpressions are equivalent.\n";
	else
		cout << "\nExpressions are not equivalent.\n";

	system("pause");

	return 0;
}
