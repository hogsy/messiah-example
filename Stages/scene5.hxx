//VarKey21	-   controls help text and various events
//				0	triggers the F5 thingy in Stor_04
//				1	console system explanation (War_ent) 
//				2	lift system explanation (from War_03 or Stor_02)
//VarKey22	- level progress indicator (doors locked, flic states, etc.)
//				1(0)	war_ent, entered for the first time
//				2(1)	war_ent, open door flic segment has been set
//				4(2)	war_ent, door to war_03 has been opened
//				8(3)	war_ent, stor_02, elevator power is now on
//				16(4)	elevator power on flic initiated
//				32(12)	War_rad, Door to annex unlocked

//VarKey23	- has the alarm in stor_02 been set (elevator power been restored), also a delay
//				for the cops that come up the elevator
//VarKey24	- has the worked been mashed in stor_01? 
//				0	worker is ok, set lower tank button to be green
//				1	lower tank button has been pressed, set button to be red
//				2	the worker has been crushed
//				3	medic should be spawned in war_ent
//				4	medic has been spawned
//VarKey25	- delay from when worker has been crushed to when medic comes in
//			- delay from when worker spawn has been requested to when they actually show up
//VarKey26	- War_rad timer for ending sequence.
//VarKey27	- Anim synch for droid
//VarKey28	- flags
//				1 - alarm in stor_02 has finished
//VarKey29	- general purpose bits
//				1 - a worker has been requested for spawn in war_03
//				2 - a scientist has been requested for spawn in war_03
//				4 - play "get away" sample
//				8 - someone is blocking the box kfobj in war_04
//				16 - don't allow kfob in war_04 to activate because of 8
//				32 - siren1 is playing (stor_02)
//				64 - siren2 is playing (war_rad)
//VarKey30	- Check progression of the droid down EL_X03
//VarBit
//------
//Help01	> Story Message #14

SubRoutine(InitSceneSound5)
{
//MSIKA! YOU NEED THIS BIATCH!		call(AutoTesselation,true);

		if(incoming!=0)
		{
			if(ScriptMark==13)
			{
				callsub(Panel13);
			}
			elseif(ScriptMark==14)
			{
				callsub(Panel14);
			}
		}
		else
		{
			callsub(ScriptLevel5);
		}


		//Annex_01
		vector(_set,gactorpos,-15424,25480,23110);
		sample(sfxindustrial1,Gactorpos);
		

		//War_01
		vector(_set,Gactorpos,-15307.11,27233.89,26796.72);
		sample(SFXTankLift,Gactorpos);

		vector(_set,Gactorpos,-15301.48,26103.02,26819.12);
		sample(SFXTankLift,Gactorpos);

		//War_03
		vector(_set,Gactorpos,-15280.24,24804.89,26819.34);
		sample(SFXTankLift,Gactorpos);

		vector(_set,Gactorpos,-7209,25023,16049);
		sample(sfxindustrial1,Gactorpos);

		vector(_set,Gactorpos,-18795,25023,12628); 
		sample(sfxindustrial8,Gactorpos);

		vector(_set,Gactorpos,-16780,25023,12551); 
		sample(sfxindustrial8,Gactorpos);

		//WAR_RAD
		vector(_set,GactorPos,-15366,22323,26392);
		sample(SFXRadWall2,GactorPos);


		//	reset sirens if they where playing when the game was saved
		//
		if(VarKey29&=32)
		{
			vector(_set,Gactorpos,-12789,25593,26250);
			sample(SFXSirenAlert,Gactorpos);
		}
		if(VarKey29&=64)
		{
			vector(_set,Gactorpos,-14726,22487,26398);
			sample(SFXSirenAlert,Gactorpos);
		}
		float(_set,AIVisionToggle,0);
		call(FadeToBlack,2);
		call(CDSwap,10,1,100,60);

}

SubRoutine(DeInitSceneSound5)
{

		//War_01
		vector(_set,Gactorpos,-15307.11,27233.89,26796.72);
		samplestop(SFXTankLift,Gactorpos);

		vector(_set,Gactorpos,-15301.48,26103.02,26819.12);
		samplestop(SFXTankLift,Gactorpos);

		//War_03
		vector(_set,Gactorpos,-15280.24,24804.89,26819.34);
		samplestop(SFXTankLift,Gactorpos);

		vector(_set,Gactorpos,-7209,25023,16049);
		samplestop(sfxindustrial1,Gactorpos);

		vector(_set,Gactorpos,-18795,25023,12628); 
		samplestop(sfxindustrial8,Gactorpos);

		vector(_set,Gactorpos,-16780,25023,12551); 
		samplestop(sfxindustrial8,Gactorpos);

		//WAR_RAD
		vector(_set,GactorPos,-15366,22323,26392);
		samplestop(SFXRadWall2,GactorPos);
}

SubRoutine(InitScene5)
{
		if(VScriptInitiated!=5)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,1024,0);
				InitActor(Bob1,0,Gactorangle,"stor_04");
			}
			if(Res01==0)
			{
				call(loadpreloaddb,10);
				// Reset all the variables
				float(_set,VarKey21,0);
				float(_set,VarKey22,0);
				float(_set,VarKey23,0);
				float(_set,VarKey24,0);
				float(_set,VarKey25,0);
				float(_set,VarKey26,0);
				float(_set,VarKey27,0);
				float(_set,VarKey28,0);
				float(_set,VarKey29,0);
				float(_set,VarKey30,0);
				float(_set,VarKey113,0);
				float(_set,CameraPan,0);
				float(_set,MaxNrSpawn,5);
				float(_set,AIVisionToggle,0);
				float(_set,LiftMsg,0)
				float(_set,timer,0);
				float(_set,timer2,0);
				float(_set,VarBit,AllHelp);
				float(_set,timer3,0);
				float(_set,VGameCounter,0);
				#include "messiahscripts\enemies\mikeware.spt"
			}
		}
		callsub(InitSceneSound5);
		call(ScriptCodeInitiated,5);
}


SubRoutine(IllegalButtonReact)
{
		if(VarKey29&=4 && VAICon!=0 && VAIClass==_AIclasscop)
		{
			sample(SFXPlayerActivatesButtonReact,-1);
			if(timer==0)
			{
				float(_clr,VarKey29,4);
				call(AIchangeplayertoenemy);
			}
		}
}


SubRoutine(MainScene5)
{
		//	countdown for turning players to enemies when activating console illegaly in war_0x
		//
		if(VarKey29&=4 && timer>0)
		{
			float(_sub,timer,1)
		}

//	Door Delay code
//
		if(VCurSet=="WAR_RAD")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("WAR_RAD","BELDOOR");
				setkeyframe("WAR_RAD","BELDOOR",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="EL_X01")
				{
					callsub(DoorOpen,1,1);
					setkeyframe("EL_X01","ELEVTRIG",0);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="EL_X01")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_X01","BELDOOR01");
				setkeyframe("EL_X01","BELDOOR01",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="WAR_04")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_X01","BELDOORE");
				setkeyframe("EL_X01","BELDOORE",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="WAR_RAD")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="WAR_04")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("WAR_04","BELDOOR01");
				setkeyframe("WAR_04","BELDOOR01",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="el_x01")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
					setkeyframe("el_x01","elevtrig",1);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("WAR_04","BELDOOR");
				setkeyframe("WAR_04","BELDOOR",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="el_big")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
					setkeyframe("el_big","beldoor",0);
				}
			}

			//	bits for checking if something is blocking boxctrl
			//
			float(_clr,VarKey29,16);
			if(VarKey29&=8)
			{
				float(_or,VarKey29,16);
			}
			float(_clr,VarKey29,8);

			CurEnvTrigger("BOXCTRL");
			vector(_set,TmpVector,-16326, 23482, 26572);
			if(timer==5 && VKeyObjFrame==1)
			{
				Sample(SFXPneumatik2,TmpVector);
				float(_set,timer,4);
			}
			elseif(timer==4 && VKeyObjFrame==3)
			{
				Sample(SFXHudLiftLoop,TmpVector);
				float(_set,timer,3);
			}
			elseif(timer==3 && VKeyObjFrame==8)
			{
				SampleStop(SFXHudLiftLoop,TmpVector);
				Sample(SFXHudLiftStop,TmpVector);
				float(_set,timer,2);
			}
			elseif(timer==2 && VKeyObjFrame==10)
			{
				Sample(SFXHudLiftLoop,TmpVector);
				float(_set,timer,1);
			}
			elseif(timer==1 && VKeyObjFrame==12)
			{
				SampleStop(SFXHudLiftLoop,TmpVector);
				Sample(SFXHudLiftStop,TmpVector);
				float(_set,timer,0);
			}
		}
		elseif(VCurSet=="WAR_01")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("WAR_01","BELDOORTP");
				setkeyframe("WAR_01","BELDOORTP",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="el_x02")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
					setkeyframe("el_x02","trigelev",1);
					if(VarKey30==1)
					{
						setkeyframe("el_x03","lift",1);
					}
				}
			}
		}
		elseif(VCurSet=="EL_X02")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_X02","BELDOORA");
				setkeyframe("EL_X02","BELDOORA",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_01")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_X02","BELDOOR02");
				setkeyframe("EL_X02","BELDOOR02",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_02")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="WAR_02")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("WAR_02","BELDOOR01");
				setkeyframe("WAR_02","BELDOOR01",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="el_x02")
				{
					callsub(DoorOpen,0,1);
					setkeyframe("el_x02","trigelev",0);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("WAR_02","BELDOOR");
				setkeyframe("WAR_02","BELDOOR",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="el_big")
				{
					callsub(DoorOpen,0,1);
					float(_set,ControlTimer,0);
					setkeyframe("el_big","beldoor",2);
					if(VarKey30==2)
					{
						setkeyframe("el_x03","lift",2);
					}
				}
			}
		}
		elseif(VCurSet=="EL_BIG")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_BIG","BELDOORB");
				setkeyframe("EL_BIG","BELDOORB",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_02")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{	
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_BIG","BELDOORC");
				setkeyframe("EL_BIG","BELDOORC",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_03")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==3)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_BIG","BELDOORD");
				setkeyframe("EL_BIG","BELDOORD",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_04")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="EL_SML")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_SML","ELVSSTO2A");
				setkeyframe("EL_SML","ELVSSTO2A",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="stor_02")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("EL_SML","ELVSWAR3A");
				setkeyframe("EL_SML","ELVSWAR3A",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_03")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="war_03")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("war_03","WARGAT");
				setkeyframe("war_03","WARGAT",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_ent")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("war_03","BELDOOR");
				setkeyframe("war_03","BELDOOR",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="el_big")
				{
					callsub(DoorOpen,0,1);
					float(_set,ControlTimer,0);
					setkeyframe("EL_BIG","BELDOOR",1);
				}
			}
			elseif(ControlTimer==3)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("war_03","WAR3ELVS1");
				setkeyframe("war_03","WAR3ELVS1",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="el_sml")
				{
					callsub(DoorOpen,0,1);
					float(_set,ControlTimer,0);
					setkeyframe("EL_sml","els_elvt",0);
				}
			}
		}
		elseif(VCurSet=="war_ent")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("war_ent","DOOR2ENT");
				setkeyframe("war_ent","DOOR2ENT",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="stor_01")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("war_ent","WARGAT");
				setkeyframe("war_ent","WARGAT",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_03")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==3)
			{
				CurEnvTriggerSet("war_ent","ANNEX");
				if(VKeyObjTriggered==0 && VRunScriptCode==6)
				{
					callsub(DeInitSceneSound6);
					call(RunScriptCode,_clr,6);
				}
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("war_ent","ANNEX",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="annx_01")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="stor_01")  //main
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("stor_01","DOORSTO1");
				setkeyframe("stor_01","DOORSTO1",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="stor_04")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==2)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("stor_01","door2ent");
				setkeyframe("stor_01","DOORSTO1",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="war_ent")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
			elseif(ControlTimer==3)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("stor_01","door2trig");
				setkeyframe("stor_01","door2trig",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="stor_02")
				{
					callsub(DoorOpen,0,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="stor_02")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("stor_02","DOOR2TRIG");
				setkeyframe("stor_02","DOOR2TRIG",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="stor_01")
				{
					callsub(DoorOpen,0,1);
					float(_set,ControlTimer,0);
				}
			}
		}
		elseif(VCurSet=="stor_04")
		{
			if(ControlTimer==1)
			{
				dmessage("L O A D I N G . . .",50,2);
				CurEnvTriggerSet("stor_04","DOORSTO1");
				setkeyframe("stor_04","DOORSTO1",1);
				call(KeyObjTrigger,255,1);
				if(VSetActive=="stor_01")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
			}
		}

