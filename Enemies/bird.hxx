/*
Da Bird:

Gliding with legs up. Not carrying anything
	DaBird\xxx\BrGldLgU.ske

Flapping with legs up. Not carrying anything
	DaBird\xxx\BrFlpLgU.ske

Gliding with legs Down. Carrying Rat:
	DaBird\xxx\BrGldLgD.ske

Flapping with legs Down. Carrying Rat:
	DaBird\xxx\BrFlpLgD.ske

Bird swooping and grabbing Rat.  Grab at frame #46:
	DaBird\xxx\BrGrbRat.ske

*/


SubRoutine(Sub_FlapSound)
{
	if(VFrame==10)
	{
		sample(SFXBobFlap,-1);
	}
}

action(BirdGlide)
{
		file("pc\actors\DaBird\xxx\BrGldLgU.ske",100,on);	//Gliding with legs up. Not carrying anything
		gravity(off);
		trigger(_allDIR);
//		AIClass(_AIClassAnimal);
		break(on);
		nrintframes(4);
		connections(BirdFly);
}

action(BirdFly)
{
		file("pc\actors\DaBird\xxx\BrFlpLgU.ske",100,on,100,-1,-1,Sub_FlapSound);	//Flapping with legs up. Not carrying anything
		gravity(off);
		trigger(_allDIR);
//		AIClass(_AIClassAnimal);
		break(on);
		nrintframes(4);
		connections(BirdFly);
}


action(BirdIdle)
{
		file("pc\actors\DaBird\xxx\BrSitHld.ske",100,on);

		gravity(off);

		trigger(_allDIR);
//		AIClass(_AIClassAnimal);
		break(on);
		nrintframes(4);
		connections(BirdIdle);
}


//	Bird is not player controlled
//
Actor(Bird)
{
		file(BirdHeader); 

		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(BirdIdle);

		float(_declare,RandomBirdSound,0);


		call(ModelAmbient,2048,2048,2048);


		CallSub(BackGroundTriggerChecks);


		if(VAIhaspath==0)
		{
			call(PickNewNode);
		}

/*
		//random birdy noises
		if(RandomBirdSound<=0)
		{
			float(_rnd2,RandomBirdSound,100);
			float(_add,RandomBirdSound,100);
			if(vrnd<50)
			{
				sample(SFXrat3,-1);
			}
			else
			{
				sample(SFXrat6,-1);
			}
		}
		else
		{
			float(_sub,RandomBirdSound,1);
		}
*/

		Direction(_clr,_DIRaiRemoveFlags);

		call(AIPickdest,10);
		if(vtrigger==_DIRtempflag)
		{
			call(PickNewNode);
		}
		CallSub(Sub_AI1WayAlignToPickDestAngle);

		PrintI("VAIstate: ",VAIstate);
		PrintI("VPickDestAngleCorr: ",VPickDestAngleCorr);
		PrintI("VPickDestOffsetY: ",VPickDestOffsetY);


		if(VAIstate!=_AIstateIdle)
		{
			if(VAction!=BirdFly)
			{
				SpawnAction(BirdFly);
			}
			if(VTrigger==_DIRleft)
			{
				turn(0,-50,0);
			}
			elseif(VTrigger==_DIRright)
			{
				turn(0,50,0);
			}
			if(vpickdestanglecorr>512 || vpickdestanglecorr<-512)	//might need bigger numbers
			{
				move(0,0,-5);
			}
			else
			{
				move(0,0,-20);
			}

			if(VPickDestOffsetY>20)
			{
				move(0,-16,0);
			}
			elseif(VPickDestOffsetY<-20)
			{
				move(0,16,0);
			}
		}

		if(VAIstate==_AIstateGetWeapon)
		{
			call(PickupActor,10,_AIclassAnimal,_RankSergeantL);
			if(VTrigger==_DIRTempFlag)
			{
				sample(SFXBirdScream,-1);
			}
		}
		elseif(VAIstate==_AIstateDetachFromPath)
		{
			call(ClrPath);
		}
		elseif(VAIstate==_AIstateDrop)
		{
			call(CheckAttached,_CADropActor);
		}
		elseif(VAIstate==_AIstateSuicide)
		{
			killactor();
		}
}
