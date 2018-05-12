
		if(VAICon!=0)
		{
			printi("health:   ",VHealth);
		}


		float(_declare,CloseUpCounter,1400);
		float(_add,CloseUpCounter,1);

		call(AIupdateAIvars);

		if(VActiveTime==0)
		{
			if(VDifficulty==_DifficultyEasy)
			{
				if(VRnd<70)		//70% chance enemy will always choose headon assault in easy mode
				{
					float(_set,AIManPowerThreshold,0);
					float(_set,AIPowerRatingThreshold,0);
				}
			}
			elseif(VDifficulty==_DifficultyMedium)
			{
				if(VRnd<30)		//30% chance enemy will always choose headon assault in medium mode
				{
					float(_set,AIManPowerThreshold,0);
					float(_set,AIPowerRatingThreshold,0);
				}
			}
			elseif(VDifficulty==_DifficultyHard)
			{

			}
		}


		if(VAIpowerrating>AIPowerRatingThreshold)
		{
			if(VAImanpowerindex>=AIManPowerThreshold || VAIpowerrating==100)
			{
				//frontal attack (against unarmed enemies or Bob for example)
				float(_set,AIControl,_AICAttack);
			}
			else
			{
				//attack using hide if appropriate (normal attack)
				if(AIUsage&=_AIUhideforattack)
				{
					float(_set,AIControl,_AICAttackUsingHide);
					//initialize hide code
				}
				else
				{
					//use frontal attack
					float(_set,AIControl,_AICAttack);
				}
			}
		}
		else
		{
			if(VTrigger!=_DIRhavegun && VAItargettrigger!=_DIRhavegun)
			{
				float(_set,AIControl,_AICAttack);		//if both unarmed
			}
			elseif(VAImanpowerindex>=AIManPowerThreshold)
			{
				//attack using hide if appropriate (normal attack)
				if(AIUsage&=_AIUhideforattack)
				{
					float(_set,AIControl,_AICAttackUsingHide);
				}
				else
				{
					float(_set,AIControl,_AICAttack);
				}
			}
			else
			{
				//retreat (act less offensive. Let them seek out you)
				if(AIUsage&=_AIUhideforretreat)
				{
					float(_set,AIControl,_AICRetreatUsingHide);
				}
				else
				{
					float(_set,AIControl,_AICRetreat);
				}
			}
		}

		printi("PowerRating:       ",VAIpowerrating);
		printi("VAImanpowerindex:  ",VAImanpowerindex);
		print("AIControl:         ",AIControl);
		print("AIPatience:        ",AIpatience);

