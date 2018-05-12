//+---------------------------+
//|SCRIPT FOR FACTORY         |
//|		SCENE		= SCENE7  |
//|		MENUNAME	= "fakk"  |
//+---------------------------+
//CameraPan	- Not Used
//VarKey31	-	Laserwall in fact_19 (bridge up/down)
//VarKey32	-	100 Doors in factory opened (Fact_1)
//VarKey33	-	weapon construction camera handler in Fact_17
//VarKey34	-	weapon construction sound handler in Fact_17
//VarKey35		beserker cannon in fact_20
//VarKey36	- Elevator Power
//VarKey37	- Whether or not fact_2 is active	(could be useless)
//VarKey38	- For helicopter position	(0 to 60, 0 == all the way left.  60 == all the way right)
//VarKey39	- For helicopter direction. (0==Heli not moving, 1==Heli moving left to right.  -1==Right to left)
//VarKey40	- Bit flags for this level
//				o  Bits 0,1 and 2 are for scientist sequence in Fact_1
//FurnaceTimer1			- These are for the flaming ballz in Fact_2
//FurnaceTimer2			- These are for the flaming ballz in Fact_2
//FurnaceTimer3			- These are for the flaming ballz in Fact_2
//FurnaceTimer4			- These are for the flaming ballz in Fact_2
//WepConstructionTimer	- For the weapon creation process in Fact_17
//GunTurretKey			- For the GunTurret sequence in Fact_20/21
//MaserKey				- For the Maser Charging sequence (MaserKey>=3 means Maser is charged)
//SecurityTimer			- The the "Get back to work" sequence for scientists in fact_1/3
//VarBit
//-----
// Help01	>	Story Message #16
// Help02	>	Story Message #17


//#######################################################################
//#######################################################################
//##                                                                   ##
//##                         INITSCENESOUND                            ##
//##                                                                   ##
//#######################################################################
//#######################################################################
SubRoutine(InitSceneSound7)
{
		if(incoming!=0)
		{
			if(ScriptMark==16)
			{
				callsub(Panel16);
			}
			elseif(ScriptMark==17)
			{
				callsub(Panel17);
			}
		}
		else
		{
			callsub(ScriptLevel7);
		}
		//fact 7
		vector(_set,gactorpos,-11852,25280,19365);
		sample(SFXIndustrial9,gactorpos);

		//fact 9
		vector(_set,gactorpos,-9733,25277,20283);
		sample(SFXRain2,gactorpos);


		//fact 23
		vector(_set,gactorpos,-10334,25129,16222);
		sample(SFXRain2,gactorpos);

		vector(_set,gactorpos,-9135,25129,16222);
		sample(SFXRain2,gactorpos);

		
		//fact 17
		vector(_set,gactorpos,-8270,24800,17810);
		sample(SFXGenericOsc3,gactorpos);

		//fact 20 / fact 21
		vector(_set,gactorpos,-8200,25620,18900);
		sample(SFXIndusGears,gactorpos);

		vector(_set,gactorpos,-7700,24600,18888);
		sample(SFXWind,gactorpos);

		//fact_14
		vector(_set,gactorpos,-11401,22271,18226);
		sample(SFXSewerHammer,gactorpos);

		vector(_set,gactorpos,-10783,24800,19360);
		sample(SFXFlamesBurning,gactorpos);


		//piston
		vector(_set,Gactorpos,-10493, 22622, 18163);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-9459, 22622, 18056);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-8202, 22622, 18063);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-7123, 22622, 18063);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6196, 22622, 18536);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6909, 22622, 19176);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6187, 22622, 19943);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6597, 22622, 20782);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-7292, 22622, 20183);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-8523, 22622, 20109);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-9245, 22622, 20989);
		sample(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-10261, 22622, 20476);
		sample(SFXPiston,gactorpos);

		call(CDPlay,7,1);
}


//#######################################################################
//#######################################################################
//##                                                                   ##
//##                        DEINITSCENESOUND                           ##
//##                                                                   ##
//#######################################################################
//#######################################################################
SubRoutine(DeInitSceneSound7)
{
		//fact 7
		vector(_set,gactorpos,-11852,25280,19365);
		samplestop(SFXIndustrial9,gactorpos);

		//fact 9
		vector(_set,gactorpos,-9733,25277,20283);
		samplestop(SFXRain2,gactorpos);

		//fact 23
		vector(_set,gactorpos,-10334,25129,16222);
		sample(SFXRain2,gactorpos);
		vector(_set,gactorpos,-9135,25129,16222);
		sample(SFXRain2,gactorpos);

		
		//fact 17
		vector(_set,gactorpos,-8270,24800,17810);
		samplestop(SFXGenericOsc3,gactorpos);

		//fact 20 / fact 21
		vector(_set,gactorpos,-8200,25620,18900);
		samplestop(SFXIndusGears,gactorpos);
		vector(_set,gactorpos,-7700,24600,18888);
		samplestop(SFXWind,gactorpos);

		//fact_14
		vector(_set,gactorpos,-11401,22271,18226);
		samplestop(SFXSewerHammer,gactorpos);

		vector(_set,gactorpos,-10783,24800,19360);
		samplestop(SFXFlamesBurning,gactorpos);

		//fact_19
		vector(_set,Gactorpos,-11383,23599,19087);
		samplestop(SFXElecFenceBlue,Gactorpos);



		//piston
		vector(_set,Gactorpos,-10493, 22622, 18163);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-9459, 22622, 18056);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-8202, 22622, 18063);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-7123, 22622, 18063);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6196, 22622, 18536);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6909, 22622, 19176);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6187, 22622, 19943);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-6597, 22622, 20782);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-7292, 22622, 20183);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-8523, 22622, 20109);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-9245, 22622, 20989);
		samplestop(SFXPiston,gactorpos);
		vector(_set,Gactorpos,-10261, 22622, 20476);
		samplestop(SFXPiston,gactorpos);
}

//#######################################################################
//#######################################################################
//##                                                                   ##
//##                            INITSCENE                              ##
//##                                                                   ##
//#######################################################################
//#######################################################################
SubRoutine(InitScene7)
{
		if(VScriptInitiated!=7)
		{
			if(VInitScriptCode==0)
			{
				vector(_set,Gactorangle,0,0,0);
				InitActor(Bob1,0,Gactorangle,"fact_7");
			}


			#include	"messiahscripts\enemies\c2_factory.spt"
			#include	"messiahscripts\enemies\c2_factlow.spt"
			#include	"messiahscripts\enemies\c2_pistons.spt"

			// Reset all the variables
			call(loadpreloaddb,13);
			float(_set,VarKey31,0);
			float(_set,VarKey32,0);
			float(_set,VarKey33,0);
			float(_set,VarKey34,0);
			float(_set,VarKey35,0);
			float(_set,VarKey36,0);	//Elevator power varialbe
			float(_set,VarKey37,0);
			float(_set,VarKey38,60);	//For helicopter location  (0-100)
			float(_set,VarKey39,1);	//For helicopter direction (-1,0,1)
			float(_set,VarKey40,0);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);
			float(_set,CameraPan,0);
			float(_set,Objective,0);
			float(_set,FurnaceTimer1,0);
			float(_set,FurnaceTimer2,0);
			float(_set,FurnaceTimer3,0);
			float(_set,FurnaceTimer4,0);
			float(_set,FlicBits,0);

			float(_set,WepConstructionTimer,0);
			float(_set,GunTurretKey,0);
			float(_set,MaserKey,1);		
			float(_set,SecurityTimer,0);
		}

		callsub(InitSceneSound7);
		call(ScriptCodeInitiated,7);

}




