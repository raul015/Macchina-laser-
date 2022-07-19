#include "slrtappmapping.h"
#include "./maps/homing_ldm.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <homing_ldm> */
		{ /* SignalMapInfo */
			homing_ldm_BIOMAP,
			homing_ldm_LBLMAP,
			homing_ldm_SIDMAP,
			homing_ldm_SBIO,
			homing_ldm_SLBL,
			{0,44},
			45,
		},
		{ /* ParamMapInfo */
			homing_ldm_PTIDSMAP,
			homing_ldm_PTNAMESMAP,
			homing_ldm_SPTMAP,
			{0,82},
			83,
		},
		"homing_ldm",
		"",
		"homing_ldm",
		1,
		homing_ldm_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}