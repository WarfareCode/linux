#ifndef SOFAHDEF
#define SOFAHDEF

/*
**  - - - - - - -
**   s o f a . h
**  - - - - - - -
**
**  Prototype function declarations for SOFA library.
**
**  This file is part of the International Astronomical Union's
**  SOFA (Standards Of Fundamental Astronomy) software collection.
**
**  This revision:   2016 March 10
**
**  SOFA release 2017-04-20
**
**  Copyright (C) 2017 IAU SOFA Board.  See notes at end.
*/

/* Added By Kongshu Xie 20170725
	Export to Dll
	Every Function is added "BWSOFA_C_API" prefix
*/
#ifdef BWSOFA_C_EXPORTS
#define BWSOFA_C_API __declspec(dllexport)
#else
#define BWSOFA_C_API __declspec(dllimport)
#endif
/*----------------*/

#include "sofam.h"
#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Astronomy/Calendars */
int BWSOFA_C_API iauCal2jd(int iy, int im, int id, double *djm0, double *djm);
double BWSOFA_C_API iauEpb(double dj1, double dj2);
void BWSOFA_C_API iauEpb2jd(double epb, double *djm0, double *djm);
double BWSOFA_C_API iauEpj(double dj1, double dj2);
void BWSOFA_C_API iauEpj2jd(double epj, double *djm0, double *djm);
int BWSOFA_C_API iauJd2cal(double dj1, double dj2,
                     int *iy, int *im, int *id, double *fd);
int BWSOFA_C_API iauJdcalf(int ndp, double dj1, double dj2, int iymdf[4]);

/* Astronomy/Astrometry */
void BWSOFA_C_API iauAb(double pnat[3], double v[3], double s, double bm1,
           double ppr[3]);
void BWSOFA_C_API iauApcg(double date1, double date2,
             double ebpv[2][3], double ehp[3],
             iauASTROM *astrom);
void BWSOFA_C_API iauApcg13(double date1, double date2, iauASTROM *astrom);
void BWSOFA_C_API iauApci(double date1, double date2,
             double ebpv[2][3], double ehp[3],
             double x, double y, double s,
             iauASTROM *astrom);
void BWSOFA_C_API iauApci13(double date1, double date2,
              iauASTROM *astrom, double *eo);
void BWSOFA_C_API iauApco(double date1, double date2,
             double ebpv[2][3], double ehp[3],
             double x, double y, double s, double theta,
             double elong, double phi, double hm,
             double xp, double yp, double sp,
             double refa, double refb,
             iauASTROM *astrom);
int BWSOFA_C_API iauApco13(double utc1, double utc2, double dut1,
              double elong, double phi, double hm, double xp, double yp,
              double phpa, double tc, double rh, double wl,
              iauASTROM *astrom, double *eo);
void BWSOFA_C_API iauApcs(double date1, double date2, double pv[2][3],
             double ebpv[2][3], double ehp[3],
             iauASTROM *astrom);
void BWSOFA_C_API iauApcs13(double date1, double date2, double pv[2][3],
               iauASTROM *astrom);
void BWSOFA_C_API iauAper(double theta, iauASTROM *astrom);
void BWSOFA_C_API iauAper13(double ut11, double ut12, iauASTROM *astrom);
void BWSOFA_C_API iauApio(double sp, double theta,
             double elong, double phi, double hm, double xp, double yp,
             double refa, double refb,
             iauASTROM *astrom);
int BWSOFA_C_API iauApio13(double utc1, double utc2, double dut1,
              double elong, double phi, double hm, double xp, double yp,
              double phpa, double tc, double rh, double wl,
              iauASTROM *astrom);
void BWSOFA_C_API iauAtci13(double rc, double dc,
               double pr, double pd, double px, double rv,
               double date1, double date2,
               double *ri, double *di, double *eo);
void BWSOFA_C_API iauAtciq(double rc, double dc, double pr, double pd,
              double px, double rv, iauASTROM *astrom,
              double *ri, double *di);
