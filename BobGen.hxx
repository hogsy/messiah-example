

		float(_declare,JumpIdleCounter,0);
		float(_declare,JumpPressCounter,0);
		float(_declare,DownwardPull,0);
		float(_declare,TurnSpeed,0);
		float(_declare,ColAngleCorrectNeeded,0);
		float(_declare,ForceRunFrames,0);
		float(_declare,AirSpeedForward,0);
		float(_declare,AirSpeedSideways,0);
		float(_declare,FallStartAltitude,0);
		float(_declare,SmokeCount,500);
		float(_declare,FireCount,0);
		float(_declare,ActionOK,1);
		float(_declare,Hanging,0);
		float(_declare,LastColDistance,0);
		float(_declare,BobFlapStrength,0);
		float(_declare,DieCounter,0);
		float(_declare,SteamCounter,0);

		float(_declare,ActorFireType,0);
		float(_declare,ActorFireLife,255);
		float(_declare,ActorFireCount,0);
		float(_declare,ActorSmokeCount,0);

		float(_declare,HitByFireCount,0);

		float(_declare,InvisibleCounter,0);

		vector(_declare,LastPos,0,0,0);


		Print("Hanging: ",Hanging);

		callsub(Sub_SqueezeCheck,GENCrushed);

		if(Hanging==0 && VActionList!=BobClimbAnims)
		{
			call(CheckColSphereOffset);
		}

		if(VTrigger==_DIRactionhold || VTrigger==_DIRaction)
		{
			Collision(0,0,0,0,0,-50);
			if(VColMaterialProperties==_MATPush)
			{
				call(MoveBackgroundObject);
			}
		}


		if(VActorFlag==_AFLAGradiated)
		{
			call(SubtractHealth,0,DamageRadioactive);
			ActorFlag(_clr,_AFLAGradiated);
		}


		//	AFLAGconfused should be for the concussion grenades for bob
		//
		if(VActorFlag==_AFLAGconfused)
		{
			call(SubtractHealth,0,DamageMachineGun);
			ActorFlag(_clr,_AFLAGconfused);
			Sample(SFXExplosionReact,-1);
		}
		
		if(VActorFlag==_AFLAGnorotation)
		{
			Direction(_clr,_DIRleft);
			Direction(_clr,_DIRright);
		}

		if(VActorFlag==_AFLAGkillandremove)
		{
			print("Kill flag set");
			call(SubtractHealth,0,30000);
		}

		if(VHealth<=0)
		{
			Direction(_clr,_DIRalive);
		}


		ActorFlag(_clr,_AFLAGcolfromabove);
		if(VState==StateFlying || VState==StateGliding || VState==StateFalling)
		{
			Collision(0,0,0,0,50,0);
			if(vcolflag==_DIRhorcol)
			{
				ActorFlag(_or,_AFLAGcolfromabove);
			}
		}

		float(_declare,PlayOnce,0);
		float(_declare,PlayOnceFX,0);

		if(VAICon==0 && vstate==statedead && PlayOnceFX==0)
		{
			sample(SFXJustDiedReact,-1);

			//if(vendofanim!=0)
			//{
				spawnparticle(fx_depossessflare,0,emptyvector,emptyvector,-1);
				spawnparticle(fx_depossessflare,0,emptyvector,emptyvector,-1);
				spawnparticle(fx_depossessflare,0,emptyvector,emptyvector,-1);
				spawnparticle(fx_depossessflare,0,emptyvector,emptyvector,-1);

				vector(_set,tmpvector,64,56,64);
				SpawnLight(PossessLight,0,emptyvector,tmpvector,EmptyVector,800);
				float(_set,PlayOnceFX,1);
			//}
		}

		if(VAICon==0 && vstate==statedead && PlayOnce==0)
		{
			call(CDSwap,-1,0,0,150);

			message("YOU CALL YOURSELF THE MESSIAH?",400,10);
			if(NrCopsInSet!=0)
			{
				sample(SFXCopJustKilledBobReact,-1);
			}
			else
			{
				sample(SFXJustKilledBobReact,-1);
			}
			float(_set,PlayOnce,1);
		}
		elseif(vstate!=statedead)
		{
			float(_set,PlayOnce,0);
		}

