
#ifndef __BW_Ray_H_
#define __BW_Ray_H_

#include "BwCal.h"
#include "BwVec3.h"

namespace BwCal
{
//--------------------------------------------------------------------------------
// 作者：皮学贤 
// 时间：2010-06-07 
// 功能：射线，具有原点和方向属性
//================================================================================
   class BW_CAL_API Ray
    {
    protected:
        Vec3 mOrigin;
        Vec3 mDirection;

    public:
        Ray():mOrigin(Vec3::ZERO), mDirection(Vec3::UNIT_Z) {}
     
		Ray(const Vec3& origin, const Vec3& direction)
            :mOrigin(origin), mDirection(direction) {}

        /** Sets the origin of the ray. */
        void setOrigin(const Vec3& origin) { mOrigin = origin;} 
       
		/** Gets the origin of the ray. */
        const Vec3& getOrigin(void) const {return mOrigin;} 

        /** Sets the direction of the ray. */
        void setDirection(const Vec3& dir) {mDirection = dir;} 
      
		/** Gets the direction of the ray. */
        const Vec3& getDirection(void) const {return mDirection;} 

		/** Gets the position of a point t units along the ray. */
		Vec3 getPoint(Real t) const { 
			return Vec3(mOrigin + (mDirection * t));
		}
		
		/** Gets the position of a point t units along the ray. */
		Vec3 operator*(Real t) const { 
			return getPoint(t);
		};

    };
}
#endif
