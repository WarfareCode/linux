#ifndef _HJSIM_HYCGF_H_
#define _HJSIM_HYCGF_H_
#pragma once

#if !defined(_WIN32)
#define HYCGF_API
#elif defined(HYCGF_EXPORTS)
#define HYCGF_API __declspec(dllexport)
#else
#define HYCGF_API __declspec(dllimport)
#endif

#ifdef _DEBUG
#pragma comment(lib, "HYCgfd.lib")
#else
#pragma comment(lib, "HYCgfr.lib")
#endif

// hdose  .h Files
#include "hdose.h"

//BwCal  .h Files
#include "CAL/BwCalExp.h"

//HYCGF  .h Files

//		// preDef
#include "CGF/AbstractMoveModel.h"
#include "CGF/AcousticSensor.h"
#include "CGF/Actuator.h"
#include "CGF/Area.h"
#include "CGF/AttitudeCtrlOper.h"
#include "CGF/BallisticMissileESR.h"
#include "CGF/CGFDS.h"
#include "CGF/Circle.h"
#include "CGF/CollisionEvent.h"
#include "CGF/CommanderESR.h"
#include "CGF/CommStateEvent.h"
#include "CGF/Controller.h"
#include "CGF/ControlObject.h"
#include "CGF/ConsoleEvt.h"
#include "CGF/ConsoleEvtConductor.h"
#include "CGF/CreateObjRequest.h"
#include "CGF/CreateObjResult.h"
#include "CGF/CreateSatOrbitEvent.h"
#include "CGF/Cruise.h"
#include "CGF/CruiseMissileESR.h"
#include "CGF/DataRange.h"
#include "CGF/Disembark.h"
#include "CGF/Ellipse.h"
#include "CGF/EntityCreateEvent.h"
#include "CGF/EntityExitEvent.h"
#include "CGF/ESM.h"
#include "CGF/ExplosionEvent.h"
#include "CGF/FacilityESR.h"
#include "CGF/FixedWingESR.h"
#include "CGF/Follow.h"
#include "CGF/GeneralEvt.h"
#include "CGF/GroundVehicleESR.h"
#include "CGF/IFF.h"
#include "CGF/InfraredDataStruct.h"
#include "CGF/JammerOper.h"
#include "CGF/LandingOn.h"
#include "CGF/LaserSensor.h"
#include "CGF/LaunchBomb.h"
#include "CGF/LaunchCanon.h"
#include "CGF/LaunchChaff.h"
#include "CGF/LaunchFakeTarget.h"
#include "CGF/LaunchMissile.h"
#include "CGF/LaunchTorpedo.h"
#include "CGF/LaunchWeapon.h"
#include "CGF/LayoutMine.h"
#include "CGF/LifeFormESR.h"
#include "CGF/LoggerCtrl.h"
#include "CGF/MagneticSensor.h"
#include "CGF/MissileESR.h"
#include "CGF/MissileWarheadESR.h"
#include "CGF/Model.h"
#include "CGF/MoveAlong.h"
#include "CGF/MoveTo.h"
#include "CGF/MunitionESR.h"
#include "CGF/OrbitData.h"
#include "CGF/Patrol.h"
#include "CGF/Phaseline.h"
#include "CGF/Polygon.h"
#include "CGF/Radar.h"
#include "CGF/RadioEvt.h"
#include "CGF/RCSDataStruct.h"
#include "CGF/Recall.h"
#include "CGF/Rectangle.h"
#include "CGF/RegulateMoveState.h"
#include "CGF/RemoveObjRequest.h"
#include "CGF/RemoveObjResult.h"
#include "CGF/RotaryWingESR.h"
#include "CGF/Route.h"
#include "CGF/SatelliteESR.h"
#include "CGF/ScnCtrl.h"
#include "CGF/ScnProfile.h"
#include "CGF/Sensor.h"
#include "CGF/SensorOper.h"
#include "CGF/SensorScanEvent.h"
#include "CGF/SetData.h"
#include "CGF/SimCtrl.h"

#include "CGF/SimpleRadar.h"

#include "CGF/Sonar.h"
#include "CGF/SpaceESR.h"
#include "CGF/StateRepository.h"
#include "CGF/SubSurfaceESR.h"
#include "CGF/SurfaceESR.h"
#include "CGF/TakeOff.h"
#include "CGF/TargetIrradiateEvent.h"
#include "CGF/TargetLossEvent.h"
#include "CGF/TargetParaEvent.h"
#include "CGF/TargetTrackingEvent.h"
#include "CGF/Task.h"
#include "CGF/ThermalSensor.h"
#include "CGF/TorpedoESR.h"
#include "CGF/Utility.h"
#include "CGF/VisualSensor.h"
#include "CGF/Wait.h"
#include "CGF/WayPoint.h"
#include "CGF/WeaponLaunchEvent.h"

#include "CGF/BackEngineStateEvt.h"
#include "CGF/RequestBackEngineStateEvt.h"

#endif