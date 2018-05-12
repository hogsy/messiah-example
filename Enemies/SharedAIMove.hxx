

SubRoutine(Sub_CivilianReactionToThreat)
{
		if(VRank<_RankPrivate && VAIClass!=_AIClassScientist)
		{
			CallSub(Sub_SetCoweringMode);
		}
		else
		{
			//run and press alarm button or other suitable action
			call(AIfindpathwithspecificstate,_AIstatePressAlarmButton);
			if(VTrigger==_DIRTempFlag)
			{
				//call(AIorder,_set,_AIstateRun);
				//State(_or,StateFollowPath);
				call(AIclrtarget);
				call(AIorder,_set,_AIstateRun);
				call(AIorder,_clr,_AInomove|_AInoturn);
				State(_clr,StateFollowPath);
				State(_or,StateExecutePathSequence);
			}
			else
			{
				CallSub(Sub_SetCoweringMode);
			}
		}
}

SubRoutine(Sub_AISetAttack)
{
		if(VAIhastarget!=0)
		{
			if(VAIclass!=_AIclassDroid && VAIClass!=_AIclassanimal)
			{
				if(VRank>=_RankSergeantL)
				{
					if(VAIState==_AIstateAttack && VState==StateFollowPath || VState==StateExecutePathSequence)
					{
						//to catch Attack state being set somewhere else
						state(_clr,StateExecutePathSequence);
						state(_change,StateFollowPath,StateNormal);
						call(ClrPath);
 						call(AIorder,_clr,_AIinspecialmode|_AInomove|_AIlockedtoactor|_AInoturn|_AIcloseupaction|_AIcombatmodereact|_AIstayonpath|_AIdontdopickdest);
						call(AIorder,_set,_AIstateAttack);
						actorflag(_clr,_AFLAGnomove);
						float(_set,CopActionBits,1);//since attack is initiated from many places, set initial attack flag
					}
					if(VAIState!=_AIstateAttack && VAIState!=_AIstateHide && VAIState!=_AIstateGuard && VAIstate!=_AIstateConfused && VAIstate!=_AIstateShutDown)
					{
						state(_clr,StateExecutePathSequence);
						state(_change,StateFollowPath,StateNormal);
						call(ClrPath);
 						call(AIorder,_clr,_AIinspecialmode|_AInomove|_AIlockedtoactor|_AInoturn|_AIcloseupaction|_AIcombatmodereact|_AIstayonpath|_AIdontdopickdest);
						call(AIorder,_set,_AIstateAttack);
						actorflag(_clr,_AFLAGnomove);
						float(_set,CopActionBits,1);//since attack is initiated from many places, set initial attack flag
						if(Vstate!=StateCrouching && VActorFlag!=_AFLAGattached && VAIClass!=_AIclassSatan && VAIClass!=_AIclassAngel)
						{
							spawnaction(CopReactionToAttack);
						}
					}
					elseif(VAIStateHigh==_AIstayonpath)
					{
						call(AIselecttarget,_AIenemy);
					}
					if(vstate==StateCrouching)
					{
						direction(_set,_DIRcrouch);
					}
				}
				else
				{
					CallSub(Sub_CivilianReactionToThreat);
				}
			}
			else
			{
				call(AIclrtarget);
			}
		}
}

SubRoutine(Sub_AIConfusedMode,float(AIAbility))
{
		print("My Abilities:   ",AIAbility);
}

SubRoutine(Sub_AIGetBackToIdle)
{
		call(AIorder,_clr,_AIinspecialmode|_AInomove|_AIlockedtoactor|_AInoturn|_AIstayonpath|_AIdontdopickdest|_AIcloseupaction|_AIcombatmodereact);
		call(AIorder,_set,_AIstatePatrol);
		ActorFlag(_clr,_AFLAGsniper);
		call(ClrPath);
		call(PickNewNode);
		call(AIclrtarget);
		State(_or,StateFollowPath);
		if(vstate==StateCrouching)
		{
			direction(_set,_DIRcrouch);
		}
}

