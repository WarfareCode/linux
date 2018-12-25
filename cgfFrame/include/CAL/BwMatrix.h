// Matrix.h: interface for the Matrix class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __BW_Matrix_H__
#define __BW_Matrix_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


///////////////////

namespace BwCal
{
int   Matdet(double  **m,int numcol,double  & det);

int   Matinv(double  **a,int n);

int   Matinv(double  *a,int n);

int   Matinv1(double  **invary,int numcol,double  & det);

class Vector;

class BW_CAL_API Matrix 
{
	protected:

		//Matrix data structure
		struct mrep
		{
			Vector **f;
			int refcnt;
			int length;
			double ** tmppointer;
		} *p;

//	    friend ostream   & operator <<(ostream   & out, Matrix   & m1);
		
	public:
		Matrix DelRow(int row);
		Matrix(int m,Vector v1,...);
		Matrix & covarptoo(Vector var,Vector point);
		Matrix & covarptooex(Vector var,Vector point);

		friend class  Vector;

		//iresult=m.row() or iresult=row(m) or iresult=row(pm)
		//retrieves row number of the Matrix.
		friend int mrow(Matrix  & m) { return m.p->length;}
		friend int mrow(Matrix  *m)  { return m->p->length;}
		int mrow(){ return p->length;}

		//iresult=m.col() or iresult=col(m) or iresult=col(pm)
		//retrieves colum number of the Matrix.
		friend int vlen(Vector  & v);
		friend int vlen(Vector  *v);

		friend int mcol(Matrix  & m){ return vlen(m.p->f[0]);}
		friend int mcol(Matrix  *m){ return vlen((Vector *)(m->p->f[0]));}
		int mcol(){ 
			if(p->f==NULL)return 0;
			else return vlen((Vector *)(p->f[0]));}

		 //Matrix()
		 //default constructor.
		 Matrix();

		 //Matrix(i1,i2,c) or Matrix(i1,i2)
		 //constructor with the order and/or initial data.
		 Matrix(int xsize, int ysize, double init=0.0);

		 //Matrix(ppt,i1,i2)
		 //constructor with a c/c++ array.
		 Matrix(double **a,int xlength,int ylength);
         Matrix(double * a,int xlength,int ylength);
		 //Matrix(m1,m2,select) or Matrix(m1,m2)
		 //constructs a new Matrix with Matrix a1 and a2. the construction
		 //mode is controlled by variable select:
		 //select=0: 		  the Matrix A1(n1*m1) and B1(n2*m2) will be
		 //					  placed at main diagnal and the dimension of
		 //					  new Matrix is (n1+n2)*(m1+m2);
		 //select=1:	      combines Matrix A1(n1*m1) and B1(n2*m2).
		 //					  the dimension of new Matrix is n*(m1+m2)
		 //					  (n=MAX(n1,n2));
		 //select=2(default): combines Matrix A1(n1*m1) and B1(n2*m2).
		 //					  the dimension of new Matrix is (n1+n2)*m
		 //					  (m=MAX(m1,m2));
		 //other select:	  report an error !
		 Matrix(Matrix  & a1, Matrix  & a2,int select=2);

		 //Matrix(m,i1,i2,i3,i4)
		 //constructor with part of a Matrix. the dimension of new Matrix  is
		 //(xlast-xfirst)*(ylast-yfist). the first element is a[xfirst][yfirst].
		 Matrix(Matrix  & a,int xfirst,int xlast,
				 int yfirst, int ylast);

		 //Matrix(m)
		 //copy constructor.
		 Matrix(const Matrix  & x);

		 //destructor.
		 ~Matrix();


		 //mresult=copy(m) or mresult=m.copy()
		 //produces an new Matrix which has the same order and elements.
		 //this Matrix has its own data structure.
		
		 Matrix   copy();
          	//mresult=copy(m)
		 friend Matrix  copy(Matrix  & m)
					{return m.copy();}

		 //ppt=m
		 //converts Matrix to double **.
		 operator double **();

		 //mresult=m
		 Matrix  &  operator=(const Matrix  & m);

		 //mresult=v
		 Matrix  &  operator=(Vector   & v);

		 //mresult=x
		 Matrix  &  operator=(double  x);

		//mresult=m1+m2;
		Matrix   operator+(Matrix  & m2);

		//mresult=m1-m2;
		Matrix   operator-(Matrix  & m2);

		//mresult=m1*m2;
		Matrix   operator*(Matrix  & m2);

		//mresult=m1/m2;
		Matrix   operator/(Matrix  & m2);

		//mresult=m1+x;
		Matrix   operator+(double x);

		//mresult=m1-x;
		Matrix   operator-(double x);

		//mresult=m1*x;
		Matrix   operator*(double x);

		//mresult=m1*v2;
		Vector   operator*(Vector  & v2);