//////////////////////


		//cheat to trigger the fog in all the War_xxx rooms
		//	if(VKey==KEY_B && VKey==KEY_RSHIFT)
		//	{
		//		float(_set,VarKey27,12);
		//	}

		//check if only one cop left in Stor_02. if TRUE then get out of the loop.
		if(VCurSet=="stor_02")
		{
			if(VarKey23!=0 && VarKey23<=600)
			{
				call(AIChangePlayerToEnemy);
			}
		}
		if(VarKey23==661)
		{
			vector(_set,Gactorpos,-12789,25593,26250);
			KillLight(Lplanelight,Gactorpos,32); //Light Id,Position,Fade time (0=kills instantly)
			sample(SFXAlertReset,Gactorpos);
			samplestop(SFXSirenAlert,Gactorpos);
			float(_clr,VarKey29,32);
			CurEnvTriggerSet("stor_02","siren");
			setkeyframe("stor_02","siren",0);
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
			float(_set,VarKey23,0);
			float(_or,VarKey28,1);				//alarm has finished
		}
		//Radiation Sequence
		if(VarKey27>9 && VarKey27<14)
		{
			float(_add,timer3,1);
			if(timer3==5)
			{
				vector(_set,tmpvector,-50,-180,-50);
				vector(_set,Gactorpos,-14726,22487,26398);
				spawnlight(LightPulseOmni2,-1,Gactorpos,tmpvector,EmptyVector,600);
			}
			if(timer3>=60)
			{
				float(_set,timer3,0)
			}

			if(vrnd<50) // green smoke
			{
				//War_rad
				if(VSetActive=="war_rad")
				{
					call(SetParticleSetID,"war_rad");
					vector(_set,Gactorpos,-14838,22432,26888);
					vector(_set,Gactorine,0,0,-20);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,22402,26888);
					vector(_set,Gactorine,0,0,-20);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,22369,26888);
					vector(_set,Gactorine,0,0,-20);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,22338,26888);
					vector(_set,Gactorine,0,0,-20);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14312,23630,26027);
					vector(_set,Gactorine,-10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);
				}
				if(VSetActive=="war_04")
				{
					call(SetParticleSetID,"war_04");
					vector(_set,Gactorpos,-14312,23630,26027);
					vector(_set,Gactorine,-10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14312,23600,26027);
					vector(_set,Gactorine,-10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14312,23568,26027);
					vector(_set,Gactorine,-10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14312,23535,26027);
					vector(_set,Gactorine,-10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16270,23631,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16270,23600,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16270,23568,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16270,23535,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);
				}
				if(VSetActive=="war_03")
				{
					call(SetParticleSetID,"war_03");
					vector(_set,Gactorpos,-16270,24830,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16270,24800,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16270,24768,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16270,24735,26766);
					vector(_set,Gactorine,10,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16258,24830,26020);
					vector(_set,Gactorine,10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16258,24800,26020);
					vector(_set,Gactorine,10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16258,24768,26020);
					vector(_set,Gactorine,10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-16258,24735,26020);
					vector(_set,Gactorine,10,0,10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);
				}
				if(VSetActive=="war_02")
				{
					call(SetParticleSetID,"war_02");
					vector(_set,Gactorpos,-14838,26033,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,26000,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,25970,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,25940,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);
				}
				if(VSetActive=="war_01")
				{
					call(SetParticleSetID,"war_01");
					vector(_set,Gactorpos,-14838,27232,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,27202,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,27170,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);

					vector(_set,Gactorpos,-14838,27140,26893);
					vector(_set,Gactorine,0,0,-10);
					spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_radsteam);
				}
			}
		}
		if(VarKey27==9)
		{
			float(_set,timer2,0);
			samplestop(SFXDroidHover);
		}
		if(VarKey27==10)
		{
			call(SetParticleSetID);
			float(_add,timer2,1);
			if(timer2==70)
			{
				CurEnvTrigger("droid4");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,250,-1);
				call(expset2,TmpFloat,250,-1);
				vector(_set,Gactorpos,-15304,22906,26926);
				sample(SFXBazookaExplode,Gactorpos);
				vector(_set,Gactorpos,-15944,22906,26926);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
				vector(_set,Gactorpos,-15944,22906,25863);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
			}
			if(timer2==100)
			{
				CurEnvTrigger("droid3");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,250,-1);
				call(expset2,TmpFloat,250,-1);
				vector(_set,Gactorpos,-15304,22650,26926);
				sample(SFXBazookaExplode,Gactorpos);
				vector(_set,Gactorpos,-15944,22650,26926);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
				vector(_set,Gactorpos,-15944,22650,25863);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
			}
			if(timer2==130)
			{
				CurEnvTrigger("droid2");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,250,-1);
				call(expset2,TmpFloat,250,-1);
				vector(_set,Gactorpos,-15304,22337,26926);
				sample(SFXBazookaExplode,Gactorpos);
				vector(_set,Gactorpos,-15944,22337,26926);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
				vector(_set,Gactorpos,-15944,22337,25863);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
			}
			if(timer2==160)
			{
				CurEnvTrigger("droid");
				float(_set,TmpFloat,0x000000);
				call(expset1,TmpFloat,250,-1);
				call(expset2,TmpFloat,250,-1);
				vector(_set,Gactorpos,-15304,22028,26926);
				sample(SFXBazookaExplode,Gactorpos);
				vector(_set,Gactorpos,-15944,22028,26926);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
				vector(_set,Gactorpos,-15944,22028,25863);
				spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
			}
			if(timer2>=170)
			{
				float(_set,timer2,0);
				float(_set,VarKey27,11);
			}
		}

		////////////////
		// VSETACTIVE //
		////////////////

		if(VSetActive=="war_ent")
		{
			if(VarKey27==12)
			{
				call(ChangeFog,_SXFogType,_SXFogExp);
				float(_set,TmpFloat,0.0007);
				call(ChangeFog,_SXFogDensity,TmpFloat);
				float(_set,VarKey27,13);
			}
			if(VarKey22&=32)
			{
				CurEnvTriggerSet("WAR_ENT","ANNEX");
				float(_set,TmpFloat,0x00f000);
				call(EXPset1,1,TmpFloat,0);
			}
		}
		if(VSetActive=="el_sml")
		{
			if(VarKey27==12)
			{
				call(ChangeFog,_SXFogType,_SXFogExp);
				float(_set,TmpFloat,0.0007);
				call(ChangeFog,_SXFogDensity,TmpFloat);
				float(_set,VarKey27,13);
			}

			CurEnvTriggerSet("el_sml","els_elvt");
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
			if(VKeyObjFrame==1 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Elevator Control Center",120,10);
				float(_set,LiftMsg,0);
			}
		}
		if(VSetActive=="el_x01")
		{
			CurEnvTriggerSet("el_x01","elevtrig");
			float(_set,TmpFloat,0x444400);  // blue-grey
			float(_set,TmpFloat2,0xffff000); // yellow
			float(_set,TmpFloat1,0xff7722);   // orange
			call(expset1,4,TmpFloat,TmpFloat1); //lift direction
			call(expset2,3,TmpFloat,TmpFloat2); //floor indicator
			if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Nuclear Power Control Center",120,10);
				float(_set,LiftMsg,0);
			}
			if(VKeyObjFrame==1 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Basement Storage",120,10);
				float(_set,LiftMsg,0);
			}
		}
		if(VSetActive=="el_x02")
		{
			CurEnvTriggerSet("el_x02","trigelev");
			float(_set,TmpFloat,0x444400);  // blue-grey
			float(_set,TmpFloat2,0xffff000); // yellow
			float(_set,TmpFloat1,0xff7722);   // orange
			call(expset1,4,TmpFloat,TmpFloat1); //lift direction
			call(expset2,3,TmpFloat,TmpFloat2); //floor indicator
			if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Level 2 - Storage",120,10);
				float(_set,LiftMsg,0);
			}
			if(VKeyObjFrame==1 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Level 3 - Storage",120,10);
				float(_set,LiftMsg,0);
			}
		}
		if(VSetActive=="el_big")
		{
			CurEnvTriggerSet("el_big","beldoor");
			float(_set,TmpFloat,0x444400);  // blue-grey
			float(_set,TmpFloat2,0xffff000); // yellow
			float(_set,TmpFloat1,0xff7722);   // orange
			call(expset1,4,TmpFloat,TmpFloat1); //lift direction
			call(expset2,3,TmpFloat,TmpFloat2); //floor indicator

			if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Basement Storage",120,10);
				float(_set,LiftMsg,0);
			}
			if(VKeyObjFrame==1 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Tank Garage",120,10);
				float(_set,LiftMsg,0);
			}
			if(VKeyObjFrame==2 && VKeyObjTriggered==0 && LiftMsg==1)
			{
				message("Level 2 - Storage",120,10);
				float(_set,LiftMsg,0);
			}
		}
		if(VSetActive=="war_rad")
		{
			if(VarKey27<9)
			{
				CurEnvTriggerSet("war_rad","droid4");
				float(_set,TmpFloat,0xba9555);
				call(expset1,TmpFloat,350,-1);
				call(expset2,TmpFloat,350,-1);
				CurEnvTriggerSet("war_rad","droid3");
				float(_set,TmpFloat,0xba9555);
				call(expset1,TmpFloat,350,-1);
				call(expset2,TmpFloat,350,-1);
				CurEnvTriggerSet("war_rad","droid2");
				float(_set,TmpFloat,0xba9555);
				call(expset1,TmpFloat,350,-1);
				call(expset2,TmpFloat,350,-1);
				CurEnvTriggerSet("war_rad","droid");
				float(_set,TmpFloat,0xba9555);
				call(expset1,TmpFloat,350,-1);
				call(expset2,TmpFloat,350,-1);
			}
		}

		////////////////
		//   VCURSET  //
		////////////////

		if(vcurset=="stor_04")
		{
			CurEnvTrigger("LIFTSND01");
			if(VKeyObjFrame==0 && VKeyObjTriggered==0);
			{
				float(_set,Incoming,0);
				call(KeyObjTrigger,1,1);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
			}
			if(VKeyObjFrame==1 && VarKey21==0)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,13);
				callsub(Panel13);
				ClearDMessage();
				float(_set,VarKey21,1);
			}
		}
		elseif(vcurset=="stor_02")
		{
			CurEnvTrigger("arme");
			if(VKeyObjTriggered!=0)
			{
				vector(_set,Gactorpos,-13189,25231,26763);
				callsub(DispenserSound);
			}
			CurEnvTrigger("door2trig");
			float(_set,TmpFloat,0xff0000);
			if(VarKey28&=1)
			{
				float(_set,TmpFloat,0x007f00);
			}
			call(expset1,1,TmpFloat,0);

			CurEnvTrigger("stor2elva");
			if(VarKey22&=16 && VarKey23!=0 && VarKey23<=660)
			{
				if(VarKey23==5)
				{
					//	get the cops ready
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,-13916.12,25300,26316.39);
					InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"El_sml");
					vector(_set,Gactorpos,-13916.12,25245,26316.39);
					InitActor(copl,Gactorpos,Gactorangle,"El_sml",TRUE,4);

					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,-13844.08,25300,26486.31);
					InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"El_sml");
					vector(_set,Gactorpos,-13844.08,25245,26486.31);
					InitActor(copl,Gactorpos,Gactorangle,"El_sml",TRUE,3);

					//set arrows on elevator panel to brown-green (lights off)
					float(_set,TmpFloat,0x707008); //brown-green
					call(expset1,1,TmpFloat); //...assign that color to the object
					call(expset2,1,TmpFloat); //...assign that color to the object
				}
				elseif(VarKey23==90)
				{
					//	Set the alarm
					vector(_set,Gactorpos,-12789,25593,26250);
					vector(_set,tmpvector,255,0,0);
					vector(_set,tmpvector1,0,0,1);
					SpawnLight(Lplanelight,-1,Gactorpos,tmpvector,tmpvector1,1000);
					sample(SFXViolation,Gactorpos);
					sample(SFXSirenAlert,Gactorpos)
					float(_or,VarKey29,32);

					// start the Rotating light on top of the console
					CurEnvTrigger("siren");
					call(KeyObjTrigger,255,1,-1);
					float(_set,TmpFloat,0x800000);
					call(expset1,1,TmpFloat,0);
				}
				elseif(VarKey23==360)
				{
					//	get the cops in here
					//setkeyframe("stor_02","stor2elva",1);
					callsub(DoorOpen,0,1);
					//call(KeyObjTrigger,255,1);//KeyObjTrigger,endframe, direction (starts anim at beginning for elevator doors)
					//set player to be considered an enemy
				}
				elseif(VarKey23>360 && VSetActive=="el_sml")
				{
					setkeyframe("el_sml","els_elvt",1);
				}


				float(_set,TmpFloat,0x707008); //brown-green
				call(expset1,1,TmpFloat); //assign color to the up arrow on elevator panel
				call(expset2,1,TmpFloat); //assign color to the down arrow on elevator panel

				if(VarKey23>120 && VarKey23<170)
				{
					float(_set,TmpFloat,0x00FF00); //bright green (on)
					call(expset2,1,TmpFloat); //assign color to the down arrow on elevator panel
				}

				if(VarKey23>170 && VarKey23<=360)
				{
					if(VarKey23>=300)//solid green
					{
						float(_set,TmpFloat,0x00FF00); //bright green (on)
					}
					else
					{
						float(_seti,TmpFloat,VGameCounter);
						float(_and,TmpFloat,8);//to blink light when (VGameCounter & 8)

						if (TmpFloat!=0) //flash arrow color
						{
							float(_set,TmpFloat,0x00FF00); //bright green (on)
						}
						else
						{
							float(_set,TmpFloat,0x707008); //brown-green
						}
					}
					call(expset1,1,TmpFloat); //assign color to the up arrow on elevator panel
				}
				else
				{
					float(_set,TmpFloat,0x707008); //brown-green
					call(expset1,1,TmpFloat); //assign color to the up arrow on elevator panel
				}
				
				float(_add,VarKey23,1);//increment counter
			}
			if(VarKey23>360)
			{
				float(_set,TmpFloat,0x707008); //brown-green
				call(expset1,1,TmpFloat); //assign color to the up arrow on elevator panel
			}
		}


		//door to war_ent steam fx
		if(vcurset=="stor_04"||vcurset=="stor_01"||vcurset=="war_ent")
		{
			call(SetParticleSetID);
			if(dooropenLife>0)
			{
				if(dooropenLife<60)
				{
					if(dooropenCount1>0)
					{
						float(_sub,dooropenCount1,1);
					}
				}
				if(dooropenLife<50)
				{
					if(dooropenCount2>0)
					{
						float(_sub,dooropenCount2,1);
					}
				}
				if(dooropenLife<40)
				{
					if(dooropenCount3>0)
					{
						float(_sub,dooropenCount3,1);
					}
				}
				if(dooropenLife<30)
				{
					if(dooropenCount4>0)
					{
						float(_sub,dooropenCount4,1);
					}
				}
				if(dooropenLife<20)
				{
					if(dooropenCount5>0)
					{
						float(_sub,dooropenCount5,1);
					}
				}


				float(_add,dooropenTime,1);
				if(dooropenTime>2)
				{
					float(_set,dooropenTime,0);
				}

				if(dooropenTime==0)
				{
					if(dooropenCurr==0)
					{
						vector(_set,fxvector,-14272,24450,24600);
					}
					elseif(dooropenCurr==1)
					{
						vector(_set,fxvector,-11450,24420,24470);
					}

					if(dooropenLife<=180)
					{
						if(dooropenCount1<10)
						{
							float(_add,dooropenCount1,1);
						}

						if(vrnd<75)
						{
							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount1);
							vector(_set,tmpvector,0,0,0);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
						}

						//if(skipcollidecount>=5)
						//{
						//	call(CheckActorCollision,gactorpos,100,0,_COLSteam);
						//}

					}
					if(dooropenLife<=165)
					{
						if(dooropenCount2<10)
						{
							float(_add,dooropenCount2,0.9);
						}

						if(vrnd<75)
						{
							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount2);
							vector(_set,tmpvector,0,0,0);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,80);
							vector(_add,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount2);
							vector(_set,tmpvector,0,0,0);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,80);
							vector(_sub,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
						}

						//if(skipcollidecount>=5)
						//{
						//	call(CheckActorCollision,gactorpos,100,0,_COLSteam);
						//}

					}
					if(dooropenLife<=145)
					{
						if(dooropenCount3<10)
						{
							float(_add,dooropenCount3,0.8);
						}

						if(vrnd<75)
						{
							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount3);
							vector(_set,tmpvector,0,0,0);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,160);
							vector(_add,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount3);
							vector(_set,tmpvector,0,0,0);		
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,160);
							vector(_sub,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
						}

						//if(skipcollidecount>=5)
						//{
						//	call(CheckActorCollision,gactorpos,100,0,_COLSteam);
						//}

					}
					if(dooropenLife<=125)
					{
						if(dooropenCount4<10)
						{
							float(_add,dooropenCount4,0.7);
						}

						if(vrnd<75)
						{
							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount4);
							vector(_set,tmpvector,0,0,0);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,240);
							vector(_add,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount4);
							vector(_set,tmpvector,0,0,0);		
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,240);
							vector(_sub,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
						}

						//if(skipcollidecount>=5)
						//{
						//	call(CheckActorCollision,gactorpos,100,0,_COLSteam);
						//}

					}
					if(dooropenLife<=115)
					{
						if(dooropenCount5<10)
						{
							float(_add,dooropenCount5,0.6);
						}

						if(vrnd<75)
						{
							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount5);
							vector(_set,tmpvector,0,0,0);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,320);
							vector(_add,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);

							vector(_set,gactorine,0,0,0);
							//vector(_sety,gactorine,dooropenCount5);
							vector(_set,tmpvector,0,0,0);		
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_setx,tmpvector,tmpfloat);
							vector(_setz,tmpvector,tmpfloat);
							float(_rnd2,tmpfloat,6)
							float(_sub,tmpfloat,3);
							vector(_sety,tmpvector,tmpfloat);
							vector(_add,gactorine,tmpvector);

							vector(_copy,gactorpos,fxvector);
							vector(_set,tmpvector,0,0,320);
							vector(_sub,gactorpos,tmpvector);
							spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
						}

						//if(skipcollidecount>=5)
						//{
						//	call(CheckActorCollision,gactorpos,100,0,_COLSteam);
						//}

					}
				}
				float(_sub,dooropenLife,1);
			}
		}



		//pipe steam
		if(vcurset=="war_ent"||vcurset=="stor_01")
		{
			call(SetParticleSetID);
			//sequenced warent/storeroom jet steamers
			if(SteamJetCount>=6)				//next hole in pipe
			{
				float(_set,SteamJetCount,0);
			}


			if(SteamJetLife>=100)				//delay between each burst
			{
				float(_add,SteamJetCount,1);
				float(_set,SteamJetLife,0);
				float(_set,Sampleflag1,1);
				float(_set,Sampleflag2,1);
			}
			float(_add,SteamJetLife,1);
		}

		if(vcurset=="stor_01")
		{
			call(SetParticleSetID,"stor_01");
			if(vrnd<30&&SteamJetLife<50)		//lifespan of each burst
			{
				//entrance
				//set 1
				if(SampleFlag1==1)
				{
					if(SteamJetCount==0)
					{
						vector(_set,Gactorpos,-12290,24917,25039);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13554,25405,23699);
						vector(_set,Gactorine,10,0,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13583,25836,23766);
						vector(_set,Gactorine,10,0,10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13583,26102,23766);
						vector(_set,Gactorine,10,0,10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13785,25083,24692);
						vector(_set,Gactorine,0,-10,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13841,25112,25138);
						vector(_set,Gactorine,-7,-10,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);
					}
					elseif(SteamJetCount==3)
					{
						vector(_set,Gactorpos,-12223,24953,25061);
						vector(_set,Gactorine,5,0,-18);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13583,25364,23766);
						vector(_set,Gactorine,10,0,10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13554,25838,23699);
						vector(_set,Gactorine,10,0,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13554,26194,23699);
						vector(_set,Gactorine,10,0,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13786,25085,25182);
						vector(_set,Gactorine,0,-10,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13815,25092,25077);
						vector(_set,Gactorine,-3,-10,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);
					}
					elseif(SteamJetCount==5)
					{
						vector(_set,Gactorpos,-12254,24825,25041);
						vector(_set,Gactorine,2,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13554,25311,23699);
						vector(_set,Gactorine,10,0,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13554,25706,23699);
						vector(_set,Gactorine,10,0,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13583,26152,23766);
						vector(_set,Gactorine,10,0,10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13855,25117,24782);
						vector(_set,Gactorine,-6,-10,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-13824,25083,24621);
						vector(_set,Gactorine,-3,-10,0);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);
					}
				}
				float(_set,Sampleflag1,0);
			}
		}
		if(vcurset=="war_rad")
		{
			call(SetParticleSetID,"war_rad");
			if(VarKey1==1 && VarKey27>=8)
			{
				call(ChangeFog,_SXFogDensity,VarKey2);
				float(_add,VarKey2,0.000005);
				if(VarKey2>=0.0007)
				{
					message("Evacuate to Annex Section Immediately",120,10);
					CurEnvTrigger("ticker");
					call(expset1,885,885,1722);
					call(KeyObjTrigger,1,1);
					float(_set,VarKey1,2);
				}
			}
			
			if(VarKey27==0 && timer3==0)
			{
				CurEnvTrigger("ticker");
				call(expset1,0,0,732);
				float(_set,timer3,1);
			}
			if(VarKey27==1)
			{
				CurEnvTrigger("droid2");
				if(VKeyObjFrame==0)
				{
					sample(SFXOpenLid,emptyvector);
					vector(_set,Gactorpos,-15263,22420,26393);
					sample(SFXDroidHover,Gactorpos);
					float(_set,VarKey26,0);
					float(_set,VarKey30,8);
					float(_set,VarKey27,2);
					
				}
			}
			if(VarKey27==2)
			{
				CurEnvTrigger("droid");
				if(VKeyObjFrame==20)
				{
					sample(SFXClawOpen,Gactorpos);
					float(_set,VarKey27,3);
				}
			}
			if(VarKey27==3)
			{
				CurEnvTrigger("droid");
				if(VKeyObjFrame==37)
				{
					sample(SFXClawSpin,Gactorpos);
					float(_set,VarKey27,4);
				}
			}
			if(VarKey27==4)
			{
				CurEnvTrigger("droid3");
				if(VKeyObjFrame==23)
				{
					sample(SFXOpenLock,Gactorpos);
					float(_set,VarKey27,5);
				}
			}
			if(VarKey27==5)
			{
				CurEnvTrigger("droid");
				if(VKeyObjFrame==69)
				{
					sample(SFXClawSpin,Gactorpos);
					float(_set,VarKey27,6);
				}
			}
			if(VarKey27==6)
			{
				CurEnvTrigger("droid3");
				if(VKeyObjFrame==37)
				{
					sample(SFXOpenLock,Gactorpos);
					CurEnvTrigger("ticker");
					call(expset1,733,820,884);
					float(_set,VarKey27,7);
				}
			}
			if(VarKey27==7)
			{
				CurEnvTrigger("droid4");
				if(VKeyObjFrame==39)
				{
					sample(SFXReactorWarning,Gactorpos);
					sample(SFXOpenPipe,Gactorpos);
					float(_set,VarKey27,8);
				}
			}
			if(VarKey27==8)
			{
				CurEnvTrigger("droid4");
				if(VKeyObjFrame==43)
				{
					sample(SFXPipeRotate,Gactorpos);
					float(_set,VarKey27,9);
				}
			}
			if(VarKey27==9)
			{
				CurEnvTrigger("droid");
				if(VKeyObjFrame==120)
				{
					vector(_set,Gactorpos,-15484,22460,26407);
					sample(SFXBazookaExplode,Gactorpos);
					vector(_set,fxvector,0,100,0);
					vector(_set,tmpvector,255,0,0);
					vector(_set,Gactorpos,-15484,22397,26407);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);

					//TRY NOT TO SPAWN 4 OF THE EXACT SAME LIGHTS IN THE SAME POSITION PLEASE!!
					//ESPECIALLY WHEN THE RADIUS IS THAT BIG ...THANK YOU!
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,-1);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,-1);
					dmessage("Computer Malfunction - Radiation Leak Detected",100,200);
					dmessage("Evacuate the Facility Immediately",110,200);
					vector(_set,Gactorpos,-14726,22487,26398);
					sample(SFXSirenAlert,Gactorpos);
					sample(SFXReactorLeak,Gactorpos);
					sample(SFXWallHit,Gactorpos);
					float(_set,VarKey27,10);
					float(_set,VarKey30,15);
					float(_or,VarKey29,64);
				}
			}
			if(VarKey27==11)
			{
				call(ChangeFog,_SXFogType,_SXFogExp);
				float(_set,VarKey1,1);
				float(_set,VarKey2,0);
				float(_set,VarKey27,12);
			}

			if(VarKey30==8)
			{
				float(_add,VarKey26,1);
				if(VarKey26==600 && VarKey30==8)
				{
					float(_set,VarKey30,9);
				}
			}
		}
		
		if(vcurset=="stor_02")
		{
			if(VarKey22&!=8)
			{
				CurEnvTrigger("console");
				call(expset2,0,0,56);
				float(_or,VarKey22,8);
			}
			if(VarKey26==1)
			{
				CurEnvTrigger("arme");
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);
			}
		}
		//more pipe steam
		if(vcurset=="war_ent")
		{
			call(SetParticleSetID,"war_ent");
			if(VarKey22&!=1)
			{
				CurEnvTrigger("DT_DOORS");
				call(EXPSet2,0,0,19);
				float(_or,VarKey22,1);
			}

			if(vrnd<30&&SteamJetLife<50)		//lifespan of each burst
			{
				//store room
				if(SampleFlag2==1)
				{
					if(SteamJetCount==3)
					{
						vector(_set,Gactorpos,-15445,24999,24140);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15445,25466,24140);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14833,25389,24144);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14766,25039,24104);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14832,25467,23998);
						vector(_set,Gactorine,0,0,-8);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14900,25079,24018);
						vector(_set,Gactorine,-7,0,-8);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15508,25429,24024);
						vector(_set,Gactorine,-8,0,-7);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15508,24999,24024);
						vector(_set,Gactorine,-7,0,-6);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);
					}
					elseif(SteamJetCount==1)
					{
						vector(_set,Gactorpos,-14747, 24936, 25252);
						call(CheckActorCollision,GActorpos,40,0,_COLsteam);

						vector(_set,Gactorpos,-14893,25389,25097);
						vector(_set,Gactorine,-6,0,-7);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14897,25079,25093);
						vector(_set,Gactorine,-7,0,-8);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15510,24942,25108);
						vector(_set,Gactorine,-7,0,-6);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15486,25331,25073);
						vector(_set,Gactorine,-10,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14769,25428,25174);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14770,24998,25169);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15445,25428,25211);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15375,25077,25177);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);
					}
					elseif(SteamJetCount==5)
					{
						vector(_set,Gactorpos,-14737, 24936, 24211);
						call(CheckActorCollision,GActorpos,40,0,_COLsteam);


						vector(_set,Gactorpos,-15379,25038,24101);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15381,25329,24090);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14766,25389,24104);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14786,24941,24141);
						vector(_set,Gactorine,5,0,11);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14833,25467,25203);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14836,25038,25209);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15451,25332,25211);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15445,25039,25211);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);
					}


					//store room
					if(SteamJetCount==2)
					{
						vector(_set,Gactorpos,-14835,25389,25065);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14823,24939,25070);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15446,25037,25067);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15509,25429,25103);
						vector(_set,Gactorine,-8,0,-7);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14898,25333,24034);
						vector(_set,Gactorine,-6,0,-7);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14897,25038,24023);
						vector(_set,Gactorine,-8,0,-9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15510,25333,24029);
						vector(_set,Gactorine,-7,0,-6);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15486,24941,23993);
						vector(_set,Gactorine,-10,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);
					}
					elseif(SteamJetCount==0)
					{
						vector(_set,Gactorpos,-14747, 24936, 25252);
						call(CheckActorCollision,GActorpos,40,0,_COLsteam);

						vector(_set,Gactorpos,-15445,25077,24140);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15375,25466,24107);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14833,25428,24144);
						vector(_set,Gactorine,0,0,9);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14766,25039,24104);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14790,25330,25206);
						vector(_set,Gactorine,5,0,11);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14772,24940,25158);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15381,25329,25160);
						vector(_set,Gactorine,7,0,5);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15399,24941,25208);
						vector(_set,Gactorine,5,0,11);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);
					}
					elseif(SteamJetCount==4)
					{
						vector(_set,Gactorpos,-14897,25469,25093);
						vector(_set,Gactorine,-7,0,-8);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14829,25075,25073);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15449,24997,25064);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15510,25333,25108);
						vector(_set,Gactorine,-10,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14826,25330,23995);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-14832,25076,23998);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15444,25467,23993);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						sample(SFXVent2,gactorpos);

						vector(_set,Gactorpos,-15449,24999,23984);
						vector(_set,Gactorine,0,0,-10);
						spawnparticle(fx_steampipes,-1,gactorpos,gactorine,-1);
						//sample(SFXVent2,gactorpos);
					}
				}
				float(_set,Sampleflag2,0);
			}
		}
		float(_add,FireJetLife,1);
		elseif(VCurSet=="stor_01")  //bt check?
		{
			if(VarKey24==2)				//the worker has been crushed
			{
				float(_add,VarKey25,1);	//increment delay counter
			}

			CurEnvTrigger("door2ent");
			if(VTrigger!=_DIREnvTrigger && VKeyObjTriggered==0)
			{
				float(_set,TmpFloat,0x8000);
				call(expset1,1,TmpFloat,0);
			}

			CurEnvTrigger("door2trig");
			float(_set,TmpFloat,0x800000);
			if(VarKey23>=670)
			{
				float(_set,TmpFloat,0x8000);
			}
			elseif(VKeyObjTriggered!=0)
			{
				float(_set,TmpFloat,0x8000);
			}
			call(expset1,1,TmpFloat,0);

			CurEnvTrigger("tanklift");
			if(VKeyObjFrame==0 && VKeyObjTriggered!=0 && varkey113==0)
			{
				vector(_set,GActorPos,-11977,24465,24340);
				SamplePlaying(SFXWorkerPanic,GActorPos);
				if(VTrigger!=_DIRTempFlag)
				{
					sample(SFXWorkerPanic,GActorPos);
					float(_set,varkey113,1);
				}

			//	sample(SFXWorkerPanic,Gactorpos);
			}
			if(VKeyObjFrame==1 && VKeyObjTriggered!=0 && varkey113==1)
			{
				vector(_set,GActorPos,-11977,24465,24340);
				SamplePlaying(SFXWorkerScream,GActorPos);
				if(VTrigger!=_DIRTempFlag)
				{
					sample(SFXWorkerScream,GActorPos);
					float(_set,varkey113,2);
				}

			//	sample(SFXWorkerScream,Gactorpos);
			}
			if(VKeyObjFrame==2 && VKeyObjTriggered!=0 && varkey113==2)
			{
				vector(_set,GActorPos,-11977,24465,24340);
				SamplePlaying(SFXWorkerCrushed,GActorPos);
				if(VTrigger!=_DIRTempFlag)
				{
					sample(SFXWorkerCrushed,GActorPos);
					float(_set,varkey113,0);
				}

			//	sample(SFXWorkerCrushed,Gactorpos);
			}
			if(VarKey24==0)
			{
				float(_set,TmpFloat,0xffff00);
				call(expset1,1,TmpFloat,0);
			}
			elseif(VarKey24==1)
			{
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);
			}
		}
		elseif(VCurSet=="war_ent")
		{
			CurEnvTrigger("DOOR2ENT");	
			if(VTrigger!=_DIREnvTrigger && VKeyObjTriggered==0)
			{
				float(_set,TmpFloat,0x8000);
				call(expset1,1,TmpFloat,0);
			}

			CurEnvTrigger("dt_lift");
			if(VKeyObjTriggered==0)
			{
				float(_set,TmpFloat,0xffff00);
				call(expset1,1,TmpFloat,0);
			}
		}
		elseif(VCurSet=="war_03")
		{
			CurEnvTrigger("BELDOOR");
			if(VarKey22&=16)
			{
				float(_set,TmpFloat,0x8000);
			}
			else
			{
				float(_set,TmpFloat,0x800000);
			}
			call(expset1,1,TmpFloat,0);
			
			CurEnvTrigger("WAR3ELVS1");
			float(_set,TmpFloat,0x8000);
			call(expset1,1,TmpFloat,0);

			CurEnvTrigger("tanklift");
			if(VKeyObjFrame==2)
			{
				float(_set,TmpFloat,0xffff00);
				call(expset1,1,TmpFloat,0);
			}
			elseif(VKeyObjFrame==0)
			{
				call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);
			}
			if(VKeyObjTriggered!=0)
			{
				call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
			}
			
			if(VarKey29&=1 || VarKey29&=2)
			{
				float(_add,VarKey25,1);
				if(VarKey25==250)
				{
					float(_clr,VarKey29,1);
					float(_clr,VarKey29,2);

					vector(_set,Gactorangle,0,1024,0);
					if(VarKey30<4)
					{
						vector(_set,Gactorpos,-16575, 24642, 26561);
						InitActor(WeaponTorch,Gactorpos,Gactorangle,"war_03");
						vector(_set,Gactorpos,-16575, 24592, 26561);
						InitActor(Worker,Gactorpos,Gactorangle,"war_03",FALSE,0);
					}
					else
					{
						vector(_set,Gactorpos,-16575, 24592, 26561);
						InitActor(RadiationWorker,Gactorpos,Gactorangle,"war_03",FALSE,0);
					}
					CurEnvTrigger("SPNWORK01");
					call(KeyObjTrigger,255,1);
					kfsample(SFXDoOp1,SFXDoMo1,SFXDoCl1,-2);
				}
				elseif(VarKey25>=251)
				{
					float(_set,VarKey25,0);
				}
			}
		}

		///////////////////////////////////////////////////
		// SPECIAL CASE : WHEN PLAYER EXITS THE FACTORY  //
		// AND LOADS THE REST OF CITY 2, THE STREET      //
		// SCRIPT NEEDS TO BE LOADED RIGHT AWAY          //
		///////////////////////////////////////////////////
		elseif(VCurSet=="walls1")
		{
			if(VRunScriptCode!=18)
			{
				callsub(DeInitSceneSound5);
				call(RunScriptCode,_clr,5);
				call(RunScriptCode,_or,18);
			}
		}
		elseif(VCurSet=="walls2")
		{
			if(VRunScriptCode!=18)
			{
				callsub(DeInitSceneSound5);
				call(RunScriptCode,_clr,5);
				call(RunScriptCode,_or,18);
			}
		}
		//Start in Factory
		elseif(VCurSet=="fact_7" || VCurSet=="pston_5")
		{
			if(VRunScriptCode!=7)
			{
				callsub(DeInitSceneSound5);
				call(RunScriptCode,_clr,5);
				call(RunScriptCode,_or,7);
			}
		}
		//Start in Wasteplant
		elseif(VCurSet=="wast17" || VCurSet=="wast1" || VCurSet=="wast8")
		{
			if(VRunScriptCode!=10)
			{
				callsub(DeInitSceneSound5);
				call(RunScriptCode,_clr,5);
				call(RunScriptCode,_or,10);
			}
		}
		//Start in conveyer
		elseif(VCurSet=="convier1")
		{
			if(VRunScriptCode!=14)
			{
				callsub(DeInitSceneSound5);
				call(RunScriptCode,_clr,5);
				call(RunScriptCode,_or,14);
			}
		}
		//Start in the annex
		elseif(VCurSet=="annx_01")
		{
			if(VRunScriptCode!=6)
			{
				callsub(DeInitSceneSound5);
				call(RunScriptCode,_clr,5);
				call(RunScriptCode,_or,6);
			}
		}
			

		if(skipcollidecount>=5)
		{
			float(_set,skipcollidecount,0);
		}
		float(_add,skipcollidecount,1);
}






