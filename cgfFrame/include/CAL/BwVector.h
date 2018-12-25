// Vector.h: interface for the Vector class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __BW_Vector_H__
#define __BW_Vector_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
namespace BwCal
{
class  Matrix;
class BW_CAL_API Vector  
{

//friend class CTarget;	
friend class  Matrix;
protected:

		struct vrep
		{
			 double *f;
			 int refcnt;
			 int length;
		} *p;
	   
public:
		 
		 Vector();
		 Vector(int num,double x,double y,double z,...);
         Vector(int size, double init=0.0);
		 Vector(double  *a,int length);
		 Vector(Vector & a1,Vector & a2);
		 Vector(Vector & a,int first,int last);
		 Vector(const Vector & x);
		 
		 virtual ~Vector();


public:
	bool isonebigthan(double value);
	Vector copy();
	Vector threedto2d();
	void getposvel(Vector &pos,Vector &vel);
	Vector assemblestatus(Vector &pos,Vector &vel);
	Vector statusptoo();
	Vector statusotop();
	void addone(double one);
	void addtwo(double one,double two);
//	public:
		
	   friend int vlen(Vector & v){ return v.p->length;}
	   friend int vlen(Vector * v){ return v->p->length;}
	   
       int vlen(){ return p->length;}

		
//	   friend ostream   & operator <<(ostream   & out, Vector   & v1);
	
//	public:	
		 
        Vector & operator = (const Vector & vec);
		Vector & operator=(double x);
	    BW_CAL_API friend  int  operator==(Vector  & v1,Vector  & v2);
		BW_CAL_API friend  int  operator!=(Vector  & v1,Vector  & v2);
        BW_CAL_API friend  int  operator<=(Vector  & v1, Vector  & v2); 
        BW_CAL_API friend  Vector   operator+(Vector  & v1,Vector  & v2 );
		BW_CAL_API friend  Vector  operator-( Vector  & v1,Vector  & v2);
		
		BW_CAL_API friend  Vector  operator*( Vector  & v1,Vector  & v2);
		BW_CAL_API friend  Vector  operator/( Vector  & v1,Vector  & v2);
		Vector  operator+(double x);
		Vector  operator-(double x);
		Vector  operator*( double x);
		Vector  operator/( double x);
		Vector  operator+();
		Vector  operator-();
		Vector & operator+=(Vector  & v1);
		Vector & operator-=(Vector  & v1);
		Vector & operator*=(Vector  & v1);
		Vector & operator/=(Vector  & v1);
		Vector & operator+=(double x);
		Vector & operator-=(double x);
		Vector & operator*=(double x);
		Vector & operator/=(double x);

		double & operator[](int i);
		
		//result=sum(v)
		//returns the sum of all elements.
		BW_CAL_API friend  double  sum(Vector &v);
        //result=v1.dot(v2)
		double  dot(Vector  & v2);
		
		//vresult=v.slice(len)
		//returns a subvector of v. it has len elements and vresult[0]=x[0].
		Vector  slice(int len);
		
		//vresult=v.slice(lstart,length)
		//return a subvector of v. it has length elements
		//and vresult[0]=v[lstart].
		Vector  slice(int lstart,int length);
		
		//vresult=v1.comvec(v2)
		//combines two vectors to return a new vector. v2 is placed behind v1.
	//	Vector  comvec(Vector  & v2);
         Vector comvec(Vector  & v2);
	  	 //直角坐标转换为极坐标
	     Vector  otop();	
	     Vector  otopex();	
	   //极坐标转换为直角坐标
	     Vector  ptooex();	
	     Vector  ptoo() ;
		 void  gadd(Vector &vec);//推广加法
		 void  gmean(Vector &vec);//推广取平均
		BW_CAL_API friend Vector weightmean(Vector vec1,Vector w1,Vector vec2,Vector w2);	   
       //跟踪输出
        BW_CAL_API friend void  VTRACE(Vector & vect);
        BW_CAL_API friend Matrix  VtoMatrix(Vector  & v1,Vector & v2);
	   