		//mresult=m1/x;
		Matrix   operator/(double x);

		//mresult=+m;
		Matrix   operator+();

		//mresult=-m;
		Matrix   operator-();

		//mresult+=m1
		Matrix  &  operator+=(Matrix  & m1);

		//mresult-=m1
		Matrix  &  operator-=(Matrix  & m1);

		//mresult/=m1
		Matrix  &  operator/=(Matrix  & m1);

		//mresult+=x
		Matrix  &  operator+=(double x);

		//mresult-=x
		Matrix  &  operator-=(double x);

		//mresult*=x
		Matrix  &  operator*=(double x);

		//mresult/=x
		Matrix  &  operator/=(double x);

		//mresult=m1.prod(m2)
		Matrix  &  prod(Matrix  & m2);

		//vresult=m[i]
		Vector  &  operator[](int i);

		//result=(m1==m2)
		int   operator==(Matrix  & m2);

		//result=(m1!=m2);
		int   operator!=(Matrix  & m2);

		//vresult=m.row(n)
		//returns a special row of a Matrix.
		Vector   row(int n);

		//vresult=m.col(n)
		//returns a special column of a Matrix.
		Vector   col(int n);

		//mresult=m.slice(row,col)
		//returns a subDMatrix of m. it is row*col and mresult[0][0]=x[0][0].
		Matrix   slice(int row,int col);

		//mresult=m.slice(row1,col1,row2,col2)
		//returns a subDMatrix of m, it is row2*col2
		//and mresult[0][0]=m[row1][col1].
		Matrix   slice(int row1,int col1,int row2,int col2);
        

		Matrix   rowdel(int row);
        Matrix   coldel(int col);

		//mresult=m1.commat(m2,select) or mresult=m1.commat(m2)
		//combines two matrices:
		//select=0: 		  the Matrix A(n1*m1) and B(n2*m2) will be placed
		//					  at main diagnal line and result is a
		//					  (n1+n2)*(m1+m2) Matrix;
		//select=1:	   	      combines a n1*m1 Matrix with a n2*m2 Matrix.the
		//					  result is a n*(m1+m2) Matrix (n=MAX(n1,n2));
		//select=2(default):  combines a n1*m1 Matrix with a n2*m2 Matrix. the
		//					  result is a (n1+n2)*m Matrix (m=MAX(m1,m2));
		//other select:		  reports an error !
		Matrix   commat(Matrix  & m2,	int select=2);

		//mresult=m1.commat(v2,select) or mresult=m1.commat(v2)
		//combines a Matrix with a Vector to form a new Matrix:
		//select=1:			    combines a n1*m1 Matrix with a n2 element
		//						column-Vector. the result is a n*(m1+1)
		//						Matrix (n=MAX(n1,n2));
		//select=2(default):    combines a n1*m1 Matrix with a m2 element
		//				        row-Vector. the result is a (n1+1)*m
		//						Matrix (m=MAX(m1,m2));
		//other select:			will report an error !
		Matrix   commat(Vector  & v2,int select=2);

		//mresult=m1.commat(m2,srow,scol)
		//combines two matrices with arbitry manner. the limitation is that
		//any element of the two matrices can not be overlapped. the Matrix
		//A(n1*m1) is placed at left-top corner. the first element of Matrix
		//B(n2*m2) is placed at (srow,scol). the dimension of result Matrix
		//is max(srow+n2,n1)*max(scol+m2,m1).
		Matrix   commat(Matrix  & m2,
							int srow,int scol);


		//vresult=m.diag()
		//returns the main diagnal element of input Matrix.
		Vector   diag();

		//vresult=m.diag(k)
		//returns the k-th subdiagnal of input Matrix. if k>0, the subdiagnal
		//is above main diagnal. otherwise, it is under the main diagnal.
		Vector   diag(int k);

		//vresult=m.sum()
		//returns the sum of every element in the same row of input Matrix.
		Vector   sum();


		//WARNING:  the tions at next part store the calculation result in
		//the memory units of Vector which calls these tions. therefore,
		//the old content of the Vector will be destroyed.

		//----------------------
		//trigonometric tion
		//----------------------

		//x.cos() or mresult=x.cos()
		Matrix  &  cos();

		//x.cosh() or mresult=x.cosh()
		Matrix  &  cosh();

		//x.acos() or mresult=x.acos()
		Matrix  &  acos();

		//x.sin() or mresult=x.sin()
		Matrix  &  sin();

		//x.sinh() or mresult=x.sinh()
		Matrix  &  sinh();

		//x.asin() or mresult=x.asin()
		Matrix  &  asin();

		//x.tan() or mresult=x.tan()
		Matrix  &  tan();

		//x.tanh() or mresult=x.tanh()
		Matrix  &  tanh();

		//x.atan() or mresult=x.atan()
		Matrix  &  atan();

