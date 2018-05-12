// Cryo section
SubRoutine(GetNumberOfConsolesVisited,float(ReturnValue))
{
	float(_set,ReturnValue,0);
	if(CryoKey3&=1)
	{
		float(_add,ReturnValue,1);
	}
	if(CryoKey3&=2)
	{
		float(_add,ReturnValue,1);
	}
	if(CryoKey3&=4)
	{
		float(_add,ReturnValue,1);
	}
	if(CryoKey3&=8)
	{
		float(_add,ReturnValue,1);
	}
}

SubRoutine(ShowConsoleMessage,float(ConsoleNumber))
{
	if(ConsoleNumber==1)
	{
		float(_set,tmpfloat2,1);
	}
	elseif(ConsoleNumber==2)
	{
		float(_set,tmpfloat2,2);
	}
	elseif(ConsoleNumber==3)
	{
		float(_set,tmpfloat2,4);
	}
	else
	{
		float(_set,tmpfloat2,8);
	}
	

	if(CryoKey3&!=tmpfloat2)
	{
		ClearTutorialLines();
		callsub(GetNumberOfConsolesVisited,tmpfloat);
		if(tmpfloat==0)
		{
			AddTutorialLine("Through negligence on our own part... Satan's");
			AddTutorialLine("stream of blood during the experiments was run");
			AddTutorialLine("at too great a level... giving him enough strength");
			AddTutorialLine("to break the restraints that we had placed upon");
			AddTutorialLine("him... thus setting him free.");  
			DisplayTutorialScreen("[40:200:200]SCIENTISTS LOG: 0786-33",15,15);
		}
		elseif(tmpfloat==1)
		{
			AddTutorialLine("During his ensuing rampage... he not only");
			AddTutorialLine("ravaged the containment dome but also the inner");
			AddTutorialLine("cryo area itself.  Thinking he had completely");
			AddTutorialLine("wiped out the staff... Satan once again retreated");
			AddTutorialLine("to the crater to replenish his strength by");
			AddTutorialLine("consuming more blood.  A few of us survived only");
			AddTutorialLine("due to the fact that we hid like cowards while");
			AddTutorialLine("the rest of our brethren were slaughtered.");
			DisplayTutorialScreen("[40:200:200]SCIENTISTS LOG: 1239-4a",15,15);
		}
		elseif(tmpfloat==2)
		{
			AddTutorialLine("After the chaos... we established a link with the");
			AddTutorialLine("clergy back on earth to devise a plan to destroy");
			AddTutorialLine("Satan.  Though our experiments are not complete...");
			AddTutorialLine("we believe that we have found a way to destroy");
			AddTutorialLine("Satan via a special Spiritual Attack which can");
			AddTutorialLine("be performed within the dome.");
			DisplayTutorialScreen("[40:200:200]SCIENTISTS LOG: 1255-00",15,15);
			Message("Grinder Room door unlocked.",120,10);
			vector(_set,Gactorpos,-3510,-1961,7812);
			sample(SFXUnLockDoor,Gactorpos);
		}
		else
		{
			AddTutorialLine("Any creature who is possessed and then depossessed");
			AddTutorialLine("will emit a powerful projectile which has enough");
			AddTutorialLine("strength to hopefully weaken Satan enough to send");
			AddTutorialLine("him back to his own dimension.  We know our time");
			AddTutorialLine("is limited before Satan senses our presence and");
			AddTutorialLine("returns to finish the job; we hope and pray that");
			AddTutorialLine("we can enable the Spiritual Attack within the dome");
			AddTutorialLine("in time...");
			DisplayTutorialScreen("[40:200:200]SCIENTISTS LOG: 1707-a0",15,15);
		}

		float(_or,CryoKey3,tmpfloat2);
	}
}


SubRoutine(InitSceneSound12)
{
	if(incoming!=0)
	{
		if(ScriptMark==25)
		{
			callsub(Panel25);
		}
	}
	else
	{
		callsub(ScriptLevel12);
	}
	vector(_set,Gactorpos,-3481,-2157,9000);
	sample(SFXIndustrial1,Gactorpos);

	vector(_set,Gactorpos,-2122,-2074,7475);
	sample(SFXIndLiftLoop,Gactorpos);

	vector(_set,Gactorpos,-2850,-2000,7450);
//	sample(SFXIndustrial6,Gactorpos);

	vector(_set,Gactorpos,-2509,-2024,7474);
	Sample(SFXSewerHammer,Gactorpos);

	sample(SFXBobCryoMessage,-1);	//Non looping sound.

	call(cdplay,17,1);
	call(fadetoblack,2);
}


