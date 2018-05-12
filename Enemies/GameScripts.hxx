
SubRoutine(IncomingMessage)
{
	if(Incoming==1 && VAICon==0)
	{
		float(_add,Blinktimer,1);
		if(Blinktimer&=8)
		{
			ClearDMessage();
			dmessage("Your head is ringing. Press your Objectives button",80,2);
			dmessage("(default to F5)",90,2);
		}
		if(BlinkTimer>2000)
		{
			float(_set,Blinktimer,0);
			ClearDMessage();
			float(_set,Dazed,3);
		}
	}

	if(Dazed==3)
	{
		if(VAICon==0)
		{
			call(ProcessKeyFrames,1);
			call(ProcessScrollUV,1);
			float(_set,AIVisionToggle,0);
			float(_set,AIToggle,0);
			float(_set,BlinkTimer,0);
			if(Vaction==BobWorshipsGod)
			{
				spawnaction(BobIdle);
			}
			elseif(Vaction==CopMessageFromGod)
			{
				spawnaction(GENCrouchUp);
				//spawnaction(GENIdle); // Gabe did this!
			}
			call(PlayerInput,1);
			call(FadeToBlack,1);
			call(DisplayHUD,true);
			float(_set,incoming,3);
			callsub(Sub_SetCameraNormal);
			float(_set,Dazed,0);
		}
	}

	//**** Start the sequence ****
	elseif(Dazed==1) // F5 has been pressed
	{
		if(VAICon==0)
		{
			if(VTrigger==_DIRhorcol && VAIClass!=_AIClassAnimal)
			{
				if(VSniperMode!=0)
				{
					call(ChangeSniperMode,0,0);
				}
				elseif(VFirstPerson!=0)
				{
					FirstPerson(0);
				}
				float(_set,Dazed,2);
				call(ProcessKeyFrames,0);
				call(ProcessScrollUV,0);
			}
		}
	}
	elseif(Dazed==2)
	{
		if(VAICon==0)
		{
			call(DisplayHUD,0);
			call(SetCamBulb,0);
			camera(-250,30); //top view. -280,30 for a face shot
			target(20,5);
			float(_set,AIVisionToggle,1);
			float(_set,AIToggle,1);
			float(_set,Incoming,2);
			call(PlayerInput,0);

			if(VAIClass!=_AIClassBeast && VAIClass!=_AIClassABeast)
			{
				if(VAIClass==_AIClassAngel)
				{
					if(Vaction!=BobWorshipsGod)
					{
						spawnaction(BobWorshipsGod);
					}
				}
				else
				{
					if(Vaction!=CopMessageFromGod)
					{
						spawnaction(CopMessageFromGod);
					}
				}
			}
			float(_add,GodTimer,1);
			if(GodTimer>=120)
			{
				vector(_set,TmpVector,200,200,10);
				spawnlight(HeavyCopSearchLight,0,Emptyvector,TmpVector,EmptyVector,250);
			}
			if(GodTimer==50)
			{
				sample(SFXScreenWipe1,-1);
				call(wCheckViewCollision,0,0,0,0);
			}
			elseif(GodTimer==120)
			{
				call(wCheckViewCollision,-1,-1,-1,0);
				call(DisplayObjectives);
			}
			elseif(GodTimer==250)
			{
				call(FadeToBlack,0);
			}
			elseif(GodTimer==400)
			{
				dmessage("                             press any button to continue.",220,999);
				call(InterMessage);
			}
			elseif(GodTimer==405)
			{
				clearDMessage();
				call(FadeToBlack,1);
				sample(SFXScreenWipe1,-1);
			}
			elseif(GodTimer==455)
			{
				float(_set,Dazed,3);
				float(_set,BobMessage,0);
				float(_set,Incoming,0);
				float(_set,GodTimer,0);
			}
		}
		else
		{
			direction(_clr,_DIRMoveBits|_DIRshoot|_DIRCombatMode);
		}
	}
}


/////////////////////////////////////////
//									   //
//	M I S S I O N    O B J E C T I V E //
//									   //
/////////////////////////////////////////

SubRoutine(ScriptLevel2) // shipping sector
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("A Chot riot is brewing at the entrance",60,300);
	MissionObjective("to Old Town which threatens to overrun the",70,350);
	MissionObjective("Shipping Sector.  Make your way there through",80,350);
	MissionObjective("Gate 2 and put a stop to it before making your",90,350);
	MissionObjective("way through Gate 1 into Old Town.",100,350);
}

