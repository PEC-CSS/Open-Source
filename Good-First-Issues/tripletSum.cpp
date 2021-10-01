// tripletSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string> //The input is first recorded into a string.
using namespace std;
#define ASCII_OF_ZERO 48;

//The function recives the following input:
// 1. The array from which it is required to find a triplet.
// 2. The place in the array of the first number of the triplet (in main function - array[i]).
// 3. The size of the array.
// 4. The difference between the input sum and array[point] (For checking if the sum of two other numbers in the array is equal to it).
//If the function finds two numbers whose sum is equal to sum-array[point], the output of the function (these two numbers) + array[i] 
//will give us the sum.
int* sumOf2Nums(int* array,int point,int size,int sum)
{
    int* solution = new int[2];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            //Checking that the three numbers are in different places in the array.
            if (j != i && j != point && array[i]+ array[j]==sum)
            {
                //Return the two numbers whose sum is equal to sum-array[point] as an array of two integers.
                solution[0] = array[i];
                solution[1] = array[j];
                return solution;
            }
        }
    }
    //If we didn't find a triplet, we return an incorrect pair and in the main function we check another prime number of the triplet.
    if (sum!=0)
    {
        solution[0] = 0;
        solution[1] = 0;
        return solution;
    }
    else
    {
        solution[0] = 1;
        solution[1] = 1;
        return solution;
    }
}

int main()
{
    
    int* solution = new int[2];
    string input;
    //Getting the input from the user.
    //Our input format is: array = {num1, num2, ....}, sum = theSum;
    getline(cin , input);
    int sum=0;
    int j = 0;
    int size = 0;
    int num = 0;
    int k=0;
    //Checking the size of the array by counting the ',' characters int the input string.
    for (j = 0; j < input.size(); j++)
    {
        if (input[j] == ',')
        {
            size++;
        }
    }
    int* array=new int[size];
    j = 0;
    k = 0;
    //Scanning the string for savine the numbers in an integer type array.
    while (input[j] != '{')
    {
        j++;
    }
    j++;
    while (input[j-1] != '}')
    { 
        //Converting the digits in the string to integers.
        while (input[j] != ',' && input[j] != '}')
        {
            num = num * 10 + input[j]- ASCII_OF_ZERO;
            j++;
        }
        //Entering the integer from the string to an array.
        array[k] = num;
        num = 0;
        k++;
        j++;
        //Skipping ' ' chaaracters.
        if (input[j] == ' ')
        {
            j++;
        }
    }
    //Skip to the place of the sum in the string (according to the input format).
    j = j + 8;
    //Converting the digits of the sum to an integer.
    while (input[j] != ';')
    {
        sum = sum * 10 + input[j] - ASCII_OF_ZERO;
        j++;
    }
    //Searching a triplet - for each array[i] we try to find two numbers in the array that complement a triplet.
    for (int i = 0; i < size; i++)
    {
        solution = sumOf2Nums(array, i, size, sum - array[i]);
        if (array[i] + solution[0] + solution[1] == sum)
        {
            //Printing thr triplet
            cout << array[i] << ", " << solution[0] << ", " << solution[1];
            return 1;
        }
    }
    //Return false if there is no triplet.
    return false;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