void BWSOFA_C_API iauAtciqn(double rc, double dc, double pr, double pd,
               double px, double rv, iauASTROM *astrom,
               int n, iauLDBODY b[], double *ri, double *di);
void BWSOFA_C_API iauAtciqz(double rc, double dc, iauASTROM *astrom,
               double *ri, double *di);
int BWSOFA_C_API iauAtco13(double rc, double dc,
              double pr, double pd, double px, double rv,
              double utc1, double utc2, double dut1,
              double elong, double phi, double hm, double xp, double yp,
              double phpa, double tc, double rh, double wl,
              double *aob, double *zob, double *hob,
              double *dob, double *rob, double *eo);
void BWSOFA_C_API iauAtic13(double ri, double di,
               double date1, double date2,
               double *rc, double *dc, double *eo);
void BWSOFA_C_API iauAticq(double ri, double di, iauASTROM *astrom,
              double *rc, double *dc);
void BWSOFA_C_API iauAticqn(double ri, double di, iauASTROM *astrom,
               int n, iauLDBODY b[], double *rc, double *dc);
int BWSOFA_C_API iauAtio13(double ri, double di,
              double utc1, double utc2, double dut1,
              double elong, double phi, double hm, double xp, double yp,
              double phpa, double tc, double rh, double wl,
              double *aob, double *zob, double *hob,
              double *dob, double *rob);
void BWSOFA_C_API iauAtioq(double ri, double di, iauASTROM *astrom,
              double *aob, double *zob,
              double *hob, double *dob, double *rob);
int BWSOFA_C_API iauAtoc13(const char *type, double ob1, double ob2,
              double utc1, double utc2, double dut1,
              double elong, double phi, double hm, double xp, double yp,
              double phpa, double tc, double rh, double wl,
              double *rc, double *dc);
int BWSOFA_C_API  iauAtoi13(const char *type, double ob1, double ob2,
              double utc1, double utc2, double dut1,
              double elong, double phi, double hm, double xp, double yp,
              double phpa, double tc, double rh, double wl,
              double *ri, double *di);
void  BWSOFA_C_API  iauAtoiq(const char *type,
              double ob1, double ob2, iauASTROM *astrom,
              double *ri, double *di);
void  BWSOFA_C_API  iauLd(double bm, double p[3], double q[3], double e[3],
           double em, double dlim, double p1[3]);
void BWSOFA_C_API   iauLdn(int n, iauLDBODY b[], double ob[3], double sc[3],
            double sn[3]);
void BWSOFA_C_API   iauLdsun(double p[3], double e[3], double em, double p1[3]);
void BWSOFA_C_API   iauPmpx(double rc, double dc, double pr, double pd,
             double px, double rv, double pmt, double pob[3],
             double pco[3]);
int BWSOFA_C_API   iauPmsafe(double ra1, double dec1, double pmr1, double pmd1,
              double px1, double rv1,
              double ep1a, double ep1b, double ep2a, double ep2b,
              double *ra2, double *dec2, double *pmr2, double *pmd2,
              double *px2, double *rv2);
void BWSOFA_C_API   iauPvtob(double elong, double phi, double height, double xp,
              double yp, double sp, double theta, double pv[2][3]);
void  BWSOFA_C_API  iauRefco(double phpa, double tc, double rh, double wl,
              double *refa, double *refb);

/* Astronomy/Ephemerides */
int  BWSOFA_C_API  iauEpv00(double date1, double date2,
             double pvh[2][3], double pvb[2][3]);
int  BWSOFA_C_API  iauPlan94(double date1, double date2, int np, double pv[2][3]);

