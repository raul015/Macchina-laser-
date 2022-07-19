#include "slrtappmapping.h"
#include "./maps/lettura_finecorsa.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <lettura_finecorsa> */
		{ /* SignalMapInfo */
			lettura_finecorsa_BIOMAP,
			lettura_finecorsa_LBLMAP,
			lettura_finecorsa_SIDMAP,
			lettura_finecorsa_SBIO,
			lettura_finecorsa_SLBL,
			{0,26},
			27,
		},
		{ /* ParamMapInfo */
			lettura_finecorsa_PTIDSMAP,
			lettura_finecorsa_PTNAMESMAP,
			lettura_finecorsa_SPTMAP,
			{0,80},
			81,
		},
		"lettura_finecorsa",
		"",
		"lettura_finecorsa",
		1,
		lettura_finecorsa_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}