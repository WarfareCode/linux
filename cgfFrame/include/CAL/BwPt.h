#pragma once

#ifndef __BW_Pt_H__
#define __BW_Pt_H__

#include "BwCal.h"
#include "BwVec3.h"


namespace BwCal
{
	//--------------------------------------------------------------------------------
	// ���ߣ�Ƥѧ�� 
	// ���ڣ�2010-06-07 
	// ���ܣ�����λ������,����x,y,z���α�ʾγ��Latitude������Longitude�����θ�Elevation
	//================================================================================

	class BW_CAL_API GeoPt
	{
    public:
		//����Ϊγ�ȡ����ȡ����θ�
		Real	x,	y,	z;

  		Real Lat()
  		{
  			return this->x ;
  		};
		Real Lon()
		{
			return this->y ;
		};
		Real Elev()
		{
			return this->z ;
		};

	public:
		GeoPt(): x( 0.0 ), y( 0.0 ), z( 0.0 ){};

		//~GeoPt(void){	};

		inline GeoPt( const Real fX, const Real fY, const Real fZ ) : x( fX ), y( fY ), z( fZ ){};       

        inline explicit GeoPt( const Real afCoordinate[3] )
            : x( afCoordinate[0] ),
              y( afCoordinate[1] ),
              z( afCoordinate[2] )
        {
        }

        inline explicit GeoPt( const int afCoordinate[3] )
        {
            x = (Real)afCoordinate[0];
            y = (Real)afCoordinate[1];
            z = (Real)afCoordinate[2];
        }

        inline explicit GeoPt( const Vec3 &vec3A )
            : x( vec3A.x ), y( vec3A.y ), z( vec3A.z )
        {
        }


        inline explicit GeoPt( Real* const r )
            : x( r[0] ), y( r[1] ), z( r[2] )
        {
        }


		inline Real operator [] ( const size_t i ) const
        {
            assert( i < 3 );

            return *(&x+i);
        }

		inline Real& operator [] ( const size_t i )
        {
            assert( i < 3 );

            return *(&x+i);
        }

		/// Pointer accessor for direct copying
		inline Real* ptr()
		{
			return &x;
		}

		/// Pointer accessor for direct copying
		inline const Real* ptr() const
		{
			return &x;
		}

        /** Assigns the value of the other vector.
            @param
                rkVector The other vector
        */
        inline GeoPt& operator = ( const GeoPt& rkVector )
        {
            x = rkVector.x;
            y = rkVector.y;
            z = rkVector.z;

            return *this;
        }

        inline bool operator == ( const GeoPt& rkVector ) const
        {
            return ( x == rkVector.x && y == rkVector.y && z == rkVector.z );
        }

        inline bool operator != ( const GeoPt& rkVector ) const
        {
            return ( x != rkVector.x || y != rkVector.y || z != rkVector.z );
        }

   		//----------------------------------------------------------------------------
		// ���ߣ�Ƥѧ�� 
		// ���ڣ�2010-06-07 
		// ���ܣ�����λ��������������(����)arithmetic operations
		//============================================================================
		inline GeoPt operator + ( const GeoPt& rkVector ) const
        {
            return GeoPt(
				x + rkVector.x,
                y + rkVector.y,
                z + rkVector.z);
        }

        inline GeoPt operator - ( const GeoPt& rkVector ) const
        {
            return GeoPt(
                x - rkVector.x,
                y - rkVector.y,
                z - rkVector.z);
        }

        inline const GeoPt& operator + () const
        {
            return *this;
        }

        inline GeoPt operator - () const
        {
            return GeoPt(-x, -y, -z);
        }

        // overloaded operators to help GeoPt
        inline friend GeoPt operator * ( const Real fScalar, const GeoPt& rkVector )
        {
            return GeoPt(
                fScalar * rkVector.x,
                fScalar * rkVector.y,
                fScalar * rkVector.z);
        }

        inline friend GeoPt operator / ( const Real fScalar, const GeoPt& rkVector )
        {
            return GeoPt(
                fScalar / rkVector.x,
                fScalar / rkVector.y,
                fScalar / rkVector.z);
        }

        inline friend GeoPt operator + (const GeoPt& lhs, const Real rhs)
        {
            return GeoPt(
                lhs.x + rhs,
                lhs.y + rhs,
                lhs.z + rhs);
        }

        inline friend GeoPt operator + (const Real lhs, const GeoPt& rhs)
        {
            return GeoPt(
                lhs + rhs.x,
                lhs + rhs.y,
                lhs + rhs.z);
        }

        inline friend GeoPt operator - (const GeoPt& lhs, const Real rhs)
        {
            return GeoPt(
                lhs.x - rhs,
                lhs.y - rhs,
                lhs.z - rhs);
        }

        inline friend GeoPt operator - (const Real lhs, const GeoPt& rhs)
        {
            return GeoPt(
                lhs - rhs.x,
                lhs - rhs.y,
                lhs - rhs.z);
        }

