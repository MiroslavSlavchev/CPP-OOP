// OOP_EXAM_PROJECT_2.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
using namespace System;


/*
Да се реализира абстрактен базов клас, представляващ обект от файловата система.
Този обект се характеризира с име. Класът да предоставя метод за определяне на заеманото
от обекта дисково пространство.
- Да се реализира наследник на този клас, представляващ файл.
Файлът трябва да пази информация за размера си.
- Да се реализира наследник на този клас, представляващ директория.
Директорията съхранява масив от обекти от файловата система.
*/

class FileObject
{
private:
	char*name;
public:
	FileObject(char* = "");
	void set_name(char*);

	virtual~FileObject()
	{
		delete[]name;
	}

	virtual double MemoryInSpace() = 0;
};
FileObject::FileObject(char* name)
{
	this->name = name;
}
void FileObject::set_name(char*name)
{
	this->name = name;
}

class File : public FileObject
{
private:
	double size;
public:
	File(double = 0.0);
	double MemoryInSpace();
};
File::File(double size)
{
	if (size >= 0.0)
	{
		this->size = size;
	}
	else
	{
		cout << "SIZE not possible" << endl;
	}
}
double File::MemoryInSpace()
{
	return size;
}

class Directory : public FileObject
{
private:
	FileObject ** fileobjects;
	int size;
public:
	Directory(FileObject** = NULL, int i = 0);
	double MemoryInSpace();
};

Directory::Directory(FileObject** fileobjects, int size)
{
	if (size > 0){
		this->size = size;
	}
	this->fileobjects = new FileObject*[size];
	for (int i = 0; i < size; i++)
	{
		this->fileobjects[i] = fileobjects[i];
	}
}
double Directory::MemoryInSpace()
{
	double getSIZE = 0.0;
	for (int i = 0; i < size; i++)
	{
		getSIZE += fileobjects[i]->MemoryInSpace();
	}
	return getSIZE;
}

/*Напишете програма, която да създаде директория, съдържаща поне една поддиректория и поне
един файл, и след това да изведе на екрана размера на тази директория*/

int main()
{
	FileObject* f;
	File f1(10);
	f = &f1;
	f->set_name("name");
	cout<<"FileObject f = &f1 :"<< f->MemoryInSpace() << endl;

	FileObject* f2[2];
	f2[0] = f;
	Directory d(f2,1);
	cout<<"Directory d(f,1):"<< d.MemoryInSpace() << endl;

	f = &d;
	f->MemoryInSpace();
	cout << "Directory f = &d:" << f->MemoryInSpace() << endl;
	
	
}