/* Astronomy/FundamentalArgs */
double  BWSOFA_C_API  iauFad03(double t);
double  BWSOFA_C_API  iauFae03(double t);
double  BWSOFA_C_API  iauFaf03(double t);
double  BWSOFA_C_API  iauFaju03(double t);
double  BWSOFA_C_API  iauFal03(double t);
double BWSOFA_C_API   iauFalp03(double t);
double  BWSOFA_C_API  iauFama03(double t);
double  BWSOFA_C_API  iauFame03(double t);
double  BWSOFA_C_API  iauFane03(double t);
double  BWSOFA_C_API  iauFaom03(double t);
double BWSOFA_C_API   iauFapa03(double t);
double BWSOFA_C_API   iauFasa03(double t);
double BWSOFA_C_API   iauFaur03(double t);
double  BWSOFA_C_API  iauFave03(double t);

/* Astronomy/PrecNutPolar */
void  BWSOFA_C_API  iauBi00(double *dpsibi, double *depsbi, double *dra);
void  BWSOFA_C_API  iauBp00(double date1, double date2,
             double rb[3][3], double rp[3][3], double rbp[3][3]);
void BWSOFA_C_API   iauBp06(double date1, double date2,
             double rb[3][3], double rp[3][3], double rbp[3][3]);
void  BWSOFA_C_API  iauBpn2xy(double rbpn[3][3], double *x, double *y);
void BWSOFA_C_API iauC2i00a(double date1, double date2, double rc2i[3][3]);
void BWSOFA_C_API iauC2i00b(double date1, double date2, double rc2i[3][3]);
void BWSOFA_C_API iauC2i06a(double date1, double date2, double rc2i[3][3]);
void BWSOFA_C_API iauC2ibpn(double date1, double date2, double rbpn[3][3],
               double rc2i[3][3]);
void BWSOFA_C_API iauC2ixy(double date1, double date2, double x, double y,
              double rc2i[3][3]);
void BWSOFA_C_API iauC2ixys(double x, double y, double s, double rc2i[3][3]);
void BWSOFA_C_API iauC2t00a(double tta, double ttb, double uta, double utb,
               double xp, double yp, double rc2t[3][3]);
void BWSOFA_C_API iauC2t00b(double tta, double ttb, double uta, double utb,
               double xp, double yp, double rc2t[3][3]);
void BWSOFA_C_API iauC2t06a(double tta, double ttb, double uta, double utb,
               double xp, double yp, double rc2t[3][3]);
void BWSOFA_C_API iauC2tcio(double rc2i[3][3], double era, double rpom[3][3],
               double rc2t[3][3]);
void BWSOFA_C_API iauC2teqx(double rbpn[3][3], double gst, double rpom[3][3],
               double rc2t[3][3]);
void BWSOFA_C_API iauC2tpe(double tta, double ttb, double uta, double utb,
              double dpsi, double deps, double xp, double yp,
              double rc2t[3][3]);
void BWSOFA_C_API iauC2txy(double tta, double ttb, double uta, double utb,
              double x, double y, double xp, double yp,
              double rc2t[3][3]);
double BWSOFA_C_API iauEo06a(double date1, double date2);
double BWSOFA_C_API iauEors(double rnpb[3][3], double s);
void BWSOFA_C_API iauFw2m(double gamb, double phib, double psi, double eps,
             double r[3][3]);
void BWSOFA_C_API iauFw2xy(double gamb, double phib, double psi, double eps,
              double *x, double *y);
