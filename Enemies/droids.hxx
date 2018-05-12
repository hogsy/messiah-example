

/*
Actors:
MDroid1
MDroid2
ForkLift
AutoCannon
*/




/////////////////////////////
/////////////////////////////
/////////////////////////////
/////////////////////////////
/////////////////////////////
/////////////////////////////

SubRoutine(MoveDroidRoutine)
{

		if(vtrigger==_DIRforward)
		{
			move(0,0,-7);
		}
		if(vtrigger==_DIRbackward)
		{
			move(0,0,5);
		}
		if(vtrigger==_DIRleft)
		{
			turn(0,-20,0);
		}
		if(vtrigger==_DIRright)
		{
			turn(0,20,0);
		}

}


SubRoutine(Sub_DisintegrateMe)
{
		if(VAIClass!=_AIclassDroid && VAIClass!=_AIclassAnimal)
		{
			vector(_settoactorpos,tmpvector);
			vector(_addy,tmpvector,-100);
			callsub(sub_fxsmallexplosion);
			sample(SFXElectricShock2,-1);
			killactor();
		}
}


Actor(CleanUpBot)
{
		file(PossesionBotHeader);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(nomove);

		float(_declare,CurrentDirection,0);

		print("cleanup bot");

		//check for dead bodies
		//select target if any

		ActorFlag(_or,_AFLAGnotarget);

		if(VactorFlag==_AFLAGinitialize)			//re-initialize after a loadgame
		{
			//must stop this sample if droid becomes inactive!!!!!!
			sample(SFXDroidHover,-1);
		}
		if(vstate==statedead)
		{
			samplestop(SFXDroidHover);
		}

		call(DeadClassRank,false);
		call(DeadClassRank,true,10000,true);

		if(VAIhaslockedonactor!=0)
		{
			call(AIsetlockedonactortotarget);
		}

		if(VAIhastarget!=0)
		{
			printi("cleanup bot has target:  ",VPickDestOffsetY);
			printi("bot pickdest angle:      ",VPickDestAngleCorr);
			printi("bot target distance:     ",VTargetDistance);
			call(AIupdatetargetpos);
			call(AIpickdest,20);

			Direction(_clr,_DIRaiRemoveFlags);
			if(VTargetDistance>70)
			{
				float(_set,CurrentDirection,0);
				CallSub(Sub_AI1WayAlignToPickDestAngle);
				if(VPickDestAngleCorr<700 && VPickDestAngleCorr>-700)
				{
					move(0,0,-10);
				}
				elseif(VPickDestAngleCorr<-1300 || VPickDestAngleCorr>1300)
				{
					move(0,0,10);
				}
				if(VPickDestOffsetY>10)
				{
					move(0,-10,0);
				}
				elseif(VPickDestOffsetY<-10)
				{
					move(0,10,0);
				}
			}
			else
			{
				//disintegrate body here
				call(AIexecutecodewithinradius,Sub_DisintegrateMe,100,true);
			}
			if(VTrigger==_DIRleft)
			{
				Turn(0,-40,0);
			}
			elseif(VTrigger==_DIRright)
			{
				Turn(0,40,0);
			}
		}

		if(vhealth<=0)
		{
			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			CallSub(sub_fxexplosion);
			killactor();
		}
}

Actor(PossesionBot)
{
		file(PossesionBotHeader);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(nomove);

		float(_declare,Counter,0);

		call(AIcheckforplayerone,500);
		if(VTrigger==_DIRTempFlag && Counter>0)
		{
			print("PlayerOneFound    ");
			call(AIchangefriendtoenemy);
			call(AIalert,Sub_AISetAttack);
			sample(SFXViolation,-1);
			float(_set,Counter,-150);
		}
		else
		{
			print("Nothing found     ");
			float(_add,Counter,1);
			if(counter<0)
			{
				Turn(0,140,0);
			}
			else
			{
				call(AIPickdest,10);
				if(vtrigger==_DIRtempflag)
				{
					call(PickNewNode);
				}

				CallSub(Sub_AI1WayAlignToPickDestAngle);
				if(VTrigger==_DIRleft)
				{
					Turn(0,-40,0);
				}
				elseif(VTrigger==_DIRright)
				{
					Turn(0,40,0);
				}
				if(VPickDestAngleCorr<700 && VPickDestAngleCorr>-700)
				{
					move(0,0,-3);
				}
				if(VPickDestOffsetY>10)
				{
					move(0,-2,0);
				}
				elseif(VPickDestOffsetY<-10)
				{
					move(0,2,0);
				}

			}
		}

		CallSub(BackGroundTriggerChecks);

		if(vhealth<=0)
		{
			killactor();
		}
}


SubRoutine(Sub_DroidCheckForAttach,float(Attached),float(PreferedDistToGroundLow),float(PreferedDistToGroundHigh))
{
		call(SearchForCloseActor,_AIclassmale|_AIclassfemale,200);
		if(VTrigger==_DIRTempFlag)
		{
			print("Found close actor");
			call(SetLockedOnActorToParent);
			Call(CopyParentFlags);
			float(_set,Attached,1);
			float(_set,PreferedDistToGroundLow,140);
			float(_set,PreferedDistToGroundHigh,220);
		}
}

