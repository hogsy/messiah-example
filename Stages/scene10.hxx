//WastePlant Script file

SubRoutine(InitSceneSound10)
{
	callsub(ScriptLevel10);


	//computer terminals
	vector(_set,Gactorpos,-15741,25263,14035);
	sample(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-16936, 25532, 14487);
	sample(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-17256, 25532, 14188);
	sample(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-17259, 25531, 13853);
	sample(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-16936, 25532, 13563);
	sample(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-15659, 25357, 13494);
	sample(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-16285, 25357, 13483);
	sample(SFXBinary,Gactorpos);


	vector(_set,Gactorpos,-15968,25224,13560);
	sample(SFXNeonLight2,Gactorpos); 
	vector(_set,Gactorpos,-16197.50,20671.42,13970.54);
	sample(SFXSewerHammer,Gactorpos); 
	vector(_set,Gactorpos,-16222.22,20671.42,16070.79);
	sample(SFXSewerHammer,Gactorpos); 
	vector(_set,Gactorpos,-15888.52,20671.42,18186.95);	
	sample(SFXSewerHammer,Gactorpos); 
	vector(_set,Gactorpos,-14331.26,20671.42,16051.14);
	sample(SFXSewerHammer,Gactorpos); 
	vector(_set,Gactorpos,-15278.38,20671.42,19564.29);
	sample(SFXSewerHammer,Gactorpos); 
	vector(_set,Gactorpos,-14549.79,20636.50,14251.39);
	sample(SFXSewerHammer,Gactorpos); 
	vector(_set,Gactorpos,-14479.91,22828.21,14238.59);
	sample(SFXSewerHammer,Gactorpos); 


	//sounds in wast5
	vector(_set,Gactorpos,-13635.72,23516.97,13199.67);
	sample(SFXShaftRotate2,Gactorpos);
	vector(_set,Gactorpos,-13635.72,21684.56,13199.67);
	sample(SFXShaftRotate2,Gactorpos);

	call(CDPlay,10,1);

}

SubRoutine(DeInitSceneSound10)
{
	//computer terminals
	vector(_set,Gactorpos,-15741,25263,14035);
	samplestop(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-16936, 25532, 14487);
	samplestop(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-17256, 25532, 14188);
	samplestop(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-17259, 25531, 13853);
	samplestop(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-16936, 25532, 13563);
	samplestop(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-15659, 25357, 13494);
	samplestop(SFXBinary,Gactorpos);
	vector(_set,Gactorpos,-16285, 25357, 13483);
	samplestop(SFXBinary,Gactorpos);

	vector(_set,Gactorpos,-15968,25224,13560);
	samplestop(SFXNeonLight2,Gactorpos); 

	vector(_set,Gactorpos,-16197.50,20671.42,13970.54);
	samplestop(SFXShaftSpecial,Gactorpos); 
	vector(_set,Gactorpos,-16222.22,20671.42,16070.79);
	samplestop(SFXShaftSpecial,Gactorpos); 
	vector(_set,Gactorpos,-15888.52,20671.42,18186.95);	
	samplestop(SFXShaftSpecial,Gactorpos); 
	vector(_set,Gactorpos,-14331.26,20671.42,16051.14);
	samplestop(SFXShaftSpecial,Gactorpos); 
	vector(_set,Gactorpos,-15278.38,20671.42,19564.29);
	samplestop(SFXShaftSpecial,Gactorpos); 
	vector(_set,Gactorpos,-14549.79,20636.50,14251.39);
	samplestop(SFXShaftSpecial,Gactorpos); 
	vector(_set,Gactorpos,-14479.91,22828.21,14238.59);
	samplestop(SFXShaftSpecial,Gactorpos); 

	//sounds in wast5
	vector(_set,Gactorpos,-13635.72,23516.97,13199.67);
	samplestop(SFXShaftRotate2,Gactorpos);
	vector(_set,Gactorpos,-13635.72,21684.56,13199.67);
	samplestop(SFXShaftRotate2,Gactorpos);
}

SubRoutine(InitScene10)
{
		if(VScriptInitiated!=10)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,1024,0);
				InitActor(Bob1,0,Gactorangle,"wast1");
			}
			
			// Reset all the variables
			call(loadpreloaddb,14);
			float(_set,VarKey111,0);     //timer. keeps steam sfx from playing every frame.
			float(_set,VarKey112,0);     //turn lights on in wast17
			float(_set,VarKey113,0);
			float(_set,VarKey114,0);
			float(_set,VarKey115,0);
			float(_set,VarKey116,0);
			float(_set,VarKey117,0);     //spawns cops
			float(_set,VarKey118,0);     //damaged console
			float(_set,VarKey119,1);     //end sequence in wast17
			float(_set,VarKey120,0); 
			float(_set,timer,0);         //end sequence and lifts in wast4
			float(_set,timer2,0);	   
			float(_set,timer3,0);        //damaged console and door in wast1
			float(_set,BarrelTimer,0);   //end sequence
			float(_set,objective,0);     //plays objective for scene
			float(_set,VarBit,AllHelp);
			float(_set,TimeForSound,0);
			float(_set,CabTimer,0);
			//float(_set,WorkerPushingObject,0);	//Whether worker is pushing an object
			
			float(_set,PlatformLevel1,1);
			float(_set,PlatformLevel2,1);

			#include "messiahscripts\enemies\c2_waste.spt"
		}

		callsub(InitSceneSound10);
		call(ScriptCodeInitiated,10);
}

