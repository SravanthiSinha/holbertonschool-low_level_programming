#include "header.h"
#include "tables.h"

/**
 * arcToRad - Takes arcAngle and returns its value in radians.
 * @arcAngle: arcAngle to be converted.
 * Description: Takes arcAngle and returns its value in radians.
 * Return: value in radians.
 */
float arcToRad(float arcAngle)
{
	return ((float)(arcAngle * PI) / (float)ANGLE180);
}

/**
 * createStepTables - Create step and fishbown values
 * @tables: Stores the step, fishbown values in tables.
 * Description: Create step and fishbown values	to make the program run faster.
 */
void createStepTables(Tables *tables)
{
	int i;
	float radian;

	for (i = 0; i <= ANGLE360 ; i++)
	{
		if (i >= ANGLE90 && i < ANGLE270)
		{
			tables->fXStepTable[i] = (float)(TILE_SIZE / tables->fTanTable[i]);
			if (tables->fXStepTable[i] > 0)
				tables->fXStepTable[i] = -tables->fXStepTable[i];
		}
		/* facing right*/
		else
		{
			tables->fXStepTable[i] = (float)(TILE_SIZE / tables->fTanTable[i]);
			if (tables->fXStepTable[i] < 0)
				tables->fXStepTable[i] = -tables->fXStepTable[i];
		}
		/* FACING DOWN*/
		if (i >= ANGLE0 && i < ANGLE180)
		{
			tables->fYStepTable[i] = (float)(TILE_SIZE * tables->fTanTable[i]);
			if (tables->fYStepTable[i] < 0)
				tables->fYStepTable[i] = -tables->fYStepTable[i];
		}
		/* FACING UP */
		else
		{
			tables->fYStepTable[i] = (float)(TILE_SIZE * tables->fTanTable[i]);
			if (tables->fYStepTable[i] > 0)
				tables->fYStepTable[i] = -tables->fYStepTable[i];
		}
	}
	for (i = -ANGLE30; i <= ANGLE30; i++)
	{
		radian = arcToRad(i);
		tables->fFishTable[i + ANGLE30] = (float)(1.0F / cos(radian));
	}
}

/**
 * createTrignometricTables - Create tigonometric values values
 * @tables: Stores the tigonometric values in tables.
 * Description: Create tigonometric values to make the program run faster.
 */
void createTrignometricTables(Tables  *tables)
{
	int i;
	float radian;

	for (i = 0; i <= ANGLE360; i++)
	{
		radian = arcToRad(i) + (float)(0.0001);
		tables->fSinTable[i] = (float)sin(radian);
		tables->fISinTable[i] = (1.0F / (tables->fSinTable[i]));
		tables->fCosTable[i] = (float)cos(radian);
		tables->fICosTable[i] = (1.0F / (tables->fCosTable[i]));
		tables->fTanTable[i] = (float)tan(radian);
		tables->fITanTable[i] = (1.0F / tables->fTanTable[i]);
	}
	createStepTables(tables);
}
