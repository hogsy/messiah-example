
//note: remember the rebound/gravity is done properly for bullets
// ie:  rebound(140); == 140/100=1.4
//      only the first parameter for gravity is needed


ActorHeader(GenericWeaponPage)
{
		type(_ActorStaticObj);
		sharemaps(-2);			//signifies: Don't free in FreeUnusedActors
		file("pc\actors\weapons\machgun\machgun.dcr");
}

ActorHeader(GenericWeaponPage2)
{
		type(_ActorStaticObj);
		sharemaps(-2);			//signifies: Don't free in FreeUnusedActors
		file("pc\actors\turret\dcr\turret.dcr");
}


ActorHeader(BulletBatteryHeader)
{
		file("pc\actors\weapons\battery\battery.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_ClassBullet|_ClassPickup);
		rebound(0);
		ColSphereSize(21);
		gravity(0.5,-127);
		InventoryType(_AmmoBattery);
		//Inventory(1);
		ColMask(_COLexplosion);

		Health(DamageGrenade)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletPumpGunShellHeader)
{
		file("pc\actors\weapons\pumpshel\pumpsh2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(1);
		rebound(140);
		ColSphereSize(1);
		gravity(0.7,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoUnLimited);

		Health(DamageNoDamage)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletMachineGunShellHeader)
{
		//file("pc\actors\weapons\pumpshel\pumpshel.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(1);
		rebound(0);
		ColSphereSize(1);
		gravity(1,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoUnLimited);

		Health(DamageNoDamage)
		AIsight(100,1);
		AIstrenght(100);
}



ActorHeader(BulletShockWaveHeader)
{
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(60);		//can't be respawned for 60 ticks
		rebound(0);
		ColSphereSize(700);
		gravity(0,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoShockWave);

		Health(DamageBlastDamage)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletExplosionHeader)
{
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(0);
		rebound(0);
		ColSphereSize(300);
		gravity(0,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoExplosion);

		Health(DamageBlastDamage)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletDistortionHeader)
{
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(0);
		rebound(0);
		ColSphereSize(350);
		gravity(0,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoExplosion);

		Health(DamageDistortion)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletTorchHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(4);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoUnLimited);

		Health(DamageTorch)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletFlameThrowerHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(1);
		rebound(0);
		ColSphereSize(16);
		gravity(0,-127);
		ColMask(_COLfire);
		InventoryType(_AmmoGasoLine);

		Health(DamageFlameThrower)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletBuzzSawHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(4);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoUnLimited);

		Health(DamageBuzzSaw)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletPumpGunHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(35);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoPumpGun);

		Health(DamagePumpGun)			//max amount of damage
		AIsight(100,1);					//nr of frames to decrease damage over, when falloff of damage starts
		AIstrenght(85);					//how much damage to keep each frame (in percent)
}
ActorHeader(BulletPumpGunHeader2)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(35);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoPumpGun);

		Health(DamagePumpGun2);
		AIsight(100,1);
		AIstrenght(95);
}


ActorHeader(BulletHarpoonHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\spear\spear2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(60);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsingleattach);
		InventoryType(_AmmoHarpoon);

		Health(DamageHarpoon)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletPAKGunHeader)
{
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(16);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoPAKGun);

		Health(DamagePAKGun)
		AIsight(100,1);
		AIstrenght(85);
}

ActorHeader(BulletMaimerHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\maimstar\maimsta2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(6);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoMaimer);

		Health(DamageMaimerGun)
		AIsight(100,1);
		AIstrenght(90);
}

ActorHeader(BulletBettyHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\maimstar\maimbett.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(1);
		rebound(0);
		ColSphereSize(8);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoMaimer);

		Health(DamageMaimerGun)
		AIsight(100,1);
		AIstrenght(95);
}

ActorHeader(BulletABeastMachineGunHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(4);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLkillsall);
		InventoryType(_AmmoMachineGun);

		Health(DamageABeastMachineGun)
		AIsight(100,1);
		AIstrenght(100);
}


ActorHeader(BulletSubGirlMachineGunHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(4);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoMachineGun);

		Health(DamageSubGirlMachineGun)
		AIsight(100,1);
		AIstrenght(85);
}


ActorHeader(BulletMachineGunHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(2);
		rebound(0);
		ColSphereSize(4);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoMachineGun);

		Health(DamageMachineGun)
		AIsight(100,1);
		AIstrenght(85);
}


ActorHeader(BulletBazookaHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\bazooka\missile2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(50);
		rebound(0);
		ColSphereSize(16);
		gravity(0,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoBazooka);

		Health(DamageBazooka)
		AIsight(100,1);
		AIstrenght(95);
}