//#######################################################################
//#######################################################################
//##                                                                   ##
//##                            MAINSCENE                              ##
//##                                                                   ##
//#######################################################################
//#######################################################################
SubRoutine(MainScene7)
{
	if(VCurSet=="rlrat1" || VCurSet=="rlrat2")
	{
		ActorFlag(_or,_AFLAGNoDepossession);
	}
	elseif(VCurSet=="rlhsin")
	{
		ActorFlag(_clr,_AFLAGNoDepossession);
	}

	
	
	//Clears bits that check for scientists switching positions in Fact_1
	float(_clr,varkey40,0x00000003);

	if(GunTurretKey>=3 && GunTurretKey<300)
	{
		float(_add,GunTurretKey,1);
	}


/*	if(VSetActive=="pston_1")
	{
		CurEnvTriggerSet("pston_1","lite");
		float(_set,TmpFloat,0x2277ff);
		call(expset1,TmpFloat,400,-1);
	}
	if(VSetActive=="pston_2")
	{
		CurEnvTriggerSet("pston_2","lite");
		float(_set,TmpFloat,0x2277ff);
		call(expset1,TmpFloat,400,-1);
		call(expset2,TmpFloat,400,-1);
		CurEnvTriggerSet("pston_2","lite2");
		float(_set,TmpFloat,0x2277ff);
		call(expset1,TmpFloat,400,-1);
		call(expset2,TmpFloat,400,-1);

	}
	if(VSetActive=="pston_3")
	{
		CurEnvTriggerSet("pston_3","lite");
		float(_set,TmpFloat,0x2277ff);
		call(expset1,TmpFloat,400,-1);
		call(expset2,TmpFloat,400,-1);
		CurEnvTriggerSet("pston_3","lite2");
		float(_set,TmpFloat,0x2277ff);
		call(expset1,TmpFloat,400,-1);

	}
	if(VSetActive=="pston_4")
	{
		CurEnvTriggerSet("pston_4","lite");
		float(_set,TmpFloat,0x2277ff);
		call(expset1,TmpFloat,400,-1);
		call(expset2,TmpFloat,400,-1);
		CurEnvTriggerSet("pston_4","lite2");
		float(_set,TmpFloat,0x2277ff);
		call(expset1,TmpFloat,400,-1);
	}
*/

	//FACT_1 IS ACTIVE	(Security Room.  2nd Room in level)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors for the doors and for the console.  Based on
	//whether security doors are unlocked (varkey32==100 means doors unlocked
	//-----------------------------------------------------------------
	if(VSetActive=="fact_1")
	{
		if(varkey32!=100)
		{
			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("fact_1","trigdoor1");		
			call(expSet1,1,tmpfloat,0);

			CurEnvTriggerSet("fact_1","trigdoor2");
			call(expSet1,1,tmpfloat,0);

			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("fact_1","dt_door");
			call(ExpSet1,1,tmpfloat,0);
		}
		elseif(varkey32==100)
		{
			float(_set,tmpfloat,0x00FF00);
			CurEnvTriggerSet("fact_1","trigdoor1");
			call(expSet1,1,tmpfloat,0);

			CurEnvTriggerSet("fact_1","trigdoor2");
			call(expSet1,1,tmpfloat,0);

			float(_set,tmpfloat,0x0000FF);
			CurEnvTriggerSet("fact_1","dt_door");
			call(ExpSet1,1,tmpfloat,0);
		}

		CurEnvTriggerSet("fact_1","ledge01");
		call(ExpGet,1,tmpfloat);
		if(FlicBits&=0x100)
		{
			if(tmpfloat>=508 && tmpfloat<509)
			{
				call(ExpSet1,510,510,550);
			}
			elseif(VCurSet!="fact_7" && VCurSet!="fact_1" && VCurSet!="fact_2")
			{
				if(tmpfloat<510)
				{
					call(ExpSet1,510,510,550);
				}
			}
		}
	}
	//=================================================================



	//FACT_2 IS ACTIVE	(Furnace room)
	//=================================================================
	//_________________________________________________________________
	//Randomly spits fireballs from furnace pit and also keeps constant
	//fireballs at the mouth of pit (for fire effects).  Msika knows how
	//this works if you cant find me about it (Joe).
	//-----------------------------------------------------------------
	if(VSetActive=="fact_2")
	{
		call(SetParticleSetID,"fact_2");
		float(_add,FurnaceTimer4,1)
		if(FurnaceTimer4>2)
		{
			float(_set,FurnaceTimer4,1);
		}

		//vector(_set,Gactorpos,-10722.80,25000,19377.80);
		//vector(_set,Gactorine,0,10,0);
		//SpawnParticle(fx_mainexplosion,-1,Gactorpos,Gactorine,-1);
		if(FurnaceTimer4==1)
		{
			vector(_set,Gactorpos,-10800,25000,19450);
			vector(_set,Gactorine,0,10,0);
			SpawnParticle(fx_mainexplosion,-1,Gactorpos,Gactorine,-1);
		}
		elseif(FurnaceTimer4==2)
		{	
			vector(_set,Gactorpos,-10800,25000,19150);
			vector(_set,Gactorine,0,10,0);
			spawnParticle(fx_mainexplosion,-1,Gactorpos,Gactorine,-1);
		}


		if (FurnaceTimer1<24900 && FurnaceTimer1!=0)
		{
			float(_set,FurnaceTimer1,0);
		}
		
		if(FurnaceTimer1==0)
		{
			if(vrnd==1 || vrnd==4)
			{
				float(_set,FurnaceTimer1,24900);
				vector(_set,Gactorpos,-10783,24800,19499.59);
				vector(_set,Gactorine,0,10,0);
				sample(SFXBazookaExplode,gactorpos);
			}
		}

		else
		{
			if(FurnaceTimer1<=25300)
			{
				float(_add,FurnaceTimer1,50);
				vector(_setx,gactorpos,-10783);
				vector(_sety,gactorpos,FurnaceTimer1);
				vector(_setz,gactorpos,19499.59);

				vector(_set,Gactorine,0,10,0);
				SpawnParticle(fx_mainexplosion2,-1,Gactorpos,Gactorine,-1);

				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);	//spawnlight(name,bone,position,color,radius)
			}
			else
			{
				float(_set,FurnaceTimer1,0);
			}
		}


		
		if (FurnaceTimer2<24900 && FurnaceTimer2!=0)
		{
			float(_set,FurnaceTimer2,0);
		}
		
		if(FurnaceTimer2==0)
		{
			if(vrnd==2 || vrnd==5)
			{
				float(_set,FurnaceTimer2,24900);
				vector(_set,Gactorpos,-10783,24800,19360);
				vector(_set,Gactorine,0,10,0);
				sample(SFXBazookaExplode,gactorpos);
			}
		}
		else
		{
			if(FurnaceTimer2<=25300)
			{
				float(_add,FurnaceTimer2,50);
				vector(_setx,gactorpos,-10783);
				vector(_sety,gactorpos,FurnaceTimer2);
				vector(_setz,gactorpos,19360);

				vector(_set,Gactorine,0,10,0);
				SpawnParticle(fx_mainexplosion2,-1,Gactorpos,Gactorine,-1);

				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);	//spawnlight(name,bone,position,color,radius)
			}
			else
			{
				float(_set,FurnaceTimer2,0);
			}
		}

		if (FurnaceTimer3<24900 && FurnaceTimer3!=0)
		{
			float(_set,FurnaceTimer3,0);
		}
		
		if(FurnaceTimer3==0)
		{
			if(vrnd==3 || vrnd==6)
			{
				float(_set,FurnaceTimer3,24900);
				vector(_set,Gactorpos,-10783.40,24800,19156.50);
				vector(_set,Gactorine,0,10,0);
				sample(SFXBazookaExplode,gactorpos);
			}
		}
		else
		{
			if(FurnaceTimer3<=25300)
			{
				float(_add,FurnaceTimer3,50);
				vector(_setx,gactorpos,-10783.40);
				vector(_sety,gactorpos,FurnaceTimer3);
				vector(_setz,gactorpos,19156.50);

				vector(_set,Gactorine,0,10,0);
				SpawnParticle(fx_mainexplosion2,-1,Gactorpos,Gactorine,-1);

				vector(_set,tmpvector,230,85,15);
				spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);	//spawnlight(name,bone,position,color,radius)
			}
			else
			{
				float(_set,FurnaceTimer3,0);
			}
		}
	}
	//=================================================================


	
	//FACT_3 IS ACTIVE	(Courtyard.  Level exit from here)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlights for room.  Exit door needs maserkey>=4 to be green.
	//Door to fact_1 is always green.  Elevator needs elevator power (varkey36==1).
	//-----------------------------------------------------------------
	if(VSetActive=="fact_3")
	{
		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerSet("fact_3","trigdoor1");  // door from fact_1
		call(expSet1,1,tmpfloat,0);

		if(MaserKey<4)
		{
			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("fact_3","trigdoor2");  // level exit
			call(expSet1,1,tmpfloat,0);
		}
		else
		{
			float(_set,tmpfloat,0x00FF00);
			CurEnvTriggerSet("fact_3","trigdoor2");  // level exit
			call(expSet1,1,tmpfloat,0);
		}

		if(varkey36==0)
		{
			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("fact_3","trigdoor3");  // elevator door
			call(expSet1,1,tmpfloat,0);
		}
		elseif(varkey36==1)
		{
			float(_set,tmpfloat,0x00FF00);
			CurEnvTriggerSet("fact_3","trigdoor3");
			call(expSet1,1,tmpfloat,0);
		}
	}
	//=================================================================


	
	//FACT_4 IS ACTIVE	(Elevator to Courtyard, Hallway, and Lower Factory)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlights and elevator indicators for elevator.  If you dont
	//understand it you are dumb.
	//-----------------------------------------------------------------
	if(VSetActive=="fact_4")
	{
		CurEnvTriggerSet("Fact_4","lift");
		float(_set,TmpFloat,0x777711);  // brown-green
		float(_set,TmpFloat2,0xffff000); // yellow
		float(_set,TmpFloat1,0xff7722);   // orange
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator

		float(_set,tmpfloat,0x00FF00);
		CurEnvTriggerSet("fact_4","doortrig1");
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("fact_4","doortrig2");
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("fact_4","doortrig3");
		call(expSet1,1,tmpfloat,0);
	}
	//=================================================================



	//FACT_5 IS ACTIVE	(Room for level exit)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors.  The only door is always green
	//-----------------------------------------------------------------
	if(Vsetactive=="fact_5")
	{
		CurEnvTriggerSet("FACT_5","FACT5DOOR");
		float(_set,tmpfloat,0x00FF00);     //set lights to green
		call(expSet1,1,tmpfloat,0);
	}
	//=================================================================



	//FACT_6 IS ACTIVE	(First room in Lower Factory)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors.  Elevator door is always green.  Door leading
	//to loft is always red
	//-----------------------------------------------------------------
	if(VSetActive=="fact_6")
	{
		CurEnvTriggerSet("FACT_6","TRIGDOOR1");
		float(_set,tmpfloat,0xFF0000);  //set lights to red
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("FACT_6","TRIGDOOR2");
		float(_set,tmpfloat,0x00FF00);  //set lights to green
		call(expSet1,1,tmpfloat,0);
	}
	//=================================================================



	//FACT_7 IS ACTIVE	(Starting Room)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors. Only door is always red.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_7")
	{
		CurEnvTriggerSet("FACT_7","ENTRANCE");
		float(_set,tmpfloat,0xFF0000);     //set lights to red
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("fact_7","console");
		call(ExpGet,1,tmpfloat);
		if(FlicBits&!=0x100)
		{
			if(tmpfloat<510)
			{
				call(ExpSet1,510,510,550);
			}
			elseif(tmpfloat<510)
			{
				print("Flic frame: ",tmpfloat);
			}
		}
		else
		{
			if(tmpfloat>=508 && tmpfloat<509)
			{
				call(ExpSet1,510,510,550);
				if(VCDTrack!=7)
				{
					call(CDSwap,7,1,100,60);
					call(CDFade,100,90);
				}
			}
		}
	}
	//=================================================================


	
	//FACT_8 IS ACTIVE	(Leads to loft area and Fact_6 (First room in lower factory))
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors. All doors are always green.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_8")
	{
		CurEnvTriggerSet("FACT_8","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);  //sets lights to green
		call(expSet1,1,TmpFloat,0);

		CurEnvTriggerSet("FACT_8","TRIGDOOR2");
		float(_set,TmpFloat,0x00FF00);  //sets lights to green
		call(expSet1,1,TmpFloat,0);
	}
	//=================================================================



	//FACT_9 IS ACTIVE	(Leads to Courtyard and to Weapon Testing area)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors. All doors are always green.
	//-----------------------------------------------------------------
	if(VSetActive=="fact_9")
	{
		CurEnvTriggerSet("FACT_9","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);     //set lights to green
		call(expSet1,1,TmpFloat,0);
	}
	//=================================================================

	
	
	//FACT_10 IS ACTIVE	(Loft area.)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors. Door to Maser Charging room is red, other is
	//green.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_10")
	{
		CurEnvTriggerSet("FACT_10","TRIGDOOR1");
		float(_set,TmpFloat,0xFF0000);     //set access lights to red
		call(expSet1,1,TmpFloat,0);

		CurEnVTriggerSet("FACT_10","TRIGDOOR2");
		float(_set,TmpFloat,0x00FF00);     //set access lights to green
		call(expSet1,1,TmpFloat,0);

	}
	//=================================================================



	//FACT_11 IS ACTIVE	(Chamber leads to Loft and Maser Charging room)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors. Both doors are always green.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_11")
	{
		CurEnvTriggerSet("FACT_11","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);     //set access lights to green
		call(expSet1,1,TmpFloat,0);

		CurEnvTriggerSet("FACT_11","TRIGDOOR2");
		float(_set,TmpFloat,0x00FF00);     //set access lights to green
		call(expSet1,1,TmpFloat,0);

	}
	//=================================================================



	//FACT_14 IS ACTIVE	(Wheel room in lower factory.  Leads to Piston area)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors. All doors are always green.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_14")
	{
		CurEnvTriggerSet("FACT_14","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);     //set access lights to green
		call(expSet1,1,TmpFloat,0);

	}
	//=================================================================



	//FACT_16 IS ACTIVE	(Elevator from Weapon Charging room to Hallway)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors and elevator lights. All doors are always green.
	//-----------------------------------------------------------------
	if(VSetActive=="fact_16")
	{
		CurEnvTriggerSet("Fact_16","lift");
		float(_set,TmpFloat,0x777711);  // brown-green
		float(_set,TmpFloat2,0xffff000); // yellow
		float(_set,TmpFloat1,0xff7722);   // orange
		call(expset1,4,TmpFloat,TmpFloat1); //lift direction
		call(expset2,3,TmpFloat,TmpFloat2); //floor indicator

		CurEnvTriggerSet("FACT_16","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);
		call(expSet1,1,TmpFloat,0);

		CurEnvTriggerSet("FACT_16","TRIGDOOR3");
		float(_set,TmpFloat,0x00FF00);
		call(expSet1,1,TmpFloat,0);
	}
	//=================================================================


	//FACT_17 IS ACTIVE	(Maser Creation Room)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight and console panel colors.  Door to elevator is red
	//until elevator power is enabled AND maser is built and retrieved.
	//Console for maser creation is red if not yet used and blue if
	//used (VarKey33>0 && Varkey33<6 means used.)  Green is set in vcurset.
	//Console for Maser retrieval is Green if ready to be retrieved 
	//(VarKey33==3), blue if already retrieved (VarKey33>=3 && Varkey33<=5)
	//and red if not yet built (all other values for VarKey33).
	//
	//Effects are also done for Maser retrieval sequence.
	//(When wepconstructiontimer != 0).
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_17")
	{
		if(VarKey36==1)
		{
			CurEnvTriggerSet("fact_17","trigdoor1");
			float(_set,TmpFloat,0x00FF00);
			call(expSet1,1,TmpFloat,0);
		}
		else
		{
			CurEnvTriggerSet("fact_17","trigdoor1");
			float(_set,TmpFloat,0xFF0000);
			call(expSet1,1,TmpFloat,0);
		}

		if(VarKey33==0 || VarKey33==6)
		{
			CurEnvTriggerSet("fact_17a","console");
			float(_set,TmpFloat,0xFF0000);
			call(expSet1,1,TmpFloat,0);
		}
		else
		{
			CurEnvTriggerSet("fact_17a","console");
			float(_set,TmpFloat,0x0000FF);
			call(expSet1,1,TmpFloat,0);
		}

		if(VarKey33==3)
		{
			CurEnvTriggerSet("fact_17","getwepn");
			float(_set,TmpFloat,0x00FF00);
			call(expSet1,1,TmpFloat,0);
		}
		elseif(VarKey33>=3 && VarKey33<=5)
		{
			CurEnvTriggerSet("fact_17","getwepn");
			float(_set,TmpFloat,0x0000FF);
			call(expSet1,1,TmpFloat,0);
		}
		else
		{
			CurEnvTriggerSet("fact_17","getwepn");
			float(_set,TmpFloat,0xFF0000);
			call(expSet1,1,TmpFloat,0);
		}


		
		CurEnvTriggerSet("FACT_17","F17F21");
		float(_set,TmpFloat,0x00FF00);
		call(expSet1,1,TmpFloat,0);

		if(VarKey33==5)
		{
			if(WepConstructionTimer!=0)
			{
				float(_set,tmpfloat,WepConstructionTimer);
				float(_add,tmpfloat,120);
				vector(_set,gactorpos,-8540,24528.76,18149.13);
				vector(_set,tmpvector,200,250,180);
				SpawnLight(fire_light4,-1,gactorpos,tmpvector,EmptyVector,tmpfloat);
	
				float(_add,WepConstructionTimer,1);
				if(WepConstructionTimer==90)
				{
					//CurEnvTriggerSet("fact_17","GoDown");
					//Call(KeyObjTrigger,255,1);
				}
				elseif(WepConstructionTimer==180)
				{
					float(_set,WepConstructionTimer,0);
				}
				call(SetParticleSetID,"s1r3");
				vector(_set,gactorpos,-8540,24528.76,18149.13);
				float(_rnd2,tmpfloat,80);
				float(_sub,tmpfloat,40);
				vector(_addx,gactorpos,tmpfloat);
				vector(_set,gactorine,0,0,0);
				float(_rnd2,tmpfloat,30);
				float(_sub,tmpfloat,30);
				vector(_sety,gactorine,tmpfloat);
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
			}
			else
			{
				vector(_set,gactorpos,-8540,24528.76,18149.13);
				vector(_set,tmpvector,200,250,180);
				SpawnLight(fire_light4,-1,gactorpos,tmpvector,EmptyVector,300);
			}
		}
	}
	//=================================================================



	//FACT_19 IS ACTIVE	(Maser Charging Room)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors.  All doors always green.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_19")
	{
		CurEnvTriggerSet("FACT_19","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);     //set access lights to green
		call(expSet1,1,TmpFloat,0);

		CurEnVTriggerSet("FACT_19","TRIGDOOR2");
		float(_set,TmpFloat,0x00FF00);     //set access lights to green
		call(expSet1,1,TmpFloat,0);

		if(MaserKey==4)
		{
			vector(_set,Gactorpos,-11387, 23331, 19569);
			if(vrnd<2)
			{
				sample(SFXZap,Gactorpos);
			}
			elseif(vrnd<8)
			{
				sample(SFXTeslaCoil,Gactorpos);
			}
		}
	}
	//=================================================================



	//FACT_20 IS ACTIVE	(Weapon testing room)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors.  All doors always green.  Also plays effects
	//for GunTurret malfunction.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_20")
	{
		CurEnvTriggerSet("FACT_20","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);     //set lights to green
		call(expSet1,1,TmpFloat,0);
		
		CurEnvTriggerSet("FACT_20","CONSOLE");
		float(_set,TmpFloat,0x00FF00);     //set lights to green
		call(expSet1,1,TmpFloat,0);

		if(GunTurretKey==301)
		{
			vector(_set,gactorpos,-7787,25632,19686);
			vector(_set,tmpvector,150,150,150);
			SpawnLight(dark_light600,-1,gactorpos,tmpvector,EmptyVector,300);
			vector(_set,tmpvector,255,0,0);
			vector(_set,tmpvector1,0,0,1);
			SpawnLight(Lplanelight2,-1,Gactorpos,tmpvector,tmpvector1,1000);
			vector(_set,gactorpos,-7781.88,25600,19750);
			sample(SFXMechanicalFailure,Gactorpos);
			float(_add,GunTurretKey,1);
		}
	}
	//=================================================================


	//FACT_21 IS ACTIVE	(Weapon testing target room)
	//=================================================================
	//_________________________________________________________________
	//Sets doorlight colors.  All doors always green.  Sets console colors
	//for Elevator Power console.  Red if not yet used.  Blue if activated.
	//(VarKey36==1 means elevator power restored).
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_21")
	{	
		CurEnvTriggerSet("FACT_21","TRIGDOOR2");
		float(_set,TmpFloat,0x00FF00);
		call(expSet1,1,TmpFloat,0);			


		if(VarKey36==0)
		{
			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("fact_21","elpower");
			call(ExpSet1,1,tmpfloat,0);
			call(ExpSet2,1,tmpfloat,0);
			CurEnvTriggerSet("fact_21","TRIGDOOR2");
			call(ExpSet2,1,tmpfloat,0);
		}
		else
		{
			float(_set,tmpfloat,0x0000FF);
			CurEnvTriggerSet("fact_21","elpower");
			call(ExpSet1,1,tmpfloat,0);
			float(_set,tmpfloat,0x00FF00);
			call(ExpSet2,1,tmpfloat,0);
			CurEnvTriggerSet("fact_21","TRIGDOOR2");
			call(ExpSet2,1,tmpfloat,0);
		}
	}
	//=================================================================

		
	//MOVEMENT CODE FOR HELICOPTER
	//=================================================================
	//_________________________________________________________________
	//If Varkey39==0 (heli not moving) does a 2 in 600 chance of heli
	//moving again.  If heli is moving... increment Varkey38 (heli position)
	//and test bounds to see if the movement is done.
	//-----------------------------------------------------------------
	if(VSetActive=="Fact_23")
	{
		if(VarKey39==0)
		{
			float(_rnd2,tmpfloat,600);
			float(_round,tmpfloat);
			if(tmpfloat==1)
			{
				float(_set,VarKey39,1);
				float(_set,VarKey38,0);
				if(VSetActive=="fact_23")
				{
					CurEnvTriggerSet("fact_23","FlyByTrg");
					setkeyframe("fact_23","FlyByTrg",0);
					call(KeyObjTrigger,255,1);
					kfsample(-1,SFXHeli,-1,-1,1);
				}
				
			}
			elseif(tmpfloat==2)
			{
				float(_set,VarKey39,-1);
				float(_set,VarKey38,60);
				if(VSetActive=="fact_23")
				{
					CurEnvTriggerSet("fact_23","FlyByTrg");
					setkeyframe("fact_23","FlyByTrg",6);
					call(KeyObjTrigger,0,-1);
					kfsample(-1,SFXHeli,-1,-1,1);
				}
			}
		}
		elseif(VarKey39==1)
		{
			float(_set,tmpfloat,1);
			float(_div,tmpfloat,4);
			float(_add,VarKey38,tmpfloat);
			if(VarKey38>60)
			{
				float(_set,VarKey39,0);
				float(_set,VarKey38,0);
				float(_set,tmpfloat,0x000000);
				CurEnvTriggerSet("fact_23","Heli1");
				call(ExpSet1,1,tmpfloat,0);
				CurEnvTriggerSet("fact_23","Heli2");
				call(ExpSet1,1,tmpfloat,0);
				call(ExpSet2,1,tmpfloat,0);
				CurEnvTriggerSet("fact_23","Heli3");
				call(ExpSet1,1,tmpfloat,0);
				call(ExpSet2,1,tmpfloat,0);
			}
		}
		else
		{
			float(_set,tmpfloat,1);
			float(_div,tmpfloat,4);
			float(_sub,VarKey38,tmpfloat);
			if(VarKey38<0)
			{
				float(_set,VarKey39,0);
				float(_set,VarKey38,0);
				float(_set,tmpfloat,0x000000);
				CurEnvTriggerSet("fact_23","Heli1");
				call(ExpSet1,1,tmpfloat,0);
				CurEnvTriggerSet("fact_23","Heli2");
				call(ExpSet1,1,tmpfloat,0);
				call(ExpSet2,1,tmpfloat,0);
				CurEnvTriggerSet("fact_23","Heli3");
				call(ExpSet1,1,tmpfloat,0);
				call(ExpSet2,1,tmpfloat,0);
			}
		}
	}
	//=================================================================



	//FACT_3 OR FACT_9 IS CURRENT SET	
	//=================================================================
	//_________________________________________________________________
	//Spawns rain and lighting SFX for courtyard
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_3" || VCurSet=="fact_9")
	{	
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_1")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_3","trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_5")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_3","trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==3)
		{
			CurEnvTrigger("trigdoor3");
			if(VSetActive=="fact_4")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_3","trigdoor3",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==4)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_20")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_9,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}



		if(RandomSound<0)
		{
			float(_rnd2,RandomSound,200);
			float(_add,RandomSound,200);
		}
		else
		{
			float(_sub,RandomSound,1);
		}


		if(RandomSound<60)
		{
			if(vrnd<50)
			{
				vector(_set,Gactorpos,-9790,20200,18782);
				sample(SFXThunder1,gactorpos);
			}
			else
			{
				vector(_set,Gactorpos,-9647,20200,19444);
				sample(SFXThunder2,gactorpos);
			}

			vector(_set,tmpvector,128,128,255);
			if(vrnd<10)
			{
				vector(_set,Gactorpos,-10265,20300,17961);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			//}
			//elseif(vrnd<24)
			//{
				vector(_set,Gactorpos,-9595,20300,17917);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			//}
			//elseif(vrnd<36)
			//{
				vector(_set,Gactorpos,-9790,20200,18782);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			//}
			//elseif(vrnd<48)
			//{
				vector(_set,Gactorpos,-10170,20180,19431);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			//}
			//elseif(vrnd<60)
			//{
				vector(_set,Gactorpos,-9647,202600,19444);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			//}
			//elseif(vrnd<72)
			//{
				vector(_set,Gactorpos,-10252,20300,20264);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			//}
			//elseif(vrnd<84)
			//{
				vector(_set,Gactorpos,-9228,20300,20352);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			//}
			//else
			//{
				vector(_set,Gactorpos,-8950,20300,19900);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			}
		}
	}
	//=================================================================



	//FACT_23 IS ACTIVE	(Hallway)
	//=================================================================
	//_________________________________________________________________
	//Spawns rain and lighting SFX for courtyard.  Also does helicopter
	//lighting code.  Tests VarKey38 (helicopter position) and sets
	//lighting in windows accordingly.  Will also update keyframed object
	//position (for sound effects) at certain intervals because it gets
	//out of sync.
	//-----------------------------------------------------------------
	if(VSetActive=="FACT_23")
	{
		CurEnvTriggerSet("FACT_23","TRIGDOOR1");
		float(_set,TmpFloat,0x00FF00);
		call(expSet1,1,TmpFloat,0);
		
		if(varkey36==0)
		{
			float(_set,tmpfloat,0xFF0000);
			CurEnvTriggerSet("fact_23","trigdoor2");
			call(expSet1,1,tmpfloat,0);

			CurEnvTriggerSet("FACT_23","TRIGDOOR3");
			call(expSet1,1,TmpFloat,0);
		}
		elseif(varkey36==1)
		{
			float(_set,TmpFloat,0x00FF00);
			CurEnvTriggerSet("FACT_23","TRIGDOOR2");
			call(expSet1,1,TmpFloat,0);

			CurEnvTriggerSet("FACT_23","TRIGDOOR3");
			call(expSet1,1,TmpFloat,0);
		}

		if(RandomSound<0)
		{
			float(_rnd2,RandomSound,200);
			float(_add,RandomSound,200);
		}
		else
		{
			float(_sub,RandomSound,1);
		}

		if(RandomSound<60)
		{
			vector(_set,tmpvector,128,128,255);

			if(vrnd<20)
			{
				vector(_set,Gactorpos,-10935,24949.85,16399.76);
				sample(SFXThunder1,gactorpos);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			}
			elseif(vrnd<40 && vrnd>=20)
			{
				vector(_set,Gactorpos,-10335,24949.85,16399.76);
				sample(SFXThunder2,gactorpos);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			}
			elseif(vrnd<60 && vrnd>=40)
			{
				vector(_set,Gactorpos,-9735,24949.85,16399.76);
				sample(SFXThunder1,gactorpos);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			}
			elseif(vrnd<80 && vrnd>=60)
			{
				vector(_set,Gactorpos,-9135,24949.85,16399.76);
				sample(SFXThunder1,gactorpos);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			}
			else
			{
				vector(_set,Gactorpos,-8535,24949.85,16399.76);
				sample(SFXThunder1,gactorpos);
				SpawnLight(fire_light3,-1,gactorpos,tmpvector,EmptyVector,500);
			}
		}

		 
		//Helicopter Lights code
		if(varKey38>0)
		{
//			vector(_set,Gactorpos,-8535,24949.85,16399.76);
			vector(_set,Gactorpos,-11242.79,25026.95,16352.69);
			float(_set,tmpfloat,varkey38);
			float(_div,tmpfloat,60);
			float(_mul,tmpfloat,3000);
			float(_add,tmpfloat,-11242.79);
			vector(_setx,Gactorpos,tmpfloat);
		
			vector(_set,tmpvector,255,255,255);
			spawnlight(LomnilightHelicopter,-1,Gactorpos,tmpvector,EmptyVector,400);

			
			if(VarKey38==10)
			{
				setkeyframe("Fact_23","FlyByTrg",1);
				CurEnvTriggerSet("Fact_23","FlyByTrg");
				if(VarKey39==1)
				{
					call(KeyObjTrigger,255,1);
				}
				elseif(VarKey39==-1)
				{
					call(KeyObjTrigger,0,-1);
				}
			}
			elseif(VarKey38==20)
			{
				setkeyframe("Fact_23","FlyByTrg",2);
				CurEnvTriggerSet("Fact_23","FlyByTrg");
				if(VarKey39==1)
				{
					call(KeyObjTrigger,255,1);
				}
				elseif(VarKey39==-1)
				{
					call(KeyObjTrigger,0,-1);
				}
			}
			elseif(VarKey38==30)
			{
				setkeyframe("Fact_23","FlyByTrg",3);
				CurEnvTriggerSet("Fact_23","FlyByTrg");
				if(VarKey39==1)
				{
					call(KeyObjTrigger,255,1);
				}
				elseif(VarKey39==-1)
				{
					call(KeyObjTrigger,0,-1);
				}
			}
			elseif(VarKey38==40)
			{
				setkeyframe("Fact_23","FlyByTrg",4);
				CurEnvTriggerSet("Fact_23","FlyByTrg");
				if(VarKey39==1)
				{
					call(KeyObjTrigger,255,1);
				}
				elseif(VarKey39==-1)
				{
					call(KeyObjTrigger,0,-1);
				}
			}
			elseif(VarKey38==50)
			{
				setkeyframe("Fact_23","FlyByTrg",5);
				CurEnvTriggerSet("Fact_23","FlyByTrg");
				if(VarKey39==1)
				{
					call(KeyObjTrigger,255,1);
				}
				elseif(VarKey39==-1)
				{
					call(KeyObjTrigger,0,-1);
				}
			}

			
			if(VarKey38<20)
			{
				//Window 3
				float(_set,tmpfloat,VarKey38);
				float(_sub,tmpfloat,10);
				float(_div,tmpfloat,10);
				if(tmpfloat>0)
				{
					CurEnvTriggerSet("fact_23","Heli2");
					float(_set,tmpfloat4,tmpfloat);
					float(_mul,tmpfloat,256);//0x000100);
					float(_round,tmpfloat);
					float(_set,tmpfloat2,tmpfloat);
					float(_set,tmpfloat3,tmpfloat);
					float(_mul,tmpfloat2,256);//0x100);
					float(_mul,tmpfloat3,65536);//0x10000);
					float(_add,tmpfloat,tmpfloat2);
					float(_add,tmpfloat,tmpfloat3);
					if(tmpfloat<16777216)
					{
						call(ExpSet2,1,tmpfloat,0);

						CurEnvTriggerSet("fact_23","Heli1");
						float(_set,tmpfloat2,16777216);
						float(_sub,tmpfloat2,tmpfloat);
						call(ExpSet1,1,tmpfloat2,0);
					}
				}
				elseif(tmpfloat<0)
				{
					CurEnvTriggerSet("fact_23","Heli1");
					float(_mul,tmpfloat,-1);
					float(_mul,tmpfloat,256);//0x000100);
					float(_round,tmpfloat);
					float(_set,tmpfloat2,tmpfloat);
					float(_set,tmpfloat3,tmpfloat);
					float(_mul,tmpfloat2,256);//0x100);
					float(_mul,tmpfloat3,65536);//0x10000);
					float(_add,tmpfloat,tmpfloat2);
					float(_add,tmpfloat,tmpfloat3);
					if(tmpfloat<16777216)
					{
						float(_set,tmpfloat2,16777216);
						float(_sub,tmpfloat2,tmpfloat);
						call(ExpSet1,1,tmpfloat2,0);
					}
				}
			}
			elseif(VarKey38<40)
			{
				//Window 4
				float(_set,tmpfloat,VarKey38);
				float(_sub,tmpfloat,30);
				float(_div,tmpfloat,10);
				if(tmpfloat>0)
				{
					CurEnvTriggerSet("fact_23","Heli3");
					float(_set,tmpfloat4,tmpfloat);
					float(_mul,tmpfloat,256);//0x000100);
					float(_round,tmpfloat);
					float(_set,tmpfloat2,tmpfloat);
					float(_set,tmpfloat3,tmpfloat);
					float(_mul,tmpfloat2,256);//0x100);
					float(_mul,tmpfloat3,65536);//0x10000);
					float(_add,tmpfloat,tmpfloat2);
					float(_add,tmpfloat,tmpfloat3);
					if(tmpfloat<16777216)
					{
						call(ExpSet2,1,tmpfloat,0);

						CurEnvTriggerSet("fact_23","Heli2");
						float(_set,tmpfloat2,16777216);
						float(_sub,tmpfloat2,tmpfloat);
						call(ExpSet1,1,tmpfloat2,0);
					}
				}
				elseif(tmpfloat<0)
				{
					CurEnvTriggerSet("fact_23","Heli2");
					float(_mul,tmpfloat,-1);
					float(_mul,tmpfloat,256);//0x000100);
					float(_round,tmpfloat);
					float(_set,tmpfloat2,tmpfloat);
					float(_set,tmpfloat3,tmpfloat);
					float(_mul,tmpfloat2,256);//0x100);
					float(_mul,tmpfloat3,65536);//0x10000);
					float(_add,tmpfloat,tmpfloat2);
					float(_add,tmpfloat,tmpfloat3);
					if(tmpfloat<16777216)
					{
						call(ExpSet2,1,tmpfloat,0);

						float(_set,tmpfloat2,16777216);
						float(_sub,tmpfloat2,tmpfloat);
						call(ExpSet1,1,tmpfloat2,0);
					}
				}
			}
			else
			{
				//Window 5
				float(_set,tmpfloat,VarKey38);
				float(_sub,tmpfloat,50);
				float(_div,tmpfloat,10);
				if(tmpfloat>0)
				{
					CurEnvTriggerSet("fact_23","Heli3");
					float(_set,tmpfloat4,tmpfloat);
					float(_mul,tmpfloat,256);//0x000100);
					float(_round,tmpfloat);
					float(_set,tmpfloat2,tmpfloat);
					float(_set,tmpfloat3,tmpfloat);
					float(_mul,tmpfloat2,256);//0x100);
					float(_mul,tmpfloat3,65536);//0x10000);
					float(_add,tmpfloat,tmpfloat2);
					float(_add,tmpfloat,tmpfloat3);
					if(tmpfloat<16777216)
					{
						float(_set,tmpfloat2,16777216);
						float(_sub,tmpfloat2,tmpfloat);
						call(ExpSet1,1,tmpfloat2,0);
					}
				}
				elseif(tmpfloat<0)
				{
					CurEnvTriggerSet("fact_23","Heli3");
					float(_mul,tmpfloat,-1);
					float(_mul,tmpfloat,256);//0x000100);
					float(_round,tmpfloat);
					float(_set,tmpfloat2,tmpfloat);
					float(_set,tmpfloat3,tmpfloat);
					float(_mul,tmpfloat2,256);//0x100);
					float(_mul,tmpfloat3,65536);//0x10000);
					float(_add,tmpfloat,tmpfloat2);
					float(_add,tmpfloat,tmpfloat3);
					if(tmpfloat<16777216)
					{
						call(ExpSet2,1,tmpfloat,0);

						float(_set,tmpfloat2,16777216);
						float(_sub,tmpfloat2,tmpfloat);
						call(ExpSet1,1,tmpfloat2,0);
					}
				}
			}
		}		
	}
	//=================================================================

	//PSTON_1 IS ACTIVE	(First piston room)
	//=================================================================
	//_________________________________________________________________
	//Door light colors are set.  All doors always green.
	//-----------------------------------------------------------------
	if(VSetActive=="pston_1")
	{
		CurEnvTriggerSet("PSTON_1","TRIGDOOR1");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//=================================================================



	//PSTON_5 IS ACTIVE	(Last piston room)
	//=================================================================
	//_________________________________________________________________
	//Door light colors are set.  All doors always green.
	//-----------------------------------------------------------------
	if(VSetActive=="pston_5")
	{
		CurEnvTriggerSet("PSTON_5","TRIGDOOR1");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);
	}
	//=================================================================



	if(VCurSet=="fact_1")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_3" && VSetInMemory=="fact_9")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_1","trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_23")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_1","trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}

	elseif(VCurSet=="fact_4")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("doortrig1");
			if(VSetActive=="fact_3")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_4","trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("doortrig2");
			if(VSetActive=="fact_23")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_4","trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==3)
		{
			CurEnvTrigger("doortrig3");
			if(VSetActive=="fact_6")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_4","trigdoor3",0);
				call(KeyObjTrigger,255,1);
			}
		}		
	}

	elseif(VCurSet=="fact_6")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_4")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_6,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}

	elseif(VCurSet=="fact_8") //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_6")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_8,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_10")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_8,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="fact_10")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_8")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_10,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="fact_11")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_10")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_11,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_19")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_11,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}	
	}
	elseif(VCurSet=="fact_14")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="pston_5")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_14,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}	
	}
	elseif(VCurSet=="fact_16")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_17")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_16,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor3");
			if(VSetActive=="fact_23")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_17,"trigdoor3",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="fact_17")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_16")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
				setkeyframe("fact_16","lift",0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_17,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("f17f21");
			if(VSetActive=="fact_21")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_17,"f17f21",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="fact_19")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="pston_1")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_19,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_11")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_19,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="fact_20")  //mainscene
	{
		if(ControlTimer==3)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_9")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_20,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="fact_21")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_17")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_21,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}	
	elseif(VCurSet=="fact_23")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_1")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_23,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_4")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
				setkeyframe("fact_4","lift",1);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_23,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==3)
		{
			CurEnvTrigger("trigdoor3");
			if(VSetActive=="fact_16")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
				setkeyframe("fact_16","lift",1);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_23,"trigdoor3",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="pston_1")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_19")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("pston_1,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	elseif(VCurSet=="pston_5")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTrigger("trigdoor1");
			if(VSetActive=="fact_14")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("pston_5,"trigdoor1",0);
				call(KeyObjTrigger,255,1);
			}
		}
	}


	if(VCurSet=="fact_5") //mainscene
	{
		CurEnvTrigger("fact5door");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				call(RunScriptCode,_or,18);
				direction(_clr,_DIRaction);
			}
		}

		if(VKeyObjTriggered==0 && VRunScriptCode==18)
		{
			callsub(DeInitSceneSound18);
			call(RunScriptCode,_clr,18);
			float(_set,LinkGlobal,0);
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("fact5door");
			if(VSetActive=="walls2")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_5","fact5door",0);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTrigger("trigdoor2");
			if(VSetActive=="fact_3")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("fact_5,"trigdoor2",0);
				call(KeyObjTrigger,255,1);
			}
		}

	}
	//---------------------------------------------
}