SubRoutine(DeInitSceneSound12)
{
	vector(_set,Gactorpos,-3481,-2157,9000);
	samplestop(SFXIndustrial1,Gactorpos);

	vector(_set,Gactorpos,-2122,-2074,7475);
	samplestop(SFXIndLiftLoop,Gactorpos);

	vector(_set,Gactorpos,-2850,-2000,7450)
//	samplestop(SFXIndustrial6,Gactorpos);

	vector(_set,Gactorpos,-2509,-2024,7474);
	SampleStop(SFXSewerHammer,Gactorpos);

}                                                                                                                                                                                                                                                                                                                                        


SubRoutine(InitScene12)
{
			InitActor(Bob1,0,Gactorangle,"elevent");

			float(_set,CryoKey1,0);		//Evil Door Activation
			float(_set,CryoKey2,0);		//Timer for telport sequence.		
			float(_set,CryoKey3,0);		//Controls access to grinder door
//			float(_set,CryoKey4,0);		//Controls order of messages for consoles
			float(_set,Timer,0);
			float(_set,VarBit,AllHelp);
			float(_set,WarnSeq,0);
			#define FlicSections 14
			#define FlicFrames 3

			#include "messiahscripts\enemies\cryo.spt"
			callsub(InitSceneSound12);
}

