#include <iostream>
//#include "Matrix.h"  

using namespace std;

class Matrix
{
		int height;
		int width; 
		int* innerArr;
	public: 
		Matrix(int,int);
		Matrix* multiply(Matrix*);
		void setElement(int,int,int);
		int getElement(int,int); 
		void printMatrix();  
		~Matrix(); 

		
};

Matrix::Matrix(int height, int width)
{
	this->height = height;
	this->width = width; 
	this->innerArr = new int[height * width]; 
	//cout <<  height * width;
	for(int i = 0; i < height * width; i++)
	{
		innerArr[i] = i;
		//cout << innerArr[i];  
	} 
}

void Matrix::printMatrix()
{
	//cout << this->innerArr[0]; 
	for(int i = 0; i < this->height; i++)
	{
		for(int j = 0; j < this->width; j++)
		{
			cout << this->innerArr[i * this->width + j] << " ";  
		}
		cout << endl; 
	}
}

void Matrix::setElement(int row, int column, int element)
{
	if((row * column) < (this->width * this->height))
	{
		this->innerArr[this->width * row + column] = element;
	} 
}

int Matrix::getElement(int row, int column)
{
	return this->innerArr[this->width * row + column];  
}

Matrix* Matrix::multiply(Matrix* other)
{
	if(this->width = other->height)
	{
		int sum = 0; 
		Matrix* toReturn = new Matrix(this->height, other->width); 
		for(int i = 0; i < toReturn->height; i++)
		{
			for(int j = 0; j < toReturn->width; j++)
			{
				sum = 0; 
				for(int k = 0; k < this->width; k++)
				{
					sum += other->getElement(k,j) * this->getElement(i,k);
				}
				toReturn->setElement(i,j, sum);		
			}
		}
		//cout << "Here ins multiply" << endl;
		return toReturn;
	}  
}

Matrix::~Matrix()
{
	delete this->innerArr;
	this->innerArr = NULL; 
}

int main(int argc, char* argv[])
{
	//cout << "Hello World" << endl;
	Matrix* myMatrix = new Matrix(2,3); 
	//myMatrix->setElement(3,4,100); 
	Matrix* otherMatrix = new Matrix(3,2); 
	myMatrix->printMatrix();
	//int element = myMatrix->getElement(3,4); 
	//cout << element << endl; 
	Matrix* result = myMatrix->multiply(otherMatrix);
	result->printMatrix(); 
	//cout << "here" << endl;
	delete result;
	delete otherMatrix;   
	delete myMatrix;    
	myMatrix = NULL; 
	result = NULL;
	otherMatrix = NULL; 
}
