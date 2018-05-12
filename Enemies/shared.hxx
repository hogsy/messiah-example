
SubRoutine(Sub_ExplodeObjectHandler)
{
	call(SetParticleSetID);
	if(VDynamicCollision|=_ExplodeGlass)
	{
		sample(SFXGlass,tmpvector);			//attached gets removed!

		if(VDynamicCollision|=_ExplodeSmall)
		{
			spawnparticle(fx_smallexplosion,-1,tmpvector,emptyvector,-1);
		}
	}
	elseif(VDynamicCollision|=_ExplodeSmall)
	{
		spawnparticle(fx_smallexplosion,-1,tmpvector,emptyvector,-1);
		sample(SFXSmallExplode,tmpvector);
	}
	elseif(VDynamicCollision|=_ExplodeBig)
	{
		vector(_copyx,TmpVector,TmpFloat2);
		vector(_copyy,TmpVector,TmpFloat3);
		vector(_copyz,TmpVector,TmpFloat4);

		if(VDynamicCollision|=_ExplodeAmmo)
		{
			spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
		}
		elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
		{
			spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
		}

		spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
		sample(SFXBazookaExplode,tmpvector);
		callsub(sub_fxexplosion);
	}
}


Subroutine(TurnToPlayer)
{
	if(VAICon!=0)
	{
		call(AIcheckforplayerone,1200);
		if(VTrigger==_DIRTempFlag)
		{
			call(AIsetlockedonactortotarget);
			callsub(Sub_AI1WayAlignToTarget);
		}
	}
}
Subroutine(HandBox,float(time),float(toggleon))
{
	call(CheckTriggerObjFlag,TmpFloat,1,_SXObjDynamicObj);
	if(TmpFloat==FALSE)
	{
		if(VTrigger==_DIREnvTrigger && toggleon==0)
		{
			if(VTrigger==_DIRaction)
			{
				call(ActivateButton,"Please Step Back",-1,FALSE);
				call(ActivateButtonSample,SFXValidFunction);
				direction(_clr,_DIRaction);
			}
		}
		if(toggleon==0)
		{
			if(VState==StateJustActivated)
			{
				call(SetTriggerObjFlag,2,_clr,_SXObjInvisible);
				sample(SFXCountDown,Gactorpos);
				sample(SFXBoxCountDown,Gactorpos);
				float(_set,toggleon,1);
			}
		}
		if(toggleon>=1)
		{
			float(_add,toggleon,1);
			if(toggleon>=time)
			{
				call(SetTriggerObjFlag,2,_or,_SXObjInvisible);
				call(ExplodeObject,TmpVector,1);
				samplestop(SFXCountDown,Gactorpos);
				callsub(Sub_ExplodeObjectHandler);
				float(_set,toggleon,0);
			}
		}
	}
	else
	{
		if(toggleon!=0)
		{
			samplestop(SFXCountDown,Gactorpos);
			float(_set,toggleon,0);
		}
	}
}

SubRoutine(Sub_BoxTrigger,float(radius),float(posx),float(posz),float(solve))
{
	vector(_settotriggerpos,TmpVector);
	vector(_settoactorpos,TmpVector2);
	vector(_sub,TmpVector,TmpVector2);
	vector(_copyx,TmpVector,posx);
	vector(_copyz,TmpVector,posz);
	float(_abs,posx);
	float(_abs,posz);
	if(posx<=radius && posz<=radius)
	{
		float(_set,solve,1);
	}
	else
	{
		float(_set,solve,0);
	}
}

SubRoutine(Sub_SpawnGrenade)
{
		if(VInventoryType==_AmmoGrenadeConcussion)
		{
			spawnactor(BulletGrenadeConcusion,0,100,-100);
		}
		elseif(VInventoryType==_AmmoGrenadeStickEm)
		{
			if(VAICon==0)
			{
				spawnactor(BulletGrenadeStickEm,0,100,-100);
			}
			else
			{
				spawnactor(BulletGrenade,0,100,-100);
			}
		}
		elseif(VInventoryType==_AmmoGrenadeBetty)
		{
			spawnactor(BulletGrenadeJumpBetty,0,100,-100);
		}
		elseif(VInventoryType==_AmmoGrenadeDistortion)
		{
			spawnactor(BulletGrenadeDistortion,0,100,-100)
		}
		elseif(VInventoryType==_AmmoGrenadeABeast)
		{
			vector(_set,gactorpos,-50,60,-180);
			spawnparticle(fx_bazookatrail,0,gactorpos,emptyvector,fx_beastfx);
			vector(_set,gactorpos,-80,100,-180);
			spawnparticle(fx_bazookatrail,0,gactorpos,emptyvector,fx_beastfx2);
			vector(_set,gactorpos,-110,60,-180);
			spawnparticle(fx_bazookatrail,0,gactorpos,emptyvector,fx_beastfx);
			sample(SFXABeastShoot,-1);
			spawnactor(BulletGrenadeNoTimer,-50,60,-200);
			spawnactor(BulletGrenadeNoTimerSecondary,-80,100,-180);
			spawnactor(BulletGrenadeNoTimerSecondary,-110,60,-180);
		}
		elseif(VInventoryType==_AmmoGrenadeSubGirl)
		{
			sample(SFXABeastShoot,-1,80);
			spawnactor(BulletGrenadeSubGirl,-10,100,0);
			spawnactor(BulletGrenadeSubGirl,40,100,0);
		}
		else	//_AmmoGrenade
		{
			spawnactor(BulletGrenade,0,100,-100);
		}

		if(VTrigger==_DIRBulletFired)
		{
			call(ChangeInventory,0,-1);
		}
}


