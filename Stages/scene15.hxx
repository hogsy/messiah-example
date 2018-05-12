/*
	+===========================================================+
	|LABORATORY                                                 |
	+-----------------------------------------------------------+
	|The goal of this level is to create the behemoth so you    |
	|can go up the elevator and fight the priest boss.  If you  |
	|trigger the alarms the autocannons will fire at you (they  |
	|can be triggered by either tripping the laserwalls without |
	|a scientist or by allowing one of the scientists near the  |
	|alarm button to see you.)  Joe is dumb...and gay.          |
	+-----------------------------------------------------------+
	|varkey106		- For beast activation sequence             |
	|varkey104		- For beast activation sequence             |
	|varkey108		- For beast activation sequence             |
	|LabAlarm		- Whether siren has been activated          |
	|LabSecBeams	- For security beams                        |
	|Undertaker		- For guy checkin out the corpse            |
	|CanMakeBeast	- Whether or not there is currently a beast |
	|					produced                                |
	|FlicBits		- For whether flic has been played or not   |
	|VarBit			-											|
	|				Help01 > Story Message #7					|
	+===========================================================+
*/
			
SubRoutine(InitSceneSound15)
{
	if(incoming!=0)
	{
		if(ScriptMark==11)
		{
			callsub(Panel11);
		}
	}
	else
	{
		callsub(ScriptLevel15);
	}

	vector(_set,Gactorpos,8007.49,3662.00,16072.45);
	sample(SFXScanHumm,Gactorpos);

	vector(_set,Gactorpos,8007.49,3662.00,16072.45);
	sample(SFXIndustrial6Small,Gactorpos);

	call(cdplay,17,1);
	callsub(ScriptLevel15);

}

SubRoutine(DeInitSceneSound15)
{
	vector(_set,Gactorpos,8007.49,3662.00,16072.45);
	samplestop(SFXScanHumm,Gactorpos);

	vector(_set,Gactorpos,8007.49,3662.00,16072.45);
	samplestop(SFXIndustrial6Small,Gactorpos);
}


SubRoutine(InitScene15)
{
		if(VScriptInitiated!=15)
		{
			if(VInitScriptCode==0)
			{
				InitActor(Bob1,0,Gactorangle,"s3_lab00");
			}

			#include "messiahscripts\enemies\c1_lab_e.spt"

			//THIS IS ONLY FOR DEBUGGING PURPOSES
			call(loadpreloaddb,8);
			float(_set,varkey106,0);	//For beast activation sequence
			float(_set,varkey104,0);	//For beast activation sequence
			float(_set,varkey108,0);	//For beast activation sequence
			float(_set,LabAlarm,0);		//Whether siren has been activated
			float(_set,LabSecBeams,0);	//For security beams
			float(_set,Undertaker,0);	//For guy checkin out the corpse
			float(_set,CanMakeBeast,1);	//Whether or not there is currently a beast produced
			float(_set,FlicBits,0);		//For whether flic has been played or not
			float(_set,VarBit,AllHelp); //Special variable...it goes up to eleven !
			/////////////////////////////////////

//DEBUG ONLY
			//float(_set,PowerOn,1);
		
		}


		callsub(InitSceneSound15);

		call(ScriptCodeInitiated,15);
//		float(_set,PowerOn,0);
}



