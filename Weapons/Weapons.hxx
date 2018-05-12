

//reload delayer for AI, ie: how many shots they fire before reloading!
#define	PUMPGUN_RELOADDELAY		5
#define	HARPOON_RELOADDELAY		3
#define	BAZOOKA_RELOADDELAY		5
#define	MAIMER_RELOADDELAY		20
#define	MACHGUN_RELOADDELAY		35
#define	PAK_RELOADDELAY			15
#define	MASER_RELOADDELAY		1


SubRoutine(Sub_AllowedToShoot)
{
		float(_seti,TmpFloat2,VState);
		State(_set,0);
		State(_copyparent);
		float(_set,TmpFloat,0);

		if(VState==StateThrown || VState==StateCrawling || VState==StateDead)
		{
			float(_set,TmpFloat,1);
		}
		elseif(VState==StateFalling && VAICon!=0)
		{
			float(_set,TmpFloat,1);
		}
		elseif(VActor==WeaponPAK && VState==StateFalling)
		{
			float(_set,TmpFloat,1);
		}
		elseif(VAIState==_AIstateRadioactive)
		{
			float(_set,TmpFloat,1);
		}
		elseif(VActorFlag==_AFLAGattached)
		{
			float(_set,TmpFloat,1);
		}

		State(_set,TmpFloat2);
}

//make sure WeaponPos is set before calling this!!
SubRoutine(Sub_WeaponTarget)
{
		call(wCheckWeaponTarget,EmptyVector,32767,WeaponPos);
}



SubRoutine(Sub_WeaponHandler,float(weaponcollision))
{
		if(vstate!=StateAttached)
		{
			//if(VActor!=WeaponBuzzSaw&&VActor!=WeaponPAK)		//are different models and don't like their ambient messed with	(detail)
			//{
				call(ModelAmbient,WeaponFaderCol,WeaponFaderCol,WeaponFaderCol);
			//}

			if(vactivetime==0)
			//if(VActorFlag==_AFLAGinitialize)
			{
				turn(1024,0,0);
			}
			if(vactivetime==1)
			{
				collision(0,-70,0,0,70,0);
				if(VColFlag==_DIRvercol)
				{
					turn(0,0,1024);
				}
				else
				{
					collision(0,70,0,0,-70,0);
					if(VColFlag==_DIRvercol)
					{
						turn(0,0,1024);
					}
				}
			}

			if(VState!=StateDead)				//cheatflag, "dead" weapons don't rotate
			{
				/*
				collision(0,-70,0,0,70,0);
				if(VColFlag==_DIRvercol)
				{
					float(_xor,weaponcollision,1);
				}
				else
				{
					collision(0,70,0,0,-70,0);
					if(VColFlag==_DIRvercol)
					{
						float(_xor,weaponcollision,1);
					}
				}

				if(weaponcollision==1)
				{
					turn(0,0,-16);
				}
				else
				{
					turn(0,0,16);
				}
				*/
				turn(0,0,16);
			}
		}
		else
		{
			call(ModelAmbient,255,255,255);
		}
}


Actor(WeaponAmmo)
{
		file(WeaponAmmoHeader);
		startaction(nomove);
		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);
}

Actor(WeaponAmmoGrenade)
{
		file(WeaponAmmoGrenadesHeader);
		startaction(nomove);
		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);
}

Actor(WeaponBaton)
{
		file(WeaponBatonHeader);
		startaction(nomove);
		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);
		if(VTrigger==_DIRshoot)
		{
		}
}



Actor(WeaponFlameThrower)
{
		file(WeaponFlameThrowerHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		float(_declare,flag_ft1,0);
		float(_declare,flag_ft2,0);
		float(_declare,flag_ft3,0);
		float(_declare,ft_flipflop,0);

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat==1)
			{
				if(flag_ft1==1)
				{
					samplestop(SFXFlameThrowerRoast);
					float(_set,flag_ft1,0);
				}
			}
			else
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,80,0);
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}

				//FIRING WEAPON
				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					if(flag_ft2>6)
					{
						//FIRING WEAPON
						spawnactor(BulletFlameThrower,0,80,0);
						if(VTrigger==_DIRBulletFired)
						{
							call(ChangeInventory,0,-1);

							if(vrnd<50)
							{
								vector(_set,tmpvector,255,32,16);
								vector(_set,gactorpos,0,32,0);
								spawnlight(Lomnilight2,0,gactorpos,tmpvector,EmptyVector,400);
							}

							float(_rnd2,tmpfloat,8);	//7
							float(_add,tmpfloat,12);	//11

							vector(_declare,ft_pos1,0,0,0);
							vector(_declare,ft_ine1,0,0,0);
							vector(_set,ft_pos1,0,50,-10);
							vector(_set,ft_ine1,0,0,0);
							vector(_sety,ft_ine1,tmpfloat);

							if(vtrigger==_DIRforward)
							{
								vector(_set,tmpvector,0,30,0);
								vector(_add,ft_pos1,tmpvector);
							}

							if(ft_flipflop==0)
							{
								spawnparticle(fx_flamethrowerroast,0,ft_pos1,ft_ine1,fx_flipuv);
								float(_set,ft_flipflop,1);
							}
							else
							{
								spawnparticle(fx_flamethrowerroast,0,ft_pos1,ft_ine1,-1);
								float(_set,ft_flipflop,0);
							}
						}
					}
					else
					{
						if(flag_ft2==0)
						{
							//IGNITE WEAPON
							samplestop(SFXFlameThrowerIdle);
							sample(SFXFlameThrowerIgnite,-1);
						}
						elseif(flag_ft2==6)
						{
							//STOP IDLE/START ROAST
							sample(SFXFlameThrowerRoast,-1);
							float(_set,flag_ft1,1);
							float(_set,flag_ft3,0);
						}

						float(_add,flag_ft2,1);
					}
				}
				else
				{
					if(flag_ft1==0)
					{
						if(VInventoryLeft>0)
						{
							//IDLE WEAPON
							if(VSniperMode==0)
							{
								float(_rnd2,tmpfloat,2);
								float(_add,tmpfloat,2);

								vector(_declare,ft_pos2,0,70,-10);
								vector(_declare,ft_ine2,0,4,0);
								vector(_set,ft_pos2,0,70,-10);
								vector(_set,ft_ine2,0,0,0);
								vector(_sety,ft_ine2,tmpfloat);
								spawnparticle(fx_flamethrowerburn,0,ft_pos2,ft_ine2,-1);
							}

							if(flag_ft3==0)
							{
								sample(SFXFlameThrowerIdle,-1);
								float(_set,flag_ft3,1);
							}
						}
					}
					elseif(flag_ft1==1)
					{
						//AFTER FIRING WEAPON
						if(VInventoryLeft>0)
						{
							vector(_set,tmpvector,0,70,0);
							spawnparticle(fx_weaponsmoke,0,tmpvector,emptyvector,fx_flamethrowsmoke);
						}
						samplestop(SFXFlameThrowerRoast);
					}
					float(_set,flag_ft2,0);
					float(_set,flag_ft1,0);
				}
			}
		}
		else
		{
			if(flag_ft3==1)
			{
				samplestop(SFXFlameThrowerIdle);
				float(_set,flag_ft3,0);
			}

			if(flag_ft1==1)
			{
				samplestop(SFXFlameThrowerRoast);
			}

			float(_set,flag_ft2,0);
			float(_set,flag_ft1,0);
		}
}



