#include "header.h"
#include "metrics.h"
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
void createStepTables(void)
{
  int i;
  float radian;

  for (i = 0; i <= ANGLE360; i++)
   {
    if (i >= ANGLE90 && i < ANGLE270)
    {
      fXStepTable[i] = (float)(TILE_SIZE / fTanTable[i]);
      if (fXStepTable[i] > 0)
    fXStepTable[i] = -fXStepTable[i];
    }
    /* facing right*/
    else
    {
      fXStepTable[i] = (float)(TILE_SIZE / fTanTable[i]);
      if (fXStepTable[i] < 0)
    fXStepTable[i] = -fXStepTable[i];
    }
    /* FACING DOWN*/
    if (i >= ANGLE0 && i < ANGLE180)
    {
      fYStepTable[i] = (float)(TILE_SIZE * fTanTable[i]);
      if (fYStepTable[i] < 0)
    fYStepTable[i] = -fYStepTable[i];
    }
    /* FACING UP */
    else
    {
      fYStepTable[i] = (float)(TILE_SIZE * fTanTable[i]);
      if (fYStepTable[i] > 0)
    fYStepTable[i] = -fYStepTable[i];
    }
  }
  for (i = -ANGLE30; i <= ANGLE30; i++)
  {
    radian = arcToRad(i);
    fFishTable[i + ANGLE30] = (float)(1.0F / cos(radian));
  }
}

/**
 * Create tigonometric values to make the program runs faster.
 */
void createTrignometricTables(void)
{
  int i;
  float radian;

  for (i = 0; i <= ANGLE360; i++)
   {
    radian = arcToRad(i) + (float)(0.0001);
    fSinTable[i] = (float)sin(radian);
    fISinTable[i] = (1.0F / (fSinTable[i]));
    fCosTable[i] = (float)cos(radian);
    fICosTable[i] = (1.0F / (fCosTable[i]));
    fTanTable[i] = (float)tan(radian);
    fITanTable[i] = (1.0F / fTanTable[i]);
  }
  createStepTables();
}
