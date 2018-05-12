//City Streets - walls.rdf

//VarBit
//-------
//Help01	>	Story Message #18
//Help02	>	Story Message #19
//Help03	>	Helicopter is destroyed
//Help04	>	Plasma wall
//Help05	>	Turn Possession off on the dweller inside the cab until door is opened.


SubRoutine(InitSceneSound18)
{
		if(incoming!=0)
		{
			if(ScriptMark==18)
			{
				callsub(Panel18);
			}
			elseif(ScriptMark==19)
			{
				callsub(Panel19);
			}
		}
		else
		{
			callsub(ScriptLevel18);
		}

		vector(_set,Gactorpos,-17461,25300,22030);
		sample(SFXHeli,Gactorpos);

		vector(_set,gactorpos,-12300,24660,21936);
		sample(SFXScanHumm,gactorpos);

		//pistons in walls8
		vector(_set,gactorpos,-19281,25127,13202);
		sample(SFXPiston,gactorpos);

		//pistons in walls7
		vector(_set,gactorpos,-19284,25130,14398);
		sample(SFXPiston,gactorpos);

		vector(_set,gactorpos,-19284,25122,15602);
		sample(SFXPiston,gactorpos);

		//ambient sound
		/*
		if(vcurset!="pilhall" && vcurset!="pillift")
		{
			vector(_set,gactorpos,-8483,25174,14315);
			sample(SFXCityAmbient02,gactorpos);	

			vector(_set,gactorpos,-20164,25174,16587);
			sample(SFXCityAmbient02,gactorpos);

			vector(_set,gactorpos,-12875,25174,25440);
			sample(SFXCityAmbient02,gactorpos);
		}
		*/
		call(CDPlay,1,1);
}

SubRoutine(DeInitSceneSound18)
{
		vector(_set,Gactorpos,-17461,25300,22030);
		samplestop(SFXHeli,Gactorpos);

		vector(_set,gactorpos,-12300,24660,21936);
		samplestop(SFXScanHumm,gactorpos);

		//ambient sound
		vector(_set,gactorpos,-8483,25174,14315);
		samplestop(SFXCityAmbient01,gactorpos);

		vector(_set,gactorpos,-20164,25174,16587);
		samplestop(SFXCityAmbient01,gactorpos);

		vector(_set,gactorpos,-12875,25174,25440);
		samplestop(SFXCityAmbient01,gactorpos);

} 


SubRoutine(InitScene18)
{
		call(loadpreloaddb,21);
		if(VScriptInitiated!=18)
		{
			if(VInitScriptCode==0) 
			{
				vector(_set,Gactorangle,0,1024,0);
				InitActor(Bob1,0,Gactorangle,"walls1");
			}

			float(_set,VarBit,AllHelp);
			float(_set,VarKey41,0);			//state of reactor blowout in convier
			float(_set,VarKey42,0);         //whether or not you can go into conv.
			float(_set,VarKey43,0);			//Controls flow of the level (accessable areas, etc).
											//	0	= Conveyer is the only sector open
											//	10	= 
			float(_set,VarKey44,0);			//elevator lights
			float(_set,VarKey45,0);			//elevator lights
			float(_set,VarKey46,0);         //kick me
			float(_set,VarKey47,0);
			float(_set,VarKey48,0);
			float(_set,VarKey49,0);
			float(_set,VarKey50,0);
			

			//debug only
			//float(_set,wstaccess,1);
			//----------

			#include    "messiahscripts\enemies\c2_streets.spt"
		}

		callsub(InitSceneSound18);
		call(ScriptCodeInitiated,18);
}

//fill in gactorpos before
SubRoutine(PlasmaWall,float(plasangle))
{
	
		//you must pass in the position of the plasma
		//and the SpecificSetId for the particle
		//before calling this routine.

		//angle > 1 if along the Z axis
		//		> 0 if along the X axis


		if(plasangle==1)
		{
			CurEnvTriggerSet("walls1","plasma");
			if(VTrigger==_DIREnvTrigger)
			{
				sample(SFXRipple,gactorpos);
				float(_set,PlasmaWallRipple,150);
			}

			CurEnvTriggerSet("walls1","plasma01");
			if(VTrigger==_DIREnvTrigger)
			{
				sample(SFXRipple,gactorpos);
				float(_set,PlasmaWallRipple,150);
			}
		}
		elseif(plasangle==0)
		{
			CurEnvTriggerSet("walls1","plasma");
			if(VTrigger==_DIREnvTrigger)
			{
				sample(SFXRipple,gactorpos);
				float(_set,PlasmaWallRipple,1);
			}

			CurEnvTriggerSet("walls1","plasma01");
			if(VTrigger==_DIREnvTrigger)
			{
				sample(SFXRipple,gactorpos);
				float(_set,PlasmaWallRipple,1);
			}
		}


		if(plasangle==1)
		{
			if(PlasmaWallRipple>0)
			{
				callSub(Sub_plasmawall,gactorpos,1,1,tmpfloat1,tmpfloat2);
			}
			else
			{
				callSub(Sub_plasmawall,gactorpos,1,0,tmpfloat1,tmpfloat2);
			}
		}
		elseif(plasangle==0)
		{
			if(PlasmaWallRipple>0)
			{
				callSub(Sub_plasmawall,gactorpos,0,1,tmpfloat1,tmpfloat2);
			}
			else
			{
				callSub(Sub_plasmawall,gactorpos,0,0,tmpfloat1,tmpfloat2);
			}
		}

		float(_sub,PlasmaWallRipple,1);
		if(PlasmaWallRipple<0)
		{
			float(_set,PlasmaWallRipple,0);
		}

}