Actor(WeaponBuzzSaw)
{
		file(WeaponBuzzSawHeader);
		startaction(WeaponBuzzSawOff);

		call(SetParticleSetID);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		float(_declare,buzzsawinit,0);
		float(_declare,buzzsawsampflag,0);

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat==1)
			{
				if(buzzsawsampflag==1)
				{
					spawnaction(WeaponBuzzSawIdle);
					samplestop(SFXMeatCutterCut);
					float(_set,buzzsawsampflag,0);
				}
			}
			else
			{
				if(buzzsawinit==0)
				{
					spawnaction(WeaponBuzzSawIdle);

					sample(SFXMeatCutterIdle,-1);
					float(_set,buzzsawinit,1);
				}

				if(VInventoryLeft<=0)
				{
					samplestop(SFXMeatCutterIdle);
					if(VAction!=WeaponBuzzSawOff)
					{
						spawnaction(WeaponBuzzSawOff);
					}
				}


				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}

				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,60,15);
					callsub(Sub_WeaponTarget);
				}

				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					spawnactor(BulletBuzzSaw,0,55,15);

					if(VSniperMode==0)
					{
						if(vrnd<25)
						{
							vector(_set,tmpvector,0,20,0);
							spawnparticle(fx_weaponsmoke,0,tmpvector,emptyvector,fx_buzzsawsmokesub);
						}
					}

					if(buzzsawsampflag==0)
					{
						sample(SFXMeatCutterCut,-1);
						spawnaction(WeaponBuzzSawRev);
					}
					float(_set,buzzsawsampflag,1);


					if(VTrigger==_DIRBulletFired)
					{
						call(ChangeInventory,0,-1);
					}
				}
				else
				{
					if(buzzsawsampflag==1)
					{
						spawnaction(WeaponBuzzSawIdle);
						samplestop(SFXMeatCutterCut);
					}
					float(_set,buzzsawsampflag,0);

					if(VInventoryLeft>0)
					{
						if(vrnd<0.005)
						{
							sample(SFXMeatCutterRev,-1);
						}
						elseif(vrnd<8)
						{
							if(VSniperMode==0)
							{
								vector(_set,tmpvector,0,20,0);
								spawnparticle(fx_weaponsmoke,0,tmpvector,emptyvector,fx_buzzsawsmokesub);
							}
						}
					}
				}
			}
		}
		else
		{
			if(buzzsawinit==1)
			{
				spawnaction(WeaponBuzzSawOff);
				samplestop(SFXMeatCutterIdle);
				float(_set,buzzsawinit,0);
			}

			if(buzzsawsampflag==1)
			{
				spawnaction(WeaponBuzzSawIdle);
				samplestop(SFXMeatCutterCut);
			}
			float(_set,buzzsawsampflag,0);
		}
}



Actor(WeaponTorch)
{
		file(WeaponTorchHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		float(_declare,torchsampflag,0);

		if(VactorFlag==_AFLAGinitialize)			//re-initialize after a loadgame
		{
			if(torchsampflag==1)
			{
				sample(SFXweapontorch2,-1);
			}
		}

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat==1)
			{
				if(torchsampflag!=0)
				{
					samplestop(SFXweapontorch2);
					float(_set,torchsampflag,0);
				}
			}
			else
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,25,-10);
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}

				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					spawnactor(BulletTorch,0,25,-10);

					if(VTrigger==_DIRBulletFired)
					{
						call(ChangeInventory,0,-1);

						if(VSniperMode==0)
						{
							//muzzle flash
							vector(_set,gactorpos,0,35,-12);
							spawnparticle(fx_torch,0,Gactorpos,emptyvector,-1);
							spawnparticle(fx_torch,0,Gactorpos,emptyvector,fx_gunflashvert);
							spawnparticle(fx_torch,0,Gactorpos,emptyvector,fx_gunflashdiag1);
							spawnparticle(fx_torch,0,Gactorpos,emptyvector,fx_gunflashdiag2);
							//muzzle flash

							vector(_set,gactorpos,0,30,-12);
							spawnparticle(fx_flare,0,gactorpos,emptyvector,fx_torchflareburn);
						}
					}

					if(torchsampflag==0)
					{
						sample(SFXweapontorch1,-1);
						sample(SFXweapontorch2,-1);
						float(_set,torchsampflag,1);
					}
				}
				else
				{
					if(VSniperMode==0)
					{
						vector(_set,gactorpos,0,30,-12);
						spawnparticle(fx_flare,0,gactorpos,emptyvector,fx_torchflareidle);
					}

					if(torchsampflag==1)
					{
						samplestop(SFXweapontorch2);
						float(_set,torchsampflag,0);
					}
				}
			}
		}
		else
		{
			if(torchsampflag==1)
			{
				samplestop(SFXweapontorch2);
				float(_set,torchsampflag,0);
			}
		}
}



