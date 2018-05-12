//*************** SEWER LEVEL ************ (PASTE IN SCENE4.HXX)

//VarBit
//------
//Help01	>	Story Message #9
//Help02	> Chot dwarf get their AI back

#define TICKS_SCAN_NOTICE  5    // scanning message
#define TICKS_SCAN_LIGHT_1 50    // green light 1
#define TICKS_SCAN_LIGHT_2 75    // green light 2
#define TICKS_SCAN_LIGHT_3 100   // green light 3   
#define TICKS_SCAN_LIGHT_4 125   // green light 4
#define TICKS_SCAN_DOOR_OPENS 180   // Door opens
#define TICKS_SCAN_DOOR_OPENED 181   // Door opened


SubRoutine(InitSceneSound13)
{
			if(incoming!=0)
			{
				if(ScriptMark==9)
				{
					callsub(Panel9);
				}
			}
			else
			{
				callsub(ScriptLevel13);
			}

			vector(_set,Gactorpos,-3105,-1016,14872);
			sample(sfxdripfalls,Gactorpos);

			vector(_set,Gactorpos,-6966,-961,15480);
			sample(sfxdripfalls,Gactorpos);

			vector(_set,Gactorpos,-7662,-1328,10968);
			sample(sfxgears,Gactorpos);

			vector(_set,Gactorpos,-6406,-1350,10940);
			sample(SFXWaterSwirl,gactorpos);

			vector(_set,Gactorpos,-7530,-1350,10940);
			sample(SFXWaterSwirl,gactorpos);

			vector(_set,Gactorpos,-8677,-1350,10940);
			sample(SFXWaterSwirl,gactorpos);
			
			vector(_set,Gactorpos,-7749,-744,14672);
			sample(SFXLaserAmbient,gactorpos);

			vector(_set,Gactorpos,-6399,-1194,10569);
			sample(SFXSewerHammer,Gactorpos);

			vector(_set,Gactorpos,-7605,-1194,10564);
			sample(SFXSewerHammer,Gactorpos);

			vector(_set,Gactorpos,-8789,-1194,10569);
			sample(SFXSewerHammer,Gactorpos);

			//s3_s12
			vector(_set,gactorpos,-7670,-880,14573);
			sample(SFXBurningFlesh,Gactorpos);

			//s3_s15
			vector(_set,gactorpos,8152,888,13307);
			sample(SFXChotEatFlesh,Gactorpos);

			vector(_set,Gactorpos,-2448, -1279, 10585);
			sample(SFXDwarfChant,Gactorpos);

			call(CDPlay,3,1);
}

SubRoutine(DeInitSceneSound13)
{
			vector(_set,Gactorpos,-3105,-1016,14872);
			SampleStop(sfxdripfalls,Gactorpos);

			vector(_set,Gactorpos,-6966,-961,15480);
			SampleStop(sfxdripfalls,Gactorpos);

			vector(_set,Gactorpos,-7662,-1328,10968);
			SampleStop(sfxgears,Gactorpos);

			vector(_set,Gactorpos,-6406,-1350,10940);
			SampleStop(SFXWaterSwirl,gactorpos);

			vector(_set,Gactorpos,-7530,-1350,10940);
			SampleStop(SFXWaterSwirl,gactorpos);

			vector(_set,Gactorpos,-8677,-1350,10940);
			SampleStop(SFXWaterSwirl,gactorpos);
			
			vector(_set,Gactorpos,-7749,-744,14672);
			SampleStop(SFXLaserAmbient,gactorpos);

			//s3_s12
			vector(_set,gactorpos,-7670,-880,14573);
			samplestop(SFXBurningFlesh,Gactorpos);

			//s3_s15
			vector(_set,gactorpos,8152,888,13307);
			samplestop(SFXChotEatFlesh,Gactorpos);

			vector(_set,Gactorpos,-6399,-1194,10569);
			SampleStop(SFXSewerHammer,Gactorpos);

			vector(_set,Gactorpos,-7605,-1194,10564);
			SampleStop(SFXSewerHammer,Gactorpos);

			vector(_set,Gactorpos,-8789,-1194,10569);
			SampleStop(SFXSewerHammer,Gactorpos);

			vector(_set,Gactorpos,-2448, -1279, 10585);
			SampleStop(SFXDwarfChant,Gactorpos);
}



