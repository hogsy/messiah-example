
//+Y is forward
//-Z is up



#define BulletStateNormal				1
#define BulletStateStuckInWall			4			//this is referenced as an absolute in saxsact.cpp ...don't change
#define	BulletStateStuckOnFloor			8			//this is referenced as an absolute in saxsact.cpp ...don't change

#define	BulletStateDud					StateDead
#define BulletStateExplode				StateThrown
#define BulletStateAttachedToActor		StateAttached



//---------------------------------------------------------------------------- ricochets SFX

SubRoutine(sub_RiccoMetal)
{
		sample(SFXRicochetMetal,-1);
}


SubRoutine(sub_RiccoWood)
{
		sample(SFXRicochetWood,-1);
}

SubRoutine(sub_RiccoConcrete)
{
		sample(SFXRicochetConc,-1);
}


//---------------------------------------------------------------------------- time out handlers


SubRoutine(Sub_BulletHandler15)
{
		rotate(0,0,0);
		if(Vactivetime>450)			//15 seconds
		{
			killactor();
		}
}

SubRoutine(Sub_BulletHandler5)
{
		rotate(0,0,0);
		if(Vactivetime>150)			//5 seconds
		{
			killactor();
		}
}


//---------------------------------------------------------------------------- explosions

//make sure tmpvector is filled in prior to calling
SubRoutine(sub_fxexplosion_lesser)
{
		call(SetParticleSetID);

		vector(_copy,TrashableVector,tmpvector);
		
		call(wCheckViewCollision,-1,emptyvector,emptyvector,-1);

		vector(_set,fxvector,0,75,0);
		vector(_add,TrashableVector,fxvector);
		spawnparticle(fx_mainexplosion,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_mainexplosion,-1,TrashableVector,emptyvector,-1);

		spawnparticle(fx_explosionsmoke,-1,TrashableVector,emptyvector,-1);
}


SubRoutine(sub_fxexplosion)
{
		call(SetParticleSetID);

		vector(_copy,TrashableVector,tmpvector);
		
		call(wCheckViewCollision,-1,emptyvector,emptyvector,-1);

		vector(_set,fxvector,0,75,0);
		vector(_add,TrashableVector,fxvector);
		spawnparticle(fx_mainexplosion,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_mainexplosion,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_mainexplosion,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_mainexplosion,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);		//should have a few shoot towards camera
		spawnparticle(fx_hshrapnel,-1,TrashableVector,emptyvector,-1);		//should have a few shoot towards camera

		spawnparticle(fx_explosionsmoke,-1,TrashableVector,emptyvector,-1);

		spawnparticle(fx_explosionshards,-1,TrashableVector,emptyvector,-1);

		vector(_set,fxvector,-128,-128,-128);
		SpawnLight(perm_light,-1,TrashableVector,fxvector,EmptyVector,400);
}

SubRoutine(sub_fxsmallexplosion)
{
		call(SetParticleSetID);

		vector(_copy,TrashableVector,tmpvector);
		
		vector(_set,fxvector,0,70,0);
		vector(_add,TrashableVector,fxvector);
		spawnparticle(fx_smallexplosion,-1,TrashableVector,emptyvector,-1);
		spawnparticle(fx_smallexplosion,-1,TrashableVector,emptyvector,-1);
}


Actor(BulletExplosion)
{
		file(BulletExplosionHeader);
		startstate(BulletStateNormal);
		startaction(nomove);

		call(SetParticleSetID);

		//PrintILog("ExplosionActiveTime: ",VActiveTime);
		if(VActiveTime==0)
		{
			call(CheckBulletCollision,-1,DamageBlastDamage,false);
		}
		elseif(VActiveTime>10)
		{
			call(BlastObjCollisionCheck,tmpvector);
			if(VDynamicCollision==0)
			{
				killactor();
			}
			else
			{
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

					sample(SFXGunTurretExplode,tmpvector);
					callsub(sub_fxexplosion_lesser);
				}
			}
		}

		//callsub(Sub_BulletHandler15);
}



Actor(BulletShockWave)
{
		file(BulletShockWaveHeader);
		startstate(BulletStateNormal);
		startaction(nomove);

		call(CheckBulletCollision,-1,DamageShockWaveDamage,true);
		killactor();

}

//same as shockwave, except for the radius and damage
Actor(BulletDistortion)
{
		file(BulletDistortionHeader);
		startstate(BulletStateNormal);
		startaction(nomove);

		call(CheckBulletCollision,-1,DamageDistortion,false);

		killactor();
}



//---------------------------------------------------------------------------- sticky bullets

