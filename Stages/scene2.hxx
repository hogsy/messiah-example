
//VarKey1	- Unlock doors in Sector 1
//VarKey2	- Battery Cell manager
//VarKey3	- LaserGrid off timer s1r2
//VarKey4	- LaserGrid off timer s1r3
//VarKey5	- LaserGrid off timer s1r8
//VarKey6	- fan positions s1r12
//VarKey7	- elevator up or down in S1r3
//VarKey8	- Counter for intensified globe in S1r3
//VarKey9	-	Chot Counter in S1r5
//VarKey10	- breaks the sequence in S1r3



//LiteCounter - Counter for lights display in s1r10
//RadiationGlow - RadDirection : Bob glowing fader in s1r13,s1r14,s1r23
//MissionLevel1	- Laser control in S1R4
//MissionLevel2 - Mission Objectives in S1R9
//MissionLevel3 - ForceField in S1r2
//MissionLevel4 - Ring zap in S1r22
//
//
//AirLock
//-------
//
//Help01	> Door out can be opened
//Help02	> Door in can be opened
//Help03	> Barman sequence
//Help04	> Fire Johnson !
//Help05	> Evil Bob Spawning
//Help06	> Turbine sound
//Help07	> Flamethrower CD Track <-> Ambient CD Track
//Help08	> Tutorial for hand over hand
//Help10	> Airlock Door to 8 is closed
//Help11	> Airlock Door to 3 is closed 
//Help12	> Airlock door between 3 and 8
//Help13	> Intro Fire
//Help14	> Intro Fire 2
//Help15	> Turn around the cops in S1r9
//Help16	> Unlock Gate 5
//Help17	> Story Message #1 (s1r2)
//Help18	> Story Message #3 (s1r8)
//Help19	> Story Message #4 (s1r5)
//Help20	> Tutorial for Glowing Halo
//Help21	> Story Message #2 (s1r8)
//Help22	>
//Help23	>
//Help24	>
//
//VarBit	    - 
//------
//
//Help01	> If door from s1r3 to s1r4 is opened, then the door in s1r4 is always openable
//Help02	> Caspule sound in S1r22
//Help03	> Check if player has picked the machine gun in S1r5
//Help04	> Lift Sequence in S1R3 (for the guy braking...)
//Help05	> If door from s1r9 to s1r9 is opened, then the door in s1r8 is always openable
//Help06	> Warning Sequence (toggles on/off for within/out of the trigger)
//Help07	> Toggle for camera reset to normal (RHAAAAAAAAAAAAAAAAAAAAAA)
//Help08	> Seq. in S1R11
//Help09	> Initialise the flic in s1r3
//Help10	> Assign the cop to its seek track in s1r3
//Help11	> CD Track change
//Help12	> If no cop left into s1r3, spawn two from s1r24
//Help13	> Shut Down in S1r18
//Help14	> Radiation warnings in S1R11/S1R12
//Help15	> Flic Control in S1r18
//Help16	> Commander Respawn in S1R9
//Help17	> Contamination Breach in S1r18
//Help18	> Cigarette Vending Machine
//Help19	> Strangle tutorial
//Help20	> Respawn timer for radiation worker in s1r18 and s1r19
//Help21	> Console #1 power on/off
//Help22	> Console #2 power on/off
//Help23	> Console #3 power on/off
//Help24	> Console #4 power on/off
//
//HelpVaR
//-------
//
//Help01	> Offense Bot
//Help02	> Explodable Boxes Tut. #1
//Help03	> Reassign path to worker if boxes explode
//Help04	> Use to avoid conflict between the two rings in S1R4
//Help05	> Door System
//Help06	> Lift System
//Help07	> Fan System
//Help08	> Combat Mode
//Help09	> Sniper Mode
//Help10	> Radiation Worker Job
//Help11	> Hand over hand
//Help12	> Battery grabber
//Help13	> Radiation warning when going into s1r20
//Help14	> Pickup weapons
//Help15	> End Sequence of the demo
//Help16	> End Sequence (beast action)
//Help17	> End Sequence Camera
//Help18	> End Sequence Kill Bob
//Help19	> Turn off CD in S1R11
//Help20	> Hand Box Tutorial
//Help21	> CDChange toggle variable
//Help22	> CDChange toggle variable
//Help23	> Battery replacement in S1R18
//Help24	> Shift change in S1R3

//OHelpVar
//-------
//
//Help01	> Offensive bot tutorial
//Help02	> Allow Access #1 in s1r5
//Help03	> Allow Access #2 in S1r5
//Help04	> Radlight in s1r14
//Help05	> door mechanism tutorial
//Help06	> ammo pickup tutorial
//Help07	> Kill Johnson
//Help08	> Ice Gun tutorial
//Help09	> sniper tutorial
//Help10	> Force Global reallocation in s1r24
//Help11	> Move the worker in s1r9
//Help12	> Move the actor upwards in s1r11
//Help13	> Radiation Sign for s1r4
//Help14	> --- UNUSED ---
//Help15	> --- UNUSED ---
//Help16	> --- UNUSED ---
//Help17	> --- UNUSED ---
//Help18	> --- UNUSED ---
//Help19	> chokehold tutorial
//Help20	> hand box tutorial
//Help21	> --- UNUSED ---
//Help22	> --- UNUSED ---
//Help23	> --- UNUSED ---
//Help24	> tank service effects in s1r9

SubRoutine(InitSceneSound2)
{
		call(CDSwap,1,1,100,60);
		if(FirstTimeRun!=0)
		{
			call(CDSwap,1,1,100,60);
			float(_set,AIVisionToggle,0);
		}
		if(incoming!=0)
		{
			if(ScriptMark==1)
			{
				callsub(Panel1);
			}
			elseif(ScriptMark==2)
			{
				callsub(Panel2);
			}
			elseif(ScriptMark==3)
			{
				callsub(Panel3);
			}
			elseif(ScriptMark==4)
			{
				callsub(Panel4);
			}
		}
		else
		{
			callsub(ScriptLevel2);
		}
		//ambient sound Fx
		#include	"messiahscripts\stages\scene2sfx.hxx"
}

SubRoutine(DeInitSceneSound2)
{
			//s1r20

			vector(_set,Gactorpos,-2540,620,8147);
			samplestop(SFXCapsuleIdle,Gactorpos);

			vector(_set,Gactorpos,-2545,603,7860);
			samplestop(SFXFieldHumLoop,Gactorpos);

			//s1r4
			vector(_set,gactorpos,-957,474,8973);
			samplestop(SFXLaserAmbient,gactorpos);

			vector(_set,Gactorpos,-386,1744,9910);
			samplestop(SFXCityAmbient01,Gactorpos);

			vector(_set,Gactorpos,-386,769,8402);
			samplestop(SFXRotatingPipe,Gactorpos);

			//s1r3
			vector(_set,Gactorpos,-733,748,4504);
			samplestop(SFXGlobeAmbient,Gactorpos);

			vector(_set,Gactorpos,891,1455,4200);		//s1r3
			samplestop(SFXElectric2,Gactorpos);

			//s1r8
			vector(_set,gactorpos,-1640,36,1119);
			samplestop(SFXLaserAmbient,gactorpos);

			vector(_set,gactorpos,-101,106,132);
			samplestop(SFXIndAmbient02,gactorpos);

			vector(_set,gactorpos,-2144,106,-145);
			samplestop(SFXIndAmbient01,gactorpos);

			//s1r10
			vector(_set,Gactorpos,-3488,1501,2409);
			samplestop(SFXPulseSound,Gactorpos);

			//s1r13
			vector(_set,Gactorpos,-5173,-62,2356);
			samplestop(SFXRadiationPool,Gactorpos);

			//s1r14
			vector(_set,Gactorpos,-5173,-62,556);
			samplestop(SFXRadiationPool,Gactorpos);

			//s1r11
			vector(_set,Gactorpos,-5203,1185,1680);
			samplestop(SFXVent2loop,Gactorpos);
			vector(_set,Gactorpos,-5134,704,1680);
			samplestop(SFXVent2loop,Gactorpos);
			vector(_set,Gactorpos,-5203,1334,1680);
			samplestop(SFXVent2loop,Gactorpos);

			//s1r4


			//s1r2
			vector(_set,Gactorpos,-4990,950,822);			//needs move with fans MSIKACHHUUUU
			samplestop(SFXAirFans,gactorpos);
			vector(_set,Gactorpos,-4999,950,421);			//needs move with fans MSIKACHHUUUU
			samplestop(SFXAirFans,gactorpos);
			vector(_set,Gactorpos,-5431,950,1452);			//needs move with fans MSIKACHHUUUU
			samplestop(SFXAirFans,gactorpos);
}

SubRoutine(InitScene2)
{
	
	if(VScriptInitiated!=2)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,10103,0);
				InitActor(Bob1,0,Gactorangle,"S1r4");
			}	
			
			call(loadpreloaddb,1,true);
			#include	"messiahscripts\enemies\c1_sector1.spt"
			#include    "messiahscripts\enemies\c1_special.spt"

			// Reset all the variables
			float(_set,VarKey1,0);
			float(_set,VarKey2,0);
			float(_set,VarKey3,0);
			float(_set,VarKey4,0);
			float(_set,VarKey5,0);
			float(_set,VarKey6,0);
			float(_set,VarKey7,0);
			float(_set,VarKey8,0);
			float(_set,VarKey9,0);
			float(_set,VarKey10,0);
			float(_set,AccessGranted,0);
			float(_set,PillarEvent,0);
			float(_set,MissionLevel1,0);
			float(_set,MissionLevel2,0);
			float(_set,MissionLevel3,0);
			float(_set,MissionLevel4,0);
			float(_set,RadiationGlow,0);
			float(_set,RadDirection,0);
			float(_set,LiteCounter,250);
			float(_set,RadActionTimer,0);
			float(_set,BarmanAction,0);
			float(_set,CallBot,0);
			float(_set,Punched,0);
			float(_set,PunchTimer,0);
			float(_set,cabtimer,0);
			float(_set,CrankAmbient,0);
			float(_set,NeedBattery,0);
			float(_set,RandomMsg,0);
			float(_set,Picked,0);
			float(_set,WarningBit,0);
			float(_set,RadAlert,0);
			float(_set,InScan,0);
			float(_set,CDTrack,1);
			float(_set,LiftMsg,0);
			float(_set,RadChecked,0);
			float(_set,CameraPan,0);
			float(_set,WarnSeq,0);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
			float(_set,timer4,0);
			float(_set,BarmanTimer,0);
			float(_set,HudTimer,0);
			float(_set,CommandTimer,0);
			float(_set,DanceKey,0);
			float(_set,ExplodeBoxTimer,0);
			float(_set,FreighTimer,-1);
			float(_set,HelpVar,AllHelp);
			float(_set,OHelpVar,AllHelp);
			float(_set,Res03,AllHelp);
			float(_set,SteamTimer,0);
			float(_set,VarBit,AllHelp);
			float(_set,FirstTimeRun,0);
			float(_set,DroidVoice,0);
			float(_set,AirLock,AllHelp);
			float(_set,ControlTimer,0);
			float(_set,Explode01,0);
			float(_set,Explode02,0);
			float(_set,InBoxTrigger,0);
			float(_set,AirLockTimer,0);
			float(_set,IntroToggle,0);
			float(_set,IntroFireYPos,530);
			float(_set,LottoTimer,0);
			float(_set,StopTutorial,0);
			float(_set,Res02,0);
			float(_set,DepossesionAbilityActive,0);
		}
		callsub(InitSceneSound2);
		call(ScriptCodeInitiated,2);
}

SubRoutine(RadiationCheck)
{
	if(VAIClass==_AIClassScientist && VTrigger==_DIRHaveGun && VWeaponAmmoType==_AmmoBattery && VWeaponAmmoLeft!=0)
	{
		float(_clr,OHelpVar,Help13);
	}
	else
	{
		float(_or,OHelpVar,Help13);
	}

	if(OHelpVar&!=Help13)
	{
		if(RadiationGlow==1)
		{
			float(_add,RadDirection,1);
			if(RadDirection&=16)
			{
				float(_set,TmpFloat,0x55ff00);
			}
			else
			{
				float(_set,TmpFloat,0x888888);
			}
			call(expset2,1,TmpFloat,0);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
		}
		else
		{
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
		}
	}
}

SubRoutine(S1r12Fans,float(position),float(turbine))
{
	if(VTrigger==_DIREnvTrigger && VKeyObjFrame==position)
	{
		if(turbine==3)
		{
			sample(SFXTurbine01,-1);
		}
		elseif(turbine==1)
		{
			sample(SFXTurbine02,-1);
		}
		elseif(turbine==2)
		{
			sample(SFXTurbine03,-1);
		}
		if(VFirstPerson==0 && VSniperMode==0)
		{
			call(PlayerInput,0);
			call(ExpSet2,150,1,1);	//position, 8 seconds, use exp1 for target
		}

		call(ActivateButton,"Fan repositioning",-1,FALSE);
		call(ActivateButtonSample,SFXValidFunction);
		if(position==4)
		{
			float(_set,position,0);
			call(SetKeyObjFrame,0);
		}

		float(_add,position,1);

		call(KeyObjTrigger,position,1);
		call(KeyObjActiveSegment,position,position);
		kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
	}
}


SubRoutine(ScanCheck,const(AIClassCompare),const(RankCompare))
{
	if(VAICon==0)
	{
		if(VTrigger==_DIREnvTrigger)
		{
			if(InScan==-1)
			{
				if(VAIClass|=AIClassCompare && VRank==RankCompare)
				{
					float(_set,AccessGranted,1);
				}
				else
				{
					if(AIClassCompare==_AIClassCop && RankCompare==_RankCommander)
					{
						message("Access Restricted To Commanders.",120,10);
						sample(SFXAccessDenied,Gactorpos);
					}
					elseif(AIClassCompare==_AIClassScientist && RankCompare==_RankScum)
					{
						message("Access Restricted To Radiation Workers.",120,10);
						sample(SFXAccessDenied,Gactorpos);
					}
					elseif(AIClassCompare==_AIClassScientist && RankCompare==_RankPrivate)
					{
						message("Access Restricted To Scientist.",120,10);
						sample(SFXAccessDenied,Gactorpos);
					}
					float(_set,AccessGranted,0);
				}
				sample(SFXScanPlateOn,-1);
			}
			float(_set,InScan,1);
		}
		else
		{
			float(_set,Inscan,-1);
			float(_set,AccessGranted,0);
		}
	}
	if(InScan==1)
	{
		if(AccessGranted!=2)
		{
			float(_add,HudTimer,1)
			if(Hudtimer<=3)
			{
				float(_set,TmpFloat,0xeeeeee);
				call(expset1,1,TmpFloat,0);
			}
			if(HudTimer>3)
			{
				float(_set,TmpFloat,0x020202);
				call(expset1,1,TmpFloat,0);
			}
			if(HudTimer>6)
			{
				float(_set,HudTimer,0);
			}
		}
	}
	if(InScan==-1)
	{
			float(_set,TmpFloat,0x020202);
			call(expset1,1,TmpFloat,0);
	}
}
SubRoutine(Scene2RadiationArea)
{
	if(VAIClass!=_AIclassscientist || VRank!=_RankScum)		//signature for radiation workers
	{
		if(VAIClass!=_AIClassDroid)
		{
 			call(SubtractHealth,0,15);
		}
	}
}

SubRoutine(Cigs)
{
	if(VSetActive=="s1r4" && FirstTimeRun>=6)	//this line is a hack, but it stops the stupid ciggy machine playing a sample before the level even comes up!
	{
		float(_rnd2,RandomMsg,6);
		sample(SFXDroidVO,Gactorpos);
	}
}