void BWSOFA_C_API iauLtp(double epj, double rp[3][3]);
void BWSOFA_C_API iauLtpb(double epj, double rpb[3][3]);
void BWSOFA_C_API iauLtpecl(double epj, double vec[3]);
void BWSOFA_C_API iauLtpequ(double epj, double veq[3]);
void BWSOFA_C_API iauNum00a(double date1, double date2, double rmatn[3][3]);
void BWSOFA_C_API iauNum00b(double date1, double date2, double rmatn[3][3]);
void BWSOFA_C_API iauNum06a(double date1, double date2, double rmatn[3][3]);
void BWSOFA_C_API iauNumat(double epsa, double dpsi, double deps, double rmatn[3][3]);
void BWSOFA_C_API iauNut00a(double date1, double date2, double *dpsi, double *deps);
void BWSOFA_C_API iauNut00b(double date1, double date2, double *dpsi, double *deps);
void BWSOFA_C_API iauNut06a(double date1, double date2, double *dpsi, double *deps);
void BWSOFA_C_API iauNut80(double date1, double date2, double *dpsi, double *deps);
void BWSOFA_C_API iauNutm80(double date1, double date2, double rmatn[3][3]);
double BWSOFA_C_API iauObl06(double date1, double date2);
double BWSOFA_C_API iauObl80(double date1, double date2);
void BWSOFA_C_API iauP06e(double date1, double date2,
             double *eps0, double *psia, double *oma, double *bpa,
             double *bqa, double *pia, double *bpia,
             double *epsa, double *chia, double *za, double *zetaa,
             double *thetaa, double *pa,
             double *gam, double *phi, double *psi);
void BWSOFA_C_API iauPb06(double date1, double date2,
             double *bzeta, double *bz, double *btheta);
void BWSOFA_C_API iauPfw06(double date1, double date2,
              double *gamb, double *phib, double *psib, double *epsa);
void BWSOFA_C_API iauPmat00(double date1, double date2, double rbp[3][3]);
void BWSOFA_C_API iauPmat06(double date1, double date2, double rbp[3][3]);
void BWSOFA_C_API iauPmat76(double date1, double date2, double rmatp[3][3]);
void BWSOFA_C_API iauPn00(double date1, double date2, double dpsi, double deps,
             double *epsa,
             double rb[3][3], double rp[3][3], double rbp[3][3],
             double rn[3][3], double rbpn[3][3]);
void BWSOFA_C_API iauPn00a(double date1, double date2,
              double *dpsi, double *deps, double *epsa,
              double rb[3][3], double rp[3][3], double rbp[3][3],
              double rn[3][3], double rbpn[3][3]);
void BWSOFA_C_API iauPn00b(double date1, double date2,
              double *dpsi, double *deps, double *epsa,
              double rb[3][3], double rp[3][3], double rbp[3][3],
              double rn[3][3], double rbpn[3][3]);
void BWSOFA_C_API iauPn06(double date1, double date2, double dpsi, double deps,
             double *epsa,
             double rb[3][3], double rp[3][3], double rbp[3][3],
             double rn[3][3], double rbpn[3][3]);
void BWSOFA_C_API iauPn06a(double date1, double date2,
              double *dpsi, double *deps, double *epsa,
              double rb[3][3], double rp[3][3], double rbp[3][3],
              double rn[3][3], double rbpn[3][3]);
void BWSOFA_C_API iauPnm00a(double date1, double date2, double rbpn[3][3]);
void BWSOFA_C_API iauPnm00b(double date1, double date2, double rbpn[3][3]);
void BWSOFA_C_API iauPnm06a(double date1, double date2, double rnpb[3][3]);
void BWSOFA_C_API iauPnm80(double date1, double date2, double rmatpn[3][3]);
void BWSOFA_C_API iauPom00(double xp, double yp, double sp, double rpom[3][3]);
void BWSOFA_C_API iauPr00(double date1, double date2,
             double *dpsipr, double *depspr);
void BWSOFA_C_API iauPrec76(double date01, double date02,
               double date11, double date12,
               double *zeta, double *z, double *theta);
double BWSOFA_C_API iauS00(double date1, double date2, double x, double y);
double BWSOFA_C_API iauS00a(double date1, double date2);
double BWSOFA_C_API iauS00b(double date1, double date2);
double BWSOFA_C_API iauS06(double date1, double date2, double x, double y);
double BWSOFA_C_API iauS06a(double date1, double date2);
double BWSOFA_C_API iauSp00(double date1, double date2);
void BWSOFA_C_API iauXy06(double date1, double date2, double *x, double *y);
void BWSOFA_C_API iauXys00a(double date1, double date2,
               double *x, double *y, double *s);
