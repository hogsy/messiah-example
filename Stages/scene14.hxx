//VarKey41	- state of reactor blowout, in convier3
//				- 0 not happened yet
//				- 1 trigger explosion
//				- 2 sequence over?
//VarKey42	- 
//				- 1, trolley is moving in convier3
//				- 2, convdoor has been opened in convier3
//				- 4, box slam sample 1
//				- 8, box slam sample 2
//				- 16, load weapons factory
//VarKey43
//VarKey44
//VarKey45
//VarKey46
//VarKey47
//VarKey48
//VarKey49
//VarKey50

SubRoutine(InitSceneSound14)
{
			callsub(ScriptLevel14);

			//convier1
			vector(_set,Gactorpos,-16434,24340,20468);
			sample(SFXIndAmbient02,Gactorpos);

			//cinvier2
			vector(_set,Gactorpos,-16787,24487,18300);
			sample(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-16836,24243,18810);
			sample(SFXSewerHammer,Gactorpos);

			vector(_set,Gactorpos,-17087, 24637, 18300);
			sample(SFXScanHumm,Gactorpos);

			//convier3
			vector(_set,Gactorpos,-15300,24725,18330);
			sample(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-14410,24175,18570);
			sample(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-14410,24175,20000);
			sample(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-15230,24295,20075);
			sample(SFXShaftRotate2,Gactorpos);

			vector(_set,Gactorpos,-14072, 24514, 19691);
			sample(SFXScanHumm,Gactorpos);

			vector(_set,Gactorpos,-13018, 24208, 19198);
			sample(SFXScanHumm,Gactorpos);

			vector(_set,Gactorpos,-15401,24341,20067);
			sample(SFXShaftSpecial,Gactorpos);
			
			call(CDPlay,10,1);

}
SubRoutine(DeInitSceneSound14)
{
			//convier1
			vector(_set,Gactorpos,-16434,24340,20468);
			samplestop(SFXIndAmbient02,Gactorpos);

			//cinvier2
			vector(_set,Gactorpos,-16787,24487,18300);
			samplestop(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-16836,24243,18810);
			samplestop(SFXSewerHammer,Gactorpos);

			vector(_set,Gactorpos,-17087, 24637, 18300);
			samplestop(SFXScanHumm,Gactorpos);

			//convier3
			vector(_set,Gactorpos,-15300,24725,18330);
			samplestop(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-14410,24175,18570);
			samplestop(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-14410,24175,20000);
			samplestop(SFXIndustrial9,Gactorpos);

			vector(_set,Gactorpos,-15230,24295,20075);
			samplestop(SFXShaftRotate2,Gactorpos);

			vector(_set,Gactorpos,-14072, 24514, 19691);
			samplestop(SFXScanHumm,Gactorpos);

			vector(_set,Gactorpos,-13018, 24208, 19198);
			samplestop(SFXScanHumm,Gactorpos);

			vector(_set,Gactorpos,-15401,24341,20067);
			samplestop(SFXShaftSpecial,Gactorpos);
}


SubRoutine(InitScene14)
{
		if(VScriptInitiated!=14)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,1024,0);
				InitActor(Bob1,0,Gactorangle,"stor_04");
			}
			
			#include "messiahscripts\enemies\convey.spt"
			call(loadpreloaddb,12);
			if(Res01==0)
			{
				// Reset all the variables
				float(_set,VarKey41,0);
				float(_set,VarKey42,0);
				float(_set,VarKey43,0);
				float(_set,VarKey44,0);
				float(_set,VarKey45,0);
				float(_set,VarKey46,0);
				float(_set,VarKey47,0);
				float(_set,VarKey48,0);
				float(_set,VarKey49,0);
				float(_set,VarKey50,0);
				float(_set,AIVisionToggle,0);
			}
		}
		callsub(InitSceneSound14);
		call(ScriptCodeInitiated,14);
}