SubRoutine(MainScene15)
{
	if(VCDPlay==0)
	{
		call(cdplay,17,1);
	}
	
	
	print("VarKey106: ",VarKey106);

	if(VCheatKeys==1)
	{
		if(VKey==KEY_K && VOKey!=KEY_K)
		{
			if(PowerOn==1)
			{
//				float(_set,PowerOn,0);
			}
			else
			{
				float(_set,PowerOn,1);
			}
		}
	}

	if(VCurSet=="s3_f1_03");
	{
		if(VRunScriptCode!=4)
		{			
			callsub(InitSceneSound4);
			call(RunScriptCode,_or,4);	
		}
	}
	elseif(VCurSet=="s3_lab02")
	{
		if(VRunScriptCode==4)
		{			
			callsub(DeInitSceneSound4);
			call(RunScriptCode,_clr,4);	
		}
	}

	if(VarKey108>=2 && VarKey108<6)
	{
		if(FlicBits&!=0x100 && FlicBits&!=0x200)
		{
			float(_rnd2,tmpfloat,500);
			if(tmpfloat<1.5)
			{
				float(_or,FlicBits,0x100);
				call(ScreenShake,4,4,4,0.01);
				vector(_set,Gactorpos,8020,3500,17016);
				if(vrnd<50)
				{
					sample(SFXBehemothScream,Gactorpos);
				}
				else
				{
					sample(SFXBehemothAngerScream,Gactorpos);
				}
			}
			elseif(tmpfloat<8)
			{
				float(_or,FlicBits,0x200);
				call(ScreenShake,4,4,4,0.9);
				vector(_set,Gactorpos,8020,3500,17016);
				if(vrnd<10)
				{
					sample(SFXLiftGrind,Gactorpos);
				}
				elseif(vrnd<40)
				{
					sample(SFXRustDoorOpen,Gactorpos);
				}
				elseif(vrnd<70)
				{
					sample(SFXRustDoorClose,Gactorpos);
				}
				else
				{
					sample(SFXRustDoorClose2,Gactorpos);
				}
			}

		}
		else
		{
			vector(_set,Gactorpos,8020,3500,17016);
			if(FlicBits&=0x100)
			{
				sampleplaying(SFXBehemothScream,Gactorpos);
				if(VTrigger!=_DIRTempFlag)
				{
					sampleplaying(SFXBehemothAngerScream,Gactorpos);
					if(VTrigger!=_DIRTempFlag)
					{
						float(_clr,FlicBits,0x100);
					}
				}
			}
			else
			{
				sampleplaying(SFXLiftGrind,Gactorpos);
				if(VTrigger!=_DIRTempFlag)
				{
					sampleplaying(SFXRustDoorOpen,Gactorpos);
					if(VTrigger!=_DIRTempFlag)
					{
						sampleplaying(SFXRustDoorClose,Gactorpos);
						if(VTrigger!=_DIRTempFlag)
						{
							sampleplaying(SFXRustDoorClose2,Gactorpos);
							if(VTrigger!=_DIRTempFlag)
							{
								float(_clr,FlicBits,0x200);
							}
						}
					}
				}
			}
		}
	}



	if(VSetActive!="s3_lab05")
	{
		GetNumbActorsInSet("s3_lab08",_AIClassScientist,tmpfloat);
		if(tmpfloat==0)
		{
			GetNumbActorsInSet("s3_lab07",_AIClassScientist,tmpfloat);
			if(tmpfloat==0)
			{
				GetNumbActorsInSet("s3_lab06",_AIClassScientist,tmpfloat);
				if(tmpfloat==0)
				{
					GetNumbActorsInSet("s3_lab05",_AIClassScientist,tmpfloat);
					if(tmpfloat==0)
					{
						GetNumbActorsInSet("s3_lab04",_AIClassScientist,tmpfloat);
						if(tmpfloat==0)
						{
							GetNumbActorsInSet("s3_lab03",_AIClassScientist,tmpfloat);
							if(tmpfloat==0)
							{
								GetNumbActorsInSet("s3_lab02",_AIClassScientist,tmpfloat);
								if(tmpfloat==0)
								{
									GetNumbActorsInSet("s3_lab01",_AIClassScientist,tmpfloat);
									if(tmpfloat==0)
									{
										if(vrnd<33)
										{
											vector(_set,Gactorpos,8760,3477,13686);
											vector(_set,Gactorangle,0,2048,0);
											InitActor(scientist,Gactorpos,Gactorangle,"S3_lab05",TRUE,1);
										}
										elseif(vrnd<66)
										{
											vector(_set,Gactorpos,8597,3470,13360);
											vector(_set,Gactorangle,0,0,0);
											InitActor(scientist,Gactorpos,Gactorangle,"S3_lab05",TRUE,2);
										}
										else
										{
											vector(_set,Gactorpos,9146,3466,13633);
											vector(_set,Gactorangle,0,0,0);
											InitActor(scientist,Gactorpos,Gactorangle,"S3_lab05",TRUE,4);
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
	elseif(VSetActive!="s3_lab08")
	{
		GetNumbActorsInSet("s3_lab08",_AIClassScientist,tmpfloat);
		if(tmpfloat==0)
		{
			GetNumbActorsInSet("s3_lab07",_AIClassScientist,tmpfloat);
			if(tmpfloat==0)
			{
				GetNumbActorsInSet("s3_lab06",_AIClassScientist,tmpfloat);
				if(tmpfloat==0)
				{
					GetNumbActorsInSet("s3_lab05",_AIClassScientist,tmpfloat);
					if(tmpfloat==0)
					{
						GetNumbActorsInSet("s3_lab04",_AIClassScientist,tmpfloat);
						if(tmpfloat==0)
						{
							GetNumbActorsInSet("s3_lab03",_AIClassScientist,tmpfloat);
							if(tmpfloat==0)
							{
								GetNumbActorsInSet("s3_lab02",_AIClassScientist,tmpfloat);
								if(tmpfloat==0)
								{
									GetNumbActorsInSet("s3_lab01",_AIClassScientist,tmpfloat);
									if(tmpfloat==0)
									{
										if(vrnd<50)
										{
											vector(_set,Gactorpos,8021,3320,15047);
											vector(_set,Gactorangle,0,-11,0);
											InitActor(scientist,Gactorpos,Gactorangle,"S3_lab08",TRUE,1);
										}
										else
										{
											vector(_set,Gactorpos,7489,3326,16729);
											vector(_set,Gactorangle,0,-489,0);
											InitActor(scientist,Gactorpos,Gactorangle,"S3_lab08",TRUE,2);
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

	if(VSetActive=="s3_lab01")
	{
		//Set door lock colors
		CurEnvTriggerSet("s3_lab01","Doorup");
		float(_set,tmpfloat,0xFF0000);
		Call(Expset1,1,tmpfloat);
	}

	if(VSetActive=="s3_lab02")
	{
		//Set door lock colors
		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerset("s3_lab02","doorup");
		call(expSet1,1,tmpfloat,0);
		call(expSet2,1,tmpfloat,0);
		
		if(VarKey108>=2)
		{
			float(_set,tmpfloat,0x00FF00);
		}
		else
		{
			float(_set,tmpfloat,0x00FF00);
		}
		CurEnvTriggerSet("s3_lab02","labdoor");
		call(expSet1,1,tmpfloat,0);


		if(VarKey108<=1)
		{
			if(VarKey108==0)
			{
					float(_set,VarKey108,1);
			}

		}
		elseif(VarKey108<=3)
		{
			if(VarKey108==2)
			{
					float(_set,VarKey108,3);
			}
		}

		if(PowerOn==0)
		{
			CurEnvTriggerSet("s3_lab02","doorup");
			if(VKeyObjTriggered!=0)
			{
				setkeyframe("s3_lab02",doorup01",0);
				CurEnvTriggerSet("s3_lab02","doorup01");
				call(KeyObjTrigger,255,1);
			}
		}
		else
		{
			if(VSetActive=="s3_f1_03")
			{
				CurEnvTriggerSet("s3_f1_03","doorup01");
				if(VKeyObjTriggered==0 || VKeyObjFrame>=5)
				{
					setkeyframe("s3_f1_03","doorup01",5);
					Call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTriggerSet("s3_lab02","doorup01");
			if(VKeyObjTriggered==0 || VKeyObjFrame>=5)
			{
				setkeyframe("s3_lab02","doorup01",5);
				Call(KeyObjTrigger,255,1);
			}
		}
	}
	if(VSetActive=="s3_lab04")
	{
		//Setting Lights for OmniAttach
		CurEnvTriggerSet("s3_lab04","STRIG2");
		float(_set,TmpFloat,0x00FF00);
		call(expset1,TmpFloat,100,-1);

		float(_set,tmpfloat,LabSecBeams);
		float(_and,tmpfloat,0x000010);
		if(tmpfloat==0)
		{
			//OMNI ATTACH LITES FOR LAZERS  (ON)
			CurEnvTriggerSet("s3_lab04","LasTrig1");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,100,-1);
			call(expset2,TmpFloat,100,-1);

			CurEnvTriggerSet("s3_lab04","LasTrig2");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,100,-1);
			call(expset2,TmpFloat,100,-1);
		}
		else
		{
			//OMNI ATTACH LITES FOR LAZERS  (OFF)
			CurEnvTriggerSet("s3_lab04","LasTrig1");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,0,-1);
			call(expset2,TmpFloat,0,-1);

			CurEnvTriggerSet("s3_lab04","LasTrig2");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,0,-1);
			call(expset2,TmpFloat,0,-1);
		}
	}
	
	if(VSetActive=="s3_lab05")
	{

		float(_set,tmpfloat,0x000001);
		float(_and,tmpfloat,FlicBits);
		if(tmpfloat==0)
		{
			CurEnvTriggerSet("s3_lab05","Comp02");
			call(ExpSet1,0,0,30);
			float(_or,FlicBits,0x000001);
		}

		
		//Setting Lights for OmniAttach
		CurEnvTriggerSet("s3_lab05","STRIG1");
		float(_set,TmpFloat,0x00FF00);
		call(expset1,TmpFloat,100,-1);
		call(expset2,TmpFloat,100,-1);
		

		call(SetParticleSetID,"s3_lab05");
		float(_set,tmpfloat,LabSecBeams);
		float(_and,tmpfloat,0x000001);
		if(tmpfloat==0)
		{
			//LASER SET 1
			//----------------------------------------------------------
			vector(_set,Gactorpos,7438.75,3319.70,14454.10);
			vector(_set,Gactorine,0,0,-406.06);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3369.70,14454.10);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3419.70,14454.10);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,7438.75,3469.70,14472.80);
			vector(_set,Gactorine,0,0,-443.46);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,7438.75,3519.70,14512.25);
			vector(_set,Gactorine,0,0,-522.36);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3569.70,14512.25);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3619.70,14512.25);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3669.70,14512.25);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3719.70,14512.25);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,7438.75,3769.70,14472.80);
			vector(_set,Gactorine,0,0,-443.46);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,7438.75,3819.70,14454.10);
			vector(_set,Gactorine,0,0,-406.06);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3869.70,14454.10);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,7438.75,3919.70,14454.10);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);
			//----------------------------------------------------------


			//OMNI ATTACH LITES FOR LAZERS  (ON)
			CurEnvTriggerSet("s3_lab05","LazTrig1");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,100,-1);
			call(expset2,TmpFloat,100,-1);

			CurEnvTriggerSet("s3_lab05","LazTrig2");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,100,-1);
			call(expset2,TmpFloat,100,-1);
		}
		else
		{
			//OMNI ATTACH LITES FOR LAZERS  (OFF)
			CurEnvTriggerSet("s3_lab05","LazTrig1");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,0,-1);
			call(expset2,TmpFloat,0,-1);

			CurEnvTriggerSet("s3_lab05","LazTrig2");
			float(_set,TmpFloat,0x0000FF);
			call(expset1,TmpFloat,0,-1);
			call(expset2,TmpFloat,0,-1);
		}
	
		float(_set,tmpfloat,LabSecBeams);
		float(_and,tmpfloat,0x000010);
		if(tmpfloat==0)
		{
			//LASER SET 2
			//----------------------------------------------------------
			vector(_set,Gactorpos,9608.19,3319.70,15174.85);
			vector(_set,Gactorine,406.06,0,0);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9608.19,3369.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9608.19,3419.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,9568.74,3469.70,15174.85);
			vector(_set,Gactorine,443.46,0,0);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,9550.04,3519.70,15174.85);
			vector(_set,Gactorine,522.36,0,0);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9550.04,3569.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9550.04,3619.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9550.04,3669.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9550.04,3719.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,9568.74,3769.70,15174.85);
			vector(_set,Gactorine,443.46,0,0);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);


			vector(_set,Gactorpos,9608.19,3819.70,15174.85);
			vector(_set,Gactorine,406.06,0,0);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9608.19,3869.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);

			vector(_set,Gactorpos,9608.19,3919.70,15174.85);
			spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserflickerblue);
			//----------------------------------------------------------

		}
	}
	if(VSetActive=="s3_lab06")
	{
		//Setting Lights for OmniAttach
		CurEnvTriggerSet("s3_lab06","STRIG1");
		float(_set,TmpFloat,0x00FF00);
		call(expset1,TmpFloat,100,-1);

		if(VCurSet=="s3_lab07")
		{
			if(VSetInMemory!="s3_lab05")
			{
				if(FlicBits&!=0x10)
				{
					call(ForceLoadSet,"s3_lab05");
					float(_or,FlicBits,0x10);
				}
			}
		}
	}
	else
	{
		float(_clr,FlicBits,0x10);
	}
	if(VSetActive=="s3_lab08")
	{
		call(SetParticleSetID,"s3_lab08");

		if(VarKey106>=1)
		{

			if(VarKey106==2)
			{
				call(ScreenShake,4,4,4,0.01);
			}
			elseif(VarKey106==80)
			{
				vector(_set,Gactorpos,8017,3500,17389);
				sample(SFXLiftGrind,Gactorpos);
			}

			CurEnvTriggerSet("s3_lab08","crumple");
			if(VKeyObjTriggered!=0)
			{
				float(_add,VarKey106,1);
			}
		}

		
		//Set door lock indicator lites.
		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerSet("s3_lab08","labdoor");
		call(expSet1,1,tmpfloat,0);

		//Particle and keyframe effects for lab area
		//-------------------------------------------------------
		curenvtriggerset("s3_lab08","top");
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,255,1);
		}

		vector(_set,gactorpos,305.99,178.5,0);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);

		vector(_set,gactorine,175,0,0);
		float(_rnd2,tmpfloat,200);
		float(_add,tmpfloat,48.5);
		vector(_sety,gactorine,tmpfloat);
		vector(_multiplywithobjtransmat,Gactorine,Gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_white);
		

		vector(_set,gactorpos,-305.99,178.5,0);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);

		vector(_set,gactorine,-175,0,0);
		float(_rnd2,tmpfloat,200);
		float(_add,tmpfloat,48.5);
		vector(_sety,gactorine,tmpfloat);
		vector(_multiplywithobjtransmat,Gactorine,Gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_white);



		vector(_set,gactorpos,238,300,43.42);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);

		vector(_set,gactorine,217.63,300,128.06);
		vector(_multiplywithobjtransmat,gactorine,gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorpos,140.11,300,203.77);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorine,0,300,246.08);
		vector(_multiplywithobjtransmat,gactorine,gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorpos,-140.11,300,203.77);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorine,-217.63,300,128.06);
		vector(_multiplywithobjtransmat,Gactorine,Gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorpos,-238,300,43.42);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);



		vector(_set,gactorpos,238,300,-43.42);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);

		vector(_set,gactorine,217.63,300,-128.06);
		vector(_multiplywithobjtransmat,gactorine,gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorpos,140.11,300,-203.77);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorine,0,300,-246.08);
		vector(_multiplywithobjtransmat,gactorine,gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorpos,-140.11,300,-203.77);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorine,-217.63,300,-128.06);
		vector(_multiplywithobjtransmat,Gactorine,Gactorine);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

		vector(_set,gactorpos,-238,300,-43.42);
		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		callsub(ElectricStrip,gactorpos,gactorine,fx_blue);
		//-------------------------------------------------------



		//Toggles between good and broken objects, and spawns particles
		//-------------------------------------------------------
		if(VarKey108==3)
		{
			CurEnvTriggerSet("s3_lab08","hide1");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			
			CurEnvTriggerSet("s3_lab08","hide2");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			
			CurEnvTriggerSet("s3_lab08","hide3");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
//			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
//			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			
			CurEnvTriggerSet("s3_lab08","hide4");
//			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
//			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
//			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
//			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			


			CurEnvTriggerSet("s3_lab08","show1");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);

			CurEnvTriggerSet("s3_lab08","show2");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);

			CurEnvTriggerSet("s3_lab08","show3");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);

			CurEnvTriggerSet("s3_lab08","show4");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			
		}
		elseif(VarKey108>3)
		{
			curenvtriggerset("s3_lab08","top");
			vector(_set,gactorpos,305.99,185,-40);
			vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
			vector(_set,tmpVector,50,50,50);
			vector(_set,gactorine,0,30,0);
			spawnparticle(fx_sparks,-1,gactorpos,Emptyvector,-1);
			spawnparticle(fx_weaponsmoke,-1,gactorpos,gactorine,fx_machinegunsmokeac);

			if(vrnd<20)
			{
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,300);	//spawnlight(name,bone,position,color,radius)
				spawnparticle(fx_impactsparks,-1,gactorpos,Emptyvector,-1);
				sample(SFXSparks,Gactorpos);
			}

			if(vrnd<45)
			{
				vector(_set,gactorpos,8997.67,3406.03,15327.08);
				vector(_set,gactorine,-5,15,6);
				spawnparticle(fx_Steam,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
				if(vrnd<15)
				{
					spawnparticle(fx_SteamPipes,-1,gactorpos,gactorine,fx_doorsteam);	//spawnparticle(particlename,bone,position,angle,color)
				}

			}
		}
		//-------------------------------------------------------
	}


	//If LabAlarm is set above 0 it will start the siren animations and run them for however
	//many frames you set LabAlarm to.  Setting it to 0 will stop the animation

	//SPAWNING WWWAAAAAYYY TOO MANY :: SFXSirenAlert
	//SPAWNING WWWAAAAAYYY TOO MANY :: SFXSirenAlert
	//SPAWNING WWWAAAAAYYY TOO MANY :: SFXSirenAlert

	//-------------------------------------------------------
	if(LabAlarm>0)
	{
		float(_sub,LabAlarm,1);

		vector(_set,tmpvector,255,0,0);
		vector(_set,tmpvector1,0,0,1);
	
		if(VSetActive=="s3_lab02")
		{
			CurEnvTriggerSet("s3_lab02","STRIG");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,8010.40,3674.00,18005.72);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
			}
		}

		if(VSetActive=="s3_lab01")
		{
			CurEnvTriggerSet("s3_lab01","STRIG1");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,5882.55,3673.50,18437.79);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}

			CurEnvTriggerSet("s3_lab01","STRIG2");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,6509.75,3673.50,17555.25);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}
		}

		if(VSetActive=="s3_lab07")
		{
/*			CurEnvTriggerSet("s3_lab07","STRIG1");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlert,-1,-1,1);
				vector(_set,Gactorpos,6217.09,3674.50,16201.00);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}*/
		}


		if(VSetActive=="s3_lab06")
		{
			CurEnvTriggerSet("s3_lab06","STRIG1");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,6818.09,3675.00,14841.78);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}
		}

		if(VSetActive=="s3_lab05")
		{
			CurEnvTriggerSet("s3_lab05","STRIG1");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,9418.29,3675.00,14548.14);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}
			CurEnvTriggerSet("s3_lab05","STRIG2");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,9056.23,3675.00,13496.34);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}
			CurEnvTriggerSet("s3_lab05","STRIG3");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,8011.19,3675.00,14259.64);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}
		}

		if(VSetActive=="s3_lab03")
		{
/*			CurEnvTriggerSet("s3_lab03","STRIG1");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlert,-1,-1,1);
				vector(_set,Gactorpos,9395.70,3675.00,17534.03);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}*/
		}


		if(VSetActive=="s3_lab04")
		{
			CurEnvTriggerSet("s3_lab04","STRIG2");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
				KfSample(-1,SFXSirenAlertSmall,-1,-1,1);
				vector(_set,Gactorpos,9795.25,3674.50,16061.78);
				SpawnLight(Lplanelight3,-1,Gactorpos,tmpvector,tmpvector1,1000);
				//sample(SFXSirenAlert,Gactorpos)
			}
		}
	}
	//END OF SIREN ANIMATION CODE
	//-------------------------------------------------------
}




