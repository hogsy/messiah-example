//ANNXVAR1	- progress bits
//				1	objectives have been displayed
//				2	Lasers turned off (Annx_06)
//				4	Power console Activated	(Annx_07)
//				8	piss off cops

//ANNXVAR2	- level progress indicator (doors locked, flic states, etc.)
//				12	War_rad, Door to annex unlocked
//				13	annx_10, Open door.
//				14	the hammers can be activated in annx_10
//				15	prevent hammer cutscene from happening when hammers are re-activated

//Varbit
//-------
//Help01	> Initiate Flic in Annx_10
//Help02	> Hammer 1 control
//Help03	> Hammer 2 Control
//Help04	> Blood shed for Grinder 1
//Help05	> Blood shed for Grinder 2
//Help06	> Blood shed for Grinder 3
//Help07	> Sound for electric barrier 1
//Help08	> Sound for electric barrier 2
//Help09	> Electric Field 1 toggle
//Help10	> Sensor Lights on the hammers
//Help11	> Bob says "it's hot in here"


SubRoutine(InitSceneSound6)
{
		if(incoming!=0)
		{
			if(ScriptMark==15)
			{
				callsub(Panel15);
			}
		}
		else
		{
			callsub(ScriptLevel6);
		}

		//Annx_07
		vector(_set,Gactorpos,-18901,24160,25517);
		sample(SFXElecAmbient,Gactorpos);

		//Annx_10
		vector(_set,Gactorpos,-21444,24200,26700);
		sample(SFXScanHumm02,Gactorpos);

		vector(_set,Gactorpos,-20100,24423,26680); 
		sample(sfxindustrial6,Gactorpos);

		vector(_set,Gactorpos,-22283,24423,26654); 
		sample(sfxindustrial10,Gactorpos);

		call(CDSwap,11,1,100,60);
}

SubRoutine(DeInitSceneSound6)
{
		//Annx_07

		vector(_set,Gactorpos,-18901,24160,25517);
		samplestop(SFXElecAmbient,Gactorpos);

		//Annx_10
		vector(_set,Gactorpos,-21444,24200,26700);
		samplestop(SFXScanHumm02,Gactorpos);

		vector(_set,Gactorpos,-20100,24423,26680); 
		samplestop(sfxindustrial6,Gactorpos);

		vector(_set,Gactorpos,-22283,24423,26654); 
		samplestop(sfxindustrial10,Gactorpos);
}

SubRoutine(InitScene6)
{
		if(VScriptInitiated!=6)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,1024,0);
				InitActor(Bob1,0,Gactorangle,"annx_01");
			}

			if(Res01==0)
			{
				call(loadpreloaddb,11);
				#include "messiahscripts\enemies\mike.spt"

				// Reset all the variables
				float(_set,ANNXVAR1,0);
				float(_set,ANNXVAR2,0);

				float(_set,CameraPan,0);
				float(_set,LiftMsg,0)
				float(_set,VarBit,AllHelp);
				float(_set,RadAlert,0);
				float(_set,timer,0);
				float(_set,timer2,0);
				float(_set,timer3,0);
			}
		}
		callsub(InitSceneSound6);
		call(ScriptCodeInitiated,6);
}

