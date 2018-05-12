#include	"messiahscripts\aaid.hxx"
#include	"messiahscripts\sampleid.hxx"

#include	"messiahscripts\defines.h"
#include	"messiahscripts\objdefines.h"
#include	"messiahscripts\weapons\WeaponDamage.h"

#include	"messiahscripts\defvals.hxx"
#include	"messiahscripts\keysall.hxx"

#include	"messiahscripts\lights.hxx"

#include	"messiahscripts\sound\soundinterface.hxx"
#include	"messiahscripts\sound\soundactors.hxx"
#include	"messiahscripts\sound\soundambient.hxx"
#include	"messiahscripts\sound\soundbackground.hxx"
#include	"messiahscripts\sound\soundweapon.hxx"
#include	"messiahscripts\sound\soundvoices.hxx"


Game(Messiah)
{
		if(VGameCounter==1)			//Pre-game
		{
			//float(_declare,LastActorID,Bob1);

	 //INSERT TESTVARS HERE
			float(_declare,GlobalVar0,47);
			float(_declare,GlobalVar1,47);
			float(_declare,GlobalVar2,47);
			float(_declare,GlobalVar3,47);
			float(_declare,GlobalVar4,47);
			float(_declare,GlobalVar5,47);

	//INPUT VARIABLES HERE

			float(_declare,DirClr,0);
			float(_declare,DirHold,0);
			float(_declare,DirOld,0);

	//Bob Flying Globals
			float(_declare,BobJumpSpeed,15);				//15	Start velocity upwards when jumping
			float(_declare,BobJumpGravity,1.0);				//1.0	Downwardpull when flying straight
			float(_declare,BobJumpGravityNoMove,0.4);		//0.4	Higher gravity that character is pulled down
			float(_declare,BobJumpNoMoveExtraYMovement,7);	//7		Extra movement upwards when not moving
			float(_declare,BobGravityGlide,0.2);		//0.2	Gravity when gliding 
			float(_declare,BobGravityFlap,0.1);		//0.2	Gravity when gliding 

	//Global variables regarding the Level
		float(_declare,BobFlappingEnabled,1);		//1= Bob can flap
		float(_declare,LightsOut,0);				//1= Lights are dimmed (ambient light reduced)

		//Misc Global variables

			vector(_declare,Gactorpos,0,0,0);
			vector(_declare,Gactorangle,0,3500,0);
			vector(_declare,Gactorine,0,3500,0);

			float(_declare,LastWepCleanup,0);

	//Global vars regarding currently playercontrolled character
			vector(_declare,PlayerPos,0,0,0);
			float(_declare,PlayerHeadBone,0);


	//Global character variables used for subroutines
			float(_declare,ColAngleTmp,0);
			float(_declare,ColAngleTmpFace,0);
			float(_declare,ColMaterial,0);


	//Generic variables
			vector(_declare,EmptyVector,0,0,0);		//Always (0,0,0)
			float(_declare,EmptyFloat,0);			//Always 0

			float(_declare,SubVar1,0);
			float(_declare,SubVar2,0);
			float(_declare,SubVar3,0);
			float(_declare,SubVar4,0);

			vector(_declare,SubVector1,0,0,0);
			vector(_declare,SubVector2,0,0,0);
			vector(_declare,SubVector3,0,0,0);

			float(_declare,SubSubParm1,0);
			float(_declare,SubSubParm2,0);
			float(_declare,SubSubParm3,0);
			float(_declare,SubSubParm4,0);
			float(_declare,SubSubParm5,0);
			float(_declare,SubSubParm6,0);
			float(_declare,SubSubParm7,0);
			float(_declare,SubSubParm8,0);
	/*
			float(_declare,Parm1,0);
			float(_declare,Parm2,0);
			float(_declare,Parm3,0);
			float(_declare,Parm4,0);
			float(_declare,Parm5,0);
			float(_declare,Parm6,0);
			float(_declare,Parm7,0);
			float(_declare,Parm8,0);

			float(_declare,Result,0);
	*/
			vector(_declare,TmpVector,0,0,0);
			vector(_declare,TmpVector1,0,0,0);
			vector(_declare,TmpVector2,0,0,0);
			vector(_declare,TmpVector3,0,0,0);
			vector(_declare,TmpVector4,0,0,0);

			float(_declare,TmpFloat,0);
			float(_declare,TmpFloat1,0);
			float(_declare,TmpFloat2,0);
			float(_declare,TmpFloat3,0);
			float(_declare,TmpFloat4,0);

			float(_declare,Var1,0);
			float(_declare,Var2,0);
			float(_declare,Var3,0);

			float(_declare,SniperToggle,1);

			//float(_Declare,DebugOnlyOneEnemy,0)
			//float(_Declare,DebugOnlyOneWeapon,0)

	//		float(_declare,keytouched,0); // for keyboard control

	//Stage global variables


	//Mission Objective Text
	
			float(_declare,MissionLevel1,0);
			float(_declare,MissionLevel2,0);
			float(_declare,MissionLevel3,0);
			float(_declare,MissionLevel4,0);
			float(_declare,MissionLevel5,0);
			float(_declare,MissionLevel6,0);
			float(_declare,MissionLevel7,0);
			float(_declare,MissionLevel8,0);
			float(_declare,MissionLevel9,0);


	//c1_s1 (Shipment sector)
			float(_declare,VarKey1,0);
			float(_declare,VarKey2,0);
			float(_declare,VarKey3,0);
			float(_declare,VarKey4,0);
			float(_declare,VarKey5,0);
			float(_declare,VarKey6,0);
			float(_declare,VarKey7,0);
			float(_declare,VarKey8,0);
			float(_declare,VarKey9,0);
			float(_declare,VarKey10,0);
			float(_declare,LiteCounter,250);

	//c1_s2 (OldTown)
			float(_declare,VarKey11,0);
			float(_declare,VarKey12,0);
			float(_declare,VarKey13,0);
			float(_declare,VarKey14,0);
			float(_declare,VarKey15,0);
			float(_declare,VarKey16,0);
			float(_declare,VarKey17,0);
			float(_declare,VarKey18,0);
			float(_declare,VarKey19,0);
			float(_declare,VarKey20,0);
			float(_declare,BattleTimer,0);
			float(_declare,Gate4Unlocked,0);
			float(_declare,Crossroads,0);
			float(_declare,RocketAttack,0);

	//c2 (Warehouse)
			float(_declare,VarKey21,0);
			float(_declare,VarKey22,0);
			float(_declare,VarKey23,0);
			float(_declare,VarKey24,0);
			float(_declare,VarKey25,0);
			float(_declare,VarKey26,0);
			float(_declare,VarKey27,0);
			float(_declare,VarKey28,0);
			float(_declare,VarKey29,0);
			float(_declare,VarKey30,0);
	//c2 (Annex)
			float(_declare,ANNXVAR1,0);
			float(_declare,ANNXVAR2,0);

	//c2 (Weapon Factory)
			float(_declare,VarKey31,0);
			float(_declare,VarKey32,0);
			float(_declare,VarKey33,0);
			float(_declare,VarKey34,0);
			float(_declare,VarKey35,0);
			float(_declare,VarKey36,0);
			float(_declare,VarKey37,0);
			float(_declare,VarKey38,0);
			float(_declare,VarKey39,0);
			float(_declare,VarKey40,0);

			float(_declare,WepConstructionTimer,0);	//For Weapon Construction
			float(_declare,GunTurretKey,0);			//For Gun turret Sequence in Fact_20
			float(_declare,MaserKey,0);				//For Maser (built? charged?)
			float(_declare,SecurityTimer,0);		//For cop reaction in Fact_3

			//For Flame Effects in Fact_2
			float(_declare,FurnaceTimer1,0);
			float(_declare,FurnaceTimer2,0);
			float(_declare,FurnaceTimer3,0);
			float(_declare,FurnaceTimer4,0);


	//c2 (Conveyer - Streets)
			float(_declare,VarKey41,0);
			float(_declare,VarKey42,0);
			float(_declare,VarKey43,0);
			float(_declare,VarKey44,0);
			float(_declare,VarKey45,0);
			float(_declare,VarKey46,0);
			float(_declare,VarKey47,0);
			float(_declare,VarKey48,0);
			float(_declare,VarKey49,0);
			float(_declare,VarKey50,0);
			float(_declare,WstAccess,0);
	
	//c3 (Redlite - CLub Perimeter)
			float(_declare,VarKey51,0);
			float(_declare,VarKey52,0);
			float(_declare,VarKey53,0);
			float(_declare,VarKey54,0);
			float(_declare,VarKey55,0);
			float(_declare,VarKey56,0);
			float(_declare,VarKey57,0);
			float(_declare,VarKey58,0);
			float(_declare,VarKey59,-1);
			float(_declare,VarKey60,0);
			float(_declare,VarKey61,0);
			float(_declare,VarKey62,0);
			float(_declare,VarKey63,0);
			float(_declare,VarKey64,0);
			float(_declare,VarKey65,0);
			float(_declare,VarKey66,0);
			float(_declare,VarKey67,0);
			float(_declare,VarKey68,0);
			float(_declare,VarKey69,0);
			float(_declare,VarKey70,0);

	//c3 (Club Kyd)
			float(_declare,VarKey71,0);
			float(_declare,VarKey72,0);
			float(_declare,VarKey73,0);
			float(_declare,VarKey74,0);
			float(_declare,VarKey75,0);
			float(_declare,VarKey76,0);
			float(_declare,VarKey77,0);
			float(_declare,VarKey78,0);
			float(_declare,VarKey79,0);
			float(_declare,VarKey80,0);
			float(_declare,LaserAngle1,0);
			float(_declare,LaserAngle2,0);
			float(_declare,DiscColor,0);
			float(_declare,ColorStage,0);
			float(_declare,DanceMoves,0);

	//c3 (Military Zone)
			float(_declare,VarKey81,0);
			float(_declare,VarKey82,0);
			float(_declare,VarKey83,0);
			float(_declare,VarKey84,0);
			float(_declare,VarKey85,0);
			float(_declare,VarKey86,0);
			float(_declare,VarKey87,0);
			float(_declare,VarKey88,0);
			float(_declare,VarKey89,0);
			float(_declare,VarKey90,0);

	//Boss Areas (Priest - Satan)
			float(_declare,VarKey91,0);
			float(_declare,VarKey92,0);
			float(_declare,VarKey93,0);
			float(_declare,VarKey94,0);
			float(_declare,VarKey95,0);
			float(_declare,VarKey96,0);
			float(_declare,VarKey97,0);
			float(_declare,VarKey98,0);
			float(_declare,VarKey99,0);

	//c1_s3 Sewer - Outskirts - Laboratory)
			float(_declare,VarKey101,0);
			float(_declare,VarKey102,0);
			float(_declare,VarKey103,0); //if outskirts power is restored
			float(_declare,VarKey104,0);
			float(_declare,VarKey105,0);
			float(_declare,VarKey106,0);
			float(_declare,VarKey107,0);
			float(_declare,VarKey108,0);
			float(_declare,VarKey109,0);
			float(_declare,VarKey110,0);
			float(_declare,OpenDoor,0);
			float(_declare,WeaponDelay01,0);
			float(_declare,WeaponDelay02,0);
			float(_declare,WeaponDelay03,0);
			float(_declare,LabAlarm,0);
			float(_declare,LabSecBeams,0);
			float(_declare,Undertaker,0);
			float(_declare,CanMakeBeast,1);			
			float(_declare,FlicBits,0);

		//Cryo
			float(_declare,CryoKey1,0);
			float(_declare,CryoKey2,0);
			float(_declare,CryoKey3,0);
			
		//c2 (Wasteplant)
			float(_declare,WorkerPushingObject,0);		//Whether or not worker is pushing object
			float(_declare,BarrelTimer,0);

			float(_declare,PlatformTimer,0);	//Used for platform scripting in wast5
			float(_declare,PlatformLevel1,0);
			float(_declare,PlatformLevel2,0);
			
			float(_declare,VarKey111,0);
			float(_declare,VarKey112,0);
			float(_declare,VarKey113,0);
			float(_declare,VarKey114,0);
			float(_declare,VarKey115,0);
			float(_declare,VarKey116,0);
			float(_declare,VarKey117,0);
			float(_declare,VarKey118,0);
			float(_declare,VarKey119,0);
			float(_declare,VarKey120,0);

			float(_declare,aitoggle,0);
			float(_declare,aivisiontoggle,0);
			float(_declare,DepossesionAbilityActive,0);
			float(_declare,tutorialtoggle,1);
			float(_declare,LastTuturialChange,0);

			float(_declare,GodMode,0);

			float(_declare,SniperMode,0);
			//TH
			float(_declare,PreCopStateBits,0);
			float(_declare,CopStateBits,0);
			float(_declare,PreCopActionBits,0);
			float(_declare,CopActionBits,0);
			float(_declare,SoundDelayCounter,0);//to make sure that sounds don't overlap, set to positive value when sound started & counts-down to zero

			float(_declare,NrActorsInSet,0);
			float(_declare,NrCopsInSet,0);
			
			float(_declare,PowerOn,1);
			float(_declare,StreetCorpses,0);

			float(_declare,CheatCode1,0);
			float(_declare,CheatCode2,0);
			float(_declare,CheatCode3,0);
			float(_declare,AIPatience,0);
			
			//

			//Msika's variables for levels
			#include	"messiahscripts\stages\DavidGlobals.hxx"

			//my vectors/floats for specialFX and soundFX,etc...
			#include	"messiahscripts\particles\TonyGlobals.hxx"

			ClrPaths();

			InstallPath("c:\mesinst");
			AddPath("pc");
			AddPath("pc\3dxprj");
			LevelFile("messiah.spt");


			//set key to be non repeat
			call(ToggleKey,KEY_9);
			call(ToggleKey,KEY_T);

			float(_set,AIPatience,AINOTARGETSEARCHTHRESHOLD);
			if(VDifficulty==_DifficultyEasy)
			{
				float(_div,AIPatience,3);
			}
			elseif(VDifficulty==_DifficultyHard)
			{
				float(_mul,AIPatience,2);
			}

			//Makes sure AI vision is turned on
			//float(_set,aivisiontoggle,0);

			if(VCurScene==1)
			{
				callsub(InitScene1)
			}
			if(VCurScene==2)
			{
				callsub(InitScene2)
			}
			if(VCurScene==3)
			{
				callsub(InitScene3);
			}
			if(VCurScene==4)
			{
				callsub(InitScene4);
			}
			if(VCurScene==5)
			{
				callsub(InitScene5);
			}
			if(VCurScene==6)
			{
				callsub(InitScene6);
			}
			if(VCurScene==7)
			{
				callsub(InitScene7);
			}
			if(VCurScene==8)
			{
				callsub(InitScene8);
			}
			if(VCurScene==9)
			{
				callsub(InitScene9);
			}
			if(VCurScene==10)
			{
				callsub(InitScene10);
			}
			if(VCurScene==11)
			{
				callsub(InitScene11);
			}
			if(VCurScene==12)
			{
				callsub(InitScene12);
			}
			if(VCurScene==13)
			{
				callsub(InitScene13);
			}
			if(VCurScene==14)
			{
				callsub(InitScene14);
			}
			if(VCurScene==15)
			{
				callsub(InitScene15);
			}
			if(VCurScene==16)
			{
				callsub(InitScene16);
			}
			if(VCurScene==17)
			{
				callsub(InitScene17);
			}
			if(VCurScene==18)
			{
				callsub(InitScene18);
			}
			if(VCurScene==19)
			{
				callsub(InitScene19);
			}
			if(VCurScene==20)
			{
				callsub(InitScene20);
			}
			if(VCurScene==21)
			{
				callsub(InitScene21);
			}
			if(VCurScene==22)
			{
				callsub(InitScene22);
			}
		}

		if(VInitSceneSounds==1)
		{
			if(VRunScriptCode==1)
			{
				callsub(InitSceneSound1)
			}
			if(VRunScriptCode==2)
			{
				callsub(InitSceneSound2)
			}
			if(VRunScriptCode==3)
			{
				callsub(InitSceneSound3);
			}
			if(VRunScriptCode==4)
			{
				callsub(InitSceneSound4);
			}
			if(VRunScriptCode==5)
			{
				callsub(InitSceneSound5);
			}
			if(VRunScriptCode==6)
			{
				callsub(InitSceneSound6);
			}
			if(VRunScriptCode==7)
			{
				callsub(InitSceneSound7);
			}
			if(VRunScriptCode==8)
			{
				callsub(InitSceneSound8);
			}
			if(VRunScriptCode==9)
			{
				callsub(InitSceneSound9);
			}
			if(VRunScriptCode==10)
			{
				callsub(InitSceneSound10);
			}
			if(VRunScriptCode==11)
			{
				callsub(InitSceneSound11);
			}
			if(VRunScriptCode==12)
			{
				callsub(InitSceneSound12);
			}
			if(VRunScriptCode==13)
			{
				callsub(InitSceneSound13);
			}
			if(VRunScriptCode==14)
			{
				callsub(InitSceneSound14);
			}
			if(VRunScriptCode==15)
			{
				callsub(InitSceneSound15);
			}
			if(VRunScriptCode==16)
			{
				callsub(InitSceneSound16);
			}
			if(VRunScriptCode==17)
			{
				callsub(InitSceneSound17);
			}
			if(VRunScriptCode==18)
			{
				callsub(InitSceneSound18);
			}
		}


		if(VGameCounter>=1)
		{
			///////////
			//MAIN LOOP
			///////////

			call(GetNumbActorsInCurrentSet,NrActorsInSet,_AIClassCop|_AIClassWorker|_AIclassprost|_AIclasspimp|_AIclasspriest|_AIclassdweller|_AIclassscientist|_AIclassbarpeople|_AIclassmale|_AIclassfemale|_AIclassmedic|_AIclasssubgirl);
			call(GetNumbActorsInCurrentSet,NrCopsInSet,_AIClassCop);

			if(VInitScriptCode!=0)
			{
				//	A new script has been requested from a script
				//
				if(VInitScriptCode==1)
				{
					callsub(InitScene1)
				}
				elseif(VInitScriptCode==2)
				{
					callsub(InitScene2)
				}
				elseif(VInitScriptCode==3)
				{
					callsub(InitScene3);
				}
				elseif(VInitScriptCode==4)
				{
					callsub(InitScene4);
				}
				elseif(VInitScriptCode==5)
				{
					callsub(InitScene5);
				}
				elseif(VInitScriptCode==6)
				{
					callsub(InitScene6);
				}
				elseif(VInitScriptCode==7)
				{
					callsub(InitScene7);
				}
				elseif(VInitScriptCode==8)
				{
					callsub(InitScene8);
				}
				elseif(VInitScriptCode==9)
				{
					callsub(InitScene9);
				}
				elseif(VInitScriptCode==10)
				{
					callsub(InitScene10);
				}
				elseif(VInitScriptCode==11)
				{
					callsub(InitScene11);
				}
				elseif(VInitScriptCode==12)
				{
					callsub(InitScene12);
				}
				elseif(VInitScriptCode==13)
				{
					callsub(InitScene13);
				}
				elseif(VInitScriptCode==14)
				{
					callsub(InitScene14);
				}
				elseif(VInitScriptCode==15)
				{
					callsub(InitScene15);
				}
				elseif(VInitScriptCode==16)
				{
					callsub(InitScene16);
				}
				elseif(VInitScriptCode==17)
				{
					callsub(InitScene17);
				}
				elseif(VInitScriptCode==18)
				{
					callsub(InitScene18);
				}
				elseif(VInitScriptCode==19)
				{
					callsub(InitScene19);
				}
			}



			//SETS GLOBAL AMBIENT LIGHTING (for power going out)
			if(Dazed==0)
			{
				if(PowerOn==0)
				{
					call(GlobalAmbient,150,150,150);
				}
				elseif(PowerOn==-1)
				{
					call(GlobalAmbient,0,0,0);
				}
				elseif(PowerOn==-2)
				{
					call(GlobalAmbient,150,150,150);
				}
				elseif(PowerOn==-3)
				{
					call(GlobalAmbient,180,180,180);
				}
				else
				{
					call(GlobalAmbient,255,255,255);
				}
			}

			if(VRunScriptCode==1)
			{
				callsub(MainScene1)
			}
			if(VRunScriptCode==2)
			{
				callsub(MainScene2)
			}
			if(VRunScriptCode==3)
			{
				callsub(MainScene3);
			}
			if(VRunScriptCode==4)
			{
				callsub(MainScene4);
			}
			if(VRunScriptCode==5)
			{
				callsub(MainScene5);
			}
			if(VRunScriptCode==6)
			{
				callsub(MainScene6);
			}
			if(VRunScriptCode==7)
			{
				callsub(MainScene7);
			}
			if(VRunScriptCode==8)
			{
				callsub(MainScene8);
			}
			if(VRunScriptCode==9)
			{
				callsub(MainScene9);
			}
			if(VRunScriptCode==10)
			{
				callsub(MainScene10);
			}
			if(VRunScriptCode==11)
			{
				callsub(MainScene11);
			}
			if(VRunScriptCode==12)
			{
				callsub(MainScene12);
			}
			if(VRunScriptCode==13)
			{
				callsub(MainScene13);
			}
			if(VRunScriptCode==14)
			{
				callsub(MainScene14);
			}
			if(VRunScriptCode==15)
			{
				callsub(MainScene15);
			}
			if(VRunScriptCode==16)
			{
				callsub(MainScene16);
			}
			if(VRunScriptCode==17)
			{
				callsub(MainScene17);
			}
			if(VRunScriptCode==18)
			{
				callsub(MainScene18);
			}
			if(VRunScriptCode==19)
			{
				callsub(MainScene19);
			}
			elseif(VCurScene==20)
			{
				callsub(MainScene20);
			}
			elseif(VCurScene==21)
			{
				callsub(MainScene21);
			}
			elseif(VCurScene==22)
			{
				callsub(MainScene22);
			}

			float(_sub,InBattle,1);
			if(InBattle<0)
			{
				float(_set,InBattle,0);
			}
			elseif(InBattle>90)
			{
				float(_set,InBattle,90);
			}


			//	Get rid of QA amounts of weapons
			//
			float(_seti,TmpFloat,VGameCounter);
			float(_sub,TmpFloat,LastWepCleanup);
			if(TmpFloat>=900)
			{
				float(_seti,LastWepCleanup,VGameCounter);
				call(CleanUpWeapons,5);
			}
		}


		callsub(ReadKeyJoy);


		if(VAICon==0)
		{
			float(_seti,DirHold,VTrigger);
			float(_set,DirClr,DirHold);
			float(_xor,DirClr,DirOld);
			float(_and,DirClr,DirOld);		//DirClr=(OldDirection^NewDirection)&OldDirection
			float(_and,DirHold,DirOld);		//DirHold=OldDirection&NewDirection
			float(_seti,DirOld,VTrigger);
		}


		print("AI:          ",aivisiontoggle);
		print("AI vision:   ",aitoggle);
		printi("AI Nr Attackers:      ",VAInrattackingplayer);
		printi("AI Attack Strenght:   ",VAIenemiesattackingplayerstrenght);
		printih("RunScriptCode:        ",VRunScriptCode);
/*
		printilog("AI Nr Attackers:      ",VAInrattackingplayer);
		printilog("AI Attack Strenght:   ",VAIenemiesattackingplayerstrenght);
		printLog("AI curvolume:         ",FFcurvolume);
		printLog("AI MAXvolume:         ",FFfader);
		printLog("Last FF sample:       ",LastCombatSFX);
		printLog("FFplaying:            ",FFPlaying);
*/

/////FF loop attacks...
		if(VCombatMusic!=0)
		{
			if(VAInrattackingplayer>=5 && VAIenemiesattackingplayerstrenght>30 && FFplaying==0)
			{
				if(vrnd<33 && LastCombatSFX!=1)
				{
					float(_set,LastCombatSFX,1);
					sample(SFXFF1,-1);
				}
				elseif(vrnd<66 && LastCombatSFX!=2)
				{
					float(_set,LastCombatSFX,2);
					sample(SFXFF2,-1);
				}
				elseif(LastCombatSFX!=3)
				{
					float(_set,LastCombatSFX,3);
					sample(SFXFF3,-1);
				}
				else
				{
					float(_set,LastCombatSFX,1);
					sample(SFXFF1,-1);
				}

				float(_set,FFplaying,1);		//playing
				float(_set,FFcurvolume,1);
			}
			elseif(VAInrattackingplayer>=3 && VAIenemiesattackingplayerstrenght>30 && FFplaying==0)
			{
				if(vrnd<33 && LastCombatSFX!=4)
				{
					float(_set,LastCombatSFX,4);
					sample(SFXFF4,-1);
				}
				elseif(vrnd<66 && LastCombatSFX!=5)
				{
					float(_set,LastCombatSFX,5);
					sample(SFXFF5,-1);
				}
				elseif(LastCombatSFX!=6)
				{
					float(_set,LastCombatSFX,6);
					sample(SFXFF6,-1);
				}
				else
				{
					float(_set,LastCombatSFX,4);
					sample(SFXFF4,-1);
				}

				float(_set,FFplaying,1);		//playing
				float(_set,FFcurvolume,1);
			}

			if(VAInrattackingplayer>3 && VAIenemiesattackingplayerstrenght>30 && FFplaying==1)
			{
				float(_set,FFfader,100);		//max volume
			}
			elseif(VAInrattackingplayer>=1 && VAIenemiesattackingplayerstrenght>30 && FFplaying==1)
			{
				float(_set,FFfader,70);			//70% volume
			}
			else
			{
				float(_set,FFfader,0);			//phase out
			}

			if(FFplaying==1)
			{
				if(VAInrattackingplayer==0)
				{
					//fade down
					float(_sub,FFcurvolume,0.8);
					if(FFcurvolume<0)
					{
						float(_set,FFcurvolume,0);
					}
				}
				else
				{
					//fado up
					float(_add,FFcurvolume,1.5);
					if(FFcurvolume>FFfader)
					{
						float(_sub,FFcurvolume,1.0);
					}
				}


				if(LastCombatSFX==1)
				{
					samplevolume(SFXFF1,FFcurvolume);
				}
				elseif(LastCombatSFX==2)
				{
					samplevolume(SFXFF2,FFcurvolume);
				}
				elseif(LastCombatSFX==3)
				{
					samplevolume(SFXFF3,FFcurvolume);
				}
				elseif(LastCombatSFX==4)
				{
					samplevolume(SFXFF4,FFcurvolume);
				}
				elseif(LastCombatSFX==5)
				{
					samplevolume(SFXFF5,FFcurvolume);
				}
				elseif(LastCombatSFX==6)
				{
					samplevolume(SFXFF6,FFcurvolume);
				}

				if(FFcurvolume<=0)
				{
					float(_set,FFplaying,0);
					if(LastCombatSFX==1)
					{
						samplestop(SFXFF1);
					}
					elseif(LastCombatSFX==2)
					{
						samplestop(SFXFF2);
					}
					elseif(LastCombatSFX==3)
					{
						samplestop(SFXFF3);
					}
					elseif(LastCombatSFX==4)
					{
						samplestop(SFXFF4);
					}
					elseif(LastCombatSFX==5)
					{
						samplestop(SFXFF5);
					}
					elseif(LastCombatSFX==6)
					{
						samplestop(SFXFF6);
					}
				}
			}
		}
		else
		{
			if(FFplaying==1)
			{
				float(_set,FFplaying,0);
				if(LastCombatSFX==1)
				{
					samplestop(SFXFF1);
				}
				elseif(LastCombatSFX==2)
				{
					samplestop(SFXFF2);
				}
				elseif(LastCombatSFX==3)
				{
					samplestop(SFXFF3);
				}
				elseif(LastCombatSFX==4)
				{
					samplestop(SFXFF4);
				}
				elseif(LastCombatSFX==5)
				{
					samplestop(SFXFF5);
				}
				elseif(LastCombatSFX==6)
				{
					samplestop(SFXFF6);
				}
			}
		}

		float(_xor,EveryOtherFrame,1);
		if(SoundDelayCounter>0)
		{
			float(_sub,SoundDelayCounter,1);
		}

		float(_add,WeaponFaderCol,WeaponFaderDir);
		if(WeaponFaderCol<128)
		{
			float(_set,WeaponFaderDir,64);
		}
		elseif(WeaponFaderCol>4096)
		{
			float(_set,WeaponFaderDir,-64);
		}

}