Actor(BulletHarpoon)
{
		file(BulletHarpoonHeader);
		startstate(BulletStateNormal);
		startaction(NoMove);

		call(SetParticleSetID);


		call(AICon,TRUE);					//need to prevent dual deposses


		float(_declare,localstate,0);
		float(_declare,blooddriptime,0);

		if(VState!=BulletStateStuckInWall)
		{
			collision(0,-110,0,0,110,0);
			float(_seti,TmpFloat,VColAngle)

			if(VSniperModeGlobal==0)
			{
				vector(_set,gactorine,0,1,0);
				spawnparticle(fx_slugwake,0,emptyvector,gactorine,-1);
				vector(_set,gactorpos,0,20,0);
				spawnparticle(fx_slugwake,0,gactorpos,gactorine,-1);
				vector(_set,gactorpos,0,40,0);
				spawnparticle(fx_slugwake,0,gactorpos,gactorine,-1);
				vector(_set,gactorpos,0,60,0);
				spawnparticle(fx_slugwake,0,gactorpos,gactorine,-1);
				vector(_set,gactorpos,0,80,0);
				spawnparticle(fx_slugwake,0,gactorpos,gactorine,-1);
				vector(_set,gactorpos,0,100,0);
				spawnparticle(fx_slugwake,0,gactorpos,gactorine,-1);
				vector(_set,gactorpos,0,120,0);
				spawnparticle(fx_slugwake,0,gactorpos,gactorine,-1);
				vector(_set,gactorpos,0,140,0);
				spawnparticle(fx_slugwake,0,gactorpos,gactorine,-1);
			}


			if(VState!=BulletStateAttachedToActor)
			{
				move(0,75,0);

				call(CheckBulletCollision,-1,DamageNoDamage,true);
				if(VTrigger==_DIRactorBulletcol)
				{
					if(VAIClass==_AIclassHuman)
					{
						call(AttachLockedActor,DamageHarpoon);
						if(VTrigger==_DIRTempFlag)								//Is he not attached to anything beforehand.
						{
							State(_or,BulletStateAttachedToActor);

							sample(SFXFlyThroughAirReact,-1);

/*							if(vrnd<50)
							{
								sample(SFXManBlastHit1,-1);
							}
							else
							{
								sample(SFXManBlastHit2,-1);
							}
*/
							float(_set,localstate,1);

							callsub(Sub_BloodFxSpurtREL);
							callsub(Sub_BloodFx10);
							callsub(Sub_BloodFxSprayREL);
						}
					}
					else
					{
						if(VAICon==0)
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
						}

						State(_or,BulletStateStuckOnFloor);

						sample(SFXShatter,-1);
						//shatter harpoon
						vector(_set,gactorpos,0,0,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
						vector(_set,gactorpos,0,-20,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
						vector(_set,gactorpos,0,-40,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
						vector(_set,gactorpos,0,-60,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
						vector(_set,gactorpos,0,-80,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
						vector(_set,gactorpos,0,-100,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
						vector(_set,gactorpos,0,-120,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
						vector(_set,gactorpos,0,-140,0);
						spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);

						call(KillHarpoonHandler);
					}
				}
			}
			else
			{

				move(0,100,-25);	//change collision line in SAXSact if you change the harpoon speed (currently 110)

				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSprayREL);
			}


			if(VColFlag==_DIRhorcol)
			{
				if(VAICon==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
				}
//	break();
				if(VColMaterialProperties==_MATWater)
				{
					sample(SFXSplosh,-1);
				}
				else
				{
					sample(SFXShatter,-1);
					State(_or,BulletStateStuckOnFloor);

					//shatter harpoon
					vector(_set,gactorpos,0,0,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-20,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-40,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-60,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-80,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-100,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-120,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-140,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);

					call(KillHarpoonHandler);
				}
			}
			elseif(VColFlag==_DIRvercol)
			{
//	break();
				/*
				if(TmpFloat>400||TmpFloat<-400)					//Correct angle when sliding along wall
				{
					if(TmpFloat<0)
					{
						float(_add,TmpFloat,1024);
					}
					else
					{
						float(_sub,TmpFloat,1024);
					}
					turn(0,0,TmpFloat);
				}
				*/

				if(VColMaterialProperties==_MATWater)
				{
					sample(SFXSplosh,-1);
				}
				elseif(VColMaterialProperties==_MATRipple)
				{
					vector(_set,fxvector,0,0,0);
					callsub(sub_shockwave,0,0);
					sample(SFXRipple,-1);

					State(_or,BulletStateStuckOnFloor);
					sample(SFXShatter,-1);

					//shatter harpoon
					vector(_set,gactorpos,0,0,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-20,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-40,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-60,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-80,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-100,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-120,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-140,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);

					call(KillHarpoonHandler);
				}
				elseif(VColMaterialProperties==_MATKFO)
				{
					State(_or,BulletStateStuckOnFloor);
					sample(SFXShatter,-1);

					//shatter harpoon
					vector(_set,gactorpos,0,0,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-20,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-40,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-60,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-80,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-100,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-120,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-140,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);

					call(KillHarpoonHandler);
				}
				elseif(VColMaterialProperties==_MATGlass)
				{
					sample(SFXShatter,-1);
					State(_or,BulletStateStuckOnFloor);

					//shatter harpoon
					vector(_set,gactorpos,0,0,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-20,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-40,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-60,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-80,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-100,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
					vector(_set,gactorpos,0,-120,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
					vector(_set,gactorpos,0,-140,0);
					spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);

					call(KillHarpoonHandler);
				}
				else
				{
					sample(SFXHarpoonHitWall,-1);
					if(VState==BulletStateAttachedToActor)
					{
						sample(SFXHarpoonHitActor,-1);
					}
					State(_or,BulletStateStuckInWall);
					call(AttachToColObjHeader);			//use this to tell the Bullet/actor what it's attached to, not needed for goo
					spawnaction(nomove);
				}

				vector(_settoactorpos,tmpvector);
				call(CheckForDynamicCollision,0);
				if(VAICon==0)
				{
					if(VDynamicCollision==0)
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
					}
					else
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
					}
				}

				if(VDynamicCollision|=_ExplodeGlass)
				{
					sample(SFXGlass,tmpvector);			//attached gets removed!

					if(VDynamicCollision|=_ExplodeSmall)
					{
						spawnparticle(fx_smallexplosion,-1,tmpvector,emptyvector,-1);
					}
				}
			}
			else
			{

				if(Vactivetime>150)
				{
					float(_set,localstate,0);
					call(KillHarpoonHandler);
				}
			}
		}
/*
		if(Vstate==BulletStateStuckOnFloor)
		{
			call(CheckAttached,_CADropActor);
		}
		else
*/
		if(Vstate!=BulletStateStuckOnFloor)
		{
			call(CheckAttached,_CANormal);
		}

		if(VState==BulletStateAttachedToActor&&VState==BulletStateStuckInWall&&blooddriptime==0)
		{																					
			//callsub(Sub_BloodFxSpray);
			float(_set,blooddriptime,1);
		}

		if(localstate==0)
		{
			if(Vactivetime>900)			//30 seconds
			{
				//shatter harpoon
				sample(SFXShatter,-1);
				vector(_set,gactorpos,0,0,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
				vector(_set,gactorpos,0,-20,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
				vector(_set,gactorpos,0,-40,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
				vector(_set,gactorpos,0,-60,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
				vector(_set,gactorpos,0,-80,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
				vector(_set,gactorpos,0,-100,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);
				vector(_set,gactorpos,0,-120,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotate);
				vector(_set,gactorpos,0,-140,0);
				spawnparticle(fx_bulletshrapnel,0,gactorpos,emptyvector,fx_madrotatenegative);

				call(KillHarpoonHandler);
			}
		}
}

Actor(BulletMaimer)
{
		file(BulletMaimerHeader);
		startstate(BulletStateNormal);
		startaction(move100);

		call(SetParticleSetID);

		rotate(192,0,0);

		if(VState!=BulletStateStuckInWall && VState!=BulletStateAttachedToActor)
		{
			call(CheckBulletCollision,-1,-1,true);
			call(wUpdateBulletDamage);
			if(VTrigger==_DIRactorBulletcol)
			{
				if(VAIClass==_AIclassHuman)
				{
					//call(CheckBoneCollision,DamageNoDamage,_BulletAttach);
					//if(VTrigger==_DIRactorBulletcol)
					//{
						//State(_or,BulletStateAttachedToActor);
						//spawnaction(nomove);

						callsub(Sub_BloodFxSpurt);
						callsub(Sub_BloodFx5);
						callsub(Sub_BloodFxSpray);
						sample(SFXHitActor7,-1);
					//}
				}
				else
				{
					if(VAICon==0)
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
					}

					//shatter maimstar
					sample(SFXShatter,-1,75);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
				}
				killactor();
			}
			elseif(VTrigger==_DIRhorcol)
			{
				if(VAICon==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
				}

				if(VColMaterialProperties==_MATWater)
				{
					sample(SFXSplosh,-1);
				}
				else
				{
					//shatter maimstar
					sample(SFXShatter,-1,75);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

					killactor();
				}
			}
			elseif(VTrigger==_DIRvercol)
			{
				if(VColMaterialProperties==_MATWater)
				{
					sample(SFXSplosh,-1);
				}
				elseif(VColMaterialProperties==_MATRipple)
				{
					vector(_set,fxvector,0,0,0);
					callsub(sub_shockwave,0,0);
					sample(SFXRipple,-1);

					//shatter maimstar
					sample(SFXShatter,-1,75);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

					killactor();
				}
				elseif(VColMaterialProperties==_MATKFO)
				{
					//shatter maimstar
					sample(SFXShatter,-1,75);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

					killactor();
				}
				elseif(VColMaterialProperties==_MATGlass)
				{
					State(_or,BulletStateStuckInWall);
					call(AttachToColObjHeader);			//use this to tell the Bullet/actor what it's attached to, not needed for goo
					spawnaction(nomove);
					SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
					sample(SFXGlassPlink,-1);
				}
				else
				{
					sample(SFXMachineGunPing0,-1);
					State(_or,BulletStateStuckInWall);
					call(AttachToColObjHeader);			//use this to tell the Bullet/actor what it's attached to, not needed for goo
					spawnaction(nomove);
					SpawnGooFX(fx_Bulletholecrack,0,EmptyVector,emptyvector,0);
				}

				vector(_settoactorpos,tmpvector);
				call(CheckForDynamicCollision,4);
				if(VAICon==0)
				{
					if(VDynamicCollision==0)
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
					}
					else
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
					}
				}

				if(VDynamicCollision|=_ExplodeGlass)
				{
					sample(SFXGlass,tmpvector);			//attached gets removed!

					if(VDynamicCollision|=_ExplodeSmall)
					{
						spawnparticle(fx_smallexplosion,-1,tmpvector,emptyvector,-1);
					}
				}
			}
			elseif(vactivetime>=150)
			{
				killactor();
			}
		}
		else
		{
			rotate(0,0,0);
			if(Vactivetime>900)			//30 seconds
			{
				//shatter maimstar
				//sample(SFXShatter,-1,75);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

				killactor();
			}
		}
}



Actor(BulletBetty)
{
		file(BulletBettyHeader);
		startstate(BulletStateNormal);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,localSin,0);
		float(_declare,localCos,0);

		if(vactivetime==0)
		{
			float(_set,localSin,BettySinAngle);
			float(_set,localCos,BettyCosAngle);
		}
		move(localSin,0,localCos);
		rotate(0,192,0);

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx5);
				callsub(Sub_BloodFxSpray);
				sample(SFXHitActor7,-1);
			}
			//else
			//{
				sample(SFXShatter,-1,75);

				//shatter maimbett
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

				killactor();
			//}
		}
		elseif(VTrigger==_DIRhorcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				sample(SFXShatter,-1,75);

				//shatter maimbett
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

				killactor();
			}
		}
		elseif(VTrigger==_DIRvercol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				if(VColMaterialProperties==_MATRipple)
				{
					vector(_set,fxvector,0,0,0);
					callsub(sub_shockwave,0,0);
					sample(SFXRipple,-1);

					//shatter maimbett
					sample(SFXShatter,-1,75);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

					killactor();
				}
				elseif(VColMaterialProperties==_MATKFO)
				{
					//shatter maimbett
					sample(SFXShatter,-1,75);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
					spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);

					killactor();
				}
				elseif(VColMaterialProperties==_MATGlass)
				{
					SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
					sample(SFXGlassPlink,-1);
				}
				else
				{
					sample(SFXMachineGunPing0,-1);
					SpawnGooFX(fx_Bulletholecrack,0,EmptyVector,emptyvector,0);
				}

				vector(_settoactorpos,tmpvector);
				call(CheckForDynamicCollision,4);
				if(VDynamicCollision|=_ExplodeGlass)
				{
					sample(SFXGlass,tmpvector);			//attached gets removed!

					if(VDynamicCollision|=_ExplodeSmall)
					{
						spawnparticle(fx_smallexplosion,-1,tmpvector,emptyvector,-1);
					}
				}

				//shatter maimbett
				//sample(SFXShatter,-1,75);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotatenegative);
				spawnparticle(fx_bulletshrapnel,0,emptyvector,emptyvector,fx_madrotate);
				killactor();
			}
		}
		elseif(vactivetime>=150)
		{
			killactor();
		}
}



//---------------------------------------------------------------------------- shells

Actor(MachineGunShell)
{
		file(BulletMachineGunShellHeader);
		startstate(BulletStateNormal);
		startaction(movePumpGunshell);

		call(SetParticleSetID);

		if(VState!=BulletStateStuckOnFloor)
		{
			if(VTrigger|=_DIRallcol)
			{
				State(_or,BulletStateStuckOnFloor);

				sample(SFXPumpGunShell,-1);
				killactor();
			}
		}

		callsub(Sub_BulletHandler5);
}

Actor(PumpGunShell)
{
		file(BulletPumpGunShellHeader);
		startstate(BulletStateNormal);
		startaction(movePumpGunshell);

		call(SetParticleSetID);

		if(VState!=BulletStateStuckOnFloor)
		{
			if(VTrigger|=_DIRallcol)
			{
				State(_or,BulletStateStuckOnFloor);

				sample(SFXPumpGunShell,-1);
			}
		}

		callsub(Sub_BulletHandler15);
}


//---------------------------------------------------------------------------- gaseous bullets

Actor(BulletBuzzSaw)
{
		file(BulletBuzzSawHeader);
		startstate(BulletStateNormal);
		startaction(move5);

		call(SetParticleSetID);

		call(CheckBulletCollision,-1,DamageBuzzSaw,true);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFx5);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
				sample(SFXBuzzSawGrinder,-1);
			}

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			vector(_set,gactorpos,0,-20,0);
			sample(SFXBuzzSawGrinder,-1);
			vector(_set,tmpvector,192,192,255);
			SpawnLight(fire_light,0,gactorpos,tmpvector,EmptyVector,300);
			if(vrnd<50)
			{
				spawnparticle(fx_torchsparks,0,emptyvector,emptyvector,-1);//fx_buzzsawsparks);
			}
			killactor();
		}

		if(Vactivetime>10)
		{
			killactor();
		}
}
 
Actor(BulletFlameThrower)
{
		file(BulletFlameThrowerHeader);
		startstate(BulletStateNormal);
		startaction(move15);

		call(SetParticleSetID);

		call(CheckBulletCollision,-1,DamageNoDamage,true);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				CheckActorCollision(0,emptyVector,80,0,_COLfire,DamageNoDamage)
				if(VCoreAICon==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
				}
			}
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(vrnd<50)
			{
				spawnparticle(fx_weaponsmoke,0,emptyvector,emptyvector,fx_flamethrowsmoke);
			}

			vector(_set,tmpvector,-32,-32,-32);
			vector(_set,gactorpos,0,-20,0);
			SpawnLight(perm_light,0,gactorpos,tmpvector,EmptyVector,350);
			killactor();
		}

		if(Vactivetime>20)
		{
			killactor();
		}
}

Actor(BulletTorch)
{
		file(BulletTorchHeader);
		startstate(BulletStateNormal);
		startaction(move2);

		call(SetParticleSetID);

		call(CheckBulletCollision,-1,DamageNoDamage,true);
		if(VTrigger==_DIRactorBulletcol)
		{
			//crap weapon , does no damage
			/*
			if(VAIClass==_AIclassHuman)
			{
				//callsub(Sub_BloodFxSpray);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
			}
			*/
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			vector(_set,gactorpos,0,-20,0);
			vector(_set,tmpvector,64,64,255);
			SpawnLight(fire_light,0,gactorpos,tmpvector,EmptyVector,300);
			if(vrnd<50)
			{
				spawnparticle(fx_torchsparks,0,emptyvector,emptyvector,-1);
			}
			killactor();
		}

		if(vactivetime>10)
		{
			killactor();
		}
}

//---------------------------------------------------------------------------- regular bullets

