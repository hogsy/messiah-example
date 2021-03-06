//armored beast

		float(_declare,heavylandfx,0);
		float(_declare,heavylandfx2,0);

		float(_declare,ShootDelayCounter,10000)
		float(_declare,JumpIdleCounter,0);
		float(_declare,JumpPressCounter,0);
		float(_declare,DownwardPull,0);
		float(_declare,TurnSpeed,0);
		float(_declare,ColAngleCorrectNeeded,0);
		float(_declare,ForceRunFrames,0);
		float(_declare,AirSpeedForward,0);
		float(_declare,AirSpeedSideways,0);
		float(_declare,FallStartAltitude,0);
		float(_declare,SmokeCount,1000);
		float(_declare,FireCount,0);
		float(_declare,ActionOK,1);
		float(_declare,Hanging,0);
		float(_declare,DropDelay,100);

		float(_declare,ActorFireType,0);
		float(_declare,ActorFireLife,255);
		float(_declare,ActorFireCount,0);
		float(_declare,ActorSmokeCount,0);

		float(_declare,HitByFireCount,0);

//keep start
		if(VActiveTime==0)
		{
			call(AttachToActor,WeaponAbeastMachineGun,8);
			Direction(_or,_DIRhavegun|_DIRcombatmode);
		}
//keep stop


		//print("Turnspeed:   ",turnspeed);

		if(vtrigger==_DIRaction)
		{
			vector(_declare,bbbcolor,200,200,255);
			vector(_declare,bbbvec,0,0,1);
			//SpawnLight(Lomnilight2,0,EmptyVector,bbbcolor,EmptyVector,250);
			//SpawnLight(Lplanelight,0,EmptyVector,bbbcolor,bbbvec,650);
		}

		//printi("State:  ",vstate);
		if(VState==StateDead)
		{
			Direction(_clr,_DIRaiRemoveFlags);
		}
		elseif(vAICon!=0)
		{
// **************************************************************************
// **************************************************************************
// **************************************************************************
/*
				//AIPickDest(100,1);

				Direction(_clr,_DIRaiRemoveFlags)

				if(VTrigger!=_DIRHaveGun)
				{
					call(IsPickupClose,_ClassWeapon);	
					if(vtrigger==_DIRTempFlag)
					{
						Direction(_set,_DIRaction);
						//float(_set,ActionOK,1);
						//direction(_clr,_DIRactionhold);
					}
				}

				float(_declare,shootcounter,0);
				if(vlockedondistance>30 && vaistate!=_AIstateIdle && 1==2)
				{
					print("Checking for movement");
					if(vtargetdistance>600 && vaistate==_AIstateAttack)
					{
						if(vlockedonangle<-20)
						{
							//turn(0,-19,0);
							Direction(_set,_DIRleft);
						}
						elseif(vlockedonangle>20)
						{
							//turn(0,19,0);
							Direction(_set,_DIRright);
						}
						//if(vlockedonangle<50 && vlockedonangle>-50)
						//{
							if(vlockedonangle<=20 && vlockedonangle>=-20)
							{
								Direction(_set,_dirrun);
								if(vstate==statenormal && vtargetdistance>1000 && vtargetdistance<1500 && vaction!=ABeastThrowGrenade && vrnd<5)
								{
					//				Direction(_set,_DIRGrenade);
								}
							}
						//}
					}
					else
					{
						if(vtargetdistance>100)
						{
							if(vlockedonangle<-20)
							{
								//turn(0,-19,0);
								Direction(_set,_DIRleft);
							}
							elseif(vlockedonangle>20)
							{
								//turn(0,19,0);
								Direction(_set,_DIRright);
							}
							if(vlockedonangle<90 && vlockedonangle>-90)
							{
								//if(vlockedondistance<300)
								if(vtrigger==_DIRhavegun)
								{
									if(vrnd<10 || shootcounter!=0)
									{
										Direction(_set,_DIRshoot);
										float(_add,shootcounter,1);
										if(shootcounter>60)
										{
											Direction(_clr,_DIRshoot);
											float(_set,shootcounter,0);
										}
									}
								}
								else
								{
									Direction(_clr,_DIRshoot);
								}
						print("Walk");
								Direction(_set,_dirwalk);
							}
						}
						else
						{
							printi("aligning to node angle",vtargetangle);
							if(vtargetangle<-20)
							{
								//turn(0,-19,0);
								Direction(_set,_DIRleft);
							}
							elseif(vtargetangle>20)
							{
								//turn(0,19,0);
								Direction(_set,_DIRright);
							}
						}
					}

				}

				if(vtrigger==_DIRvercol && vstate!=StateJump)
				{
					Collision(0,-20,0, 0,-20,-130);
					if(vcolflag==_DIRvercol)
					{
						Collision(0,60,0, 0,60,-130);
						if(vcolflag!=_DIRvercol)
						{
							Direction(_set,_DIRjump);
						}
					}
				}
				elseif(vstate==StateJump)
				{
					Direction(_set,_DIRjump);
				}

				if(VTrigger|=_DIRMoveBits)
				{
					Direction(_set,_DIRMove)
				}

// **************************************************************************
// **************************************************************************
// **************************************************************************
*/
		}
		else
		{
//Player control
			call(AIupdateAIvars);			//to update aicounters like TimeNotTarget
			call(AIcheckfortarget,10);		//for LineOfSight reasons etc. this is called for player character also

			if(vtrigger==_DIRpossesion)
			{
				float(_set,PlayerHeadBone,4);
				callsub(Sub_InitPossesion,ABeastPossesed);
			}
			elseif(vtrigger==_DIRdepossesion)
			{
				callsub(Sub_InitDepossesion,ABeastDepossesed)
			}
		}



		if(vstate!=StateDead)
		{
			callSub(Sub_ActionKeyHandler,ActionOK);
			if(vstate==StateNormal && vtrigger!=_DIRhavegun)
			{
				callSub(Sub_CheckActionPickup,ABeastPickup,14,0,0);
				callsub(BackGroundTriggerChecks);
			}
			else
			{
				callsub(BackGroundTriggerChecks);
				if(vstate==StateNormal)
				{
					callSub(Sub_CheckActionDrop,ABeastPickup,14,0,0,DropDelay,AIAbility);
				}
			}
			if (vtrigger!=_DIRhavegun)
			{
				callSub(Sub_CheckRemainingActions,ABeastPressGun,22);
			}
			else
			{
				callSub(Sub_CheckRemainingActions,ABeastPressGun,22);
			}

			callsub(Sub_Headtrack);					//Track head against object

	state(_clr,StateThrown);	//XXX Oh, ohhh. Very illegal, but I don't want to deal with thrown for beasts right now, thank you.

			//if in the electric shock animations do not check for fall, it's done for you!!
			if(VState!=StateElectricShock && VState!=StateThrown)
			{
				CallSub(Sub_CheckFallDamage,ABeastTouchDown,FallStartAltitude,ABeastMaxFall,DamageABeastFall,ABeastFallDead,0,ABeastFallInplace);

///////////////
///////////////
				if(vaction!=ABeastTouchDown)
				{
					float(_set,heavylandfx,0);
					float(_set,heavylandfx2,0);
				}
				if(vaction==ABeastTouchDown && heavylandfx==0 && heavylandfx2<=9)
				{
					if(heavylandfx2==0)
					{
						call(ScreenShake,0,24,0,0.5);
					}

					vector(_set,fxvector,0,-200,0);
					call(SetParticleSetID);
					callsub(sub_shockwave,BulletShockWave,0);
				}

				if(vaction==ABeastTouchDown)
				{
					if(heavylandfx>=3)
					{
						float(_set,heavylandfx,0);
					}
					else
					{
						float(_add,heavylandfx,1);
					}
					float(_add,heavylandfx2,1);

				}
///////////////
///////////////

			}
		}
		callsub(Sub_CheckHit,ABeastWoundLight,ABeastWoundLight,ABeastWoundLightNoBreak,FireCount,ABeastPoleDead,ABeastWoundLight,0,0,0,0,HitByFireCount);

		if(vstate==StateOnFire)	//These first if-statements are just for effects
		{
			float(_set,ActorFireType,0);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorFireEffect,SmokeCount,FireCount,ActorFireLife,ActorFireType,ActorFireCount)
		}
		elseif(vstate==StateBlind)
		{
			if(SmokeCount==0)
			{
				sample(SFXcough7,-1);
			}
			float(_set,ActorFireType,0);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorSmokeEffect,SmokeCount,ActorFireLife,ActorFireType,ActorSmokeCount)
		}

		call(CheckAttached,_CANormal);

		if(VAction!=ABeastBurningRunInCircle&&VAction!=ABeastBurningRollOnFloor&&VAction!=ABeastSlowGetUpFace)	//It would look bad if he died while in one of these animations
		{
//The last number here is used if they have to fall on their knees when energy is low
			callsub(Sub_CheckDeadOrDying,ABeastPoleDead,ABeastCrawlDead,ABeastStandDead,ABeastCrawlSpreadOut,0,ABeastFallToCrawl,ABeastStandDead,ABeastStandDead);	//0=health when entering crawling-mode

			if(vaction==ABeastStandDead||vaction==ABeastFallDead)
			{
				if(vframe==75)
				{
					call(ScreenShake,0,24,0,0.5);
				}
			}
		}


		if(vstate==StateExecuteAnim)
		{
//keep start
			if(vaction==ABeastThrowGrenade2)
			{
				if(vendofanim!=0)
				{
					callsub(Sub_SpawnGrenade);
				}
				callsub(Sub_TurnCharacter,TurnSpeed,ABeastMaxTurnSpeed,ABeastTurnAcc);
			}
//keep stop
			elseif(vaction==ABeastPossesed)
			{
				callsub(Sub_TurnCharacter,TurnSpeed,ABeastMaxTurnSpeed,ABeastTurnAcc);
			}
			elseif(vaction==ABeastPickup)
			{
			  //callSub(Sub_CheckActionButton,ABeastPickup,14)
			}
//ABeastClimbUp, ABeastDepossesed, ABeastPickup/Throw weapon,
			callsub(Sub_CheckExecuteAnimEnd)
		}
		elseif(vstate==StateDead||vstate==StateCrawling||vstate==StateBlind||vstate==StateOnFire||vstate==StateSteamed||vstate==StateHarpooned||vstate==StateElectricShock)
		{
			if(VState!=StateDead)
			{
				if(vstate==StateHarpooned)	//Here are the if-statements that control the actions when you are badly wounded
				{
					callsub(Sub_Harpooned,ABeastOnPole,ABeastOnPole,ABeastOnPole,ABeastOnPole,ABeastOnPole,ABeastOnPole,0,0);
				}
				else
				{
					callsub(Sub_TurnCharacter,TurnSpeed,ABeastMaxTurnSpeedWounded,ABeastTurnAccWounded);
					if(vstate==StateCrawling)
					{
//	is this where he has to roll over and hug his knees, and scream if you force him to move?
//
						callsub(Sub_Crawling,ABeastCrawlSpreadOut,ABeastFallToCrawl)
					}
					elseif(vstate==StateOnFire||vstate==StateSteamed||vstate==StateBlind)
					{
						float(_declare,SteamScreamCounter,0);
						callsub(Sub_BurnedSteamedBlind,ABeastBurningRollOnFloor,ABeastBurnedIdle,ABeastGettingBurned,ABeastBlindForward,ABeastBlindBackwards,ABeastBurningRunInCircle,ABeastSlowGetUpFace,SteamScreamCounter)
					}
					elseif(vstate==StateElectricShock)
					{
						callsub(Sub_ElectricShock,ABeastelectricshock0,ABeastelectricshock1);

						if(vaction==Abeastelectricshock0)
						{
							if(vframe==1)
							{
								sample(SFXElectricShock1,-1);
								call(SubtractHealth,0,DamageElectric);
							}
						}
						elseif(vaction==Abeastelectricshock1)
						{
							if(vendofanim!=0)
							{
								sample(SFXElectricShock2,-1);

								call(PlaneTriggerQuadrant,TmpFloat,1);
								if(TmpFloat==0)
								{
									spawnaction(ABeastThrownForward);
									move(0,0,-150);
								}
								elseif(TmpFloat==1)
								{
									spawnaction(ABeastThrownLeft);
									move(150,0,0);
								}
								elseif(TmpFloat==2)
								{
									spawnaction(ABeastThrownBack);
									move(0,0,150);
								}
								elseif(TmpFloat==3)
								{
									spawnaction(ABeastThrownRight);
									move(-150,0,0);
								}
								state(_change,StateElectricShock,StateThrown);
							}
						}
					}
				}
			}
		}
		else
		{
			CallSub(Sub_CheckClimbUp,ABeastClimbUp,60,ColAngleCorrectNeeded,20,-10)
			if(vstate==StateNormal)
			{
				callsub(sub_AlignToWallAndCheckRunUpStairs,ABeastRunUpStairs,ABeastIdle,ABeastIdleHitWall,ColAngleCorrectNeeded,ABeastIdleHitWallFront,ABeastHitWallSpreadOut,-0.95,ABeastSpreadOut,ABeastSpreadOut,ForceRunFrames)
				callsub(Sub_CheckForIdleLongTime,ABeastIdle,ABeastIdleLongTime);

				if(vendofanim!=0)
				{
					if(vaction==ABeastTouchDown)
					{
						spawnaction(ABeastIdle);
					}
				}

//keep start
				if(VTrigger==_DIRGrenade&&VInventoryLeft>0)
				{
					state(_or,StateExecuteAnim);
					spawnaction(ABeastThrowGrenade);
				}
//keep stop

/*				if(VAction==ABeastStandShoot && VFrame==0)
				{
					vector(_set,TmpVector,0,0,0);
					spawnactorbone(BulletMachineGun,TmpVector,Gactorpos,Gactorine,8);
				}
*/
				CallSub(Sub_CheckJumpFallDown,AIAbility,ABeastRunUpStairs,JumpPressCounter,DownwardPull,ABeastJumpSpeed,ABeastJump,AirSpeedForward,AirSpeedSideways,ABeastFall,ABeastAirSpeed)
				//callSub(Sub_CheckActionButton,ABeastPickup,14)
				callsub(Sub_TurnCharacter,TurnSpeed,ABeastMaxTurnSpeed,ABeastTurnAcc);
			}
			elseif(vstate==StateFalling||vstate==StateJump)
			{
				if(vstate==StateJump)
				{
					CallSub(Sub_Jump,JumpPressCounter,DownwardPull,15,ABeastJumpGravity,2,0)
				}
				callsub(Sub_TurnCharacter,TurnSpeed,ABeastMaxTurnSpeedAir,ABeastTurnAccAir);
				callsub(Sub_MoveInAir,AirSpeedSideways,AirSpeedForward,ABeastAirSpeed,ABeastAirBulb);
			}
		}
		//armored beast doesn't need to do this
		//callsub(FireWeaponsAndCheckAttached,ShootDelayCounter,8,ABeastHeavyRecoil,ABeastLightRecoil,0,0);


