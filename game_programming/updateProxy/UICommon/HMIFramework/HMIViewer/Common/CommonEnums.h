#ifndef COMMONENUMS_H
#define COMMONENUMS_H

#include <qglobal.h>

namespace uicommon {
	enum class LAYER : unsigned char
	{
	    LAYER_BASE   = 0x1,
	    LAYER_SCREEN = 0x2,
	    LAYER_POPUP  = 0x3,
	    LAYER_TOAST  = 0x4,
	};

	enum class LIMIT : unsigned int
	{
	    NONE    = 0,
	    SEC_1   = 1000,
	    SEC_2   = 2000,
	    SEC_3   = 3000,
	    SEC_4   = 4000,
	    SEC_5   = 5000,
	    SEC_6   = 6000,
	    SEC_7   = 7000,
	    SEC_8   = 8000,
	    SEC_9   = 9000,
	    SEC_10  = 10000,
	    SEC_20  = 20000,
	    SEC_100 = 100000
	};

	enum class VIEWER_INDEX : unsigned char
	{
	    VIEWER_1ST  = 0x1,
	    VIEWER_2ND  = 0x2,
	    VIEWER_3RD  = 0x3,
	    VIEWER_4TH  = 0x4,
	    VIEWER_5TH  = 0x4,
	};
}
#endif // COMMONENUMS_H
