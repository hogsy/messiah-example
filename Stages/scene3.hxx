

//////////////////////////////////
///		CITY ONE - SECTOR 2	   ///
//////////////////////////////////
// This script has to be merged with Scene2.hxx for final version
//

//VarKey11	-	Someone fell into the tank in s2r15
//VarKey12	-	timer for cop respawn in s2r8
//VarKey13	-	timer before chots come in s2r1
//DisablePickUp	-	Turret Control in s2r27
//VarKey15	-   Barrel Control in s2r27
//VarKey16	-	Check if a cop has been killed in S2r1
//VarKey17	-	Assign the guy on top of stairs into s2r26 to new path
//VarKey18	-   Activate Bot in s2r19
//VarKey19	-	Grinder sequence in S12R11
//timer		-	Used to time the Chot appearance in S2r2

//MissionLevel4	- InScan check
//MissionLevel2	- Ship destruction

//BattleTimer	- Flow variable for final battle sequence
//Gate4Unlocked	- Whether or not gate4 has been unlocked
//Crossroads	- Used to control flow for crossroads in s2r8 (a set the player visits twice under different circumstances)



//VarBit01
//------
//
//Help01	>	grinder ctrl #1 in s2r11
//Help02	>	Grinder explodes
//Help03	>	Grinder counter
//Help04	>	blood shed in s2r11
//Help05	>	Check if all cops are dead in s2r5
//Help06	>	Stops the shower scene
//Help07	>	blood platform in s2r11 (flickering)
//Help08	>	Wires have been shot - open fake door
//Help09	>	Lift power restored in s2r9
//Help10	>	power down for plasma glass
//Help11	>	Bring Chots in s2r1
//Help12	>	CamSequence in s2r5 (ship approaching)
//Help13	>	Turret pre-sequence 1
//Help14	>	Turret pre-sequence 2
//Help15	>	Check if shuttle1 explodes at the right place
//Help16	>	Check if shuttle explodes at the right place
//Help17	>	Check if Freightr explodes at the right place
//Help18	>	Locker explosion check
//Help19	>	"good day commander" message
//Help20	>	bridge portallink in s2r3
//Help21	>	Check if shipping sector'script is deinitialized
//Help22	>	Laser wall in s2r9
//Help23	>	Reassign Domina to idle node
//Help24	>	Domina respawn in s2r24 if dead in s2r5
//
//
//HelpVaR
//-------
//
//Help07	>	Defense Bot
//Help08	>	Companion Bot
//Help09	>	Gun Turret
//Help10	>   Story message #5
//Help11	>	Story message #6
//Help12	>	Story message #7
//Help13	>	If vent is destroyed before sequence is started
//Help14	>	Story Message #8
//
//BobSound
//--------
//
//Help01	>	Bob says "oops" in the grinder room
//Help02	>	Bob says "How can I get up there ?" in s2r12
//Help03	>	Bob says "Euch ! I hate rats" in s2r28 || s2r15
//Help04	>	Platform #1 destroyed in s2r5
//Help05	>	Platform #2 destroyed in s2r5
//Help06	>	Platform #3 destroyed in s2r5
//Help07	>	Check if all chots are dead in s2r9
//Help08	>	CDSwap killbob track
//Help09	>	All chots are dead in first Section. Start Timer
//Help10	>	When button activated in s2r15, dissolve platform
//Help11	>	Check if platform has been destroyed in s2r15...
//Help12	>	Shower Scene Trigger
//Help13	>	Fuse box is opened in s2r11
//Help14	>	Door counter in s2r11
//Help15	>	Bazooka spawn in s2r22
//Help16	>	Assign Chot to a new path if players is too close in s2r8
//Help17	>	Tutorial for High Fly
//Help18	>	Don't do the gun turret sequence twice
//Help19	>	turn down the CD volume in s2r7
//Help20	>	----- UNUSED -----
//Help21	>	----- UNUSED -----
//Help22	>	----- UNUSED -----
//Help23	>	----- UNUSED -----
//Help24	>	----- UNUSED -----

SubRoutine(InitSceneSound3)
{
	if(incoming!=0)
	{
		if(ScriptMark==5)
		{
			callsub(Panel5);
		}
		elseif(ScriptMark==6)
		{
			callsub(Panel6);
		}
		elseif(ScriptMark==7)
		{
			callsub(Panel7);
		}
		elseif(ScriptMark==8)
		{
			callsub(Panel8);
		}
	}
	else
	{
		callsub(ScriptLevel3);
	}
	call(CDPlay,2,1);

	#include	"messiahscripts\stages\scene3sfx.hxx"

}

SubRoutine(DeInitSceneSound3)
{
	//s2r1
	vector(_set,GactorPos,-2688,1337,9987);
	samplestop(SFXCityAmbient01,GactorPos);

	//s2r26 - Barricade
	vector(_set,Gactorpos,2956,300,12470);
	samplestop(SFXElectric5,Gactorpos);

	//s2r11 - Grinder sound
//	vector(_set,Gactorpos,3959,490,9385);
//	samplestop(SFXBarrelRoll,Gactorpos);

	//s2r12	- Firepit idle
	vector(_set,Gactorpos,7641,861,10823);
	samplestop(SFXFlamesBurning,Gactorpos);

	//s2r29 - Shower scene
	vector(_set,gactorpos,6500,-301,10350);
	samplestop(SFXRain2,Gactorpos);

	//s2r22 - Laser wall
	vector(_set,gactorpos,6722,-590,9196);
	samplestop(SFXLaserAmbient,Gactorpos);

	//s2r9c - generator
	vector(_set,Gactorpos,5544,766,16500);
	samplestop(SFXFieldHumLoop,Gactorpos);

	//s2r9c - plasma wall
	vector(_set,Gactorpos,5175,749,16499);
	samplestop(SFXScanHumm,Gactorpos);

	//s2r9 - laser wall
	vector(_set,gactorpos,4848,506,15511);
	samplestop(SFXLaserAmbient,Gactorpos);

	//s2r17 - rat maze (Acid sound)
	vector(_set,Gactorpos,8763,1166,11347);
	samplestop(SFXRadiationPool,Gactorpos);

	//s2r15 - Globe sound by the tank
	vector(_set,Gactorpos,8460,737,10151);
	samplestop(SFXGlobeAmbient,Gactorpos);

	//s2r2 - Shawn's flic wav synch
	vector(_set,Gactorpos,2106,599,6997);
	samplestop(SFXCrux,Gactorpos);

	//s2r5 - City sound
	vector(_set,Gactorpos,7487,-722,3861);
	samplestop(SFXCityAmbient01,Gactorpos);

}

SubRoutine(InitScene3)
{
		if(VScriptInitiated!=3)
		{
			if(VInitScriptCode==0)
			{
				InitActor(Bob1,0,Gactorangle,"s2r1");
			}

			// Reset all the variables
			call(loadpreloaddb,3);
			float(_set,VarKey11,0);
			float(_set,VarKey12,0);
			float(_set,VarKey13,0);
			float(_set,DisablePickUp,0);
			float(_set,VarKey15,0);
			float(_set,VarKey16,0);
			float(_set,VarKey17,0);
			float(_set,VarKey18,0);
			float(_set,VarKey19,0);
			float(_set,VarKey20,0);
			float(_set,FurnaceTimer1,0);
			float(_set,FurnaceTimer2,0);
			float(_set,FurnaceTimer3,0);
			float(_set,FurnaceTimer4,0);
			float(_set,MissionLevel1,0);
			float(_set,MissionLevel2,0);
			float(_set,MissionLevel3,0);
			float(_set,MissionLevel4,0);
			float(_set,MissionLevel5,0);
			float(_set,Bringmeback,2);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
			float(_set,timer4,0);
			float(_set,side,0);
			float(_set,HudTimer,0);
			float(_set,Punchtimer,0);
			float(_set,HelpVar,AllHelp);
			float(_set,RadChecked1,0);
			float(_set,RadChecked2,0);
			float(_set,RadChecked3,0);
			float(_set,VarBit,AllHelp);
			float(_set,VarBit01,AllHelp);
			float(_set,BobSound,AllHelp);
			float(_set,Res03,AllHelp);
			float(_set,MaxCopRespawn,5);
			float(_set,MaxChotRespawn,10);
			float(_set,CabTimer,0);
			float(_set,ColorRange,0);
			float(_set,ChotTimer,0);
			float(_set,GunSmoke,0);
			float(_set,GunSamFlag,0);
			float(_set,BattleTimer,0);
			float(_set,LinkGlobal,0);
			float(_set,Gate4Unlocked,0);
			float(_set,Crossroads,0);
			float(_set,StreetCorpses,0);
			float(_set,Objective,0);
			float(_set,WarnSeq,0);
			float(_set,FirstTimeRun,0);
			float(_set,FreighTimer,0)
			float(_set,LottoTimer,0);


			//enemy file
			#include "messiahscripts\enemies\c1_sector2.spt"
			
		}
		callsub(InitSceneSound3);

		call(ScriptCodeInitiated,3);
}

SubRoutine(LottoSample)
{
	float(_add,LottoTimer,1)
	if(LottoTimer==150)
	{
		vector(_set,Gactorpos,5697,100,7417);
		float(_rnd2,RandomMsg,12);
		if(RandomMsg<1 && LastLiftSamplePlayed!=1)
		{
			sample(SFXLotto01,Gactorpos);
			float(_set,LastLiftSamplePlayed,1);
		}
		elseif(RandomMsg<2 && LastLiftSamplePlayed!=2)
		{
			sample(SFXLotto02,Gactorpos);
			float(_set,LastLiftSamplePlayed,2);
		}
		elseif(RandomMsg<3 && LastLiftSamplePlayed!=3)
		{
			sample(SFXLotto03,Gactorpos);
			float(_set,LastLiftSamplePlayed,3);
		}
		elseif(RandomMsg<4 && LastLiftSamplePlayed!=4)
		{
			sample(SFXLotto04,Gactorpos);
			float(_set,LastLiftSamplePlayed,4);
		}
		elseif(RandomMsg<5 && LastLiftSamplePlayed!=5)
		{
			sample(SFXLotto05,Gactorpos);
			float(_set,LastLiftSamplePlayed,5);
		}
		elseif(RandomMsg<6 && LastLiftSamplePlayed!=6)
		{
			sample(SFXLotto06,Gactorpos);
			float(_set,LastLiftSamplePlayed,6);
		}
		elseif(RandomMsg<7 && LastLiftSamplePlayed!=7)
		{
			sample(SFXLotto07,Gactorpos);
			float(_set,LastLiftSamplePlayed,7);
		}
		elseif(RandomMsg<8 && LastLiftSamplePlayed!=8)
		{
			sample(SFXLotto08,Gactorpos);
			float(_set,LastLiftSamplePlayed,8);
		}
		elseif(RandomMsg<9 && LastLiftSamplePlayed!=9)
		{
			sample(SFXLotto09,Gactorpos);
			float(_set,LastLiftSamplePlayed,9);
		}
		elseif(RandomMsg<10 && LastLiftSamplePlayed!=10)
		{
			sample(SFXLotto10,Gactorpos);
			float(_set,LastLiftSamplePlayed,10);
		}
		elseif(RandomMsg<11 && LastLiftSamplePlayed!=11)
		{
			sample(SFXLotto11,Gactorpos);
			float(_set,LastLiftSamplePlayed,11);
		}
		elseif(RandomMsg<12 && LastLiftSamplePlayed!=12)
		{
			sample(SFXLotto12,Gactorpos);
			float(_set,LastLiftSamplePlayed,12);
		}
		float(_set,LottoTimer,0);
	}
}		

