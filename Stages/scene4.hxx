//*********** SECTOR 3 SECTION *****************

#define TICKS_SCAN_NOTICE  5    // scanning message
#define TICKS_SCAN_LIGHT_1 50    // green light 1
#define TICKS_SCAN_LIGHT_2 75    // green light 2
#define TICKS_SCAN_LIGHT_3 100   // green light 3   
#define TICKS_SCAN_LIGHT_4 125   // green light 4
#define TICKS_SCAN_DOOR_OPENS 180   // Door opens
#define TICKS_SCAN_DOOR_OPENED 181   // Door opened

/***************************** G L O B A L S *****************************/

//VarKey101	- 0 prebroke, 1 stuck/broke, 2 stuck/fixed, 3 normal
               
//VarKey102	- Chot attack in s3_st07 (1 spawns then)
//VarKey103	- Outskirts lights turned on - Door in s3_s12 unlocked
//VarKey104	- Laserbeam on/off in sewer
//VarKey105	- 
//			  0 : Player is in sewer (sound samples change)
//			  1 : Player is in Street/Factory
//			  2 : Player is in Laboratory	
//VarKey106	- Open Lab Door
//varkey107	- Special Security Door in Street 07
//varkey108	- Activate the Behemoth Creation
//VarKey109	- Laserwall in s3_f1_b01
//VarKey110 - status bits
//				bit 0 - chotbehemoth sequence not executed yet
//				bit 1 - chotbehemoth sequence is executing
//				bit 2 - chotbehemoth sequence, has stopped the chant sample
//VarBit
//------
//Help01	> Story Message #10

SubRoutine(InitSceneSound4)
{
		if(incoming!=0)
		{
			if(ScriptMark==10)
			{
				callsub(Panel10);
			}
		}
		else
		{
			callsub(ScriptLevel4);
		}	
			//s3_st07
		//removed cause the tank is dead.
		//	vector(_set,Gactorpos,10858,30,16998);
		//	sample(SFXTankIdle,Gactorpos);

			//s3_f1_02
			vector(_set,Gactorpos,8409,726,20631);
			sample(SFXDroidHover,Gactorpos);

			//s3_f1_01
			vector(_set,gactorpos,7186,720,20250);
			sample(SFXElecAmbient,Gactorpos);	

			//s3_b1f03
			vector(_set,gactorpos,8455,-407,18749);
			sample(SFXRedRoom,Gactorpos);

		call(CDPlay,7,1);

}


SubRoutine(DeInitSceneSound4)
{
			//s3_st07
			vector(_set,Gactorpos,10858,30,16998);
			SampleStop(SFXTankIdle,Gactorpos);

			//s3_f1_02
			vector(_set,Gactorpos,8409,726,20631);
			SampleStop(SFXDroidHover,Gactorpos);

			//s3_f1_01
			vector(_set,gactorpos,7186,720,20250);
			SampleStop(SFXElecAmbient,Gactorpos);	

			//s3_b1f03
			vector(_set,gactorpos,8455,-407,18749);
			SampleStop(SFXRedRoom,Gactorpos);
}



SubRoutine(InitScene4)
{
		if(VScriptInitiated!=4)
		{
			if(VInitScriptCode==0)
			{
				InitActor(Bob1,0,Gactorangle,"S3_s14")
			}

//			#include    "messiahscripts\enemies\c1_sewer_e.spt"
//			#include    "messiahscripts\enemies\c1_lab_e.spt"
			#include    "messiahscripts\enemies\c1_factory_e.spt"

			call(loadpreloaddb,6);
			// Reset all the variables
			float(_set,VarKey101,0);  //elevator
			float(_set,VarKey102,0);  //ambush
			//float(_set,VarKey103,0);  //outskirts power
			float(_set,VarKey104,0);  //laserbeam and timer for acces door in st07 (don't worry, it is set back to 0)
			float(_set,VarKey105,0);
			float(_set,VarKey106,0);
			float(_set,VarKey107,0);  //cop door
			float(_set,VarKey108,0);
			float(_set,VarKey109,0);
			float(_set,VarKey110,1);
			float(_set,OpenDoor,0);
			float(_set,VarBit,AllHelp);
			float(_set,Res03,AllHelp);
			float(_set,MissionLevel1,0);
			float(_set,MissionLevel2,0);
			float(_set,MissionLevel3,0);
			float(_set,MissionLevel4,0);
			float(_set,WeaponDelay01,0);
			float(_set,WeaponDelay02,0);
			float(_set,WeaponDelay03,0);
			float(_set,CameraPan,0);
			float(_set,LiftMsg,0);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
			float(_set,timer4,0);
			float(_set,rocketattack,0);
		}

		callsub(InitSceneSound4);

		call(ScriptCodeInitiated,4);
}