SubRoutine(MainScene10)
{
	if(timer2>0)
	{
		float(_sub,timer2,1);
	}
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST1                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VSetActive=="wast1")
	{
		call(SetParticleSetID,"wast1");
		CurEnvTriggerSet("wast1","door14");
		float(_set,tmpfloat,0xFF0000);     //set lights to green
		call(expSet1,1,tmpfloat,0);
		call(expSet2,1,tmpfloat,0);

		CurEnvTriggerSet("wast1","door13");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		if(VarKey118>0)
		{
			//CODE FOR DAMAGED CONSOLE
			//----------------------------------------------------------------
			if(vrnd<40)	//Randomly spit smoke from the corner
			{
				vector(_set,Gactorpos,-16136.70,25392.41,13480.68);
				vector(_set,Gactorine,0,15,0);
				spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
			}
			if(vrnd<10)	//Randomly spit sparks and flash lights from the same spot
			{
				//Spawn dim white light
				vector(_set,Gactorpos,-16136.70,25392.41,13480.68);
				vector(_set,tmpVector,50,50,50);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);	//spawnlight(name,bone,position,color,radius)


				//Spawn randomly aimed sparks
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);

				//Play that funky music white boy
				sample(SFXSparks,Gactorpos);
			}
			//----------------------------------------------------------------
		}

		//CODE FOR DAMAGED DOOR
		//----------------------------------------------------------------		
		if(Varkey118==1)
		{
			if(vrnd<40)
			{
				//sparks from above door			
				vector(_set,Gactorpos,-16082.67,25546.98,13611.11);
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);

				vector(_set,Gactorpos,-16110.85,25547.98,13610.24);
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,Emptyvector,300);

				vector(_set,Gactorpos,-16059.03,25547.98,13611.26);
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);

				//sparks from below door
				vector(_set,Gactorpos,-16082.67,25172.87,13611.11);
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);

				vector(_set,Gactorpos,-16110.85,25172.87,13610.24);
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,Emptyvector,300);	

				vector(_set,Gactorpos,-16059.03,25172.87,13611.26);
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);

				vector(_set,Gactorpos,-16130.03,25172.87,13611.26);
				spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
			}
		}

	}


	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯


	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST2                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ 
	if(VSetActive=="wast2")
	{
		CurEnvTriggerSet("wast2","door23");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST3                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ 
	if(VSetActive=="wast3")
	{
		CurEnvTriggerSet("wast3","door13");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("wast3","door23");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("wast3","door314");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);

	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST5                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VSetActive=="wast5")
	{
		vector(_set,Gactorpos,-13027.10,22463.12,12901.67);
		call(SetParticleSetID,"wast5");
		spawnparticle(fx_laserstrip,-1,gactorpos,emptyvector,-1);	//spawnparticle(particlename,bone,position,angle,color)


		/*CurEnvTriggerSet("wast5","turbine");
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,255,1);
			call(kfSample,-1,SFXIndustrial8,-1,-1,1);
		}*/
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯


	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST6  &&  WAST7                                           |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VSetActive=="wast6" || VSetActive=="wast7")
	{
		CurEnvTriggerSet("wast7","brltrig3");
		if(VKeyObjFrame>176 && VKeyObjFrame<180)
		{
			call(SetParticleSetID,"wast7");
			vector(_set,gactorpos,-15156,21926,12225.08);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);
			spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21926,12063.37);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);
			spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21862,12225.08);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);
			spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21862,12063.37);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);
			spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21799,12225.08);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);
			spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21799,12063.37);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);
			spawnparticle(fx_fagsmoke,-1,gactorpos,gactorine,-1);

			//--------------------------------------------------

			vector(_set,gactorpos,-15156,21926,12225.08);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21926,12063.37);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21862,12225.08);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21862,12063.37);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21799,12225.08);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);

			vector(_set,gactorpos,-15156,21799,12063.37);
			spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);

			sample(SFXSparks,Gactorpos);
		}
		call(SetParticleSetID,"wast7");
		vector(_set,gactorpos,-15156,22053,11840);
		vector(_set,gactorine,-15156,22053,12446);
		callsub(LaserStrip,gactorpos,gactorine,FX_LASERFLICKERREDx,0);

		vector(_set,gactorpos,-15156,21989.5,11840);
		vector(_set,gactorine,-15156,21989.5,12446);
		callsub(LaserStrip,gactorpos,gactorine,FX_LASERFLICKERREDx,0);

		vector(_set,gactorpos,-15156,21926,11840);
		vector(_set,gactorine,-15156,21926,12446);
		callsub(LaserStrip,gactorpos,gactorine,FX_LASERFLICKERREDx,0);

		vector(_set,gactorpos,-15156,21862.5,11840);
		vector(_set,gactorine,-15156,21862.5,12446);
		callsub(LaserStrip,gactorpos,gactorine,FX_LASERFLICKERREDx,0);

		vector(_set,gactorpos,-15156,21799,11840);
		vector(_set,gactorine,-15156,21799,12446);
		callsub(LaserStrip,gactorpos,gactorine,FX_LASERFLICKERREDx,0);

		vector(_set,gactorpos,-15156,21735.5,11840);
		vector(_set,gactorine,-15156,21735.5,12446);
		callsub(LaserStrip,gactorpos,gactorine,FX_LASERFLICKERREDx,0);

		vector(_set,gactorpos,-15156,21672,11840);
		vector(_set,gactorine,-15156,21672,12446);
		callsub(LaserStrip,gactorpos,gactorine,FX_LASERFLICKERREDx,0);

		if(VSetInMemory!="wast7" && controltimer==0)
		{
			call(ForceLoadSet,"wast7");
			float(_set,controltimer,1);
		}
		if(VSetInMemory=="wast7" && controltimer==1)
		{
			float(_set,controltimer,0);
		}

		if(VSetInMemory!="wast6" && controltimer==0)
		{
			call(ForceLoadSet,"wast6");
			float(_set,controltimer,2);
		}
		if(VSetInMemory=="wast6" && controltimer==2)
		{
			float(_set,controltimer,0);
		}

		//barrel in wast6
		CurEnvTriggerSet("wast6","brltrig2");
		if(VKeyObjFrame==1 && varkey113==0)
		{
			call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,0,_or,_SXObjInvisible);	

			CurEnvTriggerSet("wast7","brltrig3");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff); //barrel in wast7
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);

			CurEnvTriggerSet("wast7","DOORTRIG");
			call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff); 
			call(SetTriggerObjFlag,0,_or,_SXObjInvisible);

			float(_set,varkey113,1);
		}
		elseif(VKeyObjFrame==9 && varkey113==1)
		{		
			call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);

			CurEnvTriggerSet("wast7","brltrig3");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);  //barrel in wast7
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);

			CurEnvTriggerSet("wast7","DOORTRIG");
			call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff); 
			call(SetTriggerObjFlag,0,_or,_SXObjInvisible);

			float(_set,varkey113,2);
		}
		elseif(VKeyObjFrame==139 && varkey113==2)
		{

			CurEnvTriggerSet("wast7","brltrig3");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);  //barrel in wast7
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);

			CurEnvTriggerSet("wast7","DOORTRIG");
			call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff); 
			call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);

			float(_set,varkey113,3);
		}
		elseif(VKeyObjFrame==140 && varkey113==3)
		{
			call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,0,_or,_SXObjInvisible);

			float(_set,varkey113,4);
		}
		elseif(VKeyObjFrame==188 && varkey113==4)
		{
			call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,0,_or,_SXObjInvisible);

			CurEnvTriggerSet("wast7","brltrig3");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);  //barrel in wast 7
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);

			float(_set,varkey113,0);
		}

		call(SetParticleSetID);
		CurEnvTriggerSet("WAST6","BRLTRIG2");
		if(VKeyObjTriggered==0 && VSetActive=="wast7")
		{

			call(KeyObjTrigger,255,1);
			kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);

			CurEnvTriggerSet("WAST6","CLAMPTRIG");
			call(KeyObjTrigger,255,1);

			CurEnvTriggerSet("WAST7","PIPES");
			call(KeyObjTrigger,255,1);

			CurEnvTriggerSet("WAST7","BRLTRIG3");
			call(keyObjTrigger,255,1);

			CurEnvTriggerSet("WAST7","DOORTRIG");
			call(KeyObJTrigger,255,1);
		}

		CurEnvTriggerSet("wast6","BRLTRIG2");
		if(VKeyObjFrame==26 && VarKey111==0);
		{
			vector(_set,Gactorpos,-12435.38,22294.64,13856.58);
			sample(SFXBigHit,Gactorpos);
			float(_set,varkey111,1);
		}

		if(VKeyObjFrame==114 && varkey111==0);
		{
			vector(_set,Gactorpos,-12418.55,21660.16,12148.64);
			sample(SFXBigHit,Gactorpos);
			float(_set,varkey111,1);
		}

		if(varkey111>0 && varkey111<6)
		{
			float(_add,varkey111,1);

			if(varkey111==6)
			{
				float(_set,varkey111,0);
			}
		}

		if(vrnd<40)	//Randomly spit smoke from the corner
		{
			vector(_set,Gactorpos,-12451.10,22260.23,14094.59);
			vector(_set,Gactorine,0,15,0);
			spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);	//spawnparticle(particlename,bone,position,angle,color)
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST12                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VSetActive=="wast12")
	{
		CurEnvTriggerSet("wast12","door1213");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		call(SetParticleSetID,"wast12");		
		float(_rnd2,tmpfloat,256);
		if(tmpfloat<60)
		{

			if(tmpfloat<20)
			{
				vector(_set,Gactorpos,-15732.52,24232.13,14798.87);
			}
			elseif(tmpfloat>=20 && tmpfloat<40)
			{
				vector(_set,Gactorpos,-15732.52,24232.13,14500);
				float(_sub,tmpfloat,20);
			}
			elseif(tmpfloat>=40 && tmpfloat<60)
			{
				vector(_set,Gactorpos,-15732.52,24232.13,14200);
				float(_sub,tmpfloat,40);
			}

			if(tmpfloat<10)
			{
				if(tmpfloat<3)
				{
					vector(_addy,Gactorpos,24);
				}
				elseif(tmpfloat<6 && tmpfloat>=3)
				{
					vector(_addy,Gactorpos,48);
				}
			}
			else
			{
				vector(_addz,Gactorpos,59);
				vector(_addy,Gactorpos,2);

				if(tmpfloat<12)
				{
					vector(_addz,Gactorpos,35);
				}
				elseif(tmpfloat<15 && tmpfloat>=12)
				{
					vector(_addz,Gactorpos,71);
				}
			}

			vector(_set,Gactorine,20,0,0);
			float(_rnd2,tmpfloat, 25);
			float(_add,tmpfloat,5);
			vector(_setx,Gactorine,tmpfloat);
			vector(_set,tmpvector,128,128,128);

			spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);	//spawnparticle(particlename,bone,position,angle,color)
			
			if(varkey111==4)  // plays the sfx once every 4 particles spwaned.
			{
				sample(SFXGunTurretSteam,gactorpos,30);  //sample(sample name,position)
				float(_set,varkey111,0);
			}
			float(_add,varkey111,1);
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯


	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST13                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VSetActive=="wast13")
	{
		CurEnvTriggerSet("wast13","door1213");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("wast13","door1315");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("wast13","lift");
		float(_set,TmpFloat,0x777711);  // brown-green
		float(_set,TmpFloat2,0xffff000); // yellow
		float(_set,TmpFloat1,0xff7722);   // orange
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator

		if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Waste Processing Area",120,10);
			float(_set,LiftMsg,0);
		}
		if(VKeyObjFrame==1 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			message("Loading Docks",120,10);
			float(_set,LiftMsg,0);
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST15                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VSetActive=="wast15")
	{
		CurEnvTriggerSet("WAST15","DOOR1417");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);
		call(expSet2,1,tmpfloat,0);


		CurEnvTriggerSet("wast15","moveme1");
		call(ExpSet1,0,0,8);
		call(ExpSet2,0,0,8);

		CurEnvTriggerSet("wast15","moveme2");
		call(ExpSet1,0,0,8);
		call(ExpSet2,0,0,8);

		if(VSetActive=="wast17")
		{
			CurEnvTriggerSet("WAST15","BRLTRIG");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);

				CurEnvTriggerSet("WAST17","BRLTRIG");
				call(KeyObjTrigger,255,1);
				kfsample(SFXLiftMove,SFXLiftMove,-1,SFXLiftMove);
			}
		}

			CurEnvTriggerSet("WAST17","BRLTRIG");
			if(VKeyObjFrame==18 && varkey111==0)
			{
				vector(_set,Gactorpos,-16337.65,24736.41,15464.29);
				sample(SFXBigHit,Gactorpos);
				float(_set,varkey111,1);
			}
		

			CurEnvTriggerSet("WAST17","BRLTRIG");
			if(VKeyObjFrame==96 && varkey111==0)
			{
				vector(_set,Gactorpos,-16337.65,24736.41,15464.29);
				sample(SFXBigHit,Gactorpos);
				float(_set,varkey111,1);
			}

			if(varkey111>0 && varkey111<6)
			{
				float(_add,varkey111,1);	

				if(varkey111==6)
				{
					float(_set,varkey111,0);
				}
			}
		

		
	}
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST17                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VSetActive=="wast17")   //mainscene
	{
		CurEnvTriggerSet("wast17","moveme3");
		call(ExpSet1,0,0,8);
		call(ExpSet2,0,0,8);

		CurEnvTriggerSet("wast17","moveme4");
		call(ExpSet1,0,0,8);
		call(ExpSet2,0,0,8);

		CurEnvTriggerSet("wast17","moveme5");
		call(ExpSet1,0,0,8);

		if(varkey112==0)
		{
			vector(_set,Gactorpos,-14378.16,25173.00,17706.04);
			vector(_set,tmpvector,255,0,0);
			SpawnLight(Lomnilight3,-1,Gactorpos,tmpvector,EmptyVector,600);

			vector(_set,Gactorpos,-14378.16,25173.00,16767.30);
			vector(_set,tmpvector,255,0,0);
			SpawnLight(Lomnilight3,-1,Gactorpos,tmpvector,EmptyVector,600);

			float(_set,varkey112,1);
		}
		
	//	if(VarKey119==1)	
	//	{
			CurEnvTriggerSet("WAST17","BRLTRIG");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				kfsample(SFXLiftMove,SFXLiftMove,-1,SFXLiftMove);

				CurEnvTriggerSet("WAST15","BRLTRIG");
				call(KeyObjTrigger,255,1);
			}
			
	//		CurEnvTriggerSet("WAST17","BRLTRIG");
	//		if(VKeyObjFrame==18);
	//		{
	//			vector(_set,Gactorpos,-16337,24736,15464);
	//			sample(SFXBigHit,Gactorpos);
	//		}
			

	//	}
		
		if(varkey119==1)
		{
			CurEnvTriggerSet("WAST17","cmptrig");
			float(_set,tmpfloat,0xFFFF00);
			call(expSet1,1,tmpfloat,0);

			CurEnvTriggerSet("WAST17","RDTRIG");  //red on
			float(_set,tmpfloat,0xFFFFFF);         
			call(expSet1,1,tmpfloat,0);

			CurEnvTriggerSet("WAST17","GRNTRIG");   //green off
			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);
		}
	}
	if(VCurSet=="wast4")
	{
		Camera(100,elevator_camera_angle);
		Target(elevator_camera_Tdistance,elevator_camera_Tangle);
	}
	elseif(VCurSet=="wast9")
	{
		camera(200,150);
		target(50,50);
	}
	elseif(VCurset=="wast13")
	{
		camera(200,150);
		target(50,50);
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

}



