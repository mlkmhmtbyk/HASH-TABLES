// deneme.cpp : Defines the entry point for the console application.
//Library definitions 
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


typedef struct veri {								//created a struct named veri
	int k;											//it contains int k and string v
	std::string v;
}v;

int i;												//definitopn of number of collisions

// Function Definitions
//Hash functions(different functions for each m values)
int hLinearm1(v data);								
int hLinearm2(v data);								
int hDoublem1(v data,int i);						
int h1m1(int k);									
int h1m2(int k);									
int hDoublem2(v data,int i);						
int h2m1(int k);									
int h2m2(int k);									
int hUniversalm1(int key);							
int hUniversalm2(int key);
//Insert Functions
void insertLinearm1(v data);						
void insertLinearm2(v data);						
void insertDoublem1(v data);						
void insertDoublem2(v data);						
void insertUniversalm1(v data);						
void insertUniversalm2(v data);	
//Search functions
std::string searchLinearm1(v data);					
std::string searchLinearm2(v data);
std::string searchDoublem1(v data);
std::string searchDoublem2(v data);
//Print functions
void printm1();										
void printm2();
//created tables type of v(int and string) for m1 and m2
v table1[17863];
v table2[21929];									

int hLinearm1(v data) {								
	int hashed;														
	hashed = (data.k +i) % 17863;					//hashes according to pdf
	return hashed;									
}
int hLinearm2(v data) {
	int hashed;
	hashed = (data.k + i) % 21929;					//hashes according to pdf
	return hashed;
}

int hDoublem1(v data, int i) {
	int key = data.k;
	return (h1m1(key) + i * h2m1(key)) % 17863;		//hashes according to pdf
}
int h1m1(int k) {
	return k % 17863;								//hashes according to pdf
}
int h2m1(int k) {
	return 23 - (23 % 17863);						//hashes according to pdf
}

int hDoublem2(v data, int i) {
	int key = data.k;
	return (h1m2(key) + i * h2m2(key)) % 21929;		//hashes according to pdf
}
int h1m2(int k) {
	return k % 21929;								//hashes according to pdf
}
int h2m2(int k) {
	return 23 - (23 % 21929);						//hashes according to pdf
}

int hUniversalm1(int key) {
	int k0, k1, k2;									//creating 3 int values and calc mod and 
	k2 = key % 100;									//divide it to the 100 and 10000 for finding 
	k1 = ((key % 10000) - k2)/100;					//the digit pairs
	k0 = ((key % 1000000) - k2 - k1)/10000;

	int add = k0 + k1 + k2;							//adding the digit pairs
	return add % 17865;								//calc mod of addition to m1
}

int hUniversalm2(int key) {
	int k0, k1, k2;									//creating 3 int values and calc mod and 
	k2 = key % 100;									//divide it to the 100 and 10000 for finding 
	k1 = ((key % 10000) - k2)/100;					//the digit pairs
	k0 = ((key % 1000000) - k2 - k1)/10000;

	int add = k0 + k1 + k2;							//adding the digit pairs
	return add % 21929;								//calc mod of addition to m1
}

void insertLinearm1(v data) {					//Insert Function of Linear Probing for m1
	if (table1[hLinearm1(data)].k == -1) {		//Empty slot case
	table1[hLinearm1(data)] = data;
	}
	else {										//full slot case
		int indis = hLinearm1(data);
		while (table1[indis].k != -1) {			//move next index untill it is empty
			indis++;							
			i++;								//increment the collision count
			if (indis > 17863) {
			indis = 0;
			}
		}
	table1[indis]= data;						//when it is empty write the data to slot
	}
}

void insertLinearm2(v data) {					//Insert Function of Linear Probing Hash for m2
	if (table2[hLinearm2(data)].k == -1) {		//Empty slot case
		table2[hLinearm2(data)] = data;
	}
	else {										//full slot case
		int indis = hLinearm2(data);
		while (table2[indis].k != -1) {			//move next index untill it is empty
			indis++;
			i++;								//increment the collision count
			if (indis > 21929) {
				indis = 0;
			}
		}
		table2[indis] = data;					//when it is empty write the data to slot
	}
}

