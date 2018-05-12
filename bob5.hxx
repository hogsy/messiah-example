

/*
Actors:
Bob1
Halo
*/


///////////////////////////////////



#define	_WeakLittleBaby			8
#define	_WeakLittleEvilBaby		9

Actor(Bob1)
{
		file(bobHeader);
		startstate(statenormal);
		startaction(BobIdle);
		rank(_WeakLittleBaby);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,0);
		float(_declare,AIUsage,0);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIANoCloseUpReaction);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

/*
		if(vkey==key_a)
		{
			call(PlaySequence,0);		//play end sequence

			//call(wCheckViewCollision,-1,-1,-1,0);	//fade to black
			//call(wCheckViewCollision,0,0,-2,-1);	//fade to white
			//call(CDSwap,7,0,100,60);	//example: new track, newloopstate, new vol, fade time
			//call(HUDTimerSet,1800);		//example: starts displaying and counting down from 60 seconds :: call once, not every frame!
		}


		if(vkey==key_b)
		{
			//call(wCheckViewCollision,-1,-1,-1,0);	//fade to black
			//call(wCheckViewCollision,0,0,0,0);	//fade to white
			//call(CDSwap,7,0,100,60);	//example: new track, newloopstate, new vol, fade time
			//call(HUDTimerSet,1800);		//example: starts displaying and counting down from 60 seconds :: call once, not every frame!
		}
		*/


		//#include	"messiahscripts\BobGen.hxx"

		if(VFirstPerson==0) 
		{
			callsub(Sub_InitPossesion, NoMove, NoMove, NoMove);

			call(DisplayHUD, 0);
			call(ChangeSniperMode, -1, 0);

			FirstPerson(1);
		}

		print("arrrr");

		if (vtrigger==_DIRforward)
		{
			move(0, 0, -5);
		}
		elseif(vtrigger==_DIRbackward)
		{
			move(0, 0, 2);
		}
		if (VTrigger==_DIRleft || VTrigger==_DIRsideleft)
		{
			print("turning");
			turn(0, -20, 0);
		}
		elseif(VTrigger==_DIRright || VTrigger==_DIRsideright)
		{
			turn(0, 20, 0);
		}
}

Actor(EvilBob)
{
		file(EvilBobHeader);
		startstate(statenormal);
		startaction(BobIdle);
		rank(_WeakLittleEvilBaby);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUAlwaysRun|_AIUFindHost);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPossesion|_AIANoCloseUpReaction|_AIANoBoneCollision);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		float(_declare,firefeet,0);

		float(_declare,ScaleEBob,1);		//evil bob only


		printi("Evilbob target:        ",VAIhastarget);
		printih("Evilbob targetclass:   ",VAItargetclass);
		if(VAItargetclass==_AIclassAngel)
		{
			print("clearing target");
			call(AIclrtarget);
		}


		#include	"messiahscripts\enemies\CopGen.hxx"

		if(VActiveTime==1)
		{
			spawnactor(EvilHalo,0,0,0);
			call(CheckForPickup,4,_ClassPickup);

			ChangeMaterialFlags(_or,7,_SXMChromaKey,255);

			//call(SubtractHealth,0,-3000);		//bob full health after a depossess (just for now)
		}



		if(Vaction==EBobHeelTap)
		{
			if(VFrame>=25)
			{
				call(SetParticleSetID,"s1r8");
				float(_sub,ScaleEBob,0.13);
				scalebonematrix(0,ScaleEBob,ScaleEBob,ScaleEBob,_SXBoneAttAbsolute);
			}
			if(VFrame==32)
			{
				KillActor();
			}
		}


		if(VTrigger!=_DIRwalking)
		{
			if(VTrigger==_DIRforward||Vtrigger==_DIRleft||Vtrigger==_DIRright||Vtrigger==_DIRsideleft||Vtrigger==_DIRsideright||Vtrigger==_DIRbackward)
			{
				spawnparticle(fx_evilfire,20,emptyvector,EmptyVector,-1);
				if(firefeet==0)
				{
					sample(SFXGenericBurn,-1,25);
				}
				float(_set,firefeet,1);
			}
			else
			{
				if(firefeet==1)
				{
					samplestop(SFXGenericBurn);
				}
				float(_set,firefeet,0);
			}
		}
		else
		{
			if(firefeet==1)
			{
				samplestop(SFXGenericBurn);
			}
			float(_set,firefeet,0);
		}
}