SubRoutine(Sub_AISetCombatMode);
{
		if(vtrigger!=_DIRcombatmode)
		{
			direction(_set,_DIRcombatmode);
			float(_set,CopActionBits,2);//set initial combat flag
		}
}

SubRoutine(Sub_AIClrCombatMode);
{
		if(vtrigger==_DIRcombatmode)
		{
			direction(_clr,_DIRcombatmode);
		}
}

SubRoutine(Sub_SetCoweringMode)
{
		call(AIorder,_set,_AIstateCowering);
		call(AIorder,_set,_AIinspecialmode);
		call(ClrPath);
		call(AIclrtarget);
		if(vstate!=StateCrouching)
		{
			direction(_set,_DIRcrouch);
		}
}

Subroutine(Sub_ReactToBulletOrExplosion)
{
		if(VAIclass!=_AIclassDroid && VAIClass!=_AIclassanimal && VAIClass!=_AIclassEvil && VState!=StateCrawling)
		{
			sample(SFXExplosionReact,-1);
			if(VRank>=_RankSergeantL)
			{
				if(VAIState!=_AIstateAttack && VAIState!=_AIstateHide && VAIState!=_AIstateSearch)
				{
					call(AIcheckbulletorigin);
					if(vtrigger==_DIRTempFlag)
					{
						//printlog("Found target actor 666666666666666666666666666666666");
						call(AIchangefriendtoenemy);
						call(AIalert,Sub_AISetAttack);
						CallSub(Sub_AISetAttack);
					}
				}
			}
			else
			{
				callsub(Sub_CivilianReactionToThreat);
			}
		}
}

SubRoutine(Sub_AIShootCheck,const(Flag),float(CurrentDirection),float(Counter),float(AIGrenadeCounter),float(AIAbility))
{
	print("Shoot check: calling function");

		//check for firing!
		if(vstate!=StateBlind && vstate!=StateOnFire && vstate!=StateCrawling)
		{
			//if(AIGrenadeCounter!=0)
			//{
				float(_add,AIGrenadeCounter,1);
			//}
			//if(AIGrenadeCounter>100 || VTargetDistance>1500 && VInventoryLeft>0 && Counter<50 && vrnd<50)
	
			//print("AIGrenadeCounter:   ",AIGrenadeCounter);
			//print("Counter:            ",Counter);

			//if(AIGrenadeCounter>30 && VTargetDistance>1500 && VInventoryLeft>0 && Counter<50 && vrnd<50)

			if(AIGrenadeCounter<60)
			{
				Direction(_clr,_DIRMoveBits);
				float(_clr,CurrentDirection,_DIRMoveBits);
			}

			call(AInrfriendsinset,TmpFloat);
			if(TmpFloat==0 && AIAbility&!=_AIANoThrowGrenades && AIGrenadeCounter>150 && VTargetDistance>1000 && VTargetDistance<1500 && VInventoryLeft>0 && vrnd<50)
			{
				print("Shoot check: grenade check");
		//		if(VActorFlag==_AFLAGlogon)						//aim on?
		//		{
					call(AIchecklogtrajectory,600);					//no friends in path of bullet?
					if(vtrigger==_DIRTempFlag)
					{
						direction(_set,_DIRGrenade);
						float(_set,AIGrenadeCounter,0);
					}
		//		}
				if(vtrigger!=_DIRcrouch)
				{
					if(vaction==CopHideLeanLeftGrenade)
					{
						if(vframe==49)
						{
							callsub(Sub_SpawnGrenade);
							//float(_set,Counter,1000);		//to force retreat immediately after throwing grenade
							float(_set,AIGrenadeCounter,0);
						}
					}
					elseif(vaction==CopThrowGrenade)
					{
						if(vframe==10)
						{
							callsub(Sub_SpawnGrenade);
							//float(_set,Counter,1000);		//to force retreat immediately after throwing grenade
							float(_set,AIGrenadeCounter,0);
						}
					}
				}
				else
				{
					if(vaction==CopHideCrouchLeanLeftG)
					{
						if(vframe==28)
						{
							callsub(Sub_SpawnGrenade);
							//float(_set,Counter,1000);		//to force retreat immediately after throwing grenade
							float(_set,AIGrenadeCounter,0);
						}
					}
					elseif(vaction==CopHideCrouchLeanRightG)
					{
						if(vframe==28)
						{
							callsub(Sub_SpawnGrenade);
							//float(_set,Counter,1000);		//to force retreat immediately after throwing grenade
							float(_set,AIGrenadeCounter,0);
						}
					}
				}
			}
			elseif(vtrigger==_DIRhavegun)						//have gun?
			{
	printi("Shoot check: has gun      ",VActorFlag);

				if(VActorFlag==_AFLAGlogon)						//aim on?
				{
					//print("Log on   ");
	print("Shoot check: has lock      ");
					call(AIchecklogtrajectory,0);					//no friends in path of bullet?
					if(vtrigger==_DIRTempFlag || VTargetDistance<150 && VAITargetFound==_AIenemy)
					{
						print("Clear path Shooting 111111111111111111111111111111111");
						Direction(_set,_DIRshoot);				//fire
						//float(_set,Counter,1000);		//to force retreat immediately after shooting
					}
				}
			}

		}
}

