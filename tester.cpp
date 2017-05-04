#include <iostream>
#include "Matrix.h"  

using namespace std;




bool MatrixAddTest()
{
	cout << "Testing Matrix Add Function" << endl;
	Matrix* firstMatrix = new Matrix(2,3);
	Matrix* secondMatrix = new Matrix(2,3);
	Matrix* rightMatrix = new Matrix(2,3);
	for(int i = 0; i < 6; i++)	
	{
		rightMatrix->setElement(i / 3 + 1, i % 3 + 1, i * 2);
	}
	Matrix* result = firstMatrix->add(secondMatrix);  	
	if(!result->equal(rightMatrix))
	{
		cout << "Matrix does not add correctly" << endl; 
		delete firstMatrix;
		delete secondMatrix;
		delete rightMatrix;
		delete result; 
		return false; 	
	}
	//delete secondMatrix;
	//secondMatrix = new Matrix(3,2);
	//delete result; 
	//result = firstMatrix->add(secondMatrix);
	cout << "Passed Add Test" << endl; 
	delete firstMatrix;
	delete secondMatrix;
	delete rightMatrix;
	delete result; 
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
	cout << "Starting Matrix Subtract Test" << endl; 
	Matrix* first = new Matrix(2,3);
	Matrix* second = new Matrix(2,3); 
	Matrix* correct = new Matrix(2,3); 
	Matrix* result = first->subtract(second);
	for(int i = 0; i < 6; i++)
	{
		correct->setElement( i / 3 + 1, i % 3 + 1, 0);
	}
	if(!result->equal(correct))
	{
		cout << "Subtract Failed to correctly subtract" << endl;
		delete first;
		delete second;
		delete correct;
		delete result;
		return false;
	}
	delete first;
	delete second;
	delete correct;
	delete result; 
	cout << "Passed Matrix Subtract Test" << endl; 
	return true; 
}

bool MatrixMultiplyTest()
{
	cout << "Starting Multiply Matrix Test" << endl; 
	Matrix* firstMatrix = new Matrix(2,2);
	Matrix* secondMatrix = new Matrix(2,2); 
	Matrix* correct = new Matrix(2,2);
	Matrix* result; 
	correct->setElement(1,1,2);
	correct->setElement(1,2,3);
	correct->setElement(2,1,6);
	correct->setElement(2,2,11);
	
	result = firstMatrix->multiply(secondMatrix);
	//result->print();
	//correct->print(); 
	if(!result->equal(correct))
	{
		cout << "Failed Multiply Matrix Test" << endl; 
		delete firstMatrix; 
		delete secondMatrix;
		delete correct;
		delete result; 
		return false; 	
	}

	delete firstMatrix; 
	delete secondMatrix;
	delete correct;
	delete result; 
	cout << "Passed Multiply Matrix Test" << endl; 
	return true; 
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
				if(MatrixAddTest())
				{
					if(MatrixSubtractTest())
					{
						if(MatrixMultiplyTest())
						{
						}
					}
				}
			}	
		}		 
	} 
}
