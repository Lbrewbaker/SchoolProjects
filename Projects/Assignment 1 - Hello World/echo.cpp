/**********************************
Author:		 Luke Brewbaker
Program:	 Echo.cpp
date:		 10/04/14
Lab:		 CS 151 Project 1
filename: 	 Echo.cpp	
 **********************************/
#include <iostream>
  int main()
     {
  	int  input_value;
	input_value = 42; 
	std::cout << "Please enter your age: "; //user enters their age
	std::cin >> input_value;
	std::cout << "You are " << input_value << " years old"  << std::endl; //output displays users age 
	return 0;
     }	