SubRoutine(MainScene2)
{
/////////////////////////
//// SECTOR 1 SCRIPT ////
/////////////////////////
	/*
	if(BarmanTimer==15 && OHelpVar&=Help08 && TutorialToggle==1)
	{
		float(_clr,OHelpVar,Help08);
		ClearTutorialLines();
		AddTutorialLine("Stay Clear of the [20:250:50]Chot PAK Weapon[250:250:250]@ ");
		AddTutorialLine("its icy projectiles are capable ");
		AddTutorialLine("of freezing their target. ");
		AddTutorialLine(" ");
		AddTutorialLine("The more ice shards that stick into ");
		AddTutorialLine("the target@ the slower he will move ");
		AddTutorialLine("until he gets a chance to thaw. ");
		AddTutorialLine(" ");
		AddTutorialLine("    [255:255:0]             Press Any Key       ");
		AddTutorialLine("    [255:255:0]             To Continue         ");
		DisplayTutorialScreen("[255:255:20]HINT: ICE GUN",15,15);
	}
	*/

	if(HelpVar&=Help14)
	{
		if(VActionCode==_ActionPickupWeapon && tutorialtoggle==1 && InBattle==0)
		{
			if(VPickupClose!=WEAPONTORCH && VPickupClose!=WEAPONBATTERYGRABBER)
			{
				float(_clr,HelpVar,Help14);
				ClearTutorialLines();
				AddTutorialLine("To pick up a [20:250:50]weapon[250:250:250]@ move your character");
				AddTutorialLine("over to it then press and hold your");
				AddTutorialLine("Action button.");
				AddTutorialLine(" ");
				AddTutorialLine("Look for the Pickup Icon in the");
				AddTutorialLine("lower right corner of your screen.");
				AddTutorialLine(" ");
				AddTutorialLine("If you already carry a [20:250:50]weapon[250:250:250]@ you");
				AddTutorialLine("can swap it with the one lying on");
				AddTutorialLine("the ground. Just position yourself");
				AddTutorialLine("near the [20:250:50]weapon[250:250:250] you want to swap");
				AddTutorialLine("with@ then press and hold your ");
				AddTutorialLine("Action button.");
				AddTutorialLine(" ");
				AddTutorialLine("    [255:255:0]             Press Any Key       ");
				AddTutorialLine("    [255:255:0]             To Continue         ");
				DisplayTutorialScreen("[255:255:20]PICK UP WEAPONS",15,15);
			}
		}
	}		
		
	if(VSetActive=="s1r6")
	{
		if(VarKey4==0)
		{
			CurEnvTriggerSet("s1r6","omnictrl");
			float(_set,TmpFloat,0xff1111);
			call(expset1,TmpFloat,400,-1);
			call(expset2,TmpFloat,400,-1);
		}
		else
		{
			CurEnvTriggerSet("s1r6","omnictrl");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,10,-1);
			call(expset2,TmpFloat,10,-1);
		}
	}

	if(VSetActive=="s1r5")
	{
		CurEnvTriggerSet("s1r5","door5to4");
		if(MissionLevel1!=0)
		{
			float(_set,TmpFloat,0x00ff00);			
		}
		else
		{
			float(_set,TmpFloat,0xff0000);			
		}
		call(expset1,1,TmpFloat,0);
	}
	if(VSetActive=="s1r4")
	{
		call(SetParticleSetID,"s1r4");

		float(_rnd2,tmpfloat,64);
		vector(_setx,tmpvector,tmpfloat);
		float(_set,tmpfloat,0);
		vector(_sety,tmpvector,tmpfloat);
		float(_rnd2,tmpfloat,64);
		vector(_setz,tmpvector,tmpfloat);
		
		if(vrnd<50)
		{
			vector(_set,Gactorpos,-290,4,6748); //fire on the ground (black spot)
			vector(_add,gactorpos,tmpvector);
			spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
		}
		if(vrnd<50)
		{
			vector(_set,Gactorpos,-297,4,7056); //fire on the ground (black spot)
			vector(_add,gactorpos,tmpvector);
			spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
		}
		if(vrnd<50)
		{
			vector(_set,Gactorpos,4,4,7343); //fire on the ground (black spot)
			vector(_add,gactorpos,tmpvector);
			spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
		}

		if(AirLock&=Help13)
		{
			float(_add,LottoTimer,1);
			if(LottoTimer>30)
			{
				if(vrnd<50)
				{
					vector(_set,Gactorpos,-661,66,6950); //barrel fire spot
					vector(_add,gactorpos,tmpvector);
					spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
				}
			}
			if(LottoTimer>70)
			{
				if(vrnd<50)
				{
					vector(_set,Gactorpos,-633,84,6945); //barrel fire spot
					vector(_add,gactorpos,tmpvector);
					spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
				}
			}
			if(LottoTimer>100)
			{
				if(vrnd<50)
				{
					vector(_set,Gactorpos,-533,116,6964); //barrel fire spot
					vector(_add,gactorpos,tmpvector);
					spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
				}
			}
			if(LottoTimer>120)
			{
				if(vrnd<50)
				{
					vector(_set,Gactorpos,-568,15,6959); //barrel fire spot
					vector(_add,gactorpos,tmpvector);
					spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
				}
			}
			if(LottoTimer>135)
			{
				if(vrnd<50)
				{
					vector(_set,Gactorpos,-600,81,7062); //barrel fire spot
					vector(_add,gactorpos,tmpvector);
					spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
				}
			}
			if(LottoTimer>140)
			{
				if(vrnd<50)
				{
					vector(_set,Gactorpos,-570,122,7005); //barrel fire spot
					vector(_add,gactorpos,tmpvector);
					spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
				}
			}

			if(vrnd<50)
			{
				vector(_set,Gactorpos,-571,530,6993); //Top position for dropping fire
				vector(_add,gactorpos,tmpvector);
				spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
			}

			if(vrnd<50)
			{
				vector(_set,Gactorpos,-571,117,6993); //bottom position for dropping fire
				vector(_add,gactorpos,tmpvector);
				spawnparticle(fx_evilfire,-1,Gactorpos,EmptyVector,-1);
			}

			float(_sub,IntroFireYPos,3);

			if(vrnd<50)
			{
				vector(_set,Gactorpos,-571,530,6993);
				//vector(_sety,Gactorpos,IntroFireYPos);
				vector(_add,gactorpos,tmpvector);
				vector(_set,gactorine,0,2,0);
				spawnparticle(fx_evilfire,-1,Gactorpos,gactorine,-1);
			}

			if(IntroFireYPos<=117)
			{
				float(_set,IntroFireYPos,530);
			}
		}


			
		if(MissionLevel1>=6)
		{
			CurEnvTriggerSet("s1r4","inscan");
			float(_set,TmpFloat,0x020202);
			call(expset1,1,TmpFloat,0);
		}

		if(MissionLevel1<5)
		{
			vector(_set,gactorpos,-957,474,8973);
			vector(_set,gactorine,55,474,8973);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

			vector(_set,gactorpos,-957,405,8973);
			vector(_set,gactorine,55,405,8973);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

			vector(_set,gactorpos,-957,340,8973);
			vector(_set,gactorine,55,340,8973);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

			vector(_set,gactorpos,-957,275,8973);
			vector(_set,gactorine,55,275,8973);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

			vector(_set,gactorpos,-957,210,8973);
			vector(_set,gactorine,55,210,8973);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

			vector(_set,gactorpos,-957,145,8973);

			vector(_set,gactorine,55,145,8973);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

			vector(_set,gactorpos,-957,80,8973);
			vector(_set,gactorine,55,80,8973);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
			float(_set,LaserRetract,55);

			if(vrnd<20)
			{
				vector(_set,gactorpos,-957,275,8973);
				vector(_set,tmpvector,180,0,0);
				SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,350);
				vector(_set,gactorpos,55,275,8973);
				vector(_set,tmpvector,180,0,0);
				SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,350);
			}
		}
		else
		{
			vector(_set,gactorpos,-957,474,8973);
			samplestop(SFXLaserAmbient,gactorpos);
		}
	}
	if(VCurSet=="s1r12")
	{
		CurEnvTrigger("radmsg");
		call(expset1,400,4,150);
	}
	elseif(VCurSet=="s1r1")
	{
		//andrew test
		if(VSetActive=="s1r3a" && VSetInMemory!="s1r6" && controltimer==0)
		{
			call(ForceLoadSet,"s1r6");
			float(_set,controltimer,7);
		}
		elseif(VSetInMemory=="s1r6" && controltimer==7)
		{
			float(_set,controltimer,0);
		}
		//------------

		if(TutorialToggle==1 && InBattle==0)
		{
			if(HelpVar&!=Help09 && OHelpVar&=Help09) 
			{
				float(_clr,OHelpVar,Help09);
				ClearTutorialLines();
				AddTutorialLine("To take out enemies without being noticed@");
				AddTutorialLine("you can use your [20:250:50]Sniper Vision[255:255:255].");
				AddTutorialLine("Only Cops have this ability@ but the ");
				AddTutorialLine("three levels of zoom give them a very ");
				AddTutorialLine("accurate aim.");
				AddTutorialLine(" ");
				AddTutorialLine("Shooting someone in the head will kill");
				AddTutorialLine("him instantly. The [20:250:50]Pump Gun[255:255:255] has a short");
				AddTutorialLine("range. Experiment with long range");
				AddTutorialLine("weapons for deadlier results.");
				AddTutorialLine(" ");
				AddTutorialLine("    [255:255:0]             Press Any Key       ");
				AddTutorialLine("    [255:255:0]             To Continue         ");
				DisplayTutorialScreen("[255:255:20]SNIPER MODE",15,15);
			}
			elseif(VarBit&!=Help19 && OHelpVar&=Help19)
			{
				float(_clr,OHelpVar,Help19);
				ClearTutorialLines();
				AddTutorialLine("Even if you do not carry a weapon");
				AddTutorialLine("you can use your Hand-to-Hand combat");
				AddTutorialLine("ability. Within a close range to a ");
				AddTutorialLine("character@ you can perform special ");
				AddTutorialLine("actions such as kicks and punches. ");
				AddTutorialLine(" ");
				AddTutorialLine("If you manage to sneak behind someone's ");
				AddTutorialLine("back@ you can strangle him/her. ");
				AddTutorialLine(" ");
				AddTutorialLine("To enter the Hand-to-Hand combat mode");
				AddTutorialLine("press your Fire button. To use any ");
				AddTutorialLine("close combat ability@ press your ");
				AddTutorialLine("Fire button.");
				AddTutorialLine(" ");
				AddTutorialLine("    [255:255:0]             Press Any Key       ");
				AddTutorialLine("    [255:255:0]             To Continue         ");
				DisplayTutorialScreen("[255:255:20]HAND-TO-HAND COMBAT",15,15);
			}
		}
	}
	elseif(VCurSet=="s1r25")
	{
		call(SetParticleSetID,"s1r25");
		if(AirLockTimer==0)
		{
			CurEnvTrigger("omnictrl");
			float(_set,TmpFloat,0x000000)
			call(expset1,TmpFloat,10,-1);
			call(expset2,TmpFloat,10,-1);	
		}
		if(AirLock&!=Help12)
		{
			float(_set,TmpFloat,0x00ff00);
		}
		else
		{
			float(_set,TmpFloat,0xff0000);
		}
		CurEnvTrigger("door25to3");
		call(expset1,1,TmpFloat,0);
		if(VKeyObjFrame==0 && VKeyObjTriggered==0)
		{
			float(_or,Airlock,Help10);
		}
		else
		{
			float(_clr,Airlock,Help10);
		}

		CurEnvTrigger("door25to8");
		call(expset1,1,TmpFloat,0);
		if(VKeyObjFrame==0 && VKeyObjTriggered==0)
		{
			float(_or,Airlock,Help11);
		}
		else
		{
			float(_clr,Airlock,Help11);
		}

		if(Airlock&=Help10 && Airlock&=Help11 && Airlock&=Help12)
		{
			float(_add,Airlocktimer,1);
			
			if(AirLockTimer==1)
			{
				vector(_set,Gactorpos,-473,304,2321)
				sample(SFXScanHumm,Gactorpos);
			}
			if(AirLockTimer==5)
			{
				vector(_set,Gactorpos,-451,532,2395);
				vector(_set,tmpvector,200,50,0);
				spawnlight(LightPulseOmni2,-1,Gactorpos,tmpvector,EmptyVector,600);
				sample(SFXCylonPersonnelScanned,-1);
				vector(_set,Gactorpos,-452,191,2400);

			}
			elseif(AirLocktimer>=6)
			{
				if(AirLockTimer&=4)
				{
					CurEnvTrigger("omnictrl");
					float(_set,TmpFloat,0xff0000)
					call(expset1,TmpFloat,350,-1);
					call(expset2,TmpFloat,350,-1);
					CurEnvTrigger("door25to3");
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
				}
				else
				{
					CurEnvTrigger("omnictrl");
					float(_set,TmpFloat,0x000000)
					call(expset1,TmpFloat,10,-1);
					call(expset2,TmpFloat,10,-1);		
					CurEnvTrigger("door25to3");
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				}
				if(Vrnd<30)
				{
					vector(_set,Gactorpos,39,247,2258);
					vector(_set,Gactorine,-20,0,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,-20,-5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,-20,5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

					vector(_set,Gactorpos,-3,247,2258);
					vector(_set,Gactorine,-20,0,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,-20,-5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,-20,5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

					vector(_set,Gactorpos,-45,247,2258);
					vector(_set,Gactorine,-20,0,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,-20,-5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,-20,5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);



					vector(_set,Gactorpos,-942,247,2258);
					vector(_set,Gactorine,20,0,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,20,-5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,20,5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

					vector(_set,Gactorpos,-900,247,2258);
					vector(_set,Gactorine,20,0,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,20,-5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,20,5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

					vector(_set,Gactorpos,-858,247,2258);
					vector(_set,Gactorine,20,0,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,20,-5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
					vector(_set,Gactorine,20,5,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				}
			}
			if(AirLockTimer==30)
			{
				sample(SFXCylonInitiated,Gactorpos);
			}
			if(AirLockTimer==200)
			{
				vector(_set,Gactorpos,-451,532,2395);
				KillLight(LightPulseOmni3,Gactorpos,32);
				sample(SFXCylonCompleted,Gactorpos);
			}
			if(AirLockTimer>=250)
			{
				CurEnvTrigger("omnictrl");
				float(_set,TmpFloat,0x000000)
				call(expset1,TmpFloat,10,-1);
				call(expset2,TmpFloat,10,-1);		
				CurEnvTrigger("door25to3");
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				vector(_set,Gactorpos,-473,304,2321)
				samplestop(SFXScanHumm,Gactorpos);
				float(_clr,Airlock,Help12);
				float(_set,AirLockTimer,0);
				sample(SFXCylonAccessGranted,Gactorpos);
				call(ForceGlobalRealloc);
				message("Access Granted",120,10);
			}
		}

		
	}
//VSetActive
	if(VSetActive=="s1r9")
	{
		call(SetParticleSetID,"s1r9");
		if(Airlock&!=Help16)
		{
			CurEnvTriggerSet("s1r9","door8to9");
			float(_set,TmpFloat,0x00ff00);
			call(expset1,1,TmpFloat,0);
		}
		CurEnvTriggerSet("s1r9","inscan");
		float(_set,TmpFloat,0x020202);
		call(expset1,1,TmpFloat,0);
	}
	if(VSetActive=="s1ra")
	{
		CurEnvTriggerSet("s1ra","scroll");
		call(expset1,0,600,0);
	}
	if(VSetActive=="s1r13")
	{
		CurEnvTriggerSet("s1r13","trapdoor");
		if(VKeyObjFrame==1)
		{
			vector(_set,Gactorpos,-5177,297,2397);
			sample(SFXRadGlassOff,Gactorpos);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(ClrAllCollisionBuffers);
			move(0,1,0);
		}
		if(VKeyObjFrame==5)
		{
			vector(_set,Gactorpos,-5177,297,2397);
			sample(SFXRadGlassOff,Gactorpos);
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(ClrAllCollisionBuffers);
			move(0,1,0);
		}
	}
	if(VSetActive=="s1r15")
	{
		CurEnvTriggerSet("s1r15","lift");
		float(_set,TmpFloat,0xffffff);  // white
		float(_set,TmpFloat2,0xff0000); // red
		float(_set,TmpFloat1,0xffff00);   // yellow
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator
		if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Nuclear Power Control Center",120,10);
			
			float(_set,LiftMsg,0);
		}
		if(VKeyObjFrame==1 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Radiation Pool",120,10);
			float(_set,LiftMsg,0);
		}
	}
	if(VSetActive=="s1r16")
	{
		CurEnvTriggerSet("s1r16","lift");
		float(_set,TmpFloat,0xffffff);  // white
		float(_set,TmpFloat2,0xff0000); // red
		float(_set,TmpFloat1,0xffff00);   // yellow
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator
		if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Basement Storage",120,10);
			float(_set,LiftMsg,0);
		}
		if(VKeyObjFrame==1 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Nuclear Power Control Center",120,10);
			float(_set,LiftMsg,0);
		}
	}

	if(VSetActive=="s1r2")
	{
		if(MissionLevel3==0)
		{
			CurEnvTriggerSet("s1r2","scantrig");
			call(expset1,65,107,128);
			call(expset2,65,107,128);
			CurEnvTriggerSet("s1r2","inscan");
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
			float(_set,TmpFloat,0x020202);
			call(expset1,1,TmpFloat,0)
			float(_set,VarKey3,0);
			float(_set,MissionLevel3,1);
		}
		else
		{
			if(vrnd<50)
			{
				if(vrnd<25)
				{
					vector(_set,tmpvector,192,192,255);
					vector(_set,Gactorpos,-2545,500,7860);
					SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,450);
				}
				else
				{
					vector(_set,tmpvector,192,192,255);
					vector(_set,Gactorpos,-2545,1100,7860);
					SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,450);
				}
			}
		}
		if(MissionLevel3>=0 && VarKey3==1)
		{
			float(_sub,MissionLevel3,1);
			float(_set,AccessGranted,0);
		}
	}
	if(VSetActive=="s1r3a")
	{
		CurEnvTriggerSet("s1r3a","inscan");
		float(_set,TmpFloat,0x020202);
		call(expset1,1,TmpFloat,0);

		if(VarKey4==0)
		{
			CurEnvTriggerSet("s1r3a","SCANTRIG");
			call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
			if(TmpFloat==TRUE)
			{
				vector(_set,Gactorpos,891,1455,4200);		//s1r3
				SampleStop(SFXElectric2,Gactorpos);
				CurEnvTriggerSet("s1r3a","OMNICTRL");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,10,-1);
				call(expset2,TmpFloat,10,-1);
				float(_set,VarKey4,-1);
			}
			else
			{
				CurEnvTriggerSet("s1r3a","OMNICTRL");
				float(_set,TmpFloat,0xff1111);
				call(expset1,TmpFloat,400,-1);
				call(expset2,TmpFloat,400,-1);
			}
			call(SetParticleSetID,"s1r3a");

			vector(_set,Gactorpos,891,1255,4500);
			vector(_set,Gactorine,891,1255,3898);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

			vector(_set,TmpVector4,0,100,0);
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
			vector(_addy,Gactorpos,100);
			vector(_addy,Gactorine,100);
			callsub(LaserStrip,gactorpos,gactorine,fx_laserflickergreen,0);
		}
		else
		{
			if(VarKey4>0)
			{
				float(_sub,VarKey4,1);
				CurEnvTriggerSet("s1r3a","OMNICTRL");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,10,-1);
				call(expset2,TmpFloat,10,-1);
				if(VarKey4==0)
				{
					vector(_set,Gactorpos,891,1455,4200);
					sample(SFXElectric2,gactorpos);
				}
			}
		}
	}
	if(VSetActive=="s1r3")
	{
		if(VarKey10>=1)
		{
			CurEnvTriggerSet("s1r3","platctrl");
			float(_set,TmpFloat,0xff0000);
			call(expset1,1,TmpFloat,0);
			if(Vrnd<20)
			{
				vector(_set,gactorpos,-733,750,4506);
				vector(_set,tmpvector,250,0,0);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,750);
			}
		}	

		CurEnvTriggerSet("s1r3","flictrig");
		call(ExpGet,1,TmpFloat);
		if(TmpFloat==275)
		{
			sample(SFXWhatHappened,-1);
		}
		elseif(TmpFloat==400)
		{
			float(_set,VarKey10,3);
		}
		elseif(TmpFloat==427)
		{
			sample(SFXCommStu,-1);
		}
		elseif(TmpFloat>=600)
		{
			float(_clr,OHelpVar,Help07);
		}

		//make sure this is called only once
		if(VarBit&=Help09)
		{
			call(ExpSet1,0,0,269);
			float(_clr,VarBit,Help09);
		}
	}
	if(VSetActive=="s1r12")
	{
		call(SetParticleSetID,"s1r12");
		CurEnvTriggerSet("s1r12","fanbutn1");
		vector(_set,Gactorpos,0,0,0);
		spawnparticle(fx_windspecks,-3,gactorpos,gactorpos,-1);

		CurEnvTriggerSet("s1r12","fanbutn2");
		spawnparticle(fx_windspecks,-3,gactorpos,gactorpos,-1);

		CurEnvTriggerSet("s1r12","fanbutn3");
		spawnparticle(fx_windspecks,-3,gactorpos,gactorpos,-1);

	}
	if(VSetActive=="s1r18")
	{
		CurEnvTriggerSet("s1r18","doortrig");
		if(VTrigger!=_DIREnvTrigger && VKeyObjTriggered==0)
		{
			float(_set,TmpFloat,0xff0000);
			call(expset1,1,TmpFloat,0);
		}
		if(VarBit&=Help21)
		{
			CurEnvTriggerSet("s1r18","console01");
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0x000000);
			call(expset2,TmpFloat1,10,-1);
		}
		elseif(Varbit&!=Help21)
		{
			CurEnvTriggerSet("s1r18","console01");
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0xff2200);
			call(expset2,TmpFloat1,650,-1);
		}	
		if(VarBit&=Help22)
		{
			CurEnvTriggerSet("s1r18","console02");
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0x000000);
			call(expset2,TmpFloat1,10,-1);
		}
		elseif(Varbit&!=Help22)
		{
			CurEnvTriggerSet("s1r18","console02");
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0xff2200);
			call(expset2,TmpFloat1,650,-1);
		}			
		
		if(VarBit&=Help15)
		{
			CurEnvTriggerSet("s1r18","socle");
			call(expset1,0,0,142);
			float(_clr,VarBit,Help15);
		}	
	}
	if(VSetActive=="s1r22")
	{
		CurEnvTriggerSet("s1r22","checkloop");
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,255,1);
			float(_or,VarBit,Help02);
		}
		if(VKeyObjFrame==2)
		{
			float(_set,DanceKey,0);
		}
		if(VKeyObjFrame==3 && DanceKey==0)
		{
			vector(_set,Gactorpos,-2852,5722,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,1);
		}
		if(VKeyObjFrame==5 && DanceKey==1)
		{
			vector(_set,Gactorpos,-2852,5133,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,2);
		}
		if(VKeyObjFrame==7 && DanceKey==2)
		{
			vector(_set,Gactorpos,-2852,4532,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,3);
		}
		if(VKeyObjFrame==9 && DanceKey==3)
		{
			vector(_set,Gactorpos,-2852,3931,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,4);
		}
		if(VKeyObjFrame==11 && DanceKey==4)
		{
			vector(_set,Gactorpos,-2852,3330,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,5);
		}
		if(VKeyObjFrame==13 && DanceKey==5)
		{
			vector(_set,Gactorpos,-2852,2741,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,6);
		}
		if(VKeyObjFrame==15 && DanceKey==6)
		{
			vector(_set,Gactorpos,-2852,2127,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,7);
		}
		if(VKeyObjFrame==17 && DanceKey==7)
		{
			vector(_set,Gactorpos,-2852,1526,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,8);
		}
		if(VKeyObjFrame==19 && DanceKey==8)
		{
			vector(_set,Gactorpos,-2852,912,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,9);
		}
		if(VKeyObjFrame==21 && DanceKey==9)
		{
			vector(_set,Gactorpos,-2852,311,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,10);
		}
		if(VKeyObjFrame==23 && DanceKey==10)
		{
			vector(_set,Gactorpos,-2852,-315,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,11);
		}
		if(VKeyObjFrame==25 && DanceKey==11)
		{
			vector(_set,Gactorpos,-2852,-903,6379);
			sample(SFXBooster,Gactorpos);
			float(_set,DanceKey,12);
		}
		if(VKeyObjFrame==25 && VarBit&=Help02)
		{
			vector(_set,Gactorpos,-2793,669,6332);
			sample(SFXCapsuleLaunch,Gactorpos);
			float(_clr,VarBit,Help02);
		}

		CurEnvTriggerSet("s1r22","lumiere");
		float(_set,TmpFloat,0x2255ff);
		call(expset1,TmpFloat,450,-1);
		call(expset2,TmpFloat,450,-1);


	}
	if(VSetActive=="s1r20")
	{
		call(SetParticleSetID,"s1r20");
		if(NeedBattery==0)
		{
			vector(_set,Gactorpos,-3554,1443,8497);
			vector(_set,Gactorangle,0,0,0);
			InitActor(transportbot,Gactorpos,Gactorangle,"S1R20",TRUE,5);
			float(_set,NeedBattery,1);
		}
		elseif(NeedBattery==1)
		{
			GetNumbActorsInSet("s1r20",_AIClassDroid,TmpFloat);
			if(TmpFloat==0)
			{
				vector(_set,Gactorpos,-3554,1443,8497);
				vector(_set,Gactorangle,0,0,0);
				InitActor(transportbot,Gactorpos,Gactorangle,"S1R20",TRUE,5);
			}
		}
			
		if(NeedBattery==4)
		{
			if(RadActionTimer!=0)
			{
				float(_add,RadActionTimer,1);
				if(RadActionTimer>=250)
				{
					float(_set,RadActionTimer,0);
					float(_set,NeedBattery,0);
				}
			}
		}
		CurEnvTriggerSet("s1r20","captrig");
		if(timer3==0 && VKeyObjFrame==0 && VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,-2540,1870,8147);
			sample(SFXRipple2,Gactorpos);
			float(_set,timer3,1);
		}
		if(timer3==1 && VKeyObjFrame<=3)
		{
			if(vrnd<20)
			{
				vector(_set,Gactorine,0,-20,0);
				vector(_set,Gactorpos,-2555,1827,8461);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
				vector(_set,Gactorpos,-2916,1827,7979);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
				vector(_set,Gactorpos,-2553,1827,7832);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
				vector(_set,Gactorpos,-2200,1827,7969);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
			}
		}
		if(VKeyObjFrame==3 && timer3==1)
		{
			vector(_set,Gactorpos,-2540,1870,8147);
			sample(SFXClutchCap,Gactorpos);
			vector(_set,Gactorpos,-2540,620,8147);
			sample(SFXVaultMove,Gactorpos);
			float(_set,timer3,2);
		}
		if(VKeyObjFrame>=13 && VKeyObjFrame<=16)
		{
			if(vrnd<25)
			{
				vector(_set,Gactorpos,-2555,603,7860);
				vector(_set,tmpvector,255,255,255);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,500);
			}
		}
		if(VKeyObjFrame>=16 && VKeyObjFrame<=20)
		{
			if(vrnd<50)
			{
				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2331,603,7860);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2438,603,7860);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2545,603,7860);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2652,603,7860);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2759,603,7860);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);	

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2854,603,8000);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);	

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2854,603,8272);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);	

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2245,603,8000);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);	

				vector(_set,Gactorine,0,12,0);
				vector(_set,Gactorpos,-2245,603,8272);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
			}
		}
				
		if(VKeyObjFrame==13 && timer3==2)
		{
			vector(_set,Gactorpos,-2540,620,8147);
			samplestop(SFXVaultMove,Gactorpos);
			sample(SFXLatch1,gactorpos);
			float(_set,NeedBattery,3);
			float(_set,timer3,3);
		}	
		if(VKeyObjFrame==14 && timer3==3)
		{
			vector(_set,Gactorpos,-2540,620,8147);
			samplestop(SFXCapsuleIdle,Gactorpos);
			sample(SFXCapsuleLaunch,Gactorpos);
			float(_Set,timer3,4);
		}
		if(VKeyObjFrame==23 && timer3==4)
		{
			vector(_set,Gactorpos,-2540,620,8147);
			sample(SFXClutchCap,Gactorpos);
			sample(SFXVaultMove,Gactorpos);
			float(_set,timer3,5);
		}
		if(VKeyObjFrame==27 && timer3==5)
		{
			vector(_set,Gactorpos,-2540,620,8147);
			sample(SFXClutchCap,Gactorpos);
			sample(SFXCapsuleIdle,Gactorpos);
			samplestop(SFXVaultMove,Gactorpos);
			CurEnvTriggerSet("s1r20","pro");
			call(KeyObjTrigger,0,-1);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			float(_set,timer3,6);
		}
	}
	if(VSetActive=="s1r8")
	{
		vector(_set,Gactorpos,-1950,75,1161);
		vector(_set,Gactorine,-1353,75,1161);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);

		vector(_set,TmpVector4,0,75,0);
		vector(_add,Gactorpos,TmpVector4);
		vector(_add,Gactorine,TmpVector4);
		callsub(LaserStrip,gactorine,gactorpos,fx_laserflickerred,0);
		vector(_add,Gactorpos,TmpVector4);
		vector(_add,Gactorine,TmpVector4);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
		vector(_add,Gactorpos,TmpVector4);
		vector(_add,Gactorine,TmpVector4);
		callsub(LaserStrip,gactorine,gactorpos,fx_laserflickerred,0);

		CurEnvTriggerSet("s1r8","litectrl");
		float(_set,TmpFloat,0xff0000);
		call(expset1,TmpFloat,350,-1);
		call(expset2,TmpFloat,350,-1);

		/////////////////////////
		/// FREIGHT SEQUENCE  ///
		/////////////////////////

		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjTriggered==0)					
		{
			call(KeyObjTrigger,75,1);
			float(_set,FreighTimer,-1);
		}

		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==0 && FreighTimer==-1)
		{
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo02");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			float(_set,FreighTimer,0);
		}

		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==10 && FreighTimer==0)
		{
			CurEnvTriggerSet("s1r8","cargo02");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			float(_set,FreighTimer,1);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==12 && FreighTimer==1)		
		{
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			float(_set,FreighTimer,2);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==17 && FreighTimer==2)
		{
			CurEnvTriggerSet("s1r8","cargo02");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			float(_set,FreighTimer,3);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==20 && FreighTimer==3)
		{
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			float(_set,FreighTimer,4);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==25 && FreighTimer==4)
		{
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			float(_set,FreighTimer,5);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==32 && FreighTimer==5)
		{
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			float(_set,FreighTimer,6);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==41 && FreighTimer==6)
		{
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			float(_set,FreighTimer,7);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==46 && FreighTimer==7)
		{
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);

			float(_set,FreighTimer,8);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==51 && FreighTimer==8)
		{
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			float(_set,FreighTimer,9);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==52 && FreighTimer==9)
		{
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo03");
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			float(_set,FreighTimer,10);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==64 && FreighTimer==10)
		{
			CurEnvTriggerSet("s1r8","cargo02");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			float(_set,FreighTimer,11);
		}
		CurEnvTriggerSet("s1r8","cargo");
		if(VKeyObjFrame==68 && FreighTimer==11)	
		{
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			CurEnvTriggerSet("s1r8","cargo01");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			float(_set,FreighTimer,-1);
		}
	}
	if(VSetActive=="s1r10")
	{

		CurEnvTriggerSet("s1r10","RunLite");
		if(VKeyObjTriggered==0 && VKeyObjFrame==0)
		{
			call(KeyObjTrigger,40,1,-1);
			call(KeyObjActiveSegment,0,40);
			float(_set,TmpFloat,0xffffff);
			call(expset1,TmpFloat,200,-1);
			call(expset2,TmpFloat,200,-1);
		}
		if(VKeyObjFrame==8 || VKeyObjFrame==18 || VKeyObjFrame==28 || VKeyObjFrame==38)
		{
			CurEnvTriggerSet("s1r10","RunLite");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,0,-1);
			call(expset2,TmpFloat,0,-1);
		}
		else
		{
			CurEnvTriggerSet("s1r10","RunLite");
			float(_set,TmpFloat,0xffffff);
			call(expset1,TmpFloat,250,-1);
			call(expset2,TmpFloat,250,-1);
		}
	}	
	if(VSetActive=="s1r19")
	{
		if(VarBit&=Help23)
		{
			CurEnvTriggerSet("s1r19","console03");
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0x000000);
			call(expset2,TmpFloat1,10,-1);
		}
		elseif(Varbit&!=Help23)
		{
			CurEnvTriggerSet("s1r19","console03");
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0xff2200);
			call(expset2,TmpFloat1,650,-1);
		}
		if(VarBit&=Help24)
		{
			CurEnvTriggerSet("s1r19","console04");
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0x000000);
			call(expset2,TmpFloat1,10,-1);
		}
		elseif(Varbit&!=Help24)
		{
			CurEnvTriggerSet("s1r19","console04");
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
			float(_set,TmpFloat1,0xff2200);
			call(expset2,TmpFloat1,650,-1);
		}	
	}
	if(VSetActive=="S1R11")
	{
		call(SetParticleSetID,"S1R11");
		if(SteamTimer<=800)
		{
			if(VRnd<50)
			{
				if (VRnd<25)
				{
					vector(_set,Gactorine,0,-1,10);
				}
				else
				{
					vector(_set,Gactorine,0,1,10);
				}
				vector(_set,fxvector,0,0,25);

				vector(_set,Gactorpos,-5203,1334,1680);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				vector(_add,Gactorpos,fxvector);
				call(CheckActorCollision,gactorpos,35,0,_COLsteam);

				vector(_set,Gactorpos,-5203,1185,1680);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				vector(_add,Gactorpos,fxvector);
				call(CheckActorCollision,gactorpos,35,0,_COLsteam);

				vector(_set,Gactorpos,-5134,704,1680);
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
				vector(_add,Gactorpos,fxvector);
				call(CheckActorCollision,gactorpos,35,0,_COLsteam);
			}
		}
		if(SteamTimer>=1100)
		{
			float(_set,SteamTimer,0);
		}
		float(_add,SteamTimer,1);

		//East Side		
		vector(_set,gactorpos,-4852,2321,1910);
		vector(_set,gactorine,-4852,1338,1910);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,1);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerredx,1);

		vector(_set,gactorpos,-4933,2321,1989);
		vector(_set,gactorine,-4933,1338,1989);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,1);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerredx,1);

		vector(_set,gactorpos,-5007,2306,2058);
		vector(_set,gactorine,-5007,1352,2058);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,1);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerredx,1);

		//West Side,
		vector(_set,gactorpos,-4816,2310,2854);
		vector(_set,gactorine,-4816,1337,2854);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,1);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerredx,1);

		vector(_set,gactorpos,-4892,2310,2776);
		vector(_set,gactorine,-4892,1337,2776);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,1);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerredx,1);

		vector(_set,gactorpos,-4964,2296,2698);
		vector(_set,gactorine,-4964,1354,2698);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,1);
		callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerredx,1);

	}
	if(VCurSet=="s1r7")
	{
		CurEnvTrigger("arme");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,1500,1235,995);
			callsub(DispenserSound);
		}		
	}
	elseif(VCurSet=="s1r4")
	{
		if(HelpVar&!=Help05 && OHelpVar&=Help05)
		{
			float(_clr,OHelpVar,Help05);
			ClearTutorialLines();
			AddTutorialLine("[255:182:5]Doors[255:255:255] will either open automatically when");
			AddTutorialLine("they sense your presence or you will have");
			AddTutorialLine("to operate them manually. To do so@ stand");
			AddTutorialLine("in front of the middle of the door and");
			AddTutorialLine("press your[255:182:5] ACTION[255:255:255] button.");
			AddTutorialLine(" ");
			AddTutorialLine(" ");
			AddTutorialLine("    [150:150:150]                  Press Any Key       ");
			AddTutorialLine("    [150:150:150]                  To Continue         ");
			DisplayTutorialScreen("[255:255:20]DOOR MECHANISM",15,15);
		}

		if(HelpVar&!=Help20 && OHelpVar&=Help20)
		{
			float(_clr,OHelpVar,Help20);
			ClearTutorialLines();
			AddTutorialLine("[255:182:5]Boxes[255:255:255] and crates marked with a");
			AddTutorialLine("Hand symbol can be detonated");
			AddTutorialLine("manually.");
			AddTutorialLine(" ");
			AddTutorialLine("To activate the countdown@ stand");
			AddTutorialLine("in front of the [255:182:5]Hand[255:255:255] symbol and");
			AddTutorialLine("press your [20:250:50]Action[255:255:255] Button ");
			AddTutorialLine(" ");
			AddTutorialLine("  [255:255:0]          Press Any Key        ");
			AddTutorialLine("  [255:255:0]          To Continue          ");
			DisplayTutorialScreen("[255:255:20]HAND SYMBOL",15,15);
		}
		call(SetParticleSetID,"s1r4");
		float(_add,SteamTimer,1);
		if(SteamTimer<=500)
		{
			if(vrnd<20)
			{
				vector(_set,Gactorpos,-1418,831,8577);
				vector(_set,Gactorine,15,4,3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				vector(_set,Gactorpos,-1418,831,8221);
				vector(_set,Gactorine,15,4,-3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				vector(_set,Gactorpos,-1418,684,8577);
				vector(_set,Gactorine,15,-4,3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				vector(_set,Gactorpos,-1418,683,8221);
				vector(_set,Gactorine,15,-4,-3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				vector(_set,Gactorpos,815,831,8578);
				vector(_set,Gactorine,-15,4,3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				vector(_set,Gactorpos,814,831,8221);
				vector(_set,Gactorine,-15,4,-3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				vector(_set,Gactorpos,815,684,8577);
				vector(_set,Gactorine,-15,-4,3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

				vector(_set,Gactorpos,812,683,8221);
				vector(_set,Gactorine,-15,-4,-3);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
			}
		}
		if(SteamTimer>=1000)
		{
			float(_set,SteamTimer,0);
		}

		CurEnvTrigger("cigs");
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,255,1);
//			kfsample(SFXGenericOsc3b,SFXGenericOsc3b,-1,SFXGenericOsc3b);
		}
	}
	if(skipcollidecount>=5)
	{
		float(_set,skipcollidecount,0);
	}
	float(_add,skipcollidecount,1);
}


SubRoutine(BackgroundTriggerChecksScene2)
{
	if(VSpecialFlag==_sFLAGTargetLockedOn || VActorFlag==_AFLAGlogon)
	{
		float(_add,InBattle,1);
	}
	print("controlTimer :  ",Controltimer);

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel2); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////


	callsub(IncomingMessage);
	if(VAICon==0)
	{
		if (VCurSet!="s1r16" && VCurSet!="s1r15") 
		{
			float(_set,CameraPan,0);
			float(_set,Picked,0);
		}
	}
	
	if(VCurSet=="s1r25")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("door25to8")
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(AirLock&!=Help12)
				{
					if(ControlTimer==0)
					{
						call(LoadPreLoadDB,2);
						float(_set,ControlTimer,8);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Please Wait Until Sequence Is Over",350,10);
				}
			}

			CurEnvTrigger("door25to3")
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(AirLock&!=Help12)
				{
					if(ControlTimer==0)
					{
						call(ForceLoadSet,"s1r3");
						call(ForceLoadSet,"s1r3a");
						call(ForceLoadSet,"s1r1");
						call(LoadPreLoadDB,1);
						float(_set,ControlTimer,9);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Please Wait Until Sequence Is Over",350,10);
				}
			}

			if(ControlTimer==8)
			{
				CurEnvTrigger("door25to8")
				if(VSetActive=="s1r8")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r25","door25to8",1);
					call(KeyObjTrigger,255,1);
				}
			}
			elseif(ControlTimer==9)
			{
				CurEnvTrigger("door25to3")
				if(VSetActive=="s1r3")
				{
					/*
	   				if(Barmantimer==5)
					{
						float(_set,Barmantimer,10);
					}
					*/
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r25","door25to3",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}			
		////////////////////////////////
		// SPAWN CHOT ON THE WAY BACK //
		////////////////////////////////
/*
		if(barmantimer==10)
		{
			vector(_set,Gactorpos,-445,900,3746);
			vector(_set,Gactorangle,0,2048,0);
			initactor(WeaponPak,Gactorpos,Gactorangle,"s1r3");
			vector(_set,Gactorpos,-445,850,3746);
			initactor(Chot,Gactorpos,Gactorangle,"s1r3",FALSE);

			float(_set,barmantimer,15);
		}
*/
	}

// Variable Check

	if(VarBit&!=Help08)
	{
		CurEnvTriggerSet("s1r11","seq");
		if(VTrigger==_DIREnvTRigger)
		{
			if(VAIClass==_AIClassCop && VAICon!=0 && VPathID==1)
			{
				sample(SFXWorkerWhatThe,-1);
				callsub(Sub_AIGetBackToIdle);
				call(AIfindpathwithspecificid,55);
				float(_or,VarBit,Help08);
			}
		}
	}
	if(VarBit&!=Help13)
	{
		if(VarBit&=Help21 && VarBit&=Help22 && VarBit&=Help23 && VarBit&=Help24)
		{
			dmessage("Power Restored",30,50);
			vector(_set,Gactorpos,-5129,2770,-105);	
			KillLight(LightPulseOmni3,Gactorpos,16);
			sample(SFXStationPowerRestored,Gactorpos);
			CurEnvTriggerSet("s1r18","col01");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			CurEnvTriggerSet("s1r18","battin");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			CurEnvTriggerSet("s1r18","socle");
			call(expset1,145,145,329);
			float(_or,VarBit,Help13);
		}
	}
// Player Check

	if(VCurSet=="s1r1")
	{
		if(VAICon==0)
		{
			if(HelpVar&=Help09 || VarBit&=Help19)
			{
				CurEnvTrigger("tutsnip");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRForward && VAIClass==_AIClassCop)
				{
					if(VTrigger==_DIRHaveGun)
					{
						float(_clr,HelpVar,Help09);
					}
					else
					{
						float(_clr,VarBit,Help19);
					}
				}
			}

			CurEnvTrigger("display");
			if(VTrigger==_DIREnvTrigger && VSetInMemory!="s1r6")
			{
				call(ForceLoadSet,"s1r6");
			}
		}
	}
	elseif(VCurSet=="s1r2")
	{

		float(_set,StopTutorial,1);
		CurEnvTrigger("inscan");
		callsub(ScanCheck,_AIClassScientist,_RankScum);

		CurEnvTrigger("SCANTRIG");
		if(VTrigger==_DIREnvTrigger)
		{
			if(AccessGranted==1)
			{
				if(MissionLevel3==1)
				{
					message("Access Granted - Five Seconds Before Closing",200,10);
					call(expset1,23,65,65);
					call(expset1,23,65,65);
					vector(_set,Gactorpos,-2545,603,7860);
					samplestop(SFXFieldHumLoop,Gactorpos);
					sample(SFXFieldHumStop,Gactorpos);
					float(_set,MissionLevel3,150);
					CurEnvTrigger("inscan");
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					call(ClrAllCollisionBuffers);
					float(_set,VarKey3,1);
					float(_set,AccessGranted,2);
				}
			}
		}

		CurEnvTrigger("diecheck");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);	
		}
				
		CurEnvTrigger("trig2to4");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,4);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==4)
		{
			CurEnvTrigger("trig2to4")
			if(VSetActive=="s1r4")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s1r2","trig2to4",1);
				call(KeyObjTrigger,255,1);
			}
		}				
		if(VarKey3==0)
		{
			CurEnvTrigger("LASERTRIG");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
		}
	}
	elseif(VCurSet=="s1r3")
	{
		////////////////////////////////////		
		/////	   SHIFT SWITCH     ////////
		////////////////////////////////////

		CurEnvTrigger("underlft");
		if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassScientist && VAICon==0 && VPathID!=2)
		{
			if(HelpVar&=Help24 && InBoxTrigger==0)
			{
				float(_set,InboxTrigger,1);
			}
		}

		if(VAIClass==_AIClassScientist && VPathID==2 && VAIStatehigh!=_AIcombatmodereact && VAIStatehigh!=_AIcloseupaction)
		{
			if(InBoxTrigger==1)
			{
				callsub(TurnToPlayer);
				dmessage("This job sucks ! Why don't you",50,200);
				dmessage("help me out for a little while ?",60,200);
				sample(SFXThisJobSucks,-1);
				float(_set,InBoxTrigger,2);
			}
			if(InBoxTrigger>=2)
			{
				float(_add,InBoxTrigger,1);
				if(Vaction!=CopGesture1)
				{
					spawnaction(CopGesture1);
				}
				if(InBoxTrigger==20)
				{
					call(AIClrTarget);
					callsub(Sub_AIGetBackToIdle);
				}
				if(InBoxTrigger>=60)
				{
					call(AIfindpathwithspecificid,78);
					float(_set,InBoxTrigger,0);
				}
			}
			CurEnvTrigger("underlft");
			if(VTrigger==_DIREnvTrigger)
			{
				float(_or,HelpVar,Help24);
			}
			else
			{
				float(_clr,HelpVar,Help24);
			}
		}

		//If the player activates the console as a scientist...
		if(VAICon==0 && VFirstPerson==0 && VSniperMode==0)
		{
			CurEnvTrigger("fuckup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(VAIClass==_AIclassscientist && VRank==_RankPrivate)
					{
						if(VarKey10==0)
						{
							call(ActivateButton,"Improper Use of Braking Thrusters",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);				
						}
						else
						{
							call(ActivateButton,"Braking Sequence Already Activated",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
					}
					else
					{
						call(ActivateButton,"Scientist Only",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				if(VState==StateJustActivated)
				{
					if(VarKey10==0 && VAIClass==_AIclassscientist && VRank==_RankPrivate)
					{
						CurEnvTrigger("flictrig");
						call(ExpSet1,270,681,758);
						sample(SFXCrashImm,Gactorpos);
						float(_set,VarKey10,1);
						direction(_clr,_DIRaction);
					}
				}
			}				
		}

		//If the player possess Johnson...
		if(VarKey10==0)
		{
			if(VAICon==0 && VAIClass==_AIClassScientist)
			{
				if(VPathID==2 || VPathID==78)
				{
					message("System Malfunction - Shutting Down Braking System",200,10);
					CurEnvTrigger("flictrig");
					call(ExpSet1,270,681,758);
					sample(SFXCrashImm,Gactorpos);
					float(_set,VarKey10,1);
				}
			}
		}
		elseif(VarKey10==1)
		{
			vector(_set,tmpvector,0,-80,-80);
			vector(_set,Gactorpos,-733,742,4501);
			spawnlight(LightPulseOmni3,-1,Gactorpos,tmpvector,EmptyVector,1000);
			Sample(SFXZap,emptyvector);
			float(_set,VarKey10,2);
		}
		elseif(VarKey10==3)
		{
			CurEnvTrigger("trig3to8");
			callsub(DoorOpen,2,1);
			float(_clr,OHelpVar,Help07);
			float(_set,VarKey10,4);
		}

		if(VarKey10==4)
		{
			if(VSetActive=="s1r25")
			{
				vector(_set,Gactorpos,-253,150,2514);
				initactor(WeaponPumpGun,Gactorpos,Gactorangle,"s1r25");
				vector(_set,Gactorpos,-253,100,2514);
				initactor(copl,Gactorpos,Gactorangle,"s1r25",TRUE,13);

				vector(_set,Gactorpos,-672,150,2531);
				initactor(WeaponPumpGun,Gactorpos,Gactorangle,"s1r25");
				vector(_set,Gactorpos,-672,100,2531);
				initactor(copl,Gactorpos,Gactorangle,"s1r25",TRUE,12);
				float(_set,VarKey10,5);
			}
		}
		//////////////
		/// DOORS ////
		//////////////


		CurEnvTrigger("trig3to4");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
	
		if(ControlTimer==1)
		{
			CurEnvTrigger("trig3to4")
			if(VSetActive=="s1r4")
			{
				callsub(DoorOpen,2,1);
				float(_clr,VarBit,Help01);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s1r3","trig3to4",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("trig3to8");
			if(VarKey1==1)
			{
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
			}
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarKey10==0)
				{
					if(VarKey1!=0)
					{
						float(_or,Airlock,Help12);
						callsub(DoorOpen,1,1);
					}
					else
					{
						sample(SFXGate4Closed,Gactorpos);
						message("Gate 4 Remotely Locked",120,10);
					}
					direction(_clr,_DIRaction);
				}
				else
				{
					if(OHelpVar&!=Help07)
					{
						if(VarKey1!=0)
						{
							float(_or,Airlock,Help12);
							callsub(DoorOpen,1,1);
						}
						else
						{
							sample(SFXGate4Closed,Gactorpos);
							message("Gate 4 Remotely Locked",120,10);
						}
						direction(_clr,_DIRaction);
					}
					else
					{
						sample(SFXGate4Closed,Gactorpos);
						message("Gate 4 Remotely Locked",120,10);
					}						
				}
			}						
		}
		if(VarKey10>=3 && OhelpVar&!=Help07)
		{
			if(VAIClass==_AIClassScientist && VState!=StateDead)
			{
				if(VPathID==2 || VPathID==78)
				{
					if(VAICon!=0)
					{
						call(aichangemetoenemy);
					}
					else
					{
						call(aichangeplayertoenemy);
					}
				}
			}
		}
	}
	elseif(VCurSet=="s1r3a")
	{	
		//andrew test part 2
		if(vaicon==0)
		{
			if(controltimer==7)
			{
				float(_set,controltimer,0);
			}
		}
		//----------------

		if(VarKey4==0)
		{
			CurEnvTrigger("inscan");
			callsub(ScanCheck,_AIClassScientist,_RankPrivate);

			CurEnvTrigger("LASERTRIG");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
		
		}
		if(AccessGranted==1)
		{
			message("Access Granted - Laser Deactivated for 5 seconds",120,10);
			float(_set,AccessGranted,0);
			vector(_set,Gactorpos,891,1455,4200);		//s1r3
			SampleStop(SFXElectric2,Gactorpos);
			float(_set,VarKey4,200);
		}
	}
	elseif(VCurSet=="s1r5");
	{
		print("res02",res02);
		print("cabtimer",cabtimer);
		///////////////////
		// CHOT SEQUENCE //
		///////////////////
		if(VAICon!=0)
		{
			if(VState==StateCrawling || VState==StateHarpooned)
			{
				call(subtracthealth,0,20);
			}
		}

		if(OHelpVar&=Help03)
		{
			float(_add,cabtimer,1);
			if(cabtimer>=250)
			{
				GetNumbActorsInSet("s1r5",_AIClassChot,TmpFloat);
				if(TmpFloat==0)
				{
					if(Res02==0)
					{
						float(_set,Res02,1);
					}
					elseif(Res02==2)
					{
						float(_set,Res02,3);
					}
					elseif(Res02==4)
					{
						float(_clr,OHelpVar,Help03);
					}
				}
				elseif(TmpFloat==1)
				{
					if(VAICon==0 && VAIClass==_AIClassChot)
					{
						if(Res02==0)
						{
							float(_set,Res02,1);
						}
						elseif(Res02==2)
						{
							float(_set,Res02,3);
						}
						elseif(Res02==4)
						{
							float(_clr,OHelpVar,Help03);
						}
					}
				}
				float(_set,cabtimer,0);
			}
		}
		//************* JUST GOT THE BAZOOKA - SPAWN FOUR CHOTS BY THE DOOR ************
		if(Res02==1)
		{
			if(VAICon==0)
			{
				vector(_set,Gactorangle,0,0,0);

				vector(_set,Gactorpos,-814,1060,9939);
				initactor(WeaponPak,Gactorpos,Gactorangle,"s1r5");
				vector(_set,Gactorpos,-814,1010,9939);
				initactor(Chot,Gactorpos,Gactorangle,"s1r5",FALSE);

				vector(_set,Gactorpos,-445,1060,9746);
				initactor(WeaponPak,Gactorpos,Gactorangle,"s1r5");
				vector(_set,Gactorpos,-445,1010,9746);
				initactor(Chot,Gactorpos,Gactorangle,"s1r5",FALSE);

				vector(_set,Gactorpos,-57,1060,9812);
				initactor(WeaponPak,Gactorpos,Gactorangle,"s1r5");
				vector(_set,Gactorpos,-57,1010,9812);
				initactor(Chot,Gactorpos,Gactorangle,"s1r5",FALSE);

				vector(_set,Gactorpos,-1119,1060,10238);
				initactor(WeaponPak,Gactorpos,Gactorangle,"s1r5");
				vector(_set,Gactorpos,-1119,1010,10238);
				initactor(Chot,Gactorpos,Gactorangle,"s1r5",FALSE);
				float(_set,Res02,2);
			}
		}
		elseif(Res02==3)
		{
			vector(_set,Gactorangle,0,0,0);

			vector(_set,Gactorpos,-814,1060,9939);
			initactor(WeaponPak,Gactorpos,Gactorangle,"s1r5");
			vector(_set,Gactorpos,-814,1010,9939);
			initactor(Chot,Gactorpos,Gactorangle,"s1r5",FALSE);

			vector(_set,Gactorpos,-445,1060,9746);
			initactor(WeaponPak,Gactorpos,Gactorangle,"s1r5");
			vector(_set,Gactorpos,-445,1010,9746);
			initactor(Chot,Gactorpos,Gactorangle,"s1r5",FALSE);

			vector(_set,Gactorpos,-57,1060,9812);
			initactor(WeaponPak,Gactorpos,Gactorangle,"s1r5");
			vector(_set,Gactorpos,-57,1010,9812);
			initactor(Chot,Gactorpos,Gactorangle,"s1r5",FALSE);

			vector(_set,Gactorpos,2,450,10775);
			initactor(WeaponMaimer,Gactorpos,Gactorangle,"s1r5");
			vector(_set,Gactorpos,2,400,10775);
			initactor(Chot,Gactorpos,Gactorangle,"s1r5",TRUE,50);
			float(_set,Res02,4);
		}
		if(VAICon==0)
		{
			if(Airlock&=Help19 && OHelpVar&!=Help03)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,4);
				callsub(Panel4);
				ClearDMessage();
				float(_clr,Airlock,Help19);
			}

			call(aichangeplayertoenemy);
		
			CurEnvTrigger("door5to4");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && Vtrigger==_DIRAction)
			{
				if(MissionLevel1!=0)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,5);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);					
					}
				}
				else
				{
					Message("Locked.",120,10);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("secsplit");
			if(OHelpVar&!=Help03)
			{
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
			}
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(OHelpVar&!=Help03)
				{
					if(ControlTimer==0)
					{
						dmessage("L O A D I N G . . .",50,50);
						call(ForceGlobalRealloc);
						call(ForceLoadSet,"s2r2");
						call(ForceLoadSet,"s2r26");
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						float(_set,LinkGlobal,1);
						call(RunScriptCode,_or,3);
						direction(_clr,_DIRaction);
					}
					//*** opens the door only if both bazooka and machine have been picked up ***
				}
				else
				{
					message("Chot Activity Detected - Door Shut for Safety Reasons",350,10);
					sample(SFXAccessDenied,Gactorpos);
				}
			}
		

			if(VKeyObjTriggered==0 && VRunScriptCode==3)
			{
				callsub(DeInitSceneSound3);
				call(RunScriptCode,_clr,3);
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("secsplit")
				if(VSetActive=="s2r1" && VSetInMemory=="s2r2" && VSetInMemory=="s2r26")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r5","secsplit",1);
					call(KeyObjTrigger,255,1);
				}
			}
			elseif(ControlTimer==5)
			{
				CurEnvTrigger("door5to4")
				if(VSetActive=="s1r4")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r5","door5to4",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="s1r4")
	{
		if(VAICon==0)
		{
			if(Airlock&=Help17)
			{
				CurEnvTrigger("HaloGo");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_set,Incoming,1);
					float(_set,Godtimer,0);
					float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
					float(_set,ScriptMark,1);
					callsub(Panel1);
					ClearDMessage();
					float(_clr,Airlock,Help17);
				}
			}

			//******* MISSION OBJECTIVES **********
			if(FirstTimeRun==5 && VCutScene==0)
			{
				call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassCop,_GreaterEqual,_RankSergeantM);
				if(TmpFloat==0)
				{
					float(_set,FirstTimeRun,6);
					float(_set,ControlTimer,0);
				}
			}

			if(FirstTimeRun==6)
			{
				call(PlayerInput,1);
				float(_set,FirstTimeRun,7);
				float(_set,ControlTimer,0);
			}

			if(OHelpVar&=Help06 && TutorialToggle==1 && StopTutorial==0 && InBattle==0)
			{
				call(IsPickupClose,_ClassAmmoPickup,200,TmpFloat,TmpVector);
				if(VTrigger==_DIRTempFlag && TmpFloat!=0)
				{
					float(_clr,OHelpVar,Help06);
					ClearTutorialLines();
					AddTutorialLine("[20:250:50]Ammo Boxes[255:255:255] can be picked up only if your ");
					AddTutorialLine("character carries a weapon.");
					AddTutorialLine(" ");
					AddTutorialLine("The amount and type of ammunition you will");
					AddTutorialLine("receive from an [20:250:50]Ammo Box[255:255:255] varies based on");
					AddTutorialLine("the type of weapon you are carrying");
					AddTutorialLine(" ");
					AddTutorialLine("  [255:255:0]          Press Any Key        ");
					AddTutorialLine("  [255:255:0]          To Continue          ");
					DisplayTutorialScreen("[255:255:20]AMMO PICKUP",15,15);
				}
			}
		}				

		//////////////////////
		//	INTRO SEQUENCE	//
		//////////////////////

		if(FirstTimeRun==0)
		{
			call(AutoTesselation,false);
			float(_set,Incoming,0);
			call(PlayerInput,0);
			float(_set,aivisiontoggle,1);  // for intro only
			CutScene("intro");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			float(_set,FirstTimeRun,1);
			float(_set,IntroToggle,1);
			float(_set,timer2,0);

			sample(SFXCopTalkingIntroEnglish,Gactorpos);
		}
		if(FirstTimeRun>=1)
		{
			if(IntroToggle==1)
			{
				if(VAIClass==_AIClassCop && VPathID==14 && VState!=StateDead)
				{
					if(VAction!=CopIntroAnimCop)
					{
						spawnaction(CopIntroAnimCop);
						float(_add,timer2,1);
					}
				}
				if(VAIClass==_AIClassCop && VPathID==1)
				{
					if(VAction!=CopIntroAnimBob)
					{
						spawnaction(CopIntroAnimBob);
						float(_add,timer2,1);
					}
				}
			}
		}
		if(timer2==3)
		{
			float(_set,timer2,4);
			float(_set,IntroToggle,2);
		}
		if(AirLock&!=Help14)
		{
			CurEnvTrigger("intro01");
			call(ExplodeObject,TmpVector,1);
			callsub(Sub_ExplodeObjectHandler);
			float(_clr,Airlock,Help13);
			float(_or,AirLock,Help14);
			float(_set,LottoTimer,1);
		}
		if(AirLock&!=Help13 && LottoTimer>=1)
		{
			float(_add,LottoTimer,1);
			if(LottoTimer>=50)
			{
				if(VAIClass==_AIClassCop && VRank==_RankSergeantM && VAICon!=0)
				{
					samplestop(SFXElectric5);
					call(SubtractHealth,0,30000);
					State(_or,StateDead);
					float(_set,LottoTimer,0);
					float(_set,introtoggle,3);
				}
			}
		}
			
		if(VCutSceneFrame==320 && IntroToggle==3)
		{
			call(AutoTesselation,true);
			call(CutSceneEnd);
			call(CDPlay,1,1);
			float(_set,IntroToggle,4);
			float(_set,AIVisionToggle,0);
			float(_set,FirstTimeRun,5);
			call(PlayerInput,1);
		}

