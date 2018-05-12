
/*
		if(VTrigger==_DIRcombatmode)
		{
			print("actor in combat mode");
		}
		if(VTrigger==_DIRhavegun)
		{
			print("actor has gun");
		}
*/

		if(VAction==GENHolsterGun || VAction==GENUnHolsterGun)
		{
			Direction(_clr,_DIRairemoveflags);
		}

		if(VActorFlag==_AFLAGattached || VState==StateThrown)
		{
			call(ClrPath);
		}

		float(_declare,RandomGnkNoisem,0);
		float(_declare,RandomGnkNoisea,200);
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
		float(_declare,ActorDeathType,0);
		float(_declare,DropDelay,100);
		float(_declare,DieCounter,0);

		float(_declare,ActorFireType,0);
		float(_declare,ActorFireLife,255);
		float(_declare,ActorFireCount,0);
		float(_declare,ActorSmokeCount,0);

		float(_declare,HitByFireCount,0);

		float(_declare,stickumDelay,0);
		//float(_declare,batterydelay,0);

		float(_declare,riotshieldhitcount,0);
		float(_declare,riotshieldoncount,12);
		float(_declare,riotshieldoffcount,0);

		float(_declare,CurrentDirection,_DIRforward|_DIRwalking);
		float(_declare,SeenFlag,0);

		//used in aicode
		float(_declare,Counter,0);					//Not Used?
		float(_declare,AIChoiceVar,0);
		float(_declare,AIEncounterVar,0);
		float(_declare,AIGrenadeCounter,200);
		float(_declare,AILastPathTurn,0);

		float(_declare,limbblownoff,0);
		float(_declare,SteamCounter,0);

		float(_declare,GeigerCounter,0);

		vector(_declare,WeaponPickUpPos,0,0,0);

		float(_declare,DistortionGrenadeExpired,0);

		float(_declare,VisionUpdateFrequency,20);


		if(VAICon==0)
		{
			callsub(Sub_PrintStates);
			Direction(_set,_DIRnotai);
			call(AIorder,_clr,_AIinspecialmode);
		}
		else
		{
			Direction(_clr,_DIRnotai);

			if(VRank>=_RankSergeantL)
			{
				if(VAIstate==_AIstateAttack || VAIstate==_AIstateHide || VAIstate==_AIstateGuard || VAIstate==_AIstateGetWeapon)
				{
					float(_set,VisionUpdateFrequency,10);
				}
				else
				{
					float(_set,VisionUpdateFrequency,20);
				}
			}
		}

		if(VAction!=GENClimbUp)
		{
			call(CheckColSphereOffset);
		}


		if(VActorFlag==_AFLAGinitialize)			//re-initialize after a loadgame
		{
			if(GeigerCounter==1)
			{
				sample(SFXGeigerCounter,-1);
			}
		}

		if(VActiveTime==0)
		{
			callsub(Sub_ChangeStateToNormal);

			vector(_settoactorpos,TmpVector);
			vector(_copyy,TmpVector,FallStartAltitude);
		}

		if(AIAbility&=_AIAPickUpWeapon)
		{
			if(VActiveTime==0 && DisablePickUp==0)
			{
				call(CheckForPickup,12,_ClassWeapon);
			}

			if(VTrigger==_DIRhavegun)
			{
				if(VAIQhasillegalweapon!=0)
				{
					Direction(_or,_DIRillegalweapon);
				}

				if(VAICon!=0)
				{
					if(VTrigger==_DIRillegalweapon && VAction!=GENDePossesed)
					{
						print("Has illegal weapon:  ",DropDelay);
						Direction(_clr,_DIRaction);
						Direction(_set,_DIRactionhold);
						float(_set,DropDelay,9);
						callSub(Sub_CheckActionDrop,GENPickup,14,GENPickupChest,36,DropDelay,AIAbility);
						Direction(_set,_DIRaction);
					}
				}
			}
		}
	
		callsub(Sub_SqueezeCheck,GENCrushed);

		if(VActorFlag==_AFLAGnorotation)
		{
			print("Removing direction flags",TurnSpeed);
			Direction(_clr,_DIRleft|_DIRright);
			if(VAICon==0)
			{
				call(ClrAnalogValues);			//for sub_turncharacter
				float(_set,TurnSpeed,0);
			}
		}

		float(_declare,PlayOnce,0);
		float(_declare,PlayOnceFX,0);

		if(vstate==statedead && PlayOnceFX==0)
		{
			if(VActorFlag==_AFLAGSqueeze)
			{
				sample(SFXCrushedReact,-1);			
			}
			else
			{
				sample(SFXJustDiedReact,-1);
			}

			if(VAICon==0)
			{
				vector(_set,gactorpos,0,-100,0);
				spawnparticle(fx_depossessflare,0,gactorpos,emptyvector,-1);
				spawnparticle(fx_depossessflare,0,gactorpos,emptyvector,-1);
				spawnparticle(fx_depossessflare,0,gactorpos,emptyvector,-1);
				spawnparticle(fx_depossessflare,0,gactorpos,emptyvector,-1);

				vector(_set,tmpvector,64,56,64);
				SpawnLight(PossessLight,0,emptyvector,tmpvector,EmptyVector,800);
			}
			float(_set,PlayOnceFX,1);
		}

		if(VAICon==0 && vstate==statedead && PlayOnce==0)
		{
			call(CDSwap,-1,0,0,150);

			message("YOU CALL YOURSELF THE MESSIAH?",400,10);

			vector(_settoactorpos,Gactorpos);
			if(NrCopsInSet!=0)
			{
				sample(SFXCopJustKilledBobReact,Gactorpos);
			}
			else
			{
				sample(SFXJustKilledBobReact,Gactorpos);
			}
			float(_set,PlayOnce,1);
			if(VSniperMode!=0)
			{
				call(ChangeSniperMode,0,0);
			}
		}
		elseif(vstate!=statedead)
		{
			float(_set,PlayOnce,0);
		}

		if(VTrigger!=_DIRhavegun)
		{
			ActorFlag(_clr,_AFLAGlogon);
		}

		if(AIAbility&=_AIAFakeWeapon)
		{
			Direction(_or,_DIRhavegun);		//to fool the enemies into believing she is packing
		}

		if(AIAbility&=_AIAHideWeapon && VTrigger!=_DIRmove && VAction!=GENPickup)
		{
			if(VTrigger==_DIRhavegun || VActorFlag==_AFlagweaponinvisible)
			{
				print("check for holster/unholster");

				if(VTrigger==_DIRcombatmode)
				{
					print("Weapon visible");
					if(VActorFlag==_AFlagweaponinvisible)
					{
						if(VAction==GENUnHolsterGun && VFrame==11)
						{
							ActorFlag(_clr,_AFLAGweaponinvisible);
							Direction(_or,_DIRhavegun);
						}
						else
						{
							spawnaction(GENUnHolsterGun);
						}
					}
				}
				else
				{
					print("Weapon invisible");
					if(VActorFlag!=_AFlagweaponinvisible)
					{
						if(VAction==GENHolsterGun && VFrame==20)
						{
							ActorFlag(_or,_AFLAGweaponinvisible);
							Direction(_clr,_DIRhavegun);
						}
						else
						{
							spawnaction(GENHolsterGun);
						}
					}
				}
			}
		}

		if(AIAbility&=_AIAAlwaysInCombatMode)
		{
			Direction(_or,_DIRcombatmode);
		}

		if(VActorFlag==_AFLAGconfused)
		{
			if(AIAbility&!=_AIAFlashVisors)
			{
				call(AIorder,_set,_AIstateConfused);
				call(AIorder,_set,_AIinspecialmode|_AIdontdopickdest|_AInomove|_AInoturn);
				call(ClrPath);
				State(_or,StateExecutePathSequence);
			}
			else
			{
				ActorFlag(_clr,_AFLAGconfused);
			}
		}

		if(VActorFlag!=_AFLAGradiated && GeigerCounter==1)
		{
			samplestop(SFXGeigerCounter,-1);
			float(_set,GeigerCounter,0);
		}

		if(VActor==RadiationWorker && VActorFlag==_AFLAGradiated)			// If radiation worker
		{
			if(GeigerCounter==0)
			{
				sample(SFXGeigerCounter,-1);
				float(_set,GeigerCounter,1);
			}
		}

		if(VActorFlag==_AFLAGkillandremove)
		{
			print("Kill flag set");
			if(VAICon==0)
			{
				call(SubtractHealth,0,30000);
			}
			elseif(VActorFlag!=_AFLAGpossesed && VAIClass!=_AIclassangel)	//don't kill evil bob or AI possesed characters
			{
				call(SubtractHealth,0,30000);
			}
		}

		if(vstate!=statedead)
		{
			if(AIAbility&=_AIAShield && VActorFlag==_AFLAGshieldon)
			{
				print("Shield On:   ",AIAbility);

				if(riotshieldhitcount>0)
				{
					//we've been hit ..aarrggghhhh!!!!
					callsub(Sub_riotshield,fx_riotshlda1hit,fx_riotshlda2hit,fx_riotshlda3hit,fx_riotshlda4hit,fx_riotshlda5hit,fx_riotshlda6hit,emptyfloat);
					float(_sub,riotshieldhitcount,1);
				}
				else
				{
					if(riotshieldoncount==12)
					{
						sample(SFXRiotShieldOn,-1);
					}

					if(riotshieldoncount>0)
					{
						//shield forming on
						callsub(Sub_riotshield,fx_riotshlda1on,fx_riotshlda2on,fx_riotshlda3on,fx_riotshlda4on,fx_riotshlda5on,fx_riotshlda6on,riotshieldoncount);
						float(_sub,riotshieldoncount,1);
					}
					else
					{
						//normal sheild active!!!
						callsub(Sub_riotshield,fx_riotshlda1,fx_riotshlda2,fx_riotshlda3,fx_riotshlda4,fx_riotshlda5,fx_riotshlda6,emptyfloat);
					}
				}

				float(_set,riotshieldoffcount,12);

				if(VTrigger==_DIRactorbulletcol)
				{
					if(VColAngle>3072 || VColAngle<1024)
					{
						sample(SFXRiotShield,-1);

						float(_set,riotshieldoncount,0);
						float(_set,riotshieldhitcount,12);

						//call(RestoreLastHealth);

						//printilog("ColAngle:   ",VColAngle);
						Direction(_clr,_DIRactorbulletcol);
						SpecialFlag(_clr,_sFLAGLostALimb);
						SpecialFlag(_clr,_sFLAGTargetAimKillShot);
						SpecialFlag(_clr,_sFLAGTargetAimCloseRange);
						ActorFlag(_clr,_AFLAGSniped);
					}
				}
			}
			else
			{
				float(_set,riotshieldhitcount,0);
				float(_set,riotshieldoncount,12);

				if(riotshieldoffcount==12)
				{
					sample(SFXRiotShieldOff,-1);
				}

				if(riotshieldoffcount>0)
				{
					float(_set,tmpfloat,12);
					float(_sub,tmpfloat,riotshieldoffcount);
					callsub(Sub_riotshield,fx_riotshlda1off,fx_riotshlda2off,fx_riotshlda3off,fx_riotshlda4off,fx_riotshlda5off,fx_riotshlda6off,tmpfloat);
					float(_sub,riotshieldoffcount,1);
				}
			}
		}

		//don't move up higher than this to prevent sequencing problems
		if(VHealth<=0 && VTrigger==_DIRalive)
		{
			Direction(_clr,_DIRalive);
			//sample(SFXJustDiedReact,-1);	//consistently repeating and crashing game!!!
		}

		if(VColMaterialProperties==_MATDrown || VAction==GENDrown || VAction==GENDrownLoop)
		{
			if(VAction!=GENDrown && VAction!=GENDrownLoop)
			{
				state(_or,StateExecuteAnim);
				//SpawnAction(CopDrown);
				SpawnAction(GENDrown);
				if(VTrigger==_DIRalive)
				{
					sample(SFXDrownReact,-1);
				}
			}
			if(DieCounter==0)
			{
				state(_or,StateDead);
				direction(_clr,_DIRalive);
				callsub(Sub_Deposses);
				if(VAICon==0)
				{
					call(LockCamera,true);
				}
				float(_add,DieCounter,1);
				move(0,-190,0);
			}
			else
			{
				if(vrnd<15&&DieCounter<60)
				{
					callsub(Sub_RandomWaterSFX);
				}

				if(DieCounter>=680)	//&& VAICon==0)
				{
					killactor();
				}
				/* Add some bubble from mouth here
				if(vrnd<20)
				{
				}
				*/
				float(_add,DieCounter,1);
			}

			if(DieCounter>=130 && DieCounter<=160)
			{
				move(0,1,0);
			}
			elseif(DieCounter>=300)
			{
				move(0,-0.4,0);
			}

		}


		//	ActorDeathType - 1 is die from fire after walking around blinded
		if(VState==StateDead)
		{
			direction(_clr,_DIRcombatmode);
			Direction(_clr,_DIRaiRemoveFlags);

			resetbone(2);		//to make sure we are bending into the ground
			if(VAIState==_AIStateHide)
			{
				//to free up corner occupied by dead actor
				call(AIclrhidenode);
				call(AIorder,_set,_AIStateidle);
			}

			//complete any effects we started before die-ing!!
			//samplestop(SFXGenericBurn);
		}
		//elseif(VAICon!=0 && aitoggle==0 && VState!=StateThrown && VState!=StateHarpooned && VState!=StateCrawling && VActorFlag!=_AFLAGattached && VActorFlag!=_AFLAGnoai)
		elseif(VAICon!=0 && aitoggle==0 && VState!=StateThrown && VState!=StateHarpooned && VState!=StateCrawling && VActorFlag!=_AFLAGnoai && VState!=StateExecuteAnim)	// && VActorFlag!=_AFLAGattached)
		{

			// **************************************************************************
			// ************ Start of AI Control Code ************************************
			// **************************************************************************
/*
			printi("PathDestDist:     ",VPathDestDistance);
			printi("PathDestAngle:    ",VPathDestAngle);
			printi("PickDestAngle:    ",VPickDestAngle);
			printi("TargetDistance:   ",vtargetdistance);
			printi("TargetAngle:      ",vtargetangle);
*/
			float(_declare,pRndAngle,0);
			vector(_declare,pHaloOuterPos,0,0,0);
			vector(_declare,pHaloPos,0,0,-50);

			Direction(_clr,_DIRaiRemoveFlags)

			if(VTrigger!=_DIRHaveGun && VActorFlag!=_AFlagweaponinvisible && VState!=StateCrawling && AIAbility&=_AIAPickUpWeapon)
			{
				call(IsPickupClose,_ClassWeapon,115,TmpFloat,TmpVector);
				if(vtrigger==_DIRTempFlag && TmpFloat!=0)
				{
					print("Trying to pick up weapon");
					Direction(_set,_DIRaction);
					float(_set,ActionOK,1);
				}
			}

			call(AIcorrectforobstacles,5);
			float(_set,CurrentDirection,0);

			//************************************************************************
			//*********		HIDE CONTROL      ****************************************
			//************************************************************************
			if(vaistate==_AIstateHide)
			{
				#include	"messiahscripts\enemies\cophide.hxx"
			}
			//************************************************************************
			//*********		END OF HIDE CONTROL      *********************************
			//************************************************************************
			elseif(VAIstatehigh==_AInomove || VActorFlag==_AFLAGnorotation)
			{
				printi("Moving routine no move:    ",VAIhastarget);
				if(VAIstatehigh!=_AInoturn && VActorFlag!=_AFLAGnorotation)
				{
					if(VAIhastarget!=0)	// && VAITargetFound==_AIenemy)
					{
						callsub(Sub_AI1WayAlignToTarget);

						if(VAIstate==_AIstateAttack)
						{
							if(vtrigger!=_DIRcombatmode)						//put character in combatmode
							{
								direction(_set,_DIRcombatmode);
							}
							CallSub(Sub_AIShootCheck,true,CurrentDirection,Counter,AIGrenadeCounter,AIAbility);
						}
					}
					else
					{
						CallSub(Sub_AI1WayAlignToPickDestAngle)
					}
				}
			}
			elseif(vstate==StateFollowPath || vstate==StateExecutePathSequence)
			{
				//moving pattern for normal patroling
				print("Moving routine for normal patrolling   ");

				if(VTrigger==_DIRcombatmode && VAIstatehigh!=_AIinspecialmode)
				{
					direction(_clr,_DIRcombatmode);		//not in attack
				}

				if(VAIhastarget==0)
				{
					print("Has no target");
					CallSub(Sub_AI1WayAlignToPickDestAngle)
					if(VPathDestDistance>20)
					{
						if(vaistate==_AIstateRun)
						{
							printi("In state run:   ",vpickdestanglecorr);
							print("In state run:   ",CurrentDirection);
							if(vpickdestanglecorr<128 && vpickdestanglecorr>-128)	//aligned with target but standing still
							{
								float(_set,CurrentDirection,_DIRforward);
							}
						}
						else
						{
							if(vpickdestanglecorr<256 && vpickdestanglecorr>-256)	//aligned with target but standing still
							{
								float(_set,CurrentDirection,_DIRforward|_DIRwalking);
							}	
						}
					}
				}
				else
				{
					if(VRank>=_RankSergeantL)
					{
						CallSub(Sub_AI1WayAlignToTarget);
						if(vtargetdistance>800 || AIUsage&=_AIUAlwaysRun)
						{
							if(vtargetdistance>80)
							{
								CallSub(Sub_AI8WayMoveRun,CurrentDirection);
							}
						}
						elseif(vtargetdistance>80)
						{
							CallSub(Sub_AI8WayMoveWalk,CurrentDirection);
						}
					}
					else
					{
						CallSub(Sub_AI1WayAlignToPickDestAngle)
						if(VPathDestDistance>20)
						{
							if(vaistate==_AIstateRun)
							{
								if(vpickdestanglecorr<128 && vpickdestanglecorr>-128)	//aligned with target but standing still
								{
									float(_set,CurrentDirection,_DIRforward);
								}
							}
							else
							{
								if(vpickdestanglecorr<256 && vpickdestanglecorr>-256)	//aligned with target but standing still
								{
									float(_set,CurrentDirection,_DIRforward|_DIRwalking);
								}	
							}
						}
					}
				}
			}
			elseif(VAIhastarget!=0 && vtargetdistance>200)
			{
				//moving pattern for any anything but patrolling
				print("Moving routine for anything but patrolling");

				print("In special control routine");
				CallSub(Sub_AI1WayAlignToTarget);
				if(VTrigger==_DIRhavegun)
				{
					if(vtargetdistance>800)
					{
						CallSub(Sub_AI8WayMoveRun,CurrentDirection);
					}
					else
					{
						CallSub(Sub_AI8WayMoveWalk,CurrentDirection);
					}
				}
				else
				{
					CallSub(Sub_AI8WayMoveRun,CurrentDirection);
				}
				if(vtrigger!=_DIRcombatmode)						//put character in combatmode
				{
					direction(_set,_DIRcombatmode);
				}

				if(VAItargetfound!=0 && VAItargetfound==_AIenemy)
				{
					CallSub(Sub_AIShootCheck,true,CurrentDirection,Counter,AIGrenadeCounter,AIAbility);
				}

				CallSub(Sub_AIHandleWallCollision,CurrentDirection);
			}
			else	//condition true if character is closer to subject than 200 units
			{
				print("Close up attack move");
				if(VAIState==_AIstateAttack || VAIState==_AIstatesearch || VAIState==_AIstateGetWeapon)
				{
					print("Close up attack move");
					CallSub(Sub_AI1WayAlignToTarget)
					if(VAItargetfound!=0 && VAItargetfound==_AIenemy)
					{
						CallSub(Sub_AIShootCheck,true,CurrentDirection,Counter,AIGrenadeCounter,AIAbility);
					}
					if(VTrigger!=_DIRhavegun || VAItargetfound!=_AIenemy)
					{
						if(vtargetdistance>90)
						{
							CallSub(Sub_AI8WayMoveWalk,CurrentDirection);
						}
						if(VTrigger!=_DIRhavegun && AIAbility&=_AIAPossesion)
						{
							if(VPlayer1Distance<22500 && VAIPlayer1IsTarget!=0)		//150*150
							{
								Direction(_set,_DIRshoot);
							}
							elseif(AIUsage&=_AIUFindHost && VTargetAngle<100 && VTargetAngle>-100)
							{
								Direction(_set,_DIRjump);
							}
						}
						elseif(VAItargetfound==_AIenemy)
						{
							if(vtrigger!=_DIRcombatmode)						//put character in combatmode
							{
								direction(_set,_DIRcombatmode);
							}
							Direction(_set,_DIRshoot);
						}
					}
					else
					{
						if(vtrigger!=_DIRcombatmode)						//put character in combatmode
						{
							direction(_set,_DIRcombatmode);
						}
					}

					CallSub(Sub_AIHandleWallCollision,CurrentDirection);
				}
				else
				{
					//printi("aligning to pickdestcorr  ",vtargetangle);
					print("In close up mode");
					CallSub(Sub_AI1WayAlignToPickDestAngle)
				}

				if(VState!=StateCrawling)
				{
					direction(_set,_DIRaction);
					float(_set,ActionOK,1);
				}
			}

			if(AIUsage&=_AIUAlwaysRun)
			{
				float(_clr,CurrentDirection,_DIRwalking);
			}

/*			//testing if illegal Directions were entered
			if(vstate==StateCrouching)
			{
				if(CurrentDirection&=_DIRrun)				//walk is not possible in crouch mode
				{
					float(_set,CurrentDirection,_DIRwalk);
				}
				if(CurrentDirection&=_DIRrunbackward)		//walk is not possible in crouch mode
				{
					float(_set,CurrentDirection,_DIRbackward);
				}	
				if(CurrentDirection&=_DIRrunsideleft)		//walk is not possible in crouch mode
				{
					float(_set,CurrentDirection,_DIRsideleft);
				}
				if(CurrentDirection&=_DIRrunsideright)		//walk is not possible in crouch mode
				{
					float(_set,CurrentDirection,_DIRsideright);
				}
			}
*/
			//printlog("CurrentDirection:  ",CurrentDirection);
			//printilog("Pickdestangle:      ",vpickdestanglecorr);

//			if(vaistate!=_AIstateRun)					//not the best implementation but will do for now
//			{
				Direction(_set,CurrentDirection);
//			}
//			else
//			{
//				Direction(_clr,_DIRwalking);
//				Direction(_set,_DIRforward);
//			}

			//*****************************
			//******** jump code **********
			//*****************************

			//print("JumpPressCounter:   ",JumpPressCounter);
			if(JumpPressCounter<0)
			{
				float(_add,JumpPressCounter,1);
				Direction(_set,_DIRjump);
			}
			elseif(vtrigger==_DIRvercol && vstate!=StateJump && vaistate!=_AIstateHide)
			{
				Collision(0,-20,0, 0,-20,-130);
				if(vcolflag==_DIRvercol)
				{
					if(VWeaponType!=WeaponPak)
					{
						Collision(0,80,0, 0,80,-130);
					}
					else
					{
						Collision(0,280,0, 0,280,-130);
					}
					if(vcolflag!=_DIRvercol)
					{
						if(JumpPressCounter>10)
						{
							float(_set,JumpPressCounter,-30);
							Direction(_set,_DIRjump);
						}
						else
						{
							float(_add,JumpPressCounter,1);
						}
					}
				}
			}
			elseif(vstate==StateJump)
			{
				Direction(_set,_DIRjump);
			}
			else
			{
				float(_set,JumpPressCounter,0);
			}
			//*****************************
			//***** end of jump code ******
			//*****************************

			if(VTrigger|=_DIRMoveBits)
			{
				Direction(_set,_DIRMove);
			}
			else
			{
				Direction(_set,_noDIR);
			}

			//print("CurrentDirection:   ",CurrentDirection);

			if(VTrigger==_DIRactoractorcol && VTrigger!=_DIRmove && VActorFlag!=_AFLAGattached)
			{
				if(VAIStatehigh!=_AIcombatmodereact && VAIStatehigh!=_AIcloseupaction && VAIState!=_AIstateAttack && VAIState!=_AIstateSearch && VAIState!=_AIstateGetWeapon && VAIState!=_AIstateHide && VAIState!=_AIstateConfused)
				{
					sample(SFXBumpIntoReact,-1);
					if(Vaction!=GENBumped)
					{
						Spawnaction(GENBumped);
					}
				}
				Direction(_clr,_DIRactoractorcol);
			}

			#include	"messiahscripts\enemies\copai.hxx"

// **************************************************************************
// ************ End of AI Control Code **************************************
// **************************************************************************
		}
		elseif(VAIcon==0)
		{
//Player control
			call(AIupdateAIvars);			//to update aicounters like TimeNotTarget
			call(AIcheckfortarget,15);		//for LineOfSight reasons etc. this is called for player character also
		//	call(AIsetlockedonactortotarget);

			if(AIUsage&=_AIUCrouchToDefend)
			{
				if(VState==StateCrouching && VTrigger!=_DIRMove)
				{
					ActorFlag(_or,_AFLAGshieldon);
				}
				else
				{
					ActorFlag(_clr,_AFLAGshieldon);
				}
			}


			if(VAItimenottarget>30)
			{
				call(AIreinstateactoraiclass);
			}
		}

		if(vtrigger==_DIRpossesion)
		{
			float(_set,PlayerHeadBone,4);
			callsub(Sub_InitPossesion,GENPossesed,GENCrouchPossession,GENCrawlPossession);
			//Possesion callback effect init here
			call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,120);
			resetbone(PlayerHeadBone);
			resetbone(2);
			ActorFlag(_or,_AFLAGpossesed);
			
			ActorFlag(_clr,_AFLAGnorotation);	//(Torg) make sure this is cleared out so the player can turn



			//THIS PRINTS NAME OF POSESSED CHARACTER IN LOWER LEFT CORNER OF SCREEN
			if(VHUDDisplayTimer==0)		//If Timer is not currently being displayed...
			{
				if(VActor==copl)
				{
					messageXY("LIGHT COP",0,10);
				}
				elseif(VActor==copm)
				{
					MessageXY("MEDIUM COP",0,10);
				}
				elseif(VActor==coph)
				{
					MessageXY("HEAVY COP",0,10);
				}
				elseif(VActor==worker)
				{
					MessageXY("WELDER",0,10);
				}
				elseif(VActor==medic)
				{
					MessageXY("MEDIC",0,10);
				}
				elseif(VActor==abeast)
				{
					MessageXY("ARMORED BEHEMOTH",0,10);
				}
				elseif(VActor==RadiationWorker)
				{
					MessageXY("RADIATION WORKER",0,10);
				}
				elseif(VActor==Layya)
				{
					MessageXY("LAYYA",0,10);
				}
				elseif(VActor==prost1)
				{
					MessageXY("FEMALE PROSTITUTE",0,10);
				}
				elseif(VActor==hung)
				{
					MessageXY("MALE PROSTITUTE",0,10);
				}
				elseif(VActor==chot)
				{
					MessageXY("CHOT",0,10);
				}
				elseif(VActor==chotct)
				{
					MessageXY("CHOT",0,10);
				}
				elseif(VActor==chotmot)
				{
					MessageXY("CHOT",0,10);
				}
				elseif(VActor==domina)
				{
					MessageXY("COMMANDER",0,10);
				}
				elseif(VActor==Dweller1)
				{
					MessageXY("DWELLER",0,10);
				}
				elseif(VActor==Dweller3)
				{
					MessageXY("DWELLER",0,10);
				}
				elseif(VActor==subgirl1)
				{
					MessageXY("SUB-GIRL",0,10);
				}
				elseif(VActor==subgirl2)
				{
					MessageXY("SUB-GIRL",0,10);
				}
				elseif(VActor==rat)
				{
					MessageXY("RAT",0,10);
				}
				elseif(VActor==Candy)
				{
					MessageXY("CANDY",0,10);
				}
				elseif(VActor==barman)
				{
					MessageXY("BARTENDER",0,10);
				}
				elseif(VActor==scientist)
				{
					MessageXY("SCIENTIST",0,10);
				}
				elseif(VActor==priest)
				{
					MessageXY("PRIEST",0,10);
				}
				elseif(VActor==chotbeast)
				{
					MessageXY("CHOT BEHEMOTH",0,10);
				}
				elseif(VActor==Pimp)
				{
					MessageXY("PIMP",0,10);
				}
				elseif(VActor==chot2)
				{
					MessageXY("CHOT",0,10);
				}
				elseif(VActor==bouncer)
				{
					MessageXY("BOUNCER",0,10);
				}
				elseif(VActor==djkyd)
				{
					MessageXY("DJ KYD",0,10);
				}
				elseif(VActor==Dweller2)
				{
					MessageXY("DWELLER",0,10);
				}
				elseif(VActor==FemDweller1)
				{
					MessageXY("FEMALE DWELLER",0,10);
				}
				elseif(VActor==FemDweller2)
				{
					MessageXY("FEMALE DWELLER",0,10);
				}
				elseif(VActor==prost2)
				{
					MessageXY("FEMALE PROSTITUTE",0,10);
				}
				elseif(VActor==copr)
				{
					MessageXY("RIOT COP",0,10);
				}
				elseif(VActor==GunCommander)
				{
					MessageXY("GUN COMMANDER",0,10);
				}
				elseif(VActor==nun)
				{
					MessageXY("WAITRESS",0,10);
				}
				elseif(VActor==chotdwarf)
				{
					MessageXY("DWARF CHOT",0,10);
				}
				elseif(VActor==beast)
				{
					MessageXY("BEHEMOTH",0,10);
				}
				elseif(VActor==dancer1 || VActor==dancer2)
				{
					MessageXY("DANCER",0,10);
				}
				elseif(VActor==Worker2)
				{
					MessageXY("WORKER",0,10);
				}
				elseif(VActor==BarmanHelper)
				{
					MessageXY("BARMAN",0,10);
				}
			}
		}
		elseif(vtrigger==_DIRdepossesion && VActorFlag!=_AFLAGNoDepossession)
		{
			callsub(Sub_InitDepossesion,GENDepossesed,GENCrouchDepossession,GENCrawlDepossession)
			//DePossesion callback effect init here
			call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,120);
			ActorFlag(_clr,_AFLAGpossesed);

			if(DepossesionAbilityActive!=0)
			{
				spawnactor(BulletAntiSatan,0,0,-100);		//Satan depossesion weapon
				vector(_settoactorpos,tmpvector);
				callsub(sub_fxsmallexplosion);
				KillActor();
			}
		}


		if(VState==StateDead)
		{
			if(VState==StateForceBkTrig)
			{
				callsub(BackGroundTriggerChecks);
			}
		}
		elseif(VActorFlag!=_AFLAGattached)
		{
			callSub(Sub_ActionKeyHandler,ActionOK);

			if(vstate|=StateAllNormalStates && vtrigger!=_DIRhavegun && VActorFlag!=_AFlagweaponinvisible)
			{
				if(AIAbility&=_AIAPickUpWeapon && VAIStateHigh!=_AIinspecialmode && VState!=StateCrawling)
				{
					if(VState==StateCrouching)
					{
						callSub(Sub_CheckActionPickupCrouch,GENPickupCrouch,14,0,0);
					}
					else
					{
						callSub(Sub_CheckActionPickup,GENPickup,14,GENPickupChest,36);
					}
				}
				call(DeadClassRank,true,175);
				callsub(BackGroundTriggerChecks);
				call(DeadClassRank,false);
				callsub(Sub_BatteryHandler);

				if(VAICon==0)
				{
					if(vstate!=StateCrawling&&vstate!=StateBlind&&vstate!=StateOnFire&&vstate!=StateSteamed&&vstate!=StateHarpooned&&vstate!=StateElectricShock)
					{
						callsub(Sub_CombatKeyHandler,KeyPressCounter,20);
					}
				}
			}
			else
			{
				call(DeadClassRank,true,175);
				callsub(BackGroundTriggerChecks);
				call(DeadClassRank,false);
				callsub(Sub_BatteryHandler);
				if(VAICon==0)
				{
					if(vstate!=StateCrawling&&vstate!=StateBlind&&vstate!=StateOnFire&&vstate!=StateSteamed&&vstate!=StateHarpooned&&vstate!=StateElectricShock)
					{
						callsub(Sub_CombatKeyHandler,KeyPressCounter,20);
					}
				}
				if(vstate==StateNormal)
				{
					if(VState==StateCrouching)
					{
						callSub(Sub_CheckActionDropCrouch,GENPickupCrouch,14,0,0,DropDelay,AIAbility);
					}
					else
					{
						callSub(Sub_CheckActionDrop,GENPickup,14,GENPickupChest,36,DropDelay,AIAbility);
					}
				}
			}

			if(VActorFlag==_AFLAGresetfallalt)				//need to be after bacgroundtriggerchecks prevent death
			{
				ActorFlag(_clr,_AFLAGresetfallalt);
				vector(_settoactorpos,TmpVector);
				vector(_copyy,TmpVector,FallStartAltitude);
			}



			if(VState==StateCrawling)
			{
				callSub(Sub_CheckRemainingActions,GENPressGunCrawl,11);
			}
			else
			{
				callSub(Sub_CheckRemainingActions,GENPressGun,11);
			}

			callsub(Sub_Headtrack);					//Track head against object

			//if in the electric shock animations do not check for fall, it's done for you!!
			if(VState==StateThrown)
			{
				CallSub(Sub_CheckThrownFallDamage,FallStartAltitude,CopMaxFall);
				if(VState==StateNormal)
				{
					callsub(Sub_TurnCharacter,TurnSpeed,CopMaxTurnSpeedWounded,CopTurnAccWounded);
				}
			}
			elseif(VState!=StateElectricShock)
			{
				CallSub(Sub_CheckFallDamage,AIAbility,GENTouchDown,FallStartAltitude,CopMaxFall,DamageCopFall,GENFallDead,0,GENFallInPlace);
			}

			if(AIAbility&=_AIAPossesion)
			{
				if(Vstate==StateFlying||vstate==StateFalling||vstate==StateJump||vstate==StateGliding)
				{
					call(CheckForPossesion);	//DiameterSqr
				}
			}

		}

		//If character was sniped do bonespecific damage else call Sub_CheckHit() as usual	...GABE!
		if(AIAbility&!=_AIANoBoneCollision && VActorFlag==_AFLAGSniped && VState==StateNormal && VState!=StateThrown && VState!=StateExecuteAnim)
		{
			ActorFlag(_clr,_AFLAGSniped);
			if(AIAbility&=_AIAShield && VActorFlag==_AFLAGshieldon)
			{
				//riot cop
			}
			else
			{
				if(VState!=StateCrawling)
				{
					//if distance greater than 70 feet with pumpgun, then no killshot or specific bone shots!
					if(VSpecialFlag==_sFLAGTargetAimCloseRange)
					{
						if(VColBone>=16 && VColBone<=17)				//left leg
						{
							SpawnAction(GENShotInLLeg);
							state(_or,StateCrawling);
							state(_or,StateExecuteAnim);
							sample(SFXShotInLegReact,-1);
							if(AIAbility&=_AIAPickUpWeapon)
							{
								call(CheckAttached,_CADropWeaponAndShells);
							}
							CallSub(Sub_ChangeStateToNormal);
						}
						elseif(VColBone>=20 && VColBone<=21)			//right leg
						{
							SpawnAction(GENShotInRLeg);
							state(_or,StateCrawling);
							state(_or,StateExecuteAnim);
							sample(SFXShotInLegReact,-1);
							if(AIAbility&=_AIAPickUpWeapon)
							{
								call(CheckAttached,_CADropWeaponAndShells);
							}
							CallSub(Sub_ChangeStateToNormal);
						}
						else
						{
							sample(SFXShotReact,-1);
							if(VColAngle>=3072 || VColAngle<=1024)		//hit in front
							{
								if(VSpecialFlag==_sFLAGLostALimb)
								{
									State(_or,StateDead);
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
									spawnaction(CopHeadBlownOffDead);
								}
								elseif(VColBone==11 || VColBone==12); // && VHealth<500)	//right hand and weak
								{
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
									spawnaction(GENShotInRightHand);
								}
								elseif(VColBone==3)			//neck
								{
									//SpawnAction(GENShotFrHead);
									State(_or,StateDead);
									SpawnAction(GENShotInNeckFront);
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
								}
								elseif(VColBone==4)			//Head
								{
									//SpawnAction(GENShotFrHead);
									//SpawnAction(GENShotInAss);
									SpawnAction(GENShotInNeckFront);
									//SpawnAction(CopThrownSpin);
									State(_or,StateDead);
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
								}
								elseif(VColBone==1 || VColBone==19 || VColBone==15)	//lower torso (balls really)
								{
									SpawnAction(GENShotFrTorso);
									State(_or,StateDead);
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
								}
								elseif(VColBone==2 || VColBone==9 || VColBone==10)	// upper torso, right collar and upper right shoulder
								{
									//SpawnAction(GENShotFrRShoulder);	//right shoulder
									SpawnAction(GENWoundLightNoBreak);
								}
								elseif(VColBone>=5 && VColBone<=8)		//left collar -> left hand
								{
									SpawnAction(GENShotFrLShoulder);	//left shoulder
								}
								elseif(VColBone==22)		//Right Foot
								{
									SpawnAction(GENShotInRFoot);
								}
								elseif(VColBone==18)		//Left Foot
								{
									SpawnAction(GENShotInLFoot);
								}
								else
								{
									SpawnAction(GENShotGeneric);		//generic shot anim
								}
							}
							elseif(VColAngle>1024 && VColAngle<3072)	//hit in back
							{
								if(VSpecialFlag==_sFLAGLostALimb)
								{
									State(_or,StateDead);
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
									spawnaction(CopHeadBlownOffDead);
								}
								elseif(VColBone==11 || VColBone==12); // && VHealth<500)		//right hand and weak
								{
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
									spawnaction(GENShotGeneric);
								}
								elseif(VColBone==3)			//neck
								{
									State(_or,StateDead);
									SpawnAction(GENShotInNeckBack);
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
								}
								elseif(VColBone==4)			//Head
								{
									State(_or,StateDead);
									SpawnAction(GENShotInNeckBack);
									if(AIAbility&=_AIAPickUpWeapon)
									{
										call(CheckAttached,_CADropWeaponAndShells);
									}
								}
								elseif(VColBone==1 || VColBone==19 || VColBone==15) //Ass!
								{
									SpawnAction(GENShotInAss);		
									//SpawnAction(GENShotBkBack);
								}
								elseif(VColBone==2 || VColBone==5 || VColBone==9) //ltorso,rtorso,lcollar,rcollar
								{
									SpawnAction(GENShotBkBack);
								}
								elseif(VColBone==22)		//Right Foot
								{
									SpawnAction(GENShotInRFoot);
								}
								elseif(VColBone==18)		//Left Foot
								{
									SpawnAction(GENShotInLFoot);
								}
								else
								{
									//SpawnAction(GENWoundLightNoBreak);
									spawnaction(GENShotGeneric);
								}
							}
						}
					}
					else
					{
						if(vstate==StateCrouching)
						{
							spawnaction(GENCrouchWoundLight);
						}
						else
						{
							spawnaction(GENShotGeneric);
						}
						sample(SFXShotReact,-1);
					}
				}
				else
				{
					spawnaction(CopShotCrawl);
					sample(SFXShotReact,-1);
				}
			}
		}
		else
		{
			//if(VState!=StateThrown && VState!=StateAttached)
			if(VState!=StateThrown && VActorFlag!=_AFLAGattached)
			{
				callsub(Sub_CheckHit,AIAbility,GENWoundLight,GENWoundLightRun,GENWoundLightNoBreak,FireCount,GENPoleDead,GENCrouchWoundLight,GENThrownForward,GENThrownBack,GENThrownLeft,GENThrownRight,HitByFireCount);
			}
			elseif(VState==StateAttached && VState!=StateHarpooned)
			{
				callsub(Sub_CheckHit,AIAbility,GENWoundLight,GENWoundLightRun,GENWoundLightNoBreak,FireCount,GENPoleDead,GENCrouchWoundLight,GENThrownForward,GENThrownBack,GENThrownLeft,GENThrownRight,HitByFireCount);
			}
		}


		//fx states
		if(VFXFlag==_fxFLAGFire)
		{
			if(FireCount==0)
			{
				if(vstate!=StateDead)
				{
					sample(SFXOnFire,-1);
				}
				sample(SFXGenericBurn,-1);
				samplestop(SFXcough);

				float(_set,ActorDeathType,1);
			}
			float(_set,ActorFireType,1);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorFireEffect,SmokeCount,FireCount,ActorFireLife,ActorFireType,ActorFireCount)
		}
		elseif(VFXFlag==_fxFLAGSmoke)
		{
			if(SmokeCount==0)
			{
				float(_set,FireCount,0);
				samplestop(SFXGenericBurn);
				if(vstate!=StateDead)
				{
					sample(SFXcough,-1);
				}
			}
			float(_set,ActorFireType,1);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorSmokeEffect,SmokeCount,ActorFireLife,ActorFireType,ActorSmokeCount)
		}


		if(vstate==StateOnFire)	//These first if-statements are just for effects
		{
			ActorFlag(_or,_AFLAGnoai);
			if(vrnd<15)
			{
				CheckActorCollision(0,emptyVector,96,0,_COLfire,DamageFlameThrower);
			}

			if(FireCount==0)
			{
				if(vstate!=StateDead)
				{
					sample(SFXOnFire,-1);
				}
				sample(SFXGenericBurn,-1);
				samplestop(SFXcough);

/*				if(vrnd<50)
				{
					sample(SFXActorPainInFire1,-1);
				}
				else
				{
					sample(SFXActorPainInFire2,-1);
				}

*/
				float(_set,ActorDeathType,1);
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
				samplestop(SFXGenericBurn);
//				sample(SFXcough,-1);
				if(vstate!=StateDead)
				{
					sample(SFXcoughReact,-1);
				}
			}
			float(_set,ActorFireType,0);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorSmokeEffect,SmokeCount,ActorFireLife,ActorFireType,ActorSmokeCount)

			if(vstate!=StateDead && ActorDeathType==1)
			{
				//actor will die as he's been roasted
				call(SubtractHealth,0,DamageAfterFire);
			}
		}

		//The last number here is used if they have to fall on their knees when energy is low
		callsub(Sub_CheckDeadOrDying,AIAbility,GENPoleDead,GENCrawlDead,GENStandDead,GENCrawlSpreadOut,0,GENFallToCrawl,GENCrouchDead,0);	//0=health when entering crawling-mode

		if(VState==StateDead)
		{
			callsub(Sub_LostAnyLimbsLately,limbblownoff);
			if(VTrigger==_DIRdepossesion && VActorFlag!=_AFLAGNoDepossession)
			{
				callsub(Sub_InitDepossesion,GENDepossesed,GENCrouchDepossession,GENCrawlDepossession)
				//DePossesion callback effect init here
				call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,120);
				direction(_clr,_DIRdepossesion);
			}
		}

		if(vstate==StateExecuteAnim)
		{
			callsub(Sub_CheckExecuteAnimEnd);

			if(AIAbility&!=_AIASpecialSecondaryWeapon)
			{
				if(VAction==GENThrowGrenade || VOAction==GENThrowGrenade || VAction==GENCrouchGrenade)
				{
					if(VOAction==GENThrowGrenade)
					{
						if(VFrame==0)
						{
							callsub(Sub_SpawnGrenade);

							sample(SFXGrunt,-1);
							/*
							if(vrnd<50)
							{
								sample(SFXThrow1,-1);
							}
							else
							{
								sample(SFXThrow2,-1);
							}
							*/
						}
					}
					elseif(VAction==GENCrouchGrenade)
					{
						if(VFrame==27)
						{
							callsub(Sub_SpawnGrenade);

							sample(SFXGrunt,-1);
							/*
							if(vrnd<50)
							{
								sample(SFXThrow1,-1);
							}
							else
							{
								sample(SFXThrow2,-1);
							}
							*/
						}
					}
					callsub(Sub_TurnCharacter,TurnSpeed,CopMaxTurnSpeedWounded,CopTurnAccWounded);
				}
			}
			if(vaction==GENPossesed)
			{
				callsub(Sub_TurnCharacter,TurnSpeed,CopMaxTurnSpeed,CopTurnAcc);
			}
			elseif(VOAction==GENClimbUp && VState!=StateExecuteAnim)
			{
				Move(0,0,CopHangMoveIn);
//				MoveFeetColOffset(0,0,CopHangMoveIn);
				//callsub(Sub_CheckHanging,KeyPressCounter,CopClimbUp,CopFall,CopHangMoveIn);
			}
		}
		elseif(vstate==StateCrawling||vstate==StateBlind||vstate==StateOnFire||vstate==StateSteamed||vstate==StateHarpooned||vstate==StateElectricShock)
		{
			direction(_clr,_DIRcombatmode);

			if(VState!=StateDead)
			{
				if(vstate==StateHarpooned)	//Here are the if-statements that control the actions when you are badly wounded
				{
					if(RandomGnkNoisem<0)
					{
						float(_rnd2,RandomGnkNoisem,100);
						float(_add,RandomGnkNoisem,RandomGnkNoisea);
						float(_add,RandomGnkNoisea,30);

						vector(_settoactorpos,Gactorpos);
						sample(SFXManHarpooned,Gactorpos);
					}
					else
					{
						float(_sub,RandomGnkNoisem,1);
					}

					callsub(Sub_Harpooned,GENHarpoonFrontHold,GENHarpoonFrontHitWall,GENHarpoonFrontIdle,GENHarpoonFrontBurn,GENHarpoonBackHold,GENHarpoonBackHitWall,GENHarpoonBackIdle,GENHarpoonBackBurn);
					callsub(Sub_Deposses);
				}
				else
				{
					callsub(Sub_TurnCharacter,TurnSpeed,CopMaxTurnSpeedWounded,CopTurnAccWounded);
					if(vstate==StateCrawling)
					{
						sample(SFXCrawlingReact,-1);
				//		if(RandomGnkNoisem<0)
				//		{
				//			float(_rnd2,RandomGnkNoisem,100);
				//			float(_add,RandomGnkNoisem,RandomGnkNoisea);
				//			float(_add,RandomGnkNoisea,30);
				//		}
				//		else
				//		{
				//			float(_sub,RandomGnkNoisem,1);
				//		}

						//is this where he has to roll over and hug his knees, and scream if you force him to move?
						callsub(Sub_Crawling,GENCrawlSpreadOut,GENFallToCrawl)
					}
					elseif(vstate==StateOnFire || vstate==StateSteamed || vstate==StateBlind)
					{
						callsub(Sub_BurnedSteamedBlind,GENBurningRollOnFloor,GENBurnedIdle,GENGettingBurned,GENBlindForward,GENBlindBackwards,GENBurningRunInCircle,GENSlowGetUpFace,SteamCounter,GENIdle)
					}
					elseif(vstate==StateElectricShock)
					{

						callsub(Sub_ElectricShock,GENelectricshock0,GENelectricshock1);

						if(vaction==GENelectricshock0)
						{
							if(vframe==1)
							{
								sample(SFXElectricShock1,-1);
								sample(SFXElectrocuteReact,-1);
								call(SubtractHealth,0,DamageElectric);
							}
						}
						elseif(vaction==GENelectricshock1)
						{
							if(vendofanim!=0)
							{
								sample(SFXElectricShock2,-1);

								call(PlaneTriggerQuadrant,TmpFloat,1);
								if(TmpFloat==0)
								{
									spawnaction(GENThrownForward);
									move(0,0,-150);
								}
								elseif(TmpFloat==1)
								{
									spawnaction(GENThrownLeft);
									move(150,0,0);
								}
								elseif(TmpFloat==2)
								{
									spawnaction(GENThrownBack);
									move(0,0,150);
								}
								elseif(TmpFloat==3)
								{
									spawnaction(GENThrownRight);
									move(-150,0,0);
								}
//								state(_change,StateElectricShock,StateThrown);
								state(_clr,StateElectricShock);
							}
						}

					}
				}
			}
		}