SubRoutine(BackgroundTriggerChecksScene5)
{

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel5); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////


	if(VarKey27>9)
	{
		if(VCurSet=="war_rad" || VCurSet=="war_01" || VCurSet=="war_02" || VCurSet=="war_03" || VCurSet=="war_04" || VCurSet=="war_ent" || VCurSet=="el_x01" || VCurSet=="el_x02" || VCurSet=="el_big")
		{
			if(VarKey27<14)
			{
				callsub(RadiationArea);
			}
			elseif(VarKey27==14)
			{
				if(Vaction==CopDizzy)
				{
					spawnaction(GENIdle);
				}
				if(VarKey1==1)
				{
					float(_sub,VarKey2,0.000001);
					call(ChangeFog,_SXFogDensity,VarKey2);
					if(VarKey2<=0.000001)
					{
						call(ChangeFog,_SXFogType,_SXFogOff);
						message("100% Filtered - Decontamination Finished",200,10);
						float(_set,VarKey1,2);
						float(_set,VarKey27,15);
					}
				}
			}
			else
			{
				callsub(RadiationAreaNormal);
			}
		}
	}

	if(VSetActive=="el_x03")
	{
		if(VClass==_ClassDroid)
		{
			move(0,-10,0);
		}
		//drizz
		CurEnvTriggerSet("el_x03","lift");
		if(VKeyObjTriggered!=0)
		{
			kfsample(SFXTrapDoorStart,SFXTrapDoorLoop,-1,SFXTrapDoorStop);
		}
	}

	if(VAICon==0 && CameraPan==1)
	{
		if (VCurSet!="EL_SML" || VCurSet!="EL_BIG" || VCurSet!="EL_x01" || VCurSet!="EL_x02" || VCurSet!="fact_4" || VCurSet!="fact_16")
		{
			callsub(Sub_SetCameraNormal);
			float(_set,CameraPan,0);
		}
	}

	if(VCurSet=="war_ent")
	{
		if(VAICon==0)
		{
			if(VarBit&=Help01)
			{
				CurEnvTrigger("message");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_set,Incoming,1);
					float(_set,Godtimer,0);
					float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
					float(_set,ScriptMark,14);
					callsub(Panel14);
					ClearDMessage();
					float(_clr,VarBit,Help01);
				}
			}
	
			if(VarKey27==13)
			{
				message("Air Filters Activated",120,10);
				sample(SFXAirFilters,Gactorpos);
				float(_set,VarKey1,1);
				float(_set,VarKey2,0.0007);
				float(_set,VarKey27,14);

				//reset siren
				vector(_set,Gactorpos,-14726,22487,26398);
				samplestop(SFXSirenAlert,Gactorpos);
				float(_clr,VarKey29,64);
			}
