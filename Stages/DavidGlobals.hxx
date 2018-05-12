			//Global Variables
			
					//******** Radiation Related ***********
					float(_declare,RadActionTimer,0);
					float(_declare,RadAlert,0);
					float(_declare,RadChecked,0);
					float(_declare,RadChecked1,0);
					float(_declare,RadChecked2,0);
					float(_declare,RadChecked3,0);
					float(_declare,RadiationGlow,0);
					float(_declare,RadDirection,0);
					float(_declare,PakFly,0);
					
					//******** Sequence ***********

							//** S1R4 : laser wall opens
							float(_declare,PillarEvent,0);
							float(_declare,LaserRetract,0);
							
							//** S1R20 : capsule launch				
							float(_declare,NeedBattery,0);

							//** S1R8 : Possessed Barman
							float(_declare,BarmanAction,0);

							//** S2R2 : gun turret
							float(_declare,side,0);
							float(_declare,GunSmoke,0);
							float(_declare,GunSamFlag,0);

							//** S1R17 : Chot beat up
							float(_declare,punchtimer,0);
							float(_declare,punched,0);
					
					//********* Misc. **********
					float(_declare,InBattle,0);
					float(_declare,Bringmeback,2);
					float(_declare,MissionLevel5,0);
					float(_declare,IsDead,0);		
					float(_declare,AccessGranted,0);
					float(_declare,WarningBit,0);
					float(_declare,Picked,0);
					float(_declare,CrankAmbient,0);
					float(_declare,MaxNrSpawn,5);
					float(_declare,CallBot,0);
					float(_declare,InScan,0);
					float(_declare,CameraPan,0);
					float(_declare,LiftMsg,0);
					float(_declare,RandomMsg,0);
					float(_declare,CDTrack,3);
					float(_declare,AngelReact,0);
					float(_declare,WarnSeq,0);
					float(_declare,DroidVoice,0);
					float(_declare,AirLock,0);
					float(_declare,CDToggle,0);
					float(_declare,Explode01,0);
					float(_declare,Explode02,0);
					float(_declare,InBoxTrigger,0);
					float(_declare,MaxCopRespawn,5);
					float(_declare,MaxChotRespawn,10);
					float(_declare,IntroCam,0);
					float(_declare,ColorRange,0);
					float(_declare,Objective,0);
					float(_declare,StopTutorial,0);

					//***** Bob Daze and Confused ********
					float(_declare,BobMessage,0);
					float(_declare,GodTimer,0);
					float(_declare,Dazed,0);
					float(_declare,Incoming,0);
					float(_declare,BlinkTimer,0);
					float(_declare,ScriptMark,0);

			//Linking level
			float(_declare,LinkGlobal,0);

			//Bit Variables
			float(_declare,HelpVar,0);
			float(_declare,OHelpVar,0);
			float(_declare,Varbit,0);
			float(_declare,Varbit01,0);
			float(_declare,BobSound,0);

			//Timers
			float(_declare,IntroFireYPos,530);
			float(_declare,timer,0);
			float(_declare,timer2,0);
			float(_declare,timer3,0);
			float(_declare,timer4,0);
			float(_declare,SteamTimer,0);
			float(_declare,HudTimer,0);
			float(_declare,BarManTimer,0);
			float(_declare,CommandTimer,0);
			float(_declare,ExplodeBoxTimer,0);
			float(_declare,FreighTimer,0);
			float(_declare,AirLockTimer,0);
			float(_declare,ControlTimer,0);
			float(_declare,ChotTimer,0);
			float(_declare,VictimTimer,0);
			float(_declare,CabTimer,0);
			float(_declare,TimeForSound,0);
			float(_declare,LottoTimer,0);
			float(_declare,IntroToggle,0);
			float(_declare,DanceKey,0);
			float(_declare,DanceTimer,0);
			float(_declare,DanceMove,0);
			float(_declare,DanceDirection,0);
			float(_declare,DanceNumber,0);
			float(_declare,OldDanceMove,0);
			float(_declare,failure,0);
			float(_declare,DanceSequence,0);
			float(_declare,DanceLaserPos,0);
			float(_declare,DanceLaserDir,0);
			float(_declare,ODanceNumber,0);
			float(_declare,StrobeTimer,0);
			float(_declare,DisablePickUp,0);
			
			//Vectors
			vector(_declare,TurretOffset,0,0,0);
			vector(_declare,CharOffset,0,0,0);
			vector(_declare,PosVector1,0,0,0);
			vector(_declare,PosVector2,0,0,0);
			vector(_declare,PosVector3,0,0,0);
			vector(_declare,PosVector4,0,0,0);
			vector(_declare,PosVector5,0,0,0);
			vector(_declare,PosVector6,0,0,0);

			//Reserved variables
			float(_declare,Res01,0); //used to prevent the re-initialization of variable in Annex and Warehouse
			float(_declare,Res02,0); //used for chot battle in shipping sector
			float(_declare,Res03,AllHelp); //ForcePlay for CD tracks (VarBit type)
			float(_declare,Res04,0); //used to prevent re-initialization of variable and enemies in Shipping Sector
			float(_declare,Res05,0);
			float(_declare,Res06,0);
			float(_declare,Res07,0);
			float(_declare,Res08,0);
			float(_declare,Res09,0);
			float(_declare,Res10,0);
			float(_declare,Res11,0);
			float(_declare,Res12,0);

