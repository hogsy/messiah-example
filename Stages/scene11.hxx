
SubRoutine(InitSceneSound11)
{
		vector(_set,gactorpos,-2144,2832,2170);
		sample(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,2198,2832,2170);
		sample(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,-2144,2832,-1888);
		sample(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,2198,2832,-1888);
		sample(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,-3,2434,-5811);
		sample(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,-3,4489,-9611);
		sample(SFXMoonAmb,Gactorpos);

		vector(_set,gactorpos,-3,23,-9611);
		sample(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,-3,39,-5811);
		sample(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,51,34,-2756);
		sample(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,3026,34,-54);
		sample(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,-60,34,3014);
		sample(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,-3018,34,51);
		sample(SFXLavaAmb,Gactorpos);


		call(fadetoblack,2);
}

SubRoutine(DeInitSceneSound11)
{
		vector(_set,gactorpos,-2144,2832,2170);
		samplestop(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,2198,2832,2170);
		samplestop(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,-2144,2832,-1888);
		samplestop(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,2198,2832,-1888);
		samplestop(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,-3,2434,-5811);
		samplestop(SFXMoonAmb,Gactorpos);
		vector(_set,gactorpos,-3,4489,-9611);
		samplestop(SFXMoonAmb,Gactorpos);

		vector(_set,gactorpos,-3,23,-9611);
		samplestop(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,-3,39,-5811);
		samplestop(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,51,34,-2756);
		samplestop(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,3026,34,-54);
		samplestop(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,-60,34,3014);
		samplestop(SFXLavaAmb,Gactorpos);
		vector(_set,gactorpos,-3018,34,51);
		samplestop(SFXLavaAmb,Gactorpos);
}


SubRoutine(InitScene11)
{
		vector(_set,Gactorangle,0,2048,0);
		InitActor(Bob1,0,Gactorangle,"s1r1");
		#include "messiahscripts\enemies\c4_satan.spt"

		call(ScreenShake,0,1,0,0);
		sample(SFXWindSatan,emptyvector);
		
		call(loadpreloaddb,20);
		float(_set,VarKey1,0);			//sequence counter
		float(_set,VarKey2,0);			//NrValves turned
		float(_set,VarKey3,0);			//Valve bits for activated
		float(_set,VarKey4,600);		//init value for ring of fire
		float(_set,VarKey5,0);
		float(_set,VarKey7,0);
		float(_set,VarKey9,240);
		float(_set,VarKey10,1000);
		float(_set,VarKey11,0);
		float(_set,VarKey13,0);
		float(_set,VarKey14,0);
		float(_set,VarKey15,0);			//spawn delay
		float(_set,VarKey16,0);			//what to spawn
		float(_set,VarKey17,0);
		float(_set,VarKey18,0);			//get rid of mizkutz gravity floater
		float(_set,VarKey19,0);
		float(_set,VarKey20,0);
		float(_set,VarKey21,150);

		float(_set,DepossesionAbilityActive,1);

		callsub(InitSceneSound11);
}

//varkey1:	Sequence counter
//varkey2:	nrvalves shut off
//varkey3:	bits for individual valve's state
//varkey4:	counter for firewall
//varkey5:	firsttime valvecam
//varkey7:	what valves are being turned back on
//varkey8:	number of evil cherups in scene
//varkey9:	delay counter for spawning evil bobs
//varkey10:	delay counter for respawning cops and workers
//varkey11:	Satan run counter before he has to rest
//varkey12:	reserved
//varkey13:	teleport delay
//varkey14:	ring of fire
//varkey15:	delay from spawning cops and workers
//varkey16:	what to spawn
//varkey17:	drop the cylinder?
//VarKey18:	get rid of mizkutz gravity floater
//VarKey19:	ok to start the ultra super duper evil ring of fire
//VarKey20:	bob should be followed by satan
//VarKey21: die removal counter


SubRoutine(Sub_SpawnMissingActorsInSatanLevel,const(actor),const(weapon))
{
		if(VRnd<33)
		{
			vector(_set,TmpVector1,2485,779,0);
			vector(_set,TmpVector2,0,3001,0);

			CurEnvTrigger("sphincty1");
			if(VKeyObjTriggered==0)
			{
				call(SetKeyObjFrame,0);
				call(KeyObjTrigger,100,1);
			}
		}
		elseif(VRnd<33)
		{
			vector(_set,TmpVector1,-4,779,2481);
			vector(_set,TmpVector2,0,2048,0);

			CurEnvTrigger("sphincty2");
			if(VKeyObjTriggered==0)
			{
				call(SetKeyObjFrame,0);
				call(KeyObjTrigger,100,1);
			}
		}
		else
		{
			vector(_set,TmpVector1,-2476,779,0);
			vector(_set,TmpVector2,0,1058,0);

			CurEnvTrigger("sphincty3");
			if(VKeyObjTriggered==0)
			{
				call(SetKeyObjFrame,0);
				call(KeyObjTrigger,100,1);
			}
		}

		InitActor(actor,TmpVector1,TmpVector2,"Satan",FALSE,0);
		if(weapon!=0)
		{
			InitActor(weapon,TmpVector1,TmpVector2,"Satan");
		}
}