SubRoutine(MainScene6)
{
		///////////////
		// DOORDELAY //
		///////////////

		if(VCurSet=="ANNX_03")
		{
			if(ControlTimer==10)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_03","OPENDOOR");
				setkeyframe("ANNX_03","OPENDOOR",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_08")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="ANNX_04")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_04","TRIGDOOR1");
				setkeyframe("ANNX_04","TRIGDOOR1",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_06")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="ANNX_05")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_05","TRIGDOOR2");
				setkeyframe("ANNX_05","TRIGDOOR2",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_06")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="ANNX_06")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_06","TRIGDOOR2");
				setkeyframe("ANNX_06","TRIGDOOR2",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_05")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_06","TRIGDOOR1");
				setkeyframe("ANNX_06","TRIGDOOR1",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_04")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="ANNX_08")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_08","OPENDOOR");
				setkeyframe("ANNX_08","OPENDOOR",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_03")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="ANNX_09")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_09","DOORTRIG");
				setkeyframe("ANNX_09","DOORTRIG",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_10")
				{
					callsub(DoorOpen,1,0);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("ANNX_09","DOOR79");
				setkeyframe("ANNX_09","DOOR79",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="ANNX_07")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}

	

		if(ANNXVAR1&=8 && timer>0)
		{
			float(_sub,timer,1)
		}

	
		////////////////
		// VSETACTIVE //
		////////////////

		if(VSetActive=="annx_07")
		{
			if(ANNXVAR1&!=2)
			{
				float(_set,TmpFloat,0xff0000);
			}
			else
			{
				float(_set,TmpFloat,0x000000);
			}
			CurEnvTriggerSet("annx_07","lite01");
			call(expset1,TmpFloat,350,-1);
			call(expset2,TmpFloat,350,-1);
			CurEnvTriggerSet("annx_07","lite02");
			call(expset1,TmpFloat,350,-1);
			call(expset2,TmpFloat,350,-1);
			CurEnvTriggerSet("annx_07","lite03");
			call(expset1,TmpFloat,350,-1);
			call(expset2,TmpFloat,350,-1);
		}
		if(VSetActive=="annx_10")
		{
			if(VarBit&=Help10)
			{
				CurEnvTriggerSet("annx_10","hammer01");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,10,-1);
				CurEnvTriggerSet("annx_10","hammer02");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,10,-1);
				float(_clr,VarBit,Help10);
			}
		}

		////////////////
		//   VCURSET  //
		////////////////

		if(VCurSet=="annx_06")
		{
			CurEnvTrigger("laseroff");
			if(ANNXVAR1&=2)
			{
				call(expset2,42,42,42);
			}

			CurEnvTrigger("arme");
			if(VKeyObjTriggered!=0)
			{
				vector(_set,Gactorpos,-20240,25382,22795);
				callsub(DispenserSound);
			}

			CurEnvTrigger("arme01");
			if(VKeyObjTriggered!=0)
			{
				vector(_set,Gactorpos,-20240,25382,22492);
				callsub(DispenserSound);
			}
		}
		/*
		elseif(VCurSet=="annx_01")
		{
			if(ANNXVAR1&=1)
			{
				call(DisplayObjectives);
				float(_or,ANNXVAR1,1);
			}
		}
		*/
		elseif(VCurSet=="annx_10")
		{
			call(SetParticleSetID,"annx_10");
			if(VarBit&!=Help04)
			{
				float(_add,timer4,1)
				vector(_set,fxvector,-21897,23201,26716);
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
				if(timer4>=50)
				{
					float(_or,VarBit,Help04);
					float(_set,timer4,0);
				}
			}
			if(VarBit&!=Help05)
			{
				float(_add,timer,1)
				vector(_set,fxvector,-20693,23201,26712);
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
				if(timer>=50)
				{
					float(_or,VarBit,Help05);
					float(_set,timer,0);
				}
			}
			if(VarBit&!=Help06)
			{
				float(_add,timer3,1)
				vector(_set,fxvector,-19783,23201,26712);
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
				if(timer3>=50)
				{
					float(_or,VarBit,Help06);
					float(_set,timer3,0);
				}
			}

			if(ANNXVAR2==13)
			{
				CutScene("show");
				float(_set,ANNXVAR2,14);
			}
			elseif(ANNXVAR2==14)
			{
				float(_add,Hudtimer,1);
				if(HudTimer==85)
				{
					CurEnvTrigger("hammer01");
					call(KeyObjTrigger,3,1);
					CurEnvTrigger("hammer02");
					call(KeyObjTrigger,3,1);
					sample(SFXHatchEnd,-1);
				}
				elseif(HudTimer==125)
				{
					float(_clr,VarBit,Help09);
				}
				elseif(HudTimer==160)
				{
					call(CutSceneEnd);
					call(HUDTimerSet,900);
					call(PlayerInput,1);
				}
				elseif(HudTimer==165)
				{
					CurEnvTrigger("doortrig");
					callsub(DoorOpen,1,0);
				}
				elseif(HudTimer>=1065)
				{
					message("Door Closing",120,10);
					float(_set,ANNXVAR2,15);
					float(_set,HudTimer,0);
				}
			}
			
			if(ANNXVAR2>=14)
			{
				CurEnvTrigger("hammer01");
				if(VKeyObjFrame==41 && VKeyObjTriggered==0)
				{
					setkeyframe("annx_10","hammer01",3);
					float(_set,TmpFloat,0x000000);
					call(expset1,TmpFloat,10,-1);
				}

				CurEnvTrigger("hammer02");
				if(VKeyObjFrame==41 && VKeyObjTriggered==0)
				{
					setkeyframe("annx_10","hammer02",3);
					float(_set,TmpFloat,0x000000);
					call(expset1,TmpFloat,10,-1);
				}
			}

			if(VarBit&=Help09)
			{
				vector(_set,Gactorpos,-21444,23863,27152);
				vector(_set,Gactorine,-21444,23863,26246);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_set,TmpVector4,0,80,0);
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
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_laserflickerred,0);
			}

			if(VarBit&=Help01)
			{
				CurEnvTrigger("MASTERTRI");
				call(EXPSet2,0,0,19);
				float(_clr,VarBit,Help01);
			}

			float(_add,timer2,2);

			if(timer2>=650)
			{
				float(_set,timer2,0);
			}

			if(timer2<450)
			{
				if(VarBit&!=Help08)
				{
					vector(_set,Gactorpos,-20693,23201,26712);
					samplestop(SFXElectric2,Gactorpos);
					float(_or,VarBit,Help08);
				}

				if(VarBit&=Help07)
				{
					vector(_set,Gactorpos,-21897,23201,26716);
					sample(SFXElectric2,Gactorpos);
					float(_clr,VarBit,Help07);
				}
								
				// IV
				vector(_set,gactorpos,-22186,23322,26897);
				vector(_set,gactorine,-22186,23322,26489);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				// VII
				vector(_set,gactorpos,-21599,23322,26897);
				vector(_set,gactorine,-21599,23322,26489);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				// X
				vector(_set,gactorpos,-22128,23365,26974);
				vector(_set,gactorine,-21650,23365,26974);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				// V
				vector(_set,gactorpos,-22128,23365,26413);
				vector(_set,gactorine,-21650,23365,26413);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				if(vrnd<20)
				{
					vector(_set,tmpvector,255,220,30);
					vector(_set,Gactorpos,-21906,23434,27050);
					SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
				
					vector(_set,tmpvector,255,220,30);
					vector(_set,Gactorpos,-21906,23434,27050);
					SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
				}
			}
			else
			{
				if(VarBit&!=Help07)
				{
					vector(_set,Gactorpos,-21897,23201,26716);
					samplestop(SFXElectric2,Gactorpos);
					float(_or,Varbit,Help07);
				}
				if(VarBit&=Help08)
				{
					vector(_set,Gactorpos,-20693,23201,26712);
					sample(SFXElectric2,Gactorpos);
					float(_clr,VarBit,Help08);
				}

				vector(_set,gactorpos,-20992,23322,26897);
				vector(_set,gactorine,-20992,23322,26489);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				vector(_set,gactorpos,-20397,23322,26897);
				vector(_set,gactorine,-20397,23322,26489);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				vector(_set,gactorpos,-20932,23365,26974);
				vector(_set,gactorine,-20459,23365,26974);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				vector(_set,gactorpos,-20932,23365,26413);
				vector(_set,gactorine,-20459,23365,26413);
				callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

				if(vrnd<20)
				{
					vector(_set,tmpvector,255,220,30);
					vector(_set,Gactorpos,-20690,23434,27050);
					SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);									

					vector(_set,tmpvector,255,220,30);	
					vector(_set,Gactorpos,-20690,23434,26343);
					SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);

				}
			}
		}

		if(vcurset=="annx_03" || vcurset=="annx_02")
		{
			if(FireJetCount>=3)					//next hole in pipe
			{
				float(_set,FireJetCount,0);
			}
			if(FireJetLife>=210)				//next hole in pipe
			{
				float(_add,FireJetCount,1);
				float(_set,FireJetLife,0);

				if(FireJetCount==0)
				{
					//vector(_set,Gactorine,-17456,25525,25349);		//2
					vector(_set,Gactorpos,-17457,25524,24749);
				}
				elseif(FireJetCount==2)
				{
					//vector(_set,Gactorine,-17458,25524,25049);		//1
					vector(_set,Gactorpos,-17456,25525,25349);
				}
				elseif(FireJetCount==1)
				{
					//vector(_set,Gactorine,-17457,25524,24749);		//0
					vector(_set,Gactorpos,-17458,25524,25049);
				}
				//samplestop(SFXFlamesBurning,gactorine);
				sample(SFXFlamesBurning,gactorpos,100,150);
			}

			float(_rnd2,tmpfloat,24);
			float(_sub,tmpfloat,12);
			vector(_setx,tmpvector4,tmpfloat);
			vector(_sety,tmpvector4,tmpfloat);
			vector(_setz,tmpvector4,tmpfloat);

			if(vrnd<100&&FireJetLife<150)		//lifespan of each burst/delayer
			{
				vector(_set,fxvector,0,60,0);

				if(FireJetCount==0)
				{
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-17457,25524,24749);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					}

					vector(_set,Gactorpos,-17457,25524,24749);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,6,0);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,-1);
					if(skipcollidecount>=5)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,75,0,_COLFire);
					}
				}
				elseif(FireJetCount==2)
				{
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-17456,25525,25349);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					}

					vector(_set,Gactorpos,-17456,25525,25349);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,6,0);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,-1);
					if(skipcollidecount>=5)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,75,0,_COLFire);
					}
				}
				elseif(FireJetCount==1)
				{
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-17458,25524,25049);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					} 

					vector(_set,Gactorpos,-17458,25524,25049);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,6,0);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,-1);
					if(skipcollidecount>=5)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,75,0,_COLFire);
					}
				}
			}
			else
			{
				if(FireJetCount==0)
				{
					vector(_set,Gactorpos,-17457,25524,24749);	//0
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,3,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);
				}
				elseif(FireJetCount==2)
				{
					vector(_set,Gactorpos,-17456,25525,25349);	//2
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,3,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);
				}
				elseif(FireJetCount==1)
				{
					vector(_set,Gactorpos,-17458,25524,25049);	//1
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,3,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);
				}
			}
		}

		if(vcurset=="annx_04" || vcurset=="annx_02")
		{
			if(FireJetCount>=3)				//next hole in pipe
			{
				float(_set,FireJetCount,0);
			}
			if(FireJetLife>=210)				//next hole in pipe
			{
				float(_add,FireJetCount,1);
				float(_set,FireJetLife,0);

				if(FireJetCount==0)
				{
					//vector(_set,Gactorine,-19338,26006,23966);		//2
					vector(_set,Gactorpos,-18136,26006,23965);
				}
				elseif(FireJetCount==1)
				{
					//vector(_set,Gactorine,-18136,26006,23965);		//0
					vector(_set,Gactorpos,-18737,26006,23966);
				}
				elseif(FireJetCount==2)
				{
					//vector(_set,Gactorine,-18737,26006,23966);		//1
					vector(_set,Gactorpos,-19338,26006,23966);
				}
				//samplestop(SFXFlamesBurning,gactorine);
				sample(SFXFlamesBurning,gactorpos,100,150);
			}

			float(_rnd2,tmpfloat,24);
			float(_sub,tmpfloat,12);
			vector(_setx,tmpvector4,tmpfloat);
			vector(_sety,tmpvector4,tmpfloat);
			vector(_setz,tmpvector4,tmpfloat);

			if(vrnd<100&&FireJetLife<150)		//lifespan of each burst/delayer
			{
				vector(_set,fxvector,0,0,-120);

				if(FireJetCount==0)
				{
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-18136,26006,23965);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					}

					vector(_set,Gactorpos,-18135,25892,23962);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-8);
					float(_rnd2,tmpfloat,4);
					vector(_subz,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==1)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-18135,26122,23964);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==2)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-18135,26006,23965);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
				}
				elseif(FireJetCount==1)
				{
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-18737,26006,23966);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					} 

					vector(_set,Gactorpos,-18737,25892,23963);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-8);
					float(_rnd2,tmpfloat,4);
					vector(_subz,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==1)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-18732,26122,23966);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==2)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-18737,26006,23966);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
				}
				elseif(FireJetCount==2)
				{
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-19338,26006,23966);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					}

					vector(_set,Gactorpos,-19338,25892,23963);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-8);
					float(_rnd2,tmpfloat,4);
					vector(_subz,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==1)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-19334,26122,23966);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==2)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-19338,26006,23966);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
				}
			}
			else
			{
				if(FireJetCount==0)
				{
					vector(_set,Gactorpos,-18136,25892,23962);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-4);
					float(_rnd2,tmpfloat,4);
					vector(_subz,Gactorine,tmpfloat);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
					vector(_set,Gactorpos,-18131,26122,23964);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
					vector(_set,Gactorpos,-18136,26006,23965);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
				}
				elseif(FireJetCount==1)
				{
					vector(_set,Gactorpos,-18737,25892,23963);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-4);
					float(_rnd2,tmpfloat,4);
					vector(_subz,Gactorine,tmpfloat);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
					vector(_set,Gactorpos,-18732,26122,23966);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
					vector(_set,Gactorpos,-18737,26006,23966);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
				}
				elseif(FireJetCount==2)
				{
					vector(_set,Gactorpos,-19338,25892,23963);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-4);
					float(_rnd2,tmpfloat,4);
					vector(_subz,Gactorine,tmpfloat);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
					vector(_set,Gactorpos,-19334,26122,23966);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
					vector(_set,Gactorpos,-19338,26006,23966);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
				}
			}
		}
		elseif(vcurset=="annx_08")
		{
			if(FireJetCount>=4)				//next hole in pipe
			{
				float(_set,FireJetCount,0);
			}
			if(FireJetLife>=210)				//next hole in pipe
			{
				float(_add,FireJetCount,1);
				float(_set,FireJetLife,0);

				if(FireJetCount==0)
				{
					//vector(_set,Gactorine,-19200,25576,25493);		//3
					vector(_set,Gactorpos,-19200,25576,25500);
				}
				elseif(FireJetCount==1)
				{
					//vector(_set,Gactorine,-19200,25576,25500);		//0
					vector(_set,Gactorpos,-19200,25576,25570);
				}
				elseif(FireJetCount==2)
				{
					//vector(_set,Gactorine,-19200,25576,25570);		//1
					vector(_set,Gactorpos,-19200,25576,25434);
				}
				elseif(FireJetCount==3)
				{
					//vector(_set,Gactorine,-19200,25576,25434);		//2
					vector(_set,Gactorpos,-19200,25576,25493);
				}
				//samplestop(SFXFlamesBurning,gactorine);
				sample(SFXFlamesBurning,gactorpos,100,150);
			}

			float(_rnd2,tmpfloat,24);
			float(_sub,tmpfloat,12);
			vector(_setx,tmpvector4,tmpfloat);
			vector(_sety,tmpvector4,tmpfloat);
			vector(_setz,tmpvector4,tmpfloat);

			if(vrnd<100&&FireJetLife<150)		//lifespan of each burst/delayer
			{
				if(FireJetCount==0)
				{
					vector(_set,fxvector,0,100,0);
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-18961,25576,25709);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
						vector(_set,tmpvector,255,0,0);
						vector(_set,Gactorpos,-19571,25587,25295);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					}

					vector(_set,Gactorpos,-18961,25576,25709);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-19571,25587,25295);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-8,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_subx,Gactorine,tmpfloat);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==1)
					{
						//vector(_add,Gactorpos,fxvector);
						vector(_set,Gactorine,-100,100,0);
						vector(_add,Gactorpos,Gactorine);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}

					vector(_set,fxvector,0,0,-130);
					vector(_set,Gactorpos,-18581,25717,25760);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-8);
					float(_rnd2,tmpfloat,4);
					vector(_subz,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==2)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-18581,25830,25760);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-18581,25946,25760);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==4)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
				}
				elseif(FireJetCount==1)
				{
					vector(_set,fxvector,0,100,0);
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-18960,25576,25570);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
						vector(_set,tmpvector,255,0,0);
						vector(_set,Gactorpos,-19574,25587,25436);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					} 

					vector(_set,Gactorpos,-18960,25576,25570);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}

					vector(_set,Gactorpos,-19574,25587,25436);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-8,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_subx,Gactorine,tmpfloat);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==1)
					{
						//vector(_add,Gactorpos,fxvector);
						vector(_set,Gactorine,-100,100,0);
						vector(_add,Gactorpos,Gactorine);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
				}
				elseif(FireJetCount==2)
				{
					vector(_set,fxvector,0,100,0);
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-18961,25576,25434);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
						vector(_set,tmpvector,255,0,0);
						vector(_set,Gactorpos,-19573,25587,25572);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					}

					vector(_set,Gactorpos,-18961,25576,25434);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-19573,25587,25572);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-8,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_subx,Gactorine,tmpfloat);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==1)
					{
						//vector(_add,Gactorpos,fxvector);
						vector(_set,Gactorine,-100,100,0);
						vector(_add,Gactorpos,Gactorine);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}

					vector(_set,fxvector,0,0,130);
					vector(_set,Gactorpos,-19330,25717,25239);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,8);
					float(_rnd2,tmpfloat,4);
					vector(_addz,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==2)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-19330,25834,25240);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-19330,25949,25241);
					vector(_add,gactorpos,tmpvector4);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==4)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
				}
				elseif(FireJetCount==3)
				{
					vector(_set,fxvector,0,100,0);
					if(vrnd<50)
					{
						vector(_set,tmpvector,255,70,30);
						vector(_set,Gactorpos,-18959,25576,25293);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
						vector(_set,tmpvector,255,0,0);
						vector(_set,Gactorpos,-19574,25587,25711);
						SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,350);
					}

					vector(_set,Gactorpos,-18959,25576,25293);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==3)
					{
						vector(_add,Gactorpos,fxvector);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
					vector(_set,Gactorpos,-19574,25587,25711);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-8,8,0);
					float(_rnd2,tmpfloat,4);
					vector(_subx,Gactorine,tmpfloat);
					vector(_addy,Gactorine,tmpfloat);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);
					if(skipcollidecount==1)
					{
						//vector(_add,Gactorpos,fxvector);
						vector(_set,Gactorine,-100,100,0);
						vector(_add,Gactorpos,Gactorine);
						call(CheckActorCollision,gactorpos,85,0,_COLFire);
					}
				}
			}
			else
			{
				if(FireJetCount==0)
				{
					vector(_set,Gactorpos,-18959,25576,25293);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-19574,25587,25711);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-4,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);
				}
				elseif(FireJetCount==1)
				{
					vector(_set,Gactorpos,-18961,25576,25709);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-19571,25587,25295);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-4,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-18581,25717,25760);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-4);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-18581,25830,25760);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-4);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-18581,25946,25760);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,-4);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);
				}
				elseif(FireJetCount==2)
				{
					vector(_set,Gactorpos,-18960,25576,25570);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-19574,25587,25436);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-4,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);
				}
				elseif(FireJetCount==3)
				{
					vector(_set,Gactorpos,-18961,25576,25434);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-19573,25587,25572);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,-4,4,0);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-19330,25717,25239);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,4);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-19330,25834,25240);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,4);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-19330,25949,25241);
					vector(_add,gactorpos,tmpvector4);
					vector(_set,Gactorine,0,0,4);
					SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,-1);
				}
			}
		}
		float(_add,FireJetLife,1);

		if(vcurset=="annx_07"||vcurset=="annx_02"||vcurset=="annx_03")
		{
			if(ANNXVAR1&!=2)
			{
				if(vrnd<50)
				{
					vector(_set,tmpvector,255,0,0);
					vector(_set,fxvector,-18613,24460,25558);
					vector(_copy,Gactorpos,fxvector);
					vector(_set,fxvector,-274,0,0);
					vector(_add,gactorpos,fxvector);
					SpawnLight(fire_light,-1,gactorpos,tmpvector,EmptyVector,650);
				}

				vector(_set,gactorpos,-18613,24685,25558);
				vector(_set,gactorine,-19162,24685,25558);
				callsub(ElectricStrip,gactorpos,gactorine,fx_red);
				vector(_set,gactorpos,-18613,24609,25558);
				vector(_set,gactorine,-19162,24609,25558);
				callsub(ElectricStrip,gactorine,gactorpos,fx_red);
				vector(_set,gactorpos,-18613,24534,25558);
				vector(_set,gactorine,-19162,24534,25558);
				callsub(ElectricStrip,gactorpos,gactorine,fx_red);
				vector(_set,gactorpos,-18613,24460,25558);
				vector(_set,gactorine,-19162,24460,25558);
				callsub(ElectricStrip,gactorine,gactorpos,fx_red);
				vector(_set,gactorpos,-18613,24384,25558);
				vector(_set,gactorine,-19122,24384,25558);
				callsub(ElectricStrip,gactorpos,gactorine,fx_red);
				vector(_set,gactorpos,-18613,24308,25558);
				vector(_set,gactorine,-19047,24308,25558);
				callsub(ElectricStrip,gactorine,gactorpos,fx_red);
				vector(_set,gactorpos,-18613,24235,25558);
				vector(_set,gactorine,-18972,24235,25558);
				callsub(ElectricStrip,gactorpos,gactorine,fx_red);
				vector(_set,gactorpos,-18613,24180,25558);
				vector(_set,gactorine,-18920,24180,25558);
				callsub(ElectricStrip,gactorine,gactorpos,fx_red);
			}
		}


		if(VSetActive=="ANNX_01")
		{
			CurEnvTriggerSet("ANNX_01","WALLS1");
			if(ANNXVAR2>=13)
			{
				float(_set,TmpFloat,0x7f00);
			}
			else
			{
				float(_set,TmpFloat,0x7f0000);
			}
			call(expset1,1,TmpFloat,0);
		}
		if(VSetActive=="ANNX_03")
		{
			CurEnvTriggerSet("ANNX_03","OPENDOOR");
			if(ANNXVAR1&=4)
			{
				float(_set,TmpFloat,0x7f00);
			}
			else
			{
				float(_set,TmpFloat,0x7f0000);
			}
			call(expset1,1,TmpFloat,0);
		}
		if(VSetActive=="ANNX_10")
		{
			CurEnvTriggerSet("ANNX_10","DOORTRIG");
			if(ANNXVAR2>=13)
			{
				float(_set,TmpFloat,0x7f00);
			}
			else
			{
				float(_set,TmpFloat,0x7f0000);
			}
			call(expset1,1,TmpFloat,0);
		}

		if(skipcollidecount>=5)
		{
			float(_set,skipcollidecount,0);
		}
		float(_add,skipcollidecount,1);
}