SubRoutine(Sub_CorrectDroidPosition,float(Angle),float(AngleAdd),float(PreferedDistToGroundLow),float(PreferedDistToGroundHigh))
{
		if(VTrigger==_DIRTempFlag)
		{
			if(Angle>0)
			{
				float(_set,AngleAdd,-5);
			}
			else
			{
				float(_set,AngleAdd,5);
			}
		}

		float(_add,Angle,AngleAdd);
		if(Angle<-90)
		{
			float(_set,Angle,-90);
		}
		elseif(Angle>90)
		{
			float(_set,Angle,90);
		}

		if(VDistToGround<PreferedDistToGroundLow)
		{
			print(Move Up");
			move(0,4,0);
		}
		elseif(VDistToGround>PreferedDistToGroundHigh)
		{
			print(Move Down");
			move(0,-4,0);
		}
}

SubRoutine(DetachDroidFromParent,float(PreferedDistToGroundLow),float(PreferedDistToGroundHigh),float(Attached))
{
		float(_set,PreferedDistToGroundLow,30);
		float(_set,PreferedDistToGroundHigh,35);

		call(ClrParentPtr);
		float(_set,Attached,0);
		Direction(_clr,_DIRshoot|_DIRhavegun);
}


#define	_DroidStateIdle			1
#define	_DroidStateAttack		2
#define	_DroidStateDefend		4
#define	_DroidStateKamikaze		8


//-----------------------------
// WEAPONS FACTORY TURRET
//-----------------------------
Actor(GunTurret)
{
		file(GunTurretHeader);
		startaction(GunTurretIdle);

		CallSub(BackGroundTriggerChecks);

		vector(_declare,ShootOffset,0,0,-225);
		float(_declare,ShootDelay,2);
		float(_declare,ShootCounter,0);
		float(_declare,ShootSide,0);			//0 is right cannon, 1 is left cannon

		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnotarget);

		call(SetParticleSetID);

		if(VAction==GunTurretFire)
		{
			if(VFrame==81 || VFrame==121 || VFrame==161)
			{
				float(_set,ShootDelay,0);
				float(_set,ShootCounter,9);
			}
			elseif(VFrame==38 || VFrame==110 || VFrame==150)
			{
				sample(SFXGunTurretHatch,-1);
			}
			elseif(VFrame==232)
			{
				sample(SFXGunTurretSteam,-1);
			}
			elseif(VFrame==1 || VFrame==192)
			{
				sample(SFXGunTurretDoor,-1);
			}

			if(VFrame>=190 && VFrame<=231)
			{
				if(vrnd<50)
				{
					float(_rnd2,tmpfloat,2);
					float(_sub,tmpfloat,1);
					vector(_set,gactorine,0,0,0);
					vector(_setx,gactorine,tmpfloat);
					vector(_set,Gactorpos,0,0,-225);
					spawnparticle(fx_weaponsmoke,4,gactorpos,gactorine,fx_machinegunsmokeac);
					spawnparticle(fx_weaponsmoke,7,gactorpos,gactorine,fx_machinegunsmokeac);
				}
			}
		}
		elseif(VAction==GunTurretBeserker)
		{
			if(Vframe==1)
			{
				sample(SFXGunTurretDoor,-1);
			}
			elseif(VFrame==40 || VFrame==204)
			{
				sample(SFXShaftLock,-1);
			}
			elseif(VFrame==44 || VFrame==98)
			{
				sample(SFXLightning,-1);
			}
			elseif(VFrame==49 || VFrame==53 || VFrame==72 || VFrame==124)
			{
				sample(SFXGunTurretZap,-1);
			}
			elseif(VFrame==55 || VFrame==214)
			{
				sample(SFXGunTurretHatch,-1);
			}
			elseif(VFrame==81||VFrame==91||VFrame==101||VFrame==111||VFrame==121||VFrame==131||VFrame==141||VFrame==151||VFrame==161||VFrame==171||VFrame==181)	//||VFrame==191
			{
				float(_set,ShootDelay,0);
				float(_set,ShootCounter,9);
			}
		}

		if(ShootCounter>0)
		{
			if(ShootCounter==9)
			{
				sample(SFXGunTurretFire,-1);
			}
			if(ShootDelay==0)
			{
				float(_set,ShootDelay,2);
				float(_sub,ShootCounter,1);

				if(ShootSide==0)
				{
					float(_set,ShootSide,1);

					//bullet
					spawnactorbone(BulletGunTurret,ShootOffset,Gactorpos,Gactorine,4);
					vector(_set,tmpvector,0,0,-200);
					vector(_set,Gactorpos,0,0,-270);
					spawnparticle(fx_gunbulletturretac,4,Gactorpos,tmpvector,fx_gunbulhorizac,true);
					spawnparticle(fx_gunbulletturretac,4,Gactorpos,tmpvector,fx_gunbulvertac,true);
					spawnparticle(fx_gunbulletturretac,4,Gactorpos,tmpvector,fx_gunbuldiag1ac,true);
					spawnparticle(fx_gunbulletturretac,4,Gactorpos,tmpvector,fx_gunbuldiag2ac,true);


					//muzzle flash
					spawnparticle(fx_gunflashturretac,4,Gactorpos,emptyvector,fx_gunflashhorizac);
					spawnparticle(fx_gunflashturretac,4,Gactorpos,emptyvector,fx_gunflashvertac);
					spawnparticle(fx_gunflashturretac,4,Gactorpos,emptyvector,fx_gunflashdiag1ac);
					spawnparticle(fx_gunflashturretac,4,Gactorpos,emptyvector,fx_gunflashdiag2ac);
												   
					vector(_set,tmpvector,255,192,192);
					spawnlight(fire_light,4,Gactorpos,tmpvector,EmptyVector,300);
					vector(_set,Gactorpos,0,0,-220);
					spawnparticle(fx_gunstrobeturret,4,Gactorpos,emptyvector,fx_gunstrobeac);
					//muzzle flash
				}
				else
				{
					float(_set,ShootSide,0);

					//bullet
					spawnactorbone(BulletGunTurret,ShootOffset,Gactorpos,Gactorine,7);
					vector(_set,tmpvector,0,0,-200);
					vector(_set,Gactorpos,0,0,-270);
					spawnparticle(fx_gunbulletturretac,7,Gactorpos,tmpvector,fx_gunbulhorizac,true);
					spawnparticle(fx_gunbulletturretac,7,Gactorpos,tmpvector,fx_gunbulvertac,true);
					spawnparticle(fx_gunbulletturretac,7,Gactorpos,tmpvector,fx_gunbuldiag1ac,true);
					spawnparticle(fx_gunbulletturretac,7,Gactorpos,tmpvector,fx_gunbuldiag2ac,true);
												   

					//muzzle flash
					spawnparticle(fx_gunflashturretac,7,Gactorpos,emptyvector,fx_gunflashhorizac);
					spawnparticle(fx_gunflashturretac,7,Gactorpos,emptyvector,fx_gunflashvertac);
					spawnparticle(fx_gunflashturretac,7,Gactorpos,emptyvector,fx_gunflashdiag1ac);
					spawnparticle(fx_gunflashturretac,7,Gactorpos,emptyvector,fx_gunflashdiag2ac);

					//vector(_set,tmpvector,255,192,192);
					//spawnlight(fire_light,7,Gactorpos,tmpvector,EmptyVector,300);
					vector(_set,Gactorpos,0,0,-220);
					spawnparticle(fx_gunstrobeturret,7,Gactorpos,emptyvector,fx_gunstrobeac);
					//muzzle flash
				}
			}
			else
			{
				float(_sub,ShootDelay,1);
			}
		}
		elseif(ShootCounter==0)
		{
			samplestop(SFXGunTurretFire);
			float(_sub,ShootCounter,1);
		}
}





//-----------------------------
//  AI turret
//-----------------------------
Actor(ShellTurret)
{
		file(ShellTurretHeader);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(ShellTurretNoMove);

		vector(_declare,VL_LockedOnPos,0,0,0);
		vector(_declare,VL_LockedOnOffset,0,0,0);
		float(_declare,FL_AutoCannonOffset,0);
		float(_declare,anglex,-512);
		float(_declare,angley,2048);
		float(_declare,anglez,0);

		float(_declare,ShootDelay,0);
		float(_declare,SideShoot,0);

		call(AIupdateAIvars);

		call(CheckForVisual,_CLASSModel,1000);
		call(AIcheckfortarget,10);

		if(VActiveTime==1)
		{
			ActorFlag(_or,_AFLAGnomove);
		}

		if(VAItargetfound!=0)
		{
			printilog("Turret found target !");
			call(AIselecttarget,_AIenemy);
			call(AIPickdest,10);

			vector(_settotargetpos,VL_LockedOnPos);
			vector(_sety,VL_LockedOnOffset,FL_AutoCannonOffset);
			vector(_add,VL_LockedOnPos,VL_LockedOnOffset);
			vector(_settargetpos,VL_LockedOnPos);

			CallSub(BackGroundTriggerChecks);

			call(SetParticleSetID);

			if(ShootDelay==0)
			{
				float(_set,ShootDelay,3);
				if(SideShoot==0)
				{
					vector(_set,tmpvector,25,-50,-50); //left cannon
					spawnactorbone(BulletShellTurret,tmpvector,Gactorpos,Gactorine,0);

					vector(_set,tmpvector,25,-50,-250);
					vector(_set,Gactorine,0,0,-200);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbulhorizac,true);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbulvertac,true);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbuldiag1ac,true);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbuldiag2ac,true);

					vector(_set,tmpvector,25,-50,-150);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashhorizac);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashvertac);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashdiag1ac);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashdiag2ac);

					vector(_set,tmpvector,255,255,255);
					spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,300);

					float(_set,SideShoot,1)
				}
				elseif(SideShoot==1)
				{
					vector(_set,tmpvector,-25,-50,-50); //right cannon
					spawnactorbone(BulletShellTurret,tmpvector,Gactorpos,Gactorine,0);

					vector(_set,tmpvector,-25,-50,-250);
					vector(_set,Gactorine,0,0,-200);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbulhorizac,true);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbulvertac,true);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbuldiag1ac,true);
					spawnparticle(fx_gunbulletturretac,0,tmpvector,Gactorine,fx_gunbuldiag2ac,true);

					vector(_set,tmpvector,-25,-50,-150);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashhorizac);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashvertac);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashdiag1ac);
					spawnparticle(fx_gunflashturretac,0,tmpvector,emptyvector,fx_gunflashdiag2ac);

					//vector(_set,tmpvector,255,255,255);
					//spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,300);

					sample(SFXTurretFire,-1);

					float(_set,SideShoot,0)
				}
			}
			else
			{
				float(_sub,ShootDelay,1);
			}

			if(VTargetAngle<-51)
			{
				float(_add,angley,-50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			elseif(VTargetAngle>51)
			{
				float(_add,angley,50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			else
			{
				if(FL_AutoCannonOffset<-100)
				{
					float(_set,FL_AutoCannonOffset,-100);
				}
				//fine tuning angle
				if(VTargetAngle<-11)
				{
					float(_add,angley,-10);
				}
				elseif(VTargetAngle>11)
				{
					float(_add,angley,10);
				}

				if(VTargetAngleY<-11)
				{
					float(_add,anglex,10);
				}
				elseif(VTargetAngleY>11)
				{
					float(_add,anglex,-10);
				}

				else
				{
					print("turret ready to shoot !",0);
					if(FL_AutoCannonOffset<0)
					{
						float(_add,FL_AutoCannonOffset,1);
					}
				}
			}
		}
		else
		{
			float(_set,FL_AutoCannonOffset,-100);
			if(VAInotargettime>160)
			{
				if(angley<-6)
				{
					float(_add,angley,5);
				}
				else
				{
					float(_add,angley,-5);
				}
				else
				{
					float(_set,angley,0);
				}
				if(anglex<-6)
				{
					float(_add,anglex,5);
				}
				else
				{
					float(_add,anglex,-5);
				}
				else
				{
					float(_set,anglex,0);
				}
			}
		}

		if(angley>2048)
		{
			float(_set,angley,2048);
		}
		elseif(angley<0)
		{
			float(_set,angley,0);
		}
		if(anglex>512)
		{
			float(_set,anglex,512);
		}
		elseif(anglex<-512)
		{
			float(_set,anglex,-512);
		}

		if(anglex!=0 || angley!=0 || anglez!=0)
		{
			call(CalcTransMat,anglex,angley,anglez);
		}
}


Actor(CompanionBot)
{
		file(CompanionBotHeader);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(nomove);

		float(_declare,Attached,0);
		float(_declare,Angle,90);
		float(_declare,AngleAdd,5);
		float(_declare,PreferedDistToGroundLow,30);
		float(_declare,PreferedDistToGroundHigh,35);
		float(_declare,CurrentDirection,0);

		float(_declare,CBotsmokeflag,-1);
		float(_declare,CBotsampflag,0);

		if(VHasParent==0 && Attached!=0)
		{
			float(_set,Attached,0);
		}

		if(Attached==0)
		{
			//reset FX vars if it becomes de-attached
			float(_set,CBotsmokeflag,-1);
			if(CBotsampflag==1)
			{
				samplestop(SFXMachineGunFire);
			}
			float(_set,CBotsampflag,0);

			CallSub(Sub_DroidCheckForAttach,Attached,PreferedDistToGroundLow,PreferedDistToGroundHigh);
		}
		else
		{
			call(CopyParentFlags);

			call(AIcalcdroidposition,80,angle,true,true);
			CallSub(Sub_CorrectDroidPosition,Angle,AngleAdd,PreferedDistToGroundLow,PreferedDistToGroundHigh);

			call(AIupdateAIvars);
			if(aivisiontoggle==0)
			{
				call(AIcheckfortarget,10);
			}
			if(VTrigger==_DIRCombatMode)
			{
				vector(_set,WeaponPos,0,0,-20);
				call(wCheckWeaponTarget,EmptyVector,32767,WeaponPos);
			}

			if(VActorFlag==_AFLAGlogon)
			{
				print("Correcting angle in lock mode");
				if(VTargetAngle>11)
				{
					Turn(0,10,0);
				}
				elseif(VTargetAngle<-11)
				{
					Turn(0,-10,0);
				}
			}

		}

		call(SetParticleSetID);

		if(VTrigger==_DIRshoot && VActorFlag==_AFLAGlogon)
		{
			//start SFX loop
			if(CBotsampflag==0)
			{
				sample(SFXMachineGunFire,-1)
			}
			float(_set,CBotsampflag,1);

			//if parentptr fired, so do I
			SpawnActor(BulletDroid,0,20,0);
			if(VTrigger==_DIRBulletFired)
			{
				move(0,15,30);	//recoil

				//muzzle flash
				vector(_set,Gactorpos,0,0,-30);
				spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashhorizsmall);
				spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashvertsmall);
				spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag1small);
				spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag2small);
											   
				vector(_set,tmpvector,255,192,192);
				spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,300);
				vector(_set,Gactorpos,0,0,-10);
				spawnparticle(fx_gunstrobeturret,0,Gactorpos,emptyvector,fx_gunstrobesmall);
				//muzzle flash

				//reload smoke delayer
				float(_set,CBotsmokeflag,25);
			}
		}
		else
		{
			//do some smoke
			if(CBotsmokeflag>=0)
			{
				if(VSniperMode==0)
				{
					float(_rnd2,tmpfloat,2);
					float(_sub,tmpfloat,1);
					vector(_set,gactorine,0,0,0);
					vector(_setx,gactorine,tmpfloat);

					if(vrnd<50)
					{
						vector(_set,Gactorpos,0,0,-10);
						spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmoke);
					}
				}
				float(_sub,CBotsmokeflag,1);
			}

			//stop fire, so stop sample loop
			if(CBotsampflag==1)
			{
				samplestop(SFXMachineGunFire);
			}
			float(_set,CBotsampflag,0);
		}

		call(AIupdatemovementvariables);