SubRoutine(MainScene11)
{
/*		if(VKey==KEY_A)
		{
			CurEnvTrigger("sphincty1");
			if(VKeyObjTriggered==0)
			{
				call(SetKeyObjFrame,0);
				call(KeyObjTrigger,100,1);
			}

			CurEnvTrigger("sphincty2");
			if(VKeyObjTriggered==0)
			{
				call(SetKeyObjFrame,0);
				call(KeyObjTrigger,100,1);
			}

			CurEnvTrigger("sphincty3");
			if(VKeyObjTriggered==0)
			{
				call(SetKeyObjFrame,0);
				call(KeyObjTrigger,100,1);
			}
		}
*/
		if(VCutScene!=0)
		{
			call(AutoTesselation,false);
			CurEnvTrigger("FireRing");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
		}
		else
		{
			call(AutoTesselation,true);
		}


		if(VarKey17!=0)
		{
			CurEnvTrigger("CYLNDRFAL");
			if(VKeyObjTriggered==0)
			{
				if(VKeyObjFrame==0)
				{
					call(KeyObjTrigger,255,1);
					vector(_settotriggerpos,Gactorpos);
					Sample(SFXShaftRotate,Gactorpos);
				}
			}
			else
			{
				vector(_settotriggerpos,Gactorpos);
				SamplePlaying(SFXSatanRock,Gactorpos);
				if(VKeyObjFrame==4 && VTrigger!=_DIRTempFlag)
				{
					SampleStop(SFXShaftRotate,Gactorpos);
					Sample(SFXSatanRock,Gactorpos);
				}
			}
		}


		float(_add,VarKey10,1);
		if(VarKey1!=0 && VarKey10>300)
		{
			call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassCop,0,0);
			if(TmpFloat<2)		//threshold for spawning characters
			{
				float(_or,varkey16,1);
			}
			call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassWorker,0,0);
			if(TmpFloat<2)		//threshold for spawning characters
			{
				float(_or,varkey16,2);
			}
			float(_set,VarKey10,0);
		}

		if(VarKey16!=0)
		{
			if(varkey15<=0)
			{
				if(VarKey16&=1)
				{
					CallSub(Sub_SpawnMissingActorsInSatanLevel,CopL,WeaponPumpgun);
					float(_clr,varkey16,1);
					if(VarKey16!=0)
					{
						float(_set,varkey15,30);
					}
				}
				elseif(VarKey16&=2)
				{
					CallSub(Sub_SpawnMissingActorsInSatanLevel,Worker2,0);
					float(_clr,varkey16,2);
					if(VarKey16!=0)
					{
						float(_set,varkey15,30);
					}
				}
			}
			else
			{
				float(_sub,varkey15,1);
			}
		}


		printi("ActiveTime:  ",VActiveTime);
		if(VGameCounter<=2)
		{
			float(_set,TmpFloat,0x00ff00);

			CurEnvTrigger("pump01");
   			call(expset1,1,TmpFloat);

			CurEnvTrigger("pump02");
   			call(expset1,1,TmpFloat);

			CurEnvTrigger("pump03");
   			call(expset1,1,TmpFloat);

			CurEnvTrigger("pump04");
   			call(expset1,1,TmpFloat);
		}

		if(VCutScene!=0)
		{
			if(Varkey1==1)
			{
				//explode pillars during camsequence
				if(VCutSceneFrame==640)
				{
					vector(_set,TmpVector1,0,1298,-4786);
					vector(_set,TmpVector2,0,1098,-4786);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
					float(_set,VarKey1,2);

					vector(_set,gactorpos,0,1229,-4833);
					sample(SFXBazookaExplode,gactorpos);
				}
				elseif(VCutSceneFrame==585)
				{
					vector(_set,TmpVector1,0,2114,-7218);
					vector(_set,TmpVector2,0,1914,-7218);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);

					vector(_set,gactorpos,0,2044,-7264);
					sample(SFXBazookaExplode,gactorpos);
				}
				elseif(VCutSceneFrame==510)
				{
					vector(_set,TmpVector1,0,3156,-9587);
					vector(_set,TmpVector2,0,2956,-9587);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);

					vector(_set,gactorpos,0,3087,-9618);
					sample(SFXBazookaExplode,gactorpos);
				}
			}
			elseif(VarKey1==3)
			{
				//explode force field around Satan
				if(VCutSceneFrame==250)
				{
					CurEnvTrigger("forcefld");
					call(SetTriggerObjFlag,1,_set,_SXObjGlass);
					vector(_set,TmpVector1,-246,900,-645);
					vector(_set,TmpVector2,-88,900,-306);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
					call(DisplaySatanHUDToggle,1);
					float(_set,VarKey1,4);

					vector(_set,gactorpos,-150,900,-450);
					sample(SFXGlass,gactorpos);
					sample(SFXGrenadeExplode,gactorpos);
				}
			}
			elseif(VarKey1==6)
			{
				if(VCutSceneFrame==550)
				{
					/*
					//tony debug for video capture only
					//tony debug for video capture only
					//tony debug for video capture only
					CutScene("scott");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);

					float(_set,varkey1,7);
					//tony debug for video capture only
					//tony debug for video capture only
					//tony debug for video capture only
					*/

					call(PlaySequence,0);
				}
			}
		}
/*
		print("VarKey1:   ",VarKey1);
		print("VarKey2:   ",VarKey2);
		print("VarKey3:   ",VarKey3);
		print("VarKey7:   ",VarKey7);
		print("VarKey9:   ",VarKey9);
*/
		//spawn lights at all active valves
		if(VarKey3&!=1)
		{
			vector(_set,tmpvector2,0,255,0);
		}
		else
		{
			vector(_set,tmpvector2,255,0,0);
		}
		vector(_set,tmpvector1,-1614,850,-1325);
		spawnlight(Lomnilight2,-1,tmpvector1,tmpvector2,EmptyVector,800);

		if(VarKey3&!=2)
		{
			vector(_set,tmpvector2,0,255,0);
		}
		else
		{
			vector(_set,tmpvector2,255,0,0);
		}
		vector(_set,tmpvector1,-1614,850,1325);
		spawnlight(Lomnilight2,-1,tmpvector1,tmpvector2,EmptyVector,800);

		if(VarKey3&!=4)
		{
			vector(_set,tmpvector2,0,255,0);
		}
		else
		{
			vector(_set,tmpvector2,255,0,0);
		}
		vector(_set,tmpvector1,1614,850,1325);
		spawnlight(Lomnilight2,-1,tmpvector1,tmpvector2,EmptyVector,800);
		if(VarKey3&!=8)
		{
			vector(_set,tmpvector2,0,255,0);
		}
		else
		{
			vector(_set,tmpvector2,255,0,0);
		}
		vector(_set,tmpvector1,1614,850,-1325);
		spawnlight(Lomnilight2,-1,tmpvector1,tmpvector2,EmptyVector,800);