SubRoutine(MainScene3)
{
	print("PowerOn:  ",PowerOn);

	if(BattleTimer==152)
	{
		sample(SFXLightsOff,-1,80);
		float(_add,BattleTimer,1);
		float(_set,PowerOn,-1);
		call(CDFade,0,30);
	}
	elseif(BattleTimer>152 && BattleTimer<400)
	{
		float(_add,BattleTimer,1);
	}
	elseif(BattleTimer==400)
	{
		call(CDFade,60,30);
		float(_set,PowerOn,0);
		float(_add,BattleTimer,1);
		sample(SFXLightsOn,-1,80);
	}
	if(VSetActive=="s2r2")
	{
		if(HelpVar&=Help13)
		{
			CurEnvTriggerSet("s2r2","vent");
			call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
			if(Tmpfloat==TRUE)
			{
				float(_clr,VarBit01,Help11);
				float(_clr,BobSound,Help07);
				float(_clr,HelpVar,Help13);
			}		
		}
	}
	if(VSetActive=="s2r13")
	{
		CurEnvTriggerSet("s2r13","killme");
		call(ExpSet1,-10,0,0);
	}
	if(VSetActive=="s2r26")
	{
		if(VarKey17==0)
		{
			CurEnvTriggerSet("s2r26","door1");
			call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
			if(TmpFloat==TRUE)
			{
				vector(_set,Gactorpos,2956,300,12470);
				samplestop(SFXElectric5,Gactorpos);
				float(_set,VarKey17,1);
			}
		}
	}
	if(VSetActive=="s2r12")
	{
		call(SetParticleSetID,"s2r12");
		float(_add,FurnaceTimer4,1)
		if(FurnaceTimer4>2)
		{
			float(_set,FurnaceTimer4,1);
		}

		//vector(_set,Gactorpos,-10722.80,25000,19377.80);
		//vector(_set,Gactorine,0,10,0);
		//SpawnParticle(fx_mainexplosion,-1,Gactorpos,Gactorine,-1);
		if(FurnaceTimer4==1)
		{
			vector(_set,Gactorpos,5757,813,12778);
			vector(_set,Gactorine,0,10,0);
			SpawnParticle(fx_mainexplosion,-1,Gactorpos,Gactorine,-1);
			vector(_set,tmpvector,230,85,15);
			spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);
		}
		elseif(FurnaceTimer4==2)
		{	
			vector(_set,Gactorpos,5757,813,12691);
			vector(_set,Gactorine,0,10,0);
			spawnParticle(fx_mainexplosion,-1,Gactorpos,Gactorine,-1);
				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);
		}


		if (FurnaceTimer1<712 && FurnaceTimer1!=0)
		{
			float(_set,FurnaceTimer1,0);
		}
		
		if(FurnaceTimer1==0)
		{
			if(vrnd==4)
			{
				float(_set,FurnaceTimer1,712);
				vector(_set,Gactorpos,5770,612,12665);
				vector(_set,Gactorine,0,10,0);
			}
		}

		else
		{
			if(FurnaceTimer1<=1100)
			{
				float(_add,FurnaceTimer1,80);
				vector(_setx,gactorpos,-5770);
				vector(_sety,gactorpos,FurnaceTimer1);
				vector(_setz,gactorpos,12665);

				vector(_set,Gactorine,0,10,0);
				SpawnParticle(fx_mainexplosion2,-1,Gactorpos,Gactorine,-1);

				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);
			}
			else
			{
				float(_set,FurnaceTimer1,0);
			}
		}


		
		if (FurnaceTimer2<712 && FurnaceTimer2!=0)
		{
			float(_set,FurnaceTimer2,0);
		}
		
		if(FurnaceTimer2==0)
		{
			if(vrnd==2)
			{
				float(_set,FurnaceTimer2,712);
				vector(_set,Gactorpos,5757,813,12750);
				vector(_set,Gactorine,0,10,0);
			}
		}
		else
		{
			if(FurnaceTimer2<=1100)
			{
				float(_add,FurnaceTimer2,80);
				vector(_setx,gactorpos,5757);
				vector(_sety,gactorpos,FurnaceTimer2);
				vector(_setz,gactorpos,12750);

				vector(_set,Gactorine,0,10,0);
				SpawnParticle(fx_mainexplosion2,-1,Gactorpos,Gactorine,-1);

				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);	//spawnlight(name,bone,position,color,radius)
			}
			else
			{
				float(_set,FurnaceTimer2,0);
			}
		}

		if (FurnaceTimer3<712 && FurnaceTimer3!=0)
		{
			float(_set,FurnaceTimer3,0);
		}
		
		if(FurnaceTimer3==0)
		{
			if(vrnd==3 || vrnd==6)
			{
				float(_set,FurnaceTimer3,812);
				vector(_set,Gactorpos,5757,712,12690);
				vector(_set,Gactorine,0,10,0);
			}
		}
		else
		{
			if(FurnaceTimer3<=2300)
			{
				float(_add,FurnaceTimer3,50);
				vector(_setx,gactorpos,5757);
				vector(_sety,gactorpos,FurnaceTimer3);
				vector(_setz,gactorpos,12690);

				vector(_set,Gactorine,0,10,0);
				SpawnParticle(fx_mainexplosion2,-1,Gactorpos,Gactorine,-1);
				if(skipcollidecount>=5)
				{
					vector(_add,Gactorpos,fxvector);
					call(CheckActorCollision,gactorpos,220,0,_COLFire);
				}

				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);
			}
			else
			{
				float(_set,FurnaceTimer3,0);
				sample(SFXBazookaExplode,gactorpos);
			}
		}
	}
	if(VSetActive=="s2r22")
	{
		if(VarBit01&=Help18)
		{
			vector(_set,Gactorpos,6821,-581,9282);
			vector(_set,Gactorine,6619,-581,9282);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
			vector(_set,TmpVector4,0,30,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorine,gactorpos,fx_laserflickerred,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorine,gactorpos,fx_laserflickerred,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
		}
	}
	if(VSetActive=="s2r29")
	{
		//SHOWER TIME !!!
		if(BobSound&!=Help12)
		{
			CurEnvTriggerSet("s2r29","doorup");
			if(VKeyObjTriggered==0 && VKeyObjFrame!=0 && VarBit01&=Help06)
			{
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				float(_set,timer3,0);
				float(_clr,Varbit01,Help06);
			}
			call(expget,1,TmpFloat);
			if(TmpFloat<485)
			{
				if(vrnd<50)
				{
					call(SetParticleSetID,"s2r29");
					vector(_set,gactorpos,6500,-290,10350);
					vector(_set,tmpvector,0,0,0);
					vector(_set,gactorine,20,0,30);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,tmpvector,tmpfloat);
					vector(_add,gactorpos,tmpvector);
					vector(_set,Tmpvector1,0,-2,0);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					vector(_set,gactorpos,6558,-290,10392);
					vector(_set,tmpvector,0,0,0);
					vector(_set,gactorine,20,0,30);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,tmpvector,tmpfloat);
					vector(_add,gactorpos,tmpvector);
					vector(_set,Tmpvector1,0,-3,0);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					vector(_set,gactorpos,6539,-290,10312);
					vector(_set,tmpvector,0,0,0);
					vector(_set,gactorine,20,0,30);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,tmpvector,tmpfloat);
					vector(_add,gactorpos,tmpvector);
					vector(_set,Tmpvector1,0,-3,0);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					vector(_set,gactorpos,6555,-290,10345);
					vector(_set,tmpvector,0,0,0);
					vector(_set,gactorine,20,0,30);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,tmpvector,tmpfloat);
					vector(_add,gactorpos,tmpvector);
					vector(_set,Tmpvector1,0,-3,0);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
					float(_add,gactorpos,gactorine);
					spawnparticle(fx_icesmoke,-1,gactorpos,Tmpvector1,fx_icesteam);
				}
			}
			elseif(TmpFloat==485)
			{
				vector(_set,gactorpos,6500,-301,10350);
				samplestop(SFXRain2,Gactorpos);
			}
			elseif(TmpFloat==512)
			{
				call(KeyObjTrigger,255,1);
			}
			elseif(TmpFloat==560)
			{
				float(_set,IsDead,100);
				call(PlayerInput,1);
			}
		}
	}
	if(VSetActive=="s2r17")
	{
		CurEnvTriggerSet("s2r17","water");
		call(Expset1,5,2);
	}
	if(VSetActive=="s2r9c")
	{
		if(VarBit01&=Help10)
		{
			CurEnvTriggerSet("s2r9c","arme02");
			call(CheckTriggerObjFlag,TmpFloat,2,_SXObjDynamicObj);
			if(TmpFloat==TRUE)
			{
				vector(_set,Gactorpos,5544,766,16500);
				samplestop(SFXFieldHumLoop,Gactorpos);
				vector(_set,Gactorpos,5175,749,16499);
				samplestop(SFXScanHumm,Gactorpos);
				CurEnvTriggerSet("s2r9c","arme01");
				call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				CurEnvTriggerSet("s2r9a","fake");
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				float(_clr,VarBit01,Help10);
			}
		}
	}

	if(VSetActive=="s2r18")
	{

		//JOECODE
		CurEnvTriggerSet("s2r18","UnLock");
		if(VKeyObjTriggered!=0)
		{
			GetNumbActorsInSet("s2r18",_AIclasscop,TmpFloat);
			if(VKeyObjFrame==1 && Tmpfloat==0)
			{
				vector(_set,Gactorpos,10720,-1299,7964);
				vector(_set,Gactorangle,0,-1024,0);
				InitActor(copm,Gactorpos,Gactorangle,"s2r18",FALSE,0);
				InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"s2r18");

				//call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			}
		}
		else
		{
			//call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
		}
		
		if(BattleTimer==0)
		{
			CurEnvTriggerSet("s2r18","Flic");
			Call(expset1,0,0,14);
			float(_set,BattleTimer,1);
		}
		elseif(BattleTimer>0 && BattleTimer<150)
		{
			CurEnvTriggerSet("s2r18","Flic");
			Call(Expget,1,tmpfloat);
			if(tmpfloat==0)
			{
				//FIXTHIS
				sample(SFXAccess3,-1);
			}
		}
		elseif(BattleTimer==151)
		{
			CurEnvTriggerSet("s2r18","Flic");
			Call(Expget,1,tmpfloat);
			if(tmpfloat==177)
			{
				Call(ExpSet1,0,0,0);
				float(_add,BattleTimer,1);
			}
		}

		if(StreetCorpses==1 && Crossroads<1)
		{
			CurEnvTrigger("Door57");
			if(VKeyObjFrame!=0)
			{
				float(_set,Crossroads,1);	//Controls sequences in s2r8 (since its visted twice)
				float(_set,VarKey12,0);		//To prevent possible cop respawn in s2r8
				float(_set,timer,0);		//For respawn in s2r18
				call(expset1,1,TmpFloat,0);

				vector(_set,Gactorpos,11283,10,15743);
				vector(_set,Gactorangle,0,4130,0);
				InitActor(chot,Gactorpos,Gactorangle,"S2R8",TRUE,1);
				InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"S2R8");

				vector(_set,Gactorpos,11253,10,16181);
				vector(_set,Gactorangle,0,4585,0);
				InitActor(chot,Gactorpos,Gactorangle,"S2R8",TRUE,2);
				InitActor(WeaponBazooka,Gactorpos,Gactorangle,"S2R8");

				vector(_set,Gactorpos,10048,500,14038);
				vector(_set,Gactorangle,0,4130,0);
				InitActor(WeaponBazooka,Gactorpos,Gactorangle,"S2R8");
				vector(_set,Gactorpos,10048,466,14038);
				InitActor(chot,Gactorpos,Gactorangle,"S2R8",TRUE,5);

				vector(_set,Gactorpos,10042, 500, 15659);
				vector(_set,Gactorangle,0,1850,0);
				InitActor(WeaponBazooka,Gactorpos,Gactorangle,"S2R8");
				vector(_set,Gactorpos,10042, 465, 15659);
				InitActor(chot,Gactorpos,Gactorangle,"S2R8",TRUE,4);

				vector(_set,Gactorpos,10210, 67, 14200);
				vector(_set,Gactorangle,0,7259,0);
				InitActor(chot,Gactorpos,Gactorangle,"S2R8",TRUE,7);
				InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"S2R8");

				vector(_set,Gactorpos,10177,67,15506);
				vector(_set,Gactorangle,0,7918,0);
				InitActor(chot,Gactorpos,Gactorangle,"S2R8",TRUE,6);
				InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"S2R8");
			}
		}
	}

	if(VsetActive=="s2r8")  //mainscene
	{
		if(Gate4Unlocked!=0)
		{
			CurEnvTriggerSet("s2r8","dooropen");
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}
	}

	if(VSetActive=="s2r9")
	{
		if(VarBit01&!=Help22)
		{
			CurEnvTriggerSet("s2r9","fake");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
		}
	}
	if(VCurSet=="s2r9c")
	{
		CurEnvTrigger("arme01");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,5528,709,16861);
			callsub(DispenserSound);
		}

		CurEnvTrigger("arme02");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,5886,709,16504);
			callsub(DispenserSound);
		}
	}
	elseif(VCurSet=="s2r15")
	{
		if(VarKey11==1)
		{	
			call(SetParticleSetID,"s2r15");
			float(_add,timer3,1);
			if(timer3>=800)
			{
				float(_set,VarKey11,0)
				float(_set,timer3,0);
			}	
			float(_rnd2,TmpFloat1,6);
			float(_rnd2,TmpFloat2,6);
			if(TmpFloat1<1)
			{
				CurEnvTrigger("sphere01");
				vector(_settokfpos,Gactorpos,1);
			}
			elseif(TmpFloat1<2)
			{
				CurEnvTrigger("sphere01");
				vector(_settokfpos,Gactorpos,2);
			}
			elseif(TmpFloat1<3)
			{
				CurEnvTrigger("sphere02");
				vector(_settokfpos,Gactorpos,1);
			}
			elseif(TmpFloat1<4)
			{
				CurEnvTrigger("sphere02");
				vector(_settokfpos,Gactorpos,2);
			}
			elseif(TmpFloat1<5)
			{
				CurEnvTrigger("sphere03");
				vector(_settokfpos,Gactorpos,1);
			}
			elseif(TmpFloat1<6)
			{
				CurEnvTrigger("sphere03");
				vector(_settokfpos,Gactorpos,2);
			}
			if(TmpFloat2<1)
			{
				CurEnvTrigger("sphere01");
				vector(_settokfpos,Gactorine,1);
			}
			elseif(TmpFloat2<2)
			{
				CurEnvTrigger("sphere01");
				vector(_settokfpos,Gactorine,2);
			}
			elseif(TmpFloat2<3)
			{
				CurEnvTrigger("sphere02");
				vector(_settokfpos,Gactorine,1);
			}
			elseif(TmpFloat2<4)
			{
				CurEnvTrigger("sphere02");
				vector(_settokfpos,Gactorine,2);
			}
			elseif(TmpFloat2<5)
			{
				CurEnvTrigger("sphere03");
				vector(_settokfpos,Gactorine,1);
			}
			elseif(TmpFloat2<6)
			{
				CurEnvTrigger("sphere03");
				vector(_settokfpos,Gactorine,2);
			}
			callsub(ElectricStrip,gactorpos,gactorine,fx_blue);
		}
	}

	elseif(VCurSet=="s2r11")
	{
		call(SetParticleSetID,"s2r11");
		//**** SECRET *********
		if(VarBit01&=Help08)
		{
			CurEnvTrigger("barrel02");
			call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
			if(TmpFloat==TRUE)
			{
				float(_set,timer2,1);
				float(_clr,VarBit01,Help08);
			}
		}
		else
		{
			if(timer2>=1)
			{
				float(_add,timer2,1);
				if(timer2==40)
				{
					if(VFirstPerson!=0 || VSniperMode!=0)
					{
						FirstPerson(0,0);
						call(ChangeSniperMode,0,0);
					}
				}				
				if(timer2==60)
				{
					call(PlayerInput,0);
					CurEnvTrigger("facade");
					call(ExpSet2,80,1,1);
					call(KeyObjTrigger,255,1);
					kfsample(SFXDoOp1,SFXDoMo1,-1,SFXDoCl1);
				}
				if(timer2>=150)
				{
					call(PlayerInput,1);
					float(_set,timer2,0);
				}
			}

			if(vrnd<15)
			{
				vector(_set,tmpvector,0,0,0);
				float(_rnd2,tmpfloat,48);
				float(_sub,tmpfloat,24);
				vector(_setx,tmpvector,tmpfloat);
				float(_rnd2,tmpfloat,48);
				float(_sub,tmpfloat,24);
				vector(_sety,tmpvector,tmpfloat);
				float(_rnd2,tmpfloat,48);
				float(_sub,tmpfloat,24);
				vector(_setz,tmpvector,tmpfloat);
				vector(_set,Gactorpos,3966,877,9136);
				vector(_add,gactorpos,tmpvector);
				SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);

				vector(_set,tmpvector,238,177,10);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
			}
		}

		CurEnvTrigger("barrel03");
		if(VKeyObjFrame==1 && HudTimer==0)
		{
			vector(_set,Gactorpos,3959,625,9847);
			sample(SFXHatchEnd,Gactorpos);
			float(_set,HudTimer,1);
		}
		
		CurEnvTrigger("barrel01");
		if(VKeyObjFrame==21 && VarKey19<5)
		{
			CurEnvTrigger("barrel01");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			CurEnvTrigger("lift01");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			float(_set,VarKey19,5);
		}
			
		if(VarKey19>=5 && VarKey19<80)
		{
			float(_add,VarKey19,1);
			if(varkey19==20)
			{
				call(ClrAllCollisionBuffers);
			}
			if(VarKey19>=50)
			{
				CurEnvTrigger("lift01");
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,1,1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
					float(_set,VarKey19,81);
				}
			}
		}

		if(VarKey19==0)
		{
			float(_set,VarKey19,1);
		}

		if(VarBit01&!=Help04)
		{
			call(SetParticleSetID,"s2r11");
			float(_add,timer4,1)
			vector(_set,fxvector,3959,577,9450);
			vector(_set,gactorine,0,0,0);
			float(_rnd2,tmpfloat,128);
			float(_sub,tmpfloat,64);
			vector(_setx,gactorine,tmpfloat);
			float(_rnd2,tmpfloat,128);
			float(_sub,tmpfloat,64);
			vector(_setz,gactorine,tmpfloat);
			vector(_add,fxvector,gactorine);
			callsub(Sub_BloodFxSprayAbs);
			callsub(Sub_BloodFx2Abs);

			vector(_set,GactorPos,3959,577,9450);
			SamplePlaying(SFXCrushedReact,gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXCrushedReact,gactorpos);
			}

			if(timer4>=100)
			{
				float(_or,VarBit01,Help04);
				float(_set,timer4,0);
			}
		}

		//******* Grinder rotates all the time **********
		if(VarBit01&=Help01)
		{
			CurEnvTrigger("grinder");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
			}
		}
		//********** The grinder explodes **************
		if(VarBit01&!=Help01 && VarBit01&=Help02)
		{
			float(_add,timer3,1);
			if(timer3==10)
			{
				sample(SFXContainerOff,-1);
			}
			if(timer3<=30)
			{
				//*************  Big Explosion *************
				if(vrnd<15)
				{
//					vector(_set,Gactorpos,3959,490,9385);
//					samplestop(SFXBlenderLoop2,Gactorpos);

					call(SetParticleSetID,"s2r11");
					vector(_set,TmpVector,10,0,0);
					vector(_set,Gactorpos,3959,490,9385);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,500);
					sample(SFXBazookaExplode,gactorpos);
				}
			}
			elseif(timer3==45)
			{
				vector(_set,Gactorpos,3959,490,9385);
				samplestop(SFXSoftGrinder,Gactorpos);
				sample(SFXLiftBroken,Gactorpos);
			}
			elseif(timer3<=200)
			{
				//************* Sparks ******************
				if(vrnd<20)
				{
					vector(_set,tmpvector,0,0,0);
					float(_rnd2,tmpfloat,48);
					float(_sub,tmpfloat,24);
					vector(_setx,tmpvector,tmpfloat);
					float(_rnd2,tmpfloat,48);
					float(_sub,tmpfloat,24);
					vector(_sety,tmpvector,tmpfloat);
					float(_rnd2,tmpfloat,48);
					float(_sub,tmpfloat,24);
					vector(_setz,tmpvector,tmpfloat);
					vector(_set,Gactorpos,3851,582,9459);
					vector(_add,gactorpos,tmpvector);
					SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);
					vector(_set,tmpvector,20,150,250);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);
				}
			}
			elseif(timer3>=250)
			{
				//************* Plane collision is back on **************
				CurEnvTrigger("grinder");
				call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				vector(_set,tmpvector,0,-80,-80);
				vector(_set,Gactorpos,3959,800,9385);
				spawnlight(LightPulseOmni3,-1,Gactorpos,tmpvector,EmptyVector,600);
				call(KeyObjTrigger,255,1);
				float(_set,timer3,0);
				float(_clr,VarBit01,Help02);
			}
		}
	}
	elseif(VCurSet=="s2r5")
	{
		CurEnvTrigger("ship02"); //*** Far away StarDestroyer
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,255,1);
			kfsample(-1,SFXTechnoLoop,SFXTechnoLoop,-1);
		}
		CurEnvTrigger("aim01"); //*** Freighter
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,255,1);
			kfsample(-1,SFXTechnoLoop,SFXTechnoLoop,-1);
		}
		if(VarBit01&!=15)
		{
			CurEnvTrigger("ship01") //*** Close StarDestroyer
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
			}
		}

		if(ControlTimer==1)
		{
			dmessage("L O A D I N G . . .",50,2);
			CurEnvTriggerSet("s2r5","cityscape");
			setkeyframe("s2r5","cityscape",1);
			call(KeyObjTrigger,255,1);
			if(VSetActive=="s2r4")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
		}
	}
	
	if(skipcollidecount>=5)
	{
		float(_set,skipcollidecount,0);
	}
	float(_add,skipcollidecount,1);

}