/*
		//Powerup code for invisibility, slowdown and speedup. Not used presently
		if(VKey==Key_O)
		{
			call(AIorder,_set,_AIinvisible);
			float(_set,InvisibleCounter,240);
			call(SetBlendingMode,true,_or,_SXMSubTrans,64);
		}
		elseif(InvisibleCounter>0)
		{
			print("Invisible  ",InvisibleCounter);
			float(_sub,InvisibleCounter,1);

			if(InvisibleCounter<30)
			{
				if(InvisibleCounter&=1)
				{
					call(SetBlendingMode,true,0,0,128);
				}
				else
				{
					call(SetBlendingMode,true,0,0,255);
				}
			}

			if(InvisibleCounter==0)
			{
				call(AIorder,_clr,_AIinvisible);
				call(SetBlendingMode,true,_and,_SXMSubTrans,255);
			}
		}
		if(VKey==Key_J)
		{
			call(ClrSlowFastMotion);
		}
		if(VKey==Key_K)
		{
			float(_set,TmpFloat,0.2);
			call(SetSlowFastMotion,false,TmpFloat);
		}
		if(VKey==Key_L)
		{
			call(SetSlowFastMotion,true,2);
		}
*/

		if(VKey==Key_K)
		{
			float(_set,TmpFloat,0.2);
			call(SetSlowFastMotion,false,TmpFloat);
		}
		if(VKey==Key_L)
		{
			call(SetSlowFastMotion,true,2);
		}

/*		if(vactivetime==10)
		{
			vector(_set,tmpvector,255,255,255);
			vector(_set,Gactorpos,-12098,24789,20870);
			SpawnLight(Lvolumelight,-1,gactorpos,tmpvector,EmptyVector,350);
		}
*/

