/*
    Characters that have special grenade types or start with grenades:

	Medium Cop          - 3 second fuse grenade
	Heavy Cop           - Stickum Grenade
	Riot Cop            - Concussion Grenade
	Domina              - Distortion Grenade
	Gun Commander       - Distortion Grenade
	Chots w/trenchcosts - Jumping Betty
	Armoured Behemoth   - explode on impact grenade

    NOTE: any character not listed above, upon picking up a grenade ammo box will be given 3 second fuse grenades *only*
*/


ActorHeader(bobHeader)
{
		file("pc\actors\bob\mod\test\bob.dcr");
//		file("pc\actors\bob\mod\dcrfinal\new\bob.dcr");
		gravity( 0, 0 );
		control(_playeronecon);
		follow(on);
		footbones(20,24);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASSangel);
		ColSphereSize(40);		//If changing, change the #define for BobSphereSize
		ColSphereOffset(10);
		ColFeetSphereSize(30);
		ColFeetSphereOffset(0);
		Health(6000);					//xxx, was 3000, was 4000 resistant little bugger in't he!
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)
		InventoryType(_AmmoNoAmmo);
		InventoryLimit(_LimitNoAmmo);
		PickupLimit(_PickupLimitNoAmmo);
		Inventory(_InitialNoAmmo);

		NrFaces(18400,13500,5100);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.2);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		AIclass(_AIclassangel|_AIclassmale|_AIclassSpecial);
		AIfriendmask(_AIclassangel|_AIclassanimal);
		AIfov(800);
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);
}

ActorHeader(EvilBobHeader)
{
		file("pc\actors\EvilBob\Mod\DCRFinal\new\EvilBob.dcr");
		gravity( -2, -20 );
		footbones(20,24);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASSangel);
		ColSphereSize(40);		//If changing, change the #define for BobSphereSize
		ColSphereOffset(10);
		ColFeetSphereSize(30);
		ColFeetSphereOffset(0);
		Health(6000);					//xxx, was 3000, was 4000 resistant little bugger in't he!
		ColMask(0)
		ColValues(0,0,0,0,0,0,0,0);
		InventoryType(_AmmoNoAmmo);
		InventoryLimit(_LimitNoAmmo);
		PickupLimit(_PickupLimitNoAmmo);
		Inventory(_InitialNoAmmo);

		NrFaces(5100,4100,1900);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,112,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,112,192,16,64);
		BodyPartSizes(8,  0,192,192,64,64);
		BodyPartSizes(9,  0,128,192,64,64);
		
		AIclass(_AIclassEvil|_AIclassangel|_AIclassmale);
		AIfriendmask(_AIclassangel|_AIclassSatan|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(0);
}