/*		printi("PathDestDist:     ",VPathDestDistance);
		printi("PathDestAngle:    ",VPathDestAngle);
		printi("PickDestAngle:    ",VPickDestAngle);
		printi("TargetDistance:   ",VTargetDistance);
		printi("TargetAngle:      ",VTargetAngle);
		printi("DistToGround:     ",VDistToGround);
		print("PrefDistLow:      ",PreferedDistToGroundLow);
		print("PrefDistHigh:     ",PreferedDistToGroundHigh);
		printi("Health:           ",VHealth);
*/
		if(vhealth<100)
		{
			//go into kamikaze mode
			if(vhealth<=0)
			{
				sample(SFXBazookaExplode,-1);
				vector(_settoactorpos,tmpvector);
				CallSub(sub_fxexplosion);
				killactor();
			}
		}

		if(VTrigger!=_DIRalive && VHealth>0)
		{
			//parent died so detach

			float(_set,PreferedDistToGroundLow,30);
			float(_set,PreferedDistToGroundHigh,35);

			call(ClrParentPtr);
			float(_set,Attached,0);
			Direction(_clr,_DIRshoot|_DIRhavegun);
			Direction(_set,_DIRalive);
		}

		CallSub(BackGroundTriggerChecks);

}

//**********************************************************************************************************
//**********************************************************************************************************
//****************		Defensive Bot													 *******************
//**********************************************************************************************************
//**********************************************************************************************************

Actor(DefensiveBot)
{
		file(DefensiveBotHeader);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(nomove);

		float(_declare,Attached,0);
		float(_declare,KamikazeMode,0);
		float(_declare,Angle,90);
		float(_declare,AngleAdd,5);
		float(_declare,PreferedDistToGroundLow,30);
		float(_declare,PreferedDistToGroundHigh,35);
		float(_declare,CurrentDirection,0);

		if(VHasParent==0 && Attached!=0)
		{
			float(_set,Attached,0);
		}

		printi("Defensive droid start",VAIState);

		if(KamikazeMode!=0)
		{
			print("In kamikaze mode");

			if(Attached!=0)
			{
				call(CopyParentFlags);
			}

			call(AIupdateAIvars);
			if(aivisiontoggle==0)
			{
				call(AIcheckfortarget,10);
			}
			if(VAItargetfound==_AIenemy || VAIState==_AIstateAttack)
			{
				printi("Droid in attackstate:   ",VAItargetfound);
				//detach from actor
				//select target and persue

				if(VAItargetfound==_AIenemy)
				{
					call(AIselecttarget,_AIenemy);
					call(AIorder,_set,_AIstateattack);
				}
				call(AIpickdest,10);

				CallSub(Sub_CorrectDroidPosition,Angle,AngleAdd,PreferedDistToGroundLow,PreferedDistToGroundHigh);		//for up and down corrections

				Direction(_clr,_DIRaiRemoveFlags);
				if(VTargetDistance>100)
				{
					float(_set,CurrentDirection,0);
					CallSub(Sub_AI1WayAlignToTarget);
					CallSub(Sub_AI8WayMoveWalk,CurrentDirection);
					Direction(_set,CurrentDirection);
					print("CurrentDirection:  ",CurrentDirection);
					if(VTrigger==_DIRleft)
					{
						Turn(0,-40,0);
					}
					elseif(VTrigger==_DIRright)
					{
						Turn(0,40,0);
					}
					if(VTrigger==_DIRforward)
					{
						move(0,0,-15);
					}
					elseif(VTrigger==_DIRbackward)
					{
						move(0,0,15);
					}
					if(VTrigger==_DIRsideleft)
					{
						move(15,0,0);
					}
					elseif(VTrigger==_DIRsideright)
					{
						move(-15,0,0);
					}

				}
				else
				{
					//blow up
					sample(SFXBazookaExplode,-1);
					vector(_settoactorpos,tmpvector);
					initactor(BulletExplosion,tmpvector,emptyvector,false);
					CallSub(sub_fxexplosion);
					killactor();
				}

				call(SetParticleSetID);

				if(VTargetDistance<600)
				{
					if(VTargetAngle<30 && VTargetAngle>-30)
					{
						vector(_set,WeaponPos,0,0,-20);
						call(wCheckWeaponTarget,EmptyVector,32767,WeaponPos);
						if(VActorFlag==_AFLAGlogon)
						{
							print("Trying to fire bullet");
							SpawnActor(BulletDroid,0,0,-20);
							if(VTrigger==_DIRBulletFired)
							{
								move(0,15,30);	//recoil

								//muzzle flash
								vector(_set,Gactorpos,0,0,-30);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashhorizsmall);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashvertsmall);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag1small);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag2small);
															   
								vector(_set,tmpvector,255,192,192);
								spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,300);
								vector(_set,Gactorpos,0,0,-10);
								spawnparticle(fx_gunstrobeturret,0,Gactorpos,emptyvector,fx_gunstrobesmall);
								//muzzle flash
							}
						}
					}
				}
			}
		}
		elseif(Attached==0)
		{
			CallSub(Sub_DroidCheckForAttach,Attached,PreferedDistToGroundLow,PreferedDistToGroundHigh);
		}
		else
		{
			call(CopyParentFlags);

			call(AIupdateAIvars);
			if(aivisiontoggle==0)
			{
				call(AIcheckfortarget,10);
			}
			if(VAItargetfound==_AIenemy)
			{
				printi("Defensebot Found something:   ",VAItargetfound);
				call(AIselecttarget,_AIenemy);
				call(AIupdatemovementvariables);

				vector(_set,WeaponPos,0,0,-20);
				call(wCheckWeaponTarget,EmptyVector,32767,WeaponPos);

				CallSub(Sub_AI1WayAlignToTarget);
				if(VTrigger==_DIRleft)
				{
					Turn(0,-40,0);
				}
				elseif(VTrigger==_DIRright)
				{
					Turn(0,40,0);
				}

				call(SetParticleSetID);

				if(VActorFlag==_AFLAGlogon)
				{
					printi("Correcting angle in lock mode",VTargetAngle);
					if(VTargetAngle<81 && VTargetAngle>-81)
					{
						print("Trying to fire bullet");
						SpawnActor(BulletDroid,0,0,-20);
						if(VTrigger==_DIRBulletFired)
						{
							move(0,15,30);	//recoil

							//muzzle flash
							vector(_set,Gactorpos,0,0,-30);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashhorizsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashvertsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag1small);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag2small);
														   
							vector(_set,tmpvector,255,192,192);
							spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,300);
							vector(_set,Gactorpos,0,0,-10);
							spawnparticle(fx_gunstrobeturret,0,Gactorpos,emptyvector,fx_gunstrobesmall);
							//muzzle flash
						}
					}
				}
				call(AIcalcdroidposition,80,angle,true,false);
			}
			else
			{
				call(AIcalcdroidposition,80,angle,true,true);
			}
			CallSub(Sub_CorrectDroidPosition,Angle,AngleAdd,PreferedDistToGroundLow,PreferedDistToGroundHigh);
		}

		printi("PathDestDist:     ",VPathDestDistance);
		printi("PathDestAngle:    ",VPathDestAngle);
		printi("PickDestAngle:    ",VPickDestAngle);
		printi("TargetDistance:   ",VTargetDistance);
		printi("TargetAngle:      ",VTargetAngle);
		printi("DistToGround:     ",VDistToGround);
		print("PrefDistLow:      ",PreferedDistToGroundLow);
		print("PrefDistHigh:     ",PreferedDistToGroundHigh);
		printi("Health:           ",VHealth);

		if(vhealth<1000)
		{
			//go into kamikaze mode
			if(KamikazeMode==0)
			{
				float(_set,KamikazeMode,1);
				float(_set,PreferedDistToGroundLow,30);
				float(_set,PreferedDistToGroundHigh,35);
			}
			if(vhealth<=0)
			{
				sample(SFXBazookaExplode,-1);
				vector(_settoactorpos,tmpvector);
				CallSub(sub_fxexplosion);
				killactor();
			}
		}

		if(VTrigger!=_DIRalive && VHealth>0)
		{
			print("parent died so detach");

			float(_set,PreferedDistToGroundLow,30);
			float(_set,PreferedDistToGroundHigh,35);

			call(ClrParentPtr);
			float(_set,Attached,0);
			Direction(_clr,_DIRshoot|_DIRhavegun);
			Direction(_set,_DIRalive);
		}

		if(VTrigger==_DIRactorbulletcol)
		{
			printilog("VColAngle:   ",VColAngle);
			//printlog("ColAngleTmp: ",ColAngleTmp);
			if(VColAngle>=3584 && VColAngle<512)
			{
				move(0,0,60);
			}
			elseif(VColAngle>=512 && VColAngle<1536)
			{
				move(60,0,0);
			}
			elseif(VColAngle>=1536 && VColAngle<2562)
			{
				move(0,0,-60);
			}
			else
			{
				move(-60,0,0);
			}

		}

		CallSub(BackGroundTriggerChecks);

		printi("Defensive droid end");
}

