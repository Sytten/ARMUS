/*
============================================================================
 Name : Games
 Author : M.A.G.I.E Team
 Modified on: 2015-11-05
 Description : Access the different games that can be played on the robots
============================================================================
*/

#ifndef GAMES_H_
#define GAMES_H_

#include "PlaySound/PianoStreams.h"
#include "PlaySound/PlaySounds.h"
#include "Sensors/PianoNotes.h"
#include "PlaySound/Notes.h"

#define PIANO_SIZE 8

bool freePlay();
void memory();
void repeat();

//Directory path for repeat mode.


// songs to be played by kids.
void claireFontaine();
void HymeDeLaJoie();
void starwars();

#endif /* GAMES_H_ */
