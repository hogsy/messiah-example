
SubRoutine(Sub_Deposses)
{
		if(VDifficulty<_DifficultyHard && VAIcon==0)
		{
			callsub(Sub_InitDepossesion,0,0,0);
			//DePossesion callback effect init here
			call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,120);

			camera(fly_camera_distance,fly_camera_angle);
			Target(fly_camera_Tdistance,fly_camera_Tangle);
		}
}


//Checks if character is jumping or falling
SubRoutine(Sub_CheckJumpFallDown,float(AIAbility),const(OnStairsAction),float(JumpPressCounter),float(DownwardPull),const(JumpSpeed),const(JumpAction),float(AirMoveSpeedForward),float(AirMoveSpeedSideways),const(FallAction),const(MaxAirSpeed))
{
//OnStairsAction
//JumpPressCounter
//DownwardPull
//JumpSpeed
//JumpAction
//AirMoveSpeedForward
//AirMoveSpeedSideways
//FallAction
//MaxAirSpeed
		if(VState!=StateThrown)
		{
			if(AIAbility&!=_AIAJump)
			{
				Direction(_clr,_DIRjump);
			}

			if(vtrigger==_DIRjump&&votrigger!=_DIRjump)
			{
				if(VActorFlag!=_AFLAGconfused)
				{
					if(VAICon==0 && vaction!=JumpAction && VClass!=_ClassAngel)
					{
						if(VClass==_ClassBeast)
						{
							sample(SFXBeastJump,-1);
						}
						else
						{
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

					spawnaction(JumpAction);

		//			call(CheckConnections)
					if(JumpPressCounter>0 || VAIClass==_AIclassAngel)
					{
						float(_set,JumpPressCounter,0)
					}
					if(VActor==Bob1)
					{
						//XXX state(_or,StateExecuteAnim);
						float(_set,DownwardPull,BobJumpSpeed);
					}
					else
					{
						float(_set,DownwardPull,JumpSpeed);
						if(VState==StateCrouching)
						{
							float(_div,DownwardPull,2);
						}
					}
					state(_change,StateNormal,StateJump);

					vector(_speedfromdirflags,TmpVector1)
					float(_set,SubVar1,MaxAirSpeed)		//Get initial speed
					vector(_setZ,TmpVector2,SubVar1)
					float(_mul,SubVar1,-1)
					vector(_setX,TmpVector2,SubVar1)
					vector(_mul,TmpVector1,TmpVector2)
					vector(_copyX,TmpVector1,AirMoveSpeedSideways)
					vector(_copyZ,TmpVector1,AirMoveSpeedForward)
				}
			}
			else	//Check if falling.
			{
				if(VAction!=OnStairsAction)		//Not when walking on stairs
				{
					if(Vtrigger!=_DIRhorcol)
					{
						float(_Seti,SubVar1,VColFeetSphereBottom)
						float(_mul,SubVar1,-1)
						float(_add,SubVar1,70)

						if(VDistToGround>SubVar1)
						{
							if(VState!=StateThrown)
							{
								float(_set,SubSubParm1,FallAction);
								callsub(Sub_InitFall);				//breaks climb XXX
							}

							vector(_speedfromdirflags,TmpVector1)
							float(_set,SubVar1,MaxAirSpeed)	//Set initial speed
							vector(_setZ,TmpVector2,SubVar1)
							float(_mul,SubVar1,-1)
							vector(_setX,TmpVector2,SubVar1)
							vector(_mul,TmpVector1,TmpVector2)
							vector(_copyX,TmpVector1,AirMoveSpeedSideways)
							vector(_copyZ,TmpVector1,AirMoveSpeedForward)
						}
					}
				}
			}
		}
}

SubRoutine(Sub_CheckSliding,const(OnStairsAction),const(SlideAction))
{
		if(vtrigger!=_DIRjump && VAction!=OnStairsAction)
		{
			if(Vtrigger!=_DIRhorcol && VTrigger==_DIRvercol && VState!=StateExecuteAnim)
			{
				//fire ray down from character and get the angle from the surface
				//below and do stuff depending on the angle.
/*				if(VClass==_ClassAngel)
				{
					Collision(0,-30,0,0,-80,0);
				}
				else
				{
*/

					float(_seti,TmpFloat,VColFeetSphereBottom);
					float(_add,TmpFloat,10);
					vector(_set,TmpVector,0,0,0);
					vector(_sety,TmpVector,TmpFloat);
					vector(_set,TmpVector2,0,0,0);
					float(_sub,TmpFloat,20);
					vector(_sety,TmpVector2,TmpFloat);
					Collision(TmpVector,TmpVector2);
//				}
				Slope(45,_Greater);
				//Slope(46,_Less);
				

				if(VTrigger==_DIRTempFlag)
				{
					if(VState!=StateFalling)
					{
						float(_set,SubSubParm1,SlideAction)
						callsub(Sub_InitFall)
					}
					elseif(VAction!=SlideAction)
					{
						spawnaction(SlideAction);
					}
				}
			}
		}
}

//cop jump
//CallSub(Sub_Jump,JumpPressCounter,DownwardPull,15,CopJumpGravity,2,0)

SubRoutine(Sub_Jump,float(JumpPressCounter),float(DownwardPull),const(MinHoldJumpAction),const(JumpGravity),const(FrameStartMoveUp),const(FallingAction))
{
		if(vtrigger==_DIRjump || JumpPressCounter<MinHoldJumpAction)
		{
			if(JumpPressCounter>0 || VAIClass==_AIclassAngel)
			{
				float(_add,JumpPressCounter,1)
			}
			if(VFrame>=FrameStartMoveUp)
			{
				if(VActor==Bob1)
				{
					float(_sub,DownwardPull,BobJumpGravity);
					float(_set,SubVar1,0);
					if(vtrigger!=_nodir)
					{
						if(vtrigger!=_DIRvercol||ColAngleTmp>400||ColAngleTmp<-400)
						{
							float(_set,SubVar1,1);
						}
					}
					if(SubVar1==0)	//If bob is not moving along X or Z, move more up, and increase gravity
					{
						float(_sub,DownwardPull,BobJumpGravityNoMove);
						move(0,BobJumpNoMoveExtraYMovement,0);
					}
				}
				else
				{
					float(_sub,DownwardPull,JumpGravity);
				}
				move(0,DownwardPull,0);
			}
			if(vendofanim!=0)
			{
				if(JumpPressCounter>0 || VAIClass==_AIclassAngel)
				{
					float(_set,JumpPressCounter,0);
				}				
				if(VActor==Bob1)
				{
					state(_change,StateJump,StateFlying);
				}
				else
				{
					move(0,-2,0);
					float(_set,SubSubParm1,FallingAction)
					callsub(Sub_InitFall)
				}
			}
		}
		else
		{
			if(JumpPressCounter>0 || VAIClass==_AIclassAngel)
			{
				float(_set,JumpPressCounter,0);
			}
			float(_set,DownwardPull,0)
			float(_set,SubSubParm1,FallingAction)
			callsub(Sub_InitFall)
		}
}


SubRoutine(Sub_InitFall)
{
//SubSubParm1: Action when falling (0 for no change)
	if(SubSubParm1!=0)
	{
		spawnaction(SubSubParm1);
	}
//	call(CheckConnections)
	//state(_clr,StateHeadTrack);		//SAXS: don't see a need for clearing this. Come tell me otherwise

	state(_clr,StateNormal);
	state(_clr,StateFlying);
	state(_clr,StateGliding);
	state(_clr,StateJump);
	state(_or,StateFalling);
}

SubRoutine(Sub_MoveInAir,float(SubParm1),float(SubParm2),const(SubParm3),const(SubParm4))
{
//SubParm1=AirSpeedSideways
//SubParm2=AirSpeedForward
//SubParm3=MaxAirSpeed
//SubParm4=Bulb Factor
		if(VState!=StateThrown)
		{
			vector(_speedfromdirflags,TmpVector1)

			vector(_set,TmpVector3,0,0,0)
			float(_set,SubVar1,SubParm3)
			vector(_setZ,TmpVector3,SubVar1)
			float(_mul,SubVar1,-1)
			vector(_setX,TmpVector3,SubVar1)
			vector(_mul,TmpVector1,TmpVector3)

			vector(_setX,TmpVector2,SubParm1)
			vector(_setZ,TmpVector2,SubParm2)
			vector(_sub,TmpVector1,TmpVector2)

			vector(_setX,TmpVector3,SubParm4)
			vector(_setZ,TmpVector3,SubParm4)
			vector(_mul,TmpVector1,TmpVector3)
			vector(_add,TmpVector1,TmpVector2)
			vector(_copyX,TmpVector1,SubParm1)
			vector(_copyZ,TmpVector1,SubParm2)

			float(_seti,SubVar1,VActionRotation)
			vector(_rotate,TmpVector1,SubVar1)	//This must be done after bulb because if you change direction in air, it should continue in the direction you were going before
			vector(_copyX,TmpVector1,SubVar1)
			vector(_copyZ,TmpVector1,SubVar2)
			move(SubVar1,0,SubVar2)
		}
}

SubRoutine(Sub_CheckClimbUp,const(ClimbAction),const(MinHeight),float(ColAngleCorrectNeeded),float(CheckHeight),const(MoveForward))		//Check for grab onto ledge
{
//MinHeight:	Minimum height above rootbone when it grabs
//CheckHeight:	Height to check

		Direction(_clr,_DIRTempFlag);
		if(vtrigger==_DIRvercol || VClass==_ClassAngel)
		{
			if(ColAngleTmpFace<600&&ColAngleTmpFace>-600)
			{
//				if(vtrigger==_DIRwalk||vtrigger==_DIRrun)
//				{
					//if(vstate==StateJump||vstate==stateFalling||vstate==stateFlying||vstate==stateGliding)
					if(vstate|=StateJump|stateFalling|stateFlying|stateGliding)
					{
						float(_set,SubVar2,MinHeight);
						float(_add,SubVar2,CheckHeight)			//Height checked
						vector(_set,TmpVector,0,0,0)
						vector(_sety,TmpVector,MinHeight);
						float(_seti,SubVar3,VColFeetSphereSize)
						float(_mul,SubVar3,-1)
						float(_add,SubVar3,-20)
						vector(_set,TmpVector2,0,0,0)
						vector(_sety,TmpVector2,MinHeight);
						vector(_setz,TmpVector2,SubVar3)		//-Sphere-20
						Collision(TmpVector,TmpVector2);
						if(vcolflag==_DIRvercol)
						{
							//Slope(80,_Less);								//more than 10 degrees slope?
							Slope(10,_Greater);								//more than 10 degrees slope?
//							if(VTrigger!=_DIRTempFlag)
							if(VTrigger==_DIRTempFlag)
							{
								vector(_set,TmpVector3,0,20,0);
								vector(_sub,TmpVector,TmpVector3);
								vector(_sub,TmpVector2,TmpVector3);
								Collision(TmpVector,TmpVector2);
								Slope(81,_Less);								//more than 10 degrees slope?
//								Slope(9,_Greater);								//more than 10 degrees slope?
							}
//							if(VTrigger==_DIRTempFlag)	//Lower horizontal collision
							if(VTrigger!=_DIRTempFlag)	//Lower horizontal collision
							{
								float(_seti,TmpFloat2,VColAngle);
								float(_seti,SubVar1,VColDistance);
								vector(_set,TmpVector,0,0,0)
								vector(_set,TmpVector2,0,0,0)
								vector(_sety,TmpVector,SubVar2)
								vector(_sety,TmpVector2,SubVar2)
								float(_set,SubVar4,SubVar3);
								float(_add,SubVar4,-20)
								vector(_setz,TmpVector2,SubVar4)		//-Sphere-40
								Collision(TmpVector,TmpVector2);
								if(vcolflag|=_DIRallcol)	//Upper horizontal collision, Must not be neither wall nor tilted floor here 
								{
								}
								else
								{
									float(_mul,SubVar1,SubVar3);
									float(_div,SubVar1,100);	//Find exact distance to wall.
									float(_add,SubVar1,1);

									vector(_setz,TmpVector,SubVar1);
									vector(_setz,TmpVector2,SubVar1);
									float(_set,SubVar4,SubVar2);
									float(_add,SubVar4,100)		//Altitude that will be used for railing-check
									vector(_sety,TmpVector,SubVar4)
									vector(_sety,TmpVector2,SubVar2)
									Collision(TmpVector,TmpVector2);
									if(vcolflag|=_DIRallcol)	//Vertical collision to make sure it is not a railing (if there is something above it)
									{
									}
									else
									{
										vector(_set,TmpVector,0,0,0)
										vector(_sety,TmpVector,SubVar2)
										vector(_setz,TmpVector,SubVar3)		//-Sphere-20
										vector(_set,TmpVector2,0,0,0)
										vector(_sety,TmpVector2,MinHeight)
										vector(_setz,TmpVector2,SubVar3)	//-Sphere-20
										Collision(TmpVector,TmpVector2);	//Collision to get height of edge relative to model
										if(VClass==_ClassAngel)
										{
											Slope(0,_Equal);
										}
										else
										{
											Direction(_or,_DIRTempFlag);
										}

										//	if this doesn't collide then there is nothing to grab on to really
										//	don't grab moving keyframeobjects
										if(vcolflag==_DIRhorcol && VTrigger==_DIRTempFlag && VColObjTriggered==false)
										{
											float(_seti,SubVar1,VColDistance);
											float(_mul,SubVar1,CheckHeight);
											float(_div,SubVar1,-100);			//-100/height checked
											float(_add,SubVar1,3);				//just make sure they're above the grab surface
											float(_set,TmpFloat,MoveForward);
											float(_inv,TmpFloat);
											MoveFeetColOffset(0,0,TmpFloat);
											move(0,SubVar1,MoveForward);		//Corrects his altitude
											//float(_set,ColAngleCorrectNeeded,ColAngleTmpFace);	//Align to wall
											float(_set,ColAngleCorrectNeeded,TmpFloat2);	//Align to wall
											spawnaction(ClimbAction);
											callsub(sub_ChangeStateToNormal)
											state(_or,StateExecuteAnim);
											Direction(_set,_DIRTempFlag);

											if(VClass!=_ClassAngel)
											{
												sample(SFXGrunt,-1);
											}
											else
											{
												sample(SFXBobClimb,-1);
												rotatebone(0,0,0,0);
											}
										}
									}
								}
							}
						}
					}
//				}
			}
		}
		if(ColAngleCorrectNeeded!=0)	//Correct angle when climbing up or walking stairs
		{
			float(_set,SubVar1,ColAngleCorrectNeeded);
			float(_mul,SubVar1,0.1);
			turn(0,SubVar1,0);
			float(_sub,ColAngleCorrectNeeded,SubVar1);
			rotatebone(0,0,0,0);

		}
}

SubRoutine(sub_AlignToWallAndCheckRunUpStairs,const(SubParm1),const(SubParm2),const(SubParmHitWallIdle),float(SubParm4),const(SubParmHitWallIdleFront),const(SubParmHitWallSpreadOut),const(SubParm9),const(SubParmMoveList),const(SubParmMoveListGun),float(SubParmForceRunFrames))
{
//Checks if character has to walk up stairs, and controls the stairwalking
//Turns character to slide along or face wall. Check if character is allowed to walk in a direction if close to a wall

//SubParm1: Action when running up stairs
//SubParm2: Idle action
//SubParmHitWallIdle: Idle action when hitting wall
//SubParm4: ColAngleCorrectNeeded
//SubParmHitWallIdleFront: Idle action when hitting wall frontally
//SubParmHitWallSpreadOut
//SubParm9:	How much must be added to Y when running on stairs
//SubParmMoveList: List of all move-actions
		if(vtrigger==_DIRvercol)
		{
			if(vtrigger!=_DIRleft&&vtrigger!=_DIRright)
			{
//Corrects angle when walking along wall, or facing wall
				if(VColNrVerRebounds==1)
				{
					if(VActionList==SubParmMoveList||VActionList==SubParmMoveListGun)
					{
						if(VColMaterialProperties|=_MATStairOrLedge)
						{
						}
						else
						{
							vector(_vectorfromdirflags,TmpVector2)

							float(_seti,SubVar1,VColFeetSphereSize)
							float(_Mul,SubVar1,-2.1)
							vector(_setx,TmpVector3,SubVar1)		//-60 for bob
							float(_Mul,SubVar1,-1)
							vector(_setz,TmpVector3,SubVar1)		//60
							vector(_mul,TmpVector2,TmpVector3)

							float(_seti,SubVar1,VColFeetSphereBottom)
							float(_add,SubVar1,15)
							vector(_sety,TmpVector2,SubVar1);
							vector(_set,TmpVector,0,0,0)
							vector(_sety,TmpVector,SubVar1);

							collision(TmpVector,TmpVector2);
							if(vcolflag==_DIRvercol)
							{
								float(_seti,SubVar1,VColAngle)
								if(SubVar1>400||SubVar1<-400)	//turn away from wall, if hitting
								{
									if(SubVar1<1024&&SubVar1>-1024)	//Hit edge when going down stairs should not be corrected
									{
										if(SubVar1<0)
										{
											float(_add,SubVar1,1024);
										}
										else
										{
											float(_sub,SubVar1,1024);
										}	
					
										float(_mul,SubVar1,0.1);
										turn(0,SubVar1,0);
									}
								}
								else	//Turn to face wall, when close to angle.
								{
									float(_set,SubParm4,SubVar1);
				
									float(_Seti,SubVar1,VTrigger)
									float(_And,SubVar1,_DIRMoveBits)
									if(SubVar1!=_DIRforward)
									{
										spawnaction(SubParmHitWallIdle);
									}
									else
									{
										spawnaction(SubParmHitWallIdleFront);
									}
								}
							}
						}
					}
				}
			}

			if(vaction!=SubParm1)	//Not already on stairs
			{
				if(vstate==StateNormal&&Vtrigger==_DIRMove)
				{
					if(VColMaterialProperties==_MATStair)
					{
						if(ColAngleTmpFace<600&&ColAngleTmpFace>-600)
						{
							if(vtrigger==_DIRforward)
							{
								float(_seti,SubVar1,VColFeetSphereBottom);
								float(_add,SubVar1,28);
								float(_seti,SubVar2,VColFeetSphereSize);
								float(_mul,SubVar2,-1);
								float(_add,SubVar2,-20);

								vector(_set,TmpVector,0,0,0)
								vector(_sety,TmpVector,SubVar1);
								vector(_copy,TmpVector2,TmpVector)
								vector(_setz,TmpVector2,SubVar2)
								Collision(TmpVector,TmpVector2);
								if(vcolflag!=_DIRvercol)
								{
									float(_sub,SubVar1,13);
									vector(_sety,TmpVector,SubVar1);
									vector(_sety,TmpVector2,SubVar1);
									Collision(TmpVector,TmpVector2);
									if(vcolflag==_DIRvercol)
									{
										spawnaction(SubParm1);
									}
								}
							}
						}
					}
					elseif(VColMaterialProperties==_MATSmallLedge)
					{
						if(ColAngleTmp<600&&ColAngleTmp>-600)
						{
							if(VClass==_ClassAngel)
							{
								Direction(_set,_DIRjump)
							}
							else
							{
								float(_set,SubParmForceRunFrames,8);	//Frames he will be running to get over ledge
							}
						}
					}
				}
			}
		}
//Check if already on stairs, if you still are, keep running
		if(vaction==SubParm1)
		{
			if(vtrigger==_DIRforward)
			{
				move(0,SubParm9,0);	//Bob -0.33
				float(_seti,SubVar1,VColFeetSphereBottom);
				vector(_set,TmpVector,0,0,50)
				vector(_set,TmpVector2,0,0,-80)
				float(_seti,SubVar2,VColFeetSphereSize);
				float(_mul,SubVar2,-2)
				float(_add,SubVar2,-20);
				vector(_sety,TmpVector,SubVar1);
				vector(_sety,TmpVector2,SubVar1);
				vector(_setz,TmpVector2,SubVar2)	//Bob=-80
				Collision(TmpVector,TmpVector2);
				if(vcolflag==_DIRvercol)
				{
					if(VColNrVerRebounds==1)
					{
						if(VColMaterialProperties|=_MATStair)
						{
							float(_seti,SubParm4,VColAngle);	//Correct angle
						}
					}
					vector(_set,TmpVector,-10,10,-60)
					float(_add,SubVar2,20);
					vector(_setz,TmpVector,SubVar2);		//Bob=-60
					vector(_copy,TmpVector2,TmpVector);
					float(_mul,SubVar1,1.1);
					vector(_sety,TmpVector2,SubVar1);
					Collision(TmpVector,TmpVector2);	//Send ray down Front-right
					if(vcolflag!=_DIRhorcol)
					{
						vector(_set,TmpVector3,-1,1,1)
						vector(_mul,TmpVector,TmpVector2)
						vector(_mul,TmpVector,TmpVector3)
						Collision(TmpVector,TmpVector2);	//Send ray down Front-left
						if(vcolflag!=_DIRhorcol)
						{
							spawnaction(SubParm2);
					printlog("spawn action 44");
							float(_set,SubParm4,0);
						}
					}
					
				}
				else
				{
					spawnaction(SubParm2);
				}
			}
			else
			{
				spawnaction(SubParm2);
			}
		}
//If standing against wall, and pressing move-button, make collision-check before allowing character to run
		//if(VActionList==SubParmHitWallSpreadOut||VAction==SubParmHitWallIdleFront)
		if(VActionList==SubParmHitWallSpreadOut || VAction==SubParmHitWallIdleFront || VAction==SubParmHitWallIdle)
		{
			//printlog("HITWALL:  Inside actionlist");
			if(VTrigger==_DIRMove)
			{
				vector(_vectorfromdirflags,TmpVector2)

				float(_seti,SubVar1,VColFeetSphereSize)
				float(_Mul,SubVar1,-2.1)
				vector(_setx,TmpVector3,SubVar1)		//-60 for bob
				float(_Mul,SubVar1,-1)
				vector(_setz,TmpVector3,SubVar1)		//60
				vector(_mul,TmpVector2,TmpVector3)

				float(_seti,SubVar1,VColFeetSphereBottom)
				float(_add,SubVar1,15)
				vector(_sety,TmpVector2,SubVar1);
				vector(_set,TmpVector,0,0,0)
				vector(_sety,TmpVector,SubVar1);

				collision(TmpVector,TmpVector2);
				if(vcolflag==_DIRvercol)
				{
					if(VColAngle>400||VColAngle<-400)
					{
						SpawnAction(SubParm2);
					}
					elseif(VColMaterialProperties|=_MATStairOrLedge)
					{
						if(vtrigger==_DIRforward)
						{
							SpawnAction(SubParm2);
						}
					}


				}
				else
				{
						SpawnAction(SubParm2);
				}
			}
		}
		if(SubParmForceRunFrames>0)
		{
			//printlog("HITWALL:  Inside forcerunframes");
			float(_sub,SubParmForceRunFrames,1);
			Call(ForceRunning);
		}
}



SubRoutine(Sub_BobFlapControl,float(SubParm1))
{
//SubParm1=BobFlapStrength
		if(SubParm1>=0)
		{
			if(vframe<=6)
			{
				move(0,11,0);
			}
			if(SubParm1<1)
			{
//				move(0,-5,0);
				if(vframe<3)
				{
					setframe(3);
				}
				elseif(vframe==4)
				{
					setframe(11);
				}
				if(SubParm1<0)
				{
					float(_set,SubParm1,0);
				}
			}
			elseif(SubParm1<2)
			{
//				move(0,-4,0);
				if(vframe<3)
				{
					setframe(3);
				}
				elseif(vframe==5)
				{
					setframe(10);
				}
			}
			elseif(SubParm1<3)
			{
//				move(0,-3,0);
				if(vframe<3)
				{
					setframe(3);
				}
				elseif(vframe==6)
				{
					setframe(9);
				}
			}
			elseif(SubParm1<4)
			{
//				move(0,-2,0);
				if(vframe<2)
				{
					setframe(2);
				}
				elseif(vframe==8)
				{
					setframe(11);
				}
			}
			elseif(SubParm1<5)
			{
//				move(0,-1,0);
				if(vframe<1)
				{
					setframe(1);
				}
				elseif(vframe==10)
				{
					setframe(12);
				}
			}
			else
			{
				float(_set,SubParm1,5);
			}
		}
}

SubRoutine(Sub_MoveBobInAir,float(SubParm1),float(SubParm2),float(SubParm3),float(SubParm4))
{
		if(vstate!=StateNormal)
		{
//SubParm1=AirSpeedForward
//SubParm2=AirSpeedSideways
//SubParm3=TurnSpeed
//SubParm4=ColAngleCorrectNeeded
/*			if(vaction==BobFlyBackFlip)
			{
				float(_mul,SubParm1,BobDccAirBackFlip);
				float(_mul,SubParm2,BobDccAirBackFlip);
				RotateBone(0,0,0,0);
			}
			else
			{ 
*/
				if(vtrigger==_DIRvercol)
				{
					if(ColAngleTmp<400&&ColAngleTmp>-400)	//If bouncing straight into wall, with full speed, backflip
					{
						if(vdisttoground>100)
						{
							if(SubParm1<-14.37)
							{
								//if(vaction!=BobFlyBackFlip)
								if(vaction!=BobFlySmackWall)
								{ 
//Checks if there are colis above and below character. Because it is annoying if he backflips when close to edge
									Collision(0,100,0,0,100,-50);
									if(vcolflag==_DIRvercol)
									{
										Collision(0,-100,0,0,-100,-50);
										if(vcolflag==_DIRvercol)
										{
											//spawnaction(BobFlyBackFlip);
											spawnaction(BobFlySmackWall);
											sample(SFXBobUumph,-1);
											state(_or,StateExecuteAnim);
										}
									}
								}
							}
						}
						if(vtrigger!=_DIRLeft&&vtrigger!=_DIRRight)
						{
							float(_set,SubParm4,ColAngleTmp);	//SubVar1);
						}
						float(_mul,SubParm1,0.85)
						float(_mul,SubParm2,0.85)
					}
					else
					{
						if(VColNrVerRebounds==1)
						{
							if(vtrigger!=_DIRLeft&&vtrigger!=_DIRRight)
							{
								float(_set,Var1,ColAngleTmp);
								if(Var1<0)
								{
									float(_add,Var1,1024);
								}
								else
								{
									float(_sub,Var1,1024);
								}
								float(_mul,Var1,0.1);
								turn(0,Var1,0);
							}
						}
					}
					float(_mul,SubParm1,0.80)
					float(_mul,SubParm2,0.80)
				}



				if(vtrigger==_DIRforward)
				{
					camera(flyForward_camera_distance,flyForward_camera_angle);
					Target(flyForward_camera_Tdistance,flyForward_camera_Tangle);
					if(vtrigger==_DIRwalking)
					{
						if(SubParm1<=BobMaxWalkSpeedFwdAir)
						{
							float(_set,SubParm1,BobMaxWalkSpeedFwdAir);
						}
						else
						{
							float(_sub,SubParm1,BobAccAir);
						}
					}
					else
					{
						if(SubParm1<=BobMaxRunSpeedFwdAir)
						{
							float(_set,SubParm1,BobMaxRunSpeedFwdAir);
						}
						else
						{
							float(_sub,SubParm1,BobAccAir);
						}
					}
				}
				elseif(vtrigger==_DIRbackward)
				{
					camera(flyBackward_camera_distance,flyBackward_camera_angle);
					Target(flyBackward_camera_Tdistance,flyBackward_camera_Tangle);
					if(vtrigger==_DIRbackward)
					{
						if(SubParm1>=BobMaxWalkSpeedBwdAir)
						{
							float(_set,SubParm1,BobMaxWalkSpeedBwdAir);
						}
						else
						{
							float(_add,SubParm1,BobAccAir);
						}
					}
					else
					{
						if(SubParm1>=BobMaxRunSpeedBwdAir)
						{
							float(_set,SubParm1,BobMaxRunSpeedBwdAir);
						}
						else
						{
							float(_add,SubParm1,BobAccAir);
						}
					}
				}
				else
				{
//on todo list					camera(fly_camera_distance,fly_camera_angle);
//on todo list					Target(fly_camera_Tdistance,fly_camera_Tangle);
					float(_mul,SubParm1,BobDccAir);
				}

				if(VTrigger==_DIRwalking)
				{
					if(vtrigger==_DIRSideRight)
					{
						if(SubParm2<=BobMaxWalkSpeedSideAirNeg)
						{
							float(_set,SubParm2,BobMaxWalkSpeedSideAirNeg);
						}
						else
						{
							float(_sub,SubParm2,BobAccAirSide);
						}
					}
					elseif(vtrigger==_DIRSideLeft)
					{
						if(SubParm2>=BobMaxWalkSpeedSideAir)
						{
							float(_set,SubParm2,BobMaxWalkSpeedSideAir);
						}
						else
						{
							float(_add,SubParm2,BobAccAirSide);
						}
					}
					else
					{
						float(_mul,SubParm2,BobDccAir);
					}	
				}
				else
				{
					elseif(vtrigger==_DIRSideRight)
					{
						if(SubParm2<=BobMaxRunSpeedSideAirNeg)
						{
							float(_set,SubParm2,BobMaxRunSpeedSideAirNeg);
						}
						else
						{
							float(_sub,SubParm2,BobAccAirSide);
						}
					}
					elseif(vtrigger==_DIRSideLeft)
					{
						if(SubParm2>=BobMaxRunSpeedSideAir)
						{
							float(_set,SubParm2,BobMaxRunSpeedSideAir);
						}
						else
						{
							float(_add,SubParm2,BobAccAirSide);
						}
					}
					else
					{
						float(_mul,SubParm2,BobDccAir);
					}	
				}
	
				float(_Set,TmpFloat3,SubParm3);
				if(TmpFloat3<0)
				{
					float(_mul,TmpFloat3,-0.15);		//TurnSpeed when turning left
				}
				else
				{
					float(_mul,TmpFloat3,-0.20);		//TurnSpeed when turning right
				}
				float(_add,TmpFloat3,SubParm2);

				float(_set,TmpFloat,SubParm1);
				if(TmpFloat3>0)
				{
					float(_sub,TmpFloat,TmpFloat3);
				}
				else
				{
					float(_add,TmpFloat,TmpFloat3);
				}
				float(_set,TmpFloat2,TmpFloat);	//The following lines correct for the fact that the Bob is not on straight angles.
				float(_mul,TmpFloat,-14);
				float(_mul,TmpFloat2,-5);
				float(_mul,TmpFloat3,27);
				float(_add,TmpFloat2,TmpFloat3);
				rotatebone(0,TmpFloat,0,TmpFloat2);
//			}
			move(SubParm2,0,SubParm1);
		}
}	