SubRoutine(Sub_SpawnCharacters)
{
		if(VAICon==0)
		{
			if(vkey==KEY_TAB)
			{
				move(0,0,-50);
			}
		}


//		if(VActiveTime==5&&VGameCounter<8)
//		{
//			spawnactor(Weapon11,-30,100,-200);
//			spawnactor(Copl,0,150,-100);
//		}
//		if(VActiveTime==27&&VGameCounter<30)
//		{
	//		spawnactor(Copl,100,100,-400);
//		}
//weapon1
//weapon11
//weapon12
//weapon13

}

SubRoutine(Sub_SpawnActors)
{
	if(VAICon==0)
	{
		if(VKey==KEY_LEFT && VKey==KEY_RSHIFT)
		{
			float(_add,CurrentActor,0.5);
			if(CurrentActor>=55)
			{
				float(_set,CurrentActor,55);
			}
		}
		elseif(VKey==KEY_RIGHT && VKey==KEY_RSHIFT)
		{
			float(_sub,CurrentActor,0.5);
			if(CurrentActor<0)
			{
				float(_set,CurrentActor,0);
			}
		}

		//if(DebugOnlyOneEnemy==0)
		//{
			//float(_set,DebugOnlyOneEnemy,3)

			if(VKey==KEY_SPACE && VKey==KEY_LSHIFT)
			{
				if(CurrentActor<=0)
				{
					spawnactor(copl,0,150,-200);
				}
				elseif(CurrentActor<=1)
				{
					spawnactor(copm,0,150,-200);
				}
				elseif(CurrentActor<=2)
				{
					spawnactor(coph,0,150,-200);
					//spawnactor(AutoCannon,0,150,-200);
				}
				elseif(CurrentActor<=3)
				{
					spawnactor(worker,0,150,-200);
					//spawnactor(WeaponBot,0,150,-200);
				}
				elseif(CurrentActor<=4)
				{
					spawnactor(medic,0,150,-200);
				}
				elseif(CurrentActor<=5)
				{
					spawnactor(abeast,0,150,-200);
				}
				elseif(CurrentActor<=6)
				{
					spawnactor(RadiationWorker,0,150,-200);
				}
				elseif(CurrentActor<=7)
				{
					spawnactor(Layya,0,150,-200);
				}
				elseif(CurrentActor<=8)
				{
					spawnactor(prost1,0,150,-200);
				}
				elseif(CurrentActor<=9)
				{
					spawnactor(hung,0,150,-200);
				}
				elseif(CurrentActor<=10)
				{
					spawnactor(chot,0,150,-200);
				}
				elseif(CurrentActor<=11)
				{
					spawnactor(chotct,0,150,-200);
				}
				elseif(CurrentActor<=12)
				{
					spawnactor(chotmot,0,150,-200);
				}
				elseif(CurrentActor<=13)
				{
					spawnactor(domina,0,150,-200);
				}
				elseif(CurrentActor<=14)
				{
					spawnactor(Dweller1,0,150,-200);
				}
				elseif(CurrentActor<=15)
				{
					spawnactor(Dweller3,0,150,-200);
				}
				elseif(CurrentActor<=16)
				{
					spawnactor(subgirl1,0,150,-200);
				}
				elseif(CurrentActor<=17)
				{
					spawnactor(subgirl2,0,150,-200);
				}
				elseif(CurrentActor<=18)
				{
					spawnactor(MDroid1,0,150,-200);
				}
				elseif(CurrentActor<=19)
				{
					spawnactor(MDroid2,0,150,-200);
				}
				elseif(CurrentActor<=20)
				{
					spawnactor(rat,0,150,-200);
				}
				elseif(CurrentActor<=21)
				{
					spawnactor(Candy,0,150,-200);
				}
				elseif(CurrentActor<=22)
				{
					spawnactor(barman,0,150,-200);
				}
				elseif(CurrentActor<=23)
				{
					spawnactor(scientist,0,150,-200);
				}
				elseif(CurrentActor<=24)
				{
					spawnactor(priest,0,150,-200);
				}
				elseif(CurrentActor<=25)
				{
					spawnactor(chotbeast,0,150,-200);
				}
				elseif(CurrentActor<=26)
				{
					spawnactor(GunTurret,0,-35,-200);
				}
				elseif(CurrentActor<=27)
				{
					spawnactor(RocketLauncher,0,-54,-200);
				}
				elseif(CurrentActor<=28)
				{ 
					spawnactor(Pimp,0,150,-200);
				}
				elseif(CurrentActor<=29)
				{ 
					spawnactor(chot2,0,150,-200);
				}
				elseif(CurrentActor<=30)
				{ 
					spawnactor(bouncer,0,150,-200);
				}
				elseif(CurrentActor<=31)
				{ 
					spawnactor(evilbob,0,150,-200);
				}
				elseif(CurrentActor<=32)
				{ 
					spawnactor(djkyd,0,150,-200);
				}
				elseif(CurrentActor<=33)
				{ 
					spawnactor(satan,0,150,-200);
				}
				elseif(CurrentActor<=34)
				{ 
					spawnactor(DefensiveBot,0,150,-200);
				}
				elseif(CurrentActor<=35)
				{ 
					spawnactor(CompanionBot,0,150,-200);
				}
				elseif(CurrentActor<=36)
				{ 
					spawnactor(TransportBot,0,150,-200);
				}
				elseif(CurrentActor<=37)
				{ 
					spawnactor(OffensiveBot,0,150,-200);
				}
				elseif(CurrentActor<=38)
				{ 
					spawnactor(Dweller2,0,150,-200);
				}
				elseif(CurrentActor<=39)
				{ 
					spawnactor(victimmale,0,150,-200);
				}
				elseif(CurrentActor<=40)
				{ 
					spawnactor(VictimFeMale,0,150,-200);
				}
				elseif(CurrentActor<=41)
				{ 
					spawnactor(FemDweller1,0,150,-200);
				}
				elseif(CurrentActor<=42)
				{ 
					spawnactor(FemDweller2,0,150,-200);
				}
				elseif(CurrentActor<=43)
				{ 
					spawnactor(prost2,0,150,-200);
				}
				elseif(CurrentActor<=44)
				{ 
					spawnactor(copr,0,150,-200);
				}
				elseif(CurrentActor<=45)
				{ 
					spawnactor(GunCommander,0,150,-200);
				}
				elseif(CurrentActor<=46)
				{ 
					spawnactor(nun,0,150,-200);
				}
				elseif(CurrentActor<=47)
				{ 
					spawnactor(chotdwarf,0,150,-200);
				}
				elseif(CurrentActor<=48)
				{ 
					spawnactor(shellturret,0,150,-200);
				}
				elseif(CurrentActor<=49)
				{ 
					spawnactor(beast,0,150,-200);
				}
				elseif(CurrentActor<=50)
				{ 
					spawnactor(CleanUpBot,0,150,-200);
				}
				elseif(CurrentActor<=51)
				{ 
					spawnactor(BarmanHelper,0,150,-200);
				}
				elseif(CurrentActor<=52)
				{ 
					spawnactor(Dancer1,0,150,-200);
				}
				elseif(CurrentActor<=53)
				{ 
					spawnactor(Worker2,0,150,-200);
				}
				elseif(CurrentActor<=54)
				{ 
					spawnactor(dancer2,0,150,-200);
				}
				elseif(CurrentActor<=55)
				{ 
					spawnactor(bird,0,150,-200);
				}


				//else
				//{
				//	float(_set,DebugOnlyOneEnemy,0)
				//}
			}
		//}
		//else
		//{
		//	float(_sub,DebugOnlyOneEnemy,1)
		//}
	}
}