/*		DO NOT UNCOMMENT WITHOUT ASKING SAXS
		elseif(VState==StateThrown)
		{
			print("In thrown sequence");
			if (VOAction==CopGetUpFromFrontFaceDown || VOAction==CopGetUpFromBack || VOAction==CopGetUpFromLeftFaceDown || VOAction==CopGetUpFromRightFaceDown)
			{
				CallSub(sub_ChangeStateToNormal);
			}
	//		elseif(VAction!=CopThrownSpin && VAction!=CopThrownForward && VAction!=CopThrownForwardLand && VAction!=CopThrownRight && VAction!=CopThrownRightLand && VAction!=CopThrownLeft && VAction!=CopThrownLeftLand && VAction!=CopThrownBack && VAction!=CopThrownBackLand)
	//		{
	//			//PrintLog("Resetting StateThrown! risky...");
	//			//CallSub(sub_ChangeStateToNormal);
	//			state(_clr,StateThrown);
	//		}
		}
*/
		elseif(VTrigger==_DIRalive && VState!=StateThrown && VActorFlag!=_AFLAGattached)
		{
			if(AIAbility&=_AIAClimb)
			{
				CallSub(Sub_CheckClimbUp,GENClimbUp,60,ColAngleCorrectNeeded,20,CopHangMoveIn);
			}
			if(vstate==StateNormal && VTrigger!=_DIRTempFlag)	//TempFlag comes from checkclimbup, if set, character is gonna climb up
			{
				if(VState!=StateCrouching)
				{
					//callsub(Sub_AlignToWallAndCheckRunUpStairs,GENRunUpStairs,GENIdle,GENIdleHitWall,ColAngleCorrectNeeded,GENIdleHitWallFront,GENHitWallSpreadOut,-0.95,CopSpreadOut,GENSpreadOutGun,ForceRunFrames)
					//callsub(Sub_AlignToWallAndCheckRunUpStairs,GENRunUpStairs,GENIdle,GENIdleHitWall,ColAngleCorrectNeeded,GENIdleHitWallFront,GENHitWallSpreadOut,-0.95,GENSpreadOut,GENSpreadOutGun,ForceRunFrames)
					if(AIAbility&=_AIAUseHitWallCode && VAICon==0)
					{
						callsub(Sub_AlignToWallAndCheckRunUpStairs,GENRunUpStairs,GENIdle,GENIdleHitWall,ColAngleCorrectNeeded,GENIdleHitWall,GENHitWallSpreadOut,-0.95,GENSpreadOut,GENSpreadOutGun,ForceRunFrames)
					}
				}
				callsub(Sub_CheckForIdleLongTime,GENIdle,GENIdleLongTime);

				//control for Sub_SpawnGrenade: distortion/stickum's and betty's can only be thrown one at a time (tony)
				/*
				if(VInventoryType==_AmmoGrenadeBetty && AlertTrigger==JumpingBettyActive)
				{
					direction(_clr,_DIRGrenade);
				}
				*/

				if(VAICon==0)
				{
					//only PlayerOne controls stickem
					if(StickEmState==StickEmReady && VTrigger==_DIRGrenade)
					{
						//we got here , which means we have thrown a StickEm grenade, and now we are going to explode it!
						float(_set,StickEmState,StickEmExploding);
						direction(_clr,_DIRGrenade);
						float(_set,stickumDelay,60);
					}

					if(VInventoryType==_AmmoGrenadeStickEm)
					{
						float(_sub,stickumDelay,1);
						if(stickumDelay>0)
						{
							direction(_clr,_DIRGrenade);
						}
					}

					if(AIAbility&=_AIASpecialSecondaryWeapon && VTrigger==_DIRGrenade)
					{
						if(VAIclass==_AIclassChot && VAIclass==_AIclassAngel && VAction!=DwarfLaunch)
						{
							spawnaction(DwarfLaunch);
						}
					}
				}

				if(VAIcon==0)
				{
					if(VTrigger==_DIRGrenade && VInventoryLeft>0)
					{
						if(VInventoryType!=_AmmoGrenadeDistortion)
						{
							state(_or,StateExecuteAnim);
							if(VState==StateCrouching)
							{
								spawnaction(GENCrouchGrenade);
							}
							else
							{
								spawnaction(GENThrowGrenade);

								if(VAIClass==_AIclassAbeast)
								{
									sample(SFXABeastFire,-1);
								}
							}
						}
						elseif(DistortionGrenadeExpired==0)
						{
							float(_set,DistortionGrenadeExpired,90);

							state(_or,StateExecuteAnim);
							if(VState==StateCrouching)
							{
								spawnaction(GENCrouchGrenade);
							}
							else
							{
								spawnaction(GENThrowGrenade);
							}
						}
					}
				}
				else
				{
					if(VTrigger==_DIRGrenade)
					{
						if(VInventoryType!=_AmmoGrenadeDistortion)
						{
							state(_or,StateExecuteAnim);
							if(VState==StateCrouching)
							{
								spawnaction(GENCrouchGrenade);
							}
							else
							{
								spawnaction(GENThrowGrenade);

								if(VAIClass==_AIclassAbeast)
								{
									sample(SFXABeastFire,-1);
								}
							}
						}
						elseif(DistortionGrenadeExpired==0)
						{
							float(_set,DistortionGrenadeExpired,90);

							state(_or,StateExecuteAnim);
							if(VState==StateCrouching)
							{
								spawnaction(GENCrouchGrenade);
							}
							else
							{
								spawnaction(GENThrowGrenade);
							}
						}
					}
				}


				float(_sub,DistortionGrenadeExpired,1);
				if(DistortionGrenadeExpired<0)
				{
					float(_set,DistortionGrenadeExpired,0);
				}

				if(AIAbility&!=_AIANoCrouch)
				{
					CallSub(Sub_CheckCrouching,GENCrouchDown,GENCrouchUp);
				}

				CallSub(Sub_CheckJumpFallDown,AIAbility,GENRunUpStairs,JumpPressCounter,DownwardPull,CopJumpSpeed,GENJump,AirSpeedForward,AirSpeedSideways,GENFall,CopAirSpeed)
				CallSub(Sub_CheckSliding,GENRunUpStairs,GENSlide);

				if(vtrigger==_DIRaction)
				{
					call(CheckForGrab,200,TmpFloat);	//Deletes diraction flag if there is no grap possible  !??!
					if(TmpFloat!=0)
					{
						if(TmpFloat&=16)							//on stomach
						{
							if(TmpFloat&=1)
							{
								spawnaction(GENKickHeadFD);
							}
							elseif(TmpFloat&=2)
							{
								spawnaction(GENKickRightFD);
							}
							elseif(TmpFloat&=4)
							{
								spawnaction(GENKickCrotchFD);
							}
							elseif(TmpFloat&=8)
							{
								spawnaction(GENKickLeftFD);
							}
						}
						else										//on back
						{
							if(TmpFloat&=1)
							{
								spawnaction(GENKickHeadFU);
							}
							elseif(TmpFloat&=2)
							{
								spawnaction(GENKickRightFU);
							}
							elseif(TmpFloat&=4)
							{
								spawnaction(GENKickCrotchFU);
							}
							elseif(TmpFloat&=8)
							{
								spawnaction(GENKickLeftFU);
							}
						}
					}
				}

				if(VActorFlag!=_AFLAGnorotation)
				{
					callsub(Sub_TurnCharacter,TurnSpeed,CopMaxTurnSpeed,CopTurnAcc);
				}
			}
			elseif(vstate==StateFalling||vstate==StateJump)
			{
				if(vstate==StateJump)
				{
					CallSub(Sub_Jump,JumpPressCounter,DownwardPull,CopMinHoldJumpAction,CopJumpGravity,2,0);
				}
				callsub(Sub_TurnCharacter,TurnSpeed,CopMaxTurnSpeedAir,CopTurnAccAir);
				callsub(Sub_MoveInAir,AirSpeedSideways,AirSpeedForward,CopAirSpeed,CopAirBulb);
				CallSub(Sub_CheckSliding,GENRunUpStairs,GENSlide);
			}
		}

		if(VTrigger==_DIRhavegun && VState==StateThrown || VState==StateCrawling || VActorFlag==_AFLAGattached)
		{
			call(CheckAttached,_CANormal);
		}
		elseif(VAction!=GenClimbup && VActorFlag!=_AFLAGattached)
		{
			if(VTrigger==_DIRcombatmode && VTrigger!=_DIRhavegun && VTrigger==_DIRshoot)
			{
				print("Fire pressed and you have no gun");
				//if(VState!=StateDead && Vaction!=CopBoxing)
				//{
					//SpawnAction(CopBoxing);
					//if(vrnd<50)
					//{
					//	sample(SFXThrow1,-1);
					//}
					//else
					//{
					//	sample(SFXThrow2,-1);
					//}
				//}7
			}
			else
			{
				if(vstate!=stateDead)
				{
					callsub(FireWeaponsAndCheckAttached,ShootDelayCounter,1,GENReload,GENReloadCrouch,GENHeavyRecoil,GENLightRecoil,GENCrouchHeavyRecoil,GENCrouchLightRecoil,AIAbility);
				}
				else
				{
					call(CheckAttached,_CANormal);
				}
			}
		}

		//footsteps
		if(Vstate!=StateCrawling)
		{
			if(VAICon==0 && vtrigger==_DIRleft||vtrigger==_DIRright||vtrigger==_DIRforward||vtrigger==_DIRbackward||vtrigger==_DIRsideleft||vtrigger==_DIRsideright||vtrigger==_DIRjump)
			{
				if(VAIClass==_AIclasssubgirl)
				{
					if(heartbeatsfx==0)
					{
						sample(SFXSubgirlHover,-1);
						float(_set,heartbeatsfx,1);
					}
				}
				else
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
			}
			elseif(VClass==_ClassBeast && vtrigger==_DIRleft||vtrigger==_DIRright||vtrigger==_DIRforward||vtrigger==_DIRbackward||vtrigger==_DIRsideleft||vtrigger==_DIRsideright)
			{
				//the beast is the only AI character to have footstep SFX
				callsub(Sub_CheckFootSteps,_sFLAGLeftFoot);
				callsub(Sub_CheckFootSteps,_sFLAGRightFoot);
			}
		}
		if(VAICon==0&&VAIClass==_AIclasssubgirl)
		{
			if(vtrigger==_DIRwalking||vtrigger!=_DIRleft&&vtrigger!=_DIRright&&vtrigger!=_DIRforward&&vtrigger!=_DIRbackward&&vtrigger!=_DIRsideleft&&vtrigger!=_DIRsideright&&vtrigger!=_DIRjump)
			{
				if(heartbeatsfx==1)
				{
					samplestop(SFXSubgirlHover);
					float(_set,heartbeatsfx,0);
				}
			}
		}


		//weapons
		if(VAICon==0 && VSpecialFlag==_sFLAGPickedUpGun)
		{
			sample(SFXWeaponPickUp,-1);

			if(VHUDDisplayTimer==0)		//If Timer is not currently being displayed...
			{
				if(VActorWeapon==WeaponFlameThrower)
				{
					messageXY("FLAMETHROWER",0,10);
				}
				elseif(VActorWeapon==WeaponBuzzSaw)
				{
					MessageXY("BUZZ-SAW",0,10);
				}
				elseif(VActorWeapon==WeaponTorch)
				{
					MessageXY("TORCH",0,10);
				}
				elseif(VActorWeapon==WeaponPAK)
				{
					MessageXY("CHOT PAK WEAPON",0,10);
				}
				elseif(VActorWeapon==WeaponBatteryGrabber)
				{
					MessageXY("BATTERY GRABBER",0,10);
				}
				elseif(VActorWeapon==WeaponPumpGun)
				{
					MessageXY("PUMP GUN",0,10);
				}
				elseif(VActorWeapon==WeaponMachineGun)
				{
					MessageXY("MACHINE GUN",0,10);
				}
				elseif(VActorWeapon==WeaponHarpoon)
				{
					MessageXY("HARPOON GUN",0,10);
				}
				elseif(VActorWeapon==WeaponBazooka)
				{
					MessageXY("BAZOOKA",0,10);
				}
				elseif(VActorWeapon==WeaponMaser)
				{
					MessageXY("MASER",0,10);
				}
				elseif(VActorWeapon==WeaponMaimer)
				{
					MessageXY("MAIMER",0,10);
				}
			}
		}

		if(VAICon==0 && VSpecialFlag==_sFLAGPickedUpAmmo)
		{
			sample(SFXWeaponAmmo,-1);
		}


		if(VState==StateForceField)
		{
			State(_clr,StateForceField);
			float(_add,DownWardPull,CopJumpGravity);
		}

		if(VState==StateDead && StreetCorpses==1)		
		{
			callsub(BackGroundTriggerChecks);
		}



