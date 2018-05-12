// Military Zone

//VarKey81
//	1 - mz_02 birdview sequence has been activated
//	2 - mz_02 birdview sequence is going on
//	4 - left control tower up/down bit
//	8 - left control tower up/down bit
//	16 - left gun is blown to bits
//	32 - right gun is blown to bits
//	64 - panel on right control tower is blown up
//	128 - mz_09 birdview sequence has been triggered
//	256 - mz_09 birdview sequence has been initialized
//	512 - mz_09 birdview sequence is going on
//	1024 - right control tower up/down bit
//	2048 - right control tower up/down bit
//	4096 - birdview set camera to normal
//	8192 - elevator in mz_01 is moving
//	16384 - shiplaunch sound has been played

//VarKey82
//	1 - mztunl1&2 door01 can be triggered
//	2 - mztunl1&2 door can be triggered
//	4 - beast1 is engaged
//	8 - beast2 is engaged
//	16 - beast3 is engaged
//	32 - door light in mz_08
//	64 - elevator up for mz_08
//	128 - elevator down for mz_08
//	256 - door in mz_08 can be opened
//	512	- tell abeast to be pissed
//	1024 - don't trigger pissed sequence again
//  2048 - door in mz_07 can be opened
//	4096 - Beam me up, Scotty !
//	8192 - For player input in beast scene
//	16384 - For bob dropping to lower level in MZ

//VarKey83	- guns in mz04
//	1		- left gun is enemy
//	2		- left gun hit once
//	4		- left gun hit twice
//	8		- right gun is enemy
//	16		- right gun hit once
//	32		- right gun hit twice



//
//VarBit (David's lovely beautiful variable)
//	Help01	-	check if Player stays clear in MZ_04 if he's not a commander
//	Help02	-	Check if Heavy Cop is still scanning the area in MZ_04
//	Help03	-	Cops freak out when canon is pointing at them in MZ_07
//	Help04	-	Transport toggle
//	Help05	-	Dumbass move : everyone is dead. Gotta respawn some guys...
//	Help06	-	The Beast is in da house !
//	Help07	-	Is off while in the bird
//  Help08  -	Get rid of Domina's grenade at the beginning of the level
//	Help09	-	Stops the warning messages if cops are opening fire in MZ_04


//IntroCam - Camera for the intro of the level
//CommandTimer - timer for the Heavy Cop before he calls for help in MZ_04
//CallBot	-	TroupTransport Vehicle
//PillarEvent	-	Teleportation room

//VarKey90 - a timer

//VarKey85	- gun control value
//VarKey86	- steamcounter for mz_09 and shootdelaytimer for aigun in mz_04

SubRoutine(InitSceneSound17)
{

			float(_set,PowerOn,1);		
			if(incoming!=0)
			{
				if(ScriptMark==24)
				{
					callsub(Panel24);
				}
			}
			else
			{
				callsub(ScriptLevel17);
			}

			call(fadetoblack,2);
			vector(_set,gactorpos,-5984, 24580, 7426);		//beast 1
			sample(SFXBreathing,gactorpos);
			vector(_set,gactorpos,-5687, 24580, 7426);		//beast 2
			sample(SFXBreathing,gactorpos);
			vector(_set,gactorpos,-5984, 24580, 6379);		//beast 3
			sample(SFXBreathing,gactorpos);

			//mz_10
			vector(_set,Gactorpos,-10998,24459,5829);
			sample(SFXBreathing,Gactorpos);

			
			
			//AMBIENT SOUNDS FOR LEVEL
			vector(_set,gactorpos,-14976,24500,8649);
			sample(SFXFieldHumLoop,Gactorpos);

			vector(_set,gactorpos,-10933,25751,11146);
			sample(SFXIndustrial2,Gactorpos);

			vector(_set,gactorpos,-6462,25629,10560);
			sample(SFXCityAmbient01,Gactorpos);

			vector(_set,gactorpos,-14822,24790,8650);
			sample(SFXRotatingPipe,Gactorpos);

			vector(_set,gactorpos,-6576,24853,6907);
			sample(SFXIndustrial2,Gactorpos);

			vector(_set,gactorpos,-10928,25372,4543);
			sample(SFXIndustrial1,Gactorpos);
			call(CDPlay,17,1);
			call(fadetoblack,2);
}

SubRoutine(DeInitSceneSound17)
{
			vector(_set,gactorpos,-5984, 24580, 7426);		//beast 1
			samplestop(SFXBreathing,gactorpos);
			vector(_set,gactorpos,-5687, 24580, 7426);		//beast 2
			samplestop(SFXBreathing,gactorpos);
			vector(_set,gactorpos,-5984, 24580, 6379);		//beast 3
			samplestop(SFXBreathing,gactorpos);

			//mz_10
			vector(_set,Gactorpos,-10998,24459,5829);
			samplestop(SFXBreathing,Gactorpos);


			//AMBIENT SOUNDS FOR LEVEL
			vector(_set,gactorpos,-14976,24500,8649);
			samplestop(SFXGlobeIdle,Gactorpos);

			vector(_set,gactorpos,-10933,25751,11146);
			samplestop(SFXIndustrial2,Gactorpos);

			vector(_set,gactorpos,-6462,25629,10560);
			samplestop(SFXCityAmbient01,Gactorpos);

			vector(_set,gactorpos,-14822,24790,8650);
			samplestop(SFXIndustrial10,Gactorpos);

			vector(_set,gactorpos,-6576,24853,6907);
			samplestop(SFXIndustrial2,Gactorpos);

			vector(_set,gactorpos,-10928,25372,4543);
			samplestop(SFXIndustrial1,Gactorpos);
}


SubRoutine(InitScene17)
{
			vector(_set,Gactorangle,0,-1024,0);
			InitActor(Bob1,0,Gactorangle,"elevent");

			//Set of Variables for Military Zone
			call(loadpreloaddb,19);
			float(_set,VarKey81,0);
			float(_set,VarKey82,0);
			float(_set,VarKey83,0);
			float(_set,VarKey84,0);
			float(_set,VarKey85,0);
			float(_set,VarKey86,0);
			float(_set,VarKey87,0);
			float(_set,VarKey88,0);
			float(_set,VarKey89,0);
			float(_set,VarKey90,0);
			float(_set,IntroCam,0);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
			float(_set,timer4,0);
			float(_set,HudTimer,0);
			float(_set,Callbot,0);
			float(_set,PillarEvent,0);
			float(_set,VarBit,AllHelp);
			float(_set,CommandTimer,0);
			float(_set,ControlTimer,0);
			float(_set,PowerOn,1);

			#include "messiahscripts\enemies\military.spt"


			//	will be put in scene17sfx.hxx later
			//
//			vector(_set,gactorpos,-14983,25048,8319);
//			sample(SFXBirdSquak,Gactorpos);


			callsub(InitSceneSound17);
			
}