/*

Mangler:

-		Position control for formations



VAIleader							X	X
VAIgroupstate						X	X
VAItargetfound						X	X
VAInringroup						X	X
VAIingroup							X	X
VAIaskedtojoin						X	X
VAIstate							X	X
VAInotargettime						X	X
VAIgrouphealth						X	X
VAItimeincurrentorder				X	X
VAIlasttargetfound					X	X
VAIgroupleft						X	X
VAIhealth							X	X
VAIchangetonewgroup					X
VAIpowerrating			
VAIrebel				
VAIleaderaspirations

Functions:
AIasktojoin(groupstate);			X	X
AIcheckfortarget()					X	X
AIreleasegroup()					X	X
AIbreakfromgroup()					X	X
AIjoinnewgroup()					X	X
AIorder(groupstate)					X	X
AIpickdest(range,frequency)			X
*/

	if(vaicon!=0)
	{
		call(AIupdateAIvars);
		printi("curstate  ",vstate);
		if(vstate==StateFollowPath)
		{
			print("Follow path mode");
			call(AIPickdest);		//follow path
			if(vtrigger==_DIRtempflag)
			{
				call(PickNewNode);
			}
		}
		elseif(vstate==StateExecutePathSequence)
		{
			print("Executing path sequence");
			call(AIPickdest);		//follow path
			if(vtrigger==_DIRtempflag)
			{
				print("End of path");
				state(_clr,StateExecutePathSequence);
				state(_or,StateFollowPath);
				call(PickNewNode);
			}
			//check for end of path
			call(AIorder,_AIstateWork);
		}
		elseif(VAIleader!=0)			//in charge
		{
//			print("Im the leader....");
			call(AIcheckfortarget);

			if(VAIgroupstate!=_AIstateidle && VAIgroupstate!=_AIstatesearch)			//search should be widened to account for all attackstates
			{
				call(AIPickdest);
//				printi("In attack....",VAInotargettime);
				if(VAInotargettime<AINOTARGETTHRESHOLD)
				{
//					print("Persuing enemy...");
					call(AIasktojoin,_AIstateAttack);			//to make sure newcomers are asked to join for battle
					if(VAItargetfound!=_AIenemy && VAInotargettime<AINOTARGETSEARCHTHRESHOLD)
					{
						call(AIorder,_AIstateSearch);
//						sample(SFXOrderSearch,-1);
					}
/*					elseif(VAIgrouphealth<50)
					{
						call(AIorder,_AIstateretreat);
					}
					elseif(VAIpowerrating>80)		//0=no chance 50=neutral 100=superior
					{
						call(AIorder,_AIstatesurround);
					}
					elseif(VAIpowerrating<30)		//0=no chance 50=neutral 100=superior
					{
						call(AIorder,_AIstatespreadout);
					}
					elseif(VAIpowerrating<15)
					{
						call(AIorder,_AIstatehide);
					}
					elseif(VAIgroupleft<70 || VAItimeincurrentorder>AIINORDERREGROUPTHRESHOLD)			//percentage left of original group
					{
						call(AIorder,_AIstateregroup);
					}
					else
					{
						call(AIorder,_AIstateattack);
					}
*/
					if(Vaistate==_AIstateattack)
					{
						print("Im leading an attack");
					}
					call(AIgrouppickdest);
				}
			}
			else
			{
				print("No enemy in sight....");
				if(VAItargetfound==_AIenemy)		//just saw enemy
				{
		//			print("I saw you. Changing to attack mode");
					call(AIselecttarget,_AIenemy);
					call(AIorder,_AIstateAttack);
//					sample(SFXOrderGetHim,-1);
				}
				elseif(VAIlasttargetfound|=_AIenemy)			//continue searching
				{
		//			print("But there used to be....");
					if(VAInotargettime>AISTOPIFNOTARGETTHRESHOLD)		//check for release group
					{
						call(AIorder,_AIstateAtEase);
						call(AIreleasegroup);
						sample(SFXSSGirlAhBaNine,-1);
					}
					else
					{
		//				print("So search for him....");
						if(vaistate!=_AIstatesearch)
						{
							call(AIorder,_AIstateSearch);
//							sample(SFXOrderSearch,-1);
						}
					}
				}
				else									//nothing in sight. no present search
				{
					//idle formations here
		//			print("Leader in idle formation");
					call(AIasktojoin,_AIstateIdle);			//join the idle formation
					if(VAInringroup<5)
					{
						//special formation here
					}

				}
			}
		}
		elseif(VAIingroup!=0)		//included in group
		{
//			print("Im assigned to a group....");

			//call(AIcheckfortarget);

			if(VAIstatechanged!=0)
			{
				sample(SFXOrderYesSir1,-1);
			}

			if(VAIaskedtojoin!=0)
			{
//				printi("And im asked to leave",VAIchangetonewgroup);
				if(VAIchangetonewgroup!=0)
				{
					call(AIbreakfromgroup);
					call(AIjoinnewgroup);
				}
			}
			call(AIPickdest);


		//	if(Vaistate==_AIattack)
		//	{
		//		print("And in the middle of an attack........");
		//	}

/*			if(VAIrebel!=0)			//want out? (friendly fire, health, members dies, ammunition etc)
			{
				break();
				call(AIbreakfromgroup);
				if(VAItargetfound==_AIenemy)			//in the middle of battle?
				{
					if(VAIhealth<10)
					{
						call(AIorder,_AIstateflee);
						call(AIasktojoin,_AIRetreat);
					}
					elseif(VAIhealth>90)
					{
						call(AIorder,_AIstateAttack);
						call(AIasktojoin,_AIAttack);
					}
					else
					{
						call(AIorder,_AIstateHide);
						call(AIasktojoin,_AIRetreat);
					}
				}
				else
				{
					call(AIorder,_AIstateIdle);
				}
			}
			elseif(VAIaskedtojoin!=0)
			{
				if(VAIchangetonewgroup!=0)
				{
					break();
					call(AIbreakfromgroup);
					call(AIjoinnewgroup);
				}
			}
			else
			{
				call(AIpickdest,100,1);		//execute order
				if(VAIstate==_AISearch)
				{
					call(AIcheckfortarget);
					if(VAItargetfound==_AIenemy)
					{
						call(AIorder,_AIstateattention);
					}
				}
			}
*/
		}
		else
		{
			call(AIcheckfortarget);

			print("Im by my self");

			if(VAIaskedtojoin!=0)
			{
				print("I was asked to join");
				if(VAIchangetonewgroup!=0)
				{
					print("I joined");
					call(AIjoinnewgroup);
					sample(SFXOrderYesSir1,-1);

					//	spawn respond to attention
					//	then go into idle...
					//
//					if(VClass==ABeastl)
//					{
						state(_or,StateExecuteAnim);
						spawnaction(ABeastAttention);
//					}
				}
				else
				{
					printi("LeaderAspiration: ",VAIleaderaspirations);
					if(VAIleaderaspirations!=0)
					{
						printi("Ask to join new group");
						call(AIasktojoin,_AIstateAttack);
						call(AIorder,_AIstateattack);
						//sample(SFXOrderGetHim,-1);
					}
				}
			}
			else
			{
				print("And nobody asked me to join");
			}

			if(vaistate==_aistateattack)
			{
				if(VAItargetfound!=0 && VAItargetfound==_AIenemy)
				{
					print("InAttack by myself...");
					call(AIselecttarget,_AIenemy);
					call(AIPickdest);				//in no group. goes after the guy by himself
				}
				else
				{
					call(AIorder,_AIstateSearch);
//					sample(SFXOrderSearch,-1);
				}
			}
			elseif(vaistate==_aistatesearch)
			{
				print("Im searching by myself..");
				Direction(_set,_DIRright);
				if(VAItimeincurrentorder>AINOTARGETTHRESHOLD)
				{
					call(AIorder,_AIstateidle);
				}
			}
			elseif(VAItargetfound!=0)
			{
				print("Target found");
				if(VAItargetfound==_AIenemy)
				{
					print("Enemy found...............");
//	break();

					call(AIorder,_AIstateattack);
					print("Going into attackmode...");

/*					if(vaistate!=_aiattention)
					{
						call(AIorder,_AIstateattention);
						sample(SFXOrderOverThere1,-1);
					}
*/
					if(VAIleaderaspirations!=0)
					{
						call(AIasktojoin,_AIstateAttack);
						call(AIorder,_AIstateattack);
						//sample(SFXOrderGetHim,-1);
					}

				}
				elseif(VAITargetFound==_AIundetermined)
				{
					call(AIorder,_AIstateSearch);
//					sample(SFXOrderSearch,-1);
				}
				else		//friend seen
				{
			//		call(AIasktojoin,_AIstateIdle);
			//		print("Friend found.Join me.........");
				}
			}
			else
			{
				call(AIorder,_AIstateIdle);
				print("In AIIdle");
				//patrol
				//relax
				//sleep
			}
		}

		//print("..........................");
	}