SubRoutine(Sub_SpawnWeapons)
{
	if(VAICon==0)
	{
		if(VKey==KEY_8 && VKey!=KEY_RSHIFT)
		{
			float(_add,CurrentWeapon,0.5);
			if(CurrentWeapon>=15)
			{
				float(_set,CurrentWeapon,15);
			}
		}
		elseif(VKey==KEY_7 && VKey!=KEY_RSHIFT)
		{
			float(_sub,CurrentWeapon,0.5);
			if(CurrentWeapon<0)
			{
				float(_set,CurrentWeapon,0);
			}
		}


		if(CurrentWeapon<=0)
		{
			dmessage("NEXT WEAPON: (1) PUMPGUN",310,10);
		}
		elseif(CurrentWeapon<=1)
		{
			dmessage("NEXT WEAPON: (2) HARPOON",310,10);
		}
		elseif(CurrentWeapon<=2)
		{
			dmessage("NEXT WEAPON: (3) FLAMETHROWER",310,10);
		}
		elseif(CurrentWeapon<=3)
		{
			dmessage("NEXT WEAPON: (4) BAZOOKA",310,10);
		}
		elseif(CurrentWeapon<=4)
		{
			dmessage("NEXT WEAPON: (5) TORCH",310,10);
		}
		elseif(CurrentWeapon<=5)
		{
			dmessage("NEXT WEAPON: (6) MAIMER",310,10);
		}
		elseif(CurrentWeapon<=6)
		{
			dmessage("NEXT WEAPON: (7) MACHINE GUN",310,10);
		}
		elseif(CurrentWeapon<=7)
		{
			dmessage("NEXT WEAPON: (8) PAK / ICE GUN",310,10);
		}
		elseif(CurrentWeapon<=8)
		{
			dmessage("NEXT WEAPON: (9) BUZZ SAW",310,10);
		}
		elseif(CurrentWeapon<=9)
		{
			dmessage("NEXT WEAPON: (10) AMMO WEAPONS",310,10);
		}
		elseif(CurrentWeapon<=10)
		{
			dmessage("NEXT WEAPON: (11) AMMO GRENADES",310,10);
		}
		elseif(CurrentWeapon<=11)
		{
			dmessage("NEXT WEAPON: (12) BATTERY GRABBER",310,10);
		}
		elseif(CurrentWeapon<=12)
		{
			dmessage("NEXT WEAPON: (13) BATTERY",310,10);
		}
		elseif(CurrentWeapon<=13)
		{
			dmessage("NEXT WEAPON: (14) MASER",310,10);
		}
		elseif(CurrentWeapon<=14)
		{
			dmessage("NEXT WEAPON: (15) SUBGIRL ROCKETPACK",310,10);
		}
		elseif(CurrentWeapon<=15)
		{
			dmessage("NEXT WEAPON: (16) SUBGIRL PACK",310,10);
		}





//		if(DebugOnlyOneWeapon==0)
//		{
			//float(_set,DebugOnlyOneWeapon,3)

			if(VKey==KEY_9 && VKey!=KEY_RSHIFT)
			{
				if(CurrentWeapon<=0)
				{
					spawnactor(WeaponPumpGun,0,150,-200);
				}
				elseif(CurrentWeapon<=1)
				{
					spawnactor(WeaponHarpoon,0,150,-200);
				}
				elseif(CurrentWeapon<=2)
				{
					spawnactor(WeaponFlameThrower,0,150,-200);
				}
				elseif(CurrentWeapon<=3)
				{
					spawnactor(WeaponBazooka,0,150,-200);
				}
				elseif(CurrentWeapon<=4)
				{
					spawnactor(WeaponTorch,0,150,-200);
				}
				elseif(CurrentWeapon<=5)
				{
					spawnactor(WeaponMaimer,0,150,-200);
				}
				elseif(CurrentWeapon<=6)
				{
					spawnactor(WeaponMachineGun,0,150,-200);
				}
				elseif(CurrentWeapon<=7)
				{
					spawnactor(WeaponPAK,0,150,-200);
				}
				elseif(CurrentWeapon<=8)
				{
					spawnactor(WeaponBuzzSaw,0,150,-200);
				}
				elseif(CurrentWeapon<=9)
				{
					spawnactor(WeaponAmmo,0,150,-200);
				}
				elseif(CurrentWeapon<=10)
				{
					spawnactor(WeaponAmmoGrenade,0,150,-200);
				}
				elseif(CurrentWeapon<=11)
				{
					spawnactor(WeaponBatteryGrabber,0,150,-200);
				}
				elseif(CurrentWeapon<=12)
				{
					spawnactor(BulletBattery,0,150,-200);
				}
				elseif(CurrentWeapon<=13)
				{
					call(DisplayFXPagesToggle,1);				//activate MASER gfx!!!

					float(_set,MaserKey,4);						//For Maser (built? charged?)
					spawnactor(WeaponMaser,0,150,-200);
				}
				elseif(CurrentWeapon<=14)
				{
					spawnactor(WeaponSubGirlRocketPack,0,150,-200);
				}
				elseif(CurrentWeapon<=15)
				{
					spawnactor(WeaponSubGirlPack,0,150,-200);
				}



				//else
				//{
				//	float(_set,DebugOnlyOneWeapon,0)
				//}
			}
//		}
//		else
//		{
//			float(_sub,DebugOnlyOneWeapon,1)
//		}
	}
}



