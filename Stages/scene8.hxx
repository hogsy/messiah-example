//VarKey51	- Activate trap in Clubsas
//VarKey52	- Pimp escape sequence
//VarKey53  - Steelbar in Hsing1
//VarKey54  - Decontamination area (rlquar)
//VarKey55	- Lift Control in Acs07
//VarKey56	- VideoBall Control
//VarKey57	- Activate lift in ACS01
//VarKey58	- progress stats
//				1	- VIP pass taken
//				2	- door from rlhstn1 to rlhsin unlocked
//				4	- VIP passcode sequence start
//				8	- VIP passcode seqence end
//				16	- trigger pimp in rlpimp2 to get pissed coz you stole his VIP pass
//				32	- trigger bouncer in rlplin to get pissed
//				64	- trigger cop in rlplshp2 to get pissed
//				128	- Someone took pimps VIP Pass, React
//				256	- Continued reaction from pimp
//				512	- RCop reaction
//				1024 - RCop2 reaction
//				2048 - Pillar initialization in 
//				4096 - Pillar movement in rlhsin
//				8192	- Subgirl Ambush 1
//				16384	- Subgirl Ambush 2
//				32768	- Subgirl Agression Toggle
//
//
//VarKey59	- Electric Strips in Acs04
//VarKey60	- flags
//				1	- door1 can open
//				2	- door2 can open
//				4	- Apartment1 Flic has been setup
//				8	- Apartment2 Flic has been setup
//				16	- For apartment flic CD track checks
//
//VarKey61	- WindBlow when exploding glass
//VarKey62	- timer for Quarantine Area
//VarKey63  - 
//VarKey64	- Delaytime for steam in rlhsng4
//VarKey67  - FireJets
//				1 - firejet 1 In acs02
//				2 - firejet 2 In acs02
//				4 - firejet 1 In acs02
//				8 - firejet 2 In acs02
//VarKey68	- level progress stats
//				1	- Worker has fallen
//				2	- init dweller in acs07
//				4	- Worker crushed in machinery 1
//				8	- Worker crushed in machinery 2
//				16	- Worker crushed in machinery 3
//VarKey69	
//VarKey70
//
//VarBit
//------
//
//Help01	>	Linking Process started
//Help02	>	Intro sequence
//Help03	>	Cops vs SubGirl action
//Help04	>	SubGirl screams
//Help05	>	Cop talks
//Help06	>	Story Message #21

//VarKey1	>	Progress indicator for linking
//VarKey2	>	Progress indicator for intro
//timer		- used for lightning bolts

SubRoutine(InitSceneSound8)
{
		call(CDSwap,19,1,100,60);
		call(fadetoblack,2);
		if(incoming!=0)
		{
			if(ScriptMark==20)
			{
				callsub(Panel20);
			}
			elseif(ScriptMark==21)
			{
				callsub(Panel21);
			}
		}
		else
		{
			callsub(ScriptLevel8);
		}	
	
		//rlldg01
		vector(_set,Gactorpos,-11834, 21157, 7559); 
		sample(SFXElectric4,Gactorpos);

		vector(_set,Gactorpos,-11544, 21157, 7269); 
		sample(SFXElectric4,Gactorpos);

		//rlldg02
		vector(_set,Gactorpos,-10934,21285,7269); 
		sample(SFXIndustrial6,Gactorpos);

		//rlhsin
		vector(_set,gactorpos,-14350, 23244, 7738);
		sample(SFXSmallFan,Gactorpos);

		vector(_set,gactorpos,-14348, 23244, 8151);
		sample(SFXSmallFan,Gactorpos);


		//vents
		vector(_set,Gactorpos,-13779,21773,10924);
		sample(SFXVent2loop,Gactorpos);

		vector(_set,Gactorpos,-7187,20853,10926);
		sample(SFXVent2loop,Gactorpos);


		//AMBIENT CITY SOUNDS
		//Redlight1
		vector(_set,Gactorpos,-12280,22556,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-13622,22556,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-15000.10,22556,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);

		vector(_set,Gactorpos,-12280,21737,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-13622,21737,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-15000.10,21737,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);

		vector(_set,Gactorpos,-12280,20808.81,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-13622,20808.81,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-15000.10,20808.81,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);

		//Stairwell
		vector(_set,Gactorpos,-15295,22245,8369); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-15295,21568.17,8369); 
		sample(SFXCityAmbient01Small,Gactorpos,80);

		//Back Section
		vector(_set,Gactorpos,-11605,22257,8750); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-10274,20926.02,8758); 
		sample(SFXCityAmbient01Small,Gactorpos,80);


		//Redlight2
		vector(_set,Gactorpos,-6885.93,22556,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-8236.90,22556,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-9581.69,22556,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);

		vector(_set,Gactorpos,-6885.93,21737,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-8236.90,21737,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-9581.69,21737,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);

		vector(_set,Gactorpos,-6885.93,20808.81,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
		vector(_set,Gactorpos,-8236.90,20808.81,11258); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-9581.69,20808.81,11258); 
		sample(SFXCityAmbient02Small,Gactorpos,80);

		//Stairwell
		vector(_set,Gactorpos,-6578,22130,8122); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-6578,21252.72,8122); 
		sample(SFXCityAmbient02Small,Gactorpos,80);

		//Back Section
		vector(_set,Gactorpos,-10274,22282,8758); 
		sample(SFXCityAmbient01Small,Gactorpos,80);
		vector(_set,Gactorpos,-10274,21236.44,8758); 
		sample(SFXCityAmbient02Small,Gactorpos,80);
}

SubRoutine(DeInitSceneSound8)
{
		//rlldg01
		vector(_set,Gactorpos,-11834, 21157, 7559); 
		samplestop(SFXElectric4,Gactorpos);

		vector(_set,Gactorpos,-11544, 21157, 7269); 
		samplestop(SFXElectric4,Gactorpos);

		//rlldg02
		vector(_set,Gactorpos,-10934,21285,7269); 
		samplestop(SFXIndustrial6,Gactorpos);


		//rlhsin
		vector(_set,Gactorpos,-13482,21349,7944);
		samplestop(SFXShaftSpecial2,Gactorpos);


		//vents
		vector(_set,Gactorpos,-13779,21773,10924);
		samplestop(SFXVent2loop,Gactorpos);

		vector(_set,Gactorpos,-7187,20853,10926);
		samplestop(SFXVent2loop,Gactorpos);

		
		//AMBIENT CITY SOUNDS
		//Redlight1
		vector(_set,Gactorpos,-12280,22556,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-13622,22556,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-15000.10,22556,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);

		vector(_set,Gactorpos,-12280,21737,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-13622,21737,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-15000.10,21737,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);

		vector(_set,Gactorpos,-12280,20808.81,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-13622,20808.81,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-15000.10,20808.81,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);

		//Stairwell
		vector(_set,Gactorpos,-15295,22245,8369); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-15295,21568.17,8369); 
		samplestop(SFXCityAmbient01Small,Gactorpos);

		//Back Section
		vector(_set,Gactorpos,-11605,22257,8750); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-10274,20926.02,8758); 
		samplestop(SFXCityAmbient01Small,Gactorpos);


		//Redlight2
		vector(_set,Gactorpos,-6885.93,22556,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-8236.90,22556,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-9581.69,22556,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);

		vector(_set,Gactorpos,-6885.93,21737,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-8236.90,21737,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-9581.69,21737,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);

		vector(_set,Gactorpos,-6885.93,20808.81,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);
		vector(_set,Gactorpos,-8236.90,20808.81,11258); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-9581.69,20808.81,11258); 
		samplestop(SFXCityAmbient02Small,Gactorpos);

		//Stairwell
		vector(_set,Gactorpos,-6578,22130,8122); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-6578,21252.72,8122); 
		samplestop(SFXCityAmbient02Small,Gactorpos);

		//Back Section
		vector(_set,Gactorpos,-10274,22282,8758); 
		samplestop(SFXCityAmbient01Small,Gactorpos);
		vector(_set,Gactorpos,-10274,21236.44,8758); 
		samplestop(SFXCityAmbient02Small,Gactorpos);

}

SubRoutine(InitScene8)
{
		if(VScriptInitiated!=8)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,2048,0);
				InitActor(Bob1,0,Gactorangle,"rlhsng2c");
			}

			//Daniel's Enemy Script

			#include "messiahscripts\enemies\Redlite1.spt"
			#include "messiahscripts\enemies\Redlite2.spt"

			// Reset all the variables
			call(loadpreloaddb,15);
			float(_set,VarKey51,0);
			float(_set,VarKey52,0);
			float(_set,VarKey53,0);
			float(_set,VarKey54,1);				//init to worker not dead
			float(_set,VarKey55,0);
			float(_set,VarKey56,0);
			float(_set,VarKey57,0);
			float(_set,VarKey58,0);
			float(_set,VarKey60,0);
			float(_set,VarKey61,0);
			float(_set,VarKey62,0);
			float(_set,VarKey63,0);
			float(_set,VarKey64,0);
			float(_set,VarKey65,0);
			float(_set,VarKey66,0);
			float(_set,VarKey67,0);
			float(_set,VarKey68,0);
			float(_set,VarKey69,0);
			float(_set,VarKey70,0);
			float(_set,VarBit,AllHelp);
			float(_set,MissionLevel1,0);
			float(_set,MissionLevel2,0);
			float(_set,MissionLevel3,0);
			float(_set,MissionLevel4,0);
			float(_set,AIVisionToggle,1);
			float(_set,HudTimer,0);
			float(_set,AngelReact,0);
			float(_set,Objective,0);
			float(_set,VarKey1,0);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
			float(_set,timer4,0);
		}

		callsub(InitSceneSound8);
		call(ScriptCodeInitiated,8);
}