Actor(WeaponPAK)
{
		file(WeaponPAKHeader);
		startaction(WeaponPakIdle);

		call(SetParticleSetID);

		float(_declare,PAKSinAngle,0);
		float(_declare,PAKCosAngle,0);
		float(_declare,PAKAngle,0);
		float(_declare,PAKAddAngle,1365);

		float(_declare,flying,0);
		float(_declare,flyingsample,0);

		float(_declare,twirly,0);

		float(_declare,BulletCounter,PAK_RELOADDELAY);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		float(_set,twirly,0);

		if(vstate==StateAttached && VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat==1)
			{
				if(VActorFlag==_AFLAGsignalfromparent)
				{
					float(_set,flying,1);
					float(_set,twirly,1);

					//Direction(_set,_DIRshoot);

					if(vaction!=WeaponPakSpin)
					{
						spawnaction(WeaponPakSpin);
					}
					//call(CheckConnections);
				}
				elseif(flyingsample!=0)
				{
					float(_set,flying,0);
					samplestop(SFXPAKFly);
					//debugmessage("stop1");
					float(_set,flyingsample,0);
				}

				//someone broke my shit, so i moved this here ....
				if(flying==1)
				{
					vector(_set,gactorpos,0,70,0);
					float(_set,PakFly,1);
					float(_sin,PAKSinAngle,PAKAngle);
					float(_cos,PAKCosAngle,PAKAngle);
					float(_mul,PAKSinAngle,16);
					float(_mul,PAKCosAngle,16);
					float(_add,PAKAngle,PAKAddAngle);
					float(_add,PAKAddAngle,32);
					float(_and,PAKAddAngle,4095);

					vector(_set,gactorine,0,-8,0);
					vector(_setx,gactorine,PAKSinAngle);
					vector(_setz,gactorine,PAKCosAngle);

					spawnparticle(fx_pakflash,0,gactorpos,gactorine,-1);

					if(flyingsample==0)
					{
						sample(SFXPAKFly,-1);
						//debugmessage("start2");
						float(_set,flyingsample,1);
					}
				}
			}
			else
			{
				if(VAction!=WeaponPakSpin)
				{
					float(_set,flying,0);
				}


				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,80,0);
					callsub(Sub_WeaponTarget);
				}

				if(flying==1)
				{
					vector(_set,gactorpos,0,70,0);
					float(_set,PakFly,1);
					float(_sin,PAKSinAngle,PAKAngle);
					float(_cos,PAKCosAngle,PAKAngle);
					float(_mul,PAKSinAngle,16);
					float(_mul,PAKCosAngle,16);
					float(_add,PAKAngle,PAKAddAngle);
					float(_add,PAKAddAngle,32);
					float(_and,PAKAddAngle,4095);

					vector(_set,gactorine,0,-8,0);
					vector(_setx,gactorine,PAKSinAngle);
					vector(_setz,gactorine,PAKCosAngle);

					spawnparticle(fx_pakflash,0,gactorpos,gactorine,-1);

					if(flyingsample==0)
					{
						sample(SFXPAKFly,-1);
						//debugmessage("start1");
						float(_set,flyingsample,1);
					}
				}
				else
				{
					float(_set,PakFly,0);
					if(flyingsample==1)
					{
						samplestop(SFXPAKFly);
						//debugmessage("stop2");
						float(_set,flyingsample,0);
					}

					//empty gun sample
					if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
					{
						sample(SFXWeaponEmpty,-1);
					}

					if(VTrigger==_DIRShoot && VInventoryLeft>0)
					{
						spawnactor(BulletPAK,0,70,-5);

						float(_set,twirly,1);

						if(vaction!=WeaponPakSpin)
						{
							spawnaction(WeaponPakSpin);
							sample(SFXPAKSpin,-1);
						}

						if(VSniperMode==0)
						{
							//muzzle flash
							vector(_set,gactorpos,0,70,0);

							float(_sin,PAKSinAngle,PAKAngle);
							float(_cos,PAKCosAngle,PAKAngle);
							float(_mul,PAKSinAngle,12);
							float(_mul,PAKCosAngle,12);
							float(_add,PAKAngle,PAKAddAngle);
							float(_add,PAKAddAngle,32);
							float(_and,PAKAddAngle,4095);

							vector(_set,gactorine,0,0,0);
							vector(_setx,gactorine,PAKSinAngle);
							vector(_setz,gactorine,PAKCosAngle);
							spawnparticle(fx_pakflash,0,gactorpos,gactorine,-1);
						}

						if(VTrigger==_DIRBulletFired)
						{
							sample(SFXPAKFire,-1);

							Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
							call(ChangeInventory,0,-1);
							float(_sub,BulletCounter,1);
							if(BulletCounter==0&&VCoreAICon!=0)
							{
								Direction(_SetParent,_DIRTempFlag);
								float(_set,BulletCounter,PAK_RELOADDELAY);
							}
						}
					}
				}
			}
		}
		else
		{
			float(_set,flying,0);
			if(flyingsample==1)
			{
				samplestop(SFXPAKFly);
				//debugmessage("stop3");
				float(_set,flyingsample,0);
			}
		}

		if(twirly==0&&vaction!=WeaponPakIdle)
		{
			spawnaction(WeaponPakIdle);
			samplestop(SFXPAKSpin);
		}

}


Actor(WeaponBatteryGrabber)
{
		file(WeaponBatteryHeader);
		startaction(nomove);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		if(vstate!=StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			call(ChangeInventory,0,-1);
			call(CheckAttached,_CADropBattery);
		}

}