//	TmpFloat gets the floor number, -1 if nothing should happen
//	TmpFloat1 gets the direction the floor is moving in, 0 if not moving
//
SubRoutine(LiftControl,const(CurFloor),const(NumbFloors))
{
	if(TmpFloat==-1 && VTrigger==_DIREnvTrigger)
	{
		Direction(_clr,_DIRaction);

		if(VTrigger==_DIRforward) //if CHARACTER is moving forward
		{
			float(_set,TmpFloat1,1);
			Direction(_clr,_DIRforward); // clears the move
		}
		elseif(VTrigger==_DIRbackward) // if CHARACTER is moving backward
		{
			float(_set,TmpFloat1,-1);
			Direction(_clr,_DIRbackward); // clears the move
		}
		else
		{
			float(_set,TmpFloat1,0);

		}

		if(TmpFloat1!=0)
		{
			float(_set,TmpFloat,CurFloor);
			float(_add,TmpFloat,TmpFloat1);

			if(TmpFloat<0 || TmpFloat>NumbFloors)
			{
				float(_set,TmpFloat,-1);
			}
		}
	}
}

SubRoutine(DispenserSound)
{
	if(timer2==0)
	{
		float(_set,timer2,1);
	}
	if(timer2==5)
	{
		float(_set,timer2,0);
	}
	if(VKeyObjFrame==0 && timer2==1)
	{
		sample(SFXFenetre,Gactorpos)
		float(_set,timer2,2);
	}
	if(VKeyObjFrame==4 && timer2==2)
	{
		sample(SFXPneumatik2,Gactorpos);
		float(_set,timer2,3);
	}
	if(VKeyObjFrame==8 && timer2==3)
	{
		sample(SFXClawSpin,Gactorpos);
		float(_set,timer2,4);
	}
	if(VKeyObjFrame==9 && timer2==4)
	{
		sample(SFXLockedSound,Gactorpos);
		float(_set,timer2,5);
	}
}

Subroutine(Fall2Death)
{
	if(VTrigger==_DIREnvTrigger)
	{
		if(VAICon!=0)
		{
			KillActor();
		}
		else
		{
			Camera(1000,600);
			Target(-10,10);
			call(LockCamera,1);
			Direction(_clr,_DIRalive);
			State(_or,StateDead);
			call(AIchangerank,0);		//take care of plane trigger deaths internally!
		}
	}
}

//Plays random messages in lift (see exemple in Scene2.hxx, s1r15 & s1r16)
SubRoutine(PickLiftMsg)
{
	float(_add,timer3,1)
	if(timer3>=350)
	{
		float(_rnd2,RandomMsg,6);
		if(RandomMsg<1 && LastLiftSamplePlayed!=1)
		{
			sample(SFXElevatorMsg01,Gactorpos);
			float(_set,LastLiftSamplePlayed,1);
			float(_set,Picked,1);
			float(_set,timer3,0);
		}
		elseif(RandomMsg<2 && LastLiftSamplePlayed!=2)
		{
			sample(SFXElevatorMsg02,Gactorpos);
			float(_set,LastLiftSamplePlayed,2);
			float(_set,Picked,1);
			float(_set,timer3,0);
		}
		elseif(RandomMsg<3 && LastLiftSamplePlayed!=3)
		{
			sample(SFXElevatorMsg03,Gactorpos);
			float(_set,LastLiftSamplePlayed,3);
			float(_set,Picked,1);
			float(_set,timer3,0);
		}
		elseif(RandomMsg<4 && LastLiftSamplePlayed!=4)
		{
			sample(SFXElevatorMsg04,Gactorpos);
			float(_set,LastLiftSamplePlayed,4);
			float(_set,Picked,1);
			float(_set,timer3,0);
		}
		elseif(RandomMsg<5 && LastLiftSamplePlayed!=5)
		{
			sample(SFXElevatorMsg05,Gactorpos);
			float(_set,LastLiftSamplePlayed,5);
			float(_set,Picked,1);
			float(_set,timer3,0);
		}
		elseif(RandomMsg<6 && LastLiftSamplePlayed!=6)
		{
			sample(SFXElevatorMsg06,Gactorpos);
			float(_set,LastLiftSamplePlayed,6);
			float(_set,Picked,1);
			float(_set,timer3,0);
		}
		elseif(RandomMsg<7 && LastLiftSamplePlayed!=7)
		{
			sample(SFXElevatorMsg07,Gactorpos);
			float(_set,LastLiftSamplePlayed,7);
			float(_set,Picked,1);
			float(_set,timer3,0);
		}
	}
}

SubRoutine(DoorOpen,const(OpenType),const(WaitType))
{

// OpenType : 0  >> light doors sound
//			  1	 >> medium doors sound
//			  2  >> heavy doors sound
//			  3  >> rusty door sound
//			  4	 >> curtains
// 
// WaitType : 0  >> WAIT command
//			  1  >> KFEVENT command

	if(VKeyObjTriggered==0 || ControlTimer!=0)
	{
 		call(KeyObjTrigger,255,1);
		float(_set,subvar3,0);
		float(_set,SubVar1,WaitType);
		float(_set,SubVar2,OpenType);
		if(SubVar1==1)
		{
			if(SubVar2==0)
			{
				kfsample(SFXDoOp1,SFXDoMo1,-1,SFXDoCl1);
			}
			elseif(SubVar2==1)
			{
				kfsample(SFXDoOp2,SFXDoMo2,-1,SFXDoCl2);
			}
			elseif(SubVar2==2)
			{
				kfsample(SFXVaultOpen,SFXVaultMove,-1,SFXVaultClose);
			}
			elseif(SubVar2==3)
			{
				kfsample(SFXRustDoorOpen,SFXRustDoorLoop,-1,SFXRustDoorClose);
			}
			elseif(SubVar2==4)
			{
				kfsample(SFXCurtains,-1,SFXCurtains,-1);
			}
		}
		elseif(SubVar1==0)
		{

			if(SubVar2==0)
			{
				kfsample(SFXDoOp1,SFXDoMo1,SFXDoCl1,-2);
			}
			elseif(SubVar2==1)
			{
				kfsample(SFXDoOp2,SFXDoMo2,SFXDoCl2,-2);
			}
			elseif(SubVar2==2)
			{
				kfsample(SFXVaultOpen,SFXVaultMove,SFXVaultClose,-2);
			}
			elseif(SubVar2==3)
			{
				kfsample(SFXRustDoorOpen,SFXRustDoorLoop,SFXRustDoorClose,-2);
			}
			elseif(SubVar2==4)
			{
				kfsample(SFXCurtains,-1,SFXCurtains,-1);
			}
		}

		if(VClass==_ClassCop && VTrigger==_DIRhavegun && VTrigger==_DIRcombatmode)
		{
			if(VAIClass&==_AIclassCop|_AIclassMale)
			{
				SpawnAction(CopOpenDoorCombat);
			}
		}
		direction(_clr,_DIRaction);
	}
}

