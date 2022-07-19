#include "slrtappmapping.h"
#include "./maps/homing.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <homing> */
		{ /* SignalMapInfo */
			homing_BIOMAP,
			homing_LBLMAP,
			homing_SIDMAP,
			homing_SBIO,
			homing_SLBL,
			{0,40},
			41,
		},
		{ /* ParamMapInfo */
			homing_PTIDSMAP,
			homing_PTNAMESMAP,
			homing_SPTMAP,
			{0,82},
			83,
		},
		"homing",
		"",
		"homing",
		1,
		homing_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}