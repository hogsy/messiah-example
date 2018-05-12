
#ifndef	_WEAPONDAMAGE_
#define	_WEAPONDAMAGE_



#define	SNIPER_HUD	0
#define	ROCKET_HUD	1

//----------------------------------------------------------------------------

#define	_BulletNoAttach			0
#define	_BulletAttach			1

//----------------------------------------------------------------------------

#define DamageInsideFire		10		//Subtracted every frame
#define DamageInsideSteam		10		//Subtracted every frame
#define DamageOnFire			100		//Subtracted every 32 frames  (ie: avg. every 1 second)
#define DamageOnSpear			200		//Subtracted every 32 frames  (ie: avg. every 1 second)
#define DamageAfterFire			3		//subtracted every frame

#define DamageSteamDuration		30		//how long steamed character is disabled in frames

#define	DamageElectric			1000

#define DamageABeastMachineGun	1000
#define DamageSubGirlMachineGun	600

#define DamageMachineGun		300
#define DamageAutoCannon		500
#define DamageGunTurret			3000

#define DamageBazooka			1000	//torg, tweak 	//5000	//on top of DamageBlastDamage
#define DamageGrenade			1000	//torg, tweak 	//3000	//on top of DamageBlastDamage
#define DamageHarpoon			500		//In addition to DamageOnSpear

#define	DamagePumpGun			1500	//primary damage
#define	DamagePumpGun2			500		//up to 5X this damage is possible

#define	DamagePAKGun			600
#define DamageMaimerGun			500

#define DamageHarpoon2			200		//Damage when already on spear or when actor cant be attached, when moving with actor
#define	DamageTorch				50

#define	DamageShockWaveDamage	3000	//torg, tweak 
#define	DamageBlastDamage		8000	//torg, tweak 
#define	DamageNoDamage			0
#define DamageFlameThrower		200
#define	DamageBuzzSaw			150

#define DamageHeavyCannon		1000
#define DamageSecurityDroid		10

#define	DamageMaxDamage			32767

#define RadiationKillTime		150		//number of frames in radiation before you die (from max health)

#define	DamageMaser				10000

#define	DamageHolyDamage		250
#define	DamageSatansRingPiece	5000

#define	DamageRadioactive		40
													 
#define	DamageCrawlDamage		5

#define	DamageDistortion		750		//they might get hit twice if unlucky

//---------------------------------------------------------------------------- stickem grenade states

#define	StickEmNotReady			0
#define	StickEmReady			1
#define	StickEmExploding		2

#define	JumpingBettyInActive	0
#define	JumpingBettyActive		1

//----------------------------------------------------------------------------

//the amount of ammo contained in an ammo box for each weapon
#define	_PickupLimitGrenade		5
#define	_PickupLimitHarpoon		4
#define	_PickupLimitGasoline	50
#define	_PickupLimitBazooka		5
#define	_PickupLimitMachineGun	50
#define	_PickupLimitMaimer		20
#define	_PickupLimitPumpGun		10
#define	_PickupLimitNoAmmo		0
#define	_PickupLimitUnlimited	255
#define	_PickupLimitPAKGun		50
#define	_PickupLimitAmmo		10
#define	_PickupLimitPAK			40
#define	_PickupLimitMaser		255

//the max limit for each weapon
#define	_LimitGrenade			10
#define	_LimitHarpoon			8
#define	_LimitGasoline			200
#define	_LimitBazooka			10
#define	_LimitMachineGun		150
#define	_LimitMaimer			100
#define	_LimitPumpGun			40
#define	_LimitNoAmmo			0
#define	_LimitUnlimited			255
#define	_LimitPAKGun			100
#define	_LimitAmmo				100
#define	_LimitPAK				100
#define	_LimitMaser				255

//the start amount for each weapon
#define	_InitialGrenade			10
#define	_InitialHarpoon			8
#define	_InitialGasoline		200
#define	_InitialBazooka			10
#define	_InitialMachineGun		150
#define	_InitialMaimer			100
#define	_InitialPumpGun			20
#define	_InitialNoAmmo			0
#define	_InitialUnlimited		255
#define	_InitialPAKGun			100
#define	_InitialAmmo			100			//pickup, overwritten by PickupLimit
#define	_InitialAmmoGrenade		4			//pickup, overwritten by PickupLimit
#define	_InitialPAK				100
#define	_InitialMaser			255

//type identifiers
#define	_AmmoExplosion			1			//special case
#define	_AmmoHarpoon			2
#define	_AmmoGasoline			3
#define	_AmmoBazooka			4
#define	_AmmoMachineGun			5
#define	_AmmoMaser				6
#define	_AmmoMaimer				7
#define	_AmmoPumpGun			8
#define	_AmmoAutoCannon			9
#define	_AmmoUnLimited			10
#define	_AmmoPAKGun				11
#define	_AmmoAmmo				12
#define	_AmmoNoAmmo				13
#define	_AmmoBattery			14
#define	_AmmoHoly				15
#define _AmmoGunTurret			16
#define _AmmoShockWave			17
//NOTE: ALL THE GRENADES MUST BE AT THE END OF THIS LIST, WITH "_AmmoGrenade" BEING THE FIRST !
#define	_AmmoGrenade			18			//can explode nearby objects
#define	_AmmoGrenadeABeast		19			//can explode nearby objects
#define	_AmmoGrenadeStickEm		20			//can explode nearby objects
#define	_AmmoGrenadeConcussion	21
#define	_AmmoGrenadeDistortion	22
#define	_AmmoGrenadeBetty		23
#define	_AmmoGrenadeSubGirl		24			//can explode nearby objects

#endif