Actor(BulletPAK)
{
		file(BulletPAKGunHeader);
		startstate(BulletStateNormal);
		startaction(move150);

		call(SetParticleSetID);

		float(_declare,hitwall,0);

		rotate(0,0,0);

		if(VState!=BulletStateAttachedToActor)
		{
			if(hitwall==0)
			{
				call(CheckBulletCollision,-1,-1,true);
				call(wUpdateBulletDamage);
				if(VTrigger==_DIRactorBulletcol)
				{
					if(VAIClass==_AIclassHuman)
					{
						//call(CheckBoneCollision,DamageNoDamage,_BulletAttach);
						//if(VTrigger==_DIRactorBulletcol)
						//{
							call(ChangeRelativeSpeed);

							//State(_or,BulletStateAttachedToActor);
						//}
					}
					spawnaction(nomove);
					sample(SFXPAKHit,-1);

					float(_set,hitwall,1);
				}
				elseif(VTrigger|=_DIRallcol)
				{
					sample(SFXPAKHit,-1);
					if(VTrigger==_DIRhorcol)
					{
						killactor();
					}
					else
					{
						spawnaction(nomove);
						if(VColMaterialProperties==_MATRipple)
						{
							vector(_set,fxvector,0,0,0);
							callsub(sub_shockwave,0,0);
							sample(SFXRipple,-1);
						}
						if(VColMaterialProperties==_MATKFO)
						{
							killactor();
						}

						vector(_settoactorpos,tmpvector);
						call(CheckForDynamicCollision,4);
						if(VCoreAICon==0)
						{
							if(VDynamicCollision==0)
							{
								call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
							}
							else
							{
								call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
							}
						}

						if(VDynamicCollision|=_ExplodeGlass)
						{
							sample(SFXGlass,tmpvector);			//attached gets removed!
						}

						float(_set,hitwall,1);
					}
				}

				if(VState!=BulletStateAttachedToActor&&hitwall==0)
				{
					vector(_set,gactorpos,0,100,0);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					//fake some bullets
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);

					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setz,gactorpos,tmpfloat);
					spawnparticle(fx_paktracer,0,gactorpos,emptyvector,-1);
				}
			}

			//fx
			//smoke falling down
			if(hitwall==1)
			{
				if(vrnd<50)
				{
					//if(vrnd<50)
					//{
						vector(_set,gactorpos,0,0,0);
						float(_rnd2,tmpfloat,32);
						float(_sub,tmpfloat,16);
						vector(_setx,gactorpos,tmpfloat);
						spawnparticle(fx_icesmoke,0,gactorpos,emptyvector,fx_icesteam);
					//}
					//else
					//{
						float(_rnd2,tmpfloat,32);
						float(_sub,tmpfloat,16);
						vector(_setx,gactorpos,tmpfloat);
						spawnparticle(fx_icesmoke,0,gactorpos,emptyvector,-1);
					//}
				}
			}

			if(vactivetime>=60)			//3 seconds
			{
				killactor();
			}
		}
		else
		{
			//fx
			//smoke falling down
			if(vrnd<50)
			{
				//if(vrnd<50)
				//{
					vector(_set,gactorpos,0,0,0);
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					spawnparticle(fx_icesmoke,0,gactorpos,emptyvector,-1);
				//}
				//else
				//{
					float(_rnd2,tmpfloat,32);
					float(_sub,tmpfloat,16);
					vector(_setx,gactorpos,tmpfloat);
					spawnparticle(fx_icesmoke,0,gactorpos,emptyvector,fx_icesteam);
				//}
			}

			rotate(0,0,0);
			if(Vactivetime>60)			//3 seconds
			{
				killactor();
			}
		}
}




//the main pumpgun bullet
Actor(BulletPumpGun)
{
		file(BulletPumpGunHeader);
		startstate(BulletStateNormal);
		startaction(move300);

		call(SetParticleSetID);

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx10);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
				callSub(sub_RiccoMetal);
			}

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				if(VColMaterialProperties==_MATRipple)
				{
					vector(_set,fxvector,0,0,0);
					callsub(sub_shockwave,0,0);
					sample(SFXRipple,-1);
					killactor();
				}
				else
				{
					vector(_settoactorpos,tmpvector);
					call(CheckForDynamicCollision,4);
					if(VCoreAICon==0)
					{
						if(VDynamicCollision==0)
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
						}
						else
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
						}
					}

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
						vector(_settocolobjpos,TmpVector2);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

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

						vector(_copy,tmpvector,TmpVector2);
						callsub(sub_fxexplosion);
					}
					else
					{
						if(VColMaterialProperties==_MATWood)
						{
							if(VColMaterialProperties!=_MATKFO)
							{
								SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
							}
							callSub(sub_RiccoWood);
						}
						elseif(VColMaterialProperties==_MATMetal)
						{
							// / _MATSheetMetal
							if(VColMaterialProperties!=_MATKFO)
							{
								SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
							}
							callSub(sub_RiccoMetal);
						}
						elseif(VColMaterialProperties==_MATSheetMetal)
						{
							if(VColMaterialProperties!=_MATKFO)
							{
								SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
							}
							callSub(sub_RiccoMetal);
						}
						else // _MATConcrete
						{
							if(VColMaterialProperties!=_MATKFO)
							{
								SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
							}
							callSub(sub_RiccoConcrete);
						}

						spawnparticle(fx_impactpuff,0,emptyvector,emptyvector,-1);
						spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
					}

					killactor();
				}
			}
		}

		callsub(Sub_BulletHandler5);
}


//secondary pumpgun bullets
Actor(BulletPumpGunSecondary)
{
		file(BulletPumpGunHeader2);
		startstate(BulletStateNormal);
		startaction(move300);

		call(SetParticleSetID);

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
				}
				spawnparticle(fx_impactpuff,0,emptyvector,emptyvector,-1);
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);

				killactor();
			}
		}

		callsub(Sub_BulletHandler5);
}



Actor(BulletSubGirlMachineGun)
{
		file(BulletSubGirlMachineGunHeader);
		startstate(BulletStateNormal);
		startaction(move200);

		call(SetParticleSetID);

		float(_declare,MachineGunRebound,0);

		if(vactivetime==0)
		{
			vector(_set,gactorpos,0,100,0);
			vector(_set,gactorine,0,200,0);
			spawnparticle(fx_tracer,0,gactorpos,gactorine,fx_subgirltracer);
		}

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);

				callSub(sub_RiccoMetal);
			}

			float(_set,MachineGunRebound,0);
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			//if(MachineGunRebound==0)
			//{
				float(_set,MachineGunRebound,1);
				if(VColMaterialProperties==_MATRipple)
				{
					vector(_set,fxvector,0,0,0);
					callsub(sub_shockwave,0,0);
					sample(SFXRipple,-1);
				}
				elseif(VColMaterialProperties==_MATGlass)
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
					}
					sample(SFXGlass,-1);
				}
				elseif(VColMaterialProperties==_MATWood)
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
					}
					callSub(sub_RiccoWood);
				}
				elseif(VColMaterialProperties==_MATConcrete)
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
					}
					callSub(sub_RiccoConcrete);
				}
				else	//_MATMetal / _MATSheetMetal
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
					}
					callSub(sub_RiccoMetal);
				}


				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);


				vector(_settoactorpos,tmpvector);
				call(CheckForDynamicCollision,4);
				if(VCoreAICon==0)
				{
					if(VDynamicCollision==0)
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
					}
					else
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
					}
				}

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
					vector(_settocolobjpos,TmpVector2);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

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

					vector(_copy,tmpvector,TmpVector2);
					callsub(sub_fxexplosion);
				}
			//}
			//else
			//{
				float(_set,MachineGunRebound,0);
				killactor();
			//}
		}
		elseif(Vactivetime>=150)
		{
			float(_set,MachineGunRebound,0);
			killactor();
		}

		callsub(Sub_BulletHandler5);
}


Actor(BulletABeastMachineGun)
{
		file(BulletABeastMachineGunHeader);
		startstate(BulletStateNormal);
		startaction(move200);

		call(SetParticleSetID);

		float(_declare,MachineGunRebound,0);

		spawnparticle(fx_gunbulletbeast,0,emptyvector,emptyvector,fx_gunbulhorizbeast,false);
		spawnparticle(fx_gunbulletbeast,0,emptyvector,emptyvector,fx_gunbulvertbeast,false);
		spawnparticle(fx_gunbulletbeast,0,emptyvector,emptyvector,fx_gunbuldiag1beast,false);
		spawnparticle(fx_gunbulletbeast,0,emptyvector,emptyvector,fx_gunbuldiag2beast,false);

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);

				callSub(sub_RiccoMetal);
			}

			float(_set,MachineGunRebound,0);
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			//if(MachineGunRebound==0)
			//{
				float(_set,MachineGunRebound,1);
				if(VColMaterialProperties==_MATRipple)
				{
					vector(_set,fxvector,0,0,0);
					callsub(sub_shockwave,0,0);
					sample(SFXRipple,-1);
				}
				elseif(VColMaterialProperties==_MATGlass)
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
					}
					sample(SFXGlass,-1);
				}
				elseif(VColMaterialProperties==_MATWood)
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
					}
					callSub(sub_RiccoWood);
				}
				elseif(VColMaterialProperties==_MATConcrete)
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
					}
					callSub(sub_RiccoConcrete);
				}
				else	//_MATMetal / _MATSheetMetal
				{
					if(VColMaterialProperties!=_MATKFO)
					{
						SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
					}
					callSub(sub_RiccoMetal);
				}


				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);


				vector(_settoactorpos,tmpvector);
				call(CheckForDynamicCollision,4);
				if(VCoreAICon==0)
				{
					if(VDynamicCollision==0)
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
					}
					else
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
					}
				}

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
					vector(_settocolobjpos,TmpVector2);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

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

					vector(_copy,tmpvector,TmpVector2);
					callsub(sub_fxexplosion);
				}
			//}
			//else
			//{
				float(_set,MachineGunRebound,0);
				killactor();
			//}
		}
		elseif(Vactivetime>=150)
		{
			float(_set,MachineGunRebound,0);
			killactor();
		}

		callsub(Sub_BulletHandler5);
}