SubRoutine(ScriptLevel3) // downtown
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Chots are invading Old Town. Martial law is",60,350);
	MissionObjective("in effect and riot gates hinder travel",70,350);
	MissionObjective("by street to other areas of the city.",80,350);
	MissionObjective("Bypass the gates and reach the outskirts",90,350);
	MissionObjective("by traveling through the inner network of",100,350);
	MissionObjective("labs and officer quarters that connect",110,350);
	MissionObjective("to the outer streets.",120,350);
}

SubRoutine(ScriptLevel4) // outskirts
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Chots have captured Old Town's   ",60,350);
	MissionObjective("power generator in the Sewer.    ",70,350);
	MissionObjective("Make your way to it and switch   ",80,350);
	MissionObjective("the area's power back on before  ",90,350);
	MissionObjective("making your way up to the Lab.   ",100,350);
}

SubRoutine(ScriptLevel13) // sewer
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Find the Power Generator and     ",60,350);
	MissionObjective("recapture it. Turning the power  ",70,350);
	MissionObjective("back on will make life easier    ",80,350);
	MissionObjective("once you reach the lab.          ",90,350);
}

SubRoutine(ScriptLevel5) // Warehouse
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Find a way out of the Warehouse.        ",60,350);
	MissionObjective("Overload the Nuclear Power Generator    ",70,350);
	MissionObjective("to fry the Annex Security Door Circuits ",80,350);
	MissionObjective("and proceed to the next area.           ",90,350);
}

SubRoutine(ScriptLevel6) // Annex
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Locate the annex exit and make    ",60,350);
	MissionObjective("your way to the Main City Streets.",70,350);
}

SubRoutine(ScriptLevel14) // Conveyer
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Though potentially deadly@ the machinery ",60,350);
	MissionObjective("here should allow you to find the access ",70,350);
	MissionObjective("tunnel to the Weapon's Factory without   ",80,350);
	MissionObjective("detection.",90,350);
}

SubRoutine(ScriptLevel7) // Weapon Factory
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("The streets of Main City can be a dangerous   ",60,350);
	MissionObjective("place. While in the Weapons Factory@ build   ",70,350);
	MissionObjective("a Maser weapon and charge it. Controlling    ",80,350);
	MissionObjective("such a weapon will prove to be useful in     ",90,350);
	MissionObjective("your continued quest.                        ",100,350);
}

SubRoutine(ScriptLevel10) // Wasteplant
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Make your way to the loading docks and   ",60,350);
	MissionObjective("locate a vehicle. Once there@ commandeer ",70,350);
	MissionObjective("a truck and try to force your way into   ",80,350);
	MissionObjective("Sex City.                                ",90,350);
}

SubRoutine(ScriptLevel8) // Redlite
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("You need a Vip Passcode to get into Club Kyd on",60,350);
	MissionObjective("a busy night like this. Many of the rich tenants",70,350);
	MissionObjective("living in the housing area have passcodes... but",80,350);
	MissionObjective("it's a dangerous place. The cops and Pimp Daddy's",90,350);
	MissionObjective("sub-girls are going head to head over this",100,350);
	MissionObjective("territory and tensions are high.",110,350);
}

SubRoutine(ScriptLevel16) // Club Perimeter
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Find a Way Into Club Kyd at any cost.",110,350);
}

SubRoutine(ScriptLevel9) // Club Kyd
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("The Commanders are meeting in the VIP area   ",60,350);
	MissionObjective("of the Club located on the top floor. Make   ",70,350);
	MissionObjective("your way up there and see what is happening. ",80,350);
}

SubRoutine(ScriptLevel17) // Military Zone
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
}

SubRoutine(ScriptLevel12) // Cryo Area
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
}

SubRoutine(ScriptLevel15) // Lab
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
}

SubRoutine(ScriptLevel18) // Street
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
}


///////////////////////////////
//							 //
//	I N - G A M E   P L O T	 //
//							 //
///////////////////////////////