SubRoutine(MainScene14)
{
/////////////////////////
//// CONVEYER SCRIPT ////
/////////////////////////
		if(VSetActive=="Convier1")
		{
			CurEnvTriggerSet("Convier1","enemy01");
			if(VKeyObjTriggered==0)
			{
				float(_set,TmpFloat,0xff0000);
			}
			else
			{
				float(_set,TmpFloat,0xff00);
			}

			CurEnvTriggerSet("Convier1","trig2");
			call(expset1,1,TmpFloat,0);
		}

		if(VSetActive=="Convier2")
		{
			CurEnvTriggerSet("Convier2","cage04");
			call(expset1,-1400,0,2);

			call(SetParticleSetID,"Convier2");

			if(VRnd<128)
			{
				if(skipcollidecount>=5)
				{
					//	top of the vertically moving boxes
					//
					vector(_set,Gactorpos,-16675,25125,18640);
					call(CheckActorCollision,GActorpos,128,0,_COLfire);
				}

				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);

				//	top of the vertically moving boxes
				//
				vector(_set,Gactorpos,-16817,25406,18803);
				vector(_set,Gactorine,6,0,-6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-16817,25326,18803);
				vector(_set,Gactorine,6,0,-6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-16817,25242,18803);
				vector(_set,Gactorine,6,0,-6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);


				vector(_set,Gactorpos,-16860,25112,18646);
				vector(_set,Gactorine,6,-6,6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-16773,25112,18558);
				vector(_set,Gactorine,6,-6,6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-16687,25112,18473);
				vector(_set,Gactorine,6,-6,6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-16667,25112,18839);
				vector(_set,Gactorine,-6,-6,-6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-16580,25112,18751);
				vector(_set,Gactorine,-6,-6,-6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-16494,25112,18667);
				vector(_set,Gactorine,-6,-6,-6);
				SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);

				vector(_set,Gactorpos,-17130, 24540, 18447);
				vector(_set,Gactorine,-17130, 24540, 18150);
				callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
				vector(_set,TmpVector4,0,25,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
				vector(_add,Gactorpos,TmpVector4);
				vector(_add,Gactorine,TmpVector4);
				callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			}
		}
		if(VSetActive=="Convier3")
		{
			CurEnvTriggerSet("Convier3","Sensor");
			if(VarKey41==0)
			{
				float(_set,TmpFloat,0x7f0000);
			}
			else
			{
				float(_set,TmpFloat,0x7f00);
			}
			call(expset1,1,TmpFloat,0);

			call(SetParticleSetID,"Convier3");
			if(VRnd<128)
			{
				vector(_set,Gactorpos,-15448, 23281, 19429);
				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);

				if(VarKey41==0)
				{
					vector(_set,Gactorpos,-15448, 23281, 19429);
					vector(_set,Gactorine,0,10,0);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale5);
					if(skipcollidecount>=5)
					{
						call(CheckActorCollision,GActorpos,128,0,_COLfire);
					}
				}
				else
				{
					if(VCutScene==0)
					{
						float(_set,VarKey41,0);
						call(PlayerInput,1);
						vector(_set,gactorpos,-15451, 23420, 19443);
						samplestop(SFXFlamesBurning2,gactorpos);
					}
					else
					{
						float(_add,VarKey41,1);
					}

					vector(_set,Gactorpos,-15448, 23281, 19429);
					vector(_set,Gactorine,0,40,0);
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale35);
				}
			}

			if(VarKey42&=1 && VarKey42&!=2)
			{
				CurEnvTriggerSet("Convier3","trolley");
				if(VKeyObjFrame==9)
				{
					CurEnvTriggerSet("Convier3","transit");
					callsub(DoorOpen,1,1);
					float(_or,VarKey42,2);
				}
			}

			CurEnvTriggerSet("Convier3","belt01");
			//call(expset1,-1400,0,4);
			call(expset1,-3000,0,4);
			call(expset2,-1400,0,1);

			CurEnvTriggerSet("Convier3","belt02");
			call(expset1,-1400,0,2);
			//call(expset2,-1400,0,4);
			call(expset2,-3000,0,4);


			vector(_set,Gactorpos,-15285, 24553, 18477);
			vector(_set,Gactorine,-15285, 24553, 18119);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_set,TmpVector4,0,25,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);


			vector(_set,Gactorpos,-14556, 24250, 19198);
			vector(_set,Gactorine,-14261, 24250, 19198);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_set,TmpVector4,0,30,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			vector(_add,Gactorpos,TmpVector4);
			vector(_add,Gactorine,TmpVector4);
			callsub(LaserStrip,gactorpos,gactorine,fx_red,0);
			
			CurEnvTriggerSet("Convier3","belt02");
			if(VKeyObjFrame==15)
			{
				float(_clr,VarKey42,12);						//let slam sound play
			}
			elseif(VKeyObjFrame==16 && VarKey42&!=4)
			{
				float(_or,VarKey42,4);							//play only once
				vector(_set,gactorpos,-14413, 24057, 20100);
				sample(SFXBehemothLandSpecial,gactorpos);
			}
			elseif(VKeyObjFrame==18 && VarKey42&!=8)
			{
				float(_or,VarKey42,8);							//play only once
				vector(_set,gactorpos,-14413, 24301, 18299);
				sample(SFXBehemothLandSpecial,gactorpos);
			}

			if(VarKey41>=30 && VarKey41<=35)
			{
				vector(_set,Gactorpos,-15442, 23693, 19788);
				call(CheckActorCollision,GActorpos,128,0,_COLfire);
			}
		}

		if(VarKey42&=2)
		{
			if(VSetActive=="Convier4")
			{
				CurEnvTriggerSet("Convier3","trolley");
				if(VKeyObjFrame==15)
				{
					float(_or,VarKey42,16);
				}
			}
		}


		if(skipcollidecount>=5)
		{
			float(_set,skipcollidecount,0);
		}
		float(_add,skipcollidecount,1);
}






