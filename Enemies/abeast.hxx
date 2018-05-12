/*
Actors:
Abeast
beastRed
BeastBlue
*/

Actor(Abeast)//Armored Beast/Behemoth
{
		file(ABehemothHeader);
		rank(_RankGeneral);

		startstate(StateNormal);
		startaction(AbeastIdle);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,0);
		float(_declare,AIUsage,_AIUAdvanceIfEnemyUnseen);
//		float(_declare,AIAbility,_AIAJump|_AIANoCrawl|_AIANoBoneCollision|_AIANoThrown);	//_AIAAlwaysInCombatMode|
		float(_declare,AIAbility,_AIAJump|_AIANoCrawl|_AIANoBoneCollision|_AIANoThrowGrenades|_AIANoThrown);	//_AIAAlwaysInCombatMode|
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);
		float(_declare,BreathOn,0)

		/*
		if(vstate!=statedead)
		{
			vector(_set,Gactorpos,-100,-40,10);
			spawnparticle(fx_flare,9,gactorpos,emptyvector,fx_heavycoplaserflare);

			vector(_set,Gactorpos,100,-40,10);
			spawnparticle(fx_flare,9,gactorpos,emptyvector,fx_heavycoplaserflare);

			vector(_set,Gactorpos,50,20,-20);
			//spawnparticle(fx_flare,5,gactorpos,emptyvector,fx_heavycoplaserflare);
		}
		*/


		if(VactorFlag==_AFLAGinitialize)			//re-initialize after a loadgame
		{
			if(BreathOn==1)
			{
				sample(SFXBreathing,-1);
			}
		}

		if(VActiveTime==0)
		{
			call(AttachToActor,WeaponAbeastMachineGun,8);
			direction(_or,_DIRhavegun);
		}

		#include	"messiahscripts\enemies\copgen.hxx"



		if(VAICon!=0)
		{
			if(VAIState==_AIstateShutDown)
			{
				if(VActorFlag==_AFLAGnoai)
				{
					if(VAction!=ABeastShutDown)
					{
						SpawnAction(ABeastShutDown);
						ActorFlag(_or,_AFLAGnopossesion|_AFLAGnotarget);
					}
				}
				else
				{
					if(VOAction==ABeastShutDown)
					{
						SpawnAction(ABeastPowerUp);
						ActorFlag(_clr,_AFLAGnopossesion|_AFLAGnotarget);
					}
				}
			}
		}
		else
		{
			if(VTrigger==_DIRShoot)
			{
				callsub(Sub_SetCameraNormal);
			}
			elseif(VOTrigger==_DIRShoot)
			{
				callsub(Sub_SetCameraNormal);
			}
		}

		if(VAIlaststate==_AIstateShutDown)
		{
			if(BreathOn==0)
			{
				sample(SFXBreathing,-1);
				float(_set,BreathOn,1);
			}
		}
		elseif(VAIState==_AIstateShutDown)
		{
			if(BreathOn==1)
			{
				samplestop(SFXBreathing);
				float(_set,BreathOn,0);
			}
		}
		elseif(vactivetime==0)
		{
			if(BreathOn==0)
			{
				sample(SFXBreathing,-1);
				float(_set,BreathOn,1);
			}
		}

		if(vstate==statedead)
		{
			if(BreathOn==1)
			{
				samplestop(SFXBreathing);
				float(_set,BreathOn,0);
			}
		}

/*		if(VAction==ABeastStandShoot && VFrame==0)
		{
			vector(_set,TmpVector,0,0,0);
			spawnactorbone(BulletMachineGun,TmpVector,Gactorpos,Gactorine,8);
			vector(_set,tmpvector,250,167,20);
			spawnlight(flash_light,8,Gactorpos,tmpvector,EmptyVector,350);
		}
*/
}



Actor(beast)
{
		file(BehemothHeader);
		rank(_RankGeneral);

		startstate(StateNormal);
		startaction(BeastIdleNonCombat);
		//startaction(beastIdle);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,0);
		float(_declare,AIUsage,0);
//		float(_declare,AIAbility,_AIAJump|_AIASpecialSecondaryWeapon|_AIANoCrawl|_AIANoBoneCollision|_AIAAlwaysInCombatMode|_AIANoThrown);
		float(_declare,AIAbility,_AIAJump|_AIASpecialSecondaryWeapon|_AIANoCrawl|_AIANoBoneCollision|_AIANoThrown);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"

		if(vactivetime==0)
		{
			sample(SFXBreathing,-1);
		}
		if(vstate==statedead)
		{
			samplestop(SFXBreathing);
		}

		if(VActor<0 || VTrigger!=_DIRalive && VOTrigger==_DIRalive)
		{
			float(_set,CanMakeBeast,1);
		}
}


Actor(chotbeast)
{
		file(chotBehemothHeader);
		rank(_RankGeneral);

		startstate(StateNormal);
		startaction(BeastIdleNonCombat);
//		startaction(BeastIdle);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,0);
		float(_declare,AIUsage,0);
		float(_declare,AIAbility,_AIAJump|_AIASpecialSecondaryWeapon|_AIANoCrawl|_AIANoBoneCollision|_AIANoThrown);
//		float(_declare,AIAbility,_AIAJump|_AIASpecialSecondaryWeapon|_AIANoCrawl|_AIANoBoneCollision|_AIANoThrown);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}



Actor(bouncer)
{
		file(bouncerHeader);
		rank(_RankGeneral);

		startstate(StateNormal);
		startaction(BeastIdleNonCombat);
//		startaction(beastIdle);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,0);
		float(_declare,AIUsage,0);
//		float(_declare,AIAbility,_AIAJump|_AIANoCrawl|_AIANoBoneCollision|_AIANoThrown);
		float(_declare,AIAbility,_AIAJump|_AIANoCrawl|_AIANoBoneCollision|_AIANoThrown);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);


		#include	"messiahscripts\enemies\copgen.hxx"
}