SubRoutine(Sub_AIHandleWallCollision,float(CurrentDirection))
{
		//printi("Numberframesagainstwall:    ",VAIQnumberframesagainstwall);
		if(VTrigger==_DIRvercol || VAIQnumberframesagainstwall>30)
		{
			call(AIQrunningagainstwall,10);
			if(VAIQnumberframesagainstwall>150 && VAItargetvisible==0)
			{
				callsub(Sub_AIGetBackToIdle);
			}
			elseif(VAIQnumberframesagainstwall>30)
			{
				//clr direction flags
				//print("Clearing the move bits.................");
				Direction(_clr,_DIRMoveBits);
				float(_clr,CurrentDirection,_DIRMoveBits);

				//do collision
				SphereCollision(0,0,0, 0,0,-30);
				if(vcolflag!=_DIRvercol)
				{
					//print("No collision. Exiting hit wall code!!!!!!!!!!!");
					call(AIsetnumberframesagainstwall,0);
				}
				elseif(VAItargetvisible!=0)
				{
					//make sure we don't expire when enemy is in plain view
					call(AIsetnumberframesagainstwall,40);
				}
			}
		}
		else
		{
		}
}

SubRoutine(Sub_AI1WayAlignToTarget)
{
/*		if(VTargetAngle<-1200 || VTargetAngle>1200 && VClass==_ClassCop)
		{
			if(vstate==StateCrouching)
			{
				if(VAction!=CopCrouch180)
				{
					SpawnAction(CopCrouch180);
					//break();
				}
			}
			else
			{
				if(VAction!=Cop180)
				{
					SpawnAction(Cop180);
				}
			}
		}
		elseif(VTargetAngle<-20)
*/
		if(VTargetAngle<-30)
		{
			if(VTargetAngle<-220)
			{
				Direction(_set,_DIRleft);
			}
			else
			{
				turn(0,-19,0);
			}
		}
		elseif(VTargetAngle>30)
		{
			if(VTargetAngle>2000)
			{
				if(VTargetAngle<-220)
				{
					Direction(_set,_DIRleft);
				}
				else
				{
					turn(0,-19,0);
				}
			}
			else
			{
				if(VTargetAngle>220)
				{
					Direction(_set,_DIRright);
				}
				else
				{
					turn(0,19,0);
				}
			}
		}
}