void BWSOFA_C_API iauXys00b(double date1, double date2,
               double *x, double *y, double *s);
void BWSOFA_C_API iauXys06a(double date1, double date2,
               double *x, double *y, double *s);

/* Astronomy/RotationAndTime */
double BWSOFA_C_API iauEe00(double date1, double date2, double epsa, double dpsi);
double BWSOFA_C_API iauEe00a(double date1, double date2);
double BWSOFA_C_API iauEe00b(double date1, double date2);
double BWSOFA_C_API iauEe06a(double date1, double date2);
double BWSOFA_C_API iauEect00(double date1, double date2);
double BWSOFA_C_API iauEqeq94(double date1, double date2);
double BWSOFA_C_API iauEra00(double dj1, double dj2);
double BWSOFA_C_API iauGmst00(double uta, double utb, double tta, double ttb);
double BWSOFA_C_API iauGmst06(double uta, double utb, double tta, double ttb);
double BWSOFA_C_API iauGmst82(double dj1, double dj2);
double BWSOFA_C_API iauGst00a(double uta, double utb, double tta, double ttb);
double BWSOFA_C_API iauGst00b(double uta, double utb);
double BWSOFA_C_API iauGst06(double uta, double utb, double tta, double ttb,
                double rnpb[3][3]);
double BWSOFA_C_API iauGst06a(double uta, double utb, double tta, double ttb);
double BWSOFA_C_API iauGst94(double uta, double utb);

/* Astronomy/SpaceMotion */
int BWSOFA_C_API iauPvstar(double pv[2][3], double *ra, double *dec,
              double *pmr, double *pmd, double *px, double *rv);
int BWSOFA_C_API iauStarpv(double ra, double dec,
              double pmr, double pmd, double px, double rv,
              double pv[2][3]);

/* Astronomy/StarCatalogs */
void BWSOFA_C_API iauFk52h(double r5, double d5,
              double dr5, double dd5, double px5, double rv5,
              double *rh, double *dh,
              double *drh, double *ddh, double *pxh, double *rvh);
void BWSOFA_C_API iauFk5hip(double r5h[3][3], double s5h[3]);
void BWSOFA_C_API iauFk5hz(double r5, double d5, double date1, double date2,
              double *rh, double *dh);
void BWSOFA_C_API iauH2fk5(double rh, double dh,
              double drh, double ddh, double pxh, double rvh,
              double *r5, double *d5,
              double *dr5, double *dd5, double *px5, double *rv5);
void BWSOFA_C_API iauHfk5z(double rh, double dh, double date1, double date2,
              double *r5, double *d5, double *dr5, double *dd5);
int BWSOFA_C_API iauStarpm(double ra1, double dec1,
              double pmr1, double pmd1, double px1, double rv1,
              double ep1a, double ep1b, double ep2a, double ep2b,
              double *ra2, double *dec2,
              double *pmr2, double *pmd2, double *px2, double *rv2);

/* Astronomy/EclipticCoordinates */
void BWSOFA_C_API iauEceq06(double date1, double date2, double dl, double db,
               double *dr, double *dd);
void BWSOFA_C_API iauEcm06(double date1, double date2, double rm[3][3]);
void BWSOFA_C_API iauEqec06(double date1, double date2, double dr, double dd,
               double *dl, double *db);
void BWSOFA_C_API iauLteceq(double epj, double dl, double db, double *dr, double *dd);
void BWSOFA_C_API iauLtecm(double epj, double rm[3][3]);
void BWSOFA_C_API iauLteqec(double epj, double dr, double dd, double *dl, double *db);

/* Astronomy/GalacticCoordinates */
void BWSOFA_C_API iauG2icrs(double dl, double db, double *dr, double *dd);
void BWSOFA_C_API iauIcrs2g(double dr, double dd, double *dl, double *db);

/* Astronomy/GeodeticGeocentric */
int BWSOFA_C_API iauEform(int n, double *a, double *f);
int BWSOFA_C_API iauGc2gd(int n, double xyz[3],
             double *elong, double *phi, double *height);