/*
		if(vkey==key_v)
		{
			//SpawnAction(BobTaunt);
			SpawnAction(BobFlapWoundLight);
			State(_or,StateExecuteAnim);
		}
*/

		if(VActor==Bob1)
		{
			Direction(_clr,_DIRdepossesion)
			if(VActiveTime==0)
			{
				callsub(Sub_ChangeStateToNormal);
				float(_set,PlayerHeadBone,4);
				if(VGameCounter!=2)
				{
	//FirstFrame in Deposess
					spawnaction(BobDeposses);
					state(_or,StateExecuteAnim);
					vector(_settoactorpos,TmpVector);
					vector(_copyy,TmpVector,FallStartAltitude);
				}
				else
				{
	//First frame in game
				}
			}
			elseif(VActiveTime==1)
			{
				spawnactor(Halo,0,0,0);
				call(CheckForPickup,4,_ClassPickup);

				ChangeMaterialFlags(_or,7,_SXMChromaKey,255);

				//call(SubtractHealth,0,-3000);		//bob full health after a depossess (just for now)
			}
		}

		if(VColMaterialProperties==_MATDrown || VAction==BobDrown)
		{
			if(VAction!=BobDrown)
			{
				state(_or,StateExecuteAnim);
				SpawnAction(BobDrown);
				vector(_settoactorpos,Gactorpos);
				sample(SFXDrownReact,Gactorpos);
			}
			if(DieCounter==0)
			{
				state(_or,StateDead);
				float(_add,DieCounter,1);
				call(LockCamera,true);
				move(0,-50,0);
				direction(_clr,_DIRalive);
			}
			else
			{
				if(vrnd<15&&DieCounter<60)
				{
					callsub(Sub_RandomWaterSFX);
				}

				float(_add,DieCounter,1);
			}
			move(0,-1,0);
		}

		if(VAction==BobFlyDeadFall || VOAction==BobFlyDeadFall)
		{
			if(VTrigger==_DIRhorcol)
			{
				MoveFeetColOffset(0,25,0);
				SpawnAction(BobFlyDeadLand);
				state(_or,StateExecuteAnim|StateDead);
				CallSub(Sub_ChangeStateToNormal);
			}
		}
		elseif(vstate!=StateDead)
		{
			call(AIupdateAIvars);			//to update aicounters like TimeNotTarget
			call(AIcheckfortarget,10);		//for LineOfSight reasons etc. this is called for player character also

			callSub(Sub_ActionKeyHandler,ActionOK);

			/*	this is bob's running or standing possesion

			call(CheckForJumpPossesion,125,512);
			if(VTrigger==_DIRTempFlag && VTrigger==_DIRjump)
			{
				state(_or,StateExecuteAnim);

				if(VTrigger==_DIRforward || VTrigger==_DIRbackward)	//maybe include walking aswell
				{
					SpawnAction(BobRunJumpPosses);
				}
				else
				{
					SpawnAction(BobJumpPosses);
				}

				Direction(_clr,_DIRjump);		//make sure nobody else uses this right now
			}
			*/

			if(VAction==bobshoot2)
			{
				if(vframe==30)
				{
					sample(SFXbobbang,-1);
				}
				if(vframe==90)
				{
					sample(SFXbobphoomp,-1);
				}
			}


			if(VAction!=BobDeposses)
			{
				if(Vstate==StateFlying||vstate==StateFalling||vstate==StateJump||vstate==StateGliding)
				{
					call(CheckForPossesion);	//DiameterSqr
				}
			}

			call(DeadClassRank,true,100);
			CallSub(BackGroundTriggerChecks);
			call(DeadClassRank,false);

			if(VActorFlag==_AFLAGresetfallalt)				//need to be after bacgroundtriggerchecks prevent death
			{
				ActorFlag(_clr,_AFLAGresetfallalt);
				vector(_settoactorpos,TmpVector);
				vector(_copyy,TmpVector,FallStartAltitude);
			}

			callSub(Sub_CheckRemainingActions,BobConsole,20);

			callsub(Sub_Headtrack);					//Track head against object
			CallSub(Sub_CheckFallDamage,AIAbility,BobTouchDown,FallStartAltitude,BobMaxFall,DamageBobFall,BobFallDead,BobBangHead,Bobfall);
		}

		callsub(Sub_CheckHit,AIAbility,BobWoundLight,BobWoundLightRun,0,FireCount,BobDead,BobWoundLight,BobThrownForward,BobThrownBack,BobThrownBack,BobThrownBack,HitByFireCount);

		if(vstate==StateHarpooned)
		{
			if(VState!=StateDead)
			{
				call(SubtractHealth,_COLsingleattach,DamageMaxDamage);
			}
		}
		elseif(vstate==StateOnFire)	//These first if-statements are just for effects
		{
			if(vrnd<15)
			{
				CheckActorCollision(0,emptyVector,96,0,_COLfire,DamageFlameThrower);
			}

			if(FireCount==0)
			{
				samplestop(SFXCough);
				sample(SFXOnFire,-1);
				sample(SFXGenericBurn,-1);
			}
			float(_set,ActorFireType,0);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorFireEffect,SmokeCount,FireCount,ActorFireLife,ActorFireType,ActorFireCount)
		}
		elseif(vstate==StateBlind)
		{
			if(SmokeCount==0)
			{
				samplestop(SFXGenericBurn);
				sample(SFXCough,-1);
			}

			float(_set,ActorFireType,0);
			float(_set,ActorFireLife,255);
			callsub(Sub_ActorSmokeEffect,SmokeCount,ActorFireLife,ActorFireType,ActorSmokeCount)
		}
		elseif(VState==StateThrown)
		{
			if (VAction==BobGetUpFromFrontFaceDown || VAction==BobGetUpFromBack)
			{
				CallSub(sub_ChangeStateToNormal);
			}
		}

		callsub(Sub_CheckDeadOrDying,AIAbility,BobDead,BobDead,BobDead,0,0,0,BobDead,BobThrownBack);

		CallSub(Sub_CheckClimbUp,bobclimbhang,30,ColAngleCorrectNeeded,20,BobHangMoveIn)

		if(VAction==BobClimbHang)	//outside executeanim, because execute is cleared when shimmy left or right
		{ 
			if(HelpVar&=Help11 && TutorialToggle==1 && AirLock&=Help08 && InBattle==0)
			{
				ClearTutorialLines();
				AddTutorialLine("[20:250:50]Bob[255:255:255] can grab onto ledges and");
				AddTutorialLine("shimmy left and right. To move");
				AddTutorialLine("to the left or to the right@");
				AddTutorialLine("just press your [20:250:50]LEFT[255:255:255] or [20:250:50]RIGHT[255:255:255]");
				AddTutorialLine("direction key. To climb upon");
				AddTutorialLine("the ledge@ press [20:250:50]FORWARD[255:255:255]. To");
				AddTutorialLine("fall back@ press [20:250:50]BACKWARD[255:255:255].");
				AddTutorialLine(" ");
				AddTutorialLine("    [255:255:100]             Press Any Key       ");
				AddTutorialLine("    [255:255:100]             To Continue         ");
				DisplayTutorialScreen("[255:255:20]Hand-over-hand",15,15);
				float(_clr,HelpVar,help11);	
			}
			callsub(Sub_CheckHanging,Hanging,BobClimbUp,BobFall,BobHangMoveIn);

			vector(_settoactorpos,LastPos);
		}
		elseif(Hanging==1 && VTrigger==_DIRhorcol && VActionList!=BobClimbAnims)
		{
			float(_set,Hanging,0);	//if said to be hanging but on the ground, reset hang variable
//			MoveFeetColOffset(0,0,BobHangMoveIn);
//			float(_set,TmpFloat,BobHangMoveIn);
//			float(_inv,TmpFloat);
//			move(0,0,TmpFloat);
		}

		if(Hanging==1)				//bob is hanging on a ledge
		{
			//if(VAction==BobWoundLight || VState==StateThrown)
			//if(VAction!=BobClimbUp && VAction!=BobClimbHang && VAction!=BobShimmyLeft && VAction!=BobShimmyRight && VAction!=BobShimmyLeft2 && VAction!=BobShimmyRight2)
			if(VActionList!=BobClimbAnims)
			{
				state(_clr,StateExecuteAnim);
				state(_clr,StateNormal);
				//SpawnAction(DropDown);
				state(_or,StateFalling);
				float(_set,Hanging,0);
//				MoveFeetColOffset(0,0,BobHangMoveIn);
//				float(_set,TmpFloat,BobHangMoveIn);
//				float(_inv,TmpFloat);
//				move(0,0,TmpFloat);
			}
			else
			{
				if(ColAngleCorrectNeeded!=0)
				{
					turn(0,ColAngleCorrectNeeded,0);
					float(_set,ColAngleCorrectNeeded,0);
				}

				float(_set,TmpFloat,0);

				if(VTrigger==_DIRright || VTrigger==_DIRsideright)
				{
					if(VAction!=BobShimmyLeft && VAction!=BobShimmyLeft2)
					{
						float(_set,TmpFloat,-1);
					}
				}
				if(VTrigger==_DIRleft || VTrigger==_DIRsideleft)
				{
					if(VAction!=BobShimmyRight && VAction!=BobShimmyRight2)
					{
						float(_set,TmpFloat,1);
					}
				}

				vector(_settoactorpos,TmpVector);
				vector(_sub,TmpVector,LastPos);
				vector(_copyy,TmpVector,TmpFloat2);
				float(_inv,TmpFloat2);
				move(0,TmpFloat2,0);

				if(TmpFloat!=0)			//shimmy left or right
				{
					vector(_set,TmpVector,0,30,0);
					vector(_copy,TmpVector2,TmpVector);
					float(_seti,TmpFloat2,VColFeetSphereSize);
					float(_add,TmpFloat2,4);
					if(VAction==BobClimbHang)
					{
						float(_add,TmpFloat2,2);
					}
					float(_mul,TmpFloat2,TmpFloat);
					vector(_setx,TmpVector2,TmpFloat2);
					Collision(TmpVector,TmpVector2);
					if(VColFlag==_DIRvercol)
					{
						if(TmpFloat==-1)
						{
							Direction(_clr,_DIRright|_DIRsideright);
						}
						else
						{
							Direction(_clr,_DIRleft|_DIRsideleft);
						}
					}
					else				//didn't hit a wall to either side
					{
						vector(_copy,TmpVector,TmpVector2);
						vector(_setz,TmpVector2,-35)
						Collision(TmpVector,TmpVector2);
						if(VColFlag!=_DIRvercol)
						{
							if(TmpFloat==-1)
							{
								Direction(_clr,_DIRright|_DIRsideright);
							}
							else
							{
								Direction(_clr,_DIRleft|_DIRsideleft);
							}
						}
						else			//hit a wall in front and to the side
						{
							float(_seti,TmpFloat2,VColSphereSize);
							float(_add,TmpFloat2,50);
							vector(_sety,TmpVector,TmpFloat2);
							vector(_sety,TmpVector2,TmpFloat2);
							vector(_setz,TmpVector2,-60);
							Collision(TmpVector,TmpVector2);
							if(VColFlag==_DIRvercol)	//hit a wall in front, to the side and above
							{
								if(TmpFloat==-1)
								{
									Direction(_clr,_DIRright|_DIRsideright);
								}
								else
								{
									Direction(_clr,_DIRleft|_DIRsideleft);
								}
							}
						}
					}
				}

				if(Vaction==BobShimmyLeft || Vaction==BobShimmyLeft2 || Vaction==BobShimmyRight || Vaction==BobShimmyRight2)
				{
					if(VFrame==5)
					{
						if(VRnd<50)
						{
							Sample(SFXBobHand1,-1);
						}
					}
				}
			}
		}

		if(vstate==StateExecuteAnim)
		{
			callsub(Sub_CheckExecuteAnimEnd);
/*			if(vaction==BobFlyBackFlip)
			{
				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeedAir,0);
				callsub(Sub_MoveBobInAir,AirSpeedForward,AirSpeedSideways,TurnSpeed,ColAngleCorrectNeeded)
				callsub(Sub_CheckExecuteAnimEnd)
			}
			
*/
			if(VAction==BobFlyDead)
			{
				turn(0,100,0);
			}
			elseif(VOAction==BobFlyDead)
			{
				SpawnAction(BobFlyDeadFall);
				state(_or,StateExecuteAnim);
			}

			if(VAction==BobFlyDeadFall)
			{
				turn(0,100,0);
			}

			if(vaction==BobFlyFromSmackWall)
			{
				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeedAir,0);
				callsub(Sub_MoveBobInAir,AirSpeedForward,AirSpeedSideways,TurnSpeed,ColAngleCorrectNeeded)
			}

			if(VOAction==BobFlySmackWall && vstate!=StateExecuteAnim)
			{
				//SpawnAction(BobFlyFromSmackWall);
				State(_or,StateExecuteAnim);
			}
			elseif(VAction==BobDeposses)
			{
				float(_seti,TmpFloat1,VFrame)
				float(_set,TmpFloat2,TmpFloat1)
				float(_mul,TmpFloat1,-0.5)
				float(_add,TmpFloat1,24)
				float(_mul,TmpFloat2,-0.8)
				float(_add,TmpFloat2,14)
				if(TmpFloat2<0)
				{
					float(_set,TmpFloat2,0)
				}
				move(0,TmpFloat1,TmpFloat2)
				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeedAir,0);