SubRoutine(BackGroundTriggerChecks)
{
		//printi("Health:",VHealth);
		float(_seti,ColAngleTmp,VColAngle);
		float(_seti,ColAngleTmpFace,VColAngleFace);
		float(_seti,ColMaterial,VColMaterialProperties);

		if(AIVisionToggle==0)
		{
			call(AIVisionStatus,true);
		}
		else
		{
			call(AIVisionStatus,false);
		}

		if(VAICon==0)
		{
			if(VCheatCode==CHEAT_SPAWNAMMO&&CheatCode1<3)
			{
				spawnactor(WeaponAmmo,0,150,-200);
				float(_add,CheatCode1,1);
				message("weapon ammo",120,10);
			}
			elseif(VCheatCode==CHEAT_SPAWNBAZOOKA&&CheatCode2<3)
			{
				spawnactor(WeaponBazooka,0,150,-200);
				float(_add,CheatCode2,1);
				message("bazooka",120,10);
			}
			elseif(VCheatCode==CHEAT_SPAWNGRENADES&&CheatCode3<3)
			{
				spawnactor(WeaponAmmoGrenade,0,150,-200);
				float(_add,CheatCode3,1);
				message("grenades",120,10);
			}
			elseif(VCheatCode==CHEAT_GODMODE)
			{
				call(GodModeStatus,true);
				message("god mode"120,10);
			}
			elseif(VCheatCode==CHEAT_MORTALMODE)
			{
				call(GodModeStatus,false);
				message("mortal mode",120,10);
			}
			elseif(VCheatCode==CHEAT_AIOFF)
			{
				float(_set,aitoggle,1);
				message("ai off",120,10);
			}
			elseif(VCheatCode==CHEAT_AION)
			{
				float(_set,aitoggle,0);
				message("ai on",120,10);
			}
			elseif(VCheatCode==CHEAT_VISIONOFF)
			{
				float(_set,aivisiontoggle,1);
				message("ai vision off",120,10);
			}
			elseif(VCheatCode==CHEAT_VISIONON)
			{
				float(_set,aivisiontoggle,0);
				message("ai vision on",120,10);
			}
			elseif(VCheatCode==CHEAT_CWIREFRAMEON)
			{
				message("character wireframe on",120,10);
			}
			elseif(VCheatCode==CHEAT_CWIREFRAMEOFF)
			{
				message("character wireframe off",120,10);	
			}
			elseif(VCheatCode==CHEAT_WWIREFRAMEON)
			{
				message("world wireframe on",120,10);
			}
			elseif(VCheatCode==CHEAT_WWIREFRAMEOFF)
			{
				message("world wireframe off",120,10);
			}
			elseif(VCheatCode==CHEAT_SHOWPOLYS)
			{
				message("polycount on",120,10);
			}
			elseif(VCheatCode==CHEAT_HIDEPOLYS)
			{
				message("polycount off",120,10);
			}
			elseif(VCheatCode==CHEAT_TORCH)
			{
				spawnactor(WeaponTorch,0,150,-200);
				message("welding torch",120,10);
			}
			elseif(VCheatCode==CHEAT_CHAINSAW)
			{
				spawnactor(WeaponBuzzSaw,0,150,-200);
				message("buzz saw",120,10);
			}
			elseif(VCheatCode==CHEAT_PUMPGUN)
			{
				spawnactor(WeaponPumpGun,0,150,-200);
				message("pumpgun",120,10);
			}
			elseif(VCheatCode==CHEAT_MACHINGUN)
			{
				spawnactor(WeaponMachineGun,0,150,-200);
				message("machinegun",120,10);
			}
			elseif(VCheatCode==CHEAT_MAIMER)
			{
				spawnactor(WeaponMaimer,0,150,-200);
				message("maimer",120,10);
			}
			elseif(VCheatCode==CHEAT_FLAMETHROWER)
			{
				spawnactor(WeaponFlameThrower,0,150,-200);
				message("flame thrower",120,10);
			}
			elseif(VCheatCode==CHEAT_ICEPACK)
			{
				spawnactor(WeaponPAK,0,150,-200);
				message("pak gun",120,10);
			}
			elseif(VCheatCode==CHEAT_BAZOOKA)
			{
				spawnactor(WeaponBazooka,0,150,-200);
				message("bazooka",120,10);
			}
			elseif(VCheatCode==CHEAT_MASER)
			{
				call(DisplayFXPagesToggle,1);				//activate MASER gfx!!!

				float(_set,MaserKey,4);						//For Maser (built? charged?)
				spawnactor(WeaponMaser,0,150,-200);
				message("maser",120,10);
			}
			elseif(VCheatCode==CHEAT_HARPOON)
			{	
				spawnactor(WeaponHarpoon,0,150,-200);
				message("Harpoon Gun",120,10);
			}
			elseif(VCheatCode==CHEAT_WEAPONAMMO)
			{
				spawnactor(WeaponAmmo,0,150,-200);
				message("weapon ammo",120,10);
			}
			elseif(VCheatCode==CHEAT_GRENADES)
			{
				spawnactor(WeaponAmmoGrenade,0,150,-200);
				message("grenades",120,10);
			}
			elseif(VCheatCode==CHEAT_LIGHTCOP)
			{
				spawnactor(copl,0,150,-200);
				message("light cop",120,10);
			}
			elseif(VCheatCode3==CHEAT_MEDIUMCOP)
			{
				spawnactor(copm,0,150,-200);
				message("medium cop",120,10);
			}
			elseif(VCheatCode==CHEAT_HEAVYCOP)
			{
				spawnactor(coph,0,150,-200);
				message("heavy cop",120,10);
			}
			elseif(VCheatCode==CHEAT_RIOTCOP)
			{
				spawnactor(copr,0,150,-200);
				message("riot cop",120,10);
			}
			elseif(VCheatCode2==CHEAT_GUNCOMMANDER)
			{
				spawnactor(GunCommander,0,150,-200);	
				message("gun commander",120,10);
			}
			elseif(VCheatCode2==CHEAT_DOMINA)
			{
				spawnactor(domina,0,150,-200);
				message("domina",120,10);
			}
			elseif(VCheatCode2==CHEAT_ABEHEMOTH)
			{
				spawnactor(abeast,0,150,-200);
				message("Armored Behemoth",120,10);
			}
			elseif(VCheatCode2==CHEAT_WELDER)
			{
				spawnactor(worker,0,150,-200);
				message("welder",120,10);
			}
			elseif(VCheatCode2==CHEAT_WORKER)
			{
				spawnactor(worker2,0,150,-200);
				message("worker",120,10);
			}
			elseif(VCheatCode2==CHEAT_SCIENTIST)
			{
				spawnactor(scientist,0,150,-200);
				message("scientist",120,10);
			}
			elseif(VCheatCode2==CHEAT_NUKETECH)
			{
				spawnactor(RadiationWorker,0,150,-200);
				message("radiation worker",120,10);
			}
			elseif(VCheatCode2==CHEAT_MEDIC)
			{
				spawnactor(medic,0,150,-200);
				message("medic",120,10);
			}
			elseif(VCheatCode2==CHEAT_CHOT1)
			{
				spawnactor(chotct,0,150,-200);
				message("chot 1",120,10);
			}
			elseif(VCheatCode2==CHEAT_CHOT2)
			{
				spawnactor(chot,0,150,-200);
				message("chot 2",120,10);
			}
			elseif(VCheatCode2==CHEAT_CHOT3)
			{
				spawnactor(chotmot,0,150,-200);
				message("chot 3",120,10);
			}
			elseif(VCheatCode2==CHEAT_CHOT4)
			{
				spawnactor(chot2,0,150,-200);
				message("chot 4",120,10);
			}
			elseif(VCheatCode2==CHEAT_CHOTDWARF)
			{
				spawnactor(chotdwarf,0,150,-200);
				message("chot dwarf",120,10);
			}
			elseif(VCheatCode2==CHEAT_CBEHEMOTH)
			{
				spawnactor(chotbeast,0,150,-200);
				message("chot behemoth",120,10);
			}
			elseif(VCheatCode2==CHEAT_LAYYA)
			{
				spawnactor(Layya,0,150,-200);
				message("layaa",120,10);
			}
			elseif(VCheatCode2==CHEAT_PROST1)
			{
				spawnactor(prost1,0,150,-200);
				message("Prost 1",120,10);
			}
			elseif(VCheatCode2==CHEAT_PROST2)
			{
				spawnactor(prost2,0,150,-200);
				message("Prost 2",120,10);
			}
			elseif(VCheatCode2==CHEAT_HUNG)
			{
				spawnactor(hung,0,150,-200);
				message("Hung",120,10);
			}
			elseif(VCheatCode2==CHEAT_DWELLER1)
			{
				spawnactor(Dweller1,0,150,-200);
				message("Male Dweller 1",120,10);
			}
			elseif(VCheatCode2==CHEAT_DWELLER2)
			{
				spawnactor(Dweller2,0,150,-200);
				message("Male Dweller 2",120,10);
			}
			elseif(VCheatCode2==CHEAT_DWELLER3)
			{
				spawnactor(Dweller3,0,150,-200);
				message("Male Dweller 3",120,10);
			}
			elseif(VCheatCode2==CHEAT_FEMDWELLER1)
			{
				spawnactor(FemDweller1,0,150,-200);
				message("Female Dweller 1",120,10);
			}
			elseif(VCheatCode2==CHEAT_FEMDWELLER2)
			{
				spawnactor(FemDweller2,0,150,-200);
				message("Female Dwelelr 2",120,10);
			}
			elseif(VCheatCode2==CHEAT_SUBGIRL1)
			{
				spawnactor(subgirl1,0,150,-200);
				message("subgirl 1",120,10);
			}
			elseif(VCheatCode2==CHEAT_SUBGIRL2)
			{
				spawnactor(subgirl2,0,150,-200);
				message("subgirl 2",120,10);
			}
			elseif(VCheatCode2==CHEAT_RAT)
			{
				spawnactor(rat,0,150,-200);
				message("rat",120,10);
			}
			elseif(VCheatCode2==CHEAT_BARMAN)
			{
				spawnactor(barman,0,150,-200);
				message("barman",120,10);
			}
			elseif(VCheatCode2==CHEAT_WAITRESS)
			{
				spawnactor(nun,0,150,-200);
				message("waitress",120,10);
			}
			elseif(VCheatCode2==CHEAT_DANCER1)
			{
				spawnactor(Dancer1,0,150,-200);
				message("dancer 1",120,10);
			}
			elseif(VCheatCode2==CHEAT_DANCER2)
			{
				spawnactor(dancer2,0,150,-200);
				message("dancer 2",120,10);
			}
			elseif(VCheatCode2==CHEAT_DJ)
			{
				spawnactor(djkyd,0,150,-200);
				message("dj",120,10);
			}
			elseif(VCheatCode3==CHEAT_BOUNCER)
			{
				spawnactor(bouncer,0,150,-200);
				message("bouncer",120,10);
			}
			elseif(VCheatCode3==CHEAT_PIMP)
			{
				spawnactor(Pimp,0,150,-200);
				message("pimp daddy",120,10);
			}
			elseif(VCheatCode3==CHEAT_BEHEMOTH)
			{
				spawnactor(beast,0,150,-200);
				message("behemoth",120,10);
			}
			elseif(VCheatCode3==CHEAT_OFFENSIVEBOT)
			{
				spawnactor(OffensiveBot,0,150,-200);
				message("offensive bot",120,10);
			}
			elseif(VCheatCode3==CHEAT_COMPANIONBOT)
			{
				spawnactor(CompanionBot,0,150,-200);
				message("companion bot",120,10);
			}
			elseif(VCheatCode3==CHEAT_FREEZECAMON)
			{
				message("freeze camera on",120,10);
			}
			elseif(VCheatCode3==CHEAT_FREEZECAMOFF)
			{
				message("freeze camera off",120,10);
			}
			elseif(VCheatCode3==CHEAT_ENDSEQUENCE)
			{
				message("end sequence",120,10);
				call(PlaySequence,0);		//play end sequence

				call(wCheckViewCollision,-1,-1,-1,0);	//fade to black
				call(wCheckViewCollision,0,0,-2,-1);	//fade to white
				call(CDSwap,7,0,100,60);	//example: new track, newloopstate, new vol, fade time
				call(HUDTimerSet,1800);		//example: starts displaying and counting down from 60 seconds :: call once, not every frame!
			}

		}

			if(VKey==KEY_RBRACKET)
			{
				call(GodModeStatus,true);
				dmessage("GOD MODE",30,150);
			}
			elseif(VKey==KEY_LBRACKET)
			{
				call(GodModeStatus,false);
				dmessage("MORTAL MODE",30,150);
			}


		if(VKey==KEY_RSHIFT && VKey==KEY_T)
		{
			float(_seti,TmpFloat,VGameCounter);
			float(_sub,TmpFloat,LastTuturialChange);
			if(TmpFloat>4)
			{
				float(_seti,LastTuturialChange,VGameCounter);

				if(tutorialtoggle==0)
				{
					float(_set,tutorialtoggle,1);
					message("Tutorial On",200,10);
				}
				elseif(tutorialtoggle==1)
				{
					float(_set,tutorialtoggle,0);
					message("Tutorial Off",200,10);
				}
			}
		}


		direction(_clr,_DIRTempFlag);

		call(CheckTriggers);
		
		if(vAICon==0)
		{
			if(VClass==_ClassAngel)
			{
				call(CheckForPickup,4,_ClassPickup);	//pickups only
			}
			else
			{
				call(CheckForPickup,8,_ClassAmmoPickup);	//Both ammo and pickups
			}
			vector(_settoactorpos,PlayerPos);
		}

		if(VRunScriptCode==1)
		{	
			CallSub(BackGroundTriggerChecksScene1)
		}
		if(VRunScriptCode==2)
		{
			CallSub(BackGroundTriggerChecksScene2)
		}
		if(VRunScriptCode==3)
		{
			CallSub(BackGroundTriggerChecksScene3)
		}
		if(VRunScriptCode==4)
		{
			CallSub(BackGroundTriggerChecksScene4)
		}
		if(VRunScriptCode==5)
		{
			CallSub(BackGroundTriggerChecksScene5)
		}
		if(VRunScriptCode==6)
		{
			CallSub(BackGroundTriggerChecksScene6)
		}
		if(VRunScriptCode==7)
		{
			CallSub(BackGroundTriggerChecksScene7)
		}
		if(VRunScriptCode==8)
		{
			CallSub(BackGroundTriggerChecksScene8)
		}
		if(VRunScriptCode==9)
		{
			CallSub(BackGroundTriggerChecksScene9)
		}
		if(VRunScriptCode==10)
		{
			CallSub(BackGroundTriggerChecksScene10)
		}
		if(VRunScriptCode==11)
		{
			CallSub(BackGroundTriggerChecksScene11)
		}
		if(VRunScriptCode==12)
		{
			CallSub(BackGroundTriggerChecksScene12)
		}
		if(VRunScriptCode==13)
		{
			CallSub(BackGroundTriggerChecksScene13)
		}
		if(VRunScriptCode==14)
		{
			CallSub(BackGroundTriggerChecksScene14)
		}
		if(VRunScriptCode==15)
		{
			CallSub(BackGroundTriggerChecksScene15)
		}
		if(VRunScriptCode==16)
		{
			CallSub(BackGroundTriggerChecksScene16)
		}
		if(VRunScriptCode==17)
		{
			CallSub(BackGroundTriggerChecksScene17)
		}
		if(VRunScriptCode==18)
		{
			CallSub(BackGroundTriggerChecksScene18)
		}
		if(VRunScriptCode==19)
		{
			CallSub(BackGroundTriggerChecksScene19)
		}
		elseif(VCurScene==20)
		{
			CallSub(BackGroundTriggerChecksScene20)
		}
		elseif(VCurScene==21)
		{
			CallSub(BackGroundTriggerChecksScene21)
		}
		elseif(VCurScene==22)
		{
			CallSub(BackGroundTriggerChecksScene22)
		}
}