//#######################################################################
//#######################################################################
//##                                                                   ##
//##                    BACKGROUND TRIGGER CHECKS                      ##
//##                                                                   ##
//#######################################################################
//#######################################################################
SubRoutine(BackgroundTriggerChecksScene7)
{

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel7); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	//FACT_1 IS CURRENT SET	(Security Room.  2nd Room in level)
	//=================================================================
	//_________________________________________________________________
	// o Need scientist to activate security console.  Scientist already
	//	working there will step out of your way if you approach.  
	// o Doors are locked until security console is activated (VarKey32==100 
	//	means security console activated).
	//-----------------------------------------------------------------
	if(VCurSet=="fact_1")  //bt check
	{
		//For Scientists wising up and leaving fact_3 (cuz they aint got axess)
//REMOVED BY JOE
//SHOULD BE RE ADDED ONCE A PLANE TRIGGER IS ADDED IN FACT_1 POINTING INTO FACT_3
//IN THE DOORWAY
/*		if(VAIClass==_AIClassScientist)
		{
			CurEnvTrigger("Secure")
			if(VTrigger==_DIREnvTrigger)
			{
				if(SecurityTimer<300)
				{
					float(_set,SecurityTimer,0);
				}
			}
		}
*/

		CurEnvTrigger("trigdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VarKey32>=100)
			{
				//callsub(DoorOpen,0,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					call(ForceLoadSet,"fact_9");
				}
			}
			else
			{
				if(VAICON==0)
				{
					sample(SFXLockedSound,-1);
					if(vrnd<33)
					{
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}
					message("LOCKED",120,10);
				}
			}
		}

		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			if(VarKey32>=100)
			{
				//callsub(DoorOpen,0,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			else
			{
				if(VAICon==0)
				{
					sample(SFXLockedSound,-1);
					if(vrnd<33)
					{
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}
					message("LOCKED",120,10);
				}
			}
		}

		CurEnvTrigger("DT_DOOR");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass!=_AIClassAngel)
			{
				if(VAIClass==_AIClassScientist)
				{
					if(VarKey32<=99)
					{
						float(_set,tmpfloat,varkey40);
						float(_and,tmpfloat,0x00000004);
						if(tmpfloat==0)
						{

							float(_set,tmpfloat,0x00FF00);
							call(ExpSet1,1,tmpfloat,0);

							if(VAICon==0)
							{
								float(_or,varkey40,0x00000001);
							}
							else
							{
								float(_or,varkey40,0x00000002);

								float(_set,tmpfloat,varkey40);
								float(_and,tmpfloat,0x00000003);
								if(tmpfloat==0x00000003)
								{
									callsub(TurnToPlayer);
									dmessage("This job sucks ! Why don't you",50,200);
									dmessage("help me out for a little while ?",60,200);
									sample(SFXThisJobSucks,-1);
									call(AIClrPathID);
									call(AIFindPathWithSpecificID,4);
									float(_or,varkey40,0x00000004);
								}
							}
						}

						if(VTrigger==_DIRAction)
						{

							if(VAICon==0)
							{
								call(ActivateButton,"FACTORY DOORS UNLOCKED",-1,FALSE);
								call(ActivateButtonSample,SFXValidFunction);
							}
							float(_set,VarKey32,100);

							//CurEnvTrigger("trigdoor1");
							//float(_set,TmpFloat,0x8000);
							//call(expset1,1,TmpFloat,0);

							//CurEnvTrigger("trigdoor2");
							//float(_set,TmpFloat,0x8000);
							//call(expset1,1,TmpFloat,0);
						}
					}
					else
					{
						if(VAICon==0 && VTrigger==_DIRAction)
						{
							call(ActivateButton,"DOORS ALREADY OPEN",-1,FALSE);
							call(ActivateButtonSample,SFXValidFunction);
						}
					}
				}
				else
				{
					float(_set,tmpfloat,0xFF0000);
					call(ExpSet1,1,tmpfloat,0);

					if(VAICON==0 && VTrigger==_DIRAction)
					{
						sample(SFXInvalidFunction,Gactorpos);
						message("RESEARCH PERSONNEL ONLY",120,10);
					}
				}
			}
			else
			{
				float(_set,tmpfloat,0xFF0000);
				call(ExpSet1,1,tmpfloat,0);

				if(VAICON==0 && VTrigger==_DIRAction)
				{
					call(ActivateButton,"slap@slap@slap@nothing..",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
		}

	


	}	
	//=================================================================




	//FACT_2 IS CURRENT SET	(Furnace room)
	//=================================================================
	//_________________________________________________________________
	// o Checks for plane trigger death falling in furnace and ignites character 
	//	on fire if activated.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_2")  //bt check
	{
		//This code burns dem fools up when they jump in the flames.
		CurEnvTrigger("Furnace");  
		if(VTrigger==_DIREnvTrigger)
		{
			if(VState!=StateDead)
			{
				if(VAICon==0)
				{
					Camera(500,elevator_camera_angle);
					call(LockCamera,true);
					//call(AIchangerank,0);		//take care of deaths internally!
				}
				//call(SubtractHealth,0,30000);
				Direction(_clr,_DIRalive);
				state(_or,StateOnFire);
				state(_or,StateDead);
			}
		}
	}
	//=================================================================


	//FACT_3 IS CURRENT SET	(Courtyard.  Level exit from here)
	//=================================================================
	//_________________________________________________________________
	// o Checks Security Timer to see how long player has been in room.  
	//	Will turn player to enemy if Security Timer reaches 300.  Will
	//	have cop give warnings at different intervals.
	// o Door to exit room is locked until MaserKey>=4 (Maser is charged).
	// o Door to elevator is locked until Elevator Power is set (VarKey36==1)
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_3")
	{

		//Prevents scientists from just waltzing into secure zone
		if(VAIClass==_AIClassCop && SecurityTimer!=0  && VAICon!=0)
		{
			callsub(TurnToPlayer);
			if(SecurityTimer<180)
			{
				if(SecurityTimer==2)
				{
					call(AIorder,_or,_AInomove);
	//				call(AIorder,_clr,_AInoturn);
	//				call(AIselecttarget,_AIenemy|_AIfriend,_AIClassScientist);
					sample(SFXCopGetBackToWork1,-1);
				}
				elseif(SecurityTimer==60)
				{
					call(AIorder,_or,_AInomove);
	//				call(AIorder,_clr,_AInoturn);
	//				call(AIselecttarget,_AIenemy|_AIfriend,_AIClassScientist);
					callsub(TurnToPlayer);
					sample(SFXCopGetBackToWork2,-1);
				}
				elseif(SecurityTimer==120)
				{
					call(AIorder,_or,_AInomove);
	//				call(AIorder,_clr,_AInoturn);
	//				call(AIselecttarget,_AIenemy|_AIfriend,_AIClassScientist);
					callsub(TurnToPlayer);
					sample(SFXCopGetBackToWork3,-1);
				}
			}
			elseif(SecurityTimer==180)
			{
				call(AIorder,_clr,_AInomove);
				callsub(Sub_AIGetBackToIdle);
				debugmessage("Get him!  1");
			}
		}
		if(VAIClass==_AIClassScientist && VAICon==0)
		{
			if(SecurityTimer<180)
			{
				float(_add,SecurityTimer,1);
			}
			elseif(SecurityTimer==180)
			{
				float(_add,SecurityTimer,1);
			}
			elseif(SecurityTimer==181)
			{
				call(AIChangeMeToEnemy);
				float(_add,SecurityTimer,1);
			}
		}
		
		if(VTrigger==_DIRaction&&VTrigger==_DIREnvTrigger)
		{
			CurEnvTrigger("trigdoor1");
			if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0)	
			{
				//callsub(DoorOpen,0,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("trigdoor2");
			if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0)	
			{
				if(maserkey>=4)
				{
					//callsub(DoorOpen,0,1);
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					sample(SFXLockedSound,-1);
					if(vrnd<33)
					{
						sample(SFXPlayerActivatesLockedDoorReact,-1);
					}
					message("Locked.",120,10);
				}
			}

			CurEnvTrigger("trigdoor3");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
			{				
				if(VarKey36==1)
				{
					setkeyframe("fact_4","lift",2);
					//callsub(DoorOpen,1,1);
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,3);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					if(VAICON==0)
					{
						message("Elevator not Operational",120,10);
						sample(SFXLockedSound,-1);
						if(vrnd<33)
						{
							sample(SFXPlayerActivatesLockedDoorReact,-1);
						}
					}
				}
			}		
		}
	}
	//----------------------------------------------------------------


	//FACT_4 IS CURRENT SET	(Elevator to Courtyard, Hallway, and Lower Factory)
	//=================================================================
	//_________________________________________________________________
	//Normal elevator control.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_4")  //bt check
	{
		CurEnvTrigger("lift");
		if(VKeyObjTriggered==0)
		{
			callsub(Sub_SetCameraNormal);

			CurEnvTrigger("invwall");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			CurEnvTrigger("doortrig1");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,1,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("doortrig2");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,1,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("doortrig3");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,1,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,3);
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
			CurEnvTrigger("invwall");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);

			Camera(elevator_camera_distance,elevator_camera_angle);
			Target(elevator_camera_Tdistance,elevator_camera_Tangle);
		}

		if(VTrigger==_DIRactionhold && VActivateButton==0)
		{
			float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
			CurEnvTrigger("panel3");
			callsub(LiftControl,2,2);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,2);
			CurEnvTrigger("panel1");
			callsub(LiftControl,0,2);


			CurEnvTrigger("DoorTrig1");
			if(VKeyObjTriggered==0)
			{
				CurEnvTrigger("DoorTrig2");
				if(VKeyObjTriggered==0)
				{
					CurEnvTrigger("DoorTrig3");
					if(VKeyObjTriggered==0)
					{
						CurEnvTrigger("lift");
						if(TmpFloat!=-1 && VKeyObjTriggered==0)			//elevator should be activated
						{
							if(TmpFloat1==1)
							{
								if(TmpFloat==2)
								{
									call(ActivateButton,"third floor",TmpFloat,2);
								}
								else
								{
									call(ActivateButton,"second floor",TmpFloat,2);
								}
							}
							else
							{
								if(TmpFloat==0)
								{
									call(ActivateButton,"Basement",TmpFloat,2);
								}
								else
								{
									call(ActivateButton,"second floor",TmpFloat,2);
								}
							}
							call(ActivateButtonSample,SFXValidFunction);
							float(_set,CameraPan,0);
							kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
							direction(_clr,_DIRAction);
						}
					}
				}
			}
		}
	}
	//=================================================================



	//FACT_5 IS CURRENT SET	(Room for level exit)
	//=================================================================
	//_________________________________________________________________
	//Just open door code.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_5")  //bt check
	{
		if(VTrigger==_DIRaction&&VTrigger==_DIREnvTrigger)
		{
			CurEnvTrigger("trigdoor2");
			if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0)	
			{
				//callsub(DoorOpen,0,1);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}


			CurEnvTrigger("fact5door"); 
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			//check if the player is within trigger and press action key
			{
				if(VAICon==0 && ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					float(_set,LinkGlobal,1);
					call(RunScriptCode,_or,18);
					direction(_clr,_DIRaction);
				}
			}
			if(VKeyObjTriggered==0 && VRunScriptCode==18)
			{
				callsub(DeInitSceneSound7);
				call(RunScriptCode,_clr,18);
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("fact5door")
				if(VSetActive=="walls2")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("fact_5","fact5door",0);
					call(KeyObjTrigger,255,1);
				}
			}

			//Door to Streets.  (walls2)
			//CurEnvTrigger("fact5door");
			//if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0)	
			//{
			//	callsub(DoorOpen,0,1);
			//}
		}
	}
	//=================================================================



	//FACT_6 IS CURRENT SET	(First room in Lower Factory)
	//=================================================================
	//_________________________________________________________________
	//Standard Door code.  Door to loft is always locked.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_6")  //bt check
	{
		if(VAICon!=0 && VCutScene!=0)
		{
			direction(_clr,_DIRMoveBits|_DIRShoot);
			callsub(Sub_AIGetBackToIdle);
		}

		CurEnvTrigger("trigdoor1");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			message("Locked.",120,10);
			vector(_set,Gactorpos,-11702.78,23446.35,17257.42);
			sample(SFXLockedSound,Gactorpos);
		}

		CurEnvTrigger("trigdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(VarKey31==0)
		{
			CurEnvTrigger("enterin");
			if(VTrigger==_DIREnvTrigger && VAICon==0)
			{
				float(_set,VarKey31,1);
				call(PlayerInput,0);
				CutScene("zoomcam1");
			}
		}
		else
		{
			if(VAICon==0 && VCutScene==0)
			{
				call(PlayerInput,1);
			}
		}
	}
	//=================================================================


	//FACT_7 IS CURRENT SET	(Starting Room)
	//=================================================================
	//_________________________________________________________________
	//Displays objectives.  Will respawn scientist in Fact_1 if 
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_7")
	{
	
		if(VAICon==0)
		{
			if(VarBit&=Help01)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,16);
				callsub(Panel16);
				ClearDMessage();
				float(_clr,VarBit,Help01);
			}

			if(VActiveTime>100)
			{
				//float(_set,TmpFloat,0);
				GetNumbActorsInSet("fact_7",_AIClassScientist,TmpFloat);
				if(TmpFloat==0)
				{
					GetNumbActorsInSet("fact_1",_AIClassScientist,TmpFloat);
					if(TmpFloat==0)
					{
						GetNumbActorsInSet("fact_23",_AIClassScientist,TmpFloat);
						if(TmpFloat==0)
						{
							vector(_set,Gactorpos,-10785,24575,17570);
							vector(_set,Gactorangle,0,0,0);
							InitActor(scientist,Gactorpos,Gactorangle,"Fact_1",TRUE,2);
						}
					}
				}
			}


			if(FlicBits&!=0x100)
			{
				CurEnvTrigger("flicyou");
				if(VTrigger==_DIREnvTrigger && VAICon==0)
				{
					//call(CDPlaySegment,4,0,0,0,34);
					vector(_set,Gactorpos,-11833,25498,17397);
					sample(SFXSatanTakeoverFlic,gactorpos);
					Call(ExpSet1,0,0,510);
					float(_or,FlicBits,0x100);
				}
			}
		}
		
		
		CurEnvTrigger("ENTRANCE");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VTrigger==_DIRaction)
			{
				message("It Will Not Open.",120,10);
			}
		}

		call(SetParticleSetID,"fact_7");
		if(vrnd<20)
		{
			//Spawn randomly aimed sparks from rollers
			vector(_set,Gactorine,0,24,-6);
			vector(_set,Gactorpos,-11690.47,25019.87,19053.96);
			spawnparticle(fx_impactsparks,-1,gactorpos,gactorine,-1);
		}