//fill in gactorpos before
subroutine(Sub_PlasmaWallExplode)
{
		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,-1);

		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,fx_madrotatenegative64);

		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,-1);

		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,fx_madrotatenegative64);

		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,-1);

		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,fx_madrotatenegative64);

		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,-1);

		vector(_set,fxvector,0,0,0);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_sety,fxvector,tmpfloat);
		float(_rnd2,tmpfloat,512);
		float(_sub,tmpfloat,256);
		vector(_setz,fxvector,tmpfloat);
		vector(_add,fxvector,gactorpos);
		spawnparticle(fx_riotshieldshrapnel,-1,fxvector,emptyvector,fx_madrotatenegative64);
}




SubRoutine(MainScene18)
{
	
	//ambient sound
	if(VCurSet!="pilhall" && VCurSet!="pillift")
	{
		vector(_set,gactorpos,-8483,25174,14315);
		SamplePlaying(SFXCityAmbient01,Gactorpos);
		if(VTrigger!=_DIRTempFlag)
		{
			sample(SFXCityAmbient01,gactorpos);	
		}

		vector(_set,gactorpos,-20164,25174,16587);
		SamplePlaying(SFXCityAmbient01,Gactorpos);
		if(VTrigger!=_DIRTempFlag)
		{
			sample(SFXCityAmbient01,gactorpos);	
		}

		vector(_set,gactorpos,-12875,25174,25440);
		SamplePlaying(SFXCityAmbient01,Gactorpos);
		if(VTrigger!=_DIRTempFlag)
		{
			sample(SFXCityAmbient01,gactorpos);	
		}
	}
	
	if(VCurSet=="pilhall" || VCurSet=="pillift")
	{
		vector(_set,gactorpos,-8483,25174,14315);
		samplestop(SFXCityAmbient02,gactorpos);	

		vector(_set,gactorpos,-20164,25174,16587);
		samplestop(SFXCityAmbient02,gactorpos);

		vector(_set,gactorpos,-12875,25174,25440);
		samplestop(SFXCityAmbient02,gactorpos);
	}

	//////////////////////////////////////////////////////////////////
	////	F I N A L    E S C A P E   T O    S E X    C I T Y   /////
	//////////////////////////////////////////////////////////////////




		///////////////////////////////////////////////////////////////////////
		//////// S P E C I A L   B A C K G R O U N D   E F F E C T S //////////
		///////////////////////////////////////////////////////////////////////	
	if(VSetActive=="walls1b")
	{
		if(WstAccess==0)
		{
			CurEnvTriggerSet("walls1b","doorout");
			float(_set,tmpfloat,0x111111);
			call(expset1,1,tmpfloat,0);
			float(_set,tmpfloat,0xffffff);
			call(expset2,1,tmpfloat,0);		
		}
		else
		{
			CurEnvTriggerSet("walls1b","doorout");
			float(_set,tmpfloat,0x111111);
			call(expset2,1,tmpfloat,0);
			float(_set,tmpfloat,0xffffff);
			call(expset1,1,tmpfloat,0);		
		}
	}
	if(VSetActive=="walls1")
	{
		//////////////////
		// PLASMA FIELD //
		//////////////////
		if(PlasmaWallExplode==0 && VarBit&=Help04)
		{
			call(SetParticleSetID,"walls1");
			vector(_set,gactorpos,-12250,24425,21650);

			//scale ratio is 51.2 :: 1     ....otherwise you will get cracks/overlaps in the mesh!!!!!!!!!
			float(_set,tmpfloat1,102.4);				//x scale
			float(_set,tmpfloat2,68.2496);				//y scale
	
			callsub(PlasmaWall,1);
		}
		elseif(PlasmaWallExplode==1)
		{
			vector(_set,gactorpos,-12300,24660,21936);
			samplestop(SFXScanHumm,gactorpos);

			vector(_set,gactorpos,-12300,24660,21936);

			if(PlasmaWallExplode==1)
			{
				sample(SFXGlass,gactorpos);
				sample(SFXGrenadeExplode,gactorpos);
			}
			
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);
			callsub(sub_PlasmaWallExplode);

			float(_add,PlasmaWallExplode,1);
		}
		//===================//

		CurEnvTriggerSet("walls1","door2");  //red access lights are turned off
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls1","door2b");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);
		
		if(WstAccess==0)
		{
			CurEnvTriggerSet("walls1","door3");
			float(_set,tmpfloat,0x333333);
			call(expSet2,1,tmpfloat,0);

			CurEnvTriggerSet("walls1","door3b");
			float(_set,tmpfloat,0x333333);
			call(expSet2,1,tmpfloat,0);
		}
		else
		{
			CurEnvTriggerSet("walls1","door3");
			float(_set,tmpfloat,0xFFFFFF);
			call(expSet2,1,tmpfloat,0);

			CurEnvTriggerSet("walls1","door3b");
			float(_set,tmpfloat,0xFFFFFF);
			call(expSet2,1,tmpfloat,0);

			CurEnvTriggerSet("walls1","door3");
			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);

			CurEnvTriggerSet("walls1","door3b");
			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);
			
		}

		if(varkey42==0)
		{
			CurEnvTriggerSet("walls1","convtrig");
			float(_set,tmpfloat,0x333333);
			call(expSet2,1,tmpfloat,0);
		}
		else
		{
			CurEnvTriggerSet("walls1","convtrig");
			float(_set,tmpfloat,0xFFFFFF);
			call(expSet2,1,tmpfloat,0);

			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);
		}
	}

	if(VSetActive=="walls4b")
	{
		if(VarBit&=Help03)
		{
			CurEnvTriggerSet("walls4b","fake");
			float(_set,TmpFloat,0xffff55);
			call(expset2,TmpFloat,400,-1);
		}
		else
		{
			CurEnvTriggerSet("walls4b","fake");
			float(_set,TmpFloat,0x000000);
			call(expset2,TmpFloat,10,-1);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="walls9")
	{
		CurEnvTriggerSet("walls9","door2");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls9","door2b");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls9","door1");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls9","door1b");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="walls3");
	{
		CurEnvTriggerSet("walls3","door2");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls3","door2b");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls3","opdoor");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls3","opdoorb");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="walls12")
	{
		CurEnvTriggerSet("walls12","drlght1");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,);

		CurEnvTriggerSet("walls12","drlght2");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls12","drlght01");
		float(_set,tmpfloat,0x333333);
		call(expSet2,1,tmpfloat,0);

		call(SetParticleSetID,"walls12");
		
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
			vector(_set,Gactorpos,-12198,24542,15408);
			vector(_add,gactorpos,tmpvector);
			SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);

			vector(_set,tmpvector,20,50,200);
			spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,100);
		}

	}
	//----------------------------------------------------------------

	if(VSetActive=="walls2")
	{
		CurEnvTriggerSet("walls2","w2-pl");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls2","fact5door");
		float(_set,tmpfloat,0x00FF00);
		call(expSet1,1,tmpfloat,0);

		CurEnvTriggerSet("walls2","airw2-w1");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,);

		CurEnvTriggerSet("walls2","drlghts");
		float(_set,tmpfloat,0x333333);
		call(expSet1,1,tmpfloat,0);
	}
	//----------------------------------------------------------------

	if(VSetActive=="pillift")
	{
		CurEnvTriggerSet("pillift","lift");
		if(VKeyObjTriggered==0)
		{
			CurEnvTriggerSet("pillift","lift");
			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);
		}

		CurEnvTriggerSet("pillift","panel1");
		if(Vtrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			float(_set,varkey44,0x333333);
			float(_set,varkey45,0xFFFFFF);	
		}
	
		CurEnvTriggerSet("pillift","lift");
		if(VKeyObjTriggered!=0)
		{
			call(expSet2,1,varkey44,0);
			call(expSet1,1,varkey45,0);
		}

		CurEnvTriggerSet("pillift","panel2");
		if(Vtrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			float(_set,varkey45,0x333333);
			float(_set,varkey44,0xFFFFFF);
		}
		
		if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			float(_set,LiftMsg,0);
		}

		elseif(VKeyObjFrame==3 && VKeyObjTriggered==0 && LiftMsg==1)
		{
			float(_set,LiftMsg,0);
		}

	}
	//----------------------------------------------------------------

	if(VSetActive=="pilbox01")
	{
		CurEnvTriggerSet("pilbox01","arm");
		if(VKeyObjTriggered!=0)
		{
			float(_set,tmpfloat,0x0000FF);
			call(expSet1,1,tmpfloat,0);
		}
		else
		{
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
		}
	}
	//----------------------------------------------------------------

	if(VSetActive=="pilbox02")
	{
		CurEnvTriggerSet("pilbox02","arm01");
		if(VKeyObjTriggered!=0)
		{
			float(_set,TmpFloat,0x0000FF);
			call(expSet1,1,TmpFloat,0);
		}

		else
		{
			float(_set,TmpFloat,0x00FF00);
			call(expSet1,1,TmpFloat,0);
		}
	}
	//----------------------------------------------------------------
	
	if(VSetActive=="LoftLift")
	{
		CurEnvTriggerSet("loftlift","lift");
		if(VKeyObjTriggered==0)
		{
			CurEnvTriggerSet("loftlift","lift");
			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);
			call(expSet2,1,tmpfloat,0);
		}

		CurEnvTriggerSet("loftlift","panel1");
		if(Vtrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			float(_set,varkey45,0x333333);
			float(_set,varkey44,0xFFFFFF);	
		}
	
		CurEnvTriggerSet("loftlift","lift");
		if(VKeyObjTriggered!=0)
		{
			call(expSet2,1,varkey44,0);
			call(expSet1,1,varkey45,0);
		}

		CurEnvTriggerSet("loftlift","panel2");
		if(Vtrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			float(_set,varkey44,0x333333);
			float(_set,varkey45,0xFFFFFF);
		}

		if(VKeyObjFrame==0 && VKeyObjTriggered==0 && LiftMsg==1)
		{
		//	message("City Streets",120,10);
			float(_set,LiftMsg,0);
		}
		elseif(VKeyObjFrame==3 && VKeyObjTriggered==0 && LiftMsg==1)
		{
		//	message("Loft Lookout",120,10);
			float(_set,LiftMsg,0);
		}	
	}
	//----------------------------------------------------------------

	if(VSetActive=="walls4")
	{
		if(WstAccess==0) 
		{
			CurEnvTriggerSet("walls4","doorout");
			float(_set,tmpfloat,0x333333);
			call(expSet2,1,tmpfloat,0);

			CurEnvTriggerSet("walls4","light2");
			float(_set,tmpfloat,0x333333);
			call(expSet2,1,tmpfloat,0);
		}
		else
		{
			CurEnvTriggerSet("walls4","doorout");
			float(_set,tmpfloat,0xFFFFFF);
			call(expSet2,1,tmpfloat,0);

			CurEnvTriggerSet("walls4","light2");
			float(_set,tmpfloat,0xFFFFFF);
			call(expSet2,1,tmpfloat,0);

			CurEnvTriggerSet("walls4","doorout");
			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);

			CurEnvTriggerSet("walls4","light2");
			float(_set,tmpfloat,0x333333);
			call(expSet1,1,tmpfloat,0);		
		}			
	}
	//----------------------------------------------------------------


	if(VCurSet=="walls1")  //mainscene
	{
		
		//////// D O O R    L E A D I N G    T O    C O N V E Y O R  //////////	
		if(varkey42==0)
		{
			CurEnvTrigger("convtrig");
			float(_set,tmpfloat,0x00FF00);
			call(expSet1,1,tmpfloat,0);
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				if(vsetactive!="convier1" && ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					if(VRunScriptCode!=14)
					{
						call(RunScriptCode,_or,14);
					}
					direction(_clr,_DIRaction);
				}
			}

			if(VKeyObjTriggered==0 && VRunScriptCode==14)
			{
				callsub(DeInitSceneSound14);
				call(RunScriptCode,_clr,14);
				float(_set,LinkGlobal,0);
			}

			if(ControlTimer==2)
			{
				CurEnvTrigger("convtrig");
				if(VSetActive=="convier1")
				{
					callsub(DoorOpen,2,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("walls1","convtrig",1);
					call(KeyObjTrigger,255,1);
				}
			}
		}
		else
		{
			CurEnvTrigger("convtrig");
			float(_set,tmpfloat,0xFF0000);
			call(expSet1,1,tmpfloat,0);
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				message("Locked From Inside",120,10);
			}
		}
		
		//////// D O O R    L E A D I N G    T O    A N N E X        //////////
		CurEnvTrigger("walls1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				call(RunScriptCode,_or,6);
				direction(_clr,_DIRaction);
			}
		}

		if(VKeyObjTriggered==0 && VRunScriptCode==6)
		{
			callsub(DeInitSceneSound6);
			call(RunScriptCode,_clr,6);
			float(_set,LinkGlobal,0);
		}

		if(ControlTimer==1)
		{
			CurEnvTrigger("walls1");
			dmessage("L O A D I N G . . .",50,2);
			setkeyframe("walls1","walls1",1);
			call(KeyObjTrigger,255,1);
			if(VSetActive=="annx_01")
			{
				callsub(DoorOpen,1,1);
				float(_set,ControlTimer,0);
			}
		}

		// Door to walls9
		if(ControlTimer==10)
		{
			CurEnvTriggerSet("Walls1","door2");
			if(VSetActive=="airw1-w9")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls1","door2",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}

	//----------------------------------------------------------------

	elseif(VCurSet=="walls2")  //main scene
	{
		if(VarKey42==0)
		{
			float(_set,VarKey42,1);

			vector(_set,Gactorpos,-12225,25041,22546);
			vector(_set,Gactorangle,0,534,0);
			InitActor(copm,Gactorpos,Gactorangle,"Walls1",TRUE,10);
			InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"Walls1");

			vector(_set,Gactorpos,-12235,25041,21240);
			vector(_set,Gactorangle,0,1558,0);
			InitActor(copm,Gactorpos,Gactorangle,"Walls1",TRUE,11);
			InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"Walls1");
		}

		CurEnvTrigger("fact5door");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				call(RunScriptCode,_or,7);
				direction(_clr,_DIRaction);
			}
		}

		if(VKeyObjTriggered==0 && VRunScriptCode==7)
		{
			callsub(DeInitSceneSound7);
			call(RunScriptCode,_clr,7);
		}

		if(ControlTimer==2)
		{
			CurEnvTrigger("fact5door");
			if(VSetActive=="fact_5")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls2","fact5door",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==9)
		{
			CurEnvTriggerSet("walls2","w2-pl");
			if(VSetActive=="pillift")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls2","w2-pl",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==10)
		{
			CurEnvTriggerSet("walls2","airw2-w1")
			if(VSetActive=="airw2-w1")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls2","airw2-w1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="walls4")  //mainscene
	{	
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("Walls4","doorout");
			if(VSetActive=="walls1")
			{
				callsub(DoorOpen,2,-1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls4","doorout",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="AirW1-W9")  //mainscene
	{	
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("AirW1-W9","door1");
			if(VSetActive=="walls1")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls4","doorout",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTriggerSet("AirW1-W9","door2");
			if(VSetActive=="walls9")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("airw1-w9","door2",1);
				call(KeyObjTrigger,255,1);
			}
		}	
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="walls9")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("walls9","door1");
			if(VSetActive=="airw9-w3")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls9","door1",1);
				call(KeyObjTrigger,255,1);
			}
		}
		if(ControlTimer==2)
		{
			CurEnvTriggerSet("walls9","door2");
			if(VSetActive=="airw1-w9")
			{
				callsub(DoorOpen,2,1)
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls9","door2",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------
	
	elseif(VCurSet=="AirW9-W3")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("AirW9-W3","door1");
			if(VSetActive=="walls9")
			{
				callsub(DoorOpen,2,1)
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("AirW9-W3","door1",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("AirW9-W3","door2");
			if(VSetActive=="walls3")
			{
				callsub(DoorOpen,2,1)
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("AirW9-W3","door2",1);
				call(KeyObjTrigger,255,1);
			}
		}

	}
	//----------------------------------------------------------------

	elseif(VCurSet=="walls3")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("walls3","opdoor");
			if(VSetActive=="walls12")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls3","opdoor",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("walls3","door2");
			if(VSetActive=="airw9-w3")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}	
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls3","door2",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="walls12")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("walls12","loftlift");
			if(VSetActive=="loftlift")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls12","loftlift",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("walls12","opdoor2");
			if(VSetActive=="walls3")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls12","opdoor2",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="loftlift")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("loftlift","walls12");
			if(VSetActive=="walls12")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls12","opdoor2",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{	
			CurEnvTriggerSet("loftlift","loftwork");
			if(VSetActive=="loftwork")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("walls12","opdoor2",1);
				call(KeyObjTrigger,255,1);
			}
		}	
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="LOFTWORK") // mainscene
	{
		//Lower camera in the loftwork set because of cieling
		Camera(450,0);
		Target(-50,20);

		if(ControlTimer==1)
		{
			CurEnvTriggerSet("loftwork","loftlift");
			if(VSetActive=="loftlift")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("loftwork","loftlift",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="airw2-w1") //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("airw2-w1","walls2");
			if(VSetActive=="walls2")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("airw2-w1","walls2",1);
				call(KeyObjTrigger,255,1);	
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("airw2-w1","walls1");
			if(VSetActive=="walls1")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("airw2-w1","walls1",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="pillift")  //mainscene
	{
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("pillift","w2-pl");
			if(VSetActive=="walls2")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("pillift","w2-pl",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("pillift","ph-pl");
			if(VSetActive=="pilhall")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("pillift","ph-pl",1);
				call(KeyObjTrigger,255,1);
			}

		}
		
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="pilhall")
	{
		if(PlasmaWallExplode!=0)
		{
			float(_clr,VarBit,Help04);
		}
		if(VarBit&!=Help04)
		{
			if(vrnd<25)
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
				vector(_set,Gactorpos,-11586,25153,22946);
				vector(_add,gactorpos,tmpvector);
				call(SetParticleSetID,"pilhall");
				SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);

				vector(_set,tmpvector,238,177,10);
				spawnlight(flash_light,-1,Gactorpos,tmpvector,EmptyVector,250);
			}
		}
		if(ControlTimer==1)
		{
			CurEnvTriggerSet("pilhall","ph-pl");
			if(VSetActive=="pillift")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("pilhall","ph-pl",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==2)
		{
			CurEnvTriggerSet("pilhall","ph-pb1");
			if(VSetActive=="pilbox01")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("pilhall","ph-pb1",1);
				call(KeyObjTrigger,255,1);
			}
		}
		elseif(ControlTimer==3)
		{	
			CurEnvTriggerSet("pilhall","ph-pb2");
			if(VSetActive=="pilbox02")
			{
				callsub(DoorOpen,2,1);
				float(_set,ControlTimer,0);
			}
			else
			{
				dmessage("L O A D I N G . . .",50,2);
				setkeyframe("pilhall","ph-pb2",1);
				call(KeyObjTrigger,255,1);
			}
		}
	}
	//----------------------------------------------------------------
}



		///////////////////////////////////////////////////////////////////////
		//////// B A C K G R O U N D   T R I G G E R   C H E C K     //////////
		///////////////////////////////////////////////////////////////////////

