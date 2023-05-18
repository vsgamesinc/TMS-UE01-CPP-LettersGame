// Test Game program 

#include <iostream>
#include "LettersGame.h"


FLettersGame TheGame;	// instantiate new LettersGame


void BeginPlay();
FString GetAnswer();

int main() 
{
	BeginPlay();
}


void BeginPlay()
{

	for (int i = 0; i < TheGame.GetMaxTries(); i++)
	{
		FString Answer = GetAnswer();

		if (TheGame.CommitAnswer(Answer) > 0)
			std::cout << "\n\nOK\n\n";
		else
			std::cout << "\n\nNot OK\n\n";

	}
}


FString GetAnswer()
{
	FString Response = "";
	EWordStatus Status = EWordStatus::None;

	do
	{
		//...
		std::cout << TheGame.GetCurrentTry() << ") Enter the Word: ";
		getline(std::cin, Response);

		Status = TheGame.ValidateAnswer(Response);

		// TODO response (ответ на пользовательский ввод)
		if (Status == EWordStatus::Wrong_Length)
		{
			std::cout << "U typed: " << Response << " (wrong length)\n";
		}
		else if (Status == EWordStatus::Not_Lowercase)
		{
			std::cout << "U typed: " << Response << " (wrong capitalization)\n";
		}
		else
		{
			std::cout << "U typed: " << Response << " (correct)\n";

		}

	} while (Status != EWordStatus::OK);	// keep tryin until success

	return Response;
}




/*
	int a = 1;
	int b = 2;
	int c = 0;
	bool d = true;
	bool e = false;
	bool t;

	c = a + b;	// 3
	c = a - b;	// -1
	c = a * b;	// 2
	c = a / b;	// 0

	c = c + a;
	c += a;
	c -= a;		// c = c - a;
	c *= a;		// c = c * a;
	c /= a;		// c = c / a;

	c++;		// c = c + 1; // c += 1;
	c--;		// c = c - 1; // c -= 1;

	d = a > b;	// false
	d = a < b;	// true
	d = a >= b;	// false
	d = a <= b;	// true

	d = a == b;	// false
	d = a != b;	// true (1 != 2 )

	t = d && e;	// AND
	t = d || e; // OR
	t = !d;		// NOT
*/