//subroutine root
SubRoutine(Replay)
{
	if(VKeyObjTriggered==0 && VKeyObjFrame!=0)
	{
		call(KeyObjTrigger,255,1);
	}
}

// Non RadWorker will lose their health, feel dizzy and...eventually die.
SubRoutine(RadiationArea)
{
	if(VAIClass==_AIClassScientist&&VRank==_RankScum) // If NOT radiation worker
	{
		vector(_set,gactorpos,0,0,0);
	}
	else
	{
		call(SubtractHealth,0,10);
		if(VAIClass!=_AIClassAngel&&VActorFlag!=_AFLAGconfused) // Bob must not be dizzy !
		{
			ActorFlag(_or,_AFLAGconfused);
		}
		
		if(VActorFlag==_AFLAGconfused && Vaction!=CopDizzy)
		{
			if(VState!=StateCrawling && VState!=StateHarpooned && VState!=StateOnFire && VState!=StateSteamed)
			{
				spawnaction(CopDizzy);
			}
		}
		if(VAICon!=0)
		{
			ActorFlag(_or,_AFLAGnoai);
			//prevent breaking of this action
			direction(_clr,_DIRleft|_DIRright|_DIRforward|_DIRbackward|_DIRsideleft|_DIRsideright|_DIRjump|_DIRshoot|_DIRgrenade|_DIRaction|_DIRdepossesion|_DIRMove|_DIRcrouch);
		}
		elseif(VAIClass!=_AIClassAngel)
		{
			//prevent breaking of this action
			direction(_clr,_DIRleft|_DIRright|_DIRforward|_DIRbackward|_DIRsideleft|_DIRsideright|_DIRjump|_DIRshoot|_DIRgrenade|_DIRaction|_DIRdepossesion|_DIRMove|_DIRcrouch);
		}
	}
}

SubRoutine(RadiationAreaNormal)
{
	if(VAIClass!=_AIClassAngel && VAIState==_AIstateConfused) // Bob must not be dizzy !
	{
		if(VAICon!=0 && VActorFlag==_AFLAGnoai)
		{
			ActorFlag(_clr,_AFLAGnoai);
			ActorFlag(_clr,_AFLAGconfused);
		}

//		spawnaction(GenIdle);
	}
}





SubRoutine(Sub_SetCameraNormal)
{
		if(VAICon==0)
		{
			cameragroundclearance(100)
			if(VAIClass==_AICLASSangel)
			{
				Camera(BobRun_camera_distance,BobRun_camera_angle);
				Target(BobRun_camera_Tdistance,BobRun_camera_Tangle);
			}
			elseif(VAIClass==_AIClassCop)
			{
				Camera(CopRun_camera_distance,CopRun_camera_angle);
				Target(CopRun_camera_Tdistance,CopRun_camera_Tangle);
			}
			elseif(VAIClass==_AIClassBeast)
			{
				Camera(beast_camera_distance,beast_camera_angle);
				Target(beast_camera_tdistance,beast_camera_tangle);
			}
			elseif(VAIClass==_AIClassABeast)
			{
				if(VTrigger!=_DIRShoot)
				{
					Camera(550,350);
					Target(-250,100);
				}
				else
				{
					Camera(20,300);
					Target(-250,100);
				}
			}
			else
			{
				Camera(CopRun_camera_distance,CopRun_camera_angle);
				Target(CopRun_camera_Tdistance,CopRun_camera_Tangle);
//				Camera(Run_camera_distance,Run_camera_angle);
//				Target(Run_camera_Tdistance,Run_camera_Tangle);
			}
		}
}


SubRoutine(Sub_BatteryHandler)
{
		if(VState!=StateCrawling && VTrigger==_DIRcombatmode && VTrigger==_DIRhavegun && VWeaponAmmoType==_AmmoBattery)
		{
			if(VWeaponAmmoLeft==0)
			{
				//	Check for battery pickup
				//
				//if(batterydelay==0)
				//{
					call(CheckForPickup,12,_ClassPickup|_ClassBullet);
				//}
				//else
				//{
					//float(_sub,batterydelay,1);
				//}
			}
			/*
			elseif(VTrigger==_DIRaction)
			{
				//	battery drop
				//
				call(CheckAttached,_CADropBattery);
				//direction(_clr,_DIRshoot);
				//direction(_clr,_DIRcombatmode);
				//float(_set,batterydelay,30);
			}
			*/
		}
}