SubRoutine(ReadKeyJoy)
{
		Direction(_clr,_DIRairemoveflags);
		Direction(_clr,_DIRdepossesion);
		Direction(_clr,_DIRcrouch);

		if(VAnalog2<-0.7||VAnalog2>0.7||VAnalog3>0.7||VAnalog3<-0.7)
		{
			Direction(_clr,_DIRwalking);
//Running (The 0.6 and 0.7 barriers are selected to ease diagonal movement. Do not set to the same value!)
			if(VAnalog2<=-0.6)			//Threshold here must be higher than when walking
			{
				Direction(_set,_DIRbackward);
			}
			elseif(VAnalog2>=0.6)
			{
				Direction(_set,_DIRforward);
			}
			if(VAnalog3<=-0.6)
			{
				Direction(_set,_DIRsideleft);
			}
			elseif(VAnalog3>=0.6)
			{
				Direction(_set,_DIRsideright);
			}
		}
		elseif(VAnalog2<-0.3||VAnalog2>0.3||VAnalog3>0.3||VAnalog3<-0.3)	//This comparison must be here for easing diagonal walking.
		{
//walking
			Direction(_set,_DIRwalking);
			if(VAnalog2<=-0.20)
			{
				Direction(_set,_DIRbackward);
			}
			elseif(VAnalog2>=0.20)
			{
				Direction(_set,_DIRforward);
			}
			if(VAnalog3<=-0.20)
			{
				Direction(_set,_DIRsideleft);
			}
			elseif(VAnalog3>=0.20)
			{
				Direction(_set,_DIRsideright);
			}
		}

		if(VAnalog1>0)
		{
			Direction(_set,_DIRright)
		}
		elseif(VAnalog1<0)
		{
			Direction(_set,_DIRleft)
		}

		if(VInput==_SXIbutton1)
		{
			Direction(_set,_DIRjump);
		}
		if(VInput==_SXIbutton2)
		{
			Direction(_set,_DIRaction);
		}

		if(VInput==_SXIbutton6)
		{
			Direction(_set,_DIRdepossesion)
		}
		if(VInput==_SXIbutton7)
		{
			Direction(_set,_DIRcrouch);
		}
		
		if(SniperToggle==1)
		{
			if(VInput==_SXIbutton8 && VOInput!=_SXIbutton8)
			{
				if(SniperMode==0)
				{
					call(ChangeSniperMode,1,0);
				}
				else
				{
					call(ChangeSniperMode,1,1);
				}
			}
			if(VInput==_SXIbutton9 && VOInput!=_SXIbutton9)
			{
				if(SniperMode==0)
				{
					call(ChangeSniperMode,-1,0);
				}
				else
				{
					call(ChangeSniperMode,-1,1);
				}
			}
			if(VInput==_SXIbutton10 && VOInput==_SXIbutton10)
			{
				if(VFreeLook==0)
				{
					call(FreeLook,TRUE);
				}
			}
			elseif(VFreeLook!=0)
			{
				call(FreeLook,FALSE);
			}
		}

		if(VInput==_SXIbutton11)
		{
			if(BobMessage==0)
			{
				call(DisplayObjectives);
			}
			elseif(BobMessage==1)
			{
				float(_set,Dazed,1);
				float(_set,BlinkTimer,0);
				float(_set,BobMessage,2);
				float(_set,GodTimer,0);
			}
		}

		if(VInput==_SXIbutton12 && VOInput!=_SXIbutton12 && VZoomExit==0)
		{
			call(ChangeSniperMode,-3,0);						//zoom all the way out of snipermode
		}

		if(VInput==_SXIbutton3)
		{
			Direction(_set,_DIRshoot);
		}
		if(VInput==_SXIbutton4)
		{
			Direction(_set,_DIRgrenade);
		}
/*
		if(VInput==_SXIbutton5)
		{
			Direction(_set,_DIRlaser);
		}
*/
		if(VTrigger|=_DIRMoveBits)
		{
			Direction(_set,_DIRMove);
		}
		else
		{
			Direction(_set,_noDIR);
		}

}