/*		CurEnvTrigger("transit02");
		if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0)
		{
			callsub(DoorOpen,0,1);
		}*/
	}
	//----------------------------------------------------------------


	elseif(VCurSet=="fact_8")  //bt check
	{
		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("trigdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}	
	}
	//=================================================================


	//FACT_9 IS CURRENT SET	(Other half of courtyard)
	//=================================================================
	//_________________________________________________________________
	//Anyone can operate the weapons dispenser.  
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_9")
	{
		if(VAIClass==_AIClassCop && SecurityTimer!=0 && VAICon!=0)
		{
			callsub(TurnToPlayer);

			if(SecurityTimer<180)
			{
				if(SecurityTimer==2)
				{
					call(AIorder,_or,_AInomove);
	//				call(AIorder,_clr,_AInoturn);
	//				call(AIselecttarget,_AIenemy|_AIfriend,_AIClassScientist);
					sample(SFXCopGetBackToWork1,-1);
				}
				elseif(SecurityTimer==60)
				{
					call(AIorder,_or,_AInomove);
	//				call(AIorder,_clr,_AInoturn);
	//				call(AIselecttarget,_AIenemy|_AIfriend,_AIClassScientist);
					callsub(TurnToPlayer);
					sample(SFXCopGetBackToWork2,-1);
				}
				elseif(SecurityTimer==120)
				{
					call(AIorder,_or,_AInomove);
	//				call(AIorder,_clr,_AInoturn);
	//				call(AIselecttarget,_AIenemy|_AIfriend,_AIClassScientist);
					callsub(TurnToPlayer);
					sample(SFXCopGetBackToWork3,-1);
				}
			}
			elseif(SecurityTimer==180)
			{
				call(AIorder,_clr,_AInomove);
				debugmessage("Get him!  2");
				callsub(Sub_AIGetBackToIdle);
			}
		}
		if(VAIClass==_AIClassScientist && VAICon==0)
		{
			if(SecurityTimer<180)
			{
				float(_add,SecurityTimer,1);
			}
			elseif(SecurityTimer==180)
			{
				float(_add,SecurityTimer,1);
			}
			elseif(SecurityTimer==181)
			{
				call(AIChangeMeToEnemy);
				float(_add,SecurityTimer,1);
			}
		}

		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,4);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("ARME");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAIClass==_AIClassCop)
			{
				if(VKeyObjTriggered!=0)
				{
					float(_set,tmpfloat,0x0000FF);
				}
				else
				{
					float(_set,tmpfloat,0x00FF00);
				}
				call(expset1,1,tmpfloat,0);

				if(VTrigger==_DIRaction)
				{
					//if(VKeyObjFrame==0)
					if(VKeyObjTriggered==0)
					{
						vector(_set,Gactorpos,-9334,25500,19797);
						vector(_set,Gactorangle,0,0,0);
						InitActor(WeaponFlameThrower,Gactorpos,Gactorangle,"fact_9");
						call(KeyObjTrigger,255,1);
						float(_set,TmpFloat,0x0000ff);
						call(expset1,1,TmpFloat,0);
						direction(_clr,_DIRaction);
					}
					else
					{
						if(VAICON==0)
						{
							message("Weapon Dispenser Already Used",120,10);
						}
						direction(_clr,_DIRaction);
					}
				}
			}
			else
			{
				if(VAICON==0 && VTrigger==_DIRAction)
				{
					message("Access Denied.",120,10);
					sample(SFXAccessDenied,-1);
				}

				if(VKeyObjTriggered!=0)
				{
					float(_set,tmpfloat,0xFF0000);
				}
				else
				{
					float(_set,tmpfloat,0x00FF00);
				}
				call(expset1,1,tmpfloat,0);
			}
		}
	}
	//=================================================================



	//FACT_10 IS CURRENT SET	(Loft area.)
	//=================================================================
	//_________________________________________________________________
	//Door leading to Maser charging room is locked.  Other door is open.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_10")  //bt check
	{
		CurEnvTrigger("trigdoor1");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			message("Locked.",120,10);
			vector(_set,Gactorpos,-12137.62,23678.39,18790.07);
			sample(SFXLockedSound,Gactorpos);
		}

		CurEnvTrigger("trigdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(VAICon!=0 && VCutScene!=0)
		{
			direction(_clr,_DIRMoveBits|_DIRShoot);
			callsub(Sub_AIGetBackToIdle);
		}
	}
	//=================================================================


	//FACT_11 IS CURRENT SET	(Chamber leads to Loft and Maser Charging room)
	//=================================================================
	//_________________________________________________________________
	//Nothing special.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_11")  //bt check
	{
		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("trigdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	//=================================================================


	//FACT_14 IS CURRENT SET	(Wheel room in lower factory.  Leads to Piston area)
	//=================================================================
	//_________________________________________________________________
	//Nothin special.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_14")
	{
		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(VAICon!=0 && VCutScene!=0)
		{
			direction(_clr,_DIRMoveBits|_DIRShoot);
			callsub(Sub_AIGetBackToIdle);
		}
	}
	//=================================================================



	//FACT_16 IS CURRENT SET	(Elevator from Weapon Charging room to Hallway)
	//=================================================================
	//_________________________________________________________________
	//Standard lift code.  Nothing special.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_16")  //bt check
	{
		CurEnvTrigger("lift");
		if(VKeyObjTriggered==0)
		{
			callsub(Sub_SetCameraNormal);

			CurEnvTrigger("invwall");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);

			CurEnvTrigger("trigdoor1");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,1,1);

				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			CurEnvTrigger("trigdoor3");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,1,1);

				if(ControlTimer==0)
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
			Camera(elevator_camera_distance,elevator_camera_angle);
			Target(elevator_camera_Tdistance,elevator_camera_Tangle);

			CurEnvTrigger("invwall");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
		}

		if(VTrigger==_DIRactionhold && VActivateButton==0)
		{
			float(_set,TmpFloat,-1);	//must do this before calling LiftControl!
			CurEnvTrigger("panel1");
			callsub(LiftControl,0,1);
			CurEnvTrigger("panel2");
			callsub(LiftControl,1,1);


			CurEnvTrigger("TrigDoor1");
			if(VKeyObjTriggered==0)
			{
				CurEnvTrigger("TrigDoor3");
				if(VKeyObjTriggered==0)
				{
					CurEnvTrigger("lift");
					if(TmpFloat!=-1 && VKeyObjTriggered==0)			//elevator should be activated
					{
						if(TmpFloat1==1)
						{
							if(TmpFloat==1)
							{
								call(ActivateButton,"second floor",TmpFloat,2);
								kfsample(-1,-1,-1,SFXSector2,1);
							}
						}
						else
						{
							if(TmpFloat==0)
							{
								call(ActivateButton,"Basement",TmpFloat,2);
								kfsample(-1,-1,-1,SFXSectorBase,1);
							}
						}
						call(ActivateButtonSample,SFXValidFunction);
						float(_set,CameraPan,0);
						kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd,1);
						direction(_clr,_DIRAction);
					}
				}
			}
		}
	}
	//=================================================================



	//FACT_17 IS CURRENT SET	(Maser Creation Room)
	//=================================================================
	//_________________________________________________________________
	// o Locks door to elevator until Elevator Power is restored (VarKey36==1)
	//	and Maser is built and retrieved (VarKey33==6)
	// o Console can only be activated by a scientist, and only if Maser
	//	has either not yet been created or has already been retrieved.
	//  (VarKey33==0 || VarKey33==6)
	// o Maser retrieval console can only be activated once the maser
	//	is done being built (VarKey33==3).  
	// o Sequence is complete once player picks up the maser (VarKey33 is
	//	then set to 6, allowing you to build another maser or charge it).
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_17")  //bt check
	{
		callsub(Sub_SetCameraNormal);
		
		if(VarBit&=Help02)
		{
			if(VAICon==0 && VTrigger==_DIRHaveGun && VWeaponType==WeaponMaser)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,17);
				callsub(Panel17);
				ClearDMessage();
				float(_clr,VarBit,Help02);
			}
		}				


		if(VarKey33==1)
		{
			//CurEnvTrigger("ctrlcam");
			//call(ExpSet2,660,1,1);
			float(_set,VarKey33,2);
		}
		elseif(VarKey33==2)
		{
			CurEnvTrigger("console");
			if(VKeyObjTriggered==0)
			{
				float(_set,VarKey33,3);
			}
		}
	
		CurEnvTrigger("getwepn");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(VAIClass==_AIClassScientist)
			{
				if(VarKey33<2)
				{
					message("Weapon Construction Not Yet Initialized",120,10);
//					call(ActivateButtonSample,SFXInvalidFunction);
					sample(SFXInvalidFunction,-1);
				}
				elseif(VarKey33==2)
				{
					message("Weapon Construction In Progress",120,10);
//					call(ActivateButtonSample,SFXInvalidFunction);
					sample(SFXInvalidFunction,-1);
				}
				elseif(VarKey33>3)
				{
					message("Weapon Construction Already Completed",120,10);
//					call(ActivateButtonSample,SFXInvalidFunction);
					sample(SFXInvalidFunction,-1);
				}
				else
				{
					//call(KeyObjTrigger,255,1);
					call(KeyObjTrigger,87,1);
					kfsample(-1,SFXHatchLoop,-1,SFXHatchEnd,1);

					CurEnvTrigger("GoDown");
					//call(KeyObjTrigger,255,1);
					call(KeyObjTrigger,87,1);
					kfsample(-1,SFXWeaponMovement,-1,-1,1);
					
					sample(SFXValidFunction,-1);
					message("Retrieving Weapon");
					float(_set,VarKey33,4);

					call(DisplayFXPagesToggle,1);		//activate MASER gfx!!!

					vector(_set,gactorpos,-8540,24738,18109.13);
					vector(_set,Gactorangle,0,1024,0);
					InitActor(WeaponMaser,Gactorpos,Gactorangle,"fact_17",TRUE);

					call(PlayerInput,0);
					call(ChangeSniperMode,0,1);
					CutScene("masercam");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
//					Camera(0,elevator_camera_angle);
				}
			}
			else
			{
				message("Authorized Personnel Only",120,10);
//				call(ActivateButtonSample,SFXInvalidFunction);
				sample(SFXInvalidFunction,-1);
			}
		}

		if(VarKey33==4)
		{
			CurEnvTrigger("GetWepn");
			if(VKeyObjFrame==67)
			{
				float(_set,WepConstructionTimer,1);
				float(_set,VarKey33,5);
			}
		}
		if(VarKey33==5)
		{
			CurEnvTrigger("GetWepn");
			if(VKeyObjFrame==84)
			{
				call(PlayerInput,1);
			}

			if(VWeaponType==WeaponMaser)
			{
				CurEnvTrigger("getwepn");
				call(KeyObjTrigger,255,1);

				CurEnvTrigger("GoDown");
				call(KeyObjTrigger,255,1);
				float(_set,VarKey33,6);
				call(PlayerInput,1);
			}
		}
		elseif(VarKey33==6)
		{
			CurEnvTrigger("GetWepn");
			if(VKeyObjTriggered==0)
			{
				float(_set,MaserKey,1);
			}
		}

		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			if(VarKey36==1)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			else
			{
				message("Elevator Not Operational",120,10);
				sample(SFXLockedSound,-1);
				if(vrnd<33)
				{
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
		}

		CurEnvTrigger("f17f21");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}
	}
	elseif(VCurSet=="fact_17a")
	{
		CurEnvTrigger("console");
		if(VTrigger==_DIREnvTrigger)
		{
			if(VAICon==0)
			{
				if(VAIClass==_AIClassScientist)
				{
					if(VarKey33==0 || VarKey33==6)
					{
						CurEnvTriggerSet("fact_17","getwepn");
						if(VKeyObjTriggered==0)
						{
							CurEnvTriggerSet("fact_17","console");
							float(_set,tmpfloat,0x00FF00);
							call(ExpSet1,1,tmpfloat,0);

							if(VTrigger==_DIRaction)
							{
								//call(ActivateButton,"Weapon Construction Initialized",-1,FALSE);
								//call(ActivateButtonSample,SFXValidFunction);
								//call(PlayerInput,0);
								float(_set,VarKey33,1);
								call(KeyObjTrigger,57,1);
								CurEnvTriggerSet("fact_17","getwepn");
								call(KeyObjTrigger,57,1);
								kfsample(-1,SFXIndustrial10,-1,SFXLatch2,1);
				
								//message("Weapon Construction Initialized",120,10);
								sample(SFXValidFunction,-1);
								ClearTutorialLines();
								AddTutorialLine("Not often found on the streets of City Faktur@");
								AddTutorialLine("the [20:250:50]MASER[255:255:255] is the only weapon capable");
								AddTutorialLine("of efficiently destroying Armored Behemoths.");
								AddTutorialLine("Though brutally effective against mechanized foes@");
								AddTutorialLine("the [20:250:50]MASER[255:255:255] is relatively harmless to");
								AddTutorialLine("organic creatures.");
								AddTutorialLine(" ");
								AddTutorialLine("In order to use the [20:250:50]MASER[255:255:255] you will have");
								AddTutorialLine("to first charge it at the recharging station");
								AddTutorialLine("on the lower level of the Factory.");
								DisplayTutorialScreen("[255:255:20]MASER WEAPON",15,15);
							}
						}
						else
						{
							if(VTrigger==_DIRaction)
							{
								//call(ActivateButton,"Weapon Already Built",-1,FALSE);
								//call(ActivateButtonSample,SFXInvalidFunction);
								message("Maser construction resetting.",120,10);
								sample(SFXInvalidFunction,-1);
							}
						}
					}
					else
					{
						if(VTrigger==_DIRaction)
						{
							//call(ActivateButton,"Weapon Already Built",-1,FALSE);
							//call(ActivateButtonSample,SFXInvalidFunction);
							message("Weapon Already Built",120,10);
							sample(SFXInvalidFunction,-1);
						}
					}
				}
				else
				{
					if(VTrigger==_DIRaction)
					{
						//call(ActivateButton,"Authorized Personnel Only",-1,FALSE);
						//call(ActivateButtonSample,SFXInvalidFunction);
						message("Authorized Personnel Only",120,10);
						sample(SFXInvalidFunction,-1);
					}
				}
			}
		}

		if(VarKey33==1)
		{
			//CurEnvTrigger("ctrlcam");
			//call(ExpSet2,660,1,1);
			float(_set,VarKey33,2);
		}
		elseif(VarKey33==2)
		{
			CurEnvTriggerSet("fact_17","console");
			if(VKeyObjTriggered==0)
			{
				float(_set,VarKey33,3);
			}
		}

		if(VarKey33==4)
		{
			CurEnvTriggerSet("fact_17","GetWepn");
			if(VKeyObjFrame==67)
			{
				float(_set,WepConstructionTimer,1);
				float(_set,VarKey33,5);
			}
		}
		if(VarKey33==5)
		{
			CurEnvTriggerSet("fact_17","GetWepn");
			if(VKeyObjFrame==84)
			{
				call(PlayerInput,1);
			}

			if(VWeaponType==WeaponMaser)
			{
				CurEnvTriggerSet("fact_17","getwepn");
				call(KeyObjTrigger,255,1);

				CurEnvTriggerSet("fact_17","GoDown");
				call(KeyObjTrigger,255,1);
				float(_set,VarKey33,6);
				call(PlayerInput,1);
			}
		}
		elseif(VarKey33==6)
		{
			CurEnvTriggerSet("fact_17","GetWepn");
			if(VKeyObjTriggered==0)
			{
				float(_set,MaserKey,1);
			}
		}

	}
	//=================================================================


	//FACT_19 IS CURRENT SET	(Maser Charging Room)
	//=================================================================
	//_________________________________________________________________
	// o When you first enter this set a cutscene starts that shows
	//	the scientist dropping the bridge and putting up the lasers.
	// o The maser is charged by first setting it down in the Charge 
	//	trigger, MaserKey is then set to 3.  Once you go to the panel
	//	and charge it, MaserKey is then set to 4 and the maser is ready
	//	to be used.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_19")  //bt check
	{
		CurEnvTrigger("Charge");
		if(VAICon==0)
		{
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRAction && VTrigger==_DIRHaveGun && VWeaponType==WeaponMaser)
				{
					direction(_clr,_DIRAction);

					state(_or,StateExecuteAnim);
					spawnaction(GENPickup);

					float(_set,MaserKey,2);
				}
				else
				{
					if(MaserKey<5)
					{
						//This needs to keep player from picking up ze gun.
						direction(_clr,_DIRAction);
					}
				}
			}
			else
			{
				float(_set,DisablePickup,0);
			}
		}

		if(VAICon==0 && MaserKey>=2)
		{
			CurEnvTrigger("Pickup");
			if(VTrigger==_DIREnvTrigger)
			{
				if(MaserKey<5)
				{
					float(_set,DisablePickup,1);
				}
			}
			else
			{
				float(_set,DisablePickup,0);
			}
		}

		
		if(VAICon!=0 && VCutScene!=0)
		{
			direction(_clr,_DIRMoveBits|_DIRShoot);
			callsub(Sub_AIGetBackToIdle);
		}

		if(VarKey31==1)
		{
/*			CurEnvTrigger("ctrlcam");
			if(VKeyObjFrame==0)
			{
				call(ExpSet2,160,1,1);
				call(KeyObjTrigger,255,1); 
			}*/

			//if(VCutScene!=0)
			//call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			//call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			//call(ChangeCutScene,_SXCUTspeed,250);
		}
		
		if(VCutSceneFrame!=0)
		{
			if(VAIClass==_AIClassScientist)
			{
				Direction(_clr,_DIRcombatmode);
				callsub(Sub_AIGetBackToIdle);
			}
		}

		if(VCutSceneFrame==60)
		{
			if(VAIClass==_AIClassScientist)
			{
				CurEnvTrigger("bridgeup");
				if(VTrigger==_DIREnvTrigger)
				{
					spawnaction(ScientistPressButtons);				
				}
			}
		}
		elseif(VCutSceneFrame==75)
		{
			if(VarKey31<3)
			{
				float(_set,VarKey31,3);

				CurEnvTrigger("bridgeup");
				call(ActivateButton,"Bridge open",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				call(KeyObjTrigger,7,2);
				kfsample(SFXRustDoorOpen,SFXRustDoorLoop,-1,SFXRustDoorClose);
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				//call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
				//call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
				vector(_set,Gactorpos,-11383,23599,19087);
				sample(SFXElecFenceBlue,Gactorpos);
				//call(PlayerInput,1);
			}
		}

		
		if(VarKey31==3)
		{
			CurEnvTrigger("LzrWall01");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
			CurEnvTrigger("LzrWall02");
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}

		
			CurEnvTrigger("Idiot01");
			if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIClassCop)
			{
				callsub(Sub_AIGetBackToIdle);
				//call(AIFindPathWithSpecificID,1);
				call(AIOrder,_or,_AIstateGuard);
				call(AIOrder,_or,_AIstayonpath|_AIinspecialmode);
			}
		}

		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("trigdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("bridgeup");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VKeyObjFrame==0 && VarKey31!=0)
			{
				call(ActivateButton,"Bridge open",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				call(KeyObjTrigger,7,2);
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				//call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
				//call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
				vector(_set,Gactorpos,-11383,23599,19087);
				sample(SFXElecFenceBlue,Gactorpos);

				//call(PlayerInput,1);
			 	float(_set,VarKey31,3);
				direction(_clr,_DIRaction);
			}
			else
			{
				if(VAICon==0)
				{
					call(ActivateButton,"Bridge shut",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,255,1);
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
					call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
					vector(_set,Gactorpos,-11383,23599,19087);
					samplestop(SFXElecFenceBlue,Gactorpos);

					float(_set,VarKey31,4);
					direction(_clr,_DIRaction);
				}
			}
		}



		CurEnvTrigger("BridgeUp");
		if(VKeyObjTriggered==0 && VKeyObjFrame==7)
		{
			CurEnvTriggerSet("fact_14","Looky1");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);

			CurEnvTriggerSet("fact_14","trigdoor1");
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);


			/*CurEnvTriggerSet("fact_19","LookDwn");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);

			CurEnvTriggerSet("fact_19","Lookdw2");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
*/
		
		}
		else
		{
			CurEnvTriggerSet("fact_14","Looky1");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);

			CurEnvTriggerSet("fact_14","trigdoor1");
			call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);

		
