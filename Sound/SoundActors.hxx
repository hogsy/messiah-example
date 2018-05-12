
// Things I need to check...
// DROWNING - (SFXDrownReact)
// SEEING ILLEGAL WEAPON - (SFXIllegalWeaponReact)
// SEEING BOB GO OUT OF SIGHT - (SFXReactToBobGone)
// ALL CHARACTERS CLIMBING OVER A LEDGE - SFXGrunt
// BLINDING CHARACTERS
 
/*
For reacting to players activating panel: sample(SFXPlayerActivatesButtonReact,-1);
For reacting to players trying to activate locked door: sample(SFXPlayerActivatesLockedDoorReact,-1);
For reacting to smell:	sample(SFXSmellReact,-1);
For reacting to getting steamed:	sample(SFXGettingSteamedReact,-1);
For reacting to walking around blinded: sample(SFXBlindReact,-1);
*/


/*

All Character flags available

_AIclasscop
_AIclassworker
_AIclassdroid
_AIclasschot
_AIclassangel
_AIclassbeast
_AIclassabeast
_AIclassprost
_AIclasspimp
_AIclasspriest
_AIclassdweller
_AIclassscientist
_AIclassbarpeople
_AIclassmale
_AIclassfemale
_AIclassriotcop
_AIclassmedic
_AIclasssubgirl
_AIclassanimal
_AIclassSatan
_AIclassBouncer
_AIclassHuman

_AIclassfriendly		_AIclasscop|_AIclassworker|_AIclassdroid|_AIclasschot|_AIclassangel|_AIclassbeast|_AIclassabeast|_AIclassprost|_AIclasspimp|_AIclasspriest|_AIclassdweller|_AIclassscientist|_AIclassbarpeople|_AIclassmale|_AIclassfemale|_AIclassriotcop|_AIclassHipGun|_AIclasslightgun|_AIclassmedic|_AIclasssubgirl|_AIclassanimal

_AIClassBobSkeleton		_AIclassmale|_AIclassangel
_AIClassCopSkeleton		_AIclassmale|_AIclasscop|_AIclassworker|_AIclasschot|_AIclasspimp|_AIclassdweller|_AIclassscientist|_AIclassmedic|_AIclassriotcop|_AIclassmedic|_AIclassbarpeople
_AIClassProstSkeleton	_AIclassfemale|_AIclassprost|_AIclassdweller|_AIclasscop|_AIclasssubgirl|_AIclassbarpeople
_AIClassAbeastSkeleton	_AIclassmale|_AIclassabeast
_AIClassBeastSkeleton	_AIclassmale|_AIclassbeast|_AIclassBouncer

_AIClassAllButAngel		_AIclasscop|_AIclassworker|_AIclasschot|_AIclasspimp|_AIclassdweller|_AIclassscientist|_AIclassriotcop|_AIclassmedic|_AIclassbarpeople
*/

/*
sample(SFXtest)
{
//		file("pc\sound\final\welder-whistle2.wav",50,_AIclassWorker);
//		file("pc\sound\final\blue-weapon1.wav",100,_AIclassWorker);
//		file("pc\sound\final\welder-whistle1.wav",50,_AIclassCop);
//		file("pc\sound\final\bob-crush1.wav",100,_AIclassAngel);

		delay(30);			//nr of ticks before respawn allowed

		loop(FALSE);		// Looping sample?
		tridi(TRUE);		// Play saple in 3D
		rndfreq(TRUE);		// Vary pitch (for repetitive samples)
		fademin(800);		// Ramge before volume starts to fall-off
		fademax(3000);		// Maximum range you can hear sample
}
*/

// Welder whistling whilst he works.
//NOW USES : SFXBoredIdle instead ...more variety
/*
sample(SFXWelderWhistle)
{
//		file("pc\sound\actor\AllVoices\welder-whistle1.wav",5);
//		file("pc\sound\actor\AllVoices\welder-whistle2.wav",10);
//		file("pc\sound\actor\AllVoices\welder-idle1.wav",80);
//		file("pc\sound\actor\AllVoices\welder-idle2.wav",90);
//		file("pc\sound\actor\AllVoices\welder-idle3.wav",100);

		speechsample(true);

		delay(120);			// every 4 seconds

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(800);
}
*/


///////////////////////////////
//		SAXS's AI sounds	 //
///////////////////////////////