SubRoutine(BackgroundTriggerChecksScene14)
{
	
	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel14); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(VAICon==0 && VarKey42&=16)
	{
		float(_set,Res01,1);
		actorflag(_or,_AFLAGresetfallalt);
		call(LoadLevel,"fact_7",5);
	}


	if(VCurSet=="convier1")
	{
		if(VTrigger==_DIRaction && VAICon==0)
		{
			CurEnvTrigger("convtrig");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				callsub(DoorOpen,1,1);
				call(RunScriptCode,_or,18);
				Direction(_clr,_DIRaction);
			}
			if(VKeyObjTriggered==0 && VRunScriptCode==18)
			{
				call(RunScriptCode,_clr,18);
			}

			CurEnvTrigger("trig2");
			if(VTrigger==_DIREnvTrigger)
			{
				CurEnvTrigger("enemy01");
				if(VKeyObjTriggered==0)
				{
					call(ActivateButton,"door to conveyer area activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					//callsub(DoorOpen,3,1);		//maybe a 2 instead of 3
					if(VSetActive!="convier2" && ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						direction(_clr,_DIRaction);
					}
				}
				Direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("enemy01");
		if(VAICon==0 && Vtrigger==_DIREnvTrigger )
		{
			if(VKeyObjTriggered==1)
			{
				CurEnvTriggerSet("convier2","CAGE03");
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,5,1,-1);
					call(KeyObjActiveSegment,0,5);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
			}
			elseif(VTrigger==_DIRaction)
			{
				Message("Door Locked",250,10);
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("enemy01");
			if(VSetActive=="convier2")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("convier1","enemy01",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="convier2")
	{
		CurEnvTrigger("cage04");
		if(VAICon==0 && VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,5,1,-1);
			call(KeyObjActiveSegment,0,5);
			kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
		}


		CurEnvTrigger("DEATHFALL");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);
		}
		CurEnvTrigger("inciner8");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);
		}
	}
	elseif(VCurSet=="convier3")
	{
		CurEnvTrigger("Shock01");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}
		CurEnvTrigger("Shock02");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}
/*		CurEnvTrigger("Shock03");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}

		CurEnvTrigger("Shock04");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}
*/
		CurEnvTrigger("Shock05");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}
		CurEnvTrigger("Shock06");
		if(VTrigger==_DIREnvTrigger)
		{
			colstate(_or,_COLelectricity);
		}

		CurEnvTrigger("transit");
		if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0)
		{
			//callsub(DoorOpen,0,1);

			if(VSetActive!="convier4" && ControlTimer==0)
			{
				CurEnvTrigger("Trolley");
				if(VKeyObjTriggered!=0)
				{
					float(_set,ControlTimer,1);
					direction(_clr,_DIRaction);
				}
			}
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("transit");
			if(VSetActive=="convier4")
			{
				callsub(DoorOpen,0,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("convier3","transit",1);
				call(KeyObjTrigger,255,1);
			}
		}


		if(VAICon==0 && VTrigger==_DIRaction)
		{
			CurEnvTrigger("Trolley");
			if(VTrigger==_DIREnvTrigger)
			{
				call(ActivateButton,"trolley engaged",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				call(KeyObjTrigger,255,1);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				Direction(_clr,_DIRaction);
				CutScene("Camera02");
				call(ChangeCutScene,_SXCUTspeed,175);					//17.50% speed
				float(_or,VarKey42,1);
				call(PlayerInput,0);
			}

			CurEnvTrigger("Sensor");
			if(VTrigger==_DIREnvTrigger)
			{
				call(ActivateButton,"reactor discharge engaged",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				Direction(_clr,_DIRaction);
				float(_set,VarKey41,1);

				CutScene("Camera01");
				call(ChangeCutScene,_SXCUTspeed,500);					//50% speed
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(PlayerInput,0);
				vector(_set,gactorpos,-15451, 23420, 19443);
				sample(SFXFlamesBurning2,gactorpos);
			}

			CurEnvTrigger("Lifto");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,3,1);
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				Direction(_clr,_DIRaction);
			}

			CurEnvTrigger("Liftick");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,7,1);
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				Direction(_clr,_DIRaction);
			}

			float(_set,TmpFloat,0);
			if(VKeyObjFrameNoShift!=0)
			{
				float(_set,TmpFloat,1);
			}

			CurEnvTrigger("DoorSlide");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);

				if(TmpFloat==0)
				{
					callsub(DoorOpen,0,1);
				}
				else
				{
					Message("Lift Called",250,10);
					CurEnvTrigger("Liftick");
					call(KeyObjTrigger,0,-1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}

				Direction(_clr,_DIRaction);
			}

		}

		CurEnvTrigger("DEATHFALL");
		if(VTrigger==_DIREnvTrigger)
		{
			callsub(Fall2Death);
		}


		if(VAICon==0)
		{
			CurEnvTrigger("Liftick");
			if(VKeyObjTriggered!=0)
			{
				CurEnvTrigger("ElevTrig");
				vector(_set,TmpVector,140,1200,100);
				call(TriggerBox,TmpVector,0,TmpFloat);
				if(TmpFloat==1)
				{
					Camera(elevator_camera_distance,elevator_camera_angle);
					Target(elevator_camera_Tdistance,elevator_camera_Tangle);
				}
			}
		}

	}
}
