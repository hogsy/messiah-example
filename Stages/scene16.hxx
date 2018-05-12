//************* CLUB PERIMETER (Paste into Scene8.hxx) *******


//VarKey51	- ------ UNUSED -------
//VarKey52	- Pimp escape sequence
//VarKey53  - Steelbar in Hsing1
//VarKey54  - Decontamination area (rlquar)
//VarKey55	- Lift Control in Acs07
//VarKey56	- VideoBall Control
//VarKey57	- Activate lift in ACS01
//VarKey58	- progress stats
//				1	- passcode for elevator in rlplin
//				2	- door from rlhstn1 to rlhsin unlocked
//VarKey59	- Electric Strips in Acs04
//VarKey60	- Checks to see if a gun has entered the scanning room
//VarKey61	- WindBlow when exploding glass
//VarKey62	- timer for Quarantine Area
//VarKey63  - redlite
//VarKey64	- Delaytime for steam in rlhsng4
//VarKey67  - FireJets
//				1 - firejet 1 In acs02
//				2 - firejet 2 In acs02
//				8 - firejet 2 In acs02
//				4 - firejet 1 In acs02
//VarKey68	- level progress stats
//				1	- Worker has fallen
//				2	- init dweller in acs07
//				4	- Worker crushed in machinery 1
//				8	- Worker crushed in machinery 2
//				16	- Worker crushed in machinery 3
//VarKey69	
//VarKey70  -  Used as timer in clubsas.  /  Used as timer in Acs02
//
//VarBit
//------
//
//Help01	> Bouncer outside Foyer
//Help02	> Change Path for Bouncer
//Help03	> Check if Barman is inside his trigger
//Help04	> First Encounter with Barman
//Help05	> Second Encounter with Barman
//Help06	> Third+ Encounter with Barman
//Help07	> Bouncer inside Foyer
//Help08	> "Displace" dweller in ACS07
//Help09	> Force "crouch" in acsvent
//Help10	> If tesla01 has been destroyed
//Help11	> If tesla02 has been destroyed
//Help12	> Lift handler in acs07
//Help13	> Lift Hander in acs07
//Help14	> Weapon detected in ClubSas
//Help15	> Sparks/strips when console is activated in acs02 (for electric gate)
//Help16	> Player is carrying a weapon while entering club sas
//Help17	> Bob is crawling in the vent - sample played
//Help18	> Story Message #22
//Help19	> Exit FirstPerson in acs04
//Help20	> Check if character enters clubsas with a weapon (hidden or not).
//Help21	> Weapon detected
//Help22	> Weapon picked up again
//Help23	> Make the surrounding glass opaque again and turn on collision on that sucker !


//BobSound
//--------
//
//Help01	> In ACS03, Bob goes "Echo".
//

//timer		- used for lightning bolts

SubRoutine(InitSceneSound16)
{
			if(incoming!=0)
			{
				if(ScriptMark==22)
				{
					callsub(Panel22);
				}
			}
			else
			{
				callsub(ScriptLevel16);
			}
			call(fadetoblack,2);
			//ambient sound Fx
			call(CDPlay,11,1);
			#include	"messiahscripts\stages\scene8sfx.hxx"
}


SubRoutine(DeInitSceneSound16)
{
		vector(_set,Gactorpos,-13486,20990,7949);
		samplestop(SFXShaftLoop,Gactorpos);

		vector(_set,Gactorpos,-15250,20762,8511);
		samplestop(sfxvent2loop,Gactorpos);

//rotodoor in Acs10

		vector(_set,Gactorpos,-6357,19555,12627);
		samplestop(SFXShaftRotate2,Gactorpos);
		vector(_set,Gactorpos,-7621,19555,11368);
		samplestop(SFXShaftRotate2,Gactorpos);

// Wind blowing

		vector(_set,Gactorpos,-7322,18256,10734);
		samplestop(SFXWindblow,Gactorpos);

		vector(_set,Gactorpos,-9073,18256,10755);
		samplestop(SFXWindblow,Gactorpos);

//ACS02
		vector(_set,Gactorpos,-8683,17634,10020);
		samplestop(SFXSmallSparks,Gactorpos);

		vector(_set,Gactorpos,-6506,17328,11129);
		samplestop(SFXElectric4,Gactorpos);

		//Hammer
		vector(_set,Gactorpos,-8094,17502,10694);
		samplestop(SFXGears,Gactorpos);


//ACSFoyer

		vector(_set,gactorpos,-8095,18328,12135);
		samplestop(SFXTechnoLoop,Gactorpos);

//ACS03
		vector(_set,Gactorpos,-5688,17767,12439);
		samplestop(SFXWindblow,Gactorpos);

		vector(_set,Gactorpos,-5688,17767,12439);
		samplestop(SFXHangerLift,Gactorpos);

		vector(_set,Gactorpos,-5688,17767,13778);
		samplestop(SFXHangerLift,Gactorpos);

//ACS04
		vector(_set,Gactorpos,-7037,18205,15171);
		samplestop(SFXCoolingFan,Gactorpos);

		vector(_set,Gactorpos,-8515,18205,15171);
		samplestop(SFXCoolingFan,Gactorpos);

		vector(_set,Gactorpos,-7798,19190,15166);
		samplestop(SFXElectric3,Gactorpos);

		vector(_set,Gactorpos,-7798,18313,15166);
		samplestop(SFXElectric3,Gactorpos);

//ACS05
		vector(_set,Gactorpos,-11835,18205,15171);
		samplestop(SFXCoolingFan,Gactorpos);

		vector(_set,Gactorpos,-12288,18577,12975);
		samplestop(SFXWindblow,Gactorpos);

		vector(_set,Gactorpos,-12587,18309,15262);
		samplestop(SFXWindblow,Gactorpos);

//ACS06
		vector(_set,Gactorpos,-12971,18205,14121);
		samplestop(SFXCoolingFan,Gactorpos);

		vector(_set,Gactorpos,-11837,18205,13076);
		samplestop(SFXCoolingFan,Gactorpos);

		vector(_set,Gactorpos,-12288,18577,12975);
		samplestop(SFXWindblow,Gactorpos);
}

SubRoutine(InitScene16)
{
			vector(_set,Gactorangle,0,2048,0);
			InitActor(Bob1,0,Gactorangle,"ltng");

			//Daniel's Enemy Script
			#include "messiahscripts\enemies\Perimeter.spt"


			// Reset all the variables
			call(loadpreloaddb,16);
			float(_set,VarKey2,0);
			float(_set,VarKey51,0);
			float(_set,VarKey52,0);
			float(_set,VarKey53,0);
			float(_set,VarKey54,1);				//init to worker not dead
			float(_set,VarKey55,0);
			float(_set,VarKey56,0);
			float(_set,VarKey57,0);
			float(_set,VarKey58,0);
			float(_set,VarKey59,-1);
			float(_set,VarKey60,0);
			float(_set,VarKey61,0);
			float(_set,VarKey62,0);
			float(_set,VarKey64,0);
			float(_set,VarKey65,0);
			float(_set,VarKey66,0);
			float(_set,VarKey67,0);
			float(_set,VarKey68,0);
			float(_set,VarKey69,0);
			float(_set,VarKey70,0);
			float(_set,HudTimer,0);
			float(_set,VarBit,AllHelp);
			float(_set,BobSound,AllHelp);
			float(_set,MissionLevel1,0);
			float(_set,MissionLevel2,0);
			float(_set,MissionLevel3,0);
			float(_set,MissionLevel4,0);
			float(_set,AngelReact,0);
			float(_set,timer,0);
			float(_set,timer2,0);
			float(_set,timer3,0);

			callsub(InitSceneSound16);
}

