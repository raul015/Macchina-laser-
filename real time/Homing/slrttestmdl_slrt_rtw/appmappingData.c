#include "slrtappmapping.h"
#include "./maps/slrttestmdl.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <slrttestmdl> */
		{ /* SignalMapInfo */
			slrttestmdl_BIOMAP,
			slrttestmdl_LBLMAP,
			slrttestmdl_SIDMAP,
			slrttestmdl_SBIO,
			slrttestmdl_SLBL,
			{0,6},
			7,
		},
		{ /* ParamMapInfo */
			slrttestmdl_PTIDSMAP,
			slrttestmdl_PTNAMESMAP,
			slrttestmdl_SPTMAP,
			{0,6},
			7,
		},
		"slrttestmdl",
		"",
		"slrttestmdl",
		1,
		slrttestmdl_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}