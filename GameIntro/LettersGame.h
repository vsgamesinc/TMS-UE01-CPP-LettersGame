#pragma once

#include <string>

using int32 = int;
using FText = std::string;
using FString = std::string;

/*
LettersGame класс
===ПРАВИЛА ИГРЫ===
* Есть загаданное слово (6 букв) (!!!)
* Есть количество попыток на угадывание слова +++++++++++++++++++++++++++++++++++++++++++++++++++++
*** Пока у игрока есть доступные попытки (++), игрок вводит слово (!!!!) ++++++++++++++++++++++++++++++++++++++
*** Слово сравнивается с исходным (загаданным) !!!!!!!
* Повторяем до тех пор пока не угадаем слово (выигрыш) или не закончатся попытки (проигрыш) +++++
*/


/* 
1. Сделать strongly typed enum для статусов ошибок валидации строки, которую ввел игрок
1.5. Придумать коды ошибок, которые будут обрабатываться (не забываем про то, что ошибок может не быть)
2. Переделать функцию валидации так, чтобы она возрващала коды ошибок
3. Проверить, что всё компилируется/работает.
*/
enum class EWordStatus
{
	None,			// Initial state
	OK,				// Everithing is OK
	Wrong_Length,	// Answer words length is incorrect
	Not_Lowercase	// We need word in lowercase to type in
};

class FLettersGame
{
	
public:
	FLettersGame();
	
	void Reset();										// перезапуск игры
	EWordStatus ValidateAnswer(FString Answer) const;	// проверка вводимых игроком данных
	bool AreYouWinningSon();							// проверка, на выигрыш в рамках текущей сессии

	int32 GetMaxTries() const;		// получить количество попыток на игровую сессию
	int32 GetCurrentTry() const;	// получить номер текущей попытки

	// GameIteration
	int32 CommitAnswer(FString);							// функция, которая проверяет ввод игрока на выигрыш...


/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
private:
	int32 MaxTries = 6;			// maximum game loop iterations
	int32 CurrentTry = 1;		// current game loop iteration

	// Word to Find
	FString HiddenWord = "unreal";

	// Utilities
	bool IsLowercase(FString) const;

};