SubRoutine(BackgroundTriggerChecksScene18)
{

	////////////////////////////
	//*** STORY MESSAGE ******//
	////////////////////////////
	callsub(IncomingMessage);

	if(Incoming==3) // end of sequence
	{
		call(SetCamBulb,1);
		callsub(ScriptLevel18); // invokes the original MissionObjectives
		float(_set,incoming,0);
	}

	/////////////////////////////
	/////////////////////////////

	if(VCheatKeys==1)
	{
		if(VKey==KEY_M)
		{
			dmessage("Cheater! Cheater!",50,50);
			float(_set,WstAccess,1)
		}
	}

	if(VCurSet=="walls1") //btcheck
	{
		if(VAICon==0)
		{
			if(PlasmaWallExplode==0 && VarBit&=Help04)
			{
				CurEnvTrigger("PLASMA");
				if(VTrigger==_DIREnvTrigger)
				{
					colstate(_or,_COLelectricity);
				}
				else
				{
					CurEnvTrigger("PLASMA01");
					if(VTrigger==_DIREnvTrigger)
					{
						colstate(_or,_COLelectricity);
					}
				}
			}

			CurEnvTrigger("pilldr01");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				callsub(DoorOpen,1,1);
			}

			CurEnvTrigger("pilldr02");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				callsub(DoorOpen,1,1);
			}
		}

		CurEnvTrigger("door3");
		if(VKeyObjTriggered!=0)
		{
			CurEnvTrigger("shield01");
			call(KeyObjTrigger,255,1);
			CurEnvTrigger("shield02");
			call(KeyObjTrigger,255,1);
		}

		CurEnvTrigger("door3");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(WstAccess==0)
			{	
				message("Locked From Inside",120,10);
				sample(SFXLockedSound,-1);
				if(vrnd<33)
				{
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
			else
			{
				callsub(DoorOpen,2,1);
			}
		}

		CurEnvTrigger("door2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,10);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}		

		CurEnvTrigger("STO1WALL1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{	
			message("Locked",120,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}

		//door to walls4
	}
	//----------------------------------------------------------------

		///////////////////////////////////////////////////////////////////////
		//////// M I S C E L A N E O U S   L E V E L   D O O R S     //////////
		///////////////////////////////////////////////////////////////////////
	elseif(VCurSet=="walls1b")
	{
		CurEnvTrigger("DOOROUT");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(WstAccess>0)
			{
				callsub(dooropen,2,1);
			}
			else
			{	
				message("Locked",120,10);
				sample(SFXLockedSound,-1);
				if(vrnd<33)
				{
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
		}
	}

	elseif(VCurSet=="walls4")  //bt check
	{
		if(VAICon==0)
		{
			CurEnvTrigger("doorout");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
			{
				if(VAIClass!=_AIClassABeast)
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
					message("Access Denied",200,10);
					sample(SFXAccessDenied,-1);
					direction(_clr,_DIRaction);
				}
			}
			call(AIChangePlayerToEnemy);
		}
	}
	elseif(VCurSet=="walls4b")
	{
		if(VAICon!=0)
		{
			if(VAIClass==_AIClassDweller)
			{
				call(AIChangemetoenemy);
			}
			if(VPathID==5)
			{
				if(VarBit&=Help05)
				{
					ActorFlag(_or,_AFlagNoai|_AFLAGnopossesion);
				}
				else
				{
					ActorFlag(_clr,_AFLAGnopossesion);
				}
			}
			if(VAIClass==_AIClassABeast && VPathID==1)
			{
				GetNumbActorsInSet("walls4b",_AIclassdweller,TmpFloat);
				if(Tmpfloat<=1)
				{
					call(AIfindpathwithspecificid,41);
				}
			}
		}
		else
		{
			CurEnvTrigger("fake");
			if(VTrigger==_DIREnvTRigger && VTrigger==_DIRaction)
			{
				message("This Door is Melted Shut",200,10);
				sample(SFXSewerPile1,-1);
				direction(_clr,_DIRaction);
			}
			call(AIChangePlayerToEnemy);
			CurEnvTrigger("door");
			if(VKeyObjTriggered==0 && VKeyObjFrame==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				float(_clr,VarBit,Help05);
				callsub(DoorOpen,0,1);
			}
		}
		CurEnvTrigger("fake");
		call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
		if(TmpFloat==TRUE)
		{
			float(_clr,VarBit,Help03);
			vector(_set,Gactorpos,-17461,25300,22030);
			samplestop(SFXHeli,Gactorpos);
			CurEnvTrigger("door");
			call(SetTriggerObjFlag,1,_or,_SXObjInvisible);
		}
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="AirW1-W9") ///bt check
	{	
		CurEnvTrigger("door2");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("door1");
			float(_set,tmpfloat,0x00FF00);  //set lights to green
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		else
		{
			CurEnvTrigger("door1");
			float(_set,tmpfloat,0xFF0000);  //set lights to red
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				Message("Wait for airlock to close",200,10);
			}
		}

		CurEnvTrigger("door1");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("door2");
			float(_set,tmpfloat,0x00FF00);  //set lights to green
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			
		}
		else
		{
			CurEnvTrigger("door2");
			float(_set,tmpfloat,0xFF0000);  //set lights to red
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				Message("Wait for airlock to close",200,10);
			}
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Walls9") //bt check
	{
		CurEnvTrigger("door1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("door2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{

			//callsub(DoorOpen,2,1);
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("death");
		callsub(Fall2Death);
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="AirW9-W3")  //bt check
	{

		CurEnvTrigger("door2");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("door1");
			float(_set,tmpfloat,0x00FF00);  //set lights to green
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
		}
		else
		{
			CurEnvTrigger("door1");
			float(_set,tmpfloat,0xFF0000);  //set lights to red
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				Message("Wait for airlock to close",200,10);
			}
		}

		CurEnvTrigger("door1");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("door2");
			float(_set,tmpfloat,0x00FF00);  //set lights to green
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			
		}
		else
		{
			CurEnvTrigger("door2");
			float(_set,tmpfloat,0xFF0000);  //set lights to red
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				Message("Wait for airlock to close",200,10);
			}
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Walls3")  //bt check
	{
		CurEnvTrigger("opdoor");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("door2");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		CurEnvTrigger("transit");
		if(Vtrigger==_DIREnvTrigger && VTrigger==_DIRAction)
		{
			message("Locked",120,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Walls5") //bt check
	{
		if(VAICon==0)
		{
			if(VarBit&=Help02)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,19);
				callsub(Panel19);
				ClearDMessage();
				float(_clr,VarBit,Help02);
			}

			CurEnvTrigger("doorwl");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
			{
				if(Controltimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

		
			if(ControlTimer==1)
			{
				CurEnvTrigger("doorwl")
				if(VSetActive=="walls5b")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("walls5","doorwl",1);
					call(KeyObjTrigger,255,1);
				}
			}

		}

		CurEnvTrigger("death01");
		callsub(Fall2Death);
	}
	elseif(VCurSet=="walls5b")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("doorwl");
			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction && VKeyObjTriggered==0)
			{
				if(Controltimer==0)
				{
					if(VSetInMemory!="walls7")
					{
						call(ForceGlobalRealloc);
						call(ForceLoadSet,"walls7");
						call(ForceLoadSet,"walls8");
					}
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

		
			if(ControlTimer==1)
			{
				CurEnvTrigger("doorwl")
				if(VSetActive=="walls5")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("walls5b","doorwl",1);
					call(KeyObjTrigger,255,1);
				}
			}

		}
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Walls7") //bt check
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Walls8") //bt check
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);

		CurEnvTrigger("die");
		callsub(Fall2Death);
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Walls12")  //bt check
	{
		CurEnvTrigger("deathfall");
		callsub(Fall2Death);

		CurEnvTrigger("loftlift");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VAIClass==_AIClassWorker)
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
				message("Only Workers permitted in Worker Loft",120,10);	
				sample(SFXLockedSound,-1);
				if(vrnd<33)
				{
					sample(SFXPlayerActivatesLockedDoorReact,-1);
				}
			}
		}

		CurEnvTrigger("opdoor");
		if(Vtrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			message("Area is Off-limits",120,10);
			sample(SFXLockedSound,-1);
			if(vrnd<33)
			{
				sample(SFXPlayerActivatesLockedDoorReact,-1);
			}
		}

		CurEnvTrigger("opdoor2");
		if(VKeyObjTriggered==0 && Vtrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,2);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
		}

		if(VAIClass==_AIClassWorker && VAction==WorkerWelding)
		{
			if(vrnd<50)
			{
				vector(_set,gactorpos,-12192,24519,15439);
				SamplePlaying(SFXweapontorch2,Gactorpos);
				if(VTrigger!=_DIRTempFlag)
				{
					Sample(SFXweapontorch2,gactorpos);
					SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);
				}
			}
			if(vrnd<40)
			{
				vector(_set,gactorpos,-12192,24519,15439);
				SamplePlaying(SFXweapontorch2,Gactorpos);
				if(VTrigger==_DIRTempFlag)
				{
					Samplestop(SFXweapontorch2,gactorpos);
				}
				vector(_set,gactorpos,-12192,24519,15439);
				SpawnParticle(fx_sparks,-1,Gactorpos,EmptyVector,-1);
			}
		//	elseif(vrnd>40)
		//	{
		//		vector(_set,gactorpos,-12192,24519,15439);
		//		SamplePlaying(SFXweapontorch2,Gactorpos);
		//		if(VTrigger==_DIRTempFlag)
		//		{
		//			Samplestop(SFXweapontorch2,gactorpos);
		//		}
		//	}
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="LoftLift")  //bt check
	{
		CurEnvTrigger("lift");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("walls12");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);

			CurEnvTrigger("loftwork");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);

			CurEnvTrigger("walls12");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("loftwork");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
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
			CurEnvTrigger("walls12");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);

			CurEnvTrigger("loftwork");
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

		if(VTrigger==_DIRactionhold)
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
						call(ActivateButton,0,3,2);
						//kfsample(-1,-1,-1,SFX?,1);  //sound fx for floor
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						call(ActivateButton,0,0,2);
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
	//----------------------------------------------------------------
	elseif(VCurSet=="LoftWork")  //bt check
	{
		CurEnvTrigger("LoftLift");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			SetKeyFrame("loftwork","lift",3);
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,1);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}
				
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Walls2") //bt check
	{
		if(VAICon==0)
		{
			if(VarBit&=Help01)
			{
				float(_set,Incoming,1);
				float(_set,Godtimer,0);
				float(_set,BobMessage,1); // Disable Mission Objective - Enable special mode
				float(_set,ScriptMark,18);
				callsub(Panel18);
				ClearDMessage();
				float(_clr,VarBit,Help01);
			}
		}
		CurEnvTrigger("AIRW2-W1");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,10);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}	
		}

		CurEnvTrigger("w2-pl");
		if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(ControlTimer==0)
			{
				float(_set,ControlTimer,9);
				call(KeyObjTrigger,255,1);
				direction(_clr,_DIRaction);
			}	
		}

		//For cops beating on the dead chot.
		CurEnvTrigger("beatdown");
		if(VTrigger==_DIREnvTrigger && VAICon!=0)
		{
			if(VAIClass==_AIClassCop && VAItargetfound!=_AIenemy && VAIState!=_AIstateAttack)
			{
				float(_rnd2,tmpfloat,300);
				if(tmpfloat<=1)
				{
					spawnaction(CopKickGeneric);
					sample(SFXCopLaughter,-1);
				}

				float(_rnd2,tmpfloat2,300);
				if(tmpfloat2<=1)
				{
					sample(SFXBumpIntoReact,-1);
				}
			}
		}

		if(VAICon!=0 && VAction==CopKickGeneric)
		{
			if(vframe==17)
			{
				sample(SFXManPunch,-1);
			}
		}

		CurEnvTrigger("deathfall");
		callsub(Fall2Death);
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="AIRW2-W1")  //bt check
	{
		CurEnvTrigger("WALLS2");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("walls1");
			float(_set,tmpfloat,0x00FF00);  //set lights to green
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
					if(WstAccess!=1)
					{
						float(_set,WstAccess,1);
					}
				}
			}
		}
		else
		{
			CurEnvTrigger("walls1");
			float(_set,tmpfloat,0xFF0000);  //set lights to red
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				Message("Wait for airlock to close",200,10);
			}
		}

		CurEnvTrigger("walls1");
		if(VKeyObjTriggered==0)
		{
			CurEnvTrigger("WALLS2");
			float(_set,tmpfloat,0x00FF00);  //set lights to green
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction && VKeyObjTriggered==0)
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}
			
		}
		else
		{
			CurEnvTrigger("WALLS2");
			float(_set,tmpfloat,0xFF0000);  //set lights to red
			call(expset1,1,tmpfloat,0);

			if(VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				Message("Wait for airlock to close",200,10);
			}
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Pillift")  //bt check
	{
		CurEnvTrigger("lift");
		if(VkeyObjTriggered==0)
		{
			CurEnvTrigger("ph-pl");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);

			CurEnvTrigger("w2-pl");
			call(SetTriggerObjFlag,1,_or,_SXObjCollisionOff);

			CurEnvTrigger("w2-pl");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("ph-pl");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)	
			{
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
			CurEnvTrigger("ph-pl");
			call(SetTriggerObjFlag,1,_clr,_SXObjCollisionOff);

			CurEnvTrigger("w2-pl");
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

		if(VTrigger==_DIRactionhold)
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
						call(ActivateButton,0,3,2);
						//kfsample(-1,-1,-1,SFX?,1);  //sound fx for floor?
					}
				}
				else
				{
					if(TmpFloat==0)
					{
						call(ActivateButton,0,0,2);
						//kfsample(-1,-1,-1,SFX?,1);  //sound fx for floor?
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
	//----------------------------------------------------------------
	elseif(VCurSet=="Pilhall")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("PILLIFT");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				CurEnvTrigger("PH-PL");
				SetKeyFrame("pillift","lift",3);
				
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			CurEnvTrigger("PILBOX1");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				CurEnvTrigger("PH-PB1");

				if(ControlTimer==0)
				{
					float(_set,ControlTimer,2);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}	
			}

			CurEnvTrigger("PILBOX2");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				CurEnvTrigger("PH-PB2");

				if(ControlTimer==0)
				{
					float(_set,ControlTimer,3);
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}	
			}

			CurEnvTrigger("plasma");
			if(VTrigger==_DIREnvTrigger)
			{
				if(VTrigger==_DIRaction)
				{
					if(VarBit&=Help04)
					{
						call(ActivateButton,0,-1,FALSE);
						call(ActivateButtonSample,SFXValidFunction);
					}
					else
					{
						float(_clr,VarBit,Help04);
						call(ActivateButton,0,-1,FALSE);
						call(ActivateButtonSample,SFXInvalidFunction);
					}
				}
				if(VState==StateJustActivated)
				{
					if(VarBit&=Help04)
					{
						message("Plasma Wall is Off",200,10);
						call(KeyObjTrigger,255,1);
						float(_set,TmpFloat,0xff0000);
						call(expset1,1,TmpFloat,0);
						float(_clr,VarBit,Help04);
						// add a sample here
					}
					else
					{
						message("System Malfunction",120,10);
					}
				}
				direction(_clr,_DIRaction);
			}
		}
	}
	//----------------------------------------------------------------
	elseif(VCurSet=="Pilbox01")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("PILHALL");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				CurEnvTrigger("PH-PB1");
				callsub(DoorOpen,2,1);	
			}

			CurEnvTrigger("PILHALL2");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					CurEnvTrigger("PB1-W1")
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("PB1-W1")
				if(VSetActive=="walls1")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
					CurEnvTriggerSet("walls1","shield01");
					call(KeyObjTrigger,255,1);
					CurEnvTriggerSet("walls1","shield02");
					call(KeyObjTrigger,255,1);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("Pilbox01","PB1-W1",1);
					call(KeyObjTrigger,255,1);
				}
			}		
		}
		CurEnvTrigger("arm");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					vector(_set,Gactorpos,-11940,25078,20789);
					vector(_set,Gactorangle,0,0,0);
					InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"pilbox01",TRUE);
					call(KeyObjTrigger,255,1);
					float(_set,TmpFloat,0x0000ff);
					call(expset1,1,TmpFloat,0);
				}
				elseif(VAICON==0)
				{
					call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
			elseif(VAICON==0)
			{
				call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}
		}
	
		CurEnvTrigger("arm")
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,-11940,25078,20789);
			callsub(DispenserSound);
		}
		else
		{
			if(timer2!=0)
			{
				float(_set,timer2,0);
			}
		}
	}	
	//----------------------------------------------------------------
	elseif(VCurSet=="Pilbox02")
	{
		if(VAICon==0)
		{
			CurEnvTrigger("panel1");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				CurEnvTrigger("PH-PB2");	
				callsub(DoorOpen,2,1);	
			}

			CurEnvTrigger("PH-PB2");
			if(VTrigger==_DIREnvTrigger && VKeyObjTriggered!=0)
			{
				callsub(DoorOpen,2,1);
			}

			CurEnvTrigger("panel2");
			if(VKeyObjTriggered==0 && VTrigger==_DIREnvTrigger && VTrigger==_DIRAction)
			{
				call(ActivateButton,0,-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				if(ControlTimer==0)
				{
					float(_set,ControlTimer,1);
					CurEnvTrigger("PB2-W1")
					call(KeyObjTrigger,255,1);
					direction(_clr,_DIRaction);
				}
			}

			if(ControlTimer==1)
			{
				CurEnvTrigger("PB2-W1")
				if(VSetActive=="walls1")
				{
					callsub(DoorOpen,1,1);
					float(_set,ControlTimer,0);
					CurEnvTriggerSet("walls1","shield01");
					call(KeyObjTrigger,255,1);
					CurEnvTriggerSet("walls1","shield02");
					call(KeyObjTrigger,255,1);
				}
				else
				{
					dmessage("L O A D I N G . . .",50,2);
					setkeyframe("Pilbox02","PB2-W1",1);
					call(KeyObjTrigger,255,1);
				}
			}		
		}

		CurEnvTrigger("arm01");
		if(VTrigger==_DIREnvTrigger && VTrigger==_DIRaction)
		{
			if(VClass!=_ClassAngel)
			{
				if(VKeyObjFrame==0 && VKeyObjTriggered==0)
				{
					call(ActivateButton,"Weapon Dispenser Activated",-1,FALSE);
					call(ActivateButtonSample,SFXValidFunction);
					vector(_set,Gactorpos,-11945,25078,23013);
					vector(_set,Gactorangle,0,0,0);
					InitActor(WeaponMachineGun,Gactorpos,Gactorangle,"pilbox02",TRUE);
					call(KeyObjTrigger,255,1);
					float(_set,TmpFloat,0x0000ff);
					call(expset1,1,TmpFloat,0);
				}
				elseif(VAICON==0)
				{
					call(ActivateButton,"Weapon Dispenser Already Activated",-1,FALSE);
					call(ActivateButtonSample,SFXInvalidFunction);
				}
			}
			elseif(VAICON==0)
			{
				call(ActivateButton,"I wish I could operate that thing!",-1,FALSE);
				call(ActivateButtonSample,SFXInvalidFunction);
			}
		}

		CurEnvTrigger("arm01");
		if(VKeyObjTriggered!=0)
		{
			vector(_set,Gactorpos,-11945,25078,23013);
			callsub(DispenserSound);
		}
		else
		{
			if(timer2!=0)
			{
				float(_set,timer2,0);
			}
		}
	}
	//----------------------------------------------------------------

	elseif(VCurSet=="wast1")
	{
		if(VRunScriptCode!=10 && VRunScriptCode==18)
		{
			CurEnvTriggerSet("walls8","enter");
			callsub(DoorOpen,2,1);
			callsub(DeInitSceneSound18);
			call(RunScriptCode,_clr,18);
			call(RunScriptCode,_or,10);
		}
	}
	//----------------------------------------------------------------
}
//----------------------------------------------------------------