SubRoutine(Sub_CombatKeyHandler,float(CombatState),const(CombatFireDelay))
{
	//Print("CombatState: ",CombatState);
	if(VTrigger!=_DIRcombatmode)
	{
		//if(VTrigger==_DIRshoot && VTrigger!=_DIRmove)
		if(VTrigger==_DIRshoot)
		{
			Direction(_or,_DIRcombatmode);
			Direction(_clr,_DIRshoot);
			float(_set,CombatState,1);

			if(VAICon==0 && VTrigger==_DIRhavegun)
			{
				if(VWeaponAmmoType==_AmmoUnLimited)
				{
					sample(SFXreloadTorch,-1);
				}
				else
				{
					sample(SFXWeaponIntoCombat,-1);
				}
			}
		}

		if(CombatState!=0 && VTrigger==_DIRaction)
		{
			Direction(_clr,_DIRaction);
		}
		if(DirClr&=_DIRaction)
		{
			float(_set,CombatState,0);
		}
	}
	else
	{
		if(VTrigger==_DIRaction)
		{
			Direction(_clr,_DIRcombatmode);
			Direction(_clr,_DIRaction);
			float(_set,CombatState,1);

			if(VAICon==0 && VTrigger==_DIRhavegun)
			{
				if(VWeaponAmmoType==_AmmoUnLimited)
				{
					sample(SFXreloadTorch,-1);
				}
				else
				{
					sample(SFXWeaponPickUp,-1);
				}
			}
		}

		if(CombatState!=0 && VTrigger==_DIRshoot)
		{
			Direction(_clr,_DIRshoot);
			float(_add,CombatState,1);
		}
		if(DirClr&=_DIRshoot || CombatState>=CombatFireDelay)
		{
			float(_set,CombatState,0);
		}
	}
}


SubRoutine(Sub_ActionKeyHandler,float(ActionOK))
{
	if(vtrigger==_DIRaction)
	{
		if(ActionOK==1)
		{
			float(_set,ActionOK,0);
		}
		else
		{
			direction(_clr,_DIRaction);
		}
		direction(_or,_DIRactionhold);
	}
	else
	{
		float(_set,ActionOK,1);
		direction(_clr,_DIRactionhold);
	}
}

SubRoutine(Sub_CheckActionPickup,const(Pickup),const(PickupFrame),const(PickupChest),const(PickupChestFrame))
{
	if(vtrigger==_DIRaction && Pickup!=0 && DisablePickUp==0)
	{
		call(IsPickupClose,_ClassWeapon,115,TmpFloat,TmpVector);
		if(VTrigger==_DIRTempFlag && TmpFloat!=0)
		{
			//CallSub(Sub_ChangeStateToNormal);
			state(_or,StateExecuteAnim);
			direction(_clr,_DIRaction);
			if(TmpFloat==1)
			{
				spawnaction(Pickup);
			}
			else
			{
				spawnaction(PickupChest);
			}
		}
	}
/*
	PrintI("VFrame: ",VFrame);
	Print("PickupFrame: ",PickupFrame);
	PrintI("VAction: ",VAction);
	Print("Pickup: ",Pickup);
*/	
	if(vaction==Pickup&&VFrame==PickupFrame)
	{
		call(CheckForPickup,12,_ClassWeapon);	//Weapons only
	}
	elseif(vaction==PickupChest&&VFrame==PickupChestFrame)
	{
		call(CheckForPickup,12,_ClassWeapon);	//Weapons only
	}
}

SubRoutine(Sub_CheckActionPickupCrouch,const(Pickup),const(PickupFrame),const(PickupChest),const(PickupChestFrame))
{
	if(vtrigger==_DIRaction && Pickup!=0 && DisablePickUp==0)
	{
		call(IsPickupClose,_ClassWeapon,115,TmpFloat,TmpVector);
		if(VTrigger==_DIRTempFlag && TmpFloat!=0)
		{
			state(_or,StateExecuteAnim);
			direction(_clr,_DIRaction);
			spawnaction(Pickup);
		}
	}
	if(vaction==Pickup&&VFrame==PickupFrame)
	{
		call(CheckForPickup,12,_ClassWeapon);	//Weapons only
	}
}

SubRoutine(Sub_CheckActionDrop,const(DropAction),const(DropActionFrame),const(DropChest),const(DropChestFrame),float(DropDelay),float(checkability))
{
	if(checkability&=_AIAPickUpWeapon)
	{
		if(vtrigger==_DIRaction)
		{
			float(_set,DropDelay,0);
		}

		if(VTrigger==_DIRcombatmode)
		{
			float(_set,DropDelay,100);
		}

		if(vtrigger==_DIRactionhold)
		{
			float(_add,DropDelay,1);
			if(DropAction!=0 && DropDelay==10)
			{
				call(IsPickupClose,_ClassWeapon,115,TmpFloat,TmpVector);
				if(vtrigger==_DIRTempFlag && TmpFloat!=0)
				{
					if(TmpFloat==1)
					{
						state(_or,StateExecuteAnim);
						spawnaction(DropAction);			//we're swapping with wep on ground or picking up weapon
					}
					else
					{
						//if(DropDelay==10)
						//{
							state(_or,StateExecuteAnim);
							spawnaction(DropChest);				//we're swapping with wep in front
						//}
					}
				}
				else
				{
					//if(DropDelay==10)
					//{
						state(_or,StateExecuteAnim);
						spawnaction(DropAction);				//we're dropping our wep
					//}
				}
			}
		}
		else
		{
			float(_set,DropDelay,100);
		}

		Direction(_clr,_DIRTempFlag);
		if(vaction==DropAction && VFrame==DropActionFrame)
		{
			Direction(_or,_DIRTempFlag);
		}
		elseif(vaction==DropChest && VFrame==DropChestFrame)
		{
			Direction(_or,_DIRTempFlag);
		}

		if(VTrigger==_DIRTempFlag)
		{
			sample(SFXWeaponDrop1,-1);

			call(IsPickupClose,_ClassWeapon,115,TmpFloat,TmpVector);

			if(vtrigger==_DIRTempFlag && TmpFloat!=0)
			{
				if(checkability&=_AIAPickUpWeapon)
				{
					call(CheckAttached,_CASwapWeapon);
				}
				Direction(_clr,_DIRTempFlag);
			}
			else
			{
				if(VActorFlag==_AFLAGweaponinvisible)
				{
					ActorFlag(_clr,_AFLAGweaponinvisible);
					Direction(_set,_DIRhavegun);
				}
				if(checkability&=_AIAPickUpWeapon)
				{
					call(CheckAttached,_CADropWeapon);
				}
			}
		}
	}
}