SubRoutine(MainScene16)
{

/////////////////////
//// CLUB ACCESS ////
/////////////////////

	if(VSetActive=="acs04")
	{
		if(VarKey59<0)
		{
			CurEnvTriggerSet("acs04","console");
			float(_set,TmpFloat,0x000000);
			call(expset2,TmpFloat,10,-1);
		}
		if(VarKey59<=3)
		{
			if(VarBit&=Help11)
			{
				CurEnvTriggerSet("acs04","fanctrl");
				float(_set,TmpFloat,0x0000ff);
				call(expset1,TmpFloat,350,-1);
				call(expset2,TmpFloat,350,-1);

				vector(_set,Gactorpos,-7928,18298,15701);
				vector(_set,Gactorine,-7921,18298,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);

				vector(_set,Gactorpos,-7785,18466,15694);
				vector(_set,Gactorine,-7784,18470,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);

				vector(_set,Gactorpos,-7644,18298,15701);
				vector(_set,Gactorine,-7652,18298,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);

				vector(_set,Gactorpos,-7785,18132,15694);
				vector(_set,Gactorine,-7784,18132,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);
			}
//
			if(VarBit&=Help10)
			{
				vector(_set,Gactorpos,-7928,19199,15701);
				vector(_set,Gactorine,-7921,19200,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);

				vector(_set,Gactorpos,-7785,19377,15694);
				vector(_set,Gactorine,-7784,19372,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);

				vector(_set,Gactorpos,-7644,19200,15701);
				vector(_set,Gactorine,-7651,19200,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);

				vector(_set,Gactorpos,-7785,19041,15694);
				vector(_set,Gactorine,-7784,19033,14590);
				callsub(ElectricStrip,gactorine,gactorpos,fx_blue);

				if(vrnd<15)
				{
					vector(_set,Gactorpos,-7782,18300,15609);
					vector(_set,tmpvector,0,100,250);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,500);

					vector(_set,Gactorpos,-7786,18300,14521);
					vector(_set,tmpvector,0,100,250);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,500);
				}
			}
		}
		elseif(VarKey59>=4)
		{
			CurEnvTriggerSet("acs04","fanctrl");
			float(_set,TmpFloat,0x000000);
			call(expset1,TmpFloat,10,-1);
			call(expset2,TmpFloat,10,-1);

			if(vrnd<10)
			{
				vector(_set,Gactorpos,-7800,18280,15600);
				vector(_set,Gactorine,0,15,0);
				call(SetParticleSetID,"acs04");
				spawnparticle(fx_steam,-1,gactorpos,gactorine,fx_doorsteam);
			}
		}
		
		if(VarKey59==-1)
		{
			CurEnvTriggerSet("acs04","victim");
			call(expset1,0,0,0);
			call(expset2,0,0,0);
		}
		elseif(VarKey59>-1)
		{
			CurEnvTriggerSet("acs04","victim");
			call(expset1,750,5,300);
			call(expset2,750,5,300);

			CurEnvTriggerSet("acs04","fnctrl");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
			}
			if(vrnd<50)
			{
				call(SetParticleSetID,"acs04");
				vector(_set,gactorpos,-7020,18100,15180);
				spawnparticle(fx_windspecks,-1,gactorpos,emptyvector,-1);
				vector(_set,gactorpos,-8524,18100,15180);
				spawnparticle(fx_windspecks,-1,gactorpos,emptyvector,-1);
			}
		}
		if(VarKey59>0)
		{
			CurEnvTriggerSet("acs04","victim");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,255,1);
			}
		}
	}
	if(VSetActive=="acs10")
	{
		CurEnvTriggerSet("acs10","pilon1");
		if(VKeyObjFrame==100 || VKeyObjFrame==46 || VKeyObjFrame==6 || VKeyObjFrame==61)
		{
			vector(_set,Gactorpos,-6357,19555,12627);
			sample(SFXShaftLock,Gactorpos);
		}

		CurEnvTriggerSet("acs10","pilon2");
		if(VKeyObjFrame==100 || VKeyObjFrame==46 || VKeyObjFrame==6 || VKeyObjFrame==61)
		{
			vector(_set,Gactorpos,-6357,19555,12627);
			sample(SFXShaftLock,Gactorpos);
		}
	}
	if(VSetActive=="acs05")
	{
		if(vrnd<50)
		{
			vector(_set,gactorpos,-11829,18100,15180);
			call(SetParticleSetID,"acs05");
			spawnparticle(fx_windspecks,-1,gactorpos,emptyvector,-1);
		}

		CurEnvTriggerSet("acs05","fanctrl");
		float(_set,TmpFloat,0x0099ff);
		call(expset1,TmpFloat,350,-1);
		call(expset2,TmpFloat,350,-1);
	}
	if(VSetActive=="acs07")
	{
		CurEnvTriggerSet("acs07","lifty");
		if(VKeyObjFrame==0)
		{
			call(expset1,0,0,0);
		}
		if(VKeyObjFrame==2)
		{
			call(expset1,11,11,11);
		}
		if(VKeyObjFrame==3)
		{
			call(expset1,20,20,20);
		}
		if(VarKey55==0)
		{
			call(KeyObjTrigger,5,1,-1);
			kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
			call(KeyObjActiveSegment,0,5);
			float(_set,VarKey55,1);
		}
		if(VKeyObjFrame==2 && VarKey55==6)
		{
			float(_set,VarKey55,7);
		}
		
		CurEnvTriggerSet("acs07","lift2club");
		if(VarKey55<3 && VarKey55>6)
		{
			call(EXPSet1,0,0,0);
		}
	}
	if(VCurSet=="acs06")
	{
		if(vrnd<50)
		{
			call(SetParticleSetID,"acs06");
			vector(_set,gactorpos,-13025,18100,14132);
			spawnparticle(fx_windspecks,-1,gactorpos,emptyvector,-1);
			vector(_set,gactorpos,-11844,18100,13070);
			spawnparticle(fx_windspecks,-1,gactorpos,emptyvector,-1);
		}

		CurEnvTrigger("fanctrl");
		call(expset1,1300,5,300);
		call(expset2,1300,5,300);
	}
	elseif(VCurSet=="acs11")
	{
		if(VarKey55==2)
		{
			CurEnvTrigger("trap");
			if(VKeyObjFrame==0)
			{
				CurEnvTrigger("workdor");
				if(VKeyObjFrame==0)
				{
					call(KeyObjTrigger,255,1);
					float(_set,TmpFloat,0x00ff00);
					call(expset2,1,TmpFloat,0);
					sample(SFXActivateComp,Gactorpos);
					vector(_set,Gactorpos,-9179,19558,13054);
					sample(SFXPneumatik2,Gactorpos);
					float(_set,VarKey55,3);
				}
			}
		}
	}
	elseif(VCurSet=="acs08")
	{
		CurEnvTrigger("doorslam");
		if(VKeyObjFrame==1 && timer2==0)	
		{
			vector(_set,Gactorpos,-9600,20033,14258);
			sample(SFXRustDoorOpen,Gactorpos);
			sample(SFXRustDoorLoop,Gactorpos);
			float(_set,timer2,1);
		}
		if(VKeyObjFrame==7 && timer2==1)
		{
			vector(_set,Gactorpos,-9600,20033,14258);
			samplestop(SFXRustDoorLoop,Gactorpos);
			sample(SFXRustDoorClose,Gactorpos);
			float(_set,timer2,2);
		}
		if(VKeyObjFrame==10 && timer2==2)
		{
			vector(_set,Gactorpos,-9500,20033,14258);
			sample(SFXRustDoorOpen,Gactorpos);
			sample(SFXRustDoorLoop,Gactorpos);
			float(_set,timer2,3);
		}
		if(VKeyObjFrame==12 && timer2==3)
		{
			vector(_set,Gactorpos,-9500,20033,14258);
			samplestop(SFXRustDoorLoop,Gactorpos);
			sample(SFXRustDoorClose,Gactorpos);
			float(_set,timer2,0);
		}
	}
	elseif(VCurSet=="clubsas")
	{
		if(VarBit&!=Help23)
		{
			if(BarmanTimer<110)
			{
				float(_add,BarmanTimer,1);
				if(BarmanTimer<=100)
				{
					if(BarmanTimer&=2)
					{
						CurEnvTrigger("trap");
						call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
						call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
						call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);
					}
					else
					{
						CurEnvTrigger("trap");
						call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
					}
				}
				else
				{
					CurEnvTrigger("trap");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				}
			}
		}
		elseif(BarmanTimer>0)
		{
			float(_sub,BarmanTimer,1);
			if(BarmanTimer>2)
			{
				if(BarmanTimer&=2)
				{
					CurEnvTrigger("trap");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);
				}
				else
				{
					CurEnvTrigger("trap");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				}
			}
			else
			{
				CurEnvTrigger("trap");
				call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
				call(SetTriggerObjFlag,2,_or,_SXObjCollisionOff);
			}
		}
	}
	elseif(VCurSet=="acs02")
	{
		call(SetParticleSetID,"acs02");
		if(VCutSceneFrame==240)
		{
			call(PlayerInput,1);
		}

		if(VarKey51>0)
		{
			float(_rnd2,TmpFloat,500);
			vector(_set,TmpVector,0,0,0);
			vector(_sety,TmpVector,TmpFloat);
			vector(_set,Gactorpos,-6445,17130,10781);
			vector(_set,Gactorine,-6445,17130,11482);
			vector(_add,Gactorpos,TmpVector);
			vector(_add,Gactorine,TmpVector);
			callsub(ElectricStrip,gactorpos,gactorine,fx_blue);

			if(vrnd<50)
			{
				if(vrnd<50)
				{
					vector(_set,gactorpos,-6489,17333,11505);
					vector(_set,tmpvector,8,8,255);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,350);	

					vector(_set,gactorpos,-6489,17333,10779);
					vector(_set,tmpvector,8,8,255);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,350);
				}
				else
				{
					vector(_set,gactorpos,6489,17333,11505);
					vector(_set,tmpvector,255,255,8);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,350);


					vector(_set,gactorpos,-6489,17333,10779);
					vector(_set,tmpvector,255,255,8);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,350);
				}
				float(_add,varkey51,1);
			}
			if(varkey51>=150)
			{
				float(_set,varkey51,0);
			}	
		}

		if(vrnd<50)
		{
			vector(_set,gactorpos,-8818,18553,11742);
			float(_rnd2,tmpfloat,128);
			float(_sub,tmpfloat,64);
			vector(_addx,gactorpos,tmpfloat);
			vector(_addy,gactorpos,tmpfloat);
			vector(_addz,gactorpos,tmpfloat);
			call(SetParticleSetID,"acs02");
			vector(_set,tmpvector,64,64,255);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,400);
		}
		else
		{
			vector(_set,gactorpos,-8818,18553,11742);
			float(_rnd2,tmpfloat,128);
			float(_sub,tmpfloat,64);
			vector(_addx,gactorpos,tmpfloat);
			vector(_addy,gactorpos,tmpfloat);
			vector(_addz,gactorpos,tmpfloat);
			call(SetParticleSetID,"acs02");
			vector(_set,tmpvector,255,64,64);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,400);
		}
		if(vrnd<20)
		{
			vector(_set,gactorpos,-8818,18553,11742);
			float(_rnd2,tmpfloat,128);
			float(_sub,tmpfloat,64);
			vector(_addx,gactorpos,tmpfloat);
			vector(_addy,gactorpos,tmpfloat);
			vector(_addz,gactorpos,tmpfloat);

			vector(_set,tmpvector,128,255,128);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,400)
		}

		if(VarKey2<3)
		{
			float(_sub,HudTimer,1);
			if(Hudtimer<=0)
			{
				float(_rnd2,TmpFloat,380);
				float(_set,HudTimer,TmpFloat);
			}
			if(HudTimer==5)
			{
				vector(_set,Gactorpos,-6506,17328,11129);
				sample(SFXZap02,Gactorpos);
				float(_set,HudTimer,0);
			}
		}
		if(VarKey2==0)
		{	
			float(_add,timer3,1)
			if(timer3&=16)
			{
				CurEnvTrigger("repair");
				float(_set,TmpFloat,0x000000)
				call(expset1,1,TmpFloat);
				call(expset2,1,TmpFloat);
				CurEnvTrigger("dr_bars");
				call(expset1,1,TmpFloat);
				call(expset2,1,TmpFloat);
			}
			else
			{
				CurEnvTrigger("repair");
				float(_set,TmpFloat,0xff0000)
				call(expset1,1,TmpFloat);
				call(expset2,1,TmpFloat);
				CurEnvTrigger("dr_bars");
				call(expset1,1,TmpFloat);
				call(expset2,1,TmpFloat);
			}
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
				vector(_set,Gactorpos,-8683,17634,10020);
				vector(_add,gactorpos,tmpvector);
				call(SetParticleSetID,"acs02");
				SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);

				vector(_set,tmpvector,238,177,10);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
			}
		}
		if(VarKey2==1 && VCutSceneFrame>=100)
		{
			float(_add,timer3,1);
			if(timer3==10)
			{
				CurEnvTrigger("dr_bars");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==30)
			{
				CurEnvTrigger("dr_bars");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==50)
			{
				CurEnvTrigger("repair");
				float(_set,TmpFloat,0x00ff00);
				call(expset1,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3==70)
			{
				CurEnvTrigger("repair");
				float(_set,TmpFloat,0x00ff00);
				call(expset2,1,TmpFloat,0);
				sample(SFXActivate1,Gactorpos);
			}
			if(timer3>=90)
			{
				float(_set,VarKey2,2);
				float(_set,timer3,0);
			}
		}

		CurEnvTrigger("lid02");
		float(_set,tmpfloat1,0);

		if(VarKey67&!=1)
		{
			if(vkeyobjframe==24)
			{
				vector(_set,Gactorpos,-7632,17396,11400);
				sample(SFXLatch3,gactorpos);
				float(_or,VarKey67,1);
			}
			elseif(vkeyobjframe==11)
			{
				vector(_set,Gactorpos,-7632,17396,11400);
				sample(SFXLatchSpecial,gactorpos);
				float(_or,VarKey67,1);
			}
		}

		if(vkeyobjframe!=24 && vkeyobjframe!=11)
		{
			float(_clr,VarKey67,1);
		}

		if(vkeyobjframe>=25||vkeyobjframe<=9)
		{
			float(_set,tmpfloat1,1);

			if(vkeyobjframe>=25||vkeyobjframe<8)
			{
				float(_set,tmpfloat3,0);
			}
			elseif(vkeyobjframe>=8)
			{
				float(_set,tmpfloat3,1);
			}

			if(vkeyobjframe==25 && VarKey67&!=4)
			{
				vector(_set,Gactorpos,-7632,17396,11400);
				sample(SFXFlamesBurning,gactorpos);
				float(_or,VarKey67,4);
			}
			elseif(vkeyobjframe==8 && VarKey67&=4)
			{
				vector(_set,Gactorpos,-7632,17396,11400);
				samplestop(SFXFlamesBurning,gactorpos);
				float(_clr,VarKey67,4);
			}
		}

		CurEnvTrigger("lid01");
		float(_set,tmpfloat,0);

		if(VarKey67&!=2)
		{
			if(vkeyobjframe==7)
			{
				vector(_set,Gactorpos,-8535,17396,11400);
				sample(SFXLatch3,gactorpos);
				float(_or,VarKey67,2);
			}
			elseif(vkeyobjframe==0)
			{
				vector(_set,Gactorpos,-8535,17396,11400);
				sample(SFXLatchSpecial,gactorpos);
				float(_or,VarKey67,2);
			}
		}

		if(vkeyobjframe!=7 && vkeyobjframe!=0)
		{
			float(_clr,VarKey67,2);
		}

		if(vkeyobjframe>=8&&vkeyobjframe<=26)
		{
			float(_set,tmpfloat,1);

			if(vkeyobjframe>=8&&vkeyobjframe<25)
			{
				float(_set,tmpfloat2,0);
			}
			elseif(vkeyobjframe>=25)
			{
				float(_set,tmpfloat2,1);
			}

			if(vkeyobjframe==8 && VarKey67&!=8)
			{
				vector(_set,Gactorpos,-8535,17396,11400);
				sample(SFXFlamesBurning,gactorpos);
				float(_or,VarKey67,8);
			}
			elseif(vkeyobjframe==25 && VarKey67&=8)
			{
				vector(_set,Gactorpos,-8535,17396,11400);
				samplestop(SFXFlamesBurning,gactorpos);
				float(_clr,VarKey67,8);
			}
		}


		if(tmpfloat==1)
		{
			if(tmpfloat2==0)
			{
				if(vrnd<100)
				{
					vector(_set,fxvector,0,0,-220);
					vector(_set,Gactorpos,-8535,17396,11350);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_addx,gactorpos,tmpfloat);
					vector(_addy,gactorpos,tmpfloat);
					vector(_addz,gactorpos,tmpfloat);

					vector(_set,Gactorine,0,0,-15);
					float(_rnd2,tmpfloat,5);
					vector(_subz,Gactorine,tmpfloat);
					call(SetParticleSetID,"acs02");
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);

					vector(_set,tmpvector,230,85,15);
					spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);
				}

				if(skipcollidecount>=5)
				{
					vector(_copy,gactorine,gactorpos);
					vector(_add,Gactorpos,fxvector);
					call(CheckActorCollision,gactorpos,85,0,_COLFire);

					vector(_set,fxvector,0,0,-20);
					vector(_add,gactorine,fxvector);
					call(CheckActorCollision,gactorine,85,0,_COLFire);
				}
			}
			else
			{
				vector(_set,Gactorpos,-8535,17396,11350);
				float(_rnd2,tmpfloat,32);
				float(_sub,tmpfloat,16);
				vector(_addx,gactorpos,tmpfloat);
				vector(_addy,gactorpos,tmpfloat);
				vector(_addz,gactorpos,tmpfloat);


				vector(_set,Gactorine,0,0,-10);
				float(_rnd2,tmpfloat,5);
				vector(_subz,Gactorine,tmpfloat);
				call(SetParticleSetID,"acs02");
				SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
			}
		}
		if(tmpfloat1==1)
		{
			if(tmpfloat3==0)
			{
				if(vrnd<100)
				{
					vector(_set,fxvector,0,0,-220);
					vector(_set,Gactorpos,-7632,17396,11350);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_addx,gactorpos,tmpfloat);
					vector(_addy,gactorpos,tmpfloat);
					vector(_addz,gactorpos,tmpfloat);

					vector(_set,Gactorine,0,0,-15);
					float(_rnd2,tmpfloat,5);
					vector(_subz,Gactorine,tmpfloat);
					call(SetParticleSetID,"acs02");
					SpawnParticle(fx_firejets,-1,Gactorpos,Gactorine,fx_scale10);

					vector(_set,tmpvector,230,85,15);
					spawnlight(fire_light2,-1,Gactorpos,tmpvector,EmptyVector,600);
				}

				if(skipcollidecount>=5)
				{
					vector(_copy,gactorine,gactorpos);
					vector(_add,Gactorpos,fxvector);
					call(CheckActorCollision,gactorpos,85,0,_COLFire);

					vector(_set,fxvector,0,0,-20);
					vector(_add,gactorine,fxvector);
					call(CheckActorCollision,gactorine,85,0,_COLFire);
				}
			}
			else
			{
				vector(_set,Gactorpos,-7632,17396,11350);
				float(_rnd2,tmpfloat,32);
				float(_sub,tmpfloat,16);
				vector(_addx,gactorpos,tmpfloat);
				vector(_addy,gactorpos,tmpfloat);
				vector(_addz,gactorpos,tmpfloat);

				vector(_set,Gactorine,0,0,-10);
				float(_rnd2,tmpfloat,5);
				vector(_subz,Gactorine,tmpfloat);
				call(SetParticleSetID,"acs02");
				SpawnParticle(fx_smogjets,-1,Gactorpos,Gactorine,fx_scale10);
			}
		}

		
		//electric fence
		if(vrnd<50)
		{
			vector(_set,gactorpos,-6489,17333,11505);
			vector(_set,tmpvector,8,8,255);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,350);

			vector(_set,gactorpos,-6489,17333,10779);
			vector(_set,tmpvector,8,8,255);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,350);
		}

		CurEnvTrigger("dr_bars");
		if(VKeyObjTriggered==0 && VarKey2==4)
		{
			vector(_set,Gactorpos,-6506,17328,11129);
			sample(SFXElectric4,Gactorpos);
			float(_set,VarKey2,2);
		}
	}

	if(skipcollidecount>=5)
	{
		float(_set,skipcollidecount,0);
	}
	float(_add,skipcollidecount,1);

	float(_add,FireJetLife,1);
}


