#include "Games/Games.h"

#define NOTES_TO_SKIP 3
#define WAIT_DELAY 100
#define WAIT_TRYS 5

bool sequence()
{
	SongSequenceData song = readSongFile(PATH_FLINSTONES);

	PianoStreams pianoStreams;

	pianoStreams.size = PIANO_SIZE;

	Stream pianoNotes[PIANO_SIZE] = {{false, false, true, -1, VAL_DO1, 0},
									 {false, false, true, -1, VAL_RE, 0},
									 {false, false, true, -1, VAL_MI, 0},
									 {false, false, true, -1, VAL_FA, 0},
									 {false, false, true, -1, VAL_SOL, 0},
									 {false, false, true, -1, VAL_LA, 0},
									 {false, false, true, -1, VAL_SI, 0},
									 {false, false, true, -1, VAL_DO2, 0}};

	pianoStreams.streams = pianoNotes;

	int streamID;
	int currentNote = 0;
	int tryCounts = 0;
	bool wasCorrect = false;
	char readValue;

	while(currentNote < song.size + NOTES_TO_SKIP - 1)
	{
		//jouer notes a repeter
		for(int i = 0; i < song.size
							&& i < currentNote + 3; i++)
		{
			for(int j = 7; j >= 0; j--)
			{
				if(isNotePressed(j, song.noteSequences[i].note))
				{
					streamID = PlayNote(j);
				}
			}
			THREAD_MSleep(song.noteSequences[i].delay);
			StopNote(streamID);
		}
		THREAD_MSleep(1000);
		//attendre la r�p�tition de la s�quence
		for(int i = 0; i < song.size
									&& i < currentNote + 3; i++)
		{
			wasCorrect = false;
			while(!wasCorrect && tryCounts < WAIT_TRYS)
			{

				readValue = readMux(9, 10, 15, 16);
				tryCounts++;
				if(readValue == song.noteSequences[i].note)
				{
					wasCorrect = true;
					for(int j = 7; j >= 0; j--)
					{
						if(isNotePressed(j, song.noteSequences[i].note))
						{
							streamID = PlayNote(j);
						}
					}
				}
				else if(tryCounts >= WAIT_TRYS)
				{
					//wasCorrect = false;
					return false;
				}

			}
			THREAD_MSleep(song.noteSequences[i].delay);
			StopNote(streamID);
		}

		//Incr�mentation des notes
		currentNote += NOTES_TO_SKIP;
	}

	return true;
}