SubRoutine(MainScene12)
{

	float(_rnd2,tmpfloat,300);
	if(tmpfloat<6)
	{
		vector(_set,Gactorpos,-1934,-1915,8089);
		float(_rnd2,tmpfloat,3200);
		float(_sub,tmpfloat,1600);
		vector(_addx,Gactorpos,tmpfloat);
		float(_rnd2,tmpfloat,600);
		float(_sub,tmpfloat,300);
		vector(_addy,Gactorpos,tmpfloat);
		float(_rnd2,tmpfloat,3200);
		float(_sub,tmpfloat,1600);
		vector(_addz,Gactorpos,tmpfloat);


		if(tmpfloat<1)
		{
			sample(SFXDrip1,gactorpos);
		}
		elseif(tmpfloat<2)
		{
			sample(SFXDrip2,gactorpos);
		}
		elseif(tmpfloat<3)
		{
			sample(SFXDrip3,gactorpos);
		}
		elseif(tmpfloat<4)
		{
			sample(SFXDrip4,gactorpos);
		}
		elseif(tmpfloat<5)
		{
			sample(SFXDrip5,gactorpos);
		}
		else
		{
			sample(SFXDrip6,gactorpos);
		}
	}
	
	
	if(VCurSet=="Cryo02")
	{
		CurEnvTriggerSet("cryo02","Coffin");
		if(VKeyObjTriggered==0)
		{	
			if(VKeyObjFrame==0)
			{
				call(KeyObjTrigger,3,1);
				CurEnvTriggerSet("cryo02","claw");
				call(KeyObjTrigger,3,1);
				kfsample(-1,SFXLiftMove,-1,-1);
			}
			elseif(VKeyObjFrame==3)
			{
				call(KeyObjTrigger,26,1);
				CurEnvTriggerSet("cryo02","claw");
				call(KeyObjTrigger,26,1);
				kfsample(-1,SFXClawMove,-1,-1);
			}
			elseif(VKeyObjFrame==26)
			{
				call(KeyObjTrigger,255,1);
				CurEnvTriggerSet("cryo02","claw");
				call(KeyObjTrigger,255,1);
				kfsample(-1,SFXLiftMove,-1,-1);
			}
		}
		elseif(VKeyObjFrame==1)
		{
			call(SetTriggerObjFlag,-1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,-1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);

			CurEnvTriggerSet("cryo02","claw");
			call(SetTriggerObjFlag,-1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,-1,_clr,_SXObjInvisible);
		}
		elseif(VKeyObjFrame==57)
		{
			call(SetTriggerObjFlag,-1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,-1,_or,_SXObjInvisible);

			CurEnvTriggerSet("cryo02","claw");
			call(SetTriggerObjFlag,-1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,-1,_or,_SXObjInvisible);

		}
	}

	
	
	if(VSetActive=="Cryo02")
	{
		call(SetParticleSetID,"cryo02");

		//Code for conveyor belt movement.
		CurEnvTriggerSet("Cryo02","CONVTRG1");
		call(ExpSet1,-1200,0,1);

		//Code for flic control
		CurEnvTriggerSet("Cryo02","Flic");
		call(ExpGet,1,tmpfloat);
		float(_set,tmpfloat2,tmpfloat);
		float(_set,tmpfloat3,tmpfloat);
		float(_mod,tmpfloat,4);
		float(_sub,tmpfloat2,tmpfloat);
		float(_div,tmpfloat2,4);


		//Effects for conveyor belt
		CurEnvTriggerSet("cryo02","Coffin");
		if(VKeyObjFrame>=30 && VKeyObjFrame<=48)
		{
			if(vrnd<20)
			{
				vector(_set,Gactorpos,-2509,-2024,7311);
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
				
				vector(_set,Gactorpos,-2509,-2024,7637);
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
			}
			vector(_set,Gactorpos,-2509,-2024,7474);
			SamplePlaying(SFXRustDoorLoop,Gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				Sample(SFXRustDoorLoop,Gactorpos);
			}
		}
		else
		{
			vector(_set,Gactorpos,-2509,-2024,7474);
			SamplePlaying(SFXRustDoorLoop,Gactorpos);
			if(VTrigger==_DIRTempFlag)
			{
				SampleStop(SFXRustDoorLoop,Gactorpos);
			}
		}


		print("!!!!!!!!FLIC FRAME: ",tmpfloat3);

		if(tmpfloat==FlicFrames)
		{
			if(Timer>0)
			{
				float(_sub,timer,1);
			}
			else
			{
				if(tmpfloat2<FlicSections)
				{
					float(_add,tmpfloat3,1);
					float(_set,tmpfloat,tmpfloat3);
					float(_add,tmpfloat,4);
					call(ExpSet1,tmpfloat3,tmpfloat3,tmpfloat);
				}
				else
				{
					call(ExpSet1,0,0,4);
				}
				float(_set,Timer,15);
			}
		}


		
		//DAMAGE FX FOR CONSOLES
		if(vrnd<30)	//Randomly spit smoke from the corner
		{
			vector(_set,Gactorine,0,12,0);
			vector(_set,gactorpos,-2279,-1864,6420);
			spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
		}

		vector(_set,gactorpos,-2279,-1904,6420);
		if(vrnd<10)	//Randomly spit sparks and flash lights from the same spot
		{
			//Spawn dim white light
			vector(_set,tmpVector,50,50,50);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);	//spawnlight(name,bone,position,color,radius)


			//Spawn randomly aimed sparks
			spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);

			//Play that funky music white boy
			sample(SFXSparks,Gactorpos);
		}

		if(vrnd<80)
		{
			spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
		}

		if(vrnd<30)
		{
			vector(_set,Gactorpos,-2278,-1997,6745);
			float(_rnd2,tmpfloat,20);
			float(_sub,tmpfloat,10);
			vector(_addz,Gactorpos,tmpfloat);
			float(_rnd2,tmpfloat,10);
			float(_sub,tmpfloat,5);
			vector(_addy,Gactorpos,tmpfloat);
			spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
		}



		float(_rnd2,tmpfloat,100);
		if(tmpfloat<25)
		{
			vector(_set,gactorpos,-1452,-2244,9122);		
	//		vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,emptyvector,-1);

	/*		vector(_set,gactorpos,-4074.60,-2111.49,8102.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurtREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8202.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_bloodREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8302.31);
			vector(_set,gactorine,,100,0);
			spawnparticle(fx_bloodsprayREL,-1,gactorpos,gactorine,-1);
		
			vector(_set,gactorpos,-4074.60,-2111.49,8402.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurt,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8502.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_blood,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8602.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,gactorine,-1);*/
		}


		float(_rnd2,tmpfloat,100);
		if(tmpfloat<25)
		{
			vector(_set,gactorpos,-1485,-2244,8953);		
	//		vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,emptyvector,-1);

	/*		vector(_set,gactorpos,-4074.60,-2111.49,8102.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurtREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8202.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_bloodREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8302.31);
			vector(_set,gactorine,,100,0);
			spawnparticle(fx_bloodsprayREL,-1,gactorpos,gactorine,-1);
		
			vector(_set,gactorpos,-4074.60,-2111.49,8402.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurt,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8502.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_blood,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8602.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,gactorine,-1);*/
		}

		float(_rnd2,tmpfloat,100);
		if(tmpfloat<10)
		{
			vector(_set,gactorpos,-2268,-1995,6727);		
	//		vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,emptyvector,-1);

	/*		vector(_set,gactorpos,-4074.60,-2111.49,8102.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurtREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8202.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_bloodREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8302.31);
			vector(_set,gactorine,,100,0);
			spawnparticle(fx_bloodsprayREL,-1,gactorpos,gactorine,-1);
		
			vector(_set,gactorpos,-4074.60,-2111.49,8402.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurt,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8502.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_blood,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8602.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,gactorine,-1);*/
		}


		CurEnvTriggerSet("Cryo02","Bludfill");
		call(Expset1,5,2);
	}
	
	if(VSetActive=="Cryo03")
	{
		call(SetParticleSetID,"cryo03");

		callsub(GetNumberOfConsolesVisited,tmpfloat);
		if(tmpfloat>=3)
		{
			float(_set,tmpfloat,0x00FF00);
			CurEnvTriggerSet("cryo03","Door01");
			call(ExpSet1,1,tmpfloat);
		}			
		else
		{
			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("cryo03","Door01");
			call(ExpSet1,1,tmpfloat);
		}

		if(vrnd<50)
		{
			//Vector(_set,Gactorpos,-4398,-2070,8550);
			Vector(_set,Gactorpos,-4361,-2087,8550);
			//Vector(_set,Gactorpos,-4361,-2060,8550);
			float(_rnd2,tmpfloat,1);
			float(_set,tmpfloat2,37);
			float(_set,tmpfloat3,17);
			float(_mul,tmpfloat2,tmpfloat);
			float(_mul,tmpfloat3,tmpfloat);
			Vector(_subx,Gactorpos,tmpfloat2);
			Vector(_addy,Gactorpos,tmpfloat3);

			float(_rnd2,tmpfloat,10);
			if(tmpfloat<=9.2)
			{
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
			}
			else
			{
				vector(_set,tmpVector,50,50,50);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);	//spawnlight(name,bone,position,color,radius)
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
				vector(_addy,gactorpos,20);
				vector(_set,Gactorine,0,4,0);
				float(_rnd2,tmpfloat,4)
				if(tmpfloat<3)
				{
					spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
				}
				else
				{
					spawnparticle(fx_icesmoke,-1,gactorpos,gactorine,fx_doorsteam);
				}
			}
		}
		
		vector(_set,Gactorine,0,12,0);
		if(vrnd<13)
		{
			vector(_set,gactorpos,-4442,-1857,8683);
			spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
		}
		if(vrnd>7 && vrnd<20)
		{
			vector(_set,gactorpos,-4442,-1882,8717);
			spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
		}

		if(vrnd<25)
		{
			vector(_set,gactorpos,-4092.36,-2100,8109.47);		
	//		vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,emptyvector,-1);

	/*		vector(_set,gactorpos,-4074.60,-2111.49,8102.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurtREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8202.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_bloodREL,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8302.31);
			vector(_set,gactorine,,100,0);
			spawnparticle(fx_bloodsprayREL,-1,gactorpos,gactorine,-1);
		
			vector(_set,gactorpos,-4074.60,-2111.49,8402.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspurt,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8502.31);
			vector(_set,gactorine,-2,-2,0);
			spawnparticle(fx_blood,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-4074.60,-2111.49,8602.31);
			vector(_set,gactorine,0,10,0);
			spawnparticle(fx_bloodspray,-1,gactorpos,gactorine,-1);*/
		}

	}


	if(VSetActive=="cryo04")
	{

		callsub(GetNumberOfConsolesVisited,tmpfloat);
		if(tmpfloat>=3)
		{
				float(_set,tmpfloat,0x00FF00);
				CurEnvTriggerSet("cryo04","Door02");
				call(ExpSet1,1,tmpfloat);
		}			
		else
		{
			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("cryo04","Door02");
			call(ExpSet1,1,tmpfloat);
		}

		vector(_set,gactorpos,-3113,-1894,7461);
		CurEnvTriggerSet("cryo04","Flic");
		call(ExpGet,1,tmpfloat);
		if(tmpfloat==1)
		{
			sample(SFXBlenderStart,gactorpos);
		}
		elseif(tmpfloat==285)
		{
			SamplePlaying(SFXBlenderLoop1,gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXBlenderLoop1,gactorpos);
			}
			SamplePlaying(SFXBlenderLoop2,gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				sample(SFXBlenderLoop2,gactorpos);
			}
		}
		elseif(tmpfloat==834)
		{
			SamplePlaying(SFXBlenderLoop1,gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				samplestop(SFXBlenderLoop1,gactorpos);
			}
			SamplePlaying(SFXBlenderLoop2,gactorpos);
			if(VTrigger!=_DIRTempFlag)
			{
				samplestop(SFXBlenderLoop2,gactorpos);
			}
			sample(SFXBlenderEnd,gactorpos);
		}


		call(SetParticleSetID,"cryo04");
		if(vrnd<10)
		{
			vector(_set,gactorpos,-3928,-2094,7543);
			float(_rnd2,tmpfloat,10);
			if(tmpfloat<=9)
			{
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
			}
			elseif(tmpfloat<10)
			{
				vector(_set,tmpVector,50,50,50);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);	//spawnlight(name,bone,position,color,radius)
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
				vector(_addy,gactorpos,20);
				vector(_set,Gactorine,0,4,0);
				float(_rnd2,tmpfloat,4)
				if(tmpfloat<3)
				{
					spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
				}
				else
				{
					spawnparticle(fx_icesmoke,-1,gactorpos,gactorine,fx_doorsteam);
				}
			}
		}
		elseif(vrnd<20)
		{
			vector(_set,gactorpos,-3928,-2094,7591);
			float(_rnd2,tmpfloat,10);
			if(tmpfloat<=9)
			{
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
			}
			elseif(tmpfloat<10)
			{
				vector(_set,tmpVector,50,50,50);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);	//spawnlight(name,bone,position,color,radius)
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
				vector(_addy,gactorpos,20);
				vector(_set,Gactorine,0,4,0);
				float(_rnd2,tmpfloat,4)
				if(tmpfloat<3)
				{
					spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
				}
				else
				{
					spawnparticle(fx_icesmoke,-1,gactorpos,gactorine,fx_doorsteam);
				}
			}
		}
		elseif(vrnd<30)
		{
			vector(_set,gactorpos,-3928,-2094,7603);
			float(_rnd2,tmpfloat,10);
			if(tmpfloat<=9)
			{
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
			}
			elseif(tmpfloat<10)
			{
				vector(_set,tmpVector,50,50,50);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);	//spawnlight(name,bone,position,color,radius)
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
				vector(_addy,gactorpos,20);
				vector(_set,Gactorine,0,4,0);
				float(_rnd2,tmpfloat,4)
				if(tmpfloat<3)
				{
					spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
				}
				else
				{
					spawnparticle(fx_icesmoke,-1,gactorpos,gactorine,fx_doorsteam);
				}
			}
		}
	}
	if(VCurSet=="cryo05")
	{
		if(WarnSeq>=1)
		{
			call(SetParticleSetID,"cryo05");
			if(vrnd<50)
			{
				vector(_set,Gactorpos,-1265,-1934,11906);
				vector(_set,Gactorine,-1265,-1934,11906);
				float(_rnd,TmpFloat,1500);
				vector(_addx,Gactorine,tmpfloat);
				float(_rnd,TmpFloat1,1500);
				vector(_addz,Gactorine,TmpFloat1);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_blue,0);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_green,0);
				vector(_set,Gactorine,-1265,-1934,11906);
				float(_rnd,TmpFloat,1500);
				vector(_addx,Gactorine,tmpfloat);
				float(_rnd,TmpFloat1,1500);
				vector(_addz,Gactorine,TmpFloat1);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_blue,0);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_green,0);
				vector(_set,Gactorine,-1265,-1934,11906);
				float(_rnd,TmpFloat,-1500);
				vector(_addx,Gactorine,tmpfloat);
				float(_rnd,TmpFloat1,-1500);
				vector(_addz,Gactorine,TmpFloat1);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_blue,0);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_green,0);
				vector(_set,Gactorine,-1265,-1934,11906);
				float(_rnd,TmpFloat,1500);
				vector(_addx,Gactorine,tmpfloat);
				float(_rnd,TmpFloat1,1500);
				vector(_addz,Gactorine,TmpFloat1);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_blue,0);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_green,0);
				vector(_set,Gactorine,-1265,-1934,11906);
				float(_rnd,TmpFloat,-1500);
				vector(_addx,Gactorine,tmpfloat);
				float(_rnd,TmpFloat1,-1500);
				vector(_addz,Gactorine,TmpFloat1);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_blue,0);
				callsub(LaserStrip,Gactorpos,Gactorine,fx_green,0);
			}

			
			float(_rnd2,tmpfloat,100);
			if(tmpfloat<3)
			{
				sample(SFXZap,-1);
			}
			elseif(tmpfloat<13)
			{
				vector(_set,gactorpos,-1265,-1934,11906);
				sample(SFXTeslaCoil,Gactorpos);
			}
		}
	}
}

