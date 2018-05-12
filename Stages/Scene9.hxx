// Club Kyd Script File
//VarBit
//------
//Help04	> Story Message #23
//Help06	> Load DB before Dance HAll

SubRoutine(InitSceneSound9)
{
		if(incoming!=0)
		{
			if(ScriptMark==23)
			{
				callsub(Panel23);
			}
		}
		else
		{
			callsub(ScriptLevel9);
		}
		call(CDPlay,15,1);
}

SubRoutine(DeInitSceneSound9)
{

}
SubRoutine(InitScene9)
{
		if(VScriptInitiated!=9)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,2048,0);
				InitActor(Bob1,0,Gactorangle,"club_ent");
			}
			call(loadpreloaddb,17);
			float(_set,VarKey1,0);
			float(_set,VarKey71,-1);  //reset door lights
			float(_set,VarKey72,0);   //timer for door lights
			float(_set,VarKey73,0);	  
			float(_set,VarKey74,0);	  
			float(_set,VarKey75,0);   
			float(_set,VarKey76,0);	  
			float(_set,VarKey77,0);  
			float(_set,VarKey78,0);	  
			float(_set,VarKey79,0);   
			float(_set,VarKey80,0);   //used for assigning new paths
			float(_set,LaserAngle1,0);
			float(_set,LaserAngle2,0);
			float(_set,DiscColor,0x000000);
			float(_set,LaserDiscColorR,0);
			float(_set,LaserDiscColorG,0);
			float(_set,LaserDiscColorB,0);
			float(_set,PowerOn,-3);
			float(_set,ColorStage,5);
			float(_set,DanceMoves,0);  //not used
			float(_set,DisablePickup,0);
			float(_set,timer2,0);
			float(_set,timer3,-1);
			float(_set,timer4,0);

			//variable for the dance sequence by Msika
			float(_set,VarBit,AllHelp);
			float(_set,DanceKey,0);
			float(_set,DanceTimer,70);
			float(_set,DanceDirection,70);
			float(_set,DanceMove,0);
			float(_set,DanceNumber,0);
			float(_set,failure,0);
			float(_set,DanceLaserPos,23391);
			float(_set,DanceLaserDir,0);

			#define DanceTimer 30		//Number of frames for dance timer


			#include "messiahscripts\enemies\C3_KYD.spt"
		}
		callsub(InitSceneSound9);
		call(ScriptCodeInitiated,9);

}
 
SubRoutine(GetMove,float(MoveNumber),float(MovesList))
{
	float(_set,tmpfloat,3);
	float(_set,tmpfloat2,MoveNumber);
	float(_mul,tmpfloat2,2);
	float(_shiftleft,tmpfloat,tmpfloat2);
	float(_and,tmpfloat,MovesList);
	float(_shiftright,tmpfloat,tmpfloat2);
}

SubRoutine(SetMove,float(MoveNumber),float(MovesList),float(Value))
{
	//Set tmpfloat2 to number for bits to shift (Movenumber * 2)
	float(_set,tmpfloat2,MoveNumber);
	float(_mul,tmpfloat2,2);
	
	//Set tmpfloat3 to all bits turned on except for desired bits
	float(_set,tmpfloat3,16777215);
	float(_set,tmpfloat,3);
	float(_shiftleft,tmpfloat,tmpfloat2);
	float(_sub,tmpfloat3,tmpfloat);
	
	//Clears out desired bits from movelist so they can be set
	float(_and,MovesList,tmpfloat3);

	//Set desired bits of MoveList to Value
	float(_set,tmpfloat,Value);
	float(_shiftleft,tmpfloat,tmpfloat2);
	float(_or,MovesList,tmpfloat);
}


