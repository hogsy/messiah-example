

//file("pc\actors\weapons\rktlnchr\rktlnch.dcr");


ActorHeader(WeaponPakHeader)
{
		file("pc\actors\Weapons\pak\mod\dcrfinal\pak.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_ClassWeapon);

		NrFaces(1000,1000,1000);		//40

		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoPAKGun);
		InventoryLimit(_LimitPAKGun);
		PickupLimit(_PickupLimitPAKGun);
		Inventory(_InitialPAK)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(40);
		AIRange(0,5000);
		AIfov(18);
		AIsight(5000,0);
		respawn(0);
		ColMask(_COLsmallbullet);
}

ActorHeader(WeaponBatteryHeader)
{
		file("pc\actors\weapons\batgrabr\batgrabr.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_ClassWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoBattery);
		InventoryLimit(1);
		PickupLimit(1);
		Inventory(_InitialNoAmmo)
		AIclass(_AIclasslightgun);
		AIfriendmask(_AIclassworker|_AIclassscientist);
		AIstrenght(0);				//30
		AIRange(0,1000);
		AIfov(0);
		AIsight(100,0);
		respawn(0);
}

ActorHeader(WeaponBatonHeader)
{
		file("pc\actors\weapons\baton\baton.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_ClassWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoUnLimited);
		InventoryLimit(_LimitUnLimited);
		PickupLimit(_PickupLimitUnLimited);
		Inventory(_InitialNoAmmo)
		AIclass(_AIclasslightgun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(30);
		AIRange(0,1000);
		AIfov(0);
		AIsight(100,0);
		respawn(0);
}

//grenade ammo box
ActorHeader(WeaponAmmoGrenadesHeader)
{
		file("pc\actors\weapons\ammo\ammog.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_ClassAmmoPickup);
		gravity( -20, -20 );
		ColSphereSize(40);
		PossesionSphereOffset(0);
		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitAmmo);
		PickupLimit(_PickupLimitAmmo);
		Inventory(_InitialAmmoGrenade)
		AIclass(_AIclasslightgun);
		AIstrenght(30);
		AIRange(0,20000);
		AIfov(0);
		AIsight(100,0);
		respawn(900);
}

//all weapons ammo box
ActorHeader(WeaponAmmoHeader)
{
		file("pc\actors\weapons\ammo\ammo.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_ClassAmmoPickup);
		gravity( -20, -20 );
		ColSphereSize(40);
		PossesionSphereOffset(0);
		InventoryType(_AmmoAmmo);
		InventoryLimit(_LimitAmmo);
		PickupLimit(_PickupLimitAmmo);
		Inventory(_InitialAmmo)
		AIclass(_AIclasslightgun);
		AIstrenght(30);
		AIRange(0,1000);
		AIfov(0);
		AIsight(100,0);
		respawn(900);
}

ActorHeader(WeaponPumpGunHeader)
{
		file("pc\actors\weapons\pumpgun\pumpgun.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		PossesionSphereOffset(30);
		ColSphereSize(15);
		InventoryType(_AmmoPumpGun);
		InventoryLimit(_LimitPumpGun);
		PickupLimit(_PickupLimitPumpGun);
		Inventory(_InitialPumpGun)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(80);
		AIRange(0,10000);
		AIfov(18);
		AIsight(5000,0);
		respawn(0);
		ColMask(_COLsmallbullet);
}


ActorHeader(WeaponFakeHeader)
{
		file("pc\actors\weapons\fakebullet\bullet.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity(0,0);
		ColSphereSize(30);
		PossesionSphereOffset(30);
		InventoryType(_AmmoMachineGun);
		InventoryLimit(_LimitUnlimited);
		PickupLimit(_PickupLimitUnlimited);
		Inventory(_InitialUnlimited);
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassAbeast|_AIclasssubgirl);
		AIstrenght(100);
		AIRange(0,10000);
		AIfov(18);
		AIsight(5000,0);
		respawn(0);
		ColMask(_COLsmallbullet);
}

ActorHeader(WeaponMachineGunHeader)
{
		file("pc\actors\weapons\machgun\machgun_n.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(30);
		PossesionSphereOffset(30);
		InventoryType(_AmmoMachineGun);
		InventoryLimit(_LimitMachineGun);
		PickupLimit(_PickupLimitMachineGun);
		Inventory(_InitialMachineGun)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(60);
		AIRange(0,10000);
		AIfov(18);
		AIsight(5000,0);
		respawn(0);
		ColMask(_COLsmallbullet);
}

ActorHeader(WeaponMaimerHeader)
{
		file("pc\actors\weapons\maimer\maimer.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoMaimer);
		InventoryLimit(_LimitMaimer);
		PickupLimit(_PickupLimitMaimer);
		Inventory(_InitialMaimer)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(30);
		AIRange(0,10000);
		AIfov(18);
		AIsight(5000,0);
		respawn(0);
		ColMask(_COLsmallbullet);
}

ActorHeader(WeaponTorchHeader)
{
		file("pc\actors\weapons\torch\torch.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(40);
		PossesionSphereOffset(30);
		InventoryType(_AmmoUnLimited);
		InventoryLimit(_LimitUnlimited);
		PickupLimit(_PickupLimitUnLimited);
		Inventory(_InitialUnlimited)
		AIclass(_AIclassCloseRange);
		AIfriendmask(_AIclassWorker);
		AIstrenght(0);	//was 5 but needs to be 0 for tha AI to stop attacking welding workers
		AIRange(200,300);
		AIfov(1);
		AIsight(100,0);
		respawn(0);
		ColMask(_COLsmallbullet);
}

ActorHeader(WeaponBazookaHeader)
{
		file("pc\actors\weapons\bazooka\bazooka3.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoBazooka);
		InventoryLimit(_LimitBazooka);
		PickupLimit(_PickupLimitBazooka);
		Inventory(_InitialBazooka)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(100);
		AIRange(500,15000);			//blastradius is 256 on bazooka
		AIfov(18);
		AIsight(15000,0);
		respawn(0);
		ColMask(_COLexplosion);
}

ActorHeader(WeaponMaserHeader)
{
		file("pc\actors\weapons\maser\maser2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoUnLimited);
		InventoryLimit(_LimitUnlimited);
		PickupLimit(_PickupLimitUnlimited);
		Inventory(_InitialUnlimited)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclasscop|_AIclassChot|_AIclassdweller|_AIclassscientist);
		AIstrenght(100);
		AIRange(300,10000);
		AIfov(18);
		AIsight(5000,0);
		respawn(0);
		ColMask(_COLelectricity);
}

ActorHeader(WeaponHarpoonHeader)
{
		file("pc\actors\weapons\speargun\speargn2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoHarpoon);
		InventoryLimit(_LimitHarpoon);
		PickupLimit(_PickupLimitHarpoon);
		Inventory(_InitialHarpoon)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(100);
		AIRange(300,10000);
		AIfov(18);
		AIsight(5000,0);
		respawn(0);
		ColMask(_COLsingleattach);
}

ActorHeader(WeaponFlameThrowerHeader)
{
		file("pc\actors\weapons\flthrow\flthrow2.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(33);
		PossesionSphereOffset(30);
		InventoryType(_AmmoGasoline);
		InventoryLimit(_LimitGasoline);
		PickupLimit(_PickupLimitGasoline);
		Inventory(_InitialGasoline)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(80);
		AIRange(200,300);
		AIfov(18);
		AIsight(1000,0);
		respawn(0);
		ColMask(_COLfire);
}

ActorHeader(WeaponBuzzSawHeader)
{
		//file("pc\actors\weapons\meatcutr\meatcut2.dcr");
		file("pc\actors\weapons\meatcutr\meatcut3.dcr");
		sharemaps(GenericWeaponPage);
		type(_ActorStaticObj);
		class(_CLASSWeapon);

		NrFaces(1000,1000,1000);		//39

		gravity( -20, -20 );
		ColSphereSize(45);
		PossesionSphereOffset(30);
		InventoryType(_AmmoUnLimited);
		InventoryLimit(_LimitUnLimited);
		PickupLimit(_PickupLimitUnLimited);
		Inventory(_InitialUnLimited)
		AIclass(_AIclassCloseRange);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller|_AIClassScientist);
		AIstrenght(50);
		AIRange(200,300);
		AIfov(1);
		AIsight(300,0);
		respawn(0);
		ColMask(_COLsmallbullet);
}

/*
ActorHeader(WeaponSubGirlRocketPackHeader)
{
		file("pc\actors\weapons\submissle\jetrockt\dcr\jetrockt1-1.dcr");
		type(_ActorStaticObj);
		class(_CLASSWeapon);		//_ClassSubGirlPack
}
ActorHeader(WeaponSubGirlPackHeader)
{
		file("pc\actors\weapons\submissle\jetpak\dcr\jetpak1-1.dcr");
		type(_ActorStaticObj);
		class(_CLASSWeapon);		//_ClassSubGirlPack
}
*/

ActorHeader(WeaponSubGirlRocketPackHeader)
{
		file("pc\actors\weapons\submissle\jetrockt\dcr\jetrockt1-1.dcr");
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoBazooka);
		InventoryLimit(_LimitNoAmmo);
		PickupLimit(_PickupLimitNoAmmo);
		Inventory(_InitialNoAmmo)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(100);
		AIRange(500,15000);			//blastradius is 256 on bazooka
		AIfov(18);
		AIsight(15000,0);
		respawn(0);
}


ActorHeader(WeaponSubGirlPackHeader)
{
		file("pc\actors\weapons\submissle\jetpak\dcr\jetpak1-1.dcr");
		type(_ActorStaticObj);
		class(_CLASSWeapon);
		gravity( -20, -20 );
		ColSphereSize(15);
		PossesionSphereOffset(30);
		InventoryType(_AmmoBazooka);
		InventoryLimit(_LimitNoAmmo);
		PickupLimit(_PickupLimitNoAmmo);
		Inventory(_InitialNoAmmo)
		AIclass(_AIclassHipGun);
		AIfriendmask(_AIclassCop|_AIclassChot|_AIclassdweller);
		AIstrenght(100);
		AIRange(500,15000);			//blastradius is 256 on bazooka
		AIfov(18);
		AIsight(15000,0);
		respawn(0);
}




//----------------- cut here --------------------

action(WeaponSubGirlRocketPackOpen)
{
		file("pc\actors\weapons\submissle\xxx\open.ske",100,off);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		intforloop(off);
		shadow(off);
		move(0,0,0);
		nomove(on);
		gravity(on);
		connections(WeaponSubGirlRocketPackOpen);
}

action(WeaponSubGirlRocketPackClosed)
{
		file("pc\actors\weapons\submissle\xxx\closed.ske",100,off);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		intforloop(off);
		shadow(off);
		move(0,0,0);
		nomove(off);
		gravity(on);
		connections(WeaponSubGirlRocketPackClosed);
}



//----------------- cut here --------------------


action(WeaponPakIdle)
{
		file("pc\actors\Weapons\Pak\xxx\PakOff.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		intforloop(off);
		shadow(off);
		move(0,0,0);
		nomove(on);
		gravity(on);
		connections(WeaponPakIdle);
}

action(WeaponPakSpin)
{
		file("pc\actors\Weapons\Pak\xxx\PakSpin.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		intforloop(off);
		shadow(off);
		move(0,0,0);
		nomove(on);
		gravity(on);
		connections(WeaponPakSpin);
}

action(WeaponBuzzSawOff)
{
		file("pc\actors\Weapons\meatcutr\xxx\meatoff.ske",100,on);
		break(on);
		gravity(on);
		connections(WeaponBuzzSawOff);
		shadow(off);
		trigger(_allDIR);
		move(0,0,0);
		offset(0);
		nomove(on);
}
action(WeaponBuzzSawIdle)
{
		file("pc\actors\Weapons\meatcutr\xxx\meatidle.ske",100,on);
		break(on);
		gravity(on);
		connections(WeaponBuzzSawIdle);
		shadow(off);
		trigger(_allDIR);
		move(0,0,0);
		offset(30);
		nomove(on);
}
action(WeaponBuzzSawRev)
{
		file("pc\actors\Weapons\meatcutr\xxx\meatrev.ske",100,on);
		break(on);
		gravity(on);
		connections(WeaponBuzzSawRev);
		shadow(off);
		trigger(_allDIR);
		move(0,0,0);
		offset(4);
		nomove(on);
}
action(WeaponBuzzSawCut)
{
		file("pc\actors\Weapons\meatcutr\xxx\meatcut.ske",100,on);
		break(on);
		gravity(on);
		connections(WeaponBuzzSawCut);
		shadow(off);
		trigger(_allDIR);
		move(0,0,0);
		offset(4);
		nomove(off);
}