#include	"messiahscripts\particles\FlicHeaders.hxx"
#include	"messiahscripts\particles\ParticleSubs.hxx"
#include	"messiahscripts\particles\particle.hxx"

#include	"messiahscripts\enemies\EnemyHeaders.hxx"
#include	"messiahscripts\weapons\BulletHeaders.hxx"
#include	"messiahscripts\weapons\WeaponHeaders.hxx"

#include	"messiahscripts\sound\soundcode.hxx"

#include	"messiahscripts\enemies\SharedFXCode.hxx"

#include	"messiahscripts\weapons\BulletWeaponActions.hxx"
#include	"messiahscripts\weapons\Bullets.hxx"
#include	"messiahscripts\weapons\Weapons.hxx"

#include	"messiahscripts\enemies\SharedAnimCode.hxx"

#include	"messiahscripts\enemies\GenActions.hxx"

#include	"messiahscripts\bobactions.hxx"
#include	"messiahscripts\enemies\copactions.hxx"		//Action for Cops and Various Character
#include	"messiahscripts\enemies\chot1.hxx"			//Specific Actions For Chots
#include	"messiahscripts\enemies\femactions.hxx"
//#include	"messiahscripts\enemies\SubGirlActions.hxx"	//obsolete
//#include	"messiahscripts\enemies\domactions.hxx"		//obsolete
#include	"messiahscripts\enemies\abeastactions.hxx"
#include	"messiahscripts\enemies\beastactions.hxx"
#include	"messiahscripts\enemies\satanactions.hxx"

#include	"messiahscripts\enemies\shared.hxx"			//shared subroutines
#include	"messiahscripts\enemies\sharedMove.hxx"		//more shared subroutines
#include	"messiahscripts\enemies\SharedAIMove.hxx"	//shared subroutines for AI control
#include	"messiahscripts\enemies\GameScripts.hxx"	//Help texts throughout the game

#include	"messiahscripts\enemies\sharedPain.hxx"		//more shared subroutines

#include	"messiahscripts\bob5.hxx"

#include	"messiahscripts\StagesEnemies.hxx"