//XXX				callsub(Sub_CheckExecuteAnimEnd)
			}
			elseif(VOAction==BobClimbUp && vstate!=StateExecuteAnim)
			{
				move(0,0,BobHangMoveIn);
//				MoveFeetColOffset(0,0,BobHangMoveIn);
			}
			else
			{
//ClimbUp, ExplosionThrow
//XXX				callsub(Sub_CheckExecuteAnimEnd);
			}
		}
/*		elseif(vstate==StateBangedHead)
		{
			state(_clr,StateBangedHead);
			spawnaction(BobBangHead);
			state(_or,StateExecuteAnim);
		}
*/
		elseif(vstate==StateDead)
		{
//Perhaps other states here, like on fire etc.
		}
		elseif(VActorFlag==_AFLAGattached)
		{
			//don't execute any other code, and clear any in air state
			//

//			State(_clr,StateInAir);
		}
		else
		{
			//			CallSub(Sub_CheckClimbUp,bobclimbup,30,ColAngleCorrectNeeded,20)
			if(vstate==StateElectricShock)
			{
/*				callsub(Sub_ElectricShock,bobelectricshock0,bobelectricshock1);

				//	add correct thrown code here
				//

				if(vaction==bobelectricshock0)
				{
					if(vframe==1)
					{
						sample(SFXElectricShock2,-1);
						call(SubtractHealth,0,DamageElectric);
					}
				}

				if(vaction==bobelectricshock1)
				{
					if(vframe<15)
					{
						move(0,0,6);
					}
					if(vendofanim!=0)
					{
						state(_change,StateElectricShock,StateNormal);
					}
				}
*/
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
				elseif(voaction==GENelectricshock0)
				{
					sample(SFXElectrocuteReact,-1);

					call(PlaneTriggerQuadrant,TmpFloat,1);
					if(TmpFloat==0)
					{
						spawnaction(BobThrownForward);
						move(0,0,-150);
					}
					elseif(TmpFloat==1)
					{
						spawnaction(BobThrownBack);		//left
						move(150,0,0);
					}
					elseif(TmpFloat==2)
					{
						spawnaction(BobThrownBack);
						move(0,0,150);
					}
					elseif(TmpFloat==3)
					{
						spawnaction(BobThrownBack);		//right
						move(-150,0,0);
					}
					state(_clr,StateElectricShock);
				}
			}
			elseif(vstate==StateNormal && Hanging==0)
			{
				callsub(Sub_CheckForIdleLongTime,BobIdle,BobIdleLongTime);
				if(VAction==BobIdleLongTime)
				{
					sample(SFXBoredIdle,-1);
				}

				if(VAction==BobDeposses)
				{
					spawnaction(BobDepossesDaze);
				}
				rotatebone(0,0,0,0);	//Correct after landing on ground.

				if(VState!=StateCrouching)
				{
					callsub(sub_AlignToWallAndCheckRunUpStairs,BobRunUpStairs,BobIdle,BobIdleHitWall,ColAngleCorrectNeeded,BobIdleHitWallFront,BobHitWallSpreadOut,-0.33,BobSpreadOut,0,ForceRunFrames)
				}

				CallSub(Sub_CheckCrouching,BobCrouchDown,BobCrouchUp);

				CallSub(Sub_CheckJumpFallDown,AIAbility,BobRunUpStairs,JumpPressCounter,DownwardPull,0,BobJump,AirSpeedForward,AirSpeedSideways,BobFall,0);
				CallSub(Sub_CheckSliding,BobRunUpStairs,BobSlide);

				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeed,0);
			}
			elseif(vstate==StateFalling)
			{
				if(vtrigger==_DIRjump)
				{
					float(_set,BobFlapStrength,0);
					float(_set,JumpPressCounter,0)
					state(_change,StateFalling,StateFlying);
				}
				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeedAir,0);
				callsub(Sub_MoveBobInAir,AirSpeedForward,AirSpeedSideways,TurnSpeed,ColAngleCorrectNeeded)
				CallSub(Sub_CheckSliding,BobRunUpStairs,BobSlide);
			}
			elseif(vstate==StateJump)
			{
				if(vaction!=BobJump)
				{
					float(_set,BobFlapStrength,0);
				}
				CallSub(Sub_Jump,JumpPressCounter,DownwardPull,BobMinHoldJumpAction,0,0,BobFall)
				if(vstate==StateFlying)
				{
					float(_set,BobFlapStrength,-1);	//Because first doesn't count when holding down
				}
				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeedAir,0);
				callsub(Sub_MoveBobInAir,AirSpeedForward,AirSpeedSideways,TurnSpeed,ColAngleCorrectNeeded)
			}
			elseif(vstate==StateFlying)	//Flapping
			{
				if(BobFlapStrength>-1&&BobFlappingEnabled==0)
				{
					float(_set,SubSubParm1,BobFall)
					callsub(Sub_InitFall)
				}
				else
				{
					if(vtrigger==_DIRactorbulletcol)
					{
						SpawnAction(BobFlapWoundLight);
					}
					else
					{
						spawnaction(BobFlap);

						callsub(Sub_BobFlapControl,BobFlapStrength);
						callsub(Sub_InAirCheckGround,BobTouchDown);

						if(vtrigger==_DIRjump)
						{
							float(_set,JumpIdleCounter,0);
							float(_add,JumpPressCounter,1);
							if(JumpPressCounter>BobFlapPressThreshold)
							{
								state(_change,StateFlying,StateGliding);
							}
						}
						else
						{
							float(_set,JumpPressCounter,0)
							float(_add,JumpIdleCounter,1);
							if(JumpIdleCounter<10)
							{
								float(_add,BobFlapStrength,0.3);
							}
							else
							{
								float(_set,JumpIdleCounter,0);
								float(_set,SubSubParm1,BobFall)
								callsub(Sub_InitFall)
							}
						}
					}
				}
				if(BobFlapStrength>1)
				{
					float(_sub,DownwardPull,BobGravityFlap);
				}
				else
				{
					float(_sub,DownwardPull,BobGravityGlide);
				}
				move(0,DownwardPull,0);
				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeedAir,0);
				callsub(Sub_MoveBobInAir,AirSpeedForward,AirSpeedSideways,TurnSpeed,ColAngleCorrectNeeded)
			}
			elseif(vstate==StateGliding)
			{
				spawnaction(BobGlide);
				callsub(Sub_InAirCheckGround,BobIdle);

				if(vtrigger==_DIRjump)
				{
					if(JumpPressCounter==0)
					{
						state(_change,StateGliding,StateFlying);
					}
				}
				else
				{
					float(_set,SubSubParm1,BobFall)
					callsub(Sub_InitFall)
				}
				float(_sub,DownwardPull,BobGravityGlide);
				move(0,DownwardPull,0);
				callsub(Sub_TurnCharacter,TurnSpeed,BobMaxTurnSpeedAir,0);
				callsub(Sub_MoveBobInAir,AirSpeedForward,AirSpeedSideways,TurnSpeed,ColAngleCorrectNeeded)
			}
		}

		//Bobs Sound FX
		if(vaction==bobflap||vaction==bobjump)
		{
			if(vframe==0)
			{
				sample(SFXBobFlap,-1);
			}
			elseif(vframe<=1)
			{
				sample(SFXBobFlap,-1);
			}
			elseif(vframe<=2)
			{
				sample(SFXBobFlap,-1);
			}
			elseif(vframe<=3)
			{
				sample(SFXBobFlap,-1);
			}
		}


		call(CheckAttached,_CANormal);
