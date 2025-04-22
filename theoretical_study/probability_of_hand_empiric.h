#ifndef PROBABILITY_OF_HAND_EMPIRIC_H
#define PROBABILITY_OF_HAND_EMPIRIC_H

typedef struct {
    int first;
    int second;
} tirage;

tirage distrib(int * pioche);

#endif