Actor(WeaponPumpGun)
{
		file(WeaponPumpGunHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,logoncounter,0);
		float(_declare,logon,0);
		float(_declare,pumpgunsampflag,-1);
		float(_declare,pumpgunsmokeflag,-1);

		float(_declare,BulletCounter,PUMPGUN_RELOADDELAY);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat!=1)
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,70,-5);
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					//vector(_set,gactorpos,0,50,-15);
					//vector(_set,gactorine,0,500,-15);
					//spawnparticle(fx_flare,0,gactorpos,emptyvector,fx_coplaserflarered);
					//spawnparticle(fx_coplaser,0,gactorpos,gactorine,-1);
					sample(SFXWeaponEmpty,-1);
				}

				if(VActorFlag==_AFLAGlogon)
				{
					float(_sub,logoncounter,1);
					if(logoncounter<0)
					{
						float(_set,logoncounter,0);
					}
				}
				else
				{
					float(_set,logoncounter,400);
				}


				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					call(SaveAimMatrix);
					if(VCoreAICon!=0)
					{
						float(_set,logon,90);
						call(RandomizeAimMatrix,logoncounter,logoncounter,logoncounter);
					}
					else
					{
						float(_set,logon,60);
					}
					spawnactor(BulletPumpGun,0,70,-5);		//main bullet

					//secondary pumpgun bullets

					call(RandomizeAimMatrix,logon,logon,logon);
					spawnactor(BulletPumpGunSecondary,0,70,-5);
					call(RestoreAimMatrix);
					call(RandomizeAimMatrix,logon,logon,logon);
					spawnactor(BulletPumpGunSecondary,0,70,-5);
					call(RestoreAimMatrix);
					call(RandomizeAimMatrix,logon,logon,logon);
					spawnactor(BulletPumpGunSecondary,0,70,-5);
					call(RestoreAimMatrix);
					call(RandomizeAimMatrix,logon,logon,logon);
					spawnactor(BulletPumpGunSecondary,0,70,-5);
					call(RestoreAimMatrix);

					if(VTrigger==_DIRBulletFired)
					{
						if(VSniperMode==0)
						{
							//muzzle flash
							vector(_set,Gactorpos,0,85,-15);
							spawnparticle(fx_gunflashPump,0,Gactorpos,emptyvector,-1);
							spawnparticle(fx_gunflashPump,0,Gactorpos,emptyvector,fx_gunflashvert);
							spawnparticle(fx_gunflashPump,0,Gactorpos,emptyvector,fx_gunflashdiag1);
							spawnparticle(fx_gunflashPump,0,Gactorpos,emptyvector,fx_gunflashdiag2);
							vector(_set,tmpvector,255,255,255);
							spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,400);

							vector(_set,Gactorpos,0,55,-15);
							spawnparticle(fx_gunstrobePump,0,Gactorpos,emptyvector,fx_gunstroberot);
							//muzzle flash
						}

						sample(SFXPumpGunFire,-1);

						Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
						Direction(_SetParent,_DIRHeavyRecoil);
						call(ChangeInventory,0,-1);

						float(_sub,BulletCounter,1);
						if(BulletCounter==0&&VCoreAICon!=0)
						{
							Direction(_SetParent,_DIRTempFlag);
							float(_set,BulletCounter,PUMPGUN_RELOADDELAY);
						}

						float(_set,pumpgunsampflag,8);			//reload sample delayer
						float(_set,pumpgunsmokeflag,25);		//reload smoke delayer

						if(VSniperMode==0)
						{
							if(VAICon==0)
							{
								float(_rnd2,tmpfloat2,10);
								float(_sub,tmpfloat2,5);
								spawnactor(PumpGunShell,tmpfloat2,tmpfloat2,tmpfloat2);			//frames 15 or 16
							}
						}
					}
				}
				else
				{
					if(pumpgunsmokeflag>=0)
					{
						if(VSniperMode==0 && vrnd<100)
						{
							vector(_set,Gactorpos,0,75,-15);
							spawnparticle(fx_weaponsmoke,0,gactorpos,emptyvector,fx_pumpgunsmoke);
						}
						float(_sub,pumpgunsmokeflag,1);
					}

					if(pumpgunsampflag==0)
					{
						if(VSniperMode==0)
						{
							if(VAICon==0)
							{
								float(_rnd2,tmpfloat2,10);
								float(_sub,tmpfloat2,5);
								spawnactor(PumpGunShell,tmpfloat2,tmpfloat2,tmpfloat2);			//frames 15 or 16
							}
						}
						sample(SFXreload,-1);
						float(_set,pumpgunsampflag,-1);
					}
					elseif(pumpgunsampflag>0)
					{
						float(_sub,pumpgunsampflag,1);
					}
				}
			}
		}
		else
		{
			float(_set,pumpgunsampflag,-1);
			float(_set,pumpgunsmokeflag,-1);
		}
}