Actor(BulletMachineGun)
{
		file(BulletMachineGunHeader);
		startstate(BulletStateNormal);
		startaction(move200);

		call(SetParticleSetID);

		float(_declare,MachineGunRebound,0);

		if(vactivetime==0)
		{
			vector(_set,gactorpos,0,100,0);
			vector(_set,gactorine,0,200,0);
			spawnparticle(fx_tracer,0,gactorpos,gactorine,-1);
		}

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);

				callSub(sub_RiccoMetal);
			}

			float(_set,MachineGunRebound,0);
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				//if(MachineGunRebound==0)
				//{
					float(_set,MachineGunRebound,1);
					if(VColMaterialProperties==_MATRipple)
					{
						vector(_set,fxvector,0,0,0);
						callsub(sub_shockwave,0,0);
						sample(SFXRipple,-1);
					}
					elseif(VColMaterialProperties==_MATGlass)
					{
						if(VColMaterialProperties!=_MATKFO)
						{
							SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
						}
						sample(SFXGlass,-1);
					}
					elseif(VColMaterialProperties==_MATWood)
					{
						if(VColMaterialProperties!=_MATKFO)
						{
							SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
						}
						callSub(sub_RiccoWood);
					}
					elseif(VColMaterialProperties==_MATConcrete)
					{
						if(VColMaterialProperties!=_MATKFO)
						{
							SpawnGooFX(fx_Bullethole,0,EmptyVector,emptyvector,0);
						}
						callSub(sub_RiccoConcrete);
					}
					else	//_MATMetal / _MATSheetMetal
					{
						if(VColMaterialProperties!=_MATKFO)
						{
							SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
						}
						callSub(sub_RiccoMetal);
					}


					spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);


					vector(_settoactorpos,tmpvector);
					call(CheckForDynamicCollision,4);
					if(VCoreAICon==0)
					{
						if(VDynamicCollision==0)
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
						}
						else
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
						}
					}

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
						vector(_settocolobjpos,TmpVector2);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

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

						vector(_copy,tmpvector,TmpVector2);
						callsub(sub_fxexplosion);
					}
				//}
				//else
				//{
					float(_set,MachineGunRebound,0);
					killactor();
				//}
			}
		}
		elseif(Vactivetime>=150)
		{
			float(_set,MachineGunRebound,0);
			killactor();
		}

		callsub(Sub_BulletHandler5);
}

Actor(BulletBazooka)
{
		file(BulletBazookaHeader);
		startstate(BulletStateNormal);
		startaction(move100);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			sample(SFXBazookaFly,-1);
		}

		float(_declare,baz_flipflop,0);
		if(baz_flipflop==0)
		{
			if(VSniperModeGlobal==0)
			{
				spawnparticle(fx_bazookatrail,0,emptyvector,emptyvector,fx_antirotate16);
			}
			float(_set,baz_flipflop,1);
		}
		else
		{
			spawnparticle(fx_bazookatrail,0,emptyvector,emptyvector,-1);
			float(_set,baz_flipflop,0);
		}


		//type,bone,pos,color,vector,radius
		vector(_set,tmpvector,255,0,0);
		SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,400);

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			vector(_settoactorpos,tmpvector);
			vector(_copyx,tmpvector,TmpFloat2);
			vector(_copyy,tmpvector,TmpFloat3);
			vector(_copyz,tmpvector,TmpFloat4);

			callsub(sub_fxexplosion);

			if(VAIClass==_AIclassHuman)
			{
				callsub(Sub_BloodFx10);
			}

			sample(SFXBazookaExplode,-1);

			spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				sample(SFXBazookaExplode,-1);
				vector(_settoactorpos,tmpvector);
				callsub(sub_fxexplosion);

				call(CheckForDynamicCollision,0);
				if(VCoreAICon==0)
				{
					if(VDynamicCollision==0)
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
					}
					else
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
					}
				}

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
					vector(_settocolobjpos,TmpVector2);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

					if(VDynamicCollision|=_ExplodeAmmo)
					{
						spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}
					elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
					{
						spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}

					spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				else
				{
					vector(_copy,TmpVector2,tmpvector);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

					spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				killactor();
			}
		}

		callsub(Sub_BulletHandler15);
}


//make sure you have called SetParticleSetID before the flares, or else!!!
subroutine(flare3drandom)
{
		vector(_set,tmpvector2,8,0,8);
		float(_rnd,tmpfloat,4096);
		vector(_vectorfromangle,tmpvector,tmpfloat,1);
		vector(_copy,tmpvector3,tmpvector);
		vector(_normalize,tmpvector);
		vector(_mul,tmpvector,tmpvector2);
		vector(_set,tmpvector2,0,-8,0);					//towards camera
		vector(_add,tmpvector,tmpvector2);
		spawn3dflare(16,255,64,32,tmpvector3,tmpvector);
}


Actor(BulletMaser)
{
		file(BulletMaserHeader);
		startstate(BulletStateNormal);
		startaction(move50);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			vector(_set,gactorine,0,50,0);
			spawn3dflare(16,255,64,128,emptyvector,gactorine);
			spawnparticle(fx_maserstrip,0,emptyvector,gactorine,fx_maserstriph);
			spawnparticle(fx_maserstrip,0,emptyvector,gactorine,fx_maserstripv);
			spawnparticle(fx_maserstrip,0,emptyvector,gactorine,fx_maserstripd1);
			spawnparticle(fx_maserstrip,0,emptyvector,gactorine,fx_maserstriphd2);
		}

		if(PlasmaWallExplode==0)
		{
			if(VCurSet=="walls1" || VCurSet=="AIRW2-W1")
			{
				CurEnvTriggerSet("walls1","plasma");
				call(ActivateTrigger);
				if(VTrigger==_DIREnvTrigger)
				{
					float(_set,PlasmaWallExplode,1);

					vector(_set,tmpvector,32,255,128);
					SpawnLight(toruslight2,0,EmptyVector,tmpvector,EmptyVector,1000);

					sample(SFXRipple2,-1);

					callsub(flare3drandom);
					callsub(flare3drandom);
					callsub(flare3drandom);
					callsub(flare3drandom);
					callsub(flare3drandom);
					callsub(flare3drandom);

					call(CheckForDynamicCollision,32767);	//never effects background stuff, coz it's electricicty right!?!
					if(VCoreAICon==0)
					{
						if(VDynamicCollision==0)
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
						}
						else
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
						}
					}
					killactor();
				}
				else
				{
					CurEnvTriggerSet("walls1","plasma01");
					call(ActivateTrigger);
					if(VTrigger==_DIREnvTrigger)
					{
						float(_set,PlasmaWallExplode,1);

						vector(_set,tmpvector,32,255,128);
						SpawnLight(toruslight2,0,EmptyVector,tmpvector,EmptyVector,1000);

						sample(SFXRipple2,-1);

						callsub(flare3drandom);
						callsub(flare3drandom);
						callsub(flare3drandom);
						callsub(flare3drandom);
						callsub(flare3drandom);
						callsub(flare3drandom);

						call(CheckForDynamicCollision,32767);	//never effects background stuff, coz it's electricicty right!?!
						if(VCoreAICon==0)
						{
							if(VDynamicCollision==0)
							{
								call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
							}
							else
							{
								call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
							}
						}
						killactor();
					}
				}
			}
		}


		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
			}
			vector(_set,tmpvector,32,255,128);
			SpawnLight(toruslight2,0,EmptyVector,tmpvector,EmptyVector,1000);

			sample(SFXRipple2,-1);

			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				vector(_set,tmpvector,32,255,128);
				SpawnLight(toruslight2,0,EmptyVector,tmpvector,EmptyVector,1000);

				sample(SFXRipple2,-1);

				vector(_settoactorpos,tmpvector);
				call(CheckForDynamicCollision,0);
				if(VCoreAICon==0)
				{
					if(VDynamicCollision==0)
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
					}
					else
					{
						call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
					}
				}

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
					vector(_settocolobjpos,TmpVector2);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

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

					vector(_copy,tmpvector,TmpVector2);
					callsub(sub_fxexplosion);
				}

				callsub(flare3drandom);
				callsub(flare3drandom);
				callsub(flare3drandom);
				callsub(flare3drandom);
				callsub(flare3drandom);
				callsub(flare3drandom);

				killactor();
			}
		}
		else
		{
			vector(_set,tmpvector,16,255,64);
			SpawnLight(toruslight,0,EmptyVector,tmpvector,EmptyVector,600);
		}

		call(WallBulb,1000);

		if(vactivetime>128)
		{
			vector(_set,tmpvector,32,255,128);
			SpawnLight(toruslight2,0,EmptyVector,tmpvector,EmptyVector,1000);

			sample(SFXRipple2,-1);

			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);
			callsub(flare3drandom);

			killactor();
		}

		callsub(Sub_BulletHandler15);
}





//---------------------------------------------------------------------------- grenade bullets



