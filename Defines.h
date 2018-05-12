
#ifndef __SAXS_DEFINES_H__
#define __SAXS_DEFINES_H__



#define	_ActionOpenDoor				1
#define	_ActionActivatePanel		2
#define	_ActionSwapWeapon			3
#define	_ActionDropWeapon			4
#define	_ActionPickupWeapon			5
#define	_ActionExitCombatMode		6
#define	_ActionActivateLift			7

#define	_pFuncBlood					0
#define	_pFuncNormal				1
#define	_pFuncFollowSinus			2

#define	_ExplodeGlass				1
#define	_ExplodeBig					2
#define	_ExplodeCrumble				4
#define	_ExplodeAmmoGrenades		8
#define	_ExplodeSmall				16
#define	_ExplodeAmmo				32
#define	_ExplodeRipple				64
#define	_ExplodeWater				128
//DynamicCollision:: 8 bits max

#define	_DifficultyEasy				0
#define	_DifficultyMedium			1
#define	_DifficultyHard				2

#define	_sFLAGPickedUpGun			1
#define	_sFLAGPickedUpAmmo			2
#define	_sFLAGTargetAimKillShot		4
#define	_sFLAGTargetAimCloseRange	8
#define	_sFLAGOMatrixFlag			16
#define	_sFLAGTrodInGoo				32
#define	_sFLAGCloseToWall			64
#define	_sFLAGTargetLockedOn		128
#define	_sFLAGLastTargetLockedOn	256 
#define	_sFLAGTargetChanged			512
#define	_sFLAGTargetOnScenery		1024
#define	_sFLAGLeftFoot				2048
#define	_sFLAGRightFoot				4096
#define	_sFLAGFootCollide			8192
#define	_sFLAGMatrixRecalc			16384
#define	_sFLAGLostALimb				32768
//SpecialFlag:: 16 bits max

#define	_fxFLAGFire					1
#define	_fxFLAGSmoke				2
#define	_fxFLAGBackground			4
//FXFlag:: 8 bits max


#define	CHEAT_SPAWNAMMO				0x1
#define	CHEAT_SPAWNBAZOOKA			0x2
#define	CHEAT_SPAWNGRENADES			0x4
#define	CHEAT_GODMODE				0x8
#define	CHEAT_MORTALMODE			0x10
#define	CHEAT_AIOFF					0x20
#define	CHEAT_AION					0x40
#define	CHEAT_VISIONOFF				0x80
#define	CHEAT_VISIONON				0x100
#define	CHEAT_CWIREFRAMEON			0x200
#define	CHEAT_CWIREFRAMEOFF			0x400
#define	CHEAT_WWIREFRAMEON			0x800
#define	CHEAT_WWIREFRAMEOFF			0x1000
#define	CHEAT_SHOWPOLYS				0x2000
#define	CHEAT_HIDEPOLYS				0x4000
#define	CHEAT_TORCH					0x8000
#define	CHEAT_CHAINSAW				0x10000	
#define	CHEAT_PUMPGUN				0x20000				
#define	CHEAT_MACHINGUN				0x40000
#define	CHEAT_MAIMER				0x80000
#define	CHEAT_FLAMETHROWER			0x100000
#define	CHEAT_ICEPACK				0x200000
#define	CHEAT_BAZOOKA				0x400000
#define	CHEAT_MASER					0x800000
#define	CHEAT_HARPOON				0x1000000
#define	CHEAT_WEAPONAMMO			0x2000000
#define	CHEAT_GRENADES				0x4000000
#define	CHEAT_LIGHTCOP				0x8000000
#define	CHEAT_HEAVYCOP				0x20000000
#define	CHEAT_RIOTCOP				0x40000000
//32
#define	CHEAT_GUNCOMMANDER			0x1
#define	CHEAT_DOMINA				0x2
#define	CHEAT_ABEHEMOTH				0x4
#define	CHEAT_WELDER				0x8
#define	CHEAT_WORKER				0x10
#define	CHEAT_SCIENTIST				0x20
#define	CHEAT_NUKETECH				0x40
#define	CHEAT_MEDIC					0x80
#define	CHEAT_CHOT1					0x100
#define	CHEAT_CHOT2					0x200
#define	CHEAT_CHOT3					0x400
#define	CHEAT_CHOT4					0x800
#define	CHEAT_CHOTDWARF				0x1000
#define	CHEAT_CBEHEMOTH				0x2000
#define	CHEAT_LAYYA					0x4000	
#define	CHEAT_PROST1				0x8000
#define	CHEAT_PROST2				0x10000
#define	CHEAT_HUNG					0x20000
#define	CHEAT_DWELLER1				0x40000
#define	CHEAT_DWELLER2				0x80000
#define	CHEAT_DWELLER3				0x100000
#define	CHEAT_FEMDWELLER1			0x200000
#define	CHEAT_FEMDWELLER2			0x400000
#define	CHEAT_SUBGIRL1				0x800000
#define	CHEAT_SUBGIRL2				0x1000000
#define	CHEAT_RAT					0x2000000
#define	CHEAT_BARMAN				0x4000000
#define	CHEAT_WAITRESS				0x8000000
#define	CHEAT_DANCER1				0x10000000
#define	CHEAT_DANCER2				0x20000000
#define	CHEAT_DJ					0x40000000
//32
#define	CHEAT_PIMP					0x1
#define	CHEAT_BEHEMOTH				0x2
#define	CHEAT_OFFENSIVEBOT			0x4
#define	CHEAT_COMPANIONBOT			0x8
#define	CHEAT_FREEZECAMON			0x10
#define	CHEAT_FREEZECAMOFF			0x20
#define	CHEAT_ENDSEQUENCE			0x40
#define	CHEAT_BOUNCER				0x80
#define	CHEAT_MEDIUMCOP				0x10000000
//32

#define	_noDIR					0x1

#define	_DIRleft				0x2
#define	_DIRright				0x4

#define	_DIRforward				0x8
#define	_DIRbackward			0x10
#define	_DIRsideleft			0x20
#define	_DIRsideright			0x40
#define	_DIRwalking				0x80
#define	_DIRalive				0x100
#define	_DIRactoractorcol		0x200
#define	_DIRnotai				0x400
#define	_DIRjump				0x800
#define	_DIRshoot				0x1000
#define	_DIRgrenade				0x2000
#define	_DIRaction				0x4000
#define	_DIRdepossesion			0x8000
#define	_DIRillegalweapon		0x10000
#define	_DIRcombatmode			0x20000
#define _DIRMove				0x40000	//Set if any of the moveflags are set

#define	_DIRhorcol				0x80000
#define	_DIRvercol				0x100000
#define	_DIRactorbulletcol		0x200000
#define	_DIRpossesion			0x400000
#define	_DIRhavegun				0x800000
#define	_DIRcrouch				0x1000000
#define	_DIREnvTrigger			0x2000000

#define	_DIRTempFlag			0x4000000
#define	_DIRBulletFired			_DIRTempFlag

