#include "header.h"
#include "tables.h"

/**
 * Convert arc to radian
 */
float arcToRad(float arcAngle)
{
  return ((float)(arcAngle * PI) / (float)ANGLE180);
}

/**
 * Create stemp and fishbown values to make the program runs faster.
 */
void createStepTables(Tables *t)
{
  int i;
  float radian;

  for (i = 0; i <= ANGLE360; i++)
   {
    if (i >= ANGLE90 && i < ANGLE270)
    {
      t->fXStepTable[i] = (float)(TILE_SIZE / t->fTanTable[i]);
      if (t->fXStepTable[i] > 0)
    t->fXStepTable[i] = -t->fXStepTable[i];
    }
    /* facing right*/
    else
    {
      t->fXStepTable[i] = (float)(TILE_SIZE / t->fTanTable[i]);
      if (t->fXStepTable[i] < 0)
    t->fXStepTable[i] = -t->fXStepTable[i];
    }
    /* FACING DOWN*/
    if (i >= ANGLE0 && i < ANGLE180)
    {
      t->fYStepTable[i] = (float)(TILE_SIZE * t->fTanTable[i]);
      if (t->fYStepTable[i] < 0)
    t->fYStepTable[i] = -t->fYStepTable[i];
    }
    /* FACING UP */
    else
    {
      t->fYStepTable[i] = (float)(TILE_SIZE * t->fTanTable[i]);
      if (t->fYStepTable[i] > 0)
    t->fYStepTable[i] = -t->fYStepTable[i];
    }
  }
  for (i = -ANGLE30; i <= ANGLE30; i++)
  {
    radian = arcToRad(i);
    t->fFishTable[i + ANGLE30] = (float)(1.0F / cos(radian));
  }
}

/**
 * Create tigonometric values to make the program runs faster.
 */
void createTrignometricTables(Tables  *t)
{
  int i;
  float radian;

  for (i = 0; i <= ANGLE360; i++)
   {
    radian = arcToRad(i) + (float)(0.0001);
    t->fSinTable[i] = (float)sin(radian);
    t->fISinTable[i] = (1.0F / (t->fSinTable[i]));
    t->fCosTable[i] = (float)cos(radian);
    t->fICosTable[i] = (1.0F / (t->fCosTable[i]));
    t->fTanTable[i] = (float)tan(radian);
    t->fITanTable[i] = (1.0F / t->fTanTable[i]);
  }
  createStepTables(t);
}
