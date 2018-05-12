
Actor(WorkerOnBench)
{
		file(WorkerHeader);
		//rank(_RankSergeantH);
		rank(_RankScum);
		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnolinkup);

		startstate(StateNormal);
		startaction(workerweldingonbench);

		float(_declare,WelderCrushTime,450);

//		sample(SFXWelderWhistle,-1);

		if(VTrigger==_DIRalive)
		{
			if(VTrigger==_DIRactorbulletcol)
			{
				Direction(_clr,_DIRalive);
				State(_or,StateDead);
				call(SubtractHealth,0,30000);
				SpawnAction(WorkerShotOnBench);

				call(AIcheckbulletorigin);
				if(vtrigger==_DIRTempFlag)
				{
					//turn player one into enemy
					call(AIchangefriendtoenemy);
					call(AIalert,Sub_AISetAttack);
					CallSub(Sub_AISetAttack);
				}
			}
//			WorkerCowerOnBench


			if(vaction==WorkerCrushedOnBench)
			{
				call(CheckAttached,_CANormal);

				if(vframe>=55&&vframe<=75)
				{
					float(_set,WelderCrushTime,0);

					vector(_set,gactorpos,0,-100,30);
					spawnparticle(fx_bloodspurt,0,gactorpos,emptyvector,-1);
				}

				//if(VFrame>=200)
				//{
	//				direction(_clr,_DIRShoot);
	//				call(CheckAttached,_CADropWeapon);
				//}
			}
			else
			{
				if(Vaction!=WorkerShotOnBench)
				{
					if(vtrigger!=_DIRhavegun && VState!=StateDead)
					{
						call(CheckForPickup,12,_ClassWeapon);
					}

					direction(_or,_DIRShoot);
					call(CheckAttached,_CANormal);
				}
			}

			if(WelderCrushTime<150)
			{
				if(WelderCrushTime==1)
				{
					sample(SFXWorkerCrushed,-1);
				}

				if(vrnd<15)
				{
					vector(_set,gactorpos,0,-100,30);
					spawnparticle(fx_blood,0,gactorpos,emptyvector,-1);
					spawnparticle(fx_blood,0,gactorpos,emptyvector,-1);
					spawnparticle(fx_bloodspray,0,gactorpos,emptyvector,-1);
				}
				float(_add,WelderCrushTime,1);
			}

			//#include	"messiahscripts\enemies\copgen.hxx"
			callsub(BackGroundTriggerChecks);
		}
		else
		{
			call(CheckAttached,_CADropWeaponAndShells);
		}


}

Actor(WorkerKneelWelding)
{
	file(WorkerKneelHeader);
	rank(_RankScum);
	ActorFlag(_or,_AFLAGnopossesion);
	ActorFlag(_or,_AFLAGnotarget);
	startstate(StateNormal);
	startaction(WorkerWeldingKneel);

	//sample(SFXWelderWhistle,-1);

	if(Vaction==WorkerKneelCrush)
	{	
		if(VFrame==5)
		{
			sample(SFXWorkerWhatThe,-1);
		}
		if(VFrame<=50)
		{
			direction(_or,_DIRShoot);
		}

		if(Vframe==50)
		{
			vector(_set,Gactorpos,0,50,0)
			spawnparticle(fx_smallexplosion,12,gactorpos,emptyvector,fx_antirotate8); //12 should be right hand
			sample(SFXBazookaExplode,-1);
		}
		if(VFrame==73)
		{
			sample(SFXWorkerOhShit,-1);
		}
	}
	else
	{
		if(vtrigger!=_DIRhavegun && VState!=StateDead)
		{
			call(CheckForPickup,12,_ClassWeapon);
		}
		else
		{
			/*
			if(Vaction==WorkerWeldingKneel || Vaction==WorkerWelding)
			{
				direction(_or,_DIRShoot);
			}
			*/
		}			
		call(CheckAttached,_CANormal);
	}
	callsub(BackGroundTriggerChecks);
}