//-------------------------------------------------------
//-------------------------------------------------------
//BACKGROUND TRIGGER CHECKS
//-------------------------------------------------------
//-------------------------------------------------------

SubRoutine(BackgroundTriggerChecksScene15)
{
	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel15); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(VAICon==0 && VSetActive=="s3_lab01" && VAIClass==_AIClassBeast)
	{
		//Set door lock colors
		CurEnvTriggerSet("s3_lab01","Doorup");
		float(_set,tmpfloat,0x00FF00);
		Call(Expset1,1,tmpfloat);
	}


	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel15); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////	

	if(Varbit&=Help01)
	{
		if(VAICon==0 && VAIClass==_AIClassBeast)
		{
			float(_set,Incoming,1);
			float(_set,Godtimer,0);
			float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
			float(_set,ScriptMark,11);
			callsub(Panel11);
			ClearDMessage();
			float(_clr,VarBit,Help01);
		}
	}



	if(LabAlarm>0 && VAIClass==_AIClassScientist && VAICon!=0)
	{
		callsub(Sub_CivilianReactionToThreat);
	}


	//******* EXIT THE LEVEL - LOAD THE PRIEST BOSS ARENA *************
	if(VCurSet=="s3_lab00")
	{
		if(VAICon==0 && VAIClass==_AIClassBeast)
		{
			if(HudTimer<20 || HudTimer>20)
			{
				float(_add,HudTimer,1);
			}

			CurEnvTrigger("loading");
			if(VTrigger==_DIREnvTrigger)
			{
				direction(_or,_noDIR);
				direction(_clr,_DIRForward|_DIRmove|_DIRWalking);
				if(HudTimer==20)
				{
					call(PlayerInput,0);
					CurEnvTrigger("loading");
					call(KeyObjTrigger,255,1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					float(_add,HudTimer,1);
					float(_set,varkey108,201);
				}
			}
			elseif(VarKey108<=200)
			{
				CurEnvTriggerSet("s3_lab00","loading");
				direction(_clr,_noDIR);
				direction(_or,_DIRForward|_DIRmove|_DIRWalking);
			}

			if(VKeyOBjTriggered!=0)
			{
				Camera(-250,220);
				Target(60,10);
			}
			if(HudTimer>=40)
			{
				/*
				//For gabe to play with
				if(VAction!=XXX_)
				{
					spawnaction(XXX_);
				}
				*/
			}
			if(HudTimer==400)
			{
				call(FadeToBlack,0);
			}
			elseif(HudTimer==700)
			{
				float(_set,HudTimer,0);
				actorflag(_or,_AFLAGresetfallalt);
				call(LoadLevel,-1,19,1);
			}
		}
	}
	elseif(VCurSet=="s3_lab01")
	{
		if(VAICon==0)
		{
			if(VarKey108<100)
			{
				CurEnvTrigger("plate");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VAIClass==_AIClassBeast)
					{
						CurEnvTrigger("doorup");
						callsub(DoorOpen,2,1);

						CurEnvTrigger("plate");
						float(_set,tmpfloat,0x00FF00);
						Call(Expset1,1,tmpfloat);
						message("Pressure Plate Activated",200,10);
						call(KeyObjTrigger,255,1);
						sample(SFXHatchEnd,-1);
						call(cdswap,8,0,100,60);
						float(_set,HudTimer,0);
						float(_set,VarKey108,200);
						call(PlayerInput,0);
						call(FaceTriggerDirection);
					}
					else
					{
						if(VTrigger==_DIRaction)
						{
							message("Pressure Activated Door Cannot be Operated Manually.",200,10);
							sample(SFXAccessDenied,-1);
						}
					}
				}
			}
			else
			{
/*				CurEnvTrigger("doorup");
				if(VKeyObjTriggered==0)
				{
					CurEnvTrigger("plate");
					float(_set,tmpfloat,0x00FF00);
					Call(Expset1,1,tmpfloat);
					call(cdswap,14,1,100,60);
					float(_set,VarKey108,17);
				}*/
				CurEnvTriggerSet("s3_lab00","loading");
				direction(_clr,_noDIR);
				direction(_or,_DIRForward|_DIRmove|_DIRWalking);
			}
		}
	}
	elseif(VCurSet=="s3_lab02")
	{
		CurEnvTrigger("crumple");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VarKey106==0)
		{
			CurEnvTrigger("labdoor");
			if(VKeyObjFrame==1)
			{
				CurEnvTriggerSet("s3_lab08","crumple");
				Call(KeyObjTrigger,255,1);
				kfsample(SFXRustDoorOpen,SFXRustDoorLoop,-1,SFXRustDoorClose2,1);
				//vector(_set,Gactorpos,8017,3500,17389);
				//sample(SFXRustDoorOpen,Gactorpos);
				float(_set,VarKey106,1);
				float(_set,VarKey108,6);
			}
		}
		
		if(VAICon==0)
		{
			if(Res03&!=Help01)
			{
				call(CDForcePlay,false);
				float(_or,Res03,Help01);
			}
			CurEnvTrigger("labdoor");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				if(ControlTimer==0 && VKeyObjTriggered==0)
				{
					call(ForceLoadSet,"s3_lab08");
					float(_set,ControlTimer,1);
				}
			}


			CurEnvTrigger("doorup");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(ControlTimer==0 && VKeyObjTriggered==0)
					{
						if(PowerOn==0)
						{
							call(ForceLoadSet,"s3_f1_03");
							float(_set,ControlTimer,2);
							direction(_clr,_DIRaction);
						}
					}
				}

				CurEnvTrigger("DoorUp01");
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff)
			}
			else
			{
				CurEnvTrigger("DoorUp01");
				call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff)
			}

			if(ControlTimer==1)
			{
				if(VSetInMemory=="s3_lab08")
				{
					if(VarKey108<=1)
					{
						CurEnvTriggerSet("s3_lab08","crumple");
						call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
						call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);
					}
					elseif(VarKey108==3)
					{
						vector(_set,Gactorangle,0,2048,0);
						vector(_set,Gactorpos,8006,3300,17170);
						InitActor(beast,Gactorpos,Gactorangle,"s3_lab08",TRUE,3);

						CurEnvTriggerSet("s3_lab08","crumple");
						call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
						call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);
			
						float(_set,VarKey108,4);
					}
					elseif(VarKey108>=4)
					{
						setkeyframe("s3_lab08","crumple",10);

						CurEnvTriggerSet("s3_lab08","crumple");
						call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
						call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);
					}

					CurEnvTrigger("labdoor");
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				if(VSetInMemory=="s3_lab02")
				{
					CurEnvTrigger("doorup");
					call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);

					CurEnvTrigger("doorup01");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);

					CurEnvTriggerSet("s3_f1_03","doorup");
					call(SetTriggerObjFlag,0,_clr,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_clr,_SXObjCollisionOff);

					CurEnvTriggerSet("s3_f1_03","doorup01");
					call(SetTriggerObjFlag,0,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);

					CurEnvTrigger("doorup");
					callsub(Dooropen,255,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
				}
			}
		}
	}
	elseif(VCurSet=="s3_lab04")
	{
		
		CurEnvTrigger("SeeGuy");
		if(VTrigger==_DIREnvTrigger && Undertaker==0 && VAICon==0)
		{
			float(_set,Undertaker,1);
		}
		
		CurEnvTrigger("bmin1");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassCop || VAIClass==_AIClassScientist)
			{
				float(_or,LabSecBeams,0x000010);
				sample(SFXLabGranted,-1);
			}
			else
			{
				float(_clr,LabSecBeams,0x000010);
				sample(SFXLabDenied,-1);
			}
		}
		CurEnvTrigger("bmout1");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_clr,LabSecBeams,0x000010);
			sample(SFXLabTech,-1);
		}
		CurEnvTrigger("bmat1");
		if(VTrigger==_DIREnvTrigger)
		{ 
			float(_set,tmpfloat,LabSecBeams);
			float(_and,tmpfloat,0x000010);
			if(tmpfloat==0)
			{
				float(_set,LabAlarm,1000);
				sample(SFXLabBreech,-1);
				if(VAIClass==_AIClassAngel)
				{
					sample(SFXBobTripsAlarm,-1);
				}
				sample(SFXZap02,-1);
			}
		}
	}
	elseif(VCurSet=="s3_lab4a")
	{
		if(UnderTaker==1)
		{
			state(_clr,StateExecutePathSequence);
			state(_or,StateFollowPath);
			call(ClrPath);
			spawnaction(CopKickGeneric);
			float(_add,UnderTaker,1);
		}
		elseif(UnderTaker>1 && UnderTaker<40)
		{
			float(_add,UnderTaker,1);
		}
		elseif(UnderTaker==40)
		{
			spawnaction(CopKickGeneric);
			float(_add,UnderTaker,1);
		}
		elseif(UnderTaker>40 && UnderTaker<80)
		{
			float(_add,UnderTaker,1);
		}
		elseif(UnderTaker==80)
		{
			CurEnvTrigger("corpse");
			Call(KeyObjTrigger,2,1);
//			kfsample(SFXSmlDoor,-1,-1,-1,0);
			float(_add,UnderTaker,1);
		}
		elseif(UnderTaker==81)
		{
			spawnaction(CopRepresent);
			float(_add,UnderTaker,1);
		}
		elseif(UnderTaker>81 && UnderTaker<120)
		{
			float(_add,UnderTaker,1);
		}
		elseif(UnderTaker==120)
		{
			float(_add,UnderTaker,1);
			call(ClrPath);
			callsub(Sub_AIGetBackToIdle);
			call(AIFindPathWithSpecificID,5);
		}
		
/*		if(Undertaker==1)
		{
			CurEnvTrigger("begin");
			if(VTrigger==_DIREnvTrigger)
			{
				call(AIfindpathwithspecificid,5);
				float(_set,Undertaker,2);
			}
		}
		elseif(UnderTaker==2)
		{
			CurEnvTrigger("corpse");
			if(VTrigger==_DIRAction);
			{
				call(KeyObjTrigger,2,1);
				float(_set,UnderTaker,3);
			}
		}
		elseif(UnderTaker==3)
		{
			CurEnvTrigger("begin");

			if(VTrigger==_DIREnvTrigger)
			{
				float(_set,Undertaker,0);
			}
		}*/
	}
	elseif(VCurSet=="s3_lab05")
	{
		CurEnvTrigger("comp02");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VAIClass==_AIclassscientist)
				{
					if(varkey108==1 || VarKey108>3)
					{
						if(PowerOn==1)
						{
							if(CanMakeBeast==1)
							{
								if(VAICON==0)
								{
									//float(_set,TmpFloat,0xffff00);
									//call(expset1,1,TmpFloat,0);
									call(Expset1,31,182,217);

									call(ActivateButton,"Initializing Behemoth Creation",-1,FALSE);
									call(ActivateButtonSample,SFXValidFunction);

									if(VarKey108==1)
									{
										float(_set,varkey108,2);
									}
									else
									{
										vector(_set,Gactorangle,0,2048,0);
										vector(_set,Gactorpos,8006,3300,17170);
										InitActor(beast,Gactorpos,Gactorangle,"s3_lab08",TRUE,3);
									}
									float(_set,CanMakeBeast,0);
								}
							}
							else
							{
								call(ActivateButton,"Behemoth already created.",-1,FALSE);
								call(ActivateButtonSample,SFXValidFunction);
							}
						}
						else
						{
							if(VAICON==0)
							{
								call(ActivateButton,"Insufficient power supply. Find generator to restore power",-1,FALSE);
								call(ActivateButtonSample,SFXInvalidFunction);
							}
						}
					}
					else
					{
						if(VAICON==0)
						{
							call(ActivateButton,"Behemoth Creation Already Engaged",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
						}
					}
				}
				else
				{
					if(VAICON==0)
					{
						call(ActivateButton,"Authorized Lab Staff Only",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
			}
			else
			{
				if(VAICON==0)
				{
					call(ActivateButton,"blipp...blipp...blipp.....nothing!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}
	
		CurEnvTrigger("alarm");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(VAIClass==_AIClassScientist)
			{
				float(_set,LabAlarm,1000);
				if(VAIClass==_AIClassAngel)
				{
					sample(SFXBobTripsAlarm,-1);
				}
			}
		}
		
		
		
		
		CurEnvTrigger("bmin1");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassCop || VAIClass==_AIClassScientist)
			{
				float(_or,LabSecBeams,0x000010);
				sample(SFXLabGranted,-1);
			}
			else
			{
				float(_clr,LabSecBeams,0x000010);
				sample(SFXLabDenied,-1);
			}
		}
		CurEnvTrigger("bmout1");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_clr,LabSecBeams,0x000010);
			sample(SFXLabTech,-1);
		}
		CurEnvTrigger("bmat1");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_set,tmpfloat,LabSecBeams);
			float(_and,tmpfloat,0x000010);
			if(tmpfloat==0)
			{
				float(_set,LabAlarm,1000);
				sample(SFXLabBreech,-1);
				if(VAIClass==_AIClassAngel)
				{
					sample(SFXBobTripsAlarm,-1);
				}
				sample(SFXZap02,-1);
			}
		}

		
		
		
		CurEnvTrigger("bmin2");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassCop || VAIClass==_AIClassScientist)
			{
				float(_or,LabSecBeams,0x000001);
				sample(SFXLabGranted,-1);
			}
			else
			{
				float(_clr,LabSecBeams,0x000001);
				sample(SFXLabDenied,-1);
			}
		}
		CurEnvTrigger("bmout2");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_clr,LabSecBeams,0x000001);
			sample(SFXLabTech,-1);
		}
		CurEnvTrigger("bmat2");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_set,tmpfloat,LabSecBeams);
			float(_and,tmpfloat,0x000001);
			if(tmpfloat==0)
			{
				float(_set,LabAlarm,1000);
				sample(SFXLabBreech,-1);
				if(VAIClass==_AIClassAngel)
				{
					sample(SFXBobTripsAlarm,-1);
				}
				sample(SFXZap02,-1);
			}
		}
	}
	elseif(VCurSet=="s3_lab06")
	{
		CurEnvTrigger("bmin1");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassCop || VAIClass==_AIClassScientist)
			{
				float(_or,LabSecBeams,0x000001);
				sample(SFXLabGranted,-1);
			}
			else
			{
				float(_clr,LabSecBeams,0x000001);
				sample(SFXLabDenied,-1);
			}
		}
		CurEnvTrigger("bmout1");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_clr,LabSecBeams,0x000001);
			sample(SFXLabTech,-1);
		}
		CurEnvTrigger("bmat1");
		if(VTrigger==_DIREnvTrigger)
		{ 
			float(_set,tmpfloat,LabSecBeams);
			float(_and,tmpfloat,0x000001);
			if(tmpfloat==0)
			{
				float(_set,LabAlarm,1000);

				sample(SFXLabBreech,-1);
				if(VAIClass==_AIClassAngel)
				{
					sample(SFXBobTripsAlarm,-1);
				}
				sample(SFXZap02,-1);
			}
		}
	}
	elseif(VCurSet=="s3_lab08")
	{
		CurEnvTrigger("crumple");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VarKey106==0)
		{
			call(KeyObjTrigger,255,1);
			kfsample(SFXRustDoorOpen,SFXRustDoorLoop,-1,SFXRustDoorClose2,1);
			//vector(_set,Gactorpos,8017,3500,17389);
			//sample(SFXRustDoorOpen,Gactorpos);
			float(_set,VarKey106,1);
			float(_set,VarKey108,6);
		}

		if(VAICon==0)
		{
			CurEnvTrigger("labdoor");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				if(ControlTimer==0)
				{
					call(ForceLoadSet,"s3_lab02");
					float(_set,ControlTimer,1);
				}
			}

			if(ControlTimer==1)
			{
				if(VSetInMemory=="s3_lab02")
				{
					CurEnvTrigger("labdoor");
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		
		
		if(VarKey106!=0)
		{
			//kfsample(SFXRustDoorOpen,SFXRustDoorLoop,-1,SFXRustDoorClose2,1);
/*			if(VarKey106<200)
			{
				vector(_set,Gactorpos,8017,3500,17389);
				SamplePlaying(SFXRustDoorOpen,Gactorpos);
				if(VTrigger==_DIRTempFlag)
				{
					SamplePlaying(SFXRustDoorLoop,Gactorpos);
					if(VTrigger==_DIRTempFlat)
					{
						sample(SFXRustDoorLoop,Gactorpos);
					}
				}
			}*/
			if(VarKey106==14)
			{
				if(VAIClass==_AIClassBeast)
				{
					SpawnAction(ABeastTearDoorOpen);
				}
			}
			elseif(VarKey106==80)
			{
				if(VAIClass==_AIClassBeast)
				{
					sample(SFXBehemothScream,-1);
				}
			}
			
			
/*			elseif(VarKey106==200)
			{
				vector(_set,Gactorpos,8017,3500,17389);
				SamplePlaying(SFXRustDoorLoop,Gactorpos);
				if(VTrigger==_DIRTempFlag)
				{
					samplestop(SFXRustDoorLoop,Gactorpos);
					sample(SFXRustDoorClose2,Gactorpos);
				}
			}*/
		}


		CurEnvTrigger("crumple");
		if(VKeyObjTriggered==0 && VarKey108==4)
		{
			if(VAIClass==_AIClassBeast)
			{
				ActorFlag(_or,_AFLAGnoai);
				float(_set,VarKey108,5);
			}
		}

		CurEnvTrigger("crumple");
		if(VKeyObjTriggered==0 && VarKey108==6)
		{
			if(VAIClass==_AIClassBeast)
			{
				CurEnvTrigger("crumple");
				call(SetTriggerObjFlag,0,_or,_SXObjCollisionOff);

				ActorFlag(_clr,_AFLAGnoai);
				call(AICheckForTarget,0,true);
				if(VAIHasTarget==0 && VAITargetFound!=_AIEnemy)
				{
					call(ClrPath);
					call(AIFindPathWithSpecificID,9);
				}

				float(_set,VarKey108,7);
			}
		}
		
		CurEnvTrigger("zap");
		if(VTrigger==_DIREnvTrigger)
		{
			vector(_set,TmpVector,280,40,280);
			float(_seti,TmpFloat2,VColFeetSphereSize);
			call(TriggerBox,TmpVector,TmpFloat2,TmpFloat);
			if(tmpfloat!=0)
			{
				vector(_setz,Gactorine,-1);
				vector(_setplanetrignvec,Gactorine);
				colstate(_or,_COLelectricity);
			}
		}
	}
	elseif(VCurSet=="s3_lab09")
	{
		CurEnvTrigger("deathfall");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);
		}
	}
}