SubRoutine(Sub_CheckActionDropCrouch,const(DropAction),const(DropActionFrame),const(DropChest),const(DropChestFrame),float(DropDelay),float(checkability1))
{
	if(checkability1&=_AIAPickUpWeapon)
	{
		if(vtrigger==_DIRaction)
		{
			float(_set,DropDelay,0);
		}

		if(VTrigger==_DIRcombatmode)
		{
			float(_set,DropDelay,100);
		}

		if(vtrigger==_DIRactionhold)
		{
			float(_add,DropDelay,1);
			if(DropAction!=0 && DropDelay==10)
			{
				state(_or,StateExecuteAnim);
				spawnaction(DropAction); //we're swapping with wep on ground or picking up weapon
			}
		}
		else
		{
			float(_set,DropDelay,100);
		}

		Direction(_clr,_DIRTempFlag);
		if(vaction==DropAction && VFrame==DropActionFrame)
		{
			Direction(_or,_DIRTempFlag);
		}
		elseif(vaction==DropChest && VFrame==DropChestFrame)
		{
			Direction(_or,_DIRTempFlag);
		}

		if(VTrigger==_DIRTempFlag)
		{
			sample(SFXWeaponDrop1,-1);

			call(IsPickupClose,_ClassWeapon,115,TmpFloat,TmpVector);

			if(vtrigger==_DIRTempFlag && TmpFloat!=0)
			{
				if(checkability1&=_AIAPickUpWeapon)
				{
					call(CheckAttached,_CASwapWeapon);
				}
				Direction(_clr,_DIRTempFlag);
			}
			else
			{
				if(checkability1&=_AIAPickUpWeapon)
				{
					call(CheckAttached,_CADropWeapon);
				}
			}
		}
	}
}

SubRoutine(Sub_CheckRemainingActions,const(Action),const(ActionFrame))
{
	state(_clr,StateJustActivated);

	if(VActorFlag==_AFLAGactivatebutton && Action!=0)
	{
		state(_or,StateExecuteAnim)
		spawnaction(Action)
	}

	if(vaction==Action && VFrame==ActionFrame)
	{
		call(ExecuteActivateCode);		//only action in here so far
		state(_or,StateJustActivated);
	}
}
		

SubRoutine(Sub_CheckForIdleLongTime,float(SubParmIdle),float(SubParmIdleLongTime))
{
//Switch to idle long time if inactive for a long time
		if(VAICon==0)
		{
			if(VAction!=SubParmIdle&&VAction!=SubParmIdleLongTime)
			{
				ClrStateCounter();	//To Random
			}
			elseif(VEndOfAnim!=0)
			{
//				if(VAction==SubParmIdleLongTime)
//				{
//				}
				if(VInStateCounter>=450)
				{
					Direction(_set,_DIRNotEndOfAnim);
					spawnaction(SubParmIdleLongTime);
					ClrStateCounter();
				}
			}
		}
}

SubRoutine(Sub_InAirCheckGround,const(SubParm1))	//Check if landing on ground
{
//SubParm1: Action When Landing
		if(Vtrigger==_DIRhorcol && VActorFlag!=_AFLAGcolfromabove)
		{
			CallSub(Sub_ChangeStateToNormal);
			spawnaction(SubParm1);
		}
}







SubRoutine(Sub_InitPossesion,const(PossesedAction),const(PossesedCrouchAction),const(PossesedCrawlAction))	//Called when possion starts
{
		if(vstate==StateNormal && vstate!=StateDead && vstate!=StateBlind && vstate!=StateSteamed && vstate!=StateOnFire && vstate!=StateHarpooned)
		{
			state(_or,StateExecuteAnim);
			if(vstate==StateCrawling)
			{
				spawnaction(PossesedCrawlAction);
			}
			elseif(VState==StateCrouching)
			{
				spawnaction(PossesedCrouchAction);
			}
			else
			{
				spawnaction(PossesedAction);
			}

			//TmpPossessFX
			vector(_set,TmpVector,0,0,0);
			//spawnparticle(spikeballfx,0,EmptyVector,TmpVector);

			callsub(Sub_SetCameraNormal);
			Direction(_clr,_DIRpossesion);
//			call(CameraFollow,TRUE);
//			call(AICon,FALSE);
		}

		spawnparticle(fx_possessflare,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_possessflare,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_possessflare,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_possessflare,0,emptyvector,emptyvector,-1);

		vector(_set,tmpvector,64,56,64);
		SpawnLight(PossessLight,0,emptyvector,tmpvector,EmptyVector,800);

		sample(SFXRadiationReact,-1);

		sample(SFXPossess,-1);
		sample(SFXPossessHit,-1);

		if(VAICon==0)
		{
			call(AIchangemetoenemy);		//to make sure players notice the change
		}
}