SubRoutine(Sub_ColElecXAnx10)
{
		vector(_settotriggerpos,TmpVector);
		vector(_settoactorpos,TmpVector2);
		vector(_sub,TmpVector,TmpVector2);
		vector(_copyx,TmpVector,TmpFloat);
		if(TmpFloat>=0)
		{
			vector(_setx,Gactorine,-1);
		}
		else
		{
			vector(_setx,Gactorine,1);
		}
		vector(_setplanetrignvec,Gactorine);

		colstate(_or,_COLelectricity);
}




SubRoutine(BackgroundTriggerChecksScene6)
{

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel6); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////


	if(VCurSet=="annx_01")
	{
		float(_set,AIVisionToggle,0);

		if(VAICon==0)
		{
			if(RadAlert==0)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,15);
				callsub(Panel15);
				ClearDMessage();
				float(_set,RadAlert,1);
			}
			CurEnvTrigger("WALLS1");
			if(VKeyObjTriggered==0 && VRunScriptCode==18)
			{
				callsub(DeInitSceneSound18);
				call(RunScriptCode,_clr,18);
			}		
			if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(ANNXVAR2>=13 && ANNXVAR1&=4)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,5);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
						if(VRunScriptCode!=18)
						{
							call(RunScriptCode,_or,18);
						}
					}
				}
				else
				{
					sample(SFXAccessDenied,Gactorpos);
					message("access to streets denied@ re-route power from main turbine",250,10);
				}
				direction(_clr,_DIRaction);		
			}

			CurEnvTrigger("WARENT");
			if(VKeyObjTriggered==0 && VRunScriptCode==5)
			{
				callsub(DeInitSceneSound5);
				call(RunScriptCode,_clr,5);
			}
			if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					if(VRunScriptCode!=5)
					{
						call(RunScriptCode,_or,5);
					}
				}
				direction(_clr,_DIRaction);		
			}		

			if(ControlTimer==2)
			{
				CurEnvTrigger("warent")
				if(VSetActive=="war_ent")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("ANNX_01","warent",1);
					call(KeyObjTrigger,255,1);
				}
			}
			elseif(ControlTimer==5)
			{
				CurEnvTrigger("walls1")
				if(VSetActive=="walls1")
				{
					float(_set,Aivisiontoggle,0);
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("ANNX_01","WALLS1",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
	}
	elseif(VCurSet=="annx_03")
	{
		if(VAICON==0)
		{
			CurEnvTrigger("opendoor");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(ANNXVAR1&=4)
				{
					if(ControlTimer!=10 && VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
					{
						float(_set,ControlTimer,10);
						call(KeyObjTrigger,255,1);
						Sample(SFXLatch1,-1);		//leave this here
					}
				}
				else
				{
					message("Locked@ insufficient power",120,10);
				}
				direction(_clr,_DIRaction);
			}
		}
	}
	elseif(VCurSet=="annx_04")
	{
		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			callsub(DoorOpen,1,1);
		}
	}
	elseif(VCurSet=="annx_05")
	{
		CurEnvTrigger("trigdoor2");
		callsub(StartDoorDelay,1);
	}
	elseif(VCurSet=="annx_06")
	{
		if(ANNXVAR1&!=2 && VAICon==0)
		{
			float(_add,CommandTimer,1)
			if(CommandTimer>=150)
			{
				GetNumbActorsInSet("annx_04",_AIClassCop,TmpFloat);
				if(TmpFloat==0)
				{
					vector(_set,Gactorpos,-18643,24777,23851);
					vector(_set,Gactorangle,0,2048,0);
					initactor(WeaponPumpGun,Gactorpos,Gactorangle,"annx_04");
					vector(_set,Gactorpos,-18643,24727,23851);
					initactor(copl,Gactorpos,Gactorangle,"annx_04",TRUE,87);
				}
				float(_set,CommandTimer,0);
			}
		}
		CurEnvTrigger("LASEROFF");	
		if(VTrigger==_DIRaction&&VTrigger==_DIREnvTrigger)
		{
			if(VAICON==0)
			{
				if(VClass!=_ClassAngel)
				{
					if(ANNXVAR1&!=2)
					{
						GetNumbActorsInSet("annx_06",_AIclasscop,TmpFloat);
						if(TmpFloat!=0)
						{
							float(_or,ANNXVAR1,8);
							float(_set,timer,50);
						}

						float(_or,ANNXVAR1,2);
						call(ActivateButton,"Lasers turned off",-1,FALSE);
						sample(SFXLaserTurnedOffAnnex,Gactorpos);
						vector(_set,Gactorpos,-18901,24160,25517);
						samplestop(SFXElecAmbient,Gactorpos);
						float(_set,TmpFloat,0x0000ff);
						call(expset1,1,TmpFloat,0);
						call(ActivateButtonSample,SFXValidFunction);
					}
					else
					{
						call(ActivateButton,"Lasers already turned off",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
					direction(_clr,_DIRaction);
				}
				else
				{
					call(ActivateButton,"So many buttons !",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}

		if(ANNXVAR1&=8 && VAICon!=0 && VAIClass==_AIclasscop)
		{
			sample(SFXPlayerActivatesButtonReact,-1);
			if(timer==0)
			{
				float(_clr,ANNXVAR1,8);
				call(AIchangeplayertoenemy);
			}
			else
			{
				callsub(TurnToPlayer);
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
					vector(_set,Gactorpos,-20240,25382,22795);
					vector(_set,Gactorangle,0,0,0);
					InitActor(WeaponBazooka,Gactorpos,Gactorangle,"annx_06",TRUE);
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

		CurEnvTrigger("arme01");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					vector(_set,Gactorpos,-20240,25382,22492);
					vector(_set,Gactorangle,0,0,0);
					InitActor(WeaponMaimer,Gactorpos,Gactorangle,"annx_06",TRUE);
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

		CurEnvTrigger("trigdoor1");
		callsub(StartDoorDelay,2);

		CurEnvTrigger("trigdoor2");
		callsub(StartDoorDelay,1);
	}
	elseif(VCurSet=="annx_07")
	{
		CurEnvTrigger("spawn");
		if(VTrigger==_DIREnvTrigger)
		{
			if(ANNXVAR1&=2 && VAICon==0)
			{
				GetNumbActorsInSet("annx_04",_AIClassCop,TmpFloat);
				GetNumbActorsInSet("annx_02",_AIClassCop,TmpFloat2);
				GetNumbActorsInSet("annx_03",_AIClassCop,TmpFloat3);
				if(TmpFloat==0 && TmpFloat2==0 && TmpFloat3==0)
				{
					vector(_set,Gactorpos,-18643,24777,23851);
					vector(_set,Gactorangle,0,2048,0);
					initactor(WeaponPumpGun,Gactorpos,Gactorangle,"annx_04");
					vector(_set,Gactorpos,-18643,24727,23851);
					initactor(copl,Gactorpos,Gactorangle,"annx_04",TRUE,87);
				}
			}
		}

		CurEnvTrigger("panel");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VAIClass==_AIclassworker || VAIClass==_AIClassScientist)
				{
					if(ANNXVAR1&!=4)
					{	
						if(VAICON==0)
						{
							call(ActivateButton,"Power Configured - upper access door unlocked",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							sample(SFXPowerConfiguredAnnex,Gactorpos);
							float(_set,TmpFloat,0x0000ff);
							call(expset1,1,TmpFloat,0);
							float(_or,ANNXVAR1,4);
							call(KeyObjTrigger,255,1);
							//kfsample(SFXHudLiftStart,SFXHudLiftLoop,-1,SFXHudLiftStop);
							kfsample(SFXRustDoorOpen,SFXRustDoorLoop,SFXRustDoorClose,-2);
							vector(_set,TmpVector,-19045, 24420, 25944);
							Sample(SFXPneumatik2,TmpVector);
						}
					}
					else
					{
						if(VAICON==0)
						{
							call(ActivateButton,"Power Already Configured",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
						}
					}
				}
				else
				{
					call(ActivateButton,"Only workers know how to reconfigure this",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				direction(_clr,_DIRaction);
			}
			else
			{
				if(VAICON==0)
				{
					call(ActivateButton,"So many buttons !",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}

		if(ANNXVAR1&!=2)
		{
			CurEnvTrigger("LOWLAZIN");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
			else
			{
				CurEnvTrigger("HILAZIN");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				else
				{
					CurEnvTrigger("LOWLAZOUT");
					if(VTrigger==_DIREnvTrigger)
					{
						colstate(_or,_COLelectricity);
					}
					else
					{
						CurEnvTrigger("HILAZOUT");
						if(VTrigger==_DIREnvTrigger)
						{
							colstate(_or,_COLelectricity);
						}
						else
						{
							CurEnvTrigger("MIDLAZOUT");
							if(VTrigger==_DIREnvTrigger)
							{
								colstate(_or,_COLelectricity);
							}
							else
							{
								CurEnvTrigger("MIDLAZIN");
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

		if(VAICON==0 && VTrigger==_DIRaction)
		{
			CurEnvTrigger("door");
			if(VTrigger==_DIREnvTrigger)
			{
				sample(SFXAccessDenied,Gactorpos);
				message("Door locked from the inside.",120,10);
			}
		}
	}
	elseif(VCurSet=="ANNX_08")
	{
		CurEnvTrigger("opendoor");
		if(VTrigger==_DIRaction && ControlTimer==0 && VAICon==0 && VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			float(_set,ControlTimer,1);
			call(KeyObjTrigger,255,1);
			Sample(SFXLatch1,-1);		//leave this here
			Direction(_clr,_DIRaction);
		}

		if(VarBit&=Help11)
		{
			CurEnvTrigger("hot");
			if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassAngel)
			{
				sample(SFXBobHot,-1);
				float(_clr,VarBit,Help11);
			}
		}
	}
	elseif(VCurSet=="ANNX_09")
	{
		CurEnvTrigger("Doortrig");
		callsub(StartDoorDelay,1);

		CurEnvTrigger("Door79");		
		callsub(StartDoorDelay,2);

		if(VAICon==0 && HUDTimer>160)
		{
			callsub(Sub_SetCameraNormal);
		}
	}
	elseif(VCurSet=="ANNX_10")
	{
		float(_add,CommandTimer,1);
		if(CommandTimer>=400)
		{
			GetNumbActorsInSet("annx_10",_AIClassWorker,TmpFloat);
			GetNumbActorsInSet("annx_10",_AIClassChot,TmpFloat1);
			float(_add,TmpFloat,TmpFloat1);
			if(TmpFloat==0)
			{
				vector(_set,Gactorpos,-20234,23800,26683);
				vector(_set,Gactorangle,0,2048,0);
				initactor(WeaponPak,Gactorpos,Gactorangle,"annx_10");
				vector(_set,Gactorpos,-20234,23750,26683);
				initactor(Chot,Gactorpos,Gactorangle,"annx_10",TRUE,55);
			}
			float(_set,CommandTimer,0);
		}

		vector(_set,Gactorine,0,0,0);

		//First Electric Field
		if(VarBit&!=Help07)
		{
			CurEnvTrigger("col01a");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,45,75,200);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					callsub(Sub_ColElecXAnx10);
				}
			}

			CurEnvTrigger("col01b");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,230,70,60);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					vector(_setz,Gactorine,-1);
					vector(_setplanetrignvec,Gactorine);
					colstate(_or,_COLelectricity);
				}
			}

			CurEnvTrigger("col01c");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,45,75,200);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					callsub(Sub_ColElecXAnx10);
				}
			}

			CurEnvTrigger("col01d");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,230,70,60);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					vector(_setz,Gactorine,1);
					vector(_setplanetrignvec,Gactorine);
					colstate(_or,_COLelectricity);
				}
			}
		}

		if(VarBit&!=Help08)
		{
			CurEnvTrigger("col02a");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,45,75,200);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					callsub(Sub_ColElecXAnx10);
				}
			}

			CurEnvTrigger("col02b");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,230,70,60);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					vector(_setz,Gactorine,-1);
					vector(_setplanetrignvec,Gactorine);
					colstate(_or,_COLelectricity);
				}
			}

			CurEnvTrigger("col02c");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,45,75,200);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					callsub(Sub_ColElecXAnx10);
				}
			}

			CurEnvTrigger("col02d");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,230,70,60);
				float(_seti,TmpFloat2,VColFeetSphereSize);
				call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
				if(tmpfloat!=0)
				{
					vector(_setz,Gactorine,1);
					vector(_setplanetrignvec,Gactorine);
					colstate(_or,_COLelectricity);
				}
			}
		}

		CurEnvTrigger("MASTERTRI");		
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel && VAICon==0)
			{
				if (ANNXVAR2<=12)
				{
					call(ActivateButton,"Turbine Power Ready - Exit Door Unlocked for 30 seconds",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					sample(SFXTurbinePowerAnnex,Gactorpos);
					float(_set,TmpFloat,0x0000ff);
					call(expset1,1,TmpFloat,0);
					call(expset2,-1,66,67);
					vector(_set,Gactorpos,-21444,24200,26700);
					samplestop(SFXScanHumm02,Gactorpos);
					float(_set,ANNXVAR2,13);
					float(_set,HudTimer,0);
					call(PlayerInput,0);
				}
				else
				{
					if(HudTimer==0)
					{
						CurEnvTrigger("hammer01");
						if(VKeyObjTriggered==0)
						{
							call(ActivateButton,"Emergency Door Unlocked for 30 seconds",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							float(_set,ANNXVAR2,14);
							call(HUDTimerSet,900);
							float(_set,HudTimer,162);
						}
						else
						{
							call(ActivateButton,"Hammer Repositionning. Please Wait.",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
					}
					else
					{
						call(ActivateButton,"Power Already Configured - Please Use Exit",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				direction(_clr,_DIRaction);
			}
			else
			{
				if(VAICON==0)
				{
					call(ActivateButton,"I just don't get it...",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}

		}
		
		if(VAICon==0)
		{
			if(HudTimer==160)
			{	
				callsub(Sub_SetCameraNormal);
			}
			if(ANNXVAR2<13)
			{
				CurEnvTrigger("elec01");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLElectricity);
				}

				CurEnvTrigger("elec02");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLElectricity);
				}
			}

			CurEnvTrigger("grinder2");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Fall2Death);
			}
			CurEnvTrigger("grinder01");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Fall2Death);
			}
			CurEnvTrigger("grinder02");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Fall2Death);
			}
				
			CurEnvTrigger("hammer01");
			if(VKeyObjFrame==3 && VKeyObjTriggered==0)
			{
				if(VTrigger==_DIREnvTrigger)
				{
					if(VarBit&=Help02)
					{
						if(VState!=StateFalling && VState!=StateFlying && VState!=StateGliding && VState!=StateJump && VTrigger!=_DIRmove)
						{
							float(_set,TmpFloat,0x22aa55);
							call(expset1,TmpFloat,450,-1);
							message("Sensor A23 Activated",50,100);
							sample(SFXScanPlateOn,-1);
							call(KeyObjTrigger,41,1);
							float(_clr,VarBit,Help02);
						}
					}
				}
				else
				{
					float(_or,VarBit,Help02);
				}
			}
			if(VKeyObjTriggered!=0 && HudTimer>=160)
			{
				camera(900,600);
				target(-10,10);
			}

			CurEnvTrigger("hammer02");
			if(VKeyObjFrame==3 && VKeyObjTriggered==0)
			{
				if(VTrigger==_DIREnvTrigger)
				{
					if(VarBit&=Help03)
					{
						if(VState!=StateFalling && VState!=StateFlying && VState!=StateGliding && VState!=StateJump && VTrigger!=_DIRmove)
						{
							float(_set,TmpFloat,0x22aa55);
							call(expset1,TmpFloat,450,-1);
							message("Sensor A24 Activated",50,100);
							sample(SFXScanPlateOn,-1);
							call(KeyObjTrigger,41,1);
							float(_clr,VarBit,Help03);
						}
					}
				}
				else
				{
					float(_or,VarBit,Help03);
				}
			}
			if(VKeyObjTriggered!=0 && HudTimer>=160)
			{
				camera(900,600);
				target(-10,10);
			}

			CurEnvTrigger("DOORTRIG");		
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Door Remotely Locked",120,10);
				sample(SFXAccessDenied,Gactorpos);
				direction(_clr,_DIRaction);
			}
		}
		else
		{
			CurEnvTrigger("grinder2");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Fall2Death);
				sample(SFXCrushedReact,-1);
				float(_clr,VarBit,Help04);
				float(_set,timer4,0);
			}
			CurEnvTrigger("grinder01");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Fall2Death);
				sample(SFXCrushedReact,-1);
				float(_clr,VarBit,Help05);
				float(_set,timer,0);
			}
			CurEnvTrigger("grinder02");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Fall2Death);
				sample(SFXCrushedReact,-1);
				float(_clr,VarBit,Help06);
				float(_set,timer3,0);
			}
		}
	}
}
