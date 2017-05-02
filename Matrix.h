
#ifndef _MATRIX_H_INCLUDED__ 
#define _MATRIX_H_INCLUDED__ 


class Matrix
{
		int height;
		int width; 
		int* innerArr;
	public: 
		Matrix(int,int);
		void print(); 
		void setElement(int,int,int);
		int getElement(int,int); 
		bool equal(Matrix*);
		Matrix* multiply(Matrix*); 
		Matrix* add(Matrix*); 
		Matrix* subtract(Matrix*);   
		~Matrix(); 

		
};

#endif 
