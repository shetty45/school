/*********************************************************************
 * Author: Caleb Faruki
 * Professor: Dr. Xiaoxu Han
 * Course: CISC4080 Algorithms
 * Date: December 7, 2013
 * Description: Homework 3 Part B Caesarian Shift Cipher
 ********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int key; // cipher key
char message[0];

void Encrypt(char message[], int key);
void decrypt(char message[], int key);

int main()
{
    string input;
    printf("Enter your message: ");
    getline(cin,input); // reads spaces also
    char* msgPtr = new char[input.length()+1];
    strcpy(message, input.c_str());
    
    printf("\nEnter Cipher Key: ");
    scanf("%d", &key);
    
    Encrypt(message, key);
    printf("\nCiphertext: %s", message);

    decrypt(message, key);
    printf("\n\nDecrypted message: %s\n\n", message);
    
    return 0;
}

void Encrypt(char message[], int key) 
{
    int i = 0;
    if((key % 94) == 0)
        key = rand() % 126+33;

    while (message[i] != '\0') {
        message[i] = message[i] + key; 
        i++;
    }
}

void decrypt(char message[], int key) 
{
    Encrypt(message, 0-key);
}