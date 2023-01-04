#pragma once
#include <iostream>

class IntSet{
	
	private:
		int left;
		int right;
		int min;
		int max; 
		int *set;
		int power = right - left;
		
	public:
		IntSet( left, right){}; //конструктор с пустым множеством
		~IntSet;// деструктор
		IntSet (IntSet& s);//конструктор копирования


		void Push (int element); // добавление элемента в множество
		void Pop (int element); // удаление элемента из множества
		bool IsEmpty(); // проверка пустоты множества
		int HowMany(); // количество элементов в множестве
		int Max(); // наахождение максимального элемента в множестве
		int Min(); // нахождение минимального элемента в множестве
		int RightBorder();
	        int LeftBorder(); 	// границы иножества
		IntSet operator* (IntSet b);  // получаем третье множетво, которое равно пересечению первых двух
		IntSet operator*= (IntSet b); // получаем "новое" первое множество, в котором ост-сь перес-е
		bool IsEqual; // равенство двух мнгожеств







}
