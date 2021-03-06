
#ifndef __BW_Quaternion_H__
#define __BW_Quaternion_H__

#include "BwCal.h"
#include "BwMatrix3.h"
#include "BwMath.h"
#include <assert.h>

//--------------------------------------------------------------------------------
// 作者：皮学贤 
// 时间：2010-06-07 
// 功能：四元组（用于旋转控制）
//================================================================================

namespace BwCal 
{
    class BW_CAL_API Quaternion
    {
    public:
        inline Quaternion ( Real fW = 1.0, Real fX = 0.0, Real fY = 0.0, Real fZ = 0.0)
		{
			w = fW;
			x = fX;
			y = fY;
			z = fZ;
		}

        /// Construct a quaternion from a rotation matrix
        inline Quaternion(const Matrix3& rot)
        {
            this->FromRotationMatrix(rot);
        }

        /// Construct a quaternion from an angle/axis
        inline Quaternion(const Radian& rfAngle, const Vec3& rkAxis)
        {
            this->FromAngleAxis(rfAngle, rkAxis);
        }

        /// Construct a quaternion from 3 orthonormal local axes
        inline Quaternion(const Vec3& xaxis, const Vec3& yaxis, const Vec3& zaxis)
        {
            this->FromAxes(xaxis, yaxis, zaxis);
        }

        /// Construct a quaternion from 3 orthonormal local axes
        inline Quaternion(const Vec3* akAxis)
        {
            this->FromAxes(akAxis);
        }

		/// Construct a quaternion from 4 manual w/x/y/z values
		inline Quaternion(Real* valptr)
		{
			memcpy(&w, valptr, sizeof(Real)*4);
		}

		/// Array accessor operator
		inline Real operator [] ( const size_t i ) const
		{
			assert( i < 4 );

			return *(&w+i);
		}

		/// Array accessor operator
		inline Real& operator [] ( const size_t i )
		{
			assert( i < 4 );

			return *(&w+i);
		}

		/// Pointer accessor for direct copying
		inline Real* ptr()
		{
			return &w;
		}

		/// Pointer accessor for direct copying
		inline const Real* ptr() const
		{
			return &w;
		}

		void FromRotationMatrix (const Matrix3& kRot);
        void ToRotationMatrix (Matrix3& kRot) const;
        void FromAngleAxis (const Radian& rfAngle, const Vec3& rkAxis);
        void ToAngleAxis (Radian& rfAngle, Vec3& rkAxis) const;
        inline void ToAngleAxis (Degree& dAngle, Vec3& rkAxis) const {
            Radian rAngle;
            ToAngleAxis ( rAngle, rkAxis );
            dAngle = rAngle;
        }
        void FromAxes (const Vec3* akAxis);
        void FromAxes (const Vec3& xAxis, const Vec3& yAxis, const Vec3& zAxis);
        void ToAxes (Vec3* akAxis) const;
        void ToAxes (Vec3& xAxis, Vec3& yAxis, Vec3& zAxis) const;
     
		/// Get the local x-axis
        Vec3 xAxis(void) const;
      
		/// Get the local y-axis
        Vec3 yAxis(void) const;
      
		/// Get the local z-axis
        Vec3 zAxis(void) const;

        inline Quaternion& operator= (const Quaternion& rkQ)
		{
			w = rkQ.w;
			x = rkQ.x;
			y = rkQ.y;
			z = rkQ.z;
			return *this;
		}

        Quaternion operator+ (const Quaternion& rkQ) const;
        Quaternion operator- (const Quaternion& rkQ) const;
        Quaternion operator* (const Quaternion& rkQ) const;
        Quaternion operator* (Real fScalar) const;

        BW_CAL_API friend Quaternion operator* (Real fScalar,
            const Quaternion& rkQ);

        Quaternion operator- () const;
        inline bool operator== (const Quaternion& rhs) const
		{
			return (rhs.x == x) && (rhs.y == y) &&
				(rhs.z == z) && (rhs.w == w);
		}
        inline bool operator!= (const Quaternion& rhs) const
		{
			return !operator==(rhs);
		}
   