        // arithmetic updates
        inline GeoPt& operator += ( const GeoPt& rkVector )
        {
            x += rkVector.x;
            y += rkVector.y;
            z += rkVector.z;

            return *this;
        }

        inline GeoPt& operator += ( const Real fScalar )
        {
            x += fScalar;
            y += fScalar;
            z += fScalar;
            return *this;
        }

        inline GeoPt& operator -= ( const GeoPt& rkVector )
        {
            x -= rkVector.x;
            y -= rkVector.y;
            z -= rkVector.z;

            return *this;
        }
	};


	//--------------------------------------------------------------------------------
	// ���ߣ�Ƥѧ�� 
	// ���ڣ�2010-10-11 
	// ˵����ʱ����λ��
	//================================================================================

	class BW_CAL_API GeoPtTime
	{
	public:
		double	tm;
		GeoPt	lle;
		
		GeoPtTime():tm( 0.0 ), lle( 0.0, 0.0, 0.0){};

		GeoPtTime( double fT, GeoPt vec ):tm( fT ), lle(vec){};
		
		GeoPtTime( double fT, double lat, double longi, double elev )
			:tm( fT ),	lle( lat, longi, elev )	{}
	};


	//--------------------------------------------------------------------------------
	// ���ߣ�Ƥѧ�� 
	// ���ڣ�2011-06-22 
	// ˵������Χ԰����(GEOLLE)
	//================================================================================

	class BW_CAL_API GeoCylinder
	{
	public:
		GeoCylinder();
		GeoCylinder(const GeoPt& centerGeo,Degree radiusGeo,Real radiusHgt);
		GeoCylinder(const GeoCylinder& cylinder );		

		virtual ~GeoCylinder();

		inline bool Valid() const ;
		inline void Set(const GeoPt& center,Degree radiusGeo, Real radiusHgt);

		inline bool     IsContainGeolle( GeoPt pt);
		inline void		SetCenter(const GeoPt& center) { m_centerGeo = center; m_bFlag = true;}
		inline const	GeoPt& GetCenter() const { return m_centerGeo; }

		inline void		SetRadiusGeo(Degree radius) { m_radiusGeo = radius; m_bFlag = true; }
		inline Degree	GetRadiusGeo() const { return m_radiusGeo; }

		inline void		SetRadiusHgt(Real height) { m_radiusHgt = height; m_bFlag = true; }
		inline Real		GetRadiusHgt() const { return m_radiusHgt; }

		// ��־��⣺�Ƿ��Ѿ��޸���(�Ƿ��Ѿ������)
		inline bool     IsFlag(){ return m_bFlag ;} ;

		// ��־λ��λ
		inline void     ResetFlag(){ m_bFlag = false;} ;

	protected:
		GeoPt		m_centerGeo;
		Degree		m_radiusGeo;
		Real		m_radiusHgt;

	private:
		bool		m_bFlag;
	};

	//////////////////////////////////////////////////////////////////////////
	// л����, 2017-05-18

	// վ�ĵ�ƽ������ϵ: 
	// r--��վ�ĵ�ֱ�߾��룬��λ m��Az--��λ�ǣ����汱�ļнǣ�˳ʱ��Ϊ����-180~180����λ �ȣ�El--�ߵͽǣ�����Ϊ����-90~90����λ ��
	class BW_CAL_API TopocentricPolar
	{
	public:
		Real r;
		Real Az;
		Real El;
	public:
		TopocentricPolar(): r( 0.0 ), Az( 0.0 ), El( 0.0 ){};

		inline TopocentricPolar( const Real fr, const Real fAz, const Real fEl ) : r( fr ), Az( fAz ), El( fEl ){};       

		inline TopocentricPolar& operator = ( const TopocentricPolar& val )
		{
			r = val.r;
			Az = val.Az;
			El = val.El;

			return *this;
		}
	};

	// վ�ĵ�ƽֱ������ϵ��վ��Ϊԭ�㣬����������ֱ�Ϊx��y��z�ᣬ��������ϵ
	// ���򡢱���������룬��λm
	class BW_CAL_API TopoCentric 
	{
	public:
		double easting;
		double northing;
		double upping;

	public:
		TopoCentric(): easting( 0.0 ), northing( 0.0 ), upping( 0.0 ){};

		inline TopoCentric( const Real fe, const Real fn, const Real fu ) : easting( fe ), northing( fn ), upping( fu ){};     

		inline TopoCentric& operator = ( const TopoCentric& val )
		{
			easting = val.easting;
			northing = val.northing;
			upping = val.upping;

			return *this;
		}

		inline TopoCentric operator + ( const TopoCentric& val ) const
		{
			return TopoCentric(
				easting + val.easting,
				northing + val.northing,	
				upping + val.upping);
		}

		inline TopoCentric operator - ( const TopoCentric& val ) const
		{
			return TopoCentric(
				easting - val.easting,
				northing - val.northing,
				upping - val.upping);
		}

		inline const TopoCentric& operator + () const
		{
			return *this;
		}

		inline TopoCentric operator - () const
		{
			return TopoCentric(-easting, -northing, -upping);
		}
	};




}

#endif