Actor(Worker)
{
		file(WorkerHeader);
		//rank(_RankSergeantH);
		rank(_RankPrivate);

		startstate(StateNormal);
		//startaction(WorkerWelding0);
		startaction(copidleNoGun);

/*
		if(vtrigger!=_DIRhavegun)
		{
			direction(_set,_DIRaction);
		}

		float(_declare,weldingshoot,0);
		if(weldingshoot==1)
		{
			direction(_set,_DIRshoot);
		}
		else
		{
			direction(_clr,_DIRshoot);
		}

		if(vAICon==0)
		{
			direction(_clr,_DIRshoot);
		}
*/

///////
///////
///////
		if(vaicon==0)
		{
			call(AIcheckforonpath,10);
		}
		

/*		float(_declare,Count,0);
		if(vaistate!=_AIstateWork && vaistate!=_AIstateWorkWeld)
		{
			float(_add,Count,1);
			if(Count>150)
			{
				break();
			}
		}
		else
		{
			float(_set,Count,0);
		}
*/

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"


///////
///////
///////

	/*
		if(vAICon!=0)
		{
			if(vtrigger==_DIRhavegun)
			{
				float(_declare,weldcount,0);
				if(weldcount==0)
				{
					//force anim at first
					if(vaction!=WorkerWelding0)
					{
						spawnaction(WorkerWelding0);
						float(_set,weldingshoot,1);
					}
				}
				float(_set,weldcount,1);

				//random anims of welding
				if(vendofanim!=0)
				{
					if(vrnd<12)
					{
						if(vaction!=WorkerWelding1)
						{
							float(_set,weldingshoot,0);
							spawnaction(WorkerWelding1);

							sample(SFXweapontorch1,-1);
						}
					}
					elseif(vrnd<12)
					{
						if(vaction!=WorkerWelding2)
						{
							float(_set,weldingshoot,0);
							spawnaction(WorkerWelding2);
						}
					}
					else
					{
						if(vaction!=WorkerWelding0)
						{
							float(_set,weldingshoot,1);
							spawnaction(WorkerWelding0);
						}
					}
				}
			}

			float(_declare,assface,0);
			if(assface==20)
			{
				spawnactor(WeaponTorch,0,100,-50);
			}
			float(_add,assface,1);
		}
	*/

		if(VTrigger==_DIRactionhold || VTrigger==_DIRaction)
		{
			Collision(0,0,0,0,0,-50);
			if(VColMaterialProperties==_MATPush)
			{
				call(MoveBackgroundObject);
				float(_set,WorkerPushingObject,1);
			}
			
		}
		else
		{
			float(_set,WorkerPushingObject,0);
		}
}

Actor(RadiationWorker)
{
		file(RadiationWorkerHeader);
		rank(_RankScum);

		startstate(StateNormal);
		startaction(copidleNoGun);

		if(vaicon==0)
		{
			call(AIcheckforonpath,10);
		}
		else
		{
			if(VTrigger==_DIRhavegun && VWeaponAmmoType==_AmmoBattery)
			{
			
				if(VWeaponAmmoLeft==1)
				{
					if(Vtrigger!=_DIRcombatmode)
					{
						direction(_set,_DIRCombatmode);
					}
				}
				if(VAction==NukeBatteryDrop)
				{
					if(VWeaponAmmoLeft==1)
					{
						if(Vframe==15) 
						{
							call(DontBlowBattery);
							call(CheckAttached,_CADropBattery);
							float(_set,VarKey2,2);
						}
					}
				}
				if(VAction==NukeBatteryPick)
				{
					if(VWeaponAmmoLeft==0)
					{
						if(VFrame==15)
						{
							call(CheckForPickup,12,_ClassPickup|_ClassBullet);
						}
					}
				}
			}
		}		

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


Actor(Welder)
{
		file(WelderHeader);
		rank(_RankScum);

		startstate(StateNormal);
		startaction(copidleNoGun);

		if(vaicon==0)
		{
			call(AIcheckforonpath,10);
		}

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


Actor(Worker2)
{
		file(Worker2Header);
		rank(_RankScum);

		startstate(StateNormal);
		startaction(copidleNoGun);

		if(vaicon==0)
		{
			call(AIcheckforonpath,10);
		}

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