//*************************************************

		if(StopTutorial==0)
		{
			if(HelpVar&=Help08 && TutorialToggle==1 && VAICon==0 && FirstTimeRun>5 && InBattle==0)
			{
				if(VTrigger==_DIRcombatmode)
				{
					if(VTrigger==_DIRHaveGun)
					{
						float(_clr,HelpVar,Help08);
						ClearTutorialLines();
						AddTutorialLine("When you switch to [20:250:50]Combat Mode[255:255:255]@ you");
						AddTutorialLine("instantly become a threat to the");
						AddTutorialLine("surrounding characters. ");
						AddTutorialLine(" ");
						AddTutorialLine("If an armed character sees you in");
						AddTutorialLine("combat mode@ he will open fire.");
						AddTutorialLine(" ");
						AddTutorialLine("  [255:255:0]          Press Any Key        ");
						AddTutorialLine("  [255:255:0]          To Continue          ");
						DisplayTutorialScreen("[255:255:20]COMBAT MODE",15,15);
					}
					else
					{
						float(_clr,HelpVar,Help08);
						ClearTutorialLines();
						AddTutorialLine("When you switch to [20:250:50]Combat Mode[255:255:255]@ you");
						AddTutorialLine("instantly become a threat to the");
						AddTutorialLine("surrounding characters. ");
						AddTutorialLine(" ");
						AddTutorialLine("To engage an enemy in hand-to-hand combat:");
						AddTutorialLine("discard your weapon and approach your enemy."); 
						AddTutorialLine("Pressing the Attack button will allow you");
						AddTutorialLine("to strike out at your foe.");
						AddTutorialLine(" ");
						AddTutorialLine("  [255:255:0]          Press Any Key        ");
						AddTutorialLine("  [255:255:0]          To Continue          ");
						DisplayTutorialScreen("[255:255:20]COMBAT MODE",15,15);
					}
				}
			}						
		}
				
		CurEnvTrigger("inscan");
		if(MissionLevel1<=5 && HelpVar&=Help04)
		{
			callsub(ScanCheck,_AIClassCop,_RankCommander);
		}
		if(VTrigger==_DIREnvTrigger && MissionLevel1<5)
		{
			if(AccessGranted==1)
			{
				CurEnvTrigger("trig4to5");
				if(VKeyObjTriggered==0 && ControlTimer==0)
				{
					message("Access Granted",120,10);
					float(_set,Controltimer,8);
					float(_set,TmpFloat,0x00ff00);
					call(expset2,1,TmpFloat,0);
					CurEnvTrigger("inscan");
					call(expset2,1,TmpFloat,0);
					float(_set,MissionLevel1,6);
				}
			}
		}
		

		if(MissionLevel1<=5)
		{
			CurEnvTrigger("lasergrid");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
		}
		
		if(VarBit&=Help18)
		{
			CurEnvTrigger("cigs");
			call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
			if(TmpFloat==FALSE)
			{
				if(VKeyObjFrame==0 && DroidVoice==0)
				{
					vector(_set,Gactorpos,-942,876,7288);
					callsub(cigs);
					float(_set,DroidVoice,1);
				}
				if(VKeyObjFrame==2 && DroidVoice==1)
				{
					vector(_set,Gactorpos,-270,876,7288);
					callsub(cigs);
					float(_set,DroidVoice,0);
				}
			}
			else
			{
				call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
				float(_clr,VarBit,Help18);
			}
		}

		if(VAIClass==_AIClassWorker && VAICon!=0 && VPathID==6)
		{
			if(HelpVar&!=Help03)
			{
				call(AIfindpathwithspecificid,58);
				float(_or,HelpVar,Help03)				
			}
		}
		
		///// Explosive Box - Hand command ///////

		CurEnvTrigger("trig4to2");
		if(VTrigger==_DIREnvTrigger)
		{
			if(HelpVar&=help05 && TutorialToggle==1 && StopTutorial==0 && FirstTimeRun>5 && InBattle==0)
			{
				float(_clr,HelpVar,help05);	
			}	
			if(VKeyObjTriggered==0 && VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					call(ForceLoadSet,"s1r1");
					call(ForceLoadSet,"s1r3");
					call(ForceLoadSet,"s1r3a");
					float(_set,ControlTimer,4);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		CurEnvTrigger("trig4to3");
		if(VarBit&!=Help01)
		{
			float(_set,TmpFloat,0x00ff00);
			call(expset1,1,TmpFloat,0);
		}
		if(VTrigger==_DIREnvTrigger)
		{
			if(HelpVar&=help05 && TutorialToggle==1 && StopTutorial==0 && VAICon==0  && FirstTimeRun>5 && InBattle==0)
			{
				float(_clr,HelpVar,help05);	
			}	
			if(VTrigger==_DIRaction)
			{
				if(VarBit&=help01)
				{
					message("Door Is Locked From Inside",120,10);
					sample(SFXAccessDenied,Gactorpos);
				}
				else
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("trig4to3")
			if(VSetActive=="s1r3")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s1r4","trig4to3",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==4)
		{
			CurEnvTrigger("trig4to2")
			if(VSetActive=="s1r2")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s1r4","trig4to2",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VAICon==0)
		{
			vector(_set,Gactorpos,-1395,660,7198);
			CurEnvTrigger("handfx");
			if(HelpVar&=Help03)
			{
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					float(_clr,HelpVar,Help03)
				}
			}
			if(VTrigger==_DIREnvTrigger || Explode01!=0)
			{
				if(HelpVar&=Help20 && TutorialToggle==1 && StopTutorial==0 && VTrigger!=_DIRmove && InBattle==0)
				{
					float(_clr,HelpVar,Help20);
				}				
				callsub(HandBox,200,Explode01);
			}
			/////////////////////////////////////////

			///// Explosive Box - Hand command ///////
			vector(_set,Gactorpos,-807,420,7957);
			CurEnvTrigger("handfx01");
			if(VTrigger!=_DIREnvTrigger)
			{
				callsub(sub_setcameranormal);
			}
			if(VTrigger==_DIREnvTrigger || Explode02!=0)
			{
				camera(250,-50);
				if(HelpVar&=Help20 && TutorialToggle==1 && StopTutorial==0 && VTrigger!=_DIRmove && InBattle==0)
				{
					float(_clr,HelpVar,Help20);
				}		
				callsub(HandBox,200,Explode02);
			}
			/////////////////////////////////////////


			CurEnvTrigger("inscan");
			if(PillarEvent>=2)
			{
				CurEnvTrigger("trig4to5");
				if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && ControlTimer==0)
				{
					float(_set,ControlTimer,8);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			if(PillarEvent==0)
			{
				CurEnvTrigger("trig4to5");
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				call(CheckTriggerObjFlag,TmpFloat1,2,_SXObjDynamicObj);
				if(TmpFloat==TRUE || TmpFloat1==TRUE)
				{
					float(_set,PillarEvent,1);
					float(_set,MissionLevel1,6);
				}
				if(VAICon==0)
				{
					if(VTrigger==_DIREnvTrigger)
					{
						if(VAIClass==_AIClassScientist && VTrigger==_DIRHaveGun VWeaponAmmoType==_AmmoBattery && VWeaponAmmoLeft!=0);
						{
							if(MissionLevel1<6)
							{
								message("Access Granted",120,10);
								float(_set,ControlTimer,8);
								float(_set,TmpFloat,0x00ff00);
								call(expset2,1,TmpFloat,0);
								CurEnvTrigger("inscan");
								call(expset2,1,TmpFloat,0);
								float(_set,MissionLevel1,6);
							}
							CurEnvTrigger("Radctrl");
							call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						}
					}
					else
					{
						CurEnvTrigger("Radctrl");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					}
				}
			}
			CurEnvTrigger("trig4to5");
			if(MissionLevel1>=6)
			{
				if(VTrigger==_DIREnvTrigger && ControlTimer==0 && VKeyObjTriggered==0)
				{
					float(_set,ControlTimer,8);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			if(PillarEvent==1)
			{
				if(ControlTimer==0)
				{
					sample(SFXRipple,-1);
					message("System Malfunction - Unlocking Door",200,10);
					float(_set,ControlTimer,8);
					CurEnvTrigger("inscan");
					float(_set,TmpFloat,0x00ff00);
					call(expset2,1,TmpFloat,0);
					float(_set,PillarEvent,2);
				}
			}
			if(ControlTimer==8)
			{
				CurEnvTrigger("trig4to5")
				if(VSetActive=="s1r5")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r4","trig4to5",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("tutorial");
			if(HelpVar&=help02 && TutorialToggle==1 && StopTutorial==0 && VAICon==0  && FirstTimeRun>5 && InBattle==0)
			{
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==FALSE)
				{
					if(VTrigger==_DIREnvTrigger)
					{
						float(_clr,HelpVar,help02);	
						ClearTutorialLines();
						AddTutorialLine("Using your weapons you can make some");
						AddTutorialLine("[255:182:5]Boxes[255:255:255] explode. If you see a Hand");
						AddTutorialLine("Detonation Switch@ then characters");
						AddTutorialLine("can even use their hands.");
						AddTutorialLine(" ");
						AddTutorialLine("  [255:255:100]                     Press Any Key        ");
						AddTutorialLine("  [255:255:100]                     To Continue          ");
						DisplayTutorialScreen("[255:255:20]EXPLOSIVE BOXES",15,15);
					}
				}
				else
				{
					float(_clr,HelpVar,help02);
				}
			}
		}
	}
	elseif(vcurset=="s1r6")
	{

		CurEnvTrigger("trig6to7");
		if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			if(VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("trig6to7");
			if(VSetActive=="s1r7");
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				if(VAICon==0)
				{
					dmessage("L O A D I N G . . .",50,2);
				}
				setkeyframe("s1r6","trig6to7",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(VAICon==0)
		{
			if(Res03&!=Help01)
			{
				call(CDForcePlay,false);
				float(_or,Res03,Help01);
			}
			if(VarKey4==0)
			{
				vector(_set,Gactorpos,891,1455,4200);		//s1r3
				SampleStop(SFXElectric2,Gactorpos);
				CurEnvTriggerSet("s1r3a","OMNICTRL");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,10,-1);
				call(expset2,TmpFloat,10,-1);
				float(_set,VarKey4,-1);
			}

			call(CDSwap,1,1,100,60);		

			CurEnvTrigger("platetrig");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(VarKey1==0)
					{
						call(ActivateButton,"Unlocking Gate 4",-1,FALSE);
						call(ActivateButtonSample,SFXGate4UnLocked);
						sample(SFXValidFunction,Gactorpos);
					}
					else
					{
						call(ActivateButton,"Gate Already Unlocked",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
					direction(_clr,_DIRaction);
				}
				if(VState==StateJustActivated)
				{
					if(VarKey1==0)
					{
						float(_set,TmpFloat,0x00ff00);
						call(expset1,1,TmpFloat,0);
						float(_set,VarKey1,1);
					}
				}
			}
		}
		if (VarKey4==0)
		{
			CurEnvTrigger("LASERTRIG");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
		}
	}
	elseif(vcurset=="s1r7")
	{
		call(SetParticleSetID,"s1r7");
		CurEnvTrigger("arme");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAIClass!=_AIClassAngel)
			{
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					vector(_set,Gactorpos,1500,1240,995);
					vector(_set,Gactorangle,0,-1024,0);
					InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"s1r7",TRUE);
					call(KeyObjTrigger,255,1);
					float(_set,TmpFloat,0x0000ff);
					call(expset1,1,TmpFloat,0);
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
		
		CurEnvTrigger("trig6to7");
		if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			if(VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					call(ForceLoadSet,"s1r3a");
					call(ForceLoadSet,"s1r3");
					call(ForceLoadSet,"s1r1");
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("trig6to7");
			if(VSetActive=="s1r6")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				if(VAICon==0)
				{
					dmessage("L O A D I N G . . .",50,2);
				}
				setkeyframe("s1r7","trig6to7",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VAICon==0)
		{
			if(Vlanguage==0)
			{
				call(CDSwap,9,1,100,60);
			}
			elseif(VLanguage==1 || VLanguage==3)
			{
				call(CDSwap,24,1,100,60);
			}
			elseif(Vlanguage==2 || VLanguage==4)
			{
				call(CDSwap,25,1,100,60);
			}
			if(Res03&=Help01)
			{
				call(CDForcePlay,true);
				float(_clr,Res03,Help01);
			}
		}
		else
		{
			CurEnvTrigger("trig6to7");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(DoorOpen,2,1);
			}
		}
	}
	elseif(vcurset=="s1r8")
	{
		CurEnvTrigger("LASERTRIG");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}
		CurEnvTrigger("LASERTRI2");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}


		CurEnvTrigger("door8to25");
		if(VKeyObjTriggered==0 && VTRigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_or,Airlock,Help12);
				float(_set,ControlTimer,10);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(VAICon==0)
		{
			if(Airlock&=Help21)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,2);
				callsub(Panel2);
				ClearDMessage();
				float(_clr,Airlock,Help21);
			}
			if(Airlock&=Help18 && BarmanTimer==5)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,3);
				callsub(Panel3);
				ClearDMessage();
				float(_clr,Airlock,Help18);
			}
			CurEnvTrigger("door8to9");
			if(VarBit&!=Help05)
			{
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
			}
			if(VKeyObjTriggered==0 && VTRigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{	
				if(VarBit&!=Help05)
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
					message("Door Locked From The Inside",120,10);
					sample(SFXAccessDenied,Gactorpos);
				}
			}
			if(ControlTimer==2)
			{
				CurEnvTrigger("door8to9");
				if(VSetActive=="s1r9")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r8","door8to9",1);
					call(KeyObjTrigger,255,1);
				}
			}
			elseif(ControlTimer==10)
			{
				CurEnvTrigger("door8to25");
				if(VSetActive=="s1r25")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r8","door8to25",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="s1r9")
	{
		if(VAICon!=0)
		{
			if(VState==StateCrawling || VState==StateHarpooned)
			{
				call(subtracthealth,0,20);
			}
		}

		call(SetParticleSetID,"s1r9");
		callsub(Sub_SetCameraNormal);
		CurEnvTrigger("InScan");
		callsub(ScanCheck,_AIClassScientist,_RankScum);

		CurEnvTrigger("unlock");
		if(VAICon==0 && VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				if(Airlock&=Help16)
				{
					setkeyframe("s1r8","organic",0);
					call(ActivateButton,"Gate 5 Unlocked",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				else
				{
					call(ActivateButton,"Gate Already Unlocked",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
			}
			if(VState==StateJustActivated)
			{
				if(Airlock&=Help16)
				{
					float(_set,TmpFloat,0x0000ff);
					call(expset1,1,TmpFloat,0);
					float(_clr,Airlock,Help16);
				}					
			}
		}
		/////////////////////////////////
		// MISSION OBJECTIVES SEQUENCE //
		/////////////////////////////////


		CurEnvTrigger("order");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAIClass!=_AIClassCop && VRank!=_RankCommander)
			{
				message("Commanders Only",120,10);
			}
		}
		//******* Initialize Mission Objectives Flic ****************
		if(MissionLevel2==0)
		{
			call(expset1,0,0,450);
			float(_set,MissionLevel2,1);
			CurEnvTrigger("workcon");
			float(_set,SubVar2,0x2267ff);
			call(expset1,SubVar2,180,-1);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
		}

		//************ Floor Panel Blink ***********
		//******* Flic pauses and RTLite Fades *****
		if(MissionLevel2==1 || MissionLevel2==4)
		{
			call(expget,1,TmpFloat);
			float(_add,timer3,1)
			if(timer3&=16)
			{
				float(_set,SubVar1,0x000000)
				call(expset2,1,SubVar1);
			}
			else
			{
				float(_set,SubVar1,0xffffff)
				call(expset2,1,SubVar1);
			}
			if(timer==0 && Tmpfloat>=25 && LiteCounter>=0)
			{
				float(_sub,LiteCounter,2);
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,LiteCounter,-1);
			}
			if(TmpFloat>=111 && timer==0)
			{
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,180,-1);
				CurEnvTrigger("order");
				call(expset1,111,111,111);
				float(_add,timer2,1);
				if(timer2>=500)
				{
					float(_set,timer,1);
					float(_set,LiteCounter,180);
					float(_set,timer2,0);
					vector(_set,Gactorpos,-2803,190,1433);
					sample(SFXChotActivity01,Gactorpos)
					call(expset1,111,0,450);
				}
			}
			if(timer==1 && Tmpfloat>=140 && LiteCounter>=0)
			{
				float(_sub,LiteCounter,2);
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,LiteCounter,-1);
			}
			if(TmpFloat>=216 && timer==1)
			{
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,180,-1);
				CurEnvTrigger("order");
				call(expset1,216,216,216);
				float(_add,timer2,1);
				if(timer2>=500)
				{
					vector(_set,Gactorpos,-2803,190,1433);
					sample(SFXChotActivity04,Gactorpos)
					float(_set,timer,2);
					float(_set,LiteCounter,180);
					float(_set,timer2,0);
					call(expset1,216,0,450);
				}
			}
			if(timer==2 && Tmpfloat>=240 && LiteCounter>=0)
			{
				float(_sub,LiteCounter,2);
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,LiteCounter,-1);
			}
			if(TmpFloat>=314 && timer==2)
			{
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,180,-1);
				CurEnvTrigger("order");
				call(expset1,314,314,314);
				float(_add,timer2,1);
				if(timer2>=500)
				{
					vector(_set,Gactorpos,-2803,190,1433);
					sample(SFXChotActivity06,Gactorpos)
					float(_set,timer,3);
					float(_set,LiteCounter,180);
					float(_set,timer2,0);
					call(expset1,314,0,450);
				}
			}
			if(timer==3 && Tmpfloat>=340 && LiteCounter>=0)
			{
				float(_sub,LiteCounter,2);
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,LiteCounter,-1);
			}
			if(TmpFloat>=448 && timer==3)
			{
				CurEnvTrigger("workcon");
				float(_set,SubVar2,0x2267ff);
				call(expset1,SubVar2,180,-1);
				CurEnvTrigger("order");
				call(expset1,448,448,448);
				float(_add,timer2,1);
				if(timer2>=500)
				{
					vector(_set,Gactorpos,-2803,190,1433);
					sample(SFXChotActivity09,Gactorpos)
					float(_set,LiteCounter,180);
					float(_set,timer,0);
					float(_set,timer2,0);
					call(expset1,0,0,450);
				}
			}
		}

		//******* Returns to normal Flic Loop after Sequence ****************
		if(MissionLevel2==3)
		{
			call(expset1,0,0,450);
			call(PlayerInput,1);
			FirstPerson(0,0)
			float(_set,MissionLevel2,4);
		}

		//******* Activate Flic Sequence ****************
		CurEnvTrigger("order");
		if(VTrigger==_DIREnvTrigger && VAICon==0 && VAIClass==_AIClassCop && VRank==_RankCommander && InBattle==0)
		{
			if(MissionLevel2==1)
			{
				float(_set,MissionLevel2,2);
				float(_set,timer3,0);
				call(expset1,450,0,696);
				direction(_clr,_DIRaction);
				call(PlayerInput,0);
				call(FaceTriggerDirection);
				FirstPerson(1,1)
				CurEnvTrigger("workcon");
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				CurEnvTrigger("door8to9");
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			}
		}

		//******* Flic Sequence Special Events ****************
		if(MissionLevel2==2)
		{
			CurEnvTrigger("order");
			call(ExpGet,1,TmpFloat);
			//******* Starts Speech ****************
			if(TmpFloat==482)
			{
				sample(SFXChotActivity,Gactorpos);
				ClearDMessage();
				dmessage("Commander! I've been hailing !",50,400);
				dmessage("We have Chot activity in Sector 2",60,400);
				dmessage("Gather your men@ and report there",70,400);
				dmessage("immediately!",80,400);
			}
			//******* Morph Screen to 3/4th of Its size ****************
			if(TmpFloat==531 && VKeyObjFrame==0)
			{
				setkeyframe("s1r9","order",3);
			}

			//******* Morph back to Original Size ****************
			if(TmpFloat==550)
			{
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,0,-1);
				}
			}

			//******* End of Sequence (Wait 2 seconds on 'End of Transmission') ****************
			if(TmpFloat>=677)
			{
				call(expset1,688,688,688);
				float(_add,timer3,1);
				if(timer3>=100)
				{
					call(PlayerInput,1);
					FirstPerson(0,0);
					float(_set,MissionLevel2,3);
					float(_set,timer3,0);
				}
			}
		}

		if(Airlock&!=Help15)
		{
			if(VAIClass==_AIClassCop && VAICon!=0)
			{
				call(AIfindpathwithspecificid,59);
				call(aichangeplayertoenemy);
				float(_or,Airlock,Help15);
			}
		}
		CurEnvTrigger("killbob");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_clr,Airlock,Help15);
		}

		//////////////////////
		// WARNING SEQUENCE //
		//////////////////////

		//******* Attack Sequence if character is neither a worker nor a cop ****************
		CurEnvTrigger("warning");
		if(VAICon==0)
		{
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarBit&=Help06)
				{
					if(WarnSeq<3)
					{
						if(VAIClass!=_AIClassCop && VAIClass!=_AIClassWorker)
						{
							float(_set,WarningBit,1);
						}
					}
				}
			}
			else
			{
				if(VarBit&!=Help06)
				{
					float(_or,VarBit,Help06);
					float(_set,WarningBit,0);
				}
			}
		}

		CurEnvTrigger("stop");
		if(VTrigger==_DIREnvTrigger && VAICon==0 && WarnSeq<3)
		{
			if(VAIClass!=_AIClassCop && VAIClass!=_AIClassWorker)
			{
				float(_set,WarnSeq,4);
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("door8to9");
			if(VTrigger==_DIREnvTrigger && VAICon==0)
			{
				if(VTrigger==_DIRaction)
				{
					if(Airlock&!=Help16)
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
						message("Gate Remotely Locked",200,10);
						sample(SFXAccessDenied,Gactorpos);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					float(_set,InScan,-1);
				}
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("door8to9");
				if(VSetActive=="s1r8")
				{
					if(Barmantimer==0)
					{
						float(_set,Barmantimer,5);
					}
					float(_set,InScan,1);
					float(_clr,VarBit,Help05);
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r9","door8to9",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
		else
		{
			if(VAIClass==_AIClassCop && VRank==_RankCommander)
			{
				if(CommandTimer!=0)
				{
					ActorFlag(_or,_AFlagNoAI);
				}
				else
				{
					ActorFlag(_clr,_AFlagNoAi);
				}
			}
		}

		CurEnvTrigger("scantrig");
		if(AccessGranted==1)
		{
			message("Access Granted",120,10);
			float(_set,TmpFloat,0x00ff00);
			call(expset1,1,TmpFloat,0);
			float(_set,AccessGranted,0);
			callsub(DoorOpen,1,1);
		}
		if(VarBit&!=Help16)
		{
			CurEnvTrigger("stop");
			if(CommandTimer==0)
			{
				vector(_set,Gactorpos,-3279,53,745);
				sample(SFXLoweringTankLift,Gactorpos);
				sample(SFXRadGlassOff,Gactorpos);
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				float(_set,CommandTimer,1);
			}

			if(VKeyObjTriggered==0 && VKeyObjFrame==0 && CommandTimer==1)
			{
				call(KeyObjTrigger,255,1);
				float(_set,CommandTimer,2);
			}
			if(VKeyObjFrame==2 && CommandTimer==2)
			{
				vector(_set,Gactorpos,-3345,-156,626);
				sample(SFXLatch3,Gactorpos);
				float(_set,CommandTimer,3);
			}
			if(VKeyObjFrame==3 && CommandTimer==3)
			{
				vector(_set,Gactorpos,-3345,-156,626);
				sample(SFXRustDoorClose,Gactorpos);
				float(_set,CommandTimer,4);
			}
			if(VKeyObjFrame==6 && CommandTimer==4)
			{
				vector(_set,Gactorpos,-3216,-2182,440);
				vector(_set,Gactorine,0,0,0);
				Initactor(Guncommander,Gactorpos,Gactorine,"s1r9",FALSE);
				float(_set,CommandTimer,5);
			}
			if(VKeyObjFrame==11 && CommandTimer==5)
			{
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					vector(_set,Gactorpos,-3345,-156,626);
					sample(SFXLatch3,Gactorpos);
					float(_set,CommandTimer,6);
					ActorFlag(_or,_AFlagnoai)
				}
			}
			if(VKeyObjFrame==12 && CommandTimer==6)
			{
				vector(_set,Gactorpos,-3345,-156,626);
				sample(SFXRustDoorClose,Gactorpos);
				float(_set,CommandTimer,7);
			}
			if(VKeyObjFrame==13 && CommandTimer==7)
			{
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					float(_or,VarBit,Help16);
					vector(_set,Gactorpos,-3279,53,745);
					sample(SFXRadGlassOff,Gactorpos);
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(ClrAllCollisionBuffers);

					float(_set,CommandTimer,8);
				}
			}
			if(VKeyObjTriggered==0 && CommandTimer==8)
			{
				if(VAIClass==_AIClassCop && VRank==_RankCommander)
				{
					float(_or,OHelpVar,Help11);
					float(_set,CommandTimer,0);
				}
			}
		}

		CurEnvTrigger("workcon");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarBit&=Help16)
			{
				if(VAICon==0)
				{
					call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassCop,_GreaterEqual,_RankCommander);
					if(TmpFloat==0)
					{
						call(ActivateButton,"Commander Called",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						float(_set,WarningBit,0);
						float(_clr,VarBit,Help16);
						float(_set,CommandTimer,0);
					}
					else
					{
						call(ActivateButton,"No Commander Needed At This Level.",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				else
				{
					call(ActivateButton,0,-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
			}
			else
			{
				call(ActivateButton,"No Commander Needed At This Level.",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}
			direction(_clr,_DIRaction);
		}				
		
		if(VAICon!=0)
		{
			if(WarnSeq==4)
			{
				CurEnvTrigger("copcheck");
				if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassCop && VAIState!=_AIstateConfused)
				{
					dmessage("We warned you ! ATTACK !",70,80);
					call(AIchangeplayertoenemy);
					float(_set,WarnSeq,5);
				}
			}
			
			if(OHelpVar&=Help11)
			{
				if(VAIClass==_AIClassWorker)
				{
					CurEnvTrigger("workin");
					if(VTrigger==_DIREnvTrigger)
					{
						if(Varbit&!=Help16 && VPathID==1)
						{
							call(AIfindpathwithspecificid,97);
						}
					}
					else
					{
						if(VarBit&!=Help16 && VPathID==1)
						{
							float(_clr,OHelpVar,Help11);
							call(AIfindpathwithspecificid,97);
						}
					}
							

					CurEnvTrigger("workout");
					if(VTrigger==_DIREnvTrigger && VTrigger!=_DIRForward)
					{
						if(VarBit&=Help16)
						{
							if(VPathID==97)
							{
								call(AIfindpathwithspecificid,1);
							}
						}
						else
						{
							float(_clr,OHelpVar,Help11);
						}
					}
				}
			}

			CurEnvTrigger("copcheck");
			if(WarnSeq<3 && VarBit&!=Help06)
			{
				if(VTrigger==_DIREnvTrigger)
				{
					if(VAIClass==_AIClassCop && VRank==_RankSergeantM && VPathID==3)
					{
						if(Vaction!=CopGesture2 && VAction!=CopDizzy)		//no, don't gesture when you're being RADIATED mseeks!
						{
							spawnaction(CopGesture2);
						}
					}
				}
			}
			if(WarningBit==1)
			{
				CurEnvTrigger("copcheck");
				if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassCop && VState!=StateDead && VAIState!=_AIstateConfused)
				{
					vector(_set,Gactorpos,-3588,129,1354);
					if(WarnSeq==0 && VarBit&=Help06)
					{
						ClearDMessage();
						dmessage("This is as far as you go@ halflife...",100,180);
						sample(SFXWarning01,Gactorpos);
						float(_set,WarnSeq,1);					
						float(_clr,VarBit,Help06);
					}
					if(WarnSeq==1 && VarBit&=Help06)
					{
						ClearDMessage();
						dmessage("You've got no business with the commander",100,180);
						sample(SFXWarning02,Gactorpos);
						float(_set,WarnSeq,2);					
						float(_clr,VarBit,Help06);
					}
					if(WarnSeq==2 && VarBit&=Help06)
					{
						ClearDMessage();
						dmessage("What's the big idea@ fool ?",100,180);
						sample(SFXWarning03,Gactorpos);
						float(_set,WarnSeq,3);					
						float(_clr,VarBit,Help06);
						call(AIchangeplayertoenemy);
					}
				}
			}
		}

		CurEnvTrigger("diecheck");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);
		}
	}
	elseif(vcurset=="s1r10")
	{
		if(HelpVar&!=Help19)
		{
			call(CDFade,100,60);
			float(_or,HelpVar,Help19);
		}
	

		CurEnvTrigger("organic");
		if(VTrigger==_DIREnvTrigger && VAICon==0)
		{
			if(RadChecked==0)
			{
				CurEnvTriggerSet("s1r8","organic");
				call(KeyObjTrigger,2,1);
				sample(SFXOrganic,-1);
				vector(_set,Gactorpos,-1648,627,2114);
				sample(SFXBigDoorSlamShut,Gactorpos);
				call(ScreenShake,0,10,0,0.8);
				float(_set,RadChecked,1);
			}
		}

		CurEnvTrigger("switch");
		if(Vtrigger==_DIREnvTrigger)
		{
			if(VKeyObjTriggered==0)
			{
				callsub(DoorOpen,1,1);
				float(_clr,VarBit,Help08);
			}
		}
	}
	elseif(VCurSet=="s1r12")
	{
		if(HelpVar&!=Help19)
		{
			call(CDFade,100,60);
			float(_or,HelpVar,Help19);
		}
		if(VAICon==0)								//enemies should not operate the fans
		{
			if(VExpCamera==0)
			{
				call(PlayerInput,1);
			}

			if(VTrigger==_DIRaction)
			{
				float(_set,TmpFloat,VarKey6);		//VarKey has 3 bits for fans 1, 2 and 3 each, "decompressing"
				float(_and,TmpFloat,7);

				float(_set,TmpFloat2,VarKey6);
				float(_shiftright,TmpFloat2,3);
				float(_and,TmpFloat2,7);

				float(_set,TmpFloat3,VarKey6);
				float(_shiftright,TmpFloat3,6);
				float(_and,TmpFloat3,7);			


				CurEnvTrigger("fanbutn1");
				callsub(S1r12Fans,TmpFloat,1);

				CurEnvTrigger("fanbutn2");
				callsub(S1r12Fans,TmpFloat2,2);

				CurEnvTrigger("fanbutn3");
				callsub(S1r12Fans,TmpFloat3,3);

				float(_set,VarKey6,TmpFloat);
				float(_shiftleft,TmpFloat2,3);
				float(_add,VarKey6,TmpFloat2);
				float(_shiftleft,TmpFloat3,6);
				float(_add,VarKey6,TmpFloat3);
			}

			CurEnvTrigger("radmsg");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarBit&=Help14)
				{
					sample(SFXRadiationExposed,Gactorpos);
					float(_clr,VarBit,Help14);
				}
			}
			else
			{
				if(VarBit&!=Help14)
				{
					float(_or,VarBit,Help14);
				}
			}
		}
	}
	elseif(VCurSet=="s1r15")
	{
		if(HelpVar&!=Help19)
		{
			call(CDFade,100,60);
			float(_or,HelpVar,Help19);
		}
		if(Picked==0)
		{
			callsub(PickLiftMsg);
		}

		CurEnvTrigger("lift");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("ELDOOR1");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				callsub(DoorOpen,1,1);
			}
			CurEnvTrigger("ELDOOR2");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				callsub(DoorOpen,1,1);
			}
			if(CameraPan==0)
			{
				float(_set,CameraPan,1);
			}
		}
		else
		{
			float(_set,LiftMsg,1);
		}

		if(VAICon==0)
		{
			if(CameraPan==1)
			{
				callsub(Sub_SetCameraNormal);
			}
			if(CameraPan==0)
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);
			}
		}

		if(VTrigger==_DIRactionhold && VActivateButton==0)
		{
			float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
			CurEnvTrigger("panel1");
			callsub(LiftControl,0,1);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,1);

			CurEnvTrigger("lift");
			if(TmpFloat!=-1 && VKeyObjTriggered==0)			//elevator should be activated
			{
				if(TmpFloat1==1)
				{
					if(TmpFloat==1)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXSectorBase,1);
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXRadiation,1);
					}
				}
				if(VAICON==0)
				{
					call(ActivateButtonSample,SFXValidFunction);
				}
				float(_set,CameraPan,0);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
				direction(_clr,_DIRAction);
			}
		}
	}
	elseif(VCurSet=="s1r16")
	{
		CurEnvTrigger("panel2");
		if(VTrigger==_DIREnvTrigger)
		{
			if(HelpVar&=help06 && TutorialToggle==1 && VAICon==0 && InBattle==0)
			{
				float(_clr,HelpVar,help06);
				ClearTutorialLines();
				AddTutorialLine("To operate a [255:182:5]LIFT@[255:255:255] stand in front of");
				AddTutorialLine("the console and simultaneously press");
				AddTutorialLine("your [20:200:50]ACTION[255:255:255] button and [20:200:50]FORWARD[255:255:255] to go up@");
				AddTutorialLine("or [20:200:50]BACKWARD[255:255:255] to go down.");
				AddTutorialLine(" ");
				AddTutorialLine("On the console@ you will find a floor");
				AddTutorialLine("indicator and direction arrows. ");
				AddTutorialLine("[255:182:5]DOORS[255:255:255] cannot be opened ");
				AddTutorialLine("while the lift is moving.");
				AddTutorialLine(" ");
				AddTutorialLine("  [255:255:0]                     Press Any Key        ");
				AddTutorialLine("  [255:255:0]                     To Continue          ");
				DisplayTutorialScreen("[255:255:20]LIFT COMMANDS",15,15);
			}
		}
		if(Picked==0)
		{
			callsub(PickLiftMsg);
		}
		CurEnvTrigger("lift");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("ELEVDOOR1");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				callsub(DoorOpen,1,1);
			}
			CurEnvTrigger("ELDOOR2");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				callsub(DoorOpen,1,1);
			}
			if(CameraPan==0)
			{
				float(_set,CameraPan,1);
			}
		}
		else
		{
			float(_set,LiftMsg,1);
		}

		if(VAICon==0)
		{
			if(CameraPan==1)
			{
				callsub(Sub_SetCameraNormal);
			}
			if(CameraPan==0)
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);
			}
		}

		if(VTrigger==_DIRactionhold && VActivateButton==0)
		{
			float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
			CurEnvTrigger("panel1");
			callsub(LiftControl,0,1);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,1);

			CurEnvTrigger("lift");
			if(TmpFloat!=-1 && VKeyObjTriggered==0)			//elevator should be activated
			{
				if(TmpFloat1==1)
				{
					if(TmpFloat==1)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXRadiation,1);
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXSectorBase,1);
					}
				}
				if(VAICON==0)
				{
					call(ActivateButtonSample,SFXValidFunction);
				}
				float(_set,CameraPan,0);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
				direction(_clr,_DIRAction);
			}
		}
	}
	elseif(VCurSet=="s1r11")
	{
		if(HelpVar&=Help19)
		{
			call(CDFade,0,60);
			float(_clr,HelpVar,Help19);
		}
		if(VAICon==0)
		{
			/*
			CurEnvTrigger("BobClimb");
			if(VTrigger==_DIREnvTrigger && TutorialToggle==1 && AirLock&=Help08 && InBattle==0)
			{
				ClearTutorialLines();
				AddTutorialLine("[20:250:50]Bob[255:255:255] can grab onto ledges and");
				AddTutorialLine("shimmy left and right. To move");
				AddTutorialLine("to the left or to the right@");
				AddTutorialLine("just press your [20:250:50]LEFT[255:255:255] or [20:250:50]RIGHT[255:255:255]");
				AddTutorialLine("direction key. To climb upon");
				AddTutorialLine("the ledge@ press [20:250:50]FORWARD[255:255:255]. To");
				AddTutorialLine("fall back@ press [20:250:50]BACKWARD[255:255:255].");
				AddTutorialLine(" ");
				AddTutorialLine("    [255:255:100]             Press Any Key       ");
				AddTutorialLine("    [255:255:100]             To Continue         ");
				DisplayTutorialScreen("[255:255:20]Hand-over-hand",15,15);
				float(_clr,AirLock,Help08);
			}
			*/
//			call(CDSwap,2,1,100,60);
			CurEnvTrigger("radmsg");
			if(VTrigger==_DIREnvTrigger)
			{

				if(VarBit&=Help14)
				{
					sample(SFXRadiationExposed,Gactorpos);
					float(_clr,VarBit,Help14);
				}
			}
			else
			{
				if(VarBit&!=Help14)
				{
					float(_or,VarBit,Help14);
				}
			}

			CurEnvTrigger("elec");
			if(VTRigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
			else
			{
				CurEnvTrigger("elec01");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLElectricity);
				}

				else
				{
					CurEnvTrigger("elec02");
					if(VTrigger==_DIREnvTrigger)
					{
						colstate(_or,_COLElectricity);
					}
					else
					{
						CurEnvTrigger("elec03");
						if(VTrigger==_DIREnvTrigger)
						{
							colstate(_or,_COLElectricity);
						}
					}
				}
			}
			CurEnvTrigger("droidbarr");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLElectricity);
			}
		}
		CurEnvTrigger("dropbat");
		if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassDroid)
		{
			CurEnvTriggerSet("s1r13","trapdoor");
			if(VKeyObjTriggered==0)
			{
				float(_clr,OHelpVar,Help12);
				float(_set,timer4,0);
				call(KeyObjTrigger,255,1);
				//kfsample(SFXTrapDoorStart,SFXTrapDoorLoop,SFXTrapDoorStop,-2);
			}
		}
		if(OHelpVar&!=Help12)
		{
			CurEnvTrigger("radmsg");
			if(VTrigger==_DIREnvTrigger)
			{
				float(_add,timer4,1);
				move(0,10,0);
				if(timer4>=20)
				{
					float(_or,OHelpVar,Help12);
					float(_set,timer4,0);
				}
			}
		}

		CurEnvTrigger("droid");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassDroid)
			{
				if(VAICon!=0)
				{
					callsub(DoorOpen,1,1);
				}
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("edgecamd1");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Sub_SetCameraNormal);
			}
			CurEnvTrigger("edgecamd2");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Sub_SetCameraNormal);
			}

			CurEnvTrigger("edgecamu1");
			if(VTrigger==_DIREnvTrigger)
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);
				if(HelpVar&=help07 && TutorialToggle==1 && VAICon==0 && InBattle==0)
				{
					float(_clr,HelpVar,help07);
					ClearTutorialLines();
					AddTutorialLine("[255:182:5]FANS[255:255:255] can help you reach higher");
					AddTutorialLine("ground. The strength of a ");
					AddTutorialLine("[255:182:5]FAN[255:255:255] can vary.");
					AddTutorialLine(" ");
					AddTutorialLine("To use a [255:182:5]FAN[255:255:255]@ fly or jump");
					AddTutorialLine("above it and you will be");
					AddTutorialLine("thrust upward automatically.");
					AddTutorialLine(" ");
					AddTutorialLine("  [255:255:0]           Press Any Key        ");
					AddTutorialLine("  [255:255:0]           To Continue          ");
					DisplayTutorialScreen("[255:255:20]FANS",15,15);
				}
			}
			CurEnvTrigger("edgecamu2");
			if(VTrigger==_DIREnvTrigger)
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);
			}
		}
	}
	elseif(VCurSet=="s1r18")
	{
		vector(_set,GActorPos,-5940,2653,341);
		SamplePlaying(SFXScanHumm,GActorPos);
		if(VTrigger!=_DIRTempFlag)
		{
			Sample(SFXScanHumm,GActorPos);
		}

		vector(_set,GActorPos,-5480,2796,-135);
		SamplePlaying(SFXScanHumm,GActorPos);
		if(VTrigger!=_DIRTempFlag)
		{
			Sample(SFXScanHumm,GActorPos);
		}

		if(VAICon==0)
		{
			CurEnvTrigger("shock");
			vector(_set,TmpVector,50,350,50);
			Call(TriggerBox,TmpVector,0,tmpfloat);
			if(tmpfloat==1)
			{
				colstate(_or,_COLElectricity);
			}
		}

		CurEnvTrigger("BUZBUZ01");
		if(VTrigger==_DIREnvTrigger)
		{
			call(WallBulb,1000);
			call(SetParticleSetID,"s1r18");
			vector(_set,fxvector,0,0,0);
			callsub(sub_shockwave,0,1);
			sample(SFXDistortion,-1);

			if(VarBit&=Help17)
			{
				sample(SFXContaminationBreach,-1);
				float(_clr,VarBit,Help17);
			}
		}
		else
		{
			CurEnvTrigger("BUZBUZ02");
			if(VTrigger==_DIREnvTrigger)
			{
				call(WallBulb,1000);
				call(SetParticleSetID,"s1r18");
				vector(_set,fxvector,0,0,0);
				callsub(sub_shockwave,0,1);
				sample(SFXDistortion,-1);

				if(VarBit&=Help17)
				{
					sample(SFXContaminationBreach,-1);
					float(_clr,VarBit,Help17);
				}
			}
		}

		if(CallBot>=1 && VarBit&=Help13)
		{
			GetNumbActorsInSet("s1r18",_AIClassDroid,TmpFloat);
			if(TmpFloat==0)
			{
				float(_add,CallBot,1);
				if(CallBot>=20)
				{
					if(VAICon==0)
					{
						dmessage("Battery Replacement Engaged",50,150);
					}
					vector(_set,Gactorpos,-5162,4350,1728);
					vector(_set,Gactorangle,0,0,0);
					InitActor(transportbot,Gactorpos,Gactorangle,"S1R18",TRUE,4);			
					CurEnvTrigger("socle");
					call(expset1,145,145,338);
					float(_set,CallBot,0);
				}
			}
		}

		if(VarBit&=Help13)
		{
			float(_set,TmpFloat,0x2267ff);
			CurEnvTrigger("literm01");
			call(expset1,TmpFloat,350,-1);
			call(expset2,TmpFloat,350,-1);
			CurEnvTrigger("literm02");
			call(expset1,TmpFloat,350,-1);
			CurEnvTrigger("socle");
			if(VarKey2==2)
			{
				setkeyframe("s1r18","socle",0);
				float(_set,VarKey2,3);
			}
			if(VarKey2>2)
			{
				float(_add,varkey2,1);
				if(vrnd<5)
				{
					vector(_set,Gactorpos,-5479,2513,-134);
					spawnparticle(fx_windmatter,-1,Gactorpos,emptyvector,-1);
				}
				if(VarKey2>=200)
				{
					call(KeyObjTrigger,255,1);
					float(_set,VarKey2,0);
				}
			}

			CurEnvTrigger("col01");
			if(VAICon==0 && VTrigger==_DIREnvTrigger && VAIClass!=_AIClassScientist)
			{
				vector(_settoactorpos,TmpVector);
				vector(_settotriggerpos,TmpVector1);
				vector(_sub,TmpVector,TmpVector1);
				vector(_normalize,TmpVector);
				vector(_setplanetrignvec,TmpVector);

				colstate(_or,_COLelectricity);
			}
			else
			{
				CurEnvTrigger("col02");
				if(VAICon==0 && VTrigger==_DIREnvTrigger && VAIClass!=_AIClassScientist)
				{
					vector(_settoactorpos,TmpVector);
					vector(_settotriggerpos,TmpVector1);
					vector(_sub,TmpVector,TmpVector1);
					vector(_normalize,TmpVector);
					vector(_setplanetrignvec,TmpVector);

					colstate(_or,_COLelectricity);
				}
			}
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			CurEnvTrigger("literm01");
			call(expset1,TmpFloat,10,-1);
			call(expset2,TmpFloat,10,-1);
			CurEnvTrigger("literm02");
			call(expset1,TmpFloat,10,-1);
		}
		
		if(HelpVar&=Help10 && TutorialToggle==1 && VAICon==0 && InBattle==0)
		{
			if(VAICon==0)
			{
				if(VAIClass==_AIClassScientist && VRank==_RankScum)
				{
					float(_clr,HelpVar,help10);						
					ClearTutorialLines();
					AddTutorialLine("Along with his ability to operate");
					AddTutorialLine("specialized machinery@ his containment");
					AddTutorialLine("suit will also protect him from high");
					AddTutorialLine("levels of radiation.");
					AddTutorialLine(" ");
					AddTutorialLine("The [255:182:5]Battery Grabber[255:255:255] is the most common");
					AddTutorialLine("tool used by the Radiation Worker. It allows");
					AddTutorialLine("him to carry the [255:182:5]Energy Battery Cell[255:255:255] (EBC).");
					AddTutorialLine(" ");
					AddTutorialLine("To pick up an [255:182:5]EBC[255:255:255]@ get into [20:250:50]Combat Mode[255:255:255] ");
					AddTutorialLine("and just walk towards the [255:182:5]EBC[255:255:255].");
					AddTutorialLine(" ");
					AddTutorialLine("    [255:255:0]             Press Any Key       ");
					AddTutorialLine("    [255:255:0]             To Continue         ");
					DisplayTutorialScreen("[255:255:20]RADIATION WORKER",15,15);
				}
			}
		}

		CurEnvTrigger("doortrig");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VarBit&=Help13)
			{
				if(VAIClass==_AIClassScientist && VRank==_RankScum)
				{
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
				}
				if(VTrigger==_DIRaction)
				{
					callsub(DoorOpen,1,1);
					setkeyframe("s1r16","lift",1);
				}
			}
			else
			{
				if(VTrigger==_DIRaction)
				{
					sample(SFXAccessDenied,Gactorpos);
					message("Lift Cannot Be Operated During Emergency Procedure",300,10);
				}
			}
		}

		CurEnvTrigger("alarm");
		if(VarBit&=Help13)
		{
			if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger && VAIClass==_AIClassScientist)
			{
				call(ActivateButton,"Emergency Shut Down",-1,FALSE);
				call(ActivateButtonSample,SFXEmergencyShutDown);
				sample(SFXValidFunction,Gactorpos);
				vector(_set,tmpvector,0,-80,-80);
				vector(_set,Gactorpos,-5129,2770,-105);
				spawnlight(LightPulseOmni3,-1,Gactorpos,tmpvector,EmptyVector,600);
				sample(SFXPumpPower,Gactorpos);
				float(_clr,VarBit,Help21);
				float(_clr,VarBit,Help22);
				float(_clr,VarBit,Help23);
				float(_clr,VarBit,Help24);
				float(_clr,VarBit,Help13);
				float(_set,timer4,0);
				CurEnvTrigger("col01");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				CurEnvTrigger("battin");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				direction(_clr,_DIRaction);
				CurEnvTrigger("socle");
				call(expset1,142,142,142);
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("console01");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit&=Help21)
				{
					call(ActivateButton,"Console Power is already on",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				else
				{
					float(_add,timer4,1);
					if(timer4<4)
					{
						sample(SFXStation01,Gactorpos);
					}
					call(ActivateButton,"Restoring Power to Console",-1,FALSE);
					call(ActivateButtonSample,SFXPowerOnline);
					float(_or,VarBit,Help21);
				}
			}
			CurEnvTrigger("console02");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit&=Help22)
				{
					call(ActivateButton,"Console Power is already on",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				else
				{
					float(_add,timer4,1);
					if(timer4<4)
					{
						sample(SFXStation02,Gactorpos);
					}
					call(ActivateButton,"Restoring Power to Console",-1,FALSE);
					call(ActivateButtonSample,SFXPowerOnline);
					float(_or,VarBit,Help22);
				}
			}
		}			
	}
	elseif(VCurSet=="s1r19")
	{
		CurEnvTrigger("BUZBUZ01");
		if(VTrigger==_DIREnvTrigger)
		{
			call(WallBulb,1000);
			call(SetParticleSetID,"s1r19");
			vector(_set,fxvector,0,0,0);
			callsub(sub_shockwave,0,1);
			sample(SFXDistortion,-1);
		}
		else
		{
			CurEnvTrigger("BUZBUZ02");
			if(VTrigger==_DIREnvTrigger)
			{
				call(WallBulb,1000);
				call(SetParticleSetID,"s1r19");
				vector(_set,fxvector,0,0,0);
				callsub(sub_shockwave,0,1);
				sample(SFXDistortion,-1);
			}
		}
		if(VAICon==0)
		{
			if(VarBit&=Help20)
			{
				GetNumbActorsInSet("s1r18",_AIClassScientist,TmpFloat);
				GetNumbActorsInSet("s1r19",_AIClassScientist,TmpFloat1);
				float(_add,TmpFloat,TmpFloat1);
				if(TmpFloat==0)
				{
					float(_set,timer,0);
					float(_clr,VarBit,Help20);
				}
			}
			else
			{
				CurEnvTrigger("spcheck");
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					float(_add,timer,1);
					if(timer>=200)
					{
						vector(_set,Gactorangle,0,1024,0);
						vector(_set,Gactorpos,-5681,2350,1681);
						InitActor(WeaponBatteryGrabber,Gactorpos,Gactorangle,"s1r19");
						vector(_set,Gactorpos,-5681,2301,1681);
						InitActor(RadiationWorker,Gactorpos,Gactorangle,"s1r19",TRUE,3);
						float(_set,Timer,0);
						float(_or,VarBit,Help20);
						callsub(DoorOpen,1,0);		
					}
				}
			}
			CurEnvTrigger("console03");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit&=Help23)
				{
					call(ActivateButton,"Console Power is already on",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				else
				{
					call(ActivateButton,"Restoring Power to Console",-1,FALSE);
					call(ActivateButtonSample,SFXPowerOnline);
					float(_add,timer4,1);
					if(timer4<4)
					{
						sample(SFXStation03,Gactorpos);
					}
					float(_or,VarBit,Help23);
				}
			}
			CurEnvTrigger("console04");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarBit&=Help24)
				{
					call(ActivateButton,"Console Power is already on",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				else
				{
					call(ActivateButton,"Restoring Power to Console",-1,FALSE);
					call(ActivateButtonSample,SFXPowerOnline);
					float(_add,timer4,1);
					if(timer4<4)
					{
						sample(SFXStation04,Gactorpos);
					}
					float(_or,VarBit,Help24);
				}
			}
		}
	}
	elseif(VCurSet=="s1r23")
	{
		CurEnvTrigger("diecheck");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(fall2death);
		}
		else
		{
			if(vaicon==0)
			{
				Camera(450,0);
				Target(CopRun_camera_Tdistance,CopRun_camera_Tangle);
				if(RadAlert==0)
				{
					sample(SFXRadiationExposed,Gactorpos);
					float(_set,RadAlert,1);
				}
			}
			callsub(Scene2RadiationArea);
		}
	}

	elseif(VCurSet=="s1r13")
	{
		if(vaicon==0)
		{
			Camera(450,0);
			Target(CopRun_camera_Tdistance,CopRun_camera_Tangle);
			if(RadAlert==0)
			{
				sample(SFXRadiationExposed,Gactorpos);
				float(_set,RadAlert,1);
			}
		}
		callsub(Scene2RadiationArea);
	}
	elseif(VCurSet=="s1r14")
	{
		CurEnvTrigger("trapdoor");
		callsub(RadiationCheck);

		if(VAIcon==0)
		{
			Camera(450,0);
			Target(CopRun_camera_Tdistance,CopRun_camera_Tangle);
			if(RadAlert==0)
			{
				sample(SFXRadiationExposed,Gactorpos);
				float(_set,RadAlert,1);
			}
		}
		callsub(Scene2RadiationArea);

		CurEnvTrigger("elevdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAIclass==_AIClassScientist && VRank==_RankScum)
			{
				callsub(DoorOpen,1,1);
				setkeyframe("s1r16","lift",0);
			}
			else
			{
				message("Access Denied - Radiation Workers Only");
				sample(SFXAccessDenied,Gactorpos);
			}
		}
		
		CurEnvTrigger("doorout")
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				if(VAIclass==_AIClassScientist && VRank==_RankScum)
				{
					callsub(DoorOpen,1,1);
				}
				else
				{
					message("Access Denied - Radiation Workers Only");
					sample(SFXAccessDenied,Gactorpos);
				}
			}
		}
	}
	if(VCurSet=="s1r20")
	{
		callsub(Scene2RadiationArea);
		if(HelpVar&=Help13 && VAICon==0)
		{
			sample(SFXRadiationExposed,Gactorpos);
			float(_clr,HelpVar,Help13);
		}
		
		if(VAIClass==_AIClassScientist && VAICon!=0)
		{
			if(NeedBattery==2 && RadActionTimer!=0)
			{
				float(_add,RadActionTimer,1);
				if(RadActionTimer>=300)
				{
					call(AIfindpathwithspecificid,2);
					float(_set,RadActionTimer,0);
				}
			}
		}
		if(ExplodeBoxTimer>=1)
		{	
			float(_add,ExplodeBoxTimer,1);
			if(ExplodeBoxTimer>=100)
			{
				if(VAIcon==0)
				{
					message("Capsule Pod Activated",120,10);
				}
				CurEnvTrigger("captrig");
				call(KeyObjTrigger,255,1);
				float(_set,timer3,0);
				float(_set,ExplodeBoxTimer,0);
			}
		}
		if(VarKey3==0)
		{
			CurEnvTrigger("LASERTRIG");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
		}

		CurEnvTrigger("scantrig");
		if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassScientist && VRank==_RankScum && VAICon==0)
		{
			if(MissionLevel3==1)
			{
				message("Access Granted - Ten Seconds Before Closing",200,10);
				CurEnvTriggerSet("s1r2","scantrig");
				call(expset1,23,65,65);
				vector(_set,Gactorpos,-2545,603,7860);
				samplestop(SFXFieldHumLoop,Gactorpos);
				sample(SFXFieldHumStop,Gactorpos);
				float(_set,MissionLevel3,300); //Delay for door to close back
				CurEnvTriggerSet("s1r2","inscan");
				call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
				float(_set,VarKey3,1);
				float(_set,AccessGranted,2);
			}
		}

		CurEnvTrigger("captrig");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VKeyObjTriggered==0 && VKeyObjFrame==0 && ExplodeBoxTimer==0)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				CurEnvTrigger("pro");
				call(KeyObjTrigger,1,1);
				call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				float(_set,ExplodeBoxTimer,1);
			}
		}
		if(VAICon!=0)
		{
			CurEnvTrigger("captrig");
			if(VKeyObjFrame==4)
			{
				CurEnvTrigger("checkif");
				if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassScientist)
				{
					if(VAction!=ScientistCrush)
					{
					//	move(0,3,0);
						spawnaction(ScientistCrush);
					}
				}
			}
			elseif(VKeyObjFrame==8)
			{
				CurEnvTrigger("checkif");
				if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassScientist)
				{
					if(VAction!=ScientistCrush)
					{
						sample(SFXOhGodNo,-1);
					}
				}
			}
			elseif(VKeyObjFrame==12)
			{
				CurEnvTrigger("checkif");
				if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassScientist)
				{
					sample(SFXCrushedReact,-1);
				}
			}
			elseif(VKeyObjFrame==15)
			{
				CurEnvTrigger("checkif");
				if(VTrigger==_DIREnvTrigger)
				{
					KillActor();
				}
			}
		}
		if(timer3==6)
		{
			if(VAIClass==_AIClassScientist && VAICon!=0)
			{
				call(AIfindpathwithspecificid,1);
				float(_set,timer3,0);
			}
		}
	}
	elseif(VCurSet=="s1r22")
	{
		CurEnvTrigger("diecheck");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="s1r24")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("doorout");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				callsub(DoorOpen,1,1);
			}

			CurEnvTrigger("doorin");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			if(ControlTimer==2)
			{
				CurEnvTrigger("doorin");
				if(VSetActive=="s1r9")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("s1r24","doorin",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	//Start in the Sewer
	elseif(VCurSet=="s3_s01" || VcurSet=="s3_s16")
	{
		if(VRunScriptCode!=13 && VAICon==0)
		{
			callsub(DeInitSceneSound2);
			call(RunScriptCode,_clr,2);
			call(RunScriptCode,_or,13);
		}
	}
	//Start in the Outskirts
	elseif(VCurSet=="s3_st07" || VCurSet=="s3_gar01" || VCurSet=="s3_f1b01" || VCurSet=="s3_f1_03")
	{
		if(VRunScriptCode!=4 && VAICon==0)
		{
			callsub(DeInitSceneSound2);
			call(RunScriptCode,_clr,2);
			call(RunScriptCode,_or,4);
		}	
	}
	//Start in Downtown
	elseif(VCurSet=="s2r1" || VCurSet=="s2r5" || VCurSet=="s2r11" || VCurSet=="s2r15")
	{
		if(VRunScriptCode!=3 && VAICon==0)
		{
			callsub(DeInitSceneSound2);
			call(RunScriptCode,_clr,2);
			call(RunScriptCode,_or,3);
		}
	}
	//Start in Laboratory
	elseif(VCurSet=="s3_lab02" || VCurSet=="s3_lab01")
	{
		if(VRunScriptCode!=15 && VAICon==0)
		{
			callsub(DeInitSceneSound2);
			call(RunScriptCode,_clr,2);
			call(RunScriptCode,_or,15);
			float(_set,Poweron,1);
			float(_set,VarKey108,6);
		}
	}
}