Subroutine(Sub_InitDepossesion,const(SubParm1),const(SubParm2),const(SubParm3))
{
	if(StickEmState==StickEmReady&&VAICon==0)
	{
		//we got here , which means we have thrown a StickEm grenade, and now we are going to explode it!
		float(_set,StickEmState,StickEmExploding);
	}

//SubParm1: Depossession action when statenormal
	float(_seti,SubVar1,VColSphereSize);

	if(SubVar1<BobSphereSize || VSniperMode>0 || VFirstPerson!=0)
	{
//MISSING: send collisionrays out around bob to see if there is room. If not, set SubVar1==0
//Perhaps this check should always be made.
		float(_set,SubVar1,0);	//Do this if there is not room for Bob (Narrow passages etc.)
	}

//	if(SubVar1!=0)
//	{

		if(vstate!=StateDead && vstate!=StateBlind && vstate!=StateSteamed && vstate!=StateOnFire && vstate!=StateHarpooned)
		{
			if(vstate==StateNormal)
			{
				state(_or,StateExecuteAnim);
				if(vstate==StateCrawling)
				{
					spawnaction(SubParm3);
				}
				elseif(vstate==StateCrouching)
				{
					spawnaction(SubParm2);
				}
				else
				{
					spawnaction(SubParm1);
				}
			}
			elseif(VState==StateFalling)
			{
				State(_or,StateDazed);			//tell actor to do the depossessanim when landing
			}
		}
		//float(_sub,SubVar1,BobSphereSize);	//Trigger bob at top of enemys sphere
		if(SubVar1!=0)
		{
			if(VAIcon==0)
			{
				SpawnActor(Bob1,0,0,0,TRUE);
			}
			else
			{
				SpawnActor(EvilBob,0,0,0,TRUE);
			}
		}
		else
		{
			vector(_settoactorpos,TmpVector);
			vector(_copyx,TmpVector,TmpFloat);
			vector(_copyy,TmpVector,TmpFloat2);
			vector(_copyz,TmpVector,TmpFloat3);
			if(VAIcon==0)
			{
				SpawnActor(Bob1,TmpFloat,TmpFloat2,TmpFloat3,0,true);
			}
			else
			{
				SpawnActor(EvilBob,TmpFloat,TmpFloat2,TmpFloat3,0,true);
			}
		}

/*		if(VAIcon==0)
		{
			SpawnActor(Bob1,0,0,0,TRUE);
		}
		else
		{
			SpawnActor(EvilBob,0,0,0,TRUE);
		}
*/
		resetbone(PlayerHeadBone);
		resetbone(2);
		call(CameraFollow,FALSE);
		call(AICon,TRUE);

		call(CheckAttached,_CANormal);
		Direction(_clr,_DIRAIRemoveFlags);
		sample(SFXDePossess,-1);

		sample(SFXJustDeposessed,-1);

		call(ChangeSniperMode,-2,0);		//-2 special case from depossession

//	}
}



SubRoutine(Sub_Headtrack)		//Track head to objects
{

//No parameters
		if(VState==StateHeadTrack)
		{
//			printi("P1 PathDestDist:     ",VPathDestDistance);
//			printi("P1 PathDestAngle:    ",VPathDestAngle);
//			printi("P1 PickDestAngle:    ",VPickDestAngle);
//			printi("P1 TargetDistance:   ",vtargetdistance);
//			printi("P1 TargetAngle:      ",vtargetangle);
			call(CheckForVisual,_CLASSmodel|_CLASSpickup|_CLASSweapon,10000);		//classmask,viewdistance
			if(VAICon==0 || VAItargetfound==2)
			{
				if(VLockedOnAngle!=0 && VLockedOnAngle<750 && VLockedOnAngle>-750)
				{
					vector(_copy,TmpVector,EmptyVector);
					float(_seti,TmpFloat,VLockedOnAngle);
					vector(_sety,TmpVector,TmpFloat);
					call(BonePointTrack,PlayerHeadBone,TmpVector,_SXBoneAttRelative,0.95);		//bonenr,point
				}
				else
				{
					centerbone(PlayerHeadBone,0.95);
				}

				if(VTrigger==_DIRcombatmode && VActorFlag==_AFLAGlogon)
				{
					vector(_copy,TmpVector,EmptyVector);
					float(_seti,TmpFloat,VTargetAngleY);
					if(VTargetAngleY<-750)
					{
						float(_set,TmpFloat,-750);
					}
					elseif(VTargetAngleY>750)
					{
						float(_set,TmpFloat,750);
					}
					float(_mul,TmpFloat,-1);
					vector(_setx,TmpVector,TmpFloat);
					call(BonePointTrack,2,TmpVector,_SXBoneAttAbsolute,0.80);					//bonenr,point
				}
				else
				{
					centerbone(2,0.95);
				}
			}
			else
			{
				centerbone(PlayerHeadBone,0.95);
				centerbone(2,0.95);
			}
		}
}

subroutine(Sub_ChangeStateToNormal)	//Switch from flying, falling etc. to normal
{
		state(_clr,StateCrouching);
		state(_clr,StateFlying);
		state(_clr,StateFalling);
		state(_clr,StateJump);
		state(_clr,StateGliding);
		state(_clr,StateThrown);		//ttt
		state(_or,StateNormal);
		if(VAICon==0)
		{
			CallSub(Sub_SetCameraNormal);
		}
		state(_or,StateHeadTrack);
}


SubRoutine(Sub_CheckExecuteAnimEnd)	//Called if in StateExecuteAnim
{
//No parameters
	if(vendofanim!=0 && VOAction!=VAction)
	{
		state(_clr,StateExecuteAnim);
	}
}
SubRoutine(Sub_TurnCharacter,float(SubParm1),const(SubParm2),const(SubParm3))
{
//SubParm1: CurrentTurnSpeed
//SubParm2: MaxTurnSpeed
//SubParm3: TurnSpeedAcc
		if(VAICon==0)
		{
			if(VTrigger&=_DIRright|_DIRleft)
			{
				float(_seti,TmpFloat,VAnalog1);
			}
			else
			{
				float(_set,TmpFloat,0);
				float(_set,SubParm1,0);
			}
			float(_mul,TmpFloat,SubParm2);
			if(VTrigger==_DIRwalking)
			{
				float(_mul,TmpFloat,0.1)
				float(_mul,SubParm1,0.9)		//60% from current speed, 40% from new speed
			}
			else
			{
				float(_mul,TmpFloat,0.4)
				float(_mul,SubParm1,0.6)		//60% from current speed, 40% from new speed
			}
			float(_add,SubParm1,TmpFloat);
		}
		else
		{
			if(Vtrigger==_DIRleft)
			{
				if(SubParm1>0)
				{
					float(_set,SubParm1,0);
				}
				float(_sub,SubParm1,SubParm3);

				float(_set,TmpFloat,0);
				float(_sub,TmpFloat,SubParm2);
				if(SubParm1<Tmpfloat)
				{
					float(_set,SubParm1,TmpFloat);
				}												   
			}
			elseif(Vtrigger==_DIRright)
			{
				if(SubParm1<0)
				{
					float(_set,SubParm1,0);
				}
				float(_add,SubParm1,SubParm3);
				if(SubParm1>SubParm2)
				{
					float(_set,SubParm1,SubParm2);
				}
			}
			else
			{
				float(_mul,SubParm1,0.2);
			}
			//float(_mul,SubParm1,0.8);
		}
		Turn(0,SubParm1,0);
}




