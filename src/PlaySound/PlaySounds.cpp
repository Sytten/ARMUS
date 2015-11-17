#include "PlaySound/PlaySounds.h"

int PlayNotes(PianoStreams * piano)
{
	int returnedValue = 0;

	//Boucle de démarrage des sons
	for(int i = 7; i >= 0; i--)
	{

		//Démarrage du son et assignation du nouveau stream

		unsigned int note = 0;

		if(piano->streams[i].keyPressed == true && piano->streams[i].firstTime == true)
		{
			piano->streams[i].firstTime = false;

			if(piano->streams[i].streamPlaying == true)
				StopNote(piano->streams[i].streamID);


			piano->streams[i].streamID = PlayNote(piano->streams[i].note);
		}
	}

	return returnedValue;
}

int StopNotes(PianoStreams* piano)
{
	int returnedValue = 0;

	//Boucle de démarrage des sons
	for(int i = 7; i >= 0; i--)
	{
		//Fermeture des sons et modification du bool
		if (piano->streams[i].keyPressed == false && piano->streams[i].streamPlaying == true)
		{
			LCD_Printf("j'ai arreter de jouer nigga!");

			StopNote(piano->streams[i].streamID);
			piano->streams[i].streamPlaying = false;
			piano->streams[i].streamID = 0;
		}
	}

	return returnedValue;
}

int CheckStreamIsPlaying(PianoStreams * piano)
{
	int returnedValue = 0;

	for(int i = 7; i >= 0; i--)
	{
		if(piano->streams[i].streamPlaying)
		{
			piano->streams[i].streamPlaying = !AUDIO_IsPlaybackDone(piano->streams[i].streamID);
		}

	}

	return returnedValue;
}
