
//make sure fxvector is set for ABSoulte Blood types
SubRoutine(Sub_BloodFx2Abs)
{
		call(SetParticleSetID);
		spawnparticle(fx_blood,-1,fxvector,emptyvector,-1);
		spawnparticle(fx_blood,-1,fxvector,emptyvector,-1);
}
SubRoutine(Sub_BloodFxSprayAbs)
{
		call(SetParticleSetID);
		spawnparticle(fx_bloodspray,-1,fxvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFxSpurtAbs)
{
		call(SetParticleSetID);
		spawnparticle(fx_bloodspurt,-1,fxvector,emptyvector,-1);
}



//no follow
SubRoutine(Sub_BloodFx2)
{
		spawnparticle(fx_blood,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFx5)
{
		spawnparticle(fx_blood,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_blood,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFx10)
{
		spawnparticle(fx_blood,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_blood,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodlesser,0,emptyvector,emptyvector,-1);
}		

SubRoutine(Sub_BloodFxSpray)
{
		spawnparticle(fx_bloodspray,0,emptyvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFxSpurt)
{
		spawnparticle(fx_bloodspurt,0,emptyvector,emptyvector,-1);
}



//follow
SubRoutine(Sub_BloodFx2REL)
{
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFx5REL)
{
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFx10REL)
{
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_bloodREL,0,emptyvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFxSprayREL)
{
		spawnparticle(fx_bloodsprayREL,0,emptyvector,emptyvector,-1);
}

SubRoutine(Sub_BloodFxSpurtREL)
{
		spawnparticle(fx_bloodspurtREL,0,emptyvector,emptyvector,-1);
}



//must be StateDead to call this
SubRoutine(Sub_LostAnyLimbsLately,float(thislimb))
{
		if(vaction==CopHeadBlownOffDead)
		{
			scalebonematrix(4,0.001,0.001,0.001,_SXBoneAttRelative);

			if(vframe<74)
			{
				if(vrnd<50)
				{
					if(vframe<24)
					{
						spawnparticle(fx_blood,4,emptyvector,emptyvector,-1);
						spawnparticle(fx_blood,4,emptyvector,emptyvector,-1);
					}
					spawnparticle(fx_bloodspray,4,emptyvector,emptyvector,-1);
				}
			}
		}
		else
		{
			if(VSpecialFlag==_sFLAGLostALimb)
			{
				if(thislimb==0)
				{
					if(vrnd<25)
					{
						float(_set,thislimb,1);
					}
					elseif(vrnd<50)
					{
						float(_set,thislimb,2);
					}
					elseif(vrnd<75)
					{
						float(_set,thislimb,3);
					}
					elseif(vrnd<100)
					{
						float(_set,thislimb,4);
					}
				}
				else
				{
					if(thislimb==1)
					{
						//right leg
						scalebonematrix(20,0.001,0.001,0.001,_SXBoneAttAbsolute);
					}
					elseif(thislimb==2)
					{
						//left arm
						scalebonematrix(6,0.001,0.001,0.001,_SXBoneAttAbsolute);
					}
					elseif(thislimb==3)
					{
						//left leg
						scalebonematrix(16,0.001,0.001,0.001,_SXBoneAttAbsolute);
					}
					elseif(thislimb==4)
					{
						//right arm
						scalebonematrix(10,0.001,0.001,0.001,_SXBoneAttAbsolute);
					}
				}
			}
		}
}

Subroutine(Sub_DiePlease)
{
		state(_or,StateDead);
		Direction(_clr,_DIRalive);								//if timing problems, remove this and clear it if statedead in copgen (ask torg)

		if(VActorFlag==_AFLAGpossesed)
		{
			if(VAIcon!=0 || VDifficulty<_DifficultyHard)		//to allow evil bob to depossess
			{
				direction(_or,_DIRdepossesion);
			}
		}
}

SubRoutine(Sub_CheckDeadOrDying,float(AIAbility),const(PoleDead),const(CrawlDead),const(StandDead),const(CrawlSpreadOut),const(CrawlEnergy),const(FallToCrawl),const(CrouchDead),const(ThrownDeath))
{
		//tony added, becoz the broken leg people eventually die ..paff!
		if(vaction==CopCrawlIdle)
		{
			call(SubtractHealth,0,DamageCrawlDamage)
		}

//CrawlEnergy is how much energy you must have to enter crawling mode, or 0 if there is no crawling
		if(VHealth<=CrawlEnergy&&vstate!=StateDead)
		{
			if(VHealth<=0)
			{
				if(AIAbility&=_AIAPickUpWeapon)
				{
					call(CheckAttached,_CADropWeaponAndShells);
				}
				callsub(Sub_DiePlease);

				if(vstate==StateHarpooned)
				{
					spawnaction(PoleDead)
//MISSING: Sound: dead
				}
				elseif(VState==StateCrawling)
				{
					if(VColSphereScale<60)	//Must be crawling already
					{
						spawnaction(CrawlDead)
//MISSING: Sound: dead
					}
					else
					{
						spawnaction(FallToCrawl);
					}
				}
				elseif(VState==StateCrouching || VAIState==_AIstateCowering)
				{
					spawnaction(CrouchDead);
				}
				elseif(VState==StateThrown)
				{
					if(vactorflag==_AFLAGAttached)
					{
						spawnaction(StandDead);
					}
						//allow the dead to be thrown
					if(Vaction!=GENThrownForward && Vaction!=GENThrownBack && Vaction!=GENThrownLeft && Vaction!=GENThrownRight)
					{
						spawnaction(StandDead);
					}

				//	Used to prevent them from standing up after their death animation. Not neccessary anymore
				//	if(ThrownDeath!=0)
				//	{
				//		SpawnAction(ThrownDeath);
				//	}
				//	else
				//	{
				//		//spawnaction(StandDead);
				//		spawnaction(GENThrownRight);
				//	}
				}
				else
				{
					spawnaction(StandDead);
//MISSING: Sound: dead
				}
			}
			elseif(vstate!=StateCrawling&&vstate!=StateHarpooned)
			{
//MISSING: Sound: hit ground because energy is low
				if(AIAbility&!=_AIANoCrawl && vtrigger==_DIRhorcol && VState!=StateCrawling)
				{
					state(_or,StateCrawling);
					if(AIAbility&=_AIAPickUpWeapon)
					{
						call(CheckAttached,_CADropWeaponAndShells);
					}
				}
			}
		}
}


//using "WoundLightNoBreak" really sucks, because you can NEVER efficiently run away when you are being shot at
//especially by the machine gun ....
SubRoutine(Sub_CheckHit,float(AIAbility),const(WoundLight),const(WoundLightRun),const(WoundLightNoBreak),float(subFireCount),const(PoleDead),const(WoundLightCrouch),const(ThrownForward),const(ThrownBack),const(ThrownLeft),const(ThrownRight),float(HitByFireCounter))
{		
		if(VTrigger==_DIRdepossesion || VOTrigger==_DIRdepossesion)
		{
			//make it possible to depossess when on fire
			if(vtrigger==_DIRactorbulletcol && VActorColType==_COLFire)
			{
				float(_add,HitByFireCounter,4);
				colstate(_clr,_Colfire);
				direction(_clr,_DIRactorbulletcol);			//mmm?
				call(SubtractHealth,0,-200);				//gimme my health back, i'm not on fire yet :: -DamageFlameThrower
				colstate(_clr,_Colfire);
				direction(_clr,_DIRactorbulletcol);			//mmm?
			}
		}
		else
		{
			//(flamethrower) don't catch fire too easily....except for background fire
			if(vtrigger==_DIRactorbulletcol && VActorColType==_COLFire&&VFXFlag!=_fxFLAGBackground)
			{
				float(_add,HitByFireCounter,4);
				if(HitByFireCounter<6)
				{
					colstate(_clr,_Colfire);
					direction(_clr,_DIRactorbulletcol);			//mmm?
					call(SubtractHealth,0,-200);				//gimme my health back, i'm not on fire yet :: -DamageFlameThrower
					colstate(_clr,_Colfire);
					direction(_clr,_DIRactorbulletcol);			//mmm?
				}
				else
				{
					//right i'm on fire ...now don't clear states until i can be set on fire again!
					float(_set,HitByFireCounter,450);
				}
			}
		}

		float(_sub,HitByFireCounter,1);
		if(HitByFireCounter<0)
		{
			float(_set,HitByFireCounter,0);
		}



		if(vtrigger==_DIRactorbulletcol)
		{
//Please note: DIRactorbulletcol can be set, even when VActorColType=0. That is because you fall, or health is restored
			if(VActorColType==_COLFire||VActorColType==_COLSteam||VActorColType==_COLsingleattach||VActorColType==_COLelectricity)
			{
				//call(CheckAttached,_CADropWeaponAndShells);
				//if(VActorColType==_COLsingleattach && vstate!=StateHarpooned && VState!=StateExecuteAnim)
				if(VActorColType==_COLsingleattach && vstate!=StateHarpooned)
				{
					if(vstate==StateAttached)
					{
						if(vstate==StateDead)	//Already dead before this hit
						{
							spawnaction(PoleDead)
						}
						else
						{
							callsub(Sound_HitSmall);
						}

						sample(SFXFlyThroughAirReact,-1);

						state(_or,StateHarpooned)
						state(_clr,StateExecuteAnim);
					}
					else
					{
						if(vstate!=StateDead)
						{
							if(vstate==StateCrawling)
							{
								spawnaction(CopShotCrawl);
							}
							elseif(VState==StateCrouching)
							{
								spawnaction(WoundLightCrouch);
							}
							else
							{
								spawnaction(WoundLight);
							}
						}
					}
				}
				elseif(VActorColType==_COLFire)
				{
					if(Vstate!=StateOnFire)
					{
//MISSING: AI Get waypoint
						if(AIAbility&=_AIAPickUpWeapon)
						{
							call(CheckAttached,_CADropWeaponAndShells);
						}
						state(_clr,StateExecuteAnim);
						state(_or,StateOnFire)

					}
					if(subFireCount>50)
					{
						float(_set,subFireCount,50);	//Dont set to zero, that restarts fireanimation(with only head on fire at first)
					}
				}
				elseif(VActorColType==_COLelectricity)
				{
					if(Vstate!=StateElectricShock && VState!=StateThrown)
					{
//MISSING: AI Get waypoint
						state(_clr,StateExecuteAnim);
						state(_or,StateElectricShock);
						call(SetActorToPrevPos);
					}
					sample(SFXElectrocuteReact,-1);
				}
				elseif(VActorColType==_COLSteam)
				{
					if(Vstate!=StateSteamed)
					{
//MISSING: AI Get waypoint
						if(vstate!=StateDead)
						{
//Missing: play sound
						}
						state(_clr,StateExecuteAnim);
						state(_or,StateSteamed)
					}

					sample(SFXGettingSteamedReact,-1);
				}
			}
			else	//Not mortal.
			{
//MISSING: when actor is dying, it should still react to explosions(except when on harpoon), and play sounds
				if(vstate!=StateDead && vstate!=StateHarpooned && VState!=StateOnFire && VState!=StateSteamed && VState!=StateCrawling && VState!=StateExecuteAnim)
				{
					if(AIAbility&!=_AIANoThrown && VTrigger==_DIRCloseToCollision && VState!=StateThrown)
					{
						if(VClass!=_ClassAngel)
						{
							sample(SFXExplosionReact,-1);
							/*
							if(vrnd<50)
							{
								sample(SFXManBlastHit1,-1);
							}
							else
							{
								sample(SFXManBlastHit2,-1);
							}
							*/
						}
						if(VColAngle>=3584 || VColAngle<=512)		//throw back
						{
							spawnaction(ThrownBack);
						}
						elseif(VColAngle>512 && VColAngle<1536)		//throw left
						{
							spawnaction(ThrownLeft);
						}
						elseif(VColAngle>=1536 && VColAngle<=2560)	//throw forward
						{
							spawnaction(ThrownForward);
						}
						elseif(VColAngle>2560 && VColAngle<3584)	//throw right
						{
							spawnaction(ThrownRight);
						}

						if(VAIClass==_AIClassBeast || VAIClass==_AIClassABeast)
						{
							if(VTrigger!=_DIRalive)
							{
								spawnaction(GENStandDead);
							}
							else
							{
								call(ThrowCharacter,0,40,-1);				//up, directionstrength. beast pushed along floor
							}
						}
						elseif(VTrigger==_DIRalive)
						{
							call(ThrowCharacter,20,30,-1);				//up, directionstrength. Thrown alive
						}
						else
						{
							call(ThrowCharacter,20,60,-1);				//up, directionstrength Thrown Dead
						}
						state(_or,StateExecuteAnim);
						state(_or,StateThrown);
					//	PrintILog("THROWN ",VColAngle);				//torgeir, temp debug text
					}
					elseif(AIAbility&!=_AIANoCrawl && VAction!=WoundLightNoBreak && VAction!=WoundLight && VAction!=CopShotCrawl && VAction!=WoundLightCrouch && VAction!=WoundLightRun && VTrigger==_DIRalive)
					{
						if(VHealth>0)
						{
							if(VAICOn!=0)
							{
								sample(SFXShotReact,-1);
							}
							else
							{
								sample(SFXPunchedReact,-1);
							}
						}
						if(VTrigger==_noDIR || VAICon!=0)
						{
							if(vstate==StateCrawling)
							{
								spawnaction(CopShotCrawl);
							}
							elseif(VState==StateCrouching)
							{
								spawnaction(WoundLightCrouch);
							}
							else
							{
								spawnaction(WoundLightNoBreak);
							}
							//callsub(Sound_HitSmall);
						}
						elseif(VTrigger==_DIRforward && VTrigger!=_DIRwalking)
						{
							//callsub(Sound_HitSmall);
							if(vstate==StateCrawling)
							{
								spawnaction(CopShotCrawl);
							}
							elseif(VState==StateCrouching)
							{
								spawnaction(WoundLightCrouch);
							}
							else
							{
								spawnaction(WoundLightRun);
							}
						}
					}
				}
			}
		}
}

SubRoutine(Sub_CheckThrownFallDamage,float(FallStartAltitude),const(MaxFallAltitude))
{
		vector(_settoactorpos,TmpVector);
		vector(_copyy,TmpVector,SubVar1);
		float(_set,SubVar2,SubVar1)

		float(_sub,SubVar1,FallStartAltitude);
		float(_div,SubVar1,MaxFallAltitude);

		if(VTrigger!=_DIRhorcol)
		{
			if(SubVar1>4)
			{
				call(SubtractHealth,_COLFalling,50000)
				callsub(Sub_DiePlease);
			}
		}
		elseif(VState!=StateNormal)
		{
			if(SubVar1>2)
			{
				call(SubtractHealth,_COLFalling,50000)
				callsub(Sub_DiePlease);
			}
			State(_or,StateNormal);
		}

		if(VTrigger==_DIRhorcol || FallStartAltitude<SubVar2)
		{
			float(_set,FallStartAltitude,SubVar2);		//FallDamage is measured from this height.
		}
}


SubRoutine(Sub_DontCutThroughCeil)
{
		vector(_set,TmpVector,0,0,0);
		float(_seti,TmpFloat,VColSphereOffsetY);
		vector(_sety,TmpVector,TmpFloat);

		vector(_copy,TmpVector2,TmpVector);
		float(_seti,TmpFloat2,VColSphereSize);
		float(_add,TmpFloat2,10);				//some slack
		vector(_addy,TmpVector2,TmpFloat2);

		Collision(TmpVector,TmpVector2);
		if(vcolflag==_DIRhorcol)
		{
			//PrintILog("BANGHEAD VColDistance: ",VColDistance);
			vector(_settoactorpos,TmpVector);
			float(_seti,TmpFloat,VColSphereSize);
			vector(_addy,TmpVector,TmpFloat);

			vector(_settocolpos,TmpVector2);
			vector(_sub,TmpVector2,TmpVector);
			vector(_copyy,TmpVector2,TmpFloat);
			move(0,TmpFloat,0);
		}
}


SubRoutine(Sub_CheckFallDamage,float(AIAbility),const(LandAction),float(FallStartAltitude),const(MaxFallAltitude),const(MaxHealthLossFall),float(SubParmFallDead),const(BangHeadAction),const(FreakAction))
{
		vector(_settoactorpos,SubVector1);
		vector(_copyy,SubVector1,SubVar1);
		float(_set,SubVar3,SubVar1)

		ActorFlag(_clr,_AFLAGsignalfromparent);

		if(VState!=StateJump)						//might need an else for banging the head
		{
			float(_sub,SubVar1,FallStartAltitude);
			float(_div,SubVar1,MaxFallAltitude)

			if(Vtrigger!=_DIRhorcol)
			{
				//special code for pak weapon to avoid fall damage and to use different animation
				if(VTrigger==_DIRHaveGun && VWeaponType==WeaponPAK && VState!=StateExecuteAnim)
				{
					if(SubVar1>0.02)
					{
						if(VTrigger==_DIRjump || VAIcon!=0)
						{
							SpawnAction(CopPakWeaponDrift);
							ActorFlag(_or,_AFLAGsignalfromparent);
							float(_set,FallStartAltitude,SubVar3);
						}
					}
					if(VAICon==0)
					{
						callsub(Sub_DontCutThroughCeil);
					}
				}
				elseif(VAIClass==_AIclasssubgirl && VAICon==0)
				{
					callsub(Sub_DontCutThroughCeil);
				}
				elseif(SubVar1>0.3 && VState!=StateThrown && VState!=StateElectricShock)
				{
					spawnaction(FreakAction);
					State(_clr,StateNormal);
				}

/*				if(SubVar1>4)	//4 times allowed height, instant death		//SAXS: long fall instant death in mid air disabled
				{
					call(SubtractHealth,_COLFalling,50000)
					callsub(Sub_DiePlease);
					//direction(_set,_DIRdepossesion);
					state(_clr,StateExecuteAnim);
					spawnaction(SubParmFallDead);
					CallSub(Sub_ChangeStateToNormal);
				}
				elseif(SubVar1>0.5)
*/
				if(SubVar1>0.5)
				{
					//fallen for a long time
					if(VAIclass!=_AIclassAngel)
					{
						sample(SFXLongFallReact,-1);
					}
					elseif(SubVar1>1.0)
					{
						sample(SFXLongFallReact,-1);		//bob should react later
					}
				}
			}
			else
			{
				float(_set,SubVar4,0);

				if(VClass==_ClassAngel && VActorFlag==_AFLAGcolfromabove)
				{
					float(_set,SubVar4,1);
				}
				elseif(VAICon==0)
				{
					float(_seti,TmpFloat,VDistToGround);
					float(_seti,TmpFloat2,VColFeetSphereBottom);
					float(_add,TmpFloat,TmpFloat2);
					if(TmpFloat>10)
					{
						if(VAIClass==_AIclasssubgirl)
						{
							callsub(Sub_DontCutThroughCeil);
						}
						elseif(VTrigger==_DIRHaveGun && VTrigger==_DIRHaveGun && VWeaponType==WeaponPAK)
						{
							callsub(Sub_DontCutThroughCeil);
						}
					}
				}

				if(SubVar1>0.5)
				{
					if(VAIclass!=_AIclassAngel)
					{
						sample(SFXHardLandingReact,-1);
					}
				}

				if(SubVar4==0)
				{
		//MISSING: Sound: Stop the scream again
					if(SubVar1>2)	//2 times allowed height, instant death
					{
		//MISSING: sound: FallDead
						call(SubtractHealth,_COLFalling,50000)
						callsub(Sub_DiePlease);
						//direction(_set,_DIRdepossesion);
						state(_clr,StateExecuteAnim);
						spawnaction(SubParmFallDead);
						CallSub(Sub_ChangeStateToNormal);
						call(CheckAttached,_CADropWeaponAndShells);
					}
					elseif(SubVar1>1&&VClass!=_ClassAngel)	//over allowed height: Break legs
					{
						if(AIAbility&!=_AIANoCrawl)
						{
							state(_or,StateCrawling)
							if(AIAbility&=_AIAPickUpWeapon)
							{
								call(CheckAttached,_CADropWeaponAndShells);
							}
						}
						else
						{
							spawnaction(LandAction);
						}
						state(_clr,StateExecuteAnim);
						sample(SFXBreakLegReact,-1);
						call(SubtractHealth,_COLFalling,MaxHealthLossFall)
						CallSub(Sub_ChangeStateToNormal);
					}
					else
					{
						if(SubVar1>0.5)				//If falldistance >50% of maxfallheight, subtract health
						{
							if(SubVar1>1)
							{
								float(_set,SubVar1,1);
							}
							float(_mul,SubVar1,MaxHealthLossFall);
							call(SubtractHealth,_COLFalling,SubVar1)
							sample(SFXHardLandingReact,-1);
						}
						if(VState!=StateNormal)
						{
							float(_Seti,SubVar2,VColFeetSphereBottom)
							float(_mul,SubVar2,-1)
							float(_add,SubVar2,70)
							if(VDistToGround<SubVar2)		//Same as InAirCheckGround:
							{
								CallSub(Sub_ChangeStateToNormal);

								if(VClass==_ClassBeast)
								{
									sample(SFXBeastJump,-1);
								}
								elseif(VAIClass==_AIclassbarpeople&&VAIClass==_AIclassmale)
								{
									sample(SFXABeastJump,-1);
								}
								elseif(VAICon==0 && vaction!=LandAction)
								{
									if(VClass!=_ClassAngel)
									{
										sample(SFXFootStepBig,-1);
									}
									else //VClass==_ClassAngel (this is for Bob), uses softer footstep sample
									{
										sample(SFXFootStepReg,-1,75);
									}
								}

								if(VState==StateDazed)
								{
									State(_clr,StateDazed);
									spawnaction(GENDepossesed);
								}
								else
								{
									spawnaction(LandAction);
								}

		//							call(checkconnections);
							}
							else
							{
								move(0,-4,0);
							}
						}
					}
				}
			}
		}
		elseif(VClass!=_ClassAngel)
		{
			vector(_set,TmpVector,0,0,0);
			float(_seti,TmpFloat,VColSphereOffsetY);
			vector(_sety,TmpVector,TmpFloat);

			vector(_copy,TmpVector2,TmpVector);
			float(_seti,TmpFloat2,VColSphereSize);
			float(_add,TmpFloat2,10);				//some slack
			vector(_addy,TmpVector2,TmpFloat2);

			Collision(TmpVector,TmpVector2);
			if(vcolflag==_DIRhorcol)
			{
				//PrintILog("BANGHEAD VColDistance: ",VColDistance);
				vector(_settoactorpos,TmpVector);
				float(_seti,TmpFloat,VColSphereSize);
				vector(_addy,TmpVector,TmpFloat);

				vector(_settocolpos,TmpVector2);
				vector(_sub,TmpVector2,TmpVector);
				vector(_copyy,TmpVector2,TmpFloat);
				move(0,TmpFloat,0);

				//PrintLog("BANGHEAD ColMovedDist: ",TmpFloat);
				if(VState==StateBangedHead)
				{
					state(_clr,StateBangedHead|StateNormal);
					//maybe or in statefalling?
					//CallSub(Sub_ChangeStateToNormal);
					if(VDistToGround<150)						//torg is pulling a late night number out of his ass here
					{
						spawnaction(BangHeadAction);
					}
				}
				elseif(VState==StateJump)
				{
					//break();
					state(_or,StateBangedHead);
				}
			}
//MISSING: Sound: Klonk head against object
		}
		elseif(VClass==_ClassAngel &&VTrigger==_DIRjump && Vtrigger==_DIRhorcol)
		{
			Collision(0,30,0,0,50,0);
			if(vcolflag==_DIRhorcol)
			{
				if(VState==StateBangedHead)
				{
					state(_clr,StateBangedHead);
					CallSub(Sub_ChangeStateToNormal);
					spawnaction(BangHeadAction);
				}
				elseif(VState==StateJump)
				{
					//break();
					state(_or,StateBangedHead);
				}
			}
//MISSING: Sound: Klonk head against object
		}

		if(VTrigger==_DIRhorcol || FallStartAltitude<SubVar3 || Vstate==StateFlying || VState==StateGliding || VActiveTime==1)
	//Delete the last two checks if you have to lose energy even if you flap before you land
		{
			float(_set,FallStartAltitude,SubVar3);		//FallDamage is measured from this height.
		}
}

//Subtract energy and handle actions
SubRoutine(Sub_Harpooned,const(FlyFront),const(WallFront),const(IdleFront),const(BurnFront),const(FlyBack),const(WallBack),const(IdleBack),const(BurnBack))
{
//	SubVar1	- HitFront

		float(_set,SubVar1,1);								//harpooned in stomach
		if(VColAngle>1024 && VColAngle<3072)
		{
			float(_set,SubVar1,0);							//harpooned in back
		}

		if(VAction!=IdleFront && VAction!=IdleBack && VAction!=GENHarpoonFrontBeg)			//in idle?
		{
			if(VAction==BurnFront || VAction==BurnBack)		//burning
			{
				if(VState!=StateOnFire)
				{
					if(SubVar1==0)
					{
						SpawnAction(IdleBack);
					}
					else
					{
						SpawnAction(IdleFront);
					}
					state(_clr,StateExecuteAnim);
				}
			}
			else
			{
				State(_copyparent);

				if(SubVar1==0)
				{
					if(VState==BulletStateStuckInWall)		//harpoon hit the wall yet?
					{
						if(VAction!=WallBack)
						{
							SpawnAction(WallBack);
						}
					}
					elseif(VAction!=FlyBack)
					{
						spawnaction(FlyBack);				//rocket forward
						float(_seti,TmpFloat,VColAngle);
						float(_sub,TmpFloat,2048);
						Turn(0,TmpFloat,0);
					}
				}
				else
				{
					if(VState==BulletStateStuckInWall)		//harpoon hit the wall yet?
					{
						if(VAction!=WallFront)
						{
							SpawnAction(WallFront);
						}
					}
					elseif(VAction!=FlyFront)
					{
						spawnaction(FlyFront);				//rocket backwards
						float(_seti,TmpFloat,VColAngle);
						Turn(0,TmpFloat,0);
					}
				}
			}
		}
		elseif(VState==StateOnFire)							//idle & on fire?
		{
			state(_or,StateExecuteAnim);
			if(SubVar1==0)
			{
				SpawnAction(BurnBack);
			}
			else
			{
				SpawnAction(BurnFront);
			}
		}
		else
		{
			if(VAction==IdleFront && VAction!=GENHarpoonFrontBeg)
			{
				call(SearchForCloseActor,_AIclasscop|_AIclassworker|_AIclasschot|_AIclassangel|_AIclassbeast|_AIclassprost|_AIclasspimp|_AIclasspriest|_AIclassdweller|_AIclassscientist|_AIclassbarpeople|_AIclassmale|_AIclassfemale|_AIclassriotcop|_AIclassmedic|_AIclasssubgirl,256);
				if(VTrigger==_DIRTempFlag)
				{
					SpawnAction(GENHarpoonFrontBeg);
				}
			}
		}

		float(_seti,TmpFloat,VActiveTime)
		float(_and,TmpFloat,31);
		if(TmpFloat==0)
		{
			call(SubtractHealth,_COLsingleattach,DamageOnSpear);
		}
}

subroutine(Sub_Crawling,const(SubParmCrawlSpreadOut),const(SubParmFallToCrawl))
{
		if(VColSphereScale>60)	// || vactionlist!=SubParmCrawlSpreadOut)
		{
			spawnaction(SubParmFallToCrawl);
		}
}

subroutine(Sub_ElectricShock,const(ElectricShock0),const(ElectricShock1))
{
		if(VState==StateElectricShock)
		{
			if(vaction!=ElectricShock0 && vaction!=ElectricShock1)
			{
				spawnaction(ElectricShock0);
			}
			elseif(vaction==ElectricShock0)
			{
				float(_rnd2,tmpfloat1,100);
				float(_rnd2,tmpfloat2,100);
				float(_rnd2,tmpfloat3,100);
				float(_sub,tmpfloat1,50);
				float(_sub,tmpfloat2,50);
				float(_sub,tmpfloat3,50);
				vector(_setx,gactorpos,tmpfloat1);
				vector(_sety,gactorpos,tmpfloat2);
				vector(_setz,gactorpos,tmpfloat3);
				spawnparticle(fx_impactsparks,0,gactorpos,emptyvector,-1);
			}
			else
			{
				float(_rnd2,tmpfloat1,100);
				float(_rnd2,tmpfloat2,100);
				float(_rnd2,tmpfloat3,100);
				float(_sub,tmpfloat1,50);
				float(_sub,tmpfloat2,50);
				float(_sub,tmpfloat3,50);
				vector(_setx,gactorpos,tmpfloat1);
				vector(_sety,gactorpos,tmpfloat2);
				vector(_setz,gactorpos,tmpfloat3);
				spawnparticle(fx_impactsparks,0,gactorpos,emptyvector,-1);
			}
		}
}

subroutine(Sub_BurnedSteamedBlind,const(SubVarBurningRollOnFloor),const(SubVarBurnedIdle),const(SubVarGettingBurned),const(SubVarBlindForward),const(SubVarBlindBackwards),const(SubVarBurningRunInCircle),const(SubVarSlowGetUpFace),float(SubSteamCounter),const(IdleAction))
{
		if(VState==StateOnFire)
		{
			call(AIsafetyradius,500);

			call(SubtractHealth,_COLfire,DamageInsideFire)
			if(vtrigger==_DIRactorbulletcol&&VActorColType==_COLfire)	//Still inside the fire??
			{
				if(vaction!=SubVarGettingBurned && vaction!=SubVarBlindForward && vaction!=SubVarBlindBackwards && vaction!=SubVarBurningRunInCircle)
				{
					spawnaction(SubVarGettingBurned);
				}
	//MISSING: AI must control him when inside fire - give waypoint to the outside, and make him run he has been there after a little while
			}
			else	//Not inside fire any more
			{
				if(vaicon!=0)	//When computer has control of character, run and fall
				{
					if(vaction!=SubVarBurningRunInCircle && vaction!=SubVarBurningRollOnFloor)	
					{
						spawnaction(SubVarBurningRunInCircle);
					}
					elseif(vframe==20 && vaction==SubVarBurningRollOnFloor)
					{
						ActorFlag(_clr,_AFLAGnoai);
						state(_change,StateOnFire,StateBlind);
					}
				}
				else	//The player controls him
				{
					if(vaction!=SubVarBurnedIdle && vaction!=SubVarBlindForward && vaction!=SubVarBlindBackwards)
					{
						spawnaction(SubVarBurnedIdle);
					}
				}
			}	
		}
		else	//Steamed or Blind
		{
			if(vtrigger==_DIRactorbulletcol&&VActorColType==_COLSteam)
			{
				sample(SFXGettingSteamedReact,-1);

				float(_set,SubSteamCounter,DamageSteamDuration);
				if(vaicon!=0)
				{
				//MISSING: Control using AI here while inside steam
					if(vaction!=SubVarGettingBurned&&vaction!=SubVarBlindForward&&vaction!=SubVarBlindBackwards)
					{
						spawnaction(SubVarGettingBurned);
					}
				}
				else
				{
					if(vaction!=SubVarGettingBurned&&vaction!=SubVarBlindForward&&vaction!=SubVarBlindBackwards)
					{
						spawnaction(SubVarGettingBurned);
					}
				}
			}
			else
			{
//if this is here character is useless after being hit once by steam, not very player friendly
//				if(vstate==StateSteamed)
//				{
//					state(_change,StateSteamed,StateBlind)
//				}
				if(vaicon!=0)
				{
					//MISSING: Decent AI to control him around when he is steamed. This also used for when he is crawling 
					if(vtrigger==_DIRhorcol)
					{
						if(VColAngle>=3584 || VColAngle<=512)		//throw back
						{
							turn(0,-5,0);
						}
						elseif(VColAngle>512 && VColAngle<1536)		//throw left
						{
							turn(0,5,0);
						}
						elseif(VColAngle>=1536 && VColAngle<=2560)	//throw forward
						{
							turn(0,5,0);
						}
						elseif(VColAngle>2560 && VColAngle<3584)	//throw right
						{
							turn(0,-5,0);
						}
					}

					Direction(_clr,_DIRwalking);
					Direction(_set,_DIRforward);
				}

//				Torg remmed this, it messed up.
				if(vstate!=StateSteamed || SubSteamCounter!=0)
				{
					if(vaction!=SubVarBurnedIdle&&vaction!=SubVarBlindForward&&vaction!=SubVarBlindBackwards&&vaction!=SubVarSlowGetUpFace&&vaction!=SubVarBurningRollOnFloor)
					{
						spawnaction(SubVarBurnedIdle);
					}
				}
			}

			if(VState==StateSteamed)
			{
				if(SubSteamCounter==0)
				{
					State(_clr,StateSteamed);
					SpawnAction(IdleAction);
				}
				else
				{
					float(_sub,SubSteamCounter,1);
				}
			}

			sample(SFXBlindReact,-1);
			call(SubtractHealth,_COLSteam,DamageInsideSteam)		//you're basicly dying?
		}
}






//type 0 : full body
//type 1 : both hands
//type 2 : left leg
//type 3 : right arm
//type 4 : torso
//type 5 : shoulders up



SubRoutine(Sub_ActorSmokeEffect,float(SubParmSmokeCount),float(smokelifespan),float(smokefxtype),float(subActorSmokeCount))	//Body is smoking
{
//SubParmSmokeCount - Counter that starts at zero,


		float(_add,SubParmSmokeCount,1);

		float(_set,subActorSmokeCount,SubParmSmokeCount);

		//hands
		if(subActorSmokeCount<190)
		{
			spawnparticle(fx_actorsmoke,8,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,12,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,8,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,12,EmptyVector,EmptyVector,fx_sub);
		}

		//lower arms
		if(subActorSmokeCount<215)
		{
			spawnparticle(fx_actorsmoke,11,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,11,EmptyVector,EmptyVector,fx_sub);
		}

		//upper arms
		if(subActorSmokeCount<130)
		{
			spawnparticle(fx_actorsmoke,10,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,10,EmptyVector,EmptyVector,fx_add);
		}

		//collar and chest
		if(subActorSmokeCount<225)
		{
			spawnparticle(fx_actorsmoke,5,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,9,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,13,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,14,EmptyVector,EmptyVector,fx_add);
		}

		//neck and head and torso
		if(subActorSmokeCount<255)
		{
			spawnparticle(fx_actorsmoke,4,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,2,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,4,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,2,EmptyVector,EmptyVector,fx_sub);
		}

		//upper thigh
		if(subActorSmokeCount<165)
		{
			spawnparticle(fx_actorsmoke,15,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,19,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,15,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,19,EmptyVector,EmptyVector,fx_sub);
		}

		//lower leg
		if(subActorSmokeCount<185)
		{
			spawnparticle(fx_actorsmoke,17,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,21,EmptyVector,EmptyVector,fx_add);
			spawnparticle(fx_actorsmoke,17,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,21,EmptyVector,EmptyVector,fx_sub);
		}

		//feet
		if(subActorSmokeCount<195)
		{
			spawnparticle(fx_actorsmoke,18,EmptyVector,EmptyVector,fx_sub);
			spawnparticle(fx_actorsmoke,22,EmptyVector,EmptyVector,fx_sub);
		}
}




SubRoutine(Sub_ActorFireEffect,float(SubParmSmokeCount),float(SubParmFireCount),float(firelifespan),float(firefxtype),float(subActorFireCount))	//Put his body on fire
{
		float(_set,SubParmSmokeCount,0);
		call(ModelAmbient,-4,-7,-7);

		if(vrnd<50)
		{
			vector(_set,tmpvector,255,32,16);
			SpawnLight(fire_light,0,emptyvector,tmpvector,EmptyVector,400);
		}

		
		float(_set,TmpFloat,SubParmFireCount)
		float(_and,TmpFloat,31);	//Speed for how often it must subtract energy
		if(TmpFloat==0)
		{
			call(SubtractHealth,0,DamageOnFire)
		}
		float(_add,SubParmFireCount,1);

		float(_set,subActorFireCount,SubParmFireCount);

		//hands
		if(subActorFireCount>4)
		{
			spawnparticle(fx_actorfire,8,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,12,EmptyVector,EmptyVector,-1);
		}

		//lower arms
		if(subActorFireCount>8)
		{
			spawnparticle(fx_actorfire,11,EmptyVector,EmptyVector,-1);
		}

		//upper arms
		if(subActorFireCount>12)
		{
			spawnparticle(fx_actorfire,10,EmptyVector,EmptyVector,-1);
		}

		//neck and head and torso
		if(subActorFireCount>18)
		{
			spawnparticle(fx_actorfire,4,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,2,EmptyVector,EmptyVector,-1);
		}

		//collar and chest
		if(subActorFireCount>23)
		{
			spawnparticle(fx_actorfire,5,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,9,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,13,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,14,EmptyVector,EmptyVector,-1);
		}

		//upper thigh
		if(subActorFireCount>30)
		{
			spawnparticle(fx_actorfire,15,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,19,EmptyVector,EmptyVector,-1);
		}

		//lower thigh
		if(subActorFireCount>35)
		{
			spawnparticle(fx_actorfire,20,EmptyVector,EmptyVector,-1);
		}

		//lower leg
		if(subActorFireCount>40)
		{
			spawnparticle(fx_actorfire,17,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,21,EmptyVector,EmptyVector,-1);
		}

		//feet
		if(subActorFireCount>50)
		{
			spawnparticle(fx_actorfire,18,EmptyVector,EmptyVector,-1);
			spawnparticle(fx_actorfire,22,EmptyVector,EmptyVector,-1);
		}


		if(SubParmFireCount>firelifespan)	//The fire must stop automatically if the character cant do it by himself.
		{
			if(firefxtype==0)
			{
				if(VState==StateHarpooned||VState==StateCrawling||VState==StateDead||VAICon==0)
				{
					ActorFlag(_clr,_AFLAGnoai);
					state(_change,StateOnFire,StateBlind)
					float(_set,SubParmFireCount,0)
				}
			}
			else
			{
				float(_set,SubParmFireCount,0)
				fxflag(_clr,_fxFLAGFire);
				fxflag(_or,_fxFLAGSmoke);
			}
		}
}

SubRoutine(Sub_SqueezeCheck,const(CrushAction));
{
		if(VTrigger==_DIRalive && VActorFlag==_AFLAGSqueeze)
		{
			if(VAIcon==0)
			{
				call(AIchangerank,0);		//take care of deaths internally!
			}
			state(_set,StateDead);
			Direction(_clr,_DIRalive);
			spawnaction(CrushAction);

//			if(VAICon!=0)
//			{
//				sample(SFXCrushedReact,-1);
//			}
		}
}