#define _DIRNotEndOfAnim		0x8000000
#define _DIRCloseToCollision	0x10000000	//Set when close to collision with fire, steam or explosion
#define _DIRHeavyRecoil			0x20000000

#define _DIRactionhold			0x40000000	//for when the action button is held down


#define	_DIRairemoveflags		0x4fcff			//all flags under 0x80000 except _DIRcombatmode,_DIRactoractorcol _DIRillegalweapon and _DIRdead
#define	_DIRallcol				0x180000		//_DIRvercol|_DIRhorcol
#define _DIRWalkBits			0x80		//0x78
#define _DIRRunBits				0x78		//0x780
#define _DIRMoveBits			0x78		//0x7f8
//Which flags not to delete at start of frameupdate (for playercontrolled characters only)
#define	_DIRkeepflags			(_DIRnotai|_DIRalive|_DIRactoractorcol|_DIRcombatmode|_DIRNotEndOfAnim|_DIRpossesion|_DIREnvTrigger|_DIRhavegun|_DIRallcol|_DIRactorbulletcol|_DIRCloseToCollision)
//Which flags to delete at end of frameupdate
#define	_DIRdeleteflags			(_DIRcrouch|_DIRpossesion|_DIRactorbulletcol|_DIREnvTrigger|_DIRdepossesion|_DIRCloseToCollision)
#define	_allDIR					-1


#define	_ActionNoShadow			1
#define	_ActionBreak			2
#define	_ActionNoMove			4
#define	_ActionOffset			8
#define	_ActionCollisionOff		16
#define	_ActionGravityOff		32
#define	_ActionIntForLoop		64
#define	_ActionGlobalRootYChg	128

#define	_ActionActive			1
#define	_ActionPassive			2

#define	_ActorFollow			1
#define	_ActorControl			2
#define	_ActorFirstLoop			4
#define	_ActorEndOfAnim			8
#define	_ActorAnimObj			16
#define	_ActorStaticObj			32
#define	_ActorSpriteObj			64
#define	_ActorHaveGun			128
#define	_ActorNoDirectionalLight 256

#define	_PlayerOneCon			0
#define	_AICon					2

#define	_CamDistance			400		/*default*/
#define	_CamHeight				105		/*default*/


#define	VEndOfAnim				1
#define	VAICon					2
#define	VAction					3
#define	VTrigger				4
#define	VCheatCode				5
#define	VRnd					6
#define	VState					7
#define	VPlayer1Distance		8
#define	VSniperModeGlobal		9
#define	VCheatCode2				10
#define	VCheatCode3				11
//#define	VPassive				12
//#define	VSighting				13
//#define	VNearestActor			14
#define	VAttachActorHealth		15
#define	VActiveTime				16
#define	VFrame					17
#define	VColAngle				18
#define	VPickDestAngle			19
#define	VPickDestOffsetY		20
#define	VKey					21
#define	VAttrib					22
#define	VDistToGround			23
#define	VColFlag				24
#define	VColDistance			25
#define	VColMaterialProperties	26
#define	VCurScene				27
#define	VGameCounter			28
#define	VCurSet					29
#define	VSetActive				30
#define	VClass					31
#define	VRank					32
#define	VKeyObjFrame			33
#define	VKeyObjTriggered		34
#define	VPathDestDistance		35

#define	VPathDestAngle			36
#define	VTargetAngle			37
#define	VTargetAngleY			38
#define	VTargetDistance			39
#define	VColNrRebounds			40
#define	VColNrVerRebounds		41
#define	VOTrigger				42
#define	VColSphereSize			43
#define	VColAngleFace			44
#define	VActor					45
#define VColFeetSphereSize		46
#define VColFeetSphereBottom	47
#define	VColSphereScale			48
#define	VActorColType			49
#define	VHealth					50
#define VActionRotation			51
#define	VInStateCounter			52
#define	VInput					53
#define	VAnalog1				54
#define	VAnalog2				55
#define	VAnalog3				56
#define	VInventoryLeft			57
#define	VInventoryType			58
#define	VActionList				59
#define	VKeyObjFrameNoShift		60
#define	VOAction				61
#define	VPickDestAngleCorr		62
#define	VSniperMode				63
#define	VOSniperMode			64
#define	VDirectionHold			65
#define VAIClass				66
#define VActorFlag				67
#define	VCoreAICon				68
#define	VDynamicCollision		69
#define VActivateButton			70
#define	VRootAIClass			71
#define	VRootRank				72
#define	VColBone				73
#define	VDifficulty				74
#define	VActionIndex			75
#define	VFXFlag					76
#define VCheatKeys				77
#define	VOInput					78
#define VFirstPerson			79
#define	VParentTrigger			80
#define	VColObjTriggered		81
#define VOHealth				82
#define VColSphereOffsetY		83
#define	VWeaponAmmoType			84
#define	VWeaponType				85
#define	VWeaponAmmoLeft			86
#define VDeadClass				87
#define	VDeadRank				88
#define	VDeadAIClass			89
#define	VCutScene				90
#define	VCutSceneFrame			91
#define	VFreeLook				92
#define	VLockedColBone			93
#define	VCutSceneFrameEqual		94
#define	VLockedOnAngle			95
#define	VSpecialFlag			96
#define VKeyObjDirection		97
#define VInitSceneSounds		98
#define VPathID					99
#define VEXPCamera				100
#define VActionCode				101
#define	VHasParent				102
#define VRunScriptCode			103
#define VInitScriptCode			104
#define VScriptInitiated		105
#define	VKeyObjWait				106
#define VCDToggle				107
#define VHUDDisplayTimer		108
#define	VOKey					109
#define	VCDPlay					110
#define	VCDTrack				111
#define	VZoomExit				112
#define	VSetInMemory			113
#define	VActorWeapon			114
#define	VCombatMusic			115
#define VLanguage				116
#define	VPickupClose			117
#define VParenAttachActor		118

#define	VAItimeforupdate		200
#define	VAIleader				201		//AI specific calls
#define	VAIgroupstate			202
#define	VAInotargettime			203
#define	VAItargetfound			204
#define	VAIgrouphealth			205
#define	VAIpowerrating			206
#define	VAIgroupleft			207
#define	VAItimeincurrentorder	208
#define	VAIlasttargetfound		209
#define	VAInringroup			210
#define	VAIingroup				211
#define	VAIrebel				212
#define	VAIhealth				213
#define	VAIaskedtojoin			214
#define	VAIchangetonewgroup		215
#define	VAIstate				216
#define	VAIstatehigh			217
#define	VAIlaststate			218
#define	VAIstatechanged			219
#define	VAIleaderaspirations	220
#define	VAIhideheight			221
#define	VAIcornerangle			222
#define	VAIcornerdistance		223
#define	VAIhidenodenear			224
#define	VAItimenottarget		225
#define	VAItargetclass			226
#define	VAInrattackingplayer	227
#define	VAIenemiesattackingplayerstrenght	228		//only for PlayerOne
#define	VAItargetstrenght		229
#define	VAItargethealth			230
#define	VAInrattackingactor		231
#define	VAImanpowerindex		232
#define	VAItargettrigger		233					//used to check direction bits on target actor
#define	VAItargetseenme			234					//am I in target's CurrentlyVisible list
#define	VAIhastarget			235					//do I have a target?
#define	VAIhaspath				236					//do I have a path?
#define	VAItargetvisible		237					//can I see my TargetActor?
#define	VAIlosttargetptr		238					//if entity to actor dleted the targetptr
#define	VAITargetIsFriend		239
#define	VAIQhasillegalweapon	240
#define	VAIhaslockedonactor		241
#define	VAIPlayer1IsTarget		242
#define	VAIQnumberframesagainstwall	243
#define	VAIQtargetislockedonactor	244