SubRoutine(Panel1) //  Shipping Secotr - S1r4 - On the stairs
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("You have come! If it's true@ then my prayers have been",10,999);
	MissionObjective("answered. You are the one...You will set this planet",20,999);
	MissionObjective(" free of its tyranny...And I will help you. I am in a dark ",30,999);
	MissionObjective("place...But I can see through your eyes and the eyes of",40,999);
	MissionObjective("others. I will do my best to guide you by sharing what",50,999);
	MissionObjective("I know@ and what I steal from the minds of the weak.",60,999); //interline
	MissionObjective("As a mortal you must learn how to survive in this world.",80,999);
	MissionObjective("Become comfortable with your new surroundings...",90,999);
	MissionObjective("I will contact you soon and move you in the right direction.",100,999); //interline
	MissionObjective("You must trust me...The past has seen me at the pinnacle",120,999);
	MissionObjective("of this world's power. But I have been cast down",130,999);
	MissionObjective("and great evil has taken my place...",140,999);
}

SubRoutine(Panel2) // Shipping Sector - S1r8 - Upon entering the room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("A mad@ inhuman dictator known as Father Prime is at",10,999);
	MissionObjective("the nucleus of the great shadow that hangs over us.",20,999); //interline
	MissionObjective("Do whatever it takes to get to him.  He controls the people",40,999);
	MissionObjective("from his technology center near the entrance to the Main",50,999);
	MissionObjective("City.  You can access the center from the laboratory that",60,999);
	MissionObjective("feeds it.  I can lead you there@ Bob.",70,999);
	MissionObjective("But you must stay hidden... use the darkness and",80,999);
	MissionObjective("hide in the skin of others.  The people of this world",90,999);
	MissionObjective("have no faith and they will fear you and attack",100,999);
	MissionObjective("you.  They are misdirected by years of oppression. You",110,999);
	MissionObjective("must help them despite themselves and see to the demise",120,999);
	MissionObjective("of Father Prime... or he will see that the planet consumes itself.",130,999);
}

SubRoutine(Panel3) // Shipping Sector - S1r8 - When coming from Commander Room
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Century old strife continues between Father Prime's police",10,999);
	MissionObjective("force and the underground sewer dwellers known as the",20,999); //interline
	MissionObjective("Chots.  When Father Prime assumed power@ a group of",30,999);
	MissionObjective("separatist dwellers took to the underground to resist his",40,999);
	MissionObjective("tyranny.  Since the Chots dropped from mainstream society",50,999);
	MissionObjective("they have been clashing with Father Prime's troops in an",60,999);
	MissionObjective("effort to overthrow him.  They are an ally of your cause@",70,999);
	MissionObjective("but will not recognize you as such.  Fear them... 100 years",80,999);
	MissionObjective("of living underground has changed them... to something",90,999);
	MissionObjective("other than human...",100,999);
	MissionObjective("They fight with little provocation.  They eat their own.",110,999);
	MissionObjective("Their goal is no longer visible in their poisoned minds@",120,999);
	MissionObjective("only the means by which they set out to accomplish it",130,999);
	MissionObjective("so many years ago. You will meet them soon. Convince",140,999);
	MissionObjective("a Commander to return to Gate 2...",150,999);
}

SubRoutine(Panel4) // Shipping Sector - S1r5 - When all the Chots are dead and the door is opened
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Presently@ Chots are invading Old Town. Prime's forces",10,999);
	MissionObjective("have evoked martial law and riot gates block many routes",20,999); 
	MissionObjective("through the city.  Bypass the gates and reach the outskirts",30,999);
	MissionObjective("by traveling through the inner network of labs and officer",40,999);
	MissionObjective("quarters that connect to the outer streets.",50,999);

}

SubRoutine(Panel5) // Downtown - S2r11 - Upon Entering Grinder room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("You are finding much resistance in your travels@ I see.",10,999);
	MissionObjective("I'm sorry this has been difficult but you must prevail.",20,999);
	MissionObjective("Father Prime has betrayed his loyal subjects by making",30,999);
	MissionObjective("them the subjects of scientific experiments.  For decades",40,999);
	MissionObjective("he has been scooping up the population for genetic",50,999);
	MissionObjective("manipulations.  The creation of new biological products",60,999);
	MissionObjective("that defy description have given him power and knowledge",70,999);
	MissionObjective("that you can't imagine.",80,999); //interline
	MissionObjective("Just before you arrived@ Bob@ the Father's need for living",100,999);
	MissionObjective("human tissue had increased drastically for some reason.",110,999);
	MissionObjective("As the city's dwellers disappear@ the cannibalistic Chots",120,999);
	MissionObjective("are now more driven by hunger as their main food supply",130,999);
	MissionObjective("is dwindling.  The increased violence it has spawned will",140,999);
	MissionObjective("hinder your travel.",150,999);
}

