#pragma once

#ifdef __DEBUG
#define __TRACE(...) fprintf(stdout,"file[%s]line[%s]func[%s]::",__FILE__,__LINE__,__func__);fprintf(stdout,__VA_ARGS__);
#else
#define__TRACE(...)

#endif