SubRoutine(FireWeaponsAndCheckAttached,float(ShootDelayCounter),const(NumbFrames),const(ReloadStanding),const(ReloadCrouch),const(HeavyRecoil),const(LightRecoil),const(CrouchHeavyRecoil),const(CrouchLightRecoil),float(checkability2))
{
		if(vaction==ReloadCrouch || vaction==ReloadStanding)
		{
			if(VFrame==24)
			{
				if(VWeaponAmmoType==_AmmoUnLimited)
				{
					sample(SFXreloadTorch,-1);
				}
				else
				{
					sample(SFXreload1,-1);
				}
			}
			if(VFrame==42)
			{
				if(VWeaponAmmoType==_AmmoUnLimited)
				{
					sample(SFXreloadTorch,-1);
				}
				else
				{
					sample(SFXreload,-1);
				}
			}
			Direction(_clr,_DIRshoot);
		}


		if(vstate!=StateExecuteAnim && vtrigger==_DIRshoot && vtrigger==_DIRHaveGun && VTrigger==_DIRcombatmode)
		{
			float(_sub,ShootDelayCounter,1);
		}
		else
		{
			float(_set,ShootDelayCounter,NumbFrames);
		}

		if(VActorFlag==_AFlagAttached)
		{
			Direction(_clr,_DIRshoot);
		}

		//special hack for prost to drop weapon on heavy recoil
/*		if(VAIClass==_AIclassprost && VAction==GENHeavyRecoil && VFrame==1)
		{
			if(checkability2&=_AIAPickUpWeapon)
			{
				call(CheckAttached,_CADropWeapon);
			}
			Direction(_clr,_DIRhavegun);
		}
*/
		SpecialFlag(_clr,_sFLAGCloseToWall);

		if(VTrigger==_DIRshoot)
		{
			//we no longer have a need for this delay , because the animation takes care of it!
			//and it also breaks previous direction(_set) states !!!  TONY!!!
			if(ShootDelayCounter<0)
			{
				call(CheckAttached,_CANormal);
				if(VTrigger!=_DIRshoot)
				{
/*					if(VTrigger==_DIRTempFlag && VAICon!=0)
					{
						if(vstate==StateCrouching)
						{
							spawnaction(ReloadCrouch);
						}
						else
						{
							spawnaction(ReloadStanding);
						}
					}
					elseif(VTrigger!=_DIRMove)
*/
					if(VTrigger!=_DIRMove)
					{
						if(VTrigger==_DIRHeavyRecoil)
						{
							if(vstate==StateCrouching)
							{
								spawnaction(CrouchHeavyRecoil);
							}
							else
							{
								spawnaction(HeavyRecoil);
							}
						}
						else
						{
							if(VAIClass==_AIclasssubgirl)
							{
								if(VWeaponAmmoType==_AmmoMachineGun && VWeaponAmmoLeft>0)
								{
									if(vstate!=StateCrouching && VAction!=SubGirlMachineFireLeft && VAction!=SubGirlMachineFireRight)
									{
										if(VAction==SubGirlMachineFireRight)
										{
											spawnaction(SubGirlMachineFireLeft);		//subgirl left hand
										}
										else
										{
											spawnaction(SubGirlMachineFireRight);		//subgirl right hand
										}
									}
								}
							}
							elseif(VAIClass!=_AIclassabeast)
							{
								if(vstate==StateCrouching)
								{
									spawnaction(CrouchLightRecoil);
								}
								else
								{
									spawnaction(LightRecoil);
								}
							}
						}
					}
				}
			
			}
			else
			{
			//	Direction(_clr,_DIRShoot);			//clear so we do the recoil animation
			//	call(CheckAttached,_CANormal);
			}
		}
		else
		{
			call(CheckAttached,_CANormal);
		}
//		callsub(Sub_CheckForPickups);

		if(VSpecialFlag==_sFLAGCloseToWall && VTrigger==_DIRhavegun)
		{
			if(VAction!=GENThrowGrenade)
			{
/* Avoid certain death
				if(vstate==StateCrouching)
				{
					spawnaction(ReloadCrouch);
				}
				else
				{
					spawnaction(ReloadStanding);
				}
*/

				if(VAICon==0)
				{
					SamplePlaying(SFXInvalidFunction,-1);
					if(VTrigger!=_DIRTempFlag)
					{
						Sample(SFXInvalidFunction,-1);
					}
				}
			}
		}
}

//Check for start/end crouching
SubRoutine(Sub_CheckCrouching,const(CrouchDown),const(CrouchUp))
{
		if(VState!=StateDead)
		{
			if(vtrigger==_DIRcrouch)
			{
				direction(_clr,_DIRcrouch);
				if(vstate==StateCrouching)
				{
					spawnaction(CrouchUp);
					callsub(sub_ChangeStateToNormal)
					state(_or,StateExecuteAnim);
				}
				elseif(vstate==StateNormal)
				{
					spawnaction(CrouchDown);
					callsub(sub_ChangeStateToNormal)
					state(_or,StateExecuteAnim|StateCrouching);
				}
			}
		}
}