//**********************************************************************************************************
//**********************************************************************************************************
//****************		Offensive Bot													 *******************
//**********************************************************************************************************
//**********************************************************************************************************

Actor(OffensiveBot)
{
		file(OffensiveBotHeader);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(nomove);

		float(_declare,Attached,0);
		float(_declare,Angle,90);
		float(_declare,AngleAdd,5);
		float(_declare,PreferedDistToGroundLow,30);
		float(_declare,PreferedDistToGroundHigh,35);
		float(_declare,CurrentDirection,0);

		printi("Attackdroid start",VAIState);

		if(VHasParent==0 && Attached!=0)
		{
			float(_set,Attached,0);
		}

		if(Attached==0)
		{
			CallSub(Sub_DroidCheckForAttach,Attached,PreferedDistToGroundLow,PreferedDistToGroundHigh);
		}
		else
		{
			call(CopyParentFlags);

			call(AIupdateAIvars);
			if(aivisiontoggle==0)
			{
				print("Checking for target");
				call(AIcheckfortarget,10);
			}
			if(VAItargetfound==_AIenemy || VAIState==_AIstateAttack || VAIState==_AIstateSearch)
			{
				printi("Droid in attackstate:  ",VAItargetfound);
				//detach from actor
				//select target and persue

				if(VAItargetfound==_AIenemy)
				{
					print("in attack");
					call(AIselecttarget,_AIenemy);
					call(AIorder,_set,_AIstateattack);
				}
				elseif(VAIState==_AIstatesearch)
				{
					print("in search");
					if(VAInotargettime>150)
					{
						call(AIorder,_set,_AIstatepatrol);
						CallSub(DetachDroidFromParent,PreferedDistToGroundLow,PreferedDistToGroundHigh,Attached);
					}
				}
				elseif(VAInotargettime>150)
				{
					call(AIorder,_set,_AIstatesearch);
				}
				call(AIupdatetargetpos);
				call(AIpickdest,100);

				Direction(_clr,_DIRaiRemoveFlags);
				if(VTargetDistance>150)
				{
					float(_set,CurrentDirection,0);
					CallSub(Sub_AI1WayAlignToPickDestAngle);
					if(VPickDestAngleCorr<700 && VPickDestAngleCorr>-700)
					{
						move(0,0,-15);
					}
					elseif(VPickDestAngleCorr<-1300 || VPickDestAngleCorr>1300)
					{
						move(0,0,15);
					}
					if(VPickDestOffsetY>10)
					{
						move(0,-2,0);
					}
					elseif(VPickDestOffsetY<-10)
					{
						move(0,2,0);
					}
				}
				else
				{
					CallSub(Sub_AI1WayAlignToTarget);
				}
				if(VTrigger==_DIRleft)
				{
					Turn(0,-40,0);
				}
				elseif(VTrigger==_DIRright)
				{
					Turn(0,40,0);
				}

				call(SetParticleSetID);

				if(VTargetDistance<1500)
				{
					if(VTargetAngle<150 && VTargetAngle>-150)
					{
						vector(_set,WeaponPos,0,0,-20);
						call(wCheckWeaponTarget,EmptyVector,32767,WeaponPos);
						if(VActorFlag==_AFLAGlogon)
						{
							print("Trying to fire bullet");
							SpawnActor(BulletDroid,0,0,-20);
							if(VTrigger==_DIRBulletFired)
							{
								move(0,15,30);	//recoil

								//muzzle flash
								vector(_set,Gactorpos,0,0,-30);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashhorizsmall);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashvertsmall);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag1small);
								spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag2small);
															   
								vector(_set,tmpvector,255,192,192);
								spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,300);
								vector(_set,Gactorpos,0,0,-10);
								spawnparticle(fx_gunstrobeturret,0,Gactorpos,emptyvector,fx_gunstrobesmall);
								//muzzle flash
							}
						}
					}
				}

				/*
				printi("Defensebot Found something:   ",VAItargetfound);
				call(AIselecttarget,_AIenemy);
				call(AIupdatemovementvariables);

				vector(_set,WeaponPos,0,0,-20);
				call(wCheckWeaponTarget,EmptyVector,32767,WeaponPos);

				if(VActorFlag==_AFLAGlogon)
				{
					printi("Correcting angle in lock mode",VTargetAngle);
					if(VTargetAngle>11)
					{
						Turn(0,10,0);
					}
					elseif(VTargetAngle<-11)
					{
						Turn(0,-10,0);
					}
					else
					{
						print("Trying to fire bullet");
						SpawnActor(BulletDroid,0,0,-20);
						if(VTrigger==_DIRBulletFired)
						{
							vector(_set,Gactorpos,0,0,-20);
							spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,-1);
							spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashvert);
						}
					}
				}
				call(AIcalcdroidposition,80,angle,true,false);
				*/
			}
			else
			{
				print("Not in attack");
				call(AIcalcdroidposition,80,angle,true,true);
			}
		}
		CallSub(Sub_CorrectDroidPosition,Angle,AngleAdd,PreferedDistToGroundLow,PreferedDistToGroundHigh);

		printi("PickDestAngle:    ",VPickDestAngle);
		printi("TargetDistance:   ",VTargetDistance);
		printi("TargetAngle:      ",VTargetAngle);
/*
		printi("PathDestDist:     ",VPathDestDistance);
		printi("PathDestAngle:    ",VPathDestAngle);
		printi("PickDestAngle:    ",VPickDestAngle);
		printi("TargetDistance:   ",VTargetDistance);
		printi("TargetAngle:      ",VTargetAngle);
		printi("DistToGround:     ",VDistToGround);
		print("PrefDistLow:      ",PreferedDistToGroundLow);
		print("PrefDistHigh:     ",PreferedDistToGroundHigh);
		printi("Health:           ",VHealth);
*/
		if(vhealth<1000)
		{
			//go into kamikaze mode
			if(vhealth<=0)
			{
				sample(SFXBazookaExplode,-1);
				vector(_settoactorpos,tmpvector);
				CallSub(sub_fxexplosion);
				killactor();
			}
		}

		if(VTrigger!=_DIRalive && VHealth>0)
		{
			//parent died so detach

			CallSub(DetachDroidFromParent,PreferedDistToGroundLow,PreferedDistToGroundHigh,Attached);

			Direction(_set,_DIRalive);
		}

		CallSub(BackGroundTriggerChecks);
		print("Attackdroid end");
}

