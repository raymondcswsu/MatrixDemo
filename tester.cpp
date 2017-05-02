#include <iostream>
#include "Matrix.h"  

using namespace std;




bool MatrixAddTest()
{
	cout << "Testing Matrix Add Function" << endl;
	Matrix* firstMatrix = new Matrix(2,3);
	Matrix* secondMatrix = new Matrix(2,3);
	Matrix* thirdMatrix = new Matrix(2,3);
//	if()
	
	
	return true;  
}

bool MatrixEqualTest()
{
	cout << "Testing Matrix Equal Function" << endl; 
	Matrix* firstMatrix = new Matrix(2,3);
	Matrix* secondMatrix = new Matrix(2,3); 

	if(!firstMatrix->equal(secondMatrix))
	{
		cout << "Matrices were not equal when they should be" << endl;
		delete firstMatrix;
		delete secondMatrix;  
		return false; 
	}
	secondMatrix->setElement(2,3,14);
	if(firstMatrix->equal(secondMatrix))
	{
		cout << "Matrices were equal when they have different elements" << endl;
		delete firstMatrix;
		delete secondMatrix; 
		return false; 
	}


	delete firstMatrix;
	firstMatrix = new Matrix(3,2);
	if(firstMatrix->equal(secondMatrix))
	{
		cout << "(2,3) was equal to (3,2)" << endl;
		firstMatrix->print(); 
		secondMatrix->print(); 
		delete firstMatrix;
		delete secondMatrix;  
		return false;
	}
	cout << "Passed Matrix Equals Test" << endl; 
	delete firstMatrix;
	delete secondMatrix;  
	return true; 
}

bool MatrixSubtractTest()
{
	
}

bool MatrixMultiplyTest()
{
}

void MatrixPrintTest()
{
	Matrix* myMatrix = new Matrix(2,3); 
	cout <<"Running Matrix Print Test, Should be: " << endl << "0 1 2" 
	<< endl << "3 4 5" << endl << "is: " << endl;
	myMatrix->print();
	delete myMatrix;  
}

bool MatrixGetElementTest()
{
	cout << "Running Matrix get element test" << endl; 
	
	Matrix* myMatrix = new Matrix(2,3);
	int element = myMatrix->getElement(2,3);
	if(element != 5)
	{
		cout << "was supposed to return 5, it returned: " << element <<  endl; 
		return false; 
	}
	element = myMatrix->getElement(1,2);
	if(element != 1)
	{
		cout << "was supposed to return 2, it returned: " << element << endl;
		return false;  
	} 
	delete myMatrix;
	myMatrix = new Matrix(5,5);
	element = myMatrix->getElement(4,4);
	if(element != 18)
	{
		cout << "was supposed to return 18, it returned: " << element << endl;
		return false;  
	}
	delete myMatrix; 
	cout << "Matrix Get Element Passed" << endl; 	
	return true; 
}

bool MatrixSetElementTest()
{
	cout << "Running Matrix Set Element Test" << endl; 

	Matrix* myMatrix = new Matrix(2,3);
	for(int i = 0; i < 6; i++)
	{ 
		myMatrix->setElement(i / 3, i / 2, i * 2);
		if(myMatrix->getElement(i /3, i/2) != i * 2)
		{
			cout << "Matrix Set Element Failed should be " << i * 2 << ", is: " << myMatrix->getElement(i/3,i/2);
			return false;  
		}
	}
	
	delete myMatrix;
	cout << "Matrix Set Element Passed" << endl;  
	return true;
}

int main(int argc, char* argv[])
{
	MatrixPrintTest();
	if(MatrixGetElementTest())
	{
		if(MatrixSetElementTest())
		{
			if(MatrixEqualTest())
			{
			}	
		}		 
	} 
}