#define	FSpawnActor				1
#define	FInitActor				2
#define	FKillActor				3
#define	FCall					4
#define	FSample					5
#define	FMove					6
#define	FSpawnAction			7
#define	FState					8
#define	FDirection				9
#define	FType					10
#define	FAIPickDest				11
#define	FTurn					12
#define	FCalcLocalTurnMat		13
#define	FScaleBoneMatrix		14
#define	FCamera					15
#define	FTarget					16
#define	FFloat					17
#define	FVector					18
#define	FCameraRot				19
#define	FRotateBone				20
#define	FResetBone				21
#define	FCenterBone				22
#define	FPrint					23
#define	FPrintI					24
#define	FPrintLog				25
#define	FPrintILog				26
#define	FCollision				27
#define	FSetFrame				28
#define	FSpawnParticle			29
#define	FSpawnLight				30
#define	FSpawnGooFX				31
#define	FCallSub				32
#define	FBreak					33
#define	FCurEnvTrigger			34
#define	FSetKeyFrame			35
#define	FMessage				36
#define	FAIGroupPickDest		37
#define	FCameraGroundClearance	38
#define	FCheckActorCollision	39
#define	FClrStateCounter		40
#define FSetActorToTrigger		41
#define	FFXFlag					42
#define	FCurEnvTriggerSet		43
#define	FSampleStop				44
#define	FPCall					45
#define	FKFSample				46
#define	FColState				47
#define	FTriggerMessage			48
#define	FDMessage				49
#define FActorFlag				50
#define	FChangeMaterialFlags	51
#define	FGetNumbActorsInSet		52
#define FMoveFeetColOffset		53
#define	FSlope					54
#define	FRotate					55			//rotat root bone about local axis
#define FFirstPerson			56
#define	FSampleVolume			57
#define FColObj					58
#define	FSpawnActorBone			59
#define	FCutScene				60
#define FKillLight				61
#define FMissionObjective		62
#define	FSpawnActorKFObj		63
#define	FDebugMessage			64
#define FAddTutorialLine		65
#define FClearTutorialLines		66
#define FDisplayTutorialScreen	67
#define FHideTutorialScreen		68
#define	FGravity				69
#define	FPrintH					70
#define	FPrintIH				71
#define	FClearDMessage			72
#define	FSpecialFlag			73
#define	FSpawn3DFlare			74			//the only special case fx
#define	FCopyObjectToObject		75			//copy vertices from object to object (source,destination)
#define FMessageXY				76
#define	FSamplePlaying			77
#define	FSphereCollision		78

#define	CheckForPickup				0
#define	CheckAttached				1
#define	CheckForPossesion			2
#define	CheckBulletCollision		3
#define	CheckBoneCollision			4
#define	CheckActorCollision			5
#define	CheckForGrab				6
#define	AttachLockedActor			7
#define	AttachToActor				8
#define	CheckForVisual				9
#define	WallBulb					10
#define	DrawLaserBeam				11
#define	CDPlay						12
#define	CDStop						13
#define	CDPause						14
#define	CDResume					15
#define	BonePointTrack				16
#define	KeyObjTrigger				17		//control triggering of keyobjs (endframe,direction,OPTIONAL: triggervalue) direction==0 && triggervalue==0 -> stop object from mving
#define	KeyObjActiveSegment			18
#define	KeySpeed					19
#define	EXPSet1						20
#define	EXPSet2						21
#define	LightBulb					22
#define	ChangeAlpha					23
#define	ReDrawActor					24
#define	CheckConnections			25
#define	CameraFollow				26
#define	AICon						27
#define SubtractHealth				28
#define	IsPickupClose				29
#define	ModelAmbient				30
#define	ChangeInventory				31
#define	ForceRunning				32
#define	SetParticleSetID			33
#define ThrowCharacter				34
#define CheckTriggers				35
#define ActivateButton				36
#define ExecuteActivateCode			37
#define	pScale						38		//particle call types
#define	pFlicControl				39
#define	pColor						40
#define	pAngle						41
#define	pRotate						42
#define	pTrans						43
#define	pFader						44
#define	pWeight						45
#define	pScalar						46
#define	AttachToColObjHeader		47
#define	ToggleKey					48
#define	pSinusx						49
#define	pSinusy						50
#define	CheckForDynamicCollision	51
#define	PickNewNode					52
#define	wCheckViewCollision			53		//special weapon type cops laser
#define	ClrPath						54
#define	wCheckWeaponTarget			55		//weapon targetting
#define	pLifeSpan					56
#define	pCollision					57
#define	pRebound					58
#define	pColDeath					59
#define	pRotateWithDir				60
#define	pTridi						61
#define	pKillWithActor				62
#define	pSpawnFromStart				63
#define	pFunc						64
#define	MatrixCallback				65
#define	pFlipUV						66
#define	CheckForJumpPossesion		67
#define	CheckFootCollision			68
#define	pSinusz						69
#define PlaySequence				70
#define ChangeSniperMode			71
#define ActivateButtonSample		72
#define	ToggleListenerSource		73
#define PlayerInput					74
#define LockCamera					75
#define GodModeStatus				76
#define EXPGet						77
#define PlaneTriggerQuadrant		78
#define	SetKeyObjFrame				79
#define CheckTriggerObjFlag			80
#define	MoveBackgroundObject		81
#define ChangeFog					82
#define DeadClassRank				83
#define	ChangeTrigger				84
#define	wUpdateBulletDamage			85
#define	RandomizeAimMatrix			86
#define	SaveAimMatrix				87
#define	RestoreAimMatrix			88
#define	FreeLook					89
#define DisplayObjectives			90
#define	ClrAnalogValues				91
#define BlastObjCollisionCheck		92
#define GetNumbActorsInCurrentSet	93
#define ChangeCutScene				94
#define	TransferPlayerToAttachActor	95
#define	XRayModeController			96
#define	SetBlendingMode				97
#define	ClearBlendingModeChanges	98
#define	SetSlowFastMotion			99
#define	ClrSlowFastMotion			100
#define	CalcTransMat				101
#define	SearchForCloseActor			102
#define	SetLockedOnActorToParent	103
#define	ClrParentPtr				104
#define	CopyParentFlags				105
#define DontBlowBattery				106
#define	CDVol						107
#define	WAVEVol						108
#define	PauseToggle					109
#define KeyObjControl				110
#define	ScreenShake					111
#define	ScreenShakeStop				112
#define SniperKFObj					113
#define SetTriggerObjFlag			114
#define SetFlagsOnActiveActors		115		//change Direction and ActorFlag on all active actors  (radius,height,DUMMY,direction,actorflag)
#define ClrFlagsOnActiveActors		116		//clr Direction and ActorFlag on all active actors  (radius,height,DUMMY,direction,actorflag)
#define	RestoreOldHealth			117		//put OHealth in Health ()
#define PickupActor					118
#define GlobalAmbient				119
#define	CDFade						120
#define ExplodeObject				121
#define	ClrAllCollisionBuffers		122
#define	ChangeRelativeSpeed			123
#define	FadeToBlack					124
#define AutoTesselation				125
#define CheckColSphereOffset		126
#define FaceTriggerDirection		127
#define ActivateTrigger				128
#define ForceGlobalRealloc			129
#define CutSceneEnd					130
#define	DetachReattachToPath		131
#define KillHarpoonHandler			132
#define TriggerBox					133
#define	HUDTimerSet					134
#define RunScriptCode				135
#define	ScriptCodeInitiated			136
#define LoadLevel					137
#define NoZoomExit					138
#define	DeleteEntitiesAndActorsInSet 139
#define	CDSwap						140
#define	CDPlaySegment				141
#define CDForcePlay					142
#define DisplayHUD					143
#define DisplaySatanHUDToggle		144
#define MouseLookToggle				145
#define SetActorToPrevPos			146
#define RoomForDeposses				147
#define CleanUpWeapons				148
#define InterMessage				149
#define SetCamBulb					150
#define	ForceLoadSet				151
#define DisplayFXPagesToggle		152
#define	ClearDB						153		//Clears out the stats information for Samples, Actions, Actors and Particles
#define	LoadPreloadDB				154		//Load the preload DB and initialize Samples, Actions, Actors and Particles
#define	SavePreloadDB				155		//Save the preload DB and reset stat counters for Samples, Actions, Actors and Particles
#define	RestoreLastHealth			156
#define AIVisionStatus				157
#define	ClrAFlagAttached			158
#define ProcessScrollUV				159
#define ProcessKeyFrames			160

#define	AIasktojoin					200		//AI specific calls
#define	AIcheckfortarget			201
#define	AIorder						202
#define	AIreleasegroup				203
#define	AIbreakfromgroup			204
#define	AIjoinnewgroup				205
#define	AIselecttarget				206
#define	AIclrtarget					207
#define	AIupdateAIvars				208
#define	AIgrouppickdest				209
#define	AIpickdest					210
#define	AIcorrectforobstacles		211
#define	AIcheckforonpath			212
#define	AIcheckactorstates			213
#define	AIcheckactorstatesneg		214
#define	AIchecklogtrajectory		215
#define	AIpicknewhidenode			216
#define	AIclrhidenode				217
#define	AIupdatetargetpos			218
#define	AIcheckactordirections		219
#define	AIcheckactoractions			220
#define	AIchangefriendtoenemy		221
#define	AIchangeenemytofriend		222
#define	AIchangeplayertoenemy		223
#define	AIcheckbulletorigin			224
#define	AIcheckattachactionorigin	225
#define	AIreinstateactoraiclass		226
#define	AIlockedtoactorflag			227
#define	AIalert						228
#define	AIcheckforplayerone			229
#define	AIfindpathwithspecificstate	230
#define	AIfindpathwithspecificid	231
#define	AIcalcdroidposition			232
#define	AIupdatemovementvariables	233		//update TargetAngle, TargetDistance etc. ()
#define	AIchangemetoenemy			234		//set _AIclassEnemy on actor ()
#define	AIchangerank				235		//change range on actor (rank)
#define	AIexecutecodewithinradius	236
#define	AIsetlockedonactortotarget	237
#define	AIchangetargettoenemy		238
#define	AIchangeclass				239
#define AIcheckvisionbuffer			240
#define	AIclrpathid					241
#define	AIremovetargetfromvisionbuffer	242
#define	AItransfertargetfromfriend	243
#define	AIQrunningagainstwall		244
#define	AIsetnumberframesagainstwall	245
#define	AIclrlockedactorenemyflag	246
#define	AInrfriendsinset			247
#define	AIsafetyradius				248

#define	StateNormal					0x1
#define	StateFalling				0x2
#define	StateFlying					0x4
#define	StateGliding				0x8
#define	StateHeadTrack				0x10
#define	StateJump					0x20
#define	StateExecuteAnim			0x40
#define	StateUnused				0x80		//Unused
#define	StateDead					0x100
#define	StateCrawling				0x200
#define	StateBangedHead				0x400
#define	StateOnFire					0x800
#define	StateSteamed				0x1000
#define	StateBlind					0x2000
#define	StatePatrol					0x4000
#define	StateAttack					0x8000
#define	StateAttached				0x10000
#define	StateHarpooned				0x20000
#define	StateElectricShock			0x40000
#define	StateFollowPath				0x80000
#define	StateExecutePathSequence	0x100000
#define	StateCrouching				0x200000
#define	StateThrown					0x400000
#define StateForceField				0x800000
//no bits left here (24 bit)
#define StateJustActivated			0x1000000
#define StateDazed					0x2000000
#define StateForceBkTrig			0x4000000
#define	StateAllNormalStates		0x180001
#define StateInAir					(StateFalling|StateFlying|StateGliding)

#define _AFLAGnopossesion		0x1			//actor cannot be possesed when this bit is set
#define _AFLAGdoor				0x2			//actor will open a door if action is pressed
#define _AFLAGpanel				0x4			//actor will activate a panel if action is pressed
#define _AFLAGlogon				0x8			//if actor has a lock on enemy
#define _AFLAGSniped			0x10		//if actor has been shot by a sniper
#define _AFLAGSqueeze			0x20		//if actor has been squeezed by KF objects
#define _AFLAGforceactive		0x40		//forces processing of actor even if set is not open
#define _AFLAGnocollision		0x80		//disables collision in the actortoactor collision
#define _AFLAGnorotation		0x100		//disables player rotational input
#define _AFLAGattached			0x200		//in the middle of attach action
#define _AFLAGnotarget			0x400		//turns targeting off on actor (non interactive characters). AND turns bulletactorcollison off
#define _AFLAGactivatebutton	0x800		//flag is set if character was told to activate a console in backgroundtriggerchecks
#define _AFLAGnoai				0x1000		//flag is set if character is not performing ai
#define _AFLAGlift				0x2000		//actor will activate a lift if action is pressed
#define _AFLAGsniper			0x4000		//actor gets sniper vision (for now that means x2 perception and better light tolerance)
#define	_AFLAGradiated			0x8000		//when within a radioactive zone
#define	_AFLAGspawnaction		0x10000		//set if spawnaction was executed this frame to make sure from 0 is displayed
#define	_AFLAGsignalfromparent	0x20000		//like tempflag. used to send signals to weapons about abnormal state (fx. drift)
#define	_AFLAGnomove			0x40000		//so you can't push around stationary objects
#define	_AFLAGweaponinvisible	0x80000		//so it is possible to holster weapons
#define	_AFLAGconfused			0x100000	//after concussion bomb
#define	_AFLAGshieldon			0x200000	//shield currently active
#define _AFLAGresetfallalt		0x400000	//is used to prevent teleported characters from dying when they get to destination
#define _AFLAGpossesed			0x800000	//has other character inside
#define _AFLAGkillandremove		0x1000000	//signal to kill itself and remove itself from list
#define _AFLAGinitialize		0x2000000	//signal to the actor to do special init code in the scripts
#define _AFLAGnolinkup			0x4000000	//this actor should never do a linkup animation
#define _AFLAGcolfromabove		0x8000000	//the actors horizontal collision comes from above
#define _AFLAGSniperLongRange	0x10000000	//Vision is multiplied by five. Special case
#define _AFLAGNoDepossession	0x20000000	//Character cannot depossess player...(well,the other way around. sue me !)
#define	_AFLAGnobulletcollision	0x40000000	//turns off bulletactorcollision on actor
//AFLAG is full! (start optimizing)

#define _COLfalling				0	//I ran out of bits. Besides, all characters must be damaged by this. How much is set in the characters' script.
#define	_COLfire				1
#define	_COLsmallbullet			2
#define	_COLkillsall			4
#define	_COLexplosion			8
#define	_COLelectricity			16
#define	_COLholy				32
#define	_COLsingleattach		64
#define	_COLsteam				128

#define	_COLBeast				28	//(_COLelectricity|_COLkillsall|_COLexplosion)
#define _COLAll					255
#define _COLAllExceptFire		254
#define _COLAllExceptBullets	249
#define _COLAllExceptHoly		223
#define _COLsinglecol			(_COLsmallbullet|_COLsingleattach)	//Bullet can only hit one actor
#define _COLOnlyOnce			(_COLfire|_COLsteam|_COLsingleattach|_COLelectricity)	//Actor can only be hit by one of these each frame (Not only for ActorCollision, not for BulletCollision)
#define _COLTwoDistances		(_COLexplosion)	//Which types can set the _DIRCloseToCollision

#define _CANormal				0
#define _CADropWeapon			1
#define _CADropWeaponAndShells	2
#define _CASwapWeapon			3
#define _CADropBattery			4
#define	_CADropActor			5

#define	_SXAAalignmovingmaster		1	//flags for action attach
#define	_SXAAalignmovingslave		2
#define	_SXAAdisablecollision		4
#define	_SXAAdisablerotation		8
#define _SXAAonlydeadpeople			16
#define	_SXAAAlignTransToY			32
#define _SXAAStandingOnly			64
#define _SXAAPlayerOneOnly			128
#define _SXAAObserveDifficulty		256

#define _ClassFX				0		//MISSING: Remove this

#define	_ClassModel				8
#define	_ClassWeapon			16
#define	_ClassBullet			32
#define	_ClassDontStickToWall	64				//Set if character is too solid
#define	_ClassPickup			128				
#define	_ClassAmmoPickup		144	//_ClassPickup|_ClassWeapon

//It cannot check for the following types as categories, only as compares of VClass==
#define	_ClassHalo				1|_ClassPickup					//Must be unique from other pickups

#define	_ClassAngel				0|_ClassModel		
#define	_ClassCop				1|_ClassModel
#define	_ClassProstitute		2|_ClassModel
#define	_ClassDroid				3|_ClassModel
#define	_ClassMedic				4|_ClassModel
#define	_ClassGeneric			5|_ClassModel
//6-7 are free
#define	_ClassBeast				0|_ClassModel|_ClassDontStickToWall
//1-7 are free

#define	_RankScum				1
#define	_RankPrivate			2
#define	_RankSergeantL			3
#define	_RankSergeantM			4
#define	_RankSergeantH			5
#define	_RankCommander			6
#define	_RankGeneral			7

#define	_AttachLeftHand			0
#define	_AttachRightHand		1
#define	_AttachHead				2
#define	_CarryLeftHand			4
#define	_CarryRightHand			8


#define	_EmptyCondition			0
#define	_If						1
#define	_ElseIf					2
#define	_Else					3
#define	_Switch					4
#define	_Case					5
#define	_Default				6

#define	_Equal					1
#define	_NotEqual				2
#define	_Less					3
#define	_LessEqual				4
#define	_Greater				5
#define	_GreaterEqual			6
#define	_AndEqual				7
#define	_AndEqualEqual			8
#define	_AndNotEqual			9

#define	True					1
#define	False					0
#define	oFF						0
#define	oN						1
#define	_DUMMY					0


#define _english			0
#define _all				1
#define _silent				2

#define	_Gfloat				1
#define	_Gvector			2
#define	_Gmat				3
#define	_float				4
#define	_vector				5
#define	_mat				6
#define	_declare			7
#define	_set				8
#define	_seti				9
#define	_add				10
#define	_sub				11
#define	_mul				12
#define	_div				13
#define	_addtime			14
#define	_settoactorpos		15
#define	_settotargetpos		16
#define	_setactorpos		17
#define	_settargetpos		18
#define	_distance			19
#define	_distance2			20
#define	_normalize			21
#define	_dotproduct			22
#define	_xproduct			23
#define	_direction			24
#define	_copyx				25
#define	_copyy				26
#define	_copyz				27
#define	_setx				28
#define	_sety				29
#define	_setz				30
#define	_rnd				31
#define	_copy				32
#define	_vectorfromangle	33
#define	_vectorfromdirflags	34
#define	_and				35
#define	_or					36
#define	_xor				37
#define	_clr				38
#define	_change				39
#define	_speedfromdirflags	40
#define	_rotate				41
#define	_setparent			42
#define	_clrparent			43
#define	_copyparent			44
#define	_rnd2				45
#define	_swapyz				46
#define	_settobonepos		47
#define _inv				48
#define	_target				49
#define	_settocolobjpos		50
#define	_subx				51
#define	_suby				52
#define	_subz				53
#define	_addx				54
#define	_addy				55
#define	_addz				56
#define _shiftleft			57
#define _shiftright			58
#define	_settolockedpos		59
#define	_multiplywithtransmat	60
#define	_settopathdest		61
#define	_setpathdest		62
#define	_sin				63
#define	_cos				64
#define	_settokfpos			65
#define	_settocolpos		66
#define _round				67
#define _multiplywithobjtransmat 68
#define _settotriggerpos	69
#define _abs				70
#define _scale				71
#define _settocamtarget		72
#define	_settoboneposrelative	73
#define _setplanetrignvec	74
#define	_mod				75
#define	_setactorangle		76

#define	_SXIleft			0x1		//analog partner1		+-=1
#define	_SXIright			0x2		//analog partner1
#define	_SXIup				0x4		//analog partner2		+-=1
#define	_SXIdown			0x8		//analog partner2
#define	_SXIfleft			0x10	//analog partner3		+-=1
#define	_SXIfright			0x20	//analog partner3
#define	_SXIbutton1			0x40
#define	_SXIbutton2			0x80
#define	_SXIbutton3			0x100
#define	_SXIbutton4			0x200
#define	_SXIbutton5			0x400
#define	_SXIbutton6			0x800
#define	_SXIbutton7			0x1000
#define	_SXIbutton8			0x2000
#define	_SXIstart			0x4000
#define	_SXIselect			0x8000
									//start of keyboard specific input
#define	_SXIbutton9			0x10000
#define	_SXIbutton10		0x20000
#define	_SXIbutton11		0x40000
#define	_SXIbutton12		0x80000

//tutorial bits (Msika's)
#define help01	0x1
#define help02	0x2
#define help03	0x4
#define help04	0x8
#define help05	0x10
#define help06	0x20
#define help07	0x40
#define help08	0x80
#define help09	0x100
#define help10	0x200
#define help11	0x400
#define help12	0x800
#define help13	0x1000
#define help14	0x2000
#define help15	0x4000
#define help16	0x8000
#define help17	0x10000
#define help18	0x20000
#define help19	0x40000
#define help20	0x80000
#define help21	0x100000
#define help22	0x200000
#define help23	0x400000
#define help24	0x800000
#define AllHelp 0xffffff
#define RadBit  0xf00000

#define KEY_ESCAPE            1
#define KEY_1                 2
#define KEY_2                 3
#define KEY_3                 4
#define KEY_4                 5
#define KEY_5                 6
#define KEY_6                 7
#define KEY_7                 8
#define KEY_8                 9
#define KEY_9                10
#define KEY_0                11
#define KEY_MINUS            12    /* - on main keyboard */
#define KEY_EQUALS           13
#define KEY_BACK             14    /* backspace */
#define KEY_TAB              15
#define KEY_Q                16
#define KEY_W                17
#define KEY_E                18
#define KEY_R                19
#define KEY_T                20
#define KEY_Y                21
#define KEY_U                22
#define KEY_I                23
#define KEY_O                24
#define KEY_P                25
#define KEY_LBRACKET         26
#define KEY_RBRACKET         27
#define KEY_RETURN           28    /* Enter on main keyboard */
#define KEY_LCONTROL         29
#define KEY_A                30
#define KEY_S                31
#define KEY_D                32
#define KEY_F                33
#define KEY_G                34
#define KEY_H                35
#define KEY_J                36
#define KEY_K                37
#define KEY_L                38
#define KEY_SEMICOLON        39
#define KEY_APOSTROPHE       40
#define KEY_GRAVE            41    /* accent grave */
#define KEY_LSHIFT           42
#define KEY_BACKSLASH        43
#define KEY_Z                44
#define KEY_X                45
#define KEY_C                46
#define KEY_V                47
#define KEY_B                48
#define KEY_N                49
#define KEY_M                50
#define KEY_COMMA            51
#define KEY_PERIOD           52    /* . on main keyboard */
#define KEY_SLASH            53    /* / on main keyboard */
#define KEY_RSHIFT           54
#define KEY_MULTIPLY         55    /* * on numeric keypad */
#define KEY_LMENU            56    /* left Alt */
#define KEY_SPACE            57
#define KEY_CAPITAL          58
#define KEY_F1               59
#define KEY_F2               60
#define KEY_F3               61
#define KEY_F4               62
#define KEY_F5               63
#define KEY_F6               64
#define KEY_F7               65
#define KEY_F8               66
#define KEY_F9               67
#define KEY_F10              68
#define KEY_NUMLOCK          69
#define KEY_SCROLL           70    /* Scroll Lock */
#define KEY_NUMPAD7          71
#define KEY_NUMPAD8          72
#define KEY_NUMPAD9          73
#define KEY_SUBTRACT         74    /* - on numeric keypad */
#define KEY_NUMPAD4          75
#define KEY_NUMPAD5          76
#define KEY_NUMPAD6          77
#define KEY_ADD              78    /* + on numeric keypad */
#define KEY_NUMPAD1          79
#define KEY_NUMPAD2          80
#define KEY_NUMPAD3          81
#define KEY_NUMPAD0          82
#define KEY_DECIMAL          83    /* . on numeric keypad */
#define KEY_F11              87
#define KEY_F12              88
#define KEY_F13             100    /*                     (NEC PC98) */
#define KEY_F14             101    /*                     (NEC PC98) */
#define KEY_F15             102    /*                     (NEC PC98) */
#define KEY_KANA            112    /* (Japanese keyboard)            */
#define KEY_CONVERT         121    /* (Japanese keyboard)            */
#define KEY_NOCONVERT       123    /* (Japanese keyboard)            */
#define KEY_YEN             125    /* (Japanese keyboard)            */
#define KEY_NUMPADEQUALS    141    /* = on numeric keypad (NEC PC98) */
#define KEY_CIRCUMFLEX      144    /* (Japanese keyboard)            */
#define KEY_AT              145    /*                     (NEC PC98) */
#define KEY_COLON           146    /*                     (NEC PC98) */
#define KEY_UNDERLINE       147    /*                     (NEC PC98) */
#define KEY_KANJI           148    /* (Japanese keyboard)            */
#define KEY_STOP            149    /*                     (NEC PC98) */
#define KEY_AX              150    /*                     (Japan AX) */
#define KEY_UNLABELED       151    /*                        (J3100) */
#define KEY_NUMPADENTER     156    /* Enter on numeric keypad */
#define KEY_RCONTROL        157
#define KEY_NUMPADCOMMA     179    /* , on numeric keypad (NEC PC98) */
#define KEY_DIVIDE          181    /* / on numeric keypad */
#define KEY_SYSRQ           183
#define KEY_RMENU           184    /* right Alt */
#define KEY_HOME            199    /* Home on arrow keypad */
#define KEY_UP              200    /* UpArrow on arrow keypad */
#define KEY_PRIOR           201    /* PgUp on arrow keypad */
#define KEY_LEFT            203    /* LeftArrow on arrow keypad */
#define KEY_RIGHT   205    /* RightArrow on arrow keypad */
#define KEY_END             207    /* End on arrow keypad */
#define KEY_DOWN            208    /* DownArrow on arrow keypad */
#define KEY_NEXT            209    /* PgDn on arrow keypad */
#define KEY_INSERT          210    /* Insert on arrow keypad */
#define KEY_DELETE          211    /* Delete on arrow keypad */
#define KEY_LWIN            219    /* Left Windows key */
#define KEY_RWIN            220    /* Right Windows key */
#define KEY_APPS            221    /* AppMenu key */



#define	_MATstair			1
#define	_MATnocol			2
#define	_MATsmallLedge		4
#define	_MATstairOrLedge	5
#define	_MATLedge			8
#define	_MATWood			16
#define	_MATMetal			32
#define	_MATWater			64
#define	_MATSheetMetal		128
#define	_MATConcrete		256
#define	_MATGlass			512
#define	_MATKFO				1024
#define	_MATRipple			2048
#define	_MATColElectricity	4096
#define	_MATDrown			8192
#define	_MATPush			16384
#define	_MATMoveActor		32768

#define	_SXEXPActorMatrixBulb	1
 
//Light defines

#define	_SXLvolume						1	
#define	_SXLadditive					2
#define	_SXLdirectional					4
#define	_SXLomni						8
#define	_SXLplane						16
#define	_SXLspawnedfromexp				32			//this is set if spawned from expomniattach
#define	_SXLNoShadow					64
//Are you adding or modifying light defines?
//if you are please tell Torgeir what you are changing


//AI defines
#define	AINOTARGETTHRESHOLD				1500
#define	AINOTARGETSEARCHTHRESHOLD		1200
#define	AISTOPIFNOTARGETTHRESHOLD		2000
#define	AIINORDERREGROUPTHRESHOLD		400

#define	_AIfriend						1
#define	_AIenemy						2
#define	_AIundetermined					4
#define	_AIgrenade						8

//Variables shared in RenED
#define	_AIstateRetreat					1	//off
#define	_AIstateAttention				2	//off
#define	_AIstateSurrender				3	//off
#define	_AIstateRegroup					4	//off
#define	_AIstateAttack					5	//off
#define	_AIstateSpreadOut				6	//off
#define	_AIstateHide					7	//off
#define	_AIstateAtEase					8	//off
#define	_AIstateSurround				9	//off
#define	_AIstateGetDown					10	//off
#define	_AIstateFallIn					11	//off
#define	_AIstateSearch					12	//off
#define	_AIstateFlee					13	//off

#define	_AIstateINTERNALFLAGSTOPSHERE	13

#define	_AIstateIdle					14
#define	_AIstateWork					15
#define	_AIstateWorkWeld				16
#define	_AIstatePatrol					17
#define	_AIstateShoot					18
#define	_AIstateSmoke					19
#define	_AIstateRun						20
#define	_AIstateChotEat					21	
#define	_AIstateDrop					22
#define	_AIstateWatchTV					23	
#define	_AIstatePushUp					24	
#define	_AIstateShadowBoxing			25	
#define	_AIstateWatchTVIdle				26	
#define	_AIstatePressAlarmButton		27
#define	_AIstateGuard					28
#define	_AIstatePressButton				29
#define	_AIstateSmokeBong				30
#define	_AIstateGetToWork				31	//off
#define	_AIstateCombatModeReact			32	//off
#define	_AIstatePossesionReact			33	//off
#define	_AIstateDePossesionReact		34	//off
#define	_AIstateReactToBob				35	//off
#define	_AIstateCowering				36
#define _AIstateWeldKneel				37
#define _AIstateTurnToSound				38
#define _AIstateTurnToSoundSlow			39
#define _AIstateGestureAtBob			40
#define _AIstateDropBattery				41
#define _AIstateSuicide					42
#define _AIstateGetWeapon				43
#define _AIstateConfused				44
#define _AIstateSneakUp					45
#define _AIstateRiotCop					46
#define _AIstateFollowTheLeader			47
#define _AIstateDetachFromPath			48
#define _AIstateShutDown				49
#define _AIstateFreakyFemDance			50
#define _AIstateFreakyManDance			51
#define _AIstateDwellerBarIdle1			52
#define _AIstateDwellerBarIdle2			53
#define _AIstateDwellerBarIdle3			54
#define _AIstateDwellerBarIdle4			55
#define _AIstateBouncerBlockBar			56
#define _AIstateBouncerNoBlock			57
#define _AIstateDJPuke					58
#define _AIstateDJChillyChill1			59
#define _AIstateDJChillyChill2			60
#define _AIstateDJChillyChill3			61
#define _AIstateDJSpinRekids			62
#define _AIstateWaitressSpill			63
#define _AIstateWaitressClean			64
#define _AIstateWaitressPrimp1			65
#define _AIstateWaitressPrimp2			66
#define _AIstateWaitressWalk			67
#define _AIstateWaitressIdle			68
#define _AIstateWaitressFlirt			69
#define	_AIstateRadioactive				70
#define	_AIstateDweller1Sitting			71
#define	_AIstateDweller2Sitting			72
#define	_AIstateDweller3Sitting			73
#define _AIstateFemale1Sitting			74
#define _AIstateFemale2Sitting			75
#define _AIstateFemale1Sleeping			76
#define _AIstateFemale1BarIdle			77
#define _AIstateDetachReattachToPath	78


#define	_AIinspecialmode		0x10000
#define	_AInotonpath			0x20000
#define	_AInomove				0x40000
#define	_AIlockedtoactor		0x80000
#define	_AIinvisible			0x100000
#define	_AIstayonpath			0x200000
#define	_AInoturn				0x400000
#define	_AIcloseupaction		0x800000		//used for close proximity special actions
#define	_AIdontdopickdest		0x1000000		//make sure PickDest() is not called
#define	_AIcombatmodereact		0x2000000


//Variables shared in RenED
#define	_AIclasscop				0x1
#define	_AIclassworker			0x2
#define	_AIclassdroid			0x4
#define	_AIclasschot			0x8
#define	_AIclassangel			0x10
#define	_AIclassbeast			0x20
#define	_AIclassabeast			0x40
#define	_AIclassprost			0x80
#define	_AIclasspimp			0x100
#define	_AIclasspriest			0x200
#define	_AIclassdweller			0x400
#define	_AIclassscientist		0x800
#define	_AIclassbarpeople		0x1000
#define	_AIclassmale			0x2000
#define	_AIclassfemale			0x4000
#define	_AIclassriotcop			0x8000
#define	_AIclassHipGun			0x10000
#define	_AIclasslightgun		0x20000
#define	_AIclassCloseRange		0x40000
#define	_AIclassmedic			0x80000
#define	_AIclassSpecial			0x100000		//to distinguish special characters like bob in connections
#define	_AIclasssubgirl			0x200000
#define	_AIclassanimal			0x400000
#define	_AIclassSatan			0x800000
#define	_AIclassBouncer			0x1000000
#define	_AIclassHuman			0x2000000
#define	_AIclassEvil			0x4000000		//for evil bob
#define	_AIclassEnemy			0x80000000		//AI assigned flag when character is changing from friend to enemy because of hostile actions

#define _AIclassfriendly		_AIclasscop|_AIclassworker|_AIclassdroid|_AIclasschot|_AIclassangel|_AIclassbeast|_AIclassabeast|_AIclassprost|_AIclasspimp|_AIclasspriest|_AIclassdweller|_AIclassscientist|_AIclassbarpeople|_AIclassmale|_AIclassfemale|_AIclassriotcop|_AIclassHipGun|_AIclasslightgun|_AIclassmedic|_AIclasssubgirl|_AIclassanimal

#define	_AIClassBobSkeleton		_AIclassmale|_AIclassangel
#define	_AIClassCopSkeleton		_AIclassmale|_AIclasscop|_AIclassworker|_AIclasschot|_AIclasspimp|_AIclassdweller|_AIclassscientist|_AIclassmedic|_AIclassriotcop|_AIclassbarpeople
#define	_AIClassProstSkeleton	_AIclassfemale|_AIclassprost|_AIclassdweller|_AIclasscop|_AIclasssubgirl|_AIclassbarpeople
#define	_AIClassAbeastSkeleton	_AIclassmale|_AIclassabeast
#define	_AIClassBeastSkeleton	_AIclassmale|_AIclassbeast|_AIclassBouncer

#define	_AIClassAllButAngel		_AIclassmale|_AIclassfemale|_AIclasscop|_AIclassworker|_AIclasschot|_AIclassprost|_AIclasssubgirl|_AIclasspimp|_AIclassdweller|_AIclassscientist|_AIclassriotcop|_AIclassmedic|_AIclassbarpeople

//	Reverb sound definitions
//

#define REVERB_GENERIC			1
#define REVERB_PADDEDCELL		2
#define REVERB_ROOM				3
#define REVERB_BATHROOM			4
#define REVERB_LIVINGROOM		5
#define REVERB_STONEROOM		6
#define REVERB_AUDITORIUM		7
#define REVERB_CONCERTHALL		8
#define REVERB_CAVE				9
#define REVERB_ARENA			10
#define REVERB_HANGAR			11
#define REVERB_CARPETEDHALLWAY	12
#define REVERB_HALLWAY			13
#define REVERB_STONECORRIDOR	14
#define REVERB_ALLEY			15
#define REVERB_FOREST			16
#define REVERB_CITY				17
#define REVERB_MOUNTAINS		18
#define REVERB_QUARRY			19
#define REVERB_PLAIN			20
#define REVERB_PARKINGLOT		21
#define REVERB_SEWERPIPE		22
#define REVERB_UNDERWATER		23
#define REVERB_DRUGGED			24
#define REVERB_DIZZY			25
#define REVERB_PSYCHOTIC		26


//same definitions in SXStructs.h. Update both

#define	_SXMFlat			1
#define	_SXMTexture			2
#define	_SXMWire			4
#define	_SXMBumpMap			8
#define	_SXMGouraud			16
#define	_SXMSubTrans		32
#define	_SXMAddTrans		64
#define	_SXMChromaKey		128
#define	_SXMMipMap			256
#define	_SXMSecondaryMem	512
#define	_SXMTwoSided		1024
#define	_SXMEnvMap			2048
#define	_SXMPaletteIn32Bit	4096
#define	_SXMDisableZBuffer	8192
#define	_SXMUseShadowMap	16384
#define	_SXMDisableZWrites	32768


//fogtype values
#define _SXFogOff		0
#define _SXFogLinear	1
#define _SXFogExp		2
#define _SXFogExp2		3

//fogchange actions
#define _SXFogType		0
#define _SXFogColor		1			//RGB compressed into a long
#define _SXFogDensity	2			//float
#define _SXFogNear		3			//float
#define _SXFogFar		4			//float


//changetrigger values
#define _SXTrigDoor				2048
#define _SXTrigPanel			4096


//CutScene Flag Values
#define	_SXCUTnosmooth			1
#define	_SXCUTdontreset			2

//ChangeCutScene functions
#define	_SXCUTflag				1
#define _SXCUTspeed				2

#define	_SXBoneAttAbsolute				1
#define	_SXBoneAttRelative				2

//AI Control flags
#define		_AICRetreat					1							//recommends retreat
#define		_AICAttack					2							//recommends frontal attack
#define		_AICHide					4							//recommends retreat
#define		_AICRetreatUsingHide		_AICRetreat|_AICHide		//recommends retreat
#define		_AICAttackUsingHide			_AICAttack|_AICHide			//recommends attack using hide

#define		_AIHCReset					0
#define		_AIHCInRoute				0
#define		_AIHCFollowPath				1
#define		_AIHCAttack					3
#define		_AIHCAttackLCorner			4
#define		_AIHCAttackRCorner			5
#define		_AIHCAttackOEdge			6

//AI usage flags
#define		_AIUHideForRetreat			0x1		//able to use hide nodes while in retreat mode
#define		_AIUHideForAttack			0x2		//able to use hide nodes while in attack mode
#define		_AIUHideAttackOffensive		0x4		//moves forward constantly shooting once and picking closer node. Goes head one after no more hide nodes left
#define		_AIUHideAttackDefensive		0x8		//stays at hide node as long as he knows where enemy is at. If nobody spotted then move forward
#define		_AIUHideRetreatOffensive	0x10	//retreat to nearest hide node
#define		_AIUHideRetreatDefensive	0x20	//retreat to nearest hidenode and keep retreating further away until no more nodes can be found
#define		_AIUHideLeanOutRetreat		0x40	//allows him to lean out and take popshots while being in retreat mode
#define		_AIUHideLeanOutAttack		0x80	//allows him to lean out and take popshots while being in attack mode
#define		_AIUSurrender				0x100	//surrenders if gun is pulled on him
#define		_AIUAttackIfUnseen			0x200	//only attacks from behind. Some civilian types use this
#define		_AIUAdvanceIfEnemyUnseen	0x400	//stays back as long as actor can see or know exactly where enemy is
#define		_AIUAlwaysRun				0x800	//never try to use walk animations
#define		_AIUAdvanceUsingPath		0x1000	//uses character specific path for attack
#define		_AIUCrouchToDefend			0x2000	//Crouch down when challenged riot cop style
#define		_AIUCrowdAroundLeader		0x4000	//For little guys like dwarf chots
#define		_AIUFindHost				0x8000	//Seeks out host

//AI ability flags
#define		_AIAJump					0x1
#define		_AIAClimb					0x2
#define		_AIAHideWeapon				0x4
#define		_AIAPickUpWeapon			0x8
#define		_AIAFlashVisors				0x10
#define		_AIAShield					0x20
#define		_AIAFakeWeapon				0x40	//If character's weapon is a part of the model and you want people to regard the actor as a threat
#define		_AIASpecialSecondaryWeapon	0x80	//Don't throw grenade
#define		_AIANoCrawl					0x100	//don't fall to crawl when actor's crawl threshold is reached
#define		_AIANoBoneCollision			0x200	//turns off sniper bone collision on character
#define		_AIAAlwaysInCombatMode		0x400	//for characters having no special combat state
#define		_AIANoThrown				0x800	//don't allow characters to get thrown
#define		_AIAPossesion				0x1000	//can possess other characters
#define		_AIAUseHitWallCode			0x2000	//stop actor from running against wall etc.
#define		_AIANoCloseUpReaction		0x4000	//stop actor from running against wall etc.
#define		_AIANoCrouch				0x8000	//stop actor from running against wall etc.
#define		_AIANoThrowGrenades			0x8000	//stop aiactor from using grenades


//			Headers
#define		Sub_ReactToBulletOrExplosion		20000
#define		Sub_AISetAttack						20001


//			misc

#define		_RingOfFireDuration			200


#endif