//**********************************************************************************************************
//**********************************************************************************************************
//****************		Transport Bot													 *******************
//**********************************************************************************************************
//**********************************************************************************************************

Actor(TransportBot)
{
		file(TransportBotHeader);
		rank(_RankGeneral);

		ActorFlag(_or,_AFLAGnotarget);

		startstate(statenormal);
		startaction(nomove);

		if(vactivetime==0)
		{
			sample(SFXDroidHover,-1);
		}
		if(vstate==statedead)
		{
			samplestop(SFXDroidHover);
		}

		float(_declare,FirstTimeBatteryDrop,0);

		printi("Transportdroid start",VAIState);

		ActorFlag(_or,_AFLAGnoai);
		printih("ActorFlag:   ",VActorFlag);

		if(vstate==StateFollowPath)
		{
			print("Driod in follow path mode:  ",vstate);

			call(AIPickdest,10);
			if(VAIstatehigh!=_AIinspecialmode)
			{
				if(vtrigger==_DIRtempflag)
				{
					call(PickNewNode);
				}
			}
			else
			{
				print("AAHH! vstate=StateFollowPath & VAIstatehigh=_AIinspecialmode");
			}
		}
		elseif(vstate==StateExecutePathSequence)
		{
			print("Droid executing path sequence");
			call(AIPickdest,10);		//follow path
			if(vtrigger==_DIRtempflag)
			{
				state(_clr,StateExecutePathSequence);
				state(_or,StateFollowPath);
				call(PickNewNode);
			}
		}

		printi("PathDestDistance:   ",VPathDestDistance);
		printi("PickDestAngle:      ",VPickDestAngleCorr);
		
		printi("VPickDestOffsetY:   ",VPickDestOffsetY);

		Direction(_clr,_DIRaiRemoveFlags);
		if(VPathDestDistance>10)
		{
			CallSub(Sub_AI1WayAlignToPickDestAngle);
			if(VTrigger==_DIRleft)
			{
				Turn(0,-40,0);
			}
			elseif(VTrigger==_DIRright)
			{
				Turn(0,40,0);
			}
			move(0,0,-5);



/*			if(VTrigger==_DIRforward)
			{
				move(0,0,-15);
			}
			elseif(VTrigger==_DIRbackward)
			{
				move(0,0,15);
			}
			if(VTrigger==_DIRsideleft)
			{
				move(15,0,0);
			}
			elseif(VTrigger==_DIRsideright)
			{
				move(-15,0,0);
			}
*/
		//}
		//else
		//{
		//	CallSub(Sub_AI1WayAlignToTarget);
		//}
		}
		print("FirstTimeBatteryDrop is ",FirstTimeBatteryDrop);
		if(VPickDestOffsetY>10)
		{
			move(0,-2,0);
		}
		elseif(VPickDestOffsetY<-10)
		{
			move(0,2,0);
		}

		if(VAIState==_AIstateSuicide)
		{
			KillActor();
		}
		if(VAIState==_AIStateDropBattery)
		{
			print("aistatedropbattery");
			if(FirstTimeBatteryDrop==0)
			{
				vector(_settoactorpos,Gactorpos);
				vector(_set,Gactorangle,0,0,0);
				InitActor(BulletBattery,Gactorpos,Gactorangle,0);
				sample(SFXDropBattery,-1);
				float(_set,FirstTimeBatteryDrop,1);
			}
		}
		else
		{
			print("reset battery");
			if(FirstTimeBatteryDrop==1)
			{
				float(_set,FirstTimeBatteryDrop,0)
			}
		}

/*		if(Attached==0)
		{
			CallSub(Sub_DroidCheckForAttach,Attached,PreferedDistToGroundLow,PreferedDistToGroundHigh);
		}
		else
		{
			call(CopyParentFlags);

			call(AIupdateAIvars);
			if(aivisiontoggle==0)
			{
				call(AIcheckfortarget,10);
			}
			if(VAItargetfound==_AIenemy || VAIState==_AIstateAttack)
			{
				print("Droid in attackstate");
				//detach from actor
				//select target and persue

				if(VAItargetfound==_AIenemy)
				{
					call(AIselecttarget,_AIenemy);
					call(AIorder,_set,_AIstateattack);
				}
				call(AIpickdest,10);

				Direction(_clr,_DIRaiRemoveFlags);
				if(VTargetDistance>100)
				{
					float(_set,CurrentDirection,0);
					CallSub(Sub_AI1WayAlignToTarget);
					CallSub(Sub_AI8WayMoveWalk,CurrentDirection);
					Direction(_set,CurrentDirection);
					if(VTrigger==_DIRleft)
					{
						Turn(0,-40,0);
					}
					elseif(VTrigger==_DIRright)
					{
						Turn(0,40,0);
					}
					if(VTrigger==_DIRforward)
					{
						move(0,0,-15);
					}
					elseif(VTrigger==_DIRbackward)
					{
						move(0,0,15);
					}
					if(VTrigger==_DIRsideleft)
					{
						move(15,0,0);
					}
					elseif(VTrigger==_DIRsideright)
					{
						move(-15,0,0);
					}

				}
				else
				{
					CallSub(Sub_AI1WayAlignToTarget);
				}

				if(VTargetDistance<600)
				{
					if(VTargetAngle<30 && VTargetAngle>-30)
					{
						vector(_set,WeaponPos,0,0,-20);
						call(wCheckWeaponTarget,EmptyVector,32767,WeaponPos);
						if(VActorFlag==_AFLAGlogon)
						{
							print("Trying to fire bullet");
							SpawnActor(BulletAutoCannon,0,0,-20);
							if(VTrigger==_DIRBulletFired)
							{
								move(0,15,30);	//recoil
								vector(_set,Gactorpos,0,0,-20);
								spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,-1);
								spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashvert);
							}
						}
					}
				}


			}
			else
			{
				call(AIcalcdroidposition,80,angle,true,true);
			}
			CallSub(Sub_CorrectDroidPosition,Angle,AngleAdd,PreferedDistToGroundLow,PreferedDistToGroundHigh);
		}

		printi("PathDestDist:     ",VPathDestDistance);
		printi("PathDestAngle:    ",VPathDestAngle);
		printi("PickDestAngle:    ",VPickDestAngle);
		printi("TargetDistance:   ",VTargetDistance);
		printi("TargetAngle:      ",VTargetAngle);
		printi("DistToGround:     ",VDistToGround);
		print("PrefDistLow:      ",PreferedDistToGroundLow);
		print("PrefDistHigh:     ",PreferedDistToGroundHigh);
		printi("Health:           ",VHealth);

		if(vhealth<100)
		{
			//go into kamikaze mode
			if(vhealth<=0)
			{
				sample(SFXBazookaExplode,-1);
				vector(_settoactorpos,tmpvector);
				CallSub(sub_fxexplosion);
				killactor();
			}
		}

		if(VTrigger!=_DIRalive && VHealth>=0)
		{
			//parent died so detach

			float(_set,PreferedDistToGroundLow,30);
			float(_set,PreferedDistToGroundHigh,35);

			call(ClrParentPtr);
			float(_set,Attached,0);
			Direction(_clr,_DIRshoot|_DIRhavegun);
			Direction(_set,_DIRalive);
		}

		CallSub(BackGroundTriggerChecks);
		print("Attackdroid end");
*/
		//SpawnActor(BulletBattery,0,0,0);
/*
		if(vhealth<=0)
		{
			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			CallSub(sub_fxexplosion);
			killactor();
		}
*/
		CallSub(BackGroundTriggerChecks);

}



Actor(MDroid1)
{
		file(MDroid1Header);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(mdroid1work);


		CallSub(BackGroundTriggerChecks);

		if(vaicon==0)
		{
			callsub(Sub_SetCameraNormal)
			callsub(MoveDroidRoutine);

			if(vtrigger==_DIRdepossesion)
			{
				callsub(Sub_InitDepossesion,0,0,0)
			}
		}

		if(vhealth<=0)
		{
			vector(_set,Gactorpos,-12540,24441,25123);
			vector(_set,Gactorangle,0,1604,0);
			InitActor(mdroid2,Gactorpos,Gactorangle,"stor_01");
			killactor();
		}
}