/*
		//TONY video capture only!!!!!!!
		//TONY video capture only!!!!!!!
		//TONY video capture only!!!!!!!
		if(VarKey1==7)
		{
			if(VCutSceneFrame>=120)
			{
				float(_set,varkey1,8);
			}

			if(VCutSceneFrame>=25&&VCutSceneFrame<=40)
			{
				float(_rnd2,tmpfloat,2048);
				float(_sub,tmpfloat,1024);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,2048);
				float(_sub,tmpfloat,1024);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,2048);
				float(_sub,tmpfloat,1024);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,-4,1600,60);			//middle
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale200);
			}

			if(VCutSceneFrame>=65&&VCutSceneFrame<=90)
			{
				float(_rnd2,tmpfloat,2048);
				float(_sub,tmpfloat,1024);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,2048);
				float(_sub,tmpfloat,1024);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,2048);
				float(_sub,tmpfloat,1024);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,-4,1600,60);			//middle
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale100);
			}


			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,-450,1500,-800);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,450,1500,-800);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,230,1100,-490);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,-230,1100,-490);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,256);
				float(_sub,tmpfloat,128);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,-4,1600,60);			//middle
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,1280,1100,-1190);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,1440,1100,1035);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,-1280,1100,1190);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}

			if(vrnd<15)
			{
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setx,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_sety,gactorpos,tmpfloat);
				float(_rnd2,tmpfloat,512);
				float(_sub,tmpfloat,256);
				vector(_setz,gactorpos,tmpfloat);

				vector(_set,tmpvector,-1440,1100,-1035);
				vector(_add,gactorpos,tmpvector);

				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
				spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

				if(vrnd<10)
				{
					sample(SFXBazookaExplode,gactorpos);
				}
			}
		}
		//TONY video capture only!!!!!!!
		//TONY video capture only!!!!!!!
		//TONY video capture only!!!!!!!
*/


		if(VarKey1==6)
		{
			if(VCutScene==0)
			{
				//break();
			}
			else
			{
				call(SetParticleSetID);

				vector(_set,gactorine,0,0,0);

				if(VCutSceneFrame>=210&&VCutSceneFrame<350)
				{
					if(vrnd<25)
					{
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setz,gactorpos,tmpfloat);
						vector(_add,gactorpos,BloodPos);
						spawnparticle(fx_bloodlesser,-1,BloodPos,emptyvector,fx_scalesatanblood);
					}
				}

				if(VCutSceneFrame>=290&&VCutSceneFrame<=350)
				{
					if(VCutSceneFrame<=320)
					{
						if(VCutSceneFrame==290)
						{
							vector(_set,gactorpos,0,1000,-800);
							sample(SFXBazookaExplode,gactorpos);
						}

						if(vrnd<15)
						{
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_setx,gactorpos,tmpfloat);
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_sety,gactorpos,tmpfloat);
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_setz,gactorpos,tmpfloat);

							vector(_set,tmpvector,-450,2000,-800);
							vector(_add,gactorpos,tmpvector);

							spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
							spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

							if(vrnd<10)
							{
								sample(SFXBazookaExplode,gactorpos);
							}
						}
					}
					elseif(VCutSceneFrame<=335)
					{
						if(VCutSceneFrame==320)
						{
							vector(_set,gactorpos,0,1000,-800);
							sample(SFXBazookaExplode,gactorpos);
						}

						if(vrnd<15)
						{
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_setx,gactorpos,tmpfloat);
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_sety,gactorpos,tmpfloat);
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_setz,gactorpos,tmpfloat);

							vector(_set,tmpvector,450,2000,-800);
							vector(_add,gactorpos,tmpvector);

							spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
							spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

							if(vrnd<10)
							{
								sample(SFXBazookaExplode,gactorpos);
							}
						}
					}
					elseif(VCutSceneFrame<=350)
					{
						if(VCutSceneFrame==335)
						{
							vector(_set,gactorpos,0,1000,-800);
							sample(SFXBazookaExplode,gactorpos);
						}

						if(vrnd<15)
						{
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_setx,gactorpos,tmpfloat);
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_sety,gactorpos,tmpfloat);
							float(_rnd2,tmpfloat,256);
							float(_sub,tmpfloat,128);
							vector(_setz,gactorpos,tmpfloat);

							vector(_set,tmpvector,0,3000,-1000);
							vector(_add,gactorpos,tmpvector);

							spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
							spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

							if(vrnd<10)
							{
								sample(SFXBazookaExplode,gactorpos);
							}
						}
					}
				}
				if(VCutSceneFrame>=350)
				{
					if(VCutSceneFrame==350)
					{
						vector(_set,tmpvector,-4,2000,60);			//middle
						sample(SFXBazookaExplode,gactorpos);
					}

					if(vrnd<15)
					{
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setz,gactorpos,tmpfloat);

						vector(_set,tmpvector,230,1400,-490);
						vector(_add,gactorpos,tmpvector);

						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

						if(vrnd<10)
						{
							sample(SFXBazookaExplode,gactorpos);
						}
					}

					if(vrnd<15)
					{
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setz,gactorpos,tmpfloat);

						vector(_set,tmpvector,-230,1400,-490);
						vector(_add,gactorpos,tmpvector);

						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

						if(vrnd<10)
						{
							sample(SFXBazookaExplode,gactorpos);
						}
					}

					if(VCutSceneFrame<430)
					{
						vector(_set,gactorine,0,-10,0);
					}

					if(vrnd<15)
					{
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,256);
						float(_sub,tmpfloat,128);
						vector(_setz,gactorpos,tmpfloat);

						vector(_set,tmpvector,-4,2000,60);			//middle
						vector(_add,gactorpos,tmpvector);

						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

						if(vrnd<10)
						{
							sample(SFXBazookaExplode,gactorpos);
						}
					}
				}
				if(VCutSceneFrame>=380&&VCutSceneFrame<=550)
				{
					if(vrnd<15)
					{
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setz,gactorpos,tmpfloat);

						vector(_set,tmpvector,1280,2100,-1190);
						vector(_add,gactorpos,tmpvector);

						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

						if(vrnd<10)
						{
							sample(SFXBazookaExplode,gactorpos);
						}
					}

					if(vrnd<15)
					{
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setz,gactorpos,tmpfloat);

						vector(_set,tmpvector,1440,2100,1035);
						vector(_add,gactorpos,tmpvector);

						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

						if(vrnd<10)
						{
							sample(SFXBazookaExplode,gactorpos);
						}
					}

					if(vrnd<15)
					{
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setz,gactorpos,tmpfloat);

						vector(_set,tmpvector,-1280,2100,1190);
						vector(_add,gactorpos,tmpvector);

						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

						if(vrnd<10)
						{
							sample(SFXBazookaExplode,gactorpos);
						}
					}

					if(vrnd<15)
					{
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setx,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_sety,gactorpos,tmpfloat);
						float(_rnd2,tmpfloat,512);
						float(_sub,tmpfloat,256);
						vector(_setz,gactorpos,tmpfloat);

						vector(_set,tmpvector,-1440,2100,-1035);
						vector(_add,gactorpos,tmpvector);

						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);
						spawnparticle(fx_mainexplosion,-1,gactorpos,gactorine,fx_scale50);

						if(vrnd<10)
						{
							sample(SFXBazookaExplode,gactorpos);
						}
					}
				}



				if(VCutSceneFrame==350)
				{
					CurEnvTrigger("outtrig01");
					call(SetTriggerObjFlag,1,_set,_SXObjGlass);
					call(SetTriggerObjFlag,2,_set,_SXObjGlass);
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);

					CurEnvTrigger("outtrig02");
					call(SetTriggerObjFlag,1,_set,_SXObjGlass);
					call(SetTriggerObjFlag,2,_set,_SXObjGlass);
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);

					CurEnvTrigger("outtrig03");
					call(SetTriggerObjFlag,1,_set,_SXObjGlass);
					call(SetTriggerObjFlag,2,_set,_SXObjGlass);
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);
					call(SetTriggerObjFlag,2,_clr,_SXObjCollisionOff);

					CurEnvTrigger("outtrig04");
					call(SetTriggerObjFlag,1,_set,_SXObjGlass);
					call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);

					vector(_set,TmpVector1,285,5660,0);
					vector(_set,TmpVector2,0,5660,0);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
				}
				elseif(VCutSceneFrame==380)
				{
					vector(_set,TmpVector1,1015,3573,0);
					vector(_set,TmpVector2,0,3573,0);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
				}
				elseif(VCutSceneFrame==430)
				{
					vector(_set,TmpVector1,-868.79, 2273.26, -708.08);
					vector(_set,TmpVector2,-864.43, 2000.36, -713.93);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
				}
				elseif(VCutSceneFrame==410)
				{
					vector(_set,TmpVector1,-1778,2701,1129);
					vector(_set,TmpVector2,-1419,2701,1129);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
				}
				elseif(VCutSceneFrame==440)
				{
					vector(_set,TmpVector1,1778,2701,1129);
					vector(_set,TmpVector2,1419,2701,1129);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
				}
				elseif(VCutSceneFrame==470)
				{
					vector(_set,TmpVector1,1778,2701,-1129);
					vector(_set,TmpVector2,1419,2701,-1129);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
				}
				elseif(VCutSceneFrame==500)
				{
					vector(_set,TmpVector1,-1778,2701,-1129);
					vector(_set,TmpVector2,-1419,2701,-1129);
					collision(TmpVector1,TmpVector2);
					call(CheckForDynamicCollision,4);
				}
			}
		}

		CurEnvTriggerSet("satan","telport01");
		call(expset1,0,-3000,0);
		CurEnvTriggerSet("satan","telport02");
		call(expset1,0,-3000,0);
		CurEnvTriggerSet("satan","telport03");
		call(expset1,0,-3000,0);


}

