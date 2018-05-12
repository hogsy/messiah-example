
///////////////////////
////////  3D   ////////
///////////////////////

sample(SFXMaserShot)
{
		file("pc\sound\weapon\masershot.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(4000);
		flushable(0);
}

sample(SFXSplosh)
{
		file("pc\sound\weapon\splosh.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(3000);
		delay(30);
}

sample(SFXTurretPowerUp)
{
		file("pc\sound\weapon\turpowerup.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}

sample(SFXTurretPowerDown)
{
		file("pc\sound\weapon\turpowerdown.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}


sample(SFXTurretFire)
{
		file("pc\sound\weapon\turretfire.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(4000);
}

sample(SFXTurretHit)
{
		file("pc\sound\weapon\turrethit.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(4000);
}

sample(SFXMaser)
{
		file("pc\sound\weapon\magnetic5.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(4000);
		flushable(0);
}
 
sample(SFXABeastFire)
{
		file("pc\sound\weapon\beastfire.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(4000);
		flushable(0);
}

sample(SFXABeastShoot)
{
		file("pc\sound\weapon\mortar.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(4000);
		flushable(0);
}

sample(SFXMaserPower)
{
		file("pc\sound\actor\maserpower.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(4000);
		flushable(0);
}

sample(SFXPriestPower)
{
		file("pc\sound\actor\priestpower.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(4000);
		flushable(0);
}

sample(SFXPriestFire)
{
		file("pc\sound\actor\ripple3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(4000);
		flushable(0);
}

sample(SFXRiotShield)
{
		file("pc\sound\weapon\riotshld.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		delay(60);
		flushable(0);
}

sample(SFXRadioactive)
{
		file("pc\sound\weapon\botcam1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2000);
}

sample(SFXShatter)
{
		file("pc\sound\weapon\woodexp2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2000);
		flushable(0);
}


sample(SFXDistortion)
{
		file("pc\sound\weapon\grenade\rectum1.wav");
		loop(FALSE);
		tridi(FALSE);		//TRUE
		rndfreq(TRUE);
		//fademin(800);
		//fademax(5000);
		flushable(0);
}

sample(SFXBuzzSawGrinder)
{
		file("pc\sound\weapon\buzzsaw.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(2000);
		delay(20);
		flushable(0);
}

sample(SFXPAKFire)
{
		file("pc\sound\weapon\Pakshot.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXPAKFly)
{
		file("pc\sound\weapon\pakfly.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
		flushable(0);
}

sample(SFXPAKHit)
{
		file("pc\sound\weapon\pakhit.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXPAKSpin)
{
		file("pc\sound\weapon\chotgunspin.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
		flushable(0);
}

sample(SFXJumpBettyGrenade)
{
		file("pc\sound\weapon\grenade\grenade4.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXStickEmGrenade)
{
		file("pc\sound\weapon\grenade\stickem.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		delay(90);
		flushable(0);
}

sample(SFXConcGrenade)
{
		file("pc\sound\weapon\grenade\flash.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		flushable(0);
}

sample(SFXGrenadeTimer)
{
		file("pc\sound\weapon\grenade\grendtim.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXPumpGunShell)
{
		file("pc\sound\weapon\shells\gunshell1.wav",33);
		file("pc\sound\weapon\shells\gunshell2.wav",67);
		file("pc\sound\weapon\shells\gunshell3.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(600);
		fademax(2000);
		delay(45);
		flushable(0);
}

sample(SFXPumpGunFire)
{
		file("pc\sound\weapon\pumpgun\fire.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXweapontorch1)
{
		file("pc\sound\weapon\torch\torchlit.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXweapontorch2)
{
		file("pc\sound\weapon\torch\torchlp.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
		flushable(0);
}				

sample(SFXreload)
{
		file("pc\sound\weapon\reload\reload.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXreload1)
{
		file("pc\sound\weapon\reload\reload1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXreloadTorch)
{
		file("pc\sound\weapon\reload\torchcock.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}				







sample(SFXWeaponDrop1)
{
		file("pc\sound\weapon\dropgun1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXWeaponIntoCombat)
{
		file("pc\sound\weapon\weapon1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXLowOnAmmo)
{
		file("pc\sound\background\triggers\lowammo.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(2000);
		delay(90);
		flushable(0);
}

sample(SFXLowOnHealth)
{
		file("pc\sound\background\triggers\lowhealth.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(2000);
		delay(90);
		flushable(0);
}


sample(SFXWeaponPickUp)
{
		file("pc\sound\weapon\weapon2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXWeaponEmpty)
{
		file("pc\sound\weapon\ammo\empty.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		delay(15);
		flushable(0);
}

sample(SFXWeaponAmmo)
{
		file("pc\sound\weapon\ammo\ammo1.wav",33);
		file("pc\sound\weapon\ammo\ammo2.wav",67);
		file("pc\sound\weapon\ammo\ammo3.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}


sample(SFXGrenadeBounce)
{
		file("pc\sound\weapon\grenade\harphit1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXGrenadeExplode)
{
		file("pc\sound\weapon\xplode\explo11.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(4000);
		flushable(0);
}

sample(SFXSmallExplode)
{
		file("pc\sound\weapon\bazooka\mtlexp1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(3000);
		flushable(0);
}

sample(SFXBazookaExplode)
{
		file("pc\sound\weapon\xplode\explo14.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(4000);
		flushable(0);
}

sample(SFXGunTurretExplode)
{
		file("pc\sound\weapon\xplode\explo8.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(4000);
		flushable(0);
}

sample(SFXBazookaLaunch1)
{
		file("pc\sound\weapon\bazooka\Rocket3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXBazookaLaunch2)
{
		file("pc\sound\weapon\bazooka\bazooka.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXBazookaFly)
{
		file("pc\sound\weapon\bazooka\Rocketlp.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXFlameThrowerIdle)
{
		file("pc\sound\weapon\flamethrower\flameidle1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXFlameThrowerIgnite)
{
		file("pc\sound\weapon\flamethrower\flameon1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXFlameThrowerRoast)
{
		file("pc\sound\weapon\flamethrower\flameThr.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXHarpoonLaunch)
{
		file("pc\sound\weapon\harpoon\woodexp1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXHarpoonHitActor)
{
		file("pc\sound\weapon\harpoon\bodywall.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXHarpoonHitWall)
{
		file("pc\sound\weapon\harpoon\harphit5.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(4000);
		flushable(0);
}


sample(SFXHitActor7)
{
		file("pc\sound\weapon\hitactor\bullper5.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
		delay(30);
		flushable(0);
}

sample(SFXMaimerFire)
{
		file("pc\sound\weapon\maimer\maimer.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXMachineGunFire)
{
		file("pc\sound\weapon\MachineGun\machgun4.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(4000);
		flushable(0);
}
sample(SFXMachineGunFire2)
{
		file("pc\sound\weapon\MachineGun\machgun2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXMachineGunPing0)
{
		file("pc\sound\weapon\maimer\maimhit.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXMaimerPing)
{
		file("pc\sound\weapon\Maimer\maimhit2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		flushable(0);
}

sample(SFXRicochetMetal)
{
		file("pc\sound\weapon\machinegun\ricmet1.wav",50);
		file("pc\sound\weapon\MachineGun\ricco4.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		delay(15);
		flushable(0);
}


sample(SFXRicochetWood)
{
		file("pc\sound\weapon\machinegun\ricwd5.wav",50);
		file("pc\sound\weapon\MachineGun\ricwd6.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		delay(15);
		flushable(0);
}

sample(SFXRicochetConc)
{
		file("pc\sound\weapon\machinegun\ricwd1.wav",50);
		file("pc\sound\weapon\MachineGun\ricwd2.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(4000);
		delay(15);
		flushable(0);
}


sample(SFXBulletHitPlasmaWall)
{
		file("pc\sound\weapon\plasmashield.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
		flushable(0);
}


sample(SFXMeatCutterRev)
{
		file("pc\sound\weapon\Meatcutter\sawrev2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXMeatCutterIdle)
{
		file("pc\sound\weapon\Meatcutter\sawidle1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}

sample(SFXMeatCutterCut)
{
		file("pc\sound\weapon\Meatcutter\sawcut2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
		flushable(0);
}
