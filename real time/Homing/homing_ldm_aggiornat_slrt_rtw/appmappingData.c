#include "slrtappmapping.h"
#include "./maps/homing_ldm_aggiornat.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <homing_ldm_aggiornat> */
		{ /* SignalMapInfo */
			homing_ldm_aggiornat_BIOMAP,
			homing_ldm_aggiornat_LBLMAP,
			homing_ldm_aggiornat_SIDMAP,
			homing_ldm_aggiornat_SBIO,
			homing_ldm_aggiornat_SLBL,
			{0,41},
			42,
		},
		{ /* ParamMapInfo */
			homing_ldm_aggiornat_PTIDSMAP,
			homing_ldm_aggiornat_PTNAMESMAP,
			homing_ldm_aggiornat_SPTMAP,
			{0,82},
			83,
		},
		"homing_ldm_aggiornat",
		"",
		"homing_ldm_aggiornat",
		1,
		homing_ldm_aggiornat_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}