		// functions of a quaternion
        Real Dot (const Quaternion& rkQ) const;  // dot product
        Real Norm () const;  // squared-length
    
		/// Normalises this quaternion, and returns the previous length
        Real normalise(void); 
        Quaternion Inverse () const;		// apply to non-zero quaternion
        Quaternion UnitInverse () const;	// apply to unit-length quaternion
        Quaternion Exp () const;
        Quaternion Log () const;

        // rotation of a vector by a quaternion
        Vec3 operator* (const Vec3& rkVector) const;

   		/** Calculate the local roll element of this quaternion.
		@param reprojectAxis By default the method returns the 'intuitive' result
			that is, if you projected the local Y of the quaternion onto the X and
			Y axes, the angle between them is returned. If set to false though, the
			result is the actual yaw that will be used to implement the quaternion,
			which is the shortest possible path to get to the same orientation and 
			may involve less axial rotation. 
		*/
		Radian getRoll(bool reprojectAxis = true) const;

   		/** Calculate the local pitch element of this quaternion
		@param reprojectAxis By default the method returns the 'intuitive' result
			that is, if you projected the local Z of the quaternion onto the X and
			Y axes, the angle between them is returned. If set to true though, the
			result is the actual yaw that will be used to implement the quaternion,
			which is the shortest possible path to get to the same orientation and 
			may involve less axial rotation. 
		*/
		Radian getPitch(bool reprojectAxis = true) const;

   		/** Calculate the local yaw element of this quaternion
		@param reprojectAxis By default the method returns the 'intuitive' result
			that is, if you projected the local Z of the quaternion onto the X and
			Z axes, the angle between them is returned. If set to true though, the
			result is the actual yaw that will be used to implement the quaternion,
			which is the shortest possible path to get to the same orientation and 
			may involve less axial rotation. 
		*/
		Radian getYaw(bool reprojectAxis = true) const;	

		/// Equality with tolerance (tolerance is max angle difference)
		bool equals(const Quaternion& rhs, const Radian& tolerance) const;
	
		/** return true if the Quat represents a zero rotation, and therefore can be ignored in computations.*/
        bool zeroRotation() const { return x==0.0 && y==0.0 && z==0.0 && w==1.0; } 
	
	    // spherical linear interpolation
        static Quaternion Slerp (Real fT, const Quaternion& rkP,
            const Quaternion& rkQ, bool shortestPath = false);

        static Quaternion SlerpExtraSpins (Real fT,
            const Quaternion& rkP, const Quaternion& rkQ,
            int iExtraSpins);

        // setup for spherical quadratic interpolation
        static void Intermediate (const Quaternion& rkQ0,
            const Quaternion& rkQ1, const Quaternion& rkQ2,
            Quaternion& rka, Quaternion& rkB);

        // spherical quadratic interpolation
        static Quaternion Squad (Real fT, const Quaternion& rkP,
            const Quaternion& rkA, const Quaternion& rkB,
            const Quaternion& rkQ, bool shortestPath = false);

        // normalised linear interpolation - faster but less accurate (non-constant rotation velocity)
        static Quaternion nlerp(Real fT, const Quaternion& rkP, 
            const Quaternion& rkQ, bool shortestPath = false);

        // cutoff for sine near zero
        static const Real ms_fEpsilon;

        // special values
        static const Quaternion ZERO;
        static const Quaternion IDENTITY;

		Real w, x, y, z;

        /** Function for writing to a stream. Outputs "Quaternion(w, x, y, z)" with w,x,y,z
            being the member values of the quaternion.
        */
        //inline friend std::ostream& operator <<
        //    ( std::ostream& o, const Quaternion& q )
        //{
        //    o << "Quaternion(" << q.w << ", " << q.x << ", " << q.y << ", " << q.z << ")";
        //    return o;
        //}
    };
}

#endif 