ActorHeader(BulletMaserHeader)
{
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		//file("pc\actors\weapons\bazooka\missile2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(1);
		rebound(0);
		ColSphereSize(16);
		gravity(0,-127);
		ColMask(_COLelectricity);
		InventoryType(_AmmoUnLimited);

		Health(DamageMaser)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletTurretHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\bazooka\missile2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(0);
		rebound(0);
		ColSphereSize(16);
		gravity(0,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoBazooka);

		Health(DamageBazooka)
		AIsight(100,1);
		AIstrenght(95);
}

ActorHeader(BulletPriestHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(40);
		rebound(0);
		ColSphereSize(16);
		gravity(0,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoBazooka);

		Health(DamageBazooka)
		AIsight(100,1);
		AIstrenght(95);
}

ActorHeader(BulletSubGirlGrenadeHeader)
{
		file("pc\actors\weapons\rndgren\rndgren.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(16);
		rebound(150);
		ColSphereSize(16);
		gravity(1,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoGrenade);
		//Inventory(1);

		Health(DamageGrenade)
		AIsight(256,1);
		AIstrenght(100);
}

ActorHeader(BulletGrenadeHeader)
{
		file("pc\actors\weapons\rndgren\rndgren.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(8);
		rebound(150);
		ColSphereSize(16);
		gravity(0.5,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoGrenade);
		//Inventory(1);

		Health(DamageGrenade)
		AIsight(256,1);
		AIstrenght(100);
}

ActorHeader(BulletDistortionGrenadeHeader)
{
		file("pc\actors\weapons\rnddist\rnddist.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(90);
		rebound(150);
		ColSphereSize(16);
		gravity(0.5,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoGrenadeDistortion);
		//Inventory(1);

		Health(DamageNoDamage)
		AIsight(256,1);
		AIstrenght(100);
}

ActorHeader(BulletGrenadeConcusionHeader)
{
		file("pc\actors\weapons\rndgren\rndgren.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(8);
		rebound(0);
		ColSphereSize(16);
		gravity(0.5,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoGrenade);
		//Inventory(1);

		Health(DamageGrenade)
		AIsight(256,1);
		AIstrenght(100);
}

ActorHeader(BulletGrenadeStickEmHeader)
{
		file("pc\actors\weapons\rndstikc\rndstikc.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(8);
		rebound(0);
		ColSphereSize(16);
		gravity(0.5,-127);
		ColMask(_COLsingleattach|_COLexplosion);
		InventoryType(_AmmoGrenade);
		//Inventory(1);

		Health(DamageGrenade)
		AIsight(256,1);
		AIstrenght(100);
}

ActorHeader(BulletGrenadeJumpBettyHeader)
{
		file("pc\actors\weapons\minejump\minejmp2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(8);
		rebound(150);
		ColSphereSize(16);
		gravity(0.5,-127);
		ColMask(_COLexplosion);
		InventoryType(_AmmoGrenade);
		//Inventory(1);

		Health(DamageGrenade)
		AIsight(256,1);
		AIstrenght(100);
}

ActorHeader(BulletAutoCannonHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(8);
		rebound(0);
		ColSphereSize(1);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoAutoCannon);

		Health(DamageAutoCannon)
		AIsight(100,1);
		AIstrenght(100);
}


ActorHeader(BulletShellTurretHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		//file("pc\actors\gunturret\prj\original\gtbullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(4);
		rebound(0);
		ColSphereSize(6);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoAutoCannon);

		Health(DamageAutoCannon)
		AIsight(100,1);
		AIstrenght(100);
}


ActorHeader(BulletGunTurretNoAIHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		//file("pc\actors\gunturret\prj\original\gtbullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(25);
		rebound(0);
		ColSphereSize(1);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoBazooka);

		Health(DamageBazooka)
		AIsight(100,1);
		AIstrenght(100);
}

ActorHeader(BulletGunTurretHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		//file("pc\actors\gunturret\prj\original\gtbullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(4);
		rebound(0);
		ColSphereSize(1);
		gravity(0,-127);
		ColMask(_COLsmallbullet);
		InventoryType(_AmmoGunTurret);

		Health(DamageGunTurret)
		AIsight(100,1);
		AIstrenght(100);
}


ActorHeader(BulletHolyHeader)
{
		//file("pc\actors\weapons\rndgren\rndgren.dcr");
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		//file("pc\actors\gunturret\prj\original\gtbullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(4);
		rebound(0);
		ColSphereSize(1);
		gravity(0,-127);
		ColMask(_COLholy);
		InventoryType(_AmmoHoly);

		Health(DamageHolyDamage)
		AIsight(100,1);
		AIstrenght(90);
}

ActorHeader(BulletRingOfFire)
{
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSBullet);
		respawndelay(60);		//can't be respawned for 60 ticks
		rebound(0);
		ColSphereSize(700);
		gravity(0,-127);
		ColMask(_COLAllExceptHoly);
		InventoryType(_AmmoExplosion);

		Health(DamageSatansRingPiece)
		AIsight(100,1);
		AIstrenght(100);
}