/*			CurEnvTriggerSet("fact_19","LookDwn");
			call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);

			CurEnvTriggerSet("fact_19","Lookdw2");
			call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
			call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);*/
		}
		


/*		CurEnvTrigger("Charge3");
		if(VAICon==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VWeaponType==WeaponMaser)
		{
			CurEnvTrigger("Charge2");
			if(VTrigger==_DIREnvTrigger)
			{
				spawnaction(CopPickupChest);
				float(_set,MaserKey,2);
			}
		}
*/

		if(MaserKey==2 && vframe==33)
		{
			//if(AIAbility&=_AIAPickUpWeapon)
			//{
				call(CheckAttached,_CADropWeapon);
			//}
			float(_set,MaserKey,3);
		}

		CurEnvTrigger("Console");
		if(VAICon==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(MaserKey<2)
			{
				message("No weapon detected.  Please place weapon on plate for charging",120,10);
			}
			elseif(MaserKey>=2 && MaserKey<4)
			{
				setkeyframe("fact_19","console",0);
				call(KeyObjTrigger,255,1);
				kfsample(-1,SFXWeaponCharge,-1,-1,1);
				call(ExpSet1,0,-1000,0);
				message("Charging the MASER weapon",120,10);
				float(_set,MaserKey,4);
			}
			else
			{
				message("Weapon already charged",120,10);
			}
		}

		
		CurEnvTrigger("Console")
		if(MaserKey==4 && VKeyObjTriggered==0)
		{
			message("MASER weapon fully charged",120,10);
			float(_set,MaserKey,5);
		}
	}
	//=================================================================


	//FACT_20 IS CURRENT SET	(Weapon testing room)
	//=================================================================
	//_________________________________________________________________
	// o Console will start the GunTurret sequence in fact_21 by setting
	//	GunTurretKey to 1.  GunTurret will then start firing, and GunTurretKey
	//	will be set to 2.  It is then incremented every frame, and when
	//	GunTurretKey reaches 300, the GunTurret will go berserk, and the
	//	alarm lights will flash.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_20")  //bt check
	{
		callsub(Sub_SetCameraNormal);

		CurEnvTrigger("trigdoor1");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VKeyObjFrame==0)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,3);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("console");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(GunTurretKey<1)
			{
				float(_set,GunTurretKey,1);
				message("Experimental gun turret activated.",120,10);
			}
			elseif(GunTurretKey<300)
			{
				message("Gun turret already activated.",120,10);
			}
			else
			{
				message("Gun turret malfunction!",120,10);
			}
		}

		if(GunTurretKey==1)
		{
			if(VAIClass==_AIClassDroid)
			{
				spawnaction(GunTurretFire);
				float(_set,GunTurretKey,2);
			}
		}
		elseif(GunTurretKey==300)
		{
			if(VAIClass==_AIClassDroid)
			{
				if(VAction!=GunTurretBeserker)
				{
					spawnaction(GunTurretBeserker);
					float(_set,GunTurretKey,301);
				}
			}
		}
	}
	//=================================================================


	//FACT_21 IS CURRENT SET	(Weapon testing target room)
	//=================================================================
	//_________________________________________________________________
	// o Scientist working on target will be set to kneel.
	// o When GunTurretKey reaches 2, he will begin his sequenced response
	//	of freaking out, that is controlled by different GunTurretKey values.
	// o Elevator power is restored by using a scientist at the console, and 
	//	then VarKey36 is set to 1 meaning elevator power is restored.
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_21")  //bt check
	{
		if(VAICon==0)
		{
			Camera(elevator_camera_distance,elevator_camera_angle);
		}
		
		CurEnvTrigger("trigdoor2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && Vtrigger==_DIRAction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(GunTurretKey==0)
		{
			if(VAIClass==_AIClassScientist && VAICon!=0)
			{
				CurEnvTrigger("Fodder");
				if(VTrigger==_DIREnvTrigger)
				{
					spawnaction(WorkerWeldingKneel);
				}
			}
		}
		elseif(GunTurretKey==2)
		{
			CurEnvTrigger("fodder");
			if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIClassScientist)
			{
				if(VHealth>1)
				{
					float(_seti,tmpfloat,VHealth);
					float(_sub,tmpfloat,1);
					call(SubtractHealth,0,tmpfloat);
					float(_set,GunTurretKey,3);
				}
				call(AIfindpathwithspecificid,2);
//DEBUG ONLY//////////
				sample(SFXScientistDontTouch,-1);
////////////////
			}
		}
		if(GunTurretKey==75)
		{
			CurEnvTrigger("fodder");
			if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIClassScientist)
			{
				State(_clr,StateFollowPath);
				State(_or,StateExecutePathSequence);
				spawnaction(WorkerKneelCrush);
				sample(SFXScientistScared,-1);
			}
		}
		if(GunTurretKey==100)
		{
			CurEnvTrigger("fodder");
			if(VTrigger==_DIREnvTrigger && VAICon!=0 && VAIClass==_AIClassScientist)
			{
				sample(SFXScientistOhShit,-1);
			}
		}

		CurEnvTrigger("elpower");
		if(VTrigger==_DIREnvTrigger)	
		{
			float(_set,tmpfloat,0x00FF00);
			call(ExpSet1,1,tmpfloat,0);

			if(VTrigger==_DIRAction)
			{
				if(VarKey36==0)
				{
					call(ActivateButton,"Elevator Power Restored",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					float(_set,VarKey36,1);
					
					direction(_clr,_DIRaction);
				}
				else
				{
					call(ActivateButton,"Power Already restored",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
					direction(_clr,_DIRaction);
				}
			}
		}

		CurEnvTrigger("DeathFall");
		callsub(Fall2Death);
	}
	//=================================================================



	//FACT_23 IS CURRENT SET	(Hallway)
	//=================================================================
	//_________________________________________________________________
	// o Code for elevator doors.  Doors are locked until Elevator Power
	//	is restored. (VarKey36==1).
	//-----------------------------------------------------------------
	elseif(VCurSet=="fact_23")  //bt check
	{
		if(VAICon==0)
		{
			CurEnvTrigger("trigdoor1");
			if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0 && VTrigger==_DIRaction)	
			{
				//callsub(DoorOpen,0,1);

				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("TRIGDOOR2");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0 && VTrigger==_DIRaction)
			{
				if(VarKey36==1)
				{
					//callsub(DoorOpen,1,1);

					if(ControlTimer==0)
					{
						float(_set,ControlTimer,2);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					if(VAICON==0)
					{
						message("Elevator not Operational",120,10);
						sample(SFXLockedSound,-1);
						if(vrnd<33)
						{
							sample(SFXPlayerActivatesLockedDoorReact,-1);
						}
					}
				}
			}
			CurEnvTrigger("TRIGDOOR3");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0 && VTrigger==_DIRaction)
			{		
				if(VarKey36==1)
				{				
					//callsub(DoorOpen,1,1);

					if(ControlTimer==0)
					{
						float(_set,ControlTimer,3);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
					}
				}
				else
				{
					if(VAICON==0)
					{
						message("Elevator not Operational",120,10);
						sample(SFXLockedSound,-1);
						if(vrnd<33)
						{
							sample(SFXPlayerActivatesLockedDoorReact,-1);
						}
					}
				}
			}
		}

		

	}
	//=================================================================



	
	//PSTON_1 IS CURRENT SET	(First piston room)
	//=================================================================
	//_________________________________________________________________
	// o Straight forward
	//-----------------------------------------------------------------
	elseif(VCurSet=="pston_1")  //bt check
	{
		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//=================================================================

	//PSTON_2 IS CURRENT SET	(First piston room)
	//=================================================================
	//_________________________________________________________________
	// o Straight forward
	//-----------------------------------------------------------------
	elseif(VCurSet=="pston_2")  //bt check
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//=================================================================

	//PSTON_3 IS CURRENT SET	(First piston room)
	//=================================================================
	//_________________________________________________________________
	// o Straight forward
	//-----------------------------------------------------------------
	elseif(VCurSet=="pston_3")  //bt check
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//=================================================================

	//PSTON_4 IS CURRENT SET	(First piston room)
	//=================================================================
	//_________________________________________________________________
	// o Straight forward
	//-----------------------------------------------------------------
	elseif(VCurSet=="pston_4")  //bt check
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//=================================================================


	//PSTON_5 IS CURRENT SET	(Last piston room)
	//=================================================================
	//_________________________________________________________________
	// o Straight forward
	//-----------------------------------------------------------------
	elseif(VCurSet=="pston_5")  //bt check
	{
		CurEnvTrigger("trigdoor1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
		{
			//callsub(DoorOpen,1,1);

			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//=================================================================
}