Actor(chotdwarf)
{
		file(ChotdwarfHeader);

		rank(_RankSergeantL);

		startstate(statenormal);
		startaction(BobIdle);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUAlwaysRun|_AIUCrowdAroundLeader);
		float(_declare,AIAbility,_AIAJump|_AIAFlashVisors|_AIASpecialSecondaryWeapon|_AIANoCloseUpReaction|_AIANoBoneCollision);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\CopGen.hxx"
}


Actor(Halo)
{
		file(HaloHeader);
		startaction(nomove);

		//float(_declare,HaloTrans,30);
		vector(_declare,HaloPos,0,25,0);
		vector(_declare,HaloPos1,0,0,0);
		vector(_declare,HaloPos2,0,0,0);
		vector(_declare,HaloPos3,0,0,0);
		vector(_declare,HaloPos4,0,0,0);
		vector(_declare,HaloOuterPos,0,0,0);
		float(_declare,RndAngle,0);
		float(_declare,Fader,255);
		float(_declare,FaderDirection,-20);

		vector(_copy,HaloPos4,HaloPos3);
		vector(_copy,HaloPos3,HaloPos2);
		vector(_copy,HaloPos2,HaloPos1);
		vector(_settoactorpos,HaloPos1);


		if(VState==StateAttached)
		{
			print("incoming        ",incoming);
			if(InComing==0)
			{
				call(ModelAmbient,255,255,255);
			}
			else
			{
//				vector(_copy,CharOffset,HaloPos1);
//				vector(_addy,CharOffset,-80);
//				vector(_set,TmpVector,0,0,0);
//				vector(_setx,TmpVector,Fader);
//				spawnlight(HeavyCopSearchLight,-1,CharOffset,TmpVector,EmptyVector,90);
				call(ModelAmbient,255,Fader,255);
				float(_add,Fader,FaderDirection);
				if(Fader<0)
				{
					float(_set,Fader,0);
					float(_inv,FaderDirection);
				}
				elseif(Fader>255)
				{
					float(_set,Fader,255);
					float(_inv,FaderDirection);
				}
			}


			if(VSniperMode==0 && VFirstPerson==0)
			{
				call(ChangeAlpha,40);
				//call(ReDrawActor,halopos1);
				//call(ChangeAlpha,30);
				//call(ReDrawActor,halopos2);
				//call(ChangeAlpha,20);
				//call(ReDrawActor,halopos3);
				//call(ChangeAlpha,10);
			}


	//limit length of halo trail ----->
	/*
			vector(_declare,halot,0,0,0);		//tmp pos
			vector(_declare,halon,0,0,0);		//new pos
			vector(_declare,halod,-1,-1,-1);	//delta

			vector(_copy,halot,halopos1);
			vector(_sub,halot,halopos2);
			vector(_normalize,halot);			//yarK

			vector(_copy,halon,halot);
			vector(_mul,halon,halod);
			vector(_add,halon,halopos1);
			//call(ChangeAlpha,10);
			call(ReDrawActor,halon);

			//vector(_set,halod,-1,-1,-1);
			//vector(_copy,halon,halot);
			//vector(_mul,halon,halod);
			//vector(_add,halon,halopos1);

			//call(ChangeAlpha,20);
			//call(ReDrawActor,halon);

			//vector(_set,halod,0,0,0);
			//vector(_copy,halon,halot);
			//vector(_mul,halon,halod);
			//vector(_add,halon,halopos1);

			//call(ChangeAlpha,30);
			//call(ReDrawActor,halon);
	*/
	//<------limit length of halo trail


			if(vrnd<50 && VSniperMode==0 && VFirstPerson==0)
			{
				float(_rnd,RndAngle,4096);
				vector(_vectorfromangle,HaloOuterPos,RndAngle,20);
				vector(_add,HaloOuterPos,HaloPos);
				SpawnParticle(fx_Halo,0,HaloOuterPos,emptyVector,-1);
			}

			if(vtrigger==_DIRdepossesion)
			{
				killactor();
			}

			if(VRank==_WeakLittleBaby)
			{
				if(Vstate!=StateOnFire)
				{
					//vector(_declare,bbbcolor,120,75,000);
					vector(_declare,bbbcolor,10,20,30);
					SpawnLight(LomnilightAllSets,0,EmptyVector,bbbcolor,EmptyVector,250);
				}
			}
		}
}