SubRoutine(Sub_AI1WayAlignToPickDestAngle)
{
		if(vpickdestanglecorr<-30)
		{
			if(vpickdestanglecorr<-220)
			{
				Direction(_set,_DIRleft);
			}
			else
			{
				turn(0,-19,0);
			}
		}
		elseif(vpickdestanglecorr>30)
		{
			if(vpickdestanglecorr>220)
			{
				Direction(_set,_DIRright);
			}
			else
			{
				turn(0,19,0);
			}
		}
}

SubRoutine(Sub_AI2WayAlignToPickDestAngle)
{
		if(vpickdestanglecorr<-30 && vpickdestanglecorr>=-1024)
		{
			if(vpickdestanglecorr<-220)
			{
				Direction(_set,_DIRleft);
			}
			else
			{
				turn(0,-19,0);
			}
		}
		elseif(vpickdestanglecorr<-1024 && vpickdestanglecorr>-2028)
		{
			if(vpickdestanglecorr>-1220)
			{
				Direction(_set,_DIRright);
			}
			else
			{
				turn(0,19,0);
			}
		}
		elseif(vpickdestanglecorr>30 && vpickdestanglecorr<=1024)
		{
			if(vpickdestanglecorr>220)
			{
				Direction(_set,_DIRright);
			}
			else
			{
				turn(0,19,0);
			}
		}
		elseif(vpickdestanglecorr>1024 && vpickdestanglecorr<2028)
		{
			if(vpickdestanglecorr>1200)
			{
				Direction(_set,_DIRleft);
			}
			else
			{
				turn(0,-19,0);
			}
		}
}

SubRoutine(Sub_AI8WayMoveWalk,float(CurrentDirection))
{
		if(vpickdestanglecorr>-256 && vpickdestanglecorr<256)
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRforward);
		}
		elseif(vpickdestanglecorr>-768 && vpickdestanglecorr<-256)
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRforward|_DIRsideleft);
		}
		elseif(vpickdestanglecorr>256 && vpickdestanglecorr<768)
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRforward|_DIRsideright);
		}
		elseif(vpickdestanglecorr>-1280 && vpickdestanglecorr<-768)
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRsideleft);
		}
		elseif(vpickdestanglecorr>768 && vpickdestanglecorr<1280)
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRsideright);
		}
		elseif(vpickdestanglecorr>-1792 && vpickdestanglecorr<-1280)
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRbackward|_DIRsideleft);
		}
		elseif(vpickdestanglecorr>1280 && vpickdestanglecorr<1792)
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRbackward|_DIRsideright);
		}
		else
		{
			float(_set,CurrentDirection,_DIRwalking|_DIRbackward);
		}
}

SubRoutine(Sub_AI8WayMoveRun,float(CurrentDirection))
{
		float(_set,CurrentDirection,_DIRwalking);

		if(vpickdestanglecorr>-256 && vpickdestanglecorr<256)
		{
			float(_set,CurrentDirection,_DIRforward);
		}
		elseif(vpickdestanglecorr>-768 && vpickdestanglecorr<-256)
		{
			float(_set,CurrentDirection,_DIRforward|_DIRsideleft);
		}
		elseif(vpickdestanglecorr>256 && vpickdestanglecorr<768)
		{
			float(_set,CurrentDirection,_DIRforward|_DIRsideright);
		}
		elseif(vpickdestanglecorr>-1280 && vpickdestanglecorr<-768)
		{
			float(_set,CurrentDirection,_DIRsideleft);
		}
		elseif(vpickdestanglecorr>768 && vpickdestanglecorr<1280)
		{
			float(_set,CurrentDirection,_DIRsideright);
		}
		elseif(vpickdestanglecorr>-1792 && vpickdestanglecorr<-1280)
		{
			float(_set,CurrentDirection,_DIRbackward|_DIRsideleft);
		}
		elseif(vpickdestanglecorr>1280 && vpickdestanglecorr<1792)
		{
			float(_set,CurrentDirection,_DIRbackward|_DIRsideright);
		}
		else
		{
			float(_set,CurrentDirection,_DIRbackward);
		}
}