Actor(BulletGrenadeSubGirl)
{
		file(BulletSubGirlGrenadeHeader);
		startstate(BulletStateNormal);
		startaction(MoveSubGirlGrenade);

		call(SetParticleSetID);

		spawnparticle(fx_trailoffire,0,emptyvector,emptyvector,-1);

		vector(_set,tmpvector,255,255,255);
		SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,300);

		call(CheckBulletCollision,-1,DamageGrenade,true);
		if(VTrigger==_DIRactorBulletcol)
		{
			vector(_settoactorpos,tmpvector);
			vector(_copyx,tmpvector,TmpFloat2);
			vector(_copyy,tmpvector,TmpFloat3);
			vector(_copyz,tmpvector,TmpFloat4);

			callsub(sub_fxexplosion);

			if(VAIClass==_AIclassHuman)
			{
				callsub(Sub_BloodFx10);
			}

			sample(SFXGrenadeExplode,-1);

			spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			sample(SFXGrenadeExplode,-1);

			vector(_settoactorpos,tmpvector);
			callsub(sub_fxexplosion);

			call(CheckForDynamicCollision,0);
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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				if(VDynamicCollision|=_ExplodeAmmo)
				{
					spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
				{
					spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}
			else
			{
				vector(_copy,TmpVector2,tmpvector);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}

			killactor();
		}
		elseif(Vactivetime>90)
		{
			sample(SFXGrenadeExplode,-1);

			vector(_settoactorpos,tmpvector);
			callsub(sub_fxexplosion);

			call(CheckForDynamicCollision,0);
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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				if(VDynamicCollision|=_ExplodeAmmo)
				{
					spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
				{
					spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}
			else
			{
				vector(_copy,TmpVector2,tmpvector);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}

			killactor();
		}

		callsub(Sub_BulletHandler5);
}




Actor(BulletGrenadeJumpBetty)
{
		file(BulletGrenadeJumpBettyHeader);
		startstate(BulletStateNormal);
		startaction(MoveThrownGrenade);

		call(SetParticleSetID);

		float(_declare,jumpbettyjump,0);
		float(_declare,jumpbettytime,0);
		float(_declare,jumpbettytimelift,0);
		float(_declare,grenadelastcoll,0);
		float(_declare,GrenadeTimer0,90);
		float(_declare,GrenadeTimer1,0);
		float(_declare,BettyAngle,0);
		float(_declare,BettyAddAngle,1024);

		float(_set,AlertTrigger,JumpingBettyActive);

		if(vactivetime>=GrenadeTimer1)
		{
			sample(SFXGrenadeTimer,-1);
			float(_div,GrenadeTimer0,2);
			float(_add,Grenadetimer1,GrenadeTimer0);
		}
		else
		{
			float(_sub,GrenadeTimer0,1);
			if(GrenadeTimer0<=0)
			{
				vector(_set,tmpvector,255,255,255);
				SpawnLight(LightBlinkFade,0,EmptyVector,tmpvector,EmptyVector,300);

				sample(SFXLowOnAmmo,-1);
				//sample(SFXLowOnHealth,-1);
				float(_set,GrenadeTimer0,90);
			}
		}

		if(jumpbettyjump==0)
		{
			call(CheckBulletCollision,-1,DamageNoDamage,false);
			if(VTrigger|=_DIRallcol)
			{
				if(VColMaterialProperties==_MATWater)
				{
					sample(SFXSplosh,-1);
				}
				else
				{
					if(VColMaterialProperties==_MATRipple)
					{
						vector(_set,fxvector,0,0,0);
						callsub(sub_shockwave,0,0);
						sample(SFXRipple,-1);
					}
					elseif(VColMaterialProperties==_MATGlass)
					{
						if(VColMaterialProperties!=_MATKFO)
						{
							SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
						}
						sample(SFXGlassPlink,-1);
					}
					else
					{
						if(grenadelastcoll!=1)
						{
							sample(SFXGrenadeBounce,-1);
						}
					}
					float(_set,grenadelastcoll,1);

					//3 seconds after she lands, she blows ....if someone is within 5feet that is =)
					if(vactivetime>90)
					{
						//wait for it ...wait for it ....
						call(SearchForCloseActor,_AIclassmale|_AIclassfemale|_AIclassangel,512);
						if(VTrigger==_DIRTempFlag)
						{
							float(_set,jumpbettyjump,1);

							//play pitcher sample again ...manic warning -- she's about to blow
							float(_set,GrenadeTimer0,90);
							float(_set,GrenadeTimer1,0);
							float(_seti,jumpbettytimelift,vactivetime);
							float(_add,jumpbettytimelift,20);
							float(_seti,jumpbettytime,vactivetime);
							float(_add,jumpbettytime,110);
						}
						else
						{
							SpawnAction(MoveThrownGrenadeWithSound);

							//don't play the pitcher sample anymore
							float(_seti,GrenadeTimer1,vactivetime);
							float(_add,GrenadeTimer1,2);
						}
					}
				}
			}
			elseif(Vactivetime>450)
			{
				//time out -- should it fall out the level or something horrid like that!
				float(_set,grenadelastcoll,0);
				float(_set,GrenadeTimer0,90);
				float(_set,GrenadeTimer1,0);
				float(_set,jumpbettyjump,0);

				float(_set,AlertTrigger,JumpingBettyInActive);

				killactor();
			}
			else
			{
				float(_set,grenadelastcoll,0);
			}
		}


		//ladies and gentlemen Betty will now jump ...taadaa
		if(jumpbettyjump==1)
		{
			rotate(0,192,0);
			gravity(-1,-25);

			//jumping betty ...she jumps :
			if(vactivetime>=jumpbettytimelift)
			{
				vector(_settoactorpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				float(_sin,BettySinAngle,BettyAngle);
				float(_cos,BettyCosAngle,BettyAngle);
				float(_mul,BettySinAngle,100);
				float(_mul,BettyCosAngle,100);
				float(_add,BettyAngle,BettyAddAngle);
				float(_add,BettyAddAngle,10);
				float(_and,BettyAddAngle,4095);
				spawnactor(BulletBetty,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
/*
				if(VTrigger==_DIRBulletFired)
				{
					sample(SFXMaimerFire,-1);
				}
*/
			}

			if(vactivetime>=jumpbettytime)
			{
				//test for looksy!!
				sample(SFXJumpBettyGrenade,-1);
				vector(_settoactorpos,tmpvector);
				callsub(sub_fxsmallexplosion);

				float(_set,grenadelastcoll,0);
				float(_set,GrenadeTimer0,90);
				float(_set,GrenadeTimer1,0);
				float(_set,jumpbettyjump,0);

				float(_set,AlertTrigger,JumpingBettyInActive);

				killactor();
			}
		}


		//after 30 seconds, we kill it anyway, can't have too many of these blighters lying around!
		if(Vactivetime>900)
		{
			sample(SFXJumpBettyGrenade,-1);
			vector(_settoactorpos,tmpvector);
			callsub(sub_fxsmallexplosion);
			float(_set,grenadelastcoll,0);
			float(_set,GrenadeTimer0,90);
			float(_set,GrenadeTimer1,0);
			float(_set,jumpbettyjump,0);

			float(_set,AlertTrigger,JumpingBettyInActive);

			killactor();
		}
}

//with a 3 second timer
Actor(BulletGrenade)
{
		file(BulletGrenadeHeader);
		startstate(BulletStateNormal);
		startaction(MoveThrownGrenade);

		call(SetParticleSetID);

		float(_declare,grenadelastcoll,0);

		if(grenadelastcoll==0)
		{
			rotate(-128,0,128);
		}

		float(_declare,GrenadeTimer0,90);
		float(_declare,GrenadeTimer1,0);

		if(vactivetime>=GrenadeTimer1)
		{
			sample(SFXGrenadeTimer,-1);
			float(_div,GrenadeTimer0,2);
			float(_add,Grenadetimer1,GrenadeTimer0);
		}

		vector(_set,tmpvector,255,255,255);
		SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,300);

		call(CheckBulletCollision,-1,DamageGrenade,false);
		//call(CheckBulletCollision,-1,-1,false);
		//call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			float(_set,grenadelastcoll,0);
			//if(Vactivetime>90)
			//{
				vector(_settoactorpos,tmpvector);
				vector(_copyx,tmpvector,TmpFloat2);
				vector(_copyy,tmpvector,TmpFloat3);
				vector(_copyz,tmpvector,TmpFloat4);

				sample(SFXGrenadeExplode,-1);

				callsub(sub_fxexplosion);

				if(VAIClass==_AIclassHuman)
				{
					callsub(Sub_BloodFx10);
				}

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);

				float(_set,GrenadeTimer0,90);
				float(_set,GrenadeTimer1,0);

				killactor();
			//}
			//else
			//{
			//	callsub(Sub_BloodFxSpray);
			//	sample(SFXHitActor7,-1);
			//}
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(Vactivetime>90)
			{
				sample(SFXGrenadeExplode,-1);

				vector(_settoactorpos,tmpvector);
				callsub(sub_fxexplosion);

				call(CheckForDynamicCollision,0);
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
					vector(_settocolobjpos,TmpVector2);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

					if(VDynamicCollision|=_ExplodeAmmo)
					{
						spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}
					elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
					{
						spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}

					spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				else
				{
					vector(_copy,TmpVector2,tmpvector);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

					spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				float(_set,grenadelastcoll,0);

				float(_set,GrenadeTimer0,90);
				float(_set,GrenadeTimer1,0);

				killactor();
			}
			else
			{
				if(VColMaterialProperties==_MATWater)
				{
					sample(SFXSplosh,-1);
				}
				else
				{
					if(VColMaterialProperties==_MATRipple)
					{
						vector(_set,fxvector,0,0,0);
						callsub(sub_shockwave,0,0);
						sample(SFXRipple,-1);
					}
					elseif(VColMaterialProperties==_MATGlass)
					{
						if(VColMaterialProperties!=_MATKFO)
						{
							SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
						}
						sample(SFXGlassPlink,-1);
					}
					else
					{
						if(grenadelastcoll!=1)
						{
							sample(SFXGrenadeBounce,-1);
						}
					}
					float(_set,grenadelastcoll,1);
					SpawnAction(MoveThrownGrenadeWithSound);
				}
			}
		}
		elseif(Vactivetime>90)
		{
			float(_set,grenadelastcoll,0);

			sample(SFXGrenadeExplode,-1);

			vector(_settoactorpos,tmpvector);
			callsub(sub_fxexplosion);

			call(CheckForDynamicCollision,0);
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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				if(VDynamicCollision|=_ExplodeAmmo)
				{
					spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
				{
					spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}
			else
			{
				vector(_copy,TmpVector2,tmpvector);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}

			float(_set,GrenadeTimer0,90);
			float(_set,GrenadeTimer1,0);

			killactor();
		}
		else
		{
			if(grenadelastcoll!=0)
			{
				callsub(Sub_BulletHandler5);

				float(_set,GrenadeTimer0,90);
				float(_set,GrenadeTimer1,0);
			}

			float(_set,grenadelastcoll,0);
		}

		callsub(Sub_BulletHandler5);
}


Actor(BulletGrenadeDistortion)
{
		file(BulletDistortionGrenadeHeader);
		startstate(BulletStateNormal);
		startaction(moveDistgrenade);

		call(SetParticleSetID);

		float(_declare,displace,0);

		rotate(-128,0,128);

		vector(_set,tmpvector,-255,-255,-255);
		SpawnLight(darklight,0,EmptyVector,tmpvector,EmptyVector,500);

		if(displace>4)
		{
			float(_set,displace,0);

			vector(_settoactorpos,tmpvector);
			vector(_copyx,tmpvector,TmpFloat2);
			vector(_copyy,tmpvector,TmpFloat3);
			vector(_copyz,tmpvector,TmpFloat4);

			spawnactor(BulletDistortion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
		}
		float(_add,displace,1);

		if(vactivetime==0)
		{
			sample(SFXDistortion,-1);
		}

		call(WallBulb,1000);
		if(Vactivetime>90)
		{
			killactor();
		}
}



Actor(BulletPriest)
{
		file(BulletPriestHeader);
		startstate(BulletStateNormal);
		startaction(move100zpriestbullet);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			sample(SFXBazookaFly,-1);
		}

		float(_declare,baz_flipflop,0);
		if(baz_flipflop==0)
		{
			spawnparticle(fx_bazookatrail,0,emptyvector,emptyvector,fx_priestfx);
			spawnparticle(fx_TurretStrip02,0,emptyvector,emptyvector,fx_gunflashhorizac);
			spawnparticle(fx_TurretStrip02,0,emptyvector,emptyvector,fx_gunflashvertac);
			spawnparticle(fx_TurretStrip02,0,emptyvector,emptyvector,fx_gunflashdiag1ac);
			spawnparticle(fx_TurretStrip02,0,emptyvector,emptyvector,fx_gunflashdiag2ac);
			float(_set,baz_flipflop,1);
		}
		else
		{
			spawnparticle(fx_bazookatrail,0,emptyvector,emptyvector,fx_priestfx2);
			float(_set,baz_flipflop,0);
		}


		//type,bone,pos,color,vector,radius
		vector(_set,tmpvector,0,0,255);
		SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,400);

		call(CheckBulletCollision,-1,-1,true);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			vector(_settoactorpos,tmpvector);
			vector(_copyx,tmpvector,TmpFloat2);
			vector(_copyy,tmpvector,TmpFloat3);
			vector(_copyz,tmpvector,TmpFloat4);

			callsub(sub_fxexplosion);

			if(VAIClass==_AIclassHuman)
			{
				callsub(Sub_BloodFx10);
			}

			sample(SFXBazookaExplode,-1);

			spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			callsub(sub_fxexplosion);

			call(CheckForDynamicCollision,0);
			/*
			if(VCoreAICon==0)
			{
				if(VDynamicCollision==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
				}
				else
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
				}
			}
			*/

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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				if(VDynamicCollision|=_ExplodeAmmo)
				{
					spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
				{
					spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}
			else
			{
				vector(_copy,TmpVector2,tmpvector);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}

			killactor();
		}

		callsub(Sub_BulletHandler5);
}


Actor(BulletGrenadeNoTimer)
{
		file(BulletGrenadeHeader);
		startstate(BulletStateNormal);
		startaction(MoveThrownGrenade);

		call(SetParticleSetID);

		float(_declare,grenadelastcoll,0);

		rotate(-128,0,128);

		//spawnparticle(fx_trailoffire,0,emptyvector,emptyvector,-1);
		//spawnparticle(fx_trailoffire,0,emptyvector,emptyvector,-1);
		spawnparticle(fx_trailoffire,0,emptyvector,emptyvector,-1);

		vector(_set,tmpvector,255,255,255);
		SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,300);

		call(CheckBulletCollision,-1,DamageGrenade,true);
		if(VTrigger==_DIRactorBulletcol)
		{
			float(_set,grenadelastcoll,0);

			vector(_settoactorpos,tmpvector);
			vector(_copyx,tmpvector,TmpFloat2);
			vector(_copyy,tmpvector,TmpFloat3);
			vector(_copyz,tmpvector,TmpFloat4);

			callsub(sub_fxexplosion);

			if(VAIClass==_AIclassHuman)
			{
				callsub(Sub_BloodFx10);
			}

			sample(SFXGrenadeExplode,-1);

			spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				sample(SFXGrenadeExplode,-1);

				vector(_settoactorpos,tmpvector);
				callsub(sub_fxexplosion);

				call(CheckForDynamicCollision,0);
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
					vector(_settocolobjpos,TmpVector2);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

					if(VDynamicCollision|=_ExplodeAmmo)
					{
						spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}
					elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
					{
						spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}

					spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				else
				{
					vector(_copy,TmpVector2,tmpvector);
					vector(_copyx,TmpVector2,TmpFloat2);
					vector(_copyy,TmpVector2,TmpFloat3);
					vector(_copyz,TmpVector2,TmpFloat4);

					spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				SpawnAction(MoveThrownGrenadeWithSound);
				float(_set,grenadelastcoll,0);
				killactor();
			}
		}
		elseif(Vactivetime>90)
		{
			float(_set,grenadelastcoll,0);

			sample(SFXGrenadeExplode,-1);

			vector(_settoactorpos,tmpvector);
			callsub(sub_fxexplosion);

			call(CheckForDynamicCollision,0);
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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				if(VDynamicCollision|=_ExplodeAmmo)
				{
					spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
				{
					spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}
			else
			{
				vector(_copy,TmpVector2,tmpvector);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}

			killactor();
		}
		else
		{
			if(grenadelastcoll!=0)
			{
				callsub(Sub_BulletHandler5);
			}
			float(_set,grenadelastcoll,0);
		}

		callsub(Sub_BulletHandler5);
}


Actor(BulletGrenadeNoTimerSecondary)
{
		file(BulletGrenadeHeader);
		startstate(BulletStateNormal);
		startaction(MoveThrownGrenade);

		call(SetParticleSetID);

		rotate(-128,0,128);

		spawnparticle(fx_trailoffire,0,emptyvector,emptyvector,-1);

		call(CheckBulletCollision,-1,DamageGrenade,true);
		if(VTrigger==_DIRactorBulletcol)
		{
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			SpawnAction(MoveThrownGrenadeWithSound);
			killactor();
		}
		elseif(Vactivetime>90)
		{
			killactor();
		}

		callsub(Sub_BulletHandler5);
}


Actor(BulletGrenadeConcusion)
{
		file(BulletGrenadeConcusionHeader);
		startstate(BulletStateNormal);
		startaction(MoveThrownGrenade);

		call(SetParticleSetID);

		rotate(-128,0,128);

		vector(_set,tmpvector,255,255,255);
		SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,300);

		call(CheckBulletCollision,-1,DamageGrenade,false);
		if(VTrigger==_DIRactorBulletcol)
		{
			call(wCheckViewCollision,0,-1,-1,-1);
			sample(SFXConcussionFlash,-1);
			//sample(SFXConcGrenade,-1);

			spawnparticle(fx_smallexplosion,0,emptyvector,emptyvector,-1);
			//sample(SFXSmallExplode,-1);

			call(SetFlagsOnActiveActors,1000,0,_DUMMY,0,_AFLAGconfused);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATWater)
			{
				sample(SFXSplosh,-1);
			}
			else
			{
				call(wCheckViewCollision,0,-1,-1,-1);
				//sample(SFXConcGrenade,-1);
				sample(SFXConcussionFlash,-1);
	
				spawnparticle(fx_smallexplosion,0,emptyvector,emptyvector,-1);
				//sample(SFXSmallExplode,-1);
	
				call(SetFlagsOnActiveActors,1000,0,_DUMMY,0,_AFLAGconfused);
	
				SpawnAction(MoveThrownGrenadeWithSound);
				killactor();
			}
		}
		elseif(Vactivetime>90)
		{
			call(wCheckViewCollision,0,-1,-1,-1);
			//sample(SFXConcGrenade,-1);
			sample(SFXConcussionFlash,-1);

			spawnparticle(fx_smallexplosion,0,emptyvector,emptyvector,-1);
			//sample(SFXSmallExplode,-1);

			call(SetFlagsOnActiveActors,1000,0,_DUMMY,0,_AFLAGconfused);

			killactor();
		}

		callsub(Sub_BulletHandler5);
}