// Character is bored and idle
sample(SFXBoredIdle)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-idle11.wav",90,_AIclassCop|_AIclassFemale,true);
		file("pc\sound\FINAL\domina-idle10.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-sigh1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-sigh2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-sigh3.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock3.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-idle11.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-whatthat3.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-idle1.wav",20,_AIclassWorker);
		file("pc\sound\FINAL\welder-idle2.wav",40,_AIclassWorker);
		file("pc\sound\FINAL\welder-idle3.wav",60,_AIclassWorker);
		file("pc\sound\FINAL\welder-whistle1.wav",80,_AIclassWorker);
		file("pc\sound\FINAL\welder-whistle2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot-breathe.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-chatter5.wav",12,_AIclassAngel);
		file("pc\sound\FINAL\bob-ninja2.wav",24,_AIclassAngel);
		file("pc\sound\FINAL\bob-idle2.wav",36,_AIclassAngel);
		file("pc\sound\FINAL\bob-idle1.wav",48,_AIclassAngel);
		file("pc\sound\FINAL\bob-chick2.wav",60,_AIclassAngel);
		file("pc\sound\FINAL\bob-chatter3.wav",72,_AIclassAngel);
		file("pc\sound\FINAL\bob-chatter4.wav",84,_AIclassAngel);
		file("pc\sound\FINAL\bob-ninja1.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		//file("pc\sound\FINAL\behm-idle4.wav",50,_AIclassbeast);
		//file("pc\sound\FINAL\behm-idle7.wav",80,_AIclassbeast);
		file("pc\sound\FINAL\behm-idle7.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-idle8.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-idle2.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-idle6.wav",66,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-idle7.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-idle1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-idle2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-idle3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-idle1.wav",20,_AIclasspimp);
		file("pc\sound\FINAL\pimp-idle2.wav",40,_AIclasspimp);
		file("pc\sound\FINAL\pimp-idle3.wav",60,_AIclasspimp);
		file("pc\sound\FINAL\pimp-idle5.wav",80,_AIclasspimp);
		file("pc\sound\FINAL\pimp-idle7.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-chat4.wav",20,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-chat8.wav",40,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-seedeath1.wav",60,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-seedeath2.wav",80,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hiding2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-chat1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-chat2.wav",66,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-chick4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(240);			// every 8 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

// Reacting to you carrying an illegal weapon
sample(SFXIllegalWeaponReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-weapon1.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-weapon2.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-weapon3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-arrest2.wav",16,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-weapon1.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-weapon2.wav",49,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-weapon3.wav",66,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-weapon4.wav",83,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-weapon5.wav",100,_AIclassCop|_AIclassMale);
	// Welder
		file("pc\sound\FINAL\welder-donttouch1.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-donttouch4.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot9.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-threat5.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-threat6.wav",80,_AIclassbeast);
		file("pc\sound\FINAL\behm-threat7.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-weapon1.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-weapon2.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-weapon3.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-running1.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-running2.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-weapon1.wav",25,_AIclasspimp);
		file("pc\sound\FINAL\pimp-weapon2.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-weapon3.wav",75,_AIclasspimp);
		file("pc\sound\FINAL\pimp-weapon4.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-weapon1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-weapon2.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-weapon3.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-weapon1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-weapon2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-weapon3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);			// every 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
		localize(_all);
}

// Flying through the air on a harpoon
sample(SFXFlyThroughAirReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-crawl1.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-onfire1.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-burn1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-onfire3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-radiation1.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-radiation4.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-radiation1.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-scream1.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-scream1.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-onfire4.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-radiation4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(30);			// every 1 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(5000);
		localize(_all);
}

// Dying of Radiation Sickness
sample(SFXRadiationReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-crawl1.wav",40,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crawl2.wav",80,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-electric2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-choke.wav",60,_AIclassCop|_AIclassMale,true);
		file("pc\sound\FINAL\blue-harpoon2.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-burn1.wav",25,_AIclassScientist);
		file("pc\sound\FINAL\sci-burn2.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-crap1.wav",75,_AIclassScientist);
		file("pc\sound\FINAL\sci-scared1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-seeexplode2.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-onfire1.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-onfire3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-radiation1.wav",40,_AIclassAngel);
		file("pc\sound\FINAL\bob-radiation2.wav",70,_AIclassAngel);
		file("pc\sound\FINAL\bob-radiation3.wav",100,_AIclassAngel);
	// ARMORED Behemoth
		file("pc\sound\FINAL\behm-possessed3.wav",100,_AIclassabeast);
	// CHOT Behemoth
		file("pc\sound\FINAL\behm-possessed3.wav",100,_AIclassbeast|_AIclassChot);
	// NAKED Behemoth
		file("pc\sound\FINAL\behm-radiation4.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-radiation5.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-radiation1.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-radiation2.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-radiation2.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-scream2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-scream3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-scream1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-scream2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-scream3.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-onfire3.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-onfire4.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-radiation1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-radiation2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-radiation3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);			// every 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// This Character has just been DEPOSSESSED
sample(SFXJustDeposessed)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-pain11.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain10.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crawl2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-choke.wav",10,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-harpoon1.wav",20,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-harpoon2.wav",30,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind2.wav",40,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind3.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind4.wav",60,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind5.wav",70,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-break1.wav",80,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-break2.wav",90,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind1.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-ohgod1.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-pain10.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-burned1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-afterfire3.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-afterfire4.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-afterfire5.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot-hiss.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-depos5.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-depos7.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-depos1.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-depos4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-depos1.wav",25,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-depos2.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-depos3.wav",75,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-depos4.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-depos2.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-depos3.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-depos1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-depos2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-depos3.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-depos4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);			// every 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}


// Reacting to having a gun pointed at them
sample(SFXCombatModeReactGun)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-threat.wav",20,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-threat10.wav",40,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-weapon1.wav",60,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-weapon2.wav",80,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-weapon3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-arrest3.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-arrest2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-arrest1.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-arrest4.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-plead2.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-threat1.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-threat4.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-plead2.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-plead4.wav",66,_AIclassWorker);
		file("pc\sound\FINAL\welder-plead6.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot34.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-threat5.wav",33,_AIclassbeast);
		file("pc\sound\FINAL\behm-threat6.wav",67,_AIclassbeast);
		file("pc\sound\FINAL\behm-threat7.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-threat2.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-threat4.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-threat6.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-threat1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-threat2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-threat3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-threat1.wav",20,_AIclasspimp);
		file("pc\sound\FINAL\pimp-threat2.wav",40,_AIclasspimp);
		file("pc\sound\FINAL\pimp-threat3.wav",60,_AIclasspimp);
		file("pc\sound\FINAL\pimp-threat4.wav",80,_AIclasspimp);
		file("pc\sound\FINAL\pimp-threat5.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-threat2.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-threat3.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-threat5.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-threat1.wav",25,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-threat2.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-threat4.wav",75,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-threat5.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(150);			// every 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
		localize(_all);
}

// Reacting to someone holding up their fists
sample(SFXCombatModeReactNoGun)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-here2.wav",70,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-threat2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-fists1.wav",20,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-fists2.wav",40,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-fists3.wav",60,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-fists4.wav",80,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-screwing3.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-plead1.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-threat2.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-threat3.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-threat7.wav",25,_AIclassWorker);
		file("pc\sound\FINAL\welder-threat8.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-threat6.wav",75,_AIclassWorker);
		file("pc\sound\FINAL\welder-plead6.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot2.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-fists2.wav",33,_AIclassbeast);
		file("pc\sound\FINAL\behm-fists6.wav",67,_AIclassbeast);
		file("pc\sound\FINAL\behm-fists10.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-fists1.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-fists4.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-fists6.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-fists1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-fists2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-fists3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-fists1.wav",25,_AIclasspimp);
		file("pc\sound\FINAL\pimp-fists4.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-fists5.wav",75,_AIclasspimp);
		file("pc\sound\FINAL\pimp-fists7.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-fists1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-fists2.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-fists3.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-fists2.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-fists5.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-fists6.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(120);			// every 4 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
		localize(_all);
}

// Reacting to seeing a grenade land beside them
sample(SFXGrenadeReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-grenade1.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-grenade2.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-grenade3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-grenade1.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-grenade2.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-grenade1.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-grenade2.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-grenade3.wav",100,_AIclassScientist);
	// Chot
		file("pc\sound\FINAL\chot2.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-grenade1.wav",50,_AIclassAngel);
		file("pc\sound\FINAL\bob-grenade6.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-fists2.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-fists6.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-grenade3.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-grenade4.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-grenade5.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-grenade1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-grenade2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-grenade3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-grenade1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-grenade2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-grenade3.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-grenade2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-grenade3.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-grenade4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);			// every 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Getting hurt by an explosion
sample(SFXExplosionReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-shit10.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-shit11.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-shock2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-shock3.wav",100,_AIclassCop|_AIclassMale);
	// Scientist	
		file("pc\sound\FINAL\sci-shit1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-seeexplode1.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-seeexplode2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-loud3.wav",25,_AIclassAngel);
		file("pc\sound\FINAL\bob-loud4.wav",50,_AIclassAngel);
		file("pc\sound\FINAL\bob-loud5.wav",75,_AIclassAngel);
		file("pc\sound\FINAL\bob-loud7.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-hugexplo2.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-shock2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-shock5.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-hugexplo1.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-hugexplo3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-hugexplo1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hugexplo3.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hugexplo5.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-hugexplo1.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-hugexplo1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-hugexplo2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-hugexplo3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(30);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
		flushable(0);
}

// First time a character sees Bob
sample(SFXReactToBob)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-here1.wav",45,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-here2.wav",90,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-beatcold.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-comehere1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-comehere2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-comehere3.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-comehere4.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-bob1.wav",40,_AIclassScientist);
		file("pc\sound\FINAL\sci-bob3.wav",60,_AIclassScientist);
		file("pc\sound\FINAL\sci-bob6.wav",80,_AIclassScientist);
		file("pc\sound\FINAL\sci-bob8.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-shoo1.wav",20,_AIclassWorker);
		file("pc\sound\FINAL\welder-shoo2.wav",40,_AIclassWorker);
		file("pc\sound\FINAL\welder-shoo3.wav",60,_AIclassWorker);
		file("pc\sound\FINAL\welder-shoo5.wav",80,_AIclassWorker);
		file("pc\sound\FINAL\welder-shoo6.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot54.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-bob1.wav",33,_AIclassbeast);
		file("pc\sound\FINAL\behm-bob4.wav",67,_AIclassbeast);
		file("pc\sound\FINAL\behm-bob7.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-bob1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-bob2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-bob3.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-bob5.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-bob1.wav",25,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-bob2.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-bob3.wav",75,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-bob4.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-bob1.wav",25,_AIclasspimp);
		file("pc\sound\FINAL\pimp-bob2.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-bob3.wav",75,_AIclasspimp);
		file("pc\sound\FINAL\pimp-bob4.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-bob1.wav",25,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-bob2.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-bob4.wav",75,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-bob5.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-bob1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-bob2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-bob3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(150);		// Delay 5 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


// Lost sight of Bob!  (He was just there a second ago!)
sample(SFXReactToBobGone)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-hiding1.wav",25,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-hiding2.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-hiding3.wav",75,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-hiding4.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-hiding1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hiding4.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hiding5.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hiding6.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-bumping2.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-hiding1.wav",25,_AIclassWorker);
		file("pc\sound\FINAL\welder-hiding2.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-hiding3.wav",75,_AIclassWorker);
		file("pc\sound\FINAL\welder-hiding4.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot-putitdown.wav",100,_AIclassChot);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-hiding1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hiding2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hiding3.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hiding4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-hiding1.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-hiding2.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-hiding1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hiding2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hiding3.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-hiding1.wav",25,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hiding2.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hiding3.wav",75,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hiding5.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-hiding1.wav",100,_AIclassdweller|_AIclassMale);
	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(180);		// Delay 6 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

// Seeing Bob when multiple cops are also present present
sample(SFXReactToBobMoreCops)
{
		file("pc\sound\FINAL\domina-traphim1.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-traphim2.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-traphim3.wav",100,_AIclassCop|_AIclassFemale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);		// Delay 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}


// Getting electrocuted
sample(SFXElectrocuteReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-electric2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-quickshock1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-quickshock3.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-quickshock4.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-quickshock5.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-scared1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-pain11.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-electrocute2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-shock1.wav",50,_AIclassAngel);
		file("pc\sound\FINAL\bob-shock2.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-shock3.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-shock4.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-shock1.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-shock3.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-shock5.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-shock1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-shock2.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-shock1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-shock2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-shock2.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-shock4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Character is crawling
sample(SFXCrawlingReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-pain10.wav",25,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain11.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crawl1.wav",75,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crawl2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-knee1.wav",20,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-knee2.wav",40,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-knee3.wav",60,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-knee4.wav",80,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-knee5.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-burned1.wav",16,_AIclassScientist);
		file("pc\sound\FINAL\sci-help2.wav",32,_AIclassScientist);
		file("pc\sound\FINAL\sci-help3.wav",48,_AIclassScientist);
		file("pc\sound\FINAL\sci-help4.wav",64,_AIclassScientist);
		file("pc\sound\FINAL\sci-help5.wav",80,_AIclassScientist);
		file("pc\sound\FINAL\sci-help6.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-crawling1.wav",25,_AIclassWorker);
		file("pc\sound\FINAL\welder-crawling2.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-crawling3.wav",75,_AIclassWorker);
		file("pc\sound\FINAL\welder-knee3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot5.wav",50,_AIclassChot);
		file("pc\sound\FINAL\chot26.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-crawlpain2.wav",20,_AIclassbeast);
		file("pc\sound\FINAL\behm-crawlpain3.wav",40,_AIclassbeast);
		file("pc\sound\FINAL\behm-crawlpain4.wav",60,_AIclassbeast);
		file("pc\sound\FINAL\behm-crawlpain5.wav",80,_AIclassbeast);
		file("pc\sound\FINAL\behm-crawlpain6.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-crawl3.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-crawl4.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-crawl5.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-crawl6.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-crawl1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-crawl2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-crawl3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-crawl2.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-crawl3.wav",66,_AIclasspimp);
		file("pc\sound\FINAL\pimp-crawl4.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-crawl2.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-crawl3.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-crawl7.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-crawl2.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-crawl3.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-crawl5.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(120);		// Delay 4 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

// Character getting *KICKED*
sample(SFXKickedReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-kicked2.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-kicked3.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-hit1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hit2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hit4.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hit6.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-hit3.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-kicked1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-punched1.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-punched3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot30.wav",50,_AIclassChot);
		file("pc\sound\FINAL\chot54.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-grunt02.wav",20,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt03.wav",40,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt04.wav",60,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt05.wav",80,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt06.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
//		file("pc\sound\FINAL\behm-shot2.wav",100,_AIclassbeast);
		file("pc\sound\FINAL\behm-shot4.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-shot5.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-hit1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hit2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hit6.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hit8.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-hit3.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-hit4.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-hit6.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-hit1.wav",25,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hit3.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hit5.wav",75,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hit7.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-hit2.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hit4.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hit6.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-hit1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-hit4.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-hit5.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(30);		// Delay 1 second
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

// Character getting *PUNCHED* or RIFLE-BUTTED
sample(SFXPunchedReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-kicked1.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-kicked4.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain1.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-hit3.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hit7.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hit8.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-hit9.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-hit1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-hit2.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-punched2.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-pain2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot21.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-grunt02.wav",20,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt03.wav",40,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt04.wav",60,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt05.wav",80,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt06.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
//		file("pc\sound\FINAL\behm-shot2.wav",100,_AIclassbeast);
		file("pc\sound\FINAL\behm-shot4.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-shot5.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-hit3.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hit4.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-hit7.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-hit1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-hit2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-hit5.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-hit2.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hit4.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-hit6.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-hit1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hit3.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-hit5.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-hit2.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-hit3.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-hit6.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(30);		// Delay 1 second
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
		flushable(0);
}

// Shot in the Knee
sample(SFXShotInLegReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-pain1.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain2.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-hit3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-knee3.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-knee5.wav",66,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-knee6.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-knee1.wav",20,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee2.wav",40,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee3.wav",60,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee4.wav",80,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee5.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-knee1.wav",25,_AIclassWorker);
		file("pc\sound\FINAL\welder-knee3.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-knee5.wav",75,_AIclassWorker);
		file("pc\sound\FINAL\welder-knee6.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-grunt02.wav",33,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt03.wav",67,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt06.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		//file("pc\sound\FINAL\behm-shot2.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-shot4.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-shot5.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-knee1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-knee2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-knee3.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-knee5.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-knee1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-knee2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-knee4.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-knee1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-knee2.wav",66,_AIclasspimp);
		file("pc\sound\FINAL\pimp-knee5.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-knee1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-knee2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-knee2.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-knee3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);		// Every 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Fell and broke leg
sample(SFXBreakLegReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-leg.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain10.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain11.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-knee3.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-break1.wav",67,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-break2.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-knee2.wav",25,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee3.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee4.wav",75,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee5.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-knee3.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-knee6.wav",100,_AIclassWorker);
	// Chots
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);


	// NAKED Behemoth
		file("pc\sound\FINAL\behm-landpain4.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-landpain7.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-leg1.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-leg3.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-leg1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-leg2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-leg3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-leg1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-leg2.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-leg3.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-leg1.wav",25,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-leg2.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-leg3.wav",75,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-leg4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);			// Delay 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


// Getting shot, but not fatal!
sample(SFXShotReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-pain1.wav",30,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain2.wav",60,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-hit3.wav",90,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-getshot3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-shot10.wav",30,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-shot11.wav",55,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-shot12.wav",80,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-shot13.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-getshot1.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-getshot2.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-getshot3.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-getshot2.wav",20,_AIclassWorker);
		file("pc\sound\FINAL\welder-getshot4.wav",40,_AIclassWorker);
		file("pc\sound\FINAL\welder-knee4.wav",60,_AIclassWorker);
		file("pc\sound\FINAL\welder-getshot1.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot54.wav",50,_AIclassChot);
		file("pc\sound\FINAL\chot21.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-grunt02.wav",20,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt03.wav",40,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt04.wav",60,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt05.wav",80,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt06.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-shot4.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-shot5.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-getshot1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-getshot2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-getshot3.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-getshot4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-getshot1.wav",20,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-getshot2.wav",40,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-getshot3.wav",60,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-getshot4.wav",80,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-getshot5.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-getshot3.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-getshot1.wav",80,_AIclasspimp);
		file("pc\sound\FINAL\pimp-getshot2.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-getshot2.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-getshot3.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-getshot2.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-getshot4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
		flushable(0);
}

// Somebody Bumped into this Character
sample(SFXBumpIntoReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-bumping1.wav",25,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-bumping2.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-bumping3.wav",75,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-bumping4.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-bumping1.wav",16,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-bumping2.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-bumping4.wav",49,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-bumping5.wav",66,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-bumping6.wav",88,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-bumping7.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-bumping1.wav",25,_AIclassScientist);
		file("pc\sound\FINAL\sci-bumping3.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-bumping4.wav",75,_AIclassScientist);
		file("pc\sound\FINAL\sci-bumping6.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-bumping2.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-donttouch4.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot55.wav",50,_AIclassChot);
		file("pc\sound\FINAL\chot43.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-bumping1.wav",33,_AIclassbeast);
		file("pc\sound\FINAL\behm-bumping2.wav",67,_AIclassbeast);
		file("pc\sound\FINAL\behm-bumping3.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-bumping1.wav",20,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-bumping2.wav",40,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-bumping3.wav",60,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-bumping4.wav",80,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-bumping5.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-bumping1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-bumping2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-bumping3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-chat1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat4.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-bumping1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-bumping3.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-bumping4.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-bumping2.wav",25,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-bumping3.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-bumping5.wav",75,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-bumping7.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);		// Delay 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}



// Quite a hard landing
sample(SFXHardLandingReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-hit1.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-hit4.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-knee1.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-knee2.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-hit3.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-punched1.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-punched3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot30.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-land1.wav",50,_AIclassAngel);
		file("pc\sound\FINAL\bob-land2.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-land2.wav",25,_AIclassbeast);
		file("pc\sound\FINAL\behm-land3.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-land4.wav",75,_AIclassbeast);
		file("pc\sound\FINAL\behm-land5.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-land3.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-land4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-land1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-land2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-land3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-land1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-land2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-land3.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-land1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-land2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-hit1.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-hit2.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);			// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

// FALLING!
sample(SFXLongFallReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-fall1.wav",25,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-fall2.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-fall3.wav",75,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-fall4.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-fall1.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-fall2.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-fall.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-scared3.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-fall1.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-fall3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot5.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-fall1.wav",33,_AIclassAngel);
		file("pc\sound\FINAL\bob-fall2.wav",67,_AIclassAngel);
		file("pc\sound\FINAL\bob-fall3.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-fall2.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-fall3.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-fall1.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-fall2.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-fall3.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-fall1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-fall2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-fall3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-fall1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-fall2.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-fall1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-fall3.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-fall4.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-fall1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-fall2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-fall3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// JUST DIED!
sample(SFXJustDiedReact)
{
	// Cops
		file("pc\sound\FINAL\blue-die1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-die2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-die3.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-die4.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-lastbreath1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-lastbreath6.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-die1.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-die2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot-die.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-die1.wav",20,_AIclassAngel);
		file("pc\sound\FINAL\bob-die2.wav",40,_AIclassAngel);
		file("pc\sound\FINAL\bob-die3.wav",60,_AIclassAngel);
		file("pc\sound\FINAL\bob-die4.wav",80,_AIclassAngel);
		file("pc\sound\FINAL\bob-die5.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-die5.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-die6.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-die1.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-die3.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-die4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-die1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-die2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-die3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-die1.wav",25,_AIclasspimp);
		file("pc\sound\FINAL\pimp-die2.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-die3.wav",75,_AIclasspimp);
		file("pc\sound\FINAL\pimp-die4.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-die1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-die2.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-die3.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-die2.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-die3.wav",66,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-die4.wav",100,_AIclassdweller|_AIclassMale);

	// Domina/Commander/subgirls
		file("pc\sound\FINAL\domina-die1.wav",33,_AIclassFemale);
		file("pc\sound\FINAL\domina-die2.wav",67,_AIclassFemale);
		file("pc\sound\FINAL\domina-die3.wav",100,_AIclassFemale);
	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);		// Delay 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Character sees a possession happening!
sample(SFXPossesionReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-whatthe10.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-shit11.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-surprised1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-surprised2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-surprised3.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-surprised4.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-getnweird2.wav",16,_AIclassScientist);
		file("pc\sound\FINAL\sci-getnweird4.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-whatthat1.wav",49,_AIclassScientist);
		file("pc\sound\FINAL\sci-whatthat2.wav",66,_AIclassScientist);
		file("pc\sound\FINAL\sci-whatthat3.wav",83,_AIclassScientist);
		file("pc\sound\FINAL\sci-whatthat4.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-seepos1.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-seepos2.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-seepos3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot30.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-seepos1.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-seepos2.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-seepos1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-seepos2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-seepos3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-seepos1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-seepos2.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-seepos2.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-seepos4.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-seepos5.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-seepos1.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);			// Delay 3 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

// Character Drowning
sample(SFXDrownReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-drown1.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-drown2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-aciddie1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-drownscream1.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-drownscream2.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-drownscream3.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-lastbreath1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-lastbreath5.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-drown1.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-drown2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-drown.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-drown3.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-drown4.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-drown2.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-drown1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-drown2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-drown3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-drown1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-drown2.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-drown1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-drown2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-drown1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-drown2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-drown3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Character Gets CRUSHED
sample(SFXCrushedReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-crush.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crush3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-crush1.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-crush2.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-scared1.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-scared3.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-knee1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-crushed.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-crush1.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-crush2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot-crush.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-crush1.wav",50,_AIclassAngel);
		file("pc\sound\FINAL\bob-crush2.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-crush1.wav",33,_AIclassbeast);
		file("pc\sound\FINAL\behm-crush2.wav",67,_AIclassbeast);
		file("pc\sound\FINAL\behm-crush4.wav",100,_AIclassbeast);
	// MALE Prostitute
		file("pc\sound\FINAL\tv-crush1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-crush2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-crush3.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-crush4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-scream2.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-scream3.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-scream4.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-crush1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-crush2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-crush3.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-crush1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-crush3.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-crush4.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-crush1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-crush2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-crush3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);			// Delay 60 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Chatting for the first time
sample(SFXChatFirstTime)
{
	// Domina/Commander
		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		//file("pc\sound\FINAL\blue-acknowledge4.wav",16,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-acknowledge5.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-idle8.wav",66,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-idle9.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-idle11.wav",30,_AIclassScientist);
		file("pc\sound\FINAL\sci-whatare1.wav",66,_AIclassScientist);
		file("pc\sound\FINAL\sci-whatare2.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-hi.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-heard1.wav",75,_AIclassWorker);
		file("pc\sound\FINAL\welder-heard2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot4.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-bumping2.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-chat4.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-chat5.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-chat6.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-chat12.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-chat1.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-chat2.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-chat1.wav",25,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat4.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat5.wav",75,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat6.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-chat2.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-chat4.wav",66,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-chat8.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-threat1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-threat2.wav",66,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-medic4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(120);		// Delay 4 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

//Cop background conversation sounds:
sample(SFXChat)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-idle11.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-strange5.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-idle1.wav",16,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-idle2.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-idle5.wav",49,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-idle6.wav",66,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-idle8.wav",83,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-idle9.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-idle11.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-hi.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-talk1.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-talk2.wav",100,_AIclassWorker);
	// Chots
		file("pc\sound\FINAL\chot51.wav",50,_AIclassChot);
		file("pc\sound\FINAL\chot50.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-chat1.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-chat8.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-chat9.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-chat1.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-chat2.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-chat1.wav",20,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat2.wav",40,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat3.wav",60,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat4.wav",80,_AIclasspimp);
		file("pc\sound\FINAL\pimp-chat6.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-chat2.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-chat8.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-chat1.wav",25,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-chat2.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-chat3.wav",75,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-chick4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(120);		// Delay 4 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


// Character smelling something really bad  (Triggered)
// Just works for Blue Cop and Bob
sample(SFXSmellReact)
{
	// Cops
		file("pc\sound\FINAL\blue-smell1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-smell2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-smell3.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-smell4.wav",100,_AIclassCop|_AIclassMale);
	// Welder
//		file("pc\sound\FINAL\welder-stinks.wav",50,_AIclassWorker);
//		file("pc\sound\FINAL\welder-stinks1.wav",100,_AIclassWorker);
	// Bob
		file("pc\sound\FINAL\bob-smell1.wav",25,_AIclassAngel);
		file("pc\sound\FINAL\bob-smell2.wav",50,_AIclassAngel);
		file("pc\sound\FINAL\bob-smell3.wav",75,_AIclassAngel);
		file("pc\sound\FINAL\bob-smell4.wav",100,_AIclassAngel);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(150);		// Delay 5 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Getting Blinded in Steam
sample(SFXGettingSteamedReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-steamed1.wav",40,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-steamed2.wav",80,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-steamed3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-steam1.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-steam2.wav",67,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-steam3.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-scared1.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-burn1.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-burn3.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-steamed1.wav",100,_AIclassWorker);
	// Chots
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-grunt04.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
//		file("pc\sound\FINAL\behm-radiation4.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-steamed1.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-steamed3.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-steamed1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-steamed2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-steamed3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-steamed1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-steamed2.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-onfire3.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-onfire4.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-steamed1.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-steamed5.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(90);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Character Staggering around blind (after being blinded by steam)
sample(SFXBlindReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-blind1.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-blind2.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-blind3.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-blind1.wav",20,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind2.wav",40,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind3.wav",60,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind4.wav",80,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-blind5.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-burn2.wav",25,_AIclassScientist);
		file("pc\sound\FINAL\sci-crap1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-help3.wav",75,_AIclassScientist);
		file("pc\sound\FINAL\sci-help6.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-steamed2.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-steamed3.wav",100,_AIclassWorker);
	// Chots
		file("pc\sound\FINAL\chot44.wav",100,_AIclassChot);

		// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-blind3.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-blind4.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-blind5.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-blind6.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-spear1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-spear2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-spear3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-blind1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-blind3.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-blind1.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-blind1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-blind2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-blind3.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(120);			// Delay 4 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// This character just killed Bob
sample(SFXCopJustKilledBobReact)
{
	// Cops
		file("pc\sound\FINAL\blue-killedbob2.wav",4,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-killedbob3.wav",8,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock1.wav",12,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock6.wav",20,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock7.wav",24,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock9.wav",28,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock10.wav",32,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock12.wav",36,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock13.wav",40,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock14.wav",44,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock15.wav",48,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock17.wav",52,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock18.wav",56,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock19.wav",60,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock21.wav",64,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock23.wav",68,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock24.wav",72,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock25.wav",76,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock26.wav",80,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock27.wav",84,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock29.wav",88,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock30.wav",92,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock31.wav",96,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-mock32.wav",100,_AIclassCop|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

//		speechsample(true);

		delay(150);			// Delay 5 seconds
		loop(FALSE);
		tridi(FALSE);		// THIS IS A 2D SAMPLE!
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(3000);
		localize(_all);
}


// This character just killed Bob  (kinda non-discript chuckle)
sample(SFXJustKilledBobReact)
{
		file("pc\sound\FINAL\blue-killed2.wav");
//		file("pc\sound\actor\cop\walkie\killed\killed2.wav");		//remove this when the missing one is working

//		speechsample(true);

		delay(150);			// Delay 5 seconds
		loop(FALSE);
		tridi(FALSE);		// THIS IS A 2D SAMPLE!
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(3000);
}


sample(SFXRiotShieldOn)
{
		file("pc\sound\actor\rshieldup.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}

sample(SFXRiotShieldOff)
{
		file("pc\sound\actor\rshielddown.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}

sample(SFXGeigerCounter)
{
		file("pc\sound\actor\geigerlow.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}

/*
// Worker seeing Bob
sample(SFXWorkerGetLost)
{
	// Welder
//		file("pc\sound\actor\AllVoices\welder-shoo1.wav",20);
//		file("pc\sound\actor\AllVoices\welder-shoo2.wav",40);
//		file("pc\sound\actor\AllVoices\welder-shoo3.wav",60);
//		file("pc\sound\actor\AllVoices\welder-shoo5.wav",80);
//		file("pc\sound\actor\AllVoices\welder-shoo6.wav",100);

//		file("pc\sound\actor\worker\getlst.wav",33);
//		file("pc\sound\actor\worker\get.wav",67);
//		file("pc\sound\actor\worker\shoo.wav");

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
*/

/*
sample(SFXChotPainOuch)
{
	// Chot
//		file("pc\sound\actor\AllVoices\chot54.wav",50,_AIclassChot);
//		file("pc\sound\actor\AllVoices\chot21.wav",100,_AIclassChot);

//	file("pc\sound\actor\chot\grunt2.wav");

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
}
*/


sample(SFXOhGodNo)
{
		file("pc\sound\FINAL\blue-crush1.wav");
//		file("pc\sound\actor\mpain\godno.wav");

		speechsample(true);

		delay(150);		// Delay 5 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


// Scientist getting crushed
sample(SFXFatCrush)
{
	// Scientist
//		file("pc\sound\actor\AllVoices\sci-scared1.wav",33);
//		file("pc\sound\actor\AllVoices\sci-scared3.wav",67);
//		file("pc\sound\actor\AllVoices\sci-knee1.wav",100);

		file("pc\sound\actor\mpain\crush.wav");

//  		speechsample(true);

//		delay(150);		// Delay 5 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
}


// Welder in Club Perimeter crushed by the door
sample(SFXWorkerWhatThe)
{
		file("pc\sound\FINAL\welder-what.wav");  // Was what.wav

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
		localize(_silent);
}

// Welder in Club Perimeter crushed by the door
sample(SFXWorkerOhShit)
{
		file("pc\sound\FINAL\welder-ohshit1.wav");   // Was ohshit1.wav

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
		localize(_silent);
}


sample(SFXWorkerOhNo)
{
		file("pc\sound\FINAL\welder-ohno.wav");  // Was ohno.wav

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		localize(_silent);
}

/* Not used anymore
sample(SFXCopStopRightThere)
{
//		file("pc\sound\actor\cop\stopther.wav");

		speechsample(true);
	  
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}
*/

/*
sample(SFXCopPulledAGun)
{
//		file("pc\sound\actor\cop\puldagun.wav");

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
}
*/

sample(SFXCopGetBackToWork1)
{
		file("pc\sound\FINAL\blue-back2work1.wav",50);
		file("pc\sound\FINAL\blue-back2work2.wav",100);

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXCopGetBackToWork2)
{
		file("pc\sound\FINAL\blue-back2work3.wav",50);
		file("pc\sound\FINAL\blue-back2work4.wav",100);

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXCopGetBackToWork3)
{
		file("pc\sound\FINAL\blue-back2work6.wav",50);
		file("pc\sound\FINAL\blue-back2work7.wav",100);

		speechsample(true);

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

/*
sample(SFXCopOrIllKill)
{
//		file("pc\sound\actor\cop\orikill.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
}
*/

sample(SFXOrderGetHim)
{
/*	note: Saxs asked to empty because it is not needed in game!

//		file("pc\sound\actor\morders\ggethim1.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
*/
  }

sample(SFXOrderSearch)
{
/*	note: Saxs asked to empty because it is not needed in game!

//		file("pc\sound\actor\morders\gsearch1.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
*/
}

sample(SFXOrderOverThere1)
{
/*	note: Saxs asked to empty because it is not needed in game!

//		file("pc\sound\actor\morders\gthere1.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
*/
}

sample(SFXOrderYesSir1)
{
/*	note: Saxs asked to empty because it is not needed in game!

//		file("pc\sound\actor\morders\gyessir1.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
*/
}

///////////////////////////////
//		End of SAXS's AI sounds
///////////////////////////////

/*
sample(SFXManBlastHit1)
{
//		file("pc\sound\actor\panic1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(3000);
}
sample(SFXManBlastHit2)
{
//		file("pc\sound\actor\panic2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(3000);
}
*/

sample(SFXManFallToGround)
{
		file("pc\sound\actor\fall\BodyFall1.wav",33);
		file("pc\sound\actor\fall\BodyFall2.wav",66);
		file("pc\sound\actor\fall\BodyFall3.wav",100);
	
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(3000);
}

sample(SFXManPunch)
{
		file("pc\sound\actor\punch\punch1.wav",20);
		file("pc\sound\actor\punch\punch2.wav",40);
		file("pc\sound\actor\punch\punch4.wav",60);
		file("pc\sound\actor\punch\punch5.wav",80);
		file("pc\sound\actor\punch\punch8.wav",100);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		delay(20);
}

sample(SFXManNeckSnap)
{
		file("pc\sound\FINAL\blue-necksnap.wav");

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		delay(120);
		localize(_all);
}

sample(SFXPriestDrown)
{
		file("pc\sound\actor\priest\drown.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
}

sample(SFXManNeckSnap02)
{
		file("pc\sound\actor\cop\NeckSnap3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		delay(120);
}

// Getting strangled
sample(SFXManStrangled)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-choke.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-choke2.wav",100,_AIclassCop|_AIclassFemale);
	// Scientist
		file("pc\sound\FINAL\sci-lastbreath1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-lastbreath5.wav",100,_AIclassScientist);
	// Cops
		file("pc\sound\FINAL\blue-choke.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-cough3.wav",100,_AIclassCop|_AIclassMale);
	// Welder
		file("pc\sound\FINAL\welder-afterfire2.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-afterfire3.wav",100,_AIclassWorker);
	// Chots
		file("pc\sound\FINAL\chotstrangled.wav",50,_AIclassChot);
		file("pc\sound\FINAL\chot5.wav",100,_AIclassChot);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-strangle1.wav",50,_AIclassbeast);
		file("pc\sound\FINAL\behm-strangle3.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-strangle1.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-strangle2.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-strangle4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-strangle1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-strangle2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-strangle3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-strangle1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-strangle2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-strangle3.wav",100,_AIclasspimp);

	// FEMALE Dweller
		file("pc\sound\FINAL\fd-strangle1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-strangle2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-strangle4.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-strangle5.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-strangle6.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);			// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);

//		loop(FALSE);
//		tridi(TRUE);
//		rndfreq(FALSE);
//		fademin(800);
//		fademax(2800);
//		delay(120);
		localize(_all);
}




// Harpooned to the wall
sample(SFXManHarpooned)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-pain10.wav",25,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-pain11.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crawl1.wav",75,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-hit1.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-harpoon1.wav",33,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-harpoon2.wav",67,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-cough3.wav",100,_AIclassCop|_AIclassMale);
	//	Scientist
		file("pc\sound\FINAL\sci-lastbreath1.wav",25,_AIclassScientist);
		file("pc\sound\FINAL\sci-ohgod1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-pain10.wav",75,_AIclassScientist);
		file("pc\sound\FINAL\sci-burned1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-crawling1.wav",25,_AIclassWorker);
		file("pc\sound\FINAL\welder-afterfire3.wav",50,_AIclassWorker);
		file("pc\sound\FINAL\welder-afterfire4.wav",75,_AIclassWorker);
		file("pc\sound\FINAL\welder-afterfire5.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chotstrangled.wav",33,_AIclassChot);
		file("pc\sound\FINAL\chot37.wav",67,_AIclassChot);
		file("pc\sound\FINAL\chot62.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-spear1.wav",14,_AIclassAngel);
		file("pc\sound\FINAL\bob-spear2.wav",29,_AIclassAngel);
		file("pc\sound\FINAL\bob-spear3.wav",42,_AIclassAngel);
		file("pc\sound\FINAL\bob-spear4.wav",57,_AIclassAngel);
		file("pc\sound\FINAL\bob-spear5.wav",71,_AIclassAngel);
		file("pc\sound\FINAL\bob-spear6.wav",85,_AIclassAngel);
		file("pc\sound\FINAL\bob-spear7.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\actor\AllVoices\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\actor\AllVoices\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-spear2.wav",33,_AIclassbeast);
		file("pc\sound\FINAL\behm-spear3.wav",67,_AIclassbeast);
		file("pc\sound\FINAL\behm-spear4.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-spear1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-spear2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-spear3.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-spear4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-spear1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-spear2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-spear3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-spear1.wav",33,_AIclasspimp);
		file("pc\sound\FINAL\pimp-spear2.wav",67,_AIclasspimp);
		file("pc\sound\FINAL\pimp-spear3.wav",100,_AIclasspimp);

	// FEMALE Dweller
		file("pc\sound\FINAL\fd-spear1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-spear2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-spear1.wav",25,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-spear2.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-spear3.wav",75,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-spear4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(30);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(2000);

//		speechsample(true);
//		loop(FALSE);
//		tridi(TRUE);
//		rndfreq(FALSE);
//		fademin(400);
//		fademax(3000);
//		delay(120);
		localize(_all);
}



// Climb up
sample(SFXGrunt)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-hit4.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-climbon3.wav",20,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-climbon4.wav",40,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-climbon6.wav",60,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-climbon7.wav",80,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-climbon8.wav",100,_AIclassCop|_AIclassMale);
	//	Scientist
		file("pc\sound\FINAL\sci-overledge1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-overledge1.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot-overledge.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-grunt02.wav",20,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt03.wav",40,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt04.wav",60,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt05.wav",80,_AIclassAngel);
		file("pc\sound\FINAL\bob-grunt06.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",33,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-land1.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-hit6.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-land4.wav",100,_AIclasspimp);
	// FEMALE Dweller
		file("pc\sound\FINAL\fd-crawl3.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-hit1.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);

//		file("pc\sound\actor\climb\climbon3.wav",20);
//		file("pc\sound\actor\climb\climbon4.wav",40);
//		file("pc\sound\actor\climb\climbon6.wav",60);
//		file("pc\sound\actor\climb\climbon7.wav",80);
//		file("pc\sound\actor\climb\climbon8.wav",100);
//		loop(FALSE);
//		tridi(TRUE);
//		rndfreq(FALSE);
//		fademin(400);
//		fademax(3000);

		localize(_all);
}

/*
sample(SFXBobScream01)
{
//		file("pc\sound\actor\bob\scream01.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}
*/


//*******************************************

//***************
//*	BOB SAMPLE  *
//***************

// Bob saying "Whoops"
sample(SFXBobWhoops)
{
		file("pc\sound\FINAL\bob-oops2.wav");  // Was boboops2.wav

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXBobHowCanIGet)
{
		file("pc\sound\FINAL\bob-there3.wav");  // Was bobthere3.wav

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXBobEuchRats)
{
		file("pc\sound\FINAL\bob-rats1.wav");  // Was bobrats1.wav

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

/*
// Bob saying "Euew, it sticks in here!"
sample(SFXBobStinks)
{
//		file("pc\sound\FINAL\bob-smell1.wav");

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
*/

// Grunt as Bob climbs over a ledge
sample(SFXBobClimb)
{
		file("pc\sound\FINAL\bob-land2.wav");  // was bobclimb.wav

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
		flushable(0);
}

// Bob saying "BANG" when he fires his finger
sample(SFXBobBang)
{
		file("pc\sound\actor\bob\bob-bang3.wav",40);
		file("pc\sound\actor\bob\bob-bang1.wav",75);
		file("pc\sound\actor\bob\bob-bang2.wav",100);

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


// Bob blowing the tip of his finger
sample(SFXBobPhoomp)
{
		file("pc\sound\actor\bob\phoomp.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
}

// Bob flapping his wings
sample(SFXBobFlap)
{
		file("pc\sound\actor\bob\wing1.wav",25);
		file("pc\sound\actor\bob\wing2.wav",50);
		file("pc\sound\actor\bob\wing3.wav",75);
		file("pc\sound\actor\bob\wing4.wav",100);
		delay(5);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

// Bob flying into a wall
sample(SFXBobUumph)
{
		file("pc\sound\actor\bob\uumph.wav");
		delay(30);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

// Bob saying "Shes naked!"
sample(SFXBobNaked)
{
		file("pc\sound\FINAL\bob-chick5.wav");

		speechsample(true);
		
		delay(30);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


// Bob saying "Phew, that was close!"
sample(SFXBob_Close)
{
		file("pc\sound\FINAL\bob-close2.wav");

		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

//Bob saying "echo" / "too high" / "hello!" (with a delay/reverb effect)
sample(SFXBobWideRoom)
{
		file("pc\sound\FINAL\bob-ledge7.wav",50);
		file("pc\sound\FINAL\bob-ledge8.wav",100);

		speechsample(true);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

//Bob saying "Oh, it's hot in here"
sample(SFXBobHot)
{
		file("pc\sound\FINAL\bob-hot1.wav",50);
		file("pc\sound\FINAL\bob-hot2.wav",100);

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

//Bob saying "my knees hurt" / "my knees are sore" / "I'm tired of crawling"
sample(SFXBobCrawls)
{
		file("pc\sound\FINAL\bob-knee1.wav",30);
		file("pc\sound\FINAL\bob-knee2.wav",60);
		file("pc\sound\FINAL\bob-knee3.wav",100);

		speechsample(true);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


sample(SFXBobCryoMessage)
{
		file("pc\sound\FINAL\bob-mess3.wav");

		speechsample(true);
		
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXBobTripsAlarm)
{
		file("pc\sound\FINAL\bob-alarm3.wav",100);

		speechsample(true);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

//**************************************************************************

sample(SFXBirdScream1)
{
		file("pc\sound\actor\bird\falcon1.wav");
		delay(10);
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(1500);
//		fademax(3000);
}

sample(SFXBirdScream2)
{
		file("pc\sound\actor\bird\falcon2.wav");
		delay(10);
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(1500);
//		fademax(3000);
}

sample(SFXBirdSquak)
{
		file("pc\sound\actor\bird\squak.wav");
		delay(10);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(3000);
}

// Welder getting crushed by the tank
sample(SFXWorkerCrushed)
{
//		file("pc\sound\actor\mpain\combo.wav");
		file("pc\sound\FINAL\welder-crush1.wav");

		speechsample(true);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

sample(SFXChotCrushed)
{
		file("pc\sound\actor\chot\Crush4.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(3000);
}


/*sample(SFXWorkerCrushed2)
{
//		file("pc\sound\actor\mpain\Crush3.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		delay(100);
}
*/
sample(SFXWorkerPanic)
{
//		file("pc\sound\actor\mpain\chris01.wav");
		file("pc\sound\FINAL\welder-donttouch1.wav");

		speechsample(true);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

sample(SFXWorkerScream)
{
//		file("pc\sound\actor\mpain\scream01.wav");
		file("pc\sound\FINAL\welder-onfire1.wav");

		speechsample(true);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}
sample(SFXDePossess)
{
		file("pc\sound\actor\possess\deposs1.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(1500);
//		fademax(2000);
		flushable(0);
}

/*
sample(SFXPossessBeast)
{
//		file("pc\sound\actor\possess\behemoth-possessed3.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(1500);
//		fademax(2000);
}
*/

sample(SFXPossess)
{
		file("pc\sound\actor\possess\possess5.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(1500);
//		fademax(2000);
		flushable(0);
}

sample(SFXPossessHit)
{
		file("pc\sound\actor\possess\posseshit.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(1500);
//		fademax(2000);
		flushable(0);
}




sample(SFXBong)
{
		file("pc\sound\actor\bong\bubble.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
}

sample(SFXElectricShock1)
{
		file("pc\sound\actor\electric\shock.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
}

sample(SFXElectricShock2)
{
		file("pc\sound\actor\electric\zap.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
}




// Generic death
/*sample(SFXDyingMale1)
{
//		file("pc\sound\actor\mpain\dying.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}
*/

// Bob getting hurt
/*sample(SFXPainMale2)
{
//		file("pc\sound\actor\cop\yell4b.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}
*/

// General landing OOMPH!
/*sample(SFXPainMale3)
{
//		file("pc\sound\actor\cop\yell4.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}
*/


/*
sample(SFXPainMale4)
{
//		file("pc\sound\actor\mpain\ghurt3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}
*/


sample(SFXBlood2)
{
		file("pc\sound\actor\blood\blood2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		delay(25);
		flushable(0);
}



sample(SFXConcussionFlash)
{
		file("pc\sound\actor\cop\flash2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		flushable(0);
}





sample(SFXLaserOff1)
{
		file("pc\sound\actor\cop\flashoff1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
		flushable(0);
}

sample(SFXLaserStart1)
{
		file("pc\sound\actor\cop\flash1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
		flushable(0);
}



sample(SFXBongCough)
{
		file("pc\sound\actor\cough\bongcoff.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		localize(_silent);
}

// Smoking after being on fire
sample(SFXCoughReact)
{
	// Domina/Commander
		file("pc\sound\FINAL\domina-crawl1.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crawl2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-cough1.wav",25,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-cough2.wav",50,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-cough3.wav",75,_AIclassCop|_AIclassMale);
		file("pc\sound\FINAL\blue-smoker1.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
		file("pc\sound\FINAL\sci-burned1.wav",50,_AIclassScientist);
		file("pc\sound\FINAL\sci-crap1.wav",100,_AIclassScientist);
	// Welder
		file("pc\sound\FINAL\welder-cough1.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-cough2.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-afterfire5.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot-ouch.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-cough1.wav",25,_AIclassAngel);
		file("pc\sound\FINAL\bob-cough2.wav",50,_AIclassAngel);
		file("pc\sound\FINAL\bob-cough3.wav",75,_AIclassAngel);
		file("pc\sound\FINAL\bob-cough4.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-cough3.wav",33,_AIclassbeast);
		file("pc\sound\FINAL\behm-cough4.wav",67,_AIclassbeast);
		file("pc\sound\FINAL\behm-cough5.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-burned1.wav",25,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-burned2.wav",50,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-burned3.wav",75,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-burned4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-burned1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-burned4.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-burned7.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-burned1.wav",25,_AIclasspimp);
		file("pc\sound\FINAL\pimp-burned2.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-burned3.wav",75,_AIclasspimp);
		file("pc\sound\FINAL\pimp-burned4.wav",100,_AIclasspimp);

	// FEMALE Dweller
		file("pc\sound\FINAL\fd-burned1.wav",33,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-burned2.wav",67,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-burned4.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-crush1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-crush2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-crawl6.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
	
		localize(_all);
}
/*
sample(SFXCough)
{
	// Domina/Commander
//		file("pc\sound\actor\AllVoices\domina-crawl1.wav",50,_AIclassCop|_AIclassFemale);
//		file("pc\sound\actor\AllVoices\domina-crawl2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
//		file("pc\sound\actor\AllVoices\blue-cough1.wav",25,_AIclassCop|_AIclassMale);
//		file("pc\sound\actor\AllVoices\blue-cough2.wav",50,_AIclassCop|_AIclassMale);
//		file("pc\sound\actor\AllVoices\blue-cough3.wav",75,_AIclassCop|_AIclassMale);
//		file("pc\sound\actor\AllVoices\blue-smoker1.wav",100,_AIclassCop|_AIclassMale);
	// Scientist
//		file("pc\sound\actor\AllVoices\sci-burned1.wav",50,_AIclassScientist);
//		file("pc\sound\actor\AllVoices\sci-crap1.wav",100,_AIclassScientist);
	// Welder
//		file("pc\sound\actor\AllVoices\welder-cough1.wav",33,_AIclassWorker);
//		file("pc\sound\actor\AllVoices\welder-cough2.wav",67,_AIclassWorker);
//		file("pc\sound\actor\AllVoices\welder-afterfire5.wav",100,_AIclassWorker);
	// Chot
//		file("pc\sound\actor\AllVoices\chot-ouch.wav",100,_AIclassChot);
	// Bob
//		file("pc\sound\actor\Bob\bob-cough1.wav",25,_AIclassAngel);
//		file("pc\sound\actor\Bob\bob-cough2.wav",50,_AIclassAngel);
//		file("pc\sound\actor\Bob\bob-cough3.wav",75,_AIclassAngel);
//		file("pc\sound\actor\Bob\bob-cough4.wav",100,_AIclassAngel);

	// All other characters not defined yet!
//		file("pc\sound\actor\AllVoices\temp-silence.wav");

		speechsample(true);

		delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
*/

// Character on fire
sample(SFXOnFire)
{
	// Scientist
		file("pc\sound\FINAL\sci-burn1.wav",33,_AIclassScientist);
		file("pc\sound\FINAL\sci-burn2.wav",67,_AIclassScientist);
		file("pc\sound\FINAL\sci-burn3.wav",100,_AIclassScientist);
	// Domina/Commander
		file("pc\sound\FINAL\domina-crawl1.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\FINAL\domina-crawl2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\FINAL\blue-onfire1.wav",33,_AIclassCop);
		file("pc\sound\FINAL\blue-onfire2.wav",67,_AIclassCop);
		file("pc\sound\FINAL\blue-pain6.wav",100,_AIclassCop);
	// Welder
		file("pc\sound\FINAL\welder-onfire1.wav",33,_AIclassWorker);
		file("pc\sound\FINAL\welder-onfire2.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-onfire3.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\FINAL\chot32.wav",100,_AIclassChot);
	// Bob
		file("pc\sound\FINAL\bob-radiation1.wav",33,_AIclassAngel);
		file("pc\sound\FINAL\bob-radiation2.wav",67,_AIclassAngel);
		file("pc\sound\FINAL\bob-radiation3.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\FINAL\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\FINAL\behm-burn1.wav",20,_AIclassbeast);
		file("pc\sound\FINAL\behm-burn2.wav",40,_AIclassbeast);
		file("pc\sound\FINAL\behm-burn3.wav",60,_AIclassbeast);
		file("pc\sound\FINAL\behm-burn4.wav",80,_AIclassbeast);
		file("pc\sound\FINAL\behm-burn5.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\FINAL\tv-onfire2.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-onfire3.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\FINAL\tv-onfire4.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\FINAL\ho-onfire1.wav",33,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-onfire2.wav",67,_AIclassprost|_AIclassFemale);
		file("pc\sound\FINAL\ho-onfire3.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\FINAL\pimp-onfire1.wav",50,_AIclasspimp);
		file("pc\sound\FINAL\pimp-onfire4.wav",100,_AIclasspimp);

	// FEMALE Dweller
		file("pc\sound\FINAL\fd-onfire4.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\FINAL\fd-onfire5.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\FINAL\md-onfire3.wav",50,_AIclassdweller|_AIclassMale);
		file("pc\sound\FINAL\md-onfire4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		speechsample(true);

		//delay(60);		// Delay 2 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);

		localize(_all);
		flushable(0);
}


// This character sees possessed character touching buttons
sample(SFXPlayerActivatesButtonReact)
{
	// Domina/Commander
		file("pc\sound\actor\AllVoices\domina-donttouch1.wav",50,_AIclassCop|_AIclassFemale);
		file("pc\sound\actor\AllVoices\domina-donttouch2.wav",100,_AIclassCop|_AIclassFemale);
	// Scientist
		file("pc\sound\actor\AllVoices\sci-donttouch1.wav",50,_AIclassScientist);
		file("pc\sound\actor\AllVoices\sci-donttouch2.wav",100,_AIclassScientist);
	// Cops
		file("pc\sound\actor\AllVoices\blue-getaway1.wav",50,_AIclassCop);
		file("pc\sound\actor\AllVoices\blue-getaway2.wav",100,_AIclassCop);
	// Welder
		file("pc\sound\FINAL\welder-donttouch1.wav",33,_AIclassWorker);
		file("pc\sound\actor\AllVoices\welder-donttouch2.wav",67,_AIclassWorker);
		file("pc\sound\FINAL\welder-donttouch4.wav",100,_AIclassWorker);

	// Pimp Daddy
		file("pc\sound\actor\AllVoices\pimp-donttouch1.wav",33,_AIclasspimp);
		file("pc\sound\actor\AllVoices\pimp-donttouch2.wav",67,_AIclasspimp);
		file("pc\sound\actor\AllVoices\pimp-donttouch3.wav",100,_AIclasspimp);

	// All other characters not defined yet!
		file("pc\sound\FINAL\temp-silence.wav");

		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


// Door is locked
sample(SFXPlayerActivatesLockedDoorReact)
{
	// Domina/Commander
		file("pc\sound\actor\AllVoices\domina-locked5.wav",33,_AIclassCop|_AIclassFemale);
		file("pc\sound\actor\AllVoices\domina-locked1.wav",67,_AIclassCop|_AIclassFemale);
		file("pc\sound\actor\AllVoices\domina-locked2.wav",100,_AIclassCop|_AIclassFemale);
	// Cops
		file("pc\sound\actor\AllVoices\blue-door1a.wav",20,_AIclassCop);
		file("pc\sound\actor\AllVoices\blue-door1b.wav",40,_AIclassCop);
		file("pc\sound\actor\AllVoices\blue-door2.wav",60,_AIclassCop);
		file("pc\sound\actor\AllVoices\blue-door3.wav",80,_AIclassCop);
		file("pc\sound\actor\AllVoices\blue-door4.wav",100,_AIclassCop);
	// Welder
		file("pc\sound\actor\AllVoices\welder-locked1.wav",50,_AIclassWorker);
		file("pc\sound\actor\AllVoices\welder-locked2.wav",100,_AIclassWorker);
	// Chot
		file("pc\sound\actor\AllVoices\chot-no.wav",100,_AIclassChot);
	// Scientist
		file("pc\sound\actor\AllVoices\sci-jesus.wav",100,_AIclassScientist);
	// Bob
		file("pc\sound\actor\Bob\bob-locked1.wav",20,_AIclassAngel);
		file("pc\sound\actor\Bob\bob-locked4.wav",40,_AIclassAngel);
		file("pc\sound\actor\Bob\bob-locked5.wav",60,_AIclassAngel);
		file("pc\sound\actor\Bob\bob-locked6.wav",80,_AIclassAngel);
		file("pc\sound\actor\Bob\bob-locked7.wav",100,_AIclassAngel);

	// ARMORED Behemoth
//		file("pc\sound\actor\AllVoices\temp-silence.wav",100,_AIclassabeast);

	// CHOT Behemoth
//		file("pc\sound\actor\AllVoices\temp-silence.wav",100,_AIclassbeast|_AIclassChot);

	// NAKED Behemoth
		file("pc\sound\actor\AllVoices\behm-locked1.wav",33,_AIclassbeast);
		file("pc\sound\actor\AllVoices\behm-locked2.wav",67,_AIclassbeast);
		file("pc\sound\actor\AllVoices\behm-locked4.wav",100,_AIclassbeast);

	// MALE Prostitute
		file("pc\sound\actor\AllVoices\tv-locked3.wav",33,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\actor\AllVoices\tv-locked4.wav",67,_AIclassprost|_AIclassSpecial|_AIclassFemale);
		file("pc\sound\actor\AllVoices\tv-locked5.wav",100,_AIclassprost|_AIclassSpecial|_AIclassFemale);
	// FEMALE Prostitute
		file("pc\sound\actor\AllVoices\ho-locked1.wav",50,_AIclassprost|_AIclassFemale);
		file("pc\sound\actor\AllVoices\ho-locked2.wav",100,_AIclassprost|_AIclassFemale);
	// Pimp Daddy
		file("pc\sound\actor\AllVoices\pimp-locked1.wav",33,_AIclasspimp);
		file("pc\sound\actor\AllVoices\pimp-locked3.wav",67,_AIclasspimp);
		file("pc\sound\actor\AllVoices\pimp-locked5.wav",100,_AIclasspimp);

	// FEMALE Dweller
		file("pc\sound\actor\AllVoices\fd-locked1.wav",50,_AIclassdweller|_AIclassFemale);
		file("pc\sound\actor\AllVoices\fd-locked2.wav",100,_AIclassdweller|_AIclassFemale);
	// MALE Dweller
		file("pc\sound\actor\AllVoices\md-locked1.wav",33,_AIclassdweller|_AIclassMale);
		file("pc\sound\actor\AllVoices\md-locked2.wav",67,_AIclassdweller|_AIclassMale);
		file("pc\sound\actor\AllVoices\md-locked4.wav",100,_AIclassdweller|_AIclassMale);

	// All other characters not defined yet!
		file("pc\sound\actor\AllVoices\temp-silence.wav");

		delay(150);		// Delay 5 seconds
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXGenericBurn)
{
		file("pc\sound\actor\fire\fire1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		flushable(0);
}

/*

sample(SFXActorPainInFire1)
{
//		file("pc\sound\actor\fire\onfire1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXActorPainInFire2)
{
//		file("pc\sound\actor\fire\onfire2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}
*/


// Bob screaming on fire
sample(SFXBobPainInFire)
{
		file("pc\sound\actor\fire\onfire4.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
}

sample(SFXBobHand1)
{
		file("pc\sound\actor\bob\bobhand1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
}

sample(SFXBobHand2)
{
		file("pc\sound\actor\bob\bobhand2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
}


sample(SFXRatScurry)
{
		file("pc\sound\actor\rat\ratscurry.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
}

sample(SFXRat3)
{
		file("pc\sound\actor\rat\rats3.wav",50);
		file("pc\sound\actor\rat\rats6.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
}

sample(SFXFootBeast)
{
		file("pc\sound\actor\footstep\kick1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
}

sample(SFXFootStepReg)
{
		file("pc\sound\actor\footstep\footreg1.wav",25);
		file("pc\sound\actor\footstep\footreg2.wav",50);
		file("pc\sound\actor\footstep\footreg3.wav",75);
		file("pc\sound\actor\footstep\footreg4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

sample(SFXFootStepBob)
{
		file("pc\sound\actor\footstep\footbab1.wav",25);
		file("pc\sound\actor\footstep\footbab2.wav",50);
		file("pc\sound\actor\footstep\footbab3.wav",75);
		file("pc\sound\actor\footstep\footbab4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

sample(SFXFootStepFemReg)
{
		file("pc\sound\actor\footstep\heelhard1.wav",25);
		file("pc\sound\actor\footstep\heelhard2.wav",50);
		file("pc\sound\actor\footstep\heelhard3.wav",75);
		file("pc\sound\actor\footstep\heelhard4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

sample(SFXFootStepFemMet)
{
		file("pc\sound\actor\footstep\heelmetal1.wav",25);
		file("pc\sound\actor\footstep\heelmetal2.wav",50);
		file("pc\sound\actor\footstep\heelmetal3.wav",75);
		file("pc\sound\actor\footstep\heelmetal4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

sample(SFXFootStepFemCon)
{
		file("pc\sound\actor\footstep\heelconcrete1.wav",25);
		file("pc\sound\actor\footstep\heelconcrete2.wav",50);
		file("pc\sound\actor\footstep\heelconcrete3.wav",75);
		file("pc\sound\actor\footstep\heelconcrete4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}




sample(SFXFootStepBig)
{
		file("pc\sound\actor\footstep\footbig1.wav",25);
		file("pc\sound\actor\footstep\footbig2.wav",50);
		file("pc\sound\actor\footstep\footbig3.wav",75);
		file("pc\sound\actor\footstep\footbig4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

sample(SFXFootStepCon)
{
		file("pc\sound\actor\footstep\footcon1.wav",25);
		file("pc\sound\actor\footstep\footcon2.wav",50);
		file("pc\sound\actor\footstep\footcon3.wav",75);
		file("pc\sound\actor\footstep\footcon4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

sample(SFXFootStepMet)
{
		file("pc\sound\actor\footstep\footmet1.wav",25);
		file("pc\sound\actor\footstep\footmet2.wav",50);
		file("pc\sound\actor\footstep\footmet3.wav",75);
		file("pc\sound\actor\footstep\footmet4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}


sample(SFXFootStepWat)
{
		file("pc\sound\actor\footstep\footwat1.wav",25);
		file("pc\sound\actor\footstep\footwat2.wav",50);
		file("pc\sound\actor\footstep\footwat3.wav",75);
		file("pc\sound\actor\footstep\footwat4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

sample(SFXFootStepWd)
{
		file("pc\sound\actor\footstep\footwd1.wav",25);
		file("pc\sound\actor\footstep\footwd2.wav",50);
		file("pc\sound\actor\footstep\footwd3.wav",75);
		file("pc\sound\actor\footstep\footwd4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}


sample(SFXFootStepWlk)
{
		file("pc\sound\actor\footstep\footwlk1.wav",25);
		file("pc\sound\actor\footstep\footwlk2.wav",50);
		file("pc\sound\actor\footstep\footwlk3.wav",75);
		file("pc\sound\actor\footstep\footwlk4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}


// Throwing an object (grenade)
sample(SFXThrow1)
{
		file("pc\sound\actor\throwm1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}

// Throwing an object (grenade)
sample(SFXThrow2)
{
		file("pc\sound\actor\throwm2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		flushable(0);
}
sample(SFXBeastJump)
{
		file("pc\sound\actor\footstep\Smash.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
}

sample(SFXABeastJump)
{
		file("pc\sound\actor\armorsmash.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1500);
		fademax(2000);
}




sample(SFXGunTurretDoor)
{
		file("pc\sound\actor\gunturret\doorop4.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
sample(SFXGunTurretHatch)
{
		file("pc\sound\actor\gunturret\hatch.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
sample(SFXGunTurretHorizontal)
{
		file("pc\sound\actor\gunturret\turretmove.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
sample(SFXGunTurretVertical)
{
		file("pc\sound\actor\gunturret\turretmove.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
sample(SFXGunTurretWrap)
{
		file("pc\sound\actor\gunturret\turwrap.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}
sample(SFXGunTurretSteam)
{
		file("pc\sound\actor\gunturret\steam2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}

sample(SFXGunTurretFire)
{
		file("pc\sound\actor\gunturret\heavygun.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(4000);
}

sample(SFXGunTurretFireLoop)
{
		file("pc\sound\actor\gunturret\heavygun.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(4000);
}

sample(SFXGunTurretZap)
{
		file("pc\sound\background\electric\zap1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1250);
}


sample(SFXSmokePuffPuff)
{
		file("pc\sound\actor\bong\puffpuff.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		oktodrop(true);
}

sample(SFXSmokeExhale)
{
		file("pc\sound\actor\bong\exhale.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		oktodrop(true);
}

// Chots eating
sample(SFXChotGrunt)
{
		file("pc\sound\actor\chot\grunt.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
}

sample(SFXChotEatFlesh)
{
		file("pc\sound\actor\chot\Crush4.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
		oktodrop(true);
}

//TH added more cop sounds here 9-99:

//background sounds:

/*
sample(SFXSpreadOut)
{
//		file("pc\sound\actor\morders\gspread1.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(3000);
}	
*/
  
sample(SFXCop_Scratch1) //scratching crotch
{
		file("pc\sound\actor\cop\new\scratch1.wav");
		delay(60);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		oktodrop(true);
}

sample(SFXCopOhYeah) //scratching crotch
{
		file("pc\sound\actor\cop\yea2.wav");
		delay(60);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
		oktodrop(true);
}


sample(SFXPAbeastPowerUp2D)
{
		file("pc\sound\background\doors\Pnum2.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(800);
//		fademax(1250);
}

sample(SFXPAbeastStep2D)
{
		file("pc\sound\background\lift\LiftStop3.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(800);
//		fademax(1250);
}

sample(SFXABeastStretch2D)
{
		file("pc\Sound\background\terminal\poweron.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(800);
//		fademax(1250);
}

sample(SFXBooster)
{
		file("pc\Sound\actor\ripple1.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
}

sample(SFXFemaleScream)
{
		file("pc\sound\FINAL\fd-shock1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
		localize(_all);
}

sample(SFXCopLaughter)
{
		delay(150);
		file("pc\sound\FINAL\blue-laugh11.wav",33);
		file("pc\sound\FINAL\blue-laugh12.wav",66);
		file("pc\sound\FINAL\blue-laugh14.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
}

// Cops saying "Backup, backup, send backup now"
// Used in the scripted end of the internet demo
/*sample(SFXTwoCopBackUp)
{
//		file("pc\sound\actor\cop\4backup.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}
*/

// Cop saying "This is as far as you go Half-Life"
sample(SFXWarning01)
{
		file("pc\sound\actor\cop\warning\halflife.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Cop saying "You've got no business with the commander"
sample(SFXWarning02)
{
		file("pc\sound\actor\cop\warning\nobiz.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}

// Cop saying "What's the big idea moron, boy did you fuck up!"
sample(SFXWarning03)
{
		file("pc\sound\actor\cop\warning\moron.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
		localize(_all);
}


//*********************************************************************************

//		EVIL BOB SAMPLES
//      ****************

sample(SFXEvilBobLaughter)
{
		file("pc\sound\actor\EvilBob\laugh3.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
}

sample(SFXEvilBobThatWasCool)
{
		file("pc\sound\actor\EvilBob\wascool.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

//*********************************************************************************

//		PRIEST SAMPLES
//      **************

/*
sample(SFXGetOutOfMind)
{
//		file("pc\sound\actor\priest\outamind.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
}

sample(SFXWhatTroublesYou)
{
//		file("pc\sound\actor\priest\trouble.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
}
*/

//*********************************************************************************

//		SCIENTIST SAMPLES
//      *****************


sample(SFXScientistOhShit)
{
		file("pc\sound\FINAL\sci-shit1.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXScientistDontTouch)
{
		file("pc\sound\actor\scientist\sci-donttouch1.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

sample(SFXScientistScared)
{
		file("pc\sound\FINAL\sci-scared1.wav");
		delay(150);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}


sample(SFXThisJobSucks)
{
		file("pc\sound\actor\worker\jobsucks.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(1500);
		localize(_all);
}

//*********************************************************************************

//		SATAN SAMPLES
//      *************


// Satan saying "You couldn't leave well enough alone could you boy?"
sample(SFXsatanintro0)
{
		file("pc\sound\actor\Satan\20-leavealone.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

// Satan saying "Ah that was a mistake,now it's time to learn your final 
// lesson!"
sample(SFXsatanintro1)
{
		file("pc\sound\actor\Satan\21-finallesson.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

// Satan saying "Now little fool you will learn pain!"
sample(SFXsatanintro3)
{
		file("pc\sound\actor\Satan\23-learnpain.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

// Not just any pain mind you, but psychological pain as well, this 
// message before you die, I going to make you feel just absolutely terrible
// laughs...
sample(SFXsatanintro4)
{
		file("pc\sound\actor\Satan\24-notanypain.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}


// Satan saying "By my will you nimble minded fool!!!"
sample(SFXSatanByMyWill)
{
		file("pc\sound\actor\Satan\01-bymywill.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

// Satan screaming "GET AWAY!!!!"
sample(SFXSatanGetAway)
{
		file("pc\sound\actor\Satan\07-getaway.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		localize(_all);
}

sample(SFXsatanvalve1)
{
		file("pc\sound\actor\Satan\29-halfpint.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

sample(SFXsatanvalve2)
{
		file("pc\sound\actor\Satan\31-bigman.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

sample(SFXsatanvalve3)
{
		file("pc\sound\actor\Satan\32-3valve.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

sample(SFXsatanvalve4)
{
		file("pc\sound\actor\Satan\33-34-37joined.wav");

		loop(FALSE);
		tridi(FALSE);
		rndfreq(false);
//		fademin(3000);
//		fademax(4000);
		localize(_all);
}

sample(SFXSatanHurt1)
{
		file("pc\sound\actor\satan\satanhurt1.wav",16);
		file("pc\sound\actor\satan\satanhurt2.wav",33);
		file("pc\sound\actor\satan\satanhurt3.wav",50);
		file("pc\sound\actor\satan\satanhurt4.wav",66);
		file("pc\sound\actor\satan\satanhurt5.wav",83);
		file("pc\sound\actor\satan\satanhurt6.wav",100);

		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}

sample(SFXSatanDie1)
{
		file("pc\sound\actor\satan\satandie1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}



sample(SFXBloodDrain)
{
		file("pc\sound\actor\satan\blooddrain2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(2000);
}

sample(SFXCrumble1)
{
		file("pc\sound\actor\satan\crumble1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}

sample(SFXCrumble2)
{
		file("pc\sound\actor\satan\crumble2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}

sample(SFXFireRing)
{
		file("pc\sound\actor\satan\firering.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		//fademin(1500);
		//fademax(4000);
}

sample(SFXCastFireRing)
{
		file("pc\sound\actor\satan\castring.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		//fademin(1500);
		//fademax(4000);
}

sample(SFXMoonAmb)
{
		file("pc\sound\actor\satan\moonamb.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}

sample(SFXLavaAmb)
{
		file("pc\sound\actor\satan\lava1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(2500);
		fademax(5000);
}

sample(SFXSatanRock)
{
		file("pc\sound\actor\satan\satanrock.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(4000);
}


sample(SFXSoulWeapon)
{
		file("pc\sound\actor\satan\soulweapon.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		//fademin(1000);
		//fademax(4000);
}


sample(SFXFootSatan)
{
		file("pc\sound\actor\footstep\SatanStep1.wav",25);
		file("pc\sound\actor\footstep\SatanStep2.wav",50);
		file("pc\sound\actor\footstep\SatanStep3.wav",75);
		file("pc\sound\actor\footstep\SatanStep4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(1500);
}



//*********************************************************************************

//		DOMINA SAMPLES
//      **************


// Donina saying on Walkie Talkie "Gun 17, why have you armed?"
sample(SFXDominaWarning01)
{
		file("pc\sound\actor\AllVoices\domina-gun17.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

// Donina saying on Walkie Talkie "Come on Ilsa, talk to me"
sample(SFXDominaWarning02)
{
		file("pc\sound\actor\AllVoices\domina-ilsa.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

// Donina saying on Walkie Talkie "Whoever you are, you're dead"
sample(SFXDominaWarning03)
{
		file("pc\sound\actor\AllVoices\domina-whoever.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

// Donina saying on Walkie Talkie "Looks like weve got some trouble!"
sample(SFXDominaWarning04)
{
		file("pc\sound\actor\AllVoices\domina-trouble.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

//*********************************************************************************

//		SUBGIRL SAMPLES
//      ***************
sample(SFXSubgirlHover)
{
		file("pc\sound\actor\ssgirl\Magnetic6.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1500);
}



//*********************************************************************************


//		COP SAMPLES
//      ***********


sample(SFXCopBlueLastLonger)
{
		file("pc\sound\FINAL\blue-mock30.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		localize(_all);
}

sample(SFXCopComeHere)
{
		file("pc\sound\FINAL\blue-comehere2.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		localize(_all);
}
sample(SFXCopComeHere02)
{
		file("pc\sound\FINAL\blue-comehere1.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		localize(_all);
}
sample(SFXCopComeHere03)
{
		file("pc\sound\FINAL\blue-comehere4.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		localize(_all);
}
//Bob saying,"i can't use this."
sample(SFXCantUse1)
{
		file("pc\sound\actor\Bob\bob-cant1.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

//////////////////////////////////
//		CUTSCENE SAMPLES		//
//////////////////////////////////
/*
sample(SFXSatanHologram)
{
//		file("pc\sound\Final\satan-hologram.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXBobGodDialogue)
{
//		file("pc\sound\Final\bob-god.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}
*/
