// deneme.cpp : Defines the entry point for the console application.
//Library definitions 
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// function definitions


typedef struct veri {								//created a struct named veri
	int k;											//it contains int k and string v
	std::string v;
}v;

int hLinear(v data);								//Linear Probing Hash funciton		
void insertLinear(v data);							//Insert Function of Linear Probing Hash
std::string searchLinear(v data);					//Search Function of Linear Probing
void print();										//Print the Hash table function

v a[150];											//created a variable named a type veri

int hLinear(v data) {								//hash function
	int iv = 0;										//int value definiton
	int hashed;										//output of hash function
	int converted;									//string to int converted
	for (int i = 0; i < data.v.length(); i++) {
		converted = data.v[i];
		iv = iv + converted;						//int value of string
	}

	hashed = (data.k + iv) % 150;
	return hashed;									// hashed string and key pairs
}

void insertLinear(v data) {							//Insert Function of Linear Probing Hash
	if (a[hLinear(data)].k == -1) {					//Empty slot case
		a[hLinear(data)] = data;
	}
	else {											//full slot case
		int indis = hLinear(data);
		while (a[indis].k != -1) {
			indis++;
			if (indis > 149) {
				indis = 0;
			}
		}
		a[indis].k = data.k;
	}

}

//olmayan data
//doðru yerdeki data
//collision olmuþ data

std::string searchLinear(v data) {					//Search Function of Linear Probing Hash
	if (a[hLinear(data)].k == -1) {					//non existing data
		printf("olmayan deger araniyor");
		return "-1";
	}
	//Not Collision and existing data
	else if (a[hLinear(data)].k == data.k && a[hLinear(data)].v == data.v) {
		return a[hLinear(data)].v;
	}
	//Collision case
	else if (a[hLinear(data)].k == data.k && a[hLinear(data)].v != data.v) {
		int x = hLinear(data);
		while (a[x].v != data.v) {					//Goes next slot until the value matches
			x = x++;
		}
		return a[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
	}
	return "-1";
}

void print() {										//Print the table function
	for (int i = 0; i < 150; i++) {
		std::cout << a[i].k << " " << a[i].v << std::endl;
	}

}

int main()
{
	v data;
	for (int i = 0; i < 150; i++) {					//default -1 added to every slot in table
		a[i].k = -1;
	}
	std::ifstream myfile;
	myfile.open("vocabdeneme.txt");
	if (!myfile.is_open()) {
		std::cout << "Error cannot read from the file";
	}
	std::string vocab;
	int line = 0;

	while (!myfile.eof()) {
		getline(myfile, vocab);
		data.v = vocab;
		data.k = line;
		insertLinear(data);
		line++;
	}
	data.k = 7; data.v = "\"Book";
	searchLinear(data);
	data.k = 1; data.v = "melik";
	insertLinear(data);
	data.k = 2; data.v = "melil";
	insertLinear(data);
	data.k = 2; data.v = "melik";
	insertLinear(data);
	data.k = 2; data.v = "mehmet";
	insertLinear(data);
	data.k = 2; data.v = "biyik";
	insertLinear(data);
	data.k = 3; data.v = "biyik2";
	insertLinear(data);




	print();


	system("pause");
	return 0;
}