SubRoutine(BackgroundTriggerChecksScene16)
{
	print("VaRKey59    : ",VarKey59);
	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel16); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

////////////////////
//// CLUB ACCESS ////
/////////////////////
	if(VCurSet=="acs02")
	{
		if(VarKey57==0)
		{
			call(PlayerInput,0);
			CutScene("begin");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			float(_set,VarKey57,1);
		}
		elseif(VarKey57==1 && VAICon==0)
		{
			if(VCutSceneFrame==220)
			{
				CurEnvTrigger("lift");
				callsub(DoorOpen,1,1);
			}
			elseif(VCutSceneFrame==300)
			{
				call(CutSceneEnd);
				float(_set,VarKey57,2);
				call(PlayerInput,1);
			}
		}

		CurEnvTrigger("diecheck");
		callsub(Fall2Death);
		
		CurEnvTrigger("lid01");
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,28,1,-1);
			call(KeyObjActiveSegment,0,28);
		}

		CurEnvTrigger("lid02");
		if(VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,34,1,-1);
			call(KeyObjActiveSegment,0,34);
		}
					
		if(VAICon==0)
		{
			CurEnvTrigger("pelisse2");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Sub_SetCameraNormal);
			}

			CurEnvTrigger("pelisse");
			if(VTrigger==_DIREnvTrigger)
			{
				Camera(elevator_camera_distance,elevator_camera_angle);
				Target(elevator_camera_Tdistance,elevator_camera_Tangle);
			}

			CurEnvTrigger("pelisse4");
			if(VTrigger==_DIREnvTrigger)
			{
				callsub(Sub_SetCameraNormal);
			}

			CurEnvTrigger("pelisse3");
			if(VTrigger==_DIREnvTrigger)
			{
				Camera(200,400);
				Target(-10,20);
			}
		}
		if(VarBit&!=Help01 && VarBit&=Help02)
		{
			if(VAICon!=0 && VPathID==3)
			{
				call(AIfindpathwithspecificid,4);
				float(_clr,Varbit,Help02);
			}
		}
		CurEnvTrigger("bounce");
		if(VTrigger==_DIREnvTrigger && VTrigger!=_DIRMove && VAICon==0)
		{
			if(VarBit&=Help18)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,22);
				callsub(Panel22);
				ClearDMessage();
				float(_clr,VarBit,Help18);
			}
			if(VAIClass==_AIClassPimp)
			{
				if(VarBit&=Help01)
				{
					ClearDMessage();
					dmessage("Pimp Daddy@ you and your ladies caused one hell",50,250);
					dmessage("of a disaster last night! Boss says you're banned",60,250);
					dmessage("for a week!",70,250);
					float(_clr,VarBit,Help01);
				}
			}
			else
			{
				if(varkey70==0)
				{
					if(VAIClass!=_AIClassBeast)
					{
						ClearDMessage();
						dmessage("Club Kyd Is Full. Please Come Back Later",50,200);
						sample(SFXAccessDenied,Gactorpos);
						float(_set,VarKey70,1);
					}
				}
			}
		}


		CurEnvTrigger("dr_bars");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0 && VAICon==0)
		{
			if(VarKey2>=2)
			{
				call(ActivateButton,"Electrical Gate Opened.",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				vector(_set,Gactorpos,-6506,17328,11129);
				samplestop(SFXElectric4,Gactorpos);
				sample(SFXScanHumm02,Gactorpos);
				float(_set,VarKey2,3);
				direction(_clr,_DIRaction);
			}
			else
			{
				call(ActivateButton,"System Deficiency - Circuit Box Needs Repair",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
				direction(_clr,_DIRaction);

				if(varkey51==0)
				{
					float(_set,varkey51,1);
				}
			}
		}
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("bounce");
			float(_set,TmpFloat,0xff0000);
			call(Expset1,1,TmpFloat,0);
		}
		else
		{
			CurEnvTrigger("bounce");
			float(_set,TmpFloat,0x00ff00);
			call(Expset1,1,TmpFloat,0);
		}

		if(VarKey2==3)
		{
			float(_add,timer3,1);
			if(timer3>=100)
			{
				CurEnvTrigger("dr_bars");
				callsub(DoorOpen,1,1);
				float(_set,VarKey2,4);
				float(_set,timer3,0);
			}
		}
		CurEnvTrigger("zap");
		if(VarKey2<4)
		{
			if(VTrigger==_DIREnvTrigger)
			{
				colstate(_or,_COLelectricity);
			}
		}

		CurEnvTrigger("repair");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			//if(VAIClass==_AIClassWorker)
			//{
				if(VAIcon==0)
				{
					if(VarKey2==0)
					{
						call(ActivateButton,"Power to Control Console Engaged",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						vector(_set,Gactorpos,-8683,17634,10020);
						samplestop(SFXSmallSparks,Gactorpos);
						call(KeyObjTrigger,255,1);
						CurEnvTrigger("repair");
						float(_set,TmpFloat,0xff0000);
						call(expset1,1,TmpFloat);
						call(expset2,1,TmpFloat);
						CurEnvTrigger("dr_bars");
						call(expset1,1,TmpFloat);
						call(expset2,1,TmpFloat);
						float(_set,VarKey2,1);
						call(PlayerInput,0);
						CutScene("camera01");
						float(_set,timer3,0);
						direction(_clr,_DIRaction);
					}
					else
					{
						call(ActivateButton,"Power already restored",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
			}
		//	else
		//	{
		//		call(ActivateButton,"What is this thing doing?",-1,FALSE);
		//		call(ActivateButtonSample,SFXInvalidFunction);
		//	}
		//}
	}
	elseif(VCurSet=="acs03")
	{
		CurEnvTrigger("diecheck");
		callsub(Fall2Death);

		CurEnvTrigger("doorslam");
		if(VTrigger==_DIREnvTrigger);
		{
			CurEnvTrigger("slam");
			if(VKeyObjTriggered==0 && VarKey2==4)
			{
				call(KeyObjTrigger,255,1);
				vector(_set,Gactorpos,-6220,17219,11146);
				sample(SFXBigDoorSlamShut,-1);
				vector(_set,gactorpos,-8095,18328,12135);
				samplestop(SFXTechnoLoop,Gactorpos);
				call(ScreenShake,0,15,0,0.8);
				float(_set,VarKey2,5);
			}
		}

		if(BobSound&=Help01)
		{
			CurEnvTrigger("echo");
			if(VAIClass==_AIClassAngel)
			{
				if(VTrigger==_DIREnvTrigger)
				{
					sample(SFXBobWideRoom,-1);
					float(_clr,BobSound,Help01);
				}
			}
		}	
		CurEnvTrigger("elecarc");
		if(Vrnd<5)
		{
			float(_set,TmpFloat,0xffffff);
			call(expset1,1,TmpFloat,0);
		//	vector(_set,gactorpos,-15069,22138,11846);
		//	vector(_set,tmpvector,18,167,236);
		//	spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);

		//	vector(_set,gactorpos,-15069,21202,11846);
		//	vector(_set,tmpvector,18,167,236);
		//	spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
		}
		else
		{
			float(_set,TmpFloat,0x000000);
			call(expset1,1,TmpFloat,0);
		}
	}
	elseif(VCurSet=="acs04")
	{
		CurEnvTrigger("fakedr");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Locked Until End of Duty",120,10);
			sample(SFXInvalidFunction,Gactorpos);
		}

		if(VCutScene!=0)
		{
			direction(_clr,_DIRShoot|_DIRMoveBits);
		}
	/*
		if(VarBit&!=Help09)
		{
			CurEnvTrigger("wayout");
			if(VTrigger==_DIREnvTrigger && VFirstPerson!=0)
			{
				float(_or,VarBit,Help09);
				float(_clr,VarBit,Help19);
			}
		}
		if(VarBit&!=Help19)
		{
			CurEnvTrigger("out");
			if(VTrigger!=_DIREnvTrigger)
			{
				firstperson(0,0);
				float(_or,VarBit,Help19);
			}
		}
	*/
		CurEnvTrigger("diecheck");
		callsub(Fall2Death);

		CurEnvTrigger("fake");
		if(VTrigger==_DIREnvTrigger && Vtrigger==_DIRaction)
		{
			message("Locked Until End of Duty",120,10);
			sample(SFXAccessDenied,Gactorpos);
		}

		CurEnvTrigger("opdoor");
		if(VTrigger==_DIREnvTrigger && VaRKey59>=0)
		{
			if(VKeyObjFrame==0)
			{
				call(KeyObjTrigger,255,1);
				kfsample(SFXLatchSpecial,SFXVaultMove,-1,SFXLatchSpecial);
				direction(_clr,_DIRaction);
			}
		}

		if(VAICon==0)
		{
			CurEnvTrigger("crouch");
			if(VTrigger==_DIREnvTrigger && VAIClass==_AIClassAngel)
			{
				if(VTrigger==_DIRCrouch)
				{
					call(ClrAllCollisionBuffers);
				}
				if(VState==StateCrouching)
				{
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
				}
				else
				{
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
				}
			}
		
			if(VarBit&=Help10)
			{
				CurEnvTrigger("fnctrl");
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					float(_clr,VarBit,Help10);
				}
				CurEnvTrigger("strip2a");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VarKey59<4)
					{	
						colstate(_or,_COLelectricity);
					}
				}
				else
				{
					CurEnvTrigger("strip2b");
					if(VTrigger==_DIREnvTrigger)
					{
						if(VarKey59<4)
						{	
							colstate(_or,_COLelectricity);
						}
					}
				}
			}
			if(VarBit&=Help11)
			{
				CurEnvTrigger("fnctrl");
				call(CheckTriggerObjFlag,TmpFloat,2,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					float(_clr,VarBit,Help11);
				}
				CurEnvTrigger("strip1a");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VarKey59<4)
					{	
						colstate(_or,_COLelectricity);
					}
				}
				else
				{
					CurEnvTrigger("strip1b");
					if(VTrigger==_DIREnvTrigger)
					{
						if(VarKey59<4)
						{	
							colstate(_or,_COLelectricity);
						}
					}
				}
			}


			CurEnvTrigger("console");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VAICon==0)
				{
					if(VarKey59==-1)
					{
						call(ActivateButton,"Cooling Fan Activated",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						sample(SFXPumpPowerUp,-1);
						float(_set,VarKey59,0);
						CurEnvTrigger("meter");
						float(_set,TmpFloat,0xffffff);
						call(expset1,1,TmpFloat,0);
						CurEnvTrigger("console");
						float(_set,TmpFloat,0x00aa00);
						call(expset2,TmpFloat,250,-1);
						sample(SFXCoolingFan,-1);
						samplevolume(SFXCoolingFan,50);
						direction(_clr,_DIRaction);
					}
					elseif(VarKey59==0 && VarBit&=Help11)
					{
						call(ActivateButton,"Cooling Fan Power Surge",-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
						samplevolume(SFXCoolingFan,100);
						sample(SFXPumpPowerUp,-1);
						CurEnvTrigger("meter");
						float(_set,TmpFloat,0xffffff);
						call(expset2,1,TmpFloat,0);
						CurEnvTrigger("console");
						float(_set,TmpFloat,0xff0000);
						call(expset2,TmpFloat,250,-1);
						call(PlayerInput,0);
						float(_set,VarKey59,1);
						float(_set,timer2,0);
						direction(_clr,_DIRaction);
					}
					else
					{
						call(ActivateButton,"System Malfunction",-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
						direction(_clr,_DIRaction);
					}
				}
			}

			if(VKeyObjTriggered!=0)
			{
				if(VKeyObjFrame>16 && VKeyObjFrame<24)
				{
					vector(_set,Gactorpos,-7733,18311,15399);
					vector(_set,tmpvector,0,100,250);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
					vector(_set,Gactorpos,-5576,18277,15348);
					sample(SFXTeslaCoil,Gactorpos);
				}
				if(VKeyObjFrame>28 && VKeyObjFrame<36)
				{
					vector(_set,Gactorpos,-7733,18311,15399);
					vector(_set,tmpvector,0,100,250);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
					vector(_set,Gactorpos,-5576,18277,15348);
					sample(SFXTeslaCoil,Gactorpos);
				}
				if(VKeyObjFrame==30)
				{
					vector(_set,Gactorpos,-5576,18277,15348);
					sample(SFXBazookaExplode,Gactorpos);
					call(wCheckViewCollision,-1,-1,-1,-1);
					call(SetParticleSetID,"acs04");
					vector(_set,fxvector,0,100,0);
					vector(_set,tmpvector,255,0,0);
					vector(_set,Gactorpos,-7800,18250,15600);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
					spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,1500);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,-1);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,fx_antirotate8);
					vector(_add,gactorpos,fxvector);
					spawnparticle(fx_mainexplosion,-1,gactorpos,emptyvector,-1);
					vector(_set,Gactorpos,-7798,19190,15166);
					samplestop(SFXElectric3,Gactorpos);
					vector(_set,Gactorpos,-7798,18313,15166);
					samplestop(SFXElectric3,Gactorpos);
					float(_set,VarKey59,4);
				}
			}

			if(VarKey61==0)
			{
				call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
				if(TmpFloat==TRUE)
				{
					vector(_set,Gactorpos,-4879,18325,15352);
					sample(SFXWindBlow,Gactorpos);
					float(_set,VarKey61,1);
				}
			}
			if(VarKey59==1)
			{
				float(_add,timer2,1);
				if(timer2>=80)
				{
					if(VSniperMode!=0)
					{
						call(ChangeSniperMode,-2,0);
					}
					CutScene("mungsucker");
					float(_set,VarKey59,2);
					float(_set,timer2,0);
				}
			}
			
			if(VCutSceneFrame>=165 && VCutSceneFrame<=170 && VarKey59!=0)
			{
				CurEnvTrigger("console");
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,255,1);
				}
			}
			if(VCutSceneFrame>=250 && VCutSceneFrame<=280)
			{
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			}
			if(VCutSceneFrame>=290 && VarKey59<5)
			{
				call(ChangeCutScene,_SXCUTflag,_clr,_SXCUTnosmooth);
				call(PlayerInput,1);
				float(_set,VarKey59,5);
			}
		}
	}
	elseif(VCurSet=="acs05")
	{
		CurEnvTrigger("diecheck");
		callsub(Fall2Death);

		if(VAICon==0)
		{
			CurEnvTrigger("opdoor");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Automatic Lock Has Been Activated. Access Denied",200,10);
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
			if(VKeyObjTriggered==0)
			{
				float(_set,TmpFloat,0xff0000);
				call(expset1,1,TmpFloat,0);
			}
			
			CurEnvTrigger("SCFLDUP");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VkeyObjTriggered==0)
				{
					call(ActivateButton,"AutoLift Activated - Switching to Auto.",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					call(KeyObjTrigger,255,1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
				}
			}
			if(VKeyObjTriggered!=0)
			{
				camera(500,300);
				target(-10,10);
			}
			else
			{
				callsub(Sub_SetCameraNormal);
			}



			CurEnvTrigger("SCFLDDWN");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				call(ActivateButton,"AutoLift is in Automatic Mode.",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}
			


			COLobj("lightdummy");
			if(VTrigger==_DIRTempFlag)
			{
				colstate(_or,_COLelectricity);
			}
		}
	}
	elseif(VCurSet=="acs06")
	{
		CurEnvTrigger("diecheck");
		callsub(Fall2Death);
	}

	elseif(VCurSet=="acsvent")
	{
		if(VarBit&!=Help09)
		{
			if(VAICon==0 && VState!=StateCrouching)
			{
				direction(_or,_DIRCrouch);
			}
		}
		else
		{
			CurEnvTrigger("trig1");
			if(VTrigger==_DIREnvTrigger && VFirstPerson==0)
			{
				camera(100,0);
				target(0,0);
			}
		}

		if(VarBit&=Help17)
		{
			CurEnvTrigger("knee");
			if(VTrigger==_DIREnvTrigger)
			{
				sample(SFXBobCrawls,-1);
				float(_clr,VarBit,Help17);
			}
		}

		CurEnvTrigger("wayin");
		if(VTrigger==_DIREnvTrigger && VFirstPerson==0)
		{
			firstperson(1,1);
			float(_clr,VarBit,Help09);
		}
		CurEnvTrigger("wayout");
		if(VTrigger==_DIREnvTrigger && VFirstPerson==1)
		{
			firstperson(0,0);
			float(_or,VarBit,Help09);
		}
	
		CurEnvTrigger("gridin");
		if(VTrigger==_DIREnvTrigger && VFirstPerson==1)
		{
			firstperson(0,0);
			float(_or,VarBit,Help09);
		}

		CurEnvTrigger("gridout");
		if(VTrigger==_DIREnvTrigger && VFirstPerson==0)
		{
			firstperson(1,1);
			float(_clr,VarBit,Help09);
		}

		CurEnvTrigger("fall");
		if(VTrigger==_DIREnvTrigger && VKeyObjFrame==0 && VKeyObjTriggered==0)
		{
			call(KeyObjTrigger,255,1);
			sample(SFXRustDoorClose2,-1);
		}
	}
	elseif(VCurSet=="acsbooth")
	{
		if(VCutScene!=0)
		{
			direction(_clr,_DIRShoot|_DIRMoveBits);
		}
	}
	elseif(VCurSet=="acs07")
	{
		if(VAICon==0)
		{
			if(VarKey55==3)
			{
				CurEnvTrigger("Lift2Club");
				if(VTrigger==_DIREnvTrigger)
				{
					if(VAICON==0)
					{
						call(FaceTriggerDirection);
						call(PlayerInput,0);
						message("Lift Called - Please Wait a Moment",250,10);
						sample(SFXAccessOk,Gactorpos);
						vector(_set,Gactorpos,-9800,19543,13091);
						sample(SFXLiftMove,Gactorpos);
						call(expset1,1,1,15);
						float(_set,VarKey55,4);
						float(_clr,VarBit,Help12);
					}
				}
			}
			elseif(VarKey55==4)
			{
				CurEnvTrigger("lifty");
				if(VKeyObjFrame==1 && VKeyObjTriggered==0)
				{
					vector(_set,Gactorangle,0,3000,0);
					vector(_set,Gactorpos,-9583,18752,12865);
					InitActor(WeaponPumpGun,Gactorpos,Gactorangle,"acs07");
					vector(_set,Gactorpos,-9583,18702,12865);
					InitActor(dweller1,Gactorpos,Gactorangle,"acs07",FALSE,0);
					float(_clr,VarBit,Help12);
					float(_set,VarKey55,5);
					float(_set,timer4,0);
				}
			}
			elseif(VarKey55==5)
			{
				float(_add,timer4,1);
				if(timer4>=150)
				{
					CurEnvTrigger("lifty");
					call(KeyObjTrigger,2,1);
					kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
					float(_set,timer4,0);
					float(_set,VarKey55,6);
				}
			}
			elseif(VarKey55==7)
			{
				CurEnvTrigger("Lift2Club");
				vector(_set,Gactorpos,-9800,19543,13091);
				samplestop(SFXLiftMove,gactorpos);
				vector(_set,Gactorpos,-9442,21322,13081);
				sample(SFXSmallLiftStop2,Gactorpos);
				call(KeyObjTrigger,1,1);
				float(_set,VarKey55,8);
			}
			elseif(VarKey55==8)
			{
				if(VAICon==0)
				{
					direction(_clr,_noDIR);
					direction(_or,_DIRForward|_DIRmove|_DIRWalking);
				}
			}
				
			CurEnvTrigger("inlift");
			if(VTrigger==_DIREnvTrigger && VarKey55==8)
			{
				float(_set,VarKey55,9);
				CurEnvTrigger("Lift2Club");
				call(KeyObjTrigger,2,1);

				CurEnvTrigger("lifty");
				call(KeyObjTrigger,3,1);
				kfsample(SFXLiftStart,SFXLiftMove,-1,SFXLiftEnd);
			}
			
			if(VarKey55>7)
			{
				CurEnvTrigger("Lift2Club");
				if(VKeyObjTriggered==0 && VKeyObjFrame==0)
				{
					call(PlayerInput,1);
					callsub(Sub_SetCameraNormal);
				}
			}

			CurEnvTrigger("clubenter");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
			{
				if(VarKey55>=7)
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
					sample(SFXAccessDenied,Gactorpos);
				}
			}
			
			if(ControlTimer==1)
			{
				CurEnvTrigger("clubenter")
				if(VSetActive=="clubsas")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("acs07","clubenter",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}

		CurEnvTrigger("diecheck");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="acs08")
	{
		CurEnvTrigger("doorslam");
		if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
		{
			callsub(DoorOpen,2,0);
			direction(_clr,_DIRaction);
			float(_set,timer2,0);
		}
	}
	elseif(VCurSet=="acs10")
	{
		CurEnvTrigger("entrance");
		if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0 && VAICon==0)
		{
			callsub(DoorOpen,2,1);
		}
	}
	elseif(VCurSet=="acs09")
	{
		if(VAICon==0)
		{
			if(VarKey68&!=4)
			{
				CurEnvTriggerSet("acs10","pilon1");
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,110,1,-1);
					call(KeyObjActiveSegment,0,110);
				}
				CurEnvTriggerSet("acs10","pilon2");
				if(VKeyObjTriggered==0)
				{
					call(KeyObjTrigger,110,1,-1);
					call(KeyObjActiveSegment,0,110);
				}
			}
			
			CurEnvTrigger("piege");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VarKey68&!=4)
				{
					call(PlayerInput,0);
					float(_or,VarKey68,4);
					float(_set,timer2,0);
				}
			}
		}
		if(VarKey68&=4 && VarKey68&!=8)
		{
			if(VAIClass==_AIClassWorker)
			{
				if(Vaction==WorkerWeldingKneel)
				{
					spawnaction(WorkerKneelCrush);
					sample(SFXShaftRotate2,Gactorpos);
				}
			}

			float(_add,Timer2,1);
			if(timer2==120)
			{
				CurEnvTrigger("panel");
				call(KeyObjTrigger,255,1);
				sample(SFXGunTurretHatch,-1);
			}
			if(timer2>=210 && VAIClass==_AIClassWorker)
			{
				sample(SFXWorkerKneelCrush,-1);
				float(_or,VarKey68,8);
				float(_set,timer2,0);
			}
		}
		if(VarKey68&=8)
		{
			CurEnvTrigger("piege");
			if(VKeyObjTriggered==0)
			{
				call(KeyObjTrigger,110,1,-1);
				call(KeyObjActiveSegment,0,110);
			}

			if(VKeyObjFrame==6 || VKeyObjFrame==61)
			{
				vector(_set,Gactorpos,-7636,19470,13946);
				sample(SFXShaftLock,Gactorpos);
				float(_clr,VarKey68,8);
				float(_or,VarKey68,16);
				float(_set,timer3,0);
			}
		}
		if(VarKey68&=16)
		{
			if(AngelReact==0)
			{
				float(_set,AngelReact,1);
			}
			if(VAIClass==_AIClassWorker)
			{
				if(Vaction==WorkerKneelCrush)
				{
					vector(_set,Gactorpos,-7636,19470,13946);
					vector(_set,tmpvector,250,250,250);
					spawnlight(Omni_Flash,-1,Gactorpos,tmpvector,EmptyVector,600);
					sample(SFXWorkerKneelCrush,Gactorpos);
					spawnaction(WorkerKneelDead);
					//if(AIAbility&=_AIAPickUpWeapon)
					//{
						call(CheckAttached,_CADropWeaponAndShells);
					//}
					Direction(_clr,_DIRalive);
					State(_or,StateDead);
				}
			}
			if(VAICon==0)
			{
				float(_add,timer3,1);
			}
			if(timer3<=20)
			{
				vector(_set,fxvector,-7636,19470,13946);
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
			}
			else
			{
				float(_clr,VarKey68,16);
				float(_or,VarKey68,8);
			}
		}
		if(AngelReact==1)
		{
			if(VAIClass==_AIClassAngel)
			{
				spawnaction(BobBangHead);
				call(PlayerInput,1);
				float(_set,AngelReact,2);
			}
		}
	}

	elseif(VCurSet=="acs11")
	{
		if(VCutscene==0)
		{
			call(PlayerInput,1);
		}
		else
		{
			call(PlayerInput,0);
		}

		CurEnvTrigger("fake");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Locked.",150,10);
			sample(SFXPlayerActivatesLockedDoorReact,-1);
		}
		CurEnvtrigger("breakleg");
		if(VTrigger==_DIREnvTrigger && VAICon!=0)
		{
			if(VarKey68&!=1)
			{
				if(VAIClass==_AIClassWorker)
				{
					state(_or,StateCrawling)
					state(_clr,StateExecuteAnim);
					//sample(SFXPainMale1,-1);
					sample(SFXBreakLegReact,-1);
					
					//if(AIAbility&=_AIAPickUpWeapon)
					//{
						call(CheckAttached,_CADropWeaponAndShells);
					//}
					CallSub(Sub_ChangeStateToNormal);
					float(_or,VarKey68,1);
				}
			}
		}