SubRoutine(BackgroundTriggerChecksScene10)
{

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel10); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(VAICon==0)
	{
		if(CabTimer>=10)
		{
			SetActorToTrigger("loftwork","pos2");
		}
	}
	// _________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST1                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	if(VCurSet=="wast1") //Returns the Current Set name and check if the actor is within the set
	{
		if(VAICon==0)
		{
			GetNumbActorsInSet("wast1",_AIClassWorker,TmpFloat);
			GetNumbActorsInSet("wast2",_AIClassWorker,TmpFloat2);
			GetNumbActorsInSet("wast3",_AIClassWorker,TmpFloat3);
			if(TmpFloat==0 && TmpFloat2==0 && TmpFloat3==0)
			{
					vector(_set,Gactorpos,-17181,25475,13937);
					vector(_set,Gactorangle,0,1024,0);
					InitActor(worker2,Gactorpos,Gactorangle,"Wast2",TRUE,1);	
			}
		}

		callsub(Sub_SetCameraNormal);
		
		call(SetParticleSetID,"wast1");
		CurEnvTrigger("door14"); // fill triggerptr to check its structure
		//If Player is in Trigger
		if(VTrigger==_DIREnvTrigger) // Vtrigger checks informations from the trigger // _DIREnvTrigger checks if character within the trigger // _DIRaction checks if action key has been pressed
		{
			//If controlled by bob
			if(VAICon==0) // checks if it's the player or an AI character (0==player 1==AI Character)
			{
				if(VAIClass==_AIClassWorker)
				{
					//Make the surrounding lights green
					float(_set,tmpfloat,0x00FF00);
					call(expSet1,1,tmpfloat,0);  //call(expSet1,functionality,color,0)
					call(expSet2,1,tmpfloat,0); 
					
					//If he hits the action key
					if(VTrigger==_DIRAction)
					{
						//Open the door
						//callsub(DoorOpen,2,1); //see enemies\shared.hxx
						if(ControlTimer==0)
						{
							float(_set,ControlTimer,1);
							//callsub(DoorOpen,2,1);
							direction(_clr,_DIRaction);
						}
					}
				}
				else	//Otherwise he is just bob
				{
					//If he hits action key
					if(VTrigger==_DIRAction)
					{
						message("Locked.",120,10); //displays a message. Message(String,Displaytime,FontSize)
						sample(SFXLockedSound,-1);
						if(vrnd<33)
						{
							sample(SFXPlayerActivatesLockedDoorReact,-1);
						}
					}
				}
			}
		}
		else
		{
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);
		}

		//Anyone can get through this door
	    CurEnvTrigger("Door13");
		if (VTrigger==_DIREnvTrigger)
		{
//			float(_set,tmpfloat,0xFF0000)  //change acces lights to red
//			call(expSet1,1,tmpfloat,0);

			if(VTrigger==_DIRAction && timer3==0)
			{
				message("You are not allo..... ",120,10); //displays a message. Message(String,Displaytime,FontSize)
				vector(_set,gactorpos,-15963.53,25550.47,13571.60);
				float(_rnd2,tmpfloat,48);
				float(_sub,tmpfloat,24);
				vector(_setx,Gactorine,tmpFloat);
				float(_rnd2,tmpfloat,24);
				float(_sub,tmpfloat,48);
				vector(_sety,Gactorine,tmpFloat);
				float(_rnd2,tmpfloat,6);
				float(_sub,tmpfloat,18);
				vector(_setz,Gactorine,tmpFloat);
				vector(_set,Gactorine,0,-8,24);
				spawnparticle(fx_sparks,-1,gactorpos,gactorine,-1);
				sample(SFXSparks,Gactorpos);
				float(_set,timer3,1);
				float(_set,VarKey118,1);
			}
		}
		else
		{
//			float(_set,tmpfloat,0xFF0000);
//			call(expSet1,1,tmpfloat,0);
		}

		if (timer3>0)
		{
			if (timer3<30)
			{
				float(_add,timer3,1);
			}
			if (timer3==30)
			{
				CurEnvTrigger("Door13");
				call(KeyObjTrigger,1,1); //Triggers the animation of the object : 255 -> End Frame / 1 : direction (1 is forward, -1 is backward)
				direction(_clr,_DIRaction); //clears the action key
				CurEnvTriggerSet("Wast3","Door13");
				call(KeyObjTrigger,1,1); //Triggers the animation of the object : 255 -> End Frame / 1 : direction (1 is forward, -1 is backward)
				sample(sfxdoop1, -1);
				//sample(sfxdomo1, -1);
				sample(SFXLiftGrind, -1)

				float(_set,timer3,31);
			}
			if (VKeyObjFrame==1 && timer3==31 && VKeyObjTriggered==0)
			{
				float(_add,timer3,1);			
				//sample(SFXLiftGrind, -1);
				float(_set,VarKey118,2);
			}
/*			if (timer3>31)
			{
				if (timer3<62)
				{
					float(_add,timer3,1);
				}
				else
				{
					CurEnvTrigger("Door13");
					call(KeyObjTrigger,1,255); //Triggers the animation of the object : 255 -> End Frame / 1 : direction (1 is forward, -1 is backward)
					CurEnvTriggerSet("Wast3","Door13");
					call(KeyObjTrigger,1,255); //Triggers the animation of the object : 255 -> End Frame / 1 : direction (1 is forward, -1 is backward)
				}
			}
			CurEnvTrigger("Door13");
			if (timer3>=62 && VKeyObjTriggered==0)
			{
				float(_set,timer3,0);
				print("Animation over",0);
			}*/
		}

	
		if(ControlTimer==1)
		{
			CurEnvTrigger("door14");
			if(VSetActive=="wast4")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("wast1","door14",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}


	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯


	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST2                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast2") // check if ACTOR is in the set
	{
		CurEnvTrigger("Door23");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);

			if(VTrigger==_DIRAction)
			{
				//if(VKeyObjTriggered==0)
				//{
 					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					kfsample(SFXVaultOpen,SFXVaultMove,-1,SFXVaultClose);

					if(VClass==_ClassCop && VTrigger==_DIRhavegun && VTrigger==_DIRcombatmode)
					{
						SpawnAction(CopOpenDoorCombat);
					}
				//}
			}
		}
		else
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}

		CurEnvTrigger("PanTrig1");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			sample(SFXValidFunction,-1);
			message("All security systems active and ready.",120,10);
		}
		CurEnvTrigger("PanTrig2");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			sample(SFXValidFunction,-1);
			message("Next shipment currently in final loading procedure.",120,10);
		}
		CurEnvTrigger("PanTrig3");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			sample(SFXValidFunction,-1);
			message("Electro magnetic pressure field active and ready.",120,10);
		}
		CurEnvTrigger("PanTrig4");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			sample(SFXValidFunction,-1);
			message("Door malfunction in sector W-1",120,10);
		}

	
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST3                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast3") // check if ACTOR is in the set
	{		
		CurEnvTrigger("Door23");
		if (VTrigger==_DIREnvTrigger)
		{
			//set lights for door 23 to green
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);

			if(VTrigger==_DIRAction)
			{
				//callsub(DoorOpen,2,1); //see enemies\shared.hxx
                                //callsub(DoorOpen,doorsize,waittype) 
				if(VSetActive!="wast2" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		else
		{
			//turn off access lights
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}


		CurEnvTrigger("Door314");
		if (VTrigger==_DIREnvTrigger)
		{
			if(VAICOn==0)
			{
				float(_set,tmpfloat,0xFF0000);
				call(expSet1,1,tmpfloat,0);
			}

			if(VTrigger==_DIRAction)
			{
				if(VAICon==1)
				{
					//callsub(DoorOpen,2,1); //see enemies\shared.hxx
										//callsub(DoorOpen,doorsize,waittype)
					if(VSetActive!="wast14" && ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						direction(_clr,_DIRaction);
					}

					float(_set,tmpfloat,0x00FF00);
					call(expSet1,1,tmpfloat,0);  //turn lights green as npc opens door
				}
				else
				{
					//Turn his bitch ass out
					message("Locked.",120,10); //displays a message. Message(String,Displaytime,FontSize)
					sample(SFXLockedSound,-1);
					if(vrnd<33)
					{
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}

					float(_set,tmpfloat,0xFF0000);  //turn lights red
					call(expSet1,1,tmpfloat,0);
				}
			}
		}

		else
		{
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
		}

		CurEnvTrigger("PanTrig");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			sample(SFXValidFunction,-1);
			message("Furnace Temperature 6021.14 Degrees(k)",120,10);
		}


		if(ControlTimer==1)
		{
			CurEnvTrigger("door23");
			if(VSetActive=="wast2")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("wast3","door23",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("door314");
			if(VSetActive=="wast14")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("wast3","door314",1);
				call(KeyObjTrigger,255,1);
			}
		}


	}

	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

	
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST4                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast4") // check if ACTOR is in the set
	{
//		Camera(100,elevator_camera_angle);
//		Target(elevator_camera_Tdistance,elevator_camera_Tangle);

		CurEnvTrigger("Door14");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			callsub(DoorOpen,2,1);
		}


		CurEnvTrigger("Fire");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VState!=StateDead)
			{
				if(VAICon==0)
				{
					call(LockCamera,true);
//ttt					call(AIchangerank,0);		//take care of deaths internally!
				}
//				call(SubtractHealth,0,30000);
				Direction(_clr,_DIRalive);
				state(_or,StateOnFire);
				state(_or,StateDead);
			}
		}

		if(PlatformLevel1==0)
		{
			CurEnvTriggerSet("wast5","TopTrig");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				float(_set,PlatformLevel1,1);
			}
		}

		if(PlatformLevel2==0)
		{
			CurEnvTriggerSet("wast5","BtmTrig");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				float(_set,PlatformLevel2,1);
			}
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯


	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST5                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast5") // check if ACTOR is in the set
	{
		CurEnvTrigger("Death");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VState!=StateDead)
			{
				if(VAICon==0)
				{
					call(LockCamera,true);
//ttt					call(AIchangerank,0);		//take care of deaths internally!
				}
//				call(SubtractHealth,0,30000);
				state(_or,StateDead);
				Direction(_clr,_DIRalive);
			}
		}
		if(VAICon==0)
		{
			CurEnvTriggerSet("wast5","view1");
			if(VTrigger==_DirEnvTrigger)
			{
				Camera(200,50);
				target(50,50);
			}
			else
			{
				CurEnvTriggerSet("wast5","view2");
				if(VTrigger==_DirEnvTrigger)
				{
					Camera(200,50);
					target(50,50);
				}
				else
				{
					CurEnvTriggerSet("wast5","view3");
					if(VTrigger==_DirEnvTrigger)
					{
						Camera(200,50);
						target(50,50);
				
					}
					else
					{
						CurEnvTrigger("TopTrig");
						if(VTrigger==_DIREnvTrigger)
						{
							if(PlatformLevel1==1)
							{
								if(PlatformTimer<30)
								{
									float(_add,PlatformTimer,1);
								}
								elseif(PlatformTimer==30)
								{
									Camera(elevator_camera_distance,elevator_camera_angle);
									Target(elevator_camera_Tdistance,elevator_camera_Tangle);

									call(KeyObjTrigger,1,1);
									float(_set,PlatformLevel1,0);
									float(_set,PlatformTimer,0);
								}
							}
						}
						else
						{
							CurEnvTrigger("TopTrig2");
							if(VTrigger==_DIREnvTrigger)
							{
								if(PlatformLevel1==1)
								{
									if(PlatformTimer<30)
									{
										float(_add,PlatformTimer,1);
									}
									elseif(PlatformTimer==30)
									{
										Camera(elevator_camera_distance,elevator_camera_angle);
										Target(elevator_camera_Tdistance,elevator_camera_Tangle);

										CurEnvTriggeR("TopTrig");
										call(KeyObjTrigger,1,1);
										float(_set,PlatformLevel1,0);
										float(_set,PlatformTimer,0);
									}
								}
							}
							else
							{
								CurEnvTrigger("TopTrig3");
								if(VTrigger==_DIREnvTrigger)
								{
									if(PlatformLevel1==1)
									{
										if(PlatformTimer<30)
										{
											float(_add,PlatformTimer,1);
										}
										elseif(PlatformTimer==30)
										{
											Camera(elevator_camera_distance,elevator_camera_angle);
											Target(elevator_camera_Tdistance,elevator_camera_Tangle);

											CurEnvTriggeR("TopTrig");
											call(KeyObjTrigger,1,1);
											float(_set,PlatformLevel1,0);
											float(_set,PlatformTimer,0);
										}
									}
								}
								else
								{
									CurEnvTrigger("RolTrig2");
									if(VKeyObjFrame>=11)
									{

										CurEnvTrigger("BtmTrig");
										if(VTrigger==_DIREnvTrigger)
										{
											Camera(elevator_camera_distance,elevator_camera_angle);
											Target(elevator_camera_Tdistance,elevator_camera_Tangle);
											if(PlatformLevel2==1)
											{
												if(PlatformTimer<30)
												{
													float(_add,PlatformTimer,1);
												}
												elseif(PlatformTimer==30)
												{
													call(KeyObjTrigger,3,1);
													float(_set,PlatformLevel2,0);
													float(_set,PlatformTimer,0);
												}
											}
										}
									}
									else
									{	
										CurEnvTrigger("BtmTrig2");
										if(VTrigger==_DIREnvTrigger)
										{
											Camera(elevator_camera_distance,elevator_camera_angle);
											Target(elevator_camera_Tdistance,elevator_camera_Tangle);
											if(PlatformLevel2==1)
											{
												if(PlatformTimer<30)
												{
													float(_add,PlatformTimer,1);
												}
												elseif(PlatformTimer==30)
												{
													CurEnvTriggeR("BtmTrig");
													call(KeyObjTrigger,3,1);
													float(_set,PlatformLevel2,0);
													float(_set,PlatformTimer,0);
												}
											}
										}
										else
										{
											CurEnvTrigger("BtmTrig3");
											if(VTrigger==_DIREnvTrigger)
											{
												Camera(elevator_camera_distance,elevator_camera_angle);
												Target(elevator_camera_Tdistance,elevator_camera_Tangle);
												if(PlatformLevel2==1)
												{
													if(PlatformTimer<30)
													{
														float(_add,PlatformTimer,1);
													}
													elseif(PlatformTimer==30)
													{
														CurEnvTriggeR("BtmTrig");
														call(KeyObjTrigger,3,1);
														float(_set,PlatformLevel2,0);
														float(_set,PlatformTimer,0);
													}
												}
											}
											else
											{
												callsub(Sub_SetCameraNormal);
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

		CurEnvTrigger("TopTrig4")
		if(PlatformLevel1==0)
		{
			if(VTrigger!=_DIREnvTrigger)
			{
				CurEnvTrigger("TopTrig5")
				if(VTrigger!=_DIREnvTrigger)
				{
					CurEnvTrigger("TopTrig6")
					if(VTrigger!=_DIREnvTrigger)
					{
						CurEnvTrigger("TopTrig");
						if(VKeyObjTriggered==0)
						{
							CurEnvTrigger("TopTrig")
							call(KeyObjTrigger,255,1);
							float(_set,PlatformLevel1,1);
						}
					}
				}
			}
		}
		
		CurEnvTrigger("BtmTrig4")
		if(PlatformLevel2==0)
		{
			if(VTrigger!=_DIREnvTrigger)
			{
				CurEnvTrigger("BtmTrig5")
				if(VTrigger!=_DIREnvTrigger)
				{
					CurEnvTrigger("BtmTrig6")
					if(VTrigger!=_DIREnvTrigger)
					{
						CurEnvTrigger("BtmTrig");
						if(VKeyObjTriggered==0)
						{
							CurEnvTrigger("BtmTrig")
							call(KeyObjTrigger,255,1);
							float(_set,PlatformLevel2,1);
						}
					}
				}
			}
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	
	
	
	
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST6                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast6") // check if ACTOR is in the set
	{
		if(PlatformLevel1==0)
		{
			CurEnvTriggerSet("wast5","TopTrig");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				float(_set,PlatformLevel1,1);
			}
		}

		if(PlatformLevel2==0)
		{
			CurEnvTriggerSet("wast5","BtmTrig");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				float(_set,PlatformLevel2,1);
			}
		}
	}	
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

	
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST7                                                      |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast7")
	{
		CurEnvTrigger("FldTrig");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

	elseif(VCurSet=="wast8")
	{
		if(VAICon==0)
		{
			callsub(Sub_SetCameraNormal);
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST12                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast12") // check if ACTOR is in the set
	{
		CurEnvTrigger("Door1213");
		if (VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if (VAICon==0)	//Make sure it's bob
			{
				//callsub(DoorOpen,2,1); //see enemies\shared.hxx
				if(VSetActive!="wast13" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("door1213");
			if(VSetActive=="wast13")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("wast12","door1213",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}

	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST13                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast13") // check if ACTOR is in the set
	{
		if(VAICon==0)
		{
			callsub(Sub_SetCameraNormal);
		}

		CurEnvTrigger("lift");
		if(VkeyObjTriggered==0)
		{
			CurEnvTrigger("door1213");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="wast12" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("door1315");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,1,1);
				if(VSetActive!="wast15" && ControlTimer==0)
				{
					call(ForceLoadset,"wast17");
					float(_set,ControlTimer,2);
					direction(_clr,_DIRaction);
				}
			}
			if(CameraPan==0)
			{
				float(_set,CameraPan,1);
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("door1213");
				if(VSetActive=="wast12")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("wast13","door1213",1);
					call(KeyObjTrigger,255,1);
				}
			}
			if(ControlTimer==2  && VSetInMemory=="wast17")
			{
				CurEnvTrigger("door1315");
				if(VSetActive=="wast15")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("wast13","door1315",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
		else
		{
			if(CameraPan==1)
			{
				float(_set,CameraPan,0);
			}
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

		if(VTrigger==_DIRactionhold && VKeyObjTriggered==0)
		{
			float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
			CurEnvTrigger("panel1");
			callsub(LiftControl,0,1);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,1);

			
			if(TmpFloat!=-1)
			{
				CurEnvTrigger("lift");
				if(TmpFloat1==1)
				{
					if(TmpFloat==1)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXLoadingDocks,1);
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXWasteplant,1);
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
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST14                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast14") // check if ACTOR is in the set
	{
		CurEnvTrigger("Door314");
		if (VTrigger==_DIREnvTrigger)
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);

			if(VTrigger==_DIRAction)
			{
				//callsub(DoorOpen,2,1); //see enemies\shared.hxx
                                //callsub(DoorOpen,doorsize,waittype) 
				if(VSetActive!="wast3" && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		else
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}

		CurEnvTrigger("Door1415");
		if (VTrigger==_DIREnvTrigger)
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
			if(VTrigger==_DIRAction)
			{
				//callsub(DoorOpen,2,1); //see enemies\shared.hxx
                                //callsub(DoorOpen,doorsize,waittype) 
				if(VSetActive!="wast15" && ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					direction(_clr,_DIRaction);
				}
			}
		}
		else
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("door314");
			if(VSetActive=="wast3")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("wast14","door314",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("door1415");
			if(VSetActive=="wast15")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("wast14","door1415",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST15                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast15") // check if ACTOR is in the set
	{
		CurEnvTrigger("Door1317");
		if (VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			SetKeyFrame("Wast13","lift",1);
			//callsub(DoorOpen,2,1);
			if(VSetActive!="wast13" && ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("Door1417");
		if (VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			message("Locked",120,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("door1317");
			if(VSetActive=="wast13")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("wast15","door1317",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	// ___________________________________________________________________
	//|	                                                                  |
	//| SCENE: WAST17                                                     |	
	//|	                                                                  |
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	elseif(VCurSet=="wast17")
	{
		if(VAICon==0)
		{
			GetNumbActorsInSet("wast17",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
			if(tmpfloat==0)
			{
				GetNumbActorsInSet("wast15",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
				if(tmpfloat==0)
				{
					GetNumbActorsInSet("wast13",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
					if(tmpfloat==0)
					{
						GetNumbActorsInSet("wast12",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
						if(tmpfloat==0)
						{
							GetNumbActorsInSet("wast11",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
							if(tmpfloat==0 && timer2==0)
							{		
								CurEnvTriggerSet("wast15","door1317");
								callsub(DoorOpen,2,1);

								vector(_set,Gactorpos,-15577,24731,15892);
								vector(_set,Gactorangle,0,0,0);
								InitActor(GunCommander,Gactorpos,Gactorangle,"wast13",TRUE,42);
								InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"Wast13");

								float(_set,timer2,300);
							}
						}
					}
				}
			}
		}

		CurEnvTrigger("CopTrig");
		if (VTrigger==_DIREnvTrigger && VAItargetfound==_AIEnemy && VarKey117==0)
		{
			float(_set,VarKey117,1);
		}

		if(VarKey117>0 && VarKey117<30)
		{
			float(_add,VarKey117,1);
		}

		if(VarKey117==30)
		{
			CurEnvTriggerSet("Wast15","Door1417");
			callsub(DoorOpen,2,1);

			vector(_set,Gactorpos,-16000,24723,15185);
			vector(_set,Gactorangle,0,2048,0);
			InitActor(copl,Gactorpos,Gactorangle,"Wast15",TRUE,1);
			InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"Wast17");

			vector(_set,Gactorpos,-16100,24723,15185);
			vector(_set,Gactorangle,0,2048,0);
			InitActor(copl,Gactorpos,Gactorangle,"Wast15",TRUE,1);
			InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"Wast17");

			float(_set,VarKey117,31);
		}

		CurEnvTrigger("CMPTRIG");
		if (VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(VAICon==0)
			{
				if(varkey119>1 && varkey119<5)
				{
					message("Finishing Loading Sequence",120,10);
				}
				elseif(varkey119>5)
				{
					message("Loading Sequence Complete",120,10);
				}
				elseif(VAIClass==_AIClassCop)// && VRank==_RankCommander)
				{
					call(ActivateButton,"Loading Lift Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,VarKey119,2);
				}
				else
				{
					call(ActivateButton,"Authorized Personnel Only",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}

		if(VarKey119==2)
		{
	//		CurEnvTrigger("BRLTRIG");
	//		if(VKeyObjFrame==0)
	//		{
	//			SetKeyFrame("Wast17","BRLTRIG",0);
				
				CurEnvTrigger("CMPTRIG");
				call(KeyObjTrigger,1,1);
				vector(_set,Gactorpos,-15697.28,24831.28,17272.21);
				sample(SFXLiftStart,gactorpos,80);
				sample(SFXLiftMove,gactorpos,80);

				float(_set,VarKey119,3);
				float(_set,Timer,80);
	//		}
		}
		elseif(VarKey119<2)
		{
			CurEnvTrigger("BRLTRIG");
			if(VKeyObjFrame==16 && BarrelTimer==0)
			{
				float(_set,BarrelTimer,1);
			}
			
			if(BarrelTimer>0 && BarrelTimer<200)
			{
				float(_add,BarrelTimer,1);
			}
			elseif(BarrelTimer==200)
			{
				vector(_set,Gactorpos,-15733.75,24828.96,17262.73);
				vector(_set,tmpvector,70,20,100);
				sample(SFXSparks,Gactorpos);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,400);	//spawnlight(name,bone,position,color,radius)
				float(_add,BarrelTimer,1);
			}
			
			if(BarrelTimer>200)
			{
				float(_set,BarrelTimer,0);
			}
		}

		if(VarKey119==3)
		{
			CurEnvTrigger("CMPTRIG");
			if(VKeyObjTriggered==0)
			{
				if(Timer==80)
				{
					vector(_set,Gactorpos,-15697.28,24831.28,17272.21);
					samplestop(SFXLiftMove,gactorpos);
					sample(SFXSmallLiftStop,gactorpos);
				//	CurEnvTrigger("RearTrig");
				//	call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
				}
				if(Timer>0)
				{
					float(_sub,Timer,1);
					if(vrnd<50)
					{
						vector(_set,gactorine,0,30,0);
						vector(_set,gactorpos,-15561.42,24540.25,17513);
						spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
						spawnparticle(fx_SteamPipes,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
						vector(_setx,gactorpos,-14969.10);
						spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
						spawnparticle(fx_SteamPipes,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
						vector(_set,gactorpos,-15561.42,24540.25,16986.73);
						spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
						spawnparticle(fx_SteamPipes,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
						vector(_setx,gactorpos,-14969.10);
						spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
						spawnparticle(fx_SteamPipes,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)

						if(vrnd<25)
						{
							vector(_set,Gactorpos,-15355.17,24527.21,17272.21);
							sample(SFXVent2,GactorPos,100);
						}
					}
				}
				else
				{
					call(KeyObjTrigger,255,1);

					CurEnvTrigger("LIFTTRIG");
					call(KeyObjTrigger,255,1);

					float(_set,tmpfloat,0xFFFF00);
					call(expSet1,1,tmpfloat,0);	//call(expSet1,functionality,color,0)

					vector(_set,Gactorpos,-15355.17,24527.21,17272.21);
					sample(SFXLiftStart,gactorpos,100);
					sample(SFXHangerLift,gactorpos,100);

					float(_set,VarKey119,4);
				}
			}
		}


		if(VarKey119==4)
		{
			CurEnvTrigger("LIFTTRIG")
			if(VKeyObjTriggered==0)
			{
//				CurEnvTrigger("CMPTRIG")
//				float(_set,tmpfloat,0xFFFFFF);
//				call(expSet1,1,tmpfloat,0);	//call(expSet1,functionality,color,0)
//				float(_set,tmpfloat,0x333333);
//				call(expSet2,1,tmpfloat,0);	//call(expSet1,functionality,color,0)
				float(_set,VarKey119,5);

				CurEnvTrigger("GRNTRIG");       //on green
				float(_set,tmpfloat,0xFFFFFF);
				call(expSet1,1,tmpfloat,0);

				CurEnvTrigger("RDTRIG");
				float(_set,tmpfloat,0x333333);  //off red
				call(expSet1,1,tmpfloat,0);



				vector(_set,Gactorpos,-15355.17,24527.21,17272.21);
				samplestop(SFXHangerLift,gactorpos);
				sample(SFXLiftEnd,gactorpos,100);
			}
		}

		if(VarKey119==5)
		{

			vector(_set,Gactorpos,-14378.16,25173.00,17706.04);
			KillLight(Lomnilight3,Gactorpos,0);

			vector(_set,Gactorpos,-14378.16,25173.00,16767.30);
			KillLight(Lomnilight3,Gactorpos,0);
			
			vector(_set,Gactorpos,-14381.75,25015.97,17704.54);
			vector(_set,tmpvector,0,255,0);
			SpawnLight(Lomnilight3,-1,Gactorpos,tmpvector,EmptyVector,600);

			vector(_set,Gactorpos,-14381.75,25015.97,16767.30);
			vector(_set,tmpvector,0,255,0);
			SpawnLight(Lomnilight3,-1,Gactorpos,tmpvector,EmptyVector,600);
			float(_set,VarKey119,6);
		}
		//elseif(VarKey119==6)
		//{
			if(VAICon==0)
			{
				CurEnvTrigger("lifttrig");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					if(VAIClass==_AIClassCop && VRank==_RankCommander)
					{
						if(varkey119==6)
						{
							call(ForceGlobalRealloc);
							float(_set,VarKey119,7);
							message("Truck Activated",120,10);
						}
						else
						{
							sample(SFXAccessDenied,Gactorpos);
						}
					}
					else
					{
						if(Vaiclass==_aiclassangel && varkey114==0)
						{
							float(_set,varkey114,1);
							sample(SFXCantUse1,-1);
						}

						message("Only Commanders Can Activate This Vehicle",200,10);
						sample(SFXAccessDenied,Gactorpos);
					}
				}
			}
		//}

		if(VarKey119>=2 && VarKey119<=4)
		{
			CurEnvTrigger("STRIG01");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
	
				vector(_set,tmpvector,255,180,60);
				vector(_set,tmpvector1,0,0,1);
				vector(_set,Gactorpos,-14688.36,25173.00,17251.29);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,600);
			}

			CurEnvTrigger("STRIG2");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
	
				vector(_set,tmpvector,255,180,60);
				vector(_set,tmpvector1,1,0,-1);
				vector(_set,Gactorpos,-16857.81,25371.07,17250.89);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,600);
			}
		}

		/*
			The following will only work if "Street" has been combined
			with Wasteplant. AND DON'T FREAK OUT, I'M NOT BREAKING
			ANYTHING !!! +:)
		*/
		/////////////////////////////////////////////////
		////// S T A R T    E N D    S E Q U E N C E  ///
		/////////////////////////////////////////////////
		if(VAICon==0)
		{
			if(VarKey119==7)
			{
				call(DeleteEntitiesAndActorsInSet,"walls3");
				call(DeleteEntitiesAndActorsInSet,"walls12");
				ActorFlag(_or,_AFLAGforceactive);
				FirstPerson(0,0);
				if(VSniperMode!=0)
				{
					call(ChangeSniperMode,-2,0);
				}
				CutScene("camera01");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				float(_clr,Varbit,Help01);
				float(_set,AIVisionToggle,1);
				call(PlayerInput,0);
				CurEnvTrigger("transit");
				callsub(DoorOpen,2,1);
				CurEnvTrigger("moveme4");
				call(KeyObjTrigger,255,1);
				float(_set,VarKey119,8);
			}
			if(VarKey119==8)
			{
				CurEnvTrigger("moveme4");
				if(VKeyObjTriggered==0 && VKeyObjFrame!=0)
				{
					CurEnvTrigger("strig01");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					CurEnvTrigger("transit");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					CurEnvTrigger("cab");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					SetActorToTrigger("wast17","cmptrig");
					float(_set,VarKey119,9);
					float(_set,ControlTimer,0);
				}
			}

			if(VarKey119==9)
			{
				CurEnvTrigger("cab");
				call(KeyObjTrigger,255,1);
				vector(_set,TmpVector,0,0,0);
				vector(_set,Gactorpos,-12570,24550,16324);
				vector(_set,Gactorangle,0,2048,0);
				initactor(WeaponMachineGun,Gactorpos,Gactorangle,"walls3");
				vector(_set,Gactorpos,-12570,24500,16324);
				initactor(copm,Gactorpos,Gactorangle,"walls3",TRUE,1);

				vector(_set,Gactorpos,-12915,24550,16273);
				vector(_set,Gactorangle,0,2048,0);
				initactor(WeaponPumpGun,Gactorpos,Gactorangle,"walls3");
				vector(_set,Gactorpos,-12915,24500,16273);
				initactor(copm,Gactorpos,Gactorangle,"walls3",TRUE,2);

				vector(_set,Gactorpos,-13277,24550,16463);
				vector(_set,Gactorangle,0,2048,0);
				initactor(WeaponMachineGun,Gactorpos,Gactorangle,"walls3");
				vector(_set,Gactorpos,-13277,24500,16463);
				initactor(copm,Gactorpos,Gactorangle,"walls3",TRUE,3);
				
				float(_set,VarKey119,10);
			}

			if(VarKey119==10)
			{
				CurEnvTrigger("cab");
				if(VKeyObjFrame==10 && Cabtimer==0 && VAICon==0)
				{
					float(_set,TimeForSound,0);
					float(_set,CabTimer,1);
				}
				if(VKeyObjTriggered!=0)
				{
					call(SetParticleSetID,"wast17");
					vector(_settokfpos,Gactorpos,2);
					vector(_set,Gactorine,0,0,0);
					spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_priestfx);
				}
				if(CabTimer==1 && VAICon==0)
				{
					SetActorToTrigger("walls3","pos2");
					float(_set,CabTimer,2);
				}
			}
		}
	}
	if(VCurSet=="walls3")
	{

		if(VarBit&!=Help02)
		{
			float(_add,BarMantimer,1);
			if(VAICon!=0 && VAIClass==_AIClassCop)
			{
				if(VTrigger!=_DIRCombatMode)
				{
					direction(_or,_DIRcombatmode);
				}
				direction(_clr,_noDIR);
				direction(_or,_DIRshoot);
			}			
		}

		if(VAICon==0)
		{
			if(Cabtimer==2)
			{
				CutScene("cabshow");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				CurEnvTrigger("cab");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				call(KeyObjTrigger,255,1);
				kfsample(SFXCabEngine,SFXCabEngine,-1,SFXCabEngine);
				float(_set,CabTimer,3);
			}

			CurEnvTrigger("cab");
			if(VKeyObjFrame==0 && TimeForSound==0)
			{

				vector(_set,Gactorpos,-13247,24514,17422);
				sample(SFXCabCollisionAndTire,Gactorpos);
				float(_set,TimeForSound,1);
			}			
			elseif(VKeyObjFrame==2 && TimeForSound==1)
			{
				vector(_set,Gactorpos,-12446,24684,17422);
				sample(SFXBigHit,Gactorpos);
				float(_set,TimeForSound,2);
			}
			elseif(VKeyObjFrame==3)
			{
				float(_clr,VarBit,Help02);
				call(ScreenShake,0,10,0,0.8);
			}
			elseif(VKeyObjFrame==5 && TimeForSound==2)
			{
				vector(_set,Gactorpos,-12730,24578,17184);
				sample(SFXCabRevsUp,Gactorpos);
				float(_set,TimeForSound,3);
			}
			elseif(VKeyObjFrame==7 && TimeForSound==3)
			{
				vector(_set,Gactorpos,-12730,24578,17184);
				sample(SFXCabRevsUpBig,-1);
				float(_set,TimeForSound,4);
			}
			elseiF(VKeyObjFrame==12 && TimeForSound==4)
			{
				vector(_set,Gactorpos,-12730,24578,17184);
				samplestop(SFXCabRevsUp,Gactorpos);
				sample(SFXCabTiresScreech,Gactorpos);
				float(_set,TimeForsound,5);
			}
			if(VKeyObjFrame>=6 && VKeyObjFrame<=12)
			{
				if(vrnd<15)
				{
					vector(_set,Gactorine,0,10,0);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
				}
			}
			if(VKeyObjFrame>=3 && VKeyObjFrame<=4)
			{
				if(vrnd<30)
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
					vector(_set,Gactorpos,-12445,24721,17291);
					vector(_add,gactorpos,tmpvector);
					call(SetParticleSetID,"walls3");
					SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);
				}
			}
			if(VKeyObjFrame==16)
			{
				CurEnvTrigger("opdoor");
				if(VKeyObjTriggered==0)
				{
					callsub(DoorOpen,2,1);
				}
			}
			if(VKeyObjFrame==19 && CabTimer==3)
			{
				float(_or,VarBit,Help02);
				vector(_set,tmpvector,-12775,24500,16356);
				CurEnvTrigger("hide");
				call(ExplodeObject,TmpVector,1);
				samplestop(SFXCountDown,Gactorpos);
				callsub(Sub_ExplodeObjectHandler);
				float(_set,Cabtimer,4);
			}
			
			CurEnvTrigger("cab");
			if(VKeyObjTriggered!=0)
			{
				call(SetParticleSetID,"walls3");
				vector(_settokfpos,Gactorpos,2);
				vector(_set,Gactorine,0,0,0);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_priestfx);
			}
			if(VKeyObjFrame==26 && Cabtimer==4)
			{
				vector(_set,Gactorpos,-13247,24514,17422);
				float(_set,TimeForSound,0);
				float(_set,Cabtimer,5);
			}
			if(CabTimer==5 && VAICon==0)
			{
				SetActorToTrigger("walls12","transit");
				float(_set,CabTimer,6);
			}
		}
	}
	//********** Player has been "transfered" into walls12x. Cab resumes its course ******
	if(VCurSet=="walls12")
	{
		if(Cabtimer==6)
		{
			CutScene("lustywhore");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			CurEnvTriggerSet("walls3","cab");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			CurEnvTrigger("transit");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(KeyObjTrigger,255,1);
			kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
			float(_set,CabTimer,7);
		}

		CurEnvTrigger("transit");
		if(VKeyObjTriggered!=0)
		{
			call(SetParticleSetID,"walls12");
			vector(_settokfpos,Gactorpos,2);
			vector(_set,Gactorine,0,0,0);
			spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_priestfx);
		}
		if(VKeyObjFrame==2 && TimeForSound==0)
		{
			vector(_set,Gactorpos,-10592,24616,14630);
			sample(SFXCabTiresScreech,Gactorpos);
			float(_set,TimeForSound,1);
		}
			
		if(VKeyObjFrame==7 && TimeForSound==1)
		{
			vector(_set,Gactorpos,-10592,24616,14630);
			sample(SFXBigHit,Gactorpos);
			float(_set,TimeForSound,1);			
			call(ScreenShake,0,10,0,0.8);
		}
		if(VKeyObjFrame==6 && CabTimer==7 && VAICon==0)
		{
			setkeyframe("walls12","transit",1);
			float(_set,TimeForSound,0);
			CutScene("follow02");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			SetActorToTrigger("walls12","pos2");
			CurEnvTrigger("transit");
			call(KeyObjTrigger,255,1);
			kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
			float(_set,CabTimer,8);
		}
		if(VKeyObjFrame==8 && CabTimer==8)
		{
			setkeyframe("walls12","transit",1);
			CutScene("follow03");
			float(_set,TimeForSound,0);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			CurEnvTrigger("transit");
			call(KeyObjTrigger,255,1);
			kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
			CurEnvTrigger("opdoor");
			callsub(DoorOpen,2,0);
			float(_set,CabTimer,9);
		}
		if(VKeyObjFrame==10 && Cabtimer==9 && VAICon==0)
		{
			SetActorToTrigger("loftwork","pos2");
			float(_set,TimeForSound,0);
			float(_set,Cabtimer,10);
		}
	}
	if(VCurSet=="loftwork")
	{
		if(VAICon==0)
		{
			if(CabTimer==10)
			{
				CutScene("first");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				CurEnvTriggerSet("walls12","transit");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				CurEnvTrigger("transit");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				CurEnvTrigger("cab");
				call(KeyObjTrigger,255,1);
				kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
				float(_set,Cabtimer,11);
			}

			CurEnvTrigger("cab");
			if(VKeyObjTriggered!=0)
			{
				call(SetParticleSetID,"loftwork");
				vector(_set,Gactorine,0,0,0);
				vector(_settokfpos,Gactorpos,1);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_priestfx);
				vector(_settokfpos,Gactorpos,2);
				spawnparticle(fx_bazookatrail,-1,gactorpos,gactorine,fx_priestfx);
			}
			if(VKeyObjFrame==2)
			{
				CurEnvTrigger("transit");
				call(KeyObjTrigger,255,1);
			}
			if(VKeyObjFrame==15 && CabTimer==11)
			{
				setkeyframe("loftwork","cab",0);
				setkeyframe("loftwork","transit",0);
				CutScene("second");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				call(KeyObjTrigger,255,1);
				kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
				float(_set,CabTimer,12);
			}

			CurEnvTrigger("cab");
			if(VKeyObjFrame==15 && CabTimer==12)
			{
				setkeyframe("loftwork","cab",0);
				setkeyframe("loftwork","transit",0);
				CutScene("third");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				call(KeyObjTrigger,255,1);
				kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
				float(_set,CabTimer,13);
			}
			
			CurEnvTrigger("cab");
			if(VKeyObjFrame==15 && CabTimer==13)
			{
				setkeyframe("loftwork","cab",0);
				setkeyframe("loftwork","transit",0);
				CutScene("fourth");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				call(KeyObjTrigger,255,1);
				kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
				float(_set,CabTimer,14);
			}
			
			CurEnvTrigger("cab");
			if(VKeyObjFrame==15 && CabTimer==14)
			{
				setkeyframe("loftwork","cab",0);
				setkeyframe("loftwork","transit",0);
				CutScene("fifth");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				call(KeyObjTrigger,255,1);
				kfsample(SFXCabengine,SFXCabengine,-1,SFXCabengine);
				float(_set,CabTimer,15);
			}
			if(CabTimer>=15)
			{
				float(_add,CabTimer,1);
				if(CabTimer==80)
				{
					ActorFlag(_clr,_AFLAGforceactive);
					call(FadeToBlack,0);
				}
				elseif(CabTimer==200)
				{
					actorflag(_or,_AFLAGresetfallalt);
					call(LoadLevel,-1,8,1);
					float(_set,CabTimer,0);
				}
			}
		}
	}
	// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
}
