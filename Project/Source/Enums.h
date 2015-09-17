/*
  ==============================================================================

    Enums.h
    Created: 25 Jun 2015 2:49:33pm
    Author:  Michael

  ==============================================================================
*/

#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

//TODO: Idk, are there more?
enum class Key_t { A, A_sharp, B, C, C_sharp, D, D_sharp, E, F, F_sharp, G, G_sharp };

//TODO: Fill this with actual values. (Numbers 1-7 not sure if enum is necesarry)
// Not necessary, but I think it'd be worth it because we can ensure no instance ever 
// leaves that range and also makes the code more readable - 
// don't have to go look up what the number represents.
enum class Chord_t { chord_1, chord_2, chord_3, chord_4, chord_5, chord_6, chord_7 };

#endif  // ENUMS_H_INCLUDED
