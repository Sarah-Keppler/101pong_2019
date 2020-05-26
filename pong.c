/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** Master Pong on Noob !!
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

float subtraction(float a, float b)
{
    return (a - b);
}

void calculate_angle(float *location)
{
    float powX = 0;
    float powY = 0;
    float powZ = 0;
    float lengthX = 0;
    float length_hypotenuse = 0;
    float res = 0;

    powX = pow(location[3] - location[0], 2.0);
    powY = pow(location[4] - location[1], 2.0);
    powZ = pow(location[5] - location[2], 2.0);

    length_hypotenuse = sqrt(powX + powY + powZ);
    lengthX = sqrt(powX + powY);
    res = acos(lengthX / length_hypotenuse);
    res = (res * 180) / M_PI;
    printf("The incidence angle is:\n%.2f degrees\n", res);
}

void get_velocity_and_coordinates(float *location, int time)
{
    float velocity[3];
    float coordinates[3];

    for (int i = 0; 3 > i; ++i) {
        velocity[i] = subtraction(location[i + 3], location[i]);
        coordinates[i] = (time * velocity[i]) + location[i + 3];
    }
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", velocity[0], velocity[1], velocity[2]);
    printf("At time t + %d, ball coordinates will be:\n", time);
    printf("(%.2f, %.2f, %.2f)\n", coordinates[0], coordinates[1], coordinates[2]);
}

void get_angle(float *location)
{
    if (location[2] < location[5] && 0 < location[5]) {
        printf("The ball won't reach the paddle.\n");
        return;
    }
    if (location[2] > location[5] && 0 > location[5]) {
        printf("The ball won't reach the paddle.\n");
        return;
    }
    if (location[2] == location[5] && 0 != location[5]) {
        printf("The ball won't reach the paddle.\n");
        return;
    }
    if (location[0] == location[3] && location[1] == location[4]) {
        printf("The ball won't reach the paddle.\n");
        return;
    }
    calculate_angle(location);
}

int main(int ac, char **av)
{
    if (84 == check_errors(ac, av))
        return (84);
    
    float time = atoi(av[7]);
    float location[7];
    
    for (int i = 0; ac - 2 > i; ++i)
        location[i] = atof(av[i + 1]);
    get_velocity_and_coordinates(location, time);
    get_angle(location);
    return (0);
}