		//-----------------------------------
		 
		//x.log() or vresult=x.log()
		//natural logarithm.
		BW_CAL_API friend Vector   log(Vector  & v);

		//x.log10() or vresult=x.log10()
		//base-10 logarithm
		 BW_CAL_API friend Vector  log10(Vector  & v);

		//x.exp() or vresult=x.exp()
		//natural exponentiation
		Vector & exp();

		//x.sqrt() or vresult=x.sqrt()
		 BW_CAL_API friend Vector sqrt(Vector  & v);
		//------------------
		 
		 
        //Vector  copy();
	    //operator double *(){return p->f;}
		
		
		//mresult=v.diag()
		//returns a square matrix which use input vector as main diagnal elements.
		Matrix  diag();

		//mresult=v.diag(k)
		//returns a square matrix which use the elements of vector as the
		//k-th subdiagnal. if k>0, the subdiagnal is above the main diagnal.
		//otherwise, it is under the main diagnal. the dimension of return
		//matrix is (n+|k|)*(n+|k|).
		Matrix  diag(int k);

		//mresult=v1.commat(v2,select)  or mresult=v1.commat(v2)
		//combines a vector and a matrix to form a new matrix. the vector is placed at
		//the first row or first column:
		//if select=1:          combines a n elements column-vector with
		//                      a n1*m1 matrix. the result is a n*(m1+1)
		//                      matrix (n=MAX(n1,n2));
		//if select=2(default): combines a n elements row-vector with a
		//                      n1*m1 matrix. the result is a (n1+1)*m
		//                      matrix (m=MAX(m1,m2));
		//other select:         reports an error !
		Matrix  commat( Matrix  & v2,int select=2);

		//mresult=v1.commat(v2,select) or mresult=v1.commat(v2)
		//combines two vectors to form a new matrix:
		//if select=1:          combines a n1 element vector with a n2
		//                      element vector. the result is a n*2
		//                      matrix (n=MAX(n1,n2));
		//if select=2(default): combines a m1 element vector with a m2
		//                      element vector. the result is a 2*m
		//                      matrix (m=MAX(m1,m2));
		//other select:         reports an error !
		Matrix  commat(Vector  & m2,int select=2);


		BW_CAL_API friend int  any(Vector  & v);
        BW_CAL_API friend Vector  MAX(Vector  & v1,Vector  & v2);
        BW_CAL_API friend double  MAX(Vector & v);
        BW_CAL_API friend double  MIN(Vector  & v);
        BW_CAL_API friend Vector  MIN(Vector  & v1,Vector & v2);

        BW_CAL_API friend Vector  abs(Vector  & v);
        Vector & sort(int select);
        BW_CAL_API friend Vector  urand(int m);
		BW_CAL_API friend Vector  &  urand(Vector  & v);
		BW_CAL_API friend int Possion(double mean);
		BW_CAL_API friend Vector  nrand(Vector & mean,Vector & var);
        BW_CAL_API friend double  norm(Vector  & v, int n);
        BW_CAL_API friend Vector  pow(Vector  & x,Vector  & pp);
        Vector    pow(Vector  & pp);
        Vector    pow(double pp);
       

		
		Vector & cos();
		Vector & sin();
		Vector & acos();
		Vector & asin();
		Vector & tan();
		Vector & atan();
        Vector twootop();
        Vector twoptoo(); 

		/*Vector & cosh();
		  Vector & sinh();
		  Vector & tanh();
		*/
	
/////////////////////////////////////////////
	   int  pop();
       bool push(int element);
       void initstack(int n);
       int  stacklen();  //

///////////////////////////////////		

		
};
}



#endif // !defined(AFX_DVector_H__A29FBFC2_4362_11D2_B08C_444553540000__INCLUDED_)