SubRoutine(MainScene17)
{
	if(VarKey81&=128 && VarKey81&!=512)
	{
		float(_rnd2,tmpfloat,300);
		if(tmpfloat<0.5)
		{
			sample(SFXBirdScream1,-1);
		}
		elseif(tmpfloat<1)
		{
			sample(SFXBirdScream2,-1);
		}
	}
	
	//	SOUND EFFECTS FOR ALL LEVELS
	//
	if(VCurSet=="mztunl1")
	{
		CurEnvTrigger("arme");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,-8088,24573,10733);
			callsub(DispenserSound);
		}
		CurEnvTrigger("arme1");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,-7788,24573,10733);
			callsub(DispenserSound);
		}
	}
	if(VCurSet=="mztunl2")
	{
		CurEnvTrigger("arme");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,-14087,24573,10733);
			callsub(DispenserSound);
		}
		CurEnvTrigger("arme1");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,-13787,24573,10733);
			callsub(DispenserSound);
		}
	}



	//	CODE TO BE CHECKED THAT ARE NOT CHARACTER SPECIFIC
	//
	if(VSetActive=="mz_02")
	{
		if(VarKey82&=256)
		{
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_Set,TmpFloat,0x7f0000);
		}
		CurEnvTriggerSet("mz_02","Door");
		call(ExpSet1,1,TmpFloat,0);

		if(VarKey81&=2 && VCutSceneFrameEqual==30)
		{
			if(vrnd<50)
			{
				sample(SFXBirdScream1,-1);
			}
			else
			{
				sample(SFXBirdScream2,-1);
			}
		}
	}
	if(VSetActive=="mz_03")
	{
		if(VarKey81&=4)
		{
			CurEnvTriggerSet("Mz_03","TurretGo");
			if(VKeyObjTriggered==0)
			{
				CurEnvTriggerSet("Mz_03","OverRide");
				call(KeyObjTrigger,255,1);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				float(_clr,VarKey81,4);
			}
		}
		elseif(VarKey81&=8)
		{
			CurEnvTriggerSet("Mz_03","OverRide");
			if(VKeyObjTriggered==0)
			{
				CurEnvTriggerSet("Mz_03","TurretGo");
				call(KeyObjTrigger,0,-1);
				vector(_set,Gactorpos,-8687,24897,10201);
				Sample(SFXPneumatik,Gactorpos);
				float(_clr,VarKey81,8);
			}
		}
	}
	if(VSetActive=="mz_07")
	{
		if(VarKey82&=2048)
		{
			float(_set,TmpFloat,0xff00);
		}
		else
		{
			float(_Set,TmpFloat,0xff0000);
		}
		CurEnvTriggerSet("mz_07","Door");
		call(ExpSet1,1,TmpFloat,0);
	}

	if(VSetActive=="MZtunl1")
	{
		CurEnvTriggerSet("MZtunl1","Door01");
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey82,2);
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_clr,VarKey82,2);
			float(_set,TmpFloat,0x7f0000);
		}

		CurEnvTriggerSet("MZtunl1","Door");
		call(expset1,1,TmpFloat,0);
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey82,1);
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_clr,VarKey82,1);
			float(_set,TmpFloat,0x7f0000);
		}

		CurEnvTriggerSet("MZtunl1","Door01");
		call(expset1,1,TmpFloat,0);
	}
	if(VSetActive=="MZtunl2")
	{
		CurEnvTriggerSet("MZtunl2","Door01");
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey82,2);
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_clr,VarKey82,2);
			float(_set,TmpFloat,0x7f0000);
		}

		CurEnvTriggerSet("MZtunl2","Door");
		call(expset1,1,TmpFloat,0);
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey82,1);
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_clr,VarKey82,1);
			float(_set,TmpFloat,0x7f0000);
		}

		CurEnvTriggerSet("MZtunl2","Door01");
		call(expset1,1,TmpFloat,0);
	}

	if(VSetActive=="mz_04")
	{
		CurEnvTriggerSet("mz_04","warn02");
		call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
		if(TmpFloat==TRUE)
		{
			sample(SFXGlassLarge,-1);
		}

		//**********************
		//Troup Transport Script
		//**********************
		if(VarBit&!=Help24 && VarBit&=Help07)
		{
			if(CallBot==1)
			{
				//****** Turn everything visible and destructible ****
				CurEnvTriggerSet("mz_04","warn01");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				CurEnvTriggerSet("mz_04","trans01");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
				CurEnvTriggerSet("mz_04","trans02");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);				
				float(_set,TmpFloat,0x2255ff);
				CurEnvTriggerSet("mz_04","trans03");
				call(expset1,TmpFloat,400,-1);
				call(expset2,TmpFloat,300,-1);
				CurEnvTriggerSet("mz_04","trans04");
				call(expset1,TmpFloat,300,-1);
				call(expset2,TmpFloat,300,-1);
				float(_set,CallBot,2);
			}
			elseif(CallBot==3)
			{
				CurEnvTriggerSet("mz_04","trans01");
				call(KeyObjTrigger,255,1);
				float(_set,CallBot,4);
			}
			elseif(CallBot==4)
			{
				CurEnvTriggerSet("mz_04","trans01");
				if(VKeyObjFrame==16)
				{
					float(_set,AIVisiontoggle,0);
					float(_set,CallBot,5);
				}
				elseif(VKeyObjFrame==11)
				{
					if(VarKey81&!=16384)
					{
						float(_or,VarKey81,16384);
						//vector(_set,Gactorpos,-11006,24981,11198);
						sample(SFXShipLaunch,-1,95);
					}
				}
			}
			call(SetParticleSetID,"mz_04");
			CurEnvTriggerSet("mz_04","trans01");
			if(VKeyObjFrame<22)
			{
				vector(_set,Gactorine,0,-5,0);
				vector(_settokfpos,Gactorpos,1);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
				vector(_settokfpos,Gactorpos,2);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
				CurEnvTriggerSet("mz_04","trans02");
				vector(_set,Gactorine,0,-5,0);
				vector(_settokfpos,Gactorpos,1);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
				vector(_settokfpos,Gactorpos,2);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
			}
			else
			{
				CurEnvTriggerSet("mz_04","warn01");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				CurEnvTriggerSet("mz_04","trans01");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				CurEnvTriggerSet("mz_04","trans02");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				float(_or,VarBit,Help24);
			}
		}
		if(VarBit&!=Help05 && Varbit&=Help07)
		{
			
			if(CommandTimer==2)
			{
				CurEnvTriggerSet("mz_04","warn01");
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
				CurEnvTriggerSet("mz_04","trans05");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
				CurEnvTriggerSet("mz_04","trans06");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);	
				CurEnvTriggerSet("mz_04","trans07");
				float(_set,TmpFloat,0x2255ff);
				call(expset1,TmpFloat,400,-1);
				float(_set,CommandTimer,3);
			}
			elseif(Commandtimer==3)
			{
				float(_add,timer3,1);
				if(timer3>=50)
				{
					float(_set,CommandTimer,4);
					float(_set,timer3,0);
				}
			}
			elseif(CommandTimer==4)
			{
				CurEnvTriggerSet("mz_04","trans02");
				call(KeyObjTrigger,2,1);
				float(_set,CommandTimer,5);
			}
			elseif(CommandTimer==5)
			{
				CurEnvTriggerSet("mz_04","trans02");
				if(VKeyObjFrame==2)
				{
					float(_set,CommandTimer,6)
				}
			}
			elseif(CommandTimer==8)
			{
				CurEnvTriggerSet("mz_04","trans02");
				call(KeyObjTrigger,255,1);
				float(_set,CommandTimer,9);
			}
			elseif(CommandTimer==9)
			{
				CurEnvTriggerSet("mz_04","trans02");
				if(VKeyObjTriggered==0)
				{
					float(_or,VarBit,Help05);
					setkeyframe("Mz_04","trans02",0);
					CurEnvTriggerSet("mz_04","warn01");
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTriggerSet("mz_04","trans05");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTriggerSet("mz_04","trans06");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					float(_set,CommandTimer,0);	
				}
			}
			call(SetParticleSetID,"mz_04");
			CurEnvTriggerSet("mz_04","trans02");
			if(VKeyObjFrame<4)
			{
				CurEnvTriggerSet("mz_04","trans06");
				vector(_set,Gactorine,0,-5,0);
				vector(_settokfpos,Gactorpos,1);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
				vector(_settokfpos,Gactorpos,2);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
				CurEnvTriggerSet("mz_04","trans05");
				vector(_set,Gactorine,0,-5,0);
				vector(_settokfpos,Gactorpos,1);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
				vector(_settokfpos,Gactorpos,2);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_transport);
			}
		}

		//******************************
		// End of troup transport script
		//******************************

		CurEnvTriggerSet("mz_04","BarLeft");
		if(VarKey81&!=16)
		{
			if(VarKey83&!=2)
			{
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					float(_or,VarKey83,2);
					call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff|_SXObjInvisible);
				}
			}
			else
			{
				if(VarKey83&!=4)
				{
					call(CheckTriggerObjFlag,TmpFloat,2,_SXObjDynamicObj);
					if(TmpFloat==TRUE)
					{
						float(_or,VarKey83,4);
						call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff|_SXObjInvisible);
					}
				}
				else
				{
					call(CheckTriggerObjFlag,TmpFloat,0,_SXObjDynamicObj);
					if(TmpFloat==TRUE)
					{
						float(_or,VarKey81,16);
						CurEnvTriggerSet("mz_04","jumpout");
						call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					}
				}
			}
		}

		CurEnvTriggerSet("mz_04","BarRight");
		if(VarKey81&!=32)
		{
			if(VarKey83&!=16)
			{
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					float(_or,VarKey83,16);
					call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff|_SXObjInvisible);
				}
			}
			else
			{
				if(VarKey83&!=32)
				{
					call(CheckTriggerObjFlag,TmpFloat,2,_SXObjDynamicObj);
					if(TmpFloat==TRUE)
					{
						float(_or,VarKey83,32);
						call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff|_SXObjInvisible);
					}
				}
				else
				{
					call(CheckTriggerObjFlag,TmpFloat,0,_SXObjDynamicObj);
					if(TmpFloat==TRUE)
					{
						float(_or,VarKey81,32);
						CurEnvTriggerSet("mz_04","jumpout");
						call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					}
				}
			}
		}



	}
	if(VSetActive=="mz_05")
	{
		CurEnvTriggerSet("mz_05","OverRide");
		call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
		if(TmpFloat==TRUE)
		{
			float(_or,VarKey81,64);
			call(ChangeTrigger,_set,_SXTrigPanel);
		}
		if(VarKey81&=1024)
		{
			CurEnvTriggerSet("Mz_05","TurretGo");
			if(VKeyObjTriggered==0)
			{
				CurEnvTriggerSet("Mz_05","OverRide");
				call(KeyObjTrigger,255,1);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				float(_clr,VarKey81,1024);
			}
		}
		elseif(VarKey81&=2048)
		{
			CurEnvTriggerSet("Mz_05","OverRide");
			if(VKeyObjTriggered==0)
			{
				CurEnvTriggerSet("Mz_05","TurretGo");
				call(KeyObjTrigger,0,-1);
				vector(_set,Gactorpos,-13187,24897,10201);
				Sample(SFXPneumatik,Gactorpos);
				float(_clr,VarKey81,2048);
			}
		}
	}
	if(VSetActive=="mz_11")
	{
		if(PillarEvent==0)
		{
			CurEnvTriggerSet("mz_11","tele");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,10,-1);
			call(expset2,1,1,1);
			float(_set,HudTimer,0xffffff);
			float(_set,timer4,0);
		}
		elseif(PillarEvent>=1)
		{
			CurEnvTriggerSet("mz_11","tele");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				sample(SFXScanPlateOn,-1);
			}
		}
		if(PillarEvent>=4)
		{
			float(_add,timer4,1);
			CurEnvTriggerSet("mz_11","teleport");
			if(timer4&=1)
			{
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			}
			else
			{
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			}
			if(VKeyObjTriggered==0)
			{
				float(_set,SteamTimer,0x010101);
				float(_set,HudTimer,0xffffff);
				call(KeyObjTrigger,255,1);
				sample(SFXHumTeleport,-1);
			}
			if(VKeyObjFrame>=2)
			{
				float(_sub,HudTimer,SteamTimer);
				call(expset2,1,HudTimer,0);
			}
			call(SetParticleSetID,"mz_11");
			float(_rnd2,TmpFloat,315);
			vector(_set,TmpVector,0,0,0);
			vector(_sety,TmpVector,TmpFloat);
			vector(_set,Gactorpos,-11069,24516,4387);
			vector(_set,Gactorine,-10805,24516,4387);
			vector(_add,Gactorpos,TmpVector);
			vector(_add,Gactorine,TmpVector);
			callsub(laserStrip,gactorpos,gactorine,fx_yellow,0);
			vector(_set,PosVector1,-10936,24643,4386);
			vector(_set,PosVector2,0,0,0);
			float(_rnd2,TmpFloat,1300); //y
			float(_rnd2,TmpFloat1,3000); //x
			vector(_set,PosVector3,-12233,24124,5406);
			vector(_setx,PosVector2,TmpFloat1);
			vector(_sety,PosVector2,TmpFloat);
			vector(_add,PosVector3,PosVector2);
			callsub(ElectricStrip,PosVector1,PosVector3,fx_yellow);
			
			
			float(_rnd2,tmpfloat,100);
			if(tmpfloat<3)
			{
				sample(SFXZap,-1);
			}
			elseif(tmpfloat<13)
			{
				vector(_set,gactorpos,-10936,24571,4386);
				sample(SFXTeslaCoil,Gactorpos);
			}
		}
	}
	if(VSetActive=="Mz_09")
	{
		float(_rnd2,tmpfloat,1000);
		if(tmpfloat<=1)
		{
			vector(_set,gactorpos,-14983,25048,8319);
			sample(SFXBirdSquak,Gactorpos);
		}
		
		CurEnvTriggerSet("Mz_09","Control");
		if(VKeyObjTriggered==0)
		{
			Call(KeyObjTrigger,255,1);
			vector(_set,Gactorpos,-14978,24597,8654);
			sample(SFXHatchEnd,gactorpos);
		}
		else
		{
			if(VKeyObjFrame==13)
			{
				vector(_set,Gactorpos,-14978,24597,8654);
				SamplePlaying(SFXWeaponCharge,Gactorpos);
				if(VTrigger!=_DIRTempFlag)
				{
					sample(SFXWeaponCharge,gactorpos);
				}
			}
			elseif(VKeyObjFrame==33)
			{
				vector(_set,Gactorpos,-14978,24597,8654);
				//SamplePlaying(SFXWeaponCharge,Gactorpos);
				//if(VTrigger!=_DIRTempFlag)
				//{
					samplestop(SFXWeaponCharge,gactorpos);
				//}

				vector(_set,Gactorpos,-14978,24597,8654);
				SamplePlaying(SFXHatchEnd,Gactorpos);
				if(VTrigger!=_DIRTempFlag)
				{
					sample(SFXHatchEnd,gactorpos);
				}
			}
		}

		if(VRnd<50)
		{
			call(SetParticleSetID,"mz_09");

			vector(_set,Gactorine,0,10,0);
			if(VarKey86<100)
			{
				vector(_set,Gactorpos,-14904,24340,9051);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==0)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<200)
			{
				vector(_set,Gactorpos,-15062,24340,9051);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==100)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<300)
			{
				vector(_set,Gactorpos,-14904,24340,8241);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==200)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<400)
			{
				vector(_set,Gactorpos,-15210,24340,8312);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==300)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<500)
			{
				vector(_set,Gactorpos,-15062,24340,8241);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==400)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<600)
			{
				vector(_set,Gactorpos,-15312,24340,8417);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==500)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<700)
			{
				vector(_set,Gactorpos,-15392,24340,8551);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==600)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<800)
			{
				vector(_set,Gactorpos,-15389,24340,8720);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==700)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<900)
			{
				vector(_set,Gactorpos,-15317,24340,8875);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==800)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
			elseif(VarKey86<1000)
			{
				vector(_set,Gactorpos,-15220,24340,8970);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				if(VarKey86==900)
				{
					sample(SFXVent2,Gactorpos);
				}
			}
		}

		float(_add,VarKey86,1);
		if(VarKey86>1100)
		{
			float(_set,VarKey86,0);
		}
	}


	if(VarKey81&=4096 && VCutScene==0)							//doesn't have to be in any set (for the bird/rat sequence)
	{
		Camera(BobRun_camera_distance,BobRun_camera_angle);
		Target(BobRun_camera_Tdistance,BobRun_camera_Tangle);
		float(_clr,VarKey81,4096);
	}