void insertDoublem1(v data) {					//Insert Function of Double Hashing for m1
	if (table1[hDoublem1(data,i)].k == -1) {	//Empty slot case
		table1[hDoublem1(data,i)] = data;
	}
	else {										//full slot case
		int indis = hDoublem1(data,i);
		while (table1[indis].k != -1) {			//move next index and calc hash again untill it is empty
			indis++;
			i++;								//increment the collision count
			if (indis > 17863) {
				indis = 0;
			}
		}
		table1[indis] = data;					//when it is empty write the data to slot
	}
}

void insertDoublem2(v data) {					//Insert Function of Double Hashing for m2		
	if (table2[hDoublem2(data,i)].k == -1) {	//Empty slot case
		table2[hDoublem2(data,i)] = data;
	}
	else {										//full slot case
		int indis = hDoublem2(data,i);
		while (table2[indis].k != -1) {			//move next index and calc hash again untill it is empty
			indis++;
			i++;								//increment the collision count
			if (indis > 21929) {
				indis = 0;
			}
		}
		table2[indis] = data;					//when it is empty write the data to slot
	}
}
	
void insertUniversalm1(v data) {				//Insert Function of Double Hashing for m1
	if (table1[hUniversalm1(data.k)].k == -1) {	//Empty slot case
		table1[hUniversalm1(data.k)] = data;
	}
	else {										//full slot case
		int indis = hUniversalm1(data.k);
		while (table1[indis].k != -1) {			//move next index and calc hash again untill it is empty
			indis++;
			i++;								//increment the collision count
			if (indis > 17863) {
				indis = 0;
			}
		}
		table1[indis] = data;					//when it is empty write the data to slot
	}
}

void insertUniversalm2(v data) {				//Insert Function of Double Hashing for m2
	if (table2[hUniversalm2(data.k)].k == -1) {	//Empty slot case
		table2[hUniversalm2(data.k)] = data;
	}
	else {										//full slot case
		int indis = hUniversalm2(data.k);
		while (table2[indis].k != -1) {			//move next index and calc hash again untill it is empty
			indis++;
			i++;								//increment the collision count
			if (indis > 21929) {
				indis = 0;
			}
		}
		table2[indis] = data;					//when it is empty write the data to slot
	}
}

