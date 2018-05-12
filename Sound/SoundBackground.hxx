
///////////////////////
////////  2D   ////////
///////////////////////

sample(SFXPimpLiftLoop)
{
		file("pc\sound\background\lift\servo1b.wav");
		loop(TRUE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXValidFunction)
{
		file("pc\sound\background\triggers\console.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXInValidFunction)
{
		file("pc\sound\background\invalid1.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXActivateComp)
{
		file("pc\sound\background\terminal\NoCPU2.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXAccessOk)
{
		file("pc\sound\background\triggers\access2.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXSmlDoor)
{
		file("pc\sound\background\doors\smalldr.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXLiftHatchLoop)
{
		file("pc\sound\background\doors\HatchL.WAV");
		loop(TRUE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXPimpCart)
{
		file("pc\sound\background\terminal\pimpcart.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXPowerOnline)
{
		file("pc\sound\background\terminal\online1.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXWindWoosh)
{
		file("pc\sound\background\vent\woosh.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXLightsOn)
{
		file("pc\Sound\background\terminal\PwUp.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
}

sample(SFXLightsOff)
{
		file("pc\Sound\background\terminal\PwDn.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
}

sample(SFXBobDark)
{
		file("pc\sound\Actor\bob\bob-fog3.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}



sample(SFXScreenWipe1)
{
		file("pc\sound\INTERFACE\screenwipe1.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXScreenWipe2)
{
		file("pc\sound\INTERFACE\screenwipe2.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}




///////////////////////
////////  3D   ////////
///////////////////////

sample(SFXTeleportLoop)
{
		file("pc\SOUND\BACKGROUND\FIELDS\magnetic5.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(3000);
}

sample(SFXClawMove)
{
		file("pc\sound\background\lift\servo1b.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(3000);
}


sample(SFXVidBall)
{
		file("pc\sound\background\TERMINAL\fourball.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(3000);
}

sample(SFXUnLockDoor)
{
		file("pc\sound\background\Doors\opndr1_1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(3000);
}

sample(SFXBigDoorSlamShut)
{
		file("pc\sound\background\Doors\Dclose1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(3000);
		fademax(6000);
}

sample(SFXBarrelRoll)
{
		file("pc\sound\background\BarrelRoll.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1000);
}

sample(SFXTankIdle)
{
		file("pc\sound\background\Tank\TankIdle.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(5000);
}

sample(SFXCabEngine)
{
		file("pc\sound\background\Tank\engine.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
}

sample(SFXTruckFall)
{
		file("pc\sound\background\Tank\truckfall.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
}

sample(SFXCabTiresScreech)
{
		file("pc\sound\background\Tank\tires.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(2000);
		fademax(5000);
}

sample(SFXCabCollisionAndTire)
{
		file("pc\sound\background\Tank\collision01.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(3000);
}

sample(SFXCabCollision)
{
		file("pc\sound\background\Tank\collision02.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(3000);
}

sample(SFXCabRevsUp)
{
		file("pc\sound\background\Tank\cab-enginerev01.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(2000);
		fademax(5000);
}

sample(SFXCabRevsUpBig)
{
		file("pc\sound\background\Tank\engineloop3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(2000);
		fademax(5000);
}




sample(SFXBurningFlesh)
{
		file("pc\sound\background\Flames\firecrak.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(300);
		fademax(1000);
		oktodrop(true);
}

sample(SFXCoolingFan)
{
		file("pc\sound\background\vent\fan2.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1200);
		fademax(3000);
}

sample(SFXSmallFan)
{
		file("pc\sound\background\vent\fan2.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(100);
		fademax(200);
}


sample(SFXAirFans)
{
		file("pc\sound\background\vent\fan1.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(2000);
}

sample(SFXFenetre)
{
		file("pc\sound\background\doors\doorop3.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(2000);
}

sample(SFXLockedSound)
{
		file("pc\sound\background\doors\locked.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(2000);
}

sample(SFXPneumatik)
{
		file("pc\sound\background\doors\Pnum2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXPneumatik2)
{
		file("pc\sound\background\doors\Hatch.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXSplash)
{
	file("pc\sound\background\water\splash2.wav");
	loop(FALSE);
	tridi(TRUE);
	rndfreq(TRUE);
	fademin(500);
	fademax(2000);
}

sample(SFXPourWater)
{
	file("pc\sound\background\water\pour.wav");
	loop(FALSE);
	tridi(TRUE);
	rndfreq(TRUE);
	fademin(1000);
	fademax(2500);
}

sample(SFXHeavyWater)
{
		file("pc\sound\background\water\hvwater.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(3000);
}

sample(SFXRadiationPool)
{
		file("pc\sound\background\water\bubbles2.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(2000);
		oktodrop(true);
}

sample(SFXRipple)
{
		file("pc\sound\background\fields\plasglas.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
	//	fademin(100);
	//	fademax(800);
		delay(30);
}

sample(SFXFieldHumLoop)
{
		file("pc\sound\background\fields\hum7.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
}

sample(SFXHumTeleport)
{
		file("pc\sound\background\fields\hum7.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(4000);
}

sample(SFXRadGlassOff)
{
		file("pc\sound\background\fields\error9.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
		delay(150);
}

sample(SFXFieldHumStop)
{
		file("pc\sound\background\fields\tractdown2.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
}

sample(SFXRipple2)
{
		file("pc\sound\background\fields\ripple5.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(3500);
}

sample(SFXWorkerKneelCrush)
{
		file("pc\sound\actor\worker\crushed.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(3000);
}

sample(SFXDroidHover)
{
		file("pc\sound\background\droid\hover.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2200);
}

sample(SFXDroidVO)
{
		file("pc\sound\background\droid\dvo01.wav",16);
		file("pc\sound\background\droid\dvo02.wav",33);
		file("pc\sound\background\droid\dvo03.wav",50);
		file("pc\sound\background\droid\dvo04.wav",67);
		file("pc\sound\background\droid\dvo05.wav",83);
		file("pc\sound\background\droid\dvo06.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(600);
		fademax(2000);
		localize(_silent);
}


sample(SFXDropBattery)
{
		file("pc\sound\background\droid\ripple2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2000);
}

sample(SFXCapsuleIdle)
{
		file("pc\sound\background\lift\capidle.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
		oktodrop(true);
}

sample(SFXTrapDoorStart)
{
		file("pc\sound\background\lift\TDrSt.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(3000);
}

sample(SFXTrapDoorLoop)
{
		file("pc\sound\background\lift\TDrLp.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(3000);
}

sample(SFXTrapDoorStop)
{
		file("pc\sound\background\lift\TDrSp.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(3000);
}

sample(SFXIndLiftStart)
{
		file("pc\sound\background\lift\SLftStr.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
}

sample(SFXIndLiftLoop)
{
		file("pc\sound\background\lift\SLftLp.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
}

sample(SFXIndLiftStop)
{
		file("pc\sound\background\lift\SLftStp.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
}

sample(SFXCapsuleLaunch)
{
		file("pc\sound\background\lift\capgo.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(3000);
		fademax(6000);
}

sample(SFXFactLift)
{
		file("pc\sound\background\lift\Liftfact.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXBehemothAmbient)
{
		file("pc\Sound\background\Behemoth\condback.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXSmallSparks)
{
		file("pc\Sound\background\Electric\Spark1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(800);
}

sample(SFXSmallSparks02)
{
		file("pc\Sound\background\Electric\Spark1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(2000);
		fademax(3000);
}

sample(SFXScanHumm)
{
		file("pc\Sound\background\Electric\Elechum3.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(1800);
}

sample(SFXScanHumm02)
{
		file("pc\Sound\background\Electric\Elechum2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
}

sample(SFXRingZap)
{
		file("pc\Sound\background\Electric\holo2.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(2000);
}


sample(SFXLaserAmbient)
{
		file("pc\Sound\background\Electric\lazamb.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(600);
		fademax(1500);
}

sample(SFXElecFenceBlue)
{
		file("pc\Sound\background\Electric\electrical3.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(600);
		fademax(1500);
}


sample(SFXElectricQuiet)
{
		file("pc\Sound\background\Electric\ZzapRip.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXPowerRestored)
{
		file("pc\Sound\background\terminal\poweron.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXPumpPower)
{
		file("pc\Sound\background\terminal\PwDn.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(3000);
}


sample(SFXCountDown)
{
		file("pc\Sound\background\terminal\error5.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1250);
}

sample(SFXBleep)
{
		file("pc\Sound\background\terminal\error5.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1250);
}

sample(SFXGlobeIdle)
{
		file("pc\Sound\background\terminal\globe1.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
}

sample(SFXPumpPowerUp)
{
		file("pc\Sound\background\terminal\PwUp.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(3000);
}

sample(SFXLightning)
{
		file("pc\Sound\background\Electric\zap5.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXElecAmbient)
{
		file("pc\Sound\background\Electric\Elecfiz2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
}


sample(SFXThunder1)
{
		file("pc\Sound\background\Thunder\thunder4.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(3000);
		delay(100);
}

sample(SFXThunder2)
{
		file("pc\Sound\background\Thunder\thunder1.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(3000);
		delay(100);
}

sample(SFXSewerHammer)
{
		file("pc\Sound\background\Hammer\Hammer2.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(3000);
}

sample(SFXPiston)
{
		file("pc\Sound\background\Hammer\Hammer2.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(1500);
}


sample(SFXSoftGrinder)
{
		file("pc\Sound\background\Hammer\sftgrd.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(2200);
}

sample(SFXSewerPile1)
{
		delay(50);
		file("pc\Sound\background\Hammer\Pile1.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXSewerPile2)
{
		file("pc\Sound\background\Hammer\Pile2.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXShaftRotate)
{
		file("pc\Sound\background\Shaft\Rotate2.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXShaftRotate2)
{
		file("pc\Sound\background\Shaft\Rotate3.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXShaftLoop)
{
		file("pc\Sound\background\Shaft\Shaft.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(2000);
}

sample(SFXShaftSpecial)
{
		file("pc\Sound\background\Shaft\Shaft.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(300);
		fademax(2200);
}

sample(SFXShaftSpecial2)
{
		file("pc\Sound\background\Shaft\Shaft.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(300);
		fademax(3000);
}


sample(SFXShaftLock)
{
		file("pc\Sound\background\Shaft\ShaftLock.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXElecShock)
{
		file("pc\Sound\background\Electric\zap2.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXTeslaCoil)
{
		file("pc\Sound\background\Electric\zap2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(500);
		fademax(2000);
}

sample(SFXBreathing)
{
		file("pc\Sound\background\Behemoth\bbreathe.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXBehemothAngry)
{
		file("pc\Sound\background\Behemoth\bangry.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2500);
}

sample(SFXBehemothLandSpecial)
{
		file("pc\Sound\background\flames\explo11.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2500);
}

sample(SFXBehemothChest)
{
		file("pc\Sound\background\Behemoth\bchest2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2500);
}

sample(SFXBehemothScream)
{
		file("pc\Sound\background\Behemoth\bscream2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2500);
}

sample(SFXBehemothAngerScream)
{
		file("pc\Sound\background\Behemoth\beast1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2500);
}

sample(SFXBehemothLeaps)
{
		file("pc\Sound\background\Behemoth\flash3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(2500);
}

sample(SFXOpenLid)
{
		file("pc\sound\background\droid\c_unit.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXScanningAmbient)
{
		file("pc\sound\background\terminal\power1.WAV");
		loop(TRUE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXActivate1)
{
		file("pc\sound\background\triggers\access3.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}



sample(SFXOpenLock)
{
		file("pc\sound\background\droid\lock.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXOpenPipe)
{
		file("pc\sound\background\droid\pipe.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXPipeRotate)
{
		file("pc\sound\background\droid\fan.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXClawOpen)
{
		file("pc\sound\background\droid\clawopen.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXClawSpin)
{
		file("pc\sound\background\droid\clawspin.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXWallHit)
{
		file("pc\sound\background\droid\crash.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXWepDispenser)
{
		file("pc\sound\background\doors\door.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXWepPlate)
{
		file("pc\sound\background\droid\door.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXWepDispenserArm)
{
		file("pc\sound\background\doors\mecarm.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
//		fademin(100);
//		fademax(3000);
}

sample(SFXTankLift)
{
		file("pc\sound\background\terminal\tankspec.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1000);
}

sample(SFXVaultOpen)
{
		file("pc\sound\background\doors\dovaop1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXVaultMove)
{
		file("pc\sound\background\doors\dovamo1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXVaultClose)
{
		file("pc\sound\background\doors\dovacl1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXRustDoorOpen)
{
		file("pc\sound\background\doors\RustOpen.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
}

sample(SFXRustDoorLoop)
{
		file("pc\sound\background\doors\RustLoop3.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
}

sample(SFXRustDoorClose)
{
		file("pc\sound\background\doors\RustShut.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1500);
		fademax(3000);
}

sample(SFXRustDoorClose2)
{
		file("pc\sound\background\doors\RustShut2.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXDoOp1)
{
		file("pc\sound\background\doors\doop1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXDoOp2)
{
		file("pc\sound\background\doors\doop2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXDoOp9)
{
		file("pc\sound\background\doors\doorop9.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXDoMo1)
{
		file("pc\sound\background\doors\domo1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXDoMo2)
{
		file("pc\sound\background\doors\domo2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXDoCl1)
{
		file("pc\sound\background\doors\docl1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXDoCl2)
{
		file("pc\sound\background\doors\docl2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXVent2)
{
		file("pc\sound\background\vent\fvent2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXVentSmall)
{
		file("pc\sound\background\vent\gvent3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXVent2loop)
{
		file("pc\sound\background\vent\fvent2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(200);
		fademax(1000);
}

sample(SFXVent2loop2D)
{
		file("pc\sound\background\vent\fvent2.wav");
		loop(TRUE);
		tridi(FALSE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXTriggerMonitor)
{
		file("pc\sound\background\triggers\burnout.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXScanPlateOn)
{
		file("pc\sound\background\triggers\DPad01.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
}

sample(SFXSirenAlert)
{
		file("pc\sound\background\triggers\siren2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1000);
		fademax(3000);
}

sample(SFXSirenAlertSmall)
{
		file("pc\sound\background\triggers\siren2.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1000);
}

sample(SFXFlamesBurning)
{
		file("pc\sound\background\flames\fireburn.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
}

sample(SFXFlamesBurning2)
{
		file("pc\sound\background\flames\fire6.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
}

sample(SFXDoorVault)
{
		file("pc\sound\background\doors\vaultdoor.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}


sample(SFXDoorOpen9)
{
		file("pc\sound\background\doors\dopen9.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		//fademin(100);
		//fademax(1500);
}

sample(SFXBigHit)
{
		file("pc\sound\background\lift\bighit2.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		fademin(100);
		fademax(1500);
}

sample(SFXElectric2)
{
		file("pc\sound\background\electric\zzap_hum.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXElectric3)
{
		file("pc\sound\background\electric\ElecWa2.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXElectric4)
{
		file("pc\sound\background\electric\ElecWa1.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(2000);
}

sample(SFXElectric5)
{
		file("pc\sound\background\electric\Zzap.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		oktodrop(true);
}

sample(SFXZap)
{
		file("pc\sound\background\electric\zap4.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXZap02)
{
		file("pc\sound\background\electric\eleczap1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXNeonLight)
{
		file("pc\sound\background\electric\Neon3.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXLiftGrind)
{
		file("pc\sound\background\lift\liftgrind.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
}

sample(SFXLiftBroken)
{
		file("pc\sound\background\lift\Liftbk.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
}

sample(SFXSmallLiftStop)
{
		file("pc\sound\background\lift\LiftStop2.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXHudLiftStart)
{
		file("pc\sound\background\lift\Blftsrt.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(3000);
}

sample(SFXHudLiftLoop)
{
		file("pc\sound\background\lift\Blftlop.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(3000);
}

sample(SFXHudLiftStop)
{
		file("pc\sound\background\lift\Blftstp.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(3000);
}

sample(SFXSmallLiftStop2)
{
		file("pc\sound\background\lift\LiftStop3.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
	//	fademin(100);
	//	fademax(1500);
}

sample(SFXClutchCap)
{
		file("pc\sound\background\lift\LiftStop3.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(800);
		fademax(3000);
}

sample(SFXLiftStart)
{
		file("pc\sound\background\lift\liftstrt.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXLiftMove)
{
		file("pc\sound\background\lift\lftloop1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXLiftEnd)
{
		file("pc\sound\background\lift\lftend1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXHangerLift)
{
		file("pc\sound\background\lift\BigLifts3.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(2000);
}

sample(SFXGlass)
{
		file("pc\sound\background\glass\glass1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXGlassLarge)
{
		file("pc\sound\background\glass\glass1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(1400);
		fademax(3600);
}


sample(SFXGlassPlink)
{
		file("pc\sound\background\glass\plink1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXLatch2)
{
		file("pc\sound\background\doors\latch4.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(TRUE);
		//fademin(400);
		//fademax(1500);
}


sample(SFXLatch3)
{
		file("pc\sound\background\doors\latch2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXBlenderStart)
{
		file("pc\SOUND\BACKGROUND\Grinder\blendermix1st.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXBlenderLoop1)
{
		file("pc\SOUND\BACKGROUND\Grinder\blendermotor.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXBlenderLoop2)
{
		file("pc\SOUND\BACKGROUND\Grinder\blenderloop1.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXBlenderEnd)
{
		file("pc\SOUND\BACKGROUND\Grinder\blendermixend.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}


///////////////////
///////////////////
///////////////////
///////////////////

//balhh...
sample(SFXLatch1)
{
		file("pc\sound\background\doors\latch1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXLatchSpecial)
{
		file("pc\sound\background\doors\latch3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}

sample(SFXNeonLight2)
{
		file("pc\Sound\background\Electric\Neon3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(300);
		fademax(1600);
}


sample(SFXSparks)
{
		file("pc\Sound\background\Electric\Elecfiz2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(300);
		fademax(1200);
}


sample(SFXHeli)
{
		file("pc\SOUND\BACKGROUND\Chopper\Helistat.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(2000);
}

sample(SFXHeli2)
{
		file("pc\SOUND\BACKGROUND\Chopper\Helistat.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(2000);
}


sample(SFXShipLaunch)
{
		file("pc\SOUND\BACKGROUND\Chopper\shiplaunch-12.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		//fademin(400);
		//fademax(2000);
}

sample(SFXWeaponMovement)
{
//		file("pc\sound\background\droid\clawspin.wav");
		file("pc\sound\background\doors\hatchl.wav");
		loop(true);
		tridi(true);
		rndfreq(TRUE);
		fademin(300);
		fademax(1000);
}

sample(SFXHatchLoop)
{
		file("pc\sound\background\doors\hatchl.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1200);
}

sample(SFXHatchEnd)
{
		//file("pc\sound\background\doors\docl1.wav");
		file("pc\sound\background\doors\hatch.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1200);
}

sample(SFXWeaponCharge)
{
		file("pc\Sound\background\terminal\globe1.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(300);
		fademax(1200);
}

sample(SFXLabBreech)
{
		file("pc\Sound\Voices\Computer\cpu-labbreech.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1200);

		localize(_all);
}

sample(SFXLabDenied)
{
		file("pc\Sound\Voices\Computer\cpu-labdenied.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1200);
		localize(_all);
}

sample(SFXLabGranted)
{
		file("pc\Sound\Voices\Computer\cpu-labgranted.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1200);
		localize(_all);
}

sample(SFXLabTech)
{
		file("pc\Sound\Voices\Computer\cpu-labtech.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(300);
		fademax(1200);
		localize(_all);
}

sample(SFXBattlFin)
{
		file("pc\Sound\Background\Triggers\battlfin.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(600);
		fademax(1600);
		localize(_silent);
}

sample(SFXAccess3)
{
		file("pc\Sound\Background\Triggers\Access3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(600);
		fademax(1600);
}

sample(SFXWeaponScan)
{
		file("pc\Sound\Background\Terminal\weaponscan.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(600);
		fademax(1600);
}


sample(SFXDwarfChant)
{
		file("pc\sound\actor\AllVoices\chot32.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(600);		//these numbers are impossible to tweak! =(
		fademax(2500);		//these numbers are impossible to tweak! =(
}

sample(SFXSatanTakeoverFlic)
{
	file("pc\sound\BACKGROUND\satantakeover11.wav");
	loop(FALSE);
	tridi(TRUE);
	rndfreq(FALSE);
	fademin(800);
	fademax(2500);
	localize(_all);
}

sample(SFXConflictFlic)
{
	file("pc\sound\BACKGROUND\conflict11.wav");
	loop(FALSE);
	tridi(TRUE);
	rndfreq(FALSE);
	fademin(800);
	fademax(2500);
	localize(_all);
}

sample(SFXMaxFlic)
{
	file("pc\sound\BACKGROUND\max11.wav");
	loop(FALSE);
	tridi(TRUE);
	rndfreq(FALSE);
	fademin(800);
	fademax(2500);
}


///////////////////
// LOTTO SAMPLES //  (don't ask me...)
///////////////////

sample(SFXLotto01)
{
		file("pc\Sound\Voices\Lotto\animal_meat.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto02)
{
		file("pc\Sound\Voices\Lotto\beautiful_view.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto03)
{
		file("pc\Sound\Voices\Lotto\clean_air.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto04)
{
		file("pc\Sound\Voices\Lotto\dignity.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto05)
{
		file("pc\Sound\Voices\Lotto\hope.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto06)
{
		file("pc\Sound\Voices\Lotto\ideas.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto07)
{
		file("pc\Sound\Voices\Lotto\leisure_time.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto08)
{
		file("pc\Sound\Voices\Lotto\original_thought.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto09)
{
		file("pc\Sound\Voices\Lotto\popularity.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto10)
{
		file("pc\Sound\Voices\Lotto\rocks.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto11)
{
		file("pc\Sound\Voices\Lotto\stuff.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXLotto12)
{
		file("pc\Sound\Voices\Lotto\will_to_live.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXCrux)
{
		file("pc\Sound\Background\cruxvid\cruxvid.wav");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		oktodrop(true);
}

sample(SFXPuking)
{
		delay(200);
		file("pc\Sound\Background\puke\puke1.wav",30);
		file("pc\Sound\Background\puke\puke2.wav",60);
		file("pc\Sound\Background\puke\puke3.wav",100);
		loop(FALSE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(1500);
}

sample(SFXToiletFlush1)
{
		delay(300);
		file("pc\Sound\Background\puke\toiletclog1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2000);
}

sample(SFXToiletFlush2)
{
		delay(300);
		file("pc\Sound\Background\puke\toiletclog2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2000);
}

sample(SFXToiletFlush3)
{
		delay(300);
		file("pc\Sound\Background\puke\toiletflush.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2000);
}	

sample(SFXBinary)
{
		file("pc\SOUND\BACKGROUND\TERMINAL\binary.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(300);
		fademax(800);
}

sample(SFXCurtains)
{
		file("pc\SOUND\BACKGROUND\DOORS\curtains.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(3000);
}

sample(SFXRCoasterClimb)
{
		file("pc\Sound\background\RCoaster\RCoasterClimb.WAV");
		loop(TRUE);
		tridi(TRUE);
		rndfreq(TRUE);
		fademin(400);
		fademax(3000);
}