Actor(WeaponSubGirlMachineGun)
{
		file(WeaponFakeHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,MachineGunsampflag,0);
		float(_declare,MachineGunsmokeflag,-1);
		float(_declare,ShootDelayCounter,-1);

		float(_declare,MachineGunbarrel,0);

		float(_declare,BulletCounter,MACHGUN_RELOADDELAY);

		if(vstate==StateAttached)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat==1)
			{
				if(Machinegunsampflag!=0)
				{
					samplestop(SFXGunTurretFireLoop);
					float(_set,Machinegunsampflag,0);
				}
			}
			else
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					if(MachineGunbarrel==0)
					{
						vector(_set,WeaponPos,10,120,0);
					}
					else
					{
						vector(_set,WeaponPos,60,130,15);
					}
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRshoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}


				float(_rnd2,tmpfloat2,75);
				float(_rnd2,tmpfloat3,100);
				float(_sub,tmpfloat3,50);

				if(VTrigger==_DIRshoot && VInventoryLeft>0)
				{
					//if(ShootDelayCounter<4)
					//{
					//	float(_add,ShootDelayCounter,1);
					//}
					//else
					//{
						float(_set,ShootDelayCounter,0);

						if(MachineGunbarrel==0)
						{
							vector(_set,Gactorpos,10,60,10);
							spawnactor(BulletSubGirlMachineGun,10,120,0);
						}
						else
						{
							vector(_set,Gactorpos,60,70,25);
							spawnactor(BulletSubGirlMachineGun,60,130,15);
						}

						if(VTrigger==_DIRBulletFired)
						{
							if(MachineGunsampflag==0)
							{
								sample(SFXGunTurretFireLoop,-1)
							}
							float(_set,MachineGunsampflag,1);

							if(VSniperMode==0)
							{
								//muzzle flash
								spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,-1);
								spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashvert);
								spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashdiag1);
								spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashdiag2);

								vector(_set,Gactorine,0,30,0);
								vector(_sub,gactorpos,gactorine);
								spawnparticle(fx_gunstrobeMachineGun,0,Gactorpos,emptyvector,fx_gunstroberot);
								//muzzle flash
							}

							if(MachineGunbarrel==0)
							{
								vector(_set,tmpvector,255,255,255);
								spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,400);
								//call(ChangeInventory,0,-1);
							}

							if(VSniperMode==0)
							{
								vector(_set,gactorpos,0,0,0);
								vector(_setx,gactorpos,tmpfloat3);
								vector(_sety,gactorpos,tmpfloat2);
								if(VCoreAICon==0)
								{
									spawnparticle(fx_machinegunshell,0,gactorpos,emptyvector,-1);
								}
								else
								{
									spawnparticle(fx_machinegunshellAI,0,gactorpos,emptyvector,-1);
								}
							}

							//call(ChangeInventory,0,-1);
							Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
							float(_sub,BulletCounter,1);
							if(BulletCounter==0&&VCoreAICon!=0)
							{
								Direction(_SetParent,_DIRTempFlag);
								float(_set,BulletCounter,MACHGUN_RELOADDELAY);
							}

							float(_rnd2,tmpfloat,2);
							float(_sub,tmpfloat,1);
							vector(_set,gactorine,0,0,0);
							vector(_setx,gactorine,tmpfloat);

							if(MachineGunbarrel==0)
							{
								vector(_set,Gactorpos,10,60,10);
							}
							else
							{
								vector(_set,Gactorpos,60,70,25);
							}

							if(VSniperMode==0)
							{
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_harpoonsmoke);
							}

							float(_set,Machinegunsmokeflag,25);

							float(_xor,MachineGunbarrel,1);
						}
					//}
				}
				else
				{
					if(Machinegunsmokeflag>=0)
					{
						if(MachineGunsmokeflag==25)
						{
							if(VCoreAICon==0)
							{
								spawnactor(MachineGunShell,tmpfloat3,tmpfloat2,0);			//frames 15 or 16
							}
						}

						if(VSniperMode==0)
						{
							float(_rnd2,tmpfloat,2);
							float(_sub,tmpfloat,1);
							vector(_set,gactorine,0,0,0);
							vector(_setx,gactorine,tmpfloat);

							if(vrnd<25)
							{
								if(MachineGunbarrel==0)
								{
									vector(_set,Gactorpos,10,60,10);
								}
								else
								{
									vector(_set,Gactorpos,60,70,25);
								}

								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_harpoonsmoke);
							}
						}
						float(_sub,MachineGunsmokeflag,1);
						float(_set,ShootDelayCounter,-1);
					}

					if(Machinegunsampflag==1)
					{
						samplestop(SFXGunTurretFireLoop);
					}
					float(_set,Machinegunsampflag,0);
				}
			}
		}
		else
		{
			if(MachineGunsampflag==1)
			{
				samplestop(SFXGunTurretFireLoop);
			}
			float(_set,MachineGunsampflag,0);

			float(_set,Machinegunsmokeflag,-1);
			killactor();
		}
}