/*

/////////////////////////////////////////////////////////////////////////////////////
//Tim's CopStateBits stuff:

		//includes possessed character
	call(GetNumbActorsInCurrentSet,_AIClassCop|_AIClassWorker|_AIclassprost|_AIclasspimp|_AIclasspriest|_AIclassdweller|_AIclassscientist|_AIclassbarpeople|_AIclassmale|_AIclassfemale|_AIclassmedic|_AIclasssubgirl,TmpFloat);
//	print("Num Actors = ",TmpFloat);

//cop (only the Cops NOT possessed)
	if(VRank>=_RankSergeantL)
	{
		float(_set,PreCopActionBits,CopActionBits); //save previous action bits
		float(_set,PreCopStateBits,CopStateBits); //save previous state bits
		float(_set,CopStateBits,0); //clear state bits
		if(vaistate==_aistateattack)//in attack mode
		//if(CopActionBits==2)//combat flag
		{
//dmessage("in COMBAT mode",10,30);
			float(_set,CopActionBits,0);//clear initial combat bit
			float(_or,CopStateBits,1); //in COMBAT mode bit
		}
		if(VAItargetfound!=0 && VAItargetfound==_AIundetermined && vaistate!=_AIstateTurnToSound)
		{
//dmessage("Can HEAR character behind",20,30);
			callsub(Sub_RandomCopHearsBobSFX);
			float(_or,CopStateBits,2); //Can HEAR character behind bit
			callsub(TurnToFaceSound);
			call(AIorder,_set,_AIstateTurnToSound);
		}
		if(PreCopActionBits!=0 && PreCopActionBits<4)//attack: CopActionBits=1, combat: CopActionBits=2
		{
			if(VAItargetclass==_AIclassAngel)
			{
//dmessage("Cop saw Bob!",30,30);
				float(_set,CopActionBits,0);//clear initial attack bit
				float(_or,CopStateBits,4); //Just saw Bob as cherub (before going into attack mode) bit
				//spawnaction(CopGesture1);
				call(AIorder,_clr,_AIstateTurnToSound);
			//	call(AIorder,_set,_AIstateTurnToSoundSlow);
				call(AIorder,_set,_AIstateGestureAtBob);
			}
		}
		if(TmpFloat>1)//more than 1 character in room?
		{
//dmessage("more than 1 character in room",40,30);
			float(_or,CopStateBits,8); //more than one character in room
		}
		if(vtrigger==_DIRhavegun)//when NOT possessed by Bob
		{
//dmessage("cop carrying a weapon",50,30);
			float(_or,CopStateBits,16); //carrying a weapon bit
		}
		//if(VAItargetfound==_AIenemy && vaistate!=_aistateattack)//just saw enemy (not yet in attack mode)
		//if(CopActionBits!=0 && CopActionBits<4)
		if(PreCopActionBits!=0 && PreCopActionBits<4)
		{
//dmessage("Cop saw enemy possessed character",60,30);
			float(_set,CopActionBits,0);
			float(_or,CopStateBits,32); //just saw enemy (not yet in attack mode)
		}
		if(VHealth<=2500)
		{
//dmessage("energy low!",70,30);
			float(_or,CopStateBits,64); //energy low bit
		}
	}
//end
/////////////////////////////////////////////////////////////////////////////////////
//printi("VHealth: ",VHealth);//starts at 5000, then 4000, 3000 each time I kick another

*/
		if(VState!=StateExecutePathSequence)
		{
			if(aivisiontoggle==0)
			{
				call(AIcheckfortarget,VisionUpdateFrequency);
			}

//			if(VAItargetfound!=0 && VAItargetfound==_AIundetermined && vaistate!=_AIstateTurnToSound)
//			{
//				callsub(Sub_RandomCopHearsBobSFX);
//			}

			if(VAItargetfound==_AIgrenade)
			{
				//select grenade parent as target
				if(VAIState!=_AIstateAttack && VAIState!=_AIstateGuard && VAIState!=_AIstateHide && VAIState!=_AIstateSearch)
				{
					call(AIselecttarget,_AIgrenade);
					call(AIchangefriendtoenemy);
					call(AIalert,Sub_AISetAttack);
					sample(SFXGrenadeReact,-1);
					if(VAIhidenodenear!=0)
					{
						call(AIorder,_set,_AIstatehide);
						state(_clr,StateFollowPath);
						call(ClrPath);
					}
					else
					{
						//pick pos out of way
					}
				}
				else
				{

				}
			}

			if(VAIState!=_AIstateAttack && VAIState!=_AIstateHide)
			{
				call(AIcheckactoractions,10,GENPossesed); //only when possessing cop?
				if(VTrigger==_DIRTempFlag) //did character see cop being possessed
				{
		//dmessage("AIcheckactoractions CopPossesed",50,100);
					if(VRank>=_RankSergeantL)
					{
						sample(SFXPossesionReact,-1);
						call(AIsetlockedonactortotarget);
						if(VAIStateHigh!=_AIstayonpath && VAIStateHigh!=_AIstayonpath)
						{
							call(AIorder,_set,_AIstatePossesionReact);
							call(AIorder,_set,_AIinspecialmode);
							float(_set,AIChoiceVar,0);
						}
					}
					else
					{
						sample(SFXPossesionReact,-1);
						callsub(Sub_CivilianReactionToThreat);
					}
				}
			}

			call(AIcheckactoractions,10,GENDePossesed); //only when possessing cop?
			if(VTrigger==_DIRTempFlag) //did character see cop being possessed
			{
				call(AIclrlockedactorenemyflag);
				if(VAIQtargetislockedonactor!=0)
				{
					call(AIclrtarget);
				}
			}

			if(VAIState!=_AIstateAttack && VAIState!=_AIstateHide)	// && VAIState!=_AIstateGuard)
			{
				if(vtrigger==_DIRactorbulletcol)
				{
					if(VRank>=_RankSergeantL)
					{
						//if shot came from playerone, turn him into enemy
						call(AIcheckbulletorigin);
						if(vtrigger==_DIRTempFlag)
						{
							//turn player one into enemy
							call(AIsetlockedonactortotarget);
							call(AIchangetargettoenemy);
							call(AIalert,Sub_AISetAttack);
							CallSub(Sub_AISetAttack);
						}
					}
					else
					{
						callsub(Sub_CivilianReactionToThreat);
					}
				}

		//		if(VActorFlag==_AFLAGattached && VAction!=ProstKissingLink)	//for 2-man animation, changes guy who punches him in the face into an enemy
		//		{
		//			call(AIcheckattachactionorigin);
		//			call(AIchangetargettoenemy);
		//			call(AIsetlockedonactortotarget);
		//			call(AIchangetargettoenemy);
		//		}
			}
		}

		//printih("State:       ",vstate);
		printi("AIState:     ",vaistate);
		//printih("AIStateHigh: ",vaistatehigh);

		if(VActorFlag==_AFLAGattached)
		{
			//dummy to prevent ai from running
		}
		elseif(VActorFlag==_AFLAGradiated && Vactor!=RadiationWorker)
		{
			call(AIorder,_set,_AIstateRadioactive);
			call(AIorder,_set,_AIinspecialmode|_AIdontdopickdest);
		}
		elseif(vstate==StateFollowPath)
		{
			print("Im in follow path mode:  ",vstate);

			if(VAIstatehigh!=_AIdontdopickdest)
			{
				call(AIPickdest,10);
			}
			if(VAIstatehigh!=_AIinspecialmode)
			{
				if(vtrigger==_DIRtempflag && VAIstatehigh!=_AIdontdopickdest)
				{
					call(PickNewNode);
				}
			}
			else
			{
				//print("AAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
				print("AAHH! vstate=StateFollowPath & VAIstatehigh=_AIinspecialmode");
			}

			if(aivisiontoggle==0)
			{
				if(VAItargetfound!=0 && VAItargetfound==_AIenemy && VAIStateHigh!=_AIstayonpath)
				{
					if(VRank>=_RankSergeantL)
					{
						call(AIselecttarget,_AIenemy);
						if(VTrigger==_DIRTempFlag)
						{
							call(ClrPath);
							CallSub(Sub_AISetAttack);
							if(VAITargetClass==_AIclassAngel && AIEncounterVar==0)
							{
								sample(SFXReactToBob,-1);
								float(_add,AIEncounterVar,1);
							}
							call(AIalert,Sub_AISetAttack);
						}
					}
					else
					{
						call(AIselecttarget,_AIenemy);
						if(VTrigger==_DIRTempFlag)
						{
							if(VAItargetclass==_AIclassAngel)
							{
								//worker, civilian reactions to Bob or enemy
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
								elseif(VTargetDistance<400)
								{
									call(AIorder,_set,_AIstateReactToBob);
									call(AIorder,_set,_AIinspecialmode|_AInomove);
									if(vstate==StateCrouching)
									{
										direction(_set,_DIRcrouch);
									}
								}
								else
								{
									call(AIclrtarget);
								}
							}
							else
							{
								callsub(Sub_CivilianReactionToThreat);
							}
						}
					}
				}
				elseif(VRank>=_RankSergeantL)
				{
/*					//check for worker off path
					if(VAIClass==_AIClassCop && VAIStateHigh!=_AIstayonpath)
					{
						call(AIcheckactorstates,10,_AIclassworker,0,_AInotonpath);
						if(vtrigger==_DIRTempFlag && VAIstatehigh!=_AIlockedtoactor)
						{
							call(AIsetlockedonactortotarget);
							call(AIlockedtoactorflag,_set);
							call(AIorder,_set,_AIstateGetToWork);
							call(AIorder,_set,_AIinspecialmode);
							float(_set,AIChoiceVar,0);
							sample(SFXCopGetBackToWork1,-1);
						}
					}
*/
					//check for Combatmode Set
					if(VAIStateHigh!=_AIcombatmodereact && VAIState!=_AIstateCombatModeReact)
					{
						if(AIAbility&!=_AIANoCloseUpReaction)
						{
							call(AIcheckactordirections,10,_DIRcombatmode);
							if(VTrigger==_DIRTempFlag)
							{
								call(AIsetlockedonactortotarget);
								if(VAItargetstrenght!=0 && VAItargetseenme!=0 && VAITargetIsFriend!=0)
								{
									if(VAItargettrigger!=_DIRhavegun && VTargetDistance>700)
									{
										call(AIclrtarget);
									}
									else
									{
										call(AIorder,_or,_AIcombatmodereact);
										float(_set,CloseUpCounter,0);
										spawnaction(GENidle);
									}
								}
								else
								{
									call(AIclrtarget);
								}
							}

							call(AIcheckactordirections,10,_DIRillegalweapon);
							if(VTrigger==_DIRTempFlag)
							{
								call(AIsetlockedonactortotarget);
								if(VAItargetstrenght!=0 && VAITargetIsFriend!=0)
								{
									if(VTargetDistance>1500)
									{
										call(AIclrtarget);
									}
									else
									{
										call(AIorder,_or,_AIcombatmodereact);
										float(_set,CloseUpCounter,0);
										spawnaction(GENidle);
									}
								}
								else
								{
									call(AIclrtarget);
								}
							}
						}

						if(VAIClass==_AIClassChot && AIusage&=_AIUCrowdAroundLeader && VAIState!=_AIstateFollowTheLeader)
						{
							call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassChot,_GreaterEqual,_RankSergeantM);
							//print("NrChots in set: ",TmpFloat);
							if(TmpFloat!=0)
							{
								call(AIselecttarget,_AIfriend,_AIClassChot,_GreaterEqual,_RankSergeantM);
								if(VAIhastarget!=0)
								{
									call(AIOrder,_set,_AIstateFollowTheLeader);
									call(AIorder,_clr,_AInomove|_AInoturn);
									state(_or,StateFollowPath);
								}
							}
						}

					}
				}
				else
				{
					//reactions from civilians
				//	if(VTrigger!=_DIRcombatmode)
				//	{
						call(AIcheckactordirections,10,_DIRcombatmode|_DIRhavegun);
						if(VTrigger==_DIRTempFlag)
						{
							call(AIsetlockedonactortotarget);
							if(VAItargetstrenght!=0 && VTargetDistance<600 && VAItargetseenme!=0)
							{
								call(AIorder,_set,_AIstateSurrender);
								call(AIorder,_set,_AIinspecialmode);
							}
							else
							{
								call(AIclrtarget);
							}
						}
				//	}

					if(VAIState!=_AIstateSurrender && VTrigger!=_DIRhavegun && AIUsage&=_AIUAttackIfUnseen)
					{
						if(VAItargetfound!=0)
						{
							printi("attack from behind:   ",VAItargetfound);
							call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassCop|_AIClassChot);
							if(TmpFloat==1)		//make sure only 1 is in the scene
							{
								print("1 character in scene");
								call(AIselecttarget,0,_AIClassCop|_AIClassChot);
								if(VTrigger==_DIRTempFlag)
								{
									print("I can see you");
									if(VAItargettrigger==_DIRhavegun)	// does target carry gun
									{
										print("you have a gun");
										if(VAItargetseenme==0)
										{
											print("you cant see me");
											if(VTargetDistance<500)		//if he is close
											{
												print("You are close enough");
												//sneak after him and steal his weapon
												call(AIOrder,_set,_AIstateSneakUp);
												//call(ClrPath);
 												call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
												//call(AIorder,_set,_AIstateAttack);
												//state(_change,StateFollowPath,StateNormal);
											}
										}
									}
								}
								else
								{
									call(AIclrtarget);
								}
							}


						}
					}

				}