int BWSOFA_C_API iauGc2gde(double a, double f, double xyz[3],
              double *elong, double *phi, double *height);
int BWSOFA_C_API iauGd2gc(int n, double elong, double phi, double height,
             double xyz[3]);
int BWSOFA_C_API iauGd2gce(double a, double f,
              double elong, double phi, double height, double xyz[3]);

/* Astronomy/Timescales */
int BWSOFA_C_API iauD2dtf(const char *scale, int ndp, double d1, double d2,
             int *iy, int *im, int *id, int ihmsf[4]);
int BWSOFA_C_API iauDat(int iy, int im, int id, double fd, double *deltat);
double BWSOFA_C_API iauDtdb(double date1, double date2,
               double ut, double elong, double u, double v);
int BWSOFA_C_API iauDtf2d(const char *scale, int iy, int im, int id,
             int ihr, int imn, double sec, double *d1, double *d2);
int BWSOFA_C_API iauTaitt(double tai1, double tai2, double *tt1, double *tt2);
int BWSOFA_C_API iauTaiut1(double tai1, double tai2, double dta,
              double *ut11, double *ut12);
int BWSOFA_C_API iauTaiutc(double tai1, double tai2, double *utc1, double *utc2);
int BWSOFA_C_API iauTcbtdb(double tcb1, double tcb2, double *tdb1, double *tdb2);
int BWSOFA_C_API iauTcgtt(double tcg1, double tcg2, double *tt1, double *tt2);
int BWSOFA_C_API iauTdbtcb(double tdb1, double tdb2, double *tcb1, double *tcb2);
int BWSOFA_C_API iauTdbtt(double tdb1, double tdb2, double dtr,
             double *tt1, double *tt2);
int BWSOFA_C_API iauTttai(double tt1, double tt2, double *tai1, double *tai2);
int BWSOFA_C_API iauTttcg(double tt1, double tt2, double *tcg1, double *tcg2);
int BWSOFA_C_API iauTttdb(double tt1, double tt2, double dtr,
             double *tdb1, double *tdb2);
int BWSOFA_C_API iauTtut1(double tt1, double tt2, double dt,
             double *ut11, double *ut12);
int BWSOFA_C_API iauUt1tai(double ut11, double ut12, double dta,
              double *tai1, double *tai2);
int BWSOFA_C_API iauUt1tt(double ut11, double ut12, double dt,
             double *tt1, double *tt2);
int BWSOFA_C_API iauUt1utc(double ut11, double ut12, double dut1,
              double *utc1, double *utc2);
int BWSOFA_C_API iauUtctai(double utc1, double utc2, double *tai1, double *tai2);
int BWSOFA_C_API iauUtcut1(double utc1, double utc2, double dut1,
              double *ut11, double *ut12);

/* VectorMatrix/AngleOps */
void BWSOFA_C_API iauA2af(int ndp, double angle, char *sign, int idmsf[4]);
void BWSOFA_C_API iauA2tf(int ndp, double angle, char *sign, int ihmsf[4]);
int BWSOFA_C_API iauAf2a(char s, int ideg, int iamin, double asec, double *rad);
double BWSOFA_C_API iauAnp(double a);
double BWSOFA_C_API iauAnpm(double a);
void BWSOFA_C_API iauD2tf(int ndp, double days, char *sign, int ihmsf[4]);
int BWSOFA_C_API iauTf2a(char s, int ihour, int imin, double sec, double *rad);
int BWSOFA_C_API iauTf2d(char s, int ihour, int imin, double sec, double *days);

/* VectorMatrix/BuildRotations */
void BWSOFA_C_API iauRx(double phi, double r[3][3]);
void BWSOFA_C_API iauRy(double theta, double r[3][3]);
void BWSOFA_C_API iauRz(double psi, double r[3][3]);