Actor(BulletGrenadeStickEm)
{
		file(BulletGrenadeStickEmHeader);
		startstate(BulletStateNormal);
		startaction(MoveThrownGrenade);

		call(SetParticleSetID);

		float(_declare,grenadeblinker,90);

		if(StickEmState==StickEmNotReady)
		{
			//the first time it comes in, it has been thrown , so we set the state to StickEmReady
			//the second time it comes in, it has StickEmExploding state set!
			float(_set,StickEmState,StickEmReady);
		}

		//vector(_set,tmpvector,255,255,255);
		//SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,300);

		if(VState!=BulletStateStuckInWall && VState!=BulletStateAttachedToActor && VState!=BulletStateStuckOnFloor)
		{
			call(CheckBulletCollision,-1,DamageNoDamage,false);
			if(VTrigger==_DIRactorBulletcol)
			{
				call(CheckBoneCollision,DamageNoDamage,_BulletAttach);
				if(VTrigger==_DIRactorBulletcol)
				{
					State(_or,BulletStateAttachedToActor);
					spawnaction(nomovenogravityWithSound);

					sample(SFXGrenadeBounce,-1);
				}
			}
			elseif(VTrigger|=_DIRallcol)
			{
				if(VColMaterialProperties==_MATWater)
				{
					sample(SFXSplosh,-1);
				}
				else
				{
					if(VColMaterialProperties==_MATKFO)
					{
						//the only case a stickem won't stick (on a KFO)
						//so it'll just auto-explode
						float(_set,StickEmState,StickEmExploding);
					}
					if(VTrigger==_DIRhorcol)
					{
						State(_or,BulletStateStuckOnFloor);
					}
					elseif(VTrigger==_DIRvercol)
					{
						State(_or,BulletStateStuckInWall);
					}

					sample(SFXGrenadeBounce,-1);

					//call(AttachToColObjHeader);		//should call really, but crashes the game
					sample(SFXMaimerPing,-1);
					spawnaction(nomovenogravityWithSound);
				}
			}
		}
		else
		{
			if(StickEmState==StickEmReady)
			{
				sample(SFXStickEmGrenade,-1);
				vector(_set,tmpvector,255,255,255);
				if(grenadeblinker<0)
				{
					SpawnLight(LightBlinkFade,0,EmptyVector,tmpvector,EmptyVector,300);
					float(_set,grenadeblinker,90);
				}
				float(_sub,grenadeblinker,1);
			}
			elseif(StickEmState==StickEmExploding)
			{
				float(_set,StickEmState,StickEmNotReady);

				if(VState==BulletStateAttachedToActor)
				{
					vector(_settoactorpos,tmpvector);
					vector(_copyx,tmpvector,TmpFloat2);
					vector(_copyy,tmpvector,TmpFloat3);
					vector(_copyz,tmpvector,TmpFloat4);

					callsub(sub_fxexplosion);

					if(VAIClass==_AIclassHuman)
					{
						callsub(Sub_BloodFx10);
					}

					sample(SFXGrenadeExplode,-1);

					spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					killactor();
				}
				elseif(VState==BulletStateStuckOnFloor||VState==BulletStateStuckInWall)
				{
					sample(SFXGrenadeExplode,-1);

					vector(_settoactorpos,tmpvector);
					callsub(sub_fxexplosion);

					call(CheckForDynamicCollision,0);
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
						vector(_settocolobjpos,TmpVector2);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

						if(VDynamicCollision|=_ExplodeAmmo)
						{
							spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
						}
						elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
						{
							spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
						}

						spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}
					else
					{
						vector(_copy,TmpVector2,tmpvector);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

						spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}
					killactor();
				}
			}
		}
}

//---------------------------------------------------------------------------- droid bullets


//--------------------------------
//  WEAPONS FACTORY BULLET
//--------------------------------

Actor(BulletGunTurret)
{
		file(BulletGunTurretHeader);
		startstate(BulletStateNormal);
		startaction(move200z);

		call(SetParticleSetID);

		call(CheckBulletCollision,-1,-1,false);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				callSub(sub_RiccoMetal);
			}

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATRipple)
			{
				vector(_set,fxvector,0,0,0);
				callsub(sub_shockwave,0,0);
				sample(SFXRipple,-1);
			}
			elseif(VColMaterialProperties==_MATGlass)
			{
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
				}
				sample(SFXGlassPlink,-1);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
				}

				callSub(sub_RiccoMetal);
			}


			vector(_settoactorpos,tmpvector);
			call(CheckForDynamicCollision,4);

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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

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

				vector(_copy,tmpvector,TmpVector2);
				callsub(sub_fxexplosion);
			}
			killactor();
		}

		callsub(Sub_BulletHandler5);
}


