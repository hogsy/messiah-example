
///////////////////////
////////  2D   ////////
///////////////////////

////////////////////////////
sample(SFXChotConverge)
{
		file("pc\sound\voices\computer\cpu-chotact2.wav");  // was chotst2.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(60);
		localize(_all);
}

sample(SFXChotEscape)
{
		file("pc\sound\voices\computer\escape.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(60);
		localize(_silent);
}


sample(SFXCommStu)
{
		file("pc\sound\voices\computer\CommStu.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(60);
		localize(_all);
}

sample(SFXWhatHappened)
{
		file("pc\sound\voices\computer\whhpn2.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(60);
		localize(_all);
}


sample(SFXAccessDenied)
{
		file("pc\sound\voices\computer\cylon6c.wav");  // was acdenied.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(60);
		localize(_all);
}

sample(SFXAlertReset)
{
		file("pc\sound\voices\computer\cpu-alertreset.wav");  // was alert_reset.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXEvilLaugh)
{
		file("pc\sound\voices\laughter\laugh02.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(150);				//temp ...get rid of it!!
}

sample(SFXLiftActivated)
{
		file("pc\sound\voices\computer\cpu-liftact.wav");  // was liftact.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXTransferSector2)
{
		file("pc\sound\voices\computer\cpu-droid2lev2.wav");  // was droidl2.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXTransferSectorBase)
{
		file("pc\sound\voices\computer\cpu-droid2base.wav");  // was droidbst.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXTransferSectorRad)
{
		file("pc\sound\voices\computer\cpu-droid2nuke.wav");  // was droidnpc.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXRestricted)
{
		file("pc\sound\FINAL\temp-silence.wav");  // was restrict.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXElevatorOff)
{
		file("pc\sound\FINAL\temp-silence.wav");  // was elevoff.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXElevatorOn)
{
		file("pc\sound\voices\computer\cpu-powerelev.wav");  // was elpoeng.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXViolation)
{
		file("pc\sound\voices\computer\cpu-violation.wav");  // was clviol.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXUnrecognized)
{
		file("pc\sound\voices\computer\cpu-impcmnd.wav");  // was impcmnd.wav
		loop(FALSE);
		tridi(true);
		rndfreq(FALSE);
		delay(-1);
		fademin(400);
		fademax(3000);
		localize(_all);
}

sample(SFXScanning)
{
		file("pc\sound\background\triggers\idcan.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_silent);
}

sample(SFXDoorLock)
{
		file("pc\sound\FINAL\temp-silence.wav");  // was Doorlock.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXDoorUnlock)
{
		file("pc\sound\voices\computer\cpu-doorunlocked.wav"); //was Doorunlk.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		delay(-1);
		localize(_all);
}

sample(SFXSectorBase)
{
		file("pc\sound\voices\computer\elev-basement.wav");  // was base.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXTankGarage)
{
		file("pc\sound\voices\computer\cpu-tankgar.wav");  // was tankg.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXSector2)
{
		file("pc\sound\voices\computer\elev-lev2storage.wav");  // was l2.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXSector3)
{
		file("pc\sound\voices\computer\elev-lev3storage.wav");  // was l3.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXRadiation)
{
		file("pc\sound\voices\computer\elev-nuke.wav"); // was nukectr.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorCenter)
{
		file("pc\sound\voices\computer\elev-elevctrl.wav");  // was elctr.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXLoadingDocks)
{
		file("pc\sound\voices\computer\elev-loading.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXWasteplant)
{
		file("pc\sound\voices\computer\elev-waste.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXSewer)
{
		file("pc\sound\voices\computer\elev-sewer.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXReactorOutput)
{
		file("pc\sound\voices\computer\cpu-reactor.wav");  // was reactor.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXReactorWarning)
{
		file("pc\sound\voices\computer\cpu-maxoutput.wav");  // was reactorw.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXReactorLeak)
{
		file("pc\sound\voices\computer\cpu-reactorleak.wav");  // was reactorl.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXLaserTurnedOffAnnex)
{
		file("pc\sound\voices\computer\cpu-laseroff.wav");  // was lazeroff.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXPowerConfiguredAnnex)
{
		file("pc\sound\voices\computer\cpu-nopower.wav");  // was powconf.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXTurbinePowerAnnex)
{
		file("pc\sound\voices\computer\cpu-turbineready.wav");  // was turbpow.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXMechanicalFailure)
{
		file("pc\sound\voices\computer\cpu-failure.wav");  // was Mechfail.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXAirFilters)
{
		file("pc\sound\voices\computer\cpu-airfilters.wav");  //was airfilters.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorMsg01)
{
		file("pc\sound\voices\computer\talk-happy.wav");  // was elev01.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorMsg02)
{
		file("pc\sound\voices\computer\talk-future.wav"); // was elev02.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorMsg03)
{
		file("pc\sound\voices\computer\talk-matter.wav");  // was elev03.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorMsg04)
{
		file("pc\sound\voices\computer\talk-wecare.wav");  // was elev04.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorMsg05)
{
		file("pc\sound\voices\computer\talk-backbone.wav");  // was elev05.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorMsg06)
{
		file("pc\sound\voices\computer\talk-strong.wav");  // was elev06.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXElevatorMsg07)
{
		file("pc\sound\voices\computer\talk-team.wav");  // was elev07.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXCrashImm)
{
		file("pc\sound\voices\computer\cpu-reducespeed.wav");  // was crashim.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXGate4Closed)
{
		file("pc\sound\voices\computer\cpu-gate4.WAV");  // was gate4.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXGate4UnLocked)
{
		file("pc\sound\voices\computer\cpu-unlock4.wav");  // was unlock4.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXAdmitRestricted)
{
		file("pc\sound\voices\computer\cpu-admitrest.wav");  // Was admitoff.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXContaminationBreach)
{
		file("pc\sound\voices\computer\cpu-scan.wav");  // was scan.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXOrganic)
{
		file("pc\sound\voices\computer\cpu-organic.wav");  // was organic.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXEnRoute)
{
		file("pc\sound\voices\computer\cpu-security.wav");  // was enroute.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXSearchReset)
{
		file("pc\sound\voices\computer\cpu-alertnorm.wav");  // was reset.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXRadiationExposed)
{
		file("pc\sound\voices\computer\cpu-exposed.wav");  // was exposed.WAV
		delay(150);
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXRadiationOperate)
{
		file("pc\sound\voices\computer\cpu-nukesuit.wav");  // was operate.WAV
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

///////////////////////
////////  3D   ////////
///////////////////////
sample(SFXContainer25)
{
		file("pc\sound\voices\computer\cpu-recycle25.wav");  // was recycle25.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFXContainerOff)
{
		file("pc\sound\voices\computer\cpu-recycleoff.wav");  // was recycleoff.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXSeparateBodyParts)
{
		file("pc\sound\voices\computer\cpu-separatebody.wav");  // was separatebody.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_silent);
}

sample(SFXGoodDayCommander)
{
		file("pc\sound\voices\computer\cpu-goodday.wav");  // was goodday.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFXTurretArmedCommander)
{
		file("pc\sound\voices\computer\cpu-gunarmed.WAV");  // was gunarmed.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFXPrisonGroup)
{
		file("pc\sound\voices\computer\cpu-prison6.WAV");  // was prisongroup6.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFXContainer50)
{
		file("pc\sound\voices\computer\cpu-recycle50.wav");  // was recycle50.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFXContainer75)
{
		file("pc\sound\voices\computer\cpu-recycle75.wav");  // was recycle75.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFXContainer100)
{
		file("pc\sound\voices\computer\cpu-recyclefull.wav");  // was recyclefull.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFX_Zero)
{
		file("pc\sound\voices\computer\e0.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(800);
		fademax(2500);
		localize(_all);
}

sample(SFX_One)
{
		file("pc\sound\voices\computer\e1.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(400);
//		fademax(1500);
		localize(_all);
}

sample(SFX_Two)
{
		file("pc\sound\voices\computer\e2.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(400);
//		fademax(1500);
		localize(_all);
}

sample(SFX_Three)
{
		file("pc\sound\voices\computer\e3.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(400);
//		fademax(1500);
		localize(_all);
}

sample(SFX_Four)
{
		file("pc\sound\voices\computer\e4.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(400);
//		fademax(1500);
		localize(_all);
}

sample(SFX_Five)
{
		file("pc\sound\voices\computer\e5.WAV");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(400);
//		fademax(1500);
		localize(_all);
}

sample(SFXChotActivity)
{
		file("pc\sound\voices\computer\dispat.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(400);
//		fademax(1500);
		localize(_all);
}

sample(SFX_Six)
{
		file("pc\sound\voices\computer\e6.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		localize(_all);
}

sample(SFX_Seven)
{
		file("pc\sound\voices\computer\e7.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		localize(_all);
}

sample(SFX_Eight)
{
		file("pc\sound\voices\computer\e8.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		localize(_all);
}

sample(SFX_Nine)
{
		file("pc\sound\voices\computer\e9.WAV");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		localize(_all);
}

sample(SFXBoxCountDown)
{
		file("pc\sound\voices\computer\box-explode.wav");  // was boxvo5.WAV
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		localize(_all);
}
sample(SFXPodLaunched)
{
		file("pc\sound\voices\computer\cpu-podlaunch.wav");  // was podlnch.wav
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		localize(_all);
}

sample(SFXStepAway)
{
		file("pc\sound\voices\computer\cpu-stepaway.wav");  // was stepaway.wav
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(400);
		fademax(1500);
		localize(_all);
}

sample(SFXHubApproaching)
{
		file("pc\sound\voices\computer\cpu-dockhub.wav");  // was hubapp.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(400);
//		fademax(1500);
		localize(_all);
}

sample(SFXBrakingSequence)
{
		file("pc\sound\voices\computer\cpu-brake.wav");  // was brake.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(1500);
//		fademax(3000);
		localize(_all);
}

sample(SFXEmergencyShutDown)
{
		file("pc\sound\voices\computer\cpu-emergshut.wav");  // emerg.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXCautionBattery)
{
		file("pc\sound\voices\computer\cpu-cautionbattery.wav");  // was cautionb.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXHoldForLift)
{
		file("pc\sound\voices\computer\cpu-holdlift.wav");  // was plzhold.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXStation01)
{
		file("pc\sound\voices\computer\cpu-station01.wav");  // was station01.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXStation02)
{
		file("pc\sound\voices\computer\cpu-station02.wav");  // was station02.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXStation03)
{
		file("pc\sound\voices\computer\cpu-station03.wav");  // was station03.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXStation04)
{
		file("pc\sound\voices\computer\cpu-station04.wav");  // was station04.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXStationPowerRestored)
{
		file("pc\sound\voices\computer\cpu-stationon.wav");  // was pwrestor.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_all);
}

sample(SFXLoweringTankLift)
{
		file("pc\sound\voices\computer\cpu-tanklift.wav");  // was lwtklft.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
//		fademin(2000);
//		fademax(4500);
		localize(_silent);
}

sample(SFXChotActivity01)
{
		file("pc\sound\voices\computer\cpu-chotact1.wav");  // was chotac01.wav
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		localize(_all);
}
sample(SFXChotActivity04)
{
		file("pc\sound\voices\computer\cpu-chotact4.wav");  // was chotac04.wav
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		localize(_all);
}

sample(SFXChotActivity06)
{
		file("pc\sound\voices\computer\cpu-chotact6.wav");  // was chotac06.wav
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		localize(_all);
}

sample(SFXChotActivity09)
{
		file("pc\sound\voices\computer\cpu-chotact9.wav");  // chotac09.wav
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		localize(_all);
}

sample(SFXBatteryChargedLethal)
{
		file("pc\sound\voices\computer\cpu-cautionbattery.wav");  // was batleth.wav
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(1000);
		fademax(3000);
		localize(_all);
}

sample(SFXTurbine01)
{
		file("pc\sound\voices\computer\turbine1.wav");  // was cpu-turbine1.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXTurbine02)
{
		file("pc\sound\voices\computer\turbine2.wav");  // was cpu-turbine2.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXTurbine03)
{
		file("pc\sound\voices\computer\turbine3.wav");  // was cpu-turbine3.wav
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

/*
sample(SFXPersonnelScanned)
{
		file("pc\sound\voices\computer\cylon1c.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}
*/

sample(SFXCylonPersonnelScanned)
{
		file("pc\sound\voices\computer\cylon1c.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXCylonInitiated)
{
		file("pc\sound\voices\computer\cylon2c.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXCylonCompleted)
{
		file("pc\sound\voices\computer\cylon4c.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}

sample(SFXCylonAccessGranted)
{
		file("pc\sound\voices\computer\cylon5c.wav");
		loop(FALSE);
		tridi(FALSE);
		rndfreq(FALSE);
		localize(_all);
}


sample(SFXDanceLose1)
{
		file("pc\sound\actor\allvoices\dj-you-suck.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
}

sample(SFXDanceLose2)
{
		file("pc\sound\actor\allvoices\dj-too-much-to-drink.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXYouVIP)
{
		file("pc\sound\actor\allvoices\dj-you-vip2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXGoBaby)
{
		file("pc\sound\actor\allvoices\dj-go-baby1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);	
		localize(_all);
}

sample(SFXGirlsOnly)
{
		file("pc\sound\actor\allvoices\dj-girls-only1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXAreYouReady)
{
		file("pc\sound\actor\allvoices\dj-are-you-ready2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXTryAgain)
{
		file("pc\sound\actor\allvoices\dj-try-again2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXContestant)
{
		file("pc\sound\actor\allvoices\dj-contestant1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXGetItOn)
{
		file("pc\sound\actor\allvoices\dj-lets-get-it-on1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXFollowArrows)
{
		file("pc\sound\actor\allvoices\dj-follow-arrows1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXOneMoveLeft)
{
		file("pc\sound\actor\allvoices\dj-one-more-to-go.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXDoingGood1)
{
		file("pc\sound\actor\allvoices\dj-doing-good1.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXDoingGood2)
{
		file("pc\sound\actor\allvoices\dj-doing-good2.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXDoingGood3)
{
		file("pc\sound\actor\allvoices\dj-doing-good3.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}

sample(SFXDoingGood4)
{
		file("pc\sound\actor\allvoices\dj-doing-good4.wav");
		loop(FALSE);
		tridi(TRUE);
		rndfreq(FALSE);
		fademin(500);
		fademax(2000);
		localize(_all);
}