/* VectorMatrix/CopyExtendExtract */
void BWSOFA_C_API iauCp(double p[3], double c[3]);
void BWSOFA_C_API iauCpv(double pv[2][3], double c[2][3]);
void BWSOFA_C_API iauCr(double r[3][3], double c[3][3]);
void BWSOFA_C_API iauP2pv(double p[3], double pv[2][3]);
void BWSOFA_C_API iauPv2p(double pv[2][3], double p[3]);

/* VectorMatrix/Initialization */
void BWSOFA_C_API iauIr(double r[3][3]);
void BWSOFA_C_API iauZp(double p[3]);
void BWSOFA_C_API iauZpv(double pv[2][3]);
void BWSOFA_C_API iauZr(double r[3][3]);

/* VectorMatrix/MatrixOps */
void BWSOFA_C_API iauRxr(double a[3][3], double b[3][3], double atb[3][3]);
void BWSOFA_C_API iauTr(double r[3][3], double rt[3][3]);

/* VectorMatrix/MatrixVectorProducts */
void BWSOFA_C_API iauRxp(double r[3][3], double p[3], double rp[3]);
void BWSOFA_C_API iauRxpv(double r[3][3], double pv[2][3], double rpv[2][3]);
void BWSOFA_C_API iauTrxp(double r[3][3], double p[3], double trp[3]);
void BWSOFA_C_API iauTrxpv(double r[3][3], double pv[2][3], double trpv[2][3]);

/* VectorMatrix/RotationVectors */
void BWSOFA_C_API iauRm2v(double r[3][3], double w[3]);
void BWSOFA_C_API iauRv2m(double w[3], double r[3][3]);

/* VectorMatrix/SeparationAndAngle */
double BWSOFA_C_API iauPap(double a[3], double b[3]);
double BWSOFA_C_API iauPas(double al, double ap, double bl, double bp);
double BWSOFA_C_API iauSepp(double a[3], double b[3]);
double BWSOFA_C_API iauSeps(double al, double ap, double bl, double bp);

/* VectorMatrix/SphericalCartesian */
void BWSOFA_C_API iauC2s(double p[3], double *theta, double *phi);
void BWSOFA_C_API iauP2s(double p[3], double *theta, double *phi, double *r);
void BWSOFA_C_API iauPv2s(double pv[2][3],
             double *theta, double *phi, double *r,
             double *td, double *pd, double *rd);
void BWSOFA_C_API iauS2c(double theta, double phi, double c[3]);
void BWSOFA_C_API iauS2p(double theta, double phi, double r, double p[3]);
void BWSOFA_C_API iauS2pv(double theta, double phi, double r,
             double td, double pd, double rd,
             double pv[2][3]);

/* VectorMatrix/VectorOps */
double BWSOFA_C_API iauPdp(double a[3], double b[3]);
double BWSOFA_C_API iauPm(double p[3]);
void BWSOFA_C_API iauPmp(double a[3], double b[3], double amb[3]);
void BWSOFA_C_API iauPn(double p[3], double *r, double u[3]);
void BWSOFA_C_API iauPpp(double a[3], double b[3], double apb[3]);
void BWSOFA_C_API iauPpsp(double a[3], double s, double b[3], double apsb[3]);
void BWSOFA_C_API iauPvdpv(double a[2][3], double b[2][3], double adb[2]);
void BWSOFA_C_API iauPvm(double pv[2][3], double *r, double *s);
void BWSOFA_C_API iauPvmpv(double a[2][3], double b[2][3], double amb[2][3]);
void BWSOFA_C_API iauPvppv(double a[2][3], double b[2][3], double apb[2][3]);
void BWSOFA_C_API iauPvu(double dt, double pv[2][3], double upv[2][3]);
void BWSOFA_C_API iauPvup(double dt, double pv[2][3], double p[3]);
void BWSOFA_C_API iauPvxpv(double a[2][3], double b[2][3], double axb[2][3]);
void BWSOFA_C_API iauPxp(double a[3], double b[3], double axb[3]);
void BWSOFA_C_API iauS2xpv(double s1, double s2, double pv[2][3], double spv[2][3]);
void BWSOFA_C_API iauSxp(double s, double p[3], double sp[3]);
void BWSOFA_C_API iauSxpv(double s, double pv[2][3], double spv[2][3]);