SubRoutine(MainScene8)
{
	float(_seti,tmpfloat,VCDTrack);
	print("CD TRACK:  ",VCDTrack);





//////////////////////////
//// REDLITE DISTRICT ////
//////////////////////////
	if(VSetActive=="rlhsin")
	{
		CurEnvTriggerSet("rlhsin","LiftCam");
		if(VKeyObjTriggered==0)
		{
			if(VKeyObjFrame==0)
			{
				call(KeyObjTrigger,16,1);
				kfsample(SFXLiftStart,SFXLiftMove,SFXLiftEnd,-2);
			}
			elseif(VKeyObjFrame==16)
			{
				call(KeyObjTrigger,17,1);
			}
			elseif(VKeyObjFrame==17)
			{
				call(KeyObjTrigger,28,1);
				kfsample(SFXLiftStart,SFXLiftMove,SFXLiftEnd,-2);
			}
			elseif(VKeyObjFrame==28)
			{
				call(KeyObjTrigger,29,1);
			}
			elseif(VKeyObjFrame==29)
			{
				call(KeyObjTrigger,39,1);
				kfsample(SFXLiftStart,SFXLiftMove,SFXLiftEnd,-2);
			}
			elseif(VKeyObjFrame==39)
			{
				call(KeyObjTrigger,40,1);
			}
			elseif(VKeyObjFrame==40)
			{
				call(KeyObjTrigger,50,1);
				kfsample(SFXLiftStart,SFXLiftMove,SFXLiftEnd,-2);
			}
			elseif(VKeyObjFrame==50)
			{
				call(KeyObjTrigger,255,1);
			}
		}


		if(VarKey58&!=2048)
		{
			CurEnvTriggerSet("rlhsin","lever");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);

			CurEnvTriggerSet("rlhsin","Power01");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power02");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power03");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power04");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power05");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power06");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power07");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power08");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power09");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			CurEnvTriggerSet("rlhsin","Power10");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			CurEnvTriggerSet("rlhsin","Redlites");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			float(_or,VarKey58,2048);
		}

		if(VarKey58&=4096)
		{
			CurEnvTriggerSet("rlhsin","RedLites");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
			}
			CurEnvTriggerSet("rlhsin","Power01");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
			}
		}
		else
		{
			vector(_set,Gactorpos,-13474,22466,7938);
			SamplePlaying(SFXShaftRotate2,Gactorpos);
			if(VTrigger==_DIRTempFlag)
			{
				samplestop(SFXShaftRotate2,Gactorpos);
				vector(_set,Gactorpos,-13474,20863,7938);
				samplestop(SFXGears,Gactorpos);
			}
		}
	}
	if(VCurSet=="rlplin")
	{
		CurEnvTrigger("omnictrl1");
		float(_set,TmpFloat,0x0000ff);
		call(expset1,TmpFloat,300,-1);
		call(expset2,TmpFloat,300,-1);
		CurEnvTrigger("omnictrl2");
		float(_set,TmpFloat,0xff0000);
		call(expset1,TmpFloat,300,-1);
		call(expset2,TmpFloat,300,-1);
		CurEnvTrigger("omnictrl3");
		float(_set,TmpFloat,0xff0000);
		call(expset1,TmpFloat,300,-1);
		call(expset2,TmpFloat,300,-1);
		CurEnvTrigger("omnictrl2");
		float(_set,TmpFloat,0xffff00);
		call(expset1,TmpFloat,400,-1);
		CurEnvTrigger("vidball");
		float(_set,TmpFloat,0x0000ff);
		call(expset1,TmpFloat,300,-1);
		call(expset2,TmpFloat,300,-1);


		if(VarKey58&!=8)
		{
			if(VarKey58&=4)
			{
				float(_set,TmpFloat,0x7f00);

				float(_set,TmpFloat2,timer);
				float(_mod,TmpFloat2,15);
				if(TmpFloat2==0)
				{
					vector(_set,gactorpos,-8544,20635,9236);
					Sample(SFXBleep,gactorpos);

					float(_add,timer2,1);

					CurEnvTrigger("VIPL5");
					call(EXPSet1,timer2,timer2,timer2);
				}

				if(timer<15)
				{
					CurEnvTrigger("VIPL01");
					call(expset1,1,TmpFloat,0);
				}
				elseif(timer<30)
				{
					CurEnvTrigger("VIPL01");
					call(expset2,1,TmpFloat,0);
				}
				elseif(timer<45)
				{
					CurEnvTrigger("VIPL2");
					call(expset1,1,TmpFloat,0);
				}
				elseif(timer<60)
				{
					CurEnvTrigger("VIPL2");
					call(expset2,1,TmpFloat,0);
				}
				elseif(timer<75)
				{
					CurEnvTrigger("VIPL3");
					call(expset1,1,TmpFloat,0);
				}
				elseif(timer<90)
				{
					CurEnvTrigger("VIPL3");
					call(expset2,1,TmpFloat,0);
				}
				elseif(timer<105)
				{
					CurEnvTrigger("VIPL4");
					call(expset1,1,TmpFloat,0);
				}
				elseif(timer<120)
				{
					CurEnvTrigger("VIPL4");
					call(expset2,1,TmpFloat,0);
				}

				float(_add,timer,1);

				if(timer>=120)
				{
					float(_or,VarKey58,8);
					vector(_set,gactorpos,-8544,20635,9236);
					sample(SFXCylonAccessGranted,gactorpos);
				}
			}
			else
			{
				CurEnvTrigger("VIPL5");
				call(EXPSet1,0,0,0);
			}
		}
	}
	elseif(VCurSet=="rlhsng2c")
	{
		if(VarBit&=Help02)
		{
			float(_set,Incoming,0);
			call(PlayerInput,0);
			CutScene("camera01");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			float(_set,AivisionToggle,1);
			call(GodModeStatus,true);
			float(_set,timer2,0);
			float(_set,varkey2,1);
			float(_clr,VarBit,Help02);
		}
		if(VarKey2==1)
		{
			float(_add,timer2,1);
			if(timer2>=200)
			{
				CurEnvTrigger("cab");
				call(KeyObjTrigger,255,1);
				//kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
				kfsample(-1,SFXTruckFall,-1,-1);
				float(_set,timer2,0);
				float(_set,VarKey2,2);
			}
		}
		elseif(VarKey2==2)
		{
			CurEnvTrigger("cab");
			if(VKeyObjTriggered!=0)
			{
				CurEnvTrigger("pos");
				vector(_set,Gactorine,0,2,0);
				vector(_settokfpos,Gactorpos,1);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_priestfx);
				vector(_settokfpos,Gactorpos,2);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_priestfx);
			}
			else
			{
				vector(_set,Gactorpos,-15124,19845,11238);
				sample(SFXWallHit,Gactorpos);
				call(ScreenShake,0,10,0,0.8);
				sample(SFXBazookaExplode,Gactorpos);
				CurEnvTrigger("cab");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				float(_set,VarKey2,3);
				float(_set,timer2,0);
			}
		}
	}
		
			

	if(VCurSet=="rlhsapt1")
	{
		float(_or,VarKey60,4);
	}
	elseif(VCurSet=="rlhsng2a")
	{
		CurEnvTrigger("HSNGDR01");
		if(VKeyObjTriggered!=0)
		{
			float(_or,VarKey60,4);
		}
		else
		{
			float(_clr,VarKey60,4);
		}
	}
	else
	{
		float(_clr,VarKey60,4);
	}

	if(VarKey60&=4)
	{
		Vector(_set,Gactorpos,-13496,22748,9839);
		SamplePlaying(SFXSatanTakeoverFlic,Gactorpos);
		if(VTrigger!=_DIRTempFlag)
		{
			sample(SFXSatanTakeoverFlic,Gactorpos);
		}
	}
	else
	{
		Vector(_set,Gactorpos,-13496,22748,9839);
		SamplePlaying(SFXSatanTakeoverFlic,Gactorpos);
		if(VTrigger==_DIRTempFlag)
		{
			samplestop(SFXSatanTakeoverFlic,Gactorpos);
		}
	}



	if(VSetActive=="rlhsapt2")
	{
		CurEnvTriggerSet("rlhsapt2","hsngdr02");
		if(vrnd<5)
		{
			float(_set,tmpfloat,0x222233);
			Call(Expset1,tmpfloat,180,-1);
		}
		elseif(vrnd<10)
		{
			float(_set,tmpfloat,0x333344);
			Call(Expset1,tmpfloat,180,-1);
		}
		elseif(vrnd<15)
		{
			float(_set,tmpfloat,0x444455);
			Call(Expset1,tmpfloat,180,-1);
		}
		else
		{
			float(_set,tmpfloat,0x9999AA);
			Call(Expset1,tmpfloat,180,-1);
		}
	}

	if(VCurSet=="rlhsapt2")
	{
		float(_or,VarKey60,8);
	}
	elseif(VCurSet=="rlhsng2a")
	{
		CurEnvTrigger("HSNGDR02");
		if(VKeyObjTriggered!=0)
		{
			float(_or,VarKey60,8);
		}
		else
		{
			float(_clr,VarKey60,8);
		}
	}
	else
	{
		float(_clr,VarKey60,8);
	}

	if(VarKey60&=8)
	{
		CurEnvTriggerSet("rlhsapt2","Channels");
		Call(Expget,1,tmpfloat);
		if(tmpfloat<=427)
		{
			Vector(_set,Gactorpos,-13496,22748,9839);
			SamplePlaying(SFXConflictFlic,Gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXConflictFlic,Gactorpos);
			}
			SamplePlaying(SFXMaxFlic,Gactorpos);
			if(VTrigger==_DIRTempFlag)
			{
				samplestop(SFXMaxFlic,Gactorpos);
			}
		}
		else
		{
			Vector(_set,Gactorpos,-13496,22748,9839);
			SamplePlaying(SFXConflictFlic,Gactorpos);
			if(VTrigger==_DIRTempFlag)
			{
				samplestop(SFXConflictFlic,Gactorpos);
			}
			SamplePlaying(SFXMaxFlic,Gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXMaxFlic,Gactorpos);
			}
		}
	}
	else
	{
		Vector(_set,Gactorpos,-13496,22748,9839);
		SamplePlaying(SFXConflictFlic,Gactorpos);
		if(VTrigger==_DIRTempFlag)
		{
			samplestop(SFXConflictFlic,Gactorpos);
		}
		SamplePlaying(SFXMaxFlic,Gactorpos);
		if(VTrigger==_DIRTempFlag)
		{
			samplestop(SFXMaxFlic,Gactorpos);
		}
	}



	if(VSetActive=="RLPLZA1A")
	{
		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerSet("RLPLZA1A","LeDoor");
		call(ExpSet1,1,tmpfloat);
	}
	if(VSetActive=="RLPLZA2A")
	{
		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerSet("RLPLZA2A","LeDoor");
		call(ExpSet1,1,tmpfloat);
	}
	if(VSetActive=="RLHSNG1A")
	{
		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerSet("RLHSNG1A","LeDoor");
		call(ExpSet1,1,tmpfloat);
	}
	if(VSetActive=="RLHSNG2A")
	{
		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerSet("RLHSNG2A","LeDoor");
		call(ExpSet1,1,tmpfloat);
	}
	
	if(VSetActive=="rlpimp3")
	{
		if(VCutScene!=0)
		{
			//	Spawnlight for the tunnel
			//
			vector(_settocamtarget,Gactorpos); 
			vector(_set,tmpvector,250,250,250);
			SpawnLight(flash_light_across_set,-1,gactorpos,tmpvector,EmptyVector,350);
		}
	}

	if(VSetActive=="RLldg1")
	{
		call(SetParticleSetID,"RLldg1");
		vector(_set,Gactorpos,-11695, 21157, 7631); 
		vector(_set,Gactorine,-11974, 21157, 7487);
		callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

		vector(_set,Gactorpos,-11483, 21157, 7419); 
		vector(_set,Gactorine,-11606, 21157, 7119);
		callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);
		
		if(vrnd<20)
		{
			vector(_set,Gactorpos,-11834, 21157, 7559); 
			vector(_set,tmpvector,250,250,0);
			SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,200);

			vector(_set,Gactorpos,-11544, 21157, 7269); 
			vector(_set,tmpvector,250,250,0);
			SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,200);
		}
	}

	if(VSetActive=="RLldg3")
	{
		call(SetParticleSetID,"RLldg3");

		vector(_set,Gactorpos,-10169, 21157, 7631); 
		vector(_set,Gactorine,-9890, 21157, 7487);
		callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);

		vector(_set,Gactorpos,-10381, 21157, 7419); 
		vector(_set,Gactorine,-10258, 21157, 7119);
		callsub(ElectricStrip,gactorpos,gactorine,fx_yellow);
		
		if(vrnd<20)
		{
			vector(_set,Gactorpos,-10030, 21157, 7559); 
			vector(_set,tmpvector,250,250,0);
			SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,200);

			vector(_set,Gactorpos,-10320, 21157, 7269); 
			vector(_set,tmpvector,250,250,0);
			SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,200);
		}
	}



	if(VSetActive=="rlhstn1")
	{
		if(VarKey58&=2)
		{
			CurEnvTriggerSet("rlhstn1","dr_hstn1a");
			if(VKeyObjTriggered==0)
			{
				float(_or,VarKey60,2);
				float(_set,TmpFloat,0x7f00);
			}
			else
			{
				float(_clr,VarKey60,2);
				float(_set,TmpFloat,0x7f0000);
			}
		
		}
		else
		{
			float(_set,TmpFloat,0x7f0000);
		}

		CurEnvTriggerSet("rlhstn1","DR_HSTN1C");
		call(expset1,1,TmpFloat,0);
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey60,1);
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_clr,VarKey60,1);
			float(_set,TmpFloat,0x7f0000);
		}
		CurEnvTriggerSet("rlhstn1","DR_HSTN1A");
		call(expset1,1,TmpFloat,0);
	}  


	if(VSetActive=="rlhstn2")
	{
		CurEnvTriggerSet("rlhstn2","dr_hstn2c");
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey60,2);
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_clr,VarKey60,2);
			float(_set,TmpFloat,0x7f0000);
		}

		CurEnvTriggerSet("rlhstn2","dr_hstn2a");
		call(expset1,1,TmpFloat,0);
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey60,1);
			float(_set,TmpFloat,0x7f00);
		}
		else
		{
			float(_clr,VarKey60,1);
			float(_set,TmpFloat,0x7f0000);
		}

		CurEnvTriggerSet("rlhstn2","dr_hstn2c");
		call(expset1,1,TmpFloat,0);
	}


	if(VSetActive=="rlpltn")
	{
		CurEnvTriggerSet("rlpltn","Dr_pltn34");
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey60,2);
			float(_set,TmpFloat,0x007f00);
		}
		else
		{
			float(_clr,VarKey60,2);
			float(_set,TmpFloat,0x7f0000);
		}
		CurEnvTriggerSet("rlpltn","Dr_pltn12");
		call(expset1,1,TmpFloat,0);
		if(VKeyObjTriggered==0)
		{
			float(_or,VarKey60,1);
			float(_set,TmpFloat,0x007f00);
		}
		else
		{
			float(_clr,VarKey60,1);
			float(_set,TmpFloat,0x7f0000);
		}
		CurEnvTriggerSet("rlpltn","Dr_pltn34");
		call(expset1,1,TmpFloat,0);
	}



	if(VSetActive=="rlquar")
	{
		if(VarKey54&=4)
		{
			float(_set,TmpFloat,0x8000);
		}
		else
		{
			float(_set,TmpFloat,0x800000);
		}
		CurEnvTriggerSet("rlquar","Dr_quar12");
		call(expset1,1,TmpFloat,0);
		CurEnvTriggerSet("rlquar","Dr_quar34");
		call(expset1,1,TmpFloat,0);

		if(VarKey54&=1)
		{
			GetNumbActorsInSet("rlquar",_AIClassWorker,TmpFloat);
			if(TmpFloat==0)
			{
				CurEnvTriggerSet("rlquar","dead");
				call(KeyObjTrigger,255,1);
				float(_clr,VarKey54,1);			//don't check for this door opening again
			}
		}

		if(VarKey54&=2)
		{
			float(_add,VarKey62,1);

			if(VarKey62==1)
			{
				dmessage("Decontamination Sequence Initiated",100,100);
				call(ChangeFog,_SXFogType,_SXFogExp);
			}
			elseif(VarKey62==5)
			{
				vector(_Set,Gactorpos,-10936,21998,8851);
				sample(SFXCylonInitiated,Gactorpos);

				vector(_set,Gactorpos,-10951,21760,8980);
				sample(SFXVent2loop2D,Gactorpos);

				vector(_set,Gactorpos,-10953,21760,8718);
				sample(SFXVent2loop2D,Gactorpos);
			}


			if(VarKey62<=350)
			{
				if(vrnd<2)
				{
					vector(_set,Gactorine,0,10,0);
					call(SetParticleSetID,"rlquar");
					vector(_set,Gactorpos,-10988,21723,8893);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-11092,21723,8993);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-10884,21723,9003);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-10779,21723,8900);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-10884,21723,8786);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-10987,21723,8695);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-11093,21723,8799);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);

					vector(_set,Gactorpos,-10779,21723,8705);
					SpawnParticle(fx_steampipes,-1,Gactorpos,Gactorine,-1);


				}
				float(_set,TmpFloat,VarKey62);
				float(_div,TmpFloat,350);
				float(_mul,TmpFloat,0.003);
				call(ChangeFog,_SXFogDensity,TmpFloat);
			}
			else
			{
				float(_set,TmpFloat,VarKey62);
				float(_div,TmpFloat,350);
				float(_set,TmpFloat2,2);
				float(_sub,TmpFloat2,TmpFloat);
				float(_mul,TmpFloat2,0.003);
				call(ChangeFog,_SXFogDensity,TmpFloat2);
			}

			if(VarKey62==700)
			{
				message("You may proceed",120,10);

				vector(_Set,Gactorpos,-10936,21998,8851);
				sample(SFXCylonCompleted,Gactorpos);
				vector(_set,Gactorpos,-10951,21760,8980);
				samplestop(SFXVent2loop2D,Gactorpos);
				vector(_set,Gactorpos,-10953,21760,8718);
				samplestop(SFXVent2loop2D,Gactorpos);

				float(_set,VarKey62,0);
				float(_or,VarKey54,4);
				float(_clr,VarKey54,2);
				call(ChangeFog,_SXFogType,_SXFogOff);
			}
		}
	}
	if(VSetActive=="rlplza2")
	{
		float(_add,timer,2);

		if(timer==250)
		{
			vector(_set,gactorpos,-11551,21849,12386);
			sample(SFXThunder1,Gactorpos);
			float(_set,timer,0);
		}
		CurEnvTriggerSet("rlplza2","ltng5");
		if(Vrnd<15)
		{
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);

			vector(_set,gactorpos,-6609,21849,12128);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
		}
	}

	if(VSetActive=="rlplza3")					//first plaza3
	{
		CurEnvTriggerSet("rlplza3","ltng6");
		if(Vrnd<5)
		{
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);

			vector(_set,gactorpos,-8595,21849,11934);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);

			vector(_set,gactorpos,-7855,21849,11951);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
		}
		if(Vrnd<2)
		{
			float(_set,TmpFloat,0xffffff);
			call(expset2,1,TmpFloat,0);

			vector(_set,gactorpos,-10556,21849,11268);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);

			vector(_set,gactorpos,-9700,21849,11788);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			call(expset2,1,TmpFloat,0);
		}
	}

	if(VSetActive=="rlplza4a")
	{
		CurEnvTriggerSet("rlplza4a","lovedoor");
		float(_set,Tmpfloat,0x00FF00);
		Call(ExpSet1,1,Tmpfloat,0);
	}	

	if(VSetActive=="rlhsng2")
	{
		float(_add,timer,2);

		if(timer==320)
		{
			vector(_set,gactorpos,-15754,21849,12721);
			sample(SFXThunder1,Gactorpos);
		}
		if(timer==450)
		{
			vector(_set,gactorpos,-13643,21849,12724);
			sample(SFXThunder2,Gactorpos);
		}
		if(timer>=500)
		{
			float(_set,timer,0);
		}

		CurEnvTrigger("DR_HSRM1A");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			CurEnvTriggerSet("rlhsrm1","DR_HSRM1A");
			call(KeyObjTrigger,255,1);
			kfsample(SFXDoOp1,SFXDoMo1,-1,SFXDoCl1);
			direction(_clr,_DIRaction);
		}

		CurEnvTrigger("ltng3");
		if(Vrnd<5)
		{
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			vector(_set,gactorpos,-15069,22138,11846);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);

			vector(_set,gactorpos,-15069,21202,11846);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
		}
		if(Vrnd<2)
		{
			float(_set,TmpFloat,0xffffff);
			call(expset2,1,TmpFloat,0);
			vector(_set,gactorpos,-16153,21202,11959);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);

			vector(_set,gactorpos,-16153,22138,11959);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			call(expset2,1,TmpFloat,0);
		}
	}

	if(VSetActive=="rlhsng3")
	{
		float(_add,timer,2);

		if(timer==250)
		{
			vector(_set,gactorpos,-11551,21849,12386);
			sample(SFXThunder1,Gactorpos);
			float(_set,timer,0);
		}


		CurEnvTrigger("ltng2");
		if(Vrnd<7)
		{
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			vector(_set,gactorpos,-13255,22138,12099);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);

			vector(_set,gactorpos,-13255,21202,12099);
			vector(_set,tmpvector,18,167,236);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
		}
	}

	if(VCurSet=="Rlhsng4")		//is curset, because there is so many active in redlite
	{
		call(SetParticleSetID,"Rlhsng4");
		if(VarKey64&=1)
		{
			float(_set,TmpFloat,1);
			float(_set,TmpFloat2,-1);
		}
		else
		{
			float(_set,TmpFloat,-1);
			float(_set,TmpFloat2,1);
		}
		
		//	Missing sounds
		//
		if(VarKey64<90)
		{
			vector(_set,Gactorpos,-12078,20978,8041);
			if(VRnd<50)
			{
				vector(_setx,Gactorine,TmpFloat);
				vector(_sety,Gactorine,TmpFloat2);
				vector(_setz,Gactorine,10);
				call(SetParticleSetID,"Rlhsng4");
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
			}
			if(skipcollidecount>=5)
			{
				vector(_addz,Gactorpos,45);
				call(CheckActorCollision,gactorpos,45,0,_COLsteam);
			}
		}
		elseif(VarKey64<180)
		{
			vector(_set,Gactorpos,-11590,20978,8041);
			if(VRnd<50)
			{
				vector(_setx,Gactorine,TmpFloat2);
				vector(_sety,Gactorine,TmpFloat);
				vector(_setz,Gactorine,10);
				call(SetParticleSetID,"Rlhsng4");
				SpawnParticle(fx_steam,-1,Gactorpos,Gactorine,-1);
			}
			if(skipcollidecount>=5)
			{
				vector(_addz,Gactorpos,45);
				call(CheckActorCollision,gactorpos,45,0,_COLsteam);
			}
		}
		float(_add,VarKey64,1);
		if(VarKey64>270)
		{
			float(_set,VarKey64,0);
		}
	}

	if(skipcollidecount>=5)
	{
		float(_set,skipcollidecount,0);
	}
	float(_add,skipcollidecount,1);

	float(_add,FireJetLife,1);
}