//-------------------------------
// DOMINA TURRET BULLET
//-------------------------------

Actor(BulletTurret)
{
		file(BulletGunTurretNoAIHeader);
		startstate(BulletStateNormal);
		startaction(move200z);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			sample(SFXBazookaLaunch1,-1);
			vector(_set,gactorine,0,0,-200);
//			spawnparticle(fx_flare,0,emptyvector,emptyvector,fx_mturret);
			spawnparticle(fx_TurretStrip,0,emptyvector,gactorine,fx_gunflashhorizac);
			spawnparticle(fx_TurretStrip,0,emptyvector,gactorine,fx_gunflashvertac);
			spawnparticle(fx_TurretStrip,0,emptyvector,gactorine,fx_gunflashdiag1ac);
			spawnparticle(fx_TurretStrip,0,emptyvector,gactorine,fx_gunflashdiag2ac);
		}

		//type,bone,pos,color,vector,radius
		vector(_set,tmpvector,50,50,200);
		SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,400);

		call(CheckBulletCollision,-1,-1,false);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			vector(_settoactorpos,tmpvector);
			vector(_copyx,tmpvector,TmpFloat2);
			vector(_copyy,tmpvector,TmpFloat3);
			vector(_copyz,tmpvector,TmpFloat4);

			callsub(sub_fxexplosion);

			if(VAIClass==_AIclassHuman)
			{
				callsub(Sub_BloodFx10);
			}

			sample(SFXBazookaExplode,-1);

			spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			sample(SFXBazookaExplode,-1);
			vector(_settoactorpos,tmpvector);
			callsub(sub_fxexplosion);

			call(CheckForDynamicCollision,0);
			if(VCoreAICon==0)
			{
				if(VDynamicCollision==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
				}
				else
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
				}
			}

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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				if(VDynamicCollision|=_ExplodeAmmo)
				{
					spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}
				elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
				{
					spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
				}

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}
			else
			{
				vector(_copy,TmpVector2,tmpvector);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

				spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
			}

			killactor();
		}

		callsub(Sub_BulletHandler5);
}


//-------------------------------
// AI TURRET BULLET
//-------------------------------

Actor(BulletShellTurret)
{
		file(BulletShellTurretHeader);
		startstate(BulletStateNormal);
		startaction(move200z);

		call(SetParticleSetID);

		call(CheckBulletCollision,-1,-1,false);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
			}

			sample(SFXTurretHit,-1);

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATRipple)
			{
				vector(_set,fxvector,0,0,0);
				callsub(sub_shockwave,0,0);
				sample(SFXRipple,-1);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
				spawnparticle(fx_impactpuff,0,emptyvector,emptyvector,-1);

				sample(SFXTurretHit,-1);
			}

			vector(_settoactorpos,tmpvector);
			call(CheckForDynamicCollision,4);

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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

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

				vector(_copy,tmpvector,TmpVector2);
				callsub(sub_fxexplosion);
			}
			killactor();
		}

		callsub(Sub_BulletHandler5);
}


Actor(BulletAutoCannon)
{
		file(BulletAutoCannonHeader);
		startstate(BulletStateNormal);
		startaction(move100z);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			vector(_set,gactorpos,0,15,-50);
			vector(_set,gactorine,0,0,-100);
			spawnparticle(fx_tracer,0,gactorpos,gactorine,fx_tracersmall);
		}

		call(CheckBulletCollision,-1,-1,false);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				callSub(sub_RiccoMetal);
			}

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATRipple)
			{
				vector(_set,fxvector,0,0,0);
				callsub(sub_shockwave,0,0);
				sample(SFXRipple,-1);
			}
			elseif(VColMaterialProperties==_MATGlass)
			{
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
				}
				sample(SFXGlassPlink,-1);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
				}

				callSub(sub_RiccoMetal);
			}


			vector(_settoactorpos,tmpvector);
			call(CheckForDynamicCollision,4);
			if(VCoreAICon==0)
			{
				if(VDynamicCollision==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
				}
				else
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
				}
			}

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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

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

				vector(_copy,tmpvector,TmpVector2);
				callsub(sub_fxexplosion);
			}
			killactor();
		}

		callsub(Sub_BulletHandler5);
}


Actor(BulletDroidonZ)
{
		file(BulletAutoCannonHeader);
		startstate(BulletStateNormal);
		startaction(move200z);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			vector(_set,gactorpos,0,0,0);
			vector(_set,gactorine,0,0,-200);
			spawnparticle(fx_tracer,0,gactorpos,gactorine,fx_droidtraceronZ);
		}

		call(CheckBulletCollision,-1,-1,false);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				callSub(sub_RiccoMetal);
			}

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATRipple)
			{
				vector(_set,fxvector,0,0,0);
				callsub(sub_shockwave,0,0);
				sample(SFXRipple,-1);
			}
			elseif(VColMaterialProperties==_MATGlass)
			{
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
				}
				sample(SFXGlassPlink,-1);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
				}

				callSub(sub_RiccoMetal);
			}


			vector(_settoactorpos,tmpvector);
			call(CheckForDynamicCollision,4);
			if(VCoreAICon==0)
			{
				if(VDynamicCollision==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
				}
				else
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
				}
			}

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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

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

				vector(_copy,tmpvector,TmpVector2);
				callsub(sub_fxexplosion);
			}
			killactor();
		}

		callsub(Sub_BulletHandler5);
}



Actor(BulletDroid)
{
		file(BulletAutoCannonHeader);
		startstate(BulletStateNormal);
		startaction(move200);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			vector(_set,gactorpos,0,0,0);
			vector(_set,gactorine,0,200,0);
			spawnparticle(fx_tracer,0,gactorpos,gactorine,fx_droidtracer);
		}

		call(CheckBulletCollision,-1,-1,false);
		call(wUpdateBulletDamage);
		if(VTrigger==_DIRactorBulletcol)
		{
			if(VAIClass==_AIclassHuman)
			{
				sample(SFXHitActor7,-1);
				callsub(Sub_BloodFxSpurt);
				callsub(Sub_BloodFx2);
				callsub(Sub_BloodFxSpray);
			}
			else
			{
				callSub(sub_RiccoMetal);
			}

			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			if(VColMaterialProperties==_MATRipple)
			{
				vector(_set,fxvector,0,0,0);
				callsub(sub_shockwave,0,0);
				sample(SFXRipple,-1);
			}
			elseif(VColMaterialProperties==_MATGlass)
			{
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
				}
				sample(SFXGlassPlink,-1);
			}
			else
			{
				spawnparticle(fx_impactsparks,0,emptyvector,emptyvector,-1);
				if(VColMaterialProperties!=_MATKFO)
				{
					SpawnGooFX(fx_Bullethole,0,emptyvector,emptyvector,0);
				}

				callSub(sub_RiccoMetal);
			}


			vector(_settoactorpos,tmpvector);
			call(CheckForDynamicCollision,4);
			if(VCoreAICon==0)
			{
				if(VDynamicCollision==0)
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
				}
				else
				{
					call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
				}
			}

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
				vector(_settocolobjpos,TmpVector2);
				vector(_copyx,TmpVector2,TmpFloat2);
				vector(_copyy,TmpVector2,TmpFloat3);
				vector(_copyz,TmpVector2,TmpFloat4);

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

				vector(_copy,tmpvector,TmpVector2);
				callsub(sub_fxexplosion);
			}
			killactor();
		}

		callsub(Sub_BulletHandler5);
}


//---------------------------------------------------------------------------- other bullets


