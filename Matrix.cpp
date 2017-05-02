#include "Matrix.h" 
#include <iostream>

using namespace std; 

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

void Matrix::print()
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
	row--;
	column--; 
	if((row * column) < (this->width * this->height))
	{
		this->innerArr[this->width * row + column] = element;
	} 
}

int Matrix::getElement(int row, int column)
{
	return this->innerArr[this->width * (row -1)+ (column -1)];  
}

bool Matrix::equal(Matrix* other)
{
	if(!(this->height == other->height && this->width == other->width))
	{
		return false;
	}	
	int length = this->height * this->width; 
	for(int i = 0; i < length; i++)
	{
		if(this->innerArr[i] != other->innerArr[i])
		{
			return false;
		}
	}
	return true; 
 
}

Matrix* Matrix::add(Matrix* other)
{
	Matrix* myMatrix = new Matrix(3,2); 
	return myMatrix; 
}

Matrix* Matrix::subtract(Matrix* other)
{
	Matrix* myMatrix = new Matrix(3,2);
	return myMatrix; 
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