Actor(WeaponAbeastMachineGun)
{
		file(WeaponFakeHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,MachineGunsampflag,0);
		float(_declare,MachineGunsmokeflag,-1);
		float(_declare,ShootDelayCounter,-1);

		float(_declare,MachineGunbarrel,1);

		float(_declare,BulletCounter,MACHGUN_RELOADDELAY);

		if(vstate==StateAttached)
		{
			if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
			{
				vector(_set,WeaponPos,10,130,0);
				callsub(Sub_WeaponTarget);
			}

			//empty gun sample
			if(VTrigger==_DIRshoot && VInventoryLeft<=0 && VCoreAICon==0)
			{
				sample(SFXWeaponEmpty,-1);
			}


			float(_rnd2,tmpfloat2,75);
			float(_rnd2,tmpfloat3,100);
			float(_sub,tmpfloat3,50);

			if(VTrigger==_DIRshoot && VInventoryLeft>0)
			{
				//if(ShootDelayCounter<4)
				//{
				//	float(_add,ShootDelayCounter,1);
				//}
				//else
				//{
					float(_set,ShootDelayCounter,0);

					spawnactor(BulletABeastMachineGun,10,130,0);
					vector(_set,Gactorpos,10,130,0);

					if(VTrigger==_DIRBulletFired)
					{
						if(MachineGunsampflag==0)
						{
							sample(SFXGunTurretFireLoop,-1)
						}
						float(_set,MachineGunsampflag,1);

						if(VSniperMode==0)
						{
							//muzzle flash
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,-1);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashvert);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag1);
							spawnparticle(fx_gunflashturretac,0,Gactorpos,emptyvector,fx_gunflashdiag2);

							vector(_set,Gactorine,0,30,0);
							vector(_sub,gactorpos,gactorine);
							spawnparticle(fx_gunstrobeturret,0,Gactorpos,emptyvector,fx_gunstroberot);
							//muzzle flash
						}

						vector(_set,tmpvector,255,255,255);
						spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,400);

						if(VSniperMode==0)
						{
							vector(_set,gactorpos,0,0,0);
							vector(_setx,gactorpos,tmpfloat3);
							vector(_sety,gactorpos,tmpfloat2);
							if(VCoreAICon==0)
							{
								//spawnparticle(fx_machinegunshell,0,gactorpos,emptyvector,-1);
							}
							else
							{
								//spawnparticle(fx_machinegunshellAI,0,gactorpos,emptyvector,-1);
							}
						}

						//call(ChangeInventory,0,-1);
						Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
						float(_sub,BulletCounter,1);
						if(BulletCounter==0&&VCoreAICon!=0)
						{
							Direction(_SetParent,_DIRTempFlag);
							float(_set,BulletCounter,MACHGUN_RELOADDELAY);
						}

						float(_rnd2,tmpfloat,2);
						float(_sub,tmpfloat,1);
						vector(_set,gactorine,0,0,0);
						vector(_setx,gactorine,tmpfloat);
						vector(_set,Gactorpos,10,100,0);
						spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_harpoonsmoke);
						float(_set,Machinegunsmokeflag,25);
					}
				//}
			}
			else
			{
				if(Machinegunsmokeflag>=0)
				{
					if(MachineGunsmokeflag==25)
					{
						if(VCoreAICon==0)
						{
							//spawnactor(MachineGunShell,tmpfloat3,tmpfloat2,0);			//frames 15 or 16
						}
					}

					if(VSniperMode==0)
					{
						float(_rnd2,tmpfloat,2);
						float(_sub,tmpfloat,1);
						vector(_set,gactorine,0,0,0);
						vector(_setx,gactorine,tmpfloat);

						if(vrnd<25)
						{
							vector(_set,Gactorpos,10,100,0);
							spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_harpoonsmoke);
						}
					}
					float(_sub,MachineGunsmokeflag,1);
					float(_set,ShootDelayCounter,-1);
				}

				if(Machinegunsampflag==1)
				{
					samplestop(SFXGunTurretFireLoop);
				}
				float(_set,Machinegunsampflag,0);
			}
		}
		else
		{
			if(MachineGunsampflag==1)
			{
				samplestop(SFXGunTurretFireLoop);
			}
			float(_set,MachineGunsampflag,0);

			float(_set,Machinegunsmokeflag,-1);
			killactor();
		}
}


Actor(WeaponMachineGun)
{
		file(WeaponMachineGunHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,MachineGunsampflag,0);
		float(_declare,MachineGunsmokeflag,-1);

		float(_declare,BulletCounter,MACHGUN_RELOADDELAY);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		float(_declare,MachineGunbarrel,1);

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat==1)
			{
				if(MachineGunsampflag==1)
				{
					samplestop(SFXMachineGunFire);
					float(_set,MachineGunsampflag,0);
				}
			}
			else
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					if(MachineGunbarrel==0)
					{
						vector(_set,WeaponPos,0,80,-15);
					}
					else
					{
						vector(_set,WeaponPos,0,80,10);
					}
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}

				float(_rnd2,tmpfloat2,75);
				float(_rnd2,tmpfloat3,100);
				float(_sub,tmpfloat3,50);

				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					if(VSniperMode==0)
					{
						if(MachineGunbarrel==0)
						{
							float(_set,MachineGunbarrel,1);
							spawnactor(BulletMachineGun,0,80,-15);
							vector(_set,Gactorpos,0,90,-15);
						}
						else
						{
							float(_set,Machinegunbarrel,0);
							spawnactor(BulletMachineGun,0,80,10);
							vector(_set,Gactorpos,0,90,10);
						}
					}
					else
					{
						if(MachineGunbarrel==0)
						{
							float(_set,MachineGunbarrel,1);
							spawnactor(BulletMachineGun,0,80,0);
							vector(_set,Gactorpos,0,90,-15);
						}
						else
						{
							float(_set,Machinegunbarrel,0);
							spawnactor(BulletMachineGun,0,80,0);
							vector(_set,Gactorpos,0,90,10);
						}
					}

					if(VTrigger==_DIRBulletFired)
					{
						if(MachineGunsampflag==0)
						{
							sample(SFXMachineGunFire,-1)
						}
						float(_set,MachineGunsampflag,1);

						if(VSniperMode==0)
						{
							//muzzle flash
							spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,-1);
							spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashvert);
							spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashdiag1);
							spawnparticle(fx_gunflashMachineGun,0,Gactorpos,emptyvector,fx_gunflashdiag2);

							vector(_set,Gactorine,0,30,0);
							vector(_sub,gactorpos,gactorine);
							spawnparticle(fx_gunstrobeMachineGun,0,Gactorpos,emptyvector,fx_gunstroberot);
							//muzzle flash
						}

						if(MachineGunbarrel==0)
						{
							vector(_set,tmpvector,255,255,255);
							spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,400);
							call(ChangeInventory,0,-1);
						}

						if(VSniperMode==0)
						{
							vector(_set,gactorpos,0,0,0);
							vector(_setx,gactorpos,tmpfloat3);
							vector(_sety,gactorpos,tmpfloat2);
							if(VCoreAICon==0)
							{
								spawnparticle(fx_machinegunshell,0,gactorpos,emptyvector,-1);
							}
							else
							{
								spawnparticle(fx_machinegunshellAI,0,gactorpos,emptyvector,-1);
							}
						}

						Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
						float(_sub,BulletCounter,1);
						if(BulletCounter==0&&VCoreAICon!=0)
						{
							Direction(_SetParent,_DIRTempFlag);
							float(_set,BulletCounter,MACHGUN_RELOADDELAY);
						}

						float(_set,MachineGunsmokeflag,25);		//reload smoke delayer
					}
				}
				else
				{
					if(Machinegunsmokeflag>=0)
					{
						if(MachineGunsmokeflag==25)
						{
							if(VCoreAICon==0)
							{
								spawnactor(MachineGunShell,tmpfloat3,tmpfloat2,0);			//frames 15 or 16
							}
						}

						if(VSniperMode==0)
						{
							float(_rnd2,tmpfloat,2);
							float(_sub,tmpfloat,1);
							vector(_set,gactorine,0,0,0);
							vector(_setx,gactorine,tmpfloat);

							if(vrnd<50)
							{
								vector(_set,Gactorpos,0,65,-15);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmoke);
							}
							else
							{
								vector(_set,Gactorpos,0,65,10);
								spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_machinegunsmoke);
							}
						}
						float(_sub,MachineGunsmokeflag,1);
					}

					if(Machinegunsampflag==1)
					{
						samplestop(SFXMachineGunFire);
					}
					float(_set,Machinegunsampflag,0);
				}
			}
		}
		else
		{
			if(MachineGunsampflag==1)
			{
				samplestop(SFXMachineGunFire);
			}
			float(_set,MachineGunsampflag,0);

			float(_set,Machinegunsmokeflag,-1);
		}
}

