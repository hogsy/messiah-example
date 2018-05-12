
		float(_declare,ShootDelayCounter,0)
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
		float(_declare,KeyPressCounter,0);
		float(_declare,DropDelay,100);
		float(_declare,ActorDeathType_f,0);

		float(_declare,ActorFireType,0);
		float(_declare,ActorFireLife,255);
		float(_declare,ActorFireCount,0);
		float(_declare,ActorSmokeCount,0);

		float(_declare,HitByFireCount,0);

		if(VHealth<=0)
		{
			Direction(_clr,_DIRalive);
		}

		if(VActiveTime==0)
		{
			vector(_settoactorpos,TmpVector);
			vector(_copyy,TmpVector,FallStartAltitude);
		}

		if(VTrigger==_DIRalive && VActorFlag==_AFLAGSqueeze)
		{
			state(_set,StateDead);
			spawnaction(CopCrush);
		}

		if(VActorFlag==_AFLAGnorotation)
		{
			print("Removing direction flags",TurnSpeed);
			Direction(_clr,_DIRleft|_DIRright);
			call(ClrAnalogValues);			//for sub_turncharacter
			float(_set,TurnSpeed,0);
		}

		float(_declare,PlayOnce,0);
		if(VAICon==0 && vstate==statedead && PlayOnce==0)
		{
			message("YOU CALL YOURSELF THE MESSIAH ?",400,10);
			sample(SFXJustKilledBobReact,-1);
			float(_set,PlayOnce,1);
			call(ChangeSniperMode,0,0);
		}
		elseif(vstate!=statedead)
		{
			float(_set,PlayOnce,0);
		}
		if(VActiveTime==0)
		{
			vector(_settoactorpos,TmpVector);
			vector(_copyy,TmpVector,FallStartAltitude);
		}

		if(VState==StateDead)
		{
			direction(_clr,_DIRcombatmode);
			Direction(_clr,_DIRaiRemoveFlags);
		}
		elseif(vAICon!=0 && aitoggle==0)
		{
// **************************************************************************
// **************************************************************************
// **************************************************************************

				//AIPickDest(100,1);

				Direction(_clr,_DIRaiRemoveFlags)


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

		}
		elseif(VAIcon==0)
		{
//Player control
			call(AIupdateAIvars);			//to update aicounters like TimeNotTarget
			call(AIcheckfortarget,10);		//for LineOfSight reasons etc. this is called for player character also

			if(vtrigger==_DIRpossesion)
			{
				float(_set,PlayerHeadBone,4);
				callsub(Sub_InitPossesion,SubGirlPossesed);
				//Possesion callback effect init here
				call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,120);
			}
			elseif(vtrigger==_DIRdepossesion)
			{
				callsub(Sub_InitDepossesion,SubGirlDepossesed)
				//DePossesion callback effect init here
				call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,120);
			}

			if(VAItimenottarget>30)
			{
				call(AIreinstateactoraiclass);
			}

			callsub(Sub_CombatKeyHandler,KeyPressCounter,10);
		}



		if(vstate!=StateDead)
		{
			callSub(Sub_ActionKeyHandler,ActionOK);
			callsub(BackGroundTriggerChecks);

			if (vtrigger!=_DIRhavegun)
			{
				//callSub(Sub_CheckRemainingActions,SubGirlPressGun,22);
			}

			callsub(Sub_Headtrack);					//Track head against object

			if(VState==StateThrown)
			{
				CallSub(Sub_CheckThrownFallDamage,FallStartAltitude,Prost1MaxFall);
				if(VState==StateNormal)
				{
					callsub(Sub_TurnCharacter,TurnSpeed,SubGirlMaxTurnSpeedWounded,SubGirlTurnAccWounded);
				}
			}
			elseif(VState!=StateElectricShock)
			{
				CallSub(Sub_CheckFallDamage,SubGirlTouchDown,FallStartAltitude,SubGirlMaxFall,DamageSubGirlFall,SubGirlFallDead,0,SubGirlFallInplace);
			}
		}
		callsub(Sub_CheckHit,SubGirlWoundLight,SubGirlWoundLight,SubGirlWoundLightNoBreak,FireCount,SubGirlPoleDead,SubGirlWoundLight,0,0,0,0,HitByFireCount);

		if(vstate==StateOnFire)	//These first if-statements are just for effects
		{
			if(vrnd<25)
			{
				CheckActorCollision(0,emptyVector,96,0,_COLfire,DamageFlameThrower);
			}

			if(FireCount==0)
			{
				sample(SFXActorOnFire1,-1);
				samplestop(SFXcough7);

				float(_set,ActorDeathType_f,1);
			}
			float(_set,ActorFireType,0);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorFireEffect,SmokeCount,FireCount,ActorFireLife,ActorFireType,ActorFireCount)
		}
		elseif(vstate==StateBlind)
		{
			if(SmokeCount==0)
			{
				float(_set,FireCount,0);
				samplestop(SFXActorOnFire1);
				sample(SFXcough7,-1);
			}
			float(_set,ActorFireType,0);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorSmokeEffect,SmokeCount,ActorFireLife,ActorFireType,ActorSmokeCount)

			if(vstate!=StateDead && ActorDeathType_f==1)
			{
				//actor will die as he's been roasted
				call(SubtractHealth,0,DamageAfterFire);
			}
		}


		if(VAction!=SubGirlBurningRunInCircle&&VAction!=SubGirlBurningRollOnFloor&&VAction!=SubGirlSlowGetUpFace)	//It would look bad if he died while in one of these animations
		{
//The last number here is used if they have to fall on their knees when energy is low
			callsub(Sub_CheckDeadOrDying,SubGirlPoleDead,SubGirlCrawlDead,SubGirlStandDead,SubGirlCrawlSpread,500,SubGirlFallToCrawl,SubGirlStandDead,SubGirlStandDead);	//0=health when entering crawling-mode
		}

		if(vstate==StateExecuteAnim)
		{
			elseif(vaction==SubGirlPossesed)
			{
				callsub(Sub_TurnCharacter,TurnSpeed,SubGirlMaxTurnSpeed,SubGirlTurnAcc);
			}
			callsub(Sub_CheckExecuteAnimEnd)
		}
		elseif(vstate==StateDead||vstate==StateCrawling||vstate==StateBlind||vstate==StateOnFire||vstate==StateSteamed||vstate==StateHarpooned||vstate==StateElectricShock)
		{
			direction(_clr,_DIRcombatmode);

			if(VState!=StateDead)
			{
				if(vstate==StateHarpooned)	//Here are the if-statements that control the actions when you are badly wounded
				{
					callsub(Sub_Harpooned,SubGirlOnPole,SubGirlOnPole,SubGirlOnPole,SubGirlOnPole,SubGirlOnPole,SubGirlOnPole,0,0);
				}
				else
				{
					callsub(Sub_TurnCharacter,TurnSpeed,SubGirlMaxTurnSpeedWounded,SubGirlTurnAccWounded);
					if(vstate==StateCrawling)
					{
//	is this where he has to roll over and hug his knees, and scream if you force him to move?
//
						callsub(Sub_Crawling,SubGirlCrawlSpread,SubGirlFallToCrawl)
					}
					elseif(vstate==StateOnFire||vstate==StateSteamed||vstate==StateBlind)
					{
						float(_declare,SteamScreamCounter,0);
						callsub(Sub_BurnedSteamedBlind,SubGirlBurningRollOnFloor,SubGirlBurnedIdle,SubGirlGettingBurned,SubGirlBlindForward,SubGirlBlindBackwards,SubGirlBurningRunInCircle,SubGirlSlowGetUpFace,SteamScreamCounter)
					}
					elseif(vstate==StateElectricShock)
					{
						callsub(Sub_ElectricShock,SubGirlelectricshock0,SubGirlelectricshock1);

						if(vaction==SubGirlelectricshock0)
						{
							if(vframe==1)
							{
								sample(SFXElectricShock1,-1);
								call(SubtractHealth,0,DamageElectric);
							}
						}
						elseif(vaction==SubGirlelectricshock1)
						{
							if(vendofanim!=0)
							{
								sample(SFXElectricShock2,-1);

								call(PlaneTriggerQuadrant,TmpFloat,1);
								if(TmpFloat==0)
								{
									spawnaction(SubGirlThrownForward);
									move(0,0,-150);
								}
								elseif(TmpFloat==1)
								{
									spawnaction(SubGirlThrownLeft);
									move(150,0,0);
								}
								elseif(TmpFloat==2)
								{
									spawnaction(SubGirlThrownBack);
									move(0,0,150);
								}
								elseif(TmpFloat==3)
								{
									spawnaction(SubGirlThrownRight);
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
			CallSub(Sub_CheckClimbUp,SubGirlClimbUp,60,ColAngleCorrectNeeded,20,-10)

			if(vstate==StateNormal)
			{
				callsub(sub_AlignToWallAndCheckRunUpStairs,SubGirlRunUpStairs,SubGirlIdle,SubGirlIdleHitWall,ColAngleCorrectNeeded,SubGirlIdleHitWallFront,SubGirlHitWallSpread,-0.95,SubGirlSpread,SubGirlSpread,ForceRunFrames)
				callsub(Sub_CheckForIdleLongTime,SubGirlIdle,SubGirlIdleLongTime);

				if(VTrigger==_DIRGrenade&&VInventoryLeft>0)
				{
					state(_or,StateExecuteAnim)
					if(VState==StateCrouching)
					{
						spawnaction(SubGirlCrouchGrenade);
					}
					else
					{
						spawnaction(SubGirlThrowGrenade);
					}
				}

				CallSub(Sub_CheckCrouching,SubGirlCrouchDown,SubGirlCrouchUp);

				CallSub(Sub_CheckJumpFallDown,AIAbility,SubGirlRunUpStairs,JumpPressCounter,DownwardPull,SubGirlJumpSpeed,SubGirlJump,AirSpeedForward,AirSpeedSideways,SubGirlFall,SubGirlAirSpeed)
				callsub(Sub_TurnCharacter,TurnSpeed,SubGirlMaxTurnSpeed,SubGirlTurnAcc);
			}
			elseif(vstate==StateFalling||vstate==StateJump)
			{
				if(vstate==StateJump)
				{
					CallSub(Sub_Jump,JumpPressCounter,DownwardPull,SubGirlMinHoldJumpAction,SubGirlJumpGravity,2,0)
				}
				callsub(Sub_TurnCharacter,TurnSpeed,SubGirlMaxTurnSpeedAir,SubGirlTurnAccAir);
				callsub(Sub_MoveInAir,AirSpeedSideways,AirSpeedForward,SubGirlAirSpeed,SubGirlAirBulb);
			}
		}

		//callsub(FireWeaponsAndCheckAttached,ShootDelayCounter,2,SubGirlHeavyRecoil,SubGirlLightRecoil,SubGirlCrouchHeavyRecoil,SubGirlCrouchLightRecoil);

		if(vaicon!=0 && aitoggle==0)
		{
			call(AIupdateAIvars);
			if(VAIleader!=0)			//in charge
			{
				print("Im the leader....");
				call(AIcheckfortarget);

				if(VAIgroupstate!=_AIstateidle && VAIgroupstate!=_AIstatesearch)			//search should be widened to account for all attackstates
				{
					printi("In attack....",VAInotargettime);
					if(VAInotargettime<AINOTARGETTHRESHOLD)
					{
						print("Persuing enemy...");
						call(AIasktojoin,_AIstateAttack);			//to make sure newcomers are asked to join for battle
						if(VAItargetfound!=_AIenemy && VAInotargettime<AINOTARGETSEARCHTHRESHOLD)
						{
							call(AIorder,_AIstateSearch);
							//sample(SFXOrderSearch,-1);
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
						sample(SFXOrderGetHim,-1);
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
								//sample(SFXOrderSearch,-1);
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
				print("Im assigned to a group....");

				if(VAIstatechanged!=0)
				{
					sample(SFXOrderYesSir1,-1);
				}

				if(VAIaskedtojoin!=0)
				{
					printi("And im asked to leave",VAIchangetonewgroup);
					if(VAIchangetonewgroup!=0)
					{
						break();
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
							call(AIorder,_AIflee);
							call(AIasktojoin,_AIRetreat);
						}
						elseif(VAIhealth>90)
						{
							call(AIorder,_AIAttack);
							call(AIasktojoin,_AIAttack);
						}
						else
						{
							call(AIorder,_AIHide);
							call(AIasktojoin,_AIRetreat);
						}
					}
					else
					{
						call(AIorder,_AIIdle);
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
							call(AIorder,_AIattention);
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
					}
					else
					{
						printi("LeaderAspiration: ",VAIleaderaspirations);
						if(VAIleaderaspirations!=0)
						{
							printi("Ask to join new group");
							call(AIasktojoin,_AIstateAttack);
							call(AIorder,_AIstateattack);
							sample(SFXOrderGetHim,-1);
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
						//sample(SFXOrderSearch,-1);
					}
				}
				elseif(vaistate==_AIstateSearch)
				{
					print("Im searching by myself..");
					turn(0,10,0);
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

						call(AIorder,_AIstateattack);
						print("Going into attackmode...");

	/*					if(vaistate!=_aiattention)
						{
							call(AIorder,_AIattention);
							sample(SFXOrderOverThere1,-1);
						}
	*/
						if(VAIleaderaspirations!=0)
						{
							call(AIasktojoin,_AIstateAttack);
							call(AIorder,_AIstateattack);
							sample(SFXOrderGetHim,-1);
						}

					}
					elseif(VAITargetFound==_AIundetermined)
					{
						call(AIorder,_AIstateSearch);
						//sample(SFXOrderSearch,-1);
					}
					else		//friend seen
					{
						call(AIasktojoin,_AIstateIdle);
						print("Friend found.Join me.........");
					}
				}
				else
				{
					call(AIorder,_AIstateIdle);
					//patrol
					//relax
					//sleep
				}
			}

			print("..........................");
		}



		if(VAICon==0 && vtrigger==_DIRleft||vtrigger==_DIRright||vtrigger==_DIRforward||vtrigger==_DIRbackward||vtrigger==_DIRsideleft||vtrigger==_DIRsideright)
		{
			if(VSpecialFlag==_sFLAGTrodInGoo)
			{
				if(vrnd<50)
				{
					spawnparticle(fx_footbloodspray,18,emptyvector,emptyvector,-1);
				}
				else
				{
					spawnparticle(fx_footbloodspray,22,emptyvector,emptyvector,-1);
				}
				sample(SFXBlood2,-1);
			}
			else
			{
				callsub(Sub_CheckFootSteps,_sFLAGLeftFoot);
				callsub(Sub_CheckFootSteps,_sFLAGRightFoot);
			}
		}