SubRoutine(BackgroundTriggerChecksScene12)
{
	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel12); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(VCurSet=="cryo02")
	{
		if(CryoKey1==2)
		{
			CurEnvTrigger("BludFill");
			if(VKeyObjTriggered==0)
			{
				float(_set,CryoKey1,3);

				vector(_set,Gactorpos,-1733,-1942,9271);
				samplestop(SFXRadiationPool,Gactorpos);

				vector(_set,Gactorpos,-756, -1942, 9269);
				samplestop(SFXRadiationPool,Gactorpos);
			}
			else
			{
				if(vrnd<10)
				{
					sample(SFXCreepy02,-1);
				}
			}
		}

		CurEnvTrigger("EVLDOOR");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(CryoKey1==3) 
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
				}
			}
			else
			{
				message("The streets will flow with the blood of the non-believers",180,10);
				sample(SFXLockedSound,-1);
				if(vrnd<33)
				{
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("evldoor");
			if(VSetActive=="Cryo05")
			{
				call(KeyObjTrigger,255,1);
				
				vector(_set,Gactorpos,-1233,-1942,9271);
				sample(SFXDoorVault,gactorpos);

				float(_set,CryoKey1,4);
				sample(SFXCreepy02,-1);

				call(cdplay,14,0);

				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("cryo02","evldoor",0);
				call(KeyObjTrigger,255,1);
			}
		}

	
		CurEnvTrigger("DeathFall");
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

		CurEnvTrigger("Konsole");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			callsub(ShowConsoleMessage,2);
			float(_set,Tmpfloat,0xffffff);
			call(expset1,1,TmpFloat,0);
		}

		CurEnvTrigger("Konsole01");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			callsub(ShowConsoleMessage,3);
			float(_set,Tmpfloat,0xffffff);
			call(expset1,1,TmpFloat,0);

		}
	}
	elseif(VCurSet=="cryo03")
	{
		if(VAction==TeleportAction && VAICon==0)
		{
			SpawnAction(GENIdle);
		}
		
		if(VarBit&=Help01)
		{
			if(VAICon==0)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,25);
				callsub(Panel25);
				ClearDMessage();
				float(_clr,VarBit,Help01);
			}
		}				
		CurEnvTrigger("Door01");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(GetNumberOfConsolesVisited,tmpfloat);
			if(tmpfloat>=3)
			{
				if(VTrigger==_DIRAction)
				{
					callsub(DoorOpen,1,1);
				}
			}
			else
			{
				if(VTrigger==_DIRAction)
				{
					message("Locked.",120,10);
					sample(SFXLockedSound,-1);
					if(vrnd<33)
					{
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}
				}
			}
		}

		CurEnvTrigger("Konsole");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			callsub(ShowConsoleMessage,1);
			float(_set,Tmpfloat,0xffffff);
			call(expset1,1,TmpFloat,0);

		}
	}
	elseif(VCurSet=="cryo04")
	{
		CurEnvTrigger("BludCon");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
//			if(VAIClass==_AIClassScientist)
//			{
				if(CryoKey1==0)
				{
					float(_set,Tmpfloat,0xffffff);
					call(expset1,1,TmpFloat,0);
					callsub(ShowConsoleMessage,4);
			
					float(_set,CryoKey1,1);
					message("Diverting blood flow for door access.",120,10);
	
					sample(SFXValidFunction,-1);

					vector(_set,Gactorpos,-1733,-1942,9271);
					sample(SFXRadiationPool,Gactorpos);

					vector(_set,Gactorpos,-756, -1942, 9269);
					sample(SFXRadiationPool,Gactorpos);
				}
				else
				{
					message("Door access already granted.",120,10);
				}
/*			}
			else
			{
				message("Access Denied",120,10);
				sample(SFXInvalidFunction,-1);
			}*/
		}

		CurEnvTrigger("Door02");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(GetNumberOfConsolesVisited,tmpfloat);
			if(tmpfloat>=3)
			{
				if(VTrigger==_DIRAction)
				{
					callsub(DoorOpen,1,1);
					if(CryoKey1==1)
					{
						float(_set,CryoKey1,2);
						CurEnvTriggerSet("Cryo02","BludFill");
						Call(KeyObjTrigger,255,1);
					}
				}
			}
			else
			{
				if(VTrigger==_DIRAction)
				{
					message("Hazardous area.  Authorized personel only.",120,10);
					vector(_set,Gactorpos,-3508.98,-2003.34,7810.31);
					sample(SFXLockedSound,Gactorpos);
				}
			}
		}
		else
		{
		}
	}
	elseif(VCurSet=="Cryo05")
	{
		if(VAICon==0)
		{
		/*
			CurEnvTrigger("Teleport");
			if(VTrigger==_DIREnvTrigger)
			{
				actorflag(_or,_AFLAGresetfallalt);
				call(LoadLevel,-1,11);
			}
			*/		
			if(VarBit&=Help02)
			{
				CurEnvTrigger("Teleport");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_clr,VarBit,Help02);
				}
			}
			else
			{
				if(WarnSeq==0)
				{
					CutScene("tele");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
					call(PlayerInput,0);
					direction(_clr,_DIRmove);
					setactortotrigger("cryo05","pos");
					call(DisplayFXPagesToggle,1);
					float(_set,WarnSeq,2);
					sample(SFXTeleportLoop,-1);
				}
				if(WarnSeq>=1)
				{
					setactortotrigger("cryo05","pos");
					//sprite3d...
					vector(_set,gactorpos,0,0,0);
					vector(_set,gactorine,0,0,0);
					spawn3dflare(16,60,255,1,gactorpos,gactorine);
					if(VAIClass==_AIClassAngel)
					{
						if(VAction!=BobTeleportAction)
						{
							spawnaction(BobTeleportAction);
						}
					}
					else
					{
						if(VAction!=TeleportAction)
						{
							spawnaction(TeleportAction);
						}
					}
				}
				if(WarnSeq==2)
				{
					vector(_set,tmpvector,0,50,250);
					vector(_set,Gactorpos,-1265,-1934,11906);
					spawnlight(LightPulseOmni2,-1,Gactorpos,tmpvector,EmptyVector,600);
					float(_set,timer,0);
					float(_set,WarnSeq,3);
				}
				elseif(WarnSeq==3)
				{
					float(_add,timer,1);
					turn(0,timer,0);
					if(timer==180)
					{
						call(fadetoblack,0);
					}
					if(timer==340)
					{
						call(fadetoblack,2);
						call(wCheckViewCollision,-1,-1,-1,0);
						setactortotrigger("cryo05","evldoor");
					}
					if(timer==350)
					{
						float(_set,timer,0);
						samplestop(SFXTeleportLoop,-1);
						call(PlayerInput,1);
						actorflag(_or,_AFLAGresetfallalt);
						call(LoadLevel,-1,11);
					}
				}
			}
		}
		CurEnvTrigger("EVLDOOR");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			callsub(DoorOpen,1,1);
		}
	}
}

