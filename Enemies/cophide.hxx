



				if(VAItargetfound==_AIgrenade)
				{
					sample(SFXGrenadeReact,-1);
					call(AIpicknewhidenode,1,0,_AICRetreat);
					if(VTrigger!=_DIRTempFlag)
					{
						call(AIpicknewhidenode,1,0,_AICAttack);
					}
				}



				print("Movement done by hide code:   ",AIHideControl);
				printi("NoTarget time",VAInotargettime);
				//printi("CornerAngle:   ",VAICornerAngle);

				if(vtrigger!=_DIRcombatmode)						//put character in combatmode
				{
					direction(_set,_DIRcombatmode);
				}

				//*********		HIDE ATTACK      ****************************************
				if(AIHideControl>=_AIHCAttack)
				{
					print("In Hideattack",Counter);

					//Initialize HideAttack
					if(AIHideControl==_AIHCAttack)
					{
						print("HideAttack ordered. Initialize values");
						float(_set,Counter,0);
/*						if(vstate==StateCrouching && vrnd<10)
						{
							//decide if he should stand up or turn corner
							if(VAIhideheight<160)				//go into crouch if appropriate
							{
								float(_set,AIHideControl,_AIHCAttackOEdge);
								//spawnaction(standup...);
							}
						}
*/
						if(AIHideControl!=_AIHCAttack)
						{
						}
						elseif(VAICornerAngle<0)						//Left Corner
						{
							float(_set,AIHideControl,_AIHCAttackLCorner);
							if(vstate==StateCrouching)
							{
								if(VAIcornerdistance<150)
								{
									spawnaction(CopHideCrouchLeanLeftS);
								}
								else
								{
									spawnaction(CopHideCrouchRoll);
									sample(SFXGrunt,-1);
								}
							}
							else
							{
								if(VAIcornerdistance<150)
								{
									spawnaction(CopHideLeanLeftS);
								}
								else
								{
									spawnaction(CopHideRoll);
									sample(SFXGrunt,-1);
								}
							}
						}
						else											//Right Corner
						{
							float(_set,AIHideControl,_AIHCAttackRCorner);
							if(vstate==StateCrouching)
							{
								if(VAIcornerdistance<150)
								{
									spawnaction(CopHideCrouchLeanRightS);
								}
								else
								{
									spawnaction(CopHideCrouchRoll);
									sample(SFXGrunt,-1);
								}
							}
							else
							{
								if(VAIcornerdistance<150)
								{
									spawnaction(CopHideLeanRightS);
								}
								else
								{
									spawnaction(CopHideRoll);
									sample(SFXGrunt,-1);
								}
							}
						}
					}
					//End of Initialize HideAttack

					/*
					if(AIHideControl==_AIHCAttackLCorner)
					{
						print("Left corner");
					}
					elseif(AIHideControl==_AIHCAttackRCorner)
					{
						print("Right corner");
					}
					*/

					if(AIHideControl==_AIHCAttackOEdge)
					{
						print("In Attack over edge");
						if(Counter<100)
						{
							if(vstate==StateCrouching)
							{
								direction(_set,_DIRcrouch);
							}
						}
						else
						{
							if(vstate!=StateCrouching)
							{
								direction(_set,_DIRcrouch);
							}
						}
					}

					float(_add,Counter,1);		//dummy timer
					//print("Counter:   ",counter);

					//check to end hideattack
					if(voaction==CopHideLeanLeftE || voaction==CopHideCrouchLeanLeftE || voaction==CopHideLeanRightE || voaction==CopHideCrouchLeanRightE && vendofanim!=0)
					{
						float(_set,AIHideControl,_AIHCFollowPath);
					}

					if(Counter>100)				//compare with resistance, logon etc instead
					{
						if(vaction==CopHideLeanLeftE || vaction==CopHideCrouchLeanLeftE || vaction==CopHideLeanRightE || vaction==CopHideCrouchLeanRightE)
						{
							if(VPathDestAngle<-20)
							{
								turn(0,-19,0);
								//Direction(_DIRleft);
							}
							elseif(VPathDestAngle>20)
							{
								turn(0,19,0);
								//Direction(_DIRright);
							}
						}

						if(VEndOfAnim!=0)
						{
							if(VAIcornerdistance>100 && vstate==StateCrouching)
							{
								float(_set,AIHideControl,_AIHCFollowPath);
								spawnaction(GENCrouchIdle);
							}
							elseif(VAIcornerdistance>100 && vstate!=StateCrouching)
							{
								float(_set,AIHideControl,_AIHCFollowPath);
								spawnaction(GENIdle);
							}
							else
							{
								if(AIHideControl==_AIHCAttackLCorner)
								{
									if(vstate!=StateCrouching)
									{
										spawnaction(CopHideLeanLeftE);
									}
									else
									{
										spawnaction(CopHideCrouchLeanLeftE);
									}
								}
								else
								{
									if(vstate!=StateCrouching)
									{
										spawnaction(CopHideLeanRightE);
									}
									else
									{
										spawnaction(CopHideCrouchLeanRightE);
									}
								}
							}
						}
					}
					//normal hide attack. Align, log, fire etc
					else
					{
						if(VTargetAngle<-40)
						{
							if(Counter>15)
							{
								if(VTargetAngle<-140)
								{
									turn(0,-79,0);
								}
								else
								{
									turn(0,-39,0);
								}
								//turn(0,-39,0);
								//Direction(_DIRleft);
							}
						}
						elseif(VTargetAngle>40)
						{
							if(Counter>15)
							{
								if(VTargetAngle>140)
								{
									turn(0,79,0);
								}
								else
								{
									turn(0,39,0);
								}
								//Direction(_DIRright);
							}
						}
						//align to targetangle
						else
						{
							if(Counter>45)
							{
								//decide if we want to move forward
								if(vstate!=StateCrouching)
								{
									spawnaction(GENIdle);
								}
								else
								{
									spawnaction(GENCrouchIdle);
								}

								if(VAInotargettime>AIPatience)
								{
									//print("Didn't see enemy. All well. Lets get out of state");
									//leave hide since no enemy seen
									call(AIclrhidenode);
									call(AIorder,_set,_AIstateIdle);
									call(ClrPath);
									//call(PickNewNode);
									CallSub(Sub_AIGetBackToIdle);
									if(vstate==StateCrouching)						//To get rid of crouching when he is running to new Hide
									{
										direction(_set,_DIRcrouch);
									}
								}
								else
								{
									// pick new way point............
									if(AIControl&=_AICRetreat)
									{
										if(VAITargetfound!=_AIenemy && AIUsage&=_AIUHideRetreatDefensive)
										{
											//pick new hidenode further away
											call(AIpicknewhidenode,1,0,_AICRetreat);
										}
									}
									else
									{
										if(VAITargetfound!=_AIenemy || AIUsage&=_AIUHideAttackOffensive)
										{
											//pick new hidenode closer to enemy
											call(AIpicknewhidenode,1,0,_AICAttack);
										}
									}

									if(vtrigger==_DIRTempFlag)
									{
										float(_set,AIHideControl,_AIHCReset);
									}
									else
									{
										float(_set,AIHideControl,_AIHCFollowPath);
									}
								}
							}

							CallSub(Sub_AIShootCheck,true,CurrentDirection,Counter,AIGrenadeCounter,AIAbility);
							if(vtrigger==_DIRshoot)
							{
						//		float(_add,Counter,50);
							}
						}
					}
				}
				//*********		HIDE IN-ROUTE      ****************************************
				elseif(AIHideControl==_AIHCInRoute)					//has not reached dest yet
				{
					printi("In route to Hide Position    ",VPathDestDistance);
					if(vstate==StateCrouching)						//To get rid of crouching when he is running to new Hide
					{
						direction(_set,_DIRcrouch);
					}

					if(VPathDestDistance>10)
					{
						CallSub(Sub_AIShootCheck,true,CurrentDirection,Counter,AIGrenadeCounter,AIAbility);

						CallSub(Sub_AI1WayAlignToTarget);
						//CallSub(Sub_AI1WayAlignToPickDestAngle);
						if(VPathDestDistance<50)
						{
							CallSub(Sub_AI8WayMoveWalk,CurrentDirection);
						}
						else
						{
							CallSub(Sub_AI8WayMoveRun,CurrentDirection);
						}
					}
					else
					{
						float(_set,AIHideControl,_AIHCFollowPath);
					}
				}
				//*********		HIDE FOLLOW PATH    ****************************************
				else												//reached first hide node. Now use hide maneuvering
				{
					printi("In hide specific movement: ",VPathDestAngle);

					if(VAIhideheight<180)								//go into crouch if appropriate
					{
						if(vstate!=StateCrouching)
						{
							direction(_set,_DIRcrouch);
						}
						float(_set,TmpFloat,20)
					}
					else
					{
						float(_set,TmpFloat,30)
					}

					if(VPathDestDistance<TmpFloat)							//Reached destination?
					{
						printi("reached hide destination:  ",VPathDestAngle);
						if(VAItargetvisible!=0)		//make sure we still check for enemy in sight
						{
							CallSub(Sub_AIShootCheck,true,CurrentDirection,Counter,AIGrenadeCounter,AIAbility);
							CallSub(Sub_AI1WayAlignToTarget);
							//CallSub(Sub_AI8WayMoveRun,CurrentDirection);
						}
						elseif(VPathDestAngle<-20)
						{
							//turn(0,-19,0);
							Direction(_set,_DIRleft);
						}
						elseif(VPathDestAngle>20)
						{
							//turn(0,19,0);
							Direction(_set,_DIRright);
						}
						elseif(VTrigger==_DIRhavegun)
						{
							//Make decision if actor should lean out and take a shot
							if(AIControl&==_AICRetreat && AIUsage&=_AIUHideLeanOutRetreat)
							{
								float(_set,AIHideControl,_AIHCAttack);
							}
							elseif(AIControl&==_AICAttack && AIUsage&=_AIUHideLeanOutAttack)
							{
								float(_set,AIHideControl,_AIHCAttack);
							}
						}
					}
					else															//Move to HideDest
					{
						float(_set,AIHideControl,_AIHCFollowPath);
						printi("Correcting Hide Position   ",VAItargetvisible);

						if(VAIhideheight<180)										//go into crouch if appropriate
						{
							if(vstate!=StateCrouching)
							{
								direction(_set,_DIRcrouch);
							}
						}
						else
						{
							if(vstate==StateCrouching)
							{
								direction(_set,_DIRcrouch);
							}
						}

						if(VAItargetvisible!=0)
						{
							CallSub(Sub_AIShootCheck,true,CurrentDirection,Counter,AIGrenadeCounter,AIAbility);
							CallSub(Sub_AI1WayAlignToTarget);
							CallSub(Sub_AI8WayMoveRun,CurrentDirection);
						}
						else
						{
							CallSub(Sub_AI2WayAlignToPickDestAngle);

							if(vpickdestanglecorr>=-1024 && vpickdestanglecorr<=1024)		//forward
							{
								//printi("forward code   ",VPathDestDistance);
								if(VPathDestDistance<150 && vpickdestanglecorr>-120 && vpickdestanglecorr<120)
								{
									float(_set,CurrentDirection,_DIRforward|_DIRwalking);
								}
								elseif(VPathDestDistance>150 && vpickdestanglecorr>-60 && vpickdestanglecorr<60)
								{
									float(_set,CurrentDirection,_DIRforward);
								}
							}
							else															//backward
							{
								//printi("backward code   ",VPathDestDistance);
								if(vpickdestanglecorr<-1980 || vpickdestanglecorr>1980)
								{
									if(VPathDestDistance<150)
									{
										float(_set,CurrentDirection,_DIRbackward|_DIRwalking);
									}
									elseif(VPathDestDistance>150)
									{
										//float(_clr,CurrentDirection,_DIRwalking);
										float(_set,CurrentDirection,_DIRbackward);
									}
								}
							}
						}
					}

					//if(VAIpowerrating>AIPowerRatingThreshold)
					if(AIControl&!=_AICHide)
					{
						//printlog("Leaving hidemode");
						state(_clr,StateFollowPath);
						call(AIclrhidenode);
						call(ClrPath);
						call(AIorder,_set,_AIStateidle);
						CallSub(Sub_AISetAttack);
						if(vstate==StateCrouching)						//To get rid of crouching when he is running to new Hide
						{
							direction(_set,_DIRcrouch);
						}
						//play sample (he's weak. go for him");
					}
				}