Actor(MDroid2)
{
		file(MDroid2Header);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(mdroid2work);

		if(vaicon==0)
		{
			callsub(Sub_SetCameraNormal)
			callsub(MoveDroidRoutine);

			if(vtrigger==_DIRdepossesion)
			{
				callsub(Sub_InitDepossesion,0,0,0)
			}

		}
		if(vhealth<=0)
		{
			vector(_set,Gactorpos,-12540,24441,25123);
			vector(_set,Gactorangle,0,1604,0);
			InitActor(mdroid2,Gactorpos,Gactorangle,"stor_01");
			killactor();
		}
}

Actor(TankMat)
{
		file(TankMatHeader);
		rank(_RankGeneral);

		startstate(statenormal);
		startaction(nomove);

		if(vaicon==0)
		{
			callsub(Sub_SetCameraNormal)
			callsub(MoveDroidRoutine);

			if(vtrigger==_DIRdepossesion)
			{
				callsub(Sub_InitDepossesion,0,0,0)
			}

			if(vtrigger==_DIRaction)
			{
				print("Action pressed");

				call(AIcheckfortarget,10);
				if(VAItargetfound!=0)
				{
					print("Target found 6666666666666666666");
				}
			}


		}
/*		if(vhealth<0)		//respawn
		{
			vector(_set,Gactorpos,-12540,24441,25123);
			vector(_set,Gactorangle,0,1604,0);
			InitActor(mdroid2,Gactorpos,Gactorangle,"stor_01");
			killactor();
		}
*/
}


Actor(ForkLift)
{
		file(ForkLiftHeader);

		rank(_RankGeneral);

		startstate(statenormal);
		startaction(nomove);

		if(vaicon==0)
		{
			callsub(Sub_SetCameraNormal)
			callsub(MoveDroidRoutine);

			if(vtrigger==_DIRdepossesion)
			{
				callsub(Sub_InitDepossesion,0,0,0)
			}
		}
}



Actor(RocketLauncher)
{
		file(RocketLauncherHeader);
		startaction(Ridle);
		//startaction(RLaunchPatrol);

		CallSub(BackGroundTriggerChecks);

		if(vaicon!=0)
		{
			//ack!
		}
		else
		{
			if(vtrigger==_DIRpossesion)
			{
				Camera(turret_camera_distance,turret_camera_angle);
				Target(turret_camera_Tdistance,turret_camera_Tangle);
				callsub(Sub_InitPossesion,NoMove,NoMove,NoMove);
				FirstPerson(1);
			}
			elseif(vtrigger==_DIRdepossesion)
			{
				callsub(Sub_InitDepossesion,0,0,0);
				FirstPerson(0);
			}

			if(vtrigger==_DIRleft)
			{
				turn(0,-32,0);
			}
			if(vtrigger==_DIRright)
			{
				turn(0,32,0);
			}

			if(vtrigger==_DIRshoot)
			{
				/*
				//bullet
				vector(_set,tmpvector,0,110,0);
				spawnactorbone(BulletAutoCannon,tmpvector,Gactorpos,Gactorine,4);
				vector(_set,tmpvector,0,200,0);
				vector(_set,Gactorpos,0,110,0);
				spawnparticle(fx_gunflashturret,4,Gactorpos,tmpvector,fx_gunbulhorizac);
				spawnparticle(fx_gunflashturret,4,Gactorpos,tmpvector,fx_gunbulvertac);
				spawnparticle(fx_gunflashturret,4,Gactorpos,tmpvector,fx_gunbuldiag1ac);
				spawnparticle(fx_gunflashturret,4,Gactorpos,tmpvector,fx_gunbuldiag2ac);

				//muzzle flash
				vector(_set,Gactorpos,0,110,0);
				spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,-1);
				spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,fx_gunflashvert);
				spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,fx_gunflashdiag1);
				spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,fx_gunflashdiag2);

				vector(_set,tmpvector,255,192,192);
				spawnlight(fire_light,4,Gactorpos,tmpvector,EmptyVector,200);
				vector(_set,Gactorpos,0,64,0);
				spawnparticle(fx_gunstrobeturret,4,Gactorpos,emptyvector,fx_gunstroberot);
				*/
			}
		}


		//if(vtrigger==_DIRshoot)
		if(vrnd<15)
		{
			//muzzle flash
			vector(_set,Gactorpos,0,110,0);
			spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,-1);
			spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,fx_gunflashvert);
			spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,fx_gunflashdiag1);
			spawnparticle(fx_gunflashturret,4,Gactorpos,emptyvector,fx_gunflashdiag2);

			vector(_set,tmpvector,255,192,192);
			spawnlight(fire_light,4,Gactorpos,tmpvector,EmptyVector,200);
			vector(_set,Gactorpos,0,64,0);
			spawnparticle(fx_gunstrobeturret,4,Gactorpos,emptyvector,fx_gunstroberot);
			//muzzle flash
		}


		vector(_set,Gactorpos,-28,0,32);
		vector(_set,Gactorine,0,2048,0);
		spawnparticle(fx_flare,1,gactorpos,emptyvector,fx_rocklaserflarered);
		spawnparticle(fx_coplaser,1,gactorpos,gactorine,fx_rocklaser);
		spawnparticle(fx_coplaser,1,gactorpos,gactorine,fx_gunflashvert);
		spawnparticle(fx_coplaser,1,gactorpos,gactorine,fx_gunflashdiag1);
		spawnparticle(fx_coplaser,1,gactorpos,gactorine,fx_gunflashdiag2);
}




//test cannon methinks!
Actor(AutoCannon)
{
		file(AutoCannonHeader);
		startaction(nomovenocollision);

		vector(_declare,VL_LockedOnPos,0,0,0);
		vector(_declare,VL_LockedOnOffset,0,0,0);
		float(_declare,FL_AutoCannonOffset,0);
		float(_declare,anglex,0);
		float(_declare,angley,0);
		float(_declare,anglez,0);

		float(_declare,AutoCannon2Fire,0);


/*		printi("AC PathDestDist:     ",VPathDestDistance);
		printi("AC PathDestAngle:    ",VPathDestAngle);
		printi("AC PickDestAngle:    ",VPickDestAngle);
		printi("AC TargetDistance:   ",vtargetdistance);
		printi("AC TargetAngle:      ",vtargetangle);

		print("AC anglex:           ",anglex);
		print("AC angley:           ",angley);
		print("AC anglez:           ",anglez);
*/

		callsub(BackGroundTriggerChecks);

		call(AIupdateAIvars);

		call(CheckForVisual,_CLASSangel,1000);
		call(AIcheckfortarget,10);

		if(VActiveTime==1)
		{
			ActorFlag(_or,_AFLAGnomove);
		}

		if(VAItargetfound!=0)
		{
			call(AIselecttarget,_AIenemy);
			call(AIPickdest,10);

			vector(_settotargetpos,VL_LockedOnPos);
			vector(_sety,VL_LockedOnOffset,FL_AutoCannonOffset);
			vector(_add,VL_LockedOnPos,VL_LockedOnOffset);
			vector(_settargetpos,VL_LockedOnPos);

			if(VTargetAngle<-51)
			{
				float(_add,angley,-50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			elseif(VTargetAngle>51)
			{
				float(_add,angley,50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			else
			{
				if(FL_AutoCannonOffset<-100)
				{
					float(_set,FL_AutoCannonOffset,-100);
				}
				//fine tuning angle
				if(VTargetAngle<-11)
				{
					float(_add,angley,-10);
				}
				elseif(VTargetAngle>11)
				{
					float(_add,angley,10);
				}

				print("Correcting YAngle");

				if(VTargetAngleY<-11)
				{
					float(_add,anglex,10);
				}
				elseif(VTargetAngleY>11)
				{
					float(_add,anglex,-10);
				}
				if(VTargetAngleY>-51 && VTargetAngleY<51)
				{
					if(FL_AutoCannonOffset<0)
					{
						float(_add,FL_AutoCannonOffset,1);
					}

					if(AutoCannon2Fire==0)
					{
						sample(SFXMachineGunFire,-1);
						float(_set,AutoCannon2Fire,1);
					}

					spawnactor(BulletAutoCannon,0,15,-85);
					if(VTrigger==_DIRBulletFired)
					{
						call(SetParticleSetID);

						vector(_set,Gactorpos,0,15,-85);
						vector(_set,tmpvector,0,0,0);
						spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashhorizsmall);
						spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashvertsmall);
						spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag1small);
						spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag2small);

						if(vrnd<25)
						{
							float(_rnd2,tmpfloat,2);
							float(_sub,tmpfloat,1);
							vector(_set,gactorine,0,0,0);
							vector(_setx,gactorine,tmpfloat);
							spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
							spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
						}
					}
				}
				else
				{
					//stop fire, so stop sample loop
					if(AutoCannon2Fire==1)
					{
						samplestop(SFXMachineGunFire);
						float(_set,AutoCannon2Fire,0);
					}
				}
			}
		}
		else
		{
			float(_set,FL_AutoCannonOffset,-100);
			if(VAInotargettime>160)
			{
				if(angley<-6)
				{
					float(_add,angley,5);
				}
				else
				{
					float(_add,angley,-5);
				}
				else
				{
					float(_set,angley,0);
				}
				if(anglex<-6)
				{
					float(_add,anglex,5);
				}
				else
				{
					float(_add,anglex,-5);
				}
				else
				{
					float(_set,anglex,0);
				}
			}
		}

		if(angley>1024)
		{
			float(_set,angley,1024);
		}
		elseif(angley<-1024)
		{
			float(_set,angley,-1024);
		}
		if(anglex>512)
		{
			float(_set,anglex,512);
		}
		elseif(anglex<-512)
		{
			float(_set,anglex,-512);
		}

		if(anglex!=0 || angley!=0 || anglez!=0)
		{
			call(CalcTransMat,anglex,angley,anglez);
		}

		if(vhealth<=0)
		{
			//stop fire, so stop sample loop
			if(AutoCannon2Fire==1)
			{
				samplestop(SFXMachineGunFire);
				float(_set,AutoCannon2Fire,0);
			}

			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			CallSub(sub_fxexplosion);
			killactor();
		}
}