/*			if(VarKey27==14)
			{
				if(VarKey1==1)
				{
					float(_sub,VarKey2,0.000001);
					call(ChangeFog,_SXFogDensity,VarKey2);
					if(VarKey2<=0.000001)
					{
						call(ChangeFog,_SXFogType,_SXFogOff);
						message("100% Filtered - Decontamination Finished",200,10);
						float(_set,VarKey1,2);
						float(_set,VarKey27,15);
					}
				}
			}
*/
		}
		else
		{
			if(VAIClass==_AIClassCop && VPathID==22)
			{
				CurEnvTrigger("chgpath");
				if(VTrigger==_DIREnvTrigger)
				{
					call(AIfindpathwithspecificid,9);
				}
			}
		}

		CurEnvTrigger("spawn");
		if(VTrigger==_DIREnvTrigger && VAIcon==0 && VAIClass!=_AIClassCop)
		{
			GetNumbActorsInSet("war_ent",_AIClassCop,TmpFloat);
			if(TmpFloat==0)
			{	
				if(MaxNrSpawn!=0)
				{
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,-16972,24430,24903);
					InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"war_ent");
					vector(_set,Gactorpos,-16972,24383,24903);
					InitActor(copl,Gactorpos,Gactorangle,"war_ent",TRUE,22);
					
					CurEnvTrigger("spcheck");
					callsub(DoorOpen,1,1);
					float(_sub,MaxNrSpawn,1);
				}
			}
		}

		CurEnvTrigger("DOOR2ENT");
		if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassCop || VAIClass==_AIClassScientist)
			{
				callsub(StartDoorDelay,1);
				if(TmpFloat==1)
				{
					//sto1/sto4 door steam fx
					float(_set,dooropenLife,190);
					float(_set,dooropenCount1,0);
					float(_set,dooropenCount2,0);
					float(_set,dooropenCount3,0);
					float(_set,dooropenCount4,0);
					float(_set,dooropenCount5,0);
					float(_set,dooropenTime,0);
					float(_set,dooropenCurr,0);
				}
			}
			elseif(VAICON==0)
			{
				sample(SFXAccessDenied,Gactorpos);
				message("Restricted area@ security and medical staff only",120,10);
				direction(_clr,_DIRaction);
			}		
		}

		CurEnvTrigger("WARGAT");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)	
		{
			if(VarKey22&=4)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					Sample(SFXLatch1,-1);		//leave this here
				}
			}
			else
			{
				if(VAICON==0)
				{
					sample(SFXAccessDenied,Gactorpos);
					message("LOCKED",120,10);
				}
			}
			direction(_clr,_DIRaction);
		}

		CurEnvTrigger("DT_LIFT");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
		{
			if(VClass!=_ClassAngel)
			{
				if(VAICON==0)
				{
					call(ActivateButton,"Maintenance Lift Activated",-1,FALSE);
					call(ActivateButtonSample,SFXLiftActivated);
				}
				float(_set,TmpFloat,0x0000ff);
				call(expset1,1,TmpFloat,0);
				if(VKeyObjTriggered==0)
				{
					if(VKeyObjFrame==0)
					{
						call(KeyObjTrigger,1,1);
					}
					elseif(VKeyObjFrame==1)
					{
						call(KeyObjTrigger,0,-1);
					}
				}
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				direction(_clr,_DIRaction);
			}
			else
			{
				if(VAICON==0)
				{
					call(ActivateButton,"hmm... not sure what this does!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
			direction(_clr,_DIRaction);
		}

		CurEnvTrigger("DT_DOORS");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VAICon==0)
				{
					if (VarKey22&!=4)
					{
						call(ActivateButton,"Door Unlocked",-1,false);
						call(ActivateButtonSample,SFXDoorUnlock);
						sample(SFXValidFunction,Gactorpos);
						float(_set,TmpFloat,0x00ff00);
						call(expset1,1,TmpFloat,0);
						call(expset2,-1,66,67);
						float(_or,VarKey22,4);

						CurEnvTrigger("WARGAT");
						float(_set,TmpFloat,0x8000);
						call(expset1,1,TmpFloat,0);
					}
					else
					{
						call(ActivateButton,"Door Already Unlocked",-1,false);
						call(ActivateButtonSample,SFXValidFunction);
					}
				}
			}
			else
			{
				if(VAICON==0)
				{
					call(ActivateButton,"strange ....nothing happened!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
			direction(_clr,_DIRaction);
		}

		CurEnvTrigger("ANNEX");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjFrame==0)	
		{
			if(VarKey22&=32)
			{				
				if(VAICon==0 && ControlTimer==0)
				{	
					call(ForceGlobalRealloc);
					call(ForceLoadSet,"annx_02");
					call(ForceLoadSet,"annx_04");
					float(_set,ControlTimer,3);
					call(KeyObjTrigger,255,1);
					if(VRunScriptCode!=6)
					{
						call(RunScriptCode,_or,6);
					}
					direction(_clr,_DIRaction);
				}
			}
			elseif(VAICON==0)
			{
				
				sample(SFXAccessDenied,Gactorpos);
				message("Annex Security Circuits Engaged",120,10);
			}
			direction(_clr,_DIRaction);
		}
	}
	elseif(VCurSet=="stor_04")
	{
		CurEnvTrigger("DOORSTO1");
		callsub(StartDoorDelay,1);
		if(TmpFloat==1)
		{
			float(_set,dooropenLife,190);
			float(_set,dooropenCount1,0);
			float(_set,dooropenCount2,0);
			float(_set,dooropenCount3,0);
			float(_set,dooropenCount4,0);
			float(_set,dooropenCount5,0);
			float(_set,dooropenTime,0);
			float(_set,dooropenCurr,1);
		}
		CurEnvTrigger("LIFTSND01");
		if(VKeyObjTriggered!=0)
		{
			Camera(elevator_camera_distance,elevator_camera_angle);
			Target(elevator_camera_Tdistance,elevator_camera_Tangle);
		}
		else
		{
			callsub(Sub_SetCameraNormal);
		}

	}
	elseif(VCurSet=="war_03")
	{
		if(VAICon==0 && VTrigger==_DIRaction)
		{
			CurEnvTrigger("SPNWORK01");
			if(VTrigger==_DIREnvTrigger)
			{
				Direction(_clr,_DIRaction);

				if(VarKey29&=1)
				{
					call(ActivateButton,"Worker is already on his way",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				elseif(VarKey29&=2)
				{
					call(ActivateButton,"Nuclear Technician is already on his way",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
				else
				{
					if(VarKey30<4 && VarKey27==0)
					{
						GetNumbActorsInSet("war_03",_AIclassworker,TmpFloat);
						GetNumbActorsInSet("war_ent",_AIclassworker,TmpFloat2);
						GetNumbActorsInSet("el_big",_AIclassworker,TmpFloat3);
						GetNumbActorsInSet("el_sml",_AIclassworker,TmpFloat4);
						float(_add,TmpFloat,TmpFloat2);
						float(_add,TmpFloat,TmpFloat3);
						float(_add,TmpFloat,TmpFloat4);

						if(TmpFloat==0)
						{
							//	Spawn a worker
							//
							float(_set,VarKey25,0);
							float(_or,VarKey29,1);
							call(ActivateButton,"Worker is on his way",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
						}
						else
						{
							call(ActivateButton,"Workers and Nuclear Technicians are present or busy",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
					}
					else
					{
						GetNumbActorsInSet("war_03",_AIclassscientist,TmpFloat);
						GetNumbActorsInSet("war_ent",_AIclassscientist,TmpFloat2);
						GetNumbActorsInSet("el_big",_AIclassscientist,TmpFloat3);
						GetNumbActorsInSet("el_sml",_AIclassscientist,TmpFloat4);
						float(_add,TmpFloat,TmpFloat2);
						float(_add,TmpFloat,TmpFloat3);
						float(_add,TmpFloat,TmpFloat4);

						if(TmpFloat==0)
						{
							//	Spawn a scientist
							//
							float(_set,VarKey25,0);
							float(_or,VarKey29,2);
							call(ActivateButton,"Nuclear Technician is on his way",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
						}
						else
						{
							call(ActivateButton,"Workers and Nuclear Technicians are present or busy",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
					}
				}
			}
		}

		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
		}
		if(VarKey27==14 || VarKey27==0)
		{
			call(ChangeFog,_SXFogType,_SXFogOff);
		}
		if(VAICon==0)
		{
			CurEnvTrigger("stuck");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					CurEnvTrigger("spnwork01");
					call(KeyObjTrigger,255,1);
					kfsample(SFXDoOp1,SFXDoMo1,SFXDoCl1,-2);
					direction(_clr,_DIRaction);
				}
			}
		}
		CurEnvTrigger("BELDOOR");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
		{
			if (VarKey22&!=16)
			{
				if(VAICON==0)
				{
					sample(SFXElevatorOff,Gactorpos);
					message("Elevator Power Is Off",120,10);
				}
			}
			else
			{
				if(VarKey27<=10)
				{
					if(VAIClass==_AIclasscop || VAIClass==_AIclassworker || VAIClass==_AIclassscientist)
					{
						callsub(StartDoorDelay,2);
					}
					else
					{
						if(VAICON==0)
						{
							sample(SFXAccessDenied,Gactorpos);
							message("Elevator Restricted to Authorized Personnel",120,10);
						}
					}
				}
				else
				{
					callsub(StartDoorDelay,2);
				}
			}
			direction(_clr,_DIRaction);		
		}

		CurEnvTrigger("WAR3ELVS1");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
		{
			if(VAIClass==_AIclasscop || VAIClass==_AIclassworker || VAIClass==_AIclassscientist)
			{
				float(_set,ControlTimer,3);
				call(KeyObjTrigger,255,1);
				Sample(SFXLatch1,-1);		//leave this here
//				setkeyframe("el_sml","els_elvt",0);
			}
			elseif(VAICON==0)
			{
				sample(SFXAccessDenied,Gactorpos);
				message("Authorized Personnel Only",120,10);
			}
			direction(_clr,_DIRaction);
		}

		CurEnvTrigger("WARGAT");
		callsub(StartDoorDelay,1);

		CurEnvTrigger("tanklift");
		if(VTrigger==_DIRaction&&VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			if(VAIClass==_AIclassworker || VAIClass==_AIclassscientist)
			{
				if(VAICON==0)
				{
					call(ActivateButton,"Tank lift activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
				}
				if(VKeyObjFrame==0)
				{
					call(KeyObjTrigger,2,1);
					CurEnvTrigger("WRKRDR");
					call(KeyObjTrigger,2,1);
				}
				else
				{
					call(KeyObjTrigger,0,-1);
					CurEnvTrigger("WRKRDR");
					call(KeyObjTrigger,0,-1);
				}
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
			}
			elseif(VAICON==0)
			{
				call(ActivateButton,"Working Staff Only",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}
			direction(_clr,_DIRaction);
		}
	}
	elseif(VCurSet=="EL_BIG")
	{
		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
		}
		if(VarKey27==14 || VarKey27==0)
		{
			call(ChangeFog,_SXFogType,_SXFogOff);
		}
		CurEnvTrigger("beldoor");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("inv");
			if(VKeyObjFrame==1)
			{
				call(KeyObjTrigger,255,1);
			}

			CurEnvTrigger("BELDOORB");
			callsub(StartDoorDelay,1);

			CurEnvTrigger("BELDOORC");
			callsub(StartDoorDelay,2);

			CurEnvTrigger("BELDOORD");
			callsub(StartDoorDelay,3);

			if(CameraPan==0)
			{
				float(_set,CameraPan,1);
			}
		}
		else
		{
			float(_set,LiftMsg,1);
			CurEnvTrigger("inv");
			if(VKeyObjFrame==0)
			{
				call(KeyObjTrigger,1,1);
			}
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
			CurEnvTrigger("panel3");
			callsub(LiftControl,0,2);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,2);
			CurEnvTrigger("panel1");
			callsub(LiftControl,2,2);

			CurEnvTrigger("beldoor");
			if(TmpFloat!=-1 && VKeyObjTriggered==0)			//elevator should be activated
			{
				if(TmpFloat1==1)
				{
					if(TmpFloat==2)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXSector2,1);
					}
					else
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXTankGarage,1);
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						call(ActivateButton,0,TmpFloat,2);
						kfsample(-1,-1,-1,SFXSectorBase,1);
					}
					else
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
	elseif(VCurSet=="EL_x01")
	{
		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
		}
		if(VarKey27==14 || VarKey27==0)
		{
			call(ChangeFog,_SXFogType,_SXFogOff);
		}
		CurEnvTrigger("elevtrig");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("inv");
			if(VKeyObjFrame==1)
			{
				call(KeyObjTrigger,255,1);
			}
			CurEnvTrigger("BELDOOR01");
			callsub(StartDoorDelay,1);

			CurEnvTrigger("BELDOORE");
			callsub(StartDoorDelay,2);
			if(CameraPan==0)
			{
				float(_set,CameraPan,1);
			}
		}
		else
		{
			float(_set,LiftMsg,1);
			CurEnvTrigger("inv");
			if(VKeyObjFrame==0)
			{
				call(KeyObjTrigger,1,1);
			}
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

			CurEnvTrigger("elevtrig");
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
	elseif(VCurSet=="EL_x02")
	{
		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
		}
		if(VarKey27==14 || VarKey27==0)
		{
			call(ChangeFog,_SXFogType,_SXFogOff);
		}
		CurEnvTrigger("trigelev");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("inv");
			if(VKeyObjFrame==1)
			{
				call(KeyObjTrigger,255,1);
			}

			CurEnvTrigger("BELDOORA");
			callsub(StartDoorDelay,1);

			CurEnvTrigger("BELDOOR02");
			callsub(StartDoorDelay,2);

			if(CameraPan==0)
			{
				float(_set,CameraPan,1);
			}
		}
		else
		{
			float(_set,LiftMsg,1);
			CurEnvTrigger("inv");
			if(VKeyObjFrame==0)
			{
				call(KeyObjTrigger,1,1);
			}
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

		if(VTrigger==_DIRactionhold)
		{

			float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
			CurEnvTrigger("panel1");
			callsub(LiftControl,0,1);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,1);

			if(TmpFloat!=-1)			//elevator should be activated
			{
				CurEnvTrigger("trigelev");
				if(VKeyObjTriggered==0)
				{
					if(TmpFloat1==1)
					{
						if(TmpFloat==1)
						{
							call(ActivateButton,0,TmpFloat,2);
							kfsample(-1,-1,-1,SFXSector3,1);
						}
					}
					else
					{
						if(TmpFloat==0)
						{
							call(ActivateButton,0,TmpFloat,2);
							kfsample(-1,-1,-1,SFXSector2,1);
						}
					}
					if(VAICON==0)
					{
						call(ActivateButtonSample,SFXValidFunction);
					}
					float(_set,CameraPan,0);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
				}
				direction(_clr,_DIRAction);
			}
		}
	}
	elseif(VCurSet=="EL_SML")
	{

		if(VAICon==0)
		{
			if(VarKey27==13)
			{
				message("Air Filters Activated",120,10);
				sample(SFXAirFilters,Gactorpos);
				float(_set,VarKey1,1);
				float(_set,VarKey2,0.0007);
				float(_set,VarKey27,14);

				//reset siren
				vector(_set,Gactorpos,-14726,22487,26398);
				samplestop(SFXSirenAlert,Gactorpos);
				float(_clr,VarKey29,64);
			}
		}
/*
		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
			message("Air Cleaning Filters Activated",120,10);
			sample(SFXAirFilters,Gactorpos);
			float(_set,VarKey1,1);
			float(_set,VarKey2,0.0007);
			float(_set,VarKey27,13);
		}
		if(VarKey27==13)
		{
			if(VarKey1==1)
			{
				float(_sub,VarKey2,0.000003);
				call(ChangeFog,_SXFogDensity,VarKey2);
				if(VarKey2<=0.000001)
				{
					call(ChangeFog,_SXFogType,_SXFogOff);
					message("100% Filtered - Decontamination Finished",200,10);
					float(_set,VarKey1,2);
					float(_set,VarKey27,14);

					//reset siren
					vector(_set,Gactorpos,-14726,22487,26398);
					samplestop(SFXSirenAlert,Gactorpos);
					float(_clr,VarKey29,64);
				}
			}
		}
*/
		if(VarKey21<3)
		{
			float(_set,timer,4000);
			float(_set,VarKey21,3);
		}

		if(timer>5000)
		{
			if(VAICON==0)
			{
				dmessage("To operate lifts@ approach the panel@",20,400);
				dmessage("press and hold the ENTER key while",30,400);
				dmessage("pressing FORWARD (up) or BACKWARD (down).",40,400);
			}
			float(_set,timer,0);
		}

		CurEnvTrigger("els_elvt");
		if(VkeyObjTriggered==0)
		{
			if(VAICon==0)
			{
				CurEnvTrigger("inv");
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);


				CurEnvTrigger("ELVSSTO2A");
				if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
				{
					if(VarKey27!=13)
					{
						callsub(StartDoorDelay,1);
					}
					else
					{
						message("Door Locked During Decontamination Process",120,10);
						sample(SFXAccessDenied,Gactorpos);
						Direction(_clr,_DIRaction);
					}
				}
				CurEnvTrigger("ELVSWAR3A");
				if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
				{
					if(VarKey27!=13)
					{
						callsub(StartDoorDelay,2);
					}
					else
					{
						sample(SFXAccessDenied,Gactorpos);
						message("Door Locked During Decontamination Process",120,10);
						Direction(_clr,_DIRaction);
					}
				}
				if(CameraPan==0)
				{
					float(_set,CameraPan,1);
				}
			}
		}
		else
		{
			if(VAICon==0)
			{
				float(_set,LiftMsg,1);
				CurEnvTrigger("inv");
				call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				call(ClrAllCollisionBuffers);
			}
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

		if(VTrigger==_DIRactionhold)
		{
			float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
			CurEnvTrigger("panel1");
			callsub(LiftControl,0,1);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,1);

			CurEnvTrigger("els_elvt");			
			if(VKeyObjTriggered==0)
			{
				if(TmpFloat!=-1)
				{
					if(TmpFloat1==1)
					{
						if(TmpFloat==1)
						{
							call(ActivateButton,0,TmpFloat,2);
							kfsample(-1,-1,-1,SFXElevatorCenter,1);
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
	}
	elseif(VCurSet=="war_rad")
	{
		/*
		if(VKey==KEY_J && VarKey30<4)
		{
			message("bloody cheater !",120,10);
			float(_set,VarKey30,4);
		}
		*/
		if(VarKey30==5 && VKeyObjTriggered==0)
		{
			float(_set,VarKey30,7);
		}
		if(VAICon!=0)
		{
			if(VarKey1>=1 && VAIClass==_AIClassScientist)
			{
				if(Vaction!=GENCoweringLoop)
				{
//					spawnaction(GENCoweringLoop);
					callsub(Sub_CivilianReactionToThreat);
				}
			}
		}
		else
		{
			CurEnvTrigger("beldoor");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
			{
//				if(VarKey30<5 || VarKey30>14 || VarKey1==2)			//what is this!?
				if(VarKey27==0 || VarKey27>10)
				{
					callsub(StartDoorDelay,1);
					direction(_clr,_DIRaction);
				}
				else
				{
					sample(SFXAccessDenied,Gactorpos);
					dmessage("Door Locked Due To Hazard Control",60,130);
					dmessage("Please Wait For Rad-Bot",70,130);
					dmessage("To Complete His Task",80,130);
				}
			}	

			CurEnvTrigger("droid");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VClass!=_ClassAngel)
				{
					if(VAIClass==_AIClassScientist && VRank==_RankScum)
					{
						if(VarKey30<4)
						{
							call(ActivateButton,"Rad-Bot Not Detected On This Floor",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
						if(VarKey30==4)
						{
							CurEnvTrigger("beldoor");
							if(VKeyObjTriggered!=0)
							{
								call(ActivateButton,"Area is not secure@ seal off all exits",-1,FALSE);
								call(ActivateButtonSample,SFXInvalidFunction);
							}
							else
							{
								CurEnvTrigger("droid");
								call(ActivateButton,"Rad-Bot Engaged",-1,FALSE);
								call(ActivateButtonSample,SFXValidFunction);
								vector(_set,Gactorpos,-15521,22420,26388);
								call(KeyObjTrigger,255,1);
								CurEnvTrigger("droid2");
								call(KeyObjTrigger,255,1);
								CurEnvTrigger("droid3");
								call(KeyObjTrigger,255,1);
								CurEnvTrigger("droid4");
								call(KeyObjTrigger,255,1);
								sample(SFXReactorOutput,Gactorpos);
								float(_set,VarKey27,1);
								float(_or,VarKey22,32);
								float(_set,VarKey30,5);
							}
						}
						elseif(VarKey30>=5)
						{
							if(VKeyObjTriggered!=0)
							{
								call(ActivateButton,"Rad-Bot Already Engaged",-1,FALSE);
								call(ActivateButtonSample,SFXInvalidFunction);
								direction(_clr,_DIRaction);
							}
						}
						direction(_clr,_DIRaction);
					}
					else
					{
						call(ActivateButton,"Access Denied@ Nuclear Engineering Credentials Required",-1,FALSE);
						call(ActivateButtonSample,SFXAccessDenied);
						sample(SFXAccessDenied,Gactorpos);
						direction(_clr,_DIRaction);
					}
				} 
				else
				{
					call(ActivateButton,"If.. i.. could.. just.. reach.. the......",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
					direction(_clr,_DIRaction);
				}
				direction(_clr,_DIRaction);
			}
		}
	}
	elseif(VCurSet=="war_01")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("CamTrig");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,250,40,145);
				call(TriggerBox,TmpVector,0,TmpFloat);
				if(TmpFloat==1)
				{
					camera(150,20);
				}
				else
				{
					callsub(Sub_SetCameraNormal);
				}
			}
		}

		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
		}
		if(VarKey27==14 || VarKey27==0)
		{
			call(ChangeFog,_SXFogType,_SXFogOff);
		}
		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("beldoortp");
			callsub(StartDoorDelay,1);
		}

		CurEnvTrigger("droid");
		vector(_set,TmpVector,45,130,70);
		Call(TriggerBox,TmpVector,0,tmpfloat);
		if(tmpfloat==1)
		{
			if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger)
			{
				if(VClass!=_ClassAngel)
				{
					if(VAIClass==_AIclassworker || VAIClass==_AIclassscientist)
					{
						CurEnvTriggerSet("el_x03","lift");
						if(VKeyObjFrame==0)
						{
							call(ActivateButton,"Radiation Robot (Rad-Bot) Engaged",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							sample(SFXTransferSector2,-1);
							call(KeyObjTrigger,1,1);
							CurEnvTrigger("droid");
							
							float(_set,TmpFloat,0xffff00);
							call(expset1,1,TmpFloat,0);
							call(expset2,1,TmpFloat,0);
							float(_set,VarKey30,1);

							call(AIcheckvisionbuffer,_AIclasscop,0,0,0);
							if(VTrigger==_DIRTempFlag)
							{
								float(_or,VarKey29,4);
								float(_set,timer,25);
							}
						}
						else
						{
							call(ActivateButton,"Rad-Bot Not Detected On This Floor",-1,FALSE);
							sample(SFXUnrecognized,Gactorpos);
						}
					}
					else
					{
						call(ActivateButton,"Working Staff Only",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				else
				{
					call(ActivateButton,"If.. i.. could.. just.. reach.. the......",-1,FALSE);
				}
				direction(_clr,_DIRaction);
			}
		}

		callsub(IllegalButtonReact);
	}
	elseif(VCurSet=="war_02")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("CamTrig");
			if(VTrigger==_DIREnvTrigger)
			{
				vector(_set,TmpVector,250,40,145);
				call(TriggerBox,TmpVector,0,TmpFloat);
				if(TmpFloat==1)
				{
					camera(150,20);
				}
				else
				{
					callsub(Sub_SetCameraNormal);
				}
			}
		}


		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
		}
		if(VarKey27==14 || VarKey27==0)
		{
			call(ChangeFog,_SXFogType,_SXFogOff);
		}

		if(VTrigger==_DIRaction)
		{
			CurEnvTrigger("beldoor01");
			callsub(StartDoorDelay,1);

			CurEnvTrigger("beldoor");
			callsub(StartDoorDelay,2);

			CurEnvTrigger("droid");
		}

		CurEnvTrigger("droid");
		vector(_set,TmpVector,45,130,70);
		Call(TriggerBox,TmpVector,0,tmpfloat);
		if(tmpfloat==1)
		{
			if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger)
			{
				if(VClass!=_ClassAngel)
				{
					if(VAIClass==_AIclassworker || VAIClass==_AIclassscientist)
					{
						CurEnvTriggerSet("el_x03","lift");
						if(VKeyObjFrame==1)
						{
							if(VAICON==0)
							{
								call(ActivateButton,"Rad-Bot Engaged",-1,FALSE);
								call(ActivateButtonSample,SFXValidFunction);
								sample(SFXTransferSectorBase,-1);

								call(AIcheckvisionbuffer,_AIclasscop,0,0,0);
								if(VTrigger==_DIRTempFlag)
								{
									float(_or,VarKey29,4);
									float(_set,timer,25);
								}
							}
							call(KeyObjTrigger,2,1);
							CurEnvTrigger("droid");
							float(_set,TmpFloat,0xffff00);
							call(expset1,1,TmpFloat,0);
							call(expset2,1,TmpFloat,0);
							float(_set,VarKey30,2);
						}
						else
						{
							if(VAICON==0)
							{
								call(ActivateButton,"Rad-Bot Not Detected On This Floor",-1,FALSE);
								call(ActivateButtonSample,SFXInvalidFunction);
							}
						}
					}
					else
					{
						if(VAICON==0)
						{
							call(ActivateButton,"Working Staff Only",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
							sample(SFXUnrecognized,Gactorpos);
						}
					}
				}
				else
				{
					if(VAICON==0)
					{
						call(ActivateButton,"Huh.. doesn't work ..why am I not suprised!",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
					direction(_clr,_DIRaction);
				}
				direction(_clr,_DIRaction);
			}
		}
		callsub(IllegalButtonReact);
	}
	elseif(VCurSet=="war_04")
	{
		CurEnvTrigger("Blocking");
		if(VTrigger==_DIREnvTrigger)
		{
			float(_or,VarKey29,8);
		}

		CurEnvTrigger("wepdisp");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VKeyObjFrame==0 && VKEyObjTriggered==0)
			{
				message("Weapon Granted",120,10);
				vector(_set,Gactorpos,-14520,24145,26830);

				vector(_set,Gactorangle,0,1024,0);
				InitActor(WeaponHarpoon,Gactorpos,Gactorangle,"war_04",TRUE);
				call(KeyObjTrigger,255,1);
			}
		}		
		CurEnvTrigger("BOXCTRL");
		if(VKeyObjFrame==10)
		{
			CurEnvTrigger("blocking");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
		}
		CurEnvTrigger("BOXCTRL");
		//	within collision sphere &&	'enter' pressed
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			if(VarKey29&=8 || VarKey29&=16)
			{
				call(activatebutton,"Lift blocked",-1,FALSE);
				call(ActivateButtonSample,SFXInValidFunction);
			}
			else
			{
				if(VAIClass==_AIClassScientist && Vrank==_RankScum) // is a Radiation Worker
				{
					if(VKeyObjFrame==0)
					{
						if(VkeyObjTriggered==0) // if the animation has not been triggered
						{
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction); // clears the ACTION button
							call(activatebutton,"Lift activated.",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
							float(_set,TmpFloat,0x00ff00);   // green
							call(expset1,1,TmpFloat,0); //set color of control panel to green
							float(_set,timer,5);
						}
					}
					else
					{
						call(activatebutton,"Lift already activated.",-1,FALSE);
						call(ActivateButtonSample,SFXInValidFunction);
					}
				}
				else
				{
					if(VAIClass==_AIClassAngel)
					{
						call(activatebutton,"I just don't get it !",-1,FALSE);
						call(ActivateButtonSample,SFXInValidFunction);
					}
					else
					{
						call(activatebutton,"Authorized Nuclear Technicians Only",-1,FALSE);
						call(ActivateButtonSample,SFXInValidFunction);
					}
				}
			}
			Direction(_clr,_DIRaction);
		}

		if(VarKey27==12)
		{
			call(ChangeFog,_SXFogType,_SXFogExp);
			float(_set,TmpFloat,0.0007);
			call(ChangeFog,_SXFogDensity,TmpFloat);
		}
		if(VarKey27==14 || VarKey27==0)
		{
			call(ChangeFog,_SXFogType,_SXFogOff);
		}

		CurEnvTrigger("beldoor01");
		callsub(StartDoorDelay,1);

		CurEnvTrigger("beldoor");
		callsub(StartDoorDelay,2);


		CurEnvTrigger("droid");
		vector(_set,TmpVector,45,130,70);
		Call(TriggerBox,TmpVector,0,tmpfloat);
		if(tmpfloat==1)
		{
			if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger)
			{
				if(VClass!=_ClassAngel)
				{
					if(VAIClass==_AIclassworker || VAIClass==_AIclassscientist)
					{
						CurEnvTriggerSet("el_x03","lift");
						if(VKeyObjFrame==2)
						{
							if(VAICON==0)
							{
								call(ActivateButton,"Rad-Bot Engaged",-1,FALSE);
								call(ActivateButtonSample,SFXValidFunction);
								sample(SFXTransferSectorRad,-1);
								call(AIcheckvisionbuffer,_AIclasscop,0,0,0);
								if(VTrigger==_DIRTempFlag)
								{
									float(_or,VarKey29,4);
									float(_set,timer,25);
								}
							}
							call(KeyObjTrigger,4,1);
							CurEnvTrigger("droid");
							float(_set,TmpFloat,0xffff00);
							call(expset1,1,TmpFloat,0);
							float(_set,VarKey30,4);
						}
						else
						{
							if(VAICON==0)
							{
								call(ActivateButton,"Rad-Bot Not Detected On This Floor",-1,FALSE);
								call(ActivateButtonSample,SFXInvalidFunction);
							}
						}
					direction(_clr,_DIRaction);
					}

					else
					{
						if(VAICON==0)
						{
							call(ActivateButton,"Working Staff Only",-1,FALSE);
							sample(SFXUnrecognized,Gactorpos);
						}
					}
				}
				else
				{
					if(VAICON==0)
					{
						call(ActivateButton,"can't reach ...need to find a host",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
					direction(_clr,_DIRaction);
				}
			}
		}
		callsub(IllegalButtonReact);
	}
	elseif(VCurSet=="stor_01")
	{
		CurEnvTrigger("Door2Trig");
		if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger)
		{
			if(VarKey23<670)
			{
				message("Door power is off",120,10);
				sample(SFXInvalidFunction,-1);
				direction(_clr,_DIRaction);		
			}
			else
			{
				callsub(StartDoorDelay,3);
			}
		}


		CurEnvTrigger("WorkFix");
		if(VTrigger==_DIRaction && VTrigger==_DIREnvTrigger)
		{
			CurEnvTrigger("Door2Trig");
			if(VKeyObjTriggered==0)
			{
				if(VarKey23<670)
				{
					if(VAIclass==_AIclassworker)
					{
						float(_set,ControlTimer,3);
						call(KeyObjTrigger,255,1);
						Direction(_clr,_DIRaction);
						Sample(SFXLatch1,-1);
						message("Testing door power",120,10);
					}
					else
					{
						message("Only workers can figure this out",120,10);
						sample(SFXInvalidFunction,-1);
						direction(_clr,_DIRaction);		
					}
				}
				else
				{
					message("If it's not broken@ don't fix it",120,10);
				}
			}
		}

		if(VarKey24==3)	
		{
			float(_set,VarKey24,4);	
			vector(_set,Gactorpos,-13819,24073,25200);
			vector(_set,Gactorangle,0,1024,0);
			InitActor(Medic,Gactorpos,Gactorangle,"stor_01",TRUE,1);

			CurEnvTrigger("spcheck");
			callsub(DoorOpen,1,0);
		}

		if(VarKey24!=0)
		{
			CurEnvTrigger("tanklift");
			if(VTrigger==_DIRaction&&VTrigger==_DIREnvTrigger)
			{
				if(VClass!=_ClassAngel)
				{
					if(VAIClass==_AIClassWorker)
					{
						if(VAICON==0)
						{
							call(ActivateButton,"Tank Lift Control Error - System Jammed",-1,FALSE);
							call(ActivateButtonSample,SFXInvalidFunction);
						}
					}
					else
					{
						if(VAICON==0)
						{
							call(ActivateButton,"Only Workers can use this device",-1,FALSE);
							call(ActivateButtonSample,SFXUnrecognized);
						}
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					if(VAICON==0)
					{
						call(ActivateButton,"Only Workers can use this device",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
			}
		}

		if(VarKey24==0)
		{
			CurEnvTrigger("tanklift");
			if(VTrigger==_DIRaction&&VTrigger==_DIREnvTrigger)
			{
				if(VClass!=_ClassAngel)
				{
					if(VAIClass==_AIClassWorker)
					{
						call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
						call(ActivateButton,"Tank lift activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						call(KeyObjTrigger,3,1);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
						sample(SFXWorkerpanic,Gactorpos);
//						kfsample(SFXWorkerPanic,SFXWorkerScream,-1,SFXWorkerCrushed);
						direction(_clr,_DIRaction);
						float(_set,VarKey24,1);
					}
					else
					{
						if(VAICON==0)
						{
							call(ActivateButton,"Only Workers can use this device",-1,FALSE);
							call(ActivateButtonSample,SFXUnrecognized);
						}
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					if(VAICON==0)
					{
						call(ActivateButton,"Slap@slap@slap.....nothing!",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
			}
		}
		elseif(VarKey24==1)
		{
			CurEnvTrigger("tanklift");
			if(VAIClass==_AIClassWorker)
			{
				if(VAction==WorkerWeldingOnBench && VKeyObjTriggered!=0)
				{
					SpawnAction(WorkerCrushedOnBench);
				}
				elseif(VAction==WorkerCrushedOnBench && VKeyObjFrameNoShift>=139262&&VKeyObjFrameNoShift<=155646)
				{
					float(_set,VarKey24,2);	//worker is officially dead
					float(_set,VarKey25,0);	//set medic delay counter to zero
				}
			}
		}
		elseif(VarKey24==2 && VarKey25>=250)		//the worker has been crushed
		{
			float(_set,VarKey24,3);				//medic is on his way
			float(_set,VarKey25,0);				//re-init, can be used again from now on
		}

		if(VAICon==0)
		{
			GetNumbActorsInSet("stor_01",_AIClassScientist,TmpFloat);
			GetNumbActorsInSet("stor_01",_AIClassCop,TmpFloat1);
			if(TmpFloat==0 && TmpFloat1==0)
			{
				CurEnvTrigger("spcheck");
				if(VKeyObjTriggered==0 && VKeyObjFrame==0)
				{
					vector(_set,Gactorangle,0,1024,0);
					vector(_set,Gactorpos,-13819,24123,25200);
					InitActor(WeaponPumpgun,Gactorpos,Gactorangle,"stor_01",FALSE);
					vector(_set,Gactorpos,-13819,24073,25200);
					InitActor(copl,Gactorpos,Gactorangle,"stor_01",FALSE);

					callsub(DoorOpen,1,0);
				}
			}
		}

		CurEnvTrigger("door2ent");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				if(VAIClass==_AIClassCop || VAIClass==_AIClassScientist)
				{
					callsub(StartDoorDelay,2);
					if(TmpFloat==1)
					{
						//sto1/sto4 door steam fx
						float(_set,dooropenLife,190);
						float(_set,dooropenCount1,0);
						float(_set,dooropenCount2,0);
						float(_set,dooropenCount3,0);
						float(_set,dooropenCount4,0);
						float(_set,dooropenCount5,0);
						float(_set,dooropenTime,0);
						float(_set,dooropenCurr,0);
					}
				}
				elseif(VAICON==0)
				{
					sample(SFXAccessDenied,Gactorpos);
					message("Restricted area@ security and medical staff only",120,10);
					direction(_clr,_DIRaction);		
				}
			}
		}


		CurEnvTrigger("DOORSTO1");
		callsub(StartDoorDelay,1);
		if(TmpFloat==1)
		{
			float(_set,dooropenLife,190);
			float(_set,dooropenCount1,0);
			float(_set,dooropenCount2,0);
			float(_set,dooropenCount3,0);
			float(_set,dooropenCount4,0);
			float(_set,dooropenCount5,0);
			float(_set,dooropenTime,0);
			float(_set,dooropenCurr,1);
		}


		CurEnvTrigger("sto1wall1");
		if(VTrigger==_DIRaction&&VTrigger==_DIREnvTrigger&&VAICON==0)
		{
			if(VAICON==0)
			{
				sample(SFXAccessDenied,Gactorpos);
				message("Annex Security Circuits Engaged",120,10);
			}
			direction(_clr,_DIRaction);		
		}
	}
	elseif(VCurSet=="STOR_02")
	{
		CurEnvTrigger("stor2elva");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey23<1 || VarKey23>360)//can't open elevator door until sequence complete (2 cops come-up in elevator)
			{
				setkeyframe("el_sml","els_elvt",1);
				callsub(DoorOpen,0,1);
			}
		}
	
		CurEnvTrigger("Door2trig");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey28&!=1)
			{
				sample(SFXAccessDenied,GActorPos);//2d sound based on position of actor
				message("Door power is off",120,10);//120=duration on screen, 10=font size
			}
			else
			{
				callsub(StartDoorDelay,1);
			}
		}

		CurEnvTrigger("noaction");
		if(VTrigger==_DIREnvTrigger && VAICon==0)
		{
			CurEnvTrigger("arme");
			if(VKeyObjTriggered!=0)
			{
				direction(_clr,_DIRaction);
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
					vector(_set,Gactorpos,-13189,25231,26763);
					vector(_set,Gactorangle,0,1024,0);
					InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"stor_02",TRUE);
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
		CurEnvTrigger("console");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAICON==0)
			{
				if(VClass!=_ClassAngel)
				{
					if (VarKey22&!=16)
					{
						CurEnvTrigger("Door2trig");
						if(VKeyObjTriggered!=0)
						{
							call(ActivateButton,"Can't engage power while doors are being tested",-1,FALSE);
						}
						else
						{
							CurEnvTrigger("stor2elva");
							if(VKeyObjTriggered==0)
							{
								CurEnvTrigger("console");
								float(_set,TmpFloat,0x0000ff);
								call(expset1,1,TmpFloat,0);
								call(expset2,57,165,225);

								call(ActivateButton,"Power To Elevator Engaged",-1,FALSE);
								call(ActivateButtonSample,SFXValidFunction);
								direction(_clr,_DIRaction);

								GetNumbActorsInSet("stor_02",_AIclasscop,TmpFloat);
								if(TmpFloat!=0)
								{
									call(AIchangeplayertoenemy);
									float(_or,VarKey29,4);
								}
								float(_or,VarKey22,16);
							}
							else
							{
								call(ActivateButton,"Elevator Doors Are Open",-1,FALSE);
								call(ActivateButtonSample,SFXInvalidFunction);
							}								
						}
					}
					else
					{
						call(ActivateButton,"ELEVATOR ALREADY OPERATIONAL",-1,FALSE);
					}
				}
				else
				{
					call(ActivateButton,"Hmmm@ I wonder what this one does!",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
			direction(_clr,_DIRaction);
		}

		if(VarKey29&=4 && VAICon!=0 && VAIClass==_AIclasscop)
		{
			float(_clr,VarKey29,4);
			sample(SFXPlayerActivatesButtonReact,-1);
		}


		if(VarKey22&=16 && VarKey23==0 && VarKey28&!=1)
		{
			if(timer3>=0 && timer3<=50)
			{
				float(_add,timer3,1);
			}
			if(timer3==51)
			{
				sample(SFXElevatorOn,Gactorpos);
				float(_set,VarKey23,1);	//start alarm and cop stuff
				float(_set,timer3,0);
			}
		}
	}


	//allows you start off in city streets
	elseif(VCurSet=="walls1" || VCurSet=="walls2" || VCurSet=="walls4")
	{
		if(VRunScriptCode!=18 && VAICon==0)
		{
			callsub(DeInitSceneSound5);
			call(RunScriptCode,_clr,5);
			call(RunScriptCode,_or,18);
		}	
	}

	elseif(VCurSet=="wast1")
	{
		if(VRunScriptCode!=10 && VAICon==0)
		{
			callsub(DeInitSceneSound5);
			call(RunScriptCode,_clr,5);
			call(RunScriptCode,_or,10);
		}
	}
	elseif(VCurSet=="fact_7")
	{
		if(VRunScriptCode!=7 && VAICon==0)
		{
			callsub(DeInitSceneSound5);
			call(RunScriptCode,_clr,5);
			call(RunScriptCode,_or,7);
		}
	}
}