SubRoutine(MainScene4)
{

///////////////////
//// OUTSKIRTS ////
///////////////////

	//////////////////
	//	VSETACTIVE	//
	//////////////////

	if(VSetActive=="S3_f1_01")
	{
		CurEnvTriggerSet("s3_f1_01","doorout");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);


		call(SetParticleSetID,"S3_f1_01");
		if(VarKey109==0)
		{
			CurEnvTriggerSet("s3_f1_01","lite01");
			float(_set,TmpFloat,0xff2200);
			call(expset1,TmpFloat,600,-1);
			call(expset2,TmpFloat,600,-1);

			CurEnvTriggerSet("s3_f1_01","lite02");
			float(_set,TmpFloat,0xff2200);
			call(expset1,TmpFloat,600,-1);
			call(expset2,TmpFloat,600,-1);

			CurEnvTriggerSet("s3_f1_02","check");
			call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
			if(TmpFloat==TRUE)
			{	
				float(_set,VarKey109,1);
				CurEnvTriggerSet("s3_f1_02","check");
				call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			}
			vector(_set,gactorpos,7186,911,19955);
			vector(_set,gactorine,7186,911,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			vector(_set,gactorpos,7186,840,19955);
			vector(_set,gactorine,7186,840,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			vector(_set,gactorpos,7186,780,19955);
			vector(_set,gactorine,7186,780,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			vector(_set,gactorpos,7186,720,19955);
			vector(_set,gactorine,7186,720,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			vector(_set,gactorpos,7186,660,19955);
			vector(_set,gactorine,7186,660,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			vector(_set,gactorpos,7186,600,19955);
			vector(_set,gactorine,7186,600,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			vector(_set,gactorpos,7186,540,19955);
			vector(_set,gactorine,7186,540,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			vector(_set,gactorpos,7186,480,19955);
			vector(_set,gactorine,7186,480,20550);
			callsub(ElectricStrip,gactorpos,gactorine,fx_red);

			if(vrnd<20)
			{
				vector(_set,gactorpos,7212,900,20526);
				vector(_set,tmpvector,255,0,0);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);

				vector(_set,gactorpos,7212,900,19959);
				vector(_set,tmpvector,255,0,0);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);
			}
		}
		else
		{
			CurEnvTriggerSet("s3_f1_02","check");
			if(VKeyObjTriggered!=0 && VKeyObjFrame<8)
			{
				call(KeyObjTrigger,12,1,-1);
				call(KeyObjActiveSegment,8,12);
			}
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f1_02")
	{
		CurEnvTriggerSet("s3_f1_02","doordn");
		float(_set,tmpfloat,0x00FF00);  //green
		call(expSet1,1,tmpfloat,0);

		call(SetParticleSetID,"s3_f1_02");
		if(varkey109==0)
		{
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
				vector(_set,Gactorpos,8409,726,20631);
				vector(_add,gactorpos,tmpvector);
				SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);

				vector(_set,tmpvector,20,150,250);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);
			}
		}
		else
		{
			if(vrnd<20)
			{
				vector(_set,Gactorpos,8398,736,20739);
				vector(_set,gactorine,0,8,0);
				spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

				vector(_set,Gactorpos,8398,692,20739);
				spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

				vector(_set,Gactorpos,8398,774,20739);
				spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);
			}
		}

		//code to blow up the entire bot.  
		CurEnvTriggerSet("s3_f1_02","bot1");
		call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
		if(TmpFloat==TRUE)
		{
			CurEnvTriggerSet("s3_f1_02","bot2");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			CurEnvTriggerSet("s3_f1_02","bot3");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			CurEnvTriggerSet("s3_f1_02","bot4");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			CurEnvTriggerSet("s3_f1_02","bot5");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			CurEnvTriggerSet("s3_f1_02","bot6");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			CurEnvTriggerSet("s3_f1_02","bot7");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
		}


	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f1_03")
	{
		CurEnvTriggerSet("s3_f1_03","lift");
		float(_set,TmpFloat,0x777711);  // brown-green
		float(_set,TmpFloat2,0xffff000); // yellow
		float(_set,TmpFloat1,0xff7722);   // orange
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator	


		CurEnvTriggerSet("s3_f1_03","doorup");
		if(VKeyObjTriggered!=0)
		{
			setkeyframe("s3_f1_03","doorup01",0);
			CurEnvTriggerSet("s3_f1_03","doorup01");
			call(KeyObjTrigger,255,1);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f1_04");
	{
		CurEnvTriggerSet("s3_f1_04","fake");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);
		call(expSet2,1,tmpfloat,0);

		CurEnvTriggerSet("s3_f1_04","doorup");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f1_05");
	{
		CurEnvTriggerSet("s3_f1_05","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f1b01")
	{
		CurEnvTriggerSet("s3_f1b01","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);


		call(SetParticleSetID,"s3_f1b01");
		float(_add,timer,1);

		CurEnvTriggerSet("s3_f1b01","lift");
		if(VKeyObjFrame==3 && VKeyObjTriggered==0 && VarKey101<5)
		{
			CurEnvTriggerSet("s3_f1b01","inup");
			if(VTrigger==_DIREnvTrigger && VAICon==0)
			{
				CurEnvTriggerSet("s3_f1b01","lift");
				float(_set,TmpFloat,0x888800);
				float(_set,TmpFloat1,0x880000);
   				call(expset1,1,TmpFloat); //lift arrowsw
   				call(expset2,1,TmpFloat1); //floor indicator
				float(_set,VarKey101,5);
			}
		}
		if (VarKey101==1 && VKeyObjTriggered==0 && VKeyObjFrame!=0) // is elevator in broken state?
		{
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
				vector(_set,Gactorpos,6185,-658,16333);
				vector(_add,gactorpos,tmpvector);
				SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);

				vector(_set,tmpvector,238,177,10);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,100);
			}
			if(timer==10 && vrnd<30)
			{
				vector(_set,Gactorpos,6200,-658,16333);
				spawnparticle(fx_smallexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
				sample(SFXVentSmall,Gactorpos);
			}
			if(timer==15 && vrnd<50)
			{
				vector(_set,Gactorpos,6220,-670,16333);
				spawnparticle(fx_smallexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
				sample(SFXVentSmall,Gactorpos);
			}
			if(timer==30 && vrnd<50)
			{
				vector(_set,Gactorpos,6185,-658,16333);
				spawnparticle(fx_smallexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
				sample(SFXVentSmall,Gactorpos);
			}

			#define BROKE_COLOR1  0x000000   //shouldn't these be up at the top with the other defines??
			#define BROKE_COLOR2  0xff0000
			if (timer&=16)
			{
      			float(_set,TmpFloat,BROKE_COLOR1);  
			}
			else
			{
      			float(_set,TmpFloat,BROKE_COLOR2);  
			}
   			call(expset1,1,TmpFloat); //lift arrowsw
   			call(expset2,1,TmpFloat); //floor indicator
			if(timer==3)
			{
				message("System Malfunction",120,10);
				sample(SFXMechanicalFailure,-1);
				sample(SFXLiftBroken,-1);
				vector(_set,Gactorpos,6388,-551,16351);
				sample(SFXBazookaExplode,Gactorpos);
				sample(SFXGlobeIdle,Gactorpos);
			}
			if(timer==5)
			{
				vector(_set,tmpvector,250,159,8);
				vector(_set,Gactorpos,6639,-67,16886);
				spawnlight(LightPulseOmni4,-1,Gactorpos,tmpvector,EmptyVector,50);

				vector(_set,Gactorpos,6180,-67,16886);
				spawnlight(LightPulseOmni4,-1,Gactorpos,tmpvector,EmptyVector,50);

				vector(_set,Gactorpos,6180,-67,16369);
				spawnlight(LightPulseOmni4,-1,Gactorpos,tmpvector,EmptyVector,50);

				vector(_set,Gactorpos,6639,-67,16369);
				spawnlight(LightPulseOmni4,-1,Gactorpos,tmpvector,EmptyVector,50);
			}
			if(timer>=65)
			{
				float(_set,timer,4);
			}
		}
		else
		{
   			float(_set,TmpFloat,0x888822);  // light gray
   			float(_set,TmpFloat1,0xffff00) ; // green
   			call(expset1,4,TmpFloat,TmpFloat1); //lift direction
   			float(_set,TmpFloat,0x880000);  // dark gray
   			float(_set,TmpFloat2,0xff0000); // white
   			call(expset2,3,TmpFloat,TmpFloat2); //floor indicator
			if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Sub Basement",120,10);
				float(_set,LiftMsg,0);
			}
			if(VKeyObjFrame==3 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Operations Level",120,10);
				float(_set,LiftMsg,0);
			}
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f1b04")
	{	
		CurEnvTriggerSet("s3_f1b04","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f2_01")
	{	
		CurEnvTriggerSet("s3_f2_01","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------
	
	if(VSetActive=="s3_f2_0A")
	{																		
		if(VsetActive!="s3_f2_03" && LottoTimer==0)
		{
			call(ForceLoadSet,"s3_f2_03");
			float(_set,LottoTimer,7);
		}
		elseif(VSetInMemory=="s3_f2_03" && LottoTimer==7)
		{
			float(_set,LottoTimer,0);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_f2_03")
	{
		CurEnvTriggerSet("s3_f2_03","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_gar01")
	{
		CurEnvTriggerSet("s3_gar01","gardor1");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_gar02")
	{
		CurEnvTriggerSet("s3_gar02","doordn");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_gar02","gardor2");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_gar03")
	{
		CurEnvTriggerSet("s3_gar03","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_gar03","doordn");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_gar03","lift");
		float(_set,TmpFloat,0x777711);  // brown-green
		float(_set,TmpFloat2,0xffff000); // yellow
		float(_set,TmpFloat1,0xff7722);   // orange
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator
		if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Tank Garage",120,10);
			float(_set,LiftMsg,0);
		}
		if(VKeyObjFrame==3 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Factory Level",120,10);
			float(_set,LiftMsg,0);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st01")
	{
		CurEnvTriggerSet("s3_st01","door1001");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_st01","door1");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st02");
	{
		CurEnvTriggerSet("s3_st02","doordn");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st02a")
	{
		CurEnvTriggerSet("s3_st02a","doordn");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st03")
	{
		CurEnvTriggerSet("s3_st03","door1");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
		call(expSet2,1,tmpfloat,0);

		CurEnvTriggerSet("s3_st03","door1");
		if(VKeyObjFrame==2)
		{
			CurEnvTriggerSet("s3_st03","invis");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);

			CurEnvTriggerSet("s3_st04","invis");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
		}
		else
		{
			CurEnvTriggerSet("s3_st03","invis");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);

			CurEnvTriggerSet("s3_st04","invis");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st04")
	{
		CurEnvTriggerSet("s3_st04","door1");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_st04","door2");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_st04","gardor1");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_st04","gardor2");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st05")
	{
		CurEnvTriggerSet("s3_st05","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("s3_st05","door1005");  
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st06")
	{
		CurEnvTriggerSet("s3_st06","fake");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);
		call(expSet2,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st07")
	{
		CurEnvTriggerSet("s3_st07","closed");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);

		if(vrnd<50)
		{
			vector(_set,GactorPos,10811.51,166.03,17181.64);
			vector(_set,gactorine,0,15,0);
			spawnparticle(fx_Steam,-1,gactorpos,gactorine,-1);
		}

		if(vrnd<10)
		{
			vector(_set,GactorPos,10811.51,146.03,17181.64);
			vector(_set,gactorine,0,15,0);
			spawnparticle(fx_Steampipes,-1,gactorpos,gactorine,-1);
			
		}		

		if(varkey107==4)
		{
			if(varkey104>0 && varkey104<30)
			{
				float(_add,varkey104,1);
			}
				

			if(varkey104==30)
			{
				float(_set,TmpFloat,0xff0000);

				CurEnvTrigger("lock02");
				call(expset1,TmpFloat,120,-1);
				call(expset2,TmpFloat,120,-1);

				CurEnvTrigger("lock03");
				call(expset1,TmpFloat,120,-1);
				call(expset2,TmpFloat,120,-1);

				CurEnvTrigger("lock04");
				call(expset1,TmpFloat,120,-1);
				call(expset2,TmpFloat,120,-1);

				CurEnvTrigger("lock05");
				call(expset1,TmpFloat,120,-1);
				call(expset2,TmpFloat,120,-1);
					
				float(_set,varkey104,31);
				float(_set,timer4,1);
			}
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="s3_st10")
	{
		CurEnvTriggerSet("s3_st10","doorup");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	///////////////
	//	VCURSET	 //
	///////////////

	if(VCurSet=="s3_f2_01")  //mainscene
	{	
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_f2_01","doorup");
			if(VSetActive=="s3_st10")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_f2_01","doorup",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}

	elseif(VCurSet=="s3_f2_03")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_f2_03","doorup");
			if(VSetActive=="S3_gar03")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_f2_03","doorup",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}

	elseif(VCurSet=="s3_f1b01") //mainscene
	{
		CurEnvTriggerSet("s3_f1b01","lift");
		if(VKeyObjFrame==0)
		{
			CurEnvTriggerSet(s3_f1b01","button");
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}
		else
		{
			CurEnvTriggerSet("s3_f1b01","button");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
		}

		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_f1b01","doorup");
			if(VSetActive=="S3_f1_04" && VSetInMemory=="s3_f1_05")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_f1b01","doorup",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
			
	elseif(VCurSet=="s3_st07")  //mainscene
	{
		call(SetParticleSetID,"s3_st07");
		if(vrnd<20)
		{
			vector(_set,gactorpos,10889,226,17299
			vector(_set,gactorine,0,8,8);
			spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);
		}

		if(varkey107==0)
		{
			//setting radius and color of omniattach
			CurEnvTrigger("lock02");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,200,-1);
			call(expset2,TmpFloat,200,-1);

			CurEnvTrigger("lock03");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,200,-1);
			call(expset2,TmpFloat,200,-1);

			CurEnvTrigger("lock04");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,200,-1);
			call(expset2,TmpFloat,200,-1);

			CurEnvTrigger("lock05");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,200,-1);
			call(expset2,TmpFloat,200,-1);

			float(_set,varkey107,1);
		}
		
		if(OpenDoor==1)
		{
			//			CurEnvTrigger("doorup");
			CurEnvTrigger("DoorHold");
			call(KeyObjTrigger,255,1);
			kfsample(SFXDoOp2,SFXDoMo2,-1,SFXDoCl2);
			float(_set,OpenDoor,0);
		}

		if(varkey107>=1)
		{
			// Make sound when door hits full open position
			CurEnvTrigger("doorup");
			if (VKeyObjFrame==1 && timer4==TICKS_SCAN_DOOR_OPENED)
			{
				sample(SFXLatch2,Gactorpos);
				float(_add,timer4,1);
			}

			if(varkey107==2 || varkey107==3) // is in trigger and not already identified as "access denied" character?
			{
				//print ("Scanning");
				float(_set,TmpFloat,0x00ff55);
				if(timer4<=TICKS_SCAN_DOOR_OPENS)
				{
					float(_add,timer4,1);
				}
				if(timer4==TICKS_SCAN_NOTICE)
				{
					message("Scanning In Process",120,10);
					sample(SFXScanning,Gactorpos);
				}
				if(timer4==TICKS_SCAN_LIGHT_1)
				{
					CurEnvTrigger("lock02");
					call(expset1,TmpFloat,120,-1);
					call(expset2,TmpFloat,120,-1);
					sample(SFXRipple,Gactorpos);
				}
				if(timer4==TICKS_SCAN_LIGHT_2)
				{
					CurEnvTrigger("lock03");
					call(expset1,TmpFloat,120,-1);
					call(expset2,TmpFloat,120,-1);
					sample(SFXRipple,Gactorpos);
				}
				if(timer4==TICKS_SCAN_LIGHT_3)
				{
					CurEnvTrigger("lock04");
					call(expset1,TmpFloat,120,-1);
					call(expset2,TmpFloat,120,-1);
					sample(SFXRipple,Gactorpos);
				}
				if(timer4==TICKS_SCAN_LIGHT_4)
				{
					CurEnvTrigger("lock05");
					call(expset1,TmpFloat,120,-1);
					call(expset2,TmpFloat,120,-1);
					sample(SFXRipple,Gactorpos);

					if(varkey107==2)  // Check if Was scanned as a COP
					{
						message("Personnel Scanned - Access Granted",120,10);
						float(_set,OpenDoor,1);
						sample(SFXLatch2,Gactorpos);
					}
					else  // Was NOT scanned as a COP
					{
						message("Personnel Scanned - Access DENIED",120,10);

						float(_set,varkey107,4);   // make scanner unwind
/*

						float(_set,TmpFloat,0xff0000);

						CurEnvTrigger("lock02");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);

						CurEnvTrigger("lock03");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);

						CurEnvTrigger("lock04");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);

						CurEnvTrigger("lock05");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);

*/
					}
				}
			}
			elseif(varkey107==1) 
			{
				CurEnvTrigger("doorup");
				if(VKeyObjFrameNoShift==0) // Is door closed
				{
					float(_set,TmpFloat,0x000000);
					if(timer4>0)
					{
						if(timer4==TICKS_SCAN_LIGHT_1)
						{
							CurEnvTrigger("lock02");
							call(expset1,TmpFloat,120,-1);
							call(expset2,TmpFloat,120,-1);
							sample(SFXRipple,Gactorpos);
							float(_set,varkey107,1);   // Allow scanner to retrigger
						}
						if(timer4==TICKS_SCAN_LIGHT_2)
						{
							CurEnvTrigger("lock03");

							call(expset1,TmpFloat,120,-1);
							call(expset2,TmpFloat,120,-1);
							sample(SFXRipple,Gactorpos);
						}
						if(timer4==TICKS_SCAN_LIGHT_3)
						{
							CurEnvTrigger("lock04");
							call(expset1,TmpFloat,120,-1);
							call(expset2,TmpFloat,120,-1);
							sample(SFXRipple,Gactorpos);
						}
						if(timer4==TICKS_SCAN_LIGHT_4)
						{
							CurEnvTrigger("lock05");
							call(expset1,TmpFloat,120,-1);
							call(expset2,TmpFloat,120,-1);
							sample(SFXRipple,Gactorpos);
						}
						if (timer4==TICKS_SCAN_DOOR_OPENS)
						{
							sample(SFXLatch2,Gactorpos);
						}
						float(_sub,timer4,1)
					}
				}
				/*
				elseif (VKeyObjFrameNoShift>=0x10000) // if Door is closing
				{
					if (timer4>TICKS_SCAN_DOOR_OPENED) // Just started closing.
					{
						// Turn the door lights yellow to warn that door is closing.
						float(_set,timer4,TICKS_SCAN_DOOR_OPENS);       

						sample(SFXLatch2,Gactorpos);

						float(_set,TmpFloat,0xff1f00);

						CurEnvTrigger("lock02");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);

						CurEnvTrigger("lock03");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);

						CurEnvTrigger("lock04");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);

						CurEnvTrigger("lock05");
						call(expset1,TmpFloat,120,-1);
						call(expset2,TmpFloat,120,-1);
					}   
				}
				*/
			}
		}
	}
	//----------------------------------------------------------------

	if(VCurSet=="s3_st10")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_st10","doorup");
			if(VSetActive=="S3_f2_01")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_st10","doorup",1);
				call(KeyObjTrigger,255,1);
			}
		}

		CurEnvTrigger("arme");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,565,358,17976);
			callsub(DispenserSound);
		}

		CurEnvTrigger("arme01");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,892,358,18347);
			callsub(DispenserSound);
		}

		CurEnvTrigger("arme02");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,1280,358,17990);
			callsub(DispenserSound);
		}
	}
	//----------------------------------------------------------------

	//random dripping sounds
	if(VarKey105==3)
	{
		if(RandomSound<0)
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

	elseif(VCurSet=="s3_gar03") //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_gar03","doorup");
			if(VSetActive=="S3_f2_03")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_gar03","doorup",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("s3_gar03","doordn");
			if(VSetActive=="S3_gar02")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_gar03","doordn",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_05") //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_f1_05","doorup");
			if(VSetActive=="S3_st05")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_f1_05","doorup",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st02") //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_st02","doordn");
			if(VSetActive=="S3_st02a")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_st02","doordn",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st02a")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_st02a","doordn");
			if(VSetActive=="S3_st02")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_st02a","doordn",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st03")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_st03","door1");
			if(VSetActive=="S3_st04")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_st03","door1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st04") //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_st04","gardor2");
			if(VSetActive=="S3_gar02")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_st04","gardor2",1);
				call(KeyObjTrigger,255,1);
			}
		}	
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("s3_st04","gardor1");
			if(VSetActive=="S3_gar01")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_st04","gardor1",1);
				call(KeyObjTrigger,255,1);
			}
		}	
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st05")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_st05","doorup");
			if(VSetActive=="S3_f1_05")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_st05","doorup",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_gar01") //mainscene
	{
		if(controltimer==1)
		{
			CurEnvTriggerSet("s3_gar01","gardor1");
			if(VSetActive=="s3_st04" && VSetInMemory=="s3_st05")
			{
				callsub(dooropen,2,1);
				float(_set,controltimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_gar01","gardor1",1);
				call(keyobjtrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_gar02")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("s3_gar02","doordn");
			if(VSetActive=="S3_gar03")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_gar02","doordn",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("s3_gar02","gardor2");
			if(VSetActive=="S3_st04" && VSetInMemory=="s3_st05")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_gar02","gardor2",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_03")  //mainscene
	{
		if(ControlTimer==2)
		{
			CurEnvTriggerSet("s3_f1_03","doordn");
			if(VSetActive=="S3_f1_02")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("s3_f1_03","doordn",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}

//----------------------------------------------------------------
}
//----------------------------------------------------------------


//	TmpFloat gets the floor number, -1 if nothing should happen
//	TmpFloat1 gets the direction the floor is moving in, 0 if not moving
//
SubRoutine(RepairLiftControl,const(CurFloor),const(NumbFloors))
{
	if(TmpFloat==-1 && VTrigger==_DIREnvTrigger)
	{
		// Direction(_clr,_DIRaction); // Don't clear it hear because panel triggers overlap.

		if(VTrigger==_DIRforward) //if CHARACTER is moving forward
		{
			float(_set,TmpFloat1,1);
			//Direction(_clr,_DIRforward); // clears the move
		}
		elseif(VTrigger==_DIRbackward) // if CHARACTER is moving backward
		{
			float(_set,TmpFloat1,-1);
			//Direction(_clr,_DIRbackward); // clears the move
		}
		else
		{
			float(_set,TmpFloat1,0);
		}

		if(TmpFloat1!=0)
		{
			float(_set,TmpFloat,CurFloor);
			float(_add,TmpFloat,TmpFloat1);

			if(TmpFloat<0 || TmpFloat>NumbFloors)
			{
				float(_set,TmpFloat,-1);
			}
		}
	}
}

SubRoutine(BackgroundTriggerChecksScene4)
{


	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel4); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////	

	if(vcurset=="s3_f2_01")  //bt check
	{
		CurEnvTrigger("doorup");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="s3_st10" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("attack");
		if(VTrigger==_DIREnvTrigger && MissionLevel4==0 && VAICon==0)
		{
			float(_set,RocketAttack,0);

			vector(_set,Gactorangle,0,2048,0);
			vector(_set,Gactorpos,785,1790,19801);
			InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"s3_f2_02");
			vector(_set,Gactorpos,785,1740,19801);
			InitActor(chot,Gactorpos,Gactorangle,"s3_f2_02",TRUE,20);
			
			vector(_set,Gactorangle,0,2048,0);
			vector(_set,Gactorpos,931,1790,19801);
			InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"s3_f2_02");
			vector(_set,Gactorpos,931,1740,19801);
			InitActor(chot,Gactorpos,Gactorangle,"s3_f2_02",TRUE,21);
			
			vector(_set,Gactorangle,0,2048,0);
			vector(_set,Gactorpos,1086,1570,19431);
			InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"s3_f2_02");
			vector(_set,Gactorpos,1086,1520,19431);
			InitActor(chot,Gactorpos,Gactorangle,"s3_f2_02",TRUE,35);
			float(_set,MissionLevel4,1);
		}									
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f2_03")  //bt check
	{
		CurEnvTrigger("doorup");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			setkeyframe("S3_gar03","lift",1);
			
			if(VSetActive!="S3_gar03" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1b03")
	{
		CurEnvTrigger("workspawn");
		if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIClassWorker)
		{
			call(AIfindpathwithspecificid,2);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1b02")
	{
		/*
		GetNumbActorsInSet("s3_f1b02",_AIClassWorker,TmpFloat);
		if(TmpFloat==0)
		{
			GetNumbActorsInSet("s3_f1b01",_AIClassWorker,TmpFloat);
			if(TmpFloat==0 || TmpFloat==1)
			{
				GetNumbActorsInSet("s3_f1b03",_AIClassWorker,TmpFloat);
				if(TmpFloat==0)
				{
					GetNumbActorsInSet("s3_f1b04",_AIClassWorker,TmpFloat);
					if(TmpFloat==0)
					{
						vector(_set,Gactorpos,9508,-597,20082);
						vector(_set,Gactorangle,0,0,0);
						InitActor(worker,Gactorpos,Gactorangle,"S3_f1b04",TRUE,1);
					}
				}
			}
		}
		*/


		CurEnvTrigger("CALLBUTN");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VAICon==0)
		{
		/*
			call(ActivateButton,"Panel Out of Order",-1,FALSE);
			call(ActivateButtonSample,SFXInvalidFunction);
			direction(_clr,_DIRaction);		
			*/
			CurEnvTriggerSet("s3_f1b01","lift");
			if(varkey101>=2)
			{
				if(VKeyObjTriggered==0 && VKeyObjFrame!=0)
				{
					call(ActivateButton,"Elevator called",0,2);
					call(ActivateButtonSample,SFXValidFunction);
					sample(SFXLatch2,Gactorpos);
				}
			}
			else
			{
				if(VarKey101==0)
				{
					call(ActivateButton,"Elevator is Already On That Floor",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				else
				{
					call(ActivateButton,"Elevator is Out Of Order",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}	
		}

		if(VAICon==0)
		{
			CurEnvTrigger("LowCam");
			vector(_set,TmpVector,300,140,1058);
			Call(TriggerBox,TmpVector,0,tmpfloat);
			if(tmpfloat==1)
			{
				Camera(450,0);
				Target(-50,20);
			}
			else
			{
				callsub(Sub_SetCameraNormal);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1b01")  //bt check
	{
		if(VAICon==0)
		{
			GetNumbActorsInSet("s3_f1b01",_AIClassWorker,TmpFloat);
			if(TmpFloat==0 || TmpFloat==1)
			{
				GetNumbActorsInSet("s3_f1b02",_AIClassWorker,TmpFloat);
				if(TmpFloat==0)
				{
					GetNumbActorsInSet("s3_f1b03",_AIClassWorker,TmpFloat);
					if(TmpFloat==0)
					{
						GetNumbActorsInSet("s3_f1b04",_AIClassWorker,TmpFloat);
						if(TmpFloat==0)
						{
							vector(_set,Gactorpos,9508,-597,20082);
							vector(_set,Gactorangle,0,0,0);
							InitActor(worker,Gactorpos,Gactorangle,"S3_f1b04",TRUE,1);
						}
					}
				}
			}
		}

		CurEnvTrigger("button");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			CurEnvTrigger("lift");
			if(VKeyObjFrame==0)
			{
				call(ActivateButton,"Going Up.",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
				call(keyobjtrigger,255,1);		
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
			}

		}

		if(VarKey101==5)
		{
			message("Elevator Seriously Damaged. Maintenance Crew Called.",200,10);
			sample(SFXLiftBroken,Gactorpos);
			float(_set,VarKey101,6);
		}

		CurEnvTrigger("lift");
		if(VKeyObjFrame==1 && VKeyObjTriggered!=0 && MissionLevel2==0)
		{
			vector(_set,Gactorpos,6388,-500,16351);
			sample(SFXLiftGrind,Gactorpos);
			float(_set,MissionLevel2,1);
		}

		if(VKeyObjTriggered==0)
		{
			if(VAICon==0)
			{
				CurEnvTrigger("cchange");
				vector(_set,tmpvector,300,100,300);
				call(TriggerBox,tmpvector,0,tmpfloat);
				if(tmpfloat==1)
				{
					Camera(450,0);
					Target(-50,20);
				}
				else
				{
					callsub(Sub_SetCameraNormal);
				}
			}

			CurEnvTrigger("doorup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VSetActive!="S3_f1_04" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					call(ForceLoadSet,"s3_f1_05");
				}
			}
		}
		else
		{
			Camera(elevator_camera_distance,elevator_camera_angle);
			Target(elevator_camera_Tdistance,elevator_camera_Tangle);
			float(_set,LiftMsg,1);
		}

		if(VTrigger==_DIRactionhold && VActivateButton==0 && VAICon==0)
		{
			if(VarKey101==0 || VarKey101>=2 && VarKey101<5) // not broke yet or stuck/but fixed.
			{
				float(_set,TmpFloat,-1);
				CurEnvTrigger("panel1");
				callsub(RepairLiftControl,0,3);
				CurEnvTrigger("threefeet");
				callsub(RepairLiftControl,1,3);
				CurEnvTrigger("sixfeet");
				callsub(RepairLiftControl,2,3);
				CurEnvTrigger("panel2");
				callsub(RepairLiftControl,3,3);

				CurEnvTrigger("lift");
				if(TmpFloat!=-1 && VKeyObjTriggered==0)
				{
      				Direction(_clr,_DIRaction); // clear the direction input
					Direction(_clr,_DIRforward); // clears the move
					Direction(_clr,_DIRbackward); // clears the move
               
					if(VarKey101==0)
					{
						call(ActivateButton,0,2,2); // Get Stuck
					}
					else // (VarKey101>=2)
					{
   						if(TmpFloat1==1) // Is direction up?
   						{
   							call(ActivateButton,0,3,2);
							float(_set,MissionLevel2,0);
   						}
   						else
   						{
   							call(ActivateButton,0,0,2);
   						}
					}
					if(VAICON==0)
					{
						call(ActivateButtonSample,SFXValidFunction);
					}
					float(_set,CameraPan,0);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
					direction(_clr,_DIRAction);
               
					if(VarKey101<3)
					{
						float(_add,VarKey101,1); // advance to next state of repair puzzle
					}   
				}
			}
			else
			{
				float(_set,TmpFloat,-1);
				CurEnvTrigger("sixfeet");
				callsub(RepairLiftControl,2,3);
            
				CurEnvTrigger("lift");
				if(TmpFloat!=-1) // && VKeyObjTriggered==0)
				{
					if(VAICON==0)
					{
						call(ActivateButton,"Mechanical Failure - Notify Maintenance Crew",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				CurEnvTrigger("panel2");
				if(VarKey101>=5 && VTrigger==_DIREnvTrigger)
				{
					call(ActivateButton,"Mechanical Failure - Notify Maintenance Crew",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}  
		}
      
		CurEnvTrigger("Repair");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VarKey101==1 && VAICon==0) // if you're pressing the ACTION key
		{
			if(VAIClass==_AIClassWorker) //check if the CHARACTER's CLASS is : Worker
			{
				if(VWeaponType==WeaponTorch)
				{
					call(ChangeSniperMode,0,1);
					CutScene("camera01");
					float(_set,AiVisionToggle,1);
					float(_set,aitoggle,1);
					call(PlayerInput,0);
					direction(_clr,_DIRaction);
				}
				else
				{
					message("You need a torch to fix the lift control",120,10);
				}
			}
			else
			{
				call(ActivateButton,"I need someone to help me out here !",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}
		}
		if(VCutSceneFrame==3)
		{
			SamplePlaying(SFXweapontorch1,-1);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXweapontorch1,-1);
			}
		}
		if(VCutSceneFrame==19)
		{
			SamplePlaying(SFXweapontorch2,-1);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXweapontorch2,-1);
			}
		}
		if(VCutSceneFrame>=20 && VCutSceneFrame<=23)
		{
			call(ActivateButton,"Welding Cables G-14 to F-27",-1,FALSE);
	//		call(ActivateButtonSample,SFXValidFunction);
			CurEnvTrigger("repair");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,4,1,-1);
				call(KeyObjActiveSegment,0,4);
			}
		}
				
		if(VCutSceneFrame>=70 && VCutSceneFrame<=73)
		{
   			CurEnvTrigger("lift");
			call(KeyObjTrigger,1,-1);
      		sample(SFXLatch2,Gactorpos);
			vector(_set,Gactorpos,6388,-551,16351);
			samplestop(SFXGlobeIdle,Gactorpos);
		    float(_set,varkey101,2);   // make lift workable again.
		}
		if(VCutSceneFrame>=130 && VCutSceneFrame<=133)
		{
			message("Elevator Repaired",120,10);

			SamplePlaying(SFXweapontorch2,-1);
			if(VTrigger==_DIRTempFlag)
			{
				samplestop(SFXweapontorch2,-1);
			}
		}
		if(VCutSceneFrame==160)
		{
			call(CutSceneEnd);
			float(_set,AiVisionToggle,0);
			float(_set,aitoggle,0);
			call(PlayerInput,1);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st06")
	{
		CurEnvTrigger("fake");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("This Door is Melted Shut",120,10);
			sample(SFXSewerPile1,-1);
		}

		//Rolls the barrel if someone kicks it.
		CurEnvTrigger("kickme");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIcon==0 && VAIClass!=_AIClassAngel && VAIClass==_AIClassMale)
			{
				if(VKeyObjFrame==0 && VTrigger==_DIRforward)
				{
					call(KeyObjTrigger,1,1);

					//turn collission off for the invis barrier.  (needs the barrier set as the exp for kickme)
					CurEnvTrigger("kickme");   
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);	
				}
				if(VTrigger==_DIRaction && VKeyObjFrame<=1)
				{
					if(Vaction!=CopKickGeneric)
					{
						spawnaction(CopKickGeneric);
						float(_set,timer2,1);
						float(_set,timer3,0);
						direction(_clr,_DIRaction); // Necessary if character carries a weapon
					}
				}
			}
		}
		if(VKeyObjFrame!=0 && VKeyObjTriggered==0)
		{
			vector(_set,Gactorpos,8139,37,21862);
			samplestop(SFXBarrelRoll,Gactorpos);
		}
		
		if(timer2==1)
		{
			float(_add,timer3,1);
		}
		if(timer3>=5)
		{
			vector(_set,Gactorpos,8139,37,21862);
			sample(SFXBarrelRoll,Gactorpos);
			call(KeyObjTrigger,255,1);
			float(_set,timer2,0);
			float(_set,timer3,0);
		}
		CurEnvTrigger("kickme01");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRforward)
		{
			CurEnvTrigger("kickme");
			if(VKeyObjFrame==1)
			{
				call(KeyObjTrigger,0,-1);
				vector(_set,Gactorpos,8139,37,21862);
				sample(SFXBarrelRoll,Gactorpos);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st10")  //bt check
	{
		CurEnvTrigger("doorup");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{	
			if(VSetActive!="S3_f2_01" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(WeaponDelay01>=1)
		{
			float(_add,WeaponDelay01,1)
			if(WeaponDelay01>=80)
			{
				CurEnvTrigger("arme");
				vector(_set,Gactorpos,565,358,17976);
				vector(_set,Gactorangle,0,0,0);
				InitActor(WeaponMaimer,Gactorpos,Gactorangle,"s3_st10",TRUE);
				call(KeyObjTrigger,255,1);
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);	
				float(_set,WeaponDelay01,0);
			}
		}

		if(WeaponDelay02>=1)
		{
			float(_add,WeaponDelay02,1)
			if(WeaponDelay02>=80)
			{
				CurEnvTrigger("arme01");
				vector(_set,Gactorpos,912,358,18347);
				vector(_set,Gactorangle,0,0,0);
				InitActor(WeaponHarpoon,Gactorpos,Gactorangle,"s3_st10",TRUE);
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
				vector(_set,Gactorpos,1280,358,17990);
				vector(_set,Gactorangle,0,2048,0);
				InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"s3_st10",TRUE);
				call(KeyObjTrigger,255,1);
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);
				float(_set,WeaponDelay03,0);
			}
		}	

		CurEnvTrigger("arme");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,WeaponDelay01,1);
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
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_gar03")  //bt check
	{
		CurEnvTrigger("lift");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("doorup");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				if(VSetActive!="S3_f2_03" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("doordn");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				if(VSetActive!="S3_gar02" && ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
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
						kfsample(-1,-1,-1,SFXSewer,1);
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXTankGarage,1);
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
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_05")  //bt check
	{
		CurEnvTrigger("doorup");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="S3_st05" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_02")
	{
		if(VAICon==0)
		{
			if(Res03&!=Help01)
			{
				call(CDForcePlay,false);
				float(_or,Res03,Help01);
			}
			if(Varbit&=Help01)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,10);
				callsub(Panel10);
				ClearDMessage();
				float(_clr,VarBit,Help01);
			}

			CurEnvTrigger("doordn");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				callsub(DoorOpen,0,1);
				setkeyframe("S3_f1_03","lift",0);
				float(_set,timer2,1);
			}
			call(SetParticleSetID,"s3_f1_03");
			if(VKeyObjTriggered==0 && VKeyObjFrame!=1 && timer2==1)
			{
				vector(_set,Gactorine,0,5,0);
				vector(_set,Gactorpos,7913,602,19325);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
				vector(_set,Gactorpos,8007,602,19325);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
				vector(_set,Gactorpos,8101,602,19325);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
				sample(SFXVent2,gactorpos);
				float(_set,timer2,0);
			}

			if(VRunScriptCode==15) 
			{
				callsub(DeInitSceneSound15);
				call(RunScriptCode,_clr,15);
				//if they are in this room and script15 is running they must have gone back down the elevator
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st01")
	{
		float(_set,VarKey103,100);
		CurEnvTrigger("door1001");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Automatic Lock Has Been Activated. Access Denied",120,10);
			sample(SFXAccessDenied,Gactorpos);
			direction(_clr,_DIRaction);
		}

		CurEnvTrigger("door1");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Automatic Lock Has Been Activated. Access Denied",120,10);
			sample(SFXAccessDenied,Gactorpos);
			direction(_clr,_DIRaction);
		}
		if(VKeyObjTriggered==0 && VRunScriptCode==13 && VAICon==0)
		{
			callsub(DeInitSceneSound13);
			call(RunScriptCode,_clr,13);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st02")  //bt check
	{
		CurEnvTrigger("doordn");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st02a")  //bt check
	{
		CurEnvTrigger("doordn");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st03")  //bt check
	{
		CurEnvTrigger("door1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="S3_st04" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}		
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st04")  //bt check
	{
		/*
		CurEnvTrigger("door2");
		if(VKeyObjFrame==2)
		{
			CurEnvTrigger("invis");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);

			CurEnvTriggerSet("s3_st03","invis");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
		}
		else
		{
			CurEnvTrigger("invis");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);

			CurEnvTriggerSet("s3_st03","invis");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
		}
		*/
		
		
		CurEnvTrigger("door2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Door Is Out Of Order",120,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
			direction(_clr,_DIRaction);
		}
		CurEnvTrigger("gardor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="S3_gar02" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
		CurEnvTrigger("gardor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="S3_gar01" && ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
		CurEnvTrigger("door1");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Door Lock To Automatic",120,10);
			sample(SFXAccessDenied,Gactorpos);
			direction(_clr,_DIRaction);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_st05")  //bt check
	{
		if(RocketAttack==1)
		{
			if(VAIClass==_AIClassCop && VTrigger==_DIRHaveGun && VWeaponType==WeaponBazooka)
			{
				call(AIFindPathWithSpecificID,3);
				float(_set,RocketAttack,2);
			}
		}
		CurEnvTrigger("doorup");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="S3_f1_05" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
		CurEnvTrigger("door1005");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Automatic Lock Has Been Activated. Access Denied",120,10);
			sample(SFXAccessDenied,Gactorpos);
			direction(_clr,_DIRaction);
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_04")
	{
/*                                      //moved to s3_f1_06
		CurEnvTrigger("attack");
		if(VTrigger==_DIREnvTrigger)
		{
			CurEnvTriggerSet("s3_f1_02","check");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,7,1,-1);
				call(KeyObjActiveSegment,0,7);
			}
		}

*/
/*
		CurEnvTrigger("diebitch");
		if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassCop)
		{
			call(AIchangeplayertoenemy);
			sample(SFXCopStopRightThere,-1);
		}
*/
		CurEnvTrigger("doorup");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Elevator Needs Further Repair.",200,10);
			sample(SFXAccessDenied,Gactorpos);
			float(_set,TmpFloat,0xff0000);
			call(expset1,1,TmpFloat,0);
		}

		CurEnvTrigger("fake");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Door Locked From Inside",120,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_06")
	{
		CurEnvTrigger("attack");
		if(VTrigger==_DIREnvTrigger)
		{
			CurEnvTriggerSet("s3_f1_02","check");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,7,1,-1);
				call(KeyObjActiveSegment,0,7);
			}
		}		
	}
	//----------------------------------------------------------------


	elseif(VCurSet=="s3_gar01")  //bt check
	{
		CurEnvTrigger("gardor1");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassCop && VAICon!=0)
			{
				if(controltimer==0)
				{
					call(keyobjtrigger,255,1);
					float(_set,controltimer,1);
					direction(_clr,_DIRAction);
					call(ForceLoadSet,"s3_st05");
				}	
			}

			if(VTrigger==_DIRaction)
			{	
				if(controltimer==0)
				{
					call(keyobjtrigger,255,1);
					float(_set,controltimer,1);
					direction(_clr,_DIRaction);
					call(ForceLoadSet,"s3_st05");
				}	
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_gar02")  //bt check
	{
		CurEnvTrigger("doordn");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			setkeyframe("S3_gar03","lift",0);

			if(VSetActive!="S3_gar03" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
		CurEnvTrigger("gardor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="S3_st04" && ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
				call(ForceLoadSet,"s3_st05");
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_03")  //bt check
	{
		CurEnvTrigger("lift");
		if(VKeyObjTriggered==0)
		{
			callsub(Sub_SetCameraNormal);

			CurEnvTrigger("doorup");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(ControlTimer==0 && VKeyObjTriggered==0)
					{
						if(PowerOn==0)
						{
							call(ForceLoadSet,"s3_lab02");
							float(_set,ControlTimer,1);
							direction(_clr,_DIRaction);
						}
						else
						{
							CurEnvTrigger("Doorup01");
							if(VKeyObjTriggered==0)
							{
								call(ForceLoadSet,"s3_lab02");
								float(_set,ControlTimer,3);
								direction(_clr,_DIRaction);
							}
						}
					}
				}
				if(VSetActive=="s3_lab02" && VAICon==0)
				{
					CurEnvTriggerSet("s3_lab02","DoorUp01");
					if(PowerOn==1)
					{
						if(VKeyObjFrame>=5)
						{
							call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
						}
						else
						{
							call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
						}
					}
					else
					{
						call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					}
				}
			}
			else
			{
				if(VSetActive=="s3_lab02" && VAICon==0)
				{
					CurEnvTriggerSet("S3_lab02","DoorUp01");
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				}
			}

			if(VAICon==0)
			{
				if(Res03&=Help01)
				{
					call(CDForcePlay,true);
					float(_clr,Res03,Help01);
				}
				if(VRunScriptCode!=15)
				{
					callsub(InitSceneSound15);
					call(RunScriptCode,_or,15);
					//load the lab script while waiting for the set to be loaded
				}
			}

			if(ControlTimer==1)
			{
				if(VSetInMemory=="s3_lab02")
				{
					CurEnvTrigger("doorup");
					call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);

					CurEnvTrigger("doorup01");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);

					CurEnvTriggerSet("s3_lab02","doorup");
					call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);

					CurEnvTriggerSet("s3_lab02","doorup01");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);

					CurEnvTrigger("doorup");
					callsub(Dooropen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
				}
			}
			elseif(ControlTimer==3)
			{
				if(VSetInMemory=="s3_lab02")
				{
					CurEnvTrigger("doorup");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);

					CurEnvTrigger("doorup01");
					call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);

					CurEnvTriggerSet("s3_lab02","doorup");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);

					CurEnvTriggerSet("s3_lab02","doorup01");
					call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);

					setkeyframe("s3_f1_03","doorup01",0);
					CurEnvTrigger("doorup01");
					call(KeyObjTrigger,255,1);
					kfsample(SFXLiftGrind,-1,-1,-1)

					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
				}
			}

			CurEnvTrigger("doordn");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VSetActive!="S3_f1_02" && ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}	
			}
		}
		else
		{
			Camera(elevator_camera_distance,elevator_camera_angle);
			Target(elevator_camera_Tdistance,elevator_camera_Tangle);
		}

		CurEnvTrigger("lift");
		if(VTrigger==_DIRactionhold && VActivateButton==0)
		{
//			if(PowerOn==1)
//			{
				float(_set,TmpFloat,-1);
				CurEnvTrigger("panel1");
				callsub(LiftControl,0,1);
				CurEnvTrigger("panel2");
				callsub(LiftControl,1,1);

				CurEnvTrigger("lift");
				if(TmpFloat!=-1 && VKeyObjTriggered==0)
				{
					if(TmpFloat1==1)
					{
						if(TmpFloat==1)
						{
							call(ActivateButton,"Laboratory",TmpFloat,2);
							//if(VarKey113==100)
							//{
							if(VCDTrack!=13 && VLanguage==0)
							{
								call(cdplay,13,0);
								float(_set,VarKey113,101);
							}
							//}
						//	kfsample(-1,-1,-1,SFXSectorBase,1);
						}
					}
					else
					{
						if(TmpFloat==0)
						{
							call(ActivateButton,"Factory Level",TmpFloat,2);
						//	kfsample(-1,-1,-1,SFXRadiation,1);
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
//			}
/*			elseif(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				direction(_clr,_DIRAction);
				if(VAICON==0)
				{
					call(ActivateButton,"Insufficient Power - Activate The Generator",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
*/
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1_01")
	{
		if(varkey109<2)
		{
			vector(_set,gactorpos,7186,720,20250);
			sampleplaying(SFXElecAmbient,gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXElecAmbient,gactorpos);
			}
		}


		CurEnvTrigger("doorout");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Due To Violent Riots@ All Exits To Outside Are Closed",220,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}

		CurEnvTrigger("laserwall");
		if(VTrigger==_DIREnvTrigger && varkey109==0)
		{
			colstate(_or,_COLelectricity);
		}
		if(varkey109==1)
		{
			CurEnvTriggerSet("s3_f1_01","lite01");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,0,-1);
			call(expset2,TmpFloat,0,-1);

			CurEnvTriggerSet("s3_f1_01","lite02");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,0,-1);
			call(expset2,TmpFloat,0,-1);

			message("Laserwall removed",120,10);
			vector(_set,Gactorpos,8409,726,20631);
			sample(SFXPumpPower,Gactorpos);
			vector(_set,gactorpos,7186,720,20250);
			samplestop(SFXElecAmbient,Gactorpos);
			float(_set,varkey109,2);
		}
	}
	//----------------------------------------------------------------
	elseif(VCurset=="s3_f2_09")
	{
		CurEnvTrigger("script01");
		if(VTrigger==_DIREnvTrigger && VAICon==0 && VRunScriptCode==4)
		{
			callsub(DeInitSceneSound4);
			call(RunScriptCode,_clr,4);
			call(RunScriptCode,_or,13);
			dmessage("L O A D I N G . . .",50,2);
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="s3_st07")  //bt check
	{
/*
		if(VAIcon==0)
		{
			if(MissionLevel3==0)
			{
				call(DisplayObjectives);
				float(_set,MissionLevel3,1);
			}
		}

		CurEnvTrigger("dooropen");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VSetActive!="s2r8" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				call(RunScriptCode,_or,3);
				float(_set,LinkGlobal,1);
				direction(_clr,_DIRaction);
			}
		}
		if(VKeyObjTriggered==0 && LinkGlobal==1)
		{
			callsub(DeInitSceneSound3);
			call(RunScriptCode,_clr,3);
			float(_set,LinkGlobal,0);
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("dooropen");
			if(VSetActive=="s2r8")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				setkeyframe("s3_st07","dooropen",1);
				call(KeyObjTrigger,255,1);
			}
		}
*/
		if(VAICon!=0 && VAIClass==_AIClassCop && VTrigger==_DIRcombatmode && Varkey102==0)
		{
			vector(_set,Gactorangle,0,1024,0);
			vector(_set,Gactorpos,10612,850,17512);
			InitActor(WeaponPAK,Gactorpos,Gactorangle,"s3_st07");
			vector(_set,Gactorpos,10612,850,17512);
			InitActor(chot,Gactorpos,Gactorangle,"s3_st07",TRUE,15);

			float(_set,varkey102,1);
		}

		CurEnvTrigger("embush");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAICon==0 && VarKey102==1)
			{
				float(_set,VarKey102,2);
			}
		}

		if(VarKey102==2)
		{
			vector(_set,Gactorangle,0,1024,0);
			vector(_set,Gactorpos,8567,85,21543);
			InitActor(WeaponPAK,Gactorpos,Gactorangle,"s3_st07");
			vector(_set,Gactorpos,8567,30,21543);
			InitActor(chot,Gactorpos,Gactorangle,"s3_st07",TRUE,15);

			vector(_set,Gactorangle,0,1024,0);
			vector(_set,Gactorpos,8215,85,21552);
			InitActor(WeaponPAK,Gactorpos,Gactorangle,"s3_st07");
			vector(_set,Gactorpos,8215,30,21552);
			InitActor(chot,Gactorpos,Gactorangle,"s3_st07",TRUE,16);
			float(_set,VarKey102,3);
		}

		if(vaicon==0 && varkey107>0) // If Door initialized.
		{
   			CurEnvTrigger("doorup");
   			if(VTrigger==_DIREnvTrigger) // If in trigger area
   			{
				
				GetNumbActorsInSet("s3_st07",_AIClassCop,TmpFloat);
				if(TmpFloat==0)
				{
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,10371,-272,16798);
					InitActor(WeaponPumpgun,Gactorpos,Gactorangle,"s3_st07",TRUE,66);
					vector(_set,Gactorpos,10371,-212,16798);
					InitActor(copl,Gactorpos,Gactorangle,"s3_st07",TRUE,66);

					CurEnvTrigger("spcheck");
					callsub(DoorOpen,1,1);
				}
				
				if (varkey107==1 && timer4<=0) // if trigger notice requested 
				{
          			if(VAIClass==_AIClassCop) //check if the CHARACTER's CLASS is : COP
					{
						float(_set,varkey107,2);
					}
					else
					{
      					float(_set,varkey107,3);
					}
				}             
   			}
			else 
			{
  				float(_set,varkey107,1);			 
				float(_set,varkey104,0);
			   
			}
		}   
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="s3_f1b04")
	{
		CurEnvTrigger("doorup");
		if(VAICon==0) // if not computer controlled character and lights are all out.
		{
			if(VTrigger==_DIREnvTrigger) // If in trigger area
			{
				if(VTrigger==_DIRaction) // if you're pressing the ACTION key
				{
					call(KeyObjTrigger,255,1); // run the animation of the object linked to the trigger : call(KeyObjTrigger,EndFrame,Direction)
					kfsample(SFXDoOp1,SFXDoMo1,-1,SFXDoCl1); // Plays sample for the animation KFSample(Startsound, looping sound, static(-1), EndSound)
					direction(_clr,_DIRaction); // clears the ACTION button
				}	   
			}
		}
	}

	elseif(VCurSet=="s3_s01")
	{
		if(VRunScriptCode!=13 && VAICon==0)
		{
			callsub(DeInitSceneSound4);
			call(RunScriptCode,_clr,4);
			call(RunScriptCode,_or,13);
		}
	}

//----------------------------------------------------------------
}  //END OUTSKIRTS SCRIPT
//----------------------------------------------------------------