/*
	if(VSetActive=="mz_hrzn1")
	{
		CurEnvTriggerSet("mz_hrzn1","ForceTrig");
		call(expset1,-1,-8,-1);
	}
*/
	//	the sets below are meant to curset
	//
	if(VCurSet=="mz_08")									
	{
		if(VarKey82&=32)
		{
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_Set,TmpFloat,0x7f0000);
		}
		CurEnvTrigger("Door");
		call(ExpSet1,1,TmpFloat,0);
	}
	//	VARIABLES TO BE CLEARED EVERY FRAME
	//
	if(VarKey82&!=256)							//if door in mz_08 hasn't been unlocked
	{
		float(_clr,VarKey82,32);				//clear door can be opened in mz_08
	}
	if(Varbit&=Help06)
	{
		float(_clr,VarKey82,2048);					//clear door can be opened in mz_07
	}
}



SubRoutine(Sub_MZDeathFall)
{
		if(VTrigger==_DIREnvTrigger)
		{
			if(VState!=StateDead)
			{
				if(VAICon==0)
				{
					call(LockCamera,true);
					call(AIchangerank,0);		//take care of deaths internally!
				}
				call(SubtractHealth,0,30000);
				state(_or,StateDead);
			}
		}
}


SubRoutine(Sub_RightGunHandler)
{
		if(VarKey85<0)
		{
			float(_add,VarKey85,1);
		}
		else
		{
			float(_set,TmpFloat,0);
			CurEnvTrigger("TurretGo");
			if(VTrigger==_DIREnvTrigger)
			{
				float(_set,TmpFloat,1);
			}

			if(VarKey85==2)
			{
				if(VarKey81&=32 || TmpFloat==0)
				{
					Direction(_or,_DIRaction);					//jump out of this in a second

					CurEnvTriggerSet("mz_04","TURRIGHT");
//					call(KeyObjControl,0,0,-1,-1,SFXGunTurretHorizontal);	//force looping samples to stop
					call(KeyObjControl,0,0,-1,-1,SFXHatchLoop);	//force looping samples to stop
					CurEnvTriggerSet("mz_04","BARRIGHT");
//					call(KeyObjControl,0,0,0,1,SFXGunTurretVertical);
					call(KeyObjControl,0,0,0,1,SFXHatchLoop);
				}
			}

			if(VTrigger==_DIRaction)
			{
				if(VarKey85==2)
				{
					Direction(_clr,_DIRaction);
					float(_set,VarKey85,-60);
					CurEnvTriggerSet("mz_04","TURRIGHT");
					call(ExpSet2,-1,0,0);					//turn expcamera off
				}
				elseif(TmpFloat==1)
				{
					if(VarKey81&=32)
					{
						Message("The gun has been blown to bits",300,10);
					}
					else
					{
						if(VAIClass==_AIclasscop && VRank==_RankCommander)
						{
							call(ActivateButton,"gun activated",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							sample(SFXTurretPowerUp,-1);
							CurEnvTriggerSet("mz_04","TURRIGHT");
							CutScene("tcamright");
							call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
							call(ChangeCutScene,_SXCUTspeed,2000);
							float(_set,VarKey85,1);
							call(PlayerInput,0);
						}
						else
						{
							call(ActivateButton,"only guncommanders know how to operate this",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
					}
					Direction(_clr,_DIRaction);
				}
			}
			else
			{
				if(VarKey85==1 && VCutScene==0)
				{
					float(_set,VarKey85,2);
					call(PlayerInput,1);
					float(_set,timer,15);
				}

				if(VarKey85==2)
				{
					call(ChangeSniperMode,-2,0);
					CurEnvTriggerSet("mz_04","TURRIGHT");
					call(ExpSet2,4096,1,1);					//expcamera position, inf seconds, use exp1 for target
//					call(KeyObjControl,_DIRleft,_DIRright,-1,-1,SFXGunTurretHorizontal);
					call(KeyObjControl,_DIRleft,_DIRright,-1,-1,SFXHatchLoop);
					CurEnvTriggerSet("mz_04","BARRIGHT");
//					call(KeyObjControl,_DIRbackward,_DIRforward,0,1,SFXGunTurretVertical);
					call(KeyObjControl,_DIRbackward,_DIRforward,0,1,SFXHatchLoop);

					vector(_set,Gactorpos,-18,27,0);
					spawnparticle(fx_flare,-3,gactorpos,emptyvector,fx_coplaserflarered);

					vector(_set,Gactorine,0,0,-1024);
					spawnparticle(fx_coplaser,-3,gactorpos,gactorine,-1);

					if(VTrigger==_DIRshoot)
					{
						Direction(_clr,_DIRshoot);
						if(timer==30)
						{
							float(_or,VarKey83,8);

							float(_set,timer,0);
							vector(_set,tmpvector,0,0,-180);

							call(SetParticleSetID,"mz_04");
							SpawnActorKFObj(BulletBazooka,tmpvector,Gactorpos,Gactorine,true);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashhorizac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashvertac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag1ac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag2ac);
						}
					}
					if(timer<30)
					{
						float(_add,timer,1);
					}
				}
			}
		}
}	

SubRoutine(Sub_LeftGunHandler)
{
		if(VarKey85<0)
		{
			float(_add,VarKey85,1);
		}
		else
		{
			float(_set,TmpFloat,0);
			CurEnvTrigger("TurretGo");
			if(VTrigger==_DIREnvTrigger)
			{
				float(_set,TmpFloat,1);
			}

			if(VarKey85==2)
			{
				if(VarKey81&=16 || TmpFloat==0)
				{
					Direction(_or,_DIRaction);					//jump out of this in a second

					CurEnvTriggerSet("mz_04","TURLEFT");
//					call(KeyObjControl,0,0,-1,-1,SFXGunTurretHorizontal);	//force looping samples to stop
					call(KeyObjControl,0,0,-1,-1,SFXHatchLoop);	//force looping samples to stop
					CurEnvTriggerSet("mz_04","BARLEFT");
//					call(KeyObjControl,0,0,0,1,SFXGunTurretVertical);
					call(KeyObjControl,0,0,0,1,SFXHatchLoop);
				}
			}

			if(VTrigger==_DIRaction)
			{
				if(VarKey85==2)
				{
					Direction(_clr,_DIRaction);
					float(_set,VarKey85,-60);
					CurEnvTriggerSet("mz_04","TURLEFT");
					sample(SFXTurretPowerDown,-1);
					call(ExpSet2,-1,0,0);					//turn expcamera off
				}
				elseif(TmpFloat==1)
				{
					Direction(_clr,_DIRaction);
					if(VarKey81&=16)
					{
						Message("The gun has been blown to bits",300,10);
					}
					else
					{
						if(VAIClass==_AIclasscop && VRank==_RankCommander)
						{
							call(ActivateButton,"gun activated",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							CurEnvTriggerSet("mz_04","TURRIGHT");
							sample(SFXTurretPowerUp,-1);
							CutScene("tcamright");
							call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
							call(ChangeCutScene,_SXCUTspeed,2000);
							float(_set,VarKey85,1);
							call(PlayerInput,0);
						}
						else
						{
							call(ActivateButton,"only guncommanders know how to operate this",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
					}
				}
			}
			else
			{
				if(VarKey85==1 && VCutScene==0)
				{
					float(_set,VarKey85,2);
					call(PlayerInput,1);
					float(_set,timer,15);
				}

				if(VarKey85==2)
				{
					if(VAICon==0)
					{
						call(ChangeSniperMode,-2,0);
					}
					CurEnvTriggerSet("mz_04","TURLEFT");
					call(ExpSet2,4096,1,1);					//expcamera position, inf seconds, use exp1 for target
//					call(KeyObjControl,_DIRleft,_DIRright,-1,-1,SFXGunTurretHorizontal);
					call(KeyObjControl,_DIRleft,_DIRright,-1,-1,SFXHatchLoop);
					CurEnvTriggerSet("mz_04","BARLEFT");
//					call(KeyObjControl,_DIRbackward,_DIRforward,0,1,SFXGunTurretVertical);
					call(KeyObjControl,_DIRbackward,_DIRforward,0,1,SFXHatchLoop);

					vector(_set,Gactorpos,-18,27,0);
					spawnparticle(fx_flare,-3,gactorpos,emptyvector,fx_coplaserflarered);

					vector(_set,Gactorine,0,0,-1024);
					spawnparticle(fx_coplaser,-3,gactorpos,gactorine,-1);

					if(VTrigger==_DIRshoot)
					{
						Direction(_clr,_DIRshoot);
						if(timer==30)
						{
							float(_or,VarKey83,1);
							float(_set,timer,0);
							vector(_set,tmpvector,0,0,-180);
							call(SetParticleSetID,"mz_04");
							SpawnActorKFObj(BulletBazooka,tmpvector,Gactorpos,Gactorine,true);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashhorizac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashvertac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag1ac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag2ac);
						}
					}
					if(timer<30)
					{
						float(_add,timer,1);
					}
				}
			}
		}

}

SubRoutine(BackgroundTriggerChecksScene17)
{
	print("callbot",callbot);
	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel17); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(CallBot==4)
	{
		direction(_clr,_DIRmovebits|_DIRshoot);
	}
	if(VCurSet=="Mz_02")							//are we in the right set?
	{
		if(VarBit&=Help08 && VAICon==0)
		{
			if(VAIClass==_AIClassCop && VRank==_RankCommander)
			{
				call(ForceLoadSet,"mz_08");
				call(ForceLoadSet,"mz_08a");
				call(ChangeInventory,0,-100);
				float(_clr,VarBit,Help08);
			}
		}			
		if(IntroCam==0)
		{
			call(PlayerInput,0);
			CutScene("begin");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			float(_set,IntroCam,1);
		}
		elseif(IntroCam==1 && VAICon==0)
		{
			if(VCutSceneFrame==370)
			{
				CurEnvTrigger("liftgo");
				callsub(DoorOpen,1,1);
			}
			elseif(VCutSceneFrame==450)
			{
				call(CutSceneEnd);
				float(_set,IntroCam,2);
				call(PlayerInput,1);
			}
		}
		if(VarKey81&!=1)							//has sequence already been executed?
		{
			if(VAICon==0)							//only interested in non-AI players
			{
				CurEnvTrigger("BirdView");			//set the trigger to check
				if(VTrigger==_DIREnvTrigger)		//did we cross the planetrigger?
				{
					float(_or,VarKey81,3);			//mark sequence as started
					call(PlayerInput,0);			//player is going to stand and watch for a while, so disable input
					vector(_set,Gactorpos,-5980,25447,7804);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(Bird,Gactorpos,Gactorangle,"Mz_02",TRUE,1);
					CutScene("MungSucker");

					CurEnvTriggerSet("mz_08a","invtrig");
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}
			}
		}
		elseif(VarKey81&=2)
		{
			if(VCutScene==0)
			{
				if(VAICon==0)
				{
					call(PlayerInput,1);
					float(_clr,VarKey81,2);		//VERY risky, assuming playerone is last in actorlist
					CurEnvTriggerSet("mz_08a","invtrig");
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					float(_set,Incoming,1);
					float(_set,Godtimer,0);
					float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
					float(_set,ScriptMark,24);
					callsub(Panel24);
					ClearDMessage();
				}
				elseif(VAIClass==_AIclassanimal)
				{
					KillActor();
				}
			}
		}

		CurEnvTrigger("open");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			Message("Lift Has Been Called",300,10);
			sample(SFXAccessDenied,-1);
		}
					
		CurEnvTrigger("Door01");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAIClass==_AIClassABeast && VarBit&=Help24);
			{
				float(_set,MaserKey,4);
				float(_clr,VarBit,Help24);
				call(DeleteEntitiesAndActorsInSet,"mz_04");
				call(DeleteEntitiesAndActorsInSet,"mz_03");
				call(DeleteEntitiesAndActorsInSet,"mz_07");
				call(DeleteEntitiesAndActorsInSet,"mz_07");
				call(DeleteEntitiesAndActorsInSet,"mz_05");
			}
			callsub(DoorOpen,1,1);
		}

		CurEnvTrigger("Door");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey82&=256)
			{
				callsub(DoorOpen,2,1);
			}
			elseif(VAICon==0)
			{
				Message("Door is locked from the inside",300,10);
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}

		if(VarKey81&=256 && VAIClass==_AIclassAnimal && VRank==_RankSergeantM)			//bird
		{
			CurEnvTrigger("BIRDTHRU");
			if(VTrigger==_DIREnvTrigger)
			{
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			}
		}
		CurEnvTrigger("DEATHFALL");
		callsub(Sub_MZDeathFall);
	}
	elseif(VCurset=="mz_04")
	{
		if(VarBit&=Help05 && VarBit&!=Help06 && VarBit&=Help07)
		{
			GetNumbActorsInSet("mz_04",_AIClassCop,TmpFloat);
//			call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassCop,_Equal,RankSergeantH);
			GetNumbActorsInSet("mz_03",_AIClassCop,TmpFloat1);
			GetNumbActorsInSet("mz_07",_AIClassCop,TmpFloat2);
			GetNumbActorsInSet("mz_05",_AIClassCop,TmpFloat3);
			float(_add,TmpFloat,TmpFloat1);
			float(_add,Tmpfloat,TmpFloat2);
			float(_add,TmpFloat,TmpFloat3);
			if(TmpFloat==0)
			{
				float(_set,CommandTimer,0);
				float(_clr,VarBit,Help05);
			}
		}
		elseif(VarBit&!=Help05 && VarBit&=Help07)
		{
			if(CommandTimer<=7)
			{
				if(VAICon!=0 && VPathID==62)
				{
					ActorFlag(_or,_AFlagNoAI);
				}
				if(Commandtimer==6)
				{
					CurEnvTrigger("jumpout");
					if(VTrigger==_DIREnvTrigger)
					{
						if(VPathID==62 && VAICon!=0)
						{
							SetActorToTrigger("mz_04","jumpout");
							call(FaceTriggerDirection);
							float(_set,Commandtimer,7);
						}
					}
				}
				elseif(Commandtimer==7)
				{
					CurEnvTrigger("jumpout");
					if(VAIClass==_AIClassCop && VPathID==62)
					{
						if(VTrigger==_DIREnvTrigger)
						{
							direction(_clr,_noDIR);
							direction(_or,_DIRForward|_DIRmove);
						}
						else
						{
							ActorFlag(_clr,_AFlagNoAI);
							float(_set,CommandTimer,8);
							
						}
					}
				}
			}
			call(AICHangePlayerToEnemy);
		}
			
		if(VAICon==0 && VarBit&=Help03 && VarBit&=Help07)
		{
			if(VarBit&!=Help05)
			{
				if(CommandTimer==0)
				{
					CurEnvTrigger("warn01");
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);

					float(_set,CommandTimer,1);
				}
				elseif(CommandTimer==1)
				{
					vector(_set,Gactorpos,-10892,34876,11287);
					vector(_set,Gactorangle,0,0,0);
					InitActor(coph,Gactorpos,Gactorangle,"Mz_04",TRUE,62);
					InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"Mz_04");
					float(_set,CommandTimer,2);
					float(_set,timer3,0);
				}
			}

			CurEnvTrigger("warn02");
			if(VRank<_RankCommander)
			{
				if(VTrigger==_DIREnvTrigger)
				{
					float(_or,VarBit,Help01);
				}
				else
				{
					float(_clr,VarBit,Help01);
				}
			}
		}
		else
		{
			if(Varbit&=Help02 && VarBit&=Help07 && VarBit&=Help09)
			{
				if(VAIClass==_AIClassCop && VPathID==8)
				{
					if(VarBit&!=Help01)
					{
						float(_add,CommandTimer,1);
						callsub(TurnToPlayer);
					}
					if(CommandTimer==50)
					{
						sample(SFXCopComeHere02,-1);
						if(VTrigger!=_DIRCombatmode)
						{
							direction(_or,_DIRcombatmode);
						}
						dmessage("Hey You!",100,180);
					}
					elseif(CommandTimer==200)
					{
						sample(SFXWarning02,-1);
						dmessage("You've got no business with the commander",100,180);
					}
					elseif(CommandTimer==400);
					{
						sample(SFXWarning01,-1);
						dmessage("This is as far as you go@ halflife...",100,180);
						call(aichangeplayertoenemy);
						float(_set,CommandTimer,0);
						float(_clr,VarBit,Help03);
						float(_set,VarBit,Help01);
					}
				}
			}
		}
		if(VExpCamera!=0)
		{
			if(Commandtimer!=0 && VarBit&=Help02)
			{
				float(_set,CommandTimer,0);
			}
			float(_clr,Varbit,Help02);
		}
		else
		{
			float(_or,VarBit,Help02);
		}
		CurEnvTrigger("deathfall");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);
		}
	}
	elseif(VCurSet=="Mztunl1")
	{
		if(VAICon==0)
		{
			if(VarBit&=Help06)
			{
				if(VAIClass==_AIClassABeast)
				{
					float(_clr,VarBit,Help06);
					if(Varbit&!=Help24 && CallBot==0)
					{
						float(_set,AIvisiontoggle,1);
						call(DisplayFXPagesToggle,1);		//activate MASER gfx!!!

						vector(_set,Gactorpos,-12295,24424,10650);
						vector(_set,Gactorangle,0,3094,0);
						InitActor(coph,Gactorpos,Gactorangle,"Mz_04",TRUE,80);
						InitActor(WeaponMaser,Gactorpos,Gactorangle,"Mz_04");

						vector(_set,Gactorpos,-11943,24424,10881);
						vector(_set,Gactorangle,0,3094,0);
						InitActor(coph,Gactorpos,Gactorangle,"Mz_04",TRUE,82);
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"Mz_04");

						vector(_set,Gactorpos,-11926,24424,10481);
						vector(_set,Gactorangle,0,3094,0);
						InitActor(coph,Gactorpos,Gactorangle,"Mz_04",TRUE,81);
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"Mz_04");

						vector(_set,Gactorpos,-10959,24424,9053);
						vector(_set,Gactorangle,0,2048,0);
						InitActor(coph,Gactorpos,Gactorangle,"Mz_07",TRUE,85);
						InitActor(WeaponMaser,Gactorpos,Gactorangle,"Mz_07");

						vector(_set,Gactorpos,-10948,24424,8342);
						vector(_set,Gactorangle,0,2048,0);
						InitActor(coph,Gactorpos,Gactorangle,"Mz_07",TRUE,86);
						InitActor(WeaponMaser,Gactorpos,Gactorangle,"Mz_07");

						vector(_set,Gactorpos,-10994,24440,13824);
						vector(_set,Gactorangle,0,0,0);
						InitActor(coph,Gactorpos,Gactorangle,"Mz_hrzn1",TRUE,77);
						InitActor(WeaponMaser,Gactorpos,Gactorangle,"Mz_hrzn1");

						float(_set,Callbot,1);
					}
				}
			}	
			CurEnvTrigger("Door01");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VAIclass!=_AIclassanimal && VTrigger==_DIRaction)
			{
				if(VarKey82&=1)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Locked",120,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}

			CurEnvTrigger("Door");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VAIclass!=_AIclassanimal && VTrigger==_DIRaction)
			{
				if(VarKey82&=2)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Locked",120,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
			
			if(ControlTimer==1)
			{
				CurEnvTrigger("door")
				if(VSetActive=="mz_03" && VSetActive=="mz_04" && VSetActive=="mz_05")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("Mztunl1","door",1);
					call(KeyObjTrigger,255,1);
				}
			}
			if(ControlTimer==2)
			{
				CurEnvTrigger("door01")
				if(VSetActive=="mz_02")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("Mztunl1","door01",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("arme");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VClass!=_ClassAngel && VAIclass!=_AIclassanimal)
				{
					if(VKeyObjFrame==0 && VKeyObjTriggered==0)
					{
						call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						vector(_set,Gactorpos,-8078,24484,10796);
						vector(_set,Gactorangle,0,0,0);
						InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"Mztunl1",TRUE);
						call(KeyObjTrigger,255,1);
						float(_set,TmpFloat,0x0000ff);
						call(expset1,1,TmpFloat,0);
					}
					elseif(VAICON==0)
					{
						call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				elseif(VAICON==0)
				{
					call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}

			CurEnvTrigger("arme1");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VClass!=_ClassAngel && VAIclass!=_AIclassanimal)
				{
					if(VKeyObjFrame==0 && VKeyObjTriggered==0)
					{
						call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						vector(_set,Gactorpos,-7789,24480,10796);
						vector(_set,Gactorangle,0,0,0);
						InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"Mztunl1",TRUE);
						call(KeyObjTrigger,255,1);
						float(_set,TmpFloat,0x0000ff);
						call(expset1,1,TmpFloat,0);
					}
					elseif(VAICON==0)
					{
						call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
 				elseif(VAICON==0)
				{
					call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}
	}
	elseif(VCurSet=="MZ_03")
	{
		if(callBot==5)
		{
			call(aichangeplayertoenemy);
			call(PlayerInput,1);
			float(_set,callbot,6);
		}
		if(VAICon==0)
		{
			if(CallBot==2)
			{
				CurEnvTrigger("takeoff");
				if(VTrigger==_DIREnvTrigger)
				{
					call(PlayerInput,0);
					float(_set,CallBot,3);
				}
			}

			CurEnvTrigger("OverRide");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0 && VKeyObjFrame==0 && VTrigger==_DIRaction)
			{
				call(ActivateButton,"Lift called",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				CurEnvTrigger("TurretGo");
				call(KeyObjTrigger,255,1);
				vector(_set,Gactorpos,-8687,24897,10201);
				Sample(SFXPneumatik,Gactorpos);
				Direction(_clr,_DIRaction);
				float(_or,VarKey81,4);
				CurEnvTrigger("PltFrmUp");
				call(ChangeTrigger,_set,_SXTrigPanel);
			}

			CurEnvTrigger("Door");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				callsub(DoorOpen,1,1);
				Direction(_clr,_DIRaction);
			}

			CurEnvTrigger("OverRide");
			if(VKeyObjTriggered==0)
			{
				if(VTrigger==_DIRaction)
				{
					if(VKeyObjFrame==2)						//elevator up
					{
						CurEnvTrigger("PLTFRMUP");
						if(VTrigger==_DIREnvTrigger)
						{
							CurEnvTrigger("OverRide");
							call(ActivateButton,"Engaging gun controls",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							call(KeyObjTrigger,0,-1);
							kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
							Direction(_clr,_DIRaction);
							float(_or,VarKey81,8);
						}
					}
					elseif(VKeyObjFrame==0)
					{
						CurEnvTrigger("PLTFRMDWN");
						if(VTrigger==_DIREnvTrigger)
						{
							CurEnvTrigger("TurretGo");
							call(ActivateButton,"Disengaging gun controls",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							call(KeyObjTrigger,255,1);
							vector(_set,Gactorpos,-8687,24897,10201);
							Sample(SFXPneumatik,Gactorpos);
							Direction(_clr,_DIRaction);
							float(_or,VarKey81,4);
						}
					}
				}
			}
			callsub(Sub_LeftGunHandler);
		}
		else
		{
			CurEnvTrigger("floor");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,200,450,200);
				Call(TriggerBox,TmpVector,0,tmpfloat);
				if(tmpfloat==1)
				{
					CurEnvTrigger("override");
					if(VKeyObjTriggered!=0)
					{
						ActorFlag(_or,_AFlagNoAI);
					}
					else
					{
						ActorFlag(_clr,_AFlagNoAI);
						if(VKeyObjFrame==0 && VPathID!=1)
						{
							call(AIFindPathWithSpecificID,1);
						}
						elseif(VKeyObjFrame!=0 && VPathID!=77)
						{
							call(AIFindPathWithSpecificID,77);
						}
					}
				}
			}
			if(VPathID!=88 && VRank<_RankCommander)
			{
				call(AIfindpathwithspecificid,88);
			}
			if(VarKey83&=8 && VAIClass==_AIclasscop && VRank==_RankCommander && VarKey81&!=32 && VarKey81&!=16)
			{
				//you're the commander and the both guns are intact
				//left gun aiming at right gun

				CurEnvTrigger("TurretGo");
				vector(_set,TmpVector,100,100,100);
				call(TriggerBox,TmpVector,0,TmpFloat);
				if(TmpFloat==1)
				{
					CurEnvTriggerSet("mz_04","TURRIGHT");
					vector(_settokfpos,TmpVector,0);

					CurEnvTriggerSet("mz_04","BARLEFT");

					vector(_set,Gactorpos,-18,27,0);
					spawnparticle(fx_flare,-3,gactorpos,emptyvector,fx_coplaserflarered);
					vector(_set,Gactorine,0,0,-2048);
					spawnparticle(fx_coplaser,-3,gactorpos,gactorine,-1);


					vector(_set,TmpVector2,0,0,1500);
					vector(_multiplywithobjtransmat,TmpVector2,TmpVector2);

					vector(_sub,TmpVector,TmpVector2);

					vector(_copyz,TmpVector,TmpFloat);
					float(_seti,TmpFloat2,VTrigger);				//backup of direction flag
					float(_set,TmpFloat3,0);
					if(TmpFloat<-10)
					{
						Direction(_or,_DIRleft);
					}
					elseif(TmpFloat>10)
					{
						Direction(_or,_DIRright);
					}

					if(TmpFloat<=50 && TmpFloat>=-50)
					{
						float(_add,TmpFloat3,1);
					}

					vector(_copyy,TmpVector,TmpFloat);
					if(TmpFloat<-10)
					{
						Direction(_or,_DIRforward);
					}
					elseif(TmpFloat>10)
					{
						Direction(_or,_DIRbackward);
					}
					if(TmpFloat<=50 && TmpFloat>=-50)
					{
						float(_add,TmpFloat3,1);
					}

					if(TmpFloat3==2)
					{
						//fire at target
						if(VarKey86>=15)
						{
							float(_set,VarKey86,0);
							vector(_set,tmpvector,0,0,-180);
							call(SetParticleSetID,"mz_03");
							SpawnActorKFObj(BulletBazooka,tmpvector,Gactorpos,Gactorine,true);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashhorizac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashvertac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag1ac);
							spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag2ac);
						}
						else
						{
							float(_add,VarKey86,1);
						}
					}
					else
					{
						call(KeyObjControl,_DIRbackward,_DIRforward,0,1,-1);		//sample buggy
						CurEnvTriggerSet("mz_04","TURLEFT");
						call(KeyObjControl,_DIRleft,_DIRright,-1,-1,-1);			//sample buggy
					}
					
					Direction(_clr,-1);							//restore the direction flag
					Direction(_set,TmpFloat2);
				}
			}
		}
		CurEnvTrigger("DEATHFALL");
		callsub(Sub_MZDeathFall);
	}
	elseif(VCurSet=="mz_hrzn1")
	{
		CurEnvTrigger("DEATHFALL");
		callsub(Sub_MZDeathFall);
	}
	elseif(VCurSet=="mz_05")
	{
		if(VAICon==0)				//panel has been shot
		{
			CurEnvTrigger("attack");
			if(VTrigger==_DIREnvTrigger)
			{
				float(_clr,VarBit,Help09);
				call(AIChangePlayerToEnemy);
			}

			if(VarKey81&=64)
			{
				CurEnvTrigger("OverRide");
				if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0 && VKeyObjFrame==0 && VTrigger==_DIRaction)
				{
					call(ActivateButton,"Lift called",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					CurEnvTrigger("TurretGo");
					call(KeyObjTrigger,255,1);
					vector(_set,Gactorpos,-13187,24897,10201);
					Sample(SFXPneumatik,Gactorpos);
					Direction(_clr,_DIRaction);
					float(_or,VarKey81,1024);

					CurEnvTrigger("PltFrmUpF");
					call(ChangeTrigger,_set,_SXTrigPanel);
				}
			}

			CurEnvTrigger("Door");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit&=Help06)
				{
					callsub(DoorOpen,1,1);
				}
				else
				{
					message("Door Locked For Safety Reasons",300,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}

			CurEnvTrigger("OverRide");
			if(VKeyObjTriggered==0)
			{
				if(VTrigger==_DIRaction)
				{
					if(VKeyObjFrame==2)						//elevator up
					{
						CurEnvTrigger("PLTFRMUPF");
						if(VTrigger==_DIREnvTrigger)
						{
							CurEnvTrigger("OverRide");
							call(ActivateButton,"Engaging gun controls",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							call(KeyObjTrigger,0,-1);
							kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
							Direction(_clr,_DIRaction);
							float(_or,VarKey81,2048);
						}
					}
					elseif(VKeyObjFrame==0)
					{
						CurEnvTrigger("PLTFRMDWN");
						if(VTrigger==_DIREnvTrigger)
						{
							CurEnvTrigger("TurretGo");
							call(ActivateButton,"Disengaging gun controls",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							call(KeyObjTrigger,255,1);
							vector(_set,Gactorpos,-13187,24897,10201);
							Sample(SFXPneumatik,Gactorpos);
							Direction(_clr,_DIRaction);
							float(_or,VarKey81,1024);
						}
					}
				}
			}
			callsub(Sub_RightGunHandler);
		}
		elseif(VarKey83&=1 && VAIClass==_AIclasscop && VRank==_RankCommander && VarKey81&!=32 && VarKey81&!=16)
		{
			//you're the commander and the both guns are intact
			//right gun aiming at left gun

			CurEnvTrigger("TurretGo");
			vector(_set,TmpVector,100,100,100);
			call(TriggerBox,TmpVector,0,TmpFloat);
			if(TmpFloat==1)
			{
				CurEnvTriggerSet("mz_04","TURLEFT");
				vector(_settokfpos,TmpVector,0);

				CurEnvTriggerSet("mz_04","BARRIGHT");

				vector(_set,Gactorpos,-18,27,0);
				spawnparticle(fx_flare,-3,gactorpos,emptyvector,fx_coplaserflarered);
				vector(_set,Gactorine,0,0,-2048);
				spawnparticle(fx_coplaser,-3,gactorpos,gactorine,-1);


				vector(_set,TmpVector2,0,0,1500);
				vector(_multiplywithobjtransmat,TmpVector2,TmpVector2);

				vector(_sub,TmpVector,TmpVector2);

				vector(_copyz,TmpVector,TmpFloat);
				float(_seti,TmpFloat2,VTrigger);				//backup of direction flag
				float(_set,TmpFloat3,0);
				if(TmpFloat<-10)
				{
					Direction(_or,_DIRleft);
				}
				elseif(TmpFloat>10)
				{
					Direction(_or,_DIRright);
				}

				if(TmpFloat<=50 && TmpFloat>=-50)
				{
					float(_add,TmpFloat3,1);
				}

				vector(_copyy,TmpVector,TmpFloat);
				if(TmpFloat<-10)
				{
					Direction(_or,_DIRforward);
				}
				elseif(TmpFloat>10)
				{
					Direction(_or,_DIRbackward);
				}
				if(TmpFloat<=50 && TmpFloat>=-50)
				{
					float(_add,TmpFloat3,1);
				}

				if(TmpFloat3==2)
				{
					//fire at target
					if(VarKey86>=15)
					{
						float(_set,VarKey86,0);
						vector(_set,tmpvector,0,0,-180);
						call(SetParticleSetID,"mz_05");
						SpawnActorKFObj(BulletBazooka,tmpvector,Gactorpos,Gactorine,true);
						spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashhorizac);
						spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashvertac);
						spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag1ac);
						spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag2ac);
					}
					else
					{
						float(_add,VarKey86,1);
					}
				}
				else
				{
					call(KeyObjControl,_DIRbackward,_DIRforward,0,1,-1);		//sample buggy
					CurEnvTriggerSet("mz_04","TURRIGHT");
					call(KeyObjControl,_DIRleft,_DIRright,-1,-1,-1);			//sample buggy
				}
				
				Direction(_clr,-1);							//restore the direction flag
				Direction(_set,TmpFloat2);
			}
		}
		CurEnvTrigger("DEATHFALL");
		callsub(Sub_MZDeathFall);
	}
	elseif(VCurSet=="Mz_07")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("Door");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(VAIClass==_AIclassabeast)
				{
					float(_or,VarKey82,2048);
					if(VTrigger==_DIRaction)
					{
						if(ControlTimer==0)
						{
							float(_set,ControlTimer,2);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
						}
					}
				}
				elseif(VTrigger==_DIRaction)
				{
					Message("I need something heavy for this pressure plate",300,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}

			if(ControlTimer==2)
			{
				CurEnvTrigger("door");
				if(VSetActive=="mz_10");
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("mz_07","door",1);
					call(KeyObjTrigger,255,1);
				}
			}

			if(VarBit&!=Help06)
			{
				CurEnvTrigger("console");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					if(VAIClass==_AIClassCop && VRank==_RankSergeantH)
					{
						if(Controltimer==0)
						{
							call(ActivateButton,"Access Granted. Please Use Caution",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							float(_set,TmpFloat,0x000000);
							call(expset1,1,TmpFloat,0);
							float(_set,TmpFloat,0x00ff00);
							call(expset2,1,TmpFloat,0);
							CurEnvTrigger("door");
							call(expset1,1,TmpFloat,0);
							float(_set,ControlTimer,2);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
						}
					}
					else
					{
						call(ActivateButton,"Armored Officers Only",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
			}
			else
			{
				CurEnvTrigger("console");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					call(ActivateButton,"Armored Officers Only",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}						
		}
		else
		{
			if(VarBit&!=Help02)
			{
				float(_add,Commandtimer,1);
				if(VPathID==1)
				{
					call(AIfindpathwithspecificid,11);
				}
				elseif(VPathID==2)
				{
					call(AIfindpathwithspecificid,12);
				}
				elseif(VPathID==3)
				{
					call(AIfindpathwithspecificid,13);
				}
				elseif(VPathID==4)
				{
					call(AIfindpathwithspecificid,14);
				}
				elseif(VPathID==5)
				{
					call(AIfindpathwithspecificid,15);
				}
			}
			if(VPathID==11)
			{
				if(CommandTimer==10)
				{
					sample(SFXGrenadeReact,-1);
				}
				elseif(CommandTimer==50)
				{
					sample(SFXGrenadeReact,-1);
				}
			}
			elseif(VPathID==15)
			{
				if(CommandTimer==100)
				{
					sample(SFXGrenadeReact,-1);
					float(_set,CommandTimer,0);
					float(_or,VarBit,Help02);
				}
			}
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
		//callsub(Sub_MZDeathFall); trigger not there yet
	}
	elseif(VCurSet=="Mztunl2")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("Door01");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VAIClass!=_AIClassanimal && VTrigger==_DIRaction)
			{
				if(VarKey82&=1)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Locked",120,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
			
			if(ControlTimer==1)
			{
				CurEnvTrigger("door01")
				if(VSetActive=="mz_03" && VSetActive=="mz_04" && VSetActive=="mz_05")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("mztunl2","door01",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("Door");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VAIClass!=_AIClassanimal && VTrigger==_DIRaction)
			{
				if(VarKey82&=2)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Locked",120,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}

			if(ControlTimer==2)
			{
				CurEnvTrigger("door")
				if(VSetActive=="mz_06")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("mztunl2","door",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("arme");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VClass!=_ClassAngel && VAIclass!=_AIclassanimal)
				{
					if(VKeyObjFrame==0 && VKeyObjTriggered==0)
					{
						call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						vector(_set,Gactorpos,-14087,24484,10796);
						vector(_set,Gactorangle,0,0,0);
						InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"Mztunl2",TRUE);
						call(KeyObjTrigger,255,1);
						float(_set,TmpFloat,0x0000ff);
						call(expset1,1,TmpFloat,0);
					}
					elseif(VAICON==0)
					{
						call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				elseif(VAICON==0)
				{
					call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}

			
			CurEnvTrigger("arme1");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VClass!=_ClassAngel && VAIclass!=_AIclassanimal)
				{
					if(VKeyObjFrame==0 && VKeyObjTriggered==0)
					{
						call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						vector(_set,Gactorpos,-13787,24484,10780);
						vector(_set,Gactorangle,0,0,0);
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"Mztunl2",TRUE);
						call(KeyObjTrigger,255,1);
						float(_set,TmpFloat,0x0000ff);
						call(expset1,1,TmpFloat,0);
					}
					elseif(VAICON==0)
					{
						call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
 				elseif(VAICON==0)
				{
					call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}
	}
	elseif(VCurSet=="mz_06")
	{
		if(VTrigger==_DIRAction && VAIclass!=_AIclassanimal)
		{
			CurEnvTrigger("Door");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(DoorOpen,1,1);
			}
		}
		CurEnvTrigger("DEATHFALL");
		callsub(Sub_MZDeathFall);
	}
	elseif(VCurSet=="mz_08a")
	{
		if(VarKey81&!=512)
		{
			CurEnvTrigger("RatTrig");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAICon==0 && VAIClass==_AIclassanimal && VRank==_RankSergeantL)		//only if player is a rat
				{
					call(PlayerInput,1);
					FirstPerson(1);
					float(_or,VarKey81,512);
					float(_set,timer,0);
					float(_set,timer2,0);
					float(_or,VarBit,Help07);
				}
			}
		}
		if(VAIcon==0 && VAIClass==_AIClassAnimal)
		{
			float(_set,AIVisionToggle,0);
		}
	}
	elseif(VCurSet=="mz_09")
	{
		if(VAICon==0)
		{
			if(VAIClass==_AIclassAnimal)
			{
				CurEnvTrigger("Disable");
				if(VTrigger==_DIREnvTrigger)
				{
					ActorFlag(_or,_AFLAGNoDepossession);
				}
				CurEnvTrigger("Enable");
				if(VTrigger==_DIREnvTrigger)
				{
					ActorFlag(_clr,_AFLAGNoDepossession);
				}
			}
			GetNumbActorsInSet("mz_09",_AIClassAnimal,TmpFloat);
			if(TmpFloat==0)
			{
				vector(_set,Gactorpos,-15255,24426,7686);
				vector(_set,Gactorangle,0,0,0);
				InitActor(rat,Gactorpos,Gactorangle,"Mz_09",FALSE);
			}				

		}
		if(VarKey81&!=256)
		{
			if(VAICon==0 && VAIClass==_AIclassAnimal)
			{
				CurEnvTrigger("RatTrig");
				if(VTrigger==_DIREnvTrigger)
				{
					call(PlayerInput,0);
					ActorFlag(_clr,_AFLAGNoDepossession);
					vector(_set,Gactorpos,-14984,25046,8318);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(Bird,Gactorpos,Gactorangle,"Mz_09",TRUE,3);
					float(_or,VarKey81,128);
					CutScene("BirdView");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
					FirstPerson(0);

					vector(_settotriggerpos,tmpvector);
					vector(_settoactorpos,tmpvector2);
					vector(_sub,tmpvector,tmpvector2);
					vector(_copyx,tmpvector,tmpfloat);
					vector(_copyy,tmpvector,tmpfloat2);
					vector(_copyz,tmpvector,tmpfloat3);
					move(tmpfloat,tmpfloat2,tmpfloat3);
					float(_clr,VarBit,Help07);
				}
			}
			if(VarKey81&=128)
			{
				if(VAIClass==_AIclassAnimal && VRank==_RankSergeantM)			//bird
				{
					call(AIfindpathwithspecificid,3);
					float(_or,VarKey81,256);
					float(_or,VarKey81,4096);
				}
			}
		}
	}
	elseif(VCurSet=="mz_08")
	{
		if(VCutScene!=0)
		{
			if(VAICon==0)
			{
				float(_set,AIVisionToggle,1);
			}
			if(VAIClass!=_AIClassABeast)
			{
				direction(_clr,_DIRShoot|_DIRmovebits);
			}
			else
			{
				direction(_clr,_DIRleft|_DIRright);
			}
		}
		else
		{
			float(_set,AIVisionToggle,0);
		}
		if(VAICon==0)
		{
			if(VarKey82&=8192 && VCutScene==0)
			{
				call(PlayerInput,1);
			}

			CurEnvTrigger("B_LOCK01");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarKey82&=4)
				{
					Message("Armored Behemoth already activated",300,10);
				}
				else
				{
					call(ActivateButton,"Armored Behemoth activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,255,1);
					float(_set,TmpFloat,0x7f00);
					call(expset1,1,TmpFloat,0);
					float(_or,VarKey82,4);
					CutScene("BeastCam");
					call(ChangeCutScene,_SXCUTspeed,150);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(PlayerInput,0);
					float(_or,VarKey82,8192);
				}
			}

			CurEnvTrigger("B_LOCK02");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarKey82&=8)
				{
					Message("Armored Behemoth already activated",300,10);
				}
				else
				{
					call(ActivateButton,"Armored Behemoth activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,255,1);
					float(_set,TmpFloat,0x7f00);
					call(expset1,1,TmpFloat,0);
					float(_or,VarKey82,8);
					CutScene("BeastCam");
					call(ChangeCutScene,_SXCUTspeed,150);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(PlayerInput,0);
					float(_or,VarKey82,8192);
				}
			}

			CurEnvTrigger("B_LOCK03");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarKey82&=16)
				{
					Message("Armored Behemoth already activated",300,10);
				}
				else
				{
					call(ActivateButton,"Armored Behemoth activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,255,1);
					float(_set,TmpFloat,0x7f00);
					call(expset1,1,TmpFloat,0);
					float(_or,VarKey82,16);
					CutScene("BeastCam");
					call(ChangeCutScene,_SXCUTspeed,150);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(PlayerInput,0);
					float(_or,VarKey82,8192);
				}
			}

			CurEnvTrigger("panel1");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				CurEnvTrigger("LiftDown");
				if(VKEyObjTriggered==0 && VKeyObjFrame==4)
				{
						call(ActivateButton,0,-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,0,-1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
			}
			CurEnvTrigger("panel2");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				CurEnvTrigger("LiftDown");
				if(VKEyObjTriggered==0 && VKeyObjFrame==0)
				{
						call(ActivateButton,0,-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,4,1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
			}
			CurEnvTrigger("LiftDown");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VKeyObjTriggered==0)
				{
					if(VKeyObjFrame==0)
					{
						call(ActivateButton,"Lift called",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,4,1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					}
					else
					{
						call(ActivateButton,"Lift Is Already On That Floor",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
				}
				else
				{
					call(ActivateButton,"Lift is moving",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
			}

			CurEnvTrigger("LiftUp");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				CurEnvTrigger("liftdown");
				if(vkeyobjtriggered==0)
				{
					if(VKeyObjFrame!=0)
					{
						call(ActivateButton,"Lift called",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,0,-1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					}
					else
					{
						call(ActivateButton,"Lift Is Already On That Floor",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
				}
				else
				{
					call(ActivateButton,"Lift is moving",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
			}

			CurEnvTrigger("Door");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass!=_AIclassabeast && VarKey82&!=256)
				{
					if(VAICon==0 && VTrigger==_DIRaction)
					{
 						Message("I need something heavy for this pressure plate",300,10);
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}
				}
				else
				{
					float(_or,VarKey82,32);
					if(VTrigger==_DIRaction)
					{
						float(_or,VarKey82,256);
						callsub(DoorOpen,2,1);
					}
				}
			}
		}

		if(VarKey82&!=16384)
		{
			CurEnvTrigger("SeeMe");
			if(VAICon==0 && VTrigger==_DIREnvTrigger)
			{
				float(_or,VarKey82,16384);
			}
		}
		else
		{
			if(VAIClass==_AIClassCop && VAIState==_AIStateGuard)
			{
				call(AIOrder,_clr,_AIstateGuard);
				call(ClrPath);
				call(AIFindPathWithSpecificID,2);
				float(_clr,VarKey82,16384);
			}
		}
		


		if(VAICon!=0 && VAIClass==_AIclassabeast)
		{
			CurEnvTrigger("ShutDown1");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey82&=4)
				{
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					if(VCutScene!=0 && VCutSceneFrameEqual==3 && VActorFlag==_AFLAGnoai)
					{
						ActorFlag(_clr,_AFLAGnoai);
						vector(_set,gactorpos,-5984, 24580, 7426);		//beast 1
						samplestop(SFXBreathing,gactorpos);
						call(KeyObjTrigger,255,1);
						Sample(SFXLatch2,-1);
					}
				}
				else
				{
					ActorFlag(_or,_AFLAGnoai);
				}
			}

			CurEnvTrigger("ShutDown2");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey82&=8)
				{
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					if(VCutScene!=0 && VCutSceneFrameEqual==3 && VActorFlag==_AFLAGnoai)
					{
						ActorFlag(_clr,_AFLAGnoai);
						vector(_set,gactorpos,-5687, 24580, 7426);		//beast 2
						samplestop(SFXBreathing,gactorpos);
						call(KeyObjTrigger,255,1);
						Sample(SFXLatch2,-1);
					}
				}
				else
				{
					ActorFlag(_or,_AFLAGnoai);
				}
			}

			CurEnvTrigger("ShutDown3");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey82&=16)
				{
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					if(VCutScene!=0 && VCutSceneFrameEqual==3 && VActorFlag==_AFLAGnoai)
					{
						ActorFlag(_clr,_AFLAGnoai);
						vector(_set,gactorpos,-5984, 24580, 6379);		//beast 3
						samplestop(SFXBreathing,gactorpos);
						call(KeyObjTrigger,255,1);
						Sample(SFXLatch2,-1);
					}
				}
				else
				{
					ActorFlag(_or,_AFLAGnoai);
				}
			}
		}
	}
	elseif(VCurSet=="mz_10")
	{
		if(VAICon!=0)
		{
			if(VarKey82&=512 && VAIClass==_AIclassabeast)
			{
				float(_clr,VarKey82,512);					//don't be pissed again
				call(AIchangePlayertoenemy);
			}
		}
		else
		{
			if(VSetActive=="mz_11" && VSetInMemory=="mz_11")
			{
				CurEnvTrigger("quadorz");
				if(VKeyObjTriggered==0)
				{
					GetNumbActorsInSet("mz_11",_AIClassScientist,TmpFloat);
					if(TmpFloat==0)
					{					
						GetNumbActorsInSet("mz_10",_AIClassScientist,TmpFloat);
						if(TmpFloat==0)
						{					
							vector(_set,Gactorpos,-11459,24364,3772);
							vector(_set,Gactorangle,0,-512,0);
							InitActor(scientist,Gactorpos,Gactorangle,"Mz_11",TRUE,1);
						}
					}
				}
			}
				

			if(VarKey82&!=1024)
			{
				CurEnvTrigger("BstFight");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_or,VarKey82,512);				//tell abeast to get pissed
					float(_or,VarKey82,1024);				//don't trigger get pissed again
				}
			}

			CurEnvTrigger("quadorz");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,5);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
						
			CurEnvTrigger("Door");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					call(ForceLoadSet,"mz_04");
					float(_set,ControlTimer,6);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			if(ControlTimer==5)
			{
				CurEnvTrigger("quadorz");
				if(VSetActive=="mz_11");
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("mz_10","quadorz",1);
					call(KeyObjTrigger,255,1);
				}
			}

			if(ControlTimer==6)
			{
				CurEnvTrigger("door");
				if(VSetActive=="mz_07" && VSetInMemory=="Mz_04");
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("mz_10","door",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	///////////////////
	// TELEPORTATION //
	///////////////////

	//Wait for WallBulb EXP (right now, it spawns a "distort" bullet
	//from PlayerOne - Placeholder)
	
	elseif(VCurSet=="mz_11")
	{
		if(VAIClass==_AIClassScientist && VAICon!=0)
		{
			GetNumbActorsInSet("mz_11",_AIClassABeast,tmpfloat);
			if(tmpfloat!=0)
			{
				callsub(Sub_CivilianReactionToThreat);
			}
		}

		CurEnvTrigger("quadorz");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("quadorz");
			if(VSetActive=="mz_10");
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("mz_11","quadorz",1);
				call(KeyObjTrigger,255,1);
			}
		}

		///////////////////////////////
		// T E L E P O R T A T I O N //
		///////////////////////////////

		// Missing all the SFX !!!!!!!!!
		// JOE:  NOT ANYMORE!!!!!!!!!!!
		if(VAICon==0)
		{
			CurEnvTrigger("tele");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VAIClass==_AIClassScientist)
				{
					if(VKeyObjTriggered==0 && PillarEvent==0)
					{
						call(ActivateButton,"TelePod Power is on",-1,FALSE);
						call(ActivateButtonSample,SFXPumpPowerUp);
						CurEnvTrigger("quadorz");
						float(_set,TmpFloat,0x0000ff);
						call(Expset1,1,TmpFloat,0);
						float(_set,PillarEvent,1);
						float(_set,timer2,0);
						vector(_set,Gactorpos,-10359,24640,4384);
						sample(SFXLaserAmbient,gactorpos);

					}
					else
					{
						call(ActivateButton,"Power Already On",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
				}
				else
				{
					call(ActivateButton,"So many buttons !",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}

			if(PillarEvent==1)
			{
				float(_add,timer2,1);
				if(timer2==80)
				{
					float(_set,PowerOn,-2);
					CurEnvTrigger("tele");
					float(_set,TmpFloat,0xeebb22);
					call(expset1,TmpFloat,350,-1);
					call(KeyObjTrigger,255,1);
					vector(_set,tmpvector,128,50,0);
					vector(_set,Gactorpos,-10936,24771,4386);
					spawnlight(LightPulseOmni3,-1,Gactorpos,tmpvector,EmptyVector,1000);
					CurEnvTrigger("teleport");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					float(_set,timer2,0);
					float(_set,PillarEvent,2);
				}
			}
			elseif(PillarEvent==2)
			{
				CurEnvTrigger("teleport");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VAIClass!=_AIClassBeast && VAIClass!=_AIClassABeast)
					{
						call(CheckAttached,_CADropWeaponAndShells);
						call(playerInput,0);
						message("Teleportation Initiated",120,10);
						float(_set,timer2,0);
						CutScene("telep");
						float(_set,PillarEvent,3);
						vector(_set,gactorpos,-10936,24571,4386);
						sample(SFXTeleportLoop,Gactorpos);
					}
				}
			}
			elseif(PillarEvent==3)
			{
				CurEnvTrigger("push");
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,255,1);
				}
				if(VAIClass==_AIClassAngel)
				{
					if(VAction!=BobTeleportAction)
					{
						spawnaction(BobTeleportAction);
						float(_set,PillarEvent,4);
					}
				}
				else
				{
					if(VAction!=TeleportAction)
					{
						spawnaction(TeleportAction);
						float(_set,PillarEvent,4);
					}
				}
			}
			elseif(PillarEvent==4)
			{
				CurEnvTrigger("tele");
				//call(expset2,140,4,200);
				call(KeyObjTrigger,255,1);
				float(_set,PillarEvent,5);
				float(_set,timer2,100);
			}
			elseif(PillarEvent==5)
			{
				float(_sub,timer2,1)
				call(ChangeAlpha,10)
				if(timer2<=1)
				{
					float(_set,PillarEvent,6);
					float(_set,timer2,0);
					float(_set,timer3,1);
				}
			}
			elseif(PillarEvent==6);
			{
				float(_add,timer2,1);
				if(timer2==5)
				{
					call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,500);
					call(FadeToBlack,0);
				}
				elseif(timer2==200)
				{
					vector(_settoactorpos,tmpvector);
					callsub(sub_fxsmallexplosion);
					sample(SFXRipple,-1);
					setactortotrigger("mz_11","tele");
				}
				elseif(timer2>=350)
				{
					vector(_set,Gactorpos,-10359,24640,4384);
					samplestop(SFXLaserAmbient,gactorpos);
					vector(_set,gactorpos,-10936,24571,4386);
					samplestop(SFXTeleportLoop,gactorpos);
					float(_set,Poweron,1);
					actorflag(_or,_AFLAGresetfallalt);
					call(LoadLevel,-1,12);
				}
			}
		}
		else
		{
			if(PillarEvent!=0)
			{
				direction(_clr,_DIRMoveBits|_DIRShoot);
				callsub(Sub_AIGetBackToIdle);
			}
		}
	}
}