SubRoutine(Panel6) // Downtown - S2r16b - Upon entering the room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("I have a difficult task for you@ Bob... I need you to access",10,999);
	MissionObjective("a security room that is presently under siege by a large",20,999);
	MissionObjective("Chot force.  You will need to unlock some passages from",30,999);
	MissionObjective("that location in order to continue in your quest.",40,999);
	MissionObjective("Be careful!  The zone is engaged in a vicious struggle for control.",60,999);
}

SubRoutine(Panel7) // Downtown - S2r19 - Upon entering the room for the first time 
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Father Prime is playing with fire... He and his 'Scientists'",10,999);
	MissionObjective("are meddling in realms where they have no business.",20,999);
	MissionObjective("The experiments they have been conducting on the dark side",30,999);
	MissionObjective("of the moon will be their undoing.  I can assure you@ there",40,999);
	MissionObjective("will be a reckoning...  They have no idea what they have",50,999);
	MissionObjective("unleashed in their search for power.  It is too late for them.",60,999);
	MissionObjective("Bob@ but perhaps you... and I... can put things right.",70,999);
}

SubRoutine(Panel8) // Downtown - S2r18 - after the power outgage, when partial lights come back up
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("I have an idea that will even the odds for your face off",10,999);
	MissionObjective("with Father Prime@ perhaps even put then in your favor!  ",20,999); //interline
	MissionObjective("The Chots have captured the power generator in Old Town.",40,999);
	MissionObjective("You are going to need to reclaim that power if this plan",50,999);
	MissionObjective("is to be successful.",60,999); // interline
	MissionObjective("Locate it... I will contact you again shortly....",80,999);
}


SubRoutine(Panel9) // Sewer - s3_s15 - After restoring power to the generator
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("My little friend@ you have survived the sewers so far!",10,999);
	MissionObjective("Very good@ but don't relax yet. There is a beast down",20,999);
	MissionObjective("there that could be an asset if you were able to take him@",30,999);
	MissionObjective("he is a byproduct of Father Prime's manipulations...",40,999);
	MissionObjective("Use him as protection to travel through the streets above...",60,999);
}

SubRoutine(Panel10) // Outskirts - s3_f1_02 - Upon entering the room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Now@ go to the laboratory control center and activate",10,999);
	MissionObjective("Prime's experiment. Gain control of the fearsome entity",20,999);
	MissionObjective("you will spawn...the culmination of his genetic research...",30,999);
	MissionObjective("and take it to the maintenance elevator leading to the Main City.",40,999);
	MissionObjective("How very poetic it will be to see his favorite abomination",60,999);
	MissionObjective("turned against him.",70,999);
}

SubRoutine(Panel11) // Lab - No Room - As soon as the player possess the Behemoth
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("You have done very well@ my savior.  You are nearing the",10,999);
	MissionObjective("end of your journey.  Go face the demon with your head",20,999);
	MissionObjective("held high.  Be not afraid... you are the one!",30,999);
}

SubRoutine(Panel13) // Warehouse - Stor_04 - As soon as the lift stops moving
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("So@ You're coming for me@ are you... well@ I must say@",10,999);
	MissionObjective("this is very brave of you to continue on.  Certainly someone",20,999);
	MissionObjective("of your questionable ethics should not be eager to meet his",30,999);
	MissionObjective("judgment.  You have turned your back on your father...",40,999);
	MissionObjective("so do not count on him to keep you from the bowels of hell",50,999);
	MissionObjective("when you die... and you WILL die... as for when will be",60,999);
	MissionObjective("determined by your stupidity...",70,999);
}

SubRoutine(Panel14) // Warehouse - War_ent - Upon approaching the consoles in the booth
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("I welcome you here@ Bob.  You fill me with no fear",10,999);
	MissionObjective("whatsoever.  I can't imagine you will make it@ to be honest@",20,999);
	MissionObjective("but if you do I'm going to enjoy watching your escapades",30,999);
	MissionObjective("as you live them... knowing that each step could be your",40,999);
	MissionObjective("last... wondering if I'll have the pleasure of escorting you",50,999);
	MissionObjective("to hell myself. Or if your missteps will rob me of my prize...",60,999); //interline
	MissionObjective("It's going to get messy from here on in@ little one.  I can tell",80,999);
	MissionObjective("you from experience@ chaos is one hell of a tool if you know",90,999);
	MissionObjective("how to set it in motion.  If you are going to find me you will",100,999);
	MissionObjective("have to step on the backs of many - so use chaos as your",110,999);
	MissionObjective("wings.   We'll soon see what you're made of...",120,999);
}