ActorHeader(BarmanHeader)
{
		file("pc\actors\barman\mod\dcrfinal\new\barman.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassCop);
		ColSphereSize(115);
		ColFeetSphereSize(65);
		ColFeetSphereOffset(-44);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);

		Health(2500)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(9600,7200,2800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassbarpeople|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}

ActorHeader(ScientistHeader)
{
		//file("pc\actors\scientst\dcr\scient03.dcr");
		file("pc\actors\scientst\mod\DCRfinal\scientist.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		NrFaces(9000,7000,3000);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.85);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);


		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		AIclass(_AIclassscientist|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassdweller|_AIclassprost|_AIclassanimal|_AIclassAbeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}

ActorHeader(VictimFeMaleHeader)
{
		file("pc\actors\victimfemale\mod\DCRfinal\vicfemale.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-40);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(100);
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(6800,5400,2500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassEvil|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(1);
		AIsight(10,0);
		AIstrenght(20);
}



ActorHeader(VictimMaleHeader)
{
		file("pc\actors\victimmale\mod\DCRfinal\vicmale.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(100)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(6500,5400,2500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassEvil|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(1);
		AIsight(1,0);
		AIstrenght(20);
}


ActorHeader(LightCopHeader)
{
		file("pc\actors\copl\mod\dcrfinal\test\coplight.dcr");
		//file("pc\actors\copl\dcr\focus\coplight.dcr");
		//file("pc\actors\copl\dcr\new\nlcop09.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(15700,11600,4300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);


		AIclass(_AIclasscop|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast|_AIclassbarpeople);
		AIenemymask1(_AIclassSubgirl);
		AIenemymask2(_AIclassChot);
		AIenemymask3(_AIclassAngel);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}

ActorHeader(CopLSitHeader)
{
		file("pc\actors\copl\mod\dcrfinal\test\coplight.dcr");
		//file("pc\actors\copl\dcr\focus\coplight.dcr");
		//file("pc\actors\copl\dcr\new\nlcop09.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(55);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-0);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(15700,11600,4300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);

		AIclass(_AIclasscop|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast|_AIclassbarpeople);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}

ActorHeader(MedicHeader)
{
		file("pc\actors\medic\mod\dcrfinal\medic.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassMedic);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(6400,5000,2000);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);


		AIclass(_AIclassscientist|_AIclassmedic|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassbarpeople|_AIclassdroid|_AIclassscientist|_AIclassmedic|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}

ActorHeader(HeavyCopHeader)
{
		//file("pc\actors\copm\dcr\focus\copmed.dcr");
		//file("pc\actors\coph\dcr\new\nhcop06.dcr");
		file("pc\actors\coph\mod\dcrfinal\coph.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(7000)
		ColMask(_COLAll)
		ColValues(100,70,70,70,10,0,100,70)

		InventoryType(_AmmoGrenadeStickEm);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(8)

		NrFaces(5200,4300,1900);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);

		AIclass(_AIclasscop|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast|_AIclassbarpeople);
		AIenemymask1(_AIclassSubgirl);
		AIenemymask2(_AIclassChot);
		AIenemymask3(_AIclassAngel);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(70);
}

ActorHeader(MedCopHeader)
{
		file("pc\actors\copm\mod\dcrfinal\copmed.dcr");
		//file("pc\actors\copm\dcr\focus\copmed.dcr");
		//file("pc\actors\copm\dcr\new\nmcop13.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(6000)
		ColMask(_COLAll)
		ColValues(100,80,80,80,10,0,100,80)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(4)

		NrFaces(6400,5100,2300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		AIclass(_AIclasscop|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast|_AIclassbarpeople);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(60);
}

ActorHeader(RadiationWorkerHeader)
{
		//file("pc\actors\nuketek\dcr\nuktek01.dcr");
		//file("pc\actors\nuketek\dcr\nektek.dcr");

		file("pc\actors\nuketek\mod\dcred\nuketek.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);

/*		ColSphereSize(105);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
*/
		ColSphereSize(105);
		ColSphereOffset(0);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-45);

		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(4300,3600,1600);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.8);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,112,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,112,192,16,64);
		BodyPartSizes(8,  0,192,192,64,64);
		BodyPartSizes(9,  0,128,192,64,64);

		scale(0.09);

		AIclass(_AIclassscientist|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}

ActorHeader(WorkerHeader)
{
		file("pc\actors\welder\mod\dcrfinal\new\welder.dcr");
		//file("pc\actors\welder\dcr\welder03.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);

/*		ColSphereSize(105);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
*/
		ColSphereSize(105);
		ColSphereOffset(4);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-41);

		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(8000,6400,2800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);

		scale(0.087);

		AIclass(_AIclassworker|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassbarpeople|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}

ActorHeader(WorkerKneelHeader)
{
		file("pc\actors\welder\mod\dcrfinal\new\welder.dcr");
		//file("pc\actors\welder\dcr\welder03.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(105);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(1000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(8000,6400,2800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);

		scale(0.09);

		AIclass(_AIclassworker|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}

ActorHeader(WelderHeader)
{
		file("pc\actors\welder\dcr\focus\gabriel.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);

/*		ColSphereSize(105);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
*/
		ColSphereSize(105);
		ColSphereOffset(7);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-38);


		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(8000,6400,2800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		scale(0.07);

		AIclass(_AIclassworker|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}

ActorHeader(ChotHeader)
{
		file("pc\actors\chot\mod\dcrfinal\chot1.dcr");
		//file("pc\actors\chot\dcr\new\nwchot1d.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(5900,4700,2100);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.85);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclasschot|_AIclassmale);
		AIfriendmask(_AIclasschot|_AIclassdroid|_AIclassanimal);
		AIenemymask1(_AIclassCop);
		AIenemymask2(_AIclassAngel);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}


ActorHeader(ChotSPHeader)  // chot with suspenders
{
		//file("pc\actors\sp\dcr\chot2sp.dcr");
		file("pc\actors\chot3CT\mod\dcr\new2\chot3.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(5200,4300,1900);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);



		AIclass(_AIclasschot|_AIclassmale);
		AIfriendmask(_AIclasschot|_AIclassdroid|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}


ActorHeader(ChotCTHeader)  // chot closed trench
{
		//file("pc\actors\chot\dcr\new\nwchot1d.dcr");
		//file("pc\actors\chot3CT\dcr\chotCT.dcr");

		file("pc\actors\chot3CT\mod\dcr\new2\chot3.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenadeBetty);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(4);

		NrFaces(5200,4300,1900);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.8);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclasschot|_AIclassmale);
		AIfriendmask(_AIclasschot|_AIclassdroid|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}

ActorHeader(ChotMOTHeader) // mask, open trench
{
		//file("pc\actors\chot5ms\dcr\chot5ms.dcr");
		//file("pc\actors\chot4ot\dcr\new\chotOT02.dcr");
		file("pc\actors\chot5\mod\dcrfinal\new\chot5.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenadeBetty);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(4);

		NrFaces(4800,4000,2100);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.72);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclasschot|_AIclassmale);
		AIfriendmask(_AIclasschot|_AIclassdroid|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}

ActorHeader(Dweller1Header)
{
		file("pc\actors\Dwellr1\mod\dcred\dweller1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(4700,3800,1800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassdweller|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}

ActorHeader(Dweller1SitHeader)
{
		file("pc\actors\Dwellr1\mod\dcred\dweller1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(55);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-16);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(4700,3800,1800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassdweller|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}

ActorHeader(Dweller2Header)
{
		file("pc\actors\Dwellr2\Mod\DCRFinal\Dwellr2.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(6500,5000,2200);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassdweller|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}

ActorHeader(Dweller2SitHeader)
{
		file("pc\actors\Dwellr2\Mod\DCRFinal\Dwellr2.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(55);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-16);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(6200,5000,2200);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassdweller|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}

ActorHeader(Dweller3Header)
{
		file("pc\actors\Dwellr3\mod\finalDCR\dweller3.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(7200,5600,2500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassdweller|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}

ActorHeader(Dweller3SitHeader)
{
		file("pc\actors\Dwellr3\mod\finalDCR\dweller3.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(55);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-16);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(7200,5600,2500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassdweller|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}

ActorHeader(ProstituteHeader)
{
		file("pc\actors\prost1\mod\finaldcr\new2\prost1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassProstitute);
//		ColSphereSize(115);
//		ColFeetSphereSize(65);
//		ColFeetSphereOffset(-54);

		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(6300,4900,2300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);


		AIclass(_AIclassprost|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}

ActorHeader(Prost1SitHeader)
{
		file("pc\actors\prost1\mod\finaldcr\new2\prost1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassProstitute);
		ColSphereSize(50);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-14);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(6300,4900,2300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,16,32);
		BodyPartSizes(8,  0,208,192,16,32);
		BodyPartSizes(6,  0,224,192,16,32);
		BodyPartSizes(6,  0,240,192,16,32);
		BodyPartSizes(6,  0,192,224,16,32);
		BodyPartSizes(6,  0,208,224,16,32);
		BodyPartSizes(6,  0,224,224,16,32);
		BodyPartSizes(6,  0,240,224,16,32);



		AIclass(_AIclassprost|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}

ActorHeader(HungHeader)
{
		file("pc\actors\hung\mod\dcred\hung.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(110);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(9000,6500,2500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		//AIclass(_AIclassprost|_AIclassmale);
		AIclass(_AIclassprost|_AIclassfemale|_AIclassSpecial);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}

ActorHeader(DominaHeader)
{
		file("pc\actors\domina\mod\dcred\domina.dcr");
		//file("pc\actors\domina\dcr\new\tramp.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassCop);
		ColSphereSize(90);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-43);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenadeDistortion);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialGrenade);

		NrFaces(7500,5800,2300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.75);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);



		AIclass(_AIclasscop|_AIclassfemale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassprost|_AIclassscientist|_AIclassdweller|_AIclassdroid|_AIclassanimal|_AIclassabeast|_AIclassbarpeople);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(80);
}

ActorHeader(FemTestHeader)
{
		//file("pc\actors\domina\dcr\new\ndomina4.dcr");
		file("pc\actors\domina\talk\talk2.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassGeneric);
		ColSphereSize(118);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		AIclass(_AIclasscop);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassanimal);
		AIfov(40);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(1000,0);

		AIclass(_AIclasssubgirl|_AIclassfemale);
		AIfriendmask(_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclasssubgirl|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(0);
}


ActorHeader(subgirl1Header)
{
		//file("pc\actors\subgirl1\dcr\subgirl1.dcr");
		file("pc\actors\subgirl1\mod\DCRfinal\subgirl1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassProstitute);
		ColSphereSize(85);
		ColSphereOffset(-8);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-32);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(70,70,70,70,70,0,100,70)

		InventoryType(_AmmoGrenadeSubGirl);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialGrenade);

		NrFaces(10800,8200,3700);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		AIclass(_AIclasssubgirl|_AIclassfemale);
		AIfriendmask(_AIclasspimp|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclasssubgirl|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(70);
}

ActorHeader(subgirl2Header)
{
		//file("pc\actors\subgirl2\dcr\final.dcr");
		file("pc\actors\subgirl2\mod\DCRfinal\subgirl2.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassProstitute);
		ColSphereSize(85);
		ColSphereOffset(-8);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-32);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(70,70,70,70,70,0,100,70)

		InventoryType(_AmmoGrenadeSubGirl);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialGrenade);

		NrFaces(10900,8400,3700);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		AIclass(_AIclasssubgirl|_AIclassfemale);
		AIfriendmask(_AIclasspimp|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclasssubgirl|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(70);
}

ActorHeader(layyaHeader)
{
		//file("pc\actors\layya\dcr\newlaya2.dcr");
		//file("pc\actors\layya\dcr\new\newlaya3.dcr");
		file("pc\actors\layya\mod\dcrfinal\layya.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassProstitute);
		ColSphereSize(110);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(7800,5900,2400);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.82);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassprost|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}


ActorHeader(ABehemothHeader)
{
		file("pc\actors\abeast\mod\dcrFinal\abeast.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASSbeast);

		ColSphereSize(180);
		ColSphereOffset(-55);
		ColFeetSphereSize(130);
		ColFeetSphereOffset(-95);

		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(65);

		scale(0.2);

		Health(10000);
		ColMask(_COLBeast);
		ColValues(0,0,55,65,100,0,0,0);		//LEAVE _COLelectricity at 100 ...or else you muppet!!!!!

		InventoryType(_AmmoGrenadeABeast);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(10);

		NrFaces(14500,10600,4000);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.7);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);


		AIclass(_AIclassAbeast|_AIclassMale); 
		AIfriendmask(_AIclassAbeast|_AIclasscop|_AIclassanimal|_AIclassscientist|_AIclassworker);
		AIenemymask1(_AIclassSubgirl);
		AIenemymask2(_AIclassChot);
		AIenemymask3(_AIclassAngel);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(80);
}



//************************ OTHER HEADERS

ActorHeader(HaloHeader)
{
		file("pc\actors\halo\dcr\halo.dcr");
		type(_ActorStaticObj);
		class(_ClassHalo);
		sharemaps(GenericWeaponPage);
}

ActorHeader(EvilHaloHeader)
{
		file("pc\actors\halo\mod\evilhalo.dcr");
		type(_ActorStaticObj);
		class(_ClassHalo);
		sharemaps(GenericWeaponPage);
}

ActorHeader(RatHeader)
{
		file("pc\actors\rat\mod\rat.dcr");
		sharemaps(GenericWeaponPage);
		gravity(Char_fall_rate,Char_max_fall);
		type(_ActorStaticObj);
		class(_ClassGeneric);

		NrFaces(1000,1000,1000);		//32

		ColSphereSize(10);
		ColSphereoffset(-10);
		ColFeetSphereSize(10);
		ColFeetSphereOffset(-10);
		PossesionAngle(250);
		PossesionSphereSize(20);
		PossesionSphereOffset(20);
		Health(1000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassanimal);
}

ActorHeader(BirdHeader)
{
		file("pc\actors\dabird\mod\dcrfinal\bird.dcr");
		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorAnimObj);
		class(_ClassGeneric);

		NrFaces(1500,1500,1500);		//196

		ColSphereSize(15);
		ColSphereoffset(3);
		ColFeetSphereSize(15);
		ColFeetSphereOffset(3);
		PossesionAngle(0);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);							//bird can not be posessed
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassanimal);
}


ActorHeader(PossesionBotHeader)
{
		file("pc\actors\weapons\botcom\botcom.dcr");
		//file("pc\actors\weapons\botdef\botdef.dcr");

		//gravity(Char_fall_rate,Char_max_fall);
		gravity(5,5);

		type(_ActorAnimObj);
		class(_ClassDroid);
		ColSphereSize(40);

		NrFaces(1000,1000,1000);		//136

		ColFeetSphereSize(35);
		ColFeetSphereOffset(-5);
		PossesionAngle(180);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);
		Health(2000)
		ColMask(0)
		ColValues(0,0,0,0,0,0,0,0)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(40);
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);

		sharemaps(GenericWeaponPage);
}

ActorHeader(CompanionBotHeader)
{
		file("pc\actors\weapons\combot\combot.dcr");
		//file("pc\actors\weapons\botdef\botdef.dcr");

		gravity(0,0);

		type(_ActorAnimObj);
		class(_ClassDroid);
		ColSphereSize(20);

		NrFaces(1000,1000,1000);		//38

		ColFeetSphereSize(20);
		ColFeetSphereOffset(0);
		PossesionSphereSize(0);
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(80);
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);

		sharemaps(GenericWeaponPage);
}

ActorHeader(DefensiveBotHeader)
{
		file("pc\actors\weapons\botdef\botdef.dcr");
		//file("pc\actors\weapons\botdef\botdef.dcr");

		gravity(0,0);

		type(_ActorAnimObj);
		class(_ClassDroid);

		NrFaces(1000,1000,1000);		//85

		ColSphereSize(25);
		ColFeetSphereSize(25);
		ColFeetSphereOffset(0);
		PossesionSphereSize(0);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(2048);		//omnivision
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(0);

		sharemaps(GenericWeaponPage);
}

ActorHeader(OffensiveBotHeader)
{
		file("pc\actors\weapons\botoff\botoff.dcr");
		//file("pc\actors\weapons\botdef\botdef.dcr");

		gravity(0,0);

		type(_ActorAnimObj);
		class(_ClassDroid);

		NrFaces(1000,1000,1000);		//77

		ColSphereSize(25);
		ColFeetSphereSize(25);
		ColFeetSphereOffset(0);
		PossesionSphereSize(0);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(2048);		//omnivision
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(0);

		sharemaps(GenericWeaponPage);
}

ActorHeader(TransportBotHeader)
{
		file("pc\actors\weapons\batbot\batbot.dcr");
		//file("pc\actors\weapons\botdef\botdef.dcr");

		gravity(0,0);

		type(_ActorStaticObj);
		class(_ClassDroid);

		NrFaces(1000,1000,1000);		//83

		ColSphereSize(25);
		ColFeetSphereSize(25);
		ColFeetSphereOffset(0);
		PossesionSphereSize(0);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);
		Health(2000)
		ColMask(_COLAll)
		ColValues(0,0,0,0,0,0,0,0)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(2048);		//omnivision
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);

		sharemaps(GenericWeaponPage);
}

ActorHeader(MDroid1Header)
{
		file("pc\actors\droid1\dcr\droid1.dcr");

		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorAnimObj);
		class(_ClassDroid);
		ColSphereSize(80);

		NrFaces(1400,1400,1400);		//154

		ColFeetSphereSize(40);
		ColFeetSphereOffset(-40);
		PossesionAngle(180);
		PossesionSphereSize(50);
		PossesionSphereOffset(0);
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(40);
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);
}

ActorHeader(MDroid2Header)
{
		file("pc\actors\droid2\dcr\droid2.dcr");

		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorAnimObj);
		class(_ClassDroid);
		ColSphereSize(50);

		ColFeetSphereSize(50);
		ColFeetSphereOffset(0);
		PossesionAngle(180);
		PossesionSphereSize(50);
		PossesionSphereOffset(0);
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(40);
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);
}

ActorHeader(GunTurretHeader)
{
		file("pc\actors\gunturret\dcr\gturret.dcr");

		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorAnimObj);
		class(_ClassDroid);

		NrFaces(2000,2000,2000);		//40

		ColSphereSize(160);
		ColSphereOffset(155);
		ColFeetSphereSize(0);
		ColFeetSphereOffset(0);

		PossesionAngle(0);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		scale(1);

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(40);
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);
}

ActorHeader(RocketLauncherHeader)
{
		file("pc\actors\rlaunch\dcr\rlaunch.dcr");

		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorAnimObj);
		class(_ClassDroid);

		ColSphereSize(200);
		ColSphereOffset(180);
		ColFeetSphereSize(100);
		ColFeetSphereOffset(50);

		PossesionAngle(330);
		PossesionSphereSize(175);
		PossesionSphereOffset(50);

		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		scale(0.1);

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclassdroid|_AIclassanimal);
		AIfov(40);
		AIhearing(100);
		AIsight(1000,0);
		AIstrenght(0);
}

ActorHeader(ShellTurretHeader)
{
		file("pc\actors\turret\dcr\turret.dcr");
//		sharemaps(GenericWeaponPage2);

		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorAnimObj);
		class(_ClassDroid);
/*
		ColSphereSize(100);
		ColFeetSphereSize(110);
		ColFeetSphereOffset(0);
		PossesionAngle(0);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);
*/
		ColSphereSize(105);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);

		Health(5000);
		ColMask(_COLAll);
		ColValues(100,100,100,100,100,100,100,100);

		scale(0.1);

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassanimal);
		AIfov(800);
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(80);
}

ActorHeader(AutoCannonHeader)
{
		file("pc\actors\weapons\cannon\cannon.dcr");
		sharemaps(GenericWeaponPage);

		gravity(0,0);

		type(_ActorAnimObj);
		class(_ClassModel);

		NrFaces(1000,1000,1000);		//34

		ColSphereSize(80);

		ColFeetSphereSize(40);
		ColFeetSphereOffset(-40);
		PossesionAngle(0);
		PossesionSphereSize(0);
		PossesionSphereOffset(0);
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassanimal);
		AIfov(800);
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}

ActorHeader(TankMatHeader)
{
		file("pc\actors\weapons\tank_mat\lilbul01.dcr");

		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorStaticObj);
		class(_CLASSdroid);
		ColSphereSize(200);

		ColFeetSphereSize(150);
		ColFeetSphereOffset(150);
		PossesionAngle(180);
		PossesionSphereSize(150);
		PossesionSphereOffset(150);
		Health(2000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		AIclass(_AIclassdroid);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassanimal);
		AIfov(90);
		AIhearing(100);
		AIsight(400,0);
		AIstrenght(50);

}

ActorHeader(ForkLiftHeader)
{
		//file("pc\actors\weapons\tank_mat\lilbul02.dcr");
		file("pc\actors\weapons\tank_mat\forklift.dcr");
		gravity(Char_fall_rate,Char_max_fall);

		type(_ActorAnimObj);
		class(_CLASSdroid);
		ColSphereSize(300);

		ColFeetSphereSize(10);
		ColFeetSphereOffset(0);
		PossesionAngle(180);
		PossesionSphereSize(200);
		PossesionSphereOffset(0);
		Health(1000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////


ActorHeader(RiotCopHeader)
{
		file("pc\actors\CopRiot\Mod\DCRFinal\new\CopRiot.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(50,50,50,50,50,50,100,50)

		InventoryType(_AmmoGrenadeConcussion);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialGrenade)

		NrFaces(5700,4500,2100);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		AIclass(_AIclassriotcop|_AIclasscop|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(70);
}


ActorHeader(FemDweller1Header)
{
		file("pc\actors\DwelFem1\Mod\DCRFinal\new\DwellFem1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-40);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(6700,5200,1900);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.7);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		AIclass(_AIclassdweller|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}


ActorHeader(FemDweller2Header)
{
		file("pc\actors\DwelFem2\Mod\DCRFinal\new\DwelFem2.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-40);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(6400,5000,2200);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.8);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassdweller|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(30);
}

ActorHeader(worker2Header)
{
		file("pc\actors\Worker\Mod\DCRFinal\Worker.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);

/*		ColSphereSize(105);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
*/

		ColSphereSize(105);
		ColSphereOffset(4);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-41);

		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(6200,4800,1800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.7);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);

		scale(0.087);

		AIclass(_AIclassworker|_AIclassmale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassanimal|_AIclassabeast);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}


ActorHeader(NunHeader)
{
		file("pc\actors\Nun\Mod\DCRFinal\Nun.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(12300,9300,3500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.8);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassbarpeople|_AIclassprost|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}


ActorHeader(Dancer1Header)
{
		file("pc\actors\Dancer1\Mod\DCRFinal\Dancer1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(6300,4700,2100);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.7);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassbarpeople|_AIclassprost|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}


ActorHeader(Dancer2Header)
{
		file("pc\actors\Dancer3\Mod\DCRFinal\Dancer3.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(10800,8000,3000);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.8);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);


		AIclass(_AIclassbarpeople|_AIclassprost|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}



ActorHeader(PriestHeader)
{
		file("pc\actors\priest\mod\dcrfinal\priest.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
/*
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
*/
		ColSphereSize(2);
		ColSphereOffset(0);
		ColFeetSphereSize(2);
		ColFeetSphereOffset(0);

		PossesionAngle(180);
		PossesionSphereSize(2);
		PossesionSphereOffset(0);

		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		scale(0.2);

		InventoryType(_AmmoNoAmmo);
		InventoryLimit(_LimitNoAmmo);
		PickupLimit(_PickupLimitNoAmmo);
		inventory(_InitialNoAmmo);

		NrFaces(9900,7300,2800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(20000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);


		AIclass(_AIclasspriest|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(20);
}

ActorHeader(BouncerHeader)
{
		file("pc\actors\Bouncer\Mod\DCRFinal\Bouncer.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);

		ColSphereSize(163);				//probably needs some more tweakins'
		ColSphereOffset(5);		//-10
		ColFeetSphereSize(105);
		ColFeetSphereOffset(-52);	//-106

		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(80);

		Health(8000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		scale(0.175);

		NrFaces(7900,6100,2600);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclassbeast|_AIclassBouncer|_AIclassMale);
//		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast);
		AIfriendmask(_AIclassfriendly|_AIClassPimp);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(60);
}


ActorHeader(djkydHeader)
{
		//file("pc\actors\DJ\Mod\DCRFinal\DJkyd.dcr");
		file("pc\actors\DJ\Mod\DCRFinal\new\dj.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(5900,4700,2000);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);


		AIclass(_AIclasspimp|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}


ActorHeader(ProzzyHeader)
{
		file("pc\actors\Xtsee\Mod\DCRFinal\Xtsee.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_ClassProstitute);

		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);

		
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,100,100,100,100,100,100,100)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(8300,6300,2500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.8);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);

		AIclass(_AIclassprost|_AIclassfemale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}


ActorHeader(PimpHeader)
{
		file("pc\actors\Pimp\Mod\DCRFinal\Pimp1.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(11400,8400,3300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);


		AIclass(_AIclasspimp|_AIclassmale);
		AIfriendmask(_AIclassfriendly);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(10);
}

ActorHeader(chotbehemothHeader)
{
		file("pc\actors\ChotBeh\Mod\DCRFinal\new\ChotBeh.dcr");

		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASSbeast);

		ColSphereSize(163);				//probably needs some more tweakins'
		ColSphereOffset(5);		//-10
		ColFeetSphereSize(105);
		ColFeetSphereOffset(-52);	//-106

		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(80);

		scale(0.175);

		Health(10000)
		ColMask(_COLAll)
		ColValues(25,25,25,50,25,25,0,25)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(13600,10000,3600);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.7);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);

		AIclass(_AIclassBeast|_AIclassChot|_AIclassMale);
		AIfriendmask(_AIclasschot|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(80);
}

ActorHeader(SatanHeader)
{
		file("pc\actors\Satan\Mod\DCRFinal\new\satan.dcr");

		gravity(Char_fall_rate,Char_max_fall);
		footbones(37,33);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASSbeast);

		ColSphereSize(163);				//probably needs some more tweakins'
		ColSphereOffset(50);		//-10
		ColFeetSphereSize(105);
		ColFeetSphereOffset(-7);	//-106

		PossesionAngle(180);
		PossesionSphereSize(0);
		PossesionSphereOffset(105);

//		PossesionAngle(0);
//		PossesionSphereSize(0);
//		PossesionSphereOffset(0);

		scale(0.20);

		Health(2000)
		ColMask(_COLholy)
		ColValues(0,0,0,0,0,100,0,0)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(11100,8500,3400);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(20000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,128,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);
		BodyPartSizes(8,  0,128,192,64,64);

		AIclass(_AIclassSatan|_AIclassMale);
		AIfriendmask(_AIclassSatan);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(90);
}


ActorHeader(GunCommandHeader)
{
		file("pc\actors\GunCommander\Mod\DCRFinal\GunComand.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(90);
		ColSphereOffset(-13);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-43);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenadeDistortion);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialGrenade)

		NrFaces(8900,6700,2500);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);

		AIclass(_AIclasscop|_AIclassfemale);
		AIfriendmask(_AIclasscop|_AIclassworker|_AIclassdroid|_AIclassscientist|_AIclassprost|_AIclassdweller|_AIclassanimal|_AIclassabeast|_AIclassbarpeople);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(40);
}

ActorHeader(chot2Header)
{
		file("pc\actors\Chot2\Mod\DCRFinal\Chot2.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(4000,3300,1600);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,32,64);
		BodyPartSizes(8,  0,224,192,32,64);


		AIclass(_AIclasschot|_AIclassmale);
		AIfriendmask(_AIclasschot|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}


ActorHeader(chot5Header)
{
		file("pc\actors\Chot5\Mod\DCRFinal\new\Chot5.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(100);
		ColSphereOffset(-18);
		ColFeetSphereSize(60);
		ColFeetSphereOffset(-58);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(4800,4000,2100);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.9);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);

		AIclass(_AIclasschot|_AIclassmale);
		AIfriendmask(_AIclasschot|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}


ActorHeader(behemothHeader)
{
		file("pc\actors\Behemoth\Mod\DCRFinal\Behemoth.dcr");

		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASSbeast);

		ColSphereSize(163);				//probably needs some more tweakins'
		ColSphereOffset(5);
		ColFeetSphereSize(105);
		ColFeetSphereOffset(-52);

		PossesionAngle(130);
		PossesionSphereSize(65);
		PossesionSphereOffset(170);

		scale(0.175);

		Health(10000)
		ColMask(_COLAll)
		ColValues(75,75,75,75,75,75,0,75)
		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		inventory(_InitialNoAmmo);

		NrFaces(16000,11600,4300);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(0.7);
		LowDetailDistance(3000);

		NoDirectionalLight(true);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,256,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);

		AIclass(_AIclassBeast|_AIclassMale);
		AIfriendmask(_AIclassbeast|_AIclassanimal);
		AIenemymask1(_AIclassScientist);
		AIenemymask2(_AIclassAngel);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(80);
}


ActorHeader(chotdwarfHeader)
{
		file("pc\actors\chotdwarf\mod\DCRfinal\ChotDwarf.dcr");
		gravity(Char_fall_rate,Char_max_fall);
		footbones(18,22);
		HeadBone(4);
		type(_ActorAnimObj);
		class(_CLASScop);
		ColSphereSize(40);		//If changing, change the #define for BobSphereSize
		ColSphereOffset(10);
		ColFeetSphereSize(30);
		ColFeetSphereOffset(0);
		PossesionAngle(180);
		PossesionSphereSize(80);
		PossesionSphereOffset(60);
		Health(5000)
		ColMask(_COLAll)
		ColValues(100,90,90,90,10,0,100,90)

		InventoryType(_AmmoGrenade);
		InventoryLimit(_LimitGrenade);
		PickupLimit(_PickupLimitGrenade);
		Inventory(_InitialNoAmmo)

		NrFaces(8000,6200,2800);
		TesselationFactors(1.0,1.2,2.0);
		TesselationMultiplier(1.0);
		LowDetailDistance(3000);

		NrTexPages(2);
		BodyPartSizes(1,  0,0,192,192,64);		//bodypart,  texpage,  x,y(upper left corner), width,height
		BodyPartSizes(2,  1,0,0,64,256);
		BodyPartSizes(3,  0,0,0,256,192);
		BodyPartSizes(4,  1,64,0,64,256);
		BodyPartSizes(5,  1,128,0,64,256);
		BodyPartSizes(6,  1,192,0,64,256);
		BodyPartSizes(7,  0,192,192,64,64);


		AIclass(_AIclassangel|_AIclasschot|_AIclassmale);
		AIfriendmask(_AIclasschot|_AIclassanimal);
		AIfov(800);
		AIfovcorrectionangle(308);		//-27.1 degrees off for the cop skeleton
		AIhearing(100);
		AIsight(3000,0);
		AIstrenght(50);
}

action(MDroid1Work)
{
		//file("pc\actors\droid1\ske\ready.xxx",100,off);
		file("pc\actors\droid1\ske\work.ske",100,on);
		break(off);
		trigger(_allDIR);
		connections(MDroid1Work);
		//shadow(off);
}
action(MDroid2Work)
{
		//file("pc\actors\droid1\ske\ready.xxx",100,off);
		file("pc\actors\droid2\ske\idle.ske",100,on);
		break(off);
		trigger(_allDIR);
		connections(MDroid2Work);
		//shadow(off);
}

action(RLaunchPatrol)
{
		file("pc\actors\rlaunch\xxx\rfire.ske",100,on);
		break(off);
		gravity(off);
		trigger(_allDIR);
		connections(RLaunchPatrol);
		shadow(off);
}

action(RIdle)
{
		file("pc\actors\rlaunch\xxx\ridle.ske",100,on);
		break(off);
		gravity(off);
		trigger(_allDIR);
		connections(RIdle);
		shadow(off);
}

action(ShellTurretNoMove)
{
		file("pc\actors\turret\skeleton.ske",100,on);
		break(off);
		gravity(on);
		trigger(_allDIR);
		connections(ShellTurretNoMove);
		shadow(off);
}

action(GunTurretFire)
{
		file("pc\actors\gunturret\xxx\gtfire1.ske",100,on);
		break(off);
		gravity(off);
		trigger(_allDIR);
		connections(GunTurretFire);
		shadow(off);
}

action(GunTurretBeserker)
{
		file("pc\actors\gunturret\xxx\gtbrsrk.ske",100,on);
		break(off);
		gravity(off);
		trigger(_allDIR);
		connections(GunTurretBeserker);
		shadow(off);
}

action(GunTurretIdle)
{
		file("pc\actors\gunturret\xxx\gtidle1.ske",100,on);
		break(off);
		gravity(off);
		trigger(_allDIR);
		connections(GunTurretIdle);
		shadow(off);
}
