#ifndef __OBJDEFINES_H__
#define __OBJDEFINES_H__


#define	_SXObjDontRecieveLight		0x1
#define	_SXObjEXP					0x2
#define	_SXObjExplodeAmmoGrenade	0x4
#define	_SXObjIsMorphTarget			0x8
#define	_SXObjHasKFMorph			0x10
#define	_SXObjGouraudOnly			0x20
#define	_SXObjExplodeAmmo			0x40
#define	_SXObjExplodeBattery		0x80
#define	_SXObjSmallExplode			0x100
#define	_SXObjDynamicObj			0x200		//
#define	_SXObjExplodeMajor			0x400
#define	_SXObjGlass					0x800
#define	_SXObjExplode				0x1000
#define	_SXObjGouraudColorObj		0x2000	//this seems to be unused? nope, it's used by rened
#define	_SXObjCollisionOff			0x4000
#define	_SXObjInvisible				0x8000	//the last bit for rened
#define	_SXObjHasLooped				0x10000
#define	_SXObjBulletHit				0x20000
#define	_SXObjRadialEnable			0x40000
#define	_SXObjUseCopyOfVertexes		0x80000
#define	_SXObjNoTarget				0x100000
#define	_SXObjUnityMatrix			0x200000
#define	_SXObjDualParseObject		0x400000
#define	_SXObjEventOccured			0x800000
#define	_SXObjActive				0x1000000

#define	_SXObjShouldTrack			(_SXObjExplodeAmmoGrenade|_SXObjExplodeAmmo|_SXObjSmallExplode|_SXObjDynamicObj|_SXObjGlass|_SXObjExplode|_SXObjExplodeBattery|_SXObjExplodeMajor)


#endif
