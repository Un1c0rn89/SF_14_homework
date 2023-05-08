#pragma once
#include <iostream>

using visitedTimesType = int8_t; // Тип счётчика проходов должен вмещать величину ~("количеcтво слов"/"длина алфавита")~3000 для использованного словаря
constexpr char alphabetStart = 'a';
constexpr char alphabetEnd = 'z';

constexpr char alphabetSize = alphabetEnd - alphabetStart + 1;

class Node
{
public:
	Node();
	~Node();

	void addChild(const unsigned char& index);			
	void deleteChild(const unsigned char& index);		

	bool isEmpty() const;								// Возвращает false, если данный узел имеет хотя бы одного потомка
	bool childExists(const unsigned char& index) const;	// Проверка на существования потомка по коду

	Node* goDeepByIndex(const unsigned char& index);	// Проход вглубь по индексу с увеличением счётчика.
														// Если детей с префиксом нет, создаем новый узел.

	Node* lookDeepByIndex(const unsigned char& index);	// Просмотр вглубь по индексу без увеличения счётчика.

	void setEndOfWord();								// Установка флага _isEndOfWord
	void resetEndOfWord();								// Сброс флага _isEndOfWord
	bool isEndOfWord() const;							// Проверка флага _isEndOfWord

	void increaseVisitsCounter();						// Инкремент _visitedTimes
	void decreaseVisitsCounter();						// Декремент _visitedTimes
	bool isVisitedOnce() const;							// Проверка счетчика _visitedTimes
	
private:
	Node** _children;									
	bool _isEndOfWord;									
	visitedTimesType _visitedTimes;						
};