SubRoutine(BackgroundTriggerChecksScene11)
{
		state(_or,StateForceBkTrig);

		if(Vaction==GENDrown||Vaction==GENDrownLoop)
		{
			state(_or,StateOnFire);
		}

		if(VAIcon==0)
		{
			if(VarKey18==0 && VAction!=GENIdle)
			{
				float(_set,VarKey18,1);
				SpawnAction(GENIdle);
				float(_set,AIVisionToggle,0);				//force vision to be on! (counter msikabugs)
			}

			if(VAIclass!=_AIclassAngel)
			{
				call(AIchangemetoenemy);
			}
			else
			{
				if(VActorFlag==_AFLAGattached)
				{
					if(VSniperMode!=0)
					{
						call(ChangeSniperMode,-2,0);
					}
					if(VParenAttachActor==Satan)
					{
						ActorFlag(_or,_AFLAGnotarget);
						ActorFlag(_or,_AFLAGnolinkup);
						call(PlayerInput,0);
					}
				}
				else
				{
					ActorFlag(_clr,_AFLAGnotarget);
					ActorFlag(_clr,_AFLAGnolinkup);
					call(PlayerInput,1);
				}
			}


			CurEnvTrigger("OnIsland1");
			if(VTrigger==_DIREnvTrigger)
			{
				float(_set,VarKey20,1);
			}
			else
			{
				float(_set,VarKey20,0);
			}
		}
		else
		{
			if(VarKey19==0 && VActorFlag==_AFLAGpossesed)
			{
				float(_set,VarKey19,1);
			}
			if(VState==StateDead)
			{
				float(_sub,VarKey21,1);
				if(VarKey21<0)
				{
					float(_set,VarKey21,150);
					vector(_settoactorpos,tmpvector);
					callsub(sub_fxsmallexplosion);
					killactor();
				}
			}
		}

		if(VCutScene!=0)	
		{
			print("In middle of cutscene");
			Direction(_clr,_DIRMoveBits|_DIRshoot|_DIRleft|_DIRright|_DIRjump);

			float(_set,VarKey9,270);

			if(VAICon!=0)
			{
				if(VActor==EvilBob)
				{
					spawnaction(dwarfworship);
				}
				elseif(VActor!=Satan)
				{
					spawnaction(GENCoweringLoop);
				}
			}
		}
		else
		{
			if(VAICon!=0 && VActor!=Satan && VActor!=EvilBob && VAction==GENCoweringLoop)
			{
				spawnaction(GENIdle);
			}
		}

		if(VAIClass!=_AIclassSatan && VAIClass!=_AIclassAngel)
		{
			call(AIchangerank,_RankSergeantL);		//to keep worker from going into cowering animations

			if(VActorFlag!=_AFLAGpossesed)
			{
				call(AIorder,_set,_AIstateConfused);
				call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn);
				if(VActiveTime<30)
				{
					move(0,0,40);
				}
			}
			else
			{
				if(VAICon!=0)		//controlled by evil bob
				{
					printi("controlled by evil bob:  ",VAIhaspath);
					if(VAIClass==_AIclassWorker)
					{
						if(VarKey1<5 && VarKey2>0 && VarKey2<4 && VAIState!=_AIstateConfused)
						{
							//find valve to shut off
							if(VAIState==_AIstateRun || VAIState==_AIstatePressAlarmButton)
							{
							}
							elseif(VarKey3&=1 && VarKey7&!=1)
							{
								CallSub(Sub_AIGetBackToIdle);
								call(AIfindpathwithspecificid,1);
								float(_or,VarKey7,1);
							}
							elseif(VarKey3&=2 && VarKey7&!=2)
							{
								CallSub(Sub_AIGetBackToIdle);
								call(AIfindpathwithspecificid,2);
								float(_or,VarKey7,2);
							}
							elseif(VarKey3&=4 && VarKey7&!=4)
							{
								CallSub(Sub_AIGetBackToIdle);
								call(AIfindpathwithspecificid,3);
								float(_or,VarKey7,4);
							}
							elseif(VarKey3&=8 && VarKey7&!=8)
							{
								CallSub(Sub_AIGetBackToIdle);
								call(AIfindpathwithspecificid,4);
								float(_or,VarKey7,8);
							}

/*							if(VAIstate==_AIstatePressAlarmButton)
							{
								if(VPathID==1)
								{
									float(_and,VarKey7,14);
								}
								elseif(VPathID==2)
								{
									float(_and,VarKey7,13);
								}
								elseif(VPathID==3)
								{
									float(_and,VarKey7,11);
								}
								elseif(VPathID==4)
								{
									float(_and,VarKey7,7);
								}
							}
*/
							call(AIorder,_set,_AIstateRun);
							call(AIorder,_clr,_AInomove|_AInoturn);
							State(_clr,StateFollowPath);
							State(_or,StateExecutePathSequence);
						}
						elseif(VarKey3==0 || VarKey3==15)
						{
							if(VActorFlag==_AFLAGpossesed)
							{
								//no valves turned and worker is possesed so go after bob
								call(AIcheckforplayerone,10000);
								call(AIsetlockedonactortotarget);
								if(VAIState!=_AIstateAttack)
								{
									CallSub(Sub_AISetAttack);
								}
								//if(VAIState!=_AIstateRun && VAIState!=_AIstatePressAlarmButton)
								//{
								//	call(AIOrder,_set,_AIstateIdle);
								//}
							}
						}
					}
					elseif(VAIClass==_AIclassCop && VActorFlag==_AFLAGpossesed)
					{
						//no valves turned and worker is possesed so go after bob
						call(AIcheckforplayerone,10000);
						call(AIsetlockedonactortotarget);
						if(VAIState!=_AIstateAttack)
						{
							CallSub(Sub_AISetAttack);
						}
					}
/*
					if(VarKey1==5 && VAICon!=0)		//get rid of evil bobs after first sequence
					{
						vector(_settoactorpos,tmpvector);
						callsub(sub_fxsmallexplosion);
						killactor();
					}
*/
				}
			}
		}
		elseif(VAIclass==_AIclassAngel)
		{
			if(VAIcon!=0)
			{
				call(AIcheckactorstates,10,_AIclassworker|_AIclassCop,_AIstateConfused,0);
				if(vtrigger==_DIRTempFlag)
				{
					call(AIsetlockedonactortotarget);
					if(VAIState!=_AIstateAttack)
					{
						CallSub(Sub_AISetAttack);
					}
				}

				if(VarKey1==5)		//get rid of evil bobs after first sequence
				{
					vector(_settoactorpos,tmpvector);
					callsub(sub_fxsmallexplosion);
					killactor();
				}
			}
			elseif(VActorFlag!=_AFLAGattached)
			{
				/*
				//bob watches the satan level blow up :)
				if(varkey1==6&&VCutSceneFrame==300)
				{
					vector(_set,gactorpos,0,800,-2000);
					vector(_set,Gactorangle,0,2048,0);
					vector(_setactorangle,Gactorangle);
					vector(_setactorpos,gactorpos);
				}
				*/

				float(_sub,VarKey13,1);
				if(VarKey13<0)
				{
					CurEnvTrigger("telport01");
					if(VTrigger==_DIREnvTrigger)
					{
						float(_set,VarKey13,90);
						sample(SFXRipple,-1);
						if(VRnd<50)
						{
							SetActorToTrigger("satan",telport02");
						}
						else
						{
							SetActorToTrigger("satan",telport03");
						}
					}

					CurEnvTrigger("telport02");
					if(VTrigger==_DIREnvTrigger)
					{
						float(_set,VarKey13,90);
						sample(SFXRipple,-1);
						if(VRnd<50)
						{
							SetActorToTrigger("satan",telport01");
						}
						else
						{
							SetActorToTrigger("satan",telport03");
						}
					}

					CurEnvTrigger("telport03");
					if(VTrigger==_DIREnvTrigger)
					{
						float(_set,VarKey13,90);
						sample(SFXRipple,-1);
						if(VRnd<50)
						{
							SetActorToTrigger("satan",telport01");
						}
						else
						{
							SetActorToTrigger("satan",telport02");
						}
					}
				}

			}
		}
		elseif(VAIclass==_AIclassSatan)
		{
			if(VCutScene!=0)
			{
				ActorFlag(_or,_AFLAGnoai);
				if(Varkey1==1)
				{
					if(VCutSceneFrame==5)
					{
						SpawnAction(Satanintro0);
					}
				}
			}
			else
			{
				if(VarKey2<4)
				{
					ActorFlag(_or,_AFLAGnoai);
				}
				else
				{
					ActorFlag(_clr,_AFLAGnoai);
				}
			}

			if(VarKey1>=1 && VarKey1<5 && VarKey8<2)
			{
				float(_add,VarKey9,1);

				call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassAngel,_Equal,_WeakLittleEvilBaby);
				//threshold for spawning characters
				if(TmpFloat<2 && VarKey9>300 && VAction!=SatanSpawningEvilBob0 && VAction!=SatanSpawningEvilBob)
				{
					SpawnAction(SatanSpawningEvilBob0);
					float(_set,VarKey9,0);
					float(_add,VarKey8,1);
				}
			}

			if(varkey1>=5 && VActorFlag!=_AFLAGattached)
			{
				if(VColMaterialProperties==_MATDrown)
				{
					vector(_settoactorpos,TmpVector);
					vector(_copyz,TmpVector,TmpFloat);
					callsub(sub_fxexplosion);

					if(TmpFloat<=0)
					{
						setactortotrigger("satan","SatPop01");
					}
					else
					{
						setactortotrigger("satan","SatPop02");
					}

					vector(_settoactorpos,TmpVector);
					callsub(sub_fxexplosion);
				}
				elseif(VarKey20==0)
				{
					//	bob is not inside the big trigger covering most of the island
					//
					vector(_set,TmpVector,0,0,0);
					vector(_set,TmpVector2,0,0,-125);
					Collision(TmpVector,TmpVector2);
					if(vcolflag!=_DIRhorcol && vcolflag!=_DIRvercol)
					{
						vector(_copy,TmpVector,TmpVector2);
						vector(_sety,TmpVector2,-150);
						Collision(TmpVector,TmpVector2);
						if(vcolflag!=_DIRhorcol)
						{
							Direction(_clr,_DIRforward);
						}
					}
				}
				else
				{
					float(_add,varkey11,1);
					if(varkey11>400)
					{
						if(vaction!=SatanPanting && vaction!=SatanWound && vaction!=SatanDeath)
						{
							spawnaction(SatanPanting);
						}
						if(varkey11==490)
						{
							float(_set,varkey11,0);	
							if(VAction==SatanPanting)
							{
								spawnaction(SatanIdle4);
							}
						}
					}
				}
			}


			if(VarKey17==0)
			{
				CurEnvTrigger("CYLNDRFAL");
				if(VTrigger!=_DIREnvTrigger)
				{
					float(_set,VarKey17,1);
				}
			}

			///TONY TEST CODE ONLY!!!
			///TONY TEST CODE ONLY!!!
			///TONY TEST CODE ONLY!!!
			/*
			if(vkey==key_b)
			{
				call(SubtractHealth,0,30000);

				CurEnvTrigger("VALVE04");
				call(SetTriggerObjFlag,1,_or,_SXObjInvisible);

				CutScene("OutroCam");
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
				call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);

				float(_set,VarKey1,6);

				vector(_settoactorpos,BloodPos);
			}
			*/
			///TONY TEST CODE ONLY!!!
			///TONY TEST CODE ONLY!!!
			///TONY TEST CODE ONLY!!!

			if(VState==StateDead)
			{
				if(VCutScene==0 && VarKey1==5)
				{
					CurEnvTrigger("VALVE04");
					call(SetTriggerObjFlag,1,_or,_SXObjInvisible);

					CutScene("OutroCam");
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
					call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);

					float(_set,VarKey1,6);

					vector(_settoactorpos,BloodPos);
					sample(SFXSatanDie1,BloodPos);
				}
			}
		}

		if(VAIClass==_AIclassSatan && VCutScene==0 && VarKey1<5 && VAction!=SatanWound && vaction!=SatanDeath)		//XXX Remove wound check later
		{
			if(VarKey2==0)
			{
				if(VAction==SatanIdle1 || VAction==SatanIdle2 || VAction==SatanIdle3 || VAction==SatanIdle4)
				{
					SpawnAction(SatanIdle);
				}
			}
			elseif(VarKey2==1)
			{
				if(VAction==SatanIdle || VAction==SatanIdle2 || VAction==SatanIdle3 || VAction==SatanIdle4)
				{
					SpawnAction(SatanIdle1);
				}
			}
			elseif(VarKey2==2)
			{
				if(VAction==SatanIdle || VAction==SatanIdle1 || VAction==SatanIdle3 || VAction==SatanIdle4)
				{
					SpawnAction(SatanIdle2);
				}
			}
			elseif(VarKey2==3)
			{
				if(VAction==SatanIdle || VAction==SatanIdle1 || VAction==SatanIdle2 || VAction==SatanIdle4)
				{
					SpawnAction(SatanIdle3);
				}
			}
			elseif(VarKey2==4)
			{
				if(VAction==SatanIdle || VAction==SatanIdle1 || VAction==SatanIdle2 || VAction==SatanIdle3)
				{
					SpawnAction(SatanIdle4);
					float(_set,VarKey1,5);
				}
			}

/////////////////////////////////////////
/*
			//tony test ONLY!
			//tony test ONLY!
			//tony test ONLY!
			if(vkey==KEY_J&&Vaction!=SatanRingOfFire)
			{
				sample(SFXCastFireRing,-1);
				SpawnAction(SatanRingOfFire);
			}

			if(VAction==SatanRingOfFire && VFrame==40)
			{
				vector(_set,TmpVector1,0,0,-80);		//down a bit
				SpawnActorBone(BulletRingOfFire,TmpVector1,Gactorpos,Gactorine,36);
				sample(SFXFireRing,-1);

				CurEnvTrigger("FireRing");
				call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);

				float(_set,VarKey14,_RingOfFireDuration);		//duration
			}
			//tony test ONLY!
			//tony test ONLY!
			//tony test ONLY!
*/
/////////////////////////////////////////

			//ring of fire code, don't spawn if no evil bob has possesed yet or if in a cutscene
			if(VCutScene==0 && VarKey19!=0)
			{
				float(_add,VarKey4,1);
				if(VarKey4>900 && VAction!=SatanSpawningEvilBob0 && VAction!=SatanSpawningEvilBob)
				{
					float(_set,VarKey4,0);
					SpawnAction(SatanRingOfFire);
				}
				if(VAction==SatanRingOfFire && VFrame==40)
				{
					vector(_set,TmpVector1,0,0,-80);		//down a bit
					SpawnActorBone(BulletRingOfFire,TmpVector1,Gactorpos,Gactorine,36);
					sample(SFXFireRing,-1);

					CurEnvTrigger("FireRing");
					call(SetTriggerObjFlag,1,_clr,_SXObjInvisible);

					float(_set,VarKey14,_RingOfFireDuration);		//duration
				}
			}

			if(VarKey14>0)
			{
				float(_sub,VarKey14,1);
			}
			elseif(VarKey14==0)
			{
				CurEnvTrigger("FireRing");
				call(SetTriggerObjFlag,1,_set,_SXObjInvisible);
				float(_sub,VarKey14,1);
			}
		}


		if(VarKey1==0)
		{
			//first cutscene after bob lands on island
			if(VAICon==0)
			{
				CurEnvTrigger("newintro");
				if(VTrigger==_DIREnvTrigger)
				{
					PrintI("VDistToGround: ",VDistToGround);

					vector(_set,TmpVector,0,0,0);
					vector(_set,TmpVector2,0,-100,0);
					Collision(TmpVector,TmpVector2);
					if(VColFlag==_DIRhorcol)
					{
						Direction(_clr,_DIRMoveBits|_DIRshoot|_DIRleft|_DIRright|_DIRjump);
						CutScene("IntroCam");
						float(_set,VarKey1,1);
					}
				}
			}

/*			CurEnvTrigger("introcam");
			if(VTrigger==_DIREnvTrigger)
			{
				CutScene("IntroCam");
				float(_set,VarKey1,1);
			}
*/
		}
		elseif(VarKey1<3)
		{
			if(VTrigger==_DIRaction)
			{
				float(_set,VarKey12,0);

				CurEnvTrigger("valve01");
				if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
				{
					if(VAIClass==_AIclassWorker)
					{
						if(VAICon==0)
						{
							call(ActivateButton,0,-1,0);
						}
						else
						{
							sample(SFXEvilBobLaughter,-1);
						}
						call(SetKeyObjFrame,0);
						call(KeyObjTrigger,100,1);

						CurEnvTrigger("pump01");
						if(VarKey3&=1)
						{
							if(VAICon!=0)
							{
								float(_sub,VarKey2,1);
								call(KeyObjActiveSegment,0,2);
								float(_set,TmpFloat,0x00ff00);
   								call(expset1,1,TmpFloat);
								float(_and,VarKey7,14);
								float(_clr,VarKey3,1);
							}
						}
						elseif(VAICon==0)
						{
							sample(SFXBloodDrain,-1);
							float(_add,VarKey2,1);
							call(KeyObjActiveSegment,4,5);
							float(_set,TmpFloat,0xff0000);
   							call(expset1,1,TmpFloat);
							float(_set,VarKey12,1);
							if(VarKey2==4)
							{
								CurEnvTrigger("forcefld");
								call(SetTriggerObjFlag,2,_set,_SXObjInvisible);
								CutScene("SatanCam01");
								float(_set,VarKey1,3);
							}
							elseif(VarKey5==0)
							{
								float(_set,VarKey5,1);
								CutScene("PumpRCam01");
							}
							float(_or,VarKey3,1);
						}
						//float(_xor,VarKey3,1);
					}
					elseif(VAICon==0)
					{
						message("Only worker can operate valves.",120,10);
					}
				}

				CurEnvTrigger("valve02");
				if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
				{
					if(VAIClass==_AIclassWorker)
					{
						if(VAICon==0)
						{
							call(ActivateButton,0,-1,0);
						}
						else
						{
							sample(SFXEvilBobLaughter,-1);
						}
						call(SetKeyObjFrame,0);
						call(KeyObjTrigger,100,1);

						CurEnvTrigger("pump02");
						if(VarKey3&=2)
						{
							if(VAICon!=0)
							{
								float(_sub,VarKey2,1);
								call(KeyObjActiveSegment,0,2);

								float(_set,TmpFloat,0x00ff00);
   								call(expset1,1,TmpFloat);
								float(_and,VarKey7,13);
								float(_clr,VarKey3,2);
							}
						}
						elseif(VAICon==0)
						{
							sample(SFXBloodDrain,-1);
							float(_add,VarKey2,1);
							call(KeyObjActiveSegment,4,5);
							float(_set,TmpFloat,0xff0000);
   							call(expset1,1,TmpFloat);
							float(_set,VarKey12,1);
							if(VarKey2==4)
							{
								CurEnvTrigger("forcefld");
								call(SetTriggerObjFlag,2,_set,_SXObjInvisible);
								CutScene("SatanCam02");
								float(_set,VarKey1,3);
							}
							elseif(VarKey5==0)
							{
								float(_set,VarKey5,1);
								CutScene("PumpRCam02");
							}
							float(_or,VarKey3,2);
						}
//						float(_xor,VarKey3,2);
					}
					elseif(VAICon==0)
					{
						message("Only worker can operate valves.",120,10);
					}
				}

				CurEnvTrigger("valve03");
				if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
				{
					if(VAIClass==_AIclassWorker)
					{
						if(VAICon==0)
						{
							call(ActivateButton,0,-1,0);
						}
						else
						{
							sample(SFXEvilBobLaughter,-1);
						}
						call(SetKeyObjFrame,0);
						call(KeyObjTrigger,100,1);

						CurEnvTrigger("pump03");
						if(VarKey3&=4)
						{
							if(VAICon!=0)
							{
								float(_sub,VarKey2,1);
								call(KeyObjActiveSegment,0,2);

								float(_set,TmpFloat,0x00ff00);
   								call(expset1,1,TmpFloat);
								float(_and,VarKey7,11);
								float(_clr,VarKey3,4);
							}
						}
						elseif(VAICon==0)
						{
							sample(SFXBloodDrain,-1);
							float(_add,VarKey2,1);
							call(KeyObjActiveSegment,4,5);
							float(_set,TmpFloat,0xff0000);
   							call(expset1,1,TmpFloat);
							float(_set,VarKey12,1);
							if(VarKey2==4)
							{
								CurEnvTrigger("forcefld");
								call(SetTriggerObjFlag,2,_set,_SXObjInvisible);
								CutScene("SatanCam03");
								float(_set,VarKey1,3);
							}
							elseif(VarKey5==0)
							{
								float(_set,VarKey5,1);
								CutScene("PumpRCam03");
							}
							float(_or,VarKey3,4);
						}
//						float(_xor,VarKey3,4);
					}
					elseif(VAICon==0)
					{
						message("Only worker can operate valves.",120,10);
					}
				}

				CurEnvTrigger("valve04");
				if(VTrigger==_DIREnvTrigger && VKeyObjTriggered==0)
				{
					if(VAIClass==_AIclassWorker)
					{
						if(VAICon==0)
						{
							call(ActivateButton,0,-1,0);
						}
						else
						{
							sample(SFXEvilBobLaughter,-1);
						}
						call(SetKeyObjFrame,0);
						call(KeyObjTrigger,100,1);

						CurEnvTrigger("pump04");
						if(VarKey3&=8)
						{
							if(VAICon!=0)
							{
								float(_sub,VarKey2,1);
								call(KeyObjActiveSegment,0,2);

								float(_set,TmpFloat,0x00ff00);
   								call(expset1,1,TmpFloat);
								float(_and,VarKey7,7);
								float(_clr,VarKey3,8);
							}
						}
						elseif(VAICon==0)
						{
							sample(SFXBloodDrain,-1);
							float(_add,VarKey2,1);
							call(KeyObjActiveSegment,4,5);
							float(_set,TmpFloat,0xff0000);
   							call(expset1,1,TmpFloat);
							float(_set,VarKey12,1);
							if(VarKey2==4)
							{
								CurEnvTrigger("forcefld");
								call(SetTriggerObjFlag,2,_set,_SXObjInvisible);
								CutScene("SatanCam04");
								float(_set,VarKey1,3);
							}
							elseif(VarKey5==0)
							{
								float(_set,VarKey5,1);
								CutScene("PumpRCam04");
							}
							float(_or,VarKey3,8);
						}
						//float(_xor,VarKey3,8);
					}
					elseif(VAICon==0)
					{
						message("Only worker can operate valves.",120,10);
					}
				}

				if(VarKey12!=0)
				{
					//pump activated this frame
					if(VarKey2==1)
					{
						sample(SFXsatanvalve1,-1);
					}
					elseif(VarKey2==2)
					{
						sample(SFXsatanvalve2,-1);
					}
					elseif(VarKey2==3)
					{
						sample(SFXsatanvalve3,-1);
					}
					elseif(VarKey2==4)
					{
						sample(SFXsatanvalve4,-1);
					}
				}

			}
		}
}

