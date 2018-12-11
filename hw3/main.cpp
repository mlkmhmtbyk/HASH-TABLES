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
		}
		a[indis].k = data.k;
	}

}
std::string searchLinear(v data) {					//Search Function of Linear Probing Hash
	if (a[hLinear(data)].k == -1) {
		printf("olmayan deger araniyor");
		return "-1";
	}
	return a[hLinear(data)].v;						//retuns value of searched data
}

void print() {										//Print the table function
	for (int i = 0; i < 150; i++) {
		std::cout << a[i].k << " " << a[i].v << std::endl;
	}

}




int main()
{
	for (int i = 0; i < 150; i++) {					//default -1 added to every slot in table
		a[i].k = -1;
	}
	v data;
	data.k = 1; data.v = "melik";
	insertLinear(data);
	data.k = 2; data.v = "melik";
	insertLinear(data);
	data.k = 2; data.v = "mehmet";
	insertLinear(data);
	data.k = 2; data.v = "biyik";
	insertLinear(data);
	data.k = 3; data.v = "biyik2";
	insertLinear(data);

	data.k = 2; data.v = "melik";
	std::cout << searchLinear(data) << std::endl;


	print();


	system("pause");
	return 0;
}