Actor(WeaponMaimer)
{
		file(WeaponMaimerHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,BulletCounter,MAIMER_RELOADDELAY);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat!=1)
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,80,0);
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}

				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					spawnactor(BulletMaimer,0,80,0);

					if(VTrigger==_DIRBulletFired)
					{
						sample(SFXMaimerFire,-1);
						if(VSniperMode==0)
						{
							//muzzle flash
							vector(_set,Gactorpos,0,100,-10);
							spawnparticle(fx_gunflashMaimer,0,Gactorpos,emptyvector,-1);
							spawnparticle(fx_gunflashMaimer,0,Gactorpos,emptyvector,fx_gunflashvert);
							spawnparticle(fx_gunflashMaimer,0,Gactorpos,emptyvector,fx_gunflashdiag1);
							spawnparticle(fx_gunflashMaimer,0,Gactorpos,emptyvector,fx_gunflashdiag2);
							vector(_set,tmpvector,255,255,255);
							spawnlight(fire_light,0,Gactorpos,tmpvector,EmptyVector,400);

							vector(_set,Gactorpos,0,70,-10);
							spawnparticle(fx_gunstrobeMaimer,0,Gactorpos,emptyvector,fx_gunstroberot);
							//muzzle flash
						}

						Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
						call(ChangeInventory,0,-1);
						float(_sub,BulletCounter,1);
						if(BulletCounter==0&&VCoreAICon!=0)
						{
							Direction(_SetParent,_DIRTempFlag);
							float(_set,BulletCounter,MAIMER_RELOADDELAY);
						}
					}
				}
			}
		}
}

Actor(WeaponHarpoon)
{
		file(WeaponHarpoonHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,BulletCounter,HARPOON_RELOADDELAY);

		float(_declare,harpsmokeflag,-1);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat!=1)
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,95,-8);
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}

				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					spawnactor(BulletHarpoon,0,95,-8);

					if(VTrigger==_DIRBulletFired)
					{
						Direction(_SetParent,_DIRHeavyRecoil);
						Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
						call(ChangeInventory,0,-1);
						float(_sub,BulletCounter,1);
						if(BulletCounter==0&&VCoreAICon!=0)
						{
							Direction(_SetParent,_DIRTempFlag);
							float(_set,BulletCounter,HARPOON_RELOADDELAY);
						}

						sample(SFXHarpoonLaunch,-1);

						float(_set,harpsmokeflag,35);		//reload smoke delayer
					}
				}
				else
				{
					if(harpsmokeflag>=0)
					{
						if(VSniperMode==0 && vrnd<50)
						{
							vector(_set,Gactorpos,0,110,-8);
							float(_rnd2,tmpfloat,2);
							float(_sub,tmpfloat,1);
							vector(_set,gactorine,0,0,0);
							vector(_setx,gactorine,tmpfloat);
							spawnparticle(fx_weaponsmoke,0,gactorpos,gactorine,fx_harpoonsmoke);
						}
						float(_sub,harpsmokeflag,1);
					}
				}
			}
		}
		else
		{
			float(_set,harpsmokeflag,-1);
		}
}



Actor(WeaponBazooka)
{
		file(WeaponBazookaHeader);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,BulletCounter,BAZOOKA_RELOADDELAY);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		if(vstate==StateAttached&&VActorFlag!=_AFLAGweaponinvisible)
		{
			callsub(Sub_AllowedToShoot);
			if(TmpFloat!=1)
			{
				if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
				{
					vector(_set,WeaponPos,0,100,0);
					callsub(Sub_WeaponTarget);
				}

				//empty gun sample
				if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
				{
					sample(SFXWeaponEmpty,-1);
				}

				if(VTrigger==_DIRShoot && VInventoryLeft>0)
				{
					spawnactor(BulletBazooka,0,100,0);

					if(VTrigger==_DIRBulletFired)
					{
						Direction(_SetParent,_DIRHeavyRecoil);
						Direction(_ClrParent,_DIRshoot|_DIRTempFlag);
						call(ChangeInventory,0,-1);

						float(_sub,BulletCounter,1);
						if(BulletCounter==0&&VCoreAICon!=0)
						{
							Direction(_SetParent,_DIRTempFlag);
							float(_set,BulletCounter,BAZOOKA_RELOADDELAY);
						}

						sample(SFXBazookaLaunch1,-1);
					}
				}
			}
		}
}
 