/**************************** R O U T I N E S ****************************/

SubRoutine(InitScene13)
{
		if(VScriptInitiated!=13)
		{
			if(VInitScriptCode==0)
			{
				InitActor(Bob1,0,Gactorangle,"S3_s01")
			}

			#include    "messiahscripts\enemies\c1_sewer_e.spt"

//			#include    "messiahscripts\enemies\c1_lab_e.spt"
//			#include    "messiahscripts\enemies\c1_factory_e.spt"

			// Reset all the variables
		    float(_set,VarKey101,0);
			call(loadpreloaddb,7);
			float(_set,VarKey102,0);  //used to light the city model
			float(_set,VarKey103,0);   //if outskirts power is restored
			float(_set,VarKey104,0);  //laser sequence
			float(_set,VarKey105,0);  //flickering lights.
			float(_set,VarKey106,0);  //flickering lights
			float(_set,VarKey107,0);  //falling bridge. (plays sound at correct time and keeps it from looping)
			float(_set,VarKey108,0);  //used for beast activation sequence in lab
			//float(_set,VarKey109,0);  //laser wall in outskirts....do not reset to 0!
			float(_set,VarKey110,1);	//chot beast cutscene
			float(_set,OpenDoor,0);
			float(_set,MissionLevel1,0);
			float(_set,MissionLevel2,0);
			float(_set,MissionLevel3,0);
			float(_set,MissionLevel4,0);
			float(_set,WeaponDelay01,0);
			float(_set,WeaponDelay02,0);
			float(_set,WeaponDelay03,0);
			float(_set,VarBit,AllHelp);
			float(_set,CameraPan,0);
			float(_set,LiftMsg,0);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
			float(_set,timer4,0);
			float(_set,Objective,0);
//			float(_set,PowerOn,0);
		}

		callsub(InitSceneSound13);

		call(ScriptCodeInitiated,13);
}