#ifdef __cplusplus
}
#endif

#endif

/*----------------------------------------------------------------------
**
**  Copyright (C) 2017
**  Standards Of Fundamental Astronomy Board
**  of the International Astronomical Union.
**
**  =====================
**  SOFA Software License
**  =====================
**
**  NOTICE TO USER:
**
**  BY USING THIS SOFTWARE YOU ACCEPT THE FOLLOWING SIX TERMS AND
**  CONDITIONS WHICH APPLY TO ITS USE.
**
**  1. The Software is owned by the IAU SOFA Board ("SOFA").
**
**  2. Permission is granted to anyone to use the SOFA software for any
**     purpose, including commercial applications, free of charge and
**     without payment of royalties, subject to the conditions and
**     restrictions listed below.
**
**  3. You (the user) may copy and distribute SOFA source code to others,
**     and use and adapt its code and algorithms in your own software,
**     on a world-wide, royalty-free basis.  That portion of your
**     distribution that does not consist of intact and unchanged copies
**     of SOFA source code files is a "derived work" that must comply
**     with the following requirements:
**
**     a) Your work shall be marked or carry a statement that it
**        (i) uses routines and computations derived by you from
**        software provided by SOFA under license to you; and
**        (ii) does not itself constitute software provided by and/or
**        endorsed by SOFA.
**
**     b) The source code of your derived work must contain descriptions
**        of how the derived work is based upon, contains and/or differs
**        from the original SOFA software.
**
**     c) The names of all routines in your derived work shall not
**        include the prefix "iau" or "sofa" or trivial modifications
**        thereof such as changes of case.
**
**     d) The origin of the SOFA components of your derived work must
**        not be misrepresented;  you must not claim that you wrote the
**        original software, nor file a patent application for SOFA
**        software or algorithms embedded in the SOFA software.
**
**     e) These requirements must be reproduced intact in any source
**        distribution and shall apply to anyone to whom you have
**        granted a further right to modify the source code of your
**        derived work.
**
**     Note that, as originally distributed, the SOFA software is
**     intended to be a definitive implementation of the IAU standards,
**     and consequently third-party modifications are discouraged.  All
**     variations, no matter how minor, must be explicitly marked as
**     such, as explained above.
**
**  4. You shall not cause the SOFA software to be brought into
**     disrepute, either by misuse, or use for inappropriate tasks, or
**     by inappropriate modification.
**
**  5. The SOFA software is provided "as is" and SOFA makes no warranty
**     as to its use or performance.   SOFA does not and cannot warrant
**     the performance or results which the user may obtain by using the
**     SOFA software.  SOFA makes no warranties, express or implied, as
**     to non-infringement of third party rights, merchantability, or
**     fitness for any particular purpose.  In no event will SOFA be
**     liable to the user for any consequential, incidental, or special
**     damages, including any lost profits or lost savings, even if a
**     SOFA representative has been advised of such damages, or for any
**     claim by any third party.
**
**  6. The provision of any version of the SOFA software under the terms
**     and conditions specified herein does not imply that future
**     versions will also be made available under the same terms and
**     conditions.
*
**  In any published work or commercial product which uses the SOFA
**  software directly, acknowledgement (see www.iausofa.org) is
**  appreciated.
**
**  Correspondence concerning SOFA software should be addressed as
**  follows:
**
**      By email:  sofa@ukho.gov.uk
**      By post:   IAU SOFA Center
**                 HM Nautical Almanac Office
**                 UK Hydrographic Office
**                 Admiralty Way, Taunton
**                 Somerset, TA1 2DN
**                 United Kingdom
**
**--------------------------------------------------------------------*/