Actor(BulletBattery)
{
		file(BulletBatteryHeader);
		startstate(BulletStateNormal);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,grenadelastcoll,0);
		float(_declare,ActiveTimeStart,-1);

		float(_declare,radsamp,0);
		float(_declare,radtime,1000000000);
		float(_declare,radstate,0);					//0:normal battery, 1:radioactive battery

		if(VactorFlag==_AFLAGinitialize)			//re-initialize after a loadgame
		{
			if(radsamp==1)
			{
				sample(SFXRadioactive,-1);
			}
		}


		direction(_clr,_DIRTempFlag);
		call(CheckTriggers);

		if(VSetActive=="s1r18")
		{
			CurEnvTriggerSet("s1r18","batcol");
			if(VTrigger==_DIREnvTrigger)
			{
				if(radsamp==1)
				{
					samplestop(SFXRadioactive);
				}
				KillActor();
			}
			CurEnvTriggerSet("s1r18","battin");
			if(VTrigger!=_DIREnvTrigger)
			{
				if(HelpVar&=Help23)
				{
					float(_set,CallBot,1);
					float(_clr,HelpVar,Help23);
				}
			}
			else
			{
				if(HelpVar&!=Help23)
				{
					float(_set,CallBot,0);
					float(_or,HelpVar,Help23);
				}
			}
		}
		if(VSetActive=="s1r20")
		{
			if(NeedBattery==1)
			{
				CurEnvTriggerSet("s1r20","checkif");
				if(VTrigger==_DIREnvTrigger)
				{
					float(_set,RadActionTimer,1);
					float(_set,NeedBattery,2);
				}
			}
			if(NeedBattery==3)
			{
				CurEnvTriggerSet("s1r20","checkif");
				if(VTrigger==_DIREnvTrigger)
				{	
					if(radsamp==1)
					{
						samplestop(SFXRadioactive);
					}

					KillActor();
					float(_set,RadActionTimer,1);
					float(_set,NeedBattery,4);
				}
			}
		}
		if(VCurSet=="s1r13")
		{
			CurEnvTrigger("killbat");
			if(VTrigger==_DIREnvTrigger)
			{
				if(radsamp==1)
				{
					samplestop(SFXRadioactive);
				}

				KillActor();
			}
		}
		if(VCurSet=="s1r14")
		{
			CurEnvTrigger("killbat");
			if(VTrigger==_DIREnvTrigger)
			{
				if(radsamp==1)
				{
					samplestop(SFXRadioactive);
				}

				KillActor();
			}
		}

		//off after 1m 30 seconds after pickup
		if(ActiveTimeStart==-1)
		{
			//dropped initially
			if(vstate==StateAttached&&vactivetime<radtime&&VRootAIClass==_AIClassScientist&&VRootRank==_RankScum)	//nuketek only
			{
				float(_set,RadiationGlow,1);
				float(_set,radstate,1);
				//picked up
				spawnparticle(fx_flare,0,emptyvector,emptyvector,fx_activebatteryflare);
				vector(_set,tmpvector,192,32,32);
				SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,600);

				call(SetFlagsOnActiveActors,900,0,_DUMMY,0,_AFLAGradiated);
				if(radsamp==0)
				{
					sample(SFXBatteryChargedLethal,-1);
					sample(SFXRadioactive,-1);
					float(_set,radsamp,1);
					float(_seti,radtime,VActiveTime);
					float(_add,radtime,2700);
				}
			}
			else
			{
				if(radsamp==1)
				{
					if(vactivetime<radtime)
					{
						//still radioactive, but we are dropping it
					}
					else
					{
						//radiation has worn off , but we are still holding it  ..get rid of it!!
						samplestop(SFXRadioactive);
						float(_set,radsamp,0);
						float(_set,radstate,0);

						call(ChangeInventory,0,-1);		//SAXS: Msika, don't do this in the bulletcode
														//TONY: He didn't, I did, and it has to be here!

						sample(SFXShatter,-1);
						vector(_settoactorpos,tmpvector);
						callsub(sub_fxsmallexplosion);
						killactor();
					}
				}

				if(radstate==0)
				{
					spawnparticle(fx_flare,0,emptyvector,emptyvector,fx_batteryflare);
				}
			}

			if(VState==BulletStateExplode)
			{
				//set dropped after being picked up
				float(_seti,ActiveTimeStart,VActiveTime);
			}
		}
		else
		{
			//dropped after being picked up
			float(_declare,ActiveTimeDelta,0);
			float(_seti,ActiveTimeDelta,VActiveTime);
			float(_sub,ActiveTimeDelta,ActiveTimeStart);

			if(radstate==1)
			{
				if(vactivetime<radtime)
				{
					call(SetFlagsOnActiveActors,900,0,_DUMMY,0,_AFLAGradiated);

					if(radsamp==0)
					{
						sample(SFXRadioactive,-1);
						float(_set,radsamp,1);
					}
				}
				else
				{
					if(radsamp==1)
					{
						samplestop(SFXRadioactive);
					}
				}

				spawnparticle(fx_flare,0,emptyvector,emptyvector,fx_activebatteryflare);
				vector(_set,tmpvector,192,32,32);
				SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,600);
			}
			else
			{
				//radstate 0
				spawnparticle(fx_flare,0,emptyvector,emptyvector,fx_batteryflare);
				vector(_set,tmpvector,128,128,192);
				SpawnLight(Lomnilight2,0,EmptyVector,tmpvector,EmptyVector,300);
			}

			if(radstate==1)
			{
				/*
				//call(CheckBulletCollision,-1,DamageNoDamage,false);
				if(VTrigger|=_DIRallcol)
				{
					if(grenadelastcoll!=1)
					{
						sample(SFXGrenadeBounce,-1);
					}
					float(_set,grenadelastcoll,1);
				}
				else
				{
					float(_set,grenadelastcoll,0);
				}
				*/

				if(vactivetime>radtime)
				{
					if(radsamp==1)
					{
						samplestop(SFXRadioactive);
					}

					sample(SFXGrenadeExplode,-1);

					vector(_settoactorpos,tmpvector);
					callsub(sub_fxexplosion);

					call(CheckForDynamicCollision,0);
					if(VCoreAICon==0)
					{
						if(VDynamicCollision==0)
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
						}
						else
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
						}
					}

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
						vector(_settocolobjpos,TmpVector2);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

						if(VDynamicCollision|=_ExplodeAmmo)
						{
							spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
						}
						elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
						{
							spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
						}

						spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}
					else
					{
						vector(_copy,TmpVector2,tmpvector);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

						spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}

					float(_set,grenadelastcoll,0);

					killactor();

					//sample(SFXShatter,-1);
					//vector(_settoactorpos,tmpvector);
					//callsub(sub_fxsmallexplosion);
					//killactor();
				}
			}
			else
			{
				if(ActiveTimeDelta>90)
				{
					sample(SFXGrenadeExplode,-1);

					vector(_settoactorpos,tmpvector);
					callsub(sub_fxexplosion);

					call(CheckForDynamicCollision,0);
					if(VCoreAICon==0)
					{
						if(VDynamicCollision==0)
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,1000);
						}
						else
						{
							call(AIexecutecodewithinradius,Sub_ReactToBulletOrExplosion,3000);
						}
					}

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
						vector(_settocolobjpos,TmpVector2);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

						if(VDynamicCollision|=_ExplodeAmmo)
						{
							spawnactor(WeaponAmmo,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
						}
						elseif(VDynamicCollision|=_ExplodeAmmoGrenades)
						{
							spawnactor(WeaponAmmoGrenade,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
						}

						spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}
					else
					{
						vector(_copy,TmpVector2,tmpvector);
						vector(_copyx,TmpVector2,TmpFloat2);
						vector(_copyy,TmpVector2,TmpFloat3);
						vector(_copyz,TmpVector2,TmpFloat4);

						spawnactor(BulletExplosion,TmpFloat2,TmpFloat3,TmpFloat4,false,true);
					}

					float(_set,grenadelastcoll,0);

					if(radsamp==1)
					{
						samplestop(SFXRadioactive);
					}

					killactor();
				}
				else
				{
					call(CheckBulletCollision,-1,DamageGrenade,false);
					if(VTrigger|=_DIRallcol)
					{
						if(VColMaterialProperties==_MATRipple)
						{
							vector(_set,fxvector,0,0,0);
							callsub(sub_shockwave,0,0);
							sample(SFXRipple,-1);
						}
						elseif(VColMaterialProperties==_MATGlass)
						{
							if(VColMaterialProperties!=_MATKFO)
							{
								SpawnGooFX(fx_Bulletholeglass,0,EmptyVector,emptyvector,0);
							}
							sample(SFXGlassPlink,-1);
						}
						else
						{
							if(grenadelastcoll!=1)
							{
								sample(SFXGrenadeBounce,-1);
							}
						}
						float(_set,grenadelastcoll,1);
						SpawnAction(MoveThrownGrenadeWithSound);
					}
					else
					{
						if(grenadelastcoll!=0)
						{
							if(ActiveTimeDelta>150)			//5 seconds
							{
								if(radsamp==1)
								{
									samplestop(SFXRadioactive);
								}

								killactor();
							}
						}

						float(_set,grenadelastcoll,0);
					}
				}
			}
		}
}



//---------------------------------------------------------------------------- Satan bullets FX


Actor(BulletAntiSatan)
{
		file(BulletHolyHeader);
		startstate(BulletStateNormal);
		startaction(move200zandUp);

		call(SetParticleSetID);

		if(vactivetime==0)
		{
			sample(SFXSoulWeapon,-1);

			vector(_set,gactorine,0,16,-200);
			spawnparticle(fx_Satanstrip,0,emptyvector,gactorine,fx_Satanstriph);
			spawnparticle(fx_Satanstrip,0,emptyvector,gactorine,fx_Satanstripv);
			spawnparticle(fx_Satanstrip,0,emptyvector,gactorine,fx_Satanstripd1);
			spawnparticle(fx_Satanstrip,0,emptyvector,gactorine,fx_Satanstriphd2);
		}

		//vector(_set,tmpvector,255,255,255);
		//SpawnLight(toruslight,0,EmptyVector,tmpvector,EmptyVector,600);

		call(CheckBulletCollision,-1,DamageHolyDamage,false);
		if(VTrigger==_DIRactorBulletcol)
		{
			sample(SFXSatanHurt1,-1);

			//satan screams
			killactor();
		}
		elseif(VTrigger|=_DIRallcol)
		{
			killactor();
		}

		callsub(Sub_BulletHandler5);
}






//////////// NEEDS SFX !!!!!!!!!!!!!
//////////// NEEDS SFX !!!!!!!!!!!!!
//////////// NEEDS SFX !!!!!!!!!!!!!

Actor(BulletRingOfFire)
{
		file(BulletHolyHeader);
		startstate(BulletStateNormal);
		startaction(nomove);

		call(SetParticleSetID);

		float(_declare,Radius1,615);
		float(_declare,Radius2,515);
		float(_declare,Radius1fx,100);
		float(_declare,Radius2fx,0);

		float(_declare,ringsin,0);
		float(_declare,ringcos,0);

		call(SetFlagsOnActiveActors,Radius1,110,_DUMMY,0,_AFLAGkillandremove);
		call(ClrFlagsOnActiveActors,Radius2,110,_DUMMY,0,_AFLAGkillandremove);

		float(_add,Radius1,10);
		float(_add,Radius2,10);
		float(_add,Radius1fx,10);
		float(_add,Radius2fx,10);


//------ hubble bubble fx

		if(vactivetime<45)
		{
			float(_rnd2,tmpfloat,4096);
			float(_sin,ringsin,tmpfloat);
			float(_cos,ringcos,tmpfloat);
			float(_mul,ringsin,Radius1fx);
			float(_mul,ringcos,Radius1fx);

			vector(_set,gactorpos,0,0,0);
			vector(_setx,gactorpos,ringsin);
			vector(_setz,gactorpos,ringcos);
			spawnparticle(fx_smallexplosion,0,gactorpos,emptyvector,-1);

			float(_rnd2,tmpfloat,4096);
			float(_sin,ringsin,tmpfloat);
			float(_cos,ringcos,tmpfloat);
			float(_mul,ringsin,Radius2fx);
			float(_mul,ringcos,Radius2fx);

			vector(_setx,gactorpos,ringsin);
			vector(_setz,gactorpos,ringcos);
			spawnparticle(fx_smallexplosion,0,gactorpos,emptyvector,-1);
			/*
			float(_rnd2,tmpfloat,4096);
			float(_sin,ringsin,tmpfloat);
			float(_cos,ringcos,tmpfloat);
			float(_mul,ringsin,Radius1fx);
			float(_mul,ringcos,Radius1fx);

			vector(_set,gactorpos,0,0,0);
			vector(_setx,gactorpos,ringsin);
			vector(_setz,gactorpos,ringcos);
			spawnparticle(fx_smallexplosion,0,gactorpos,emptyvector,-1);

			float(_rnd2,tmpfloat,4096);
			float(_sin,ringsin,tmpfloat);
			float(_cos,ringcos,tmpfloat);
			float(_mul,ringsin,Radius2fx);
			float(_mul,ringcos,Radius2fx);

			vector(_setx,gactorpos,ringsin);
			vector(_setz,gactorpos,ringcos);
			spawnparticle(fx_smallexplosion,0,gactorpos,emptyvector,-1);
			*/
		}

/*
		vector(_set,tmpvector,255,0,0);
		SpawnLight(toruslight,0,EmptyVector,tmpvector,EmptyVector,Radius1);
		vector(_set,tmpvector,-255,-255,-255);
		SpawnLight(toruslight,0,EmptyVector,tmpvector,EmptyVector,Radius2);
*/

		if(vactivetime>=_RingOfFireDuration || VCutScene!=0)
		{
			killactor();
		}
}
