
SubRoutine(InitSceneSound1)
{
	callsub(ScriptLevel2);
}

SubRoutine(InitScene1)
{
		vector(_set,GActorAngle,0,1224,0);
		InitActor(Bob1,0,Gactorangle,"luder");
/*
		vector(_set,Gactorpos,4300,200,3444);
		vector(_set,Gactorangle,0,0,0);
		InitActor(subgirl1,Gactorpos,Gactorangle,"Dynamic",FALSE);

		vector(_set,Gactorpos,4300,200,3444);
		vector(_set,Gactorangle,0,0,0);
		InitActor(subgirl2,Gactorpos,Gactorangle,"Dynamic",FALSE);
*/
		//#include	"messiahscripts\enemies\boxroomtestenemies.spt"
//		#include	"messiahscripts\stages\test.spt"
/*
		//Tony's

		vector(_set,Gactorpos,4100,200,3444);
		vector(_set,Gactorangle,0,0,0);
		InitActor(coph,Gactorpos,Gactorangle,"Dynamic",FALSE);
		
		vector(_set,Gactorpos,4000,200,3444);
		vector(_set,Gactorangle,0,0,0);
		InitActor(copr,Gactorpos,Gactorangle,"Dynamic",FALSE);
		
		vector(_set,Gactorpos,4200,200,3444);
		vector(_set,Gactorangle,0,0,0);
		InitActor(copr,Gactorpos,Gactorangle,"Dynamic",FALSE);
*/
		callsub(InitSceneSound1);
}

SubRoutine(MainScene1)
{
	/*
		ClearDMessage();
		dmessage("Commander! I've been hailing !",50,400);
		dmessage("We have Chot activity in Sector 2",60,400);
		dmessage("Gather your men@ and report there",70,400);
		dmessage("immediately!",80,400);
	*/
}

SubRoutine(BackgroundTriggerChecksScene1)
{


}