SubRoutine(MainScene9)
{

	if(VSetActive=="VIP_LIFT")
	{
		CurEnvTriggerSet("vip_lift","lift");
		float(_set,TmpFloat,0x000000);  // blue-grey
		float(_set,TmpFloat2,0xffff00); // yellow
		float(_set,TmpFloat1,0xff7722);   // orange
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator
	}

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: DANCHAL1                                                   |
    //|___________________________________________________________________|
	//
	if(VSetActive=="Danchal1")
	{
		call(SetParticleSetID,"danchal1");
		// Z diff. = 370

		if(DanceSequence==0)
		{
			float(_set,TmpFloat,0x000000);
			CurEnvTriggerSet("danchal1","lite01");
			call(expset1,TmpFloat,10,-1);	
			call(expset2,TmpFloat,10,-1);	
			CurEnvTriggerSet("danchal1","lite02");
			call(expset1,TmpFloat,10,-1);	
			call(expset2,TmpFloat,10,-1);	
		}
		if(DanceSequence>=0)
		{
			if(DanceLaserDir==0)
			{
				float(_sub,DanceLaserPos,2);
				if(DanceLaserPos<=23150)
				{
					float(_set,DanceLaserDir,1);
				}
			}
			elseif(DanceLaserDir==1)
			{
				float(_add,DanceLaserPos,2);
				if(DanceLaserPos>=23650)
				{
					float(_set,DanceLaserDir,0);
				}
			}

			float(_rnd2,TmpFloat1,60);
			float(_inv,TmpFloat1);
			vector(_set,PosVector1,0,0,-30);
			vector(_set,PosVector2,0,0,-60);
			vector(_addz,PosVector2,TmpFloat1);
			vector(_set,Gactorpos,-6086,23491,13262); //extreme left on sign
			vector(_set,Gactorine,-8232,0,13600); //extreme left on wall
			vector(_sety,Gactorine,DanceLaserPos);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
			vector(_add,Gactorpos,PosVector1);
			vector(_add,Gactorine,PosVector2);
			callsub(LaserStrip,Gactorpos,Gactorine,fx_laserflickergreen,0);
	/*		
			vector(_set,Gactorpos,-6086,23491,12892); //extreme right on sign

			// Z diff. = 1437
			vector(_set,Gactorpos,-8232,23491,13801); //extreme left on wall
			vector(_set,Gactorpos,-8232,23491,12364); //extreme right on wall
	*/
		}
			
		//  resets all lights for vip access door
		//----------------------------------------------------------------
		if(VarKey71==-1)
		{
			float(_set,tmpfloat,0x222222);
		
			CurEnvTriggerset("Danchal1","lights1");
			call(expset1,1,tmpfloat,0);
			call(expset2,1,tmpfloat,0);
		
			CurEnvTriggerset("Danchal1","lights2");
			call(expset1,1,tmpfloat,0);
			call(expset2,1,tmpfloat,0);

			CurEnvTriggerset("Danchal1","lights3");
			call(expset1,1,tmpfloat,0);
			call(expset2,1,tmpfloat,0);

			CurEnvTriggerset("Danchal1","lights4");
			call(expset1,1,tmpfloat,0);
			call(expset2,1,tmpfloat,0);
	
			CurEnvTriggerset("Danchal1","lights5");
			call(expset1,1,tmpfloat,0);
			call(expset2,1,tmpfloat,0);	
	
			CurEnvTriggerset("Danchal1","lights6");
			call(expset1,1,tmpfloat,0);
			call(expset2,1,tmpfloat,0);

			float(_set,VarKey71,0);
		}
		//----------------------------------------------------------------

		
		//code for laser and laserdisc colors
		//----------------------------------------------------------------
		if(ColorStage==0)
		{
			float(_sub,LaserDiscColorB,16);
			float(_sub,DiscColor,0x000010);
			if(LaserDiscColorB<0)
			{
				float(_set,ColorStage,1);
				float(_add,LaserDiscColorB,16);
				float(_add,DiscColor,0x000010);

			}
		}
		elseif(ColorStage==1)
		{
			float(_add,LaserDiscColorG,16);
			float(_add,DiscColor,0x001000);
			if(LaserDiscColorG==256)
			{
				float(_set,ColorStage,2);
				float(_sub,LaserDiscColorG,16);
				float(_sub,DiscColor,0x001000);
			}
		}
		elseif(ColorStage==2)
		{
			float(_sub,LaserDiscColorR,16);
			float(_sub,DiscColor,0x100000);
			if(LaserDiscColorR<0)
			{
				float(_set,ColorStage,3);
				float(_add,LaserDiscColorR,16);
				float(_add,DiscColor,0x100000);
			}
		}
		elseif(ColorStage==3)
		{
			float(_add,LaserDiscColorB,16);
			float(_add,DiscColor,0x000010);
			if(LaserDiscColorB==256)
			{
				float(_set,ColorStage,4);
				float(_sub,LaserDiscColorB,16);
				float(_sub,DiscColor,0x000010);
			}
		}
		elseif(ColorStage==4)
		{
			float(_sub,LaserDiscColorG,16);
			float(_sub,DiscColor,0x001000);
			if(LaserDiscColorG<0)
			{
				float(_set,ColorStage,5);
				float(_add,LaserDiscColorG,16);
				float(_add,DiscColor,0x001000);
			}
		}
		elseif(ColorStage==5)
		{
			float(_add,LaserDiscColorR,16);
			float(_add,DiscColor,0x100000);
			if(LaserDiscColorR==256)
			{
				float(_set,ColorStage,0);
				float(_sub,LaserDiscColorR,16);
				float(_sub,DiscColor,0x100000);
			}
		}
		//----------------------------------------------------------------

		//code to draw laser disc colors
		//----------------------------------------------------------------
		CurEnvTriggerSet("DANCHAL1","LAZER1");
		call(expSet1,1,DiscColor,0);

		CurEnvTriggerSet("DANCHAL1","LAZER2");
		call(expSet1,1,DiscColor,0);
		//----------------------------------------------------------------

        //  lasers from object3
		//----------------------------------------------------------------
		vector(_set,Gactorpos,-7174.00,23290.00,13525.00)
		float(_rnd2,LaserAngle1,4096);


		float(_sin,tmpfloat2,LaserAngle1);
		float(_mul,tmpfloat2,3000);

		float(_cos,tmpfloat3,LaserAngle1);
		float(_mul,tmpfloat3,3000);

		vector(_setx,Gactorine,tmpfloat2);
		vector(_setz,Gactorine,tmpfloat3);
		vector(_sety,Gactorine,0);

		vector(_set,gactorpos,0,0,0);
		curenvtriggerset("danchal1","LAZER1");

		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		vector(_multiplywithobjtransmat,Gactorine,Gactorine);

		Collision(Gactorpos,Gactorine);
		if(VColFlag==_DIRhorcol || VColFlag==_DIRvercol)
		{
			Vector(_SetToColPos,Gactorine);
		}
		Vector(_sub,Gactorine,Gactorpos);

		call(KeyObjTrigger,255,1);
		call(SetParticleSetID,"danchal1");
		spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserdisc);
		//----------------------------------------------------------------


        // lasers from object6
		//----------------------------------------------------------------
		vector(_set,Gactorpos,-7174.00,23290.00,12615.00)
		float(_rnd2,LaserAngle1,4096);


		float(_sin,tmpfloat2,LaserAngle1);
		float(_mul,tmpfloat2,3000);

		float(_cos,tmpfloat3,LaserAngle1);
		float(_mul,tmpfloat3,3000);

		vector(_sety,Gactorine,tmpfloat2);
		vector(_setz,Gactorine,tmpfloat3);
		vector(_setx,Gactorine,0);

		vector(_set,Gactorpos,0,0,0);
		curenvtriggerset("danchal1","LAZER2");

		vector(_multiplywithobjtransmat,Gactorpos,Gactorpos);
		vector(_multiplywithobjtransmat,Gactorine,Gactorine);

		Collision(Gactorpos,Gactorine);
		if(VColFlag==_DIRhorcol || VColFlag==_DIRvercol)
		{
			Vector(_SetToColPos,Gactorine);
		}
		Vector(_sub,Gactorine,Gactorpos);

		call(KeyObjTrigger,255,1);
		call(SetParticleSetID,"danchal1");
		spawnparticle(fx_laserstrip,-1,gactorpos,gactorine,fx_laserdisc);	
		//-----------------------------------------------------------------
	}

	if(VSetActive=="club01b")  
	{
		float(_rnd2,tmpFloat,4);
		if(vrnd<20)
		{
			vector(_set,Gactorpos,-9103,21862,15145);
			vector(_set,TmpVector,-100,-100,-100);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,150);
			CurEnvTriggerSet("club01b","light");
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
		}
		else
		{
			CurEnvTriggerSet("club01b","light");
			float(_set,TmpFloat,0x777777);
			call(expset1,1,TmpFloat,0);
		}
		if(vrnd<5)
		{	
			CurEnvTriggerSet("club01b","light");
			float(_set,TmpFloat,0x000000);
			call(expset2,1,TmpFloat,0);
			vector(_set,Gactorpos,-9333,22092,14471);
			vector(_set,TmpVector,-100,-100,-100);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,150);
		}
		else
		{
			CurEnvTriggerSet("club01b","light");
			float(_set,TmpFloat,0x777777);
			call(expset2,1,TmpFloat,0);
		}
		CurEnvTriggerSet("club01b","c01bv01a");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("club01b","c01bc01y");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//-----------------------------------------------------------------

	if(VSetActive=="club01v")  
	{
		CurEnvTriggerSet("club01v","c01vc01a");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//-----------------------------------------------------------------

	if(VSetActive=="club01y")  
	{
		CurEnvTriggerSet("club01y","c01bc01y");
		float(_set,tmpfloat,0xFF0000);			
		call(expSet1,1,tmpfloat,0);
	}
	//-----------------------------------------------------------------
	if(VSetActive=="vip01a")  
	{
		CurEnvTriggerSet("vip01a","V01AV01B");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);

	}
	//-----------------------------------------------------------------

	if(VSetActive=="vip02a")
	{
		CurEnvTriggerSet("vip02a","lft-v02a");
		float(_set,tmpfloat,0xFF0000); //set lights to red
		call(expSet1,1,tmpfloat,0);
	}
	//-----------------------------------------------------------------
	if(VsetActive=="vip02d")
	{
		CurEnvTriggerSet("vip02d","enter");
		float(_set,tmpfloat,0xFF0000);
		call(expSet1,1,tmpfloat,0);
	}
	//-----------------------------------------------------------------

	if(VCurSet=="club01b")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("club01b","C01BC01Y");
			if(VSetActive=="club01y")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club01b","C01BC01Y",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("club01b","C01BV01A");
			if(VSetActive=="vip01a")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club01b","C01BV01A",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="club01v")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("club01v","c01vc01a");
			if(VSetActive=="club01a")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club01v","c01vc01a",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip01b")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip01b","V01AV01B");
			if(VSetActive=="vip01a")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01b","V01AV01B",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip01b","V01BV01D");
			if(VSetActive=="vip01d")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01b","V01BV01D",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==3)
		{
			CurEnvTriggerSet("vip01b","V01BDE1");
			if(VSetActive=="dnc_ent1")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01b","V01BDE1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip01c")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip01c","V01AV01C");
			if(VSetActive=="vip01a")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01C","V01AV01C",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip01c","V01CV01D");
			if(VSetActive=="vip01d")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01C","V01CV01D",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	if(VCurSet=="danchal1")  //mainscene
	{
		if(ControlTimer==2)
		{
			CurEnvTriggerSet("danchal1","eledoor");
			if(VSetActive=="VIP_LIFT")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("danchal1","eledoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="Club_Ent")  //mainscene
	{
		CurEnvTriggerSet("Club_Ent","CENTC01Y");
		if(VTrigger==_DIREnvTrigger)
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
			CurEnvTriggerSet("Club_Ent","CENTC01Y");
			if(VSetActive=="club01y")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club_ent","CENTC01Y",1);
				call(KeyObjTrigger,255,1);
			}
		}
		
		CurEnvTriggerSet("club_ent","CENTC01x");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VKeyObjTriggered==0 && ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(ControlTimer==2)
		{
			CurEnvTriggerSet("Club_Ent","CENTC01x");
			if(VSetActive=="club01x")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club_ent","CENTC01x",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip01a")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip01a","V01AV01B");
			if(VSetActive=="vip01b")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01a","V01AV01B",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip01a","V01AV01C");
			if(VSetActive=="vip01c")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01a","V01AV01C",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==3)
		{
			CurEnvTriggerSet("vip01a","C01BV01A");
			if(VSetActive=="club01b")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01a","C01BV01A",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="dnc_ent2")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("DE2DH1");
			if(VSetActive=="Danchal1")
			{
				if(VarBit&=Help06)
				{
					dmessage("L O A D I N G . . .",50,2);
					call(LoadPreLoadDB,18);
					float(_clr,VarBit,Help06);
				}
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("Dnc_Ent2","DE2DH1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip01d")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip01d","V01BV01D");
			if(VSetActive=="vip01b")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01d","V01BV01D",1);
				call(KeyObjTrigger,255,1);
			}
		}

		if(ControlTimer==2)
		{
			CurEnvTriggerSet("vip01c","V01CV01D");
			if(VSetActive=="vip01c")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip01d","V01CV01D",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="club01a")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("club01a","C01VC01A");
			if(VSetActive=="club01v")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club01a","C01VC01A",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="club01x")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("club01x","CENTC01X");
			if(VSetActive=="club_ent")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club01x","CENTC01X",1);
				call(KeyObjTrigger,255,1);
			}
		}	
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="club01y")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("club01y","C01BC01Y");
			if(VSetActive=="club01b")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club01y","C01BC01Y",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("club01y","CENTC01Y");
			if(VSetActive=="club_ent")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("club01y","CENTC01Y",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="dnc_ent1")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("dnc_ent1","V01BDE1");
			if(VSetActive=="vip01b")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("dnc_ent1","V01BDE1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip_lift") //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip_lift","lft-v02a");
			if(VSetActive=="vip02a")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip_lift","lft-v02a",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip_lift","lft-dnchl");
			if(VSetActive=="danchal1")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip_lift","lft-dnchl",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip02a")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip02a","V02AV02B");
			if(VSetActive=="vip02b")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02a","V02AV02B",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip02a","V02AV02C");
			if(VSetActive=="vip02c")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02a","V02AV02C",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip02b")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip02b","V02AV02B");
			if(VSetActive=="vip02a")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02b","V02AV02B",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip02b","V02BV02D");
			if(VSetActive=="vip02d")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02b","V02BV02D",1);
				call(KeyObjTrigger,255,1);
			}
		}	
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip02c")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip02c","V02AV02C");
			if(VSetActive=="vip02a")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02c","V02AV02C",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip02c","V02CV02D");
			if(VSetActive=="vip02d")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02c","V02CV02D",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------

	elseif(VCurSet=="vip02d")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("vip02d","V02BV02D");
			if(VSetActive=="vip02b")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02d","V02BV02D",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("vip02d","V02CV02D");
			if(VSetActive=="vip02c")
			{
				callsub(DoorOpen,4,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("vip02d","V02CV02D",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//-----------------------------------------------------------------
//-----------------------------------------------------------------	
}
//-----------------------------------------------------------------


SubRoutine(BackgroundTriggerChecksScene9)
{
	print("dancesequence : ",dancesequence);
	print("dancenumber   : ",dancenumber);
	print("dancekey      : ",dancekey);
	print("failure       : ",failure);
	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel9); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: CLUB_ENT                                                   |
    //|___________________________________________________________________|
	//
	if(Vcurset=="CLUB_ENT")
	{
		print("Scriptmark ",scriptmark);
		if(VAICon==0)
		{
			if(VarBit&=Help04)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,23);
				callsub(Panel23);
				float(_clr,VarBit,Help04);
			}
		}

		CurEnvTrigger("enter");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Locked",120,10);
			sample(SFXPlayerActivatesLockedDoorReact,-1);
		}
		if(VKeyObjTriggered==0)
		{
			if(VRunScriptCode==16)
			{
				callsub(DeInitSceneSound16);
				call(RunScriptCode,_clr,16);
			}
			float(_set,TmpFloat,0xff0000);
			call(expset1,1,TmpFloat,0);
		}
	}
	//---------------------------------------------


	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: CLUB01A                                                    |
    //|___________________________________________________________________|
	//

	if(Vcurset=="CLUB01A")  //bt check
	{
		CurEnvTrigger("C01VC01A");	
		if(VKeyObjTriggered==0 && Vtrigger==_DIREnvTrigger && Vtrigger==_DIRAction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("newpath");
		if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassBarPeople|_AIClassFemale && VRank==_RankScum && varkey80==1)
		{
			call(AIfindpathwithspecificid,46);
			float(_set,varkey80,2);
		}

		//spawn waitress
		if(VAICon==0 && VActiveTime!=0)
		{
			float(_set,TmpFloat,0);
			GetNumbActorsInSet("club01a",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
			if(TmpFloat==0)
			{
				GetNumbActorsInSet("club01v",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
				if(TmpFloat==0)
				{
					GetNumbActorsInSet("club01x",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
					if(TmpFloat==0)
					{
						GetNumbActorsInSet("club01x",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
						if(TmpFloat==0)
						{
							GetNumbActorsInSet("club01z",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
							if(TmpFloat==0)
							{
								GetNumbActorsInSet("club01w",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
								if(TmpFloat==0)
								{
									GetNumbActorsInSet("club01y",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);	
									if(TmpFloat==0)
									{
										GetNumbActorsInSet("club_ent",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
										if(TmpFloat==0)
										{
											GetNumbActorsInSet("club01b",_AIclassbarpeople,TmpFloat,0,_Equal,_RankScum);
											if(TmpFloat==0)
											{
												float(_set,varkey80,0);
												vector(_set,Gactorpos,-6927.07,21450.00,13440.55);
												vector(_set,Gactorangle,0,0,0);
												InitActor(nun,Gactorpos,Gactorangle,"club01z",TRUE,42);
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
		//---------------------------------------------

	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: CLUB01B                                                    |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="CLUB01B")  //bt check
	{
		CurEnvTrigger("C01BC01Y");
		if(VKeyObjTriggered==0 && Vtrigger==_DIREnvTrigger && Vtrigger==_DIRAction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("C01BV01A");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: CLUB01V                                                    |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="CLUB01V")  //bt check
	{
		CurEnvTrigger("C01VC01A");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassBarPeople|_AIClassFemale && VAICon!=0)
			{
				if(ControlTimer==0 && VKeyObjTriggered==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			elseif(VTrigger==_DIRAction)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		
		CurEnvTrigger("newpath");
		if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassBarPeople|_AIClassFemale && VRank==_RankScum && varkey80==0)
		{
			call(AIfindpathwithspecificid,45);
			float(_set,varkey80,1);
		}	
	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: CLUB01X                                                    |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="CLUB01X")  //bt check
	{
		CurEnvTrigger("CENTC01X");
		if(Vtrigger==_DIREnvTrigger && VAICon==0)
		{
			if(ControlTimer==0 && VKeyObjTriggered==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: CLUB01Y                                                    |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="CLUB01Y")  //bt check
	{
		CurEnvTrigger("C01BC01Y");
		if(Vtrigger==_DIREnvTrigger && VAIClass==_AIClassBarPeople && VRank==_RankScum)
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);

			if(Vtrigger==_DIRAction)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		elseif(VTrigger==_DIREnvTrigger && VTRigger==_DIRAction)
		{
			message("Bar Personnel Only",120,10);
			sample(SFXPlayerActivatesLockedDoorReact,-1);
		}
	
		CurEnvTrigger("CENTC01Y");
		if(Vtrigger==_DIREnvTrigger && VAICon==0 && VKeyObjTriggered==0)
		{	
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}	
		}
	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: CLUB01Z                                                    |
    //|___________________________________________________________________|
	//
	elseif(VCurSet=="club01z")
	{
//		CurEnvTrigger("no_ai");
//		if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIClassDweller && VAIState!=_AIstateDweller3sitting)
//		{
//			spawnaction(dweller3sitting);
//		}
	}
	//---------------------------------------------
			
	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP01A                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP01A")  //bt check
	{
		if(VAICon==0)
		{
			CurEnvTrigger("C01BV01A");		
			if(Vtrigger==_DIREnvTrigger)
			{
				if(VAIClass==_AIClassBarPeople && VRank==_RankScum)
				{
					float(_set,tmpfloat,0x00FF00);  //change lights to green
					call(expSet1,1,tmpfloat,0);

					if(Vtrigger==_DIRAction )
					{
						if(ControlTimer==0)
						{
							float(_set,ControlTimer,3);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
						}
					}
				}
				else
				{
					if(VTrigger==_DIRaction)
					{
						message("Bar Personnel Only",120,10);
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}
				}
			}
			else
			{
				float(_set,TmpFloat,0xff0000);
				call(Expset1,1,Tmpfloat,0);
			}
		}	
		
		CurEnvTrigger("V01AV01B");
		if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("V01AV01C"); 
		if(VTrigger==_DIREnvTrigger  && VKeyObjTriggered==0)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP01B                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP01B")  //bt check
	{
		CurEnvTrigger("no_ai1");
		if(VTrigger==_DirEnvTrigger && VAIClass==_AIClassDweller && VAIState!=_AIstateDweller2sitting && VAICon!=0 && VFrame==1)
		{
			ActorFlag(_or,_AFLAGnoai);
			spawnaction(dweller2sitting);
		}

		CurEnvTrigger("no_ai2");
		if(VTrigger==_DirEnvTrigger && VAIClass==_AIClassDweller && VAIState!=_AIstateDweller1sitting && VAICon!=0 && VFrame==1)
		{
			ActorFlag(_or,_AFLAGnoai);
			spawnaction(dweller1sitting);
		}

		CurEnvTrigger("no_ai3");
		if(VTrigger==_DirEnvTrigger && VAIClass==_AIClassDweller && VAIState!=_AIstateDweller3sitting && VAICon!=0 && VFrame==1)
		{
			ActorFlag(_or,_AFLAGnoai);
			spawnaction(dweller3sitting);
		}
		

		CurEnvTrigger("V01AV01B");
		if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("V01BV01D");
		if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(VAIcon==0)
		{
			CurEnvTrigger("V01BDE1");
			if(Vtrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(VAIClass==_AIclassbarpeople && VRank==_RankPrivate)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,3);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				elseif(VarBit&=Help05)
				{
					message("Only Dancers Beyond That Point",120,10);
					float(_clr,VarBit,Help05);
				}
			}
			else
			{
				float(_or,VarBit,Help05);
			}
		}
	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP01C                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP01C")  //bt check
	{
		if(VAICon!=0)
		{
			CurEnvTrigger("no_ai1");
			if(VTrigger==_DirEnvTrigger && VAIClass==_AIClassDweller && VAIState!=_AIstateDweller1Sitting && VFrame==1)
			{
				ActorFlag(_or,_AFLAGnoai);
				spawnaction(dweller1sitting);
			}

			CurEnvTrigger("no_ai3");
			if(VTrigger==_DirEnvTrigger && VAIClass==_AIClassBarPeople && VAIState!=_AIstateDweller3sitting && VFrame==1)
			{
				ActorFlag(_or,_AFLAGnoai);
				spawnaction(dweller3sitting);
			}
			CurEnvTrigger("newpath");
			if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassBarPeople && VRank==_RankCommander && varkey80==0)
			{
				if(varkey80==0)
				{
					call(AIfindpathwithspecificid,43);	
					float(_set,varkey80,1);
				}
			}
		}
		else
		{
			CurEnvTrigger("V01AV01C");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("V01CV01D");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("V01CVB01");
			if(VTrigger==_DIREnvTrigger) 
			{
				if(VAIClass==_AIClassMale)
				{
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
					if(VTrigger==_DIRAction)
					{
						callsub(DoorOpen,2,1);
					}
				}
				else
				{
					if(Vtrigger==_DIRaction)
					{
						message("Men only",120,10);
						direction(_clr,_DIRaction);			
					}
				}
			}
			else
			{
				float(_set,TmpFloat,0xff0000);
				call(expset1,1,TmpFloat,0);
			}

			CurEnvTrigger("V01CVB02")
			if(VTrigger==_DIREnvTrigger) 
			{
				if(VAIClass==_AIClassFemale)
				{
					float(_set,TmpFloat,0x00ff00);
					call(expset1,1,TmpFloat,0);
					if(VTrigger==_DIRAction)
					{
						callsub(DoorOpen,2,1);
					}
				}
				else
				{
					if(Vtrigger==_DIRaction)
					{
						message("Women only",120,10);
						direction(_clr,_DIRaction);			
					}
				}
			}
			else
			{
				float(_set,TmpFloat,0xff0000);
				call(expset1,1,TmpFloat,0);
			}
		}
	}
	//---------------------------------------------


	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP01D                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP01D")  //bt check
	{
		
		if(VAICon==0)
		{
			GetNumbActorsInSet("vip01a",_AIclassFemale,TmpFloat,0)
			if(TmpFloat==0)
			{
				GetNumbActorsInSet("vip01b",_AIclassFemale,TmpFloat,0)
				if(TmpFloat==0)
				{
					GetNumbActorsInSet("vip01c",_AIclassFemale,TmpFloat,0)
					if(TmpFloat==0)
					{
						GetNumbActorsInSet("vip01d",_AIclassFemale,TmpFloat,0)
						if(TmpFloat==0)
						{
							vector(_set,Gactorpos,-7634,22048,14059);
							vector(_set,Gactorangle,0,-1024,0);
							InitActor(FemDweller1,Gactorpos,Gactorangle,"Vip01a",False,0);
						}
					}
				}
			}
		}
		

		if(VAICon==0)
		{
			float(_add,StrobeTimer,1);
			if(StrobeTimer<20)
			{
				CurEnvTrigger("V01CV01D");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			}
			elseif(StrobeTimer>=20 && StrobeTimer<=80)
			{
				if(StrobeTimer&=2)
				{
					vector(_set,Gactorpos,-7785,22394,12071);
					vector(_set,tmpvector,255,255,255);
					SpawnLight(flash_light,-1,gactorpos,tmpvector,EmptyVector,500);

			//		call(wCheckViewCollision,0,0,-2,-1);
					CurEnvTrigger("V01CV01D");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				}
				else
				{
					CurEnvTrigger("V01CV01D");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				}
			}
			elseif(StrobeTimer==82)
			{
				float(_set,StrobeTimer,0);
			}
			CurEnvTrigger("V01BV01D"); 
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0);
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("V01CV01D");
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
	}
	//---------------------------------------------

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP1_B01                                                   |
    //|___________________________________________________________________|
	//
	elseif(VCurSet=="vip1_b01")  //bt check
	{
		if(VAICon==0)
		{
			CurEnvTrigger("V01CVB01");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				callsub(DoorOpen,2,1);
			}
		}
	}
	//---------------------------------------------


	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP1_B02                                                   |
    //|___________________________________________________________________|
	//
	elseif(VCurset=="vip1_b02")  //bt check
	{
		CurEnvTrigger("toilet1");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				call(ActivateButton,0,-1,FALSE);
			}
			if(VState==StateJustActivated)
			{
				sample(SFXToiletFlush1,-1);
			}
		}
		CurEnvTrigger("toilet2");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				call(ActivateButton,0,-1,FALSE);
			}
			if(VState==StateJustActivated)
			{
				sample(SFXToiletFlush2,-1);
			}
		}
		CurEnvTrigger("toilet3");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				call(ActivateButton,0,-1,FALSE);
			}
			if(VState==StateJustActivated)
			{
				sample(SFXToiletFlush3,-1);
			}
		}
		//spawn dancer
		if(VAICon==0 && VActiveTime!=0)
		{
			float(_set,TmpFloat,0);
			GetNumbActorsInSet("vip01a",_AIclassprost,TmpFloat,0,_Equal,_RankPrivate);
			if(TmpFloat==0)
			{
				GetNumbActorsInSet("vip01b",_AIclassprost,TmpFloat,0,_Equal,_RankPrivate);
				if(TmpFloat==0)
				{
					GetNumbActorsInSet("vip01c",_AIclassprost,TmpFloat,0,_Equal,_RankPrivate);
					if(TmpFloat==0)
					{
						GetNumbActorsInSet("vip01d",_AIclassprost,TmpFloat,0,_Equal,_RankPrivate);
						if(TmpFloat==0)
						{
							GetNumbActorsInSet("vip1_b01",_AIclassprost,TmpFloat,0,_Equal,_RankPrivate);
							if(TmpFloat==0)
							{
								GetNumbActorsInSet("vip1_b02",_AIclassprost,TmpFloat,0,_Equal,_RankPrivate);
								if(TmpFloat==0)
								{
									float(_set,varkey80,0);
									vector(_set,Gactorpos,-8244.38,22050.00,12223.80);
									vector(_set,Gactorangle,0,0,0);
									InitActor(dancer1,Gactorpos,Gactorangle,"vip01d",TRUE,42);
								}
							}
						}
					}
				}
			}						
		}
		//---------------------------------------------

	 	CurEnvTrigger("V01CVB02");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			callsub(DoorOpen,2,1);
		}
		CurEnvTrigger("newpath");
		if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIClassBarPeople && VRank==_RankCommander && varkey80==1)
		{
			call(AIfindpathwithspecificid,44);
			float(_set,varkey80,2);
		}

	}
	//--------------------------------------------------------------------


	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: DNC_ENT1                                                   |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="DNC_ENT1")  //bt check
	{
		if(VAICon==0)
		{
			if(VActorFlag==_AFLAGNoDepossession);
			{
					ActorFlag(_clr,_AFLAGNoDepossession);
			}				

			CurEnvTrigger("V01BDE1");
			if(Vtrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{	
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}			
			}
		}
	}


	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: DNC_ENT2                                                   |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="DNC_ENT2")
	{	
		if(VAICon==0)
		{
			call(cdswap,16,1,100,60);

			CurEnvTrigger("DE2DH1");
			if(VKeyObjTriggered==0)
			{
				ActorFlag(_clr,_AFLAGNoDepossession);
			}
			else
			{
				ActorFlag(_or,_AFLAGNoDepossession);
			}				
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass==_AIclassbarpeople && VRank==_RankPrivate)
				{
					if(VKeyObjTriggered==0 && ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					if(VTrigger==_DIRaction)
					{
						message("Only Dancers Beyond That Point",120,10);
						direction(_clr,_DIRaction);
					}
				}
			}
		}
	}

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: DANCHAL1                                                   |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="DANCHAL1")  //bt check
	{
		if(VAICon==0)
		{
			CurEnvTrigger("entrance");
			if(VTrigger==_DIREnvTrigger)
			{
				call(FaceTriggerDirection);
			}
			if(DanceSequence==0)
			{
				call(AutoTesselation,false);
				CurEnvTrigger("entrance");
				if(VTrigger==_DIREnvTrigger)
				{
					call(PlayerInput,0);
					CutScene("First");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
					SetActorToTrigger("danchal1","entrance");
					call(FaceTriggerDirection);
					float(_set,DanceSequence,1);
				}
			}
			elseif(DanceSequence==1)
			{
				direction(_clr,_noDIR);
				direction(_or,_DIRForward|_DIRmove|_DIRWalking);
				CurEnvTrigger("secsplit");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_set,DanceSequence,2);
				}
			}
			elseif(DanceSequence==2)
			{
				CurEnvTrigger("secsplit");
				CutScene("second");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				call(KeyObjTrigger,255,1);
				float(_set,DanceSequence,3);
			}
			elseif(DanceSequence==3)
			{
				CurEnvTrigger("secsplit");
				if(VKeyObjTriggered==0)
				{
					SetActorToTrigger("danchal1","pos");
					CurEnvTrigger("pos");
					call(FaceTriggerDirection);
					CutScene("camera02");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
					float(_set,DanceSequence,4);
				}
			}
			elseif(DanceSequence==4)
			{
				if(VCutScene!=0)
				{
					if(VCutSceneFrame==10)
					{
						float(_set,DanceSequence,5);
						ClearTutorialLines();
						AddTutorialLine("Hosted by DJ Kyd@ the Dance Contest");
						AddTutorialLine("allows you to go into the VIP lounge");
						AddTutorialLine("of the club.");
						AddTutorialLine(" ");
						AddTutorialLine("Just follow the sequence of the DJ");
						AddTutorialLine("to perform a perfect dance number.");
						AddTutorialLine("Whenever an arrow is lit@ press the");
						AddTutorialLine("corresponding direction button. The");
						AddTutorialLine("longer you last@ the faster the sequence...");
						AddTutorialLine(" ");
						AddTutorialLine("    [255:255:0]             Press Any Key       ");
						AddTutorialLine("    [255:255:0]             To Continue         ");
						DisplayTutorialScreen("[255:255:20]Dance Contest",15,15);
						SetActorToTrigger("danchal1","pos");
					}
				}
			}
			elseif(DanceSequence==5)
			{
				call(PlayerInput,1);
				CutScene("contest");
				call(ChangeCutScene,_SXCUTflag,_clr,_SXCUTnosmooth);
				sample(SFXAreYouReady,-1);
				dmessage("Press your Action button to start",50,500);
				float(_set,DanceSequence,6);
			}
			elseif(DanceSequence==6)
			{
				direction(_clr,_DIRMovebits|_DIRShoot|_DIRLeft|_DIRright|_DIRJump);
				if(VTrigger==_DIRaction)
				{
					ClearDMessage();
					spawnaction(DanceIdle);
					float(_set,DanceSequence,7);
					float(_clr,VarBit,Help01);
				}
			}
			elseif(DanceSequence>6 && DanceSequence<11)
			{
				direction(_clr,_DIRMovebits|_DIRShoot|_DIRLeft|_DIRright|_DIRJump);
			}
			if(VarBit&!=Help01 && DanceSequence==7)
			{
				SetActorToTrigger("danchal1","pos");
				if(DanceNumber==10 && ODanceNumber!=10)
				{
					sample(SFXDoingGood1,-1);
					float(_set,ODanceNumber,10);
				}
				elseif(DanceNumber==20 && ODanceNumber!=20)
				{
					float(_set,ODanceNumber,20);
					sample(SFXDoingGood2,-1);
				}
				elseif(DanceNumber==30 && ODanceNumber!=30)
				{
					float(_set,ODanceNumber,30);
					sample(SFXDoingGood3,-1);
				}
				elseif(DanceNumber==35 && ODanceNumber!=35)
				{
					float(_set,ODanceNumber,35);
					sample(SFXDoingGood4,-1);
				}
				if(DanceKey==0)
				{
					call(ToggleKey,KEY_RIGHT);
					call(ToggleKey,KEY_UP);
					call(ToggleKey,KEY_DOWN);
					call(ToggleKey,KEY_LEFT);
//					call(PlayerInput,0);
					float(_set,DanceKey,1);
					float(_set,DanceDirection,50); // start with 1.8 second delay to press the key
				}
				elseif(DanceKey==1)
				{
					if(DanceNumber<5)
					{
						if(VDifficulty==_DifficultyEasy)
						{
							float(_set,DanceDirection,50); 
						}
						elseif(VDifficulty==_DifficultyMedium)
						{
							float(_set,DanceDirection,45); 
						}
						elseif(VDifficulty==_DifficultyHard)
						{
							float(_set,DanceDirection,45); 
						}
					}
					elseif(DanceNumber<10)
					{
						if(VDifficulty==_DifficultyEasy)
						{
							float(_set,DanceDirection,44); 
						}
						elseif(VDifficulty==_DifficultyMedium)
						{
							float(_set,DanceDirection,40); 
						}
						elseif(VDifficulty==_DifficultyHard)
						{
							float(_set,DanceDirection,40); 
						}
					}
					elseif(DanceNumber<15)
					{
						if(VDifficulty==_DifficultyEasy)
						{
							float(_set,DanceDirection,35); 
						}
						elseif(VDifficulty==_DifficultyMedium)
						{
							float(_set,DanceDirection,34); 
						}
						elseif(VDifficulty==_DifficultyHard)
						{
							float(_set,DanceDirection,33); 
						}
					}
					elseif(DanceNumber<20)
					{
						if(VDifficulty==_DifficultyEasy)
						{
							float(_set,DanceDirection,30); 
						}
						elseif(VDifficulty==_DifficultyMedium)
						{
							float(_set,DanceDirection,29); 
						}
						elseif(VDifficulty==_DifficultyHard)
						{
							float(_set,DanceDirection,28); 
						}
					}
					elseif(DanceNumber<32)
					{
						if(VDifficulty==_DifficultyEasy)
						{
							float(_set,DanceDirection,26); 
						}
						elseif(VDifficulty==_DifficultyMedium)
						{
							float(_set,DanceDirection,24); 
						}
						elseif(VDifficulty==_DifficultyHard)
						{
							float(_set,DanceDirection,22); 
						}
					}
					else
					{
						if(VDifficulty==_DifficultyEasy)
						{
							float(_set,DanceDirection,23); 
						}
						elseif(VDifficulty==_DifficultyMedium)
						{
							float(_set,DanceDirection,22); 
						}
						elseif(VDifficulty==_DifficultyHard)
						{
							float(_set,DanceDirection,17); 
						}
					}

					CurEnvTrigger("lite01");
					call(expset1,TmpFloat,10,-1);	
					call(expset2,TmpFloat,10,-1);	
					CurEnvTrigger("lite02");
					call(expset1,TmpFloat,10,-1);	
					call(expset2,TmpFloat,10,-1);	
					if(DanceTimer>7)
					{
						float(_sub,DanceTimer,2);
					}
//					float(_set,DanceDirection,DanceTimer);
					if(DanceNumber<42)
					{
						float(_rnd2,DanceMove,4);
						float(_round,DanceMove);
						if(DanceMove!=OldDanceMove)
						{
							float(_set,DanceKey,2);
							float(_add,DanceNumber,1);
						}
					}
					else
					{
						float(_set,DanceKey,4);
					}
				}
				elseif(DanceKey==2)
				{
					vector(_set,Gactorpos,-6216,23140,13079);
					float(_set,TmpFloat1,0x2255ff);
					if(DanceMove==1) //UP
					{
						float(_set,OldDanceMove,1);
					//	sample(SFXDanceUp1,Gactorpos);
						float(_set,TmpFloat,0xffffff);
						CurEnvTrigger("rarrow2");
						call(expset1,1,TmpFloat,0);
						float(_set,TmpFloat,0x000000);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("rarrow3");
						call(expset1,1,TmpFloat,0);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("lite01");
						call(expset1,TmpFloat1,150,-1);	
					}
					elseif(DanceMove==2) //DOWN
					{
						float(_set,OldDanceMove,2);
					//	sample(SFXDanceDown1,Gactorpos);
						float(_set,TmpFloat,0xffffff);
						CurEnvTrigger("rarrow2");
						call(expset2,1,TmpFloat,0);
						float(_set,TmpFloat,0x000000);
						call(expset1,1,TmpFloat,0);
						CurEnvTrigger("rarrow3");
						call(expset1,1,TmpFloat,0);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("lite01");
						call(expset2,TmpFloat1,150,-1);	
					}
					elseif(DanceMove==3) //RIGHT
					{
						float(_set,OldDanceMove,3);
					//	sample(SFXDanceRight1,Gactorpos);
						float(_set,TmpFloat,0xffffff);
						CurEnvTrigger("rarrow3");
						call(expset1,1,TmpFloat,0);
						float(_set,TmpFloat,0x000000);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("rarrow2");
						call(expset1,1,TmpFloat,0);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("lite02");
						call(expset1,TmpFloat1,150,-1);	
					}
					elseif(DanceMove==4) //LEFT
					{
						float(_set,OldDanceMove,4);
					//	sample(SFXDanceLeft1,Gactorpos);
						float(_set,TmpFloat,0xffffff);
						CurEnvTrigger("rarrow3");
						call(expset2,1,TmpFloat,0);
						float(_set,TmpFloat,0x000000);
						call(expset1,1,TmpFloat,0);
						CurEnvTrigger("rarrow2");
						call(expset1,1,TmpFloat,0);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("lite02");
						call(expset2,TmpFloat1,150,-1);	
					}
					float(_set,DanceKey,3);
				}
				elseif(DanceKey==3)
				{
					float(_sub,DanceDirection,1);
					if(DanceDirection>0)
					{
						if(DanceNumber<5)
						{
							float(_set,TmpFloat,0x00aa00);
						}
						elseif(DanceNumber<10)
						{
							float(_set,TmpFloat,0x00bb00);
						}
						elseif(DanceNumber<15)
						{
							float(_set,TmpFloat,0x00cc00);
						}
						elseif(DanceNumber<20)
						{
							float(_set,TmpFloat,0x00dd00);
						}
						elseif(DanceNumber<32)
						{
							float(_set,TmpFloat,0x00ee00);
						}
						else
						{
							float(_set,TmpFloat,0x00ff00);
						}
						if(VarBit&=Help02)
						{
							if(DanceMove==1)
							{
								if(VKey==KEY_UP || VTrigger==_DIRForward)
								{
									spawnaction(DanceUp);
									CurEnvTrigger("rarrow4");
									call(expset1,1,TmpFloat,0);
									float(_clr,VarBit,Help02);
									CurEnvTrigger("lite01");
									call(expset1,TmpFloat,150,-1);	
								}
								elseif(VKEY==KEY_DOWN || VKEY==KEY_RIGHT || VKEY==KEY_LEFT || VTrigger==_DIRBackward || VTrigger==_DIRRight|| VTrigger==_DIRLeft)
								{
									float(_set,TmpFloat,0xff0000);
									CurEnvTrigger("rarrow4");
									call(expset1,1,TmpFloat,0);
									CurEnvTrigger("lite01");
									call(expset1,TmpFloat,150,-1);	
									float(_clr,VarBit,Help02);
									float(_clr,VarBit,Help03);
								}
							}
							elseif(DanceMove==2)
							{
								if(VKEY==KEY_DOWN || VTrigger==_DIRBackward)
								{
									spawnaction(DanceDown);
									CurEnvTrigger("rarrow4");
									call(expset2,1,TmpFloat,0);
									CurEnvTrigger("lite01");
									call(expset2,TmpFloat,150,-1);	
									float(_clr,VarBit,Help02);
								}
								elseif(VKEY==KEY_LEFT || VKEY==KEY_RIGHT || VKEY==KEY_UP || VTrigger==_DIRForward || VTrigger==_DIRRight|| VTrigger==_DIRLeft)
								{
									float(_set,TmpFloat,0xff0000);
									CurEnvTrigger("rarrow4");
									call(expset2,1,TmpFloat,0);
									CurEnvTrigger("lite01");
									call(expset2,TmpFloat,150,-1);	
									float(_clr,VarBit,Help02);
									float(_clr,VarBit,Help03);
								}
							}
							elseif(DanceMove==3)
							{
								if(VKEY==KEY_RIGHT || VTrigger==_DIRRight || Vtrigger==_DIRsideright)
								{
									spawnaction(DanceRight);
									CurEnvTrigger("arrow17");
									call(expset1,1,TmpFloat,0);
									CurEnvTrigger("lite02");
									call(expset1,TmpFloat,150,-1);	
									float(_clr,VarBit,Help02);
								}
								elseif(VKEY==KEY_DOWN || VKEY==KEY_LEFT || VKEY==KEY_UP || VTrigger==_DIRBackward || VTrigger==_DIRForward || VTrigger==_DIRLeft)
								{
									float(_set,TmpFloat,0xff0000);
									CurEnvTrigger("arrow17");
									call(expset1,1,TmpFloat,0);
									CurEnvTrigger("lite02");
									call(expset1,TmpFloat,150,-1);	
									float(_clr,VarBit,Help02);
									float(_clr,VarBit,Help03);
								}
							}
							elseif(DanceMove==4)
							{
								if(VKEY==KEY_LEFT || VTrigger==_DIRleft || Vtrigger==_DIRsideleft)
								{
									spawnaction(DanceLeft);
									CurEnvTrigger("arrow17");
									call(expset2,1,TmpFloat,0);
									CurEnvTrigger("lite02");
									call(expset2,TmpFloat,150,-1);	
									float(_clr,VarBit,Help02);
								}
								elseif(VKEY==KEY_DOWN || VKEY==KEY_RIGHT || VKEY==KEY_UP || VTrigger==_DIRBackward || VTrigger==_DIRForward || VTrigger==_DIRForward)
								{
									float(_set,TmpFloat,0xff0000);
									CurEnvTrigger("arrow17");
									call(expset2,1,TmpFloat,0);
									CurEnvTrigger("lite02");
									call(expset2,TmpFloat,150,-1);	
									float(_clr,VarBit,Help02);
									float(_clr,VarBit,Help03);
								}
							}
						}
					}
					else
					{
						if(VarBit&!=Help02)
						{
							if(VarBit&!=Help03)
							{
								float(_set,DanceKey,8);
							}
							else
							{
								float(_set,DanceKey,1);
							}
							float(_or,Varbit,Help02);
							float(_or,VarBit,Help03);
						}
						else
						{
							float(_set,DanceKey,5);
						}
						float(_set,TmpFloat,0x000000);
						CurEnvTrigger("rarrow4");
						call(expset1,1,TmpFloat,0);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("arrow17");
						call(expset1,1,TmpFloat,0);
						call(expset2,1,TmpFloat,0);
					}
					if(DanceTimer<7)
					{
						float(_set,DanceTimer,7);
					}
				}
				elseif(DanceKey==4)
				{
					message("You Be Happy!",120,10);
					sample(SFXYouVIP,-1);
					spawnaction(EndDance);
					float(_set,DanceKey,7);
					float(_set,timer4,0);
					float(_set,DanceSequence,8);
					call(PlayerInput,0);
				}
				elseif(DanceKey==5)
				{
					float(_add,failure,1);
					if(failure==3)
					{
						message("You are disqualified!",120,10);
						vector(_set,tmpvector,255,0,0);
						spawnlight(Omni_Flash,1,emptyvector,tmpvector,EmptyVector,250);
						sample(SFXTryAgain,-1);
						float(_set,DanceKey,6);
						call(PlayerInput,1);
					}
					else
					{
						dmessage("You are too slow!",50,50);
						//sample(SFXDanceLose1,-1);
						sample(SFXConcGrenade,-1);
						vector(_set,tmpvector,255,0,0);
						spawnlight(Omni_Flash,1,emptyvector,tmpvector,EmptyVector,250);
						float(_set,DanceKey,1);
					}
				}
				elseif(DanceKey==6)
				{
					call(PlayerInput,0);
					dmessage("Do you want to continue? Y/N",20,2);
					if(VKey==KEY_Y || VKey==KEY_O || VKEY==KEY_J || VKey==KEY_S)
					{
						CurEnvTrigger("secsplit");
						if(Vtrigger!=_DIREnvTrigger)
						{
							float(_set,DanceKey,0);
							float(_set,DanceTimer,90);
							float(_set,DanceDirection,90);
							float(_set,DanceMove,0);
							float(_set,DanceNumber,0);
							float(_set,DanceSequence,5);
							float(_set,failure,0);
							float(_or,VarBit,Help01);
							call(PlayerInput,1);
						}
					}
					elseif(VKey==KEY_N)
					{
						call(PlayerInput,1);
						call(AutoTesselation,true);
						call(ToggleKey,KEY_RIGHT);
						call(ToggleKey,KEY_UP);
						call(ToggleKey,KEY_DOWN);
						call(ToggleKey,KEY_LEFT);
						ActorFlag(_clr,_AFLAGNoDepossession);
						float(_set,DanceKey,0);
						float(_set,DanceTimer,90);
						float(_set,DanceDirection,90);
						float(_set,DanceMove,0);
						float(_set,DanceNumber,0);
						float(_set,DanceSequence,0);
						float(_set,failure,0);
						float(_or,VarBit,Help01);
						spawnaction(GENIdle);
						call(CutSceneEnd);
						setkeyframe("DANCHAL1","secsplit",0);
						call(wCheckViewCollision,-1,-1,-1,0);
						SetActorToTrigger("vip01b","pos");
					}
				}
				elseif(DanceKey==8)
				{
					float(_add,failure,1);
					if(failure==3)
					{
						message("You are disqualified!",120,10);
						call(PlayerInput,1);
						sample(SFXTryAgain,-1);
						float(_set,DanceKey,6);
					}
					else
					{
						dmessage("You pressed the wrong key!",50,50);
						float(_set,DanceKey,1);
						//sample(SFXDanceLose1,-1);
					}
				}
			}
			if(DanceSequence==8)
			{
				float(_add,timer4,1);
				if(timer4>=120)
				{
					call(CutSceneEnd);
					CurEnvTrigger("pos02");
					call(FaceTriggerDirection);
					call(PlayerInput,0);
					CurEnvTrigger("secsplit");
					call(KeyObjTrigger,0,-1);
					float(_set,DanceSequence,9);
					float(_set,timer4,0);
				}
			}
			elseif(DanceSequence==9)
			{
				CurEnvTrigger("secsplit");
				if(VKeyObjTriggered==0)
				{
					float(_set,DanceSequence,10);
				}
			}
			elseif(DanceSequence==10)
			{
				turn(0,-45,0);
				float(_set,DanceSequence,11);
			}
			elseif(DanceSequence==11)
			{
				direction(_clr,_noDIR);
				direction(_or,_DIRForward|_DIRmove|_DIRWalking);
				CurEnvTrigger("ELEDOOR1");
				if(VTrigger==_DIREnvTrigger)
				{
					call(FaceTriggerDirection);
					float(_set,DanceSequence,12);
				}
			}
			elseif(DanceSequence==12)
			{
				CurEnvTrigger("eledoor");
				if(VKeyObjTriggered!=0)
				{
					float(_set,DanceSequence,13);
				}
			}
			elseif(DanceSequence==13)
			{
				float(_set,DanceTimer,0);
				float(_set,failure,0);
				direction(_clr,_noDIR);
				direction(_or,_DIRForward|_DIRmove|_DIRWalking);
			}
		}

		//turns off ai for all dancers
		CurEnvTrigger("no_ai");
		vector(_set,tmpvector,1050,800,275);
		float(_set,tmpfloat,0);
		call(TriggerBox,tmpvector,tmpfloat2,tmpfloat);
		if(tmpfloat==0 && vaicon!=0)
		{
			ActorFlag(_or,_AFLAGnoai);

			if(VAIClass==_AIClassFemale)
			{
				if(VAction!=FemDance)
				{
					spawnaction(FemDance);
				}

				if(vrnd<5)
				{
					spawnaction(FemDance);
				}
			}
			else
			{
				if(VAction!=ManDance)
				{
					spawnaction(ManDance);
				}

				if(vrnd<5)
				{
					spawnaction(ManDance);
				}

			}
		}
		elseif(tmpfloat==1 && VAICon!=0 && VActorFlag!=_AFLAGnoai)
		{
			ActorFlag(_or,_AFLAGnoai);  //turn ai back on
		}

		//code for vip door access lights
		CurEnvTrigger("ELEDOOR1");
		if(Vtrigger==_DIREnvTrigger)  //check if facing trig dir
		{
			if(VarKey71==0)
			{
				CurEnvTrigger("ELEDOOR1");
				float(_set,VarKey71,16);
				call(expset1,1,tmpfloat,0);

				if(VarKey72>0)
				{
					float(_set,VarKey71,VarKey72);  
					float(_set,VarKey72,0);
				}
			}
			
			//code to turn vip door access lights on
			//----------------------------------------------------------------
			elseif(VarKey71>0)
			{
				if(varkey71!=180)
				{
					float(_add,VarKey71,1);
				}

				float(_set,tmpfloat,0xFFFFFF);

				if(VarKey71==30)
				{
					CurEnvTriggerset("Danchal1","lights1");
					call(expset1,1,tmpfloat,0);
					call(expset2,1,tmpfloat,0);
						
					float(_add,VarKey71,16);
				}

				if(VarKey71==60)
				{
					CurEnvTriggerset("Danchal1","lights2");
					call(expset1,1,tmpfloat,0);
					call(expset2,1,tmpfloat,0);

					float(_add,Varkey71,16);
				}

				if(VarKey71==90)
				{
					CurEnvTriggerset("Danchal1","lights3");
					call(expset1,1,tmpfloat,0);
					call(expset2,1,tmpfloat,0);

					float(_add,VarKey71,16);
				}


				if(VarKey71==120)
				{
					CurEnvTriggerset("Danchal1","lights4");
					call(expset1,1,tmpfloat,0);
					call(expset2,1,tmpfloat,0);

					float(_add,VarKey71,16);
				}

				if(VarKey71==150)
				{
					CurEnvTriggerset("Danchal1","lights5");
					call(expset1,1,tmpfloat,0);
					call(expset2,1,tmpfloat,0);

					float(_add,VarKey71,16);
				}

				if(VarKey71==180)
				{
					CurEnvTriggerset("Danchal1","lights6");
					call(expset1,1,tmpfloat,0);
					call(expset2,1,tmpfloat,0);

					if(VAIClass==_AIClassFemale)
					{
						CurEnvTrigger("eledoor");
						if(ControlTimer==0)
						{
							float(_set,ControlTimer,2);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
						}		
					}

					else
					{
						message("Access Denied",200,10);
					}

				}
			}
			//----------------------------------------------------------------
		}
		
		elseif(vaicon==0 && VTrigger!=_DIREnvTrigger)
		{
			//sets VarKey72 as an even number
			if(VarKey71>0)
			{
				float(_set,tmpfloat,0xffffff);
				call(expset1,1,tmpfloat,0);
				float(_set,VarKey72,VarKey71);
				float(_set,VarKey71,0);
				float(_div,VarKey72,2);
				float(_round,VarKey72);
				float(_mul,VarKey72,2);
			}
		}
		
		//code to turn vip door access lights off
		//----------------------------------------------------------------
		if(VarKey72>0 && Vtrigger!=_DIREnvTrigger)
		{
			float(_set,tmpfloat,0x222222);

			if( ==180)
			{
				CurEnvTriggerset("Danchal1","lights6");

				call(expset1,1,tmpfloat,0);
				call(expset2,1,tmpfloat,0);
			}

			if(VarKey72==150)
			{
				CurEnvTriggerset("Danchal1","lights5");

				call(expset1,1,tmpfloat,0);
				call(expset2,1,tmpfloat,0);
			}

			if(VarKey72==120)
			{
				CurEnvTriggerset("Danchal1","lights4");
				call(expset1,1,tmpfloat,0);
				call(expset2,1,tmpfloat,0);
			}

			if(VarKey72==90)
			{
				CurEnvTriggerset("Danchal1","lights3");
				call(expset1,1,tmpfloat,0);
				call(expset2,1,tmpfloat,0);
			}

			if(VarKey72==60)
			{
				CurEnvTriggerset("Danchal1","lights2");
				call(expset1,1,tmpfloat,0);
				call(expset2,1,tmpfloat,0);
			}

			if(VarKey72==30)
			{
				CurEnvTriggerset("Danchal1","lights1");
				call(expset1,1,tmpfloat,0);
				call(expset2,1,tmpfloat,0);
			}				

			if(VarKey72<=2)
			{
				float(_set,VarKey71,-1);
				float(_set,VarKey72,0);
			}

			float(_sub,VarKey72,2);
		}
		//----------------------------------------------------------------

	}


    // ___________________________________________________________________
	//|                                                                   |
    //| Scene: Lift                                                       |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP_LIFT")  //bt check
	{
		if(VAICon==0)
		{
			if(DanceSequence==13)
			{
				direction(_clr,_noDIR);
				direction(_or,_DIRForward|_DIRmove|_DIRWalking);
				float(_add,Failure,1);
				if(Failure==50)
				{
					call(AutoTesselation,true);
					call(ToggleKey,KEY_RIGHT);
					call(ToggleKey,KEY_UP);
					call(ToggleKey,KEY_DOWN);
					call(ToggleKey,KEY_LEFT);
				}
				elseif(Failure>=60)
				{
					ActorFlag(_clr,_AFLAGNoDepossession);
					float(_set,Failure,0);
					float(_set,DanceSequence,0);
				}

				CurEnvTrigger("lft-dnchl");
				if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
				{
					message("Locked",120,10);
					sample(SFXPlayerActivatesLockedDoorReact,-1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("lft-dnchl");
			if(VKeyObjTriggered==0 && VKeyObjWait==0)
			{
				call(PlayerInput,1);
			}
		}

		CurEnvTrigger("lift");
		if(VkeyObjTriggered==0)
		{
			CurEnvTrigger("lft-v02a");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
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
			CurEnvTrigger("lft-v02a");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
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

		CurEnvTrigger("lift");
		if(VkeyObjTriggered==0)
		{
			if(VTrigger==_DIRactionhold)
			{
				float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
				CurEnvTrigger("panel1");
				callsub(LiftControl,0,1);
				CurEnvTrigger("panel2");
				callsub(LiftControl,1,1);
			
				if(TmpFloat!=-1 && VKeyObjTriggered==0)
				{
					CurEnvTrigger("lift");
					if(TmpFloat1==1)
					{
						if(TmpFloat==1)
						{
							call(ActivateButton,0,TmpFloat,2);
							//kfsample(-1,-1,-1,SFX?,1);  //sound fx for floor
						}
					}
					else
					{
						if(TmpFloat==0)
						{
							call(ActivateButton,0,TmpFloat,2);
							//kfsample(-1,-1,-1,SFX?,1);  //sound fx for floor
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
	}
	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP02A                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP02A")  //bt check
	{
		CurEnvTrigger("V02AV02B");
		if(Vtrigger==_DIREnvTrigger)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("V02AV02C");
		if(Vtrigger==_DIREnvTrigger)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("newpath");
		if(VAIClass==_AIClassProst && VAICon!=0 && VTrigger==_DIREnvTrigger)
		{
			call(AIfindpathwithspecificid,3);
		}
		
		CurEnvTrigger("lft-v02a");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("locked",120,10);
			sample(SFXLockedSound,-1);
		}

	}

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP02B                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP02B")  //bt check
	{
		if(VAICon!=0 && VAIClass==_AIClassCop && VRank==_RankCommander && VarKey73==0)
		{
			call(ChangeInventory,0,-100);
			float(_set,varkey73,1);
		}

		CurEnvTrigger("V02AV02B");
		if(Vtrigger==_DIREnvTrigger)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("V02BV02D");
		if(Vtrigger==_DIREnvTrigger)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("newpath");
		if(VAIClass==_AIClassProst && VAICon!=0 && VTrigger==_DIREnvTrigger)
		{
			call(AIfindpathwithspecificid,2);
		}
	}

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP02C                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP02C")  //bt check
	{
		if(VAICon!=0 && VAIClass==_AIClassCop && VRank==_RankCommander && VarKey75==0)
		{
			call(ChangeInventory,0,-100);
			float(_set,varkey75,1);
		}

		CurEnvTrigger("V02AV02C");
		if(Vtrigger==_DIREnvTrigger)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("V02CV02D");
		if(Vtrigger==_DIREnvTrigger)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("newpath");
		if(VAIClass==_AIClassProst && VAICon!=0 && VTrigger==_DIREnvTrigger)
		{
			call(AIfindpathwithspecificid,4);
		}
	}

	// ___________________________________________________________________
	//|                                                                   |
    //| Scene: VIP02D                                                     |
    //|___________________________________________________________________|
	//
	elseif(Vcurset=="VIP02D")  //bt check
	{
		if(VAICon!=0 && VAIClass==_AIClassCop && VRank==_RankCommander && VarKey74==0)
		{
			call(ChangeInventory,0,-100);
			float(_set,varkey74,1);
		}

		if(varkey1>=1)
		{
			//test
			if(VAICon!=0)
			{
				direction(_clr,_DIRMoveBits|_DIRShoot);
				callsub(Sub_AIGetBackToIdle);

			}
			//else
			//{
			//	direction(_clr,_DIRcombatmode);	//turn combat mode off for bob
			//}
			//end test
		}

		if(VAICon==0)
		{
			if(VActiveTime!=0)
			{
				float(_set,TmpFloat,0);
				GetNumbActorsInSet("vip02a",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
				if(tmpfloat==0)
				{
					GetNumbActorsInSet("vip02b",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
					if(tmpfloat==0)
					{
						GetNumbActorsInSet("vip02c",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
						if(tmpfloat==0)
						{
							GetNumbActorsInSet("vip02d",_AIclassCop,TmpFloat,0,_Equal,_RankCommander);
							if(tmpfloat==0)
							{
							    float(_set,varkey80,0);
								vector(_set,Gactorpos,-6463.35,24000.00,12750.59);
								vector(_set,Gactorangle,0,0,0);
								InitActor(GunCommander,Gactorpos,Gactorangle,"vip02a",TRUE,42);
							}
						}
					}
				}
			}
		
			CurEnvTrigger("V02BV02D");
			if(Vtrigger==_DIREnvTrigger)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("V02CV02D");
			if(Vtrigger==_DIREnvTrigger)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("enter");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass==_AICLassCop && VRank>=_RankCommander)
				{	
					float(_set,tmpfloat,0x00FF00);
					call(expSet1,1,tmpfloat,0);

					if(VTrigger==_DIRAction && VKeyObjTriggered==0)
					{
						call(FaceTriggerDirection);
						callsub(DoorOpen,1,1);
						call(PlayerInput,0);
						float(_set,VarKey1,1);

						direction(_clr,_DIRAction);
					}
				}
				else
				{
					float(_set,tmpfloat,0xFF0000);
					call(expSet1,tmpfloat,0);

					if(VTrigger==_DIRAction && VKeyObjTriggered==0)
					{
						message("Elevator restricted to Commanders",200,10);
						sample(SFXAccessDenied,-1);

						direction(_clr,_DIRAction);
					}
				}	
			}

			if(VarKey1==1)
			{
				CurEnvTrigger("enter");
				if(VKeyObjFrame==1)
				{
					CutScene("end");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
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
					float(_set,VarKey1,3);
					float(_set,timer,0);
				}
			}
			elseif(VarKey1==3)
			{
				float(_add,timer,1);
				if(timer>=70)
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
					CutScene("scroll");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
				}
				elseif(timer==40)
				{
					CurEnvTrigger("lift");
					call(KeyObjTrigger,255,1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					call(FadeToBlack,0);
				}
				elseif(timer==120)
				{
					ActorFlag(_or,_AFLAGnoai);  //turn ai back on
					float(_set,VarKey1,5);
					actorflag(_or,_AFLAGresetfallalt);
					call(LoadLevel,-1,17);
				}
			}									
		}
	}
	//---------------------------------------------
		
//----------------------------------------------------------------								
}   //  FIN
//----------------------------------------------------------------