SubRoutine(Panel15) // Annex - Annx_01 - Upon entering room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("MY GOD!! Did you ever fry some people!  How can",10,999);
	MissionObjective("you sleep at night? Heh@ heh@ heh...",20,999); //interline
	MissionObjective("I tell you@ there is something very satisfying watching a",40,999);
	MissionObjective("'good' boy do such BAD things...My spawns are not",50,999);
	MissionObjective("nearly as entertaining... They're kind of annoying@",60,999);
	MissionObjective("actually... But you...well@... I'm waiting for you on",70,999);
	MissionObjective("earth's moon... on a scientific 'research' base appropriately",80,999);
	MissionObjective("situated on the dark side...",90,999); //interline
	MissionObjective("So@ get moving...",110,999); //interline
	MissionObjective("Oh@ and... heh@ heh... stay out of trouble...",130,999);
}

SubRoutine(Panel16) // Weapon Factory - Fact_07 - Upon entering the factory for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("HA! You sure have spunk...you little rascal...look at",10,999);
	MissionObjective("you go...flying around in all that machinery could",20,999);
	MissionObjective("have made stew out of you!  Hey!  That's not a bad idea!",30,999); //interline
	MissionObjective("So@ you're in the weapons factory...now that's my",50,999);
	MissionObjective("kind of place...wouldn't you know it@  I've got a",60,999);
	MissionObjective("penchant for machinery of mass destruction... Maybe",70,999);
	MissionObjective("you'll find some thing there that you could use against",80,999);
	MissionObjective("me!!  HA@ ha@...and...you know@ put a stop to my",90,999);
	MissionObjective("plans of world domination... Hee@ hee...",100,999); //interline
	MissionObjective("Oh@ and speaking of that@ did you know I'm running",120,999);
	MissionObjective("for president now that Father Prime is no longer tying up",130,999);
	MissionObjective("that chair.  I don't want to ruin the surprise@ but I think",140,999);
	MissionObjective("I'm gonna win!  Yours is not the only mind I have been",150,999);
	MissionObjective("wandering around in lately...",160,999);
}

SubRoutine(Panel17) // Weapon Factory - Fact_17 - When the player grabs the maser
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("That's a fine gun you've got there@ boy@ but I'd say",10,999);
	MissionObjective("you're shooting blanks...heh@ heh...",20,999);
}

SubRoutine(Panel18) // Streets - Walls2 - Upon entering the room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Before Father Prime was taken out of the picture he",10,999);
	MissionObjective("populated the streets with big@ pesky armored",20,999);
	MissionObjective("behemoths.  You won't like them@ I'm pretty sure@",30,999);
	MissionObjective("and they won't like you.  What a blast you'll have",40,999);
	MissionObjective("playing with them...Those beasts barely have the mind",50,999);
	MissionObjective("of a child@ and most of that is filled up with faulty wiring...",60,999); //interline
	MissionObjective("Chances are@ they'll mash you little one@ and spoil all",80,999);
	MissionObjective("my fun...so...well...it was nice knowing you...",90,999);
}

SubRoutine(Panel19) // Streets - Walls5 - Upon entering the room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Say@ did you know that liquid plasma is much better",10,999);
	MissionObjective("for you than orange juice?  I swear by the stuff@ and",20,999);
	MissionObjective("the people of earth are just loaded with it.  In fact@ I'm",30,999);
	MissionObjective("enjoying the refreshing effects of a tasty human as we",40,999);
	MissionObjective("speak...<gulp> ahhhhh.. yep@ that's where everyone's",50,999);
	MissionObjective("going... into my belly... It's the 'in' thing to do.",60,999);
	MissionObjective("heh@ heh@ ha-har...",70,999); //interline
	MissionObjective("Now@ don't judge me@ Bob... We're both feeding",90,999);
	MissionObjective("on the lifeforces of these people while we assume mortal",100,999);
	MissionObjective("form...I'm just a little more hungry then you@ that's all...",110,999);
}