/*
		CurEnvTrigger("trap");
		if(VKeyObjFrame==20)
		{
			CurEnvTrigger("entrance");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIcon==0)
				{
					call(LockCamera,1);
					call(PlayerInput,0);
					Direction(_clr,_DIRalive);
					State(_or,StateDead);
					call(FadeToBlack,4);
				}
			}
		}
*/
		CurEnvTrigger("workdor");
		if(VTrigger==_DIREnvTrigger && VAICon==0)
		{
			setkeyframe("acs07","lifty",1);
			call(DeleteEntitiesAndActorsInSet,"acs07");
			if(VAIClass==_AIClassWorker)
			{
				if(Vtrigger==_DIRaction)
				{
					Curenvtrigger("entrance");
					if(VKeyobjtriggered==0 && VKeyObjFrame==0)
					{
						call(ActivateButton,0,-1,FALSE);
					}
					else
					{
						Message("Wait for airlock to close",200,10);
						sample(SFXInvalidFunction,-1);
						direction(_clr,_DIRaction);
					}
				}
				elseif(VState==StateJustActivated)
				{
					if(MissionLevel1!=0 && VarKey55<2)
					{
						message("All System Back To Normal",120,10);
						float(_set,TmpFloat,0x00ff00);
						call(expset1,1,TmpFloat,0);
						CurEnvTrigger("trap");
						call(KeySpeed,0,20,1000);
						call(KeyObjTrigger,0,-1);
						float(_set,VarKey55,2);
						vector(_set,Gactorpos,-8908,19729,12936);
						KillLight(LightPulseOmni3,Gactorpos,16);
						samplestop(SFXSirenAlert,Gactorpos)
						direction(_clr,_DIRaction);
						sample(SFXValidFunction,-1);
					}
					else
					{
						message("Door Unlocked",120,10);
						CurEnvTrigger("workdor");
						if(VKeyObjFrame==0)
						{
							call(KeyObjTrigger,255,1);
							float(_set,TmpFloat,0x00ff00);
							call(expset2,1,TmpFloat,0);
							sample(SFXValidFunction,-1);
							//sample(SFXActivateComp,Gactorpos);
							vector(_set,Gactorpos,-9179,19558,13054);
							sample(SFXPneumatik2,Gactorpos);
							float(_set,VarKey55,3);
						}
					}
				}
			}
			else
			{
				if(Vtrigger==_DIRaction)
				{
					Curenvtrigger("entrance");
					if(VKeyobjtriggered==0 && VKeyObjFrame==0)
					{
						call(ActivateButton,0,-1,FALSE);
					}
					else
					{
						Message("Wait for airlock to close",200,10);
						sample(SFXInvalidFunction,-1);
						direction(_clr,_DIRaction);
					}
				}
				elseif(VState==StateJustActivated)
				{
					if(VarKey55<2)
					{
						CurEnvTrigger("trap");
						if(VKeyObjFrame==0)
						{
							sample(SFXInValidFunction,-1);
							message("INTRUDER ALERT - EMERGENCY PROCEDURE",120,10);
							vector(_set,Gactorpos,-8715,19593,13054);
							sample(SFXIndustrial12,Gactorpos);
							float(_set,TmpFloat,0xff0000);
							call(expset1,1,TmpFloat,0);
							float(_set,MissionLevel1,1)
						}
						else
						{
							sample(SFXInValidFunction,-1);
							message("Improper Digital Identification. Crushing Process Continuing.",300,10);
							sample(SFXInvalidFunction,Gactorpos);
						}
					}
					else
					{
						CurEnvTrigger("workdor");
						if(VKeyObjFrame==0)
						{
							message("Unlocking Door",120,10);
							sample(SFXValidFunction,-1);
							call(KeyObjTrigger,255,1);
							float(_set,TmpFloat,0x00ff00);
							call(expset2,1,TmpFloat,0);
							sample(SFXActivateComp,Gactorpos);
							vector(_set,Gactorpos,-9179,19558,13054);
							sample(SFXPneumatik2,Gactorpos);
							float(_set,VarKey55,3);
						}
					}
				}
			}
		}
		if(MissionLevel1==1)
		{
			CutScene("mungsucker");
			float(_set,MissionLevel1,2);
			float(_set,timer3,0);
		}
		if(MissionLevel1==2 && VCutSceneFrame==90)
		{	
			CurEnvTrigger("trap");
			call(KeyObjTrigger,10,1);
			sample(SFXGunTurretHatch,-1);
			direction(_clr,_DIRaction);
			float(_clr,VarBit,Help08);
			vector(_set,tmpvector,80,-50,-100);
			vector(_set,Gactorpos,-8908,19729,12936);
			spawnlight(LightPulseOmni3,-1,Gactorpos,tmpvector,EmptyVector,1000);
			sample(SFXSirenAlert,Gactorpos)
			float(_set,MissionLevel1,3);
		}
		if(MissionLevel1==3 && VCutSceneFrame>=190)
		{
			CurEnvTrigger("trap");
			call(KeyObjTrigger,255,1);
			kfsample(-1,SFXIndustrial2,-1,-1);
			sample(SFXRustDoorClose,-1);
			float(_set,MissionLevel1,4);
		}
	}

