#include <iostream>
#include <string>
#include "Trie.h"

int main()
{
	setlocale(LC_ALL, "");

	Trie* trie = new Trie();							
	
	std::string vocabularyFileName = "words.txt";

	trie->loadVocabulary(vocabularyFileName);			// Загружаем все слова длиной >= 4 букв
	
	//Дополнительный функционал:
	/*
	std::cout << trie->search("errorful") << std::endl;	// Проверка на наличие слова в дереве
	trie->remove("errorful");							// Удаление слова из дерева
	std::cout << trie->search("errorful") << std::endl;	// "0", если слово удалилось
	*/
	//trie->print();										// Вывод полного списка сохранённых слов
	//std::cout << trie->findMinPrefixes();				// Вывод кратчайших уникальных префиксов для каждого слова

	std::cout << std::endl << "Autocompletion: please, input prefix or \'exit\' to stop" << std::endl;
	std::string prefix;
	do
	{
		std::cin >> prefix;
		trie->T9(prefix);								
	} 
	while (prefix.compare("exit") != 0);
	
	delete trie;

	return 0;
}