SubRoutine(MainScene13)
{

/////////////////////////
//// SECTOR 3 SCRIPT ////
/////////////////////////

	//////////////////
	//	VSETACTIVE	//
	//////////////////

	if(RandomSound<0 && VAICon==0)
	{
		float(_rnd2,RandomSound,20);
		float(_add,RandomSound,20);
		if(vrnd<15)
		{
			sample(SFXdrip1,-1);
		}
		elseif(vrnd<30)
		{
			sample(SFXdrip2,-1);
		}
		elseif(vrnd<45)
		{
			sample(SFXdrip3,-1);
		}
		elseif(vrnd<60)
		{
			sample(SFXdrip4,-1);
		}
		elseif(vrnd<75)
		{
			sample(SFXdrip5,-1);
		}
		else
		{
			sample(SFXdrip6,-1);
		}
	}
	else
	{
		float(_sub,RandomSound,1);
	}

	if(VSetActive=="s3_s02")
	{
		CurEnvTriggerSet("s3_s02","flickert");
		if(PowerOn==1);
		{
			if(vrnd<15)
			{
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);				

				if(varkey106==0)
				{
					vector(_set,tmpvector,-2785.83,-752.60,17930.86);
					vector(_set,tmpvector2,150,150,100);
					SpawnLight(perm_light,-1,tmpvector,tmpvector2,EmptyVector,200);
					float(_set,varkey106,1);
				}
			}
			else
			{
				float(_set,tmpfloat,0x333333);
				call(expSet1,1,tmpfloat,0);

				if(varkey106==1)
				{
					vector(_set,gactorpos,-2785.83,-752.60,17930.86);
					KillLight(perm_light,gactorpos,0);	
					float(_set,varkey106,0);
				}
			}
		}
		
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s03")
	{
		CurEnvTriggerSet("s3_s03","sdoor2");
		if(VarKey103==0)
		{
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat);
		}
		else
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat);
		}

		if(PowerOn==1);
		{
			CurEnvTriggerSet("s3_s03","flickert");
			if(vrnd<15)
			{
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);	

				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);  //light is visible

				if(varkey105==0)
				{
					vector(_set,tmpvector,-4595.59,-490.44,16971.82);
					vector(_set,tmpvector2,150,150,0);
					SpawnLight(perm_light,-1,tmpvector,tmpvector2,EmptyVector,500);
					float(_set,varkey105,1);
				}

				if(vrnd<10)
				{			
					vector(_set,gactorpos,-4552.24,-302.05,16939.71);
					spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
				}
			}
			else
			{
				float(_set,tmpfloat,0x333333);
				call(expSet1,1,tmpfloat,0);		

				if(varkey105==1)
				{
					vector(_set,gactorpos,-4595.59,-490.44,16971.82);
					KillLight(perm_light,gactorpos,0);	
					float(_set,varkey105,0);
				}

				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);  //light is invisi
	
			}
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s04")
	{
		CurEnvTriggerSet("s3_s04","coptrig");
		call(ExpSet1,-2,0,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s10");
	{
		if(PowerOn==1)
		{
			CurEnvTriggerSet("s3_s10","flickert");
			if(vrnd<15)
			{
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);  //make visible	

				if(varkey105==0)
				{
					vector(_set,tmpvector,-9097.06,-712.89,13649.07);
					vector(_set,tmpvector2,150,150,0);
					SpawnLight(perm_light,-1,tmpvector,tmpvector2,EmptyVector,450);
					float(_set,varkey105,1);
				}
			}
			else
			{
				float(_set,tmpfloat,0x333333);
				call(expSet1,1,tmpfloat,0);
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);  //make invisible

				if(varkey105==1)
				{
					vector(_set,gactorpos,-9097.06,-712.89,13649.07);
					KillLight(perm_light,gactorpos,0);	
					float(_set,varkey105,0);
				}
			}
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s12")
	{
	
//		CurEnvTriggerSet("s3_s12","sdoor1");
//		call(ExpSet2,-2,0,0);

		call(SetParticleSetID,"S3_s12");
		if(VarKey104<2)
		{
			vector(_set,gactorpos,-7460,-880,14573);
			vector(_set,gactorine,-7670,-880,14573);
			callsub(LaserStrip,gactorpos,gactorine,fx_yellow,0);

			vector(_set,gactorpos,-7670,-880,14573);
			spawnparticle(fx_flare,-1,gactorpos,emptyvector,fx_coplaserflarered);
			if(vrnd<20)
			{
				vector(_set,gactorine,0,15,0);
				spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);
			}

			vector(_set,gactorpos,-7460,-830,14573);
			vector(_set,gactorine,-8075,-830,14573);
			callsub(LaserStrip,gactorpos,gactorine,fx_yellow,0);

			vector(_set,gactorpos,-7460,-780,14573);
			vector(_set,gactorine,-8075,-780,14573);
			callsub(LaserStrip,gactorpos,gactorine,fx_yellow,0);

			vector(_set,gactorpos,-7460,-730,14573);
			vector(_set,gactorine,-8075,-730,14573);
			callsub(LaserStrip,gactorpos,gactorine,fx_yellow,0);

			vector(_set,gactorpos,-7460,-680,14573);
			vector(_set,gactorine,-8075,-680,14573);
			callsub(LaserStrip,gactorpos,gactorine,fx_yellow,0);

			vector(_set,gactorpos,-7460,-630,14573);
			vector(_set,gactorine,-8075,-630,14573);
			callsub(LaserStrip,gactorpos,gactorine,fx_yellow,0);

			vector(_set,gactorpos,-7460,-580,14573);
			vector(_set,gactorine,-8075,-580,14573);
			callsub(LaserStrip,gactorpos,gactorine,fx_yellow,0);
		}

		if(VarKey103==0)
		{
			CurEnvTriggerSet("s3_s12","sdoor1");
			float(_set,TmpFloat,0xff0000);
			call(expset1,1,TmpFloat,0);
		}
		else
		{
			CurEnvTriggerSet("s3_s12","sdoor1");
			float(_set,TmpFloat,0x00ff00);
			call(expset1,1,TmpFloat,0);
		}

		if(VarKey104==2)
		{
	/*
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
				vector(_set,Gactorpos,-7468,-777,14373);
				vector(_add,gactorpos,tmpvector);
				SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);

				vector(_set,tmpvector,238,177,10);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,100);
			}
	*/

		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s13")
	{
		CurEnvTriggerSet("s3_s13","SDOOR1");
		float(_set,TmpFloat,0x00FF00);
		call(expSet1,1,TmpFloat,0);

		CurEnvTriggerSet("s3_s13","SDOOR2");
		float(_set,TmpFloat,0x00FF00);
		call(expSet1,1,TmpFloat,0);

		//flickering light
		if(PowerOn==1)
		{
			CurEnvTriggerSet("s3_s13","flickert");
			if(vrnd<15)
			{
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);  //make visible

				if(varkey106==0)
				{
					vector(_set,tmpvector,-5926.70,-601.32,17102.13);
					vector(_set,tmpvector2,150,150,0);
					SpawnLight(perm_light,-1,tmpvector,tmpvector2,EmptyVector,350);
					float(_set,varkey106,1);
				}

			}
			else
			{
				float(_set,tmpfloat,0x333333);
				call(expSet1,1,tmpfloat,0);
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);  //make invisible	

				if(varkey106==1)
				{
					vector(_set,gactorpos,-5926.70,-601.32,17102.13);
					KillLight(perm_light,gactorpos,0);	
					float(_set,varkey106,0);
				}
			}
		}

	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_s14")
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("Door1");
			if(VSetActive=="s3_st01")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_s14","door1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s14")
	{
		CurEnvTriggerSet("s3_s14","door1");
		if(VarKey103==0)
		{
			float(_set,TmpFloat,0xFF0000); //set door lights to red
			call(expSet1,1,TmpFloat,0);
		}
		else
		{
			float(_set,TmpFloat,0x00FF00);  // set door lights to green
			call(expSet1,1,TmpFloat,0);
		}

		if(PowerOn==1)
		{
			if(vrnd<15)
			{
				CurEnvTriggerSet("s3_s14","flickert");					
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);

				CurEnvTriggerSet("s3_s14","flickert2");
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);	
			}
			else
			{
				CurEnvTriggerSet("s3_s14","flickert");
				float(_set,tmpfloat,0x333333);
				call(expSet1,1,tmpfloat,0);
		
				CurEnvTriggerSet("s3_s14","flickert2");
				float(_set,tmpfloat,0x333333);
				call(expSet1,1,tmpfloat,0);
			}
		}

		CurEnvTriggerSet("s3_s16","DoorLite");
		if(VarKey103==0)
		{
			CurEnvTriggerSet("s3_s16","DoorLite");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
		}
		else
		{	
			CurEnvTriggerSet("s3_s16","DoorLite");
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s15")
	{
		if(VarKey103==0)
		{
			CurEnvTriggerSet("s3_s15","computer");
			float(_set,tmpfloat,0xFFFF00);
			call(expSet1,1,tmpfloat,0);
		}
		else
		{
			CurEnvTriggerSet("s3_s15","computer");
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);	
		}

		if(VarKey103==0)
		{
			CurEnvTriggerSet("s3_s15","street09");
			float(_set,TmpFloat,0x020202);
			call(expset1,TmpFloat,10,-1);
			call(expset2,TmpFloat,10,-1);

			CurEnvTriggerSet("s3_s15","street10");
			float(_set,TmpFloat,0x020202);
			call(expset1,TmpFloat,10,-1);
		}
		elseif(VarKey103==2)
		{
			float(_add,timer3,1);
			if(timer3==10)
			{
				CurEnvTriggerSet("s3_s15","street01");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==20)
			{
				CurEnvTriggerSet("s3_s15","street01");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==30)
			{
				CurEnvTriggerSet("s3_s15","street02");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==40)
			{
				CurEnvTriggerSet("s3_s15","street02");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);

			}
			if(timer3==50)
			{
				CurEnvTriggerSet("s3_s15","street03");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==60)
			{
				CurEnvTriggerSet("s3_s15","street03");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==70)
			{
				CurEnvTriggerSet("s3_s15","street04");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==80)
			{
				CurEnvTriggerSet("s3_s15","street04");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==90)
			{
				CurEnvTriggerSet("s3_s15","street05");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==100)
			{
				CurEnvTriggerSet("s3_s15","street05");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==110)
			{
				CurEnvTriggerSet("s3_s15","street06");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==120)
			{
				CurEnvTriggerSet("s3_s15","street06");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==130)
			{
				CurEnvTriggerSet("s3_s15","street07");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3>=140)
			{
				float(_set,VarKey103,3);
				float(_set,timer3,0);
			}
		}

		if(VarKey103==3)
		{
			CurEnvTriggerSet("s3_s15","street09");
			float(_set,TmpFloat,0x00ff22);
			call(expset1,TmpFloat,450,-1);
			call(expset2,TmpFloat,450,-1);

			CurEnvTriggerSet("s3_s15","street10");
			float(_set,TmpFloat,0x00ff22);
			call(expset1,TmpFloat,450,-1);

			CurEnvTriggerSet("s3_s15","street07");
			float(_set,TmpFloat,0xffffff);
			call(expset2,1,TmpFloat,0);

			CurEnvTriggerSet("s3_s15","street08");
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			call(expset2,1,TmpFloat,0);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_s16")
	{
	//	CurEnvTriggerSet("s3_s16","DoorLite");
	//	if(VarKey103==0)
	//	{
	//		float(_set,tmpfloat,0xFF0000);
	//		call(expSet1,1,tmpfloat,0);
	//	}
	//	else
	//	{	
	//		float(_set,tmpfloat,0x00FF00);
	//		call(expSet1,1,tmpfloat,0);
	//	}
	}
	//----------------------------------------------------------------


	if(VSetActive=="s3_s17")
	{
		if(PowerOn==1)
		{
			CurEnvTriggerSet("s3_s17","flickert");
			if(vrnd<15)
			{
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);
			}
			else
			{
				float(_set,tmpfloat,0x333333);
				call(expSet1,1,tmpfloat,0);
			}
		}
	}
	//----------------------------------------------------------------


	///////////////
	//	VCURSET	 //
	///////////////


	if(VCurSet=="s3_s15")
	{
		CurEnvTrigger("computer");
		if(VKeyObjFrame>=3 && VarKey103==1)
		{
			float(_set,timer3,0);
			float(_set,VarKey103,2);	
		}

		if(VarKey103==0)
		{
			CurEnvTrigger("street01");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);

			CurEnvTrigger("street02");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);

			CurEnvTrigger("street03");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);

			CurEnvTrigger("street04");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);

			CurEnvTrigger("street05");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);

			CurEnvTrigger("street06");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);

			CurEnvTrigger("street07");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_s05")
	{
		if(VSetActive=="s3_s06" && VSetInMemory!="s3_s08" && varkey101==0)
		{
			call(ForceLoadSet,"s3_s08");
			float(_set,varkey101,1);
		}
		elseif(VSetInMemory=="s3_s08" && varkey101==1)
		{
			float(_set,varkey101,0);
		}
	}
	elseif(VCurSet=="s3_s08")
	{
		if(ControlTimer==1)
		{
			float(_set,varkey101,0); 
		}
	}
}