//////////////////
//// Club KYD ////
//////////////////
	elseif(VCurSet=="clubsas")
	{
		if(VAICon==0)
		{
			if(VTrigger==_DIRHaveGun)
			{
				float(_set,DisablePickUp,1);
			}
			if(VarBit&=Help20 && VarBit&=Help22)
			{
				if(VTrigger==_DIRHAveGun || VactorFlag==_AFLAGweaponinvisible)
				{
					float(_set,DisablePickup,1);
					float(_clr,VarBit,Help20);
				}
			}
			CurEnvTrigger("enter");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(VAIClass==_AIClassAngel)
				{
					if(ControlTimer==0)
					{
						float(_set,ControlTimer,1);
						call(RunScriptCode,_or,9);
						call(KeyObjTrigger,255,1);
						direction(_clr,_DIRaction);
						call(ForceGlobalRealloc);
						call(ForceLoadSet,"club01v");
						call(ForceLoadSet,"club01w");
						call(ForceLoadSet,"club01x");
						call(ForceLoadSet,"club01y");
						call(ForceLoadSet,"club01z");
					}
				}
				else
				{
					if(VTrigger!=_DIRHaveGun && VarKey51>=9)
					{
						if(ControlTimer==0)
						{
							float(_set,ControlTimer,1);
							call(RunScriptCode,_or,9);
							call(KeyObjTrigger,255,1);
							direction(_clr,_DIRaction);
							float(_set,DisablePickup,0);
							call(ForceGlobalRealloc);
							call(ForceLoadSet,"club01v");
							call(ForceLoadSet,"club01w");
							call(ForceLoadSet,"club01x");
							call(ForceLoadSet,"club01y");
							call(ForceLoadSet,"club01z");
						}
					}
					else
					{
						message("Weapon Scanning Incomplete.",200,10);
						direction(_clr,_DIRaction);
					}
				}
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("enter")
				if(VSetActive=="club_ent")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("clubsas","enter",1);
					call(KeyObjTrigger,255,1);
				}
			}

			CurEnvTrigger("clubenter");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Door Locked",200,10);
				direction(_clr,_DIRaction);
			}

			CurEnvTrigger("trap");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VAIClass!=_AIClassAngel)
				{
					if(VarKey51==0 && VarBit&=Help21)
					{
						ActorFlag(_or,_AFLAGNoDepossession);
						call(KeyObjTrigger,9,1);
						vector(_set,Gactorpos,-8915,21411,13067);
						sample(SFXPneumatik,Gactorpos);
						message("Weapon Detector Activated - Put your Hand on the Console",200,10);
						float(_set,VarKey51,1);
						float(_clr,VarBit,Help23);
						float(_set,BarmanTimer,0);
					}
				}
			}
			else
			{
				if(VarBit&!=Help21)
				{
					float(_or,VarBit,Help21);
				}
			}

			if(VKeyObjTriggered==0 && VarKey51==1)
			{
				CurEnvTrigger("Console");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					if(VTrigger==_DIRHaveGun || VactorFlag==_AFLAGweaponinvisible)
					{
						float(_clr,VarBit,Help14);
					}
					call(ActivateButton,"Scanning for Identification",-1,FALSE);
					call(ActivateButtonSample,SFXActivate1);
					CurEnvTrigger("console");
					call(KeyObjTrigger,255,1);
					sample(SFXClawSpin,Gactorpos);
					sample(SFXOpenPipe,Gactorpos);
					sample(SFXScanning,Gactorpos);
					vector(_set,Gactorpos,-8915,21411,13067);
					vector(_set,tmpvector,50,50,200);
					spawnlight(LightPulseOmni3,-1,Gactorpos,tmpvector,EmptyVector,600);
					sample(SFXScanningAmbient,Gactorpos);
					CurEnvTrigger("check");
					call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);
					direction(_clr,_DIRaction);
					float(_set,timer,0);
					float(_set,VarKey51,2);
				}
			}
			if(VarKey51==2)
			{
				float(_add,timer,1);
				if(timer>=100)
				{
					vector(_set,Gactorpos,-8915,21411,13067);
					KillLight(LightPulseOmni3,Gactorpos,16);
					float(_set,timer,0);
					float(_set,VarKey51,3);	
				}
			}
			elseif(VarKey51==3)
			{
				if(VarBit&=Help14)
				{
					if(Varbit&=Help20)
					{
						message("No Weapon Detected - You May Proceed",200,10);
						CurEnvTrigger("trap");
						call(KeyObjTrigger,255,1);
						float(_or,VarBit,Help23);
						vector(_set,Gactorpos,-8915,21411,13067);
						sample(SFXPneumatik,Gactorpos)
						CurEnvTrigger("console");
						call(KeyObjTrigger,0,-1);
						float(_set,DisablePickUp,0);
						sample(SFXClawSpin,Gactorpos);
						sample(SFXOpenPipe,Gactorpos);
						ActorFlag(_clr,_AFLAGNoDepossession);
						float(_set,timer,0);
						float(_set,VarKey51,9);					
					}
					else
					{
						message("Weapon Detected in this room. Pick it up",200,10);
						float(_set,DisablePickup,0);
						CurEnvTrigger("trap");
						call(KeyObjTrigger,0,-1);
						float(_or,VarBit,Help23);
						sample(SFXPneumatik,Gactorpos);
						float(_clr,VarBit,Help21);
						float(_set,VarKey51,0);
					}
				}
				else
				{
					message("Weapon Detected - Drop it on the plate",200,10);
					CurEnvTrigger("detector");
					call(KeyObjTrigger,1,1);
					sample(SFXWepPlate,Gactorpos);
					float(_or,VarBit,Help20);
					float(_clr,VarBit,Help22);
					float(_set,timer,0);
					float(_set,VarKey51,5);
				}
			}
			elseif(VarKey51==5)
			{
				CurEnvTrigger("drop");
				if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
				{
					if(VTrigger==_DIRHaveGun || VactorFlag==_AFLAGweaponinvisible)
					{
						float(_set,VarKey51,6);
						direction(_clr,_DIRaction);
					}
					else
					{
						float(_set,DisablePickUp,0);
						message("Please Pick Up Your Weapon Before Using The Container",200,10);
					}
				}
			}
			elseif(VarKey51==6)
			{
				direction(_clr,_DIRaction|_DIRleft|_DIRright);
				if(Vaction!=GENPickupChest)
				{
					spawnaction(GENPickupChest);
				}
				if(VFrame==36)
				{
					message("Please Step Back",120,10);
					//if(AIAbility&=_AIAPickUpWeapon)
					//{
						call(CheckAttached,_CADropWeapon);
					//}
					if(VactorFlag==_AFLAGweaponinvisible)
					{
						ActorFlag(_clr,_AFLAGweaponinvisible);
					}
					float(_set,VarKey51,7);
				}
			}
			elseif(VarKey51==7)
			{
				CurEnvTrigger("drop");
				if(Vtrigger!=_DIREnvTrigger)
				{
					CurEnvTrigger("trap2");
					if(VTrigger!=_DIREnvTrigger)
					{
						if(VTrigger==_DIRHaveGun)
						{
							message("Place your Weapon on the plate.",200,10);
							float(_set,VarKey51,5);
						}
						else
						{
							CurEnvTrigger("drop");
							call(KeyObjTrigger,255,1);
							kfsample(SFXWeaponScan,-1,-1,-1);
							CurEnvTrigger("check");
							call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
							float(_set,VarKey51,8);
						}
					}
				}
			}
			elseif(VarKey51==8)
			{
				float(_add,timer,1);
				if(timer>=100)
				{
					CurEnvTrigger("detector");
					call(KeyObjTrigger,0,-1);
					message("Please Use the console for a safety scan.",200,10);
					direction(_clr,_DIRHaveGun);
					float(_set,timer,0);
					float(_or,VarBit,Help14);
					float(_set,VarKey51,1);
				}
			}
		}
	}
	elseif(VCurSet=="CLUB_ENT")
	{
		if(VRunScriptCode!=9 && VAICon==0)
		{
			callsub(DeInitSceneSound16);
			call(RunScriptCode,_clr,16);
			call(RunScriptCode,_or,9);
		}
	}

	elseif(VCurSet=="DNC_ENT1" || VCurSet=="vip02d")
	{
		if(VRunScriptCode!=9 && VAICon==0)
		{
			callsub(DeInitSceneSound16);
			call(RunScriptCode,_clr,16);
			call(RunScriptCode,_or,9);
		}
	}
}