/*				if(VAItargetfound!=0 && VAItargetfound==_AIundetermined && VAIState!=_AIStateGuard)
				{
//dmessage("_AIundetermined",90,30);
					if(VRank>=_RankSergeantL)
					{
						//cop reaction to sound etc.
//dmessage("cop reaction to sound",50,10);
					}
					else
					{
						//civilian reaction to sound etc.
//dmessage("civilian reaction to sound",50,10);
					}
				}
*/
			}
		}
		elseif(vstate==StateExecutePathSequence)
		{
			if(VAIstatehigh!=_AIdontdopickdest)
			{
				call(AIPickdest,10);		//follow path
				if(vtrigger==_DIRtempflag)
				{
					state(_clr,StateExecutePathSequence);
					state(_or,StateFollowPath);
					call(ClrPath);
					call(PickNewNode);
				}
			}
		}
		//*****************
		//Group Leader Code
		//*****************
		elseif(VAIleader!=0)			//in charge
		{
	break();
			print("Im the Leader");
			call(AIPickdest,10);
			if(VAIgroupstate!=_AIstateidle && VAIgroupstate!=_AIstatesearch)//search should be widened to account for all attackstates
			{
				if(VAInotargettime<AINOTARGETTHRESHOLD)
				{
					call(AIasktojoin,_AIstateAttack);	//to make sure newcomers are asked to join for battle
					if(VAItargetfound!=_AIenemy && VAInotargettime<AINOTARGETSEARCHTHRESHOLD)
					{
						call(AIorder,_set,_AIstateSearch);
					}
					call(AIgrouppickdest);
				}
			}
			else
			{
				if(VAItargetfound==_AIenemy)	//just saw enemy
				{
					call(AIselecttarget,_AIenemy);
					call(AIorder,_set,_AIstateAttack);
				}
				elseif(VAIlasttargetfound|=_AIenemy)			//continue searching
				{
					if(VAInotargettime>AISTOPIFNOTARGETTHRESHOLD)		//check for release group
					{
						call(AIorder,_set,_AIstateAtEase);
						call(AIreleasegroup);
					}
					else
					{
						if(vaistate!=_AIstatesearch)
						{
							call(AIorder,_set,_AIstateSearch);
						}
					}
				}
				else									//nothing in sight. no present search
				{
					call(AIasktojoin,_AIstateIdle);			//join the idle formation
				}
			}
		}
		//*****************
		//Group member Code
		//*****************
		elseif(VAIingroup!=0)		//included in group
		{
	break();
			print("Im in a Group");
			if(VAIstatechanged!=0)
			{
				sample(SFXOrderYesSir1,-1);
			}

			if(VAIaskedtojoin!=0)
			{
				if(VAIchangetonewgroup!=0)
				{
					call(AIbreakfromgroup);
					call(AIjoinnewgroup);
				}
			}
			call(AIPickdest,10);
		}
		//****************
		//In No Group Code
		//****************
		elseif(vactivetime>10)
		{
			//print("Decide what to do");
			if(VAIaskedtojoin!=0)
			{
				if(VAIchangetonewgroup!=0)
				{
					call(AIjoinnewgroup);
					sample(SFXOrderYesSir1,-1);

					state(_or,StateExecuteAnim);
					spawnaction(CopAttention);
				}
				else
				{
					if(VAIleaderaspirations!=0)
					{
						call(AIasktojoin,_AIstateAttack);
						call(AIorder,_set,_AIstateattack);
					}
				}
			}
			if(vaistate==_AIstateGetWeapon)
			{
				call(AIPickdest,10);
				if(VTrigger!=_DIRhavegun)
				{
					call(IsPickupClose,_ClassWeapon,1000,TmpFloat,WeaponPickUpPos);
					if(vtrigger!=_DIRTempFlag)
					{
						call(AIorder,_set,_AIstateAttack);
					}
					else
					{
						vector(_setpathdest,WeaponPickUpPos);		//just in case position changed
					}
				}
				else
				{
					call(AIorder,_set,_AIstateAttack);
				}
				print("In Get Weapon State");
			}
			elseif(vaistate==_AIstateAttack)
			{
				//printi("Im in attack:   ",VAItargetfound);
				call(AIPickdest,10);

				if(VAItargetfound==_AIenemy)
				{
					//printi(Powerrating:    ",VAIpowerrating);
					
					if(VAIhastarget==0 || VAItimeincurrentorder>90)		//force selction of target every 3 seconds
					{
						call(AIselecttarget,_AIenemy);	//in no group. goes after the guy by himself
						if(VTrigger==_DIRTempFlag)
						{
							call(AIalert,Sub_AISetAttack);
						}
					}

					if(VAIHasTarget!=0)
					{
						call(AIupdatetargetpos);

						if(AIControl&=_AICHide)
						{
							if(VAIhidenodenear!=0)
							{
								call(AIorder,_set,_AIstateHide);
								state(_clr,StateFollowPath);
								call(ClrPath);
							}
						}

						if(VAITargetClass!=_AIclassAngel)
						{
							if(VAItargettrigger!=_DIRhavegun)
							{
								sample(SFXCombatModeReactNoGun,-1);
							}
							else
							{
								sample(SFXCombatModeReactGun,-1);
							}
						}

					}
					else
					{
						if(VAInotargettime>30)
						{
							if(VAITargetClass==_AIclassAngel)
							{
								sample(SFXReactToBobGone,-1);
							}
							call(AIorder,_set,_AIstateSearch);
						}
					}
				}
				else
				{
					if(VAIhastarget!=0 && VAItargetvisible!=0)		//if actor can see his targetactor but he changed from enemy to friend
					{
						call(AIchangetargettoenemy);				//change him to enemy again
					}
					call(AIupdatetargetpos);

					print("Leaving attack cause no target found");
					//if(vtrigger==_DIRtempflag || VAInotargettime>2000)
					if(VAInotargettime>30)
					{
						if(VAITargetClass==_AIclassAngel && VAITargetHealth>0)
						{
							sample(SFXReactToBobGone,-1);
						}
						call(AIorder,_set,_AIstateSearch);
					}
				}

				if(VAIhastarget!=0 && VAItargethealth<=0)
				{
					call(AIremovetargetfromvisionbuffer);
					call(AItransfertargetfromfriend);
					if(VAIhastarget==0)
					{
						callsub(Sub_AIGetBackToIdle);
					}
				}

				if(VTrigger!=_DIRhavegun && AIAbility&=_AIAPickUpWeapon)
				{
					//Check if weapon closeby
					//if so go for it
					call(IsPickupClose,_ClassWeapon,1000,TmpFloat,WeaponPickUpPos);
					if(vtrigger==_DIRTempFlag && TmpFloat!=0)
					{
						vector(_setpathdest,WeaponPickUpPos);
						call(AIorder,_set,_AIstateGetWeapon);
					}
				}
			}
			elseif(vaistate==_aistateSearch)
			{
				print("Im in search");
				//MISSING: pick random near node
				call(AIPickdest,10);
				if(VAItargetfound!=0 && VAItargetfound==_AIenemy)
				{
					call(AIorder,_set,_AIstateattack);
				}

				if(VAItimeincurrentorder>AIPatience || VTargetDistance<170 || VAItargethealth<=0)
				{
					if(VAIlosttargetptr!=0 || VAITargetHealth<=0)
					{
						if(VAITargetHealth<=0)
						{
							call(AIremovetargetfromvisionbuffer);
						}
						call(AItransfertargetfromfriend);
						if(VAIhastarget==0)
						{
							callsub(Sub_AIGetBackToIdle);
						}
					}
				}
			}
			elseif(vaistate==_AIstateHide)
			{
				printi("AIstate hide:  ",VAItimeincurrentorder);
				if(VAItargetfound==_AIenemy)
				{
					if(VAIhastarget==0 || VAItimeincurrentorder>90)		//force selction of target every 3 seconds
					{
						call(AIselecttarget,_AIenemy);				//in no group. goes after the guy by himself
						if(VTrigger==_DIRTempFlag)
						{
							call(AIalert,Sub_AISetAttack);
						}
					}
					call(AIupdatetargetpos);
				}
				else
				{
					printi("HIDE: AITarget visible:  ",VAItargetvisible);
					if(VAIhastarget!=0 && VAItargetvisible!=0)		//if actor can see his targetactor but he changed from enemy to friend
					{
						call(AIchangetargettoenemy);				//change him to enemy again
					}
					call(AIupdatetargetpos);
				}
				call(AIPickdest,10);

				if(VAIlosttargetptr!=0 || VAITargetHealth<=0)
				{
					if(VAITargetHealth<=0)
					{
						call(AIremovetargetfromvisionbuffer);
					}
					call(AItransfertargetfromfriend);

					if(VAIhastarget==0)
					{
						print("Exiting hide mode");
						state(_clr,StateFollowPath);
						call(AIclrhidenode);
						call(ClrPath);
						callsub(Sub_AIGetBackToIdle);
						if(vstate==StateCrouching)						//To get rid of crouching when he is running to new Hide
						{
							direction(_set,_DIRcrouch);
						}
					}
				}
			}
			elseif(VAItargetfound!=0)
			{
				printi("Im in targetfound:    ",VAItargetfound);
				if(VAItargetfound==_AIenemy)	// && VRank>=_RankSergeantL)
				{
					call(AIorder,_set,_AIstateattack);
					if(VAIleaderaspirations!=0)
					{
						//call(AIasktojoin,_AIstateAttack);
						//call(AIorder,_set,_AIstateattack);
						//sample(SFXOrderGetHim,-1);
					}
				}
				elseif(VAITargetFound==_AIundetermined)
				{
					print("Target undetermined");
					//call(AIselecttarget,_AIundetermined);
					//call(AIorder,_set,_AIstateSearch);
				}
				else
				{
					//resets back to idle if no enemy found. Should use threshold values.
					CallSub(Sub_AIGetBackToIdle);
				}
				call(AIPickdest,10);
			}
			else
			{
				print("Im in changetoidle");
				CallSub(Sub_AIGetBackToIdle);
				call(AIPickdest,10);
			}

			if(VAIState!=_AIstatePatrol)
			{
				if(AIUsage&=_AIUAdvanceIfEnemyUnseen)
				{
					if(VAITargetFound==_AIenemy)
					{
						call(AIorder,_or,_AInomove);
						call(AIorder,_clr,_AInoturn);
					}
					else
					{
						call(AIorder,_clr,_AInomove|_AInoturn);
					}
				}
				//if(AIUsage&=_AIUCrouchToDefend)
				//{
				//	call(AIOrder,_set,_AIstateRiotCop)
				//}
			}
		}

		if(VActorFlag==_AFLAGattached)
		{
			//dummy to prevent ai from running
		}
		elseif(VAIState==_AIstateConfused)							//defenceless state, therefore should override any attack/defend states
		{
			print("In confused state:   ",AIChoiceVar);
			if(VAction!=CopDizzy)
			{
				SpawnAction(CopDizzy);
				float(_set,AIChoiceVar,100);
			}
			else
			{
				float(_sub,AIChoiceVar,1);
				if(AIChoiceVar<0)
				{
					CallSub(Sub_AIGetBackToIdle);
					SpawnAction(GENidle);
					ActorFlag(_clr,_AFLAGconfused);
					State(_clr,StateExecutePathSequence);
				}
			}
			if(VTrigger==_DIRcombatmode)
			{
				Direction(_clr,_DIRcombatmode);
			}
		}
		elseif(VAIState==_AIstateRadioactive)						//defenceless state, therefore should override any attack/defend states
		{
			if(VActorFlag!=_AFLAGradiated)
			{
				ActorFlag(_clr,_AFLAGradiated);
				call(AIorder,_clr,_AIstateRadioactive);
				call(AIorder,_clr,_AIinspecialmode|_AIdontdopickdest);
				SpawnAction(GENIdle);
			}
			else
			{
				ActorFlag(_clr,_AFLAGradiated);

				print("mofo i'm radioactive:   ",AIChoiceVar);
				call(SubtractHealth,0,DamageRadioactive);
				if(VAction!=CopDizzy)
				{
					SpawnAction(CopDizzy);
					float(_set,AIChoiceVar,100);
				}
				else
				{
					float(_sub,AIChoiceVar,1);
					if(AIChoiceVar<0)
					{
						CallSub(Sub_AIGetBackToIdle);
						SpawnAction(GENidle);
						ActorFlag(_clr,_AFLAGradiated);
					}
				}
				sample(SFXRadiationReact,-1);
			}
		}
		elseif(VAIStatehigh==_AIcombatmodereact)
		{
			print("Combat mode react:  ",CloseUpCounter);
			call(AIOrder,_or,_AInomove|_AInoturn|_AIstayonpath);

			if(CloseUpCounter==0)
			{
				if(VAItargettrigger==_DIRillegalweapon)
				{
					sample(SFXIllegalWeaponReact,-1);
				}
				else
				{
					if(VAItargettrigger!=_DIRhavegun)
					{
						sample(SFXCombatModeReactNoGun,-1);
					}
					else
					{
						sample(SFXCombatModeReactGun,-1);
					}
				}
			}

			call(AIsetlockedonactortotarget);
			callsub(Sub_AI1WayAlignToTarget);
			if(VTargetAngle>-50 && VTargetAngle<50)
			{
				if(VAction!=CopGesture1)
				{
					SpawnAction(CopGesture1);
				}
			}

			if(VAItargettrigger!=_DIRcombatmode && VAItargettrigger!=_DIRillegalweapon)
			{
				call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction|_AIcombatmodereact);
				SpawnAction(GENidle);
				float(_set,CloseUpCounter,-100);
				call(AIclrtarget);
			}
			elseif(CloseUpCounter==120 || VAITargetIsFriend==0)
			{
				call(AIchangetargettoenemy);
				//call(AIorder,_set,_AIstateCombatModeReact);
				//call(AIorder,_set,_AIinspecialmode);
				//float(_set,AIChoiceVar,0);
				SpawnAction(GENidle);
				call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction|_AIcombatmodereact);

				if(VRank>=_RankSergeantL)
				{
					call(AIchangefriendtoenemy);
					CallSub(Sub_AISetAttack);
					Call(AIalert,Sub_AISetAttack);
				}
				float(_set,CloseUpCounter,-100);
			}
		}
		elseif(VAIStatehigh==_AIcloseupaction)
		{
			print("In close up action. What up:  ",CloseUpCounter);
			call(AIOrder,_or,_AInomove|_AInoturn|_AIstayonpath);

			call(AIcheckforplayerone,300);
			if(VTrigger==_DIRTempFlag)
			{
				call(AIsetlockedonactortotarget);
				if(VAITargetIsFriend!=0 && VAItargetclass!=_AIclassanimal)
				{
					if(CloseUpCounter==0)
					{
						SpawnAction(GENidle);
					}

					if(VAIState==_AIstateWeldKneel)
					{
						if(VAction!=WorkerRepresentKneel)
						{
							SpawnAction(WorkerRepresentKneel);
							float(_set,CloseUpCounter,1);
							sample(SFXChat,-1);
						}
						if(CloseUpCounter>150 || VTrigger!=_DIRnotendofanim)
						{
							call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction);
							call(AIclrtarget);
							float(_set,CloseUpCounter,1);
							spawnaction(GENidle);
						}
					}
					else
					{
						//if(VAIState==....			//list of states that shouldn't face
						callsub(Sub_AI1WayAlignToTarget);
						if(VTargetAngle>-50 && VTargetAngle<50)
						{
							if(VAItargetclass==_AIclassAngel)
							{
								sample(SFXReactToBob,-1);
								if(VAction!=CopRepresent && VAction!=CopRepresentIdle)
								{
									SpawnAction(CopRepresent);
								}
							}
							else
							{
								if(VAction!=CopRepresent && VAction!=CopRepresentSalute && VAction!=CopRepresentShort && VAction!=CopRepresentIdle)
								{
									elseif(CloseUpCounter>1350)
									{
										sample(SFXChat,-1);
										SpawnAction(CopRepresent);
									}
									else
									{
										if(VAItargetclass==_AIclassCop|_AIclassFemale)
										{
											SpawnAction(CopRepresentSalute);
										}
										else
										{
											sample(SFXChatFirsttime,-1);
											SpawnAction(CopRepresentShort);
										}
									}
									float(_set,CloseUpCounter,1);
								}
							}
							if(CloseUpCounter>150)
							{
								call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction);
								call(AIclrtarget);
								float(_set,CloseUpCounter,1);
								spawnaction(GENidle);
							}
						}
					}
				}
				else
				{
					print("Clr closeupaction    66666666666666666");
					call(AIclrtarget);
					call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction);
				}
			}
			else
			{
				if(VState!=StateCrouching)
				{
					spawnaction(GENidle);
				}
				call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction);
				call(AIclrtarget);
				float(_set,CloseUpCounter,1);
			}

			if(VRank<_RankSergeantL)
			{
				call(AIcheckactordirections,10,_DIRcombatmode|_DIRhavegun);
				if(VTrigger==_DIRTempFlag)
				{
					call(AIsetlockedonactortotarget);
					if(VTargetDistance<600 && VAItargetseenme!=0)
					{
						call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction);
						call(AIorder,_set,_AIstateSurrender);
						call(AIorder,_set,_AIinspecialmode);
					}
				}
			}

			if(VAItargetfound==_AIenemy && VAItargetvisible!=0)
			{
				call(AIOrder,_clr,_AInomove|_AInoturn|_AIstayonpath|_AIcloseupaction);
				call(AIclrtarget);
			}
		}
		elseif(VAIState==_AIstateIdle)
		{
			//Direction(_clr,_DIRMove);			//XXX shouldn't be there. If it breaks talk to SAXS
			/*
			if(VPlayer1Distance<90000 && CloseUpCounter>150 && AIAbility&!=_AIANoCloseUpReaction)	//300*300
			{
				call(AIOrder,_or,_AIcloseupaction);
				float(_set,CloseUpCounter,0);
			}
			*/
			sample(SFXBoredIdle,-1);
		}
		elseif(VAIState==_AIstatePatrol)
		{
			if(VPlayer1Distance<90000 && CloseUpCounter>150 && AIAbility&!=_AIANoCloseUpReaction)	//300*300
			{
				call(AIOrder,_or,_AIcloseupaction);
				float(_set,CloseUpCounter,0);
			}
			sample(SFXBoredIdle,-1);
		}
		elseif(vaistate==_AIstateSmoke)
		{
			if(VPlayer1Distance<90000 && CloseUpCounter>150 && AIAbility&!=_AIANoCloseUpReaction)	//300*300
			{
				call(AIOrder,_or,_AIcloseupaction);
				float(_set,CloseUpCounter,0);
			}
			print("In state smoke");
			if(VAIstatechanged!=0)
			{
			//	if(vrnd<20)
			//	{
					float(_declare,CopSmokeTimer,500);
					float(_set,AIChoiceVar,1);
			//	}
			//	elseif(vrnd<10)
			//	{
			//		float(_set,AIChoiceVar,2);
			//	}
			//	else
			//	{
			//		float(_set,AIChoiceVar,0);
			//		call(AIorder,_set,_AIstatePatrol);
			//		call(PickNewNode);
			//	}
			}
			if(AIChoiceVar==1)
			{
				print("In state smoke choice 1");
				if(VTrigger!=_DIRNotEndOfAnim && vaction!=CopSmoke && vaction!=CopLightSmoke && vaction!=CopStopSmoke && vaction!=CopChokingCough)
				{
					spawnaction(CopLightSmoke);
				}
				else
				{
					//direction(_clr,_DIRMoveBits);
				}

				if(vaction==CopLightSmoke)
				{
					if(vframe>=165 && vframe<=190)		//match strike 165-190, brightest flickering burn
					{
						//match strike sample
						//red smoke
					}
					elseif(vframe>190&&vframe<=290)		//match burns from 190-290, both from left hand
					{
						//red smoke from above to subtractive smoke
					}
					elseif(vframe>=250&&vframe<=300)	//puffing just lit cigarette 250-300, puffing to get it lit
					{
						//puffing sample
					}
				}
				elseif(vaction==CopSmoke)
				{
					//constant smoke effects floating upwards
					if(vrnd<10)
					{
						spawnparticle(fx_fagsmoke,8,emptyvector,emptyvector,-1);
					}

					if(vframe>=45&&vframe<=90)
					{
						//vector(_set,tmpvector,255,64,0);
						//spawnlight(Lomnilight2,4,emptyvector,tmpvector,EmptyVector,10);
						if(vframe==45)
						{
							sample(SFXSmokePuffPuff,-1);
						}
					}
					elseif(vframe>=150&&vframe<=210)
					{
						if(vrnd<50)
						{
							vector(_set,gactorpos,-8,6,16);
							spawnparticle(fx_fagblow,4,gactorpos,emptyvector,-1);
						}

						if(vframe==150)
						{
							sample(SFXSmokeExhale,-1);
						}
					}
				}
				elseif(vaction==CopStopSmoke)
				{
					if(vframe==10)						//throwing cigarette,  Spawn the particle at frame 10
					{
						//sprite cigarette with small red flare and grey smoke
					}
				}

				if(vaction==CopSmoke)					//in smoking idle
				{
					if(CopSmokeTimer==0)
					{
						spawnaction(CopStopSmoke);		//finish smoking
						float(_set,CopSmokeTimer,500);
					}
					else
					{
						float(_sub,CopSmokeTimer,1);
					}
				}
			}
			elseif(AIChoiceVar==2)
			{
				print("In state smoke choice 2");
				if(vtrigger==_DIRhavegun)
				{
					direction(_set,_DIRaction);
				}
				elseif(vaction!=CopBongSmoke)
				{
					spawnaction(CopBongSmoke);
				}
				else
				{
					direction(_clr,_DIRMoveBits);

					if(vframe==125)
					{
						sample(SFXBong,-1);
					}
					elseif(vframe==260)
					{
						sample(SFXBongCough,-1);
					}
					if(vendofanim!=0)
					{
						call(AIorder,_set,_AIstatePatrol);
						call(PickNewNode);
						direction(_set,_DIRaction);
						float(_set,ActionOK,1);
					}
				}
			}
		}
		elseif(VAIstatechanged!=0 && VAIlaststate==_AIstateSmoke)
		{
			print("Was in smoke");
			spawnaction(CopIdle);
			//call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
			//call(AIorder,_set,_AIstateIdle);
			call(ClrPath);
		}
		elseif(vaistate==_AIstatePressButton)
		{
			print("Pressing button");
			direction(_set,_DIRaction);
			float(_set,ActionOK,1);
		}
		elseif(vaistate==_AIstateWeldKneel)
		{
			//sample(SFXWelderWhistle,-1);
			sample(SFXBoredIdle,-1);

			if(VPlayer1Distance<90000 && CloseUpCounter>150 && AIAbility&!=_AIANoCloseUpReaction)	//300*300
			{
				call(AIOrder,_or,_AIcloseupaction);
			}

			print("In Weld Kneeling");
			if(VWeaponType==WeaponTorch || VWeaponType==WeaponBuzzSaw)
			{
				if(VPickDestAngle<20 && VPickDestAngle>-20)
				{
					if(vaction!=WorkerWeldingKneel)
					{
						actorflag(_or,_AFLAGnomove);
						spawnaction(WorkerWeldingKneel)
					}
					Direction(_set,_DIRcombatmode);
					Direction(_set,_DIRHaveGun);
					Direction(_set,_DIRshoot);
				}
			}
			if(VPathDestDistance>40 && VAction==WorkerWeldingKneel)
			{
				print("Was In Weld");
				spawnaction(CopIdle);
				actorflag(_clr,_AFLAGnomove);
				call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				call(AIorder,_set,_AIstateIdle);
				call(ClrPath);
			}
		}
		elseif(VAIState==_AIStateWatchTV)
		{
			print("Watching TV Normal at : ",VPathDestDistance);

			if(VPlayer1Distance<90000 && CloseUpCounter>150 && AIAbility&!=_AIANoCloseUpReaction)	//300*300
			{
				call(AIOrder,_or,_AIcloseupaction);
				float(_set,CloseUpCounter,0);
			}

			if(VPathDestDistance>40 && VAction==CopWatchTVActive)
			{
				
				spawnaction(CopIdle);
				call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				call(AIorder,_set,_AIstateIdle);
				call(ClrPath);
			}
			else
			{
				print("VPickDestAngle For TV Normal : ",VPickDestAngle);
				if(VPickDestAngle<20 && VPickDestAngle>-20)
				{
					if(vaction!=CopWatchTVActive)
					{
						actorflag(_or,_AFLAGnomove);
						spawnaction(CopWatchTVActive)
					}
				}
			}
		}
		elseif(VAIState==_AIStateWatchTVIdle)
		{
			print("Watching TV Idle at : ",VPathDestDistance);
			if(VPathDestDistance>40 && VAction==CopWatchTVIdle)
			{
				spawnaction(CopIdle);
				call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				call(AIorder,_set,_AIstateIdle);
				call(ClrPath);
			}
			else
			{
				print("VPickDestAngle For TV Idle : ",VPickDestAngle);
				if(VPickDestAngle<20 && VPickDestAngle>-20)
				{
					if(VAction!=CopWatchTVIdle)
					{
						actorflag(_or,_AFLAGnomove);
						spawnaction(CopWatchTVIdle);
					}
				}
			}
		}
		elseif(VAIState==_AIstatePushUp)
		{
			print("in pushup");
			if(VPickDestAngle<20 && VPickDestAngle>-20)
			{
				if(vaction!=CopPushUpsLoop)
				{
					actorflag(_or,_AFLAGnomove);
					spawnaction(CopPushUpsLoop)
				}
				else
				{
					state(_or,StateCrouching);
				}
			}
			if(VPathDestDistance>40 && VAction==CopPushUpsLoop)
			{
				spawnaction(CopIdle);
				call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				call(AIorder,_set,_AIstateIdle);
				call(ClrPath);
			}
		}
		elseif(VAIState==_AIstateShadowBoxing)
		{
			print("in Shadow Boxing");
			if(VPickDestAngle<40 && VPickDestAngle>-40)
			{
				float(_add,PunchTimer,1);
				if(PunchTimer<=200)
				{
					if(vaction!=CopShadowBoxingIdle)
					{
						spawnaction(CopShadowBoxingIdle)
					}
				}
				elseif(PunchTimer<=220)
				{
					if(vaction!=CopShadowBoxingPunch)
					{
						spawnaction(CopShadowBoxingPunch)
					}
				}
				if(PunchTimer>220)
				{
					float(_set,PunchTimer,0);
				}
			}
		}
		elseif(vaistate==_AIstateWork)
		{
			if(VAIclass==_AIclassmedic)
			{
				if(VAction!=MedicWorking)
				{
					SpawnAction(MedicWorking);
				}
			}
		}
		elseif(vaistate==_AIstateWorkWeld)
		{
			//callsub(Sub_AI1WayAlignToTarget);
			print("In Weld");

			//sample(SFXWelderWhistle,-1);
			sample(SFXBoredIdle,-1);

			if(VWeaponType==WeaponTorch || VWeaponType==WeaponBuzzSaw)
			{
				if(VPickDestAngle<20 && VPickDestAngle>-20)
				{
					if(vaction!=WorkerWelding)
					{
						spawnaction(WorkerWelding);
					}
					Direction(_set,_DIRcombatmode);
					Direction(_set,_DIRHaveGun);
					direction(_set,_DIRshoot);
				}
			}
			if(VPathDestDistance>40 && VAction==WorkerWelding)
			{
				print("Was In Weld");
				spawnaction(CopIdle);
				call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				call(AIorder,_set,_AIstateIdle);
				call(ClrPath);
			}
		}
		elseif(vailaststate==_AIstateWorkWeld || vailaststate==_AIstateWorkWeld)
		{
			if(VAIstate!=_AIstateCowering)		//include any state that is spwned by outside code like attack reactions etc.
			{
				print("Was In Weld");
				spawnaction(CopIdle);
				call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				call(AIorder,_set,_AIstateIdle);
				call(ClrPath);
			}
		}
		elseif(vaistate==_AIstateGetToWork)
		{
			call(AIcheckactorstatesneg,0,_AIclassworker,0,_AInotonpath);
			if(vtrigger!=_DIRTempFlag)
			{
				call(AIchangeenemytofriend);
				callSub(Sub_AIGetBackToIdle);
			}
			else
			{
				call(AIupdatetargetpos);
				if(AIChoiceVar==0)
				{
					if(VTargetDistance<500 && vaistatehigh!=_AInomove)
					{
						call(AIorder,_set,_AInomove);
					}
					if(vaistatehigh==_AInomove && VAItimeincurrentorder>100)
					{
						float(_set,AIChoiceVar,1);
						sample(SFXCopGetBackToWork2,-1);
						spawnaction(CopGesture2);
						call(AIorder,_set,_AInomove);		//XXX to reset timeincurrentorder
					}
				}
				elseif(AIChoiceVar==1)
				{
					if(VAItimeincurrentorder>100)
					{
						call(AIorder,_clr,_AInomove|_AInoturn);
						float(_set,AIChoiceVar,2);
						CallSub(Sub_AISetCombatMode);
						sample(SFXCopGetBackToWork3,-1);
						spawnaction(CopGesture1);
					}
				}
				elseif(AICHoiceVar==2)
				{
					if(VTargetDistance<300 && vaistatehigh!=_AInomove)
					{
						call(AIorder,_set,_AInomove);
					}
					if(VAItimeincurrentorder>100)
					{
						call(AIchangefriendtoenemy);
						call(AIlockedtoactorflag,_clr);
						CallSub(Sub_AISetAttack);
						float(_set,AIChoiceVar,0);
					}
				}
			}
		}
		elseif(vaistate==_AIstateCombatModeReact)
		{
			if(VRank>=_RankSergeantL)
			{
				sample(SFXCombatModeReactGun,-1);
				call(AIchangefriendtoenemy);
				CallSub(Sub_AISetAttack);
				Call(AIalert,Sub_AISetAttack);
			}
		}
		elseif(vaistate==_AIstatePossesionReact)
		{
			if(VRank>=_RankSergeantL)
			{
				CallSub(Sub_AISetAttack);
			}
			else
			{
				float(_set,AIEncounterVar,2);
				//panic
				//for now just go back to idle
				CallSub(Sub_AIGetBackToIdle);
			}
		}
		elseif(vaistate==_AIstateReactToBob)
		{
			print("In bob reaction   ");
			if(VAItimeincurrentorder==0 && AIEncounterVar<=1)
			{
				if(AIEncounterVar==0)				//first encounter
				{
					sample(SFXReactToBob,-1);
					float(_set,AIEncounterVar,1);
					spawnaction(WorkerWhatThe);
				}
				elseif(AIEncounterVar==1)			//second encounter, no possesion
				{
					//gesture to "get away"
					spawnaction(WorkerGetLost);
					if(VAItargethealth>0)//only when Bob is NOT dead
					{
						sample(SFXReactToBob,-1);
					}
				}
			}
			else
			{
				if(AIEncounterVar==2)
				{
					if(VAIhidenodenear!=0)
					{
						call(AIorder,_set,_AIstatehide);
						call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
						state(_clr,StateFollowPath);
						call(ClrPath);
					}
					else
					{
						//if no hidenode can be found search for node far away and run there
						//for now just go back to idle
						CallSub(Sub_AIGetBackToIdle);
					}
				}
				if(VEndOfAnim!=0)
				{
					CallSub(Sub_AIGetBackToIdle);
					//call(AIorder,_clr,_AIinspecialmode|_AInomove|_AInoturn);
				}
			}
		}
		elseif(vaistate==_AIstateCowering)
		{
			if(vstate!=StateOnFire && vstate!=StateSteamed && vstate!=StateBlind && VActorFlag!=_AFLAGSniped)
			{
				if(vaction!=GENCoweringLoop)
				{
					SpawnAction(GENCoweringLoop);
					float(_set,AIChoiceVar,0);
				}
				else
				{
					if(VAITargetClass==_AIclassAngel)
					{
						sample(SFXReactToBobMoreCops,-1);
					}
					float(_add,AIChoiceVar,1)
					if(AIChoiceVar>840 && VRnd<7)
					{
						CallSub(Sub_AIGetBackToIdle);
						State(_clr,StateCrouching);
						Direction(_clr,_DIRcrouch);
						SpawnAction(GENEndCower);
					}
				}
			}
		}
		elseif(VAIState==_AIstateDropBattery)
		{
			if(VAIClass==_AIClassScientist)
			{
				if(Vaction!=NukeBatteryDrop && VTrigger==_DIRhavegun && VWeaponAmmoType==_AmmoBattery && VWeaponAmmoLeft!=0)
				{
					if(vpickdestanglecorr>-20 && vpickdestanglecorr<20)
					{
						spawnaction(NukeBatteryDrop);
						sample(SFXDropBattery,-1);
					}
				}
			}
		}
		elseif(VAIState==_AIStateShoot)
		{
			if(VAIClass==_AIClassScientist)
			{
				if(Vaction!=NukeBatteryPick && VTrigger==_DIRhavegun && VWeaponAmmoType==_AmmoBattery && VWeaponAmmoLeft==0)
				{
					if(vpickdestanglecorr>-20 && vpickdestanglecorr<20)
					{
						spawnaction(NukeBatteryPick);
					}
				}
			}
			else
			{
				if(vtrigger==_DIRHAveGun)
				{
					if(vtrigger!=_DIRcombatmode)
					{
						float(_set,SubVar1,0);
						direction(_set,_DIRcombatmode);
					}
					else
					{
						float(_add,SubVar1,1)
						if(SubVar1>=50)
						{
							direction(_or,_DIRShoot);
						}
						if(SubVar1>=55)
						{
							direction(_clr,_DIRShoot);
							float(_set,SubVar1,0);
						}
					}
				}
			}
		}
		elseif(vaistate==_AIstateGuard)
		{
			print("In state guard");
			call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn|_AIstayonpath);

			if(VPlayer1Distance<90000 && CloseUpCounter>150 && AIAbility&!=_AIANoCloseUpReaction)	//300*300
			{
				call(AIOrder,_or,_AIcloseupaction);
				float(_set,CloseUpCounter,0);
			}

			if(VAIhastarget!=0 || VAItargetfound==_AIenemy)
			{
				if(VAIhastarget==0 || VAItimeincurrentorder>90)		//force selction of target every 3 seconds
				{
					call(AIselecttarget,_AIenemy);				//in no group. goes after the guy by himself
					if(VTrigger==_DIRTempFlag)
					{
						call(AIalert,Sub_AISetAttack);
					}
				}
				elseif(VAItargetvisible!=0 && VAItargetfound!=_AIenemy)		//if actor can see his targetactor but he changed from enemy to friend
				{
					call(AIchangetargettoenemy);						//change him to enemy again
				}

				if(VAIHasTarget!=0)
				{
					call(AIupdatetargetpos);
				}

				print("In guard mode and has target");
				if(vtrigger!=_DIRcombatmode)
				{
					ActorFlag(_or,_AFLAGsniper);
					direction(_set,_DIRcombatmode);
				}
				CallSub(Sub_AI1WayAlignToTarget);
				CallSub(Sub_AIShootCheck,false,0,Counter,AIGrenadeCounter,AIAbility);

				printi("No Target Time:   ",VAInotargettime);
				if(VAInotargettime>AINOTARGETTHRESHOLD || VAItargethealth<=0)
				{
					call(AIclrtarget);
				}
			}
			elseif(vtrigger==_DIRcombatmode)
			{
				ActorFlag(_clr,_AFLAGsniper);
				direction(_clr,_DIRcombatmode);
			}

			if(vtrigger==_DIRactorbulletcol)
			{
				//if shot came from playerone, turn him into enemy
				call(AIcheckbulletorigin);
				if(vtrigger==_DIRTempFlag)
				{
					//turn player one into enemy
					call(AIsetlockedonactortotarget);
					call(AIchangetargettoenemy);
					call(AIalert,Sub_AISetAttack);
					CallSub(Sub_AISetAttack);
				}
			}

		}
		elseif(VAIstatechanged!=0 && VAIlaststate==_AIStateGuard)
		{
			ActorFlag(_clr,_AFLAGsniper);
			call(ClrPath);
		}

		elseif(vaistate==_AIstatePressAlarmButton)
		{
	printilog("In alarm state:  ",VGameCounter);
			if(vpickdestanglecorr<128 && vpickdestanglecorr>-128)
			{
				direction(_set,_DIRaction);
				float(_set,ActionOK,1);
				call(ClrPath);
				if(VRank<_RankSergeantL)
				{
					CallSub(Sub_SetCoweringMode);
				}
				else
				{
					CallSub(Sub_AIGetBackToIdle);
				}
			}
		}
		elseif(VAIstate==_AIStateRun)
		{
			print("In state run");
		}
		elseif(VAIState==_AIstateSurrender)
		{
			if(VTrigger==_DIRhavegun)
			{
				if(AIAbility&=_AIAPickUpWeapon)
				{
					call(CheckAttached,_CADropWeaponAndShells);
				}
			}
			if(VAction!=GENSurrender && VAction!=GENCrouchSurrender)
			{
				if(VAction!=GENCoweringLoop && VState!=StateCrouching)
				{
					SpawnAction(GENSurrender);
				}
				else
				{
					SpawnAction(GENCrouchSurrender);
				}
			}
			if(VAItimeincurrentorder>100)
			{
				CallSub(Sub_SetCoweringMode);
			}
			if(VAItargettrigger!=_DIRhavegun)
			{
				sample(SFXCombatModeReactNoGun,-1);
			}
			else
			{
				sample(SFXCombatModeReactGun,-1);
			}
		}
		elseif(VAIState==_AIstateSneakUp)
		{
			printi("In sneak up state:  ",VTargetDistance);
			if(VAItargetseenme!=0)
			{
				print("Spotted. OOOpppss");
				CallSub(Sub_AIGetBackToIdle);
				SpawnAction(DwellerCaughtSneakingUp);
			}

			if(VTargetDistance<120)
			{
				if(VTrigger!=_DIRcombatmode)
				{
					Direction(_set,_DIRcombatmode);
				}
				Direction(_set,_DIRshoot);
				call(AIorder,_set,_AInomove);
			}
		}
		elseif(VAIState==_AIstateRiotCop)
		{
			printi("In riot cop mode:  ",VTargetDistance);

			if(VAIhaspath!=0)
			{
//				call(AIOrder,_or,_AInomove|_AIstayonpath|_AIinspecialmode|_AInoturn);
			}

			if(VAIhastarget!=0)
			{
				if(VTargetDistance<250)
				{
					Direction(_or,_DIRshoot);
				}

				if(VAItargetfound==_AIenemy)
				{
//					call(AIupdatetargetpos);
//					call(AIselecttarget,_AIenemy);
					if(VAItargetseenme!=0 && VAItargettrigger==_DIRcombatmode && VAItargettrigger==_DIRhavegun)
					{
						if(vstate!=StateCrouching)
						{
							direction(_set,_DIRcrouch);
						}
						print("riotcop no move");
						call(AIorder,_or,_AInomove);
						ActorFlag(_or,_AFLAGshieldon);
					}
					else
					{
						print("riotcop move");
						call(AIorder,_clr,_AInomove|_AInoturn);
						ActorFlag(_clr,_AFLAGshieldon);
						if(vstate==StateCrouching)
						{
							direction(_set,_DIRcrouch);
						}
					}
				}
/*				else
				{
					ActorFlag(_clr,_AFLAGshieldon);
					call(AIorder,_set,_AIstateAttack);

					if(vstate==StateCrouching)
					{
						direction(_set,_DIRcrouch);
					}
				}
*/
			}
		}
		elseif(VAIState==_AIstateFollowTheLeader)
		{
			//only happens in idle mode
			print("Crowd around leader");
			call(AIorder,_clr,_AInomove|_AInoturn);
			if(VAIhastarget!=0)
			{
				if(VAItargethealth<=0)
				{
					call(AIclrtarget);
				}
				else
				{
					print("I have a target");
					call(AIupdatetargetpos);
				}
			}
			else
			{
				print("Found no target for crowding");
				call(GetNumbActorsInCurrentSet,TmpFloat,_AIClassChot,_GreaterEqual,_RankSergeantM);
				print("NrChots: ",TmpFloat);
				if(TmpFloat!=0)
				{
					call(AIselecttarget,_AIfriend,_AIClassChot,_GreaterEqual,_RankSergeantM);
				}
				else
				{
					CallSub(Sub_AIGetBackToIdle);
				}
			}
		}
		elseif(VAIState==_AIStateDetachFromPath)
		{
			state(_clr,StateExecutePathSequence);
			state(_or,StateFollowPath);
			call(ClrPath);
			call(PickNewNode);
			call(AIorder,_set,_AIstatepatrol);
		}
		elseif(VAIState==_AIstateDetachReattachToPath)
		{
			call(DetachReattachToPath);
		}
		elseif(VAIState==_AIstateDJPuke)
		{
			ActorFlag(_or,_AFLAGnorotation);
			if(VAction!=DJPuke)
			{
				sample(SFXPuking,-1);
				SpawnAction(DJPuke);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDJChillyChill1)
		{
			if(VAction!=DJChillyChill1)
			{
				SpawnAction(DJChillyChill1);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDJChillyChill2)
		{
			if(VAction!=DJChillyChill2)
			{
				SpawnAction(DJChillyChill2);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDJChillyChill3)
		{
			if(VAction!=DJChillyChill3)
			{
				SpawnAction(DJChillyChill3);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDJSpinRekids)
		{
			if(VAction!=DJSpinRekids)
			{
				SpawnAction(DJSpinRekids);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateFreakyManDance)
		{
			if(VAction!=ManDance)
			{
				SpawnAction(ManDance);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIStateSmokeBong)
		{
			if(VAction!=SmokeBong)
			{
				SpawnAction(SmokeBong);
			}
			else
			{
				if(vframe==125)
				{
					sample(SFXBong,-1);
				}
				elseif(vframe==260)
				{						
					sample(SFXBongCough,-1);
				}
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDwellerBarIdle1)
		{
			if(VAction!=DwellerBarIdle1)
			{
				SpawnAction(DwellerBarIdle1);
			}
			else
			{
				//Animation already going
			}
		}

		
		elseif(VAIState==_AIstateDweller1Sitting)
		{
			call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn|_AIstayonpath);

			if(VAction!=Dweller1Sitting)
			{
				SpawnAction(Dweller1Sitting);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDwellerBarIdle2)
		{
			if(VAction!=DwellerBarIdle2)
			{
				SpawnAction(DwellerBarIdle2);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDweller2Sitting)
		{
			call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn|_AIstayonpath);
			if(VAction!=Dweller2Sitting)
			{
				SpawnAction(Dweller2Sitting);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDwellerBarIdle3)
		{
			if(VAction!=DwellerBarIdle3)
			{
				SpawnAction(DwellerBarIdle3);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateDweller3Sitting)
		{
			call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn|_AIstayonpath);
			if(VAction!=Dweller3Sitting)
			{
				SpawnAction(Dweller3Sitting);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateFemale1BarIdle)
		{
			if(VAction!=Female1BarIdle)
			{
				SpawnAction(Female1BarIdle);
			}
			else
			{
				//Animation already going
			}
		}
			
		elseif(VAIState==_AIstateDwellerBarIdle4)
		{
			if(VAction!=DwellerBarIdle4)
			{
				SpawnAction(DwellerBarIdle4);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateFemale1Sitting)
		{
			call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn|_AIstayonpath);
			if(VAction!=Female1Sitting)
			{
				SpawnAction(Female1Sitting);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateFemale2Sitting)
		{
			call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn|_AIstayonpath);
			if(VAction!=Female2Sitting)
			{
				SpawnAction(Female2Sitting);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateFemale1Sleeping)
		{
			call(AIorder,_set,_AIinspecialmode|_AInomove|_AInoturn|_AIstayonpath);
			if(VAction!=Female1Sleeping)
			{
				SpawnAction(Female1Sleeping);
			}
			else
			{
				//Animation already going
			}
		}

		elseif(VAIState==_AIstateFreakyFemDance)
		{
			if(VAction!=FemDance)
			{
				SpawnAction(FemDance);
			}
			else
			{
				//Animation already going
			}
		}
		elseif(VAIState==_AIstateBouncerBlockBar)
		{
			if(VAction!=BouncerBlockBar && VAction!=BouncerNoBlock)
			{
				SpawnAction(BouncerBlockBar);
			}
			else
			{
			}
		}
		elseif(VAIState==_AIstateWaitressSpill)
		{
			if(VAction!=WaitressSpill)
			{
				SpawnAction(WaitressSpill);
			}
			else
			{
			}
		}
		elseif(VAIState==_AIstateWaitressClean)
		{
			if(VAction!=WaitressClean)
			{
				SpawnAction(WaitressClean);
			}
			else
			{
			}
		}
		elseif(VAIState==_AIstateWaitressPrimp1)
		{
			if(VAction!=WaitressPrimp1)
			{
				SpawnAction(WaitressPrimp1);
			}
			else
			{
			}
		}
		elseif(VAIState==_AIstateWaitressPrimp2)
		{
			if(VAction!=WaitressPrimp2)
			{
				SpawnAction(WaitressPrimp2);
			}
			else
			{
			}
		}
		elseif(VAIState==_AIstateWaitressIdle)
		{
			if(VAction!=WaitressIdle)
			{
				SpawnAction(WaitressIdle);
			}
			else
			{
			}
		}
		elseif(VAIState==_AIstateWaitressFlirt)
		{
			if(VAction!=WaitressFlirt)
			{
				SpawnAction(WaitressFlirt);
			}
			else
			{
			}
		}
//		else
//		{
//		}

/*		if(VAIStateHigh==_AIstayonpath)
		{
			print("Stay on path code");

			if(VAIhastarget==0)
			{
				if(VAItargetfound==_AIenemy)
				{
					call(AIselecttarget,_AIenemy);
				}
			}
			else
			{
				call(AIupdatetargetpos);
				call(AIPickdest,10);
			}

			//pick closer node etc.
		}
*/
		//character specific code
		if(VAIclass&==_AIclassAngel|_AIclassChot)	//dwarfchot
		{
			print("Dwarfchot special code");
			if(VAIState==_AIstateAttack && VTargetDistance>1000 && VTargetAngle>-50 && VTargetAngle<50 && VTrigger==_DIRhorcol)
			{
				print("Dwarf in attack");
				SpawnAction(DwarfLaunch);
			}
		}


		if(AIUsage&=_AIUCrouchToDefend && VAIstate==_AIstateAttack)
		{
			//call(AIOrder,_set,_AIstateRiotCop)
			printi("In riot cop mode:  ",VTargetDistance);

			if(VAIhastarget!=0)
			{
				if(VTargetDistance<250)
				{
					Direction(_or,_DIRshoot);
				}

				if(VAItargetfound==_AIenemy)
				{
//					call(AIupdatetargetpos);
//					call(AIselecttarget,_AIenemy);
					if(VAItargetseenme!=0 && VAItargettrigger==_DIRcombatmode)
					{
						if(vstate!=StateCrouching)
						{
							direction(_set,_DIRcrouch);
						}
						print("riotcop no move");
						call(AIorder,_or,_AInomove);
						ActorFlag(_or,_AFLAGshieldon);
					}
					else
					{
						print("riotcop move");
						call(AIorder,_clr,_AInomove|_AInoturn);
						ActorFlag(_clr,_AFLAGshieldon);
						if(vstate==StateCrouching)
						{
							direction(_set,_DIRcrouch);
						}
					}
				}
/*				else
				{
					ActorFlag(_clr,_AFLAGshieldon);
					call(AIorder,_set,_AIstateAttack);

					if(vstate==StateCrouching)
					{
						direction(_set,_DIRcrouch);
					}
				}
*/
			}


		}