SubRoutine(Sub_PrintStates)
{
		Print("---------------STATE ",0);
		if(VState==StateNormal)
		{
			Print("Normal ",0);
		}
		if(VState==StateFalling)
		{
			Print("Falling ",0);
		}
		if(VState==StateFlying)
		{
			Print("Flying ",0);
		}
		if(VState==StateGliding)
		{
			Print("Gliding ",0);
		}
		if(VState==StateHeadTrack)
		{
			Print("HeadTrack ",0);
		}
		if(VState==StateJump)
		{
			Print("Jump ",0);
		}
		if(VState==StateExecuteAnim)
		{
			Print("ExecuteAnim ",0);
		}
		if(VState==StateUnused)
		{
			Print("Unused ",0);
		}
		if(VState==StateDead)
		{
			Print("Dead ",0);
		}
		if(VState==StateCrawling)
		{
			Print("Crawling ",0);
		}
		if(VState==StateBangedHead)
		{
			Print("BangedHead ",0);
		}
		if(VState==StateOnFire)
		{
			Print("OnFire ",0);
		}
		if(VState==StateSteamed)
		{
			Print("Steamed ",0);
		}
		if(VState==StateBlind)
		{
			Print("Blind ",0);
		}
		if(VState==StatePatrol)
		{
			Print("Patrol ",0);
		}
		if(VState==StateAttack)
		{
			Print("Attack ",0);
		}
		if(VState==StateAttached)
		{
			Print("Attached ",0);
		}
		if(VState==StateHarpooned)
		{
			Print("Harpooned ",0);
		}
		if(VState==StateElectricShock)
		{
			Print("ElectricShock ",0);
		}
		if(VState==StateFollowPath)
		{
			Print("FollowPath ",0);
		}
		if(VState==StateExecutePathSequence)
		{
			Print("ExecutePathSequence ",0);
		}
		if(VState==StateCrouching)
		{
			Print("Crouching ",0);
		}
		if(VState==StateThrown)
		{
			Print("Thrown ",0);
		}
		if(VState==StateForceField)
		{
			Print("ForceField ",0);
		}
}


SubRoutine(Sub_CheckHanging,float(Hanging),const(ClimbUp),const(DropDown),const(ColOffset))
{
		if(VTrigger==_DIRhorcol)
		{
			//something claims to have touched him from below, verify
			vector(_set,TmpVector,0,0,0);
			float(_seti,TmpFloat,VColFeetSphereBottom);
			float(_sub,TmpFloat,5);
			vector(_sety,TmpVector,TmpFloat);

			vector(_copy,TmpVector2,TmpVector);
			vector(_suby,TmpVector2,175);

			Collision(TmpVector,TmpVector2);
			if(vcolflag==_DIRhorcol)
			{
				//yup, something hit bob, so aforce him to climb up...
				sample(SFXBobClimb,-1);
				spawnaction(ClimbUp);
				callsub(sub_ChangeStateToNormal);
				state(_or,StateExecuteAnim);
				float(_set,Hanging,0);
			}
		}
		elseif(VDirectionHold==_DIRforward)
		{
			if(Hanging==1)
			{
				float(_set,Hanging,2);
			}
		}
		else
		{
			float(_set,Hanging,1);
		}

		if(VTrigger==_DIRforward && Hanging==2)
		{
			sample(SFXBobClimb,-1);
			spawnaction(ClimbUp);
			callsub(sub_ChangeStateToNormal);
			state(_or,StateExecuteAnim);
			float(_set,Hanging,0);
		}
		elseif(VTrigger==_DIRbackward)
		{
			direction(_clr,_DIRbackward);
			state(_clr,StateExecuteAnim);
			state(_clr,StateNormal);
			SpawnAction(DropDown);
			state(_or,StateFalling);
			float(_set,Hanging,0);
			MoveFeetColOffset(0,0,ColOffset);
			float(_set,TmpFloat,ColOffset);
			float(_inv,TmpFloat);
			move(0,0,TmpFloat);
		}
}

SubRoutine(TurnToFaceSound)//TH, when Bob running behind Cop, Cop turns to face sound
{
		call(ClrPath);
		state(_clr,StateExecutePathSequence);
		state(_clr,StateFollowPath);
		call(AIPickdest,10);
		call(AIupdatetargetpos);
		VAItargetfound=0;
		call(ClrAnalogValues); //for sub_turncharacter
//		float(_clr,TmpFloat);
//		float(_sub,TmpFloat,vtargetangle);
printi("vtargetangle:   ",vtargetangle);
		if(vtargetangle>0)
		{
			spawnaction(CopTurnRight);
			turn(0,45,0);
//			turn(0,TmpFloat,0);
//			Direction(_set,_DIRright);
		}
		else
		{
			spawnaction(CopTurnLeft);
			turn(0,-45,0);
//			turn(0,TmpFloat,0);
//			Direction(_set,_DIRleft);
		}
}

SubRoutine(TurnToFaceSoundSlow)//TH
{
		VAItargetfound=0;
		call(ClrAnalogValues);
		call(AIPickdest,10);
		call(AIupdatetargetpos);
printi("vtargetangle:   ",vtargetangle);
		if(vtargetangle>0)
		{
		//	spawnaction(CopTurnRight);
			turn(0,45,0);
		//	Direction(_set,_DIRright);
		}
		else
		{
		//	spawnaction(CopTurnLeft);
			turn(0,-45,0);
		//	Direction(_set,_DIRleft);
		}
}

SubRoutine(Sub_DirectionColCheck)
{
		vector(_set,TmpVector2,0,0,0);

		vector(_vectorfromdirflags,TmpVector3);
		float(_seti,SubVar1,VColFeetSphereSize);
		float(_add,SubVar1,2);
		vector(_scale,TmpVector3,SubVar1);

		//	need to invert x, because, because (you dig?)
		//
		vector(_copyx,TmpVector3,SubVar1);
		float(_inv,SubVar1);
		vector(_setx,TmpVector3,SubVar1);


		Collision(TmpVector2,TmpVector3);
}

SubRoutine(StartDoorDelay,const(TimerValue))
{
	float(_set,TmpFloat,0);
	if(ControlTimer==0 && VKeyObjTriggered==0 && VTrigger==_DIRaction && VTrigger==_DIREnvTrigger)
	{
		float(_set,ControlTimer,TimerValue);
		call(KeyObjTrigger,255,1);
		Direction(_clr,_DIRaction);
		Sample(SFXLatch1,-1);		//leave this here	SFXWeaponDrop1
		float(_set,TmpFloat,1);
	}
}