		//--------------------
		//logarithmic tion
		//--------------------

		//x.log() or mresult=x.log()
		//natural logarithm.
		Matrix  &  log();

		//x.log10() or mresult=x.log10()
		//base-10 logarithm.
		Matrix  &  log10();

		//x.exp() or mresult=x.exp()
		//natural exponentiation.
		Matrix  &  exp();

		//x.pow(pp) or mresult=x.pow(pp)
		//calculates exponentiation for every element.
		//mresult[i][j]=x[i][j]^pp.
		Matrix  &  pow(double pp);

		//x.pow(pp) or mresult=x.pow(pp)
		//calculates exponentiation for conresponded element.
		//mresult[i][j]=x[i][j]^pp[i][j].
		Matrix  &  pow(Matrix  & pp);

		//x.sqrt() or mresult=x.sqrt()
		Matrix  &  sqrt();

		//-------------------------------------
		        //mresult=m1*m2
		BW_CAL_API friend Vector  operator*(Vector  & m1,
				 Matrix  & m2);
		//mresult=trans(m) or mresult=m.trans()
		Matrix  trans();
		BW_CAL_API friend Matrix  trans(Matrix  & m);

		//mresult=ABS(m) or mresult=m.ABS()
		Matrix  abs();
		BW_CAL_API friend Matrix  abs(Matrix  & m);

		//vresult=any(m) or vresult=m.any()
		//returns a vector. if the i-th row has any non-zero element,the i-th
		//element of return vector is 1. otherwise, it is 0.
		Vector  any();
		BW_CAL_API friend Vector  any(Matrix  & m);

		 //vresult=max(m) or vresult=m.max()
		 Vector  MAX();
		 BW_CAL_API friend Vector  MAX(Matrix  & m);

		 //mresult=max(m1,m2) or mresult=m1.max(m2)
		 //mresult[i][j]=max(m1(i,j),m2(i,j)).
		 Matrix  MAX(Matrix  & m2);
		 BW_CAL_API friend Matrix  MAX(Matrix  & m1,Matrix  & m2);

		 //vresult=min(m) or vresult=m.min()
		 Vector  MIN();
		 BW_CAL_API friend Vector  MIN(Matrix  & m);

		 //mresult=min(m1,m2) or mresult=m1.min(m2)
		 //mresult[i][j]=min(m1(i,j),m2(i,j)).
		 Matrix  MIN(Matrix  & m2);
		 BW_CAL_API friend Matrix  MIN(Matrix  & m1,Matrix  & m2);

		//mresult=eye(i)
		//returns a E matrix which is n*n (the main diagnal elements
		//are 1. other elements are 0.)
		BW_CAL_API friend Matrix  eye(int n);

		//mresult=eye(i1,i2)
		//returns a m*n matrix. the main diagnal elements are 1.
		//other elements are 0.
		BW_CAL_API friend Matrix  eye(int n1,int n2);

		//mresult=eye(m) or mresult=m.eye()
		//returns a matrix which has the same order with input matrix.
		//the main diagnal elements are 1. other elements are 0.
		BW_CAL_API friend Matrix  eye(Matrix  & m);
		Matrix  eye();

		 //mresult=rand(m) or rand(m) or mresult=m.rand()
		 //fullfills every element of matrix m with random numbers
		 //which are uniformly distributed in the range of (0.0, 1.0).
		 //WARNING: this function will destroy the old content of
		 //matrix object which calls this function.
		 Matrix  &  rand();
		 BW_CAL_API friend Matrix  &  RAND(Matrix  & m);

		 //mresult=m.rand(i1,i2)
		 //creates a new n1*n2 random matrix.
		 //there is no influence to matrix which calls this function.
		 Matrix  rand(int n1,int n2);
    	//result=det(m) or result=m.det()
		double  det();
		BW_CAL_API friend double  det(Matrix  & m);

		//mresult=inv(m) or mresult=m.inv()
		Matrix  inv();
		BW_CAL_API friend Matrix  inv(Matrix  & m);

		//mesult=inv1(m) or mresult=m.inv1()
		Matrix  inv1();
		BW_CAL_API friend Matrix  inv1(Matrix  & m);

		//mresult=inv(m,det) or mresult=m.inv(det)
		//calculates inverse and determinate at the same time.
		Matrix  inv(double  & det);
		BW_CAL_API friend Matrix  inv(Matrix  & m,
				double  & det);
        BW_CAL_API friend Matrix  sort(Matrix matix,int select,int rown);

		//--------------------------------------
		//display the matrix in OutPut window
		BW_CAL_API friend void  MTRACE(Matrix m);
		BW_CAL_API friend bool ZD(Matrix &m);
};
}

#endif // !defined(AFX_DMATRIX_H__4EDE6E22_4625_11D2_B08C_444553540000__INCLUDED_)