SubRoutine(BackgroundTriggerChecksScene8)
{

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel8); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

//////////////////////////
//// REDLITE DISTRICT ////
//////////////////////////
	if(VCurSet=="rlelev")
	{
		CurEnvTrigger("lift");
		if(VTrigger==_DIRenvTrigger)
		{
			call(PlayerInput,0);
			float(_set,timer,2);
		}

		if(timer>=2)
		{	
			float(_add,timer,1);
			if(timer>=150)
			{
				actorflag(_or,_AFLAGresetfallalt);
				call(LoadLevel,-1,16);
			}
		}
	}
	elseif(VCurSet=="rlhsng3c")
	{
		if(VAICon==0)
		{
			if(Varbit&=Help03)
			{
				CurEnvTrigger("kill");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_clr,VarBit,Help03);
					CurEnvTriggerSet("rlhsng4c","invwall");
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}
			}
		}
	}
	elseif(VCurSet=="rlhsng4c")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);

		if(VAICon!=0)
		{
			if(VAIClass==_AIClassSubGirl && VAction==GENCoweringLoop)
			{
				GetNumbActorsInSet("rlhsng4c",_AIClassCop,Tmpfloat);
				if(Tmpfloat==0)
				{
					ActorFlag(_clr,_AFLAGnoai);
					callsub(Sub_AIGetBackToIdle);
				}
			}

			if(VarBit&!=Help03)
			{
				if(VAIClass==_AIClassSubGirl && VarBit&=Help05)
				{
				//	call(AIChangeMeToEnemy);
//not localized					sample(SFXCopLaughter,-1);
					float(_clr,VarBit,Help05);
				}
				if(VarBit&=Help04)
				{
					sample(SFXFemaleScream,-1);
					float(_clr,VarBit,Help04);
				}
			}
			else
			{
				if(VarBit&=Help04)
				{
					if(VAIClass==_AIClassSubGirl)
					{
						ActorFlag(_or,_AFLAGnoai);
						if(Vaction!=GENCoweringLoop)
						{
							spawnaction(GENCoweringLoop);
						}
					}
				}
			}
		}
	}
	elseif(VCurSet=="rlpimp3")
	{
	}
	elseif(VCurSet=="rlpimp2")
	{
		if(VAIClass==_AIClassPimp && VAICon!=0)
		{
			if(VarKey58&=128)
			{
				float(_clr,VarKey58,128);
				float(_or,VarKey58,256);
				Sample(SFXPlayerActivatesButtonReact,-1);
			}
			elseif(VarKey58&=256)
			{
/*				float(_rnd2,tmpfloat,100);
				if(tmpfloat<0.3)
				{
					SamplePlaying(SFXPlayerActivatesButtonReact,-1);
					if(vtrigger!=_DIRTempFlag)
					{
						SamplePlaying(SFXBoredIdle,-1);
						if(vtrigger!=_DIRTempFlag)
						{
							Sample(SFXPlayerActivatesButtonReact,-1);
						}
					}
				}*/
			}
		}
		
		if(VAICon==0)
		{
			CurEnvTrigger("detect");
			if(VKeyObjFrame==9 && VarKey52==1)
			{
				sample(SFXSmlDoor,Gactorpos);
				float(_set,VarKey52,2);
			}

			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass==_AIClassPimp)
				{
					if(VKeyObjTriggered==0 && VarKey52==0)
					{
						call(KeyObjTrigger,255,1);
						message("Welcome Mr Pimp Daddy.",120,10);
						sample(SFXAccessOk,Gactorpos);
						sample(SFXSmlDoor,Gactorpos);
						float(_set,VarKey52,1);
					}
				}
				else
				{
					message("Pimp Daddy must be scanning fingerprints",200,10);
				}
			}


			if(VarKey58&!=1)
			{
				CurEnvTrigger("SafeOpen");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VTrigger==_DIRaction)
					{
						if(VKeyObjFrame==0 && VKeyObjTriggered==0)
						{
							call(KeyObjTrigger,255,1);
							vector(_set,Gactorpos,-11829,23449,6482);
							sample(SFXWepDispenser,Gactorpos);
						}
						elseif(VKeyObjFrame==11)
						{
							call(ActivateButton,"You now know the VIP passcode for club kyd",-1,FALSE);
							call(ChangeTrigger,_clr,_SXTrigPanel);
						}
					}
					if(VState==StateJustActivated)
					{
						float(_or,VarKey58,1);	//VIP pass taken
						call(SetTriggerObjFlag,1,_set,_SXObjCollisionOff|_SXObjInvisible);

						GetNumbActorsInSet("rlpimp2",_AIclasspimp,TmpFloat);
						GetNumbActorsInSet("rlpimp1",_AIclasspimp,TmpFloat2);
						float(_add,TmpFloat,TmpFloat2);
						if(TmpFloat!=0)
						{
							//call(AIchangemetoenemy);
							//float(_or,VarKey58,16);	//play pimp buttonreact sample
							float(_or,VarKey58,128);
						}
					}
				}
			}
			if(VAIClass==_AIClassPimp)
			{
				if(VTrigger==_DIRaction && VarKey52==2)
				{
					CurEnvTrigger("pimp");
					if(Vtrigger==_DIREnvTrigger)
					{
						call(ChangeSniperMode,0,0);
						call(ActivateButton,"Your private lift has been activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,255,1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
						call(PlayerInput,FALSE);
						//	do sequence here
						//
						call(ExpSet2,4096,1,1);	//expcamera position, inf seconds, use exp1 for target
						float(_set,VarKey52,3);
					}
				}
				if(VarKey52==3)
				{
					move(0,-2,0);				//force a smooth down elevator action
					CurEnvTrigger("pimp");
					if(VKeyObjTriggered==0)		//has the platform stopped moving down there?
					{
						float(_set,VarKey52,4);
						call(ExpSet2,-1,0,0);	//turn expcamera off
						CutScene("camera01");	//play camera sequence
						call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
						call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
						call(ChangeCutScene,_SXCUTspeed,250);
						call(SetCamBulb,0);
						Sample(SFXPimpLiftLoop,-1);
						Sample(SFXCapsuleLaunch,-1);
						//float(_set,Timer,250);
						//float(_seti,tmpfloat2,VCutSceneFrame);
					}
				}
				elseif(VarKey52==4)
				{
					if(VCheatKeys==1)
					{
						if(VKey==KEY_S)
						{
							float(_seti,tmpfloat,VCutSceneFrame);
					
							break(tmpfloat,VCutSceneFrame,Timer);
						}
					}

					if(VCutSceneFrameEqual==69)
					{
						//call(ChangeCutScene,_SXCUTSpeed,600);
					}
					elseif(VCutSceneFrameEqual==85)
					{
						//call(ChangeCutScene,_SXCUTSpeed,250);
					}

					if(VCutSceneFrame<14)
					{
					//	call(ChangeCutScene,_SXCutSpeed,TmpFloat3);
					}
					elseif(VCutSceneFrame==14)
					{
						//call(ChangeCutScene,_SXCutSpeed,50);
						//float(_set,timer,50);
					}
					elseif(VCutSceneFrame<30)
					{
						if(VCutSceneFrame!=tmpfloat2)
						{
							//float(_add,Timer,15);
							//call(ChangeCutScene,_SXCUTspeed,Timer);
							call(ChangeCutScene,_SXCUTspeed,250);
							//float(_seti,tmpfloat2,VCutSceneFrame);
						}
					}

					if(VCutScene==0)
					{
						SetActorToTrigger("Rlpimp3","PimpPos");
						call(SetCamBulb,1);
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						call(PlayerInput,TRUE);
						float(_set,VarKey52,5);
						SampleStop(SFXPimpLiftLoop);
						Sample(SFXLatch2,-1);
					}
				}
			}
		}
		elseif(VAIclass==_AIclasspimp && VarKey58&=16)
		{
			sample(SFXPlayerActivatesButtonReact,-1);
			float(_clr,VarKey58,16);
		}

		if(VAIClass!=_AIClassPimp)
		{
			if(VarKey52==3 || VarKey52==4)
			{
				direction(_clr,_DIRMoveBits|_DIRShoot);
				callsub(Sub_AIGetBackToIdle);
			}
		}

	}
	elseif(VCurSet=="RLldg1")
	{

		vector(_settoactorpos,TmpVector);
		vector(_copyy,TmpVector,TmpFloat);
		float(_seti,TmpFloat2,VColFeetSphereBottom);
		float(_add,TmpFloat,TmpFloat2);

		Print("POSY: ",TmpFloat);

		if(TmpFloat>21100 && TmpFloat<21225)
		{
			if(VState!=StateElectricShock && VState!=StateThrown)
			{
				CurEnvTrigger("Elec01");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				CurEnvTrigger("Elec02");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				CurEnvTrigger("Elec03");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				CurEnvTrigger("Elec04");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
			}
		}
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="rlhsin")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("DR_PIMP12");
			if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassAnimal && VAICon==0)
			{
				//callsub(DoorOpen,0,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					call(ForceLoadSet,"RLPimp2");
				}
			}
			CurEnvTrigger("DR_HSTN1C");
			if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassAnimal)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLhstn1" && ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
				float(_or,VarKey58,2);
			}
			CurEnvTrigger("Dr_hstn2c");
			if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassAnimal)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLhstn2" && ControlTimer==0)
				{
					float(_set,ControlTimer,3);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("legate");
			if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassAnimal)
			{
				call(ActivateButton,0,-1,0);
			}


			CurEnvTrigger("Lever");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey58&=4096)
				{
					call(ActivateButton,"Stopping piston",-1,FALSE);
				}
				else
				{
					call(ActivateButton,"Engaging piston",-1,FALSE);
				}
			}
		}

		if(VState==StateJustActivated)
		{
			CurEnvTrigger("legate");
			if(VTrigger==_DIREnvTrigger && VAIClass!=_AIClassAnimal)
			{
				sample(SFXValidFunction,-1);
				call(KeyObjTrigger,255,1);
				kfsample(SFXDoop9,-1,-1,-1,1);
			}

			CurEnvTrigger("Lever");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey58&=4096)
				{
					call(KeyObjTrigger,255,1);

					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);

					CurEnvTrigger("Power01");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power02");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power03");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power04");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power05");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power06");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power07");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power08");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power09");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					CurEnvTrigger("Power10");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

					CurEnvTrigger("Redlites");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

					float(_clr,VarKey58,4096);
				}
				else
				{
					call(KeyObjTrigger,1,1);
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);

					CurEnvTrigger("Power01");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power02");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power03");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power04");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power05");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power06");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power07");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power08");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power09");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
					CurEnvTrigger("Power10");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);

					CurEnvTrigger("Redlites");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);

					vector(_set,Gactorpos,-13474,22466,7938);
					SamplePlaying(SFXShaftRotate2,Gactorpos);
					if(VTrigger!=_DIRTempFlag)
					{
						sample(SFXShaftRotate2,Gactorpos);
						vector(_set,Gactorpos,-13474,20863,7938);
						sample(SFXGears,Gactorpos);
					}

					float(_or,VarKey58,4096);
				}
			}
		}




		if(VAICon==0)
		{
			if(ControlTimer==1)
			{
				CurEnvTrigger("DR_PIMP12");

				if(VSetActive=="RLpimp1" && VSetInMemory=="RLpimp2")
				{
					callsub(DoorOpen,0,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("rlhsin","DR_PIMP12",1);
					call(KeyObjTrigger,255,1);
				}
			}
			if(ControlTimer==2)
			{
				CurEnvTrigger("DR_HSTN1C");
				if(VSetActive=="RLhstn1")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("rlhsin","DR_HSTN1C",1);
					call(KeyObjTrigger,255,1);
				}
			}
			if(ControlTimer==3)
			{
				CurEnvTrigger("Dr_hstn2c");
				if(VSetActive=="RLhstn2")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("rlhsin","Dr_hstn2c",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("LiftCam");
			if(VKeyObjWait!=0)
			{
				callsub(Sub_SetCameraNormal);
			}
			else
			{
				vector(_set,TmpVector,170,900,300);
				Call(TriggerBox,TmpVector,0,tmpfloat);
				if(tmpfloat==1)
				{
					camera(200,300);
				}
				else
				{
					callsub(Sub_SetCameraNormal);
				}
			}
		}
	}
	elseif(VCurSet=="rlhstn1")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("DR_HSTN1C");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey58&=2)
				{
					if(VarKey60&=2)
					{
						//callsub(DoorOpen,1,1);
						if(VSetActive!="rlhsin" && ControlTimer==0)
						{
							float(_set,ControlTimer,1);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
						}
					}
				}
				else
				{
					Message("This door is locked from the inside",200,10);
					sample(SFXLockedSound,-1);
					if(vrnd<33)
					{
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}
				}
			}

			CurEnvTrigger("Dr_hstn1a");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey60&=1)
				{
					//callsub(DoorOpen,1,1);
					if(VSetActive!="RLhsng1b" && ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					Message("Wait for airlock to close",200,10);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("DR_HSTN1C");
			if(VSetActive=="rlhsin")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhstn1","DR_HSTN1C",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("Dr_hstn1a");
			if(VSetActive=="RLhsng1b")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhstn1","Dr_hstn1a",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}  
	elseif(VCurSet=="rlhstn2")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("Dr_hstn2a");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey60&=2)
				{
					//callsub(DoorOpen,1,1);
					if(VSetActive!="RLhsng1c" && ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					Message("Wait for airlock to close",200,10);
				}
			}
			
			CurEnvTrigger("Dr_hstn2c");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey60&=1)
				{
					//callsub(DoorOpen,1,1);
					if(VSetActive!="RLhsin" && ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					Message("Wait for airlock to close",200,10);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("Dr_hstn2a");
			if(VSetActive=="RLhsng1c")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhstn2","Dr_hstn2a",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("Dr_hstn2c");
			if(VSetActive=="RLhsin")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhstn2","Dr_hstn2c",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}  
	elseif(VCurSet=="rlhsapt1")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("HSNGDR01");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				//callsub(DoorOpen,0,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,3);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			
			CurEnvTrigger("Channels");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				//Call(Expget,1,tmpfloat);

				Call(Expset1,0,0,509);
				Call(Expset2,0,0,0);

				Vector(_set,Gactorpos,-13496,22748,9839);
				SamplePlaying(SFXSatanTakeoverFlic,Gactorpos);
				if(VTrigger==_DIRTempFlag)
				{
					samplestop(SFXSatanTakeoverFlic,Gactorpos);
				}

				
/*				if(tmpfloat<=511)
				{
					Call(Expset1,510,510,901);
					call(CDPlaySegment,4,0,34,1,00);
					Call(Expset2,1,1,1);
				}
				elseif(tmpfloat<=901)
				{
					Call(Expset1,902,902,1338);
//					call(CDPlaySegment,4,1,00,1,29);
					if(VLanguage==0)
					{
						call(CDPlaySegment,4,1,00,1,29);
					}
					elseif(VLanguage==1)
					{
						call(CDPlaySegment,4,3,25,3,54);
					}
					elseif(VLanguage==2)
					{
						call(CDPlaySegment,4,4,27,4,59);
					}
					Call(Expset2,2,2,2);
				}
				elseif(tmpfloat<=1338)
				{
					Call(Expset1,1339,1339,1745);
					call(CDPlaySegment,4,1,29,1,56);
					Call(Expset2,3,3,3);
				}
				elseif(tmpfloat<=1745)
				{
					Call(Expset1,1746,1746,2550);
					call(CDPlaySegment,4,1,56,2,50);
					Call(Expset2,4,4,4);
				}
				else
				{
					Call(Expset1,0,0,509);
					if(VLanguage==0)
					{
						call(CDPlaySegment,4,0,0,0,34);
					}
					elseif(VLanguage==1)
					{
						call(CDPlaySegment,4,2,50,3,24);
					}
					elseif(VLanguage==2)
					{
						call(CDPlaySegment,4,3,54,4,27);
					}
					Call(Expset2,0,0,0);
				}*/
			}
			
		}

		if(ControlTimer==3)
		{
			CurEnvTrigger("HSNGDR01");
			if(VSetActive=="RLhsng2a")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhsapt1","HSNGDR01",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}  
	elseif(VCurSet=="rlhsapt2")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("HSNGDR02");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLhsng2a" && ControlTimer==0)
				{
					float(_set,ControlTimer,4);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			
			CurEnvTrigger("Channels");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				Call(Expget,1,tmpfloat);

				if(tmpfloat<427)
				{
					Call(Expset1,427,427,1239);
					Call(Expset2,1,1,1);
				}
				else
				{
					Call(Expset1,0,0,427);
					Call(Expset2,0,0,0);
				}

				/*if(tmpfloat<=511)
				{
					Call(Expset1,510,510,901);
					call(CDPlaySegment,4,0,34,1,00);
					Call(Expset2,1,1,1);
				}
				elseif(tmpfloat<=901)
				{
					Call(Expset1,902,902,1338);
//					call(CDPlaySegment,4,1,00,1,29);
					if(VLanguage==0)
					{
						call(CDPlaySegment,4,1,00,1,29);
					}
					elseif(VLanguage==1)
					{
						call(CDPlaySegment,4,3,25,3,54);
					}
					elseif(VLanguage==2)
					{
						call(CDPlaySegment,4,4,27,4,59);
					}
					Call(Expset2,2,2,2);
				}
				elseif(tmpfloat<=1338)
				{
					Call(Expset1,1339,1339,1745);
					call(CDPlaySegment,4,1,29,1,56);
					Call(Expset2,3,3,3);
				}
				elseif(tmpfloat<=1745)
				{
					Call(Expset1,1746,1746,2550);
					call(CDPlaySegment,4,1,56,2,50);
					Call(Expset2,4,4,4);
				}
				else
				{
					Call(Expset1,0,0,509);
					if(VLanguage==0)
					{
						call(CDPlaySegment,4,0,0,0,34);
					}
					elseif(VLanguage==1)
					{
						call(CDPlaySegment,4,2,50,3,24);
					}
					elseif(VLanguage==2)
					{
						call(CDPlaySegment,4,3,54,4,27);
					}
					Call(Expset2,0,0,0);
				}*/
			}
			
		}

		if(ControlTimer==4)
		{
			CurEnvTrigger("HSNGDR02");
			if(VSetActive=="RLhsng2a")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhsapt2","HSNGDR02",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}  
	elseif(VCurSet=="rlpimp1")
	{
		CurEnvTriggerSet("rlpimp2","detect");
		if(VKeyObjFrame==9 && VarKey52==1)
		{
			sample(SFXSmlDoor,Gactorpos);
			float(_set,VarKey52,2);
		}

		if(VAIClass!=_AIClassPimp)
		{
			if(VarKey52==3 || VarKey52==4)
			{
				direction(_clr,_DIRMoveBits|_DIRShoot);
				callsub(Sub_AIGetBackToIdle);
			}
		}

		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("DR_PIMP12");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLhsin" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("DR_PIMP12");
			if(VSetActive=="RLhsin")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlpimp1","DR_PIMP12",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VAICon!=0 && VAIclass==_AIclasspimp && VarKey58&=16)
		{
			sample(SFXPlayerActivatesButtonReact,-1);
			float(_clr,VarKey58,16);
		}
	}
	elseif(VCurSet=="rlpimp4")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("DR_PIMP2");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="rlplin" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
	
		if(ControlTimer==1)
		{
			CurEnvTrigger("DR_PIMP2");
			if(VSetActive=="rlplin")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlpimp4","DR_PIMP2",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="rlhsstr1")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("HSNGDR01");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLhsng4a" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("HSNGDR01");
			if(VSetActive=="RLhsng4a")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhsstr1","HSNGDR01",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="rlhsng2a")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("HSNGDR01");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLhsapt1" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("HSNGDR02");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLhsapt2" && ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("LeDoor");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,3);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("HSNGDR01");
			if(VSetActive=="RLhsapt1")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);

				CurEnvTriggerSet("rlhsapt1","Channels");
				Call(Expset1,0,0,509);
				Call(Expset2,0,0,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhsng2a","HSNGDR01",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("HSNGDR02");
			if(VSetActive=="RLhsapt2")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);

				CurEnvTriggerSet("rlhsapt2","Channels");
				Call(Expset1,0,0,509);
				Call(Expset2,0,0,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlhsng2a","HSNGDR02",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==3)
		{
			CurEnvTrigger("LeDoor");
			if(VSetActive=="RLHSNG1A")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLHSNG2A","LeDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="rlhsng2b")
	{
		if(VAICon==0)
		{
			if(VarKey58&!=8192)
			{
				CurEnvTrigger("SubGirl01");
				if(VTrigger==_DIREnvTrigger)
				{
					vector(_set,Gactorpos,-15052,21727,9530);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(subgirl1,Gactorpos,Gactorangle,"Rlhsng2b",TRUE,2);

					vector(_set,Gactorpos,-14940,21727,9620);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(subgirl1,Gactorpos,Gactorangle,"Rlhsng2b",TRUE,1);
					
					float(_or,VarKey58,8192);
				}
			}

			if(VarKey58&!=16384)
			{
				CurEnvTrigger("SubGirl02")
				if(VTrigger==_DIREnvTrigger)
				{
					vector(_set,Gactorpos,-14088,22244,9896);
					vector(_set,Gactorangle,0,2048,0);
					InitActor(subgirl1,Gactorpos,Gactorangle,"Rlhsng2b",TRUE,5);

					float(_or,VarKey58,16384);
				}
			}
		}
	}
	elseif(VCurSet=="rlplin")
	{
		if(VAICon==0)
		{
			GetNumbActorsInSet("rlplin",_AIclassbeast,TmpFloat);
			if(TmpFloat>0)
			{
				CurEnvTrigger("bncrwarn");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VAIClass==_AIclasspimp)
					{
						Message("welcome mister pimp daddy",200,10);
					}
					elseif(VarKey58&=1)
					{
						Message("Come on in@ we always let the VIPs through",200,10);
					}
					else
					{
						Message("You're no VIP! Get lost or I'll kick your head in!",200,10);
						if(VarBit&=Help06)
						{
							float(_set,Incoming,1);
							float(_set,Godtimer,0);
							float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
							float(_set,ScriptMark,21);
							callsub(Panel21);
							float(_clr,VarBit,Help06);
						}
					}
				}

				CurEnvTrigger("bncrmad");
				if(VTrigger==_DIREnvTrigger && VarKey58&!=1 && VAIClass!=_AIclasspimp) 
				{
					//bouncer get pissed
					float(_or,VarKey58,32);
					float(_set,CommandTimer,0);
				}
			}

			CurEnvTrigger("pdoor");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction) 
			{
				Message("Door is locked from the inside",120,10);
				sample(SFXLockedSound,-1);
				if(vrnd<33)
				{
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}

			CurEnvTrigger("LiftCam");
			if(VKeyObjWait!=0)
			{
				callsub(Sub_SetCameraNormal);
			}
			else
			{
				vector(_set,TmpVector,170,900,300);
				Call(TriggerBox,TmpVector,0,tmpfloat);
				if(tmpfloat==1)
				{
					camera(200,300);
				}
				else
				{
					callsub(Sub_SetCameraNormal);
				}
			}
		}

		if(VarKey58&=32 && VAICon!=0 && VAIClass==_AIclassbouncer)
		{
			callsub(TurnToPlayer);
			float(_add,CommandTimer,1);
			if(CommandTimer==50)
			{
				float(_clr,VarKey58,32);
				call(AIchangeplayertoenemy);
			}
		}

		if(VarKey56==0)
		{
			CurEnvTrigger("vidball");
			call(KeyObjTrigger,23,1,-1);
			call(KeyObjActiveSegment,0,23);
			float(_set,VarKey56,1);
		}

		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("dr_pltn34");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLpltn" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("dr_pltn34");
			if(VSetActive=="RLpltn")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlplin","dr_pltn34",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VAICon==0)
		{
			if(VarBit&!=Help01)
			{
				if(VarKey1==0)
				{
					call(PlayerInput,0);
					message("Access Granted",120,10);
					CurEnvTrigger("enter");
					callsub(DoorOpen,1,1);
					float(_set,VarKey1,1);
				}
				elseif(VarKey1==1)
				{
					CurEnvTrigger("enter");
					if(VKeyObjFrame==1)
					{
						call(FaceTriggerDirection);
						float(_set,VarKey1,2);
					}
				}
				elseif(VarKey1==2)
				{
					direction(_clr,_noDIR);
					direction(_or,_DIRForward|_DIRmove);
					CurEnvTrigger("stop");
					if(VTrigger==_DIREnvTrigger)
					{
//						call(LoadPreLoadDB,22);
						CutScene("scroll");
						call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
						call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
						setkeyframe("rlplin","enter",0);
						CurEnvTrigger("lift");
						call(KeyObjTrigger,255,1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
						float(_set,VarKey1,3);
						float(_set,timer,0);
					}
				}
				elseif(VarKey1==3)
				{
					float(_add,timer,1);
					if(timer>=50)
					{
						float(_set,VarKey1,4);
						float(_set,timer,0);
					}
				}
				elseif(VarKey1==4)
				{
					float(_add,timer,1);
					if(timer==5)
					{
						call(FadeToBlack,0);
					}
					elseif(timer==120)
					{
						float(_set,VarKey1,5);
						actorflag(_or,_AFLAGresetfallalt);
						call(LoadLevel,-1,16);
					}
				}									
			}

			CurEnvTrigger("VIPL5");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(VarKey58&=8)
					{
						Message("access already granted",200,10);
						sample(SFXInvalidFunction,-1);
					}
					else
					{
						if(VarKey58&=1 || VAIClass==_AIclasspimp)			//have the VIP pass
						{
							call(ActivateButton,"Entering passcode",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							float(_or,VarKey58,1);
						}
						else
						{
							Message("I do not have the passcode",200,10);
							sample(SFXInvalidFunction,-1);
						}
					}
				}

				if(VarKey58&=1 && VarKey58&!=8 && VState==StateJustActivated)
				{
					float(_set,timer,0);
					float(_set,timer2,0);
					float(_or,VarKey58,4);
				}
			}

			////////////////////
			// LINK TO ACCESS //
			////////////////////
			CurEnvTrigger("enter");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
			{
				if(VarKey58&=8)
				{
					float(_clr,VarBit,Help01);
				}
				else
				{
					message("Door locked",200,10);
					sample(SFXInvalidFunction,-1);
				}
			}
		}
		else
		{
			if(VarKey1!=0)
			{
				direction(_clr,_DIRMoveBits|_DIRShoot);
				callsub(Sub_AIGetBackToIdle);
			}
		}
	}
	elseif(VCurSet=="rlpltn")
	{
		CurEnvTrigger("Dr_pltn34");
		if(VKeyObjFrame==10)
		{
			if(VCDTrack!=19)
			{
				Call(CDSwap,19,1,100,60);
			}
		}

		CurEnvTrigger("Dr_pltn34");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey60&=1)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLplin" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);

					if(VCDTrack!=21 && VLanguage==0)
					{
						Call(CDSwap,21,1,100,60);
					}
				}
			}
			else
			{
				Message("Wait for airlock to close",200,10);
			}
		}

		CurEnvTrigger("Dr_pltn12");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey60&=2)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLplza1b" && ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,2);
					direction(_clr,_DIRaction);
				}
			}
			else
			{
				Message("Wait for airlock to close",200,10);
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("Dr_pltn34");
			if(VSetActive=="RLplin")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlpltn","Dr_pltn34",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("Dr_pltn12");
			if(VSetActive=="RLplza1b")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlpltn","Dr_pltn12",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="rlquar")
	{
		if(VAIClass==_AIClassWorker)
		{
			ActorFlag(_or,_AFLAGnopossesion);
		}

		if(VarKey54&=4)
		{
			CurEnvTrigger("Dr_quar12");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLplza4b" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					call(ForceGlobalRealloc);
					call(ForceLoadSet,"rlplza3b");
					call(ForceLoadSet,"rlplza2b");
					call(ForceLoadSet,"rlplza1b");
				}
			}

			CurEnvTrigger("Dr_quar34");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLhsng4b" && ControlTimer==0)
				{
					dmessage("L O A D I N G . . .",50,2);
					call(LoadPreLoadDB,22);
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					call(ForceGlobalRealloc);
					call(ForceLoadSet,"rlhsng3b");
					call(ForceLoadSet,"rlhsng2b");
					call(ForceLoadSet,"rlhsng1b");
				}
			}
		}
		else
		{
			if(VarKey54&=2)
			{
				CurEnvTrigger("Dr_quar12");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					Message("Decontamination procedure still in progress",200,10);
				}

				CurEnvTrigger("Dr_quar34");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					Message("Decontamination procedure still in progress",200,10);
				}
			}
			else
			{
				CurEnvTrigger("Dr_quar12");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					if(VKeyObjTriggered==0)
					{
						CurEnvTrigger("Dr_quar34");
						if(VKeyObjTriggered==0)
						{
							float(_or,VarKey54,2);
						}
					}
				}

				CurEnvTrigger("Dr_quar34");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					if(VKeyObjTriggered==0)
					{
						CurEnvTrigger("Dr_quar12");
						if(VKeyObjTriggered==0)
						{
							float(_or,VarKey54,2);
						}
					}
				}
			}
		}


		CurEnvTrigger("Dr_quar12");
		if(VKeyObjFrame==17)
		{
			float(_or,VarKey54,2);
		}

		CurEnvTrigger("Dr_quar34");
		if(VKeyObjFrame==17)
		{
			float(_or,VarKey54,2);
		}


		if(ControlTimer==1)
		{
			CurEnvTrigger("Dr_quar12");
			if(VSetActive=="RLplza4b")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlquar","Dr_quar12",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("Dr_quar34");
			if(VSetActive=="RLhsng4b")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlquar","Dr_quar34",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="RLHSNG1A")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("LeDoor");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
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
			CurEnvTrigger("LeDoor");
			if(VSetActive=="RLHSNG2A")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLHSNG1A","LeDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}

		CurEnvTrigger("death");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLHSNG1B")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("DR_HSTN1A");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLhstn1" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("DR_HSTN1A");
			if(VSetActive=="RLhstn1")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLHSNG1B","DR_HSTN1A",1);
				call(KeyObjTrigger,255,1);
			}
		}
		CurEnvTrigger("death");
		callsub(Fall2Death);

	}
	elseif(VCurSet=="RLHSNG1C")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("DR_HSTN2A");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLhstn2" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("DR_HSTN2A");
			if(VSetActive=="RLhstn2")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLHSNG1C","DR_HSTN2A",1);
				call(KeyObjTrigger,255,1);
			}
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
		CurEnvTrigger("death");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLHSNG2C")
	{
		if(Objective==0 && VarKey2==8)
		{
			float(_set,Incoming,1);
			float(_set,Godtimer,0);
			float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
			float(_set,ScriptMark,20);
			callsub(Panel20);
			ClearDMessage();
			float(_set,Objective,1);
		}
		
		if(VAICon==0)
		{
			if(VarKey2==3)
			{
				float(_add,timer2,1);
				if(timer2>=20)
				{
					CutScene("drill");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
					float(_set,timer2,0);
					float(_set,VarKey2,4);
				}
			}
			elseif(VarKey2==4)
			{
				if(VCutSceneFrame==20)
				{
					SetActorToTrigger("RLHSNG2C","pos");
					call(FaceTriggerDirection);
				}
				CurEnvTrigger("fly");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_set,VarKey2,5);
				}
			}
			elseif(VarKey2==5)
			{
				CurEnvTrigger("fly");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_add,timer4,1);
					if(timer4>=10)
					{
						direction(_clr,_noDIR);
						direction(_or,_DIRForward|_DIRmove|_DIRjump);
					}
				}
				else
				{
					float(_add,timer2,1);
					direction(_clr,_noDIR);
					direction(_or,_DIRForward);
					if(timer2>=40)
					{
						float(_set,VarKey2,6);
						float(_set,timer2,0);
					}
				}
			}
			elseif(VarKey2==6)
			{
				float(_add,timer2,1);
				if(timer2>=20)
				{
					float(_set,VarKey2,7);
					float(_set,timer2,0);
				}
			}
			elseif(VarKey2==7)
			{
				call(PlayerInput,1);
				float(_set,AIVisionToggle,0);
				call(GodModeStatus,false);
				call(CutSceneEnd);
				float(_set,VarKey2,8);
				call(ForceGlobalRealloc);
				call(ForceLoadSet,"rlhsng1c");
				call(ForceLoadSet,"rlhsng3c");
				call(ForceLoadSet,"rlhsng4c");
				call(ForceLoadSet,"rlldg1");
				call(ForceLoadSet,"rlldg2");
				call(ForceLoadSet,"rlldg3");
			}
		}
	}
	elseif(VCurSet=="RLHSNG5")
	{
		if(VAICon==0)
		{
			if(VarKey2==4)
			{
				if(VCutSceneFrame==20)
				{
					SetActorToTrigger("RLHSNG2C","pos");
					call(FaceTriggerDirection);
				}
				CurEnvTrigger("fly");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_set,VarKey2,5);
				}
			}
			elseif(VarKey2==5)
			{
				CurEnvTrigger("fly");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_add,timer4,1);
					if(timer4>=10)
					{
						direction(_clr,_noDIR);
						direction(_or,_DIRForward|_DIRmove|_DIRjump);
					}
				}
				else
				{
					float(_add,timer2,1);
					direction(_clr,_noDIR);
					direction(_or,_DIRForward);
					if(timer2>=40)
					{
						float(_set,VarKey2,6);
						float(_set,timer2,0);
					}
				}
			}
			elseif(VarKey2==6)
			{
				float(_add,timer2,1);
				if(timer2>=20)
				{
					float(_set,VarKey2,7);
					float(_set,timer2,0);
				}
			}
			elseif(VarKey2==7)
			{
				call(PlayerInput,1);
				float(_set,AIVisionToggle,0);
				call(CutSceneEnd);
				float(_set,VarKey2,8);
			}
		}
	}
	elseif(VCurSet=="RLHSNG6A")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLHSNG6B")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLLDG2")
	{
		CurEnvTrigger("Uplift");
		if(VTrigger==_DIREnvTrigger)
		{
			camera(200,0);
		}
		else
		{
			callsub(Sub_SetCameraNormal);
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLLDG3")
	{
		vector(_settoactorpos,TmpVector);
		vector(_copyy,TmpVector,TmpFloat);
		float(_seti,TmpFloat2,VColFeetSphereBottom);
		float(_add,TmpFloat,TmpFloat2);

		Print("POSY: ",TmpFloat);

		if(TmpFloat>21100 && TmpFloat<21225)
		{
			if(VState!=StateElectricShock && VState!=StateThrown)
			{
				CurEnvTrigger("Elec01");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				CurEnvTrigger("Elec02");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				CurEnvTrigger("Elec03");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				CurEnvTrigger("Elec04");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
			}
		}
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA2C")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA3C")
	{
		//CurEnvTrigger("deathfall");
		//callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA5")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA6A")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA6B")
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLHSNG4a")
	{
 		float(_clr,VarKey54,4);			//turn contamination back to normal
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("HSNGDR01");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLhsstr1" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("HSNGDR01");
			if(VSetActive=="RLhsstr1")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLHSNG4a","HSNGDR01",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="RLHSNG4b")
	{
 		float(_clr,VarKey54,4);			//turn contamination back to normal
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("DR_QUAR34");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLquar" && ControlTimer==0)
				{
				//	call(LoadPreLoadDB,15);
					float(_set,ControlTimer,9);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==9)
		{
			CurEnvTrigger("DR_QUAR34");
			if(VSetActive=="RLquar")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLHSNG4b","DR_QUAR34",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="rlplza3b")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("ChkPoint");
			if(VTrigger==_DIREnvTrigger)
			{
				GetNumbActorsInSet("rlplza3b",_AIclasscop,TmpFloat);

				if(VClass==_ClassCop)
				{
					if(TmpFloat>1)
					{
						if(VRank<_RankSergeantH)
						{
							Message("No lower ranking officer is allowed past this point!",200,10);
						}
						else
						{
							Message("Watch out for those evil subgirls sir!",200,10);
						}
					}
				}
				elseif(TmpFloat>=1)
				{
					Message("The housing district has been quarantined@ go away!",200,10);
				}
			}
		}
		else
		{
			if(VActor==CopR && VAITargetFound==_AIenemy && VAITargetVisible==1)
			{
				if(VarKey58&!=512)
				{
					CurEnvTrigger("RCop01");
					if(VTrigger==_DIREnvTrigger)
					{
						callsub(Sub_AIGetBackToIdle);
						call(AIClrTarget);
						call(AIFindPathWithSpecificID,12);
						float(_or,VarKey58,512);
					}
				}
				if(VarKey58&!=1024)
				{
					CurEnvTrigger("RCop02");
					if(VTrigger==_DIREnvTrigger)
					{
						callsub(Sub_AIGetBackToIdle);
						call(AIClrTarget);
						call(AIFindPathWithSpecificID,11);
						float(_or,VarKey58,1024);
					}
				}
			}
		}
	}
	elseif(VCurSet=="RLPLZA1A")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("LeDoor");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
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
			CurEnvTrigger("LeDoor");
			if(VSetActive=="RLPLZA2A")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLPLZA1A","LeDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
		
		CurEnvTrigger("death");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA1b")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("Load");
			if(vTrigger==_DIREnvTrigger)
			{
				call(ForceLoadSet,"rlplza2b");
				call(ForceLoadSet,"rlplza3b");
				call(ForceLoadSet,"rlplza4b");
			}
		}

		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("dr_pltn12");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLpltn" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("dr_pltn12");
			if(VSetActive=="RLpltn")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLPLZA1b","dr_pltn12",1);
				call(KeyObjTrigger,255,1);
			}
		}
		CurEnvTrigger("death");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA1c")
	{
		CurEnvTrigger("Condem");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VAICon==0)
		{
			message("This area is condemned",120,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
		CurEnvTrigger("death");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="RLPLZA2A")
	{
		if(VAICon==0)
		{
			float(_clr,VarKey58,64);			//don't piss the cop off
		}

		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("LoveDoor");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLplshp1" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("LeDoor");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("LoveDoor");
			if(VSetActive=="RLplshp1")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLPLZA2A","LoveDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("LeDoor");
			if(VSetActive=="RLPLZA1A")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLPLZA2A","LeDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="RLPLZA3A")
	{
		if(VAICon==0)
		{
			callsub(Sub_SetCameraNormal);
		}

		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("LoveDoor");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLplshp2" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("LOVEDOO01");
			if(VTrigger==_DIREnvTrigger)
			{
				Message("Locked.",120,10);
				sample(SFXLockedSound,-1);
				if(vrnd<33)
				{
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("LoveDoor");
			if(VSetActive=="RLplshp2")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLPLZA3A","LoveDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="rlplshp1")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("LoveDoor");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLplza2a" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("LoveDoor");
			if(VSetActive=="RLplza2a")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlplshp1","LoveDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="rlplshp2")
	{
		if(VAICon==0)
		{
			Camera(450,0);
			Target(-50,20);
		}


		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("LoveDoor");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLplza3a" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("LoveDoor");
			if(VSetActive=="RLplza3a")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlplshp2","LoveDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VarKey58&!=64 && VAICon==0)
		{
			CurEnvTrigger("MadCop");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass==_AIclassprost)
				{
					Message("Give me some sugar baby!",120,10);
				}
				elseif(VAIClass!=_AIClassCop)
				{
					//get lost
					float(_or,VarKey58,64);			//piss the cop off
					float(_set,CommandTimer,0);
					sample(SFXCopBlueLastLonger,-1);
				}
			}
		}

		if(VarKey58&=64 && VAICon!=0 && VAIClass==_AIclasscop)
		{
			callsub(TurnToPlayer);

			float(_add,CommandTimer,1);
			if(CommandTimer==50)
			{
				Message("Get lost@ can't you see I'm busy?",120,10);
			}
			elseif(CommandTimer==200)
			{
				Message("That's it! I've had it with you!",120,10);
				float(_clr,VarKey58,64);
				call(AIchangeplayertoenemy);
			}
		}


		if(VAICon==0 && VTrigger==_DIRAction)
		{
			CurEnvTrigger("Machine01");
			if(VTrigger==_DIREnvTrigger)
			{
				Message("Damn@ wish I had some money for this thing.",120,10);
			}
			CurEnvTrigger("Machine02");
			if(VTrigger==_DIREnvTrigger)
			{
				Message("Someone sure messed this baby up.",120,10);
			}
			CurEnvTrigger("Machine03");
			if(VTrigger==_DIREnvTrigger)
			{
				Message("Says it's out of order...",120,10);
			}
			CurEnvTrigger("Machine04");
			if(VTrigger==_DIREnvTrigger)
			{
				Message("Too bad these things don't take checks.",120,10);
			}
		}
	}
	elseif(VCurSet=="rlplshp3")
	{
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("LoveDoor");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,0,1);
				if(VSetActive!="RLplza4a" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("LoveDoor");
			if(VSetActive=="RLplza4a")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("rlplshp3","LoveDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("Camera")
			vector(_set,TmpVector,80,120,80);
			float(_seti,TmpFloat2,VColFeetSphereSize);
			call(TriggerBox,TmpVector,0,TmpFloat);
			if(TmpFloat!=0)
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
	elseif(VCurSet=="RLPLZA4A")
	{
		CurEnvTrigger("LoveDoor");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			//callsub(DoorOpen,0,1);
			if(VSetActive!="RLplshp3" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTrigger("LoveDoor");
			if(VSetActive=="RLplshp3")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLPLZA4A","LoveDoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="RLPLZA4B")
	{
		float(_clr,VarKey54,4);			//turn contamination back to normal
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("Dr_quar12");
			if(VTrigger==_DIREnvTrigger)
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="RLquar" && ControlTimer==0)
				{
				//	call(loadpreloaddb,15);
					float(_set,ControlTimer,8);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		if(ControlTimer==8)
		{
			CurEnvTrigger("Dr_quar12");
			if(VSetActive=="RLquar")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("RLPLZA4B","Dr_quar12",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(VAIClass==_AIclasscop && VRank>=_RankSergeantH)
		{
			//	You're ok, nobody will kill you
			//
		}
		else
		{
			CurEnvTrigger("Police01");
			if(VTrigger==_DIREnvTrigger)
			{
				call(AIchangemetoenemy);
			}
			CurEnvTrigger("Police02");
			if(VTrigger==_DIREnvTrigger)
			{
				call(AIchangemetoenemy);
			}
			CurEnvTrigger("Police03");
			if(VTrigger==_DIREnvTrigger)
			{
				call(AIchangemetoenemy);
			}
			CurEnvTrigger("Police04");
			if(VTrigger==_DIREnvTrigger)
			{
				call(AIchangemetoenemy);
			}
		}
	}
	elseif(VCurSet=="RLPLZA4C")
	{
		CurEnvTrigger("Lowcam");
		vector(_set,TmpVector,70,200,140);
		call(TriggerBox,TmpVector,0,TmpFloat);
		if(TmpFloat!=0)
		{
			Camera(120,60);
			//Target(-50,20);
		}
		else
		{
			callsub(Sub_SetCameraNormal);
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="rlhsrm1")
	{
		CurEnvTrigger("DR_HSRM1A");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			callsub(DoorOpen,0,1);
		}
	}

//////////////////
//// Club KYD ////
//////////////////
	elseif(VCurSet=="clubsas")
	{
		float(_add,timer,1);

		CurEnvTrigger("trap");
		if(VTrigger==_DIREnvTrigger && VarKey51==0)
		{
			call(KeyObjTrigger,9,1);
			vector(_set,Gactorpos,-8915,21411,13067);
			sample(SFXPneumatik,Gactorpos)
			if(VAICON==0)
			{
				message("Weapon Detector Activated - Put your Hand on the Console",200,10);
			}
			float(_set,VarKey51,1);
		}
		if(VKeyObjTriggered==0 && VarKey51==1)
		{
			float(_set,VarKey51,2);
		}

		if(timer>300 && VarKey51==3)
		{
			if(Vtrigger==_DIRhavegun)
			{
				message("Weapon Detected - Drop it on the Plate Behind You",200,10);
				CurEnvTrigger("detector");
				call(KeyObjTrigger,255,1);
				sample(SFXWepPlate,Gactorpos);
				CurEnvTrigger("console");
				call(KeyObjTrigger,255,1);
				float(_set,timer,0);
				float(_set,VarKey51,5);
			}
			else
			{
				message("No Weapon Detected - You May Proceed",200,10);
				CurEnvTrigger("trap");
				call(KeyObjTrigger,255,1);
				vector(_set,Gactorpos,-8915,21411,13067);
				sample(SFXPneumatik,Gactorpos)
				CurEnvTrigger("console");
				call(KeyObjTrigger,255,1);
				sample(SFXClawSpin,Gactorpos);
				sample(SFXOpenPipe,Gactorpos);
				float(_set,timer,0);
				float(_set,VarKey51,4);
			}
			samplestop(SFXScanningAmbient);
		}

		CurEnvTrigger("check");
		if(VTrigger==_DIREnvTrigger&&VOTrigger==_DIRActionHold&&VTrigger!=_DIRAction&&VarKey51==5)
		{
			setkeyframe("clubsas","console",0);
			float(_set,VarKey51,6);
		}

		if(VTrigger!=_DIREnvTrigger && VarKey51==6)
		{
			CurEnvTrigger("detector");
			call(KeyObjTrigger,0,-1);
			sample(SFXWepPlate,Gactorpos);
			message("Use The Console Again For Another Test",200,10);
			float(_set,VarKey51,2)
		}

		CurEnvTrigger("console");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VarKey51==2)
		{
			setkeyframe("clubsas","check",0);
			call(KeyObjTrigger,10,1);
			call(ActivateButton,"Scanning for Identification",-1,FALSE);
			call(ActivateButtonSample,SFXActivate1);
			sample(SFXClawSpin,Gactorpos);
			sample(SFXOpenPipe,Gactorpos);
			sample(SFXScanning,Gactorpos);
			vector(_set,Gactorpos,-8915,21411,13067);
			vector(_set,tmpvector,0,250,130);
			vector(_set,tmpvector1,0,0,1);
			SpawnLight(Rplanelight,-1,Gactorpos,tmpvector,tmpvector1,1000);
			sample(SFXScanningAmbient,Gactorpos);
			float(_set,timer,0);
			float(_set,VarKey51,3);
		}

		CurEnvTrigger("enter");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey51<4)
			{
				if(VAICON==0)
				{
					message("Customer Not Scanned - Access Denied For Safety Reasons",250,10);
					sample(SFXInvalidFunction,Gactorpos);
				}
				direction(_clr,_DIRaction);
			}
			else
			{
				if(VAICON==0)
				{
					dmessage("Welcome to the Club Kyd",60,150);
				}
				callsub(DoorOpen,1,1);
			}
		}

		CurEnvTrigger("outside");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAICON==0)
			{
				message("This is not an Exit - Please Proceed to the Exit on the last floor",250,10);
				sample(SFXInvalidFunction,Gactorpos);
			}
			direction(_clr,_DIRaction);
		}
	}

	if(VCurSet=="rlhsng2b" || VCurSet=="rlhsng3b" || VCurSet=="rlhsng4b")
	{
		if(VarKey58&!=32768)
		{
			if(VAIClass==_AIClassSubgirl)
			{
				if(VAITargetFound!=0 && VAIPlayer1IsTarget!=0 && VAITargetFound==_AIEnemy)
				{
					float(_or,VarKey58,32768);
				}
			}
		}
		else
		{
			if(VAICon==0)
			{
				call(AIChangeMeToEnemy);
			}
		}
	}
}