//		callsub(Sub_CheckForPickups);


		float(_declare,footsampleb,0);
		if(VAICon==0 && vtrigger==_DIRleft||vtrigger==_DIRright||vtrigger==_DIRforward||vtrigger==_DIRbackward||vtrigger==_DIRsideleft||vtrigger==_DIRsideright)
		{
			if(VSpecialFlag==_sFLAGTrodInGoo)
			{
				if(vrnd<50)
				{
					spawnparticle(fx_footbloodspray,20,emptyvector,emptyvector,-1);
				}
				else
				{
					spawnparticle(fx_footbloodspray,24,emptyvector,emptyvector,-1);
				}
				if(footsampleb==0)
				{
					float(_set,footsampleb,25);
					sample(SFXBlood2,-1);
				}
			}
			else
			{
				callsub(Sub_CheckFootSteps,_sFLAGLeftFoot);
				callsub(Sub_CheckFootSteps,_sFLAGRightFoot);
			}
			if(footsampleb>0)
			{
				float(_sub,footsampleb,1);
			}
		}

		if(VState==StateForceField)
		{
			State(_clr,StateForceField);

			float(_set,DownWardPull,0);
			float(_set,BobFlapStrength,0);
			float(_set,JumpPressCounter,0)
		}

		if(VState==StateSteamed)
		{
			if(SteamCounter==30)
			{
				float(_set,SteamCounter,0);
				state(_clr,StateSteamed);
			}
			else
			{
				float(_add,SteamCounter,1);
			}
		}
