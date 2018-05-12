
#define PriestMaxTurnSpeed 75
#define PriestTurnAcc 7


Actor(Medic)
{
		file(MedicHeader);
		rank(_RankPrivate);
		startstate(StateNormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"

		if(VAction==MedicWorking)
		{
			//Chot\xxx\MedWld2.ske  : 0
			//Chot\xxx\MedWld3.ske  : 1
			//Chot\xxx\MedWld4.ske  : 2

			if(VActionIndex==0)
			{
				//Loop working/sewing on crushed guy animation. Lots of blood from crushed workers chest.
				if(vrnd<10)
				{
					spawnparticle(fx_bloodspray,8,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,8,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,12,emptyvector,emptyvector,-1);
					spawnparticle(fx_bloodlesser,8,emptyvector,emptyvector,-1);
					spawnparticle(fx_bloodlesser,12,emptyvector,emptyvector,-1);
				}
			}
			elseif(VActionIndex==1)
			{
				//Look at flesh in right hand, then toss it over shoulder at frame #73:
				if(vrnd<25&&vframe>=70&&vframe<=75)
				{
					spawnparticle(fx_bloodspray,12,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,12,emptyvector,emptyvector,-1);
					spawnparticle(fx_bloodlesser,12,emptyvector,emptyvector,-1);
				}
			}
			elseif(VActionIndex==2)
			{
				//Tossing something in left hand over shoulder frame #20:
				if(vrnd<25&&vframe>=20&&vframe<=25)
				{
					spawnparticle(fx_bloodspray,8,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,8,emptyvector,emptyvector,-1);
					spawnparticle(fx_bloodlesser,8,emptyvector,emptyvector,-1);
				}
			}
		}
}





Actor(Barman)
{
		file(BarmanHeader);
		rank(_RankPrivate);
		startstate(StateNormal);
		startaction(copidleNoGun);

		ActorFlag(_or,_AFLAGnopossesion);
		//AI variables. All characters using copgen.hxx needs these defined to work properly
		
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(BarmanHelper)
{
		file(BarmanHeader);
		rank(_RankPrivate);
		startstate(StateNormal);
		startaction(copidleNoGun);

		float(_declare,alphachange,0);
		float(_declare,alphadirection,0);

		if(alphadirection==0)
		{
			float(_add,alphachange,1);
			if(alphachange>128)
			{
				float(_set,alphadirection,1);
			}
		}
		else
		{
			float(_sub,alphachange,1);
			if(alphachange<1)
			{
				float(_set,alphadirection,0);
			}
		}

		call(SetBlendingMode,false,_or,_SXMAddTrans,alphachange);

		ActorFlag(_or,_AFLAGnopossesion|_AFLAGnocollision|_AFLAGnotarget);
		
		call(ModelAmbient,64,128,64);

		vector(_set,TmpVector,128,200,128);
		spawnlight(HeavyCopSearchLight,1,Emptyvector,TmpVector,EmptyVector,350);
	//	#include	"messiahscripts\enemies\copgen.hxx"
}



Actor(Priest)
{
		file(PriestHeader);
		rank(_RankPrivate);
		startstate(StateNormal);
		startaction(PriestPrayingIdle);

		//----------------------------------------------------
		// start of priest shoot FX
		//----------------------------------------------------
		if(vaction==PriestPrayingIdle)
		{
			spawnparticle(fx_windspecks,6,emptyvector,emptyvector,-1);
			spawnparticle(fx_windspecks,12,emptyvector,emptyvector,-1);
		}
			
		if(vaction==PriestAttackSequence&&vframe==105)
		{
			sample(SFXEvilLaugh,-1);
			sample(SFXPriestPower,-1);
			CutScene("second");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
		}

		if(vaction==PriestAttackSequence&&vframe<176&&vframe>105)
		{
			if(vrnd<50)
			{
				spawnparticle(fx_bazookatrail,6,emptyvector,emptyvector,fx_priestfx);
			}
			else
			{
				spawnparticle(fx_bazookatrail,12,emptyvector,emptyvector,fx_priestfx);
			}
		}
		if(vaction==PriestAttackSequence&&vframe<=417)
		{
			spawnparticle(fx_windspecks,6,emptyvector,emptyvector,-1);
			spawnparticle(fx_windspecks,12,emptyvector,emptyvector,-1);
		}
		if(vaction==PriestAttackSequence&&vframe==176)
		{
			CutScene("third");
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
			call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
			vector(_settoboneposrelative,TmpVector,6);
			spawnactorbone(BulletPriest,TmpVector,Gactorpos,Gactorine,0);
			vector(_settoboneposrelative,TmpVector,12);
			spawnactorbone(BulletPriest,TmpVector,Gactorpos,Gactorine,0);
			sample(SFXPriestFire,-1);
		}
		elseif(vaction==PriestAttackSequence&&vframe>=282&&vframe<417)
		{
			if(vrnd<50)
			{
				vector(_set,Gactorpos,-2555,603,7860);
				vector(_set,tmpvector,50,100,250);
				spawnlight(flash_light,6,emptyvector,tmpvector,EmptyVector,500);
				spawnlight(flash_light,12,emptyvector,tmpvector,EmptyVector,500);
			}
		}
		elseif(vaction==PriestAttackSequence&&vframe==417)
		{
			float(_set,timer,3);
		}
		elseif(vaction==PriestAttackSequence&&vframe==442)
		{
			sample(SFXManFallToGround,-1);
			call(ScreenShake,0,10,0,0.8);
		}
		elseif(vaction==PriestAttackSequence&&vframe==453)
		{
			sample(SFXManFallToGround,-1);
			call(ScreenShake,0,10,0,0.8);
		}
		elseif(vaction==PriestAttackSequence&&vframe==503)
		{
			sample(SFXManPunch,-1);
		}
		elseif(vaction==PriestAttackSequence && vframe==548)
		{
			sample(SFXPriestDrown,-1);
		}
		

		//----------------------------------------------------
		// end of priest shoot FX
		//----------------------------------------------------


		if(vtrigger==_DIRdepossesion)
		{
			callsub(Sub_InitDepossesion,PriestIdle,PriestIdle,PriestIdle);
		}
		elseif(vtrigger==_DIRpossesion)
		{
			SpawnAction(PriestIdle);
		}

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		float(_declare,TurnSpeed,0);
		callsub(Sub_TurnCharacter,TurnSpeed,PriestMaxTurnSpeed,PriestTurnAcc);

		if(vtrigger==_DIRforward)
		{
			move(0,0,-20);
		}
		elseif(vtrigger==_DIRbackward)
		{
			move(0,0,10);
		}

		CallSub(BackGroundTriggerChecks);
		//#include	"messiahscripts\enemies\copgen.hxx"
}


Actor(Scientist)
{
		file(ScientistHeader);
		rank(_RankPrivate);
		startstate(StateNormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(DeadScientist)
{
		file(ScientistHeader);
		rank(_RankPrivate);
		startstate(StateDead);
		startaction(CopStartDead);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

//		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(DeadScientistInMonitor)
{
		file(ScientistHeader);
		rank(_RankPrivate);
		startstate(StateDead);
		startaction(CopStartDeadInMonitor);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

//		#include	"messiahscripts\enemies\copgen.hxx"
}
