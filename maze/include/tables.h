#ifndef _TABLES_H_
#define _TABLES_H_

/**
 * struct Tables - stores trignometric, step, fishbown table values
 * @fSinTable: sin values
 * @fISinTable: inverse sin values
 * @fCosTable: cos values
 * @fICosTable: inverse cos values
 * @fTanTable: tan values
 * @fITanTable: inverse tan values
 * @fTanTable: tan values
 * @fFishTable: fish effect values
 * @fXStepTable: step X values
 * @fYStepTable: step Y values
 *
 *  Stores trignometric, step, fishbown table values
 */
typedef struct Tables
{
float fSinTable[ANGLE360 + 1];
float fISinTable[ANGLE360 + 1];
float fCosTable[ANGLE360 + 1];
float fICosTable[ANGLE360 + 1];
float fTanTable[ANGLE360 + 1];
float fITanTable[ANGLE360 + 1];
float fFishTable[ANGLE360 + 1];
float fXStepTable[ANGLE360 + 1];
float fYStepTable[ANGLE360 + 1];
} Tables;


float arcToRad(float arcAngle);
void createTrignometricTables(Tables *);

#endif