SubRoutine(BackgroundTriggerChecksScene13)
{

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel13); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(VCurSet=="s3_s01")
	{
	//	float(_set,VarKey105,3);

		if(Objective==0)
		{
			sample(SFXSmellReact,-1);
			float(_set,Objective,1);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_s03")
	{	
//		if(VAICon==0)
//		{
//			if(VSetActive=="s3_s04" && VSetInMemory!="s3_s14" && varkey101==0)
//			{
//				call(ForceLoadSet,"s3_s14");
//				float(_set,varkey101,2);
//			}
//			elseif(VSetActive=="s3_s14" && varkey101==2)
//			{
//				float(_set,varkey101,0);
//			}
//		}

		CurEnvTrigger("sdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAICON==0)
			{
				if(VarKey103==0)
				{
					message("Door locked from inside",120,10);
					sample(SFXLockedSound,-1);
				}

				else
				{
					if(VSetActive!="S3_s13" && ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						direction(_clr,_DIRaction);
					}
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("sdoor2");
			if(VSetActive=="S3_s13")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_s03","sdoor2",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="S3_S04B")
	{
		CurEnvTrigger("doorout");
		if(VKeyObjTriggered==0 && VKeyObjFrame==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			call(ForceLoadSet,"s3_s08");
			call(ForceLoadSet,"s3_s14");
			call(ForceLoadSet,"s3_s05");
			call(ForceLoadSet,"s3_s12");
			call(ForceLoadSet,"s3_s06");
			call(ForceLoadSet,"s3_s15");
			callsub(DoorOpen,3,1);
			direction(_clr,_DIRaction);				
		}
	}

	//----------------------------------------------------------------
	

	elseif(VCurSet=="S3_S10")
	{
		CurEnvTrigger("yikes");
		float(_seti,TmpFloat2,VColFeetSphereSize);
		vector(_set,tmpvector,100,5,160);
		call(TriggerBox,tmpvector,tmpfloat2,tmpfloat);

		if(tmpfloat==1 && varkey107==0)
		{
				call(keyobjtrigger,255,1);

				vector(_set,Gactorpos,-9216.01,-1072.15,13493.33);
				sample(SFXRustDoorOpen,Gactorpos);

				float(_set,varkey107,1);
		}

		if(varkey107>0 && varkey107<20)
		{
			float(_add,varkey107,1);
		}

		if(varkey107==20)
		{
			vector(_set,Gactorpos,-9052.30,-1348.64,13645.63);
			sample(SFXSplash,Gactorpos);	

			float(_set,varkey107,21);
		}

		CurEnvTrigger("CLOSESFX");
		if(VTrigger==_DIREnvTrigger && varkey107==21 && VAIClass==_AIClassAngel)
		{
			sample(SFXBob_Close,-1);
			float(_set,VarKey107,22);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="S3_S11")
	{
		if(aivisiontoggle==1)
		{
			float(_set,aivisiontoggle,0);
		}
	}
	
	//----------------------------------------------------------------

	elseif(VCurSet=="S3_S12")
	{
		CurEnvTrigger("stop");
		if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassChot && varkey104<1)
		{
			callsub(Sub_AIGetBackToIdle);
			call(AIOrder,_or,_AIstateGuard);
			call(AIOrder,_or,_AIstayonpath|_AIinspecialmode);		
		}

		if(MissionLevel2==0)				
		{									
			float(_set,aivisiontoggle,1);
		}
		if(VarKey104==1)
		{
			float(_add,timer3,1);
			if(timer3>=70)
			{
				vector(_set,gactorpos,-7670,-880,14573);
				samplestop(SFXBurningFlesh,Gactorpos);
				vector(_set,Gactorpos,-7749,-744,14672);
				samplestop(SFXLaserAmbient,gactorpos);
				sample(SFXLaserOff1,-1);
				float(_set,timer3,0);
				float(_set,VarKey104,2);
			}
		}
		if(VarKey104==3)
		{
			float(_add,timer3,1);
			if(timer3>=70)
			{
				vector(_set,gactorpos,-7670,-880,14573);
				sample(SFXBurningFlesh,Gactorpos);
				vector(_set,Gactorpos,-7749,-744,14672);
				sample(SFXLaserAmbient,gactorpos);
				float(_set,timer3,0);
				float(_set,VarKey104,0);
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("SDOOR1");
			if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{								
				if(VarKey103>=1)
				{
					if(VSetActive!="S3_s13" && ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("Insufficient Power.",120,10);
					sample(SFXAccessDenied,-1);
				}			
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("sdoor1");
			if(VSetActive=="S3_s13")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_s12","sdoor1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	

		CurEnvTrigger("switch");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
					if(VarKey104==0)
					{
						call(ActivateButton,"Laser Deactivated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						float(_set,timer3,0);
						float(_set,VarKey104,1);
					}
					else
					{
						call(ActivateButton,"Laser Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						float(_set,Varkey104,3);
					}

			}
		}

		if(varkey104<1)
		{
			CurEnvTrigger("lzrzapn");
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

			CurEnvTrigger("lzrzapo");
			if(Vtrigger==_DirEnvTrigger)
			{
				if(Vclass==_ClassAngel && VState==StateCrouching)
				{
					sample(SFXSmallSparks02,-1);
				}
				else
				{
					colstate(_or,_Colelectricity);
				}
			}

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
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="S3_S13")
	{	
		if(aivisiontoggle==1)
		{
			float(_set,aivisiontoggle,0);  //vision on
		}
	
		CurEnvTrigger("sdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				direction(_clr,_DIRaction);
			}
		}
		CurEnvTrigger("sdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			float(_set,VarKey102,0);
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				direction(_clr,_DIRaction);
			}
			direction(_clr,_DIRaction);
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("sdoor1");
			if(VSetActive=="S3_s12")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_s13","sdoor1",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("sdoor2");
			if(VSetActive=="S3_s03")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_s13","sdoor2",1);
				call(KeyObjTrigger,255,1);
			}
		}


		if(RandomSound<0 && VAICon==0)
		{
			float(_rnd2,RandomSound,20);
			float(_add,RandomSound,20);
			if(vrnd<15)
			{
				sample(SFXdrip1,-1);
			}
			elseif(vrnd<30)
			{
				sample(SFXdrip2,-1);
			}
			elseif(vrnd<45)
			{
				sample(SFXdrip3,-1);
			}
			elseif(vrnd<60)
			{
				sample(SFXdrip4,-1);
			}
			elseif(vrnd<75)
			{
				sample(SFXdrip5,-1);
			}
			else
			{
				sample(SFXdrip6,-1);
			}
		}
		else
		{
			float(_sub,RandomSound,1);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="S3_S14")
	{
		//	if(VarKey103>0)	
	//	{
			CurEnvTrigger("Door1");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VarKey103>0)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						call(RunScriptCode,_or,4);

						//test
						call(ForceGlobalRealloc);
						call(ForceLoadSet,"s3_st01");
						call(ForceLoadSet,"s3_st01a");
						call(ForceLoadSet,"s3_st01b");
						call(ForceLoadSet,"s3_st02a");

						direction(_clr,_DIRaction);
					}
				}
				else
				{
					message("insufficient power.",210,10);
				}

			}

			if(VKeyObjTriggered==0 && VRunScriptCode==4 && VAICon==0)
			{
				callsub(DeInitSceneSound4);
				call(RunScriptCode,_clr,4);
				float(_set,LinkGlobal,0);

			}	
	//	}


		CurEnvTrigger("gate1416");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(VarKey103>=1)
			{
				CurEnvTriggerSet("s3_s16","doorlite");
				call(KeyObjTrigger,255,1);
				kfsample(SFXDoop9,-1,-1,-1,1);
			}
			else
			{
				message("Insufficient Power.",210,10);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_s15")
	{
		if(VAICon!=0 && VAIClass==_AIClassChot && Vaction==ChotEatCop)
		{
			SamplePlaying(SFXFatCrush,-1);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXFatCrush,-1);	
			}
		}
		if(VAICon==0)
		{
			if(VarKey103!=0 && VarBit&=Help01 && timer3>=80)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,9);
				callsub(Panel9);
				ClearDMessage();
				float(_clr,VarBit,Help01);
			}

			CurEnvTrigger("what");
			if(VTrigger==_DIREnvTrigger)
			{
				float(_set,AIVisionToggle,0);
			}

			CurEnvTrigger("computer");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction);
			{
				if(VarKey103==0)
				{
					call(ActivateButton,"Outskirts Power Restored.",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,8,1,-1);
					call(KeyObjActiveSegment,4,8);
					sample(SFXPowerRestored,emptyvector);
					float(_set,AIVisionToggle,0);
					float(_set,VarKey103,1);
					float(_set,PowerOn,1);
				}
				else
				{
					call(ActivateButton,"Power Already Restored",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
			}

			CurEnvTrigger("memo");
			if(VTrigger==_DIREnvTrigger && VAIcon==0 && MissionLevel2==0)
			{
				float(_set,MissionLevel2,1);
			}
			
			CurEnvTrigger("memo01")
			if(VTrigger==_DIREnvTrigger && VAIcon==0 && MissionLevel2==0)
			{
				float(_set,MissionLevel2,6);
				float(_set,aivisiontoggle,0);
			}
		}

		CurEnvTrigger("check");
		if(VTrigger==_DIREnvTrigger && VAICon!=0 && MissionLevel2==1 && AIVisionToggle!=0)
		{
			call(PlayerInput,0);
			CutScene("choteat");
			float(_set,MissionLevel2,2);
		}

		if(MissionLevel2==2 && VCutSceneFrameEqual==125)
		{
			if(VAIClass==_AIClassChot)
			{
				sample(SFXChotGrunt,-1);
				float(_set,MissionLevel2,3);
			}
		}
		if(MissionLevel2==3 && VCutSceneFrameEqual==230)
		{
			if(VAIClass==_AIClassChot && Vaction==ChotEatCop)
			{
				spawnaction(ChotStandUpFromEat);
				vector(_set,gactorpos,8152,888,13307);
				samplestop(SFXChotEatFlesh,Gactorpos);
				float(_set,MissionLevel2,4);
			}
		}
		if(MissionLevel2==4 && VCutSceneFrameEqual==325)
		{
			call(PlayerInput,1);
			float(_set,MissionLevel2,5);
			float(_set,timer3,0);
		}
		if(MissionLevel2==5)
		{
			float(_add,timer3,1);
			if(timer3>=50)
			{
				float(_set,aivisiontoggle,0);
				float(_set,MissionLevel2,6);
				float(_set,timer3,0);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_s17")
	{


/*		CurEnvTrigger("slamdoor");
		if(VTrigger==_DIREnvTrigger && VAICon==0)
		{
			if(VarKey110&=1)
			{
				CurEnvTrigger("opendoor");
				if(VKeyObjFrame!=1)
				{
					call(KeyObjTrigger,1,1);
					sample(SFXRustDoorClose,Gactorpos);
				}
			}
		}

		CurEnvTrigger("opendoor");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey110&=1)
			{
				message("Door Locked",120,10);
				sample(SFXAccessDenied,Gactorpos);
			}
			else
			{
				if(VKeyObjFrame==1)
				{
					call(KeyObjTrigger,2,1);
				}
			}
		}
*/

		if(VAICon==0 && VarKey110&=1)
		{
			if(VCutScene==0)
			{
				if(VarKey110&=2)
				{
					float(_and,VarKey110,0xfffffc);
					call(PlayerInput,1);
					float(_clr,VarKey110,1);
				}
				else
				{
					CurEnvTrigger("SEQTRIG");
					if(VTrigger==_DIREnvTrigger)
					{
						call(ChangeSniperMode,0,1);
						CutScene("chotbeh");
						call(PlayerInput,0);
						float(_or,VarKey110,2);
					}
				}
			}
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="s3_s18")
	{
		if(VAICon==0)
		{
			if(VarKey110&=1)
			{
				if(VCutScene==0)
				{
					if(VarKey110&=2)
					{
						float(_and,VarKey110,0xfffffc);
						call(PlayerInput,1);
						float(_clr,VarKey110,1);
					}
				}
			}
			if(VarBit&=Help02)
			{
				if(VAIClass==_AIClassChot && VRank==_RankGeneral && VAction!=GENPossesed)
				{
					call(AIchangeenemytofriend);
					float(_set,timer,1);
					float(_clr,VarBit,Help02);
				}
			}
		}


		if(VAICon!=0)
		{
			if(VarKey110&=1)
			{
				Direction(_clr,_DIRright|_DIRleft|_DIRforward|_DIRbackward|_DIRsideleft|_DIRsideright|_DIRjump|_DIRMove);
				ActorFlag(_or,_AFLAGnoai|_AFLAGnorotation);
				call(AIorder,_or,_AIinspecialmode|_AInomove|_AInoturn);
			}
			elseif(VRank==_RankGeneral)
			{
				ActorFlag(_clr,_AFLAGnoai|_AFLAGnorotation);
				call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				if(VarKey110&!=4)
				{
					float(_or,VarKey110,4);
					vector(_set,Gactorpos,-2448, -1279, 10585);
					SampleStop(SFXDwarfChant,Gactorpos);
				}
			}

			if(VarBit&!=Help02)
			{
				if(timer>0)
				{
					float(_add,timer,1);
					if(timer>=80)
					{
						ActorFlag(_clr,_AFLAGnoai|_AFLAGnorotation);
						call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
					}
					if(timer>=100)
					{
						float(_set,timer,0);
					}
				}
			}				

			if(VCutScene!=0)
			{
				if(VAIClass==_AIclasschot)
				{
					if(VRank==_RankGeneral)
					{
						if(VCutSceneFrameEqual==30)
						{
							call(AIcheckfortarget,10);
							SpawnAction(ChotBehEatSlow);
						}
					}
					//elseif(VCutSceneFrame>10 && VAction!=DwarfWorship)
					//{
					//	SpawnAction(DwarfWorship);
					//}
				}
			}

			if(VActor==ChotDwarf && VarBit&=Help02)
			{
				if(VAction!=DwarfWorship)
				{
					SpawnAction(DwarfWorship);
				}
			}
		}
	}


//----------------------------------------------------------------
}  //END SEWER SCRIPT
//----------------------------------------------------------------