Actor(EvilHalo)
{
		file(EvilHaloHeader);
		startaction(nomove);

		//float(_declare,HaloTrans,30);
		vector(_declare,HaloPos,0,25,0);
		vector(_declare,HaloPos1,0,0,0);
		vector(_declare,HaloPos2,0,0,0);
		vector(_declare,HaloPos3,0,0,0);
		vector(_declare,HaloPos4,0,0,0);
		float(_declare,RndAngle,0);
		vector(_declare,HaloOuterPos,0,0,0);

		vector(_copy,HaloPos4,HaloPos3);
		vector(_copy,HaloPos3,HaloPos2);
		vector(_copy,HaloPos2,HaloPos1);
		vector(_settoactorpos,HaloPos1);

		if(VState==StateAttached)
		{
			if(VSniperMode==0 && VFirstPerson==0)
			{
				call(ChangeAlpha,80);
				//call(ReDrawActor,halopos1);
				//call(ChangeAlpha,30);
				//call(ReDrawActor,halopos2);
				//call(ChangeAlpha,20);
				//call(ReDrawActor,halopos3);
				//call(ChangeAlpha,10);
			}


	//limit length of halo trail ----->
	/*
			vector(_declare,halot,0,0,0);		//tmp pos
			vector(_declare,halon,0,0,0);		//new pos
			vector(_declare,halod,-1,-1,-1);	//delta

			vector(_copy,halot,halopos1);
			vector(_sub,halot,halopos2);
			vector(_normalize,halot);			//yarK

			vector(_copy,halon,halot);
			vector(_mul,halon,halod);
			vector(_add,halon,halopos1);
			//call(ChangeAlpha,10);
			call(ReDrawActor,halon);

			//vector(_set,halod,-1,-1,-1);
			//vector(_copy,halon,halot);
			//vector(_mul,halon,halod);
			//vector(_add,halon,halopos1);

			//call(ChangeAlpha,20);
			//call(ReDrawActor,halon);

			//vector(_set,halod,0,0,0);
			//vector(_copy,halon,halot);
			//vector(_mul,halon,halod);
			//vector(_add,halon,halopos1);

			//call(ChangeAlpha,30);
			//call(ReDrawActor,halon);
	*/
	//<------limit length of halo trail


			if(vrnd<50 && VSniperMode==0 && VFirstPerson==0)
			{
				float(_rnd,RndAngle,4096);
				vector(_vectorfromangle,HaloOuterPos,RndAngle,20);
				vector(_add,HaloOuterPos,HaloPos);
				SpawnParticle(fx_Halo,0,HaloOuterPos,emptyVector,-1);
			}

			if(vtrigger==_DIRdepossesion)
			{
				killactor();
			}

			if(VRank==_WeakLittleBaby)
			{
				if(Vstate!=StateOnFire)
				{
					//vector(_declare,bbbcolor,120,75,000);
					vector(_declare,bbbcolor,10,20,30);
					SpawnLight(LomnilightAllSets,0,EmptyVector,bbbcolor,EmptyVector,250);
				}
			}
		}
}