std::string searchLinearm1(v data) {				//Search Function of Linear Probing for m1
	if (table1[hLinearm1(data)].k == -1){
		insertLinearm1(data);						//if non existing token search insert it to table
		return table1[hLinearm1(data)].v;
	}

	else if (table1[hLinearm1(data)].k == data.k && table1[hLinearm1(data)].v == data.v) {
		return table1[hLinearm1(data)].v;			//not collision case
	}
	//collision case
	else if (table1[hLinearm1(data)].k == data.k && table1[hLinearm1(data)].v != data.v) {
		int x = hLinearm1(data);					//collision case
		while (table1[x].v != data.v) {				//Goes next slot until the value matches
			x = x++;
		}
		return table1[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
	}
	return "-1";
}

std::string searchLinearm2(v data) {				//Search Function of Linear Probing Hash
	if (table2[hLinearm2(data)].k == -1) {					
		insertLinearm2(data);						//if non existing token search insert it to table
		return table2[hLinearm2(data)].v;
	}

	else if (table2[hLinearm2(data)].k == data.k && table2[hLinearm2(data)].v == data.v) {
		return table1[hLinearm2(data)].v;			//not collision case
	}
	//collision case
	else if (table1[hLinearm2(data)].k == data.k && table2[hLinearm2(data)].v != data.v) {
		int x = hLinearm2(data);					//collision case
		while (table2[x].v != data.v) {				//Goes next slot until the value matches
			x = x++;
		}
		return table2[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
	}
	return "-1";
}

std::string searchDoublem1(v data) {				//Search function of Double Hash for m1
	if (table1[hLinearm1(data)].k == -1) {
		insertDoublem1(data);						//if non existing token search insert it to table
		return table1[hDoublem1(data, i)].v;
	}
	//Not Collision and existing data
	else if (table1[hDoublem1(data, i)].k == data.k && table1[hDoublem1(data, i)].v == data.v) {
		return table1[hDoublem1(data, i)].v;		//not collision case
	}
	//Collision case
	else if (table1[hDoublem1(data, i)].k == data.k && table1[hDoublem1(data, i)].v != data.v) {
		int x = hDoublem1(data, i);					
		while (table1[x].v != data.v) {				//Goes next slot until the value matches
			x = x++;
		}
		return table1[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
		return "-1";
	}

}

std::string searchDoublem2(v data) {				//Search Function of Linear Probing Hash
	if (table2[hLinearm2(data)].k == -1 ) {
		insertDoublem2(data);						//if non existing token search insert it to table
		return table2[hDoublem2(data,i)].v;
	}
	//Not Collision and existing data
	else if (table2[hDoublem2(data,i)].k == data.k && table2[hDoublem2(data,i)].v == data.v) {
		return table2[hDoublem2(data,i)].v;			//not collision case
	}
	//Collision case
	else if (table2[hDoublem2(data,i)].k == data.k && table2[hDoublem2(data,i)].v != data.v) {
		int x = hDoublem2(data,i);			
		while (table2[x].v != data.v) {				//Goes next slot until the value matches
			x = x++;
		}
		return table2[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
		return "-1";
	}
	
}

std::string searchUniversalm1(v data) {						//Search Function of Linear Probing Hash
	if (table1[hUniversalm1(data.k)].k == -1) {				
		insertUniversalm1(data);							//if non existing token search insert it to table
		return table1[hUniversalm1(data.k)].v;	
	}

	else if (table1[hUniversalm1(data.k)].k == data.k && table1[hUniversalm1(data.k)].v == data.v) {
		return table1[hUniversalm1(data.k)].v;				//not collision case
	}
	//collision case
	else if (table1[hUniversalm1(data.k)].k == data.k && table1[hUniversalm1(data.k)].v != data.v) {
		int x = hUniversalm1(data.k);
		while (table1[x].v != data.v) {					//Goes next slot until the value matches
			x = x++;
		}
		return table1[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
	}
	return "-1";
}
 
std::string searchUniversalm2(v data) {					//Search Function of Linear Probing Hash
	if (table2[hUniversalm2(data.k)].k == -1) {					
		insertUniversalm1(data);						//if non existing token search insert it to table
		return table2[hUniversalm2(data.k)].v;
	}

	else if (table2[hUniversalm2(data.k)].k == data.k && table2[hUniversalm2(data.k)].v == data.v) {
		return table2[hUniversalm2(data.k)].v;			//not collision case
	}
	//collision case
	else if (table2[hUniversalm2(data.k)].k == data.k && table2[hUniversalm2(data.k)].v != data.v) {
		int x = hUniversalm2(data.k);
		while (table2[x].v != data.v) {					//Goes next slot until the value matches
			x = x++;
		}
		return table2[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
	}
	return "-1";
}


void printm1() {									//Print the table function for m1
	for (int i = 0; i < 17865; i++) {
		std::cout << table2[i].k << " " << table2[i].v << std::endl;
	}
	std::cout << "collision count " << i << std::endl;
}

void printm2() {									//Print the table function for m2
	for (int i = 0; i < 22000; i++) {
		std::cout << table2[i].k << " " << table2[i].v << std::endl;
	}
	std::cout << "collision count " << i << std::endl;
}

int main()
{
	v data;
	for (int i = 0; i < 22000; i++) {				//default -1 added to every slot in table
		table2[i].k = -1;
	}
	std::ifstream myfile;
	myfile.open("vocab.txt");						//open vocab.txt
	if (!myfile.is_open()) {
		std::cout << "Error cannot read from the file";
	}
	std::string vocab;
	int line = 0;

	while (!myfile.eof()) {							//insert the vocab to Hash Table
		getline(myfile, vocab);
		data.v = vocab;
		data.k = line;
		insertUniversalm2(data);					//Change insert function for changing m and hash type
		line++;
	}
	myfile.close();
	//printm1();									//print the table for selected m
	printm2();	


	std::ifstream myfile2;
	myfile2.open("search.txt");						//open search.txt
	if (!myfile2.is_open()) {
		std::cout << "Error cannot read from the file";
	}
	std::string search;
	int lineInSearch = 0;
	while (!myfile2.eof()) {						//Search every token in search.txt
		getline(myfile2, search);
		data.v = search;
		data.k = lineInSearch;
		searchUniversalm2(data);					//Change search function for changing m and hash type
		line++;
	}
	

	system("pause");
	return 0;
}