SubRoutine(BackgroundTriggerChecksScene3)
{
	print("Dazed   :  ",dazed);
	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel3); // invokes the original MissionObjectives
		float(_set,incoming,0);
		float(_set,BobMessage,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(VSetActive=="s2r9a")
	{
		if(VAICon==0)
		{
			//******* HAND BOX **********	
			vector(_set,Gactorpos,4797,833,16590);
			CurEnvTriggerSet("s2r9a","handfx01");
			if(VTrigger==_DIREnvTrigger || Explode01!=0)
			{
				callsub(HandBox,150,Explode01);
			}
			//***************************
		}
	}
	//****** Calls in Chots until there are 4 of them in the room **********
	if(VAICon==0 && FirstTimeRun>=100)
	{
		if(VSetInMemory=="s2r1" && VSetActive=="s2r1")
		{
			GetNumbActorsInSet("s2r1",_AIClassDroid,TmpFloat);
			if(VSetInMemory=="s2r2" || VSetActive=="s2r2")
			{
				GetNumbActorsInSet("s2r2",_AIClassDroid,TmpFloat1);
				if(VSetInMemory=="s2r26" || VSetActive=="s2r26")
				{
					GetNumbActorsInSet("s2r26",_AIClassDroid,TmpFloat2);
					float(_add,TmpFloat,TmpFloat1);
					float(_add,TmpFloat,TmpFloat2);
					if(TmpFloat==0)
					{
						vector(_set,Gactorangle,0,1024,0);
						vector(_set,Gactorpos,1400,29,12621);
						initactor(Cleanupbot,Gactorpos,Gactorangle,"s2r26");
					}
				}
			}
		}
		if(VAIClass==_AIClassAnimal)
		{
			float(_set,SniperToggle,0);
		}
		else
		{
			float(_set,SniperToggle,1);
		}

		if(VarBit01&!=Help11 && FirstTimeRun>=100)
		{
			GetNumbActorsInSet("s2r1",_AIClassChot,TmpFloat);
			GetNumbActorsInSet("s2r2",_AIClassChot,TmpFloat1);
			GetNumbActorsInSet("s2r28",_AIClassChot,TmpFloat2);
			float(_add,TmpFloat,TmpFloat1);
			float(_add,TmpFloat,TmpFloat2);
			if(BobSound&=Help09)
			{
				if(VAIClass==_AIClassChot)
				{
					if(TmpFloat==1)
					{
						float(_clr,BobSound,Help09);
					}					
				}
				else
				{
					if(TmpFloat==0)
					{
						float(_clr,BobSound,Help09);
					}
				}
			}
			elseif(BobSound&!=Help09)
			{
				float(_add,ChotTimer,1);
				if(ChotTimer==1500)
				{
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,3682,1540,8133);
					initactor(WeaponPak,Gactorpos,Gactorangle,"s2r28");
					vector(_set,Gactorpos,3682,1520,8133);
					initactor(Chot,Gactorpos,Gactorangle,"s2r28",TRUE,8);
				}				
				if(ChotTimer==2000)
				{
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,3682,1540,8133);
					initactor(WeaponPak,Gactorpos,Gactorangle,"s2r28");
					vector(_set,Gactorpos,3682,1520,8133);
					initactor(Chot,Gactorpos,Gactorangle,"s2r28",TRUE,8);
				}
				elseif(ChotTimer==2500)
				{
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,3682,1540,8133);
					initactor(WeaponPak,Gactorpos,Gactorangle,"s2r28");
					vector(_set,Gactorpos,3682,1520,8133);
					initactor(Chot,Gactorpos,Gactorangle,"s2r28",TRUE,8);
					float(_set,ChotTimer,0);
					float(_or,BobSound,Help09);
				}
			}
		}
	}
	else
	{
		if(VCurSet=="s2r1" || VCurSet=="s2r24" || VCurSet=="s2r2" || VCurSet=="s2r26" || VCurSet=="s2r9" || VCurSet=="s2r8" || VCurSet=="s2r9a")
		{
			if(VState==StateCrawling || VState==StateHarpooned)
			{
				call(subtracthealth,0,20);
			}
		}
	}
	if(VCurSet=="s2r7")
	{
		CurEnvTrigger("door57");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			callsub(DoorOpen,2,1);
		}

		CurEnvTrigger("death");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);	
		}

		if(VAICon==0)
		{
			float(_set,TmpFloat,0x00ff00);
			CurEnvTriggerSet("s2r8","door78");
			call(expset2,1,TmpFloat,0);

			if(BobSound&=Help19)
			{
				call(CDFade,30,60);
				float(_clr,BobSound,Help19);
			}
	
			CurEnvTrigger("door78");
			/*vector(_set,tmpvector,600,200,6);
			float(_seti,TmpFloat2,VColFeetSphereSize);
			call(TriggerBox,tmpvector,tmpfloat2,tmpfloat);*/
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VKeyObjTriggered==0)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						float(_set,StreetCorpses,2);
						direction(_clr,_DIRaction);
					}
				}
			}
		
			if(ControlTimer==1)
			{
				CurEnvTrigger("door78")
				if(VSetActive=="s2r8")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r7","door78",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="s2r8")
	{
		if(Gate4Unlocked!=0)
		{
			if(BobSound&=Help16)
			{
				CurEnvTrigger("change");
				if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassCop)
				{
					float(_clr,BobSound,Help16);
				}
			}
			else
			{
				if(VAIClass==_AIClassChot && VAICon!=0 && VPathID==2)
				{
					callsub(Sub_AIGetBackToIdle);
					call(AIfindpathwithspecificid,69);
				}
			}
		}
		if(VAICon==0)
		{
			if(BobSound&!=Help19)
			{
				call(CDFade,60,60);
				float(_or,BobSound,Help19);
			}

			CurEnvTrigger("pl12");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}

			CurEnvTrigger("unlock");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit01&=Help22)
				{
					vector(_set,gactorpos,4848,506,15511);
					samplestop(SFXLaserAmbient,Gactorpos);
					call(ActivateButton,"Laser Wall Turned Off",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_clr,VarBit01,Help22);
				}
				else
				{
					call(ActivateButton,"Laser Wall already Disengaged",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}

			CurEnvTrigger("door78");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(Gate4Unlocked!=0)
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
					message("Door Is Locked For Safety Reasons",200,10);
					sample(SFXACcessDenied,Gactorpos);
				}
			}

			if(ControlTimer==2)
			{
				CurEnvTrigger("door78")
				if(VSetActive=="s2r7")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r8","door78",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("dooropen");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(Gate4Unlocked!=0)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						call(RunScriptCode,_or,4);
						//test
						call(ForceGlobalRealloc);
						call(ForceLoadSet,"s3_st07");
						call(ForceLoadSet,"s3_st06");
				
						float(_set,LinkGlobal,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Door Is Locked For Safety Reasons",200,10);
					sample(SFXACcessDenied,Gactorpos);
				}
			}
			if(VKeyObjTriggered==0 && LinkGlobal==1)
			{
				callsub(DeInitSceneSound4);
				call(RunScriptCode,_clr,4);
				float(_set,LinkGlobal,0);
			}
			if(ControlTimer==1)
			{
				CurEnvTrigger("dooropen");
				if(VSetActive=="s3_st07")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r8","dooropen",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="s2r2")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);

		if(VAICon==0)
		{
			if(VCutScene!=0)
			{
				call(GodModeStatus,true);
			}
			else
			{
				call(GodModeStatus,false);
			}

			CurEnvTrigger("calllft1");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				CurEnvTrigger("lift");
				if(VKeyObjTriggered==0)
				{
					if(VKeyObjFrame==1)
					{
						call(ActivateButton,"Lift is already on that floor",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
					elseif(VKeyObjFrame==0)
					{
						call(ActivateButton,"Lift called. Please Wait",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,1,1);
					}
				}
				else
				{
					call(ActivateButton,"Lift is moving",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				direction(_clr,_DIRaction);
			}

			CurEnvTrigger("calllft2");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				CurEnvTrigger("lift");
				if(VKeyObjTriggered==0)
				{
					if(VKeyObjFrame==0)
					{
						call(ActivateButton,"Lift is already on that floor",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
					elseif(VKeyObjFrame==1)
					{
						call(ActivateButton,"Lift called. Please Wait",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,0,-1);
					}
				}
				else
				{
					call(ActivateButton,"Lift is moving",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				direction(_clr,_DIRaction);
			}
			//******* HAND BOX **********	
			vector(_set,Gactorpos,1572,1113,7582);
			CurEnvTrigger("handfx");
			if(VTrigger==_DIREnvTrigger || Explode01!=0)
			{
				callsub(HandBox,200,Explode01);
			}
			//***************************

			//******* HAND BOX **********	
			vector(_set,Gactorpos,3314,47,7790);
			CurEnvTrigger("handfx01");
			if(VTrigger==_DIREnvTrigger || Explode02!=0)
			{
				callsub(HandBox,200,Explode02);
			}
			//***************************


						
			if(VarBit01&=Help11 && HelpVar&=Help13)
			{
				float(_add,VarKey13,1);
				if(VarKey13>=400)
				{
					float(_clr,VarBit01,Help11);
					float(_set,AiVisionToggle,1);
					float(_set,aitoggle,1);
					call(PlayerInput,0);
					if(VFirstPerson!=0 || VSniperMode!=0)
					{
						FirstPerson(0,0);
						call(ChangeSniperMode,0,0);
					}
					CutScene("vent");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
					float(_set,VarKey13,1);
					float(_set,ColorRange,0x010000);
				}
			}
			else
			{
				if(VarKey13>0)
				{
					float(_add,VarKey13,1);
					if(VarKey13<150)
					{
						CurEnvTrigger("vent");
						float(_set,TmpFloat2,0x010000);
						float(_add,ColorRange,TmpFloat2);
						call(expset1,1,ColorRange,0);
						/*
						if(vrnd<15)
						{
							vector(_set,Gactorpos,3082,900,8850);
							vector(_set,tmpvector,180,180,0);
							SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,100);
						}
						*/
					}
					elseif(VarKey13==150)
					{
						CurEnvTrigger("vent");
						call(ExplodeObject,TmpVector,1);
						callsub(Sub_ExplodeObjectHandler);
						float(_set,AIVisionToggle,0);
						float(_set,Aitoggle,0);
						vector(_set,Gactorangle,0,1024,0);
						vector(_set,Gactorpos,3682,1540,8133);
						initactor(WeaponPak,Gactorpos,Gactorangle,"s2r28");
						vector(_set,Gactorpos,3682,1520,8133);
						initactor(Chot,Gactorpos,Gactorangle,"s2r28",TRUE,8);
					}
					elseif(VarKey13==200)
					{
						call(CutSceneEnd);
						sample(SFXChotGrunt,Gactorpos);
						call(PlayerInput,1);
						float(_set,VarKey13,0);
					}
				}
			}

			CurEnvTrigger("liftdown");
			call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
			if(Tmpfloat==TRUE)
			{
				float(_clr,VarBit01,Help23);
			}

			if(VarBit01&!=Help23)
			{
				if(VAICon!=0 && VAIClass==_AIClassCop && VPathID==6)
				{
					callsub(Sub_AIGetBackToIdle);
					call(AIfindpathwithspecificid,99);
					float(_or,VarBit01,Help23);
				}
			}
		}
		else
		{
			if(VAIClass==_AIClassCop && VRank==_RankCommander)
			{
				direction(_clr,_DIRgrenade);
			}
			CurEnvTrigger("turctrl");
			if(VTrigger==_DIREnvTrigger && DisablePickUp!=0 && VAIClass!=_AIClassCop)
			{
				Direction(_clr,_DIRMoveBits|_DIRshoot);
			}
		}

		
		CurEnvTrigger("lift");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAICon==0)
			{
				if(VTrigger==_DIRaction)
				{
					if(VKeyObjTriggered==0)
					{
						call(KeyObjTrigger,1,1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					}
				}
			}
			else
			{
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,1,1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
			}
		}

		CurEnvTrigger("liftdown");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAICon==0)
			{
				if(VTrigger==_DIRaction)
				{
					CurEnvTrigger("lift");
					if(VKeyObjTriggered==0)
					{
						call(KeyObjTrigger,0,-1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					}
				}
			}
			else
			{
				CurEnvTrigger("lift");
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,0,-1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
			}
		}

	

		///////////////////////////////////
		///		GUN TURRET SEQUENCE		///
		///////////////////////////////////

		//******** Initialize Sequence - press button S2R2 *****************

		if(VAICon==0)
		{
			if(DisablePickup!=0)
			{
				Direction(_clr,_DIRgrenade);
			}
			CurEnvTrigger("turret01");
			vector(_set,TmpVector,10,110,30);
			Call(TriggerBox,TmpVector,0,tmpfloat);
			if(tmpfloat==1 && VTrigger==_DIREnvTrigger)
			{
				if(VarBit01&=Help19)
				{
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						sample(SFXGoodDayCommander,-1);
						float(_clr,VarBit01,Help19);
					}
				}
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					if(HelpVar&=help09 && TutorialToggle==1 && InBattle==0)
					{
						float(_clr,HelpVar,Help09);
						ClearTutorialLines();
						AddTutorialLine("To activate the [20:250:50]GUN TURRET[255:255:255]@ press");
						AddTutorialLine("your [20:250:50]ACTION[255:255:255] button in front of the");
						AddTutorialLine("console.");
						AddTutorialLine(" ");
						AddTutorialLine("In the [20:250:50]GUN TURRET[255:255:255]@ press your");
						AddTutorialLine("[20:250:50]FIRE[255:255:255] button to shoot and aim with");
						AddTutorialLine("[20:250:50]UP[255:255:255] and [20:250:50]DOWN[255:255:255]. To rotate the turret");
						AddTutorialLine("press [20:250:50]LEFT[255:255:255] and [20:250:50]RIGHT[255:255:255].");
						AddTutorialLine(" ");
						AddTutorialLine("To exit the Gun Turret@ press your");
						AddTutorialLine("Action Key and the Gun Turret will");
						AddTutorialLine("reset to its original position.");
						AddTutorialLine(" ");
						AddTutorialLine("  [100:100:100]             Press Any Key        ");
						AddTutorialLine("  [100:100:100]             To Continue          ");
						DisplayTutorialScreen("[255:255:20]GUN TURRET[150:150:150]",15,15);
					}
				}
			
				if(VTrigger==_DIRaction && VKeyObjFrame==0 && DisablePickUp==0)
				{
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						if(VSniperMode!=0)
						{
							call(ChangeSniperMode,-2,0);
						}
						call(ActivateButton,"Gun Turret Activated",-1,FALSE);
						call(CheckAttached,_CADropWeaponAndShells);
						call(ActivateButtonSample,SFXValidFunction);
						call(PlayerInput,0);
						CutScene("turret");
						float(_set,timer3,0);
						float(_set,DisablePickUp,1);
					}
					else
					{
						message("Only commanders can Operate This Unit.",200,10);
						sample(SFXAccessDenied,Gactorpos);
					}
				}
			}
			else
			{
				if(VarBit01&!=Help19)
				{
					float(_or,VarBit01,Help19);
				}
			}

			//******* Camera rotates - delay before Gun Turret animation starts ***********
			if(DisablePickUp==1)
			{
				float(_add,timer3,1);
				if(timer3>=40)
				{
					vector(_set,Gactorpos,1709,1061,9272);
					sample(SFXGunTurretWrap,Gactorpos);
					CurEnvTrigger("turret01");
					call(KeyObjTrigger,10,1);
					CurEnvTrigger("turret02");
					call(KeyObjTrigger,10,1);
					CurEnvTrigger("barrel");
					call(KeyObjTrigger,1,1);
					float(_set,DisablePickUp,2);
					float(_set,timer3,0);
					direction(_clr,_DIRaction);
				}
			}

			//********** Domina gets into her "Tron" position *****************
			CurEnvTrigger("turret01");
			if(VKeyObjFrame==5 && DisablePickUp==2)
			{
				if(Vaction!=DominaGunInit)
				{
					sample(SFXTurretArmedCommander,-1);
					ActorFlag(_or,_AFLAGnobulletcollision);
					spawnaction(DominaGunInit);
					float(_set,DisablePickUp,3);
					direction(_clr,_DIRaction);
				}
			}

			//*********** HUD change to ROCKET_HUD ********************
			if(VKeyObjFrame>=9 && DisablePickUp==3)
			{
				ActorFlag(_or,_AFLAGNoDepossession);
				if(VTrigger==_DIRHaveGun)
				{
					//if(AIAbility&=_AIAPickUpWeapon)
					//{
						call(CheckAttached,_CADropWeapon);
					//}
				}
				if(VCutScene==0)
				{
					CurEnvTrigger("turret01");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(KeyObjTrigger,13,1);
					CurEnvTrigger("turret02");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(KeyObjTrigger,13,1);
					float(_set,SniperMode,1);
					call(ChangeSniperMode,1,1);
					CurEnvTrigger("barrel");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					setkeyframe("s2r2","barrel",4);
					if(VarKey15==0)
					{
						vector(_set,TmpVector,0,0,0);
						call(SniperKFObj,TRUE,TmpVector);
						float(_set,VarKey15,1);
					}
					CurEnvTrigger("turret02");
					
					float(_set,DisablePickUp,4);
				}
			}

			//******** Turn Collision On (to be explodable) on Turret ****************
			if(DisablePickUp==4 && VKeyObjFrame>=13)
			{
				call(PlayerInput,1);
				CurEnvTrigger("turret01");
				call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);
				CurEnvTrigger("turret02");
				call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);			
				float(_set,DisablePickUp,5);
			}

			//******** Assign Special KFControl to Turret *******************
			if(DisablePickUp==5)
			{
				CurEnvTrigger("turctrl");
				if(VTrigger==_DIREnvTrigger)
				{
					call(NoZoomExit,true);
					CurEnvTrigger("turret01");
					if(VKeyObjFrame==13 && VTrigger==_DIRleft)
					{
						setkeyframe("s2r2","turret01",26);
					}
					if(VKeyObjFrame==26 && VTrigger==_DIRright)
					{
						setkeyframe("s2r2","turret01",13);
					}
					if(VKeyObjFrame>=13)
					{
						if(VSniperMode==1 && CallBot!=1)
						{
							call(KeySpeed,13,25,0xaaa);
							call(KeySpeed,25,26,0xfff);
						}
						elseif(VSniperMode==2 && CallBot!=2)
						{
							call(KeySpeed,25,26,0xfff);
							call(KeySpeed,13,25,0x600);
						}
						elseif(VSniperMode==3 && CallBot!=3)
						{
							call(KeySpeed,25,26,0xfff);
							call(KeySpeed,13,25,0x200);
						}
						elseif(VSniperMode==4 && CallBot!=4)
						{
							call(KeySpeed,25,26,0xfff);
							call(KeySpeed,13,25,0x100);
						}
						call(KeyObjControl,_DIRleft,_DIRright,13,26,SFXGunTurretHorizontal);
						CurEnvTrigger("barrel");
						if(VSniperMode==1 && CallBot!=1)
						{
							call(KeySpeed,3,5,0xaaa);
							float(_set,CallBot,1);
						}
						elseif(VSniperMode==2 && CallBot!=2)
						{
							call(KeySpeed,3,5,0x600);
							float(_set,CallBot,2);
						}
						elseif(VSniperMode==3 && CallBot!=3)
						{
							call(KeySpeed,3,5,0x320);
							float(_set,CallBot,3);
						}
						elseif(VSniperMode==4 && CallBot!=4)
						{
							call(KeySpeed,3,5,0x200);
							float(_set,CallBot,4);
						}
						call(KeyObjControl,_DIRBackward,_DIRforward,3,5,SFXGunTurretVertical);
					}
					callsub(Sub_GunTurretHandler);
					if(VTrigger==_DIRaction)
					{
						CurEnvTrigger("turret01");
						call(KeyObjControl,0,0,-1,-1,SFXGunTurretHorizontal);	//force looping samples to stop
						CurEnvTrigger("barrel");
						call(KeyObjControl,0,0,-1,-1,SFXGunTurretVertical);		//force looping samples to stop

						call(PlayerInput,0);
						float(_set,DisablePickUp,6);
						direction(_clr,_DIRaction);
					}
				}
			}

			//******** Action Key has been pressed. Turret reset to original position **********
			if(DisablePickUp==6)
			{
				call(CheckAttached,_CASwapWeapon);
				CurEnvTrigger("Turret01");
				call(KeySpeed,13,26,0xfff);
				call(ChangeSniperMode,1,1);
				call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);
				call(KeyObjTrigger,0,-1);
				CurEnvTrigger("turret02");
				call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);
				call(KeyObjTrigger,0,-1);
				setkeyframe("s2r2","barrel",0);
				float(_set,DisablePickUp,7);
			}
			
			//******** Reset HUD to normal **************
			if(DisablePickUp==7)
			{
				CurEnvTrigger("Turret01");
				if(VKeyObjFrame==9)
				{
					ActorFlag(_clr,_AFLAGNoDepossession);
					call(NoZoomExit,false);
					float(_set,SniperMode,0);
					call(ChangeSniperMode,0,1);
					CutScene("endseq");
					CurEnvTrigger("turret02");
					call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					CurEnvTrigger("barrel");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					if(VarKey15!=0)
					{
						vector(_set,TmpVector,0,0,0);
						call(SniperKFObj,FALSE,TmpVector);
						float(_set,VarKey15,0);
					}
					float(_set,DisablePickUp,8);
				}
			}

			//******* Domina gets back into an idle **************
			if(DisablePickUp==8)
			{
				CurEnvTrigger("turret01");
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						if(Vaction!=GenIdle)
						{
							spawnaction(GenIdle);
							call(PlayerInput,1);
							if(VAICon==0)
							{
								ActorFlag(_clr,_AFLAGnobulletcollision|_AFLAGnorotation|_AFlagNoTarget);
								call(CheckForPickup,12,_ClassWeapon);
							}
							float(_set,DisablePickUp,0);
						}
					}
				}
			}
		}
	}
	elseif(VCurSet=="s2r1")
	{
/*
		if(Objective==0)
		{
			call(DisplayObjectives);
			float(_set,Objective,1);
		}			
*/
		CurEnvTrigger("secsplit");
		if(VAICon==0 && VKeyObjTriggered==0 && VRunScriptCode==2)
		{
			callsub(DeInitSceneSound2);
			call(RunScriptCode,_clr,2);
			float(_set,TmpFloat,0xff0000);
			call(expset1,1,TmpFloat,0);
		}
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VKeyObjTriggered==0)
			{
				message("Door is Locked for Safety Reasons",200,10);
				sample(SFXAccessDenied,Gactorpos);
			}
		}
	}
	elseif(VCurSet=="s2r12")
	{
		CurEnvTrigger("death");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);
		}
		if(VAICon==0)
		{
			CurEnvTrigger("fuse");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Access Denied",120,10);
				sample(SFXPlayerActivatesLockedDoorReact,-1);
				direction(_clr,_DIRaction);
			}
			if(BobSound&=Help02 && VAIClass==_AIClassAngel)
			{
				if(VState!=StateFalling && VState!=StateFlying && VState!=StateGliding && VState!=StateJump && VTrigger!=_DIRmove)
				{
					sample(SFXBobHowCanIGet,-1);
					float(_clr,BobSound,Help02);
				}
			}
		}
	}
	elseif(VCurSet=="s2r28")
	{
		if(VAICon==0)
		{
			//******* HAND BOX **********	
			vector(_set,Gactorpos,4623,852,10080);
			CurEnvTrigger("handfx");
			if(VTrigger==_DIREnvTrigger || Explode02!=0)
			{
				callsub(HandBox,200,Explode02);
			}
			//***************************

			CurEnvTrigger("hidden");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VKeyObjFrame==0)
				{
					call(ActivateButton,"Unlocking Door",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,255,1);
					kfsample(SFXRustDoorOpen,SFXRustDoorLoop,-1,SFXRustDoorClose);
				}
				else
				{
					call(ActivateButton,"nothing...",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}


			if(BobSound&=Help03)
			{
				CurEnvTrigger("ratsound");
				if(VAIClass==_AIClassAngel && VTrigger==_DIREnvTrigger)
				{
					sample(SFXBobEuchRats,-1);
					float(_clr,BobSound,Help03);
				}
			}
		}			
	}
	elseif(VCurSet=="s2r26")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("door1");
			if(VTrigger==_DIRenvtrigger && VTRigger==_DIRaction)
			{
				message("Door Locked",120,10);
				sample(SFXAccessDenied,Gactorpos);
			}

			CurEnvTrigger("doorup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					call(LoadPreLoadDB,4);
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			if(ControlTimer==1)
			{
				CurEnvTrigger("doorup")
				if(VSetActive=="s2r11")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r26","doorup",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
		else
		{
			if(VarKey17==1)
			{
				if(VAIClass==_AIClassCop && VPathID==4)
				{
					callsub(Sub_AIGetBackToIdle);
					call(AIfindpathwithspecificid,61);
					float(_set,VarKey17,2);
				}
			}
		}
	}
	elseif(VCurSet=="s2r11")
	{
		CurEnvTrigger("blocked");
		vector(_set,TmpVector,282,15,245);
		Call(TriggerBox,TmpVector,0,tmpfloat);
		if(tmpfloat==1 && VarBit01&=Help07)
		{
			call(subtracthealth,0,10000);
		}

		if(HelpVar&=Help10 && VAICon==0)
		{
			float(_set,Incoming,1);
			float(_set,Godtimer,0);
			float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
			float(_set,ScriptMark,5);
			callsub(Panel5);
			ClearDMessage();
			float(_clr,HelpVar,Help10);
		}
		
		if(VAICon==0)
		{
			float(_add,IsDead,1);
			if(IsDead>=450)
			{
				GetNumbActorsInSet("s2r11",_AIClassScientist,TmpFloat);
				if(TmpFloat==0)
				{
					vector(_set,Gactorpos,3193,1300,9457);
					vector(_set,Gactorangle,0,2048,0);
					initactor(WeaponBuzzSaw,Gactorpos,Gactorangle,"s2r11");
					vector(_set,Gactorpos,3193,1250,9457);
					initactor(Scientist,Gactorpos,Gactorangle,"s2r11",TRUE,3);
				}
				float(_set,IsDead,0);
			}
		}

		CurEnvTrigger("laserin");
		if(Vtrigger==_DirEnvTrigger)
		{
			if(Vclass==_ClassAngel && VState==StateCrouching)
			{
				sample(SFXSmallSparks02,-1);
			}
			else
			{
				colstate(_or,_COLelectricity);
			}
		}

		CurEnvTrigger("laserout");
		if(Vtrigger==_DirEnvTrigger)
		{
			if(Vclass==_ClassAngel && VState==StateCrouching)
			{
				sample(SFXSmallSparks02,-1);
			}
			else
			{
				colstate(_or,_COLelectricity);
			}
		}


		CurEnvTrigger("scream");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass!=_AIClassAngel)
			{
				sample(SFXDrownReact,-1);
				if(Vaction!=CopfallFL)
				{
					spawnaction(CopfallFL);
				}
			}
			else
			{
				camera(350,150);
			}
		}
		CurEnvTrigger("activate");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(RadAlert<=4)
			{
				if(RadAlert==0)
				{
					call(ActivateButton,"Container is empty.",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				elseif(RadAlert==1)
				{
					call(ActivateButton,"Container is 25 percent filled",-1,FALSE);
					call(ActivateButtonSample,SFXContainer25);
				}
				elseif(RadAlert==2)
				{
					call(ActivateButton,"Container is 50 percent filled",-1,FALSE);
					call(ActivateButtonSample,SFXContainer50);
				}
				elseif(RadAlert==3)
				{
					call(ActivateButton,"Container is 75 percent filled",-1,FALSE);
					call(ActivateButtonSample,SFXContainer75);
				}
				elseif(RadAlert==4)
				{
					call(ActivateButton,"Container is filled and ready",-1,FALSE);
					call(ActivateButtonSample,SFXContainer100);
				}
			}
			else
			{
				CurEnvTrigger("barrel01");
				if(VKeyObjFrame==0)
				{
					call(ActivateButton,"Transport in progress",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,21,1);
					CurEnvTrigger("barrel03");
					call(KeyObjTrigger,21,1);
				}
				else
				{
					call(ActivateButton,"System Is Busy",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);										
				}
			}
		}
	
		if(VAICon==0)
		{
			if(BobSound&=Help17)
			{
				CurEnvTrigger("lift01");
				if(VKeyObjTriggered==0 && VKeyObjFrame!=0)
				{
					CurEnvTrigger("tut");
					if(VTrigger==_DIREnvTrigger)
					{
						float(_clr,BobSound,Help17);
						ClearTutorialLines();
						AddTutorialLine("To reach higher ground@ press and hold");
						AddTutorialLine("your [20:100:200]jump/fly button[255:255:255] and once you reach");
						AddTutorialLine("the peak of your initial jump@ start");
						AddTutorialLine("flapping your wings repeatedly.");
						AddTutorialLine(" ");
						AddTutorialLine("This technique allows you to gain access");
						AddTutorialLine("to seemingly unreachable areas of the");
						AddTutorialLine("game.");
						AddTutorialLine(" ");
						AddTutorialLine("    [255:255:0]             Press Any Key       ");
						AddTutorialLine("    [255:255:0]             To Continue         ");
						DisplayTutorialScreen("[255:255:20]HINT: FLY HIGHER",15,15);
					}
				}
			}

			printh("BobSound    ",BobSound);
			CurEnvTrigger("fake");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Door is Remotely locked",200,10);
				sample(SFXPlayerActivatesLockedDoorReact,-1);
				direction(_clr,_DIRaction);
			}
			CurEnvTrigger("openfuse");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				sample(SFXHatchEnd,Gactorpos);
			}
			if(VKeyObjFrame==1)
			{
				float(_clr,BobSound,Help13);
			}
			else
			{
				float(_or,BobSound,Help13);
			}

			CurEnvTrigger("fuse");
			if(BobSound&!=Help13 && BobSound&=Help14)
			{
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					call(ActivateButton,"Storage Door Opened for Seven Seconds",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
					float(_set,TmpFloat,0x000000);
					call(expset2,1,TmpFloat,0);
					call(HUDTimerSet,210);
					callsub(DoorOpen,2,0);
					float(_clr,BobSound,Help14);
				}
			}
			if(VKeyObjTriggered==0 && VKeyObjFrame==0)
			{
				float(_set,TmpFloat,0xff0000);
				call(expset2,1,TmpFloat,0);
				float(_set,TmpFloat,0x000000);
				call(expset1,1,TmpFloat,0);
				float(_or,BobSound,Help14);
			}
			if(BobSound&=Help14)
			{
				float(_set,TmpFloat,0xff0000);
				CurEnvTrigger("fake");
				call(expset1,1,TmpFloat,0);
			}
			else
			{
				float(_set,TmpFloat,0x00ff00);
				CurEnvTrigger("fake");
				call(expset1,1,TmpFloat,0);
			}

			CurEnvTrigger("doorup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Automatic Lock Has Been Activated. Access Denied",120,10);
				sample(SFXAccessDenied,Gactorpos);
			}
			if(VKeyObjTriggered==0)
			{
				float(_set,TmpFloat,0xff0000);
				call(expset1,1,TmpFloat,0);
			}
		}
		CurEnvTrigger("grinder2");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAICon!=0)
			{
				sample(SFXCrushedReact,-1);
				KillActor();
				sample(SFXSeparateBodyParts,-1);
				sample(SFXBobWhoops,-1);
				float(_add,RadAlert,1);
				float(_clr,VarBit01,Help03);
				float(_clr,VarBit01,Help04);
				float(_set,timer4,0);
			}
			else
			{
				sample(SFXCrushedReact,-1);
				float(_clr,VarBit01,Help03);
				float(_clr,VarBit01,Help04);
				float(_set,timer4,0);
//				Camera(1000,600);
//				Target(-10,10);
				call(LockCamera,1);
				Direction(_clr,_DIRalive);
				State(_or,StateDead);
				call(AIchangerank,0);
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("panel");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit01&=Help07)
				{
					call(ActivateButton,"Platform Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,TmpFloat,0xff5500);
					call(expset1,1,TmpFloat,0);
					float(_set,CommandTimer,0);
					float(_clr,VarBit01,Help07);
				}
				else
				{
					call(ActivateButton,"Platform Already Activated",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				direction(_clr,_DIRaction);
			}

			if(VarBit01&!=Help07)
			{
				float(_add,CommandTimer,1);
				if(CommandTimer<=100)
				{
					if(CommandTimer&=1)
					{
						CurEnvTrigger("panel");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					}
					else
					{
						CurEnvTrigger("panel");
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					}
				}
				elseif(Commandtimer==101)
				{
					CurEnvTrigger("panel");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(ClrAllCollisionBuffers);
					float(_set,TmpFloat,0xffffff);
					call(expset1,1,TmpFloat,0);
				}
				elseif(CommandTimer<=250)
				{
					CurEnvTrigger("panel");
					float(_set,TmpFloat,0xff5500);
					call(expset1,1,TmpFloat,0);
				}
				elseif(CommandTimer<=255)
				{
					if(CommandTimer&=1)
					{
						CurEnvTrigger("panel");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					}
					else
					{
						CurEnvTrigger("panel");
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					}
				}
				elseif(CommandTimer==256)
				{
					CurEnvTrigger("panel");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					call(ClrAllCollisionBuffers);
					float(_set,TmpFloat,0xffffff);
					call(expset1,1,TmpFloat,0);
				}
				elseif(CommandTimer==270)
				{
					float(_or,VarBit01,Help07);
					float(_set,CommandTimer,0);
				}
			}

			if(RadAlert<7)
			{
				if(RadAlert==1)
				{
					if(VarBit01&!=Help03)
					{
						CurEnvTrigger("barrel02");
						call(KeyObjTrigger,1,1);
						vector(_set,Gactorpos,3959,800,9385);
						sample(SFXPourWater,Gactorpos);
						float(_or,VarBit01,Help03);
					}
				}
				elseif(RadAlert==2)
				{
					if(VarBit01&!=Help03)
					{
						CurEnvTrigger("barrel02");
						call(KeyObjTrigger,2,1);
						vector(_set,Gactorpos,3959,800,9385);
						sample(SFXPourWater,Gactorpos);
						float(_or,VarBit01,Help03);
					}
				}
				elseif(RadAlert==3)
				{
					if(VarBit01&!=Help03)
					{
						CurEnvTrigger("barrel02");
						call(KeyObjTrigger,3,1);
						vector(_set,Gactorpos,3959,800,9385);
						sample(SFXPourWater,Gactorpos);
						float(_or,VarBit01,Help03);
					}
				}
				elseif(RadAlert==4)
				{
					if(VarBit01&!=Help03)
					{
						CurEnvTrigger("barrel02");
						call(KeyObjTrigger,4,1);
						vector(_set,Gactorpos,3959,800,9385);
						sample(SFXPourWater,Gactorpos);
						float(_or,VarBit01,Help03);
					}
					dmessage("Container Filled. Please Activate Magnetic Track",50,200);
					float(_set,RadAlert,5);
				}
				elseif(RadAlert==6)
				{
					float(_clr,Varbit01,Help01);
					float(_set,RadAlert,7);
				}
			}
		}
	}
	elseif(VCurSet=="s2r3")
	{
		if(VAICon==0)
		{
			callsub(LottoSample);

			CurEnvTrigger("doorup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				callsub(DoorOpen,1,1);
			}

			CurEnvTrigger("door23");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Door Locked For Safety Reasons",200,10);
				sample(SFXAccessDenied,Gactorpos);
			}
		}

		CurEnvTrigger("death");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="s2r4")
	{
		if(VAICon==0)
		{
			////////////////////
			// Respawn GUN COMMANDER //
			////////////////////

			if(VarBit01&=Help24)
			{
				call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassCop,_GreaterEqual,_RankCommander);
				if(TmpFloat==0)
				{
					vector(_set,Gactorpos,5601,-585,9972);
					initactor(GunCommander,Gactorpos,Gactorangle,"s2r24",TRUE,1);
					float(_clr,VarBit01,Help24);
				}
			}

			CurEnvTrigger("door45");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(crossroads==0)
					{
						message("Door Cannot Be Operated",200,10);
						sample(SFXAccessDenied,Gactorpos);
					}
					else
					{
						callsub(DoorOpen,2,1);
					}
				}		
			}

			CurEnvTrigger("cityscape");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(VAIClass==_AIClassCop && VRank>=_RankCommander)
				{
					GetNumbActorsInSet("s2r4",_AIClassChot,TmpFloat);
					if(TmpFloat==0)
					{
						float(_set,TmpFloat,0x00ff00);
						call(expset1,1,TmpFloat,0);
					}
				}
				else
				{
					float(_set,TmpFloat,0xff0000);
					call(expset1,1,TmpFloat,0);
				}
				if(VTrigger==_DIRaction && ControlTimer==0)
				{				
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						GetNumbActorsInSet("s2r4",_AIClassChot,TmpFloat);
						if(TmpFloat==0)
						{
							float(_set,ControlTimer,1);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
						}
						else
						{
							message("Chot Activity Detected - Door Shut for Safety Reasons",350,10);
							direction(_clr,_DIRaction);
						}
					}
					else
					{
						message("Access Restricted to Commanders",120,10);
						sample(SFXAccessDenied,Gactorpos);
						direction(_clr,_DIRaction);
					}
				}
			}
			else
			{
				if(VKeyObjTriggered==0)
				{
					float(_set,TmpFloat,0xff0000);
					call(expset1,1,TmpFloat,0);
				}
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("cityscape")
				if(VSetActive=="s2r5")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r4","cityscape",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}		
	}
	elseif(VCurSet=="s2r9")
	{
		if(VAICon==0 && StreetCorpses==0)
		{
			if(VarBit01&=Help22)
			{
				CurEnvTrigger("lazerwall");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
			}
			else
			{
				CurEnvTrigger("fake");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			}

			if(BobSound&=Help07 && FirstTimeRun!=0)
			{
				GetNumbActorsInSet("s2r9",_AIClassChot,TmpFloat);
				if(VAIClass==_AIClassChot)
				{
					if(TmpFloat==1)
					{
						float(_clr,Bobsound,Help07);
						float(_set,CommandTimer,0);							
						float(_sub,MaxChotRespawn,1);
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						float(_clr,Bobsound,Help07);
						float(_set,CommandTimer,0);							
						float(_sub,MaxChotRespawn,1);
					}
				}
			}
			if(BobSound&!=Help07)
			{
				float(_add,CommandTimer,1);
				if(Commandtimer==400)
				{

					vector(_set,Gactorpos,4721,1020,15298);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(WeaponPAK,Gactorpos,Gactorangle,"S2r9");
					vector(_set,Gactorpos,4721,980,15298);
					InitActor(Chot,Gactorpos,Gactorangle,"S2r9",FALSE);
				}
				elseif(CommandTimer==450)
				{				
					vector(_set,Gactorpos,4667,1021,14999);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(WeaponPAK,Gactorpos,Gactorangle,"S2r9");
					vector(_set,Gactorpos,4667,980,14999);
					InitActor(Chot,Gactorpos,Gactorangle,"S2r9",FALSE);
				}
				elseif(CommandTimer==500)
				{
					vector(_set,Gactorpos,4732,1021,14402);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(WeaponPAK,Gactorpos,Gactorangle,"S2r9");
					vector(_set,Gactorpos,4732,980,14402);
					InitActor(Chot,Gactorpos,Gactorangle,"S2r9",FALSE);
					float(_or,BobSound,Help07);
					float(_set,CommandTimer,0);
				}
			}

			CurEnvTrigger("lift");
			if(VKeyObjTriggered==0 || VKeyObjFrame==11)
			{
				callsub(Sub_SetCameraNormal);
			}
			else
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);
			}

			CurEnvTrigger("clift");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				CurEnvTrigger("lift");
				if(VKeyObjFrame!=0)
				{
					call(ActivateButton,"Lift Called",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,0,-1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					direction(_clr,_DIRaction);
				}
				else
				{
					if(VKeyObjTriggered==0)
					{
						call(ActivateButton,"Lift Is Already At Your Floor",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						direction(_clr,_DIRaction);
					}
				}
			}

			CurEnvTrigger("panel1");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(VarBit01&!=Help09)
					{
						CurEnvTrigger("lift");
						if(VKeyObjFrame==0 && VKeyObjTriggered==0)
						{
							call(ActivateButton,"Lift Activated",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);			
							call(KeyObjTrigger,3,1);
							kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
							direction(_clr,_DIRaction);
						}
					}
					else
					{
						call(ActivateButton,"Lift Power is Off",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
				}
			}

			CurEnvTrigger("doorup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit01&!=Help09)
				{
					if(ControlTimer==0)
					{
						call(LoadPreLoadDB,5);
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Door Power is off",200,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}


			if(ControlTimer==1)
			{
				CurEnvTrigger("doorup")
				if(VSetActive=="s2r19")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r9","doorup",1);
					call(KeyObjTrigger,255,1);
				}
			}
			CurEnvTrigger("fake");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Door is melted shut.",120,10);
				sample(SFXAccessDenied,Gactorpos);
				direction(_clr,_DIRaction);
			}
		}
	}
	elseif(VCurSet=="s2r5")
	{

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);

		CurEnvTrigger("door1");
		call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
		if(Tmpfloat==TRUE)
		{
			call(AIChangePlayerToEnemy);
			float(_set,aivisiontoggle,0);		
		}
							
		CurEnvTrigger("plate_m");
		call(CheckTriggerObjFlag,TmpFloat,2,_SXObjDynamicObj);
		if(Tmpfloat==TRUE)
		{
			float(_clr,BobSound,Help04);
			CurEnvTrigger("ship01");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(ClrAllCollisionBuffers);
		}

		CurEnvTrigger("plate_l");
		call(CheckTriggerObjFlag,TmpFloat,2,_SXObjDynamicObj);
		if(Tmpfloat==TRUE)
		{
			float(_clr,BobSound,Help05);
			CurEnvTrigger("ship01");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
			call(ClrAllCollisionBuffers);
		}

		CurEnvTrigger("plate_r");
		call(CheckTriggerObjFlag,TmpFloat,2,_SXObjDynamicObj);
		if(Tmpfloat==TRUE)
		{
			float(_clr,BobSound,Help06);
			CurEnvTrigger("ship02");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(ClrAllCollisionBuffers);
		}

		if(VAICon!=0)
		{
			if(VAIClass==_AIClassCop)
			{
				ActorFlag(_or,_AFLAGsniperLongRange);
				if(DisablePickUp!=0 && DisablePickUp<5)
				{
					direction(_clr,_DIRshoot);
				}
			}
			////////////////////////////////
			// Make the stoopid cops fall //
			////////////////////////////////

			if(BobSound&!=Help04)
			{
				if(VPathID==30)
				{
					CurEnvTrigger("plate_m");
					if(VTrigger==_DIREnvTrigger)
					{
						move(0,-10,0);
						call(ClrAllCollisionBuffers);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					}
				}
			}
			if(BobSound&!=Help05)
			{
				if(VPathID==40)
				{
					CurEnvTrigger("plate_l");
					if(VTrigger==_DIREnvTrigger)
					{
						move(0,-10,0);
						call(ClrAllCollisionBuffers);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
						call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
					}
				}
			}
			if(BobSound&!=Help06)
			{
				if(VPathID==20)
				{
					CurEnvTrigger("plate_r");
					if(VTrigger==_DIREnvTrigger)
					{
						move(0,-10,0);
						call(ClrAllCollisionBuffers);
						CurEnvTrigger("ship02");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					}
				}
			}
						
		}
		else
		{
			if(DisablePickUp>=3)
			{
				if(Varbit01&=Help05)
				{
					float(_add,CabTimer,1);
					if(CabTimer<50)
					{
						CurEnvTrigger("plate_m");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					}
					else
					{
						CurEnvTrigger("plate_m");
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
						if(CabTimer>200)
						{
							float(_set,CabTimer,0);
						}					
					}
				}
				else
				{
					CurEnvTrigger("plate_m");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}												
				if(FreighTimer==0)
				{
					CurEnvTrigger("hull01");
					call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
					if(Tmpfloat==TRUE)
					{
						ClearDMessage();
						dmessage("Hull Breach. 75% left",50,150);
						CurEnvTrigger("barrel");
						call(SetParticleSetID,"s2r5");
						vector(_settokfpos,TmpVector,1);
						callsub(sub_fxexplosion);
						call(ScreenShake,0,10,0,0.8);
						CurEnvTrigger("hull02");
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
						float(_set,FreighTimer,1);
					}
				}
				elseif(FreighTimer==1)
				{
					CurEnvTrigger("hull02");
					call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
					if(Tmpfloat==TRUE)
					{
						ClearDMessage();
						dmessage("Hull Breach. 50% left",50,150);
						CurEnvTrigger("barrel");
						call(SetParticleSetID,"s2r5");
						vector(_settokfpos,TmpVector,1);
						callsub(sub_fxexplosion);
						call(ScreenShake,8,8,8,0.9);
						CurEnvTrigger("hull03");
						call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						float(_set,FreighTimer,2);
					}
				}
				elseif(FreighTimer==2)
				{
					CurEnvTrigger("hull03");
					call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
					if(Tmpfloat==TRUE)
					{
						ClearDMessage();
						dmessage("Hull Breach. 25% left",50,150);
						CurEnvTrigger("barrel");
						call(SetParticleSetID,"s2r5");
						vector(_settokfpos,TmpVector,1);
						callsub(sub_fxexplosion);
						call(ScreenShake,15,15,15,0.9);
						CurEnvTrigger("hull04");
						call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						float(_set,FreighTimer,3);
					}
				}
				elseif(FreighTimer==3)
				{
					CurEnvTrigger("hull04");
					call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
					if(Tmpfloat==TRUE)
					{
						ClearDMessage();
						dmessage("Hull Destroyed",50,150);
						CurEnvTrigger("barrel");
						call(SetParticleSetID,"s2r5");
						vector(_settokfpos,TmpVector,1);
						callsub(sub_fxexplosion);
						call(ScreenShake,20,20,20,0.9);
						float(_set,FreighTimer,5);
					}
				}
				if(FreighTimer>=2 && FreighTimer<5)
				{
					CurEnvTrigger("barrel");
					vector(_settokfpos,Gactorpos,0);
					vector(_set,tmpvector,180,100,0);
					SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,350);
				}
				elseif(FreighTimer==5)
				{
					call(subtracthealth,0,30000);
					direction(_clr,_DIRalive);
					state(_or,StateDead);
					call(FadeToBlack,3); //ends the game
				}
			}
												
			CurEnvTrigger("cityscape");
			callsub(StartDoorDelay,1);

			////////////////////
			// OPEN TANK DOOR //
			////////////////////
			CurEnvTrigger("doortank");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					call(ForceLoadSet,"s2r18");
					float(_set,ControlTimer,4);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		
			if(ControlTimer==4)
			{
				CurEnvTrigger("doortank")
				if(VSetActive=="s2r18" && VSetInMemory=="s2r18")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r5","doortank",1);
					call(KeyObjTrigger,255,1);
				}
			}

			///////////////////////////////////////////////////////
			// Check if all Cops are dead, then open plasma door //
			///////////////////////////////////////////////////////
			if(VarBit01&=Help05)
			{
				if(BobSound&!=Help04 && BobSound&!=Help05 && BobSound&!=Help06)
				{
					message("Disabling Plasma Door",200,10);
					CurEnvTrigger("door1");
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					float(_clr,Varbit01,Help05);
				}
			}
			else
			{
				float(_clr,BobSound,Help18);
			}
				
				
			///////////////////
			// SHIP CHECKING //
			///////////////////
			//
			//*** Trigger SHIP01 - Object SHUTTLE1 
			//*** Trigger SHIP02 - Object SHUTTLE
			//*** Trigger AIM01  - Object FREIGHTR - EXP1 SHUTTLE  - EXP2 EXPLO FOR PLTFRM #1
			//*** Trigger AIM02	 -				   - EXP1 SHUTTLE1 - EXP2 EXPLO FOR PLTFRM #2
			//*** Trigger AIM03  -				   - EXP1 FREIGHTR - EXP2 EXPLO FOR PLTFRM #3
			//

			if(Varbit01&=Help15)
			{
				CurEnvTrigger("ship01");
				if(VKeyObjFrame>=11 && VKeyObjFrame<=13)
				{
					float(_set,MissionLevel2,2);
				}
				elseif(VkeyObjFrame>=20 && VKeyObjFrame<=22)
				{
					float(_set,MissionLevel2,3);
				}
				elseif(VKeyObjFrame>=23 && VKeyObjFrame<=25)
				{
					float(_set,MissionLevel2,1);
				}
				elseif(VKeyObjFrame>=26 && VKeyObjFrame<=28)
				{
					float(_set,MissionLevel2,2);
				}
				elseif(VKeyObjFrame==42)
				{
					float(_set,MissionLevel2,3);
				}
				elseif(VKeyObjFrame==43)
				{
					float(_set,MissionLevel2,1);
				}
				elseif(VKeyObjFrame>=44 && VKeyObjFrame<=45)
				{
					float(_set,MissionLevel2,2);
				}
				else
				{
					float(_set,MissionLevel2,0);
				}

				CurEnvTrigger("AIM01");
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(Tmpfloat==TRUE)
				{
					call(ClrAllCollisionBuffers);
					float(_clr,Varbit01,Help15);
					if(MissionLevel2==1)
					{
						CurEnvTrigger("AIM01");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						float(_clr,BobSound,Help04);
					}

					elseif(MissionLevel2==2)
					{
						CurEnvTrigger("AIM02");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
						float(_clr,BobSound,Help05);

					}
					elseif(MissionLevel2==3)
					{
						CurEnvTrigger("AIM03");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						CurEnvTrigger("ship02");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						float(_clr,BobSound,Help06);
					}
					float(_set,RadChecked1,1);
				}
			}
			else
			{
				if(RadChecked1>=1)
				{
					float(_add,RadChecked1,1);
					if(RadChecked1>=1000)
					{
						CopyObjectToObject("dummy01","shuttle1");
						float(_set,RadChecked1,0);
						float(_or,Varbit01,Help15);
					}
				}
			}
					

			if(Varbit01&=Help16)
			{
				CurEnvTrigger("ship02");
				if(VKeyObjFrame>=22 && VKeyObjFrame<=23)
				{
					float(_set,MissionLevel3,1);
				}
				elseif(VkeyObjFrame>=24 && VKeyObjFrame<=26)
				{
					float(_set,MissionLevel3,3);			
				}
				elseif(VKeyObjFrame>=43 && VKeyObjFrame<=45)
				{
					float(_set,MissionLevel3,3);
				}
				elseif(VKeyObjFrame>=46 && VKeyObjFrame<=48)
				{
					float(_set,MissionLevel3,1);
				}
				elseif(VKeyObjFrame>=49 && VKeyObjFrame<=52)
				{
					float(_set,MissionLevel3,2);
				}
				else
				{
					float(_set,MissionLevel3,0);
				}

				CurEnvTrigger("AIM02");
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(Tmpfloat==TRUE)
				{
					call(ClrAllCollisionBuffers);
					float(_clr,Varbit01,Help16);
					if(MissionLevel3==1)
					{
						CurEnvTrigger("AIM01");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						float(_clr,BobSound,Help04);
					}

					elseif(MissionLevel3==2)
					{
						CurEnvTrigger("AIM02");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
						float(_clr,BobSound,Help05);

					}
					elseif(MissionLevel3==3)
					{
						CurEnvTrigger("AIM03");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						CurEnvTrigger("ship02");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						float(_clr,BobSound,Help06);
					}
					float(_set,RadChecked2,1);
				}
			}
			else
			{
				if(RadChecked2>=1)
				{
					float(_add,RadChecked2,1);
					if(RadChecked2>=1000)
					{
						CopyObjectToObject("dummy02","shuttle");
						float(_set,RadChecked2,0);
						float(_or,Varbit01,Help16);
					}
				}
			}


			if(Varbit01&=Help17)
			{
				CurEnvTrigger("aim01");
				if(VKeyObjFrame>=3 && VKeyObjFrame<=5)
				{
					float(_set,MissionLevel5,2);
				}
				elseif(VkeyObjFrame>=6 && VKeyObjFrame<=8)
				{
					float(_set,MissionLevel5,1);
				
				}
				elseif(VKeyObjFrame>=9 && VKeyObjFrame<=11)
				{
					float(_set,MissionLevel5,3);
				}
				elseif(VKeyObjFrame>=17 && VKeyObjFrame<=19)
				{
					float(_set,MissionLevel5,3);
				}
				elseif(VKeyObjFrame>=20 && VKeyObjFrame<=22)
				{
					float(_set,MissionLevel5,1);
				}
				elseif(VKeyObjFrame>=23 && VKeyObjFrame<=24)
				{
					float(_set,MissionLevel5,3);
				}
				else
				{
					float(_set,MissionLevel5,0);
				}

				CurEnvTrigger("AIM03");
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(Tmpfloat==TRUE)
				{
					call(ClrAllCollisionBuffers);
					float(_clr,Varbit01,Help17);
					if(MissionLevel5==1)
					{
						CurEnvTrigger("AIM01");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						float(_sub,Bringmeback,1);
						float(_clr,BobSound,Help04);
					}

					elseif(MissionLevel5==2)
					{
						CurEnvTrigger("AIM02");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						float(_sub,Bringmeback,1);
						CurEnvTrigger("ship01");
						call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
						float(_clr,BobSound,Help05);

					}
					elseif(MissionLevel5==3)
					{
						CurEnvTrigger("AIM03");
						call(ExplodeObject,TmpVector,2);
						callsub(Sub_ExplodeObjectHandler);
						float(_sub,Bringmeback,1);
						CurEnvTrigger("ship02");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
						float(_clr,BobSound,Help06);
					}
					float(_set,RadChecked3,1);
				}
			}
			else
			{
				if(Bringmeback>0 && RadChecked3==0)
				{
					float(_set,RadChecked3,1);
				}
				if(RadChecked3>=1)
				{
					float(_add,RadChecked3,1);
					if(RadChecked3>=1000)
					{
						CopyObjectToObject("dummy03","freightr");
						float(_set,RadChecked3,0);
						float(_or,Varbit01,Help17);
					}
				}
			}

			/////////////////////////
			// FORCEFIELD TRIGGERS //
			/////////////////////////
			CurEnvTrigger("pl01");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
			else
			{
				CurEnvTrigger("pl02");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				else
				{
					CurEnvTrigger("pl03");
					if(VTrigger==_DIREnvTrigger)
					{
						colstate(_or,_COLelectricity);
					}
					else
					{
						CurEnvTrigger("pl04");
						if(VTrigger==_DIREnvTrigger)
						{
							colstate(_or,_COLelectricity);
						}
						else
						{
							CurEnvTrigger("pl05");
							if(VTrigger==_DIREnvTrigger)
							{
								colstate(_or,_COLelectricity);
							}
							else
							{
								CurEnvTrigger("pl06");
								if(VTrigger==_DIREnvTrigger)
								{
									colstate(_or,_COLelectricity);
								}
								else
								{
									CurEnvTrigger("pl07");
									if(VTrigger==_DIREnvTrigger)
									{
										colstate(_or,_COLelectricity);
									}
									else
									{
										CurEnvTrigger("pl08");
										if(VTrigger==_DIREnvTrigger)
										{
											colstate(_or,_COLelectricity);
										}
										else
										{
											CurEnvTrigger("pl09");
											if(VTrigger==_DIREnvTrigger)
											{
												colstate(_or,_COLelectricity);
											}
											else
											{
												CurEnvTrigger("pl10");
												if(VTrigger==_DIREnvTrigger)
												{
													colstate(_or,_COLelectricity);
												}
												else
												{
													CurEnvTrigger("pl11");
													if(VTrigger==_DIREnvTrigger)
													{
														colstate(_or,_COLelectricity);
													}
													else
													{
														CurEnvTrigger("pl12");
														if(VTrigger==_DIREnvTrigger)
														{
															colstate(_or,_COLelectricity);
														}
														else
														{
															CurEnvTrigger("pl13");
															if(VTrigger==_DIREnvTrigger)
															{
																colstate(_or,_COLelectricity);
															}
															else
															{
																CurEnvTrigger("pl14");
																if(VTrigger==_DIREnvTrigger)
																{
																	colstate(_or,_COLelectricity);
																}
																else
																{
																	CurEnvTrigger("pl15");
																	if(VTrigger==_DIREnvTrigger)
																	{
																		colstate(_or,_COLelectricity);
																	}
																	else
																	{
																		CurEnvTrigger("pl16");
																		if(VTrigger==_DIREnvTrigger)
																		{
																			colstate(_or,_COLelectricity);
																		}
																		else
																		{
																			CurEnvTrigger("pl17");
																			if(VTrigger==_DIREnvTrigger)
																			{
																				colstate(_or,_COLelectricity);
																			}
																			else
																			{
																				CurEnvTrigger("pl17");
																				if(VTrigger==_DIREnvTrigger)
																				{
																					colstate(_or,_COLelectricity);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	
			if(DisablePickup!=0)
			{
				Direction(_clr,_DIRgrenade);
			}	
			///////////////////////////////////
			///		GUN TURRET SEQUENCE		///
			///////////////////////////////////

			//******** Initialize Sequence - press button *****************
			CurEnvTrigger("turret01");
			vector(_set,TmpVector,10,110,40);
			Call(TriggerBox,TmpVector,0,tmpfloat);
			if(tmpfloat==1 && VTrigger==_DIREnvTrigger)
			{
				if(VarBit01&=Help19)
				{
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						sample(SFXGoodDayCommander,-1);
						float(_clr,VarBit01,Help19);
					}
				}
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					if(HelpVar&=help09 && TutorialToggle==1 && InBattle==0)
					{
						float(_clr,HelpVar,Help09);
						ClearTutorialLines();
						AddTutorialLine("To activate the [20:250:50]GUN TURRET[255:255:255]@ press");
						AddTutorialLine("your [20:250:50]ACTION[255:255:255] button in front of the");
						AddTutorialLine("console.");
						AddTutorialLine(" ");
						AddTutorialLine("In the [20:250:50]GUN TURRET[255:255:255]@ press your");
						AddTutorialLine("[20:250:50]FIRE[255:255:255] button to shoot and aim with");
						AddTutorialLine("[20:250:50]UP[255:255:255] and [20:250:50]DOWN[255:255:255]. To rotate the turret");
						AddTutorialLine("press [20:250:50]LEFT[255:255:255] and [20:250:50]RIGHT[255:255:255].");
						AddTutorialLine(" ");
						AddTutorialLine("To exit the Gun Turret@ press your");
						AddTutorialLine("Action Key and the Gun Turret will");
						AddTutorialLine("reset to its original position.");
						AddTutorialLine(" ");
						AddTutorialLine("  [100:100:100]             Press Any Key        ");
						AddTutorialLine("  [100:100:100]             To Continue          ");
						DisplayTutorialScreen("[255:255:20]GUN TURRET[150:150:150]",15,15);
					}
				}
			
				if(VTrigger==_DIRaction && VKeyObjFrame==0 && DisablePickUp==0)
				{
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						if(VSniperMode!=0)
						{
							call(ChangeSniperMode,-2,0);
						}
						ActorFlag(_or,_AFLAGnobulletcollision|_AFlagNoTarget);
						call(ActivateButton,"Gun Turret Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						//if(AIAbility&=_AIAPickUpWeapon)
						//{
							call(CheckAttached,_CADropWeaponAndShells);
						//}
						call(PlayerInput,0);
						if(BobSound&=Help18)
						{
							CutScene("first");
							call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
							call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
						}
						float(_set,timer3,0);
						float(_set,DisablePickUp,1);
					}
					else
					{
						message("Only commanders can Operate This Unit.",200,10);
						sample(SFXAccessDenied,Gactorpos);
					}
				}
			}
			else
			{
				if(VarBit01&!=Help19)
				{
					float(_or,VarBit01,Help19);
				}
			}

			//******* Camera rotates - delay before Gun Turret animation starts ***********
			if(DisablePickUp==1)
			{
				float(_add,timer3,1);
				if(timer3>=40)
				{
					float(_set,BarmanTimer,0);
					vector(_set,Gactorpos,7863,-89,4741);
					sample(SFXGunTurretWrap,Gactorpos);
					CurEnvTrigger("turret01");
					call(KeyObjTrigger,10,1);
					CurEnvTrigger("turret02");
					call(KeyObjTrigger,10,1);
					CurEnvTrigger("barrel");
					call(KeyObjTrigger,1,1);
					float(_set,DisablePickUp,2);
					float(_set,timer3,0);
					direction(_clr,_DIRaction);
				}
			}

			//********** Domina gets into her "Tron" position *****************
			CurEnvTrigger("turret01");
			if(VKeyObjFrame==5 && DisablePickUp==2)
			{
				if(Vaction!=DominaGunInit)
				{
					sample(SFXTurretArmedCommander,-1);
					ActorFlag(_or,_AFLAGnobulletcollision);
					spawnaction(DominaGunInit);
					float(_set,DisablePickUp,3);
					direction(_clr,_DIRaction);
				}
			}
			
			if(BobSound&=Help18)
			{
				CurEnvTrigger("turret01");
				if(VKeyObjFrame==10 && VarBit01&=Help12)
				{
					//**** Have the ship approaching *******
					CurEnvTrigger("ship01");
					call(KeyObjTrigger,255,1);
					float(_clr,VarBit01,Help12);
					float(_set,timer2,1);			
				}

				//*** When ship goes out of FOV... ***********
				CurEnvTrigger("ship01");
				if(VKeyObjFrame==4 && timer2==1)
				{                                                                
					sample(SFXDominaWarning01,-1);
					float(_set,timer2,2);
				}
				if(VKeyObjFrame==6 && timer2==2)
				{
					sample(SFXDominaWarning02,-1);
					float(_set,timer2,3);
				}
				if(VKeyObjFrame==7 && timer2==3)
				{
					sample(SFXDominaWarning04,-1);
					float(_set,timer2,0);
				}
				if(VKeyObjFrame==9 && VarBit01&!=Help12)
				{
					if(VarBit01&=Help13)
					{
						CutScene("second");
						call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
						call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
						float(_clr,VarBit01,Help13);
						ClearDMessage();
						sample(SFXDominaWarning03,-1);
					}
				}

				if(VarBit01&!=Help13 && VarBit01&=Help14)
				{
					float(_add,BarmanTimer,1);
					if(BarmanTimer==50)
					{
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
						CurEnvTrigger("ship02");
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					}
					if(BarmanTimer>=110)
					{
						call(CutSceneEnd);
						float(_set,BarmanTimer,0);
						float(_clr,VarBit01,Help14);
					}
							
				}
				
				if(VarBit01&!=Help14)
				{
					CurEnvTrigger("turret01");
					call(KeyObjTrigger,10,1);
					CurEnvTrigger("turret02");
					call(KeyObjTrigger,10,1);
					float(_or,Varbit01,Help14);
					float(_clr,BobSound,Help18);			
				}
			}

			//*********** HUD change to ROCKET_HUD ********************
			if(VKeyObjFrame>=9 && DisablePickUp==3)
			{
				ActorFlag(_or,_AFLAGNoDepossession);
				if(VTrigger==_DIRHaveGun)
				{
					//if(AIAbility&=_AIAPickUpWeapon)
					//{
						call(CheckAttached,_CADropWeapon);
					//}
				}
				ActorFlag(_clr,_AFlagNoTarget);
				if(VCutScene==0)
				{
					CurEnvTrigger("turret01");
					call(KeyObjTrigger,13,1);
					CurEnvTrigger("turret02");
					call(KeyObjTrigger,13,1);
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("hull01");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					float(_set,SniperMode,1);
					call(ChangeSniperMode,1,1);
					CurEnvTrigger("barrel");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					setkeyframe("s2r5","barrel",4);
					if(VarKey15==0)
					{
						vector(_set,TmpVector,0,0,0);
						call(SniperKFObj,TRUE,TmpVector);
						float(_set,VarKey15,1);
					}
					float(_set,DisablePickUp,4);
				}
			}

			//******** Turn Collision On (to be explodable) on Turret ****************
			if(DisablePickUp==4 && VKeyObjFrame>=13)
			{
				Direction(_clr,_DIRgrenade);
				call(PlayerInput,1);
				ActorFlag(_or,_AFLAGnobulletcollision);
//				CurEnvTrigger("turret01");
//				call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);
//				CurEnvTrigger("turret02");
//				call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);			
				float(_set,DisablePickUp,5);
				float(_set,AIVisionToggle,0);
			}

			//******** Assign Special KFControl to Turret *******************
			if(DisablePickUp==5)
			{
				call(aichangeplayertoenemy);
				Direction(_clr,_DIRgrenade);
				CurEnvTrigger("turctrl");
				if(VTrigger==_DIREnvTrigger)
				{
					call(NoZoomExit,true);
					CurEnvTrigger("turret01");
					/*
					vector(_settoactorpos,Gactorpos);
					vector(_settokfpos,CharOffset,1);
					vector(_setx,CharOffset,TmpFloat);
					vector(_setx,Gactorpos,TmpFloat1);
					float(_sub,TmpFloat,TmpFloat1);
					move(TmpFloat,0,0);
					*/
					if(VKeyObjFrame==13 && VTrigger==_DIRleft)
					{
						setkeyframe("s2r5","turret01",26);
					}
					if(VKeyObjFrame==26 && VTrigger==_DIRright)
					{
						setkeyframe("s2r5","turret01",14);
					}
					if(VKeyObjFrame>=13)
					{
						if(VSniperMode==1 && CallBot!=1)
						{
							call(KeySpeed,13,26,0xaaa);
						}
						elseif(VSniperMode==2 && CallBot!=2)
						{
							call(KeySpeed,13,26,0x600);
						}
						elseif(VSniperMode==3 && CallBot!=3)
						{
							call(KeySpeed,13,26,0x200);
						}
						elseif(VSniperMode==4 && CallBot!=4)
						{
							call(KeySpeed,13,26,0x100);
						}
						call(KeyObjControl,_DIRleft,_DIRright,13,26,SFXGunTurretHorizontal);
						CurEnvTrigger("barrel");
						if(VSniperMode==1 && CallBot!=1)
						{
							call(KeySpeed,3,5,0xaaa);
							float(_set,CallBot,1);
						}
						elseif(VSniperMode==2 && CallBot!=2)
						{
							call(KeySpeed,3,5,0x600);
							float(_set,CallBot,2);
						}
						elseif(VSniperMode==3 && CallBot!=3)
						{
							call(KeySpeed,3,5,0x320);
							float(_set,CallBot,3);
						}
						elseif(VSniperMode==4 && CallBot!=4)
						{
							call(KeySpeed,3,5,0x200);
							float(_set,CallBot,4);
						}
						call(KeyObjControl,_DIRBackward,_DIRforward,3,5,SFXGunTurretVertical);
					}
					callsub(Sub_GunTurretHandler);
					if(VTrigger==_DIRaction)
					{
						CurEnvTrigger("turret01");
						call(KeyObjControl,0,0,-1,-1,SFXGunTurretHorizontal);	//force looping samples to stop
						CurEnvTrigger("barrel");
						call(KeyObjControl,0,0,-1,-1,SFXGunTurretVertical);		//force looping samples to stop

						call(PlayerInput,0);
						float(_set,DisablePickUp,6);
						direction(_clr,_DIRaction);
					}
				}
			}

			//******** Action Key has been pressed. Turret reset to original position **********
			if(DisablePickUp==6)
			{
				call(CheckAttached,_CASwapWeapon);
				CurEnvTrigger("Turret01");
				call(KeySpeed,13,26,0xfff);
				call(ChangeSniperMode,1,1);
				setkeyframe("s2r5","turret01",13);
				call(KeyObjTrigger,0,-1);
				CurEnvTrigger("turret02");
				call(KeyObjTrigger,0,-1);
				setkeyframe("s2r2","barrel",0);
				if(Freightimer==0)
				{
					CurEnvTrigger("hull01");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					CurEnvTrigger("hull02");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					CurEnvTrigger("hull03");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					CurEnvTrigger("hull04");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}
				elseif(Freightimer==1)
				{
					CurEnvTrigger("hull02");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					CurEnvTrigger("hull03");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					CurEnvTrigger("hull04");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}
				elseif(Freightimer==2)
				{
					CurEnvTrigger("hull03");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					CurEnvTrigger("hull04");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}
				elseif(Freightimer==3)
				{
					CurEnvTrigger("hull04");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}
				float(_set,DisablePickUp,7);
			}
			
			//******** Reset HUD to normal **************
			if(DisablePickUp==7)
			{
				ActorFlag(_clr,_AFLAGNoDepossession);
				CurEnvTrigger("Turret01");
				if(VKeyObjFrame==9)
				{
					float(_set,SniperMode,0);
					call(NoZoomExit,false);
					call(ChangeSniperMode,0,1);
					CurEnvTrigger("turret02");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("barrel");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					if(VarKey15!=0)
					{
						vector(_set,TmpVector,0,0,0);
						call(SniperKFObj,FALSE,TmpVector);
						float(_set,VarKey15,0);
					}
					float(_set,DisablePickUp,8);
					
					if(VAICon==0)
					{
						SamplePlaying(SFXGunTurretDoor,-1);
						if(VTrigger!=_DIRTempFlag)
						{
							sample(SFXGunTurretDoor,-1);
						}
					}
				}
			}

			//******* Domina gets back into an idle **************
			if(DisablePickUp==8)
			{
				CurEnvTrigger("turret01");
				if(VKeyObjFrame==0)
				{
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						if(Vaction!=GenIdle)
						{
							spawnaction(GenIdle);
							call(PlayerInput,1);
							if(VAICon==0)
							{
								ActorFlag(_clr,_AFLAGnobulletcollision|_AFLAGnorotation|_AFlagNoTarget);
								call(CheckForPickup,12,_ClassWeapon);
							}
							float(_set,DisablePickUp,0);
						}
					}
				}
			}
		}
	}
	elseif(VCurSet=="s2r9b")
	{
		if(VAICon==0)
		{
			if(Res03&=Help01)
			{
				call(CDForcePlay,true);
				float(_clr,Res03,Help01);
			}
			if(VLanguage==0)
			{
				call(CDSwap,12,1,100,60);
			}
			elseif(VLanguage==1 || VLanguage==3)
			{
				call(CDSwap,18,1,100,60);
			}
			elseif(VLanguage==2 || VLanguage==4)
			{
				call(CDSwap,20,1,100,60);
			}
			CurEnvTrigger("powon");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit&=Help09)
				{
					call(ActivateButton,"Lift Power is On",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					CurEnvTriggerSet("s2r9","panel1");
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
					CurEnvTriggerSet("s2r9","doorup");
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);

					vector(_set,Gactorpos,9865,368,14694);
					vector(_set,Gactorangle,0,1115,0);
					InitActor(copl,Gactorpos,Gactorangle,"S2R9",TRUE,50);
					InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"S2R9");

					float(_clr,VarBit01,Help09);
				}
				else
				{
					call(ActivateButton,"Lift Power already restored",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				direction(_clr,_DIRaction);
			}
		}
	}
	elseif(VCurSet=="s2r14")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("trigdoor");
			if(VTrigger==_DIREnvTrigger && ControlTimer==0 && VKeyObjTriggered==0)
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
				CurEnvTrigger("trigdoor")
				if(VSetActive=="s2r15")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r14","trigdoor",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
				
	elseif(VCurSet=="s2r15")
	{
		if(VAICon==0)
		{
			float(_add,timer4,1);
			if(timer4>=250)
			{
				GetNumbActorsInSet("s2r15",_AIClassAnimal,TmpFloat);
				GetNumbActorsInSet("s2r21",_AIClassAnimal,TmpFloat1);
				float(_add,TmpFloat,TmpFloat1);
				if(TmpFloat<=1)
				{
					vector(_set,Gactorpos,8654, 1138, 11077);
					vector(_set,Gactorine,0,0,0);
					initactor(rat,Gactorpos,Gactorine,"s2r21",TRUE,1);
				}
				float(_set,timer4,0);
			}
			if(BobSound&=Help03 && VAIcon==0)
			{
				CurEnvTrigger("ratsound");
				if(VAIClass==_AIClassAngel && VTrigger==_DIREnvTrigger)
				{
					sample(SFXBobEuchRats,-1);
					float(_clr,BobSound,Help03);
				}
			}
			
			CurEnvTrigger("calllft");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				CurEnvTrigger("liftup");
				if(VKeyObjTriggered==0 && VKeyObjFrame==1)
				{
					call(ActivateButton,"Lift Called - Please Wait",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,0,-1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
				else
				{
					call(ActivateButton,"Lift Is Already On That Floor",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				direction(_clr,_DIRaction);
			}					
					

			CurEnvTrigger("trigdoor");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
			{
				message("Door Locked From Inside",120,10);
				sample(SFXAccessDenied,Gactorpos);
				direction(_clr,_DIRaction);
			}

			CurEnvTrigger("liftup");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction && VKeyObjTriggered==0 && VKeyObjFrame==0)
				{
					call(ActivateButton,"Lift Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				if(VState==StateJustActivated)
				{
					call(KeyObjTrigger,1,1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
				direction(_clr,_DIRaction);
			}
			if(VKeyObjTriggered==0)
			{
				CurEnvTrigger("doorup");
				if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					callsub(DoorOpen,1,1);
				}
			}
			
			CurEnvTrigger("liftdown");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				CurEnvTrigger("liftup");
				if(VKeyObjTriggered==0 && VKeyObjFrame==1)
				{
					call(ActivateButton,"Lift Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,0,-1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
				direction(_clr,_DIRaction);
			}

			CurEnvTrigger("button");
			if(BobSound&=Help11)
			{
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					float(_clr,Bobsound,Help11);
				}
			}
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(BobSound&=Help11)
				{
					if(Bobsound&=Help10)
					{
						call(ActivateButton,"Platform Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						float(_set,TmpFloat,0xff5500);
						call(expset1,1,TmpFloat,0);
						call(AIChangePlayerToEnemy);
						float(_set,CommandTimer,0);
						float(_clr,BobSound,Help10);
						float(_set,VarKey11,1);
					}
					else
					{
						call(ActivateButton,"Platform Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				else
				{
					if(VarKey11==0)
					{
						call(ActivateButton,"Platform Destroyed - Laser Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
						float(_set,VarKey11,1);
					}
					else
					{
						call(ActivateButton,"Laser Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}		
				direction(_clr,_DIRaction);
			}

			if(BobSound&!=Help10)
			{
				float(_add,CommandTimer,1);
				if(CommandTimer<=100)
				{
					if(CommandTimer&=1)
					{
						CurEnvTrigger("button");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					}
					else
					{
						CurEnvTrigger("button");
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					}
				}
				elseif(Commandtimer==101)
				{
					CurEnvTrigger("button");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(ClrAllCollisionBuffers);
					float(_set,TmpFloat,0xffffff);
					call(expset1,1,TmpFloat,0);
				}
				elseif(CommandTimer<=250)
				{
					CurEnvTrigger("button");
					float(_set,TmpFloat,0xff5500);
					call(expset1,1,TmpFloat,0);
				}
				elseif(CommandTimer<=255)
				{
					if(CommandTimer&=1)
					{
						CurEnvTrigger("button");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					}
					else
					{
						CurEnvTrigger("button");
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					}
				}
				elseif(CommandTimer==256)
				{
					CurEnvTrigger("button");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					call(ClrAllCollisionBuffers);
					float(_set,TmpFloat,0xffffff);
					call(expset1,1,TmpFloat,0);
				}
				elseif(CommandTimer==270)
				{
					float(_or,BobSound,Help10);
					float(_set,CommandTimer,0);
				}
			}
		}

		CurEnvTrigger("fin");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAICon!=0)
			{
				if(vstate!=StateCrawling)
				{
					state(_or,StateCrawling)
					state(_clr,StateExecuteAnim);
					//if(AIAbility&=_AIAPickUpWeapon)
					//{
						call(CheckAttached,_CADropWeaponAndShells);
					//}
					CallSub(Sub_ChangeStateToNormal);
					call(subtracthealth,0,30000);

					fxflag(_or,_fxFLAGFire);			//just for effectx
					//state(_or,StateOnFire);			//for real

					float(_set,VarKey11,1);
					float(_set,timer3,0);
				}
			}
			else
			{
				call(subtracthealth,0,30000);
				direction(_clr,_DIRalive);
			}
		}
	}
	elseif(VCurSet=="s2r17")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("laserin");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
			CurEnvTrigger("laserout");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
			CurEnvTrigger("nodepo1");
			if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassAnimal)
			{
				ActorFlag(_or,_AFLAGNoDepossession);
			}
			else
			{
				if(VFirstPerson!=0)
				{
					ActorFlag(_or,_AFLAGNoDepossession);
				}
				else
				{
					ActorFlag(_clr,_AFLAGNoDepossession);
				}
			}
			if(VAIClass==_AIClassAnimal)
			{
				CurEnvTrigger("Panmeup");
				vector(_set,TmpVector,445,50,135);
				Call(TriggerBox,TmpVector,0,tmpfloat);
				if(tmpfloat==1 && VTrigger==_DIREnvTrigger)
				{
					FirstPerson(0);				
				}
				else
				{
					FirstPerson(1);
				}
				if(VFirstPerson==0)
				{
					camera(20,250);
					target(-50,0);
					call(MouseLookToggle,0);
				}
			}
			else
			{
				call(MouseLookToggle,1);
			}
			float(_add,VictimTimer,1);
			if(VictimTimer>=500)
			{
				//GetNumbActorsInSet("s2r17",_AIclassanimal,TmpFloat);
				call(GetNumbActorsInCurrentSet,TmpFloat,_AIclassanimal);
				if(TmpFloat<2)
				{
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,8548,1146,11174);
					initactor(rat,Gactorpos,Gactorangle,"s2r17",FALSE);
				}
			}
		}
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="s2r19")
	{
		if(VAICon==0)
		{
			if(HelpVar&=Help12)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,7);
				callsub(Panel7);
				ClearDMessage();
				float(_clr,HelpVar,Help12);
			}

			CurEnvTrigger("doorup");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{

				message("Area Closed For Safety Reasons",200,10);
				sample(SFXAccessDenied,Gactorpos);
				/*
				if(VSetActive!="s2r9" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("doorup")
				if(VSetActive=="s2r9")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r19","doorup",1);
					call(KeyObjTrigger,255,1);
				}
				*/
			}
			if(VKeyObjTriggered==0)
			{
				float(_set,TmpFloat,0xff0000);
				call(expset1,1,TmpFloat,0);
			}

			//******* HAND BOX **********	
			vector(_set,Gactorpos,7386,1144,11917);
			CurEnvTrigger("handfx01");
			if(VTrigger==_DIREnvTrigger || Explode02!=0)
			{
				callsub(HandBox,200,Explode02);
			}
		}
		//******************** Activate the DefenseBot sequence **************
		CurEnvTrigger("Bot01");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAIClass==_AIClassCop && VRank==_RankCommander)
			{
				if(VarKey18==0)
				{
					call(ActivateButton,"Offensive Bot Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,TmpFloat,0x0000ff);
					call(expset1,1,TmpFloat,0);
					float(_set,VarKey18,1)
				}
				else
				{
					call(ActivateButton,"Bot Already Activated",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
			else
			{
				call(ActivateButton,"Commanders Only",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}				
		}
		
		//******************* Activate the Companion Bot sequence ***************
		CurEnvTrigger("Bot02");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAIClass==_AIClassCop && VRank==_RankCommander)
			{
				if(VarKey18==0)
				{
					call(ActivateButton,"Companion Bot Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,TmpFloat,0x0000ff);
					call(expset1,1,TmpFloat,0);
					float(_set,VarKey18,2)
				}
				else
				{
					call(ActivateButton,"Bot Already Activated",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
			else
			{
				call(ActivateButton,"Commanders Only",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}				
		}

		//*********** Spawn Offensive Bot OR Companion Bot ************
		if(VarKey18>0 && VarKey18<3)
		{
			call(PlayerInput,0);
			CurEnvTrigger("botctrl")
			call(KeyObjTrigger,255,1);
			vector(_set,Gactorangle,0,0,0);
			vector(_set,Gactorpos,7855,450,11882);
			if(VarKey18==1)
			{
				InitActor(OffensiveBot,Gactorpos,Gactorangle,"s2r19");
				float(_set,VarKey18,3);
			}
			elseif(VarKey18==2)
			{
				InitActor(CompanionBot,Gactorpos,Gactorangle,"s2r19");
				float(_set,VarKey18,4);
			}
			direction(_clr,_DIRaction);
		}
	
		//********* Moves the camera over to the Bot Box *************
		CurEnvTrigger("botctrl");
		if(VKeyObjFrame==3 && VarKey18==3)
		{
			if(HelpVar&=help07)
			{
				call(ExpSet2,45,1,1);
			}
			float(_set,VarKey18,5);
			float(_set,timer3,0);
		}

		if(VKeyObjFrame==3 && VarKey18==4)
		{
			if(HelpVar&=help08)
			{
				call(ExpSet2,45,1,1);
			}
			float(_set,VarKey18,6);
			float(_set,timer3,0);
		}

		//************** Display Tutorial lines *************
		if(VarKey18==5)
		{
			float(_add,timer3,1)
			if(HelpVar&=help07)
			{
				if(timer3==50)
				{
					float(_xor,HelpVar,help07);
					ClearTutorialLines();
					AddTutorialLine("Seeks out enemies of the [250:250:0]Bot's Operator.");
					AddTutorialLine("[10:50:200]Bot[255:255:255] will fire at any attacker.");
					AddTutorialLine(" ");
					AddTutorialLine("To activate the [10:50:200]Bot[255:255:255] just walk past it");
					AddTutorialLine("and it will attach itself to you.");
					AddTutorialLine(" ");
					AddTutorialLine("  [100:100:100]             Press Any Key        ");
					AddTutorialLine("  [100:100:100]             To Continue          ");
					DisplayTutorialScreen("[255:255:20]OFFENSIVE BOT [150:150:150]Attack Class",15,15);
				}
			}
			if(timer3>=55)
			{
				call(PlayerInput,1);
				float(_set,timer3,0);
				float(_set,VarKey18,7);
			}
		}

		if(VarKey18==6)
		{
			float(_add,timer3,1)
			if(HelpVar&=help08)
			{
				if(timer3==50)
				{
					float(_xor,HelpVar,help08);
					ClearTutorialLines();
					AddTutorialLine("Provides additional firepower during a confrontation. ");
					AddTutorialLine("Fires only while [20:250:50]Bot Operator[255:255:255] is pressing his [20:250:50]FIRE[255:255:255] button.");
					AddTutorialLine(" ");
					AddTutorialLine("To activate the [20:250:50]Bot[255:255:255] just walk past it and it will");
					AddTutorialLine("attach itself to you.");
					AddTutorialLine(" ");
					AddTutorialLine("  [100:100:100]             Press Any Key        ");
					AddTutorialLine("  [100:100:100]             To Continue          ");
					DisplayTutorialScreen("[255:255:20]COMPANION BOT [150:150:150]Support Class",15,15);
				}
			}
			if(timer3>=55)
			{
				call(PlayerInput,1);
				float(_set,timer3,0);
				float(_set,VarKey18,7);
			}
		}
	}
	elseif(VCurSet=="s2r21")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("secsplit");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
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
				CurEnvTrigger("secsplit")
				if(VSetActive=="s2r17")
				{
					callsub(DoorOpen,1,1);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(ClrAllCollisionBuffers);
					float(_set,ControlTimer,0);
				}
				else
				{
					direction(_clr,_DIRMovebits|_DIRleft|_DIRRight);
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r21","secsplit",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="s2r25")
	{
		if(VAICon==0)
		{
			if(Res03&!=Help01)
			{
				call(CDForcePlay,false);
				float(_or,Res03,Help01);
			}
			call(CDSwap,2,1,100,60);
			CurEnvTrigger("doorup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					call(ForceLoadSet,"s2r4");
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			
			if(ControlTimer==1)
			{
				CurEnvTrigger("doorup")
				if(VSetActive=="s2r3");// && VSetInMemory=="s2r4")
				{
					callsub(DoorOpen,1,1);
					float(_clr,VarBit,Help01);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r25","doorup",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="s2r9c")
	{
		if(VAICon==0)
		{
			if(Res03&!=Help01)
			{
				call(CDForcePlay,false);
				float(_or,Res03,Help01);
			}
			call(CDSwap,2,1,100,60);
		}
		if(VarBit01&=Help10)
		{
			CurEnvTrigger("elecout");
			if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassDroid)
			{
				colstate(_or,_COLelectricity);
			}
		}

		CurEnvTrigger("trigdoor");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				if(VarBit01&=Help10)
				{
					call(ActivateButton,"Plasma Wall is Off",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					vector(_set,Gactorpos,5175,749,16499);
					samplestop(SFXScanHumm,Gactorpos);
					CurEnvTrigger("arme01");
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					float(_clr,VarBit01,Help10);
				}				
				else
				{
					call(ActivateButton,"Plasma Wall is On",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					vector(_set,Gactorpos,5175,749,16499);
					sample(SFXScanHumm,Gactorpos);
					CurEnvTrigger("arme01");
					call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					float(_or,VarBit01,Help10);
				}
				direction(_clr,_DIRaction);
			}

		}

		if(WeaponDelay02>=1)
		{
			float(_add,WeaponDelay02,1)
			if(WeaponDelay02>=80)
			{
				CurEnvTrigger("arme01");
				vector(_set,Gactorpos,5540,618,16863);
				vector(_set,Gactorangle,0,2048,0);
				InitActor(WeaponBazooka,Gactorpos,Gactorangle,"s2r9c",TRUE);
				call(KeyObjTrigger,255,1);
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);
				float(_set,WeaponDelay02,0);
			}
		}

		if(WeaponDelay03>=1)
		{
			float(_add,WeaponDelay03,1)
			if(WeaponDelay03>=80)
			{
				CurEnvTrigger("arme02");
				vector(_set,Gactorpos,5907,618,16498);
				vector(_set,Gactorangle,0,0,0);
				InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"s2r9c",TRUE);
				call(KeyObjTrigger,255,1);
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);
				float(_set,WeaponDelay03,0);
			}
		}	

		CurEnvTrigger("arme01");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,WeaponDelay02,1);
				}
				else
				{
					if(VAICON==0)
					{
						call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
			}
			else
			{
				if(VAICON==0)
				{
					call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}
		CurEnvTrigger("arme02");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,WeaponDelay03,1);
				}
				else
				{
					if(VAICON==0)
					{
						call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
			}
			else
			{
				if(VAICON==0)
				{
					call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}
	}
	elseif(VCurSet=="s2r9a")
	{
		if(VArBit01&=Help10)
		{
			CurEnvTrigger("fake");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);

			CurEnvTrigger("elecin");
			if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassDroid)
			{
				colstate(_or,_COLelectricity);
			}
		}
		else
		{
			CurEnvTrigger("fake");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
		}
		if(VAICon!=0)
		{
			if(VAIClass==_AIClassChot && VPathID==1)
			{
				if(VAIStatehigh!=_AIcombatmodereact && VAIStatehigh!=_AIcloseupaction)
				{
					float(_add,punchtimer,1);
					if(VTrigger!=_DIRCombatMode)
					{
						direction(_or,_DIRCombatMode);
					}
					if(punchtimer>=80)
					{
						direction(_clr,_noDIR);
						direction(_or,_DIRshoot);
					}
					if(punchtimer>=100)
					{
						float(_set,punchtimer,0);
					}
				}
			}
		}
	}
	elseif(VCurSet=="s2r16b")
	{
		if(VAICon==0)
		{
			if(HelpVar&=Help11)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,6);
				callsub(Panel6);
				ClearDMessage();
				float(_clr,HelpVar,Help11);
			}
		}
	}
	elseif(VCurSet=="s2r16")
	{
		if(VAICon==0)
		{
			if(VAIClass==_AIclassAnimal)
			{
				CurEnvTrigger("Disable2");
				if(VTrigger==_DIREnvTrigger)
				{
					ActorFlag(_or,_AFLAGNoDepossession);
				}
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

			call(MouseLookToggle,1);
			if(VAIClass==_AIClassAnimal)
			{
				if(VFirstPerson!=1)
				{
					FirstPerson(1);
				}
			}
			//******* HAND BOX **********	
			vector(_set,Gactorpos,9256,848,13020);
			CurEnvTrigger("handfx01");
			callsub(HandBox,200,Explode02);
			//***************************
		}
	}
	elseif(VCurSet=="s2r20")
	{
		if(VAICon==0)
		{
			Curenvtrigger("opwindow");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && BobSound&=Help12)
			{
				CurEnvTriggerSet("s2r22","window");
				if(VKeyObjTriggered==0 && VKeyObjFrame==0)
				{
					call(KeyObjTrigger,255,1);
				}
			}
			if(PakFly!=0)
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);					
			}
			elseif(VState==StateInAir)
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);				
			}
			else
			{
				callsub(Sub_SetCameraNormal);
			}

			if(BobSound&=Help12 && Varbit01&=Help06)
			{
				CurEnvTrigger("TRIGSHOWR");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VState!=StateFalling && VState!=StateFlying && VState!=StateGliding && VState!=StateJump)
					{
						CurEnvTriggerSet("s2r29","doorup");
						call(expset1,230,652,652);
						if(VAIClass==_AIClassAngel)
						{
							sample(SFXBobNaked,-1);
						}
						else
						{
							sample(SFXCopOhYeah,-1);
						}
						float(_clr,BobSound,Help12);
					}
				}
			}
			if(IsDead==100 && BobSound&!=Help12)
			{
				float(_add,timer3,1)
				if(timer3>=90)
				{
					CurEnvTriggerSet("s2r22","window");
					call(KeyObjTrigger,255,1);
					CurEnvTriggerSet("s2r29","doorup");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,6518, -580, 10050);
					initactor(GunCommander,Gactorpos,Gactorangle,"s2r22",TRUE,4);
					float(_set,timer3,0);
					float(_set,IsDead,0);
					float(_or,BobSound,Help12);
				}
			}
		}
	}
	elseif(VCurSet=="s2r24")
	{
		if(VarBit01&!=Help24)
		{
			float(_or,VarBit01,Help24);
		}

		if(VAICon==0)
		{
			if(Res03&=Help01)
			{
				call(CDForcePlay,true);
				float(_clr,Res03,Help01);
			}
			if(VLanguage==0)
			{
				call(CDSwap,5,1,100,60);
			}
			elseif(VLanguage==1 || VLanguage==3)
			{
				call(CDSwap,22,1,100,60);
			}
			elseif(VLanguage==2 || VLanguage==4)
			{
				call(CDSwap,23,1,100,60);
			}
			CurEnvTrigger("door1");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
				}
				else
				{
					float(_set,TmpFloat,0xff0000);
					call(expset1,1,TmpFloat,0);
				}
				if(VTrigger==_DIRaction && VKeyObjTriggered==0)
				{				
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						callsub(DoorOpen,1,1);
					}
					else
					{
						message("Access Restricted to Commanders",120,10);
						sample(SFXAccessDenied,Gactorpos);
						direction(_clr,_DIRaction);
					}
				}
			}
			else
			{
				if(VKeyObjTriggered==0)
				{
					float(_set,TmpFloat,0xff0000);
					call(expset1,1,TmpFloat,0);
				}
			}
			
			CurEnvTrigger("doorc");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
				}
				else
				{
					float(_set,TmpFloat,0xff0000);
					call(expset1,1,TmpFloat,0);
				}
				if(VTrigger==_DIRaction && VKeyObjTriggered==0)
				{				
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						callsub(DoorOpen,1,1);
					}
					else
					{
						message("Access Restricted to Commanders",120,10);
						sample(SFXAccessDenied,Gactorpos);
						direction(_clr,_DIRaction);
					}
				}
			}
			else
			{
				if(VKeyObjTriggered==0)
				{
					float(_set,TmpFloat,0xff0000);
					call(expset1,1,TmpFloat,0);
				}
			}
		}
	}
	elseif(VCurSet=="s2r23")
	{
		if(VAICon==0)
		{
			if(Res03&!=Help01)
			{
				call(CDForcePlay,false);
				float(_or,Res03,Help01);
			}

			call(CDSwap,2,1,100,60);
			CurEnvTrigger("doorc");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
				}
				else
				{
					float(_set,TmpFloat,0xff0000);
					call(expset1,1,TmpFloat,0);
				}
				if(VTrigger==_DIRaction)
				{				
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						if(VTrigger==_DIRaction && ControlTimer==0)
						{
							float(_set,ControlTimer,4);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
						}
					}
					else
					{
						message("Access Restricted to Commanders",120,10);
						sample(SFXAccessDenied,Gactorpos);
						direction(_clr,_DIRaction);
					}
				}
			}
			else
			{
				float(_set,TmpFloat,0xff0000);
				call(expset1,1,TmpFloat,0);
			}
			
			if(ControlTimer==4)
			{
				CurEnvTrigger("doorc")
				if(VSetActive=="s2r24")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r23","doorc",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="s2r22")
	{
		if(VAICon==0)
		{
			if(Res03&!=Help01)
			{
				call(CDForcePlay,false);
				float(_or,Res03,Help01);
			}
			CurEnvTrigger("window");
			if(VKeyObjFrame!=0 && VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,0,-1);
			}
			call(CDSwap,2,1,100,60);
			if(VarBit01&=Help18)
			{
				CurEnvTrigger("hidden");
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					vector(_set,gactorpos,6722,-590,9196);
					samplestop(SFXLaserAmbient,Gactorpos);
					CurEnvtrigger("hidden");
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					float(_clr,VarBit01,Help18);
				}
				
				CurEnvTrigger("elec");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}			
			}

			CurEnvTrigger("door1");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(VTrigger==_DIRaction && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("door1")
				if(VSetActive=="s2r24")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r22","door1",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("hidden");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(BobSound&=Help15)
				{
					call(ActivateButton,"Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,7197,-503,9754);
					initactor(WeaponBazooka,Gactorpos,Gactorangle,"s2r22");
					callsub(DoorOpen,2,1);
					float(_clr,BobSound,Help15);
				}
				else
				{
					call(ActivateButton,"Dispenser Already Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
			}
		}
	}
	elseif(VCurSet=="s2r18")
	{
		if(BattleTimer>=280)
		{
			//SAXS say NO!!! Msika say YES!!!
			if(VAIClass==_AIClassCop && VAICon!=0 && BattleTimer<400)
			{
				if(VPathID==18 || VPathID==19)
				{
					if(VTrigger!=_DIRCombatMode)
					{
						direction(_or,_DIRCombatMode);
					}
				}
			}
		}
		if(VAICon==0)
		{
			if(BattleTimer==200)
			{
				if(VAIClass==_AIClassAngel)
				{
					sample(SFXBobDark,-1);
				}
				else
				{
					sample(SFXExplosionReact,-1);
				}
				call(DeleteEntitiesAndActorsInSet,"s2r8");
				call(DeleteEntitiesAndActorsInSet,"s2r9");
			}
		}
		else
		{
			if(VAICLass==_AIClassCop && VRank==_RankSergeantM)
			{
				CurEnvTrigger("unlock");
				if(VKeyObjTriggered!=0)
				{
					ActorFlag(_or,_AFlagNoAI);
				}
				else
				{
					ActorFlag(_clr,_AFlagNoAI);
				}
			}
		}
		if(BattleTimer>=400)
		{
			if(HelpVar&=Help14)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,8);
				callsub(Panel8);
				ClearDMessage();
				float(_clr,HelpVar,Help14);
			}

			GetNumbActorsInSet("s2r8",_AIclasscop,TmpFloat);
			if(TmpFloat==0)
			{
				GetNumbActorsInSet("s2r7",_AIclasscop,TmpFloat);
				if(TmpFloat==0)
				{
					GetNumbActorsInSet("s2r18",_AIclasscop,TmpFloat);
					if(TmpFloat==0)
					{
						if(timer==0)
						{
							float(_rnd2,timer,1200);
						}
						elseif(timer>1)
						{
							float(_sub,timer,1);
						}
						else
						{
							CurEnvTrigger("UnLock");
							if(VKeyObjTriggered==0);
							{
								float(_set,timer,0);
								Call(KeyObjTrigger,255,1);
							}
						}
					}
					else
					{
						float(_set,timer,0);
//						break(tmpfloat,1);
						//NEEDFIXIN -- always getting in here cuz of throw bug.
					}
				}
				else
				{
					float(_set,timer,0);
//					break(tmpfloat,2);
				}
			}
			else
			{
				float(_set,timer,0);
//				break(tmpfloat,3);
			}
		}
 

		//JOECODE
		if(VAICon==0)
		{
			CurEnvTrigger("doortank");
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
				CurEnvTrigger("doortank")
				if(VSetActive=="s2r5")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r18","doortank",1);
					call(KeyObjTrigger,255,1);
				}
			}

			if(BattleTimer<150 && BattleTimer>0)
			{
				float(_add,BattleTimer,1);
			}
			elseif(BattleTimer==150)
			{
				CurEnvTrigger("Flic");
				Call(expset1,15,15,178);
				float(_add,BattleTimer,1);
				//FIXTHIS
				sample(SFXBattlFin,-1);
			}
		}

		CurEnvTrigger("Unlock");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(Gate4Unlocked==0)
			{
				call(ActivateButton,"Gate 4 Unlocked",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				float(_set,Gate4Unlocked,1);
				CurEnvTrigger("door57");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				CurEnvTriggerSet("s2r8","dooropen");
				call(expset1,1,TmpFloat,0);
				CurEnvTriggerSet("s2r8","door78");
				call(expset2,1,TmpFloat,0);

			}
			else
			{
				call(ActivateButton,"Gate 4 Locked",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				float(_set,Gate4Unlocked,0);
				CurEnvTrigger("door57");
				float(_set,TmpFloat,0xff0000);
				call(expset1,1,TmpFloat,0);
			}
			direction(_clr,_DIRaction);
		}
		if(VAICon==0)
		{
			CurEnvTrigger("door45a");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(crossroads==0)
					{
						message("Door Cannot Be Operated",200,10);
						sample(SFXAccessDenied,Gactorpos);
					}
					else
					{
						callsub(DoorOpen,2,1);
					}
				}		
			}
			CurEnvTrigger("Door57");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				if(Gate4Unlocked==1)
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
					message("Access Denied. Door Is Locked",120,10);
					sample(SFXAccessDenied,Gactorpos);
				}
			}
			
			if(ControlTimer==2)
			{
				CurEnvTrigger("door57")
				if(VSetActive=="s2r7")
				{
					callsub(DoorOpen,1,1);
					if(StreetCorpses==0)
					{			
						float(_set,StreetCorpses,1);
					}
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s2r18","door57",1);
					call(KeyObjTrigger,255,1);
					float(_set,StreetCorpses,1);
				}
			}
		}
	}
	if(VSetActive=="s2r13")
	{
		if(VAICon==0)
		{
			//******** If a victim has been killed, spawn another one **********
			GetNumbActorsInSet("s2r13",_AIclassEvil,TmpFloat);
			if(TmpFloat<7)
			{
				float(_add,VictimTimer,1);
				if(VictimTimer>=80);
				{
					vector(_set,Gactorpos,6992,1276,9612);
					vector(_set,Gactorangle,0,2048,0);
					float(_rnd2,TmpFloat1,10);
					if(TmpFloat1<5)
					{
						InitActor(victimmale,Gactorpos,Gactorangle,"s2r13",TRUE,2);
					}
					else(TmpFloat1>=5)
					{
						InitActor(victimfemale,Gactorpos,Gactorangle,"s2r13",TRUE,2);
					}
					float(_set,VictimTimer,0);
				}
			}
		}

		CurEnvTriggerSet("s2r13","killme");
		if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIclassEvil)
		{
			call(KeyObjTrigger,255,1);
		}
		if(VKeyObjFrame>=1)
		{
			if(VTrigger==_DIREnvTrigger && VAIClass==_AIclassEvil)
			{
				vector(_set,Gactorpos,5160,1301,9595);
				sample(SFXSewerPile1,Gactorpos);
				vector(_set,tmpvector,255,255,255);
				spawnlight(flash_light,-1,Gactorpos,emptyvector,emptyVector,500);
				KillActor();
			}
		}
	}
	
	if(VSetActive=="s2r8")
	{
		if(VAICon==0)
		{
			if(StreetCorpses>=1)
			{
				CurEnvTriggerSet("s2r8","door78");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				CurEnvTriggerSet("s2r8","dooropen");
				float(_set,TmpFloat,0x00ff00);
				call(Expset2,1,TmpFloat,0);
				CurEnvTriggerSet("s2r8","LAZERWALL");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
			}

			if(Crossroads==0 && VarKey12==0)
			{
				GetNumbActorsInSet("s2r8",_AIClassCop,TmpFloat1);
				GetNumbActorsInSet("s2r9",_AIClassCop,TmpFloat2);
				float(_add,TmpFloat1,TmpFloat2);
				if(VAIClass==_AIClassCop)
				{
					if(TmpFloat1==1)
					{
						float(_set,VarKey12,1);
						float(_set,BarmanTimer,0);
					}
				}
				else
				{
					if(TmpFloat1==0)
					{
						float(_set,VarKey12,1);
						float(_set,BarmanTimer,0);
					}
				}
			}
			//*** COP RESPAWN WITH RANDOM WEAPONS. WAVE OF THREE (2 SECONDS INTERVAL) ***
			if(VarKey12==1)
			{
				float(_add,BarmanTimer,1);
				if(BarmanTimer==250)
				{
					vector(_set,Gactorpos,11517,150,14606);
					vector(_set,Gactorangle,0,2048,0);
					float(_rnd2,TmpFloat,6);
					if(TmpFloat<1)
					{
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<2)
					{
						InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<3)
					{
						InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<4)
					{
						InitActor(WeaponMaimer,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<5)
					{
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"S2r8");
					}
					vector(_set,Gactorpos,11517,100,14606);
					InitActor(copl,Gactorpos,Gactorangle,"S2r8",TRUE,51);
				}
				elseif(BarmanTimer==350)
				{
					vector(_set,Gactorpos,11517,150,14606);
					vector(_set,Gactorangle,0,2048,0);
					float(_rnd2,TmpFloat,6);
					if(TmpFloat<1)
					{
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<2)
					{
						InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<3)
					{
						InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<4)
					{
						InitActor(WeaponMaimer,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<5)
					{
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"S2r8");
					}
					vector(_set,Gactorpos,11517,100,14606);
					InitActor(copl,Gactorpos,Gactorangle,"S2r8",TRUE,51);
				}
				elseif(BarmanTimer>=500)
				{
					vector(_set,Gactorpos,11517,150,14606);
					vector(_set,Gactorangle,0,2048,0);
					float(_rnd2,TmpFloat,6);
					if(TmpFloat<1)
					{
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<2)
					{
						InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<3)
					{
						InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<4)
					{
						InitActor(WeaponMaimer,Gactorpos,Gactorangle,"S2r8");
					}
					elseif(TmpFloat<5)
					{
						InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"S2r8");
					}
					vector(_set,Gactorpos,11517,100,14606);
					InitActor(copl,Gactorpos,Gactorangle,"S2r8",TRUE,51);
					float(_set,VarKey12,0);
					float(_set,BarmanTimer,0);
				}
			}
		}
	}
	float(_add,FirstTimeRun,1);
}