Actor(AutoCannon2)
{
		file(AutoCannonHeader);
		startaction(nomovenocollision);

		vector(_declare,VL_LockedOnPos,0,0,0);
		vector(_declare,VL_LockedOnOffset,0,0,0);
		float(_declare,FL_AutoCannonOffset,0);
		float(_declare,anglex,-512);
		float(_declare,angley,2048);
		float(_declare,anglez,0);

		float(_declare,AutoCannon2Fire,0);

		printi("AC PathDestDist:     ",VPathDestDistance);
		printi("AC PathDestAngle:    ",VPathDestAngle);
		printi("AC PickDestAngle:    ",VPickDestAngle);
		printi("AC TargetDistance:   ",vtargetdistance);
		printi("AC TargetAngle:      ",vtargetangle);
		printi("AC VTargetAngleY     ",VTargetAngleY);
		print("AC anglex:           ",anglex);
		print("AC angley:           ",angley);
		print("AC anglez:           ",anglez);
		print("AC offsety:          ",FL_AutoCannonOffset);


		call(AIupdateAIvars);

		call(CheckForVisual,_CLASSangel,1000);
		call(AIcheckfortarget,10);

		if(VActiveTime==1)
		{
			ActorFlag(_or,_AFLAGnomove);
		}

		if(VAItargetfound!=0 && VAItargetfound==_AIenemy)
		{
			call(AIselecttarget,_AIenemy);
			call(AIPickdest,10);

			vector(_settotargetpos,VL_LockedOnPos);
			vector(_sety,VL_LockedOnOffset,FL_AutoCannonOffset);
			vector(_add,VL_LockedOnPos,VL_LockedOnOffset);
			vector(_settargetpos,VL_LockedOnPos);

			if(VTargetAngle<-51)
			{
				float(_add,angley,-50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			elseif(VTargetAngle>51)
			{
				float(_add,angley,50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			else
			{
				if(FL_AutoCannonOffset<-100)
				{
					float(_set,FL_AutoCannonOffset,-100);
				}
				//fine tuning angle
				if(VTargetAngle<-11)
				{
					float(_add,angley,-10);
				}
				elseif(VTargetAngle>11)
				{
					float(_add,angley,10);
				}

				print("Correcting YAngle");

				if(VTargetAngleY<-11)
				{
					float(_add,anglex,10);
				}
				elseif(VTargetAngleY>11)
				{
					float(_add,anglex,-10);
				}

				if(VTargetAngleY>-51 && VTargetAngleY<51)
				{
					if(FL_AutoCannonOffset<0)
					{
						float(_add,FL_AutoCannonOffset,1);
					}
					if(LabAlarm!=0)
					{
						if(AutoCannon2Fire==0)
						{
							sample(SFXMachineGunFire,-1);
							float(_set,AutoCannon2Fire,1);
						}

						spawnactor(BulletAutoCannon,0,15,-85);
						if(VTrigger==_DIRBulletFired)
						{
							call(SetParticleSetID,"s3_lab05");

							float(_rnd2,tmpfloat,100)

							vector(_set,Gactorpos,0,15,-85);
							vector(_set,tmpvector,0,0,0);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashhorizsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashvertsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag1small);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag2small);

							if(vrnd<25)
							{
								float(_rnd2,tmpfloat,2);
								float(_sub,tmpfloat,1);
								vector(_set,gactorine,0,0,0);
								vector(_setx,gactorine,tmpfloat);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
							}
						}
					}
					else
					{
						//stop fire, so stop sample loop
						if(AutoCannon2Fire==1)
						{
							samplestop(SFXMachineGunFire);
							float(_set,AutoCannon2Fire,0);
						}
					}
				}
			}
		}
		else
		{
			float(_set,FL_AutoCannonOffset,-100);
			if(VAInotargettime>160)
			{
				if(angley<-6)
				{
					float(_add,angley,5);
				}
				else
				{
					float(_add,angley,-5);
				}
				else
				{
					float(_set,angley,0);
				}
				if(anglex<-6)
				{
					float(_add,anglex,5);
				}
				else
				{
					float(_add,anglex,-5);
				}
				else
				{
					float(_set,anglex,0);
				}
			}
		}


		if(angley>2176)
		{
			float(_set,angley,2176);
		}
		elseif(angley<896)
		{
			float(_set,angley,896);
		}
		if(anglex>512)
		{
			float(_set,anglex,512);
		}
		elseif(anglex<-512)
		{
			float(_set,anglex,-512);
		}

		if(anglex!=0 || angley!=0 || anglez!=0)
		{
			call(CalcTransMat,anglex,angley,anglez);
		}

		if(VarKey108==0)
		{
			vector(_settoactorpos,Gactorpos);
			vector(_copyy,Gactorpos,tmpfloat);
			if(tmpfloat<3750)
			{
				float(_add,tmpfloat,1);
				vector(_sety,Gactorpos,tmpfloat);
				vector(_setactorpos,Gactorpos);
			}
		}
		elseif(VarKey108==1)
		{
			vector(_settoactorpos,Gactorpos);
			vector(_copyy,Gactorpos,tmpfloat);
			if(tmpfloat>3700)
			{
				print("Y COORDINATE: ",tmpfloat);
				float(_sub,tmpfloat,1);
				vector(_sety,Gactorpos,tmpfloat);
				vector(_setactorpos,Gactorpos);
			}
		}

		if(vhealth<=0)
		{
			//stop fire, so stop sample loop
			if(AutoCannon2Fire==1)
			{
				samplestop(SFXMachineGunFire);
			}
			float(_set,AutoCannon2Fire,0);

			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			CallSub(sub_fxexplosion);
			killactor();
		}
}


Actor(AutoCannon3)
{
		file(AutoCannonHeader);
		startaction(nomovenocollision);

		vector(_declare,VL_LockedOnPos,0,0,0);
		vector(_declare,VL_LockedOnOffset,0,0,0);
		float(_declare,FL_AutoCannonOffset,0);
		float(_declare,anglex,-512);
		float(_declare,angley,2048);
		float(_declare,anglez,0);

		float(_declare,AutoCannon2Fire,0);

/*		printi("AC PathDestDist:     ",VPathDestDistance);
		printi("AC PathDestAngle:    ",VPathDestAngle);
		printi("AC PickDestAngle:    ",VPickDestAngle);
		printi("AC TargetDistance:   ",vtargetdistance);
		printi("AC TargetAngle:      ",vtargetangle);

		print("AC anglex:           ",anglex);
		print("AC angley:           ",angley);
		print("AC anglez:           ",anglez);
*/



		call(AIupdateAIvars);

		call(CheckForVisual,_CLASSangel,1000);
		call(AIcheckfortarget,10);

		if(VActiveTime==1)
		{
			ActorFlag(_or,_AFLAGnomove);
		}

		if(VAItargetfound!=0 && VAItargetfound==_AIenemy)
		{

			call(AIselecttarget,_AIenemy);
			call(AIPickdest,10);

			vector(_settotargetpos,VL_LockedOnPos);
			vector(_sety,VL_LockedOnOffset,FL_AutoCannonOffset);
			vector(_add,VL_LockedOnPos,VL_LockedOnOffset);
			vector(_settargetpos,VL_LockedOnPos);

			if(VTargetAngle<-51)
			{
				float(_add,angley,-50);
				float(_sub,FL_AutoCannonOffset,1);
				if(VCheatKeys==1)
				{
					if(VKey==KEY_Y)
					{
						float(_seti,tmpfloat,VTargetAngle);
						break(angley,FL_AutoCannonOffset,tmpfloat);
					}
				}
			}
			elseif(VTargetAngle>51)
			{
				float(_add,angley,50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			else
			{

				if(FL_AutoCannonOffset<-100)
				{
					float(_set,FL_AutoCannonOffset,-100);
				}
				//fine tuning angle
				if(VTargetAngle<-11)
				{
					float(_add,angley,-10);
				}
				elseif(VTargetAngle>11)
				{
					float(_add,angley,10);
				}

				print("Correcting YAngle");

				if(VTargetAngleY<-11)
				{
					float(_add,anglex,10);
				}
				elseif(VTargetAngleY>11)
				{
					float(_add,anglex,-10);
				}

				if(VTargetAngleY>-51 && VTargetAngleY<51)
				{
					if(FL_AutoCannonOffset<0)
					{
						float(_add,FL_AutoCannonOffset,1);
					}
					if(LabAlarm!=0)
					{
						if(AutoCannon2Fire==0)
						{
							sample(SFXMachineGunFire,-1);
							float(_set,AutoCannon2Fire,1);
						}

						spawnactor(BulletAutoCannon,0,15,-85);
						if(VTrigger==_DIRBulletFired)
						{
							call(SetParticleSetID,"s3_lab05");

							float(_rnd2,tmpfloat,100)

							vector(_set,Gactorpos,0,15,-85);
							vector(_set,tmpvector,0,0,0);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashhorizsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashvertsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag1small);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag2small);

							if(vrnd<25)
							{
								float(_rnd2,tmpfloat,2);
								float(_sub,tmpfloat,1);
								vector(_set,gactorine,0,0,0);
								vector(_setx,gactorine,tmpfloat);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
							}
						}
					}
					else
					{
						//stop fire, so stop sample loop
						if(AutoCannon2Fire==1)
						{
							samplestop(SFXMachineGunFire);
							float(_set,AutoCannon2Fire,0);
						}
					}
				}
			}
		}
		else
		{
			float(_set,FL_AutoCannonOffset,-100);
			if(VAInotargettime>160)
			{
				if(angley<-6)
				{
					float(_add,angley,5);
				}
				else
				{
					float(_add,angley,-5);
				}
				else
				{
					float(_set,angley,0);
				}
				if(anglex<-6)
				{
					float(_add,anglex,5);
				}
				else
				{
					float(_add,anglex,-5);
				}
				else
				{
					float(_set,anglex,0);
				}
			}
		}


		if(angley>3204)
		{
			float(_set,angley,3204);
		}
		elseif(angley<1920)
		{
			float(_set,angley,1920);
		}
		if(anglex>512)
		{
			float(_set,anglex,512);
		}
		elseif(anglex<-512)
		{
			float(_set,anglex,-512);
		}



		if(anglex!=0 || angley!=0 || anglez!=0)
		{
			call(CalcTransMat,anglex,angley,anglez);
		}
	
			  
		if(VarKey108==0)
		{
			vector(_settoactorpos,Gactorpos);
			vector(_copyy,Gactorpos,tmpfloat);
			if(tmpfloat<3750)
			{
				float(_add,tmpfloat,1);
				vector(_sety,Gactorpos,tmpfloat);
				vector(_setactorpos,Gactorpos);
			}
		}
		elseif(VarKey108==1)
		{
			vector(_settoactorpos,Gactorpos);
			vector(_copyy,Gactorpos,tmpfloat);
			if(tmpfloat>3700)
			{
				print("Y COORDINATE: ",tmpfloat);
				float(_sub,tmpfloat,1);
				vector(_sety,Gactorpos,tmpfloat);
				vector(_setactorpos,Gactorpos);
			}
		}

		if(vhealth<=0)
		{
			//stop fire, so stop sample loop
			if(AutoCannon2Fire==1)
			{
				samplestop(SFXMachineGunFire);
				float(_set,AutoCannon2Fire,0);
			}

			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			CallSub(sub_fxexplosion);
			killactor();
		}
}



Actor(AutoCannon4)
{
		file(AutoCannonHeader);
		startaction(nomovenocollision);

		vector(_declare,VL_LockedOnPos,0,0,0);
		vector(_declare,VL_LockedOnOffset,0,0,0);
		float(_declare,FL_AutoCannonOffset,0);
		float(_declare,anglex,-512);
		float(_declare,angley,2048);
		float(_declare,anglez,0);

		float(_declare,AutoCannon2Fire,0);


/*		printi("AC PathDestDist:     ",VPathDestDistance);
		printi("AC PathDestAngle:    ",VPathDestAngle);
		printi("AC PickDestAngle:    ",VPickDestAngle);
		printi("AC TargetDistance:   ",vtargetdistance);
		printi("AC TargetAngle:      ",vtargetangle);

		print("AC anglex:           ",anglex);
		print("AC angley:           ",angley);
		print("AC anglez:           ",anglez);
*/


		call(AIupdateAIvars);

		call(CheckForVisual,_CLASSangel,1000);
		call(AIcheckfortarget,10);

		if(VActiveTime==1)
		{
			ActorFlag(_or,_AFLAGnomove);
		}

		if(VAItargetfound!=0 && VAItargetfound==_AIFriend)
		{
			call(AIselecttarget,_AIenemy);
			call(AIPickdest,10);

			vector(_settotargetpos,VL_LockedOnPos);
			vector(_sety,VL_LockedOnOffset,FL_AutoCannonOffset);
			vector(_add,VL_LockedOnPos,VL_LockedOnOffset);
			vector(_settargetpos,VL_LockedOnPos);

			if(VTargetAngle<-51)
			{
				float(_add,angley,-50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			elseif(VTargetAngle>51)
			{
				float(_add,angley,50);
				float(_sub,FL_AutoCannonOffset,1);
			}
			else
			{
				if(FL_AutoCannonOffset<-100)
				{
					float(_set,FL_AutoCannonOffset,-100);
				}
				//fine tuning angle
				if(VTargetAngle<-11)
				{
					float(_add,angley,-10);
				}
				elseif(VTargetAngle>11)
				{
					float(_add,angley,10);
				}

				print("Correcting YAngle");

				if(VTargetAngleY<-11)
				{
					float(_add,anglex,10);
				}
				elseif(VTargetAngleY>11)
				{
					float(_add,anglex,-10);
				}

				if(VTargetAngleY>-51 && VTargetAngleY<51)
				{
					if(FL_AutoCannonOffset<0)
					{
						float(_add,FL_AutoCannonOffset,1);
					}
					if(LabAlarm!=0)
					{
						if(AutoCannon2Fire==0)
						{
							sample(SFXMachineGunFire,-1);
							float(_set,AutoCannon2Fire,1);
						}

						spawnactor(BulletAutoCannon,0,15,-85);
						if(VTrigger==_DIRBulletFired)
						{
							call(SetParticleSetID,"S3_lab07");

							float(_rnd2,tmpfloat,100)

							vector(_set,Gactorpos,0,15,-85);
							vector(_set,tmpvector,0,0,0);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashhorizsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashvertsmall);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag1small);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,tmpvector,fx_gunflashdiag2small);

							if(vrnd<25)
							{
								float(_rnd2,tmpfloat,2);
								float(_sub,tmpfloat,1);
								vector(_set,gactorine,0,0,0);
								vector(_setx,gactorine,tmpfloat);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmokeac);
							}
						}
					}
					else
					{
						//stop fire, so stop sample loop
						if(AutoCannon2Fire==1)
						{
							samplestop(SFXMachineGunFire);
							float(_set,AutoCannon2Fire,0);
						}
					}
				}
			}
		}
		else
		{
			float(_set,FL_AutoCannonOffset,-100);
			if(VAInotargettime>160)
			{
				if(angley<-6)
				{
					float(_add,angley,5);
				}
				else
				{
					float(_add,angley,-5);
				}
				else
				{
					float(_set,angley,0);
				}
				if(anglex<-6)
				{
					float(_add,anglex,5);
				}
				else
				{
					float(_add,anglex,-5);
				}
				else
				{
					float(_set,anglex,0);
				}
			}
		}


/*		if(angley>3204)
		{
			float(_set,angley,3204);
		}*/
		if(angley>3640)
		{
			float(_set,angley,3640);
		}
		elseif(angley<1920)
		{
			float(_set,angley,1920);
		}
		if(anglex>512)
		{
			float(_set,anglex,512);
		}
		elseif(anglex<-512)
		{
			float(_set,anglex,-512);
		}




		if(anglex!=0 || angley!=0 || anglez!=0)
		{
			call(CalcTransMat,anglex,angley,anglez);
		}
	
			  
/*		if(VarKey108==0)
		{
			vector(_settoactorpos,Gactorpos);
			vector(_copyy,Gactorpos,tmpfloat);
			if(tmpfloat<3750)
			{
				float(_add,tmpfloat,1);
				vector(_sety,Gactorpos,tmpfloat);
				vector(_setactorpos,Gactorpos);
			}
		}
		elseif(VarKey108==1)
		{
			vector(_settoactorpos,Gactorpos);
			vector(_copyy,Gactorpos,tmpfloat);
			if(tmpfloat>3700)
			{
				print("Y COORDINATE: ",tmpfloat);
				float(_sub,tmpfloat,1);
				vector(_sety,Gactorpos,tmpfloat);
				vector(_setactorpos,Gactorpos);
			}
		}*/

		if(vhealth<=0)
		{
			//stop fire, so stop sample loop
			if(AutoCannon2Fire==1)
			{
				samplestop(SFXMachineGunFire);
				float(_set,AutoCannon2Fire,0);
			}

			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			CallSub(sub_fxexplosion);
			killactor();
		}
}