Actor(WeaponMaser)
{
		file(WeaponMaserHeader);
		startaction(nomove);

		float(_declare,maserfirsttime,0);
		float(_declare,maserloopSFX,0);
		float(_declare,maserpowerup,0);
		float(_declare,maserpowerupSFX,0);

		call(SetParticleSetID);

		float(_declare,BulletCounter,MASER_RELOADDELAY);

		float(_declare,weaponcollider,0);
		callsub(Sub_WeaponHandler,weaponcollider);

		float(_set,maserpowerup,0);


		//Is Maser charged
		if(MaserKey>=4)
		{
			if(VActorFlag!=_AFLAGweaponinvisible)
			{
				if(vrnd<100)
				{
					if(VSniperMode==0)
					{
						vector(_set,gactorpos,0,50,-8);
						spawnparticle(fx_masersparks,0,gactorpos,emptyvector,-1);
					}
				}

				if(vstate==StateAttached)
				{
					callsub(Sub_AllowedToShoot);
					if(TmpFloat==1)
					{
						if(maserloopSFX==1)
						{
							samplestop(SFXMaser);
							float(_set,maserloopSFX,0);
						}
					}
					else
					{
						if(VTrigger==_DIRcombatmode && VTrigger==_DIRHaveGun)
						{
							if(maserloopSFX==0)
							{
								sample(SFXMaser,-1);
								float(_set,maserloopSFX,1);
							}

							vector(_set,WeaponPos,0,40,0);
							callsub(Sub_WeaponTarget);
						}
						else
						{
							if(maserloopSFX==1)
							{
								samplestop(SFXMaser);
								float(_set,maserloopSFX,0);
							}
						}

						//empty gun sample
						if(VTrigger==_DIRShoot && VInventoryLeft<=0 && VCoreAICon==0)
						{
							sample(SFXWeaponEmpty,-1);
						}

						if(VTrigger==_DIRShoot && VInventoryLeft>0)
						{
							//power up first before we fire please!
							if(VAICon==0)
							{
								if(maserfirsttime==60)								//charge up time
								{
									spawnactor(BulletMaser,0,40,0);
									float(_set,maserfirsttime,0);
								}
							}
							else
							{
								if(maserfirsttime==90)								//charge up time
								{
									spawnactor(BulletMaser,0,40,0);
									float(_set,maserfirsttime,0);
								}
							}
							float(_add,maserfirsttime,1);

							if(VTrigger==_DIRBulletFired)
							{
								float(_set,maserpowerupSFX,0);					//no longer powering up the maser
								sample(SFXMaserPower,-1);

								Direction(_SetParent,_DIRHeavyRecoil);
								Direction(_ClrParent,_DIRshoot|_DIRBulletFired);
								call(ChangeInventory,0,-1);

								float(_sub,BulletCounter,1);
								if(BulletCounter==0&&VCoreAICon!=0)
								{
									Direction(_SetParent,_DIRTempFlag);
									float(_set,BulletCounter,MASER_RELOADDELAY);
								}
							}
							else
							{
								float(_set,maserpowerup,1);						//powering up
								if(maserpowerupSFX==0)
								{
									float(_set,maserpowerupSFX,1);
									sample(SFXMaserPower,-1);
								}

								vector(_set,tmpvector,16,255,64);
								SpawnLight(toruslight,0,EmptyVector,tmpvector,EmptyVector,600);

								if(VSniperMode==0)
								{
									vector(_set,gactorpos,0,100,0);
									vector(_set,gactorine,0,0,0);
									spawn3dflare(16,255,64,1,gactorpos,gactorine);
								}
							}
						}
						else
						{
							float(_set,maserfirsttime,0);
						}
					}
				}
				else
				{
					if(maserloopSFX==1)
					{
						samplestop(SFXMaser);
						float(_set,maserloopSFX,0);
					}

					float(_set,maserfirsttime,0);
				}

				//no longer powering up the maser
				if(maserpowerup==0)
				{
					if(maserpowerupSFX==1)
					{
						samplestop(SFXMaserPower);
						float(_set,maserpowerupSFX,0);
					}
				}
			}
		}
}





Actor(WeaponBot)
{
		file(WeaponBotHeader);
		startaction(botidle);

		printi("health:  ",vhealth);

		if(vtrigger|=_DIRallcol)
		{
			turn(0,20,0);
			move(0,0,-1);
		}
		else
		{
			move(0,0,-3);
		}
		if(vdisttoground>150)
		{
			move(0,-1,0);
		}
		elseif(vdisttoground<100)
		{
			move(0,1,0);
		}
		if(VTrigger==_DIRactorbulletcol)
		{
			move(0,30,0);
		}
		if(Vhealth<=0)
		{
			killactor();
		}
}











//-------------------------------
// DOMINA TURRET
//-------------------------------
SubRoutine(Sub_GunTurretHandler)
{
		if(VTrigger==_DIRshoot)
		{
			if(side==0)
			{
				float(_set,side,1);
				vector(_set,tmpvector,30,-10,70);
				SpawnActorKFObj(BulletTurret,tmpvector,Gactorpos,Gactorine,false);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashhorizac);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashvertac);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag1ac);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag2ac);
			}
			elseif(side==1)
			{
				float(_set,side,0);
				vector(_set,tmpvector,-30,-10,70);
				SpawnActorKFObj(BulletTurret,tmpvector,Gactorpos,Gactorine,false);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashhorizac);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashvertac);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag1ac);
				spawnparticle(fx_TurFlash,-2,Gactorpos,Gactorine,fx_gunflashdiag2ac);
			}
		}
		if(VTrigger!=_DIRshoot)
		{
			if(GunSamFlag==1)
			{
				samplestop(SFXMachineGunFire2);
				float(_set,GunSamFlag,0);
			}
		}
}





//--------------------------------
// SUB GIRL ROCKET PACK
//--------------------------------
Actor(WeaponSubGirlRocketPack)
{
		file(WeaponSubGirlRocketPackHeader);
		startaction(WeaponSubGirlRocketPackOpen);
/*
		if(vstate==StateAttached)
		{
		}
		else
		{
			killactor();
		}
*/
}
 


Actor(WeaponSubGirlPack)
{
		file(WeaponSubGirlPackHeader);
		startaction(WeaponSubGirlRocketPackClosed);

/*
		if(vstate==StateAttached)
		{
		}
		else
		{
			killactor();
		}
*/
}
 




/*
			callsub(Sub_AllowedToShoot);
			if(TmpFloat==1)
			{
				if(MachineGunsampflag==1)
				{
					samplestop(SFXMachineGunFire);
					float(_set,MachineGunsampflag,0);
				}
			}
			else
			{
*/