SubRoutine(Panel20) // Redlite - Rlhsng2c - Right after the intro sequence
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Jeez@ Bob@ that was pretty extreme@ but I must say@ I'm",10,999);
	MissionObjective("most impressed.  Now that you are in Sex City@ take a",20,999);
	MissionObjective("good look around - Your Pop probably never let you see",30,999);
	MissionObjective("this kind of stuff so take it in while you have the chance.  ",40,999); //interline
	MissionObjective("I hope you're enjoying this little adventure as much as",60,999);
	MissionObjective("I am...too bad it has to end with your demise...although",70,999);
	MissionObjective("I'm pretty sure that will be a lot of fun also...",80,999);
}

SubRoutine(Panel21) // Redlite - RlPlin - If you're not a VIP and the bouncer turns you down
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Awww...they wouldn't let you in? Gosh@ that's a",10,999);
	MissionObjective("surprise... I guess you need to be a Very Important",20,999);
	MissionObjective("Person instead of a most Un-Important Person like you.",30,999); //interline
	MissionObjective("Maybe you could get yourself an upgrade@ you know@",50,999);
	MissionObjective("become a better person... I'm sure a few years of therapy",60,999);
	MissionObjective("could do wonders...",70,999);
}

SubRoutine(Panel22) // Club Access - ACS02 - After being denied access to the club
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("So you've decided to take a break@ and have a drink@ huh.",10,999);
	MissionObjective("Ok...get drunk and pass out in a pool of your own vomit...",20,999);
	MissionObjective("we could fight later...but I see you can't even do this right.",30,999); //interline
	MissionObjective("How can you make it to the moon if you can't even get",50,999);
	MissionObjective("into a night club...come on@ Bob@ I don't really have to",60,999);
	MissionObjective("walk you through this@ do I?",70,999);
}

SubRoutine(Panel23) // Club Kyd - Club_ent - Upon entering the club for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("HA!!  You finally made it inside... I'm glad I woke up...",10,999);
	MissionObjective("would have hated to miss your big dance number...",20,999);
	MissionObjective("heh@ heh...heh...",30,999); //interline
	MissionObjective("What@ exactly@ are you doing there@ anyway?  I fear you",50,999);
	MissionObjective("may have taken one too many bumps to the head!",60,999);
}

SubRoutine(Panel24) // Military Zone - MZ_02 - After the first bird sequence
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("Now@ I could say that was clever@ but it was more likely",10,999);
	MissionObjective("a fluke... finding your way into the Military Zone through",20,999);
	MissionObjective("a nightclub... what on earth possessed you to do that?",30,999); //interline
	MissionObjective("I think@ maybe@ I'll get the chance to meet you face to",50,999);
	MissionObjective("face@ after all!  Ooooh@ I'm getting goose bumps...we",60,999);
	MissionObjective("are going to have a great little fight...probably pretty",70,999);
	MissionObjective("short@ but still great.",80,999); //interline
	MissionObjective("Find the glowing transporter pad and come on up to the",100,999);
	MissionObjective("moon base.  I think you'll like what I've done with the place...",110,999);
	MissionObjective("I snuffed out the pesky laboratory technicians and replaced",120,999);
	MissionObjective("their crater full of primitive monitoring equipment with molten",130,999);
	MissionObjective("hot LAVA!!   Much more cozy I find...",140,999);
}

SubRoutine(Panel25) // Cryo - Cryo03 - Upon arriving in the room for the first time
{
	ClearDMessage();
	MissionObjective(0,-1,-1);
	MissionObjective("So close!! Can you feel it?  Can you dig it?  'Mano y Boyo'",10,999);
	MissionObjective("Man versus the chicken-boy...ah@ the fun we'll have...",20,999);
	MissionObjective("first I'll squish you dead and then I'll put your soul to",30,999);
	MissionObjective("work in hell while I reign over Earth...could it be any sweeter?",40,999); //interline
	MissionObjective("I am feeling SO juiced right now!!  I have been feasting",60,999);
	MissionObjective("on the blood of humans for weeks and I feel their power",70,999);
	MissionObjective("course through my veins... What tasty little batteries they are... ",80,999); //interline
	MissionObjective("I can feel you in the processing plant...you are on the moon",100,999);
	MissionObjective("Bob@ just a few miles away from my 'research' site... I've",110,999);
	MissionObjective("left the teleporter receiver pad in a place where I can keep",120,999);
	MissionObjective("an eye on visitors... I'll see you shortly@ shorty